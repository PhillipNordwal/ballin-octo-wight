#include "island.h"

/* returns a count of the number of 1 entries in grid */
int kntmon(int grid[N][N])
{

	int i,j,n;
	
	n = 0;
	for(i=0;i<N;i++) {
	for(j=0;j<N;j++) {

	if(grid[i][j] == 1) n++;
	}
	}

	return n;
}
