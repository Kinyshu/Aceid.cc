#pragma once

#ifndef GAME_HPP
#define GAME_HPP

/*
 online_id: 126110933@warface/GameClient
 profileId: 46145523
 nickname: (NickName)
 status: 9
 placeToken: @ui_playerinfo_inlobby
 placeInfoToken:
 modeInfoToken:
 missionInfoToken:
 experience: 1274000


 online_id: 129450106@warface/GameClient
 profileId: 1193962
 nickname:
 status: 9
 placeToken: @ui_playerinfo_inlobby
 placeInfoToken:
 modeInfoToken:
 missionInfoToken:
 experience: 1274000
*/

namespace render {

	void OnGameRender(ImVec2 screen, CFontsManager fm, CImagesManager im) {

		auto gEnv = SSystemGlobalEnvironment::GetInstance();
		auto pGame = reinterpret_cast<CGame*>(gEnv->pGame);

		if (GetAsyncKeyState(VK_TAB)) {

			auto m_pOnlineAccount = pGame->m_pOnlineAccount;

			if (m_pOnlineAccount) {

				char buffer[1024];
				sprintf(buffer, u8"Информация об аккаунте\nИд: %d\nРегион: %s\nСтатус подключения: %d",
					m_pOnlineAccount->m_userId, m_pOnlineAccount->m_regionId.m_str, m_pOnlineAccount->m_state
				);

				ImGui::SetNextWindowPos(ImVec2(0.f, 500.f));
				ImGui::SetNextWindowSize(ImVec2(250.f, 175.f));
				ImGui::PushStyleVar(ImGuiStyleVar_::ImGuiStyleVar_WindowRounding, 0.f);
				ImGui::PushStyleColor(ImGuiCol_::ImGuiCol_WindowBg, ImColor(15, 15, 15).operator ImVec4());
				ImGui::Begin("##StatsGUI", 0, ImGuiWindowFlags_NoTitleBar |
					ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings |
					ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
				{
					ImVec2 position = ImGui::GetWindowPos();
					ImGui::GetWindowDrawList()->AddRectFilled(CALC(position.x, position.y, 250.f, 45.f), ImColor(25, 25, 25));

					ImGui::PushFont(fm.get("__MAIN__", 26.f));
					ImGui::GetWindowDrawList()->AddText({ position.x + 15.f, position.y + 8.f }, ImColor(255, 255, 255), u8"Игровая статистика");
					ImGui::PopFont();

					ImGui::PushFont(fm.get("__MAIN__", 20.f));
					ImGui::SetCursorPos({ 15.f, 55.f });
					ImGui::Text(buffer);

					auto m_channel = m_pOnlineAccount->m_channel;
					if (m_channel) {
						if (m_channel->m_serverList.empty() == false) {

							int online = 0;
							for (auto it : m_channel->m_serverList) {
								online += it.online_users;
							}

							ImGui::SetCursorPos({ 15.f, 145.f });
							ImGui::Text(std::string(u8"Текущий онлайн: " + std::to_string(online)).c_str());
						}
					}

					ImGui::PopFont();
				}
				ImGui::End();
				ImGui::PopStyleVar();
				ImGui::PopStyleColor();
			}
		}
	}
}

#endif // !GAME_HPP