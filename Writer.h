//
// Created by leobellaera on 19/9/19.
//

#ifndef FRAME_OF_REFERENCE_WRITER_H
#define FRAME_OF_REFERENCE_WRITER_H

#include "Thread.h"
#include <fstream>
#include "BlockingQueue.h"
#include <vector>

class Writer : public Thread {
    private:
        std::vector<BlockingQueue*> &queues;
        std::ofstream stream;
        bool write_to_stdout;
        int writeBlock(int index, std::ostream& output);
        bool finish_signal_received(std::vector<uint8_t> &compressed_block);
    public:
        Writer(std::vector<BlockingQueue*> &queues, char* outfile_path);
        virtual void run() override;
        ~Writer();
};


#endif //FRAME_OF_REFERENCE_WRITER_H
