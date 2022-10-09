#pragma once

#ifndef WEAPON_HPP
#define WEAPON_HPP

class CWeaponTab {
public:

	CWeaponTab() {}

	bool create() {

		if (context::initializer[eUIT_Weapon] == false) {

			context::tabs[eUIT_Weapon].push_back({ "Weapon.Knife", false, "Melee" });
			context::tabs[eUIT_Weapon].push_back({ "Weapon.Crosshair", true, "Firing" });

			context::initializer[eUIT_Weapon] = true;
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
		ImGui::SetCursorPos({ 125.f - (ImGui::CalcTextSize(u8"Оружие").x / 2), 25.f });
		ImGui::Text(u8"Оружие");
		ImGui::PopFont();

		drawhelper::tabButton(this->data, context::tabs[eUIT_Weapon]);

		ImGui::PushFont(this->data.fontsManager.get("__MAIN__", 18.f));
		for (auto tab : context::tabs[eUIT_Weapon]) {

			if (tab.description == "Firing" && tab.variable == true) {
				ImGui::SetCursorPos({ 0.f, 80.f });
				ImGui::BeginChild("##ContextMenu", { 250.f, 420.f });
				{
					ImVec2 position = ImGui::GetWindowPos();
					ImGui::GetWindowDrawList()->AddRectFilled(CALC(position.x, position.y, 250.f, 420.f), ImColor(30, 30, 30), 12.f, ImDrawFlags_::ImDrawFlags_RoundCornersBottomLeft);
				}
				ImGui::EndChild();
			}

			if (tab.description == "Melee" && tab.variable == true) {
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

#endif // !WEAPON_HPP