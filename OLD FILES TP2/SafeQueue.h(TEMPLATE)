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

template<class T>
class SafeQueue {
    private:
        std::queue<T> q;
        std::mutex m;
        std::condition_variable cond_var;
        size_t max_size;
    public:
        SafeQueue(size_t max_size) {
            this->max_size = max_size;
        }

        void push(T elem) {
            std::unique_lock<std::mutex> lock(m);
            while (q.size() == max_size) {
                cond_var.wait(lock);
            }
            q.push(elem);
            cond_var.notify_one();
        }

        T pop(){
            std::unique_lock<std::mutex> lock(m);
            while(q.empty()) {
                cond_var.wait(lock);
            }
            T elem = q.front();
            q.pop();
            cond_var.notify_one();
            return elem;
        }

        ~SafeQueue() {}
};

#endif //FRAME_OF_REFERENCE_SAFEQUEUE_H
