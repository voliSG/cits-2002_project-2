#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/param.h>
#include <sys/stat.h>

#include "hashtable.h"

//declare variables for statistics
extern int      total_files;
extern int      total_size;
extern int      min_files;
extern int      min_size;

//
extern char     **hash_array;

// declare function that reads directory
extern HASHTABLE    *hash_dir(char *dirname, bool show_hidden);

extern bool         hf_flags(HASHTABLE *files, char *hash_key);

// declare SHA2 hash used for files
extern	char        *strSHA2(char *filename);

extern  char        *strdup(const char *s);
