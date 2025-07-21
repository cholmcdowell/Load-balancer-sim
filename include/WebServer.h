#pragma once
#include "Request.h"
#include <queue>

class WebServer {

public:
    int server_id;
    int available_at;  // cycle count when server is free again
    std::queue<Request> queue;
    WebServer(int id = 0);
    void enqueue(const Request& req);
    void try_process(int current_cycle);
    bool is_available(int current_cycle) const;
    int get_queue_length() const;
	int get_id() const;         
	bool is_busy(int curr_cycle) const;

};

