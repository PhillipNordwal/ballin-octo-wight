CC = cc -O3 -funroll-loops -ffast-math -Wall -pedantic -g -pg
CC = cc -O0 -Wall -pedantic -g -pg

all: pointisland.c addone.c diff.c util.c island.h
	$(CC) pointisland.c addone.c diff.c util.c -lm -o Tisles
test:
	./Tisles
clean:
	rm ginf* *~
