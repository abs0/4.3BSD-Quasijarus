h08489
s 00027/00000/00129
d D 5.3 86/10/30 21:35:47 sam 6 4
c add tahoe (should be just like pdp11)
e
s 00006/00006/00123
d R 5.3 86/10/30 21:25:37 sam 5 4
c add tahoe
e
s 00001/00001/00128
d D 5.2 85/06/07 23:01:50 kre 4 3
c fix botch in previous delta
e
s 00005/00001/00124
d D 5.1 85/06/07 22:30:27 kre 3 2
c Add copyright
e
s 00063/00017/00062
d D 1.2 82/10/30 21:52:40 dlw 2 1
c added {,d}ffrac(); changed VAX -> vax in #if's. DLW
e
s 00079/00000/00000
d D 1.1 81/04/19 19:32:24 dlw 1 0
c date and time created 81/04/19 19:32:24 by dlw
e
u
U
t
T
I 1
/*
D 3
char id_range[] = "%W%";
E 3
I 3
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 3
 *
I 3
 *	%W%	%G%
D 4
 */
E 4
I 4
 *
E 4
E 3
 * routines to return extreme values
 * VERY MACHINE DEPENDENT
 */

union fi
{	float	f;
	long	i;
} ;

union dj
{	double	d;
	long	j[2];
} ;

float
flmax_()
{
	union fi n;
D 2
#ifdef	PDP11
E 2
I 2
#if	pdp11
E 2
	n.i = 0x7fffffffL;
D 2
#endif
#ifdef	VAX
E 2
I 2
#else	pdp11
#if	vax
E 2
	n.i = 0xffff7fff;
D 2
#endif
E 2
I 2
#else	vax
I 6
#if	tahoe
	n.i = 0x7fffffffL;
#else	tahoe
E 6
	UNKNOWN MACHINE!
I 6
#endif	tahoe
E 6
#endif	vax
#endif	pdp11
E 2
	return(n.f);
}

double
dflmax_()
{
	union dj n;
D 2
#ifdef	PDP11
E 2
I 2
#if	pdp11
E 2
	n.j[0] = 0x7fffffffL;
	n.j[1] = 0xffffffffL;
D 2
#endif
#ifdef	VAX
E 2
I 2
#else	pdp11
#if	vax
E 2
	n.j[0] = 0xffff7fff;
	n.j[1] = 0xffffffff;
D 2
#endif
E 2
I 2
#else	vax
I 6
#if	tahoe
	n.j[0] = 0x7fffffffL;
	n.j[1] = 0xffffffffL;
#else	tahoe
E 6
	UNKNOWN MACHINE!
I 6
#endif	tahoe
E 6
#endif	vax
#endif	pdp11
E 2
	return(n.d);
}

float
flmin_()
{
	union fi n;
D 2
#ifdef	PDP11
E 2
I 2
#if	pdp11
E 2
	n.i = 0x00800000L;
D 2
#endif
#ifdef	VAX
E 2
I 2
#else	pdp11
#if	vax
E 2
	n.i = 0x00000080;
D 2
#endif
E 2
I 2
#else	vax
I 6
#if	tahoe
	n.i = 0x00800000L;
#else	tahoe
E 6
	UNKNOWN MACHINE!
I 6
#endif	tahoe
E 6
#endif	vax
#endif	pdp11
E 2
	return(n.f);
}

double
dflmin_()
{
	union dj n;
D 2
#ifdef	PDP11
E 2
I 2
#if	pdp11
E 2
	n.j[0] = 0x00800000L;
	n.j[1] = 0;
D 2
#endif
#ifdef	VAX
E 2
I 2
#else	pdp11
#if	vax
E 2
	n.j[0] = 0x00000080;
	n.j[1] = 0;
D 2
#endif
E 2
I 2
#else	vax
I 6
#if	tahoe
	n.j[0] = 0x00800000L;
	n.j[1] = 0;
#else	tahoe
E 6
	UNKNOWN MACHINE!
I 6
#endif	tahoe
E 6
#endif	vax
#endif	pdp11
E 2
	return(n.d);
}

long int
inmax_()
{
D 2
	return(0x7fffffff);
E 2
I 2
	return(0x7fffffffL);
E 2
}

I 2

float
ffrac_()
{
	union fi n;
#if	pdp11
	n.i = 0x35000000L;
#else	pdp11
#if	vax
	n.i = 0x00003500;
#else	vax
I 6
#if	tahoe
	n.i = 0x35000000L;
#else	tahoe
E 6
	UNKNOWN MACHINE!
I 6
#endif	tahoe
E 6
#endif	vax
#endif	pdp11
	return(n.f);
}

double
dffrac_()
{
	union dj n;
#if	pdp11
	n.j[0] = 0x25000000L;
	n.j[1] = 0;
#else	pdp11
#if	vax
	n.j[0] = 0x00002500;
	n.j[1] = 0;
#else	vax
I 6
#if	tahoe
	n.j[0] = 0x25000000L;
	n.j[1] = 0;
#else	tahoe
E 6
	UNKNOWN MACHINE!
I 6
#endif	tahoe
E 6
#endif	vax
#endif	pdp11
	return(n.d);
}
E 2
E 1
