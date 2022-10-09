#pragma once

#ifndef VEC3_TPL_HPP
#define VEC3_TPL_HPP

#include "math.hpp"

template< typename T >
struct Vec3_tpl {

	T x;
	T y;
	T z;
	
	Vec3_tpl(T t) : x(x), y(y), z(z) { }
	Vec3_tpl() { Vec3_tpl(0, 0, 0); }
	Vec3_tpl(T x, T y, T z) { this->x = x; this->y = y; this->z = z; }

	T GetLenght() { return reinterpret_cast<T>(math::_sqrt(this->x * this->x + this->y * this->y + this->z * this->z)); }
	T GetLenghtSquared() { return this->x* this->x + this->y * this->y + this->z * this->z; }
	T CalculateDistance(Vec3_tpl< T > vector) { return static_cast<T>(math::_sqrt(((this->x - vector.x) * (this->x - vector.x))
		+ ((this->y - vector.y) * (this->y - vector.y)) + ((this->z - vector.z) * (this->z - vector.z)))); }

	template < typename F > T Dot(F a, F b) { return ::sum(a * b); }
	template < typename F > T Dot(const F& vector) { return  this->x * vector.x + this->y * vector.y + this->z * vector.z; }

	/* operators */
	void operator += (T t) { this->x += t; this->y += t; this->z += t; }
	void operator -= (T t) { this->x -= t; this->y -= t; this->z -= t; }

	Vec3_tpl< T > operator*(T t) { return Vec3_tpl< T >(this->x * t, this->y * t, this->z * t); }

	Vec3_tpl& operator /  (T f) { return Vec3_tpl(x / f, y / f, z / f); }
	Vec3_tpl& operator = (const Vec3_tpl& source) { x = source.x; y = source.y; z = source.z; return *this; }
	Vec3_tpl& operator = (const T value) { x = value; y = value; z = value;   return *this; }
	Vec3_tpl& operator *= (T f) { x *= f; y *= f; z *= f; return *this; }
	Vec3_tpl& operator /= (T f) { x /= f; y /= f; z /= f; return *this; }

	friend Vec3_tpl operator + (const Vec3_tpl& vec1, const Vec3_tpl& vec2) { return Vec3_tpl(vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z); }
	friend Vec3_tpl operator + (const Vec3_tpl& vec1, const T* vec2) { return vec1 + Vec3_tpl(vec2); }
	friend Vec3_tpl operator + (const T* vec1, const Vec3_tpl& vec2) { return Vec3_tpl(vec1) + vec2; }

	friend Vec3_tpl operator - (const Vec3_tpl& vec1, const Vec3_tpl& vec2) { return Vec3_tpl(vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z); }
	friend Vec3_tpl operator - (const Vec3_tpl& vec1, const T* vec2) { return vec1 - Vec3_tpl(vec2); }
	friend Vec3_tpl operator - (const T* vec1, const Vec3_tpl& vec2) { return Vec3_tpl(vec1) - vec2; }
};

#endif // !VEC3_TPL_HPP
