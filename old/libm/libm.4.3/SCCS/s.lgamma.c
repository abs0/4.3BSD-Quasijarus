h16617
s 00013/00021/00128
d D 4.4 85/09/11 18:05:37 mckusick 5 3
c new from Kahan
e
s 00010/00018/00131
d R 4.4 85/08/21 10:21:30 miriam 4 3
c Revision by Prof. Kahan.
e
s 00019/00011/00130
d D 4.3 85/06/19 10:11:51 miriam 3 2
c uses floor() instead of drem() to identify even/odd intervals, fix from
c kahan.
e
s 00031/00008/00110
d D 4.2 85/06/06 15:23:19 miriam 2 1
c modified neg() to make it work with the new sin().  now it'll return the
c reserved operand on the VAX if the argument is a negative integer or 0.
c added some comments. (from zliu/kahan)
e
s 00118/00000/00000
d D 4.1 82/12/25 10:46:42 sam 1 0
c date and time created 82/12/25 10:46:42 by sam
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
D 5
/*	%W%	%G% */
E 5
I 5
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 5
E 2

/*
D 5
	C program for floating point log gamma function
E 5
I 5
	C program for floating point log Gamma function
E 5

D 5
	gamma(x) computes the log of the absolute
	value of the gamma function.
	The sign of the gamma function is returned in the
E 5
I 5
	lgamma(x) computes the log of the absolute
	value of the Gamma function.
	The sign of the Gamma function is returned in the
E 5
	external quantity signgam.

	The coefficients for expansion around zero
	are #5243 from Hart & Cheney; for expansion
	around infinity they are #5404.

D 2
	Calls log and sin.
E 2
I 2
D 3
	Calls log, drem and sin.
E 3
I 3
	Calls log, floor and sin.
E 3
E 2
*/

D 5
#include <errno.h>
E 5
#include <math.h>
I 2
#ifdef VAX
D 5
static long	NaN_[] = {0x8000, 0x0};
#define NaN	(*(double *) NaN_)
E 5
I 5
#include <errno.h>
E 5
#endif
E 2
D 5

I 2

E 2
int	errno;
E 5
int	signgam = 0;
D 2
static double goobie	= 0.9189385332046727417803297;
E 2
I 2
static double goobie	= 0.9189385332046727417803297;	/* log(2*pi)/2 */
E 2
static double pi	= 3.1415926535897932384626434;

#define M 6
#define N 8
static double p1[] = {
	0.83333333333333101837e-1,
	-.277777777735865004e-2,
	0.793650576493454e-3,
	-.5951896861197e-3,
	0.83645878922e-3,
	-.1633436431e-2,
};
static double p2[] = {
	-.42353689509744089647e5,
	-.20886861789269887364e5,
	-.87627102978521489560e4,
	-.20085274013072791214e4,
	-.43933044406002567613e3,
	-.50108693752970953015e2,
	-.67449507245925289918e1,
	0.0,
};
static double q2[] = {
	-.42353689509744090010e5,
	-.29803853309256649932e4,
	0.99403074150827709015e4,
	-.15286072737795220248e4,
	-.49902852662143904834e3,
	0.18949823415702801641e3,
	-.23081551524580124562e2,
	0.10000000000000000000e1,
};

double
D 5
gamma(arg)
E 5
I 5
lgamma(arg)
E 5
double arg;
{
	double log(), pos(), neg(), asym();

	signgam = 1.;
	if(arg <= 0.) return(neg(arg));
	if(arg > 8.) return(asym(arg));
	return(log(pos(arg)));
}

static double
asym(arg)
double arg;
{
	double log();
	double n, argsq;
	int i;

	argsq = 1./(arg*arg);
	for(n=0,i=M-1; i>=0; i--){
		n = n*argsq + p1[i];
	}
	return((arg-.5)*log(arg) - arg + goobie + n/arg);
}

static double
neg(arg)
double arg;
{
D 3
	double temp;
D 2
	double log(), sin(), pos();
E 2
I 2
	double log(), sin(), drem(), pos();
E 3
I 3
	double t;
	double log(), sin(), floor(), pos();
E 3
E 2

	arg = -arg;
D 2
	temp = sin(pi*arg);
E 2
I 2
     /*
      * to see if arg were a true integer, the old code used the
      * mathematically correct observation:
      * sin(n*pi) = 0 <=> n is an integer.
      * but in finite precision arithmetic, sin(n*PI) will NEVER
      * be zero simply because n*PI is a rational number.  hence
      *	it failed to work with our newer, more accurate sin()
      * which uses true pi to do the argument reduction...
      *	temp = sin(pi*arg);
      */
D 3
	temp = drem(arg, 1.e0);
E 2
	if(temp == 0.) {
E 3
I 3
	t = floor(arg);
	if (arg - t  > 0.5e0)
D 5
	    t += 1.e0;			/* t := integer nearest arg */
#if !(IEEE|NATIONAL)
	if(arg == t) {
E 3
		errno = EDOM;
E 5
I 5
	    t += 1.e0;				/* t := integer nearest arg */
E 5
I 2
#ifdef VAX
D 5
		return (NaN);
#else
E 2
		return(HUGE);
I 2
#endif
E 5
I 5
	if (arg == t) {
	    extern double infnan();
	    return(infnan(ERANGE));		/* +INF */
E 5
E 2
	}
I 3
#endif
E 3
D 2
	if(temp < 0.) temp = -temp;
	else signgam = -1;
	return(-log(arg*pos(arg)*temp/pi));
E 2
I 2
D 5

E 5
D 3
	temp = drem(arg, 2.e0);
	if (temp < 0.)
	    temp = -temp;
	else
	    signgam = -1;
	return(-log(arg*pos(arg)*sin(pi*temp)/pi));
E 3
I 3
	signgam = (int) (t - 2*floor(t/2));	/* signgam =  1 if t was odd, */
						/*            0 if t was even */
	signgam = signgam - 1 + signgam;	/* signgam =  1 if t was odd, */
						/*           -1 if t was even */
	t = arg - t;				/*  -0.5 <= t <= 0.5 */
	if (t < 0.e0) {
	    t = -t;
	    signgam = -signgam;
	}
	return(-log(arg*pos(arg)*sin(pi*t)/pi));
E 3
E 2
}

static double
pos(arg)
double arg;
{
	double n, d, s;
	register i;

	if(arg < 2.) return(pos(arg+1.)/arg);
	if(arg > 3.) return((arg-1.)*pos(arg-1.));

	s = arg - 2.;
	for(n=0,d=0,i=N-1; i>=0; i--){
		n = n*s + p2[i];
		d = d*s + q2[i];
	}
	return(n/d);
}
E 1
