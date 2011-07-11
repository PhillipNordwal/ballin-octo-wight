CC = cc -O2

all: pointisland.c addone.c diff.c kountmon.c util.c island.h
	$(CC) pointisland.c addone.c diff.c util.c -lm -o Tisles
test:
	./Tisles
clean:
	rm ginf* *~
