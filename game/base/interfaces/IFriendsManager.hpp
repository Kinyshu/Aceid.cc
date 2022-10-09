#pragma once

#ifndef IFRIENDSLISTENER_HPP
#define IFRIENDSLISTENER_HPP

#include "../structures/SFriendInfo.hpp"

using V_FRIEND_INFO = std::vector<SFriendInfo, std::allocator<SFriendInfo>>;

interface IFriendsManager {

	V_FRIEND_INFO* GetFriends() {
		return __vtbl< V_FRIEND_INFO*, 3 >(this);
	}

	void AddFriend(const char* nickname) {
		__vtbl< void, 4 >(this, nickname);
	}

	void RemoveFriend(const char* nickname) {
		__vtbl< void, 5 >(this, nickname);
	}

	char IsFriend(const char* nickname) {
		return __vtbl< char, 7 >(this, nickname);
	}
};

#endif // !IFRIENDSLISTENER_HPP