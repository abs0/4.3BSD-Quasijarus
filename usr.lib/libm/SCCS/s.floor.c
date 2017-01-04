h17885
s 00010/00005/00115
d D 5.4 88/06/30 17:45:20 bostic 10 9
c install approved copyright notice
e
s 00063/00033/00057
d D 5.3 88/05/21 16:56:07 bostic 9 8
c new version from Kahan and Zliu; AT&T free, add Berkeley header
e
s 00009/00001/00081
d D 5.2 88/04/29 12:21:16 bostic 8 7
c add Berkeley copyright; NOTE: this code is AT&T derived!
e
s 00000/00000/00082
d D 5.1 87/11/30 18:33:59 bostic 7 6
c tahoe release
e
s 00010/00010/00072
d D 1.6 87/07/13 19:20:35 zliu 6 5
c clean-ups.
e
s 00002/00000/00080
d D 1.5 87/07/13 15:21:03 zliu 5 4
c ifdef out rint since KC added rint in ./NATIONAL/support.s
e
s 00006/00001/00074
d D 1.4 87/07/10 10:36:29 zliu 4 3
c adding _0x macro for TAHOE.
e
s 00002/00002/00073
d D 1.3 87/07/07 01:31:53 zliu 3 2
c first shot at TAHOE.
e
s 00001/00001/00074
d D 1.2 85/09/11 23:54:03 elefunt 2 1
c 4.3BSD version dated 09/11/85.
e
s 00075/00000/00000
d D 1.1 85/09/06 17:52:50 zliu 1 0
c date and time created 85/09/06 17:52:50 by zliu
e
u
U
t
T
I 1
D 2
/* %W% (ELEFUNT) %G% */
E 2
I 2
D 8
/*	%Z%%M%	4.2	9/11/85; %I% (ucb.elefunt) %G% */
E 8
I 8
/*
 * Copyright (c) 1985 Regents of the University of California.
D 9
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 9
I 9
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 10
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 10
I 10
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 10
 *
 * All recipients should regard themselves as participants in an ongoing
 * research project and hence should feel obligated to report their
 * experiences (good or bad) with these elementary function codes, using
 * the sendbug(8) program, to the authors.
E 9
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 8
E 2

I 9
#if defined(vax)||defined(tahoe)
#ifdef vax
#define _0x(A,B)	0x/**/A/**/B
#else	/* vax */
#define _0x(A,B)	0x/**/B/**/A
#endif	/* vax */
static long Lx[] = {_0x(0000,5c00),_0x(0000,0000)};	/* 2**55 */
#define L *(double *) Lx
#else	/* defined(vax)||defined(tahoe) */
static double L = 4503599627370496.0E0;		/* 2**52 */
#endif	/* defined(vax)||defined(tahoe) */

E 9
/*
D 9
 * floor and ceil-- greatest integer <= arg
 * (resp least >=)
E 9
I 9
 * floor(x) := the largest integer no larger than x;
 * ceil(x) := -floor(-x), for all real x.
 *
 * Note: Inexact will be signaled if x is not an integer, as is
 *	customary for IEEE 754.  No other signal can be emitted.
E 9
 */
D 9

double	modf();

E 9
double
D 9
floor(d)
double d;
E 9
I 9
floor(x)
double x;
E 9
{
D 9
	double fract;
E 9
I 9
	double y,ceil();
E 9

D 9
	if (d<0.0) {
		d = -d;
		fract = modf(d, &d);
		if (fract != 0.0)
			d += 1;
		d = -d;
	} else
		modf(d, &d);
	return(d);
E 9
I 9
	if (
#if !defined(vax)&&!defined(tahoe)
		x != x ||	/* NaN */
#endif	/* !defined(vax)&&!defined(tahoe) */
		x >= L)		/* already an even integer */
		return x;
	else if (x < (double)0)
		return -ceil(-x);
	else {			/* now 0 <= x < L */
		y = L+x;		/* destructive store must be forced */
		y -= L;			/* an integer, and |x-y| < 1 */
		return x < y ? y-(double)1 : y;
	}
E 9
}

double
D 9
ceil(d)
double d;
E 9
I 9
ceil(x)
double x;
E 9
{
D 9
	return(-floor(-d));
E 9
I 9
	double y,floor();

	if (
#if !defined(vax)&&!defined(tahoe)
		x != x ||	/* NaN */
#endif	/* !defined(vax)&&!defined(tahoe) */
		x >= L)		/* already an even integer */
		return x;
	else if (x < (double)0)
		return -floor(-x);
	else {			/* now 0 <= x < L */
		y = L+x;		/* destructive store must be forced */
		y -= L;			/* an integer, and |x-y| < 1 */
		return x > y ? y+(double)1 : y;
	}
E 9
}

I 5
D 6
#ifndef NATIONAL			/* rint() is in ./NATIONAL/support.s */
E 6
I 6
#ifndef national			/* rint() is in ./NATIONAL/support.s */
E 6
E 5
/*
 * algorithm for rint(x) in pseudo-pascal form ...
 *
 * real rint(x): real x;
 *	... delivers integer nearest x in direction of prevailing rounding
 *	... mode
 * const	L = (last consecutive integer)/2
 * 	  = 2**55; for VAX D
 * 	  = 2**52; for IEEE 754 Double
 * real	s,t;
 * begin
 * 	if x != x then return x;		... NaN
 * 	if |x| >= L then return x;		... already an integer
 * 	s := copysign(L,x);
 * 	t := x + s;				... = (x+s) rounded to integer
 * 	return t - s
 * end;
 *
 * Note: Inexact will be signaled if x is not an integer, as is
 *	customary for IEEE 754.  No other signal can be emitted.
 */
D 3
#ifdef VAX
E 3
I 3
D 6
#if (defined(VAX)||defined(TAHOE))
E 3
D 4
static long Lx[] = {0x5c00,0x0};		/* 2**55 */
E 4
I 4
#ifdef VAX
E 6
I 6
D 9
#if defined(vax)||defined(tahoe)
#ifdef vax
E 6
#define _0x(A,B)	0x/**/A/**/B
D 6
#else	/* VAX */
E 6
I 6
#else	/* vax */
E 6
#define _0x(A,B)	0x/**/B/**/A
D 6
#endif	/* VAX */
E 6
I 6
#endif	/* vax */
E 6
static long Lx[] = {_0x(0000,5c00),_0x(0000,0000)};	/* 2**55 */
E 4
#define L *(double *) Lx
D 6
#else	/* IEEE double */
E 6
I 6
#else	/* defined(vax)||defined(tahoe) */
E 6
static double L = 4503599627370496.0E0;		/* 2**52 */
D 6
#endif
E 6
I 6
#endif	/* defined(vax)||defined(tahoe) */
E 9
E 6
double
rint(x)
double x;
{
	double s,t,one = 1.0,copysign();
D 3
#ifndef VAX
E 3
I 3
D 6
#if (!defined(VAX)&&!defined(TAHOE))
E 6
I 6
#if !defined(vax)&&!defined(tahoe)
E 6
E 3
	if (x != x)				/* NaN */
		return (x);
D 6
#endif
E 6
I 6
#endif	/* !defined(vax)&&!defined(tahoe) */
E 6
	if (copysign(x,one) >= L)		/* already an integer */
	    return (x);
	s = copysign(L,x);
	t = x + s;				/* x+s rounded to integer */
	return (t - s);
}
I 5
D 6
#endif	/* NATIONAL */
E 6
I 6
#endif	/* not national */
E 6
E 5
E 1
