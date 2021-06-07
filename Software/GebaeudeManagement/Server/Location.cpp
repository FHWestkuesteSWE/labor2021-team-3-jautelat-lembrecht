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
bool Location::readAccess(std::string zugang_bez)
{
	bool zustand = accesses[zugang_bez].getZustand();
	return zustand;
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
void Location::addRoom(std::string raum_bez)
{
	Raum new_room;
	new_room.avg_temp = 0.0;
	rooms[raum_bez] = new_room;
	return;
}

void Location::delRoom(std::string raum_bez)
{
	rooms.erase(raum_bez);
	return;
}
