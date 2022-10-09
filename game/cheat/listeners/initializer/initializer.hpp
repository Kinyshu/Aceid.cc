#pragma once

#ifndef INITIALIZER_HPP
#define INITIALIZER_HPP

#include "../../../../hooks/vmt.hpp"
#include "../actions/CActionsListener.hpp"

#include "../functions/CWeaponListener.hpp"
#include "../functions/CPlayerListener.hpp"

class CInitializerListener 
	: public IGameFrameworkListener {
public:

	CInitializerListener() {

		DEBUG_LOG("[+] INITIALIZER, created\n");
	}
	~CInitializerListener() { }

	void OnActionEvent(const SActionEvent& event) {

		auto gEnv = SSystemGlobalEnvironment::GetInstance();
		auto pGame = reinterpret_cast<CGame*>(gEnv->pGame);

		if (this->bInitialized == false) {

			DEBUG_LOG("[+] INITIALIZER, started\n");

			reinterpret_cast<IGame*>(pGame)->GetIGameFramework()->RegisterListener(new CActionsListener(), 0, FRAMEWORKLISTENERPRIORITY_GAME);

			reinterpret_cast<IGame*>(pGame)->GetIGameFramework()->RegisterListener(new CWeaponListener(), 0, FRAMEWORKLISTENERPRIORITY_GAME);
			reinterpret_cast<IGame*>(pGame)->GetIGameFramework()->RegisterListener(new CPlayerListener(), 0, FRAMEWORKLISTENERPRIORITY_GAME);
			reinterpret_cast<IGame*>(pGame)->GetIGameFramework()->UnregisterListener(this);
			rpc::Create("discord code");

			this->bInitialized = true;
		}

		if (event.m_value == eAE_loadLevel) {
			reinterpret_cast<IGame*>(pGame)->GetIGameFramework()->UnregisterListener(this);
		}
	}

private:
	bool bInitialized = false;
};

#endif // !INITIALIZER_HPP