#include "WebServer.h"

/**
 * @brief Constructs a WebServer with the given ID.
 * @param server_id Unique server identifier.
 */
WebServer::WebServer(int server_id) : server_id(server_id), available_at(0) {}

/**
 * @brief Adds a request to the server's queue.
 * @param req The request to enqueue.
 */
void WebServer::enqueue(const Request& req) {
    queue.push(req);
}

/**
 * @brief Attempts to process the next request if the server is available.
 * @param current_cycle The current simulation cycle.
 */
void WebServer::try_process(int current_cycle) {
    if (!queue.empty() && is_available(current_cycle)) {
        Request req = queue.front();
        queue.pop();
        available_at = current_cycle + req.proc_time;
    }
}

/**
 * @brief Checks if the server is available for processing at the given cycle.
 * @param current_cycle The current simulation cycle.
 * @return True if the server is available, false otherwise.
 */
bool WebServer::is_available(int current_cycle) const {
    return current_cycle >= available_at;
}

/**
 * @brief Returns the number of requests waiting in the queue.
 * @return Number of queued requests.
 */
int WebServer::get_queue_length() const {
    return queue.size();
}

/**
 * @brief Returns the server's unique ID.
 * @return Server ID.
 */
int WebServer::get_id() const {
    return server_id;
}

/**
 * @brief Checks if the server is currently busy processing a request.
 * @param current_cycle The current simulation cycle.
 * @return True if the server is busy, false otherwise.
 */
bool WebServer::is_busy(int current_cycle) const {
    return current_cycle < available_at;
}
