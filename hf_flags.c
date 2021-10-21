#include "duplicates.h"

bool hf_flags(HASHTABLE *files, char *hash_key, char *ignore) {
    FILE_DATA *file;

    char *ignore_path = ignore;
    file = hashtable_get(files, hash_key);

    if (file == NULL) {
        return false;
    }

    for (int i = 0; i <= file->num_files; ++i) {
      if(strcmp(file->pathname[i], ignore_path) != 0){
        printf("%s\n", file->pathname[i]);
      }
    }

    return true;
}
