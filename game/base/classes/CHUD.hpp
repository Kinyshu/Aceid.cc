#pragma once

#ifndef CHUD_HPP
#define CHUD_HPP

#include "CHUDCommon.hpp"
#include "CHUDTweakMenu.hpp"
#include "CHUDSilhouettes.hpp"

class CHUD
	: public CHUDCommon {
public:

	ACEID_API CREATE_FUNCTOR(CHUDTweakMenu*, m_pHUDTweakMenu, 0x70);
	ACEID_API CREATE_FUNCTOR(CHUDSilhouettes*, m_pHUDSilhouettes, 0x88);

	ACEID_API CREATE_FUNCTOR(int, m_playerAmmo, 0xCC);
	ACEID_API CREATE_FUNCTOR(int, m_playerClipSize, 0xD4);
	ACEID_API CREATE_FUNCTOR(int, m_iGrenadeAmmo, 0xC8);

	// IFFont* m_pDefaultFont; // 0xB0
	// v4->RegisterListener(v4, &this->IGameFrameworkListener, "hud", FRAMEWORKLISTENERPRIORITY_HUD);
}; 

#endif // !CHUD_HPP