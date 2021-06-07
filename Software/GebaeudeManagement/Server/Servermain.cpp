#include "BasicServer.h"
#include "LocationServer.h"
#include "Zugang.h"


int main(int argc, char* argv[]) {
	Zugang Tuer0001;
	char port[] = "5000";
	LocationServer s;
//	s.start(argv[1]);
	s.start(port);
	return 0;
}