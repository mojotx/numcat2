#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include "process.h"

#define BLK "\e[1;30m"
#define OFF "\e[0m"

void process( const char *fn )
{
    FILE *fp;
    char buffer[4096]={0};

    if ((fp = fopen(fn, "r"))==NULL) {
        fprintf(stderr,"Cannot read from %s: %s\n", fn, strerror(errno));
        return;
    }

    // First, count how many lines are in the file
    unsigned long line_count=0;
    while (fgets(buffer,sizeof (buffer), fp)) {
       line_count++;
    }
    unsigned width = (unsigned)(log10( (double)(line_count) ) )+1;

    unsigned long int n=0;
    rewind(fp);
    while(fgets(buffer, sizeof(buffer), fp)) {
        printf( BLK "%*lu:" OFF " %s", width, ++n, buffer);
    }
    if (fclose(fp)) {
        fprintf(stderr,"Cannot close file %s: %s\n", fn, strerror(errno));
    }
}

