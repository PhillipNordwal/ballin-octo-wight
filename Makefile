CC = cc -O2

all: pointisland.c addone.c diff.c kountmon.c util.c island.h
	$(CC) -g -pg pointisland.c addone.c diff.c kountmon.c util.c -lm -o Tisles
