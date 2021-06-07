#define _CRT_SECURE_NO_WARNINGS

#include "LocationServer.h"
#include "BasicServer.h"
#include "Location.h"

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>


void LocationServer::processRequest(char req[], char ans[])
{
	//strncpy(ans, req, std::min<int>(max_length, strlen(ans) + 1));
	
	/*
	std::string::size_type pos = std::string::npos;
	std::string command = getSubString(req);
	std::string options = "";
	*/

	std::vector<std::string> command = splitCommand(req);
	std::string answer = "No answer defined.";
	std::string cmd = command[0];
	if (cmd == "state") {
		bool zustand = location.readAccess(command[1]);
		if (zustand)
		{
			answer = "Der Zugang ist VERSCHLOSSEN";
		}
		else
		{
			answer = "Der Zugang ist offen";
		}

	}
	else if (cmd == "add") {
		if (command[1] == "access")
		{
			location.addAccess(command[2]);
			answer = "Der Zugang " + command[2] + " wurde erstellt.";
		}
		else if (command[1] == "room")
		{
			location.addRoom(command[2]);
			answer = "Der Raum " + command[2] + " wurde erstellt.";
		}
		else 
		{
			answer = "Bitte geben Sie einen Typ (\"room\" oder \"access\") an!";
		}
	}
	else {
		answer = "Unknown command!";
	}
	strcpy(ans, answer.c_str());
}

std::vector<std::string> LocationServer::splitCommand(char req[])
{
	std::vector<std::string> list = {};
	
	std::string request = req;
	uint16_t pos = 0;
	size_t end = 1024;
	do 
	{
		end = request.find('|');
		pos = request.find(' ');
		list.push_back(request.substr(0, pos));
		request = request.substr(pos+1, end);
	} while (pos < end-1);

	return list;
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

void LocationServer::saveLocation(Location loc)
{

	return;
}

Location LocationServer::openLocation(std::string path)
{
	Location loc1;
	return loc1;
}