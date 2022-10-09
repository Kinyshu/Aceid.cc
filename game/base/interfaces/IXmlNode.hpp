#pragma once

#ifndef IXMLNODE_HPP
#define IXMLNODE_HPP

interface IXmlNode {

	virtual void Function0();
	virtual void Function1();

	const char* getTag() { return __vtbl< const char*, 7 >(this); }
	void setTag(const char* tag) { __vtbl< void, 8 >(this); }

	void setAttr(const char* key, EntityId value) { __vtbl< void, 60 >(this, key, value); }
	void setAttr(const char* key, int value) { __vtbl< void, 63 >(this, key, value); }
	void setAttr(const char* key, const char* value) { __vtbl< void, 64 >(this, key, value); }

	int m_nRefCount;
};

#endif // !IXMLNODE_HPP