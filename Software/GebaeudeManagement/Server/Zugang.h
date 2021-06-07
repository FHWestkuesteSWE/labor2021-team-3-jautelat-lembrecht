//
//
//Zugang.h

#ifndef ZUGANG_H
#define ZUGANG_H

#include <string> //error without

class Zugang {
public:
	bool lock();
	bool unlock();
	bool getZustand();
private:
	bool zustand;
};

#endif  // ZUGANG_H
