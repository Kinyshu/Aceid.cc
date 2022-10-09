#pragma once

#ifndef IONLINELOG_HPP
#define IONLINELOG_HPP

enum EOnlineLogLevel {

	eOnlineLog_Debug = 0x0,
	eOnlineLog_Warning = 0x1,
	eOnlineLog_Error = 0x2,
};

interface IOnlineLog {

	virtual ~IOnlineLog();
	virtual void OnLogMessage(EOnlineLogLevel level, const char* message);
};

#endif // !IONLINELOG_HPP
