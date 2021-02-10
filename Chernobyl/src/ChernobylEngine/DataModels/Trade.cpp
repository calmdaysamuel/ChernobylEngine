#include "Trade.h"

namespace Chernobyl
{
	Trade::Trade(std::string s,
		std::string lp,
		std::string ts,
		std::string v,
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

}
