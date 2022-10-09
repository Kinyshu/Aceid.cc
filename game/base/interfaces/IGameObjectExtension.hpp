#pragma once

#ifndef IGAMEOBJECTEXTENSION_HPP
#define IGAMEOBJECTEXTENSION_HPP

#include "../classes/CEntity.hpp"
#include "../classes/CGameObject.hpp"

interface IGameObjectExtension {

	ACEID_API CREATE_FUNCTOR(int, m_nReserved, 0x8);
	ACEID_API CREATE_FUNCTOR(IEntity*, m_pEntity, 0x10);
	ACEID_API CREATE_FUNCTOR(IGameObject*, m_pGameObject, 0x18);
	ACEID_API CREATE_FUNCTOR(EntityId, m_entityId, 0x20);
};

#endif // !IGAMEOBJECTEXTENSION_HPP
