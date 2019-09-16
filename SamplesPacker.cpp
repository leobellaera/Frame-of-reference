//
// Created by leobellaera on 13/9/19.
//

#include "SamplesPacker.h"
#include <bitset>
#include <math.h>
#include <cstring>
#define UINT32_SIZE 4

SamplesPacker::SamplesPacker(int block_size) :
        size(block_size) {}

uint8_t SamplesPacker::getBitsPerSample(uint32_t* block) {
    uint32_t max = 0;
    for (int i = 0; i < size; i++) {
        if (block[i] > max) {
            max = block[i];
        }
    }
    if (max == 0) {
        return 0;
    }
    return (uint8_t)log2(max)+1;
}



void SamplesPacker::packSamples(uint32_t* block, uint8_t* buf) {
    std::string compressed_block;
    this->getSamplesPackedAsString(block, compressed_block);
    const char* aux = compressed_block.c_str();
    int i = 0;
    while (aux[i] != '\0') {
        uint8_t numb = this->convertBinaryByteToNumb(&aux[i*8]);
        std::memcpy(&buf[i], &numb, 1);
        i++;
    }
}

void SamplesPacker::getSamplesPackedAsString(uint32_t* block, std::string &string) {
    int bits_per_sample = this->getBitsPerSample(block);
    for (int i = 0; i < this->size; i++) {
        std::bitset<32> bitset_numb(block[i]);
        std::string aux = bitset_numb.to_string<char,std::string::traits_type,std::string::allocator_type>();
        aux = aux.substr(32 - bits_per_sample, bits_per_sample);
        string.append(aux);
    }
    while (string.length() % 8 != 0) {
        string.append("0");
    }
}

uint8_t SamplesPacker::convertBinaryByteToNumb(const char* binary) {
    uint8_t sum = 0;
    for (int i = 0; i < 8; i++) {
        if (binary[i] == '1') {
            sum += pow(2, 7-i);
        }
    }
    return sum;
}

SamplesPacker::~SamplesPacker() {

}

