#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/param.h>
#include <sys/stat.h>

#include "hashtable.h"

// declare global variables for statistics
extern int      total_files;
extern int      total_size;
extern int      min_files;
extern int      min_size;

// declare global variables for duplicate files
extern int      num_dup;
extern char     **hash_array;

// declare extern function that reads directory
extern HASHTABLE    *hash_dir(HASHTABLE *files, char *dirname, bool show_hidden);


// declare extern function for program outputs
extern bool         hf_flags(HASHTABLE *files, char *hash_key, char *ignore);
extern void         l_flag(HASHTABLE *files, char **dup_array);

// declare SHA2 hash used for files
extern	char        *strSHA2(char *filename);

// declare strdup function from string.h
extern  char        *strdup(const char *s);
