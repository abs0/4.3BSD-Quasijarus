h48259
s 00003/00003/00044
d D 5.3 86/10/30 21:22:19 sam 4 3
c add tahoe
e
s 00001/00001/00046
d D 5.2 85/06/07 22:32:58 kre 3 2
c undo botch in previous delta
e
s 00005/00001/00042
d D 5.1 85/06/07 22:30:09 kre 2 1
c Add copyright
e
s 00043/00000/00000
d D 1.1 85/03/28 11:01:35 ralph 1 0
c date and time created 85/03/28 11:01:35 by ralph
e
u
U
t
T
I 1
/*
D 2
char id_random[] = "%W%";
E 2
I 2
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 2
 *
I 2
 *	%W%	%G%
D 3
 */
E 3
I 3
 * 
E 3
E 2
 * Routines to return random values
 *
 * calling sequence:
 *	double precision d, drandm
 *	i = irandm(iflag)
 *	x = random(iflag)
 *	d = drandm(iflag)
 * where:
 *	If arg is nonzero, generator is restarted and value is returned.
 *	If arg is 0, next value is returned.
 *	Integer values will range from 0 thru 2147483647 (see random(3)).
 *	Real values will range from 0.0 thru 1.0 .
 */

D 4
#if	vax
E 4
I 4
#if	defined(vax) || defined(tahoe)
E 4
#define	RANDMAX		2147483647
D 4
#else	vax
E 4
I 4
#else	vax || tahoe
E 4
	UNKNOWN MACHINE!
D 4
#endif	vax
E 4
I 4
#endif	vax || tahoe
E 4

long irandm_(iarg)
long *iarg;
{
	if (*iarg) srandom((int)*iarg);
	return( random() );
}

float random_(iarg)
long *iarg;
{
	if (*iarg) srandom((int)*iarg);
	return( (float)(random())/(float)RANDMAX );
}

double drandm_(iarg)
long *iarg;
{
	if (*iarg) srandom((int)*iarg);
	return( (double)(random())/(double)RANDMAX );
}
E 1
