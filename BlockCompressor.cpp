//
// Created by leobellaera on 13/9/19.
//

#include "BlockCompressor.h"
#include <stdint.h>
#include <cstring>
#include <endian.h>

#define UINT32_SIZE 4

BlockCompressor::BlockCompressor(int block_size) :
    samples_packer(block_size),
    size(block_size) {}

void BlockCompressor::compressBlock(Block &block, std::vector<uint8_t> &compressed_block) {
    uint32_t min = htobe32(block.getMin());
    block.subtractMin();
    uint8_t bits_per_sample = samples_packer.getBitsPerSample(block);

    std::memcpy(compressed_block.data(), &min, UINT32_SIZE);
    compressed_block.push_back(bits_per_sample);

    if (bits_per_sample != 0) {
        this->samples_packer.packSamples(block, compressed_block);
    }
}

BlockCompressor::~BlockCompressor() {

}
