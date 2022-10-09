#pragma once

#ifndef CSCRIPTTABLE_HPP
#define CSCRIPTTABLE_HPP

#include "../interfaces/IScriptTable.hpp"

class CScriptTable
	: IScriptTable {

	int m_nRefCount;
	int m_nRef;
};

#endif // !CSCRIPTTABLE_HPP