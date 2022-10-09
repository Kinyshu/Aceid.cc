#pragma once

#ifndef SFRIENDINFO_HPP
#define SFRIENDINFO_HPP

#include "../classes/CryStringT.hpp"
#include "SPlayerStatus.hpp"

struct SFriendInfo {

	CryStringT<char> online_id;
	unsigned __int64 profileId;
	CryStringT<char> nickname;
	SPlayerStatus status;
	unsigned __int64 experience;
};

#endif // !SFRIENDINFO_HPP