#include "hashtable.h"
#include "duplicates.h"

// DECLARE EXTERNAL FUNCTIONS
// declare SHA2 hash used for files
extern	char *strSHA2(char *filename);

// declare function that reads directory
extern HASHTABLE    *readDir(char *dirname, bool show_hidden);