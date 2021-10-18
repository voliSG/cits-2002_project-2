// CITS2002 Project 2 2021
// Name(s): Sean Peralta Garcia, Agnibho Gangopadhyay
// Student number(s): 23088091, 23175264

#include "duplicates.h"
#include <getopt.h>

#define OPTLIST    "aAfhlq"

int total_files = 0;
int total_size  = 0;
int min_files   = 0;
int min_size    = 0;

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

    //
    HASHTABLE *files;

    // flag to determine if hidden files are to be read
    bool show_hidden = false;

    // file hash (usage: -f, -h)
    //char *hash_key;

    // no flag has been parsed
    files = hash_dir(argv[1], show_hidden);

    hashtable_get(files, "aa");
    // output stats

    while((opt = getopt(argc, argv, OPTLIST)) != -1){
        switch (opt) {
            case 'a':
                //show_hidden = true;
                printf("a\n");
                break;

            case 'A':
                printf("A\n");
                exit(EXIT_FAILURE);

            case 'f': ;
            // NOTE: filepath will appear before directory
                // optind will point to filepath
                //char *file_path = argv[optind];

                // obtain hash of file


                // increment optind to index directory path
                ++optind;




                printf("f\n");
                break;

            case 'h': ;
            // NOTE: hash will appear before directory
                //char *hash_key = argv[optind];

                printf("h\n");
                break;

            case 'l':
                printf("l\n");
                break;

            case 'q':
                printf("q\n");
                break;
        }
    }
    print_solutions();
    exit(EXIT_SUCCESS);
}
