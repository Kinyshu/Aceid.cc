#pragma once

#ifndef CLOCALPROFILECONFIG_HPP
#define CLOCALPROFILECONFIG_HPP

#include "CryStringT.hpp"

class CLocalProfileConfig {
public:

	CryStringT<char> m_cfg_path;
	std::set<CryStringT<char>, std::less<CryStringT<char> >, std::allocator<CryStringT<char> > > m_tracked_vars;
};


#endif // !CLOCALPROFILECONFIG_HPP