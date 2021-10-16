#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/param.h>

extern FILE_DATA **readDir();

typedef struct{
    char *filehash;
    int filesize;
    char **pathname;
    int num_files;
    // next FILE_DATA field
}FILE_DATA;
