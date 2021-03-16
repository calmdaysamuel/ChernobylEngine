#pragma once
#/*include <websocketpp/config/asio_client.hpp>

#include <websocketpp/client.hpp>*/
#include <iostream>
#include <chrono>
#include <cpprest/ws_client.h>
#include <future>
#include "DataModels/Trade.h"

namespace Chernobyl
{
	class WebSocket
	{
	public:
		WebSocket(std::string, std::function<void(Trade*)>);
		~WebSocket();
		// Consider const char *
		void onMessageReceived(std::string);
		bool sendMessage(std::string);
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
		web::websockets::client::websocket_callback_client client;
		//void listen();
		bool isConnected;
		std::future<void> pendingFuture;
		pplx::task_completion_event<void> tce;
		Concurrency::task<void> receive_task;
		std::function<void(Trade*)> onTradeReceived;
	};



}

