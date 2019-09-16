//
// Created by leobellaera on 13/9/19.
//


#ifndef TP2_SAMPLESPACKER_H
#define TP2_SAMPLESPACKER_H

#include <stdint.h>
#include <string>

class SamplesPacker {
    private:
        int size;
        uint8_t convertBinaryByteToNumb(const char* binary);
        void getSamplesPackedAsString(uint32_t* block, std::string &str);
    public:
        SamplesPacker(int block_size);
        uint8_t getBitsPerSample(uint32_t* block);
        void packSamples(uint32_t* block, uint8_t* buf);
        ~SamplesPacker();
};

#endif //TP2_SAMPLESPACKER_H
