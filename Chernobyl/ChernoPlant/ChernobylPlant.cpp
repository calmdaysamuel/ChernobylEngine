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
		//with lambda function
		// with class member
		EveryTimeAmount("00:00:05", std::bind(&TestApplication::hello, this));

		// with external function
		EveryTimeAmount("00:00:11", hi);
		BindTradeReceived("AAPL",std::bind(&TestApplication::printTrade, this, std::placeholders::_1));
		BindAnyTradeReceived(std::bind(&TestApplication::printTrade, this, std::placeholders::_1));

		If([this]() 
			{
				if (ApplicationTime.TimePast == 11 || ApplicationTime.TimePast == 5)
				{
					return true;
				}

				return false;
			}, 
			std::bind(&TestApplication::hello, this));
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
