#include "API.h"
#include <cpprest/http_client.h>
namespace Chernobyl
{

	

	web::json::value API::GetRequest(std::string requestQuery)
	{
		return web::json::value();
	}

	Quote API::JsonToQuote(web::json::value quoteObj)
	{
		return Quote();
	}

	Quote API::GetQuote(std::string symbol)
	{
		std::string url = "";
		return API::JsonToQuote(API::GetRequest(url + ""));
	}


}
