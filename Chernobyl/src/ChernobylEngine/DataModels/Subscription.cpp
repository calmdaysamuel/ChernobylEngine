#include "Subscription.h"

namespace Chernobyl
{
	Subscription::Subscription(std::string ticker) {
		this->symbol = ticker;
	}

	void Subscription::AddTrade(Trade* trade) {
		tradeStream.push_back(trade);
	}
}
