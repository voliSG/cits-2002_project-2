#include "duplicates.h"

bool hf_flags(HASHTABLE *files, char *hash_key, char *ignore) {
    FILE_DATA *file;

    char *ignore_path = ignore;             // the file path we compare, this won't be printed
    file = hashtable_get(files, hash_key);

    // check if there is a file at the index or not
    if (file == NULL) {
        return false;
    }

    // pathname array for each file stores the pathnames of duplicate files
    for (int i = 0; i <= file->num_files; ++i) {
      // compare each pathname, to avoid printing the pathname of the intial file
      if(strcmp(file->pathname[i], ignore_path) != 0){
        printf("%s\n", file->pathname[i]);
      }
    }

    return true;
}
