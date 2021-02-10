#pragma once
#include <string>
#include <cpprest/http_client.h>
#include <websocketpp/client.hpp>
#include <websocketpp/config/asio_no_tls_client.hpp>

namespace Chernobyl
{
	class API
	{
	public:
		static websocketpp::client<websocketpp::config::asio_client>*  InitWebSocket(std::string webSocket);

		static std::string QuoteRequestString(std::string requestQuery);

		static web::json::value QuoteRequestJSON(std::string requestQuery);

		static std::string GetRequest(std::string requestQuery);

	};
}


