#include<stdlib.h>
#include "island.h"

/* increments a random grid entry */
void addmon(int grid[N][N])
{

  int x, y, i;

  x = (int)(drand48()*N);
  y = (int)(drand48()*N);
  /* check to see that we aren't adding to an island */
  if (grid[x][y] == 0){
    list[0][count]=x;
    list[1][count]=y;
		rlist[x][y] = count;
    count++;
  /* check to see if we are removing a mobile cell */
  } else if (grid[x][y] == 1) {
    /* find the cell in the list to remove */
    i=rlist[x][y];
    for (; i < count; i++) {
      list[0][i] = list[0][i+1];
      list[1][i] = list[1][i+1];
			rlist[list[0][i+1]][list[1][i+1]] = i;
    }
    count--;
  } 
  grid[x][y] += 1;

}	
/* vim: set ts=2 sw=2: */
