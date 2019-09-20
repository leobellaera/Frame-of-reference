//
// Created by leobellaera on 19/9/19.
//

#include "Writer.h"

Writer::Writer(std::vector<BlockingQueue> &queues, char* outfile_path) :
    queues(queues) {
    if (strcmp(path, "-")  != 0) {
        write_to_stdout = false;
        stream.open(outfile_path, std::ofstream::binary);
    } else {
        write_to_stdout = true;
    }
}

void Writer::run() {
    std::ostream& output = write_to_stdout ? std::cout : stream;
    int queues_finished_amount = 0;
    while (queues_finished_amount != queues.size()) {
        for (int i = 0; i < queues.size(); i++) {
            if (queues[i].is_closed()){
                queues_finished_amount++;
                continue;
            }
            std::vector<uint8_t> compressed_block = queues[i].pop();
            output.write((char*)compressed_block.data(), compressed_block.size());
        }
        queues_finished_amount = 0;
    }
}

Writer::~Writer() {}
