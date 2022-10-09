#pragma once

#ifndef IINVENTORY_HPP
#define IINVENTORY_HPP

#include "IGameObjectExtension.hpp"

interface IInventory
	: IGameObjectExtension {

	enum EInventorySlots {

		eInventorySlot_Weapon = 0x0,
		eInventorySlot_Explosives = 0x1,
		eInventorySlot_Grenades = 0x2,
		eInventorySlot_Last = 0x3,
	};
};

#endif // !IINVENTORY_HPP