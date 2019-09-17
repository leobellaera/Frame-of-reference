//
// Created by leobellaera on 15/9/19.
//

#include "FrameOfReference.h"
#include <stdint.h>
#include <vector>

#include <iostream> //HARCODEO
#include <fstream> //HARCODEO

#define SUCCESS 0
#define ERROR 1
#define EOF_REACHED 2

FrameOfReference::FrameOfReference(int block_size, char* infile_path, char* outfile_path) :
    block_size(block_size),
    block_compressor(block_size),
    file_reader(infile_path, block_size),
    outfile(outfile_path) {} //HARCODEO!!!!!!!!!!!!
    //file_writer(outfile_path) {}

int FrameOfReference::compressFile() {
    int state = SUCCESS;
    while (state == SUCCESS) {
        state = this->compressBlock();
    }
    return (state == ERROR);
}

int FrameOfReference::compressBlock() {
    std::vector<uint32_t> numbs;
    int state = file_reader.readBlock(numbs);
    if (state == ERROR) {
        return ERROR;
    }
    Block block(numbs, block_size);
    uint32_t compressed_block_size = block_compressor.getCompressedBlockSize(block);
    uint8_t* compression = block_compressor.compressBlock(block);
    ofstream myfile;
    myfile.open(outfile);
    return state;
}




