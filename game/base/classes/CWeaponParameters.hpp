#pragma once

#ifndef CWEAPONPARAMETERS_HPP
#define CWEAPONPARAMETERS_HPP

#include "../math/Vec2_tpl.hpp"
#include "../math/Vec3_tpl.hpp"
#include "../classes/CMaskedVarT.hpp"

#include "CParamBlock.hpp"
#include "CStatsArray.hpp"
#include "CTimeInStanceTracker.hpp"

#include "../enums/EParamStance.hpp"

class CWeaponParameters {
public:

	interface IWeaponParamsVisitor { virtual void Function0() = 0; };
	struct CWeaponParamsVisitor 
		: IWeaponParamsVisitor {
		std::vector<CBaseSettings::SFireModeParams*, std::allocator<CBaseSettings::SFireModeParams*>> fireModeParams;
		bool isSilenced;
		bool hasBayonet;
		std::vector<CParamBlock const*, std::allocator<CParamBlock const*> > m_active;
	};
public:

	int GetClipSize() {
		return static_cast<int>(this->m_stats.GetValue(eGS_AmmoAmount));
	}

public:

	Vec2_tpl<float> m_lastSwayMin;
	Vec2_tpl<float> m_lastSwayMinRate;
	float m_lastSwayDec;
	float m_lastSwayDecRate;
	float m_prevSwaySpeedMult;
	float m_stepLength;
	bool m_isSwaySynchronized;
	CMaskedVarT<float, unsigned int, 4294967295> m_spreadLastAtt;
	CMaskedVarT<float, unsigned int, 4294967295> m_spreadCurr;
	CMaskedVarT<float, unsigned int, 4294967295> m_recoilLastAtt;
	Vec2_tpl<float> m_recoilCurr;
	Vec2_tpl<float> m_recoilDest;
	CMaskedVarT<float, unsigned int, 4294967295> m_swayCycle;
	Vec2_tpl<float> m_swayCurr;
	class CWeaponGeneral* m_weapon;
	CStatsArray m_stats; // 68hex
	int m_recoilHintIndex;
	int m_spreadMulIndex;
	int m_recoilMulIndex;
	int m_bulletIdxInBurst;
	float m_lastShot;
	EParamStance m_savedStance;
	CTimeInStanceTracker m_timeInStanceTracker;
	CWeaponParamsVisitor* m_paramsVisitor;
	std::vector<CParamBlock const*, std::allocator<CParamBlock const*> > m_externalParamBlocks;
	const CParamBlock* m_performanceParamBlock;
};

#endif // !CWEAPONPARAMETERS_HPP