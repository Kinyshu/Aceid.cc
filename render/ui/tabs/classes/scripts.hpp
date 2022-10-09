#pragma once

#ifndef SCRIPTS_HPP
#define SCRIPTS_HPP

class CScriptsTab {
public:

	bool create() {

		if (context::initializer[eUIT_Scripts] == false) {

			context::tabs[eUIT_Scripts].push_back({ "Scripts.Python", false, "Python" });
			context::tabs[eUIT_Scripts].push_back({ "Scripts.Lua", true, "Game LUA" });

			context::initializer[eUIT_Scripts] = true;
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
		ImGui::SetCursorPos({ 125.f - (ImGui::CalcTextSize(u8"Скриптинг").x / 2), 25.f });
		ImGui::Text(u8"Скриптинг");
		ImGui::PopFont();

		drawhelper::tabButton(this->data, context::tabs[eUIT_Scripts]);

		ImGui::PushFont(this->data.fontsManager.get("__MAIN__", 18.f));
		for (auto tab : context::tabs[eUIT_Scripts]) {

			if (tab.description == "Game LUA" && tab.variable == true) {

				ImGui::SetCursorPos({ 0.f, 80.f });
				ImGui::BeginChild("##ContextMenu", { 250.f, 420.f });
				{
					ImVec2 position = ImGui::GetWindowPos();
					ImGui::GetWindowDrawList()->AddRectFilled(CALC(position.x, position.y, 250.f, 420.f), ImColor(30, 30, 30), 12.f, ImDrawFlags_::ImDrawFlags_RoundCornersBottomLeft);

				}
				ImGui::EndChild();
			}

			if (tab.description == "Python" && tab.variable == true) {

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

#endif // !SCRIPTS_HPP