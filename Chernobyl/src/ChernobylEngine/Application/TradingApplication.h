#pragma once
#include "Application.h"
#include "../Core/ChernobylCore.h"
#include "../DataModels/Quote.h"
#include "../DataModels/Trade.h"
#include "../DataModels/Subscription.h"
#include <set>
#include <functional>
#include <DataModels/Account.h>
namespace Chernobyl
{
	class CHERNOBYL_API TradingApplication : public Application
	{
	public:
		std::map<std::string, Subscription*> subscriptions;
		bool tradeReceived = false;
		Trade lastestTrade;
		std::string symbol;
		WebSocket* ws;

	public:
		TradingApplication();
		~TradingApplication();

		virtual void Update();
		virtual void LateUpdate();
		virtual void Awake();
		void Run();

		virtual void BindTradeReceived(std::string symbol, std::function<void(Trade)> func);
		virtual void BindAnyTradeReceived(std::function<void(Trade)> func);
		void BindToKey(std::string key, std::function<void(void)> func);
		void Subscribe(std::string symbol);

		void AfterTimeAmount(std::string time, std::function<void(void)> func);
		void EveryTimeAmount(std::string time, std::function<void(void)> func);

		void ForEachTrade(std::string symbol, std::function<void(Trade)> func);

		void CompareNeighboringTrades(std::string symbol, std::function<void(Trade, Trade)> func);

		void CompareIntervals(std::string symbol, int i, std::function<void(Trade, Trade)> func);

		void CompareIntervals(std::string symbol, std::string time, std::function<void(Trade, Trade)> func);


		
		//Buy And Sell
		void BuyWithLimit(std::string symbol, int amount, float limitPrice = 1);
		void Buy(std::string symbol, int amount);
		void SellWithStopLoss(std::string symbol, int amount);
		void Sell(std::string symbol, int amount);
		void SellAll(std::string symbol);
		void SellWithLimit(std::string symbol, int amount, float limitPrice = 1);

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

		Account account;

	};
}


