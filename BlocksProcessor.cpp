//
// Created by leobellaera on 20/9/19.
//

#include "BlocksProcessor.h"
#include <vector>

#define REFERENCE_SIZE 4
#define CONTINUE 0
#define EOF_REACHED 2

BlocksProcessor(BlockingQueue &queue, FileReader &fr, int n, int slot, int block_size) :
    queue(queue),
    file_reader(fr),
    processors_amount(n),
    slot(slot),
    block_compressor(block_size) {}

virtual void run() override {
    int state = CONTINUE;
    //int block_a_leer
    while (state == CONTINUE) {
        //int block_a_leer+=..
    }
    return;
}

int process_block(/*int block_a_leer*/) { /*metodo privado*/
    std::vector<uint32_t> numbs;
    int state = file_reader.readBlock(numbs);
    if (state == EOF_REACHED) {
        queue.close();
        return EOF_REACHED;
    }
    Block block(numbs, block_size);
    std::vector<uint8_t> compressed_block(REFERENCE_SIZE);
    block_compressor.compressBlock(block, compressed_block);
    queue.push(compressed_block);
    return SUCC
}

~BlocksProcessor() {}
