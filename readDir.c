#include "readDir.h"

// DECLARE EXTERNAL FUNCTIONS
// declare SHA2 hash used for files
extern	char *strSHA2(char *filename);

// declare FILE_DATA array to hold unique file hashes and relative paths
FILE_DATA *files = NULL;

// fnv.c - hash function for hashtable

// return files
int readDir() {
    return &files;
}