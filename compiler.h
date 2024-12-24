#ifndef PEACHCOMPILER_H
#define PEACHCOMPILER_H

#include <stdio.h>

enum 
{
    COMPILER_FILE_COMPILED_OK,
    COMPILER_FAILED_WITH_ERRORS,

};

struct compile_process
{
    struct compile_process_input_file
    {
        FILE* fp;
        const char* abs_path;
    } cfile;

    FILE* ofile;

    // the flags in regard to how to compile the file
    int flags;
};

/**
 * create a compile process for a file
 */
struct compile_process* compile_process_create(const char *filename, const char *out_filename, int flags);

/**
 * compile a file
 */
int compile_file(const char *filename, const char *out_filename, int flags);

#endif