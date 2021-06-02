//LocationServer.h

#ifndef LOCATIONSERVER_H
#define LOCATIONSERVER_H

#include <string> //error without
#include "BasicServer.h"

class LocationServer : BasicServer
{
public:


private:
	virtual void processRequest(char request[], char answer[]);
	std::string getSubString(std::string const& s);
};

#endif


