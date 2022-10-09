#pragma once

#ifndef IFIREMODEOBJECT_HPP
#define IFIREMODEOBJECT_HPP

interface IFireModeObject {

	virtual void Function0() = 0;
	virtual bool Update(float, unsigned int) = 0;
	virtual void PostUpdate(float) = 0;
	virtual void StartFire() = 0;
	virtual void StopFire() = 0;
	virtual void ClearFireCounter() = 0;
	virtual int GetBulletCount() = 0;
	virtual CBaseSettings::EFiremode GetType() = 0;
	virtual float GetRechargeTimer() = 0;
	virtual void OnFireRequestSkipped() = 0;
	virtual void OnReload(bool, bool) = 0;
	virtual void OnSpawnProjectile(void*) = 0;
	virtual bool IsFiringAvailable() = 0;
	virtual bool IsReloadingAvailable() = 0;
};

/*
  void (__fastcall *~IFireModeObject)(IFireModeObject *this);
  bool (__fastcall *Update)(IFireModeObject *this, float, unsigned int);
  void (__fastcall *PostUpdate)(IFireModeObject *this, float);
  void (__fastcall *StartFire)(IFireModeObject *this);
  void (__fastcall *StopFire)(IFireModeObject *this);
  void (__fastcall *ClearFireCounter)(IFireModeObject *this);
  int (__fastcall *GetBulletCount)(IFireModeObject *this);
  CBaseSettings::EFiremode (__fastcall *GetType)(IFireModeObject *this);
  float (__fastcall *GetRechargeTimer)(IFireModeObject *this);
  void (__fastcall *OnFireRequestSkipped)(IFireModeObject *this);
  void (__fastcall *OnReload)(IFireModeObject *this, bool, bool);
  void (__fastcall *OnSpawnProjectile)(IFireModeObject *this, CProjectile *);
  bool (__fastcall *IsFiringAvailable)(IFireModeObject *this);
  bool (__fastcall *IsReloadingAvailable)(IFireModeObject *this);
*/

#endif // !IFIREMODEOBJECT_HPP