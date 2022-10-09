#pragma once

#ifndef VISUALS_HPP
#define VISUALS_HPP

class CVisualsTab {
public:

	bool create() {

		if (context::initializer[eUIT_Visuals] == false) {

			context::tabs[eUIT_Visuals].push_back({ "Visuals.Pov", false, "Drawing" });
			context::tabs[eUIT_Visuals].push_back({ "Visuals.Environment", true, "Environment" });

			context::initializer[eUIT_Visuals] = true;
		}

		return true;
	}

	void update(context::STabData buffer) {

		this->data.size = buffer.size;
		this->data.position = buffer.position;
		this->data.fontsManager = buffer.fontsManager;
		this->data.imagesManager = buffer.imagesManager;
	}

	void render() {

		ImGui::PushFont(this->data.fontsManager.get("GothamPro-Light", 26.f));		
		ImGui::SetCursorPos({ 125.f - (ImGui::CalcTextSize(u8"Окружение").x / 2), 25.f });
		ImGui::Text(u8"Окружение");
		ImGui::PopFont();

		drawhelper::tabButton(this->data, context::tabs[eUIT_Visuals]);

		ImGui::PushFont(this->data.fontsManager.get("__MAIN__", 18.f));
		for (auto tab : context::tabs[eUIT_Visuals]) {

			if (tab.description == "Environment" && tab.variable == true) {

				ImGui::SetCursorPos({ 0.f, 80.f });
				ImGui::BeginChild("##ContextMenu", { 250.f, 420.f });
				{
					ImVec2 position = ImGui::GetWindowPos();
					ImGui::GetWindowDrawList()->AddRectFilled(CALC(position.x, position.y, 250.f, 420.f), ImColor(30, 30, 30), 12.f, ImDrawFlags_::ImDrawFlags_RoundCornersBottomLeft);

				}
				ImGui::EndChild();
			}

			if (tab.description == "Drawing" && tab.variable == true) {

				ImGui::SetCursorPos({ 0.f, 80.f });
				ImGui::BeginChild("##ContextMenu", { 250.f, 420.f });
				{
					ImVec2 position = ImGui::GetWindowPos();
					ImGui::GetWindowDrawList()->AddRectFilled(CALC(position.x, position.y, 250.f, 420.f), ImColor(30, 30, 30), 12.f, ImDrawFlags_::ImDrawFlags_RoundCornersBottomLeft);
				}
				ImGui::EndChild();
			}

		}
		ImGui::PopFont();
	}

private:
	context::STabData data;
};

#endif // !VISUALS_HPP