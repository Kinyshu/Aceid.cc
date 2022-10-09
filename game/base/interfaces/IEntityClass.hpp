#pragma once

#ifndef IENTITYCLASS_HPP
#define IENTITYCLASS_HPP

interface IEntityClass {

	enum EventValueType {

		EVT_INT = 0x0,
		EVT_FLOAT = 0x1,
		EVT_BOOL = 0x2,
		EVT_VECTOR = 0x3,
		EVT_ENTITY = 0x4,
		EVT_STRING = 0x5,
	};

	struct SEventInfo {

		const char* name;
		EventValueType type;
		bool bOutput;
	};

	virtual void Function0() = 0;
	virtual void Function1() = 0;
	virtual const char* GetName() = 0;
};

#endif // !IENTITYCLASS_HPP