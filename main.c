#include <stdio.h>

#include "compiler.h"

int main()
{
    int res = compile_file("./samples/test.c", "./dist/test", 0);
    if (res == COMPILER_FILE_COMPILED_OK)
    {
        printf("Everything compiled successfully...");
    }
    else if (res = COMPILER_FAILED_WITH_ERRORS)
    {
        printf("Compile failed!...");
    }
    else
    {
        printf("Unknown response for compile file\n");
    }

    return 0;
}