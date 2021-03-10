#pragma once
#include <map>
#include <string>
namespace Chernobyl
{
	class Position
	{
		std::string symbol;
		int amount;
		double price;
	};
	class Account
	{
		int Balance;


		std::map<std::string, Position> positions;
	};

	
}