//
// Created by leobellaera on 19/9/19.
//

#ifndef FRAME_OF_REFERENCE_SAFEQUEUE_H
#define FRAME_OF_REFERENCE_SAFEQUEUE_H

#include <queue>
#include <mutex>
#include <condition_variable>

#define SUCCESS 0
#define ERROR 1

class SafeQueue {
    private:
        std::queue<std::vector<uint8_t>> q;
        std::mutex m;
        std::condition_variable cond_var;
        size_t max_size;
    public:
        SafeQueue(size_t max_size);
        void push(std::vector<uint8_t> &elem);
        std::vector<uint8_t> pop();
        ~SafeQueue();
};

#endif //FRAME_OF_REFERENCE_SAFEQUEUE_H