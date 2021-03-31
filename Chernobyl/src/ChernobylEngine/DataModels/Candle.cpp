#include "Candle.h"

namespace Chernobyl
{
	Candle::Candle(double op, double cp, double hp, double lp)
	{
		this->openPrice = op;
		this->closePrice = cp;
		this->highPrice = hp;
		this->lowPrice = lp;
	}

}