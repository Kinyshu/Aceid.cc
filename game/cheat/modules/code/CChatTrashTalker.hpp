#pragma once

#ifndef CCHATTRASHTALKER_HPP
#define CCHATTRASHTALKER_HPP

#include <fstream>
#include "../../../../hooks/vmt.hpp"

namespace api::trashtalker::words {

	bool ReadWords(std::string path, std::vector<std::string>* buffer) {

		if (buffer->empty() == false) {
			buffer->clear();
		}

		std::ifstream input(path.c_str());
		if (input.is_open() == false) {
			return false;
		}

		std::string line;
		while (std::getline(input, line)) {
			buffer->push_back(line);
		}

		input.close();
		return buffer->empty() == false;
	}

	std::vector< std::string > answers;
	std::vector< std::string > kills;
	std::vector< std::string > suicide;
	std::vector< std::string > spam;

}

class CChatTrashTalker
	: public IOnlineChatRoomListener {
public:

	CChatTrashTalker() {

		this->gEnv = SSystemGlobalEnvironment::GetInstance();
		this->pFramework = this->gEnv->pGame->GetIGameFramework();
	}

	void OnChatRoomMessage(const char* nickname, const char* message, bool isPrivate) {
		
		auto pActorSystem = this->pFramework->GetIActorSystem();
		if (pActorSystem == nullptr) {
			return;
		}

		auto m_pLobbyChat = reinterpret_cast<CGame*>(gEnv->pGame)->m_pLobbyChat;
		if (m_pLobbyChat == nullptr) {
			return;
		}

		auto pActor = pActorSystem->FindActorByName(nickname);
		if (pActor) {

			auto eCC_Room = m_pLobbyChat->eCC_Room;
			if (eCC_Room) {
				eCC_Room->SendMessage(std::string(nickname + std::string(" ") + api::trashtalker::words::answers[rand() % api::trashtalker::words::answers.size()]).c_str());
			}
		}
	}

private:

	IGameFramework* pFramework;
	SSystemGlobalEnvironment* gEnv;
};

namespace api::trashtalker {

	namespace hooks {

		CChatTrashTalker* pChatListener;

		ACEID_API CREATE_VMT_HOOK(IOnlineChatRoom*, GetChatRoom, nullptr,
			WITH_ARGUMENTS(IOnlineChat* m_ptr, const char* argv1, const char* argv2)) {

			auto pChatRoom = GetChatRoom_Original(m_ptr, argv1, argv2);
			if (pChatRoom) {

				if (pChatListener) {
					pChatRoom->UnregisterListener(pChatListener);
					pChatListener = nullptr;
				}

				pChatListener = new CChatTrashTalker();
				pChatRoom->RegisterListener(pChatListener);
			}

			return pChatRoom;
		}

		ACEID_API CREATE_VMT_HOOK(void, OnKillMessage, nullptr,
			WITH_ARGUMENTS(CGameRules* m_ptr, unsigned int targetId, __int64 shooterId, const char* weaponClassName, float damage, int material, int hit_type)) {

			auto gEnv = SSystemGlobalEnvironment::GetInstance();
			auto pFramework = gEnv->pGame->GetIGameFramework();

			auto pActorSystem = pFramework->GetIActorSystem();
			if (pActorSystem) {

				auto m_pLobbyChat = reinterpret_cast<CGame*>(gEnv->pGame)->m_pLobbyChat;
				if (m_pLobbyChat) {

					auto eCC_Room = m_pLobbyChat->eCC_Room;
					if (eCC_Room) {

						IActor* pPlayer = nullptr;
						pFramework->GetClientActorInternal(&pPlayer);

						CActor* pTarget = pActorSystem->FindActorById(targetId);
						CActor* pShooter = pActorSystem->FindActorById(static_cast<EntityId>(shooterId));

						if (pPlayer && pTarget && pShooter) {

							if (targetId == shooterId) {
								eCC_Room->SendMessage(
									std::string(std::string(u8"Лол, игрок \"") + reinterpret_cast<IActor*>(pTarget)->m_pEntity->GetName() 
										+ std::string(u8"\", совершил суицид, помянем")).c_str()
								);
							}

							if (pShooter == reinterpret_cast<CActor*>(pPlayer)) {
								eCC_Room->SendMessage(
									std::string(std::string(u8"Бигнейм \"") + reinterpret_cast<IActor*>(pShooter)->m_pEntity->GetName()
										+ std::string(u8"\", изи дропнул пёсика \"") + reinterpret_cast<IActor*>(pTarget)->m_pEntity->GetName() + std::string(u8"\"")).c_str()
								);
							}

							if (pShooter->m_teamId == reinterpret_cast<CActor*>(pPlayer)->m_teamId) {
								eCC_Room->SendMessage(
									std::string(std::string(u8"Лол, игрок \"") + reinterpret_cast<IActor*>(pShooter)->m_pEntity->GetName()
										+ std::string(u8"\", изи дропнул пёсика \"") + reinterpret_cast<IActor*>(pTarget)->m_pEntity->GetName() + std::string(u8"\"")).c_str()
								);
							}
						}
					}
				}
			}

			OnKillMessage_Original(m_ptr, targetId, shooterId, weaponClassName, damage, material, hit_type);
		}
		
		bool b_on_kill_hook_updated = false;
	}

	void Create() {
#if TRASH_TALKER_COMPILE == 1

		printf("[+] MODULES, Module \"TrashTalker 1.5\" created\n");

		api::trashtalker::words::ReadWords("C:\\Aceid.cc\\modules\\TrashTalker\\answers.msg", &api::trashtalker::words::answers);
		api::trashtalker::words::ReadWords("C:\\Aceid.cc\\modules\\TrashTalker\\kills.msg", &api::trashtalker::words::kills);
		api::trashtalker::words::ReadWords("C:\\Aceid.cc\\modules\\TrashTalker\\spam.msg", &api::trashtalker::words::spam);
		api::trashtalker::words::ReadWords("C:\\Aceid.cc\\modules\\TrashTalker\\suicide.msg", &api::trashtalker::words::suicide);

		hooks::GetChatRoom_Pointer = new CVMTHandler(reinterpret_cast<std::uintptr_t**>(
			IOnline::GetInstance()->GetConnection("game")->GetChat("conference.warface"))
		);

		hooks::GetChatRoom_Original = hooks::GetChatRoom_Pointer->hook(3, hooks::GetChatRoom_Hook);

#endif // TRASH_TALKER_COMPILE == 1
	}

	void Update() {
#if TRASH_TALKER_COMPILE == 1

		if (hooks::b_on_kill_hook_updated == false) {

			hooks::OnKillMessage_Pointer = nullptr;
			hooks::OnKillMessage_Pointer = new CVMTHandler(reinterpret_cast<std::uintptr_t**>(
				SSystemGlobalEnvironment::GetInstance()->pGame->GetIGameFramework()->GetGameRules())
			);

			hooks::OnKillMessage_Original = hooks::OnKillMessage_Pointer->hook(78, hooks::OnKillMessage_Hook);

			hooks::b_on_kill_hook_updated = true;
		}

#endif // TRASH_TALKER_COMPILE == 1
	}
}

#endif // !CCHATTRASHTALKER_HPP