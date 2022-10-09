#pragma once

#ifndef GAME_HPP_
#define GAME_HPP_

#include "../classes/CCompoundCharacter.hpp"
#include "../classes/CryStringT.hpp"

#include "../enums/ECharacterClassId.hpp"

namespace Game {

	struct SCharacterParams {

		ICompoundCharacter::EGender m_gender;
		float m_scale;
		float m_fatness;
		CryStringT<char> m_customHead;
		ECharacterClassId m_currentClass;
	};

}

#endif // !GAME_HPP_