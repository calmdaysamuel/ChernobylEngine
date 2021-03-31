#include "Trade.h"

namespace Chernobyl
{
	Trade::Trade(std::string s, float lp, std::string ts, float v, std::string tc)
	{
		this->symbol = s;
		this->lastPrice = lp;
		this->timeStamp = ts;
		this->volume = v;
		this->tradeConditions = tc;
	}

	Trade::Trade()
	{

	}

	std::string Trade::ToString()
	{
		return "";
	}
}
