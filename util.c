#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/stat.h>
#include "island.h"



void open_files(void)
{
        char fname[256];
        int i;
        struct stat st;

        if(write_ginfo) {
                snprintf(fname, 256, "ginfo.%d", N);
                for(i=0; stat(fname, &st) == 0; i++) {
                        snprintf(fname, 256, "ginfo.%d.%d", N, i);
                }

                ginfo_file = fopen(fname, "w");

                if(!ginfo_file) {
                        perror("Cannot open ginfo file");
                        exit(1);
                } 
        }

}
