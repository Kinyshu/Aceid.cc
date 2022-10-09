#pragma once

#ifndef HANDLER_HPP
#define HANDLER_HPP

#include "../../include/imgui/imgui.h"
#include "../../include/imgui/imgui_impl_win32.h"
#include "../../include/imgui/imgui_impl_dx11.h"

#include "../../main/stdafx.hpp"

#include "../ui/ui.hpp"

#include "../render/game/game.hpp"


using WNDPROC =							LRESULT(CALLBACK*)(HWND, UINT, WPARAM, LPARAM);
using IDXGISwapChainPresent =			HRESULT(WINAPI*)(IDXGISwapChain*, UINT, UINT);
using D3D11ClearRenderTargetView =		VOID(WINAPI*)(ID3D11DeviceContext*, ID3D11RenderTargetView*, const FLOAT[4]);
using ResizeBuffers =					HRESULT(WINAPI*)(IDXGISwapChain*, UINT, UINT, UINT, DXGI_FORMAT, UINT);
using D3D11DrawIndexed =				VOID(WINAPI*)(ID3D11DeviceContext*, UINT, UINT, INT);

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

static bool g_ig_initialized = false;

namespace dxhook::handler {

	int w = 0, h = 0;
	CFontsManager g_fontsManager;
	CImagesManager g_imagesManager;

	HWND hwnd;
	WNDPROC wndProc;

	ID3D11Device* g_device = nullptr;
	IDXGISwapChain* g_swapChain = nullptr;
	ID3D11DeviceContext* g_deviceContext = nullptr;

	IDXGISwapChainPresent swapChainPresent;
	D3D11ClearRenderTargetView clearRenderTargetView;
	ResizeBuffers resizeBuffers;
	D3D11DrawIndexed drawIndexed;

	static bool g_initialized = false;

	LRESULT CALLBACK WndProc(HWND handle, UINT message, WPARAM wParam, LPARAM lParam) {

		if (::ImGui_ImplWin32_WndProcHandler(handle, message, wParam, lParam))
			return true;

		return ::CallWindowProc(wndProc, handle, message, wParam, lParam);
	}

	std::tuple< int, int > wndWH(HWND hw) {

		auto monitor = MonitorFromWindow(hw, MONITOR_DEFAULTTONEAREST);

		MONITORINFO info;
		{
			info.cbSize = sizeof(MONITORINFO);
			GetMonitorInfo(monitor, &info);
		}

		return {
			info.rcMonitor.right - info.rcMonitor.left,
			info.rcMonitor.bottom - info.rcMonitor.top
		};
	}

	void create(IDXGISwapChain* swapChain) {

		if (g_initialized == false) {

			swapChain->GetDevice(__uuidof(ID3D11Device), reinterpret_cast<void**>(&dxhook::handler::g_device));
			dxhook::handler::g_device->GetImmediateContext(&dxhook::handler::g_deviceContext);

			DXGI_SWAP_CHAIN_DESC desc;
			swapChain->GetDesc(&desc);

			dxhook::handler::hwnd = desc.OutputWindow;
			dxhook::handler::wndProc = reinterpret_cast<WNDPROC>(SetWindowLongPtrA(dxhook::handler::hwnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(WndProc)));

			std::tie(w, h) = wndWH(hwnd);

			/* ImGui */
			ImGui::CreateContext();

			ImGuiIO& io = ImGui::GetIO();
			io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;

			g_fontsManager.init();
			g_imagesManager.init(g_device);

			::ImGui_ImplDX11_Init(dxhook::handler::g_device, dxhook::handler::g_deviceContext);
			::ImGui_ImplWin32_Init(dxhook::handler::hwnd);
			
			g_initialized = true;
		}
	}

	void resize(IDXGISwapChain* swapChain) {

		dxhook::handler::g_device->Release();
		dxhook::handler::g_deviceContext->Release();

		swapChain->GetDevice(__uuidof(ID3D11Device), reinterpret_cast<void**>(&dxhook::handler::g_device));
		dxhook::handler::g_device->GetImmediateContext(&dxhook::handler::g_deviceContext);

		::ImGui_ImplDX11_Init(dxhook::handler::g_device, dxhook::handler::g_deviceContext);
		::ImGui_ImplWin32_Init(dxhook::handler::hwnd);
	}

	HRESULT WINAPI hookPresent(IDXGISwapChain* swapChain, UINT interval, UINT flags) {

		if (::GetAsyncKeyState(VK_INSERT) & 1 || ::GetAsyncKeyState(VK_HOME) & 1) {
			context::b_ui_variable_show = !context::b_ui_variable_show;
		}
	
		dxhook::handler::create(swapChain);

		ImGui_ImplDX11_NewFrame();
		ImGui_ImplWin32_NewFrame();

		ImGui::NewFrame();
		{			
			if (context::b_ui_variable_show) {
				CUserInterface ui;
				{
					ui.update(w, h, g_fontsManager, g_imagesManager);
					ui.render();
				}
			}


			ImGui::SetNextWindowPos({ w - 300.f, 100.f });
			ImGui::SetNextWindowSize({ 300.f, h - 200.f });

			ImGui::PushStyleColor(ImGuiCol_WindowShadow, ImColor(0, 0, 0, 0).operator ImVec4());
			ImGui::Begin("##LOGGER", 0, ImGuiWindowFlags_NoTitleBar |
				ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings |
				ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBackground);
			{
				ImGui::PushFont(g_fontsManager.get("__MAIN__", 18.f));
				for (auto it : ctx::log) {
					ImGui::Text(it.second.c_str());
				}
				ImGui::PopFont();
			}
			ImGui::End();
			ImGui::PopStyleColor();

			ImGui::End();

#if GUI_COMPILE == 0
			render::OnGameRender(ImVec2(w, h), g_fontsManager, g_imagesManager);
#endif
		}
		ImGui::EndFrame();

		ImGui::Render();

		ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

		return swapChainPresent(swapChain, interval, flags);
	}

	HRESULT WINAPI hookResizeBuffers(IDXGISwapChain* swapChain, UINT bufferCount, UINT width, UINT height, DXGI_FORMAT format, UINT flags) {

		w = width;
		h = height;

		dxhook::handler::resize(swapChain);
		return resizeBuffers(swapChain, bufferCount, width, height, format, flags);
	}

	VOID WINAPI hookDrawIndexed(ID3D11DeviceContext* context, UINT indexCount, UINT startIndexLocation, INT baseVertexLocation) {

		return drawIndexed(context, indexCount, startIndexLocation, baseVertexLocation);
	}
}

#endif // !HANDLER_HPP