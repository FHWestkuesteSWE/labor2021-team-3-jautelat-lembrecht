#include "BasicClient.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	BasicClient c(argv[1], argv[2]);
	char req[1024] = "Hallo !";
	char ans[1024];
	c.sendRequest(req, ans);
	cout << ans << endl;
	return 0;
}
