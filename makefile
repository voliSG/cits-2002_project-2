PROJECT = duplicates
HEADERS = $(PROJECT).h
OBJ     = duplicates.o hf_flags.o l_flag.o hash_dir.o hashtable.o strSHA2.o

C11 = cc -std=c11
CFLAGS = -Wall -Werror -pedantic

$(PROJECT) : $(OBJ)
	$(C11) $(CFLAGS) -o $(PROJECT) $(OBJ) 

duplicates.o : duplicates.c $(HEADERS)
	$(C11) $(CFLAGS) -c duplicates.c

hf_flags.o : hf_flags.c $(HEADERS)
	$(C11) $(CFLAGS) -c hf_flags.c

l_flag.o : l_flag.c $(HEADERS)
	$(C11) $(CFLAGS) -c l_flag.c

hash_dir.o : hash_dir.c $(HEADERS)
	$(C11) $(CFLAGS) -c hash_dir.c

hashtable.o : hashtable.c hashtable.h
	$(C11) $(CFLAGS) -c hashtable.c

strSHA2.o : strSHA2.c
	$(C11) $(CFLAGS) -c strSHA2.c

clean: rm -f $(PROJECT) $(OBJ)
