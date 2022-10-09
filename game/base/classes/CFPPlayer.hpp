#pragma once

#ifndef CFPPLAYER_HPP
#define CFPPLAYER_HPP

#include "../math/Vec3_tpl.hpp"
#include "../math/Quat_tpl.hpp"
//#include "../math/Ang3_tpl.hpp"

class CPlayerView {
public:
	struct SFPViewParams {

		Vec3_tpl<float> m_eyeOffsetView;
		Vec3_tpl<float> m_bobOffset;
		Vec3_tpl<float> m_FPWeaponLastDirVec;
		float smoothViewZ;
		Vec3_tpl<float> spectatorTargetPos;
		Vec3_tpl<float> spectatorCamPos;
		float spectatorPosZ;
		Vec3_tpl<float> deathCamPlayerPos;
		Vec3_tpl<float> deathCamKillerPrevPos;
		Quat_tpl<float> deathCamView;
		Quat_tpl<float> deathCamKillView;
		float deathCamKillerFov;
	};
};

class CFPPlayer {
public:

	CPlayerView::SFPViewParams m_FPViewParams;
	Quat_tpl<float> m_viewQuat;
	Quat_tpl<float> m_viewQuatFinal;
	Quat_tpl<float> m_baseQuat;
	bool m_timedemo;
	bool m_ignoreRecoil;
	Vec3_tpl<float> m_viewAnglesOffset;
	Vec3_tpl<float> m_FPWeaponPos;
	Vec3_tpl<float> m_FPWeaponAngles;
	bool m_viewBlending;
};

#endif // !CFPPLAYER_HPP
