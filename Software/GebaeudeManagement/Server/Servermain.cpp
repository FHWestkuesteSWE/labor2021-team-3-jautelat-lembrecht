#include "BasicServer.h"
#include <string>
//#include "Zugang.h"

using namespace std;

int main(int argc, char* argv[]) {
	char port[] = "5000";
	BasicServer s;
//	s.start(argv[1]);
	s.start(port);
	return 0;
}