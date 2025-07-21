#include "Request.h"
#include <sstream>
#include <cstdlib> 

/**
 * @brief Generates a random IPv4 address as a string.
 * @return Randomly generated IP address in dot-decimal notation.
 */
std::string rand_ip() {
    std::ostringstream oss;
    for (int i = 0; i < 4; i++) {
        oss << (rand() % 256); // Each octet ranges from 0 to 255
        if (i < 3) {
            oss << ".";
        }
    }
    return oss.str();
}

/**
 * @brief Default constructor that initializes the Request with random IPs and processing time.
 */
Request::Request() {
    ip_in = rand_ip();
    ip_out = rand_ip();
    proc_time = rand() % 100 + 1;  // Random processing time between 1 and 100 cycles
}

/**
 * @brief Parameterized constructor to create a Request with specific IPs and processing time.
 * @param ip_in Source IP address.
 * @param ip_out Destination IP address.
 * @param proc_time Processing time in clock cycles.
 */
Request::Request(const std::string& ip_in, const std::string& ip_out, int proc_time)
    : ip_in(ip_in), ip_out(ip_out), proc_time(proc_time) {}
