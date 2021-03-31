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
		Subscribe("VOO");
		Subscribe("AAPL");
		Subscribe("MSFT");
		// with class member
		//EveryTimeAmount("00:00:05", [this]() {Sell("VOO", 5); });
		//EveryTimeAmount("00:00:03", [this]() {Buy("VOO", 10); });
		EveryTimeAmount("00:00:10", [this]() {std::cout << portfolio.ToString() << std::endl; });
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
