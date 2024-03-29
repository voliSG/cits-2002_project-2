#include "duplicates.h"

// PROCESS DIRECTORIES AND RETURN HASHTABLE THAT HOLDS ALL FILE PATHS AND HASHES
HASHTABLE *hash_dir(HASHTABLE *files, char *dirname, bool show_hidden) {
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

        sprintf(pathname, "%s/%s", dirname, dp->d_name);    // concatenates dirname + d_name to char *pathname

        if(stat(pathname, &stat_buffer) != 0) {
            perror( pathname );
            exit(EXIT_FAILURE);
        }

        // if path is a new directory then call function recursively for new path
        if( S_ISDIR( stat_p->st_mode )) {
            // check if directory is . (current) or .. (parent)
            if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0) {
                hash_dir(files, pathname, show_hidden);
            }
        }
        // if path is a file then process new file
        else if( S_ISREG( stat_p->st_mode )) {
            char *filehash;
            FILE_DATA *file;

            // if show_hidden == true then read all files OR
            // show_hidden == false AND file name does not start with '.'
            if (show_hidden || (!show_hidden && dp->d_name[0] != '.')) {
                filehash = strSHA2(pathname);

                // check if hash already in hashtable hashtable_get()
                file = hashtable_get(files, filehash);

                // if return pointer (duplicate)
                if (file != NULL) {
                    ++file->num_files;          // increment num_files

                    // add filepath to FILE_DATA (*file)
                    char *path_p = strdup(pathname);
                    file->pathname = realloc(file->pathname, (file->num_files) * sizeof(path_p));         // allocate memory for one pointer of
                    file->pathname[file->num_files] = path_p;   // add pathname to pathname array

                    ++total_files;                              // increment total_files
                    total_size += stat_p->st_size;              // update total_size

                    //add duplicate hash to the hash_array
                    if(file->num_files == 1){
                      num_dup++; //keep track of the duplicate hash array size
                      hash_array = realloc(hash_array, num_dup*sizeof(filehash));
                      hash_array[num_dup-1] = filehash;
                    }

                // if return NULL (unique file)
                } else {
                    // create FILE_DATA struct
                    FILE_DATA new_file;
                    FILE_DATA *p_newfile = &new_file;

                    p_newfile->filehash    = strdup(filehash);         // set filehash
                    p_newfile->num_files   = 0;                        // set num_files

                    char *path_p = strdup(pathname);                   // allocate memory and return char* pointer to path_p
                    p_newfile->pathname    = malloc(sizeof(path_p));   // init file
                    p_newfile->pathname[0] = path_p;

                    hashtable_add(files, p_newfile);                   // add new file to hashtable


                    ++total_files;                                     // increment total_files
                    ++min_files;                                       // increment min_files
                    total_size += stat_p->st_size;                     // update total_size
                    min_size   += stat_p->st_size;                     // update min_size
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
