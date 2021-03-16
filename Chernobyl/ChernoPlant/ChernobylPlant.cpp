//#include "../Chernobyl/src/ChernobylEngine.h"
#include <iostream>
#include "ChernobylEngine.h"

void hi()
{
	std::cout << "greeting" << std::endl;
}


class TestApplication: public Chernobyl::TradingApplication
{
	std::string greeting = "hello";

	void Awake()
	{
		std::cout << "Awaking\n";
		Subscribe("AAPL");
		Subscribe("MSFT");

		//with lambda function
		EveryTimeAmount(
			
			"00:00:3", 
			[this]() 
			{
				auto trade = this->subscriptions["AAPL"]->trades;
				auto sTrade = trade[trade.size() - 1];
				std::cout << sTrade->symbol << std::endl;
				std::cout << sTrade->lastPrice << std::endl;
			}
		);

		EveryTimeAmount(

			"00:00:3",
			[this]()
			{
				auto trade = this->subscriptions["MSFT"]->trades;
				auto sTrade = trade[trade.size() - 1];
				std::cout << sTrade->symbol << std::endl;
				std::cout << sTrade->lastPrice << std::endl;
			}
		);

		// with class member
		//EveryTimeAmount("00:00:05", std::bind(&TestApplication::hello, this));

		// with external function
		//EveryTimeAmount("00:00:11", hi);
	}

	void hello()
	{
		std::cout << greeting << std::endl;
	}
	
	void printTrade(Chernobyl::Trade trade)
	{
		std::cout << trade.ToString() << std::endl;
	}

};

Chernobyl::Application* CreateApplication()
{
 
	return new TestApplication();

}
