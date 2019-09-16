//
// Created by leobellaera on 13/9/19.
//

#ifndef TP2_BLOCKCOMPRESSOR_H
#define TP2_BLOCKCOMPRESSOR_H

#include <stdint.h>
#include "SamplesPacker.h"


class BlockCompressor {
    private:
        SamplesPacker samples_packer;
        int size;
        uint32_t getBlockMin(uint32_t* block);
        void subtractMinToBlock(uint32_t* block);
    public:
        BlockCompressor(int block_size);
        uint8_t* compressBlock(uint32_t* block);
        uint32_t getCompressedBlockSize(uint32_t* block);

        ~BlockCompressor();
};


#endif //TP2_BLOCKCOMPRESSOR_H
