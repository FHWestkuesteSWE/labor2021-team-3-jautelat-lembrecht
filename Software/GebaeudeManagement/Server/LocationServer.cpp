#define _CRT_SECURE_NO_WARNINGS

#include "LocationServer.h"
#include "BasicServer.h"
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>


void LocationServer::processRequest(char req[], char ans[]) {
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

std::string LocationServer::getSubString(std::string const &s)
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
