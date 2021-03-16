#pragma once
#include "ChernobylEngine/Core/ChernobylCore.h"

namespace Chernobyl
{
	class CHERNOBYL_API Trade
	{
	public:
		
			std::string symbol;
			float lastPrice;
			std::string timeStamp;
			float volume;
			std::string tradeConditions;
	
	public:
		Trade();
		Trade(
			std::string s,
			float lp,
			std::string ts,
			float v,
			std::string tc
		);

		std::string ToString();
	};
}


