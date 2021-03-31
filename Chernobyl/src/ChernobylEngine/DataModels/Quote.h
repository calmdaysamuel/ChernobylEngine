#pragma once
#include "Utilities/Utils.h"
#include "ChernobylEngine/Core/ChernobylCore.h"

namespace Chernobyl
{

	class CHERNOBYL_API Quote
	{
	public:
		std::string symbol = "";
		double openPrice = 0.0;
		double highPrice = 0.0;
		double lowPrice = 0.0;
		double currentPrice = 0.0;
		double previousClosePrice = 0.0;

		Quote();
		Quote(std::string symbol, double openPrice, double highPrice, double lowPrice, double currentPrice, double previousClosePrice);
		std::string ToString();
	};

}


