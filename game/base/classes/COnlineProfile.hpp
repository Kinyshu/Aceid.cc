#pragma once

#ifndef CONLINEPROFILE_HPP
#define CONLINEPROFILE_HPP

#include "CFriendsManager.hpp"

class COnlineProfile {
public:
	ACEID_API CREATE_FUNCTOR(class COnlineAccount*, m_account, 0x18);
	ACEID_API CREATE_FUNCTOR(CFriendsManager*, m_friendManager, 0x20);
};

#endif // !CONLINEPROFILE_HPP