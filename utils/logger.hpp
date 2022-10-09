#pragma once

#ifndef LOGGER_HPP
#define LOGGER_HPP

namespace logger {

	void Log(std::string fmt, ...);
	void LogError(std::string fmt, ...);
	void LogWarning(std::string fmt, ...);
}

#endif // !LOGGER_HPP