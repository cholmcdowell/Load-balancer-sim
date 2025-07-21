#include "WebServer.h"


WebServer::WebServer(int server_id) : server_id(server_id), available_at(0) {}


void WebServer::enqueue(const Request& req) {
    queue.push(req);
}

void WebServer::try_process(int current_cycle) {
    if (!queue.empty() && is_available(current_cycle)) {
        Request req = queue.front();
        queue.pop();
        available_at = current_cycle + req.proc_time;
    }
}


bool WebServer::is_available(int current_cycle) const {
    return current_cycle >= available_at;
}

int WebServer::get_queue_length() const {
    return queue.size();
}

int WebServer::get_id() const {
    return server_id;
}


bool WebServer::is_busy(int current_cycle) const {
    // Server is busy if current cycle is before available_at time
    return current_cycle < available_at;
}

