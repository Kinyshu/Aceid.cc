#pragma once

#ifndef HELPER_HPP_
#define HELPER_HPP_

std::string CORE_FOLDER_PATH = "C:\\Aceid.cc";

#define GUI_COMPILE		 1

#define aceid_api
#define ACEID_API

#define DEBUG_COMPILE	 0
#define DEBUG_LOG(...)				\
	if (DEBUG_COMPILE == 1)			\
		printf(__VA_ARGS__)			\

/* mod */

#define TRASH_TALKER_COMPILE 0

/* end*/

#define WITH_ARGUMENTS
#define CREATE_VMT_HOOK(TYPE, NAME, CODE, ARGUMENTS)
#define CREATE_VMT_STATIC_HOOK(TYPE, NAME, CODE, ARGUMENTS)			

/*
	Гетеро и сетеро для Си плюс плюс
*/
#define CREATE_FUNCTOR(TYPE, NAME, OFFSET)									
#define CREATE_FUNCTOR_STRUCT(TYPE, NAME, OFFSET)							

using EntityId = unsigned int;

namespace api {

	std::string format(std::string str, ...) {
		return "";
	}
}

template <typename TYPE, std::uintptr_t INDEX, typename ...ARGUMENTS>
__forceinline auto __vtbl(void* __ptr64 pointer, ARGUMENTS... arguments) {
	return ((*reinterpret_cast<TYPE(__thiscall***)(void*, ARGUMENTS...)>(pointer))[INDEX])(pointer, arguments...);
}

#endif // !HELPER_HPP_