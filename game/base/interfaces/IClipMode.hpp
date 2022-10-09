#pragma once

#ifndef ICLIPMODE_HPP
#define ICLIPMODE_HPP

interface IClipMode {

	virtual void Function0(); //
	virtual int GetAmmoCount(); //
	virtual void SetAmmoCount(int count); //
	virtual void ExpendAmmo(); //
	virtual bool IsEmpty(); //
	virtual bool IsBarrel(); //
	virtual bool IsRechargeable(); //
	virtual bool RunLevelNotification(); //
};

#endif // !ICLIPMODE_HPP