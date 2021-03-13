#include "WebSocket.h"
#include <iostream>
#include <cpprest/ws_client.h>
#include <utility>
#include <future>

//using namespace web;
//using namespace web::websockets::client;


namespace Chernobyl
{
	/*std::string webSocket*/

	static std::future<void> pendingFuture;

	WebSocket::WebSocket(std::string url)
	{
		client.connect(web::uri::uri(utility::conversions::to_string_t(url))).wait();
		isConnected = true;
		pendingFuture = std::async(std::launch::async, &WebSocket::listen, this);
		
		// For testing only
		sendMessage("Test");
		std::this_thread::sleep_for(std::chrono::seconds(5));
		sendMessage("Another test");
	}

	void WebSocket::listen() {
		std::cout << "Listening\n";
		while (true) {
			try {
				// Listen for messages and call onMessageReceived if there is one
				client.receive().then([](web::websockets::client::websocket_incoming_message incomingMessage) {
					return incomingMessage.extract_string();
					}).then([&](std::string body) {
						// Probably call this method on another thread
						onMessageReceived(body);
					}).wait();
			}
			catch (...) {
				//std::cout << "Exception\n";
				break;
			}
			std::this_thread::sleep_for(std::chrono::seconds(2));
		}
		
	}

	void WebSocket::sendMessage(std::string message) {
		if (isConnected) {
			web::websockets::client::websocket_outgoing_message outMessage;
			outMessage.set_utf8_message(message);
			client.send(outMessage).wait();
		}
	}

	void WebSocket::closeConnection() {
		// Potential race condition with listening thread -> Probably not a problem anymore
		isConnected = false;
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
		std::cout << "Message Received: " << message << std::endl;
	}
	/*
	void WebSocket::onFail(websocketpp::connection_hdl hdl)
	{

	}*/
}
