//Zugang.cpp


#include "Zugang.h"
#include <string>

bool Zugang::lock() {
	zustand = true;
	//Fehlerpr�fung immer true
	return true;
}

bool Zugang::unlock() {
	zustand = false;
	return true;
}

bool Zugang::getZustand() {
	return zustand;
}

