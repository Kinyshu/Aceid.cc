#pragma once

#ifndef CSCRIPTSYSTEM_HPP
#define CSCRIPTSYSTEM_HPP

#include "../interfaces/IScriptSystem.hpp"

struct SmartScriptTable {
	IScriptTable* p;
};

class CScriptSystem
	: IScriptSystem {
public:
};

#endif // !CSCRIPTSYSTEM_HPP