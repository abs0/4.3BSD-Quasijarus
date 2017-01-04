h55185
s 00005/00001/00019
d D 5.1 85/06/07 21:55:01 kre 3 2
c Add copyright
e
s 00002/00001/00011
d D 1.2 84/12/21 15:04:02 dlw 2 1
c dereference exit code before cleanup. Donn Seeley
e
s 00012/00000/00000
d D 1.1 83/01/21 11:12:40 dlw 1 0
c date and time created 83/01/21 11:12:40 by dlw
e
u
U
t
T
I 1
/*
D 3
 *	"%W%"
E 3
I 3
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W%	%G%
E 3
 */


exit_(n)
long *n;
{
I 2
	int	exitcode;

#if	vax
	if (nargs() == 0)
		exitcode = 0;
	else
#endif	vax
		exitcode = *n;	/* take any segmentation violation here */
E 2
	f_exit();
	_cleanup();
D 2
	exit((int)*n);
E 2
I 2
	exit(exitcode);
E 2
}
E 1
