#pragma once

#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include "../helpers/helper.hpp"
#include "../../../utils/systemtime.hpp"

class CUIBackground {
public:

	CUIBackground() {

		this->width = 0;
		this->height = 0;
	}
	~CUIBackground() { }

	void update(int w, int h, CFontsManager fm, CImagesManager im) {
		this->width = w;
		this->height = h;

		this->fontsManager = fm;
		this->imagesManager = im;
	}

	void render() {

		ImGui::PushFont(this->fontsManager.get("GothamPro-Light", 16.f));
		{
			ImGui::GetBackgroundDrawList()->AddText({ 10.f, this->height - 30.f }, ImColor(255, 255, 255, 155), "ACEID.CC 3.0 CLOSED, BUILD VERSION 1.3a");
		}
		ImGui::PopFont();
	}

private:

	int width;
	int height;
	CFontsManager fontsManager;
	CImagesManager imagesManager;
};

#endif // !BACKGROUND_HPP