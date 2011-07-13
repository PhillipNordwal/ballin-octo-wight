#include "island.h"

/* select a random cell that contains a 1, zero it and increment its neighbors */
void diffone(int grid[N][N])
{

	int r;

  r = (int)(drand48()*count);
  walk(list[0][r], list[1][r], grid);
}

/* increment one of the cells 4-neighbors and zero the cell */
void walk(int i,int j, int grid[N][N])
{
	int max, x, y, l;
	double p;

	max = N-1;
  x = i;
  y = j;
	p = drand48();

	if(p<=0.25) { /* increment the cell to the right */
    x = (i+1)%N;
	}
  else if(p>0.25 && p<=0.5) { /* increment the cell to the left */
    x = (i-1+N)%N;
	}
	else if(p>0.5 && p<=0.75) { /* increment the cell to the bottom side */
    y = (j+1)%N;
	}
	else if(p>0.75 && p<=1.0) { /* increment the cell to the top side */
    y = (j-1+N)%N;
	}

  /* find the position after the old position in the list */
  for (l = 0; list[0][l] != i || list[1][l] != j; l++);

  /* check to see that we aren't adding to an island */
  if (grid[x][y] == 0){
    list[0][l] = x;
    list[1][l] = y;
  } else if (grid[x][y] == 1) {
    /* remove the old entry */
    for (; l < count; l++) {
      list[0][l] = list[0][l+1];
      list[1][l] = list[1][l+1];
    }
    count--;
    /* remove the entry that was collided with */
    for (l=0; list[0][l] != x || list[1][l] != y; l++);
    for (; l < count; l++) {
      list[0][l] = list[0][l+1];
      list[1][l] = list[1][l+1];
    }
    count--;
  } else if (grid[x][y] > 1) {
    /* remove the old entry */
    for (; l < count; l++) {
      list[0][l] = list[0][l+1];
      list[1][l] = list[1][l+1];
    }
    count--;
  }
	grid[x][y] += 1;
	grid[i][j] = 0;

}
/* vim: set ts=2 sw=2: */
