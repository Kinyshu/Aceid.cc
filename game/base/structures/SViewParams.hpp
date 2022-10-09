#pragma once

#ifndef SVEIWPARAMS_HPP
#define SVEIWPARAMS_HPP

#include "../math/Vec3_tpl.hpp"
#include "../math/Quat_tpl.hpp"

struct SViewParams {

	Vec3_tpl<float> position;
	Quat_tpl<float> rotation;
	Quat_tpl<float> localRotationLast;
	float nearplane;
	float fov;
	char viewID;
	bool groundOnly;
	float shakingRatio;
	Quat_tpl<float> currentShakeQuat;
	Vec3_tpl<float> currentShakeShift;
	unsigned int idTarget;
	Vec3_tpl<float> targetPos;
	float frameTime;
	float angleVel;
	float vel;
	float dist;
	bool blend;
	float blendPosSpeed;
	float blendRotSpeed;
	float blendFOVSpeed;
	Vec3_tpl<float> blendPosOffset;
	Quat_tpl<float> blendRotOffset;
	float blendFOVOffset;
	bool justActivated;
	char viewIDLast;
	Vec3_tpl<float> positionLast;
	Quat_tpl<float> rotationLast;
	float FOVLast;
};

#endif // !SVEIWPARAMS_HPP