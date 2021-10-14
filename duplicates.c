#include "duplicates.h"
#define OPTLIST   "aAfhlq"

int main(int argc, char *argv[])
{
  int opt;

  while((opt = getopt(argc, argv, OPTLIST)) != -1){
    switch (opt) {
      case 'a':
        break;
      case 'A':
        exit(EXIT_FAILURE);
      case 'f':
        break;
      case 'h':
        break;
      case 'l':
        break;
      case 'q':
        break;
    }
  }
}
