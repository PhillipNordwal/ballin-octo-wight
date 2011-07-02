#include <stdio.h>
#include <signal.h>
#include <unistd.h>

#define ALARMTIME 14400

#define N 14

/* increments a random grid entry */
void addmon(int grid[N][N]); 
/* returns a count of the number of 1 entries in grid */
int kntmon(int grid[N][N]); 
/* select a random cell that contains a 1 zero it and increment its neighbors */
void diffone(int grid[N][N]); 
/* opens a unique file ginfo_N_termdouble_XXXXXX and writes grid to it */
void write_file(double term, int grid[N][N]);
/* increment one of the cells 4-neighbors and zero the cell */
void walk(int i,int j, int grid[N][N]); 

/* setup signal handlers and an alarm */
void setup_signals(void);
/* catch a signal and output the grid to stderr */
void CatchUSR1(int signum);
/* opens a unique file dump_pid_ginfo_N_XXXXXX and writes grid to it */
void CatchNDump(int signum);

/* vim: set ts=2 sw=2: */