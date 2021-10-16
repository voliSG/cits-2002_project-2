#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// define stuff
#define TABLE_SIZE 1301

// DECLARE FUNCTIONS THAT ARE DEFINED IN hashtable.c

// hash function for array indexing
extern  uint32_t    hash_string(char *string);

extern  void        hashtable_init(int *files[]);

