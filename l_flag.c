#include "duplicates.h"

void l_output(FILE_DATA *dupfile){
  //use numfiles because the pathname array in that file will be the size of numfiles
  for(int i = 0; i <= dupfile->num_files; i++){
    printf("%s\t", dupfile -> pathname[i]);     // getting each pathname
  }
  printf("\n");
}

void l_flag(HASHTABLE *files, char **dup_array){
  FILE_DATA *dup_file;

  for(int i = 0; i < num_dup; i++) {
    char *dup_hash = dup_array[i];              // getting each hash from the array made
    dup_file = hashtable_get(files, dup_hash);  // getting the file at the index the hash belongs to
    l_output(dup_file);                         // calling the function which prints it
  }
}
