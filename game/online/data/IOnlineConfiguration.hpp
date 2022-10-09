#pragma once

#ifndef IONLINECONFIGURATION_HPP
#define IONLINECONFIGURATION_HPP

enum EOnlineTLSPolicy {

	eOnlineTLS_Disabled = 0x0,
	eOnlineTLS_Optional = 0x1,
	eOnlineTLS_Required = 0x2,
};

interface IOnlineConfiguration {

	virtual ~IOnlineConfiguration();
	virtual const char* GetDomain();
	virtual void SetDomain(const char* domain);
	virtual const char* GetServer();
	virtual void SetServer(const char* server);
	virtual int GetServerPort();
	virtual void SetServerPort(int port);
	virtual const char* GetHost();
	virtual void SetHost(const char* host);
	virtual const char* GetResource();
	virtual void SetResource(const char* resource);
	virtual const char* GetPassword();
	virtual void SetPassword(const char* password);
	virtual const char* GetOnlineId();
	virtual void SetOnlineId(const char* id);
	virtual const char* GetFSProxy();
	virtual void SetFSProxy(const char* proxy);
	virtual EOnlineTLSPolicy GetTLSPolicy();
	virtual void SetTLSPolicy(EOnlineTLSPolicy policy);
	virtual int GetFSProxyPort();
	virtual void SetFSProxyPort(int port);
	virtual void SetDefaultCompression(ECompressType type);
	virtual ECompressType GetDefaultCompression();
	virtual void SetSendDelay(int delay);
	virtual int GetSendDelay();
	virtual void SetTcpReceiveBufferSize(int buffer);
	virtual int GetTcpReceiveBufferSize();
	virtual const char* GetFullOnlineId();
	virtual void SetOnlineVerbose(int verbose);
	virtual bool IsOnlineVerbose();
	virtual void SetThreadMode(int mode);
	virtual int GetThreadMode();
};

#endif // !IONLINECONFIGURATION_HPP