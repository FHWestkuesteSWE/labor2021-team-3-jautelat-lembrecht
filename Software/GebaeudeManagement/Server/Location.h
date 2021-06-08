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

	bool getAccess(std::string zugang_bez);
	bool setAccess(std::string zugang_bez, bool lock);
	void addAccess(std::string zugang_bez);
	void delAccess(std::string zugang_bez);

	float getRoomTemp(std::string raum_bez);
	bool setRoomTemp(std::string raum_bez, float temp);
	void addRoom(std::string raum_bez);
	void delRoom(std::string raum_bez);

private:

};

#endif
