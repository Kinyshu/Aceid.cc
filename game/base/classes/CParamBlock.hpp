#pragma once

#ifndef CPARAMBLOCK_HPP
#define CPARAMBLOCK_HPP

#include "../math/math.hpp"
#include "../enums/EGameStatType.hpp"

#include "CMaskedVarT.hpp"
#include "CryStringT.hpp"

using EGameParameterType = EGameStatType;

class CParamBlock
	: _reference_target<int> {
public:

	struct SParam {

		CMaskedVarT<float, unsigned int, 4294967295> values[19];
		bool custom[19];
	};
public:

	std::map<EGameParameterType, CParamBlock::SParam, std::less<EGameParameterType>, std::allocator<std::pair<EGameParameterType const, CParamBlock::SParam> > > m_params;
	CryStringT<char> m_name;
};

#endif // !CPARAMBLOCK_HPP