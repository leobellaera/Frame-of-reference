//
// Created by leobellaera on 12/9/19.
//

#include "FileReader.h"
#include <string.h>
#include <iostream>
#include <cstring>
#include <endian.h>

#define UINT32_SIZE 4
#define SUCCESS 0
#define ERROR 1
#define EOF_REACHED 2

FileReader::FileReader(char* path, int block_size) :
    block_size(block_size) {
    if (strcmp(path, "-")  != 0) {
        stdin_reading = false;
        stream.open(path, std::ifstream::binary);
    } else {
        stdin_reading = true;
    }
}

int FileReader::readBlock(std::vector<uint32_t> &destin) {
    int state = SUCCESS;
    int i = 0;
    while (i < block_size && state == SUCCESS) {
        state = this->readSample(destin);
        i++;
    }
    return state;
}

int FileReader::readSample(std::vector<uint32_t> &destin){
    std::istream& input = stdin_reading ? std::cin : stream;
    char buf[UINT32_SIZE+1];
    uint32_t numb;
    input.get(buf, UINT32_SIZE+1);
    if (input.fail()) {
        return ERROR;
    } else {
        std::memcpy(&numb, buf, UINT32_SIZE);
        numb = be32toh(numb);
        destin.push_back(numb);
        return input.eof() ? EOF_REACHED : SUCCESS;
    }
}

FileReader::~FileReader() {
    if (stream.is_open()) {
        stream.close();
    }
}
