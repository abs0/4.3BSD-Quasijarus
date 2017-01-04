h47336
s 00044/00001/00031
d D 4.2 85/09/11 17:56:50 mckusick 2 1
c new from Kahan
e
s 00032/00000/00000
d D 4.1 82/12/25 10:46:41 sam 1 0
c date and time created 82/12/25 10:46:41 by sam
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
/*	%W%	%G% */
E 2

/*
 * floor and ceil-- greatest integer <= arg
 * (resp least >=)
 */

double	modf();

double
floor(d)
double d;
{
	double fract;

	if (d<0.0) {
		d = -d;
		fract = modf(d, &d);
		if (fract != 0.0)
			d += 1;
		d = -d;
	} else
		modf(d, &d);
	return(d);
}

double
ceil(d)
double d;
{
	return(-floor(-d));
I 2
}

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
#ifdef VAX
static long Lx[] = {0x5c00,0x0};		/* 2**55 */
#define L *(double *) Lx
#else	/* IEEE double */
static double L = 4503599627370496.0E0;		/* 2**52 */
#endif
double
rint(x)
double x;
{
	double s,t,one = 1.0,copysign();
#ifndef VAX
	if (x != x)				/* NaN */
		return (x);
#endif
	if (copysign(x,one) >= L)		/* already an integer */
	    return (x);
	s = copysign(L,x);
	t = x + s;				/* x+s rounded to integer */
	return (t - s);
E 2
}
E 1
