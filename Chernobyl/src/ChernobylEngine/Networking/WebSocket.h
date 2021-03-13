#pragma once
#/*include <websocketpp/config/asio_client.hpp>

#include <websocketpp/client.hpp>*/
#include <iostream>
#include <chrono>
#include <cpprest/ws_client.h>
namespace Chernobyl
{
	class WebSocket
	{
	public:
		WebSocket(std::string);
		// Consider const char *
		void onMessageReceived(std::string);
		void sendMessage(std::string);
		void closeConnection();
		void onClose();
		/*typedef websocketpp::config::asio_tls_client::message_type::ptr message_ptr;
		WebSocket(std::string webSocket);

		void onOpen(websocketpp::connection_hdl hdl);
		
		
		void onFail(websocketpp::connection_hdl hdl);
		void onSocketInit(websocketpp::connection_hdl);
		websocketpp::client<websocketpp::config::asio_client> endpoint;*/
		//void* messageRecieved;
	private:
		web::websockets::client::websocket_client client;
		void listen();
		bool isConnected;
	};



}

