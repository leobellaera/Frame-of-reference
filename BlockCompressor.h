//
// Created by leobellaera on 13/9/19.
//

#ifndef FRAME_OF_REFERENCE_BLOCKCOMPRESSOR_H
#define FRAME_OF_REFERENCE_BLOCKCOMPRESSOR_H

#include <stdint.h>
#include "Block.h"
#include "SamplesPacker.h"


class BlockCompressor {
    private:
        SamplesPacker samples_packer;
        int size;
    public:
        BlockCompressor(int block_size);
        uint8_t* compressBlock(Block &block);
        uint32_t getCompressedBlockSize(Block& block);

        ~BlockCompressor();
};

#endif //FRAME_OF_REFERENCE_BLOCKCOMPRESSOR_H
