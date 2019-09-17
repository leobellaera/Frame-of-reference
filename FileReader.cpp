//
// Created by leobellaera on 12/9/19.
//

#include "FileReader.h"
#include <endian.h>

#define UINT32_SIZE 4
#define SUCCESS 0
#define ERROR 1
#define EOF_REACHED 2

FileReader::FileReader(char* path) :
    stream() {
    if (path != "-") {
        read_from_stdin = false;
        stream.open(path);
    } else {
        read_from_stdin = true;
    }
}

int FileReader::readBlock(std::vector<uint32_t> &destin) {
    if (read_from_stdin) {
        return this->read(std::cin, destin);
    } else {
        return this->read(this->stream, destin);
    }
}

int FileReader::read_wrapper(std::istream& stream, std::vector<uint32_t> &destin){
    uint32_t numb;
    for (int i = 0; i < block_size; i++) {
        if (stream.get(&numb, UINT32_SIZE)) {
            numb = be32toh(numb);
            destin.push_back(numb);
        } else {
            break;
        }
    }
    if (stream.eof()) {
        return EOF_REACHED;
    } else if(stream.fail()) {
        return ERROR;
    }
    return SUCCESS;
}

FileReader::~FileReader() {
    if (stream.is_open()) {
        stream.close();
    }
}
