#include <stdio.h>
#include <stdarg.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#include "error.h"
#include "getpar.h"

void sf_error( char *format, ... )
{
    va_list args;

    (void) fflush(stdout);
    va_start(args,format);

    /* print out name of program causing error */
    fprintf (stderr,"%s: ",sf_getprog());

    /* print out remainder of message */
    (void) vfprintf( stderr, format, args );
    va_end(args);

    /* if format ends with ':', print system information */
    if (format[0] != '\0' && format[strlen(format)-1] == ':')
	fprintf (stderr, " %s", strerror(errno));

    fprintf (stderr, "\n");
    exit(EXIT_FAILURE); 
}

void sf_warning( char *format, ... )
{
    va_list args;
    
    (void) fflush(stdout);
    va_start(args,format);

    /* print out name of program causing error */
    fprintf(stderr,"%s: ",sf_getprog()); 

    /* print out remainder of message */
    (void) vfprintf( stderr, format, args );
    va_end(args);

    /* if format ends with ':', print system information */
    if (format[0] != '\0' && format[strlen(format)-1] == ':')
	fprintf (stderr, " %s", strerror(errno));

    fprintf (stderr, "\n");
}

/* 	$Id: error.c,v 1.2 2003/09/29 14:34:55 fomels Exp $	 */

