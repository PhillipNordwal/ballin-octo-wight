#include <stdio.h>

/* The following block of code allows this file to work as a
 * header file for most files (letting them know about extern
 * variables), but actually declare the variables if MAIN is
 * defined. */

#ifdef MAIN
  #define EXTERN
  #define INIT(x) =x
#else
  #define EXTERN extern
  #define INIT(x)
#endif


#define N 800

EXTERN const int write_ginfo INIT(1);
EXTERN FILE *ginfo_file;

void addmon(int grid[N][N]);
int kntmon(int grid[N][N]);
void diffone(int grid[N][N]);
void walk(int i,int j, int grid[N][N]);
void open_files(void);
