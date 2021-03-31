#pragma once
#include "../Core/ChernobylCore.h"
#include <chrono>


namespace Chernobyl {

	// Time format hh:mm:ss:nnn
	class CHERNOBYL_API Time
	{
	public:
		int TimePast;
		int DeltaTime;
		Time();
		~Time();

		void SetDeltaTime();
		void SetStartTime();
		void SetTimePast();
		void SetEndTime();
		int ToMilliSeconds(std::string time);
		int ToSeconds(std::string time);
	private:
		std::chrono::time_point<std::chrono::steady_clock> EndTime;
		std::chrono::time_point<std::chrono::steady_clock> StartTime;
		std::chrono::time_point<std::chrono::steady_clock> InitClock;
	};
}


