#pragma once
#include "Utilities/Utils.h"
#include "DataModels/Currency.h"
#include "DataModels/Position.h"
namespace Chernobyl
{
	class Portfolio
	{
	private:
		Currency portfolioValue;
		std::unordered_map<std::string, Position> positions;

	public:
		void UpdateValue();
		void UpdatePosition(std::string symbol, int amount, double costBasis);
		Position GetPosition(std::string symbol);
	};
	
}