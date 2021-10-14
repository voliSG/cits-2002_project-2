// CITS2002 Project 2 2021
// Name(s): Sean Peralta Garcia, Agnibho Gangopadhyay
// Student number(s): 23088091, 23175264

#include "duplicates.h"
#include <getopt.h>

#define OPTLIST   "aAfhlq"

int main(int argc, char *argv[])
{
  int opt;

  // file hash (usage: -f, -h)
  char *hash_key;

  while((opt = getopt(argc, argv, OPTLIST)) != -1){
    switch (opt) {
      case 'a':
      // create some sort of flag to read hidden files
        printf("a\n");
        break;

      case 'A':
        printf("A\n");
        exit(EXIT_FAILURE);

      case 'f': ;
      // NOTE: filepath will appear before directory
        // optind will point to filepath
        char *file_path = argv[optind];

        // obtain hash of file
        

        // increment optind to index directory path
        ++optind;




        printf("f\n");
        break;

      case 'h': ;
      // NOTE: hash will appear before directory
        char *hash_key = argv[optind];

        printf("h\n");
        break;

      case 'l':
        printf("l\n");
        break;

      case 'q':
        printf("q\n");
        break;

      default:
      // no flag has been parsed
        // output stats
        break;
    }
  }
}
