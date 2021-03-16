#include "Subscription.h"

namespace Chernobyl
{
	Subscription::Subscription(std::string ticker) {
		this->ticker = ticker;
	}

	void Subscription::addTrade(Trade* trade) {
		trades.push_back(trade);
	}
}
