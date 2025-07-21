#pragma once
#include "WebServer.h"
#include <vector>

/**
 * @class LoadBalancer
 * @brief Manages and distributes requests to multiple web servers.
 */
class LoadBalancer {

private:
    /// Collection of web servers.
    std::vector<WebServer> servers;

    /// Index for round-robin distribution.
    int rr_indx;

public:
    /**
     * @brief Constructs a LoadBalancer with the given number of servers.
     * @param servers Number of initial web servers.
     */
    LoadBalancer(int servers);

    /**
     * @brief Distributes a request to a web server using round-robin policy.
     * @param req The request to distribute.
     */
    void distribute(const Request& req);

    /**
     * @brief Runs a single cycle of load balancing and server processing.
     * @param cycle The current cycle number.
     */
    void run_cycle(int cycle);

    /**
     * @brief Computes the total number of queued requests across all servers.
     * @return Total queued requests.
     */
    int queued_requests() const;
};
