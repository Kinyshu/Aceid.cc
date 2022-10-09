/* MAIN.CC */

/*
	~~~ ACEID.CC SOURCE CODE, WRITED BY KINYSHU ~~~
	
	Social:
	 VK - @kinyshu
	 TG - @yushkin
*/
#include "stdafx.hpp"

BOOL WINAPI DllMain(HMODULE handle, DWORD reason, LPVOID reserved) {

	UNREFERENCED_PARAMETER(handle);
	UNREFERENCED_PARAMETER(reserved);

#if DEBUG_COMPILE == 1
	::AllocConsole();
	::SetConsoleTitleA("Aceid.cc");
	::freopen("CONOUT$", "w", stdout);
#endif

	switch (reason) {

		case DLL_PROCESS_ATTACH: {

			DEBUG_LOG("[+] Welcome to Aceid.cc\n");
			DEBUG_LOG("[+] Software version 3.0, build 0.6a\n\n");

			api::mrc(&dxhook::create);

#if GUI_COMPILE == 0
			auto gEnv = SSystemGlobalEnvironment::GetInstance();
			gEnv->pGame->GetIGameFramework()->RegisterListener(new CInitializerListener(), 0, EFRAMEWORKLISTENERPRIORITY::FRAMEWORKLISTENERPRIORITY_DEFAULT);
#endif

		} break;

		case DLL_PROCESS_DETACH: break;
		case DLL_THREAD_ATTACH: break;
		case DLL_THREAD_DETACH: break;
	}

	return TRUE;
}