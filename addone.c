#include<stdlib.h>
#include "island.h"

/* increments a random grid entry */
void addmon(int grid[N][N])
{

	int x,y;

	x = (int)(drand48()*N);
	y = (int)(drand48()*N);

	grid[x][y] += 1;
}	
/* vim: set ts=2 sw=2: */
