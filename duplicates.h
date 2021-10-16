#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/param.h>

typedef struct{
  char *filehash;
  int filesize;
  char **pathname;
  int num_files;
  // next FILE_DATA
}FILE_DATA;
