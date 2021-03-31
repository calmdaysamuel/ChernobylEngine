#pragma once
#include "ChernobylEngine/Core/ChernobylCore.h"

namespace Chernobyl
{
	class CHERNOBYL_API Trade
	{
	public:
		
			std::string symbol = "";
			double lastPrice = 0.0;
			std::string timeStamp = "";
			int volume = 0;
			std::string tradeConditions = "";
	
	public:

		Trade();
		Trade(std::string s, double lp, std::string ts, int v, std::string tc);
		std::string ToString();
	};
}


