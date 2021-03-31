#pragma once
#include "Utilities/Utils.h"
#include "ChernobylEngine/Core/ChernobylCore.h"

namespace Chernobyl
{

	class CHERNOBYL_API Quote
	{
	public:
		std::string symbol;
		double openPrice;
		double highPrice;
		double lowPrice;
		double currentPrice;
		double previousClosePrice;

		Quote();
		Quote(std::string symbol, double openPrice, double highPrice, double lowPrice, double currentPrice, double previousClosePrice);
	};

}


