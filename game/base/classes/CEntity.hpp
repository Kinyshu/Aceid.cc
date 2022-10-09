#pragma once

#ifndef CENTITY_HPP
#define CENTITY_HPP

#include "../interfaces/IEntity.hpp"
#include "../math/Vec3_tpl.hpp"

class CEntity
	: IEntity {
public:

	ACEID_API CREATE_FUNCTOR(Vec3_tpl< float >, m_vPos, 0x70);
};

#endif // !CENTITY_HPP