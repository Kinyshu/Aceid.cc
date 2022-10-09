#pragma once

#ifndef ENETREALIABILITYTYPE_HPP
#define ENETREALIABILITYTYPE_HPP

enum ENetReliabilityType {

	eNRT_ReliableOrdered = 0x0,
	eNRT_ReliableUnordered = 0x1,
	eNRT_UnreliableOrdered = 0x2,
	eNRT_UnreliableUnordered = 0x3,
	eNRT_NumReliabilityTypes = 0x4
};

#endif // !ENETREALIABILITYTYPE_HPP