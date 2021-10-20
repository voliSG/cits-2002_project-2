#include "duplicates.h"

void output(FILE_DATA *file) {
    for (int i = 0; i <= file->num_files; ++i) {
        printf("%s\n", file->pathname[i]);
    }
}

bool hf_flags(HASHTABLE *files, char *hash_key) {
    FILE_DATA *file;

    file = hashtable_get(files, hash_key);

    if (file == NULL) {
        return false;
    }

    output(file);

    return true;
}