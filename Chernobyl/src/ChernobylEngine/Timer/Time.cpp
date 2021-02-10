#include "Time.h"

namespace Chernobyl
{
	Time::Time()
	{
		InitClock = std::chrono::system_clock::now();
	}

	Time::~Time()
	{

	}

	double Time::ToSeconds(std::string time)
	{
		return 1.0;
	}
	void Time::SetDeltaTime()
	{
		DeltaTime = StartTime - EndTime;
	}

	void Time::SetStartTime()
	{
		StartTime = std::chrono::system_clock::now();
	}
	void Time::SetEndTime()
	{
		EndTime = std::chrono::system_clock::now();
	}

	void Time::SetTimePast()
	{
		TimePast = InitClock - std::chrono::system_clock::now();
	}
}