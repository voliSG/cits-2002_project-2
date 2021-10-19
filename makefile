PROJECT = duplicates
HEADERS = $(PROJECT).h
OBJ     = duplicates.o hashtable.o strSHA2.o

C11 = cc -std=c11
CFLAGS = -Wall -Werror -pedantic

$(PROJECT) : $(OBJ)
	$(C11) $(CFLAGS) -o $(PROJECT) $(OBJ) -lm

duplicates.o : duplicates.c $(HEADERS)
	$(C11) $(CFLAGS) -c duplicates.c

hash_dir.o : hash_dir.c $(HEADERS)
	$(C11) $(CFLAGS) -c hash_dir.c

hashtable.o : hashtable.c hashtable.h
	$(C11) $(CFLAGS) -c hashtable.c

strSHA2.o : strSHA2.c
	$(C11) $(CFLAGS) -c strSHA2.c

clean: rm -f $(PROJECT) $(OBJ)
