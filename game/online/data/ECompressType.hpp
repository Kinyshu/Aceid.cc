#pragma once

#ifndef ECOMPRESSTYPE_HPP
#define ECOMPRESSTYPE_HPP

enum ECompressType {

	eCS_Default = 0x0,
	eCS_NoCompression = 0x1,
	eCS_ForceNoCompression = 0x2,
	eCS_Compress = 0x3,
	eCS_SmartCompress = 0x4,
};

#endif // !ECOMPRESSTYPE_HPP
