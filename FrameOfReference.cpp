//
// Created by leobellaera on 15/9/19.
//

#include "FrameOfReference.h"
#define ERROR 1
#define SUCCESS 0

FrameOfReference::FrameOfReference(int block_size, char* infile_path, char* outfile_path) :
    block_size(block_size),
    block_compressor(block_size),
    file_reader(infile_path, block_size),
    //file_writer(outfile_path) {}

int FrameOfReference::compressFile() {
    uint32_t block[4];
    while (this->compressBlock()) {
        //continue
    }
    /*int this->file_reader.readBlock(block);
    while (this->file_reader.readBlock(block) != ERROR) {
        if
        //write file
    }*/
}