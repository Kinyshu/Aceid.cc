#pragma once

#ifndef CPLAYERLISTENER_HPP
#define CPLAYERLISTENER_HPP

class CPlayerListener
	: public IGameFrameworkListener {
public:

	CPlayerListener() {
		DEBUG_LOG("[+] PLAYER, created\n");
	}
	~CPlayerListener() { }

	void OnPreRender() {

		auto gEnv = SSystemGlobalEnvironment::GetInstance();

		auto pGame = gEnv->pGame;
		if (pGame == nullptr) {
			return;
		}

		auto pFramework = pGame->GetIGameFramework();
		if (pFramework == nullptr) {
			return;
		}

		IActor* pPlayer = nullptr;
		if (pFramework->GetClientActorInternal(&pPlayer) == false) {
			return;
		}
	}
};

#endif // !CPLAYERLISTENER_HPP