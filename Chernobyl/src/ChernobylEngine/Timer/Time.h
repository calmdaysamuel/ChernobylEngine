#pragma once
#include "../Core/ChernobylCore.h"
#include <chrono>


namespace Chernobyl {
	class CHERNOBYL_API Time
	{
	public:
		std::chrono::duration<double> TimePast;
		std::chrono::duration<double> DeltaTime;
		Time();
		~Time();

		void SetDeltaTime();
		void SetStartTime();
		void SetTimePast();
		void SetEndTime();
		double ToSeconds(std::string time);

	private:
		std::chrono::time_point<std::chrono::system_clock> EndTime;
		std::chrono::time_point<std::chrono::system_clock> StartTime;
		std::chrono::time_point<std::chrono::system_clock> InitClock;
	};
}


