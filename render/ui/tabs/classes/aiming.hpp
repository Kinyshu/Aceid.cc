#pragma once

#ifndef AIMING_HPP
#define AIMING_HPP

class CAimingTab {
public:

	bool create() {

		if (context::initializer[eUIT_Aiming] == false) {

			context::tabs[eUIT_Aiming].push_back({ "Aiming.Trigger", false, "Trigger" });
			context::tabs[eUIT_Aiming].push_back({ "Aiming.Pve", false, "PVE" });
			context::tabs[eUIT_Aiming].push_back({ "Aiming.Pvp", true, "PVP" });

			context::initializer[eUIT_Aiming] = true;
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
		ImGui::SetCursorPos({ 125.f - (ImGui::CalcTextSize(u8"Наводка").x / 2), 25.f });
		ImGui::Text(u8"Наводка");
		ImGui::PopFont();

		drawhelper::tabButton(this->data, context::tabs[eUIT_Aiming]);

		ImGui::PushFont(this->data.fontsManager.get("__MAIN__", 18.f));
		for (auto tab : context::tabs[eUIT_Aiming]) {

			if (tab.description == "PVE" && tab.variable == true) {

				ImGui::SetCursorPos({ 0.f, 80.f });
				ImGui::BeginChild("##ContextMenu", { 250.f, 420.f });
				{
					ImVec2 position = ImGui::GetWindowPos();
					ImGui::GetWindowDrawList()->AddRectFilled(CALC(position.x, position.y, 250.f, 420.f), ImColor(30, 30, 30), 12.f, ImDrawFlags_::ImDrawFlags_RoundCornersBottomLeft);

				}
				ImGui::EndChild();
			}

			if (tab.description == "PVP" && tab.variable == true) {

				ImGui::SetCursorPos({ 0.f, 80.f });
				ImGui::BeginChild("##ContextMenu", { 250.f, 420.f });
				{
					ImVec2 position = ImGui::GetWindowPos();
					ImGui::GetWindowDrawList()->AddRectFilled(CALC(position.x, position.y, 250.f, 420.f), ImColor(30, 30, 30), 12.f, ImDrawFlags_::ImDrawFlags_RoundCornersBottomLeft);

				}
				ImGui::EndChild();
			}

			if (tab.description == "Trigger" && tab.variable == true) {

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
	bool initialized = false;
	context::STabData data;

};

#endif // !AIMING_HPP