#pragma once
#include <cpprest/http_client.h>
#include "DataModels/Quote.h"
namespace Chernobyl
{
	class API
	{
	public:

		static web::json::value GetRequest(std::string requestQuery);

		static Quote JsonToQuote(web::json::value quoteObj);

		static Quote GetQuote(std::string symbol);
	};
}


