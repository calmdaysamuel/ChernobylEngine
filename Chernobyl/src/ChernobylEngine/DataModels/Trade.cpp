#include "Trade.h"

namespace Chernobyl
{
	Trade::Trade(std::string s, double lp, std::string ts, int v, std::string tc)
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
		std::string output = symbol + " {\n" + 
			"Last Price: " + std::to_string(lastPrice) + "\n" + 
			"Volume: " + std::to_string(volume) + "\n" + 
			"Time Stamp: " + timeStamp + "\n"+ 
			"Trade Conditions: " + tradeConditions + 
			"\n}\n";

		return output;
	}
}
