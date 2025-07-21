#include "Request.h"
#include "WebServer.h"
#include "LoadBalancer.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
	// seeding
	srand(time(0)); 
	
	// Testing Request
	Request r0;
	cout << "Request IP in " << r0.ip_in << endl;
	cout << "Request IP out " << r0.ip_out << endl;
	cout << "Processing time " << r0.proc_time << endl;

	// Testing LoadBalancer
	LoadBalancer lb(3);
	const int cycles = 20;

	for (int c  = 1; c <= cycles; c++){
		cout << "Cycle " << c << endl;
		
		// Generate a new req every 3 cycles
		if(c%3 == 1){
			Request r;
			lb.distribute(r);
		}
	lb.run_cycle(c);
	cout << "Total pending requests: " << lb.queued_requests() << endl;
	}


	return 0;
}
