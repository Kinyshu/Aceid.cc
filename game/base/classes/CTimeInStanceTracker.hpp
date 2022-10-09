#pragma once

#ifndef CTIMEINSTANCETRACKER_HPP
#define CTIMEINSTANCETRACKER_HPP

#include "../enums/EParamStance.hpp"

class CTimeInStanceTracker {

	EParamStance m_curStance;
	EParamStance m_dstStance;
	bool m_isTransiting;
	float m_timeTransiting;
	float m_thresholdMult;
};

#endif // !CTIMEINSTANCETRACKER_HPP