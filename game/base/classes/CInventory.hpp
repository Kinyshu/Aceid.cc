#pragma once

#ifndef CINVENTORY_HPP
#define CINVENTORY_HPP

#include "../interfaces/IInventory.hpp"

#include "CEntityClass.hpp"
#include "CGameObjectExtensionHelper.hpp"

interface IInventoryListener { };

class CInventory
	: CGameObjectExtensionHelper<CInventory, IInventory, 64> {
public:

	struct SAmmoInfo {

		int count;
		int users;
		int capacity;
	};

	struct SSlotInfo {

		unsigned int count;
		unsigned int maxCapacity;
		unsigned int lastSelected;
	};

	struct SInventoryStats {

		std::vector<unsigned int, std::allocator<unsigned int> > slots;
		std::vector<IEntityClass*, std::allocator<IEntityClass*> > accessorySlots;
		std::map<IEntityClass*, SAmmoInfo, std::less<IEntityClass*>, std::allocator<std::pair<IEntityClass* const, SAmmoInfo> > > ammoInfo;
		SSlotInfo slotsInfo[3];
		std::map<CryStringT<char>, EInventorySlots, std::less<CryStringT<char> >, std::allocator<std::pair<CryStringT<char> const, EInventorySlots> > > categoriesToSlot;
		std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<IEntityClass* const, CInventory::SAmmoInfo> > > > ammoIterator;
		IEntityClass* tossItem;
		unsigned int currentItemId;
		unsigned int holsteredItemId;
		unsigned int lastItemId;
	};
public:
	CInventory::SInventoryStats m_stats;
	CInventory::SInventoryStats m_editorstats;
	std::vector<IInventoryListener*, std::allocator<IInventoryListener*> > m_listeners;
	interface IGameFramework* m_pGameFrameWork;
	interface IActor* m_pActor;
	bool m_bSerializeLTL;
	bool m_iteratingListeners;
	bool m_ignoreNextClear;
};

#endif // !CINVENTORY_HPP