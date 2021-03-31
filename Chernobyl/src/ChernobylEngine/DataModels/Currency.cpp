#include "Currency.h"

namespace Chernobyl
{
	Currency::Currency()
	{

	}
	Currency::Currency(std::string name, std::string symbol, double value)
	{
		this->name = name;
		this->symbol = symbol;
		this->value = value;
	}
	void Currency::UpdateValue(double value)
	{
		this->value = value;
	}
	void Currency::Add(double value)
	{
		this->value += value;
	}
	void Currency::Subtract(double value)
	{
		this->value -= value;
	}
	void Currency::Multiply(double value)
	{
		this->value *= value;
	}
}
