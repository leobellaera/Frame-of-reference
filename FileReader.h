//
// Created by leobellaera on 12/9/19.
//

#ifndef TP2_FILE_H
#define TP2_FILE_H

#include <iostream>
#include <fstream>
#include <vector>

class FileReader {
    private:
        std::ifstream stream;
        int block_size;
        bool stdin_reading;
        int readSample(std::vector<uint32_t> &destin);
    public:
        FileReader(char* path, int block_size);
        int readBlock(std::vector<uint32_t> &destin);
        ~FileReader();

};

#endif //TP2_FILE_H
