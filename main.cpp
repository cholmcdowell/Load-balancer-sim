#include "Request.h"
#include "WebServer.h"
#include "LoadBalancer.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {

    srand(time(0));
    int num_servers;
    int cycles;

    cout << "Enter number of web servers: ";
    cin >> num_servers;

    cout << "Enter number of clock cycles to run: ";
    cin >> cycles;

    LoadBalancer lb(num_servers);

    // Fill initial queue: servers * 100 requests
    for (int i = 0; i < num_servers * 100; ++i) {
        Request r;
        lb.distribute(r); // preload request queue
    }

    for (int c = 1; c <= cycles; ++c) {
        cout << "Cycle " << c << endl;

        // Add random requests (simulate traffic)
        if (rand() % 5 == 0) {  // ~20% chance
            Request r;
            lb.distribute(r);
        }

        lb.run_cycle(c);
        cout << "Total pending requests: " << lb.queued_requests() << endl;
    }

    return 0;
}

