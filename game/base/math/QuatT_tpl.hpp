#pragma once

#ifndef QUATT_TPL_HPP
#define QUATT_TPL_HPP

#include "Quat_tpl.hpp"

template <typename T>
struct QuatT_tpl {

	Quat_tpl< T > q;
	Vec3_tpl< T > t;
};

#endif // !QUATT_TPL_HPP