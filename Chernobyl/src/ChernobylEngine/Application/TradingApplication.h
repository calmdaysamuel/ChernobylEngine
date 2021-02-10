#pragma once
#include "Application.h"
#include "../Core/ChernobylCore.h"
#include "../DataModels/Quote.h"
#include "../DataModels/Trade.h"
#include <set>
namespace Chernobyl
{
	class CHERNOBYL_API TradingApplication : public Application
	{
	public:
		std::map<std::string, Quote*> Subscription;
		bool tradeReceived = false;
		Trade lastestTrade;
		std::string symbol;

	public:
		TradingApplication();
		~TradingApplication();

		virtual void Update();
		virtual void LateUpdate();
		virtual void Awake();
		void Run();

		virtual void BindTradeReceived(std::string symbol, void(*func)(Trade));
		virtual void BindAnyTradeReceived(void(*func)(Trade));
		void BindToKey(std::string key, void(*func)());
		void Subscribe(std::string symbol);

		void AfterTimeAmount(std::string time, void(*func)());
		void EveryTimeAmount(std::string time, void(*func)());

		template<class T>
		void ForEachTrade(std::string symbol, void(*func)(Trade));

		template<class T>
		void CompareNeighboringTrades(std::string symbol, void(*func)(Trade, Trade));

		template<class T>
		void CompareIntervals(std::string symbol, int i, void(*func)(Trade, Trade));

		template<class T>
		void CompareIntervals(std::string symbol, std::string time, void(*func)(Trade, Trade));

		//Buy And Sell
		void BuyWithLimit(std::string symbol, int amount, float limitPrice = 1);
		void Buy(std::string symbol, int amount);
		void SellWithStopLoss(std::string symbol, int amount);
		void Sell(std::string symbol, int amount);
		void SellAll(std::string symbol);
		void SellWithLimit(std::string symbol, int amount, float limitPrice = 1);

		//Conditional Binding
		void BuyIf(std::string symbol, int amount, bool(*condition)());
		void SellIf(std::string symbol, int amount, bool(*condition)());
		void SellAllIf(std::string symbol, bool(*condition)());
		void If(bool(*condition)(), bool(*func)());
	private:
		void ExecuteConditionals();
		void ExecuteTimedBindings();
		void OnTradeReceived(std::string symbol);


	private:
		std::map<std::string, bool(*)()> buyIfBindings;
		std::map<std::string, bool(*)()> sellIfBindings;
		std::map<std::string, bool(*)()> sellAllIfBindings;
		std::map<bool(*)(), void(*)()> ifBindings;
		std::map<std::string, void(*)(Trade)> onTradeRecievedBindings;
		std::map<std::string, std::vector<void(*)()>> everyTimeAmountBinding;
		std::map<std::string, std::vector<void(*)()>> afterTimeAmountBinding;
		std::string UNIVERSAL_RECEIVED_BINDING = "UNIVERSAL_RECEIVED_BINDING";
		std::set<std::string> timeAmountValues = {};
	};
}


