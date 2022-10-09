#pragma once

#ifndef IACTOR_HPP
#define IACTOR_HPP

#include "../classes/CEntity.hpp"
#include "../classes/CGameObjectExtensionHelper.hpp"
#include "../classes/CItemProxy.hpp"

#include "../enums/EBonesID.hpp"
#include "../math/Vec3_tpl.hpp"

#include "../interfaces/IMovementController.hpp"

interface IActor 
	: IGameObjectExtension {
public:
	int GetHealth() {
		return __vtbl< int, 28 >(this);
	}

	bool IsDead() {
		return this->GetHealth() <= 0;
	}

	IItemProxy* GetCurrentItem() {
		return __vtbl< IItemProxy*, 58 >(this);
	}

	IMovementController* GetMovementController() {
		return __vtbl< IMovementController*, 62 >(this);
	}

	void SetThirdPerson(bool bValue) {
		__vtbl< void, 67 >(this, bValue);
	}

	bool GetBonePos(Vec3_tpl<float>* pos, EBonesID ID, int slot, int* pBoneIndex) {
		return __vtbl< bool, 158 >(this, pos, ID, slot, pBoneIndex);
	}

	void Revive(bool bFromInit) {
		return __vtbl< void, 127 >(this, bFromInit);
	}

	void LocalRevive() {
		return __vtbl< void, 167 >(this);
	}

	void SetActorModel() {
		return __vtbl< void, 169 >(this);
	}

	void NetworkUpdateCharacterParams() {
		return __vtbl< void, 181 >(this);
	}
};

#endif // !IACTOR_HPP*