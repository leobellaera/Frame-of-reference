//
// Created by leobellaera on 20/9/19.
//

#ifndef FRAME_OF_REFERENCE_FRAMEOFREFERENCE_H
#define FRAME_OF_REFERENCE_FRAMEOFREFERENCE_H

#include <vector>
#include "BlockingQueue.h"
#include "Thread.h"
#include "FileReader.h"
#include "BlocksProcessor.h"
#include "Writer.h"

class FrameOfReference {
    private:
        FileReader file_reader;
        std::vector<BlockingQueue*> queues;
        std::vector<Thread*> threads;
    public:
        FrameOfReference(int block_size, int processors_amount,
                int q_size, char* infile_path, char* outfile_path);
        void compress();
        ~FrameOfReference();
};


#endif //FRAME_OF_REFERENCE_FRAMEOFREFERENCE_H
