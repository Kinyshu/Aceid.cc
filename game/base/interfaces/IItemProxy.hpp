#pragma once

#ifndef IITEMPROXY_HPP
#define IITEMPROXY_HPP

#include "IItem.hpp"
#include "IWeapon.hpp"

interface IItemProxy
	: IItem {

	IWeapon* GetIWeapon() {
		return __vtbl< IWeapon*, 79 >(this);
	}
};

#endif // !IITEMPROXY_HPP