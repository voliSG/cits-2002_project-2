PROJECT = duplicates
HEADERS = $(PROJECT).h
OBJ     = duplicates.o strSHA2.o readDir.o

C11 = cc -std=c11
CFLAGS = -Wall -Werror -pedantic

$(PROJECT) : $(OBJ)
	$(C11) $(CFLAGS) -o $(PROJECT) $(OBJ) -lm

duplicates.o : duplicates.c $(HEADERS)
	$(C11) $(CFLAGS) -c duplicates.c

readDir.o : readDir.c $(HEADERS)
	$(C11) $(CFLAGS) -c readDir.c

strSHA2.o : strSHA2.c
	$(C11) $(CFLAGS) -c strSHA2.c

clean: rm -f $(PROJECT) $(OBJ)
