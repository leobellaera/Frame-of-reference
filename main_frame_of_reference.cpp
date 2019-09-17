//
// Created by leobellaera on 16/9/19.
//
#include <iostream>
#include "FrameOfReference.h"
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int first_param = atoi(argv[1]);
    FrameOfReference FOR(first_param, argv[2], argv[3]);
    FOR.compressFile();
    return 0;
}
