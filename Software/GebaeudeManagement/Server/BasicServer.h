#pragma once

#ifndef BASICSERVER_H
#define BASICSERVER_H


#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/thread/thread.hpp>

typedef boost::shared_ptr<boost::asio::ip::tcp::socket> socket_ptr;

class BasicServer
{
public:
	void start(char port[]);
	BasicServer();
	~BasicServer();
	const static int max_length = 1024;

private:
	void session(socket_ptr sock);
	virtual void processRequest(char request[], char answer[]);
	//std::string getSubString(std::string const &s);
};

#endif