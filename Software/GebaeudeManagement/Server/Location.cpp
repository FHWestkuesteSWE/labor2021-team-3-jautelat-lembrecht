//Location.cpp

#include <string>
#include <map>

#include "Location.h"
#include "Raum.h"
#include "Zugang.h"

Location::Location()
{
	rooms.clear();
	accesses.clear();
}


//Accesses
bool Location::getAccess(std::string zugang_bez)
{
	bool zustand = accesses[zugang_bez].getZustand();
	return zustand;
}

bool Location::setAccess(std::string zugang_bez, bool lock)
{
	bool success = accesses[zugang_bez].setZustand(lock);
	return success;
}

void Location::addAccess(std::string zugang_bez)
{
	Zugang new_access;
	accesses[zugang_bez] = new_access;
	return;
}

void Location::delAccess(std::string zugang_bez)
{
	accesses.erase(zugang_bez);
	return;
}


//Rooms
float Location::getRoomTemp(std::string raum_bez)
{
	float temp = rooms[raum_bez].getTemp();
	return temp;
}

bool Location::setRoomTemp(std::string raum_bez, float temp)
{
	bool success = accesses[raum_bez].setZustand(temp);
	return success;
}

void Location::addRoom(std::string raum_bez)
{
	Raum new_room;
	new_room.setTemp(20.0);
	rooms[raum_bez] = new_room;	//Overwrite possible without notice!!!
	return;
}

void Location::delRoom(std::string raum_bez)
{
	rooms.erase(raum_bez);
	return;
}
