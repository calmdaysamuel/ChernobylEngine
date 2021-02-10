#pragma once
#include <websocketpp/config/asio_client.hpp>

#include <websocketpp/client.hpp>
#include <iostream>
#include <chrono>

namespace Chernobyl
{
	class WebSocket
	{
	public:
		WebSocket();
		typedef websocketpp::config::asio_tls_client::message_type::ptr message_ptr;
		WebSocket(std::string webSocket);

		void onOpen(websocketpp::connection_hdl hdl);
		void onMessageReceived(websocketpp::connection_hdl hdl, message_ptr);
		void onClose(websocketpp::connection_hdl hdl);
		void onFail(websocketpp::connection_hdl hdl);
		void onSocketInit(websocketpp::connection_hdl);
		websocketpp::client<websocketpp::config::asio_client> endpoint;
		void* messageRecieved;
	};



}

