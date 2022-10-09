#pragma once

#ifndef SD3DPOSTEFFECTSUTILS_HPP
#define SD3DPOSTEFFECTSUTILS_HPP

struct Matrix44 {
	float m00;
	float m01;
	float m02;
	float m03;
	float m10;
	float m11;
	float m12;
	float m13;
	float m20;
	float m21;
	float m22;
	float m23;
	float m30;
	float m31;
	float m32;
	float m33;
};

struct SD3DPostEffectsUtils {

	char pad[0x8];
	Matrix44 m_pView;
	Matrix44 m_pProj;
	Matrix44 m_pViewProj;
	Matrix44 m_pColorMat;

	static SD3DPostEffectsUtils* GetInstance() {
		return *reinterpret_cast<SD3DPostEffectsUtils**>(0x141F0A6C0); // SSReflection_Comp, (*((void (__fastcall **)(void **, __int64, __int64))off_141F0A6C0 + 2))(&off_141F0A6C0, qword_14216EFF8, 1i64);
	}
};

#endif // !SD3DPOSTEFFECTSUTILS_HPP
