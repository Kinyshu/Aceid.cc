#pragma once

#ifndef CWEAPONLISTENER_HPP
#define CWEAPONLISTENER_HPP

#include "../../managers/hits.hpp"

class CWeaponListener
	: public IGameFrameworkListener {
public:

	CWeaponListener() { 
		DEBUG_LOG("[+] WEAPON, created\n");
	}
	~CWeaponListener() { }

	void OnPreRender() {

		auto gEnv = SSystemGlobalEnvironment::GetInstance();

		auto pGame = gEnv->pGame;
		if (pGame == nullptr) {
			return;
		}

		auto pFramework = pGame->GetIGameFramework();
		if (pFramework == nullptr) {
			return;
		}

		IActor* pPlayer = nullptr;
		if (pFramework->GetClientActorInternal(&pPlayer) == false) {
			return;
		}

		if (pPlayer->IsDead() == true) {
			return;
		}

		auto pItemProxy = pPlayer->GetCurrentItem();
		if (pItemProxy == nullptr) {
			return;
		}

		auto m_weaponExt = reinterpret_cast<CItemProxy*>(pItemProxy)->m_weaponExt;
		if (m_weaponExt == nullptr) {
			return;
		}

		auto pSettings = reinterpret_cast<IWeaponGeneral*>(m_weaponExt)->GetSettings();
		if (pSettings == nullptr) {
			return;
		}

		if (pSettings->m_fireparams->ammo_type_class == nullptr) {
			return;
		}

		auto pParameters = reinterpret_cast<IWeaponGeneral*>(m_weaponExt)->GetParameters();
		if (pParameters == nullptr) {
			return;
		}

		this->CreateRecoil(pParameters);
		this->CreateSpread(pParameters->m_stats);
		this->CreateShutter(pParameters->m_stats);
		this->CreateSway(pParameters);
		this->CreateRpm(pParameters->m_stats);
		this->CreateFastChange(pParameters->m_stats);
		this->CreateAutoReload(m_weaponExt);
		this->CreateMelee(reinterpret_cast<IWeaponGeneral*>(m_weaponExt));
		this->CreateFireMode(reinterpret_cast<CItemProxy*>(pItemProxy));
	}

private:

	void CreateRecoil(CWeaponParameters* pParameters) {

		if (ctx::weapon::recoil::settings) {
			pParameters->m_stats.SetValue(EGameStatType::eGS_RclAtt, ctx::weapon::recoil::attack);
			pParameters->m_stats.SetValue(EGameStatType::eGS_RclDec, ctx::weapon::recoil::decay);
			pParameters->m_stats.SetValue(EGameStatType::eGS_RclDecDelay, ctx::weapon::recoil::decay_delay);
			pParameters->m_stats.SetValue(EGameStatType::eGS_RclMax, ctx::weapon::recoil::max);
			pParameters->m_stats.SetValue(EGameStatType::eGS_RclRnd, ctx::weapon::recoil::random);
			pParameters->m_stats.SetValue(EGameStatType::eGS_RclSmth, ctx::weapon::recoil::smooth);

			if (ctx::weapon::recoil::forced) {
				pParameters->m_recoilCurr = { 0.f, 0.f };
				pParameters->m_recoilDest = { 0.f, 0.f };
				pParameters->m_recoilHintIndex = 0;
				pParameters->m_recoilLastAtt = 0;
				pParameters->m_recoilMulIndex = 0;
			}
		}
	}

	void CreateSpread(CStatsArray& m_stats) {

		if (ctx::weapon::spread::settings) {
			m_stats.SetValue(EGameStatType::eGS_SprdAtt, ctx::weapon::spread::attack);
			m_stats.SetValue(EGameStatType::eGS_SprdDec, ctx::weapon::spread::decay);
			m_stats.SetValue(EGameStatType::eGS_SprdDecDelay, ctx::weapon::spread::decay_delay);
			m_stats.SetValue(EGameStatType::eGS_SprdMax, ctx::weapon::spread::max);
			m_stats.SetValue(EGameStatType::eGS_SprdMin, ctx::weapon::spread::min);
			m_stats.SetValue(EGameStatType::eGS_SprdInverted, ctx::weapon::spread::inverted);
		}
	}

	void CreateShutter(CStatsArray& m_stats) {

		if (ctx::weapon::misc::shutter) {
			m_stats.SetValue(EGameStatType::eGS_BoltAction, 0.f);
			m_stats.SetValue(EGameStatType::eGS_BoltActionDuration, 0.f);
			m_stats.SetValue(EGameStatType::eGS_ZoomedBoltActionDuration, 0.f);
		}
	}

	void CreateSway(CWeaponParameters* pParameters) {

		if (ctx::weapon::misc::sway) {
			pParameters->m_swayCurr = { 0.f, 0.f };
		}
	}

	void CreateRpm(CStatsArray& m_stats) {

		if (ctx::weapon::rpm::settings) {
			m_stats.SetValue(EGameStatType::eGS_Rpm, ctx::weapon::rpm::rpm);
		}
	}

	void CreateFastChange(CStatsArray& m_stats) {

		if (ctx::weapon::misc::fast_change) {
			m_stats.SetValue(EGameStatType::eGS_SelectDuration, 0.f);
			m_stats.SetValue(EGameStatType::eGS_SelectDurationBuff, 0.f);
			m_stats.SetValue(EGameStatType::eGS_DeselectDuration, 0.f);
			m_stats.SetValue(EGameStatType::eGS_DeselectDurationBuff, 0.f);
			m_stats.SetValue(EGameStatType::eGS_InSlotSelectDuration, 0.f);
			m_stats.SetValue(EGameStatType::eGS_InSlotDeselectDuration, 0.f);
		}
	}

	void CreateAutoReload(CWeaponGeneral* m_weaponExt) {

		if (ctx::weapon::misc::manual_reload) {
			
			if (m_weaponExt->IsReloadingAvailable()) {
				m_weaponExt->RequestReload(false);
			}
		}
	}

	void CreateMelee(IWeaponGeneral* m_weaponExt) {

		auto pSettings = m_weaponExt->GetSettings();
		auto pParameters = m_weaponExt->GetParameters();

		if (ctx::weapon::melee::settings) {

			if (ctx::weapon::melee::fast) {

				pParameters->m_stats.SetValue(EGameStatType::eGS_MeleeRes, 0.f);

				pParameters->m_stats.SetValue(EGameStatType::eGS_BayonetMeleeDuration, 0.f);
				pParameters->m_stats.SetValue(EGameStatType::eGS_BayonetMeleeOutDuration, 0.f);

				pParameters->m_stats.SetValue(EGameStatType::eGS_MeleeDuration, 0.f);
				pParameters->m_stats.SetValue(EGameStatType::eGS_MeleeDurationBuff, 0.f);
				pParameters->m_stats.SetValue(EGameStatType::eGS_MeleeOutDuration, 0.f);

				pParameters->m_stats.SetValue(EGameStatType::eGS_SecondaryMeleeDuration, 0.f);
				pParameters->m_stats.SetValue(EGameStatType::eGS_SecondaryMeleeOutDuration, 0.f);
				pParameters->m_stats.SetValue(EGameStatType::eGS_SecondaryMeleeDurationBuff, 0.f);
			}

			if (ctx::weapon::melee::splash && pSettings->m_meleeparams) {
				pSettings->m_meleeparams->m_aoeHeight = 999.f;
				pSettings->m_meleeparams->m_aoe_enabled = true;
				pSettings->m_meleeparams->m_armorAbsorb = true;
				pSettings->m_meleeparams->m_impulse = 999.f;
				pSettings->m_meleeparams->m_noRayTest = true;
				pSettings->m_meleeparams->m_pierceability = 9999;
			}

			if (ctx::weapon::melee::splash && pSettings->m_secondaryMeleeparams) {
				pSettings->m_secondaryMeleeparams->m_aoeHeight = 999.f;
				pSettings->m_secondaryMeleeparams->m_aoe_enabled = true;
				pSettings->m_secondaryMeleeparams->m_armorAbsorb = true;
				pSettings->m_secondaryMeleeparams->m_impulse = 999.f;
				pSettings->m_secondaryMeleeparams->m_noRayTest = true;
				pSettings->m_secondaryMeleeparams->m_pierceability = 9999;
			}
		}

		if (ctx::weapon::melee::distance_settings) {

			pParameters->m_stats.SetValue(EGameStatType::eGS_MeleeRadius, ctx::weapon::melee::lm_distance);
			pParameters->m_stats.SetValue(EGameStatType::eGS_SecondaryMeleeRadius, ctx::weapon::melee::lm_distance);

			pParameters->m_stats.SetValue(EGameStatType::eGS_MeleeRange, ctx::weapon::melee::lm_range);
			pParameters->m_stats.SetValue(EGameStatType::eGS_SecondaryMeleeRange, ctx::weapon::melee::rm_range);
		}
	}

	void CreateFireMode(CItemProxy* pItemProxy) {

		if (ctx::weapon::firemode::settings && ctx::weapon::firemode::bullets_settings) {

			auto pWeapon = reinterpret_cast<IItemProxy*>(pItemProxy)->GetIWeapon();
			auto pWeaponExt = reinterpret_cast<IWeaponGeneral*>(pItemProxy->m_weaponExt);
			auto pSettings = pWeaponExt->GetSettings();

			if (!strstr(pSettings->m_fireparams->ammo_type_class->GetName(), "sr")) {
				return;
			}

			int fireModeIdx = pWeapon->GetCurrentFireMode();
			if (auto m_fireMode = pSettings->m_firemodes[fireModeIdx]) {

				m_fireMode->fireMode = CBaseSettings::EFiremode::eFM_RapidBurst;
				m_fireMode->rpm_burst = 999999;
				m_fireMode->burst_bullet_count = ctx::weapon::firemode::bullets;
			}
		}
	}
};

#endif // !CWEAPONLISTENER_HPP