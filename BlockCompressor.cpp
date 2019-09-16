//
// Created by leobellaera on 13/9/19.
//

#include "BlockCompressor.h"
#include <cstring>
#include <arpa/inet.h>
#include <iostream>
#define DECOMPRESS_BYTES_INFO 5
#define UINT32_SIZE 4

BlockCompressor::BlockCompressor(int block_size) :
    samples_packer(block_size),
    size(block_size) {}

uint8_t* BlockCompressor::compressBlock(uint32_t* block) {
    uint32_t min = htonl(this->getBlockMin(block)); //min to Big Endian.
    this->subtractMinToBlock(block);

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

uint32_t BlockCompressor::getCompressedBlockSize(uint32_t* block) {
    uint32_t bits_per_block = this->samples_packer.getBitsPerSample(block) * this->size;
    while (bits_per_block % 8 != 0) {
        bits_per_block++;
    }
    return bits_per_block/8 + DECOMPRESS_BYTES_INFO;
}

uint32_t BlockCompressor::getBlockMin(uint32_t* block) {
    uint32_t min = block[0];
    for (int i = 0; i < this->size; i++) {
        if (block[i] < min) {
            min = block[i];
        }
    }
    return min;
}

void BlockCompressor::subtractMinToBlock(uint32_t* block) {
    uint32_t min = this->getBlockMin(block);
    for (int i = 0; i < this->size; i++) {
        block[i] = block[i] - min;
    }
}

BlockCompressor::~BlockCompressor() {

}
