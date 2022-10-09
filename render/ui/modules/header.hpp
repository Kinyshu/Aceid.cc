#pragma once

#ifndef HEADER_HPP
#define HEADER_HPP

#include "../helpers/helper.hpp"
#include "../../../utils/systemtime.hpp"

std::list< context::STabButton > g_tabs = {
	{ "Weapon", false },
	{ "Player", false },
	{ "Visuals", false },
	{ "Aiming", false },
	{ "Misc", false },
	{ "Scripts", false },
	{ "Settings", true }
};
//C:\\Aceid.cc\\assets\\audio\\knock.wav
static std::string g_playPath = "";
extern "C" void playThread() {
	mciSendStringA(std::string(std::string("play ") + g_playPath).c_str(), 0, 0, 0);
}

class CUIHeader {
public:

	CUIHeader() {

		this->width = 0;
		this->height = 0;
	}
	~CUIHeader() { }

	void update(int w, int h, CFontsManager fm, CImagesManager im) {
		this->width = w;
		this->height = h;

		this->fontsManager = fm;
		this->imagesManager = im;
	}

	void render() {

		/* Background */
		ImGui::GetForegroundDrawList()->AddRectFilled(CALC(0.f, 0.f, this->width, 45.f), ImColor(15, 15, 15).operator ImU32());

		/* Tab */
		ImGui::PushFont(this->fontsManager.get("__MAIN__", 20.f));
		{
			ImVec2 size = { 80.f, 45.f };
			ImVec2 position = { 240.f, 0.f };

			for (auto it = g_tabs.begin(); 
				it != g_tabs.end(); it++) {

				this->button(it->name, size, { position.x += 80.f, position.y }, it->variable);
			}
		}
		ImGui::PopFont();

		/* Image */
		if (context::style::header::b_draw_image)
			ImGui::GetForegroundDrawList()->AddImage(this->imagesManager.get("__HEADER__"), CALC(0.f, 0.f, this->width, 45.f),
				ImVec2(0, 0), ImVec2(1, 1), ImColor(255, 255, 255, 65).operator ImU32());

		/* Mask */
		ImGui::GetForegroundDrawList()->AddRectFilled(CALC(0.f, 0.f, this->width, 45.f), context::style::header::ic_header_mask_color);

		/* Logo */
		ImGui::PushFont(this->fontsManager.get("Gypsy Killer Laser", 30.f));
		{
			ImGui::GetForegroundDrawList()->AddText(ImVec2(80, 6), ImColor(255, 255, 255), "Ace");
			ImGui::GetForegroundDrawList()->AddText(ImVec2(ImGui::CalcTextSize("Ace").x + 80, 6), ImColor(255, 35, 35), "id");
			ImGui::GetForegroundDrawList()->AddText(ImVec2(ImGui::CalcTextSize("Aceid").x + 80, 6), ImColor(255, 255, 255), ".cc");
		}
		ImGui::PopFont();

		/* Current system time */
		ImGui::PushFont(this->fontsManager.get("__MAIN__", 30.f));
		{
			ImGui::GetForegroundDrawList()->AddText(ImVec2(this->width - 20 - ImGui::CalcTextSize(systemtime::get().c_str()).x, 8),
				ImColor(255, 255, 255), systemtime::get().c_str());
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

	void button(std::string name, ImVec2 size, ImVec2 position, bool &variable) {

		ImColor color;
		if (helper::cursorInBox(position.x, position.y, size.x, size.y)) {
			if (ImGui::IsMouseClicked(0)) {

				if (variable == false) {
					g_playPath = "C:\\Aceid.cc\\assets\\audio\\knock.wav";
				}

				for (auto it = g_tabs.begin(); it != g_tabs.end(); it++) {
					it->variable = false;
				}

				variable = !variable;
			}
		}

		helper::cursorInBox(position.x, position.y, size.x, size.y) ?
			color = ImColor(25, 25, 25) :
			color = ImColor(15, 15, 15);

		if (variable == true) {
			color = ImColor(35, 35, 35);
		}

		ImGui::GetForegroundDrawList()->AddRectFilled(CALC(position.x, position.y, size.x, size.y), color);

		if (variable == true) {

			ImColor hc = context::style::header::ic_header_button_color;
			ImGui::GetForegroundDrawList()->AddShadowRect(CALC(position.x, size.y, size.x, 2), hc, 16.f, { 0.f, 1.f });

			hc.Value.w = 0.3f;
			ImGui::GetForegroundDrawList()->AddRectFilled(CALC(position.x, size.y, size.x, 2), hc);
		}

		ImGui::GetForegroundDrawList()->AddText(ImVec2((position.x + (size.x / 2)) - (ImGui::CalcTextSize(name.c_str()).x / 2),
			(position.y + (size.y / 2)) - (ImGui::CalcTextSize(name.c_str()).y / 2)), ImColor(255, 255, 255), name.c_str());
	}
};

#endif // !HEADER_HPP