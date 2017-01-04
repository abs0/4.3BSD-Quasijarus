h12712
s 00014/00012/00132
d D 4.5 85/08/21 10:32:33 miriam 5 4
c Revision by Prof. Kahan.
e
s 00007/00001/00137
d D 4.4 85/06/03 16:08:36 miriam 4 3
c Return reserve operand for vax
e
s 00125/00051/00013
d D 4.3 85/05/23 14:50:02 miriam 3 2
c From Prof. Kahan
e
s 00001/00001/00063
d D 4.2 85/01/22 16:34:36 ralph 2 1
c fix constant value.
e
s 00064/00000/00000
d D 4.1 82/12/25 10:46:50 sam 1 0
c date and time created 82/12/25 10:46:50 by sam
e
u
U
t
T
I 1
D 3
/*	%W%	%G%	*/
E 3
I 3
/* 
 * Copyright (c) 1985 Regents of the University of California.
 * 
 * Use and reproduction of this software are granted  in  accordance  with
 * the terms and conditions specified in  the  Berkeley  Software  License
 * Agreement (in particular, this entails acknowledgement of the programs'
 * source, and inclusion of this notice) with the additional understanding
 * that  all  recipients  should regard themselves as participants  in  an
 * ongoing  research  project and hence should  feel  obligated  to report
 * their  experiences (good or bad) with these elementary function  codes,
 * using "sendbug 4bsd-bugs@BERKELEY", to the authors.
 */
E 3

D 3
/*
	log returns the natural logarithm of its floating
	point argument.
E 3
I 3
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 3

D 3
	The coefficients are #2705 from Hart & Cheney. (19.38D)
E 3
I 3
/* LOG(X)
 * RETURN THE LOGARITHM OF x 
 * DOUBLE PRECISION (VAX D FORMAT 56 bits or IEEE DOUBLE 53 BITS)
 * CODED IN C BY K.C. NG, 1/19/85;
 * REVISED BY K.C. NG on 2/7/85, 3/7/85, 3/24/85, 4/16/85.
 *
 * Required system supported functions:
 *	scalb(x,n)
 *	copysign(x,y)
 *	logb(x)	
 *	finite(x)
 *
 * Required kernel function:
 *	log__L(z) 
 *
 * Method :
 *	1. Argument Reduction: find k and f such that 
 *			x = 2^k * (1+f), 
 *	   where  sqrt(2)/2 < 1+f < sqrt(2) .
 *
 *	2. Let s = f/(2+f) ; based on log(1+f) = log(1+s) - log(1-s)
 *		 = 2s + 2/3 s**3 + 2/5 s**5 + .....,
 *	   log(1+f) is computed by
 *
 *	     		log(1+f) = 2s + s*log__L(s*s)
 *	   where
 *		log__L(z) = z*(L1 + z*(L2 + z*(... (L6 + z*L7)...)))
 *
 *	   See log__L() for the values of the coefficients.
 *
 *	3. Finally,  log(x) = k*ln2 + log(1+f).  (Here n*ln2 will be stored
 *	   in two floating point number: n*ln2hi + n*ln2lo, n*ln2hi is exact
 *	   since the last 20 bits of ln2hi is 0.)
 *
 * Special cases:
D 5
 *	log(x) is NAN with signal if x < 0 (including -INF) ; 
E 5
I 5
 *	log(x) is NaN with signal if x < 0 (including -INF) ; 
E 5
 *	log(+INF) is +INF; log(0) is -INF with signal;
D 5
 *	log(NAN) is that NAN with no signal.
E 5
I 5
 *	log(NaN) is that NaN with no signal.
E 5
 *
 * Accuracy:
 *	log(x) returns the exact log(x) nearly rounded. In a test run with
 *	1,536,000 random arguments on a VAX, the maximum observed error was
 *	.826 ulps (units in the last place).
 *
 * Constants:
 * The hexadecimal values are the intended ones for the following constants.
 * The decimal values may be used, provided that the compiler will convert
 * from decimal to binary accurately enough to produce the hexadecimal values
 * shown.
 */
E 3

D 3
	It calls frexp.
*/

E 3
I 3
#ifdef VAX	/* VAX D format */
E 3
#include <errno.h>
D 3
#include <math.h>
E 3
I 3
D 5
extern errno;
I 4
static long	NaN_[] = {0x8000, 0x0};
#define NaN	(*(double *) NaN_)
E 5

