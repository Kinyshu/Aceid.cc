#pragma once

#ifndef CPLAYER_HPP
#define CPLAYER_HPP

#include "CActor.hpp"
#include "CFPPlayer.hpp"
#include "../structures/SSpecialMovementState.hpp"

class CPlayer 
	: CActor {
public:

	ESMType GetActiveSM() {
		return this->m_SMState->activeSM;
	}

public:

	ACEID_API CREATE_FUNCTOR(CFPPlayer*, m_fpPlayer, 0xD10);
	ACEID_API CREATE_FUNCTOR_STRUCT(SSpecialMovementState, m_SMState, 0xF98);
};

#endif // !CPLAYER_HPP