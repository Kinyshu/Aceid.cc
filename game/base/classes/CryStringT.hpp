#pragma once

#ifndef CRYSTRINGT_HPP
#define CRYSTRINGT_HPP

template <typename T>
class CryStringT {
public:

	struct StrHeader {
		volatile int nRefCount;
		int nLength;
		int nAllocSize;
	};

public:

	T* m_str;
	StrHeader* m_header;
};

#endif // !CRYSTRINGT_HPP