#pragma once

#ifndef CONLINEVARIABLES_HPP
#define CONLINEVARIABLES_HPP

#include "CryStringT.hpp"

class COnlineVariables {

	std::map<CryStringT<char>, CryStringT<char>, std::less<CryStringT<char> >, std::allocator<std::pair<CryStringT<char> const, CryStringT<char> > > > m_dedicatedCVars;
	std::map<CryStringT<char>, CryStringT<char>, std::less<CryStringT<char> >, std::allocator<std::pair<CryStringT<char> const, CryStringT<char> > > > m_vars;
};

#endif // !CONLINEVARIABLES_HPP