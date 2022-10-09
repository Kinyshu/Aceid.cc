#pragma once

#ifndef CPLAYERSTATUS_HPP
#define CPLAYERSTATUS_HPP

#include "../structures/SPlayerStatus.hpp"

class CPlayerStatus /* : public IFlowchartListener, public IInputEventListener */ {
public:

public:
	ACEID_API CREATE_FUNCTOR(float, m_afkTime, 0x10);
	ACEID_API CREATE_FUNCTOR_STRUCT(SPlayerStatus, m_playerStatus, 0x18);
};

#endif // !CPLAYERSTATUS_HPP