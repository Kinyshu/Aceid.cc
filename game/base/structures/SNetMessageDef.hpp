#pragma once

#ifndef SNETMESSAGEDEF_HPP
#define SNETMESSAGEDEF_HPP

#include "../enums/ENetReliabilityType.hpp"

struct SNetMessageDef {

	void* handler;//std::pair<bool, INetAtSyncItem*>* (__fastcall* handler)(std::pair<bool, INetAtSyncItem*>* result, unsigned int, INetMessageSink*, CSerializeWrapper<ISerialize>, unsigned int, unsigned int, unsigned int*, INetChannel*);
	const char* description;
	ENetReliabilityType reliability;
	unsigned int nUser;
	unsigned int parallelFlags;
};

#endif // !SNETMESSAGEDEF_HPP
