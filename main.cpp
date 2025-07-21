#include "Request.h"
#include "WebServer.h"
#include "LoadBalancer.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

/**
 * @brief Entry point of the load balancer simulation.
 * 
 * Prompts the user to enter the number of servers and number of cycles to run.
 * Initializes the LoadBalancer, pre-fills the request queue, and simulates cycles.
 * 
 * @return int Exit status code.
 */
int main() {
    // Seed random number generator with current time
    srand(time(0));

    int num_servers;
    int cycles;

    cout << "Enter number of web servers: ";
    cin >> num_servers;

    cout << "Enter number of clock cycles to run: ";
    cin >> cycles;

    // Create LoadBalancer with specified number of servers
    LoadBalancer lb(num_servers);

    // Fill initial queue with servers * 100 requests
    for (int i = 0; i < num_servers * 100; ++i) {
        Request r;
        lb.distribute(r);
    }

    // Run simulation for specified number of cycles
    for (int c = 1; c <= cycles; ++c) {
        cout << "Cycle " << c << endl;

        // Occasionally add new requests to simulate traffic (~20% chance)
        if (rand() % 5 == 0) {
            Request r;
            lb.distribute(r);
        }

        lb.run_cycle(c);

        cout << "Total pending requests: " << lb.queued_requests() << endl;
    }

    return 0;
}
