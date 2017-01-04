h56095
s 00004/00004/00052
d D 5.3 86/10/30 21:22:17 sam 4 3
c add tahoe
e
s 00001/00001/00055
d D 5.2 85/06/07 22:32:54 kre 3 2
c undo botch in previous delta
e
s 00005/00001/00051
d D 5.1 85/06/07 22:29:46 kre 2 1
c Add copyright
e
s 00052/00000/00000
d D 1.1 82/10/30 22:05:26 dlw 1 0
c date and time created 82/10/30 22:05:26 by dlw
e
u
U
t
T
I 1
/*
D 2
char id_rand[] = "%W%";
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
 *	double precision d, drand
 *	i = irand(iflag)
 *	x = rand(iflag)
 *	d = drand(iflag)
 * where:
 *	If arg is 1, generator is restarted. If arg is 0, next value
 *	is returned. Any other arg is a new seed for the generator.
 *	Integer values will range from 0 thru 2147483647.
 *	Real values will range from 0.0 thru 1.0
 *	(see rand(3))
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
#if	pdp11
#define	RANDMAX		32767
#else	pdp11
	UNKNOWN MACHINE!
#endif	pdp11
D 4
#endif	vax
E 4
I 4
#endif	vax || tahoe
E 4

long irand_(iarg)
long *iarg;
{
	if (*iarg) srand((int)*iarg);
#if	pdp11
	return(( ((long)rand()) << 16) | rand());
#else	pdp11
	return( rand() );
#endif	pdp11
}

float rand_(iarg)
long *iarg;
{
	if (*iarg) srand((int)*iarg);
	return( (float)(rand())/(float)RANDMAX );
}

double drand_(iarg)
long *iarg;
{
	if (*iarg) srand((int)*iarg);
	return( (double)(rand())/(double)RANDMAX );
}
E 1
