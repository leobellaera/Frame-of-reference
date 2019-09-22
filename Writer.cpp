//
// Created by leobellaera on 19/9/19.
//

#include "Writer.h"
#include <iostream>
#include <cstring>

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
    while (queues_finished_amount != queues.size()) {
        queues_finished_amount = 0;
        for (int i = 0; (size_t)i < queues.size(); i++) {
            std::vector<uint8_t> comp;
            if (this->writeBlock(i, output, comp) == 1) {
                queues_finished_amount++;
            }
        }
    }
}

int Writer::writeBlock(int index, std::ostream& output, std::vector<uint8_t> &compressed_block) {
    if (queues[index]->pop(compressed_block) == 1) {
        return 1;
    }
    output.write((char*)compressed_block.data(), compressed_block.size());
    return 0;
}

Writer::~Writer() {}
