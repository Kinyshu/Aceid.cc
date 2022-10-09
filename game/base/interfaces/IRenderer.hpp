#pragma once

#ifndef IRENDERER_HPP
#define IRENDERER_HPP

#include "../classes/CCamera.hpp"
#include "../math/Vec3_tpl.hpp"

interface IRenderer {

	struct SProjectToScreen {

		SProjectToScreen() { }
		SProjectToScreen(Vec3_tpl<float> to, Vec3_tpl<float>& out)
			: ptx(to.x), pty(to.y), ptz(to.z), sx(&out.x), sy(&out.y), sz(&out.z) { }

		float ptx;
		float pty;
		float ptz;
		float* sx;
		float* sy;
		float* sz;
	};

	CCamera* SetGetCamera(const CCamera* pCamera, bool bSet) {
		return __vtbl< CCamera*, 68 >(this, pCamera, bSet);
	}

	int GetWidth() { 
		return __vtbl< int, 102 >(this); 
	}

	int GetHeight() {
		return __vtbl< int, 103 >(this, 103);
	}

	bool ProjectToScreenInternal(SProjectToScreen* proj) {
		return __vtbl< bool, 112 >(this, proj);
	}

};

#endif // !IRENDERER_HPP