#include "hashtable.h"
#include "duplicates.h"

// DECLARE EXTERNAL FUNCTIONS
// declare SHA2 hash used for files
extern	char *strSHA2(char *filename);

// define fixed length hashtable to hold pointer that point to FILE_DATA types
FILE_DATA *files[TABLE_SIZE];