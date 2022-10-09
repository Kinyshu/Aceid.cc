#pragma once

#ifndef CONTEXT_HPP
#define CONTEXT_HPP

enum EUITabs {
	eUIT_Weapon = 0,
	eUIT_Player,
	eUIT_Visuals,
	eUIT_Aiming,
	eUIT_Misc,
	eUIT_Scripts,
	eUIT_Settings,

	eUIT_Count
};

namespace context {

	bool b_window_active = false;

	bool b_ui_variable_show = true;
	bool b_ui_variable_draw_snow = false;

	float f_temp_size = 0.f;

	struct STabButton {

		STabButton(std::string n, bool v, std::string d = "")
		: name(n), variable(v), description(d) { }

		std::string name;
		bool variable;
		std::string description;
	};
	
	struct STabData {

		STabData() {
		}
		STabData(ImVec2 s, ImVec2 p, CFontsManager f, CImagesManager i) :
			size(s), position(p), fontsManager(f), imagesManager(i) {
		}

		ImVec2 size;
		ImVec2 position;
		CFontsManager fontsManager;
		CImagesManager imagesManager;
	};

	bool initializer[EUITabs::eUIT_Count];
	std::list< STabButton > tabs[EUITabs::eUIT_Count];

	namespace style {

		static float alpha = 1.f;

		namespace header {

			static bool b_draw_image = true;
			static bool b_style_color = false;
			static bool b_style_image = false;

			static ImColor ic_header_mask_color = ImColor(25, 15, 255, 25);
			static ImColor ic_header_button_color = ImColor(255, 15, 15);

			std::string str_image_path = "";
		}

		namespace body {

			static bool b_style_color = false;

			static ImColor ic_body_background = ImColor(25, 25, 25);
			static ImColor ic_ctx_body_background = ImColor(30, 30, 30);
		}
	}

	namespace shaders {

		ID3D11PixelShader* redShader = nullptr;
		ID3D11PixelShader* greenShader = nullptr;
		ID3D11PixelShader* blueShader = nullptr;
		ID3D11PixelShader* yellowShader = nullptr;
	}
}

#endif // !CONTEXT_HPP