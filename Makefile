CC=gcc
CFLAGS=-Wall -Werror -pg -std=gnu99 -pedantic
COMMON= main.o match-counts.o

all: quick naive

quick: main.c match-counts.c match-counts.h 
	gcc -DQUICK -o bin/$@ $(CFLAGS) main.c match-counts.c

naive: $(COMMON)
	gcc -o bin/$@ $(CFLAGS) $^

clean:
	rm -rf *.o bin/quick bin/naive *~
