// CITS2002 Project 2 2021
// Name(s): Sean Peralta Garcia, Agnibho Gangopadhyay
// Student number(s): 23088091, 23175264

#include "duplicates.h"
#include <getopt.h>

// define option flags in char array
#define OPTLIST    "aAfhlq"


// initialise counters for output
int total_files   = 0;      // total number of files found in specified directory
int total_size    = 0;      // total size (in bytes) of all files found in directory
int min_files     = 0;      // number of UNIQUE files in directory
int min_size      = 0;      // size of files (in bytes) of all UNIQUE files

int num_dup       = 0;      // number of duplicate files (only counted once)
char **hash_array = NULL;   // array that holds the hashes of files that are duplicates (usage -l)


// procedure that outputs program usage for incorrect params
void usage(bool a) {
  //when argc < 2
  if (a) {
    printf("Enter the correct number of arguments (i.e. <directory>/<filename>)\n");
  }
  //when wrong flag used
  else {
    printf("The incorrect flag was used, (i.e. -a,-f,-h,-l,-q)\n");
  }
  // exit program with failure
  exit(EXIT_FAILURE);
}


// procedure that outputs the results when no opt flags are input
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


    // process option args
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

    // check if advanced project is attemped
    if (case_A) {exit(EXIT_FAILURE);}

    // check if all files are requested
    if (case_a) {show_hidden = true;}

    if (case_f || case_h) {
        // check number of args for -f or -h - print usage
        if (argc - optind != 2) {       // get num of non flag args
            printf("-f/-h option arg requires <filename/hash> <directory>\n");
            exit(EXIT_FAILURE);
        }

        char * cmp_path = NULL;             // path not included in output (usage -f)
        
        if (case_f) {                       // if opt -f get the hash of the filename parsed
            cmp_path = argv[optind];        // optind currently points to argv with filename
            hash_key = strSHA2(cmp_path);   // get hash_key of filename specified
        }
        else {                              // else case_h
            hash_key = argv[optind];        // optind currently points to hash
        }

        ++optind;                           // increment optind to index directory path;
        
        // read directory specified and return hashtable of all file data
        files = hash_dir(files, argv[optind], show_hidden);

        bool found = hf_flags(files, hash_key, cmp_path);

        // if file found then exit success
        if (found) {exit(EXIT_SUCCESS);}
        // else exit failure
        exit(EXIT_FAILURE);
    }

    if (case_l) {
        // check number of args for -l - print usage
        if (argc - optind != 1) {       // get num of non flag args
            printf("-l option arg requires <directory>\n");
        }

        // read directory specified and return hashtable of all file data
        files = hash_dir(files, argv[optind], show_hidden);

        l_flag(files, hash_array);
        exit(EXIT_SUCCESS);
    }

    if (case_q) {
        // read directory specified and return hashtable of all file data
        files = hash_dir(files, argv[optind], show_hidden);

        // if there are no duplicates then exit success
        if (total_files == min_files) {exit(EXIT_SUCCESS);}
        // else exit failure
        exit(EXIT_FAILURE);
    }

    // no flag has been parsed
    // read directory specified and return hashtable of all file data
    files = hash_dir(files, argv[argc-1], show_hidden);

    print_solutions();
    exit(EXIT_SUCCESS);
}
