#pragma once

#ifndef STYLE_HPP
#define STYLE_HPP

namespace style {

	void create() {

		ImGuiStyle* style = &ImGui::GetStyle();
		{
			style->Alpha = 1.f;

			style->WindowPadding = ImVec2();
			style->WindowRounding = 0.f;

			style->FrameRounding = 0.0f;
			style->ItemSpacing = { 15.f, 5.f };

			style->ScrollbarSize = 4.f;
			style->ScrollbarRounding = 0.f;

			style->GrabMinSize = 2.f;

			style->AntiAliasedLines = true;
			style->AntiAliasedFill = true;
			style->AntiAliasedLinesUseTex = true;

			style->FrameRounding = 6.f;

			style->Colors[ImGuiCol_Text] = ImColor(255, 255, 255, 255);
			style->Colors[ImGuiCol_TextDisabled] = ImColor(235, 235, 235, 255);

			style->Colors[ImGuiCol_WindowBg] = ImColor(55, 55, 55);
			style->Colors[ImGuiCol_PopupBg] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
			style->Colors[ImGuiCol_Border] = ImColor(255, 255, 255, 0);
			style->Colors[ImGuiCol_FrameBg] = ImColor(22, 22, 22);

			style->Colors[ImGuiCol_Button] = ImColor(45, 45, 45);
			style->Colors[ImGuiCol_ButtonHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
			style->Colors[ImGuiCol_ButtonActive] = ImColor(40, 40, 40);

			style->Colors[ImGuiCol_ScrollbarBg] = ImColor(55, 55, 60);
			style->Colors[ImGuiCol_ScrollbarGrab] = ImColor(62, 87, 93);
			style->Colors[ImGuiCol_ScrollbarGrabActive] = ImColor(75, 95, 120);

			style->Colors[ImGuiCol_SliderGrab] = ImColor(55, 55, 60);
			style->Colors[ImGuiCol_SliderGrabActive] = ImColor(55, 75, 100);

			style->Colors[ImGuiCol_FrameBg] = ImColor(18, 18, 18);
			style->Colors[ImGuiCol_FrameBgHovered] = ImColor(40, 40, 40);
			style->Colors[ImGuiCol_FrameBgActive] = ImColor(45, 45, 45);
			style->Colors[ImGuiCol_CheckMark] = ImColor(255, 35, 35);
		}
	}
}

#endif // !STYLE_HPP