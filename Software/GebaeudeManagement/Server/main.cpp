#pragma once
#include "Server.h"
#include <string>
#include "Zugang.cpp"

using namespace std;

int main(int argc, char* argv[]) {
	Server s;
	s.start(argv[1]);
	return 0;
}