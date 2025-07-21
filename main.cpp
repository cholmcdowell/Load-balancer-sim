#include "include/Request.h"
#include <iostream>
#include <ctime>

using namespace std;

int main() {
	// seeding
	srand(time(0)); 
	
	// Testing Request
	Request r0;
	cout << "Request IP in " << r0.ip_in << endl;
	cout << "Request IP out " << r0.ip_out << endl;
	cout << "Processing time " << r0.proc_time << endl;

	return 0;
}
