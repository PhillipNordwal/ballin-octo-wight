CC = cc -O0 -g

all: pointisland.c addone.c diff.c kountmon.c util.c island.h
	$(CC) pointisland.c addone.c diff.c kountmon.c util.c -lm -o Tisles
test:
	./Tisles
clean:
	rm ginf* *~
