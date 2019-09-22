//
// Created by leobellaera on 20/9/19.
//

#ifndef FRAME_OF_REFERENCE_BLOCKSPROCESSOR_H
#define FRAME_OF_REFERENCE_BLOCKSPROCESSOR_H

#include "Thread.h"
#include "FileReader.h"
#include "BlockingQueue.h"
#include "BlockCompressor.h"

class BlocksProcessor : public Thread {
    private:
        BlockingQueue* queue;
        FileReader &file_reader;
        BlockCompressor block_compressor;
        int processors_amount;
        int slot;
        int block_size;
        int process_block(int block_to_read);
        void push_invalid_block();
    public:
        BlocksProcessor(BlockingQueue* queue,
                FileReader &fr, int n, int slot, int block_size);
        virtual void run() override;
        ~BlocksProcessor();
};


#endif //FRAME_OF_REFERENCE_BLOCKSPROCESSOR_H
