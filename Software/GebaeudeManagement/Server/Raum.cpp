//Raum.cpp


#include <string>
#include <map>

#include "Raum.h"

bool Raum::setTemp(float value)
{
	avgtemp = value;
	return true;
}

float Raum::getTemp()
{
	avgtemp = temp1.getTemp();
	return avgtemp;
}

