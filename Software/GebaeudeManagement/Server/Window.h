//Window.cpp

#ifndef WINDOW_H
#define WINDOW_H

#include <string>

class Window {
public:
	std::string window_bez;
	int zustand;
	void setWindow(int window_bez, int zustand);
	int getWindow(int window_bez);
};

#endif  // WINDOW_H
