#pragma once

#ifndef PLAYER_HPP
#define PLAYER_HPP

class CPlayerTab {
public:

	bool create() {

		if (context::initializer[eUIT_Player] == false) {

			context::tabs[eUIT_Player].push_back({ "Player.ServerMovement", false, "Debug" });
			context::tabs[eUIT_Player].push_back({ "Player.Movement", true, "Movement" });

			context::initializer[eUIT_Player] = true;
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
		ImGui::SetCursorPos({ 125.f - (ImGui::CalcTextSize(u8"Персонаж").x / 2), 25.f });
		ImGui::Text(u8"Персонаж");
		ImGui::PopFont();

		drawhelper::tabButton(this->data, context::tabs[eUIT_Player]);

		ImGui::PushFont(this->data.fontsManager.get("__MAIN__", 18.f));
		for (auto tab : context::tabs[eUIT_Player]) {

			if (tab.description == "Movement" && tab.variable == true) {

				ImGui::SetCursorPos({ 0.f, 80.f });
				ImGui::BeginChild("##ContextMenu", { 250.f, 420.f });
				{
					ImVec2 position = ImGui::GetWindowPos();
					ImGui::GetWindowDrawList()->AddRectFilled(CALC(position.x, position.y, 250.f, 420.f), ImColor(30, 30, 30), 12.f, ImDrawFlags_::ImDrawFlags_RoundCornersBottomLeft);
				}
				ImGui::EndChild();
			}

			if (tab.description == "Debug" && tab.variable == true) {

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

#endif // !PLAYER_HPP