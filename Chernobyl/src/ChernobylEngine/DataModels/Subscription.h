#pragma once
#include "ChernobylEngine/Core/ChernobylCore.h"
#include "ChernobylEngine/Utilities/Utils.h"
#include "./Trade.h"


namespace Chernobyl
{
	class CHERNOBYL_API Subscription
	{
	public:
		Subscription(std::string);
		void AddTrade(Trade*);
		std::vector<Trade*> tradeStream;
	private:
		std::string symbol;
		
	};
}
