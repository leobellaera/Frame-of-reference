//
// Created by leobellaera on 15/9/19.
//

#include "FrameOfReference.h"

FrameOfReference::FrameOfReference(int block_size, char* infile_path, char* outfile_path) :
    block_size(block_size),
    block_compressor(block_size),
    file_reader(infile_path),
    file_writer(outfile_path) {}

int FrameOfReference::compressFile() {

}