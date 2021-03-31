#include "TradingApplication.h"
#include "../Timer/Time.h"
#include "../Networking/WebSocket.h"
#include "Networking/API.h"
#include <future>
namespace Chernobyl
{
	//Constructor and Destructor
	TradingApplication::TradingApplication()
	{
		webSocket = new WebSocket("wss://ws.finnhub.io?token=c0g8rn748v6ob1prm39g", std::bind(&TradingApplication::OnTradeReceived, this, std::placeholders::_1));
	}

	TradingApplication::~TradingApplication()
	{

	}

	void TradingApplication::Init()
	{
		// std::future<void> inputProcess = std::async(std::bind(&TradingApplication::ProcessInput, this));
		//  std::thread inputProcess(std::bind(&TradingApplication::ProcessInput, this));
	}
	


	// DONE
	void TradingApplication::ProcessInput()
	{
		while (true)
		{
			std::string input;
			std::cin >> input;
			std::cout << "I am asynchronous" << std::endl;
			if (keyBinding.find(input) != keyBinding.end())
			{
				for (auto func : keyBinding[input])
				{
					func();
				}
			}
		}
	}

	void TradingApplication::Run()
	{
		std::cout << "Runing ..." << std::endl;

		Awake();
		Init();
		while (true)
		{
			ApplicationTime.SetStartTime();
			ExecuteTimedBindings();
			ExecuteConditionals();
			ApplicationTime.SetEndTime();
			ApplicationTime.SetDeltaTime();
			ApplicationTime.SetTimePast();

		}
	}

	void TradingApplication::ExecuteConditionals()
	{

		for (auto value : ifBindings)
		{
			if (std::get<0>(value))
			{
				std::get<1>(value);
			}
		}

	}

	void TradingApplication::If(std::function<bool(void)> condition, std::function<void(void)> func)
	{
		auto temp = std::make_tuple(condition, func);

		ifBindings.push_back(temp);
	}

	void TradingApplication::ExecuteTimedBindings()
	{
		if (ApplicationTime.TimePast / 1000 == lastTime)
		{
			return;
		}
		lastTime = ApplicationTime.TimePast / 1000;
		for (auto value : everyTimeAmountBinding)
		{

			if (ApplicationTime.TimePast / 1000 % value.first == 0 && ApplicationTime.TimePast / 1000 >= value.first) {

				for (auto func : value.second)
				{
					func();
				}

			}

		}


	}

	void TradingApplication::Awake()
	{

	}

	void TradingApplication::Subscribe(std::string symbol)
	{
		if (subscriptions.find(symbol) == subscriptions.end()) {
			bool messageSent = webSocket->sendMessage("{ \"type\":\"subscribe\",\"symbol\" : \"" + symbol + "\" }");
			if (messageSent) {
				subscriptions[symbol] = new Subscription(symbol);
				portfolio.UpdatePosition(symbol, 0, 0.0);
				return;
			}
			// Throw network error exception here, cannot make subscription
		}

	}

	void TradingApplication::AfterTimeAmount(std::string time, std::function<void(void)> func)
	{
		afterTimeAmountBinding[ApplicationTime.ToSeconds(time)].push_back(func);
	}

	void TradingApplication::EveryTimeAmount(std::string time, std::function<void(void)> func)
	{
		everyTimeAmountBinding[ApplicationTime.ToSeconds(time)].push_back(func);
	}

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

	void TradingApplication::OnTradeReceived(Trade* trade)
	{
		subscriptions[trade->symbol]->AddTrade(trade);

		for (auto func : onTradeRecievedBindings[trade->symbol])
		{
			func(*trade);
		}

		for (auto func : onTradeRecievedBindings[UNIVERSAL_RECEIVED_BINDING])
		{
			func(*trade);
		}

	}

	void TradingApplication::SellWithStopLoss(std::string symbol, int amount, double stopPrice)
	{
		Quote q = GetQuote(symbol);
		auto temp = std::make_tuple([&]() {return stopPrice <= q.currentPrice; }, [&]() {Sell(symbol, amount); });
		ifBindings.push_back(temp);
	}

	void TradingApplication::Sell(std::string symbol, int amount)
	{
		//Quote q = GetQuote(symbol);
		portfolio.UpdatePosition(symbol, amount * -1, 123);
	}

	void TradingApplication::SellAll(std::string symbol)
	{
		Sell(symbol, INT_MIN);
	}

	void TradingApplication::SellWithLimit(std::string symbol, int amount, double limitPrice)
	{
		Quote q = GetQuote(symbol);
		auto temp = std::make_tuple([&]() {return q.currentPrice >= limitPrice; }, [&]() {Sell(symbol, amount); });
		ifBindings.push_back(temp);
	}

	void TradingApplication::BuyWithLimit(std::string symbol, int amount, double limitPrice)
	{
		Quote q = GetQuote(symbol);
		auto temp = std::make_tuple([&]() {return limitPrice >= q.currentPrice; }, [&]() {Buy(symbol, amount); });
		ifBindings.push_back(temp);
	}

	void TradingApplication::Buy(std::string symbol, int amount)
	{
		//Quote q = GetQuote(symbol);
		this->portfolio.UpdatePosition(symbol, amount, 123);
	}

	void TradingApplication::BuyIf(std::string symbol, int amount, std::function<bool(void)> condition)
	{
		auto temp = std::make_tuple(condition, [&]() {Buy(symbol, amount); });
		ifBindings.push_back(temp);
	}

	void TradingApplication::SellIf(std::string symbol, int amount, std::function<bool(void)> condition)
	{
		auto temp = std::make_tuple(condition, [&]() {Sell(symbol, amount); });
		ifBindings.push_back(temp);
	}

	void TradingApplication::SellAllIf(std::string symbol, std::function<bool(void)> condition)
	{
		auto temp = std::make_tuple(condition, [&]() {SellAll(symbol); });
		ifBindings.push_back(temp);
	}

	Quote TradingApplication::GetQuote(std::string symbol)
	{
		return API::GetQuote(symbol);
	}
}
