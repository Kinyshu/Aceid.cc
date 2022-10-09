#pragma once

#ifndef IONLINEQUERYBINDER_HPP
#define IONLINEQUERYBINDER_HPP

#include "ECompressType.hpp"

enum EQueryType {

	eQT_Unknown = 0x0,
	eQT_Request = 0x1,
	eQT_Response = 0x2,
};

enum EOnlineError {

	eOnlineError_NoError = 0x0,
	eOnlineError_StreamError = 0x1,
	eOnlineError_StreamVersionError = 0x2,
	eOnlineError_StreamClosed = 0x3,
	eOnlineError_ProxyAuthRequired = 0x4,
	eOnlineError_ProxyAuthFailed = 0x5,
	eOnlineError_ProxyNoSupportedAuth = 0x6,
	eOnlineError_IoError = 0x7,
	eOnlineError_ParseError = 0x8,
	eOnlineError_ConnectionRefused = 0x9,
	eOnlineError_DnsError = 0xA,
	eOnlineError_OutOfMemory = 0xB,
	eOnlineError_NoSupportedAuth = 0xC,
	eOnlineError_TlsFailed = 0xD,
	eOnlineError_TlsNotAvailable = 0xE,
	eOnlineError_CompressionFailed = 0xF,
	eOnlineError_AuthenticationFailed = 0x10,
	eOnlineError_UserDisconnected = 0x11,
	eOnlineError_NotConnected = 0x12,
	eOnlineError_UnknownError = 0x13,
	eOnlineError_ServiceNotFound = 0x194,
	eOnlineError_ServiceUnavailable = 0x1F7,
	eOnlineError_QoSLimitReached = 0x3EE,
	eOnlineError_MaxOnlineUsersReached = 0x3EF,
	eOnlineError_InvalidSession = 0x3F0,
	eOnlineError_LastingServerFailure = 0x3F1,
	eOnlineError_LostConnection = 0x3F2,
	eOnlineError_QueryTimeout = 0x3F3,
	eOnlineError_TryAgain = 0x3F4,
	eOnlineError_ServerNotFound = 0x3F5,
	eOnlineError_UnknownServer = 0x3F6,
};

struct SBaseQuery {

	char sId[128];
	char online_id[128];
	char tag[128];
	char description[1024];
	int id;
};

const struct SOnlineQuery 
	: SBaseQuery {

	EQueryType type;
};

const struct SQueryError 
	: SBaseQuery {

	EOnlineError online_error;
	int custom_code;
};

interface IOnlineQueryBinder {

	virtual ~IOnlineQueryBinder();
	virtual const char* Tag();
	virtual ECompressType GetCompressionType();
	virtual const char* GetReceiverId();
	virtual void OnQueryCompleted(interface IOnlineConnection* connection, const SOnlineQuery* query, const char* buffer);
	virtual void OnRequest(IOnlineConnection* connection, const SOnlineQuery* query, const char* buffer);
	virtual void OnQueryError(IOnlineConnection* connection, const SQueryError* error);
};

#endif // !IONLINEQUERYBINDER_HPP