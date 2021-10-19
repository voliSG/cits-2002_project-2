#include "duplicates.h"

void l_output(char **pathname, int n){
  for(int i = 0; i < n; i++){
      printf("%s", pathname[i]);
      printf("  ");
  }
  printf("\n");
}

void l_flag(HASHTABLE *files){
  FILE_DATA *file;

  //loop through the hashtable
  for(int i = 0; i < TABLE_SIZE; i++){
    //get each file
    file = files[i]->file;
    int num = file->num_files; //get the number of duplicates in each file

    //check for duplicates
    if(num > 0){
      l_output(file->pathname, num);
    }

  }
}
