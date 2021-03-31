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
		this->previousClosePrice = previousClosePrice;
	}

	std::string Quote::ToString()
	{
		std::string output = symbol + " {\n" + 
			"Open Price: " + std::to_string(openPrice) + "\n" + 
			"High Price: " + std::to_string(highPrice) + "\n" + 
			"Low Price: " + std::to_string(lowPrice) + "\n" + 
			"Current Price: " + std::to_string(currentPrice) + "\n" +
			"Previous Close Price: " + std::to_string(previousClosePrice) + "\n" +
			"}\n";
		return output;
	}

	Quote::Quote()
	{

	}
}
