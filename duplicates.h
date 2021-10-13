#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/param.h>

typedef struct{
  char *hash;
  int filesize;
  char **pathname;
}FILE;
