//
// Created by leobellaera on 12/9/19.
//

#ifndef TP2_FILE_H
#define TP2_FILE_H

#include <iostream>
#include <fstream>
#include <mutex>
#include <vector>

class FileReader {
    private:
        std::ifstream stream;
        int block_size;
        bool read_from_stdin;
        std::mutex m;
        int readSample(std::vector<uint32_t> &destin, std::istream &input, int block_to_read);
    public:
        FileReader(char* path, int block_size);
        int readBlock(std::vector<uint32_t> &destin, int block_to_read);
        ~FileReader();

};

#endif //TP2_FILE_H
