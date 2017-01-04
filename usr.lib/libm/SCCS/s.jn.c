h46203
s 00008/00003/00115
d D 5.2 88/04/29 12:19:48 bostic 6 5
c add Berkeley copyright; NOTE: this code is AT&T derived!
e
s 00000/00000/00118
d D 5.1 87/11/30 18:34:02 bostic 5 4
c tahoe release
e
s 00007/00007/00111
d D 1.4 87/07/13 19:20:39 zliu 4 3
c clean-ups.
e
s 00002/00002/00116
d D 1.3 87/07/07 01:31:56 zliu 3 2
c first shot at TAHOE.
e
s 00002/00001/00116
d D 1.2 85/09/11 23:54:16 elefunt 2 1
c 4.3BSD version dated 09/11/85.
e
s 00117/00000/00000
d D 1.1 85/09/06 17:52:56 zliu 1 0
c date and time created 85/09/06 17:52:56 by zliu
e
u
U
t
T
I 6
/*
 * Copyright (c) 1985 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 6
I 1
#ifndef lint
D 2
static char sccsid[] = "%W% (ELEFUNT) %G%";
E 2
I 2
D 6
static char sccsid[] =
"%Z%%M%	4.2 (Berkeley) 8/21/85; %I% (ucb.elefunt) %G%";
E 2
D 4
#endif not lint
E 4
I 4
#endif	/* not lint */
E 6
I 6
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 6
E 4

/*
	floating point Bessel's function of
	the first and second kinds and of
	integer order.

	int n;
	double x;
	jn(n,x);

	returns the value of Jn(x) for all
	integer values of n and all real values
	of x.

	There are no error returns.
	Calls j0, j1.

	For n=0, j0(x) is called,
	for n=1, j1(x) is called,
	for n<x, forward recursion us used starting
	from values of j0(x) and j1(x).
	for n>x, a continued fraction approximation to
	j(n,x)/j(n-1,x) is evaluated and then backward
	recursion is used starting from a supposed value
	for j(n,x). The resulting value of j(0,x) is
	compared with the actual value to correct the
	supposed value of j(n,x).

	yn(n,x) is similar in all respects, except
	that forward recursion is used for all
	values of n>1.
*/

#include <math.h>
D 3
#ifdef VAX
E 3
I 3
D 4
#if defined(VAX)
E 4
I 4
#if defined(vax)||defined(tahoe)
E 4
E 3
#include <errno.h>
D 4
#else	/* IEEE double */
E 4
I 4
#else	/* defined(vax)||defined(tahoe) */
E 4
static double zero = 0.e0;
D 4
#endif
E 4
I 4
#endif	/* defined(vax)||defined(tahoe) */
E 4

double
jn(n,x) int n; double x;{
	int i;
	double a, b, temp;
	double xsq, t;
	double j0(), j1();

	if(n<0){
		n = -n;
		x = -x;
	}
	if(n==0) return(j0(x));
	if(n==1) return(j1(x));
	if(x == 0.) return(0.);
	if(n>x) goto recurs;

	a = j0(x);
	b = j1(x);
	for(i=1;i<n;i++){
		temp = b;
		b = (2.*i/x)*b - a;
		a = temp;
	}
	return(b);

recurs:
	xsq = x*x;
	for(t=0,i=n+16;i>n;i--){
		t = xsq/(2.*i - t);
	}
	t = x/(2.*n-t);

	a = t;
	b = 1;
	for(i=n-1;i>0;i--){
		temp = b;
		b = (2.*i/x)*b - a;
		a = temp;
	}
	return(t*j0(x)/b);
}

double
yn(n,x) int n; double x;{
	int i;
	int sign;
	double a, b, temp;
	double y0(), y1();

	if (x <= 0) {
D 3
#ifdef VAX
E 3
I 3
D 4
#if defined(VAX)
E 4
I 4
#if defined(vax)||defined(tahoe)
E 4
E 3
		extern double infnan();
		return(infnan(EDOM));	/* NaN */
D 4
#else	/* IEEE double */
E 4
I 4
#else	/* defined(vax)||defined(tahoe) */
E 4
		return(zero/zero);	/* IEEE machines: invalid operation */
D 4
#endif
E 4
I 4
#endif	/* defined(vax)||defined(tahoe) */
E 4
	}
	sign = 1;
	if(n<0){
		n = -n;
		if(n%2 == 1) sign = -1;
	}
	if(n==0) return(y0(x));
	if(n==1) return(sign*y1(x));

	a = y0(x);
	b = y1(x);
	for(i=1;i<n;i++){
		temp = b;
		b = (2.*i/x)*b - a;
		a = temp;
	}
	return(sign*b);
}
E 1
