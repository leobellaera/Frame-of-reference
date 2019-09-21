//
// Created by leobellaera on 16/9/19.
//
#include <iostream>
#include <string>
#include "FrameOfReference.h"

#define INVALID_ARGS_AMOUNT_MSG "Invalid number of parameters inserted.\n"

int main(int argc, char *argv[]) {
    if (argc != 6) {
        std::cerr << INVALID_ARGS_AMOUNT_MSG;
        return 1;
    }
    int block_size = std::stoi(argv[1]);
    int threads_processors_amount = std::stoi(argv[2]);
    int q_size = std::stoi(argv[3]);

    FrameOfReference compressor(block_size, threads_processors_amount,
            q_size, argv[4], argv[5]);
    compressor.compress();
    return 0;
}
