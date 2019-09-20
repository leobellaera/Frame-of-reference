//
// Created by leobellaera on 19/9/19.
//

#include "SafeQueue.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vector;
    vector.push_back(50);
    SafeQueue<std::vector<int>*> q(9);
    q.push(&vector);
    std::vector<int>* top_elem = q.pop();
    std::cout << (*top_elem)[0] << std::endl;
    return 0;
}

