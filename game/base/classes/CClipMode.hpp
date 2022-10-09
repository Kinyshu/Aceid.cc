#pragma once

#ifndef CCLIPMODE_HPP
#define CCLIPMODE_HPP

#include "../interfaces/IClipMode.hpp"

class CClipMode 
	: IClipMode {
public:

	bool m_unlimited;
	int m_ammoCount;
	bool m_isBarrel;
	class CWeaponGeneral* m_weapon;
};

#endif // !CCLIPMODE_HPP