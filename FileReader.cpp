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
#define EOF_REACHED 1
#define NO_BLOCK_TO_READ -1


#include <thread>
int h = 0;

FileReader::FileReader(char* path, int block_size) :
    block_size(block_size) {
    if (strcmp(path, "-")  != 0) {
        read_from_stdin = false;
        stream.open(path, std::ifstream::binary);
    } else {
        read_from_stdin = true;
    }
    std::cout<<"BLOCK SIZE IS "<<block_size<<std::endl;
}

int FileReader::readBlock(std::vector<uint32_t> &destin, int block_to_read) {
    std::unique_lock<std::mutex> lock(m);
    std::istream& input = read_from_stdin ? std::cin : stream;
    std::streampos pos = UINT32_SIZE * block_size * block_to_read;
    input.clear();
    input.seekg(pos);
    if (input.fail()) {
        std::cout<<"FALLO EN EL BYTE: "<<pos<<std::endl;
        std::cout<<"READING ERROR: "<<block_to_read<<std::endl;
        return NO_BLOCK_TO_READ;
    }
    for (int i = 0; i < block_size; i++) {
        if (this->readSample(destin, input, block_to_read) == EOF_REACHED) { //block to read no va
            if (i == 0) {
                return NO_BLOCK_TO_READ;
            } else {
                return EOF_REACHED;
            }
        }
    }
    return SUCCESS;
}

int FileReader::readSample(std::vector<uint32_t> &destin, std::istream& input, int block_to_read){
    char buf[UINT32_SIZE];
    uint32_t numb;
    input.read(buf, UINT32_SIZE);
    if (input.eof()) {
        std::cout<<"EOF: "<<block_to_read<<std::endl;
        return EOF_REACHED;
    } else {
        std::memcpy(&numb, buf, UINT32_SIZE);
        numb = be32toh(numb);
        std::cout<<"THREAD NRO: " <<std::this_thread::get_id()<<" IS READING BLOCK: "<<block_to_read<<std::endl;
        //h++; to debug .. thread nro: .. h
        destin.push_back(numb);
        return SUCCESS;
    }
}

FileReader::~FileReader() {}
