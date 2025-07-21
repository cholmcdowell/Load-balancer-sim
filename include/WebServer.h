#pragma once
#include "Request.h"
#include <queue>

/**
 * @class WebServer
 * @brief Represents a single web server that processes incoming requests.
 */
class WebServer {

public:
    /// Unique identifier for the server.
    int server_id;

    /// Cycle when the server becomes available.
    int available_at;

    /// Queue of incoming requests.
    std::queue<Request> queue;

    /**
     * @brief Constructs a WebServer with the given ID.
     * @param id Server ID (default is 0).
     */
    WebServer(int id = 0);

    /**
     * @brief Adds a request to the server's queue.
     * @param req The request to enqueue.
     */
    void enqueue(const Request& req);

    /**
     * @brief Attempts to process a request if the server is available.
     * @param current_cycle The current cycle.
     */
    void try_process(int current_cycle);

    /**
     * @brief Checks if the server is available in the given cycle.
     * @param current_cycle The current cycle.
     * @return True if the server is available, false otherwise.
     */
    bool is_available(int current_cycle) const;

    /**
     * @brief Returns the number of queued requests.
     * @return Queue size.
     */
    int get_queue_length() const;

    /**
     * @brief Returns the server's unique identifier.
     * @return Server ID.
     */
    int get_id() const;

    /**
     * @brief Checks if the server is currently processing a request.
     * @param curr_cycle Current cycle.
     * @return True if the server is busy, false otherwise.
     */
    bool is_busy(int curr_cycle) const;
};
