#pragma once

#ifndef SETTINGS_HPP
#define SETTINGS_HPP

class CSettingsTab {
public:

	bool create() {

		if (context::initializer[eUIT_Settings] == false) {

			context::tabs[eUIT_Settings].push_back({ "Settings.Config", false, "Config" });
			context::tabs[eUIT_Settings].push_back({ "Settings.Brush", true, "Design" });

			context::initializer[eUIT_Settings] = true;
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
		ImGui::SetCursorPos({ 125.f - (ImGui::CalcTextSize(u8"���������").x / 2), 25.f });
		ImGui::Text(u8"���������");
		ImGui::PopFont();

		drawhelper::tabButton(this->data, context::tabs[eUIT_Settings]);

		ImGui::PushFont(this->data.fontsManager.get("__MAIN__", 18.f));
		for (auto tab : context::tabs[eUIT_Settings]) {

			if (tab.description == "Design" && tab.variable == true) {

				ImGui::SetCursorPos({ 0.f, 80.f });
				ImGui::BeginChild("##ContextMenu", { 250.f, 420.f });
				{
					ImVec2 position = ImGui::GetWindowPos();
					ImGui::GetWindowDrawList()->AddRectFilled(CALC(position.x, position.y, 250.f, 420.f), ImColor(30, 30, 30), 12.f, ImDrawFlags_::ImDrawFlags_RoundCornersBottomLeft);

					ImGui::SetCursorPos({ 10.f, 10.f });
					drawhelper::beginContextMenu("##HeaderStyleMenu", u8"������ �����", { 230.f, 90.f });
					{
						drawhelper::checkBox(u8"����", &context::style::header::b_style_color);
						drawhelper::checkBox(u8"�����������", &context::style::header::b_style_image);
					}
					drawhelper::endContextMenu();

					ImGui::SetCursorPosX(10.f);
					drawhelper::beginContextMenu("##BodyStyleMenu", u8"������ ����", { 230.f, 90.f });
					{
						drawhelper::checkBox(u8"�����������", &context::style::body::b_style_color);
					}
					drawhelper::endContextMenu();
				}
				ImGui::EndChild();

				ImGui::SetCursorPos({ 260.f, 90.f });
				ImGui::BeginChild("##TabsPanel", { 480.f, 400.f });
				{
					if (context::style::header::b_style_color) {

						drawhelper::beginContextMenu("##HeaderColorMenu", u8"��������� ����� �����", { 430.f, 90.f });
						{
							ImGui::SetCursorPosX(15.f);
							ImGui::ColorEdit3(u8"��������� ������", &context::style::header::ic_header_button_color.Value.x);

							ImGui::SetCursorPosX(15.f);
							ImGui::ColorEdit4(u8"���� �����", &context::style::header::ic_header_mask_color.Value.x, 0, 0.245f);
						}
						drawhelper::endContextMenu();
					}

					if (context::style::header::b_style_image) {

						drawhelper::beginContextMenu("##HeaderImageMenu", u8"��������� ����������� �����", { 430.f, 65.f });
						{
							drawhelper::checkBox(u8"�������� �����������", &context::style::header::b_draw_image);
						}
						drawhelper::endContextMenu();
					}

					if (context::style::body::b_style_color) {

						drawhelper::beginContextMenu("##BodyColorMenu", u8"��������� ����� ����", { 430.f, 130.f });
						{
							drawhelper::checkBox(u8"��������� ������� ��� �������� ����", &context::b_ui_variable_draw_snow);
						}
						drawhelper::endContextMenu();
					}
				}
				ImGui::EndChild();
			}
		}
		ImGui::PopFont();
	}

private:
	context::STabData data;
};

#endif // !SETTINGS_HPP