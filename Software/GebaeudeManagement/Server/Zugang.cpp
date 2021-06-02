//Zugang.cpp


#include "Zugang.h"
#include <string>

bool Zugang::lock(std::string zugang_bez) {
	zustand = true;
	//Fehlerprüfung immer true
	return true;
}

bool Zugang::unlock(std::string zugang_bez) {
	zustand = false;
	return true;
}

bool Zugang::getZustand(std::string zugang_bez) {
	return zustand;
}