E 4
/* double static */
/* ln2hi  =  6.9314718055829871446E-1    , Hex  2^  0   *  .B17217F7D00000 */
/* ln2lo  =  1.6465949582897081279E-12   , Hex  2^-39   *  .E7BCD5E4F1D9CC */
/* sqrt2  =  1.4142135623730950622E0     ; Hex  2^  1   *  .B504F333F9DE65 */
static long     ln2hix[] = { 0x72174031, 0x0000f7d0};
static long     ln2lox[] = { 0xbcd52ce7, 0xd9cce4f1};
static long     sqrt2x[] = { 0x04f340b5, 0xde6533f9};
#define    ln2hi    (*(double*)ln2hix)
#define    ln2lo    (*(double*)ln2lox)
#define    sqrt2    (*(double*)sqrt2x)
D 5
#else		/* IEEE double format */
E 5
I 5
#else	/* IEEE double */
E 5
double static
ln2hi  =  6.9314718036912381649E-1    , /*Hex  2^ -1   *  1.62E42FEE00000 */
ln2lo  =  1.9082149292705877000E-10   , /*Hex  2^-33   *  1.A39EF35793C76 */
sqrt2  =  1.4142135623730951455E0     ; /*Hex  2^  0   *  1.6A09E667F3BCD */
#endif
E 3

D 3
int	errno;
double	frexp();
static double	log2	= 0.693147180559945309e0;
static double	ln10	= 2.302585092994045684;
static double	sqrto2	= 0.707106781186547524e0;
static double	p0	= -.240139179559210510e2;
static double	p1	= 0.309572928215376501e2;
D 2
static double	p2	= -.963769093368686593e1;
E 2
I 2
static double	p2	= -.963769093377840513e1;
E 2
static double	p3	= 0.421087371217979714e0;
static double	q0	= -.120069589779605255e2;
static double	q1	= 0.194809660700889731e2;
static double	q2	= -.891110902798312337e1;

double
log(arg)
double arg;
E 3
I 3
double log(x)
double x;
E 3
{
D 3
	double x,z, zsq, temp;
	int exp;
E 3
I 3
	static double zero=0.0, negone= -1.0, half=1.0/2.0;
	double logb(),scalb(),copysign(),log__L(),s,z,t;
	int k,n,finite();
E 3

D 3
	if(arg <= 0.) {
E 3
I 3
D 5
	if(x!=x) return(x);
E 5
I 5
#ifndef VAX
	if(x!=x) return(x);	/* x is NaN */
#endif
E 5
	if(finite(x)) {
	   if( x > zero ) {

	   /* argument reduction */
	      k=logb(x);   x=scalb(x,-k);
	      if(k == -1022) /* subnormal no. */
		   {n=logb(x); x=scalb(x,-n); k+=n;} 
	      if(x >= sqrt2 ) {k += 1; x *= half;}
	      x += negone ;

	   /* compute log(1+x)  */
              s=x/(2+x); t=x*x*half;
	      z=k*ln2lo+s*(t+log__L(s*s));
	      x += (z - t) ;

	      return(k*ln2hi+x);
	   }
	/* end of if (x > zero) */

	   else {
#ifdef VAX
E 3
D 5
		errno = EDOM;
D 3
		return(-HUGE);
E 3
I 3
D 4
#endif
E 4
I 4
		return (NaN);
#else
E 5
I 5
		extern double infnan();
		if ( x == zero )
		    return (infnan(-ERANGE));	/* -INF */
		else
		    return (infnan(EDOM));	/* NaN */
#else	/* IEEE double */
E 5
E 4
		/* zero argument, return -INF with signal */
		if ( x == zero )
		    return( negone/zero );

D 5
		/* negative argument, return NAN with signal */
E 5
I 5
		/* negative argument, return NaN with signal */
E 5
		else 
		    return ( zero / zero );
I 4
#endif
E 4
	    }
E 3
	}
D 3
	x = frexp(arg,&exp);
	while(x<0.5) {
		x = x*2;
		exp = exp-1;
	}
	if(x<sqrto2) {
		x = 2*x;
		exp = exp-1;
	}
E 3
I 3
    /* end of if (finite(x)) */
I 4
    /* NOT REACHED ifdef VAX */
E 4
E 3

D 3
	z = (x-1)/(x+1);
	zsq = z*z;
E 3
I 3
D 5
    /* log(-INF) is NAN with signal */
E 5
I 5
    /* log(-INF) is NaN with signal */
E 5
	else if (x<0) 
	    return(zero/zero);      
E 3

D 3
	temp = ((p3*zsq + p2)*zsq + p1)*zsq + p0;
	temp = temp/(((1.0*zsq + q2)*zsq + q1)*zsq + q0);
	temp = temp*z + exp*log2;
	return(temp);
}
E 3
I 3
    /* log(+INF) is +INF */
	else return(x);      
E 3

D 3
double
log10(arg)
double arg;
{

	return(log(arg)/ln10);
E 3
}
E 1
