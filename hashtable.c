#include "hashtable.h"

// hash function for array indexing
uint32_t hash_index(char *string) {
    uint32_t hash = 0;
    while(*string != '\0') {
        hash = hash*31 + *string;
            ++string;
    }
    // returns valid index in array
    return hash % TABLE_SIZE;
}


// DEFINE LINKED LIST FUNCTIONS
// function that finds desired string in linked list
FILE_DATA *filehash_find(LIST *list, char *filehash) {
    // while file is not found
    while(list != NULL) {
        FILE_DATA *file = list->file;                   // get file pointed to by list node
        if(strcmp(file->filehash, filehash) == 0) {     // if filehash arg matches filehash in list
            return file;                                // return FILE_DATA when match found
        }
        list = list->next;
    }
    return NULL;        // no files found - return NULL
}

// function that adds new linked list node
LIST *list_add(LIST *list, FILE_DATA *file) {
    // allocate memory for 1 node
    LIST *new_ls    = malloc(sizeof(LIST));
    new_ls->file    = file;
    new_ls->next    = list;

    return new_ls;
}


// DEFINE HASHTABLE FUNCTIONS
// allocate memory for hashtable
HASHTABLE *hashtable_init() {
    HASHTABLE   *new_hasht = malloc(TABLE_SIZE * sizeof(LIST *));
    return new_hasht;
}


// add FILE_DATA struct to hashtable
void hashtable_add(HASHTABLE *hashtable, FILE_DATA *file) {
    uint32_t index = hash_index(file->filehash);
    // set hashtable[index] to pointer to first list node
    hashtable[index] = list_add(hashtable[index], file);
}


// return FILE_DATA struct from specified hash
FILE_DATA *hashtable_get(HASHTABLE *hashtable, char *filehash) {
    uint32_t index = hash_index(filehash);
    // store linked list pointer of hashtable index
    LIST *list = hashtable[index];
    return filehash_find(list, filehash);
}
