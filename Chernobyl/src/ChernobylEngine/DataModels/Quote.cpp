#include "Quote.h"

namespace Chernobyl
{
	Quote::Quote(std::string symbol, double openPrice, double highPrice, double lowPrice, double currentPrice, double previousClosePrice)
	{
		this->symbol = symbol;
		this->openPrice = openPrice;
		this->highPrice = highPrice;
		this->lowPrice = lowPrice;
		this->currentPrice = currentPrice;
		this->previousClosePrice;
	}

	Quote::Quote()
	{

	}
}
