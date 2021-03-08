//#include "../Chernobyl/src/ChernobylEngine.h"
#include <iostream>
#include "ChernobylEngine.h"

class TestApplication: public Chernobyl::TradingApplication
{
	void Awake()
	{
		//Subscribe("AAPL");
		

	}

	void TradeReceived(Chernobyl::Trade& trade)
	{

	}
};

Chernobyl::Application* CreateApplication()
{
    // S&P 500
 
	return new TestApplication();

}
