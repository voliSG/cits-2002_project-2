#include "readDir.h"

// return files
HASHTABLE *readDir(char *dirname, bool show_hidden) {
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
            readDir(pathname, show_hidden);
        }
        else if( S_ISREG( stat_p->st_mode )) {
            char *filehash;

            // if show_hidden == true then read all files OR
            // show_hidden == false AND file name starts with '.'
            if (show_hidden || (!show_hidden && dp->d_name[0] != '.')) {
                filehash = strSHA2(pathname);
                
            }


            // check if hash already in hashtable hashtable_get()
            // if return pointer (at least one list node)
                // search nodes for correct hash (strcmp)
                // add filepath to string array
                // increment num_files
            // if return NULL (no files in index)
                // create FILE_DATA struct
                // call hashtable_add()
        }
        else {
            perror("Error: no such file or directory");
        }
    }
    closedir(dirp);


    return files;
}
