#include "API.h"
#include <cpprest/http_client.h>
namespace Chernobyl
{

	web::json::value API::QuoteRequestJSON(std::string requestQuery)
	{
		return web::json::value::parse(utility::conversions::to_string_t(GetRequest(requestQuery)));
	}

	std::string API::QuoteRequestString(std::string requestQuery)
	{
		return GetRequest(requestQuery);
	}

	std::string API::GetRequest(std::string requestQuery)
	{
		web::http::client::http_client client(utility::conversions::to_string_t(requestQuery));

		web::http::uri_builder builder(U("SADA"));

		std::string responseString;
		auto hr = client.request(web::http::methods::GET)

			.then(
				[=](web::http::http_response response)
				{
					std::string data(utility::conversions::to_utf8string(response.extract_string().get()));
					return data;
				}
			);

		responseString = hr.get();

		return responseString;
	}


}
