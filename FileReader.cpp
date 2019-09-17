//
// Created by leobellaera on 12/9/19.
//

#include "FileReader.h"
#include <endian.h>
#include <cstream>
#define UINT32_SIZE 4
#define ERROR -1

FileReader::FileReader(char* path, uint32_t numbs_per_block) :
    stream(),
    numbs_per_block(numbs_per_block) {
    if (this->file_path != "-") {
        this->readFromStdin = false;
        this->stream.open(path);
    } else {
        this->readFromStdin = true;
    }
}

int FileReader::readBlock(uint32_t* block) {
    if (this->readFromStdin) {
        return this->read(std::cin, block);
    } else {
        return this->read(this->stream, block);
    }
}

/*int FileReader::readBlockFromFile(uint32_t* block) {
    int i = 0;
    uint32_t actual_numb;
    while (i < this->numbs_per_block) {
        if (!this->stream) {
            return -1;
        }
        if (this->stream.get(actual_numb, UINT32_SIZE)) {
            actual_numb = be32toh(actual_numb);
            std::memcpy()
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
        actual_numb = be32toh(actual_numb);
        std::memcpy();
        i++;
    }
    return i;
}*/

int FileReader::read(std::istream& stream, uint32_t* block){
    int i = 0;
    uint32_t actual_numb;
    while (i < this->numbs_per_block && stream.get(actual_numb, UINT32_SIZE) {
        actual_numb = be32toh(actual_numb);
        std::memcpy(&block[i], &actual_numb, UINT32_SIZE);
        i++;
    }
    if (stream.good() || stream.eof()) { //in other case, error happened
        return i;
    } else {
        return ERROR;
    }
}

FileReader::~FileReader() {
    if (this->readFile.is_open()) {
        this->readFile.close();
    }
}
