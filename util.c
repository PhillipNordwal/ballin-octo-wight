#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/stat.h>
#include "island.h"


/* opens a unique file of the format ginfo_N_termdouble_XXXXXX to the file 
 * stream ginfo_file */
void open_files(double term)
{
	int fd;
	char fnametemplate[256];
	snprintf(fnametemplate, 256, "ginfo_%d_%.3f_XXXXXX", N, term);
	fd = mkstemp(fnametemplate);
	ginfo_file = fdopen(fd, "w");

}

void checkpoint(void)
{
}
/* vim: set ts=2 sw=2: */
