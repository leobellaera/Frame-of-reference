//
// Created by leobellaera on 20/9/19.
//

#ifndef FRAME_OF_REFERENCE_BLOCKSPROCESSOR_H
#define FRAME_OF_REFERENCE_BLOCKSPROCESSOR_H

#include "Thread.h"
#include "FileReader.h"
#include "BlockingQueue.h"

class BlocksProcessor : public Thread {
    private:
        BlockingQueue &queue;
        FileReader &file_reader;
        int processors_amount;
        int slot;
        int process_block(int block_to_read);
    public:
        BlocksProcessor(BlockingQueue &queue, FileReader &fr, int n, int slot, int block_size);
        virtual void run() override;
        ~BlocksProcessor();
};


#endif //FRAME_OF_REFERENCE_BLOCKSPROCESSOR_H
