h33886
s 00005/00001/00023
d D 5.1 85/06/07 22:35:52 kre 4 3
c Add copyright
e
s 00001/00002/00023
d D 1.2 85/05/09 23:08:07 libs 3 1
c call f77_abort() instead of abort() to get consistent error handling
c and dumps only when wanted.
e
s 00001/00001/00024
d R 1.2 85/05/06 14:13:46 libs 2 1
c Change all calls to abort() to f77_abort() and have f77_abort() 
c call abort() for dump only when environment and load flags so specify.
e
s 00025/00000/00000
d D 1.1 83/01/21 11:19:05 dlw 1 0
c date and time created 83/01/21 11:19:05 by dlw
e
u
U
t
T
I 1
/*
D 4
 *	"%W%"
E 4
I 4
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W%	%G%
E 4
 */

#include <stdio.h>

/* called when a subscript is out of range */

s_rnge(varn, offset, procn, line)
char *varn, *procn;
long int offset;
int line;
{
register int i;

fprintf(stderr, "Subscript out of range on file line %d, procedure ", line);
for(i = 0 ; i < 8 && *procn!='_' ; ++i)
	putc(*procn++, stderr);
fprintf(stderr, ".\nAttempt to access the %ld-th element of variable ", offset+1);
for(i = 0 ; i < 6  && *varn!=' ' ; ++i)
	putc(*varn++, stderr);
fprintf(stderr, ".\n");
D 3
_cleanup();
abort();
E 3
I 3
f77_abort();
E 3
}
E 1
