#pragma once

#ifndef CLOBBYCHAT_HPP
#define CLOBBYCHAT_HPP

#undef SendMessage

enum ELobbyChatChannel {

	eCC_First = 0x0,
	eCC_Global = 0x0,
	eCC_Room = 0x1,
	eCC_Team = 0x2,
	eCC_Clan = 0x3,
	eCC_Observer = 0x4,
	eCC_Whisper = 0x5,
	eCC_Count = 0x6,
};

struct SLobbyChatMessage {

	CryStringT<char> nick;
	CryStringT<char> message;
	bool is_local;
	bool is_service;
	CTimeValue time_stamp;
};

struct SChannelAntispamCfg {

	CTimeValue highFrequency;
	CTimeValue lowFrequency;
	CTimeValue notifFrequency;
};

class CLobbyChat
	/* : IOnlineServiceStatusListener, IChatChannelInfoListener, IGameRoomListener, IClansListener, IFlowchartListener */ {
public:

	class CChannel {
	public:

		struct SMessageHistory {

			bool unread;
			std::deque<SLobbyChatMessage> messages;
		};
	public:

		virtual void DCChannel();
		virtual void OnLostChannel();
		virtual ELobbyChatChannel GetChannelType();
		virtual void AddServiceMessage(const char*);
		virtual bool SendMessage(const char*);
		virtual bool HasUnreadMessages();
		virtual void MarkRead();
		virtual const std::deque<SLobbyChatMessage>* GetMessages();
		virtual int GetChannelSize();
	public:

		CLobbyChat* m_pOwner;
		ELobbyChatChannel m_channel;
		CLobbyChat::CChannel::SMessageHistory m_history;
	};


	class CMUCChannel 
		: public CLobbyChat::CChannel, IOnlineChatRoomListener {
	public:

		virtual void DCChannel();
		virtual void OnLostChannel();
		virtual ELobbyChatChannel GetChannelType();
		virtual void AddServiceMessage(const char*);
		virtual bool SendMessage(const char*);
		virtual bool HasUnreadMessages();
		virtual void MarkRead();
		virtual const std::deque<SLobbyChatMessage>* GetMessages();
		virtual int GetChannelSize();

	public:
					
		IOnlineChatRoom* m_pChatRoom;
		SChannelAntispamCfg m_antispamCfg;
		int m_channelSize;
		CryStringT<char> m_channelId;
	};
public:

	ACEID_API CREATE_FUNCTOR(CMUCChannel*, m_channels, 0x28); // m_channels[6];
	ACEID_API CREATE_FUNCTOR(CMUCChannel*, eCC_Room, 48);
	ACEID_API CREATE_FUNCTOR(int, m_antispamRankThreshold, 0x58);

};

#endif // !CLOBBYCHAT_HPP