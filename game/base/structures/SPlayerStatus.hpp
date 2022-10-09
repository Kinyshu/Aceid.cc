#pragma once

#ifndef SPLAYERSTATUS_HPP
#define SPLAYERSTATUS_HPP

#include "../classes/CryStringT.hpp"

struct SPlayerStatus {

	enum Status {

		Offline = 0x0,
		Online = 0x1,
		Logout = 0x2,
		Away = 0x4,
		InLobby = 0x8,
		InGameRoom = 0x10,
		InGame = 0x20,
		InShop = 0x40,
		InCustomize = 0x80,
		InRatingGame = 0x100,
		InTutorialGame = 0x200,
		BannedInRatingGame = 0x400,
		BannedInPvpAutostartGame = 0x800,
	};

	enum Group {

		Online_Group = 0x0,
		AdditionalState_Group = 0x1,
		PreGame_Group = 0x2,
		Inventory_Group = 0x3,
		Num_Groups = 0x4,
	};

	int value;
	CryStringT<char> placeToken;
	CryStringT<char> placeInfoToken;
	CryStringT<char> modeInfoToken;
	CryStringT<char> missionInfoToken;
};

#endif // !SPLAYERSTATUS_HPP