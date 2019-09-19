//
// Created by leobellaera on 13/9/19.
//

#ifndef FRAME_OF_REFERENCE_BLOCKCOMPRESSOR_H
#define FRAME_OF_REFERENCE_BLOCKCOMPRESSOR_H

#include "Block.h"
#include <vector>
#include "SamplesPacker.h"


class BlockCompressor {
    private:
        SamplesPacker samples_packer;
        int size;
    public:
        BlockCompressor(int block_size);
        std::vector<uint8_t> compressBlock(Block &block);
        ~BlockCompressor();
};

#endif //FRAME_OF_REFERENCE_BLOCKCOMPRESSOR_H
