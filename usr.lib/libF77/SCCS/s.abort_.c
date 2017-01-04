h51940
s 00002/00002/00027
d D 5.2 86/11/03 20:36:19 mckusick 7 6
c update for tahoe
e
s 00005/00001/00024
d D 5.1 85/06/07 21:30:13 kre 6 4
c Add copyright
e
s 00005/00000/00025
d R 5.1 85/06/06 21:40:02 jerry 5 4
c Add Copyright
e
s 00001/00003/00024
d D 1.2 85/05/09 23:08:01 libs 4 1
c call f77_abort() instead of abort() to get consistent error handling
c and dumps only when wanted.
e
s 00001/00001/00026
d R 1.2 85/05/06 17:03:24 libs 3 1
c Change all calls to abort() to f77_abort() and have f77_abort() 
c call abort() for dump only when environment and load flags so specify.
e
s 00001/00001/00026
d R 1.2 85/05/06 14:13:32 libs 2 1
c Change all calls to abort() to f77_abort() and have f77_abort() 
c call abort() for dump only when environment and load flags so specify.
e
s 00027/00000/00000
d D 1.1 83/01/21 11:02:38 dlw 1 0
c date and time created 83/01/21 11:02:38 by dlw
e
u
U
t
T
I 1
/*
D 6
 *	"%W%"
E 6
I 6
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W%	%G%
E 6
 */

#include <stdio.h>

#if	pdp11
abort_()
{
	fprintf(stderr, "Fortran abort routine called\n");
	f_exit();
	_cleanup();
	abort();
}
D 7
#else	vax
E 7
I 7
#else	vax || tahoe
E 7
abort_(msg,len)
char *msg; int len;
{
	fprintf(stderr, "abort: ");
	if (nargs()) while (len-- > 0) fputc(*msg++, stderr);
	else fprintf(stderr, "called");
	fputc('\n', stderr);
D 4
	f_exit();
	_cleanup();
	abort();
E 4
I 4
	f77_abort();
E 4
}
D 7
#endif	vax
E 7
I 7
#endif	vax || tahoe
E 7
E 1
