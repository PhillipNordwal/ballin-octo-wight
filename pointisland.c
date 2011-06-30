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

/*	f1=fopen("Tcovti1.d","w");
	f2=fopen("Tsteps1","w");
	f3=fopen("Tgrid1.d","w");*/

	open_files();

	F = 0.00000001;
	tau = 1.0;
	n = 0;
	L = (double)(N);
	iflag = 0;
	t = 0;
	knt = 100;
	sum = 0.0;
	for (i=0;i<N;i++) {
	for (j=0;j<N;j++) {	
	grid[i][j] = 0;
	}
	}

	i = 0;
	while (F*t<0.20)  {
	  	pf = F/(F+n/(L*L*tau));
//		pd = (n/(L*L*tau))/(F+n/(L*L*tau)); 
	    p=drand48();
	    if(p<pf) {
		addmon(grid);
	    	n = kntmon(grid);
//		fprintf(f2,"%f	%f	%d	%f\n",p,pf,i,t);
	    }
	    else diffone(grid);

//	printf("looping: %d	 %f	%f	%f\n",n,F*t,p,pf);

	t += 1.0/(F*L*L + n/tau);
//	if (i==knt) {
//	       fprintf(f1,"%f	%f	%f\n",t,F*t,n/(L*L));
//		knt += 10000;
//	   }
	i++;
	}

        for (i=0;i<N;i++) {
        for (j=0;j<N;j++) {
        if(grid[i][j] != 0) fprintf(ginfo_file,"%d	%d	%d\n",i,j,grid[i][j]);
//	sum += grid[i][j];
        }
        }

//	printf("#  %f\n",sum/(L*L));
 return 0;
}
	
