#include<stdlib.h>
#include "island.h"


void addmon(int grid[N][N])
{

	int x,y;

	x = (int)(drand48()*N);
	y = (int)(drand48()*N);

	grid[x][y] += 1;
}	
