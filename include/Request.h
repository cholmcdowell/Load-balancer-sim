#pragma once
#include <string>

struct Request{
	std::string ip_in;
	std::string ip_out;
	int proc_time; // Processing time in cycles

	// Default Constructor
	Request();
	// Parameterized Constructor 
	Request(const std::string& ip_in, const std::string& ip_out, int proc_time);
};

// Random IP generator
std::string rand_ip();
