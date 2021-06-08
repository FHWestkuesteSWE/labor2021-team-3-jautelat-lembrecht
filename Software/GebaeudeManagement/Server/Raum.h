//Raum.h

#ifndef RAUM_H
#define RAUM_H

#include "Temperatursensor.h"

class Raum {
public:
	float avgtemp = 0.0;
	Temperatursensor temp1;
	bool setTemp(float value);
	float getTemp();

};

#endif  // RAUM_H
