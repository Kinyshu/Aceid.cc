#pragma once

#ifndef CFIREMODEOBJECTBASE_HPP
#define CFIREMODEOBJECTBASE_HPP

#include "CTimeValue.hpp"
#include "../interfaces/IFireModeObject.hpp"

class CFireModeObjectBase
	: IFireModeObject {

	class CWeaponGeneral* m_pWeapon;
	CTimeValue m_lastFireTime;
	CTimeValue m_lastServerTime;
};

#endif // !CFIREMODEOBJECTBASE_HPP