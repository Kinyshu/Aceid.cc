#pragma once

#ifndef IGAMEFRAMEWORK_HPP
#define IGAMEFRAMEWORK_HPP

#include "../classes/CPlayer.hpp"
#include "IGameFrameworkListener.hpp"
#include "../classes/CActorSystem.hpp"

#include "../classes/CGameRules.hpp"

interface IGameFramework {
public:

	CActorSystem* GetIActorSystem() {
		return __vtbl< CActorSystem*, 25 >(this);
	}

	CTimeValue* GetServerTime(CTimeValue* result) {
		return __vtbl< CTimeValue*, 73 >(this, result);
	}

	void RegisterListener(IGameFrameworkListener* pGameFrameworkListener, const char* name,
		EFRAMEWORKLISTENERPRIORITY eFrameworkListenerPriority) {
		__vtbl< void, 108 >(this, pGameFrameworkListener, name, eFrameworkListenerPriority); 
	}

	void UnregisterListener(IGameFrameworkListener* pGameFrameworkListener) { 
		__vtbl< void, 109 >(this, pGameFrameworkListener); 
	}

	CGameRules* GetGameRules() {
		return __vtbl< CGameRules*, 137 >(this);
	}

	char GetClientActorInternal(IActor** pOutActor) {
		return __vtbl< char, 142 >(this, pOutActor);
	}
};

#endif // !IGAMEFRAMEWORK_HPP
