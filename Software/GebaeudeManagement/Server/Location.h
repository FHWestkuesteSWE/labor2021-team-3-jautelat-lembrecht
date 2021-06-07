//Location.h

#ifndef LOCATION_H
#define LOCATION_H


#include "Raum.h"
#include "Zugang.h"

class Location {
public:
	std::string location_bez;
	std::map<std::string, Zugang> accesses;
	std::map<std::string, Raum> rooms;
	
	Location();

	bool readAccess(std::string raum_bez);
	void addAccess(std::string zugang_bez);
	void delAccess(std::string zugang_bez);

	void addRoom(std::string raum_bez);
	void delRoom(std::string raum_bez);

private:

};

#endif
