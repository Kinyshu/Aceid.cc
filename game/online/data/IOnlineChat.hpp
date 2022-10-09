#pragma once

#ifndef IONLINECHAT_HPP
#define IONLINECHAT_HPP

#include "IOnlineChatRoom.hpp"

interface IOnlineChat {

	virtual bool RegisterListener(interface IOnlineChatListener* listener);
	virtual bool UnregisterListener(IOnlineChatListener* listener);
	virtual void DiscoverChatRooms();
	virtual IOnlineChatRoom* GetChatRoom(const char* a, const char* b);
};

#endif // !IONLINECHAT_HPP