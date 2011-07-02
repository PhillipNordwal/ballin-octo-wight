#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/stat.h>
#include "island.h"

extern int grid[N][N];

/* opens a unique file ginfo_N_termdouble_XXXXXX and writes grid to it */
void write_file(double term, int grid[N][N])
{
	int fd, i, j;
	char fnametemplate[256];
	FILE *ginfo_file;
	snprintf(fnametemplate, 256, "ginfo_%d_%.3f_XXXXXX", N, term);
	fd = mkstemp(fnametemplate);
	ginfo_file = fdopen(fd, "w");
	for (i=0;i<N;i++) {
		for (j=0;j<N;j++) {
			if(grid[i][j] != 0) fprintf(ginfo_file,"%d	%d	%d\n",i,j,grid[i][j]);
		}
	}
	fclose(ginfo_file);
}

/* setup signal handlers 
 * CatchUSR1 for USR1
 * CatchUSR1 for SIGINT
 * CatchNDump for USR2
 * CatchNDump for SIGTERM 
 * CatchNDump for SIGHUP 
 * CatchNDump for SIGINT */
void setup_signals(void)
{
	signal(SIGUSR1, CatchUSR1);
	signal(SIGINT, CatchUSR1);
	signal(SIGUSR2, CatchNDump);
	signal(SIGHUP, CatchNDump);
	signal(SIGTERM, CatchNDump);
}

/* catch a USR1 signal */
void CatchUSR1(int signum)
{
	int i, j;
	for (i=0;i<N;i++) {
		for (j=0;j<N;j++) {
			if(grid[i][j] != 0) fprintf(stderr, "%d	%d	%d\n",i,j,grid[i][j]);
		}
	}
	fflush(stderr);
}

/* opens a unique file dump_ginfo_N_XXXXXX and writes grid to it */
void CatchNDump(int signum)
{
	int fd, i, j;
	char fnametemplate[256];
	FILE *ginfo_file;
	snprintf(fnametemplate, 256, "dump_ginfo_%d_XXXXXX", N);
	fd = mkstemp(fnametemplate);
	ginfo_file = fdopen(fd, "w");
	for (i=0;i<N;i++) {
		for (j=0;j<N;j++) {
			if(grid[i][j] != 0) fprintf(ginfo_file,"%d	%d	%d\n",i,j,grid[i][j]);
		}
	}
	fclose(ginfo_file);
	if (signum == SIGHUP || signum == SIGTERM)
		kill(getpid(), SIGKILL);
}
/* vim: set ts=2 sw=2: */
	