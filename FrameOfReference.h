//
// Created by leobellaera on 15/9/19.
//

#ifndef TP2_FRAMEOFREFERENCE_H
#define TP2_FRAMEOFREFERENCE_H

#include "BlockCompressor.h"
#include "FileReader.h"


class FrameOfReference {
    private:
        int block_size;
        FileReader file_reader;
        FileWriter file_writer;
        BlockCompressor block_compressor;

    public:
        FrameOfReference(int block_size, char* infile_path, char* outfile_path);
        int compressFile(); //0 on success, 1 on error.
        ~FrameOfReference();
};


#endif //TP2_FRAMEOFREFERENCE_H
