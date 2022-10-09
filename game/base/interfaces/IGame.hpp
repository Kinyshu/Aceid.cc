#pragma once

#ifndef IGAME_HPP
#define IGAME_HPP

#include "../classes/CCryAction.hpp"

interface IGame {
public:

	IGameFramework* GetIGameFramework() { 
		return __vtbl< IGameFramework*, 15 >(this); 
	}
};

#endif // !IGAME_HPP