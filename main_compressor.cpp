#include "BlockCompressor.h"
#include <iostream>
#include <cstring>
#include <vector>
#include "Block.h"
#include <fstream>

int main() {
    std::vector<uint32_t> test;
    test.push_back(18);
    test.push_back(21);
    test.push_back(19);
    test.push_back(20);
    int size = 4;
    BlockCompressor b(size);
    Block block(test, 4);
    std::vector<uint8_t> res = b.compressBlock(block);
    //uint32_t num;
    //memcpy(&num, res, 4);
    std::ofstream myFile("outfile", std::ios::binary);
    myFile.write((char*)res.data(), res.size());
    myFile.close();
    //std::cout<<"buffer tam is : " << (unsigned)tam << std::endl;
    //std::cout<<"reference is: " << num << std::endl;
    //std::cout<<"number of bits used is: "<< +res[4] << std::endl;
    /*std::cout<<"buf[0]: "<< (unsigned)res[5] << std::endl;
    std::cout << "buf[1]: " << (unsigned)res[6] << std::endl;
    std::cout << "buf[1]: " << (unsigned)res[7] << std::endl;*/

    return 0;
}

