#include "Position.h"
namespace Chernobyl
{
	Position::Position(std::string symbol, int amount, double costBasis)
	{
		this->name = name;
		this->symbol = symbol;
		// this->amount = amount;
	}
	void Position::UpdateValue(int amount, double value)
	{
		this->amount += amount;
	}

	Position::Position()
	{

	}
}
