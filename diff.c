#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "island.h"



void diffone(int grid[N][N])
{

	int iwalk,x,y,i,j;
	double r,s;

	i = 0;
	j = 0;
	iwalk = 1;
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

	if(grid[x][y] == 1) {
	  walk(x,y,grid);
	  iwalk = 1;
	}
	}
}

void walk(int i,int j, int grid[N][N])
{

	int max;
	double p;

	max = N-1;

	p = drand48();
//	printf("walk	%f\n",p);

	if(p<=0.25) {
		if(i+1>max) grid[0][j] += 1;
		else grid[i+1][j] +=1;
	}
	else if(p>0.25 && p<=0.5) {
                if(i-1<0) grid[max][j] += 1;
                else grid[i-1][j] +=1;
	}
        else if(p>0.5 && p<=0.75) {
                if(j+1>max) grid[i][0] += 1;
                else grid[i][j+1] +=1;
        }
        else if(p>0.75 && p<=1.0) {
                if(j-1<0) grid[i][max] += 1;
                else grid[i][j-1] +=1;
        }

	grid[i][j] = 0;

}
