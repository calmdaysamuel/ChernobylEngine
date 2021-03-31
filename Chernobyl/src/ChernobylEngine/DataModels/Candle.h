#pragma once
#include "Utilities/Utils.h"
namespace Chernobyl
{
	class Candle
	{
	public:
		double openPrice;
		double closePrice;
		double highPrice;
		double lowPrice;

		Candle(double op, double cp, double hp, double lp);
		std::string ToString();
	};

}

