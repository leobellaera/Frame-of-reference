//
// Created by leobellaera on 20/9/19.
//

#include "BlockingQueue.h"
#include <vector>

#define QUEUE_CLOSED 1
#define SUCCESS 0

BlockingQueue::BlockingQueue(size_t max_size) :
    max_size(max_size),
    closed(false) {}

void BlockingQueue::push(std::vector<uint8_t> &elem) {
    std::unique_lock<std::mutex> lock(m);
    while (q.size() == max_size) {
        cond_var.wait(lock);
    }
    q.push(std::move(elem));
    cond_var.notify_all();
}

int BlockingQueue::pop(std::vector<uint8_t> &elem) {
    std::unique_lock<std::mutex> lock(m);
    while (q.empty() && !closed) {
        cond_var.wait(lock);
    }
    if (closed && q.empty()) {
        return QUEUE_CLOSED;
    }
    elem = std::move(q.front());
    q.pop();
    cond_var.notify_all();
    return SUCCESS;
}

void BlockingQueue::close() {
    std::unique_lock<std::mutex> lock(m);
    closed = true;
    cond_var.notify_all();
}

BlockingQueue::~BlockingQueue() {}
