//
// Created by leobellaera on 20/9/19.
//

#include "SafeQueue.h"

SafeQueue::SafeQueue(size_t max_size) {
    this->max_size = max_size;
}

void SafeQueue::push(std::vector<uint8_t> &elem) {
    std::unique_lock<std::mutex> lock(m);
    while (q.size() == max_size) {
        cond_var.wait(lock);
    }
    q.push(elem);
    cond_var.notify_one();
}

std::vector<uint8_t> SafeQueue::pop(){
    std::unique_lock<std::mutex> lock(m);
    while(q.empty()) {
        cond_var.wait(lock);
    }
    std::vector<uint8_t> elem = std::move(q.front());
    q.pop();
    cond_var.notify_one();
    return elem;
}

SafeQueue::~SafeQueue() {}
