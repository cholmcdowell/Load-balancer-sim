#pragma once
#include <string>

using namespace std;

struct Request{
string ip_in;
string ip_out;
int proc_time; // Processing time in cycles

// Default Constructor
Request();
// Parameterized Constructor 
Request(const string& ip_in, const string& ip_out, int proc_time);

// Random IP generator
string rand_ip();
};
