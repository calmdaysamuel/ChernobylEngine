#include "Position.h"
namespace Chernobyl
{
	Position::Position(std::string symbol, int amount, double price)
	{
		this->symbol = symbol;
		this->amount = amount;
		this->value.UpdateValue(price);
	}
	void Position::UpdateValue(int amount, double value)
	{
		this->amount += amount;
		
		if (this->amount < 0)

		{
			this->amount = 0;
		}

		this->value.UpdateValue(this->amount * value);
	}

	std::string Position::ToString()
	{
		std::string output = symbol + " Position {\n" +
			"Amount: " + std::to_string(amount) + "\n" +
			"Value: " + value.ToString()  +
			"\n}\n";
		return output;
	}

	Position::Position()
	{

	}
}
