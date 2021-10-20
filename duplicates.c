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

int num_dup = 0;
char **hash_array = NULL;  // usage -l


void usage(bool a) {
  //when argc < 2
  if (a) {
    printf("Enter the correct number of arguments (i.e. <directory>/<filename>)\n");
  }
  //when wrong flag used
  else {
    printf("The incorrect flag was used, (i.e. -a,-f,-h,-l,-q)\n");
  }
  exit(EXIT_FAILURE);
}


void print_solutions() {
    printf("%i\n%i\n%i\n%i\n", total_files, total_size, min_files, min_size);
}

int main(int argc, char *argv[]) {
    int opt;

    // init hashtable to be used when determining outputs
    HASHTABLE *files    = hashtable_init();

    // file hash (usage: -f, -h)
    char *hash_key = NULL;

    // flag to determine if hidden files are to be read
    bool show_hidden = false;

    // init flags to keep track of opt args
    bool case_A = false;
    bool case_a = false;
    bool case_f = false;
    bool case_h = false;
    bool case_l = false;
    bool case_q = false;

    //checking the number of arguments
    if(argc < 2){
      usage(true);
    }


    while((opt = getopt(argc, argv, OPTLIST)) != -1) {
        switch (opt) {
            case 'A':   case_A = true; break;
            case 'a':   case_a = true; break;
            case 'f':   case_f = true; break;
            case 'h':   case_h = true; break;
            case 'l':   case_l = true; break;
            case 'q':   case_q = true; break;
            default:    usage(false);  break;
        }
    }

    if (case_A) {exit(EXIT_FAILURE);}

    if (case_a) {show_hidden = true;}

    if (case_f || case_h) {
        // check number of args for -f or -h - print usage
        if (argc - optind != 2) {       // get num of non flag args
            printf("-f/-h option arg requires <filename/hash> <directory>\n");
            exit(EXIT_FAILURE);
        }

        // if opt -f get the hash of the filename parsed
        if (case_f) {hash_key = strSHA2(argv[optind]);}
        else        {hash_key = argv[optind];}

        ++optind; // increment optind to index directory path;
        files = hash_dir(files, argv[optind], show_hidden);

        bool found = hf_flags(files, hash_key);

        // check if successful
        if (found) {exit(EXIT_SUCCESS);}
        // else
        exit(EXIT_FAILURE);
    }

    if (case_l) {
        files = hash_dir(files, argv[optind], show_hidden);
        l_flag(files, hash_array);
        exit(EXIT_SUCCESS);
    }

    if (case_q) {
        files = hash_dir(files, argv[optind], show_hidden);

        //
        if (total_files == min_files) {exit(EXIT_SUCCESS);}
        //
        exit(EXIT_FAILURE);
    }

    // no flag has been parsed
    files = hash_dir(files, argv[argc-1], show_hidden);

    print_solutions();
    exit(EXIT_SUCCESS);

}
