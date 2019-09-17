//
// Created by leobellaera on 16/9/19.
//

#ifndef FRAME_OF_REFERENCE_BLOCK_H
#define FRAME_OF_REFERENCE_BLOCK_H

#include <stdint.h>

class Block {
    private:
        int size;
        uint32_t* numbers;
    public:
        Block(uint32_t* numbs, int size);
        void subtractMin();
        uint32_t getNumber(int position);
        uint32_t getMax();
        uint32_t getMin();
        ~Block();
};

#endif //FRAME_OF_REFERENCE_BLOCK_H
