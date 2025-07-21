#pragma once
#include "WebServer.h"
#include <vector>

class LoadBalancer {

	private:
	std::vector<WebServer> servers;
	int rr_indx; // Round-robin index

	public:
	// Constructor
	LoadBalancer(int servers);

	// Distribute a request using round-robin
	void distribute(const Request& req);

	//  Run single cycle
	void run_cycle(int cycle);

	// Total pending requests across all servers
	int queued_requests() const;
};

