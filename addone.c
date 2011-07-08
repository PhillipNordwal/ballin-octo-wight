#include<stdlib.h>
#include "island.h"


/* increments a grid entry */
void addone(int x, int y, int grid[N][N])
{
	int i;
  /* check to see that we aren't adding to an island */
  if (grid[x][y] == 0){
  } else if (grid[x][y] == 1) {
    count -= 2;
  } else if (grid[x][y] > 1) {
    count -= 1;
  }
	grid[x][y] += 1;
}	

/* increments a random grid entry */
void addmon(int grid[N][N])
{

	int x,y;

	x = (int)(drand48()*N);
	y = (int)(drand48()*N);
  addone(x, y, grid);
  count++;

}	
/* vim: set ts=2 sw=2: */
