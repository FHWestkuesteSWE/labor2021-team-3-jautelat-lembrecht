//Heizung.h

#ifndef HEIZUNG_H
#define HEIZUNG_H


class Heizung {
public:
	float sollwert;
	//std::string heizung_bez;
	void setTemp(int heizung_bez, int sollwert);
};

#endif  //HEIZUNG_H
