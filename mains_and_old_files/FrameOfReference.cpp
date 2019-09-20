//
// Created by leobellaera on 15/9/19.
//

#include "FrameOfReference.h"
#include <stdint.h>
#include <vector>

#include <iostream> //HARCODEO
#include <fstream> //HARCODEO

#define SUCCESS 0
#define EOF_REACHED 1
#define REFERENCE_SIZE 4

FrameOfReference::FrameOfReference(int block_size, char* infile_path, char* outfile_path) :
    //file_writer(outfile_path)
    block_size(block_size),
    file_reader(infile_path, block_size),
    output(outfile_path, std::ofstream::binary),
    block_compressor(block_size) {}

int FrameOfReference::compressFile() {
    while (1) {
        if(this->compressBlock() == EOF_REACHED) {
            return SUCCESS;
        }
    }
}

int FrameOfReference::compressBlock() {
    std::vector<uint32_t> numbs;
    int state = file_reader.readBlock(numbs);
    Block block(numbs, block_size);
    std::vector<uint8_t> compression(REFERENCE_SIZE);
    block_compressor.compressBlock(block, compression);
    output.write((char*)compression.data(), compression.size());
    return state;
}

FrameOfReference::~FrameOfReference() {}




