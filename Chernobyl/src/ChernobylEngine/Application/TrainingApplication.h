#pragma once
#include "Application.h"
#include "../Core/ChernobylCore.h"
#include "../DataModels/Trade.h"
#include "../DataModels/Candle.h"
#include <vector>
#include <map>
#include "../DataModels/Quote.h"

namespace Chernobyl {
	class CHERNOBYL_API TrainingApplication: public Application
	{
	public:
		std::map<std::string, std::vector<Candle>> subscription;
	public:
		TrainingApplication();
		~TrainingApplication();

		virtual void Run();
		void Subscribe(std::string symbol, std::string from, std::string to, int resolution = 1);
		virtual void Awake();

		std::vector<Candle>* GetData(std::string symbol);

		template<class T>
		std::vector<T> ForEach(std::string symbol, void(func)(Candle));

		template<class T>
		std::vector<T> CompareNeighbors(std::string symbol, void(func)(Candle, Candle));

		template<class T>
		std::vector<T> CompareIntervals(std::string symbol, int i, void(func)(Candle, Candle));
		
		template<class T>
		std::vector<T> CompareIntervals(std::string symbol, std::string time, void(func)(Candle, Candle));

		
	};
}


