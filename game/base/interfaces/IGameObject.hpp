#pragma once

#ifndef IGAMEOBJECT_HPP
#define IGAMEOBJECT_HPP

#include "../classes/CEntity.hpp"
#include "IMovementController.hpp"

interface IGameObject {

	ACEID_API CREATE_FUNCTOR(EntityId, m_entityId, 0x8);
	ACEID_API CREATE_FUNCTOR(IMovementController*, m_pMovementController, 0x10);
	ACEID_API CREATE_FUNCTOR(IEntity*, m_pEntity, 0x10);
};

#endif // !IGAMEOBJECT_HPP