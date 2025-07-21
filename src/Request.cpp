#include "Request.h"
#include <sstream>
#include <cstdlib> 

// Random IP address
string rand_ip() {
	ostringstream oss;
	for (int i = 0; i < 4; i++){
		oss  << (rand() % 256); // at 256 because we are using IPv4 address
		if (i < 3){
			oss << ".";
		}
	}
	return oss.str();
}

// Default Constructor
Request::Request() {
	ip_in = rand_ip();
	ip_out = rand_ip();
	proc_time = rand % 100 + 1;
}

// Param Constructor
Request::Request(const string ip_in, const string ip_out, int proc_time)
	: ip_in(ip_in), ip_out(ip_out), proc_time(proc_time) {}
