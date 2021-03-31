#pragma once
#include "Utilities/Utils.h"
namespace Chernobyl
{
	class Currency
	{
	public:
		std::string name;
		std::string symbol;
		double value;

		Currency(std::string name, std::string symbol, double value);
		Currency();
		void UpdateValue(double value);
		void Add(double value);
		void Subtract(double value);
		void Multiply(double value);
	};
}


