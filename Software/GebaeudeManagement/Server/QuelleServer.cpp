#include "BasicServer.h"

int main(int argc, char* argv[]) { 
	BasicServer s;
	s.start(argv[1]);
	return 0; 
}