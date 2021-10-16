#include "hashtable.h"

// hash function for array indexing
uint32_t hash_string(char *string)
{
    uint32_t hash = 0;
    while(*string != '\0') {
        hash = hash*31 + *string;
            ++string;
    }
    return hash;
}

// initialise hashtable values to NULL
void hashtable_init(int *hash_table[]) {
    for (int i=0; i < TABLE_SIZE; ++i) {
        hash_table[i] = NULL;
    }
}

void hashtable_add() {

}


