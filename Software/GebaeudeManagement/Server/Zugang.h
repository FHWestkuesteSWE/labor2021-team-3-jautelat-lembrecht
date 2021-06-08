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
	bool setZustand(bool lock);
private:
	bool zustand;
};

#endif  // ZUGANG_H
