#pragma once
#include "ChernobylEngine/Core/ChernobylCore.h"

namespace Chernobyl
{
	class CHERNOBYL_API Trade
	{
	public:
		
			std::string symbol;
			std::string lastPrice;
			std::string timeStamp;
			std::string volume;
			std::string tradeConditions;
	
	public:
		Trade();
		Trade(
			std::string s,
			std::string lp,
			std::string ts,
			std::string v,
			std::string tc
		);

		std::string ToString();

		
	};
}


