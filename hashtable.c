#include "hashtable.h"

// DEFINE LINKED LIST FUNCTIONS
FILE_DATA *filehash_find(LIST *list, char *filehash) {
    while(list != NULL) {
        FILE_DATA *file = list->file;
        // if filehash arg matches filehash in list 
        if(strcmp(file->filehash, filehash)) {
            return file;
        }
        list = list->next;
    }
    // no files found
    return NULL;
}

LIST *list_add(LIST *list, FILE_DATA *file) {
    // allocate memory for 1 node 
    LIST *new_ls    = malloc(sizeof(LIST));
    new_ls->file    = file;
    new_ls->next    = list;
    return new_ls;
}


// DEFINE HASHTABLE FUNCTIONS
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

// allocate memory for hashtable
HASHTABLE *hashtable_init() {
    HASHTABLE   *new_hasht = malloc(TABLE_SIZE * sizeof(LIST *));
    return new_hasht;
}

void hashtable_add(HASHTABLE *hashtable, FILE_DATA *file) {
    uint32_t index = hash_index(file->filehash);
    
    hashtable[index] = list_add(hashtable[index], file);
}

FILE_DATA *hashtable_get(HASHTABLE *hashtable, char *filehash) {
    uint32_t index = hash_index(filehash);

    // store linked list pointer of hashtable index
    LIST *list = hashtable[index];

    return filehash_find(list, filehash);
}
