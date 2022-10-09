#pragma once

#ifndef CFRIENDSLISTENER_HPP
#define CFRIENDSLISTENER_HPP

#include "../interfaces/IFriendsManager.hpp"

class CFriendsManager
	: IFriendsManager {
public:
	
	ACEID_API CREATE_FUNCTOR(V_FRIEND_INFO, m_friends, 0x30);
};

#endif // !CFRIENDSLISTENER_HPP