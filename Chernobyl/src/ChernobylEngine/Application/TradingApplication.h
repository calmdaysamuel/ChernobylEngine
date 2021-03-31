#pragma once
#include "Application.h"
#include "../Core/ChernobylCore.h"
#include "../DataModels/Quote.h"
#include "../DataModels/Trade.h"
#include "../DataModels/Subscription.h"

#include <DataModels/Portfolio.h>
#include "Networking/WebSocket.h"
namespace Chernobyl
{
	class CHERNOBYL_API TradingApplication : public Application
	{
	public:
		TradingApplication();
		~TradingApplication();
		virtual void Awake();
		void Run();
		void Init();
		void ProcessInput();
		virtual void BindTradeReceived(std::string symbol, std::function<void(Trade)> func);
		virtual void BindAnyTradeReceived(std::function<void(Trade)> func);
		void BindToKey(std::string key, std::function<void(void)> func);
		void Subscribe(std::string symbol);
		Quote GetQuote(std::string symbol);
		void AfterTimeAmount(std::string time, std::function<void(void)> func);
		void EveryTimeAmount(std::string time, std::function<void(void)> func);


		
		//Buy And Sell
		void BuyWithLimit(std::string symbol, int amount, double limitPrice = 1);
		void Buy(std::string symbol, int amount);
		void SellWithStopLoss(std::string symbol, int amount, double stopPrice);
		void Sell(std::string symbol, int amount);
		void SellAll(std::string symbol);
		void SellWithLimit(std::string symbol, int amount, double limitPrice = 1);

		//Conditional Binding
		void BuyIf(std::string symbol, int amount, std::function<bool(void)> condition);
		void SellIf(std::string symbol, int amount, std::function<bool(void)> condition);
		void SellAllIf(std::string symbol, std::function<bool(void)> condition);
		void If(std::function<bool(void)> condition, std::function<void(void)> func);
	private:
		void ExecuteConditionals();
		void ExecuteTimedBindings();
		void OnTradeReceived(Trade* trade);


	private:
		std::map<std::string, std::vector<std::function<bool(void)>>> buyIfBindings;
		std::map<std::string, std::vector<std::function<bool(void)>>> sellIfBindings;
		std::map<std::string, std::vector<std::function<bool(void)>>> sellAllIfBindings;
		std::vector<std::tuple<std::function<bool(void)>, std::function<void(void)>>> ifBindings;
		std::map<std::string, std::vector<std::function<void(Trade)>>> onTradeRecievedBindings;
		std::map<std::string, std::vector<std::function<void(void)>>> keyBinding;
		std::string UNIVERSAL_RECEIVED_BINDING = "UNIVERSAL_RECEIVED_BINDING";
		
		//Time
		std::map<int, std::vector<std::function<void(void)>>> everyTimeAmountBinding;
		std::map<int, std::vector<std::function<void(void)>>> afterTimeAmountBinding;
		int lastTime = -1;

	public:
		Portfolio portfolio;
		std::map<std::string, Subscription*> subscriptions;
		WebSocket* webSocket;
	};
}


