#pragma once

#ifndef UI_HPP
#define UI_HPP

#define CALC(x, y, w, h) { x, y }, { x + w, y + h }

#include "managers/fonts.hpp"
#include "managers/images.hpp"
#include "managers/style.hpp"

#include "context/context.hpp"

#include "modules/header.hpp"
#include "modules/body.hpp"
#include "modules/background.hpp"
#include "modules/footer.hpp"

class CUserInterface {
public:

	CUserInterface() { 

		this->width = 0;
		this->height = 0;
	}
	~CUserInterface() { }

	void update(
		int w,
		int h,
		CFontsManager fm, 
		CImagesManager im)
	{
		this->width = w;
		this->height = h;

		this->fontsManager = fm;
		this->imagesManager = im;
	}

	void render() {

		if (this->b_ui_initialized == false) {

			ImGui::SetNextWindowPos(ImVec2(0.f, 0.f));
			ImGui::SetNextWindowSize(ImVec2(static_cast<float>(this->width), 35.f));

			style::create();

			this->b_ui_initialized = true;
		}

		if (this->width < 970) {
			this->width = 970;
		}

		if (this->height < 680) {
			this->height = 680;
		}

		ImGui::Begin("Aceid.cc", 0, ImGuiWindowFlags_NoTitleBar |
			ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings |
			ImGuiWindowFlags_NoResize);
		{

			background.update(this->width, this->height,
				this->fontsManager, this->imagesManager);
			background.render();

			header.update(this->width, this->height,
				this->fontsManager, this->imagesManager);
			header.render();

			body.update(this->width, this->height,
				this->fontsManager, this->imagesManager);
			body.render();

			//footer.update(this->width, this->height,
			//	this->fontsManager, this->imagesManager);
			//footer.render();
		}
		ImGui::End();
	}

private:
	CFontsManager fontsManager;
	CImagesManager imagesManager;

	CUIHeader header;
	CUIBody body;
	CUIBackground background = CUIBackground();
	CUIFooter footer;

	int width;
	int height;

	bool b_ui_initialized = false;
};

#endif // !UI_HPP