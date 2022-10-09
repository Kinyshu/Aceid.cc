#pragma once

#ifndef SLEEP_HPP
#define SLEEP_HPP

#include <time.h>
#include <chrono>

namespace sleep {

	using Clock = std::chrono::steady_clock;
	std::chrono::time_point<std::chrono::steady_clock> start = Clock::now(), now;
	std::chrono::milliseconds duration;

	bool join(int ms) {

		while (true) {

			now = Clock::now();
			duration = std::chrono::duration_cast<std::chrono::milliseconds>(now - start);

			if (duration.count() >= ms) {

				start = Clock::now();
				return true;
			}

			return false;
		}
	}
}

#endif // !SLEEP_HPP