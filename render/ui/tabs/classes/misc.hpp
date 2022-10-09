#pragma once

#ifndef MISC_HPP
#define MISC_HPP

class CMiscTab {
public:

	bool create() {

		if (context::initializer[eUIT_Misc] == false) {

			context::tabs[eUIT_Misc].push_back({ "Misc.Modules", true, "Modules" });

			context::initializer[eUIT_Misc] = true;
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
		ImGui::SetCursorPos({ 125.f - (ImGui::CalcTextSize(u8"Разное").x / 2), 25.f });
		ImGui::Text(u8"Разное");
		ImGui::PopFont();

		drawhelper::tabButton(this->data, context::tabs[eUIT_Misc]);

		ImGui::PushFont(this->data.fontsManager.get("__MAIN__", 18.f));
		for (auto tab : context::tabs[eUIT_Misc]) {

			if (tab.description == "Modules" && tab.variable == true) {

				ImGui::SetCursorPos({ 0.f, 80.f });
				ImGui::BeginChild("##ContextMenu", { 250.f, 420.f });
				{
					ImVec2 position = ImGui::GetWindowPos();
					ImGui::GetWindowDrawList()->AddRectFilled(CALC(position.x, position.y, 250.f, 420.f), ImColor(30, 30, 30), 12.f, ImDrawFlags_::ImDrawFlags_RoundCornersBottomLeft);

					ImGui::SetCursorPosY(15.f);
					drawhelper::beginModule("TrashTalker", u8"спамит и отвечает в чате", "1.4", "Kinyshu", this->data.imagesManager, this->data.fontsManager);
				}
				ImGui::EndChild();
			}

		}
		ImGui::PopFont();
	}

private:
	context::STabData data;
};

#endif // !MISC_HPP