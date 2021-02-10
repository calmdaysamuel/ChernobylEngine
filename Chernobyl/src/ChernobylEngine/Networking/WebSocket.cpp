#include "WebSocket.h"

namespace Chernobyl
{


	WebSocket::WebSocket(std::string webSocket)
	{
		endpoint.set_access_channels(websocketpp::log::alevel::all);
		endpoint.set_error_channels(websocketpp::log::elevel::all);

		// Initialize ASIO
		endpoint.init_asio();
		endpoint.set_socket_init_handler(bind(&WebSocket::onSocketInit, this, websocketpp::lib::placeholders::_1));
		endpoint.set_message_handler(websocketpp::lib::bind(&WebSocket::onMessageReceived, this, websocketpp::lib::placeholders::_1, websocketpp::lib::placeholders::_2));
		endpoint.set_open_handler(websocketpp::lib::bind(&WebSocket::onOpen, this, websocketpp::lib::placeholders::_1));
		endpoint.set_close_handler(websocketpp::lib::bind(&WebSocket::onClose, this, websocketpp::lib::placeholders::_1));
		endpoint.set_fail_handler(websocketpp::lib::bind(&WebSocket::onFail, this, websocketpp::lib::placeholders::_1));

		websocketpp::lib::error_code ec;
		auto con = endpoint.get_connection(webSocket, ec);

		if (ec) {
			endpoint.get_alog().write(websocketpp::log::alevel::app, ec.message());
			std::cout << "Something weird is happening" << std::endl;
			return;
		}

		endpoint.connect(con);
		endpoint.run();
		std::cout << "Something weird is not  happening" << std::endl;

	}

	void WebSocket::onSocketInit(websocketpp::connection_hdl)
	{

	}
	void WebSocket::onClose(websocketpp::connection_hdl hdl)
	{
		
	}

	void WebSocket::onOpen(websocketpp::connection_hdl hdl)
	{

	}

	void WebSocket::onMessageReceived(websocketpp::connection_hdl hdl, message_ptr)
	{
		std::cout << "Message Received" << std::endl;
	}

	void WebSocket::onFail(websocketpp::connection_hdl hdl)
	{

	}
}
