#include "hash_dir.h"

// return files
HASHTABLE *hash_dir(char *dirname, bool show_hidden) {
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

        if(stat(pathname, &stat_buffer) != 0) {
            perror( pathname );
            exit(EXIT_FAILURE);
        }

        if( S_ISDIR( stat_p->st_mode )) {
            if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0) {
                hash_dir(pathname, show_hidden);
            }
        }
        else if( S_ISREG( stat_p->st_mode )) {
            char *filehash;
            FILE_DATA *file;

            // if show_hidden == true then read all files OR
            // show_hidden == false AND file name starts with '.'
            if (show_hidden || (!show_hidden && dp->d_name[0] != '.')) {
                filehash = strSHA2(pathname);

                // check if hash already in hashtable hashtable_get()
                file = hashtable_get(files, filehash);
                
                // if return pointer (duplicate)
                if (file != NULL) {
                    ++file->num_files;          // increment

                    // add filepath to FILE_DATA (*file)
                    file->pathname = realloc(file->pathname, (file->num_files) * sizeof(pathname));         // allocate memory for one pointer of
                    file->pathname[file->num_files] = strdup(pathname);



                    ++total_files;          // increment total_files
                    // update total_size


                // if return NULL (unique file)
                } else {
                    // create FILE_DATA struct

                    // call hashtable_add()


                    ++total_files;          // increment total_files
                    ++min_files;            // increment min_files
                    //update min_size
                }
            }
        }
        else {
            printf("Error: no such file or directory\n");
        }
    }
    closedir(dirp);


    return files;
}
