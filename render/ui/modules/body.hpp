#pragma once

#ifndef BODY_HPP
#define BODY_HPP

#include "../tabs/handler.hpp"
class CUIBody {
public:

	CUIBody() {

		this->width = 0;
		this->height = 0;
	}
	~CUIBody() { }

	void update(int w, int h, CFontsManager fm, CImagesManager im) {
		this->width = w;
		this->height = h;

		this->fontsManager = fm;
		this->imagesManager = im;
	}

	void render() {

		ImGui::SetNextWindowSize(ImVec2(700, 500.f));
		ImGui::PushStyleColor(ImGuiCol_::ImGuiCol_WindowBg, context::style::body::ic_body_background.operator ImVec4());
		ImGui::PushStyleVar(ImGuiStyleVar_::ImGuiStyleVar_WindowRounding, 8.f);

		/* Tab body */
		ImGui::Begin("##body", 0, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse |
			ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoResize);
		{

			/* Getting size and position current window */
			ImVec2 size = ImGui::GetWindowSize();
			ImVec2 position = ImGui::GetWindowPos();

			ImGui::GetBackgroundDrawList()->AddRectFilled(CALC(position.x, position.y, size.x, 10.f), context::style::body::ic_body_background);

			ImGui::GetWindowDrawList()->AddRectFilled(CALC(position.x, position.y + 80, size.x, 2.f), context::style::body::ic_ctx_body_background);

			handler.update(size, position, this->fontsManager, this->imagesManager);
			handler.worker();
		}
		ImGui::End();
		ImGui::PopStyleColor();
	}

private:

	int width;
	int height;
	CFontsManager fontsManager;
	CImagesManager imagesManager;

	CTabsHandler handler;
};

#endif // !BODY_HPP