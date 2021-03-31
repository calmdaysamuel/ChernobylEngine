#include "Portfolio.h"

namespace Chernobyl
{
	void Portfolio::UpdateValue()
	{
		double newValue = 0.0;
		for (auto position : positions)
		{
			newValue += position.second.value.value;
		}

		portfolioValue.UpdateValue(newValue);
	}
	void Portfolio::UpdatePosition(std::string symbol, int amount, double costBasis)
	{
		if (positions.find(symbol) != positions.end())
		{
			positions[symbol].UpdateValue(amount, costBasis);
		}
		else
		{
			positions[symbol] = Position(symbol, amount, costBasis);
		}

		UpdateValue();
	}
	Position Portfolio::GetPosition(std::string symbol)
	{
		return this->positions[symbol];
	}
}
