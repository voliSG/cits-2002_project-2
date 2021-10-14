#include <duplicates.h>
#define OPTLIST   "aAfhlq"
int main(int argc, char *argv[])
{
  int opt;

  while((opt = getopt(argc, argv, OPTLIST)) != -1){
    switch (opt) {
      case 'a':

      case 'A':
        exit(EXIT_FAILURE);
      case 'f':

      case 'h':

      case 'l':

      case 'q':

    }
  }
}
