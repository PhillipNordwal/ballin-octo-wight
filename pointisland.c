#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define MAIN
#include"island.h"

//FILE *f1,*f2,*f3;

int main(void)
{

	int i,j,iflag,utime,n;
	long ltime;
	double F,tau,p,pf,pd,L,t,sum;
	int knt,grid[N][N];

	ltime=time(NULL);
	utime=(unsigned int) ltime/2;
	srand48(utime);
	/* should save utime for reproducability */


	/* should save starting values of N, F, tau, knt for reproducability */
	F = 0.00000001;
	tau = 1.0;
	n = 0;
	L = (double)(N);
	iflag = 0;
	t = 0;
	knt = 100;
	sum = 0.0;
	/* initialize the grid to zeros */
	for (i=0;i<N;i++) {
		for (j=0;j<N;j++) {	
			grid[i][j] = 0;
		}
	}

	i = 0;
	while (F*t<0.20)  { 
/*	while (i<1000)  { */
		pf = F/(F+n/(L*L*tau));
		p=drand48();
		if(p<pf) {
			addmon(grid);
			n = kntmon(grid);
		}
		else diffone(grid);

		t += 1.0/(F*L*L + n/tau);
		i++;
		//if (i%(1<<11)==0) printf("%f\n",t*F);
	}

	open_files();
	for (i=0;i<N;i++) {
		for (j=0;j<N;j++) {
			if(grid[i][j] != 0) fprintf(ginfo_file,"%d	%d	%d\n",i,j,grid[i][j]);
			//	sum += grid[i][j];
		}
	}

	//	printf("#  %f\n",sum/(L*L));
	return 0;
}

/* vim: set ts=2 sw=2, ff=dos, ffs=dos sw=2: */
