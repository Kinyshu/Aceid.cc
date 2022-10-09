#pragma once

#ifndef CFRAMEPROFILERSECTION_HPP
#define CFRAMEPROFILERSECTION_HPP

//#include "CFrameProfiler.hpp"

const class CFrameProfilerSection {
public:
	__int64 m_startTime;
	__int64 m_excludeTime;
	__int64 m_yieldTime;
	class CFrameProfiler* m_pFrameProfiler;
	CFrameProfilerSection* m_pParent;
};


#endif // !CFRAMEPROFILERSECTION_HPP