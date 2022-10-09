#pragma once

#ifndef IMOVEMENTCONTROLLER_HPP
#define IMOVEMENTCONTROLLER_HPP

#include "../math/AABB.hpp"
#include "../math/Vec2_tpl.hpp"
#include "../math/Vec3_tpl.hpp"

#include "../enums/EStance.hpp"

struct SStanceState {

	Vec3_tpl<float> pos;
	Vec3_tpl<float> entityDirection;
	Vec3_tpl<float> animationBodyDirection;
	Vec3_tpl<float> upDirection;
	Vec3_tpl<float> weaponPosition;
	Vec3_tpl<float> aimDirection;
	Vec3_tpl<float> fireDirection;
	Vec3_tpl<float> eyePosition;
	Vec3_tpl<float> eyeDirection;
	AABB m_StanceSize;
	AABB m_ColliderSize;
};

struct SMovementState 
	: SStanceState {

	Vec3_tpl<float> fireTarget;
	EStance stance;
	Vec3_tpl<float> animationEyeDirection;
	Vec3_tpl<float> movementDirection;
	Vec3_tpl<float> lastMovementDirection;
	float desiredSpeed;
	float minSpeed;
	float normalSpeed;
	float maxSpeed;
	float slopeAngle;
	bool atMoveTarget;
	bool isAiming;
	bool isVisible;
};

interface IMovementController {

	virtual void DIMovementController();
	virtual bool RequestMovement(const class CMovementRequest* request);
	virtual void GetMovementState(SMovementState* state);
	virtual bool GetStanceState(const struct SStanceStateQuery* query, SStanceState* state);
	virtual Vec2_tpl<float>* GetDesiredMoveDir(Vec2_tpl<float>* result);
};

#endif // !IMOVEMENTCONTROLLER_HPP
