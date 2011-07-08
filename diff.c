#include "island.h"

/* select a random cell that contains a 1, zero it and increment its neighbors */
void diffone(int grid[N][N])
{

	int iwalk,x,y,i,j;
	double r,s;

	i = 0;
	j = 0;
	iwalk = 1;
	/* if any of the cells are 1  set iwalk=0 */
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(grid[i][j]==1) iwalk=0;
		}
	}

	while(iwalk==0){
		r = drand48()*(double)(N);
		s = drand48()*(double)(N);
		x = (int)(r);
		y = (int)(s);

		/* pick a random cell, set it to zero and increment a neighbor */
		if(grid[x][y] == 1) {
			walk(x,y,grid);
			iwalk = 1;
		}
	}
}

/* increment one of the cells 4-neighbors and zero the cell */
void walk(int i,int j, int grid[N][N])
{

	int max;
	double p;

	max = N-1;

	p = drand48();
	//	printf("walk	%f\n",p);

	if(p<=0.25) { /* increment the cell to the right */
		if(i+1>max) addone(0,j,grid);
		else addone(i+1, j, grid);
	}
	else if(p>0.25 && p<=0.5) { /* increment the cell to the left */
		if(i-1<0) addone(max,j,grid);
		else addone(i-1,j,grid);
	}
	else if(p>0.5 && p<=0.75) { /* increment the cell to the bottom side */
		if(j+1>max) addone(i,0,grid);
		else addone(i,j+1,grid);
	}
	else if(p>0.75 && p<=1.0) { /* increment the cell to the top side */
		if(j-1<0) addone(i,max,grid);
		else addone(i,j-1,grid);
	}

	grid[i][j] = 0;

}
/* vim: set ts=2 sw=2: */
