#pragma once

#ifndef IONLINE_HPP
#define IONLINE_HPP

#include "IOnlineQueryBinder.hpp"

#include "IOnlineLog.hpp"
#include "IOnlineConnection.hpp"
#include "IOnlineConfiguration.hpp"

interface IOnlineConnectionListener {
};

interface IOnline {

	virtual void Tick();
	virtual void Shutdown();
	virtual IOnlineConnection* CreateConnection(const char* domain);
	virtual void ReleaseConnection(const char* domain);
	virtual void RegisterLog(IOnlineLog* log);
	virtual void UnregisterLog();
	virtual IOnlineLog* GetLog();
	virtual IOnlineConfiguration* GetConfiguration(const char* configuration);
	virtual IOnlineConnection* GetConnection(const char* connection);
	virtual bool RegisterConnectionListener(interface IOnlineConnectionListener* listener, const char* name);
	virtual bool UnregisterConnectionListener(IOnlineConnectionListener* listener);
	virtual void RegisterQueryBinder(IOnlineQueryBinder* binder, const char* name);
	virtual void UnregisterQueryBinder(IOnlineQueryBinder* binder);

	static IOnline* GetInstance() {
		return *reinterpret_cast<IOnline**>(0x141BE3A80);
	}
};

#endif // !IONLINE_HPP