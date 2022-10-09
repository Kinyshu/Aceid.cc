#pragma once

#ifndef STDAFX_HPP
#define STDAFX_HPP

#define _CRT_SECURE_NO_WARNINGS
#define _HAS_AUTO_PTR_ETC 1

#include <Windows.h>
#include <d3d11.h>
#include <d3dcompiler.h>
#include <iostream>
#include <string>
#include <list>
#include <map>
#include <vector>
#include <memory.h>
#include <set>
#include <deque>
#include <algorithm>
#include <time.h>
#include <chrono>

#include "../include/discord/rpc/include/discord_rpc.h"
#include "../include/discord/rpc/include/discord_register.h"
#include "../utils/rpc.hpp"

#include "../game/context/context.hpp"

#include "../game/connect.hpp"
#include "../render/hook/hook.hpp"

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "Winmm.lib")
#pragma comment(lib, "discord-rpc.lib")

#endif // !STDAFX_HPP