#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// define constant hashtable size
#define TABLE_SIZE      1301

// define FILE_DATA struct
typedef struct _file{
    char *filehash;             // string that holds SHA2 hash of file  
    char **pathname;            // array of strings holds pathnames of duplicate files
    int  num_files;             // holds number of files -1 (used for indexing)
}FILE_DATA;

// define linked list struct
typedef struct _list{
    struct _file    *file;      // pointer to a FILE_DATA struct
    struct _list    *next;      // pointer to next linked list struct
}LIST;


// define files hashtable as dynamically allocated array of LISTs
typedef LIST *HASHTABLE;

// DECLARE FUNCTIONS THAT ARE DEFINED IN hashtable.c
// allocate memry for hashtable
extern  HASHTABLE       *hashtable_init();

// add FILE_DATA struct to hashtable
extern  void            hashtable_add(HASHTABLE *hashtable, FILE_DATA *file);

// return FILE_DATA struct from specified hash
extern  FILE_DATA       *hashtable_get(HASHTABLE *hashtable, char *filehash);