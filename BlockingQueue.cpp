//
// Created by leobellaera on 20/9/19.
//

#include "BlockingQueue.h"

#include <thread>
#include <chrono>

BlockingQueue::BlockingQueue(size_t max_size) {
    this->max_size = max_size;
    closed = false;
}

void BlockingQueue::push(std::vector<uint8_t> &elem) {
    std::unique_lock<std::mutex> lock(m);
    while (q.size() == max_size) {
        cond_var.wait(lock);
    }
    q.push(std::move(elem));
    cond_var.notify_one();
}

int BlockingQueue::pop(std::vector<uint8_t> &elem) {
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    std::unique_lock<std::mutex> lock(m);
    if (q.empty() && closed) {
        return 1;
    }
    while(q.empty()) {
        cond_var.wait(lock);
    }
    elem = std::move(q.front());
    q.pop();
    cond_var.notify_one();
    return 0;
}

void BlockingQueue::close() {
    //std::unique_lock<std::mutex> lock(m);
    closed = true;
}

BlockingQueue::~BlockingQueue() {}
