#pragma once

#ifndef SGAMEOBJECTEXTENSIONRMI_HPP
#define SGAMEOBJECTEXTENSIONRMI_HPP

#include "../enums/ERMIAttachmentType.hpp"
#include "../enums/ENetReliabilityType.hpp"

#include "SNetMessageDef.hpp"

struct SGameObjectExtensionRMI {

	void* decoder;//INetAtSyncItem* (__fastcall* decoder)(CSerializeWrapper<ISerialize>, unsigned int*, INetChannel*);
	const char* description;
	const void* pBase;
	SNetMessageDef* pMsgDef;
	ERMIAttachmentType attach;
	bool isServerCall;
	bool lowDelay;
	ENetReliabilityType reliability;
};

#endif // !SGAMEOBJECTEXTENSIONRMI_HPP
