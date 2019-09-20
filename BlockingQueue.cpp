//
// Created by leobellaera on 20/9/19.
//

#include "BlockingQueue.h"

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

std::vector<uint8_t> BlockingQueue::pop(){
    std::unique_lock<std::mutex> lock(m);
    while(q.empty()) {
        cond_var.wait(lock);
    }
    std::vector<uint8_t> elem = std::move(q.front());
    q.pop();
    cond_var.notify_one();
    return std::move(elem);
}

bool BlockingQueue::is_closed() {
    return (closed && q.empty());
}

void BlockingQueue::close() {
    closed = true;
}

BlockingQueue::~BlockingQueue() {}
