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

	int Time::ToSeconds(std::string time)
	{
		std::string hh = "0";
		std::string mm = "0";
		std::string ss = "0";

		hh = time.substr(0, 2);
		mm = time.substr(3, 2);
		ss = time.substr(6, 2);

		return stoi(hh) * 3600 + stoi(mm) * 60 + stoi(ss);
	}
	void Time::SetDeltaTime()
	{
		 
		 DeltaTime =  std::chrono::duration_cast<std::chrono::milliseconds>(EndTime - StartTime).count() / 1000;
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
		TimePast = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - InitClock).count() / 1000;
	}
}