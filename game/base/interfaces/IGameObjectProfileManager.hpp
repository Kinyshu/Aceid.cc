#pragma once

#ifndef IGAMEOBJECTPROFILEMANAGER_HPP
#define IGAMEOBJECTPROFILEMANAGER_HPP

#include "../enums/EEntityAspects.hpp"

interface IGameObjectProfileManager {

	virtual void vecDelDtor() = 0;
	virtual bool SetAspectProfile(EEntityAspects aspect, char profile) = 0;
	virtual char GetDefaultProfile(EEntityAspects aspect) = 0;
};

#endif // !IGAMEOBJECTPROFILEMANAGER_HPP