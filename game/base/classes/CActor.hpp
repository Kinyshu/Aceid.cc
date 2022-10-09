#pragma once

#ifndef CACTOR_HPP
#define CACTOR_HPP

#include "CInventory.hpp"
#include "../enums/EStance.hpp"
#include "../interfaces/IActor.hpp"
#include "../namespaces/Game.hpp"
#include "../namespaces/SM_Network.hpp"
#include "../structures/SStanceInfo.hpp"

#include "CScriptSystem.hpp"

struct SHitParticleAttInfo {

	CryStringT<char> name;
	CTimeValue creationTime;
	CTimeValue lifeTime;
};

class CActor 
	: CGameObjectExtensionHelper<CActor, IActor, 128> {
public:

	class CHitParticleAtt {
	public:

		std::vector<SHitParticleAttInfo> m_particleAtt;
		CActor* m_owner;
		int m_attCount;
	};

public:
	bool IsStand() {
		return this->m_stance == STANCE_STAND;
	}

	bool IsCrouch() {
		return this->m_stance == STANCE_CROUCH;
	}

	bool IsProne() {
		return this->m_stance == STANCE_PRONE;
	}

	std::tuple< int, Vec3_tpl<float> > GetBonePosition(EBonesID id) {

		int index;
		Vec3_tpl<float> position;

		if (this->GetBonePos(&position, id, 0, &index)) {

			auto current = reinterpret_cast<CEntity*>(this->m_pEntity)->m_vPos;
			auto output = current + position;

			return { index,  output };
		}
		else {
			return { -1, Vec3_tpl<float>(0, 0, 0) };
		}
	}
public:

	void SetModel(IScriptSystem* pScriptSystem, const char* model) {

		auto script = api::format(
			R"(
local Entity = System.GetEntity(%d);
Entity.Properties.fileModel = "%s";
			)", this->m_entityId, model
		);

		pScriptSystem->ExecuteBuffer(script.c_str(), script.size());
		this->NetworkUpdateCharacterParams();
		this->SetActorModel();
		this->Revive(1);
	}
public:

	ACEID_API CREATE_FUNCTOR(IInventory*, m_pInventory, 0x38);
	ACEID_API CREATE_FUNCTOR(bool, m_isClient, 0x70);
	ACEID_API CREATE_FUNCTOR(EStance, m_stance, 0xE0); 									// default: -1
	ACEID_API CREATE_FUNCTOR(EStance, m_desiredStance, 0xE8); 							// default: STANCE_STAND
	ACEID_API CREATE_FUNCTOR(SStanceInfo*, m_stances, 0xEC); 							// m_stances[8]
	ACEID_API CREATE_FUNCTOR_STRUCT(SmartScriptTable, m_actorStats, 0x3A0);
	ACEID_API CREATE_FUNCTOR(int, m_teamId, 0x3E0);
	ACEID_API CREATE_FUNCTOR_STRUCT(Game::SCharacterParams, m_characterParams, 0x438);
	ACEID_API CREATE_FUNCTOR(ICompoundCharacter*, m_actorCC, 0xA08);
	ACEID_API CREATE_FUNCTOR(ICompoundCharacter*, m_itemCC, 0xA10);
	ACEID_API CREATE_FUNCTOR(CryStringT<char>, m_actorModel, 0xA20);
	ACEID_API CREATE_FUNCTOR(CHitParticleAtt*, m_hitParticleAtt, 0xA38);
	ACEID_API CREATE_FUNCTOR(unsigned __int8, m_netPhysCounter, 0xC74);
	ACEID_API CREATE_FUNCTOR(CryStringT<char>, m_currModel, 0xC78);
};

#endif // !CACTOR_HPP