//
//
//Zugang.h

#ifndef ZUGANG_H
#define ZUGANG_H

#include <string> //error without

class Zugang {
public:
	bool zustand;
	std::string zugang_bez;
	bool lock(std::string zugang_bez);
	bool unlock(std::string zugang_bez);
	bool getZustand(std::string zugang_bez);
};

#endif  // ZUGANG_H
