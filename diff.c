#include "island.h"

/* select a random cell that contains a 1, zero it and increment its neighbors */
void diffone(int grid[N][N])
{

  int r;

  r = (int)(drand48()*count);
  walk(list[0][r], list[1][r], grid);
}

long getrand() { return mrand48() &3 ; }

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
	*x = (i+a*d+N)%N;
	*y = (j+c*d+N)%N;
}

int find_list_position(int i, int j)
{
  int l;
  /* find the position in the list being walked into */
  for (l = 0; list[0][l] != i || list[1][l] != j; l++);
  return l;
}

/* increment one of the cells 4-neighbors and zero the cell */
void walk(int i,int j, int grid[N][N])
{
  int x, y, l;

  x = i;
  y = j;

  choose_direction(i, j, &x, &y);
  l = find_list_position(i,j);

  /* check to see that we aren't adding to an island */
  if (grid[x][y] == 0){
		/* their is no monomer in the new spot, update the monomer list to contain
		 * the new spot*/
    list[0][l] = x;
    list[1][l] = y;
  } else if (grid[x][y] == 1) {
    /* we are adding to an existing monomer, remove the old entry */
    for (; l < count; l++) {
			/* we remove the old entry, by shifting the remaining list entries
			 * back towards the beginning and update the monomer count */
      list[0][l] = list[0][l+1];
      list[1][l] = list[1][l+1];
    }
    count--;
    /* we just collided with a monomer, look up its position in the list */
    l = find_list_position(x,y);
    for (; l < count; l++) {
			/* remove the collided entry from the list by shifting the remaining list
			 * entries towards the beginning and update the monomer count */
      list[0][l] = list[0][l+1];
      list[1][l] = list[1][l+1];
    }
    count--;
  } else if (grid[x][y] > 1) {
    /* we are adding to an existing monomer, remove the old entry */
    for (; l < count; l++) {
			/* we remove the old entry, by shifting the remaining list entries
			 * back towards the beginning and update the monomer count */
      list[0][l] = list[0][l+1];
      list[1][l] = list[1][l+1];
    }
    count--;
  }
  grid[x][y] += 1;
  grid[i][j] = 0;

}
/* vim: set ts=2 sw=2: */
