#pragma once

#ifndef QUAT_TPL_HPP
#define QUAT_TPL_HPP

#include "Vec3_tpl.hpp"

template <typename T>
struct Quat_tpl {

	Vec3_tpl< T > v;
	T w;

	Quat_tpl() { }
};

#endif // !QUAT_TPL_HPP