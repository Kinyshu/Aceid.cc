#pragma once

#ifndef CSTATSARRAY_HPP
#define CSTATSARRAY_HPP

#include "../enums/EGameStatType.hpp"

class CStatsArray {
public:

	void SetValue(EGameStatType type, float value) {

		auto it = m_stats.find(type);
		if (it != m_stats.end()) {
			it->second = value;
		}
	}

	float GetValue(EGameStatType type) {

		auto it = m_stats.find(type);
		if (it == m_stats.end()) {
			return 1072.0f;
		}

		return it->second;
	}

private:
	std::map<short, CMaskedVarT<float, unsigned int>> m_stats;
};


#endif // !CSTATSARRAY_HPP