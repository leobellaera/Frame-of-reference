//
// Created by leobellaera on 13/9/19.
//

#include "BlockCompressor.h"
#include <cstring>
#include <endian.h>
#include <iostream>
#define DECOMPRESS_BYTES_INFO 5
#define UINT32_SIZE 4

BlockCompressor::BlockCompressor(int block_size) :
    samples_packer(block_size),
    size(block_size) {}

uint8_t* BlockCompressor::compressBlock(Block &block) {
    uint32_t min = htobe32(block.getMin());
    block.subtractMin();

    uint8_t bits_per_sample = this->samples_packer.getBitsPerSample(block);
    uint32_t compressed_block_size = this->getCompressedBlockSize(block);
    uint8_t* compressed_block = new uint8_t[compressed_block_size]();

    std::memcpy(compressed_block, &min, UINT32_SIZE);
    compressed_block[4] = bits_per_sample;
    if (compressed_block_size != 0) {
        this->samples_packer.packSamples(block, &compressed_block[5]);
    }

    return compressed_block;
}

uint32_t BlockCompressor::getCompressedBlockSize(Block& block) {
    uint8_t bits_per_sample = samples_packer.getBitsPerSample(block);
    uint32_t bits_per_block = bits_per_sample * size;
    while (bits_per_block % 8 != 0) {
        bits_per_block++;
    }
    return bits_per_block/8 + DECOMPRESS_BYTES_INFO;
}

BlockCompressor::~BlockCompressor() {

}
