//Location.h

#ifndef LOCATION_H
#define LOCATION_H

//#include <string>
#include "Raum.h"
#include "Zugang.h"

class Location {
public:
	std::string location_bez;
	std::map<std::string, Raum> rooms;
	void addRoom(std::string raum_bez);
	
	std::map<std::string, Zugang> accesses;
	void addAccess(std::string zugang_bez);

private:

};

#endif
