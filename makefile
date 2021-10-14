PROJECT = duplicates
HEADERS = $(PROJECT).h
OBJ     = duplicates.o

C11 = cc -std=c11
CFLAGS = -Wall -Werror -pedantic

$(PROJECT) : $(OBJ)
	$(C11) $(CFLAGS) -o $(PROJECT) $(OBJ) -lm

duplicates.o : duplicates.c $(HEADERS)
	$(C11) $(CFLAGS) -c duplicates.c