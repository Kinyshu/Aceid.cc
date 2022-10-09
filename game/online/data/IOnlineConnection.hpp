#pragma once

#ifndef IONLINECONNECTION_HPP
#define IONLINECONNECTION_HPP

#include "CXmlNodeHandler.hpp"
#include "IOnlineConfiguration.hpp"

#include "IOnlineChat.hpp"

enum EConnectionMode {

	eCM_Polling = 0x0,
	eCM_Blocking = 0x1,
};

enum ERequestSendType {

	eRST_Regular = 0x0,
	eRST_Immediate = 0x1,
};

enum EOnlineConnectionState {

	eOnlineConnectionState_Disconnected = 0x0,
	eOnlineConnectionState_Connecting = 0x1,
	eOnlineConnectionState_Connected = 0x2,
	eOnlineConnectionState_Unknown = 0x3,
};

interface IOnlineBandwidthStats {

	~IOnlineBandwidthStats();
	int GetTotalBytesSent();
	int GetTotalBytesRecv();
};

struct IOnlineConnection {

	virtual bool Connect(EConnectionMode mode);
	virtual int Query(IXmlNodeHandler*, const char* receiverId, const char* const* hz, unsigned __int64 p, IOnlineQueryBinder* binder, ECompressType compression, ERequestSendType type);
	virtual int Query(IXmlNodeHandler*, const char* receiverId, IOnlineQueryBinder* binder, ECompressType compression, ERequestSendType type);
	virtual int Query(const char* request, const char* receiverId, IOnlineQueryBinder* binder, ECompressType compression);
	virtual int Query(const char* request, const char* receiverId);
	virtual void Response(const SOnlineQuery* query, const char* data, ECompressType compression);
	virtual void ResponseError(const SQueryError* error, const char* data);
	virtual void ScheduleFailedQuery(EOnlineError error, const char* data, IOnlineQueryBinder* binder);
	virtual EOnlineConnectionState GetConnectionState();
	virtual IOnlineConfiguration* GetConfiguration();
	virtual IOnlineChat* GetChat(const char* domain);
	virtual void RegisterQueryStatsListener(interface IOnlineQueryStatsListener* listener);
	virtual void UnregisterQueryStatsListener(IOnlineQueryStatsListener* listener);
	virtual IOnlineBandwidthStats* GetBandwidthStatistics();
	virtual void RegisterDataProtect(interface IOnlineDataProtect* protect);
	virtual void UnregisterDataProtect();
	virtual void SendProtectionData(const char* data, const char* data1, unsigned __int64 salt);
	virtual void SetCertificateValidator(interface ICertificateValidator* validator);
};

#endif // !IONLINECONNECTION_HPP