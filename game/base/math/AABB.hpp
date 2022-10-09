#pragma once

#ifndef AABB_HPP
#define AABB_HPP

#include "Vec3_tpl.hpp"

struct AABB {
	Vec3_tpl<float> min;
	Vec3_tpl<float> max;
};

#endif // !AABB_HPP
