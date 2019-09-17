//
// Created by leobellaera on 15/9/19.
//

#ifndef FRAME_OF_REFERENCE_H
#define FRAME_OF_REFERENCE_H

#include "BlockCompressor.h"
#include "FileReader.h"


class FrameOfReference {
    private:
        int block_size;
        FileReader file_reader;
        char* outfile; //HARCODEO
        //FileWriter file_writer;
        BlockCompressor block_compressor;

    public:
        FrameOfReference(int block_size, char* infile_path, char* outfile_path);
        int compressFile();
        ~FrameOfReference();
};


#endif //FRAME_OF_REFERENCE_H
