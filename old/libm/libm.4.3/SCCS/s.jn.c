h36272
s 00013/00005/00104
d D 4.2 85/08/21 10:31:29 miriam 2 1
c Revision by Prof. Kahan.
e
s 00109/00000/00000
d D 4.1 82/12/25 10:46:49 sam 1 0
c date and time created 82/12/25 10:46:49 by sam
e
u
U
t
T
I 1
D 2
/*	%W%	%G%	*/
E 2
I 2
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 2

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
I 2
#ifdef VAX
E 2
#include <errno.h>
I 2
#else	/* IEEE double */
static double zero = 0.e0;
#endif
E 2

D 2
int	errno;

E 2
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
D 2
		errno = EDOM;
		return(-HUGE);
E 2
I 2
#ifdef VAX
		extern double infnan();
		return(infnan(EDOM));	/* NaN */
#else	/* IEEE double */
		return(zero/zero);	/* IEEE machines: invalid operation */
#endif
E 2
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
