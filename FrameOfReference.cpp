//
// Created by leobellaera on 20/9/19.
//

#include "FrameOfReference.h"

FrameOfReference::FrameOfReference(int block_size, int processors_amount,
        int q_size, char* infile_path, char* outfile_path) :
    file_reader(infile_path, block_size) {
    for (int i = 0; i < processors_amount; ++i) {
        queues.push_back(new BlockingQueue(q_size));
        threads.push_back(new BlocksProcessor(queues[i],
                file_reader, processors_amount, i, block_size));
    }
    threads.push_back(new Writer(queues, outfile_path));
}

void FrameOfReference::compress() {
    int t_size = threads.size();
    int q_size = queues.size();
    for (int i = 0; i < t_size; i++) {
        threads[i]->start();
    }
    for (int i = 0; i < t_size; i++) {
        threads[i]->join();
    }
    for (int i = 0; i < t_size; i++) {
        delete threads[i];
        if (i < q_size) {
            delete queues[i];
        }
    }
}

FrameOfReference::~FrameOfReference() {}
