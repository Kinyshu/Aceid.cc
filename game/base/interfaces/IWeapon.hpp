#pragma once

#ifndef IWEAPON_HPP
#define IWEAPON_HPP

interface IWeapon {

	int GetCurrentFireMode() {
		return __vtbl< int, 30 >(this);
	}
};

#endif // !IWEAPON_HPP