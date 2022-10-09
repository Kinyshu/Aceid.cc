#pragma once

#ifndef MATH_HPP
#define MATH_HPP

template <typename T>
struct __declspec(align(8)) _reference_target {
	virtual void Function0() = 0;
	T m_nRefCounter;
};

namespace math {

	float _sqrt(float number) {

		long i;
		float x2, y;
		const float threehalfs = 1.5F;

		x2 = number * 0.5F;
		y = number;
		i = *(long*)&y;
		i = 0x5f3759df - (i >> 1);
		y = *(float*)&i;
		y = y * (threehalfs - (x2 * y * y));
		y = y * (threehalfs - (x2 * y * y));
		y = y * (threehalfs - (x2 * y * y));

		return 1 / y;
	}
}

#endif // !MATH_HPP
