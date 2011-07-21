#include "island.h"

/* select a random cell that contains a 1, zero it and increment its neighbors */
void diffone(int grid[N][N])
{

  int r;

  r = (int)(drand48()*count);
  walk(list[0][r], list[1][r], grid);
}

void choose_direction(int i, int j, int *x, int *y)
{
  long p;
	int a, b, c, d;
  p = bitrand2();

	/* the arithematic below is equivalent to this switch code  *
  switch(p)
  {
    case 0: {*y = (j+1)%N; break; }   // inc to the bottom
    case 1: {*x = (i+1)%N; break; }   // inc to the right
    case 2: {*y = (j-1+N)%N; break; } // inc to the top
    case 3: {*x = (i-1+N)%N; break; } // inc to the left
  } 
	*/
	a = p&1;
	b = p&2;
	c = !a;
	d = 1-b;
	/* the arithematic below is equivalent to this mod code if n=2^d*
	*x = (i+a*d+N)%N;
	*y = (j+c*d+N)%N;
	*/
	*x = (i+a*d)&(N-1);
	*y = (j+c*d)&(N-1);
}

/* increment one of the cells 4-neighbors and zero the cell */
void walk(int i,int j, int grid[N][N])
{
  int x, y, l;

  x = i;
  y = j;

  choose_direction(i, j, &x, &y);
  l = rlist[i][j];

  /* check to see that we aren't adding to an island */
  if (grid[x][y] == 0){
		/* their is no monomer in the new spot, update the monomer list to contain
		 * the new spot*/
    list[0][l] = x;
    list[1][l] = y;
		rlist[x][y] = l;
  } else {
    /* we are adding to an existing monomer, remove the old entry */
    for (; l < count; l++) {
			/* we remove the old entry, by shifting the remaining list entries
			 * back towards the beginning and update the monomer count */
      list[0][l] = list[0][l+1];
      list[1][l] = list[1][l+1];
			rlist[list[0][l+1]][list[1][l+1]] = l;
    }
    count--;
  	if (grid[x][y] == 1) {
      /* we just collided with a monomer, look up its position in the list */
      l = rlist[x][y];
      for (; l < count; l++) {
  			/* remove the collided entry from the list by shifting the remaining list
  			 * entries towards the beginning and update the monomer count */
        list[0][l] = list[0][l+1];
        list[1][l] = list[1][l+1];
				rlist[list[0][l+1]][list[1][l+1]] = l;
      }
      count--;
    } 
  }
  grid[x][y] += 1;
  grid[i][j] = 0;

}
/* vim: set ts=2 sw=2: */
