#pragma once

#ifndef IXMLNODEHANDLER_HPP
#define IXMLNODEHANDLER_HPP

interface IXmlNodeHandler {

	virtual const char* GetTag();
	virtual const char* GetContent();
	virtual int GetNumAttributes();
	virtual bool GetAttributeByIndex(int index, const char** attr, const char** attr2);
	virtual int GetChildCount();
	virtual IXmlNodeHandler* GetChild(int);
};

#endif // !IXMLNODEHANDLER_HPP