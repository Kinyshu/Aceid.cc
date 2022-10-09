#pragma once

#ifndef CWEAPONNETWORK_HPP
#define CWEAPONNETWORK_HPP

class CWeaponNetwork {
public:

	struct ReloadParams {
		bool manual;
	};

public:

	class CWeaponGeneral* m_weapon;
};

#endif // !CWEAPONNETWORK_HPP
