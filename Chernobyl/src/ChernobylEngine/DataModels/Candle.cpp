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

	std::string Candle::ToString()
	{
		std::string output = "{\n" +
			std::to_string(openPrice) + "\n" +
			std::to_string(closePrice) + "\n" +
			std::to_string(highPrice) + "\n" +
			std::to_string(lowPrice) + "\n" +
			"}/n";
		return std::string();
	}

}