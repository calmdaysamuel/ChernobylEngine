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
		void addTrade(Trade*);
		std::vector<Trade*> trades;
	private:
		std::string ticker;
		
	};
}
