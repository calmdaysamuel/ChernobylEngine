#include "Portfolio.h"

namespace Chernobyl
{
	void Portfolio::UpdateValue()
	{
		double newValue = 0.0;
		for (auto position : positions)
		{
			newValue += position.second->value.value;
		}

		portfolioValue.UpdateValue(newValue);
	}
	void Portfolio::UpdatePosition(std::string symbol, int amount, double price)
	{
		if (positions.find(symbol) != positions.end())
		{
			positions[symbol]->UpdateValue(amount, price);
		}
		else
		{
			positions[symbol] = new Position(symbol, amount, price);
		}

		UpdateValue();
	}
	Position* Portfolio::GetPosition(std::string symbol)
	{
		return this->positions[symbol];
	}

	std::string Portfolio::ToString()
	{
		std::string output = "Portfolio {\n" + 
			std::string("Value: ") + portfolioValue.ToString() + "\n\n"
			"Positions:" + "\n";

		for (auto postion : positions)
		{
			output += postion.second->ToString();
		}
		return output + "\n}\n";
	}
}
