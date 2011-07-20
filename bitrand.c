#include <stdlib.h>

#define BITS 2
#define BITSDIV (32/BITS)
#define MASK (BITS*BITS-1)

unsigned int bitrand2()
{
	static int pos = BITSDIV;
	static unsigned int rnd[BITSDIV];
	unsigned int tmp, j;
	if (pos==BITSDIV){
		pos=0;
		tmp=(unsigned int) mrand48();
		for (j = 0; j<BITSDIV; ++j){
			rnd[j] = (unsigned int) (tmp & (MASK<<(j*BITS)))>>(j*BITS);
		}
	}
	return rnd[pos++];
}

