#define _CRT_SECURE_NO_WARNINGS

#define WARNING_NO_TYPE "Bitte geben Sie einen Typ (\"room\" oder \"access\") an!"

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
	const std::string warning_no_type = WARNING_NO_TYPE;
	std::vector<std::string> command = splitCommand(req);
	std::string answer = "No answer defined.";
	std::string cmd = command[0];
	if (cmd == "get") {
		if (command[1] == "access")
		{
			bool zustand = location.getAccess(command[1]);
			if (zustand)
			{
				answer = "Der Zugang ist VERSCHLOSSEN";
			}
			else
			{
				answer = "Der Zugang ist offen";
			}
		}
		else if (command[1] == "room")
		{
			float temp = location.getRoomTemp(command[2]);
			answer = "Die Raumtemperatur beträgt: " + std::to_string(temp) + " C.";
		}
		else
		{
			answer = warning_no_type;
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
			answer = warning_no_type;
		}
	}
	else if (cmd == "set") {
		if (command[1] == "access")
		{
			bool zustand = detectTrueString(command[2]);
			location.setAccess(command[2], zustand);
			answer = "Der Zugang " + command[2] + " wurde auf " + std::to_string(zustand) + " gesetzt.";
		}
		else if (command[1] == "room")
		{
			float temp = 19.0;//float(command[3]);
			location.setRoomTemp(command[2], temp);
			answer = "Die Soll-Temperatur im Raum wurde auf " + std::to_string(temp) + " C gesetzt.";
		}
		else
		{
			answer = warning_no_type;
		}
	}
	else if (cmd == "del") {
		if (command[1] == "access")
		{
			location.delAccess(command[2]);
			answer = "Der Zugang " + command[2] + " wurde gelöscht.";
		}
		else if (command[1] == "room")
		{
			location.delRoom(command[2]);
			answer = "Der Raum " + command[2] + " wurde gelöscht.";
		}
		else
		{
			answer = warning_no_type;
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

bool LocationServer::detectTrueString(std::string str)
{
	if (str == "true" || str == "True" || str == "TRUE" || str == "1")
	{
		return true;
	}
	else
	{
		return false;
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
