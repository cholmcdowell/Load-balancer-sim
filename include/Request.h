#pragma once
#include <string>

/**
 * @struct Request
 * @brief Represents a web request with input/output IPs and processing time.
 */
struct Request {
    /// Input IP address.
    std::string ip_in;

    /// Output IP address.
    std::string ip_out;

    /// Processing time required (in cycles).
    int proc_time;

    /**
     * @brief Default constructor.
     */
    Request();

    /**
     * @brief Parameterized constructor.
     * @param ip_in Source IP address.
     * @param ip_out Destination IP address.
     * @param proc_time Processing time in cycles.
     */
    Request(const std::string& ip_in, const std::string& ip_out, int proc_time);
};

/**
 * @brief Generates a random IP address in string format.
 * @return A randomly generated IP address.
 */
std::string rand_ip();
