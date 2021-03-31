#pragma once
#include "Utilities/Utils.h"
#include "DataModels/Currency.h"
namespace Chernobyl
{
	class Position
	{
	public:
		std::string name;
		std::string symbol;
		int amount = 0;
		Currency value;
		double costBasis = 0 ;


		Position(std::string symbol, int amount, double costBasis);
		Position();
		void UpdateValue(int amount, double value);

		std::string ToString();
	};
}




