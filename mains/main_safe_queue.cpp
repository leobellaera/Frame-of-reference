//
// Created by leobellaera on 19/9/19.
//

#include "BlockingQueue.h"
#include <iostream>
#include <stdint.h>
#include <vector>

int main() {
    std::vector<uint8_t> vector;
    vector.push_back(50);
    BlockingQueue q(9);
    q.push(vector);
    std::vector<uint8_t> top_elem = q.pop();
    std::cout << (unsigned)top_elem[0] << std::endl;
    return 0;
}

