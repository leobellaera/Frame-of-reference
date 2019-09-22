//
// Created by leobellaera on 19/9/19.
//

#ifndef FRAME_OF_REFERENCE_BLOCKINGQUEUE_H
#define FRAME_OF_REFERENCE_BLOCKINGQUEUE_H

#include <queue>
#include <vector>
#include <stdint.h>
#include <mutex>
#include <condition_variable>

class BlockingQueue {
    private:
        std::queue<std::vector<uint8_t>> q;
        std::mutex m;
        std::condition_variable cond_var;
        size_t max_size;
        bool closed;
    public:
        explicit BlockingQueue(size_t max_size);
        void push(std::vector<uint8_t> &elem);
        int pop(std::vector<uint8_t> &elem);
        void close();
        ~BlockingQueue();
};

#endif //FRAME_OF_REFERENCE_BLOCKINGQUEUE_H
