#pragma once

#ifndef HITS_HPP
#define HITS_HPP

class CSHManager {
public:

	struct SClientGameHitInfoEx {

		SClientGameHitInfoEx(EntityId targetId, int materialId, int typeId, int partId, 
			Vec3_tpl<float> position, float damageReduction, unsigned __int8 physCounter) :
			targetId(targetId), materialId(materialId), typeId(typeId), partId(partId),
			position(position), damageReduction(damageReduction), physCounter(physCounter) { }

		EntityId targetId;				/* 0x0 */
		int materialId;					/* 0x4 */
		int typeId;						/* 0x8 */
		int partId;						/* 0xC */
		Vec3_tpl<float> position;		/* 0x10 */
		float damageReduction;			/* 0x1C */
		unsigned __int8 physCounter;	/* 0x20 */
	};

	struct SClientGameProjectilesInfo {

		SClientGameProjectilesInfo(EntityId projectileId, std::vector<SClientGameHitInfoEx> hit) :
			projectileId(projectileId), hit(hit) { }

		EntityId projectileId;
		std::vector<SClientGameHitInfoEx> hit;
	};

	struct SClientGameMultiHitInfo {

		Vec3_tpl<float> shootPosition;
		int predictionHandle;		  
		Vec3_tpl<float> velocity;  
		unsigned __int8 physCounter;
		std::vector<std::pair<EntityId, std::vector<SClientGameHitInfoEx>>> projectiles;
		unsigned __int8 fireCounter;
		float spreadMax;
		bool b_unknown;
		CTimeValue previousTime;
		CTimeValue nextTime;
		unsigned int ui_unknown;
		int ammoCount;
		Vec3_tpl<float> direction;
	};

	using FN_SvRequestShootHit = void(__fastcall*)(IGameObject*, const SGameObjectExtensionRMI* method, const SClientGameMultiHitInfo* params, unsigned int, int);
	void SvRequestShootHit(IGameObject* pGameObject, const SClientGameMultiHitInfo* params) {
		FN_SvRequestShootHit(0x14132C480)(pGameObject, *reinterpret_cast<SGameObjectExtensionRMI**>(0x1421C4190), params, 0, 0);
	}

	void send(IActor* pActor, std::vector<std::pair<EntityId, std::vector<SClientGameHitInfoEx>>> projectiles) {

		SClientGameMultiHitInfo m_hits;
		::memset(&m_hits, 0, sizeof SClientGameMultiHitInfo);
		{
			m_hits.shootPosition = SSystemGlobalEnvironment::GetInstance()->pRenderer->SetGetCamera(0, 0)->m_Matrix.GetTranslation();
			m_hits.physCounter = *(unsigned __int8*)(pActor + 0xc74);
		}

		this->SvRequestShootHit(pActor->GetCurrentItem()->m_pGameObject, &m_hits);
	}
};

#endif // !HITS_HPP