h16785
s 00056/00000/00000
d D 5.1 85/04/29 18:37:01 mckusick 1 0
c date and time created 85/04/29 18:37:01 by mckusick
e
u
U
t
T
I 1
/*
 * Copyright (c) 1979 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

/* fake portable I/O routines, for those
    sites so backward as to not have the
     port. library */
/* munged for standard i/o library: peter and louise 5 may 80 */
#include <stdio.h>

FILE *cin, *cout;

FILE *copen( s, c )
    char *s;
    char c;
  {
  FILE *f;

	  if( c == 'r' ){
	    f = fopen( s, "r" );
  } else  if( c == 'a' ){
	    f = fopen( s, "a" );
	    fseek( f, 0L, 2 );
  } else {  /* c == w */
	    f = fopen( s, "w" );
  }

  return( f );
  }

cflush(x) FILE *x; { /* fake! sets file to x */
  fflush( cout );
  cout = x;
  }

system(){
  error( "The function \"system\" is called" );
  }

cclose(i) FILE *i; {
  fclose(i);
  }

cexit(i){
  fflush( cout );
  if ( i != 0 ) {
    abort();
  }
  exit(i);
  }
E 1
