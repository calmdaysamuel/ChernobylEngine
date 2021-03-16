#include "WebSocket.h"
#include <iostream>
#include <cpprest/ws_client.h>
#include <utility>
#include <future>
#include "DataModels/Trade.h"
#include <nlohmann/json.hpp>

namespace Chernobyl
{
	/*std::string webSocket*/


	WebSocket::WebSocket(std::string url, std::function<void(Trade*)> onTradeReceived)
	{
		this->onTradeReceived = onTradeReceived;
		try {
			// FIXME: Use a pointer so as not to call the constructor twice
			auto config = web::websockets::client::websocket_client_config();

			// Credentials are compulsory for wss
			config.set_credentials(web::credentials());
			client = web::websockets::client::websocket_callback_client(config);
			client.connect(web::uri(utility::conversions::to_string_t(url))).wait();
		}
		catch (web::websockets::client::websocket_exception& e) {
			std::cout << e.what() << '\n';
			std::cin.get();
		}

		isConnected = true;
		receive_task = create_task(tce);
		client.set_message_handler([&](web::websockets::client::websocket_incoming_message incomingMessage) {
			auto extractedMessage = incomingMessage.extract_string().get();
			onMessageReceived(extractedMessage);
			tce.set();
			});

		utility::string_t close_reason;
		client.set_close_handler([&](web::websockets::client::websocket_close_status status,
			const utility::string_t& reason,
			const std::error_code& code) {
				ucout << " closing reason..." << reason << "\n";
				ucout << "connection closed, reason: " << reason << " close status: " << int(status) << " error code " << code << std::endl;
				onClose();
			});
	}

	WebSocket::~WebSocket() {
		std::cout << "Already destroyed\n";
	}

	bool WebSocket::sendMessage(std::string message) {
		if (isConnected) {
			web::websockets::client::websocket_outgoing_message outMessage;
			outMessage.set_utf8_message(message);
			client.send(outMessage).wait();
			return true;
		}
		return false;
	}

	void WebSocket::closeConnection() {
		// Potential race condition with listening thread -> Probably not a problem anymore
		isConnected = false;
		receive_task.wait();
		client.close().wait();
		onClose();
	}

	void WebSocket::onClose()
	{

	}

	/*void WebSocket::onSocketInit(websocketpp::connection_hdl)
	{

	}


	void WebSocket::onOpen(websocketpp::connection_hdl hdl)
	{

	}*/

	void WebSocket::onMessageReceived(std::string message)
	{
		if (!message.empty()) {
			auto jsonMessage = nlohmann::json::parse(message);

			if (jsonMessage["type"].get<std::string>() == "trade") {
				auto jsonData = jsonMessage["data"][0];
				Trade* trade = new Trade(jsonData["s"].get<std::string>(), jsonData["p"].get<float>(), std::to_string(jsonData["t"].get<long long>()), jsonData["v"].get<float>(), "");
				onTradeReceived(trade);
			}

		}
	}
	/*
	void WebSocket::onFail(websocketpp::connection_hdl hdl)
	{

	}*/
}
