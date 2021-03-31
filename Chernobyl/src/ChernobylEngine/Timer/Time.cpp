#include "Time.h"

namespace Chernobyl
{
	Time::Time()
	{
		InitClock = std::chrono::steady_clock::now();
	}

	Time::~Time()
	{

	}

	int Time::ToMilliSeconds(std::string time)
	{
		
		return (stoi(time.substr(0, 2)) * 3600 + stoi(time.substr(3, 2)) * 60 + stoi(time.substr(6, 2)) * 1000) + stoi(time.substr(9, 3));
	}
	int Time::ToSeconds(std::string time)
	{
		return stoi(time.substr(0, 2)) * 3600 + stoi(time.substr(3, 2)) * 60 + stoi(time.substr(6, 2));
	}
	void Time::SetDeltaTime()
	{
		 
		 DeltaTime =  std::chrono::duration_cast<std::chrono::milliseconds>(EndTime - StartTime).count();
	}

	void Time::SetStartTime()
	{
		StartTime = std::chrono::steady_clock::now();
	}
	void Time::SetEndTime()
	{
		EndTime = std::chrono::steady_clock::now();
	}

	void Time::SetTimePast()
	{
		TimePast = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - InitClock).count();
	}
}