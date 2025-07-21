#include "LoadBalancer.h"
#include <iostream>


LoadBalancer::LoadBalancer(int num_servers) : rr_indx(0) {
    for (int i = 0; i < num_servers; i++) {
        WebServer ws(i + 1);
        servers.push_back(ws);
    }
}


void LoadBalancer::distribute(const Request& req) {
    // Send to the current server in round-robin order
    servers[rr_indx].enqueue(req);
    std::cout << "Load Balancer sent req to server " << (rr_indx + 1) << std::endl;
    rr_indx++;
    if (rr_indx >= servers.size()) {
        rr_indx = 0;
    }
}


void LoadBalancer::run_cycle(int curr_cycle) {
    for (int i = 0; i < servers.size(); i++) {
        servers[i].try_process(curr_cycle);
    }

	// Find total queued requests across servers
	int total_reqs = queued_requests();
	int overload_thresh = servers.size() * 50;
	int underload_thresh = servers.size() * 10;
	
	// If overloaded - add server
	if (total_reqs > overload_thresh){
		std::cout << "Overlaoded, adding new server." << std::endl;
		int new_server_id = servers.size() + 1;
		servers.emplace_back(new_server_id);
	}
	
	// If underloaded - remove a server (as long as more than 1 server exists)
	else if (servers.size() > 1 && total_reqs < underload_thresh){
		WebServer& last_server = servers.back();

		// Check if queue is empty and not busy
		if (last_server.get_queue_length() == 0 && !last_server.is_busy(curr_cycle)){
			std::cout << "Underloaded, removing server "<< last_server.get_id() << std::endl;
			servers.pop_back();
		}
	}

}


int LoadBalancer::queued_requests() const {
    int total = 0;
    for (int i = 0; i < servers.size(); i++) {
        total += servers[i].get_queue_length();
    }
    return total;
}
