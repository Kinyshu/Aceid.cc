#pragma once

#ifndef SPLATFORMINFO_HPP
#define SPLATFORMINFO_HPP

struct SPlatformInfo {

	enum EWinVersion {

		WinUndetected = 0x0,
		Win2000 = 0x1,
		WinXP = 0x2,
		WinSrv2003 = 0x3,
		WinVista = 0x4,
		Win7 = 0x5,
		Win8 = 0x6,
		Win10 = 0x7,
		WinXXX = 0x8,
	};

	unsigned int numCoresAvailableToProcess;
	SPlatformInfo::EWinVersion winVer;
	bool win64Bit;
	bool vistaKB940105Required;
};

#endif // !SPLATFORMINFO_HPP