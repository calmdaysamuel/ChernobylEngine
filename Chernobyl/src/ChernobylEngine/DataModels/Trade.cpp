#include "Trade.h"

namespace Chernobyl
{
	Trade::Trade(std::string s,
		float lp,
		std::string ts,
		float v,
		std::string tc)
	{
		symbol = s;
		lastPrice = lp;
		timeStamp = ts;
		volume = v;
		tradeConditions = tc;
	}

	Trade::Trade()
	{

	}

	std::string Trade::ToString()
	{
		return "";
	}
}
