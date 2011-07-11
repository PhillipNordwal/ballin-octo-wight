#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define MAIN
#include <assert.h>
#include "island.h"

int main(void)
{

  int i,j,iflag,utime,n;
  long ltime;
  double F,tau,p,pf,pd,L,t,sum;
  int knt;
  int passed_boundary;

  setup_signals();
  count=0;

  ltime=time(NULL);
  utime=(unsigned int) ltime/2;
  //srand48(utime);
  srand48(2);
  /* should save utime for reproducability */

  passed_boundary=0;
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
  addmon(grid);
  addmon(grid);
  while (F*t<0.20)  { 
    /*	while (i<1000)  { */
    pf = F/(F+count/(L*L*tau));
    p=drand48();
    if(p<pf) {
      addmon(grid);
    } else {
      diffone(grid);
    }

    t += 1.0/(F*L*L + count/tau);
    i++;
    //if (i%(1<<11)==0) printf("%f\n",t*F);
    if (!passed_boundary && F*t>0.15) {
      write_file(0.15, grid);
      passed_boundary = 1;
    }
  }
  write_file(0.20, grid);


  //	printf("#  %f\n",sum/(L*L));
  return 0;
  }

  /* vim: set ts=2 sw=2: */
