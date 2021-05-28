#define _CRT_SECURE_NO_WARNINGS
#include "BasicServer.h"
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>

void BasicServer::session(socket_ptr sock)
{
	try
	{
		for (;;)
		{
			char request[BasicServer::max_length];
			char answer[BasicServer::max_length];
			boost::system::error_code error;
			size_t length = sock->read_some(boost::asio::buffer(request), error);
			if (error == boost::asio::error::eof)
				break; // Connection closed cleanly by peer.
			else if (error)
				throw boost::system::system_error(error); // Some other error.
			this->processRequest(request, answer);
			boost::asio::write(*sock, boost::asio::buffer(boost::asio::buffer(answer), max_length));
		}
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception in thread: " << e.what() << "\n";
	}
}
BasicServer::BasicServer()
{

}

void BasicServer::start(char port[]) {
	boost::asio::io_service io_service;

	using namespace std; // For atoi.
	using boost::asio::ip::tcp;
	tcp::acceptor a(io_service, tcp::endpoint(tcp::v4(), atoi(port)));
	for (;;)
	{
		socket_ptr sock(new tcp::socket(io_service));
		a.accept(*sock);
		boost::thread t(boost::bind(&BasicServer::session, this, sock));
	}
}

void BasicServer::processRequest(char req[], char ans[]) {
	//strncpy(ans, req, std::min<int>(max_length, strlen(ans) + 1));
	std::string command = getSubString(req);
	std::string answer = "No answer defined.";
	if (command == "state") {
		answer = "Der Zugang hat den Status:";
	}
	else {
		answer = "Unknown command!";
	}
	strcpy(ans, answer.c_str());
}

std::string BasicServer::getSubString(std::string const &s)
{
	std::string::size_type pos = s.find(' ');
	if (pos != std::string::npos)
	{
		return s.substr(0, pos);
	}
	else
	{
		return s;
	}
}

BasicServer::~BasicServer()
{
}