#pragma once
#include <string>
#include "ChernobylEngine/Core/ChernobylCore.h"
#include "Trade.h"
#include "../Networking/API.h"
#include <cpprest/ws_client.h>
#include <cpprest/http_client.h>
#include <vector>
#include <string>

#include <cpprest/filestream.h>
#include "Networking/WebSocket.h"
#include "Candle.h"

namespace Chernobyl
{

	class CHERNOBYL_API Quote
	{
		typedef web::websockets::client::websocket_client  WebSocketClient;
		typedef web::http::client::http_client HttpClient;
		typedef web::http::http_response HttpResponse;
	public:
		
		std::string symbol;
		float openPrice;
		float lowPrice;
		float currentPrice;
		float previousClosePrice;
		float highPrice;
		WebSocket* webSocket = nullptr;

		Quote()
		{
			symbol = "AAPL";
			GetQuote();
		}
		Quote(std::string s)
		{
			symbol = s;
			GetQuote();
		}
		std::vector<Trade> tradeStream;

	public:
		void Subscribe()
		{
			webSocket = new WebSocket("wss://ws.finnhub.io?token=c0g8rn748v6ob1prm39g&symbol=AAPL");
		}

		void GetQuote()
		{

			std::cout << "Getting Quote" << std::endl;
			auto data = API::QuoteRequestJSON("https://finnhub.io/api/v1/quote?symbol=AAPL&token=c0g8rn748v6ob1prm39g");
			
			openPrice = data.at(L"o").as_number().to_double();
			highPrice = data.at(L"h").as_number().to_double();
			lowPrice = data.at(L"l").as_number().to_double();
			currentPrice = data.at(L"c").as_number().to_double();
			previousClosePrice = data.at(L"pc").as_number().to_double();
			std::cout << symbol << openPrice << lowPrice << std::endl;
				                    // Common utilities like string conversions
				//using namespace web;                        // Common features like URIs.
				//using namespace web::http;                  // Common HTTP functionality
				//using namespace web::http::client;          // HTTP client features
				//using namespace concurrency::streams;       // Asynchronous streams


			
				//auto fileStream = std::make_shared<ostream>();


				//http_client client(U("https://finnhub.io/api/v1"));

				//// Build request URI and start the request.
				//uri_builder builder(U("/quote"));


				//builder.append_query(U("symbol"), U("ftyytf"));
				//builder.append_query(U("token"), U("c0g8rn748v6ob1prm39g"));
				//auto hr = client.request(methods::GET, builder.to_string());

				//hr.then([=](http_response response) {

				//std::string data(conversions::to_utf8string(response.extract_string().get()));

				//return data;
				//}).then([=](std::string info) {
				//	std::cout << info << std::endl;
				//	});

				//std::cin.get();
	
			
		}

		std::vector<Candle> GetCandles()
		{
			return std::vector<Candle>();
		}
	//	void ToTrade(std::string info)
	//	{
	//		Trade trade;
	//		OnTradeRecieved(trade);
	//	}

	//	virtual void OnTradeRecieved(Trade trade)
	//	{

	//	}

	//	void UpdateQuoteData()
	//	{
	//		web::uri_builder builder(U("/search"));
	//		//quoteClientHttp.request(web::http::methods::GET, builder.to_string());
	//	}

	};

}


