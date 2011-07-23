#CC = cc -O3 -funroll-loops -ffast-math -Wall -pedantic -march=core2
CC = cc -O0 -Wall -pedantic -g -pg

all: pointisland.c addone.c diff.c util.c bitrand.c island.h
	$(CC) pointisland.c addone.c diff.c util.c bitrand.c -lm -o Tisles
test:
	./Tisles
clean:
	rm ginf* *~
