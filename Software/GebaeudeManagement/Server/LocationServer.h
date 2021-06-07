//LocationServer.h

#ifndef LOCATIONSERVER_H
#define LOCATIONSERVER_H

#include <string> //error without
#include "BasicServer.h"
#include "Location.h" //error without

class LocationServer : public BasicServer
{
public:


private:
	Location location;
	virtual void processRequest(char request[], char answer[]);
	std::vector<std::string> splitCommand(char req[]);
	std::string getSubString(std::string const& s);
	void saveLocation(Location loc);
	Location openLocation(std::string path);
};

#endif


