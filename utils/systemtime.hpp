#pragma once

#ifndef TIME_HPP
#define TIME_HPP

#include <time.h>

namespace systemtime {

	std::string get() {

		time_t     now = time(0);
		struct tm  tstruct;
		char       buf[80];
		tstruct = *localtime(&now);
		strftime(buf, sizeof(buf), "%H:%M", &tstruct);

		return buf;
	}
}

#endif // !TIME_HPP