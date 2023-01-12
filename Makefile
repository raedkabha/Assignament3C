CC=gcc
CFLAGS= -Wall -g
.PHONEY: all 


all: isort txtfind


isort: isort.o
	$(CC) $(CFLAGS) -o isort isort.o


txtfind: txtfind.o
	$(CC) $(CFLAGS) -o txtfind txtfind.o


isort.o: isort.c
	$(CC) $(CFLAGS) -c isort.c


txtfind.o: txtfind.c
	$(CC) $(CFLAGS) -c txtfind.c


clean:
	rm -f *.o isort txtfind