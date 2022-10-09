#pragma once

#ifndef SSYSTEMGLOBALENVIRONMENT_HPP
#define SSYSTEMGLOBALENVIRONMENT_HPP

#include "SPlatformInfo.hpp"

#include "../classes/CGame.hpp"
#include "../classes/CRenderer.hpp"
#include "../classes/CScriptSystem.hpp"
#include "../classes/CPhysicalWorld.hpp"

struct SSystemGlobalEnvironment {
public:
	ACEID_API CREATE_FUNCTOR(IScriptSystem*, pScriptSystem, 0x40);
	ACEID_API CREATE_FUNCTOR(IRenderer*, pRenderer, 0x48);
	ACEID_API CREATE_FUNCTOR(IPhysicalWorld*, pPhysicalWorld, 0x70);
	ACEID_API CREATE_FUNCTOR(IGame*, pGame, 0xD0);

	static SSystemGlobalEnvironment* GetInstance() {
		return *reinterpret_cast<SSystemGlobalEnvironment**>(0x1420F5B80);
	}
};

#endif // !SSYSTEMGLOBALENVIRONMENT_HPP