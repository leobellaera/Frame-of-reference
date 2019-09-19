//
// Created by leobellaera on 12/9/19.
//

#include "FileReader.h"
#include <string.h>
#include <cstring>
#include <endian.h>

#define UINT32_SIZE 4
#define SUCCESS 0
#define ERROR 1
#define EOF_REACHED 2

#include <iostream> //SACAR ESTO

FileReader::FileReader(char* path, int block_size) :
    stream(path, std::ios::binary), //despues sacar esto
    block_size(block_size) {
    /*if (strcmp(path, "-")  != 0) {
        read_from_stdin = false;
        stream.open(path, std::ifstream::binary); //No se si esto sirve (binary)
    } else {
        read_from_stdin = true;
    }*/
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
    char buf[UINT32_SIZE+1];
    uint32_t numb;
    stream.get(buf, UINT32_SIZE+1);
    if (stream.fail()) {
        return ERROR;
    } else {
        std::memcpy(&numb, buf, UINT32_SIZE);
        numb = be32toh(numb);
        destin.push_back(numb);
        return stream.good() ? SUCCESS : EOF_REACHED;
    }
}

FileReader::~FileReader() {
    if (stream.is_open()) {
        stream.close();
    }
}
