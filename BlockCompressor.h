//
// Created by leobellaera on 13/9/19.
//

#ifndef FRAME_OF_REFERENCE_BLOCKCOMPRESSOR_H
#define FRAME_OF_REFERENCE_BLOCKCOMPRESSOR_H

#include "Block.h"
#include <vector>
#include <stdint.h>
#include "SamplesPacker.h"


class BlockCompressor {
    private:
        SamplesPacker samples_packer;
        int size;
    public:
        explicit BlockCompressor(int block_size);
        void compressBlock(Block &block,
                std::vector<uint8_t> &compressed_block);
        ~BlockCompressor();
};

#endif
