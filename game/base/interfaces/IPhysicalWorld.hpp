#pragma once

#ifndef IPHYSICALWORLD_HPP
#define IPHYSICALWORLD_HPP

#include "../structures/ray_hit.hpp"
#include "../structures/pe_type.hpp"
#include "../structures/SCollisionClass.hpp"

interface IPhysicalWorld {

	struct SRWIParams {

		void* pForeignData;
		int iForeignData;
		int(__fastcall* OnEvent)(const void*);
		Vec3_tpl<float> org;
		Vec3_tpl<float> dir;
		int objtypes;
		unsigned int flags;
		ray_hit* hits;
		int nMaxHits;
		ray_hit_cached* phitLast;
		int nSkipEnts;
		interface IPhysicalEntity** pSkipEnts;
		SCollisionClass collclass;
	};

};

#endif // !IPHYSICALWORLD_HPP
