//
// Created by leobellaera on 15/9/19.
//

#include "FrameOfReference.h"
#include <stdint.h>
#include <vector>

#include <iostream> //HARCODEO
#include <fstream> //HARCODEO

#define NO_BLOCK_TO_READ -1
#define REFERENCE_SIZE 4

FrameOfReference::FrameOfReference(int block_size, char* infile_path, char* outfile_path) :
        block_size(block_size),
        file_reader(infile_path, block_size),
        output(outfile_path, std::ofstream::binary),
        block_compressor(block_size) {}

void FrameOfReference::compressFile() {
    int i = 0;
    while (1) {
        int state = this->compressBlock(i);
        if (state == NO_BLOCK_TO_READ) {
            return;
        }
        i++;
    }
}

int FrameOfReference::compressBlock(int block_to_read) {
    std::vector<uint32_t> numbs;
    int state = file_reader.readBlock(numbs, block_to_read);
    if (state == NO_BLOCK_TO_READ) {
        return NO_BLOCK_TO_READ;
    }
    Block block(numbs, block_size);
    std::vector<uint8_t> compression(REFERENCE_SIZE);
    block_compressor.compressBlock(block, compression);
    output.write((char*)compression.data(), compression.size());
    return state;
}

FrameOfReference::~FrameOfReference() {}
