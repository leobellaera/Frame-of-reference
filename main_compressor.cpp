#include "BlockCompressor.h"
#include <iostream>
#include <cstring>
#include <vector>
#include "Block.h"
#include <fstream>

int main() {
    std::vector<uint32_t> test;
    test.push_back(2147555169);
    test.push_back(2147558181);
    test.push_back(2147558194);
    test.push_back(2147558172);
    int size = 4;
    BlockCompressor b(size);
    Block block(test, 4);
    uint8_t* res = b.compressBlock(block);
    //uint32_t num;
    //memcpy(&num, res, 4);
    uint32_t tam = b.getCompressedBlockSize(block);
    std::ofstream myFile("outfile", std::ios::binary);
    myFile.write((char*)res, tam);
    myFile.close();
    /*std::cout<<"buffer tam is : " << (unsigned)tam << std::endl;
    std::cout<<"reference is: " << num << std::endl;
    std::cout<<"number of bits used is: "<< +res[4] << std::endl;
    std::cout<<"buf[0]: "<< (unsigned)res[5] << std::endl;
    std::cout << "buf[1]: " << (unsigned)res[6] << std::endl;
    std::cout << "buf[1]: " << (unsigned)res[7] << std::endl;*/

    return 0;
}

