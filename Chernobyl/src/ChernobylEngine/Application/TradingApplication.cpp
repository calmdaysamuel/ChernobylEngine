#include "TradingApplication.h"
#include "../Timer/Time.h"

namespace Chernobyl
{
	//Constructor and Destructor
	TradingApplication::TradingApplication()
	{

	}

	TradingApplication::~TradingApplication()
	{

	}
	
	//Subscription
	void TradingApplication::Subscribe(std::string symbol)
	{
	}

	//Time Functions
	void TradingApplication::AfterTimeAmount(std::string time, std::function<void(void)> func)
	{
		
		afterTimeAmountBinding[ApplicationTime.ToSeconds(time)].push_back(func);
	}

	void TradingApplication::EveryTimeAmount(std::string time, std::function<void(void)> func)
	{
		everyTimeAmountBinding[ApplicationTime.ToSeconds(time)].push_back(func);
	}



	//Helper Functions
	

	void TradingApplication::CompareNeighboringTrades(std::string symbol, std::function<void(Trade, Trade)> func)
	{

	}

	void TradingApplication::CompareIntervals(std::string symbol, int i, std::function<void(Trade, Trade)> func)
	{

	}

	void TradingApplication::CompareIntervals(std::string symbol, std::string time, std::function<void(Trade, Trade)> func)
	{

	}

	void TradingApplication::OnTradeReceived(std::string symbol)
	{
		//onTradeRecievedBindings[symbol](Trade());
		//onTradeRecievedBindings[UNIVERSAL_RECEIVED_BINDING](Trade());
	}

	//Binding Functions
	void TradingApplication::BindTradeReceived(std::string symbol, std::function<void(Trade)> func)
	{
		onTradeRecievedBindings[symbol].push_back(func);
	}

	void TradingApplication::BindAnyTradeReceived(std::function<void(Trade)> func)
	{
		onTradeRecievedBindings[UNIVERSAL_RECEIVED_BINDING].push_back(func);
	}
	
	void TradingApplication::BindToKey(std::string key, std::function<void(void)> func)
	{
		
		keyBinding[key].push_back(func);
	}

	//Buy
	void TradingApplication::BuyWithLimit(std::string symbol, int amount, float limitPrice) 
	{

	}

	void TradingApplication::Buy(std::string symbol, int amount)
	{

	}

	//Sell
	void TradingApplication::SellWithStopLoss(std::string symbol, int amount)
	{

	}

	void TradingApplication::Sell(std::string symbol, int amount)
	{

	}

	void TradingApplication::SellAll(std::string symbol)
	{

	}

	void TradingApplication::SellWithLimit(std::string symbol, int amount, float limitPrice)
	{

	}







	//Step Functions
	void TradingApplication::Awake()
	{

	}

	void TradingApplication::LateUpdate()
	{

	}

	void TradingApplication::Update()
	{

	}

	void TradingApplication::ExecuteTimedBindings()
	{
		if (ApplicationTime.TimePast == lastTime)
		{
			return;
		}
		lastTime = ApplicationTime.TimePast;
		for (auto value : everyTimeAmountBinding)
		{
			
			if (ApplicationTime.TimePast % value.first == 0 && ApplicationTime.TimePast >= value.first) {
				
				for (auto func : value.second)
				{
					func();
				}
				
			}

		}


	}

	void TradingApplication::ExecuteConditionals()
	{
		

	}

	//Execute Application
	void TradingApplication::Run()
	{
		std::cout << "Runing ..." << std::endl;
		Awake();
		while (true)
		{
			ApplicationTime.SetStartTime();
			Update();
			LateUpdate();
			ExecuteTimedBindings();
			ExecuteConditionals();
			ApplicationTime.SetEndTime();
			ApplicationTime.SetDeltaTime();
			ApplicationTime.SetTimePast();

		}
	}
}
