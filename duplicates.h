#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/param.h>
#include <sys/stat.h>

#include "hashtable.h"

// declare function that reads directory
extern HASHTABLE    *readDir(char *dirname, bool show_hidden);
