#include "readDir.h"


void read_file() {
    // readfile
    // get SHA2 hash

    // check if hash already in hashtable hashtable_get()
    // if return pointer (at least one list node)
        // search nodes for correct hash (strcmp)
        // add filepath to string array
        // increment num_files
    // if return NULL (no files in index)
        // create FILE_DATA struct
        // call hashtable_add()
}

// return files
HASHTABLE *readDir(char *dirname) {
    HASHTABLE *files    = hashtable_init();

    DIR             *dirp;
    struct dirent   *dp;

    dirp       = opendir(dirname);
    if(dirp == NULL) {
        perror( dirname );
        exit(EXIT_FAILURE);
    }

    while((dp = readdir(dirp)) != NULL) {  
        struct stat     stat_buffer;
        struct stat *stat_p = &stat_buffer;
        char            pathname[MAXPATHLEN];

        sprintf(pathname, "%s/%s", dirname, dp->d_name);

        if( S_ISDIR( stat_p->st_mode )) {
            readDir(pathname);
        }
        else if( S_ISREG( stat_p->st_mode )) {
            read_file();
        }
        else {
            perror("Error: no such file or directory");
        }
    }

    return files;
}