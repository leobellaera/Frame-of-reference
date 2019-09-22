//
// Created by leobellaera on 19/9/19.
//

#include "Writer.h"
#include <iostream>
#include <algorithm>
#include <cstring>

#define REFERENCE_SIZE 4
#define INVALID_SIGNAL_NUMB 255

Writer::Writer(std::vector<BlockingQueue*> &queues, char* outfile_path) :
    queues(queues) {
    if (strcmp(outfile_path, "-")  != 0) {
        write_to_stdout = false;
        stream.open(outfile_path, std::ofstream::binary);
    } else {
        write_to_stdout = true;
    }
}

void Writer::run() {
    std::ostream& output = write_to_stdout ? std::cout : stream;
    size_t queues_finished_amount = 0;
    std::vector<int> queues_finished;
    while (queues_finished_amount != queues.size()) {
        for (int i = 0; (size_t)i < queues.size(); i++) {
            if (std::find(queues_finished.begin(), queues_finished.end(), i)
                != queues_finished.end()) {
                continue;
            }
            if (this->writeBlock(i, output) == 1) {
                queues_finished.push_back(i);
                queues_finished_amount++;
            }
        }
    }
}

int Writer::writeBlock(int index, std::ostream& output) {
    std::vector<uint8_t> compressed_block = queues[index]->pop();
    if (this->finish_signal_received(compressed_block)) {
        return 1;
    }
    output.write((char*)compressed_block.data(), compressed_block.size());
    return 0;
}

bool Writer::finish_signal_received(std::vector<uint8_t> &compressed_block) {
    for (int i = 0; i < REFERENCE_SIZE; i++) {
        if (compressed_block[i] != INVALID_SIGNAL_NUMB) {
            return false;
        }
    }
    return true;
}

Writer::~Writer() {}
