//Location.cpp


#include <string>
#include <map>

#include "Location.h"
#include "Raum.h"
#include "Zugang.h"



void Location::addRoom(std::string raum_bez)
{
	Raum new_room;
	new_room.avg_temp = 0.0;
	rooms[raum_bez] = new_room;
	return;
}

void Location::addAccess(std::string zugang_bez)
{
	Zugang new_access;
	accesses[zugang_bez] = new_access;
	return;
}