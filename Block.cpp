//
// Created by leobellaera on 16/9/19.
//

#define SUCCESS 0
#define ERROR 1

#include "Block.h"

Block::Block(uint32_t* numbs, int size) {
    this->size = size;
    numbers = new uint32_t[size]();
    for (int i = 0; i < size; i++) {
        numbers[i] = numbs[i];
    }
}

uint32_t Block::getNumber(int position) {
    return numbers[position];
}

void Block::subtractMin() {
    uint32_t min = this->getMin();
    for (int i = 0; i < size; i++) {
        numbers[i] -= min;
    }
}

uint32_t Block::getMin() {
    uint32_t min = numbers[0];
    for (int i = 0; i < size; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }
    return min;
}

uint32_t Block::getMax() {
    uint32_t max = numbers[0];
    for (int i = 0; i < size; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    return max;
}

Block::~Block() {
    delete[] numbers;
}
