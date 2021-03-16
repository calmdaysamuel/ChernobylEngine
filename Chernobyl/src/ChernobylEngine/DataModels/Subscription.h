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
	private:
		std::string ticker;
		std::vector<Trade*> trades;
	};
}
