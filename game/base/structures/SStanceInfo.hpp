#pragma once
#ifndef SSTANCEINFO_HPP
#define SSTANCEINFO_HPP

#include "../math/Vec3_tpl.hpp"

struct SStanceInfo {

	float heightCollider;
	float heightPivot;
	bool useCapsule;
	Vec3_tpl<float> size;
	Vec3_tpl<float> viewOffset;
	float maxSpeed;
	char name[32];
	Vec3_tpl<float> modelOffset;
};

#endif // !SSTANCEINFO_HPP