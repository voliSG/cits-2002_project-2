// CITS2002 Project 2 2021
// Name(s): Sean Peralta Garcia, Agnibho Gangopadhyay
// Student number(s): 23088091, 23175264

#include "duplicates.h"
#include <getopt.h>

#define OPTLIST   "aAfhlq"

int main(int argc, char *argv[])
{
  int opt;

  while((opt = getopt(argc, argv, OPTLIST)) != -1){
    switch (opt) {
      case 'a':
        printf("a\n");
        break;
      case 'A':
        printf("A\n");
        exit(EXIT_FAILURE);
      case 'f':
        printf("f\n");
        break;
      case 'h':
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

// PRINTS NON OPTION ARGS
//  for(; optind < argc; optind++){     
//          printf("extra arguments: %s\n", argv[optind]); 
//  }


}
