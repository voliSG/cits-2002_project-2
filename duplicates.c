#include "duplicates.h"


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
}
