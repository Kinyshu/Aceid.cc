#pragma once

#ifndef IENTITY_HPP
#define IENTITY_HPP

interface IEntity {

	const char* GetName() {
		return __vtbl< const char*, 13 >(this);
	}
};

#endif // !IENTITY_HPP