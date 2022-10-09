#pragma once

#ifndef CACTIONSLISTENER_HPP
#define CACTIONSLISTENER_HPP

#include "actions.hpp"
#include "../../../base/namespaces/SM_Network.hpp"
#include "../../../../render/ui/modules/chrono/sleep.hpp"

class CActionsListener
	: public IGameFrameworkListener {
public:

	CActionsListener() {
		DEBUG_LOG("[+] ACTIONS, created\n");
	}

	void OnPreRender() {

		auto gEnv = SSystemGlobalEnvironment::GetInstance();
		auto pGame = reinterpret_cast<CGame*>(gEnv->pGame);

		auto m_pFlowchartManager = pGame->m_pFlowchartManager;
		if (m_pFlowchartManager) {

			switch (m_pFlowchartManager->m_currentState) {
				
			case EFlowchartState::eFS_Ingame:
				actions::OnInGame();
				break;

			case EFlowchartState::eFS_Lobby:
				actions::OnInLobby();
				break;

			case EFlowchartState::eFS_LoadingLobby:
				actions::OnLoadingLobby();
				break;

			case EFlowchartState::eFS_LoadingLevel:
				actions::OnLoadingLevel();
				break;

			case EFlowchartState::eFS_PostGame:			
				actions::OnPostGame();
				break;
			}
		}

		if (this->bInitialized == false) {
			api::trashtalker::Create();
			this->bInitialized = true;
		}
	}

	void OnActionEvent(const SActionEvent& event) { }

private:
	bool bInitialized = false;
};

#endif // !CACTIONSLISTENER_HPP