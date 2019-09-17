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
    //file_writer(outfile_path)
    block_size(block_size),
    file_reader(infile_path, block_size),
    output(outfile_path),
    block_compressor(block_size) {}

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
    /*HARCODEO*/
    uint32_t compressed_block_size = block_compressor.getCompressedBlockSize(block);
    char* compression = (char*)block_compressor.compressBlock(block);
    output.write((char*)compression, compressed_block_size);
    /*HARCODEO*/
    return state;
}

FrameOfReference::~FrameOfReference() {
    output.close(); //HARCODEO
}




