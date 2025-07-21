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
}


int LoadBalancer::queued_requests() const {
    int total = 0;
    for (int i = 0; i < servers.size(); i++) {
        total += servers[i].get_queue_length();
    }
    return total;
}
