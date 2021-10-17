#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// define constant hashtable size
#define TABLE_SIZE      1301

// define FILE_DATA struct
typedef struct _file{
    char *filehash;
    int filesize;
    char **pathname;
    int num_files;
}FILE_DATA;

// define linked list struct
typedef struct _list{
    struct _file    *file;
    struct _list    *next;
}LIST;


// define files hashtable as dynamically allocated array of LISTs
typedef LIST *HASHTABLE;

// DECLARE FUNCTIONS THAT ARE DEFINED IN hashtable.c
// hash function for array indexing
extern  uint32_t        hash_string(char *string);

extern  HASHTABLE       *hashtable_init();

extern  void            hashtable_add(HASHTABLE *hashtable, FILE_DATA *file);

extern  FILE_DATA       *hashtable_get(HASHTABLE *hashtable, char *filehash);