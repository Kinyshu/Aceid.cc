#pragma once

#ifndef SCRIPTANYVALUE_HPP

enum ScriptAnyType {

	ANY_ANY = 0x0,
	ANY_TNIL = 0x1,
	ANY_TBOOLEAN = 0x2,
	ANY_THANDLE = 0x3,
	ANY_TNUMBER = 0x4,
	ANY_TSTRING = 0x5,
	ANY_TTABLE = 0x6,
	ANY_TFUNCTION = 0x7,
	ANY_TUSERDATA = 0x8,
	ANY_TVECTOR = 0x9,
	ANY_COUNT = 0xA,
};

enum ScriptVarType {

	svtNull = 0x0,
	svtString = 0x1,
	svtNumber = 0x2,
	svtBool = 0x3,
	svtFunction = 0x4,
	svtObject = 0x5,
	svtPointer = 0x6,
	svtUserData = 0x7,
};

struct ScriptAnyValue {

	ScriptAnyType type;
	union {

		bool b;
		float number;
		const char* str;
		interface IScriptTable* table;
		const void* ptr;
		struct SScriptFuncHandle* function;

		struct { 
			float x, y, z;
		}vec3;
		
		struct {
			void* ptr;
			int nRef;
		}ud;
	};
};

#endif // !SCRIPTANYVALUE_HPP
