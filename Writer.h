//
// Created by leobellaera on 19/9/19.
//

#ifndef FRAME_OF_REFERENCE_WRITER_H
#define FRAME_OF_REFERENCE_WRITER_H

#include "Thread.h

class Writer : public Thread {
    private:
        std::vector<SafeQueue>& queues;
    public:
        Writer(std::vector<SafeQueue>, char* outfile_path);
        virtual void run() override;
        ~Writer();
};


#endif //FRAME_OF_REFERENCE_WRITER_H
