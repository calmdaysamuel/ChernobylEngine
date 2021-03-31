#include "TrainingApplication.h"

namespace Chernobyl
{
	TrainingApplication::TrainingApplication()
	{

	}

	TrainingApplication::~TrainingApplication()
	{

	}

	void TrainingApplication::Run()
	{

	}

	void TrainingApplication::Awake()
	{

	}

	void TrainingApplication::Subscribe(std::string symbol, std::string from, std::string to, int resolution)
	{
		// subscription[symbol] = Quote("AAPL").GetCandles();
	}

	std::vector<Candle>* TrainingApplication::GetData(std::string symbol)
	{
		return new std::vector<Candle>();
	}

	template<class T>
	std::vector<T> TrainingApplication::ForEach(std::string symbol, void(func)(Candle))
	{
		return std::vector<T>();

	}

	template<class T>
	std::vector<T> TrainingApplication::CompareNeighbors(std::string symbol, void(func)(Candle, Candle))
	{
		return std::vector<T>();
	}

	template<class T>
	std::vector<T> TrainingApplication::CompareIntervals(std::string symbol, int i, void(func)(Candle, Candle))
	{
		return std::vector<T>();
	}

	template<class T>
	std::vector<T> TrainingApplication::CompareIntervals(std::string symbol, std::string time, void(func)(Candle, Candle))
	{
		return std::vector<T>();
	}
}