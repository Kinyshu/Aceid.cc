#pragma once

#ifndef IONLINECHATROOM_HPP
#define IONLINECHATROOM_HPP

enum EOnlinePresence {

	eOnlinePresence_Unknown = 0x0,
	eOnlinePresence_Available = 0x1,
	eOnlinePresence_Chat = 0x2,
	eOnlinePresence_Away = 0x3,
	eOnlinePresence_Dnd = 0x4,
	eOnlinePresence_Xa = 0x5,
	eOnlinePresence_Unavailable = 0x6,
};

interface IOnlineChatRoomListener {
public:
	virtual ~IOnlineChatRoomListener() { };
	virtual void OnChatRoomMessage(const char* nickname, const char* message, bool isPrivate) { };
	virtual void OnChatRoomPresence(const char*, EOnlinePresence) { };
	virtual void OnChatRoomParticipant(const char*, bool) { };
};

interface IOnlineChatRoom {
	
	virtual ~IOnlineChatRoom();
	virtual bool RegisterListener(IOnlineChatRoomListener* listener);
	virtual bool UnregisterListener(IOnlineChatRoomListener* listener);
	virtual bool IsListenersEmpty();
	virtual void Join();
	virtual void Leave();
	virtual void EnumerateParticipants();
	virtual void Send(const char* message);
	virtual void SendPrivate(const char* nickname, const char* message);
};

#endif // !IONLINECHATROOM_HPP