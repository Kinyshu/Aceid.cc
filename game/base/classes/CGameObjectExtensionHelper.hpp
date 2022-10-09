#pragma once

#ifndef CGAMEOBJECTEXTENSIONHELPER_HPP
#define CGAMEOBJECTEXTENSIONHELPER_HPP

#include "../interfaces/IGameObjectExtension.hpp"

template <class T_Derived, class T_Parent, size_t MAX_STATIC_MESSAGES = 64>
class CGameObjectExtensionHelper
	: public T_Parent { };

#endif // !CGAMEOBJECTEXTENSIONHELPER_HPP
