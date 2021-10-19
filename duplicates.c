// CITS2002 Project 2 2021
// Name(s): Sean Peralta Garcia, Agnibho Gangopadhyay
// Student number(s): 23088091, 23175264

#include "duplicates.h"
#include <getopt.h>

#define OPTLIST    "aAfhlq"

int total_files   = 0;
int total_size    = 0;
int min_files     = 0;
int min_size      = 0;

char **hash_array = NULL;  // usage -l



void usage(bool a)
{
  //when argc < 2
  if(a){
    printf("Enter the correct number of arguments (i.e. <directory>/<filename>)\n");
  }
  //when wrong flag used
  else{
    printf("The incorrect flag was used, (i.e. -a,-f,-h,-l,-q)\n");
  }
  exit(EXIT_FAILURE);
}


void print_solutions()
{
    printf("%i\n", total_files);
    printf("%i\n", total_size);
    printf("%i\n", min_files);
    printf("%i\n", min_size);
}

int main(int argc, char *argv[])
{
    int opt;

    //checking the number of arguments
    if(argc < 2){
      usage(true);
    }

    // define
    HASHTABLE *files;

    // flag to determine if hidden files are to be read
    bool show_hidden = false;

    // file hash (usage: -f, -h)
    char *hash_key = NULL;

    // output stats


    // CHECK FOR -a before everything else
    /*while((opt = getopt(argc, argv, OPTLIST)) != -1){
        switch (opt) {
            case 'a':
                show_hidden = true;
                break;
            default:
                break;
        }
    }*/
    for(int i = 0; i < argc; i++){
      if(strcmp(argv[i], "-a") == 0){
       show_hidden = true;
      }
    }

    while((opt = getopt(argc, argv, OPTLIST)) != -1){
        switch (opt) {
            case 'A':
                printf("A\n");
                exit(EXIT_FAILURE);

            case 'a':
                // do nothing
                break;

            case 'f': ;
            // get hash of file then continue with -h
                // optind will point to filepath
                hash_key = strSHA2(argv[optind]);

            case 'h': ;
            // NOTE: hash will appear before directory

                // if hash_key != NULL then opt was -f
                if (hash_key == NULL) {
                    strcpy(hash_key, argv[optind]);
                }

                ++optind; // increment optind to index directory path

                files = hash_dir(argv[optind], show_hidden);

                bool complete = hf_flags(files, hash_key);

                // check if successful
                if (complete) {
                    exit(EXIT_SUCCESS);
                }
                exit(EXIT_FAILURE);

            case 'l':
                files = hash_dir(argv[optind], show_hidden);
                printf("going to l flags\n");
                l_flag(hash_array);
                break;

            case 'q':
                files = hash_dir(argv[optind], show_hidden);

                if (total_files == min_files) {
                    exit(EXIT_SUCCESS);
                }
                exit(EXIT_FAILURE);

            default:
                usage(false);
        }
    }
    // no flag has been parsed
    files = hash_dir(argv[argc-1], show_hidden);

    print_solutions();
    exit(EXIT_SUCCESS);
}
