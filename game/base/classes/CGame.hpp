#pragma once

#ifndef CGAME_HPP
#define CGAME_HPP

#include "../interfaces/IGame.hpp"

#include "CHUD.hpp"
#include "CLobbyChat.hpp"
#include "COnlineAccount.hpp"
#include "CFlowchartManager.hpp"
#include "CPlayerStatus.hpp"

class CGame 
	: IGame {
public:

	ACEID_API CREATE_FUNCTOR(CHUD*, m_pHUD, 0x110); 								// Find: Libs/UI/HUD_Network_Icon.gfx
	ACEID_API CREATE_FUNCTOR(CFlowchartManager*, m_pFlowchartManager, 0x210); 		// Find: FlowchartManager
	ACEID_API CREATE_FUNCTOR(CLobbyChat*, m_pLobbyChat, 0x218);
	ACEID_API CREATE_FUNCTOR(COnlineAccount*, m_pOnlineAccount, 0x240);				// Find: bootstrap
	ACEID_API CREATE_FUNCTOR(CPlayerStatus*, m_playerStatus, 0x318);				// COA
};

#endif // !CGAME_HPP