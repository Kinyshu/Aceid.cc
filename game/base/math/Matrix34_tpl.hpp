#pragma once

#ifndef MATRIX34_TPL_HPP
#define MATRIX34_TPL_HPP

#include "Vec3_tpl.hpp"

template <typename T>
struct Matrix34_tpl {

	T m00; T m01; T m02;
	T m03; T m10; T m11;
	T m12; T m13; T m20;
	T m21; T m22; T m23;

	Vec3_tpl<T> GetTranslation() const { return Vec3_tpl<T>(m03, m13, m23); }
	void SetTranslation(const Vec3_tpl<T>& t) { m03 = t.x;  m13 = t.y; m23 = t.z; }
};

#endif // !MATRIX34_TPL_HPP