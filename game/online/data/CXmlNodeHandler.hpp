#pragma once

#ifndef CXMLNODEHANDLER_HPP
#define CXMLNODEHANDLER_HPP

#include "IXmlNodeHandler.hpp"
#include "../../base/structures/XmlNodeRef.hpp"

class CXmlNodeHandler
	: IXmlNodeHandler {

	XmlNodeRef m_node;
	std::vector<CXmlNodeHandler, std::allocator<CXmlNodeHandler> > m_children;
};

#endif // !CXMLNODEHANDLER_HPP