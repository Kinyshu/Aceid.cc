#pragma once

#ifndef SAUTHPROFILEINFO_HPP
#define SAUTHPROFILEINFO_HPP

#include "../classes/CryStringT.hpp"

struct SAuthProfileInfo {

	unsigned __int64 profile_id;
	CryStringT<char> nickname;
	CryStringT<char> head;
};

#endif // !SAUTHPROFILEINFO_HPP