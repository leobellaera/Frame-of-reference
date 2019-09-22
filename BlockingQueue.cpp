//
// Created by leobellaera on 20/9/19.
//

#include "BlockingQueue.h"

#include <chrono>
#include <thread>

BlockingQueue::BlockingQueue(size_t max_size) :
    max_size(max_size) {}

void BlockingQueue::push(std::vector<uint8_t> &elem) {
    std::unique_lock<std::mutex> lock(m);
    while (q.size() == max_size) {
        cond_var.wait(lock);
    }
    q.push(std::move(elem));
    cond_var.notify_all();
}

std::vector<uint8_t> BlockingQueue::pop() {
    //std::this_thread::sleep_for(std::chrono::milliseconds(1));
    std::unique_lock<std::mutex> lock(m);
    while (q.empty()) {
        cond_var.wait(lock);
    }
    std::vector<uint8_t> elem = std::move(q.front());
    q.pop();
    cond_var.notify_all();
    return std::move(elem);
}

bool BlockingQueue::empty() {
    return q.empty();
}

BlockingQueue::~BlockingQueue() {}
