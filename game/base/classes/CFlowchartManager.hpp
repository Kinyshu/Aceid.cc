#pragma once

#ifndef CFLOWCHARTMANAGER_HPP
#define CFLOWCHARTMANAGER_HPP

enum EFlowchartState {

	eFS_None = 0xFFFFFFFF,
	eFS_First = 0x0,
	eFS_NoUI = 0x0,
	eFS_Login = 0x1,
	eFS_LoadingLobby = 0x2,
	eFS_CharacterCreation = 0x3,
	eFS_Lobby = 0x4,
	eFS_LoadingLevel = 0x5,
	eFS_Ingame = 0x6,
	eFS_Renaming = 0x7,
	eFS_PromoTutorial = 0x8,
	eFS_PostGame = 0x9,
	eFS_Count = 0xA,
};

class CFlowchartManager {
public:

	ACEID_API CREATE_FUNCTOR(EFlowchartState, m_currentState, 0x30);
};

#endif // !CFLOWCHARTMANAGER_HPP
