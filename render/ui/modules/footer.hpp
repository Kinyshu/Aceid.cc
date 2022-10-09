#pragma once

#ifndef FOOTER_HPP
#define FOOTER_HPP

#include "../helpers/helper.hpp"
#include "../../../utils/systemtime.hpp"

std::string g_userName = "Kiny Shu";
char g_first = g_userName[0];
char* g_second = &g_userName[1];

class CUIFooter {
public:

	CUIFooter() {

		this->width = 0;
		this->height = 0;
	}
	~CUIFooter() { }

	void update(int w, int h, CFontsManager fm, CImagesManager im) {
		this->width = w;
		this->height = h;

		this->fontsManager = fm;
		this->imagesManager = im;
	}

	void render() {

		ImGui::GetForegroundDrawList()->AddRectFilled(CALC(0.f, this->height - 120.f, this->width, 120.f), ImColor(15, 15, 15, 230));
		ImGui::AddCircleImageFilled(this->imagesManager.get("Account.Image"), { 225.f, this->height - 58.f }, 46.f, ImColor(255, 255, 255, 230), 24);
		
		ImGui::PushFont(this->fontsManager.get("GothamPro-Light", 24.f));
		{
			ImGui::GetForegroundDrawList()->AddText({ 295.f, this->height - 95.f }, ImColor(255, 55, 55), &g_first);
			ImGui::GetForegroundDrawList()->AddText({ 295.f + ImGui::CalcTextSize(&g_first).x, this->height - 95.f }, ImColor(235, 235, 235), g_second);
		}
		ImGui::PopFont();

		ImGui::PushFont(this->fontsManager.get("GothamPro-Light", 14.f));
		{
			ImGui::GetForegroundDrawList()->AddText({ 297.f, this->height - 55.f }, ImColor(255, 255, 255), u8"Подписка до");
			ImGui::GetForegroundDrawList()->AddText({ 295.f + ImGui::CalcTextSize(u8"Подписка до").x - ImGui::CalcTextSize(__DATE__).x,
				this->height - 35.f }, ImColor(255, 35, 35), __DATE__);
		}
		ImGui::PopFont();

		ImGui::PushFont(this->fontsManager.get("GothamPro-Light", 72.f));
		{
			std::string time = systemtime::get();
			ImGui::GetForegroundDrawList()->AddText({ this->width / 2 - ImGui::CalcTextSize(time.c_str()).x / 2, this->height - 95.f }, ImColor(255, 255, 255), time.c_str());
		}
		ImGui::PopFont();
	}

private:

	int width;
	int height;
	std::string time;
	CFontsManager fontsManager;
	CImagesManager imagesManager;

protected:
	std::string GetUserNameA() {

		char buffer[MAX_PATH];
		DWORD size = sizeof buffer;

		::GetUserNameA(buffer, &size);

		return buffer;
	}
};

#endif // !FOOTER_HPP