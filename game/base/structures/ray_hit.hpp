#pragma once

#ifndef RAY_HIT_HPP
#define RAY_HIT_HPP

struct ray_hit_cached {

	interface IPhysicalEntity* pCollider;
	int ipart;
	int iNode;
};

const struct ray_hit {

	float dist;
	interface IPhysicalEntity* pCollider;
	int ipart;
	int partid;
	__int16 surface_idx;
	__int16 idmatOrg;
	int foreignIdx;
	int iNode;
	Vec3_tpl<float> pt;
	Vec3_tpl<float> n;
	int bTerrain;
	int iPrim;
	ray_hit* next;
};

#endif // !RAY_HIT_HPP