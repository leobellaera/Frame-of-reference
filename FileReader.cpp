//
// Created by leobellaera on 12/9/19.
//

#include "FileReader.h"
#include <arpa/inet.h>
#define UINT32_SIZE 4

FileReader::FileReader(char* path, uint32_t numbs_per_block) :
    stream(),
    file_path(path),
    numbs_per_block(numbs_per_block) {
    if (this->file_path != "-") {
        this->stream.open(this->file_path);
    }
}

int FileReader::readBlock(uint32_t* block) {
    if (this->file_path != "-") {
        return this->readBlockFromFile(block);
    }
    else {
        return this->readBlockFromStdin(block);
    }
}

int FileReader::readBlockFromFile(uint32_t* block) {
    int i = 0;
    char actual_numb[4];
    while (i < this->numbs_per_block) {
        if (!this->stream) {
            return -1;
        }
        if (this->stream.get(actual_numb, UINT32_SIZE)) {
            //ntohl..
            //memcpy
            i++;
        } else {
            return i;
        }
    }
    return i;
}

int FileReader::readBlockFromStdin(uint32_t* block) {
    int i = 0;
    uint32_t actual_numb;
    while (i < this->numbs_per_block && std::cin.get(&actual_numb, UINT32_SIZE)) {
        //ntohl..
        //memcpy
        i++;
    }
    return i;
}

FileReader::~FileReader() {
    if (this->readFile.is_open()) {
        this->readFile.close();
    }
}
