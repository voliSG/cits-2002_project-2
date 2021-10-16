#include "duplicates.h"
// #include "hashtable.h"

// DECLARE EXTERNAL FUNCTIONS
// declare SHA2 hash used for files
extern	char *strSHA2(char *filename);

// declare FILE_DATA array to hold unique file hashes and relative paths
FILE_DATA *files = NULL;

// init hashtable
// HASHTABLE *files = hashtable_new();

// fnv.c - hash function for hashtable

// return files
int readDir() {
    return &files;
}