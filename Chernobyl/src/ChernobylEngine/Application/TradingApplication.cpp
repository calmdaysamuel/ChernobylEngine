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
		Subscription[symbol] = new Quote(symbol);
		Subscription[symbol]->Subscribe();
	}

	//Time Functions
	void TradingApplication::AfterTimeAmount(std::string time, void(*func)())
	{
		afterTimeAmountBinding[time].push_back(func);
		timeAmountValues.insert(time);
	}

	void TradingApplication::EveryTimeAmount(std::string time, void(*func)())
	{
		everyTimeAmountBinding[time].push_back(func);
		timeAmountValues.insert(time);
	}

	//Helper Functions
	template<class T>
	void TradingApplication::ForEachTrade(std::string symbol, void(*func)(Trade))
	{

	}

	template<class T>
	void TradingApplication::CompareNeighboringTrades(std::string symbol, void(*func)(Trade, Trade))
	{

	}

	template<class T>
	void TradingApplication::CompareIntervals(std::string symbol, int i, void(*func)(Trade, Trade))
	{

	}

	template<class T>
	void TradingApplication::CompareIntervals(std::string symbol, std::string time, void(*func)(Trade, Trade))
	{

	}

	void TradingApplication::OnTradeReceived(std::string symbol)
	{
		onTradeRecievedBindings[symbol](Trade());
		onTradeRecievedBindings[UNIVERSAL_RECEIVED_BINDING](Trade());
	}

	//Binding Functions
	void TradingApplication::BindTradeReceived(std::string symbol, void(*func)(Trade))
	{
		onTradeRecievedBindings[symbol] = func;
	}

	void TradingApplication::BindAnyTradeReceived(void(*func)(Trade))
	{
		onTradeRecievedBindings[UNIVERSAL_RECEIVED_BINDING] = func;
	}
	
	void TradingApplication::BindToKey(std::string key, void(*func)())
	{
		//TODO: BINDS A KEY ON THE KEYBOARD TO A FUNCTION
		//TODO: USEFUL FOR LOGGING OR CHANGING ALGORITHM

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
		for (auto value : timeAmountValues)
		{
			if (ApplicationTime.ToSeconds(value))
			{
				if (everyTimeAmountBinding.find(value) != everyTimeAmountBinding.end())
				{
					for (auto func : afterTimeAmountBinding[""])
					{
						func();
					}
				}

				if (afterTimeAmountBinding.find(value) != afterTimeAmountBinding.end())
				{
					for (auto func : everyTimeAmountBinding[""])
					{
						func();
					}
				}
			}

		}

	}

	void TradingApplication::ExecuteConditionals()
	{
		for (auto value: buyIfBindings)
		{
			if (value.second())
			{
				Buy(value.first, 1);
			}
		}

		for (auto value : sellIfBindings)
		{
			if (value.second())
			{
				Sell(value.first, 1);
			}
		}

		for (auto value : sellIfBindings)
		{
			if (value.second())
			{
				SellAll(value.first);
			}
		}

		for (auto value : ifBindings)
		{
			if (value.first())
			{
				value.second();
			}
		}

	}

	//Execute Application
	void TradingApplication::Run()
	{
		std::cout << "Runing" << std::endl;
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
