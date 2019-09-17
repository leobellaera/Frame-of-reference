//
// Created by leobellaera on 13/9/19.
//


#ifndef TP2_SAMPLESPACKER_H
#define TP2_SAMPLESPACKER_H

#include <stdint.h>
#include <string>
#include "Block.h"

class SamplesPacker {
    private:
        int size;
        uint8_t convertBinaryByteToNumb(const char* binary);
        void getSamplesPackedAsString(Block& block, std::string &str);
    public:
        SamplesPacker(int block_size);
        uint8_t getBitsPerSample(Block& block);
        void packSamples(Block& block, uint8_t* buf);
        ~SamplesPacker();
};

#endif //TP2_SAMPLESPACKER_H
