#include "duplicates.h"

void l_output(FILE_DATA *dupfile){
  for(int i = 0; i < dupfile -> num_files; i++){
    printf("%s", dupfile -> pathname[i]);
    printf("  ");
  }
  printf("\n");
}

void l_flag(HASHTABLE *files, char **dup_array){
  printf("in l_flag atm\n");
  FILE_DATA *dup_file;

  for(int i = 0; i < num_dup; i++){
    char *dup_hash = dup_array[i];
    dup_file = hashtable_get(files, dup_hash);
    l_output(dup_file);
  }

}
