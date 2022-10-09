#pragma once

#ifndef CONLINECHANNEL_HPP
#define CONLINECHANNEL_HPP

#include "../structures/SMasterServerInfo.hpp"

using V_SERVER_LIST = std::vector<SMasterServerInfo, std::allocator<SMasterServerInfo>>;

class COnlineChannel {
public:
	ACEID_API CREATE_FUNCTOR(V_SERVER_LIST, m_serverList, 0xB8);
};

#endif // !CONLINECHANNEL_HPP
