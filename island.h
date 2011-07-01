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


#define N 10

EXTERN const int write_ginfo INIT(1);
EXTERN FILE *ginfo_file;

/* increments a random grid entry */
void addmon(int grid[N][N]); 
/* returns a count of the number of 1 entries in grid */
int kntmon(int grid[N][N]); 
/* select a random cell that contains a 1, zero it and increment its neighbors */
void diffone(int grid[N][N]); 
/* opens a file ginfo.N, if it already exists search for the first open
   option of the form ginfo.N.i and open it into the global ginfo_file */
void open_files(void);
/* increment one of the cells 4-neighbors and zero the cell */
void walk(int i,int j, int grid[N][N]); 
/* vim: set ts=2 sw=2: */
