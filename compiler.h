#ifndef PEACHCOMPILER_H
#define PEACHCOMPILER_H

#include <stdio.h>
#include <stdbool.h>

enum
{
    COMPILER_FILE_COMPILED_OK,
    COMPILER_FAILED_WITH_ERRORS,

};

struct pos
{
    int line;
    int col;
    const char *filename;
};

enum
{
    TOKEN_TYPE_IDENTIFIER,
    TOKEN_TYPE_KEYWORD,
    TOKEN_TYPE_OPERATOR,
    TOKEN_TYPE_SYMBOL,
    TOKEN_TYPE_NUMBER,
    TOKEN_TYPE_STRING,
    TOKEN_TYPE_COMMENT,
    TOKEN_TYPE_NEWLINE,
};

struct token
{
    int type;
    int flags;

    union
    {
        char cval;
        const char *sval;
        unsigned int inum;
        unsigned long lnum;
        unsigned long long llnum;
        void *any;
    };

    bool whitespace;
    const char *between_brackets;
};

struct compile_process
{
    struct compile_process_input_file
    {
        FILE *fp;
        const char *abs_path;
    } cfile;

    FILE *ofile;

    // the flags in regard to how to compile the file
    int flags;
};

/**
 * create a compile process for a file
 */
struct compile_process *compile_process_create(const char *filename, const char *out_filename, int flags);

/**
 * compile a file
 */
int compile_file(const char *filename, const char *out_filename, int flags);

#endif