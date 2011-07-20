#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define MAIN
#include <assert.h>
#include "island.h"

void update_t(double *pt)
{
  const double F = 0.00000001;
  const double tau = 1.0;
  const double L = (double)(N);
  *pt += 1.0/(F*L*L + count/tau);
}

void update_pf(double *ppf)
{
  const double F = 0.00000001;
  const double tau = 1.0;
  const double L = (double)(N);
  *ppf = F/(F+count/(L*L*tau));

}
int main(void)
{

  int i,j,utime;
  long ltime;
  double p,pf,t;
  int passed_boundary;
  const double F = 0.00000001;

  setup_signals();
  count=0;

  ltime=time(NULL);
  utime=(unsigned int) ltime/2;
  /*
   * srand48(utime);
  */
  srand48(2);
  srand(2);
  /* should save utime for reproducability */

  passed_boundary=0;
  t = 0;
  /* initialize the grid to zeros */
  for (i=0;i<N;i++) {
    for (j=0;j<N;j++) {	
      grid[i][j] = 0;
    }
  }

  while (F*t<0.20)  { 
    update_pf(&pf);
    p=drand48();
    if(p<pf) {
      addmon(grid);
    } else {
      diffone(grid);
    }

    update_t(&t);
    if (!passed_boundary && F*t>0.15) {
      write_file(0.15, grid);
      passed_boundary = 1;
    }
  }
  write_file(0.20, grid);

  return 0;
  }

  /* vim: set ts=2 sw=2: */
