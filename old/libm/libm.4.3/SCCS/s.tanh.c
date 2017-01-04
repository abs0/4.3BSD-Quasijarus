h20024
s 00023/00021/00056
d D 4.3 85/08/21 10:38:10 miriam 3 2
c Revision by Prof. Kahan
e
s 00069/00021/00008
d D 4.2 85/05/23 15:17:32 miriam 2 1
c From Prof. Kahan
e
s 00029/00000/00000
d D 4.1 82/12/25 10:46:56 sam 1 0
c date and time created 82/12/25 10:46:56 by sam
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
E 2

D 2
/*
	tanh(arg) computes the hyperbolic tangent of its floating
	point argument.
E 2
I 2
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 2

D 2
	sinh and cosh are called except for large arguments, which
	would cause overflow improperly.
*/
E 2
I 2
/* TANH(X)
 * RETURN THE HYPERBOLIC TANGENT OF X
 * DOUBLE PRECISION (VAX D FORMAT 56 BITS, IEEE DOUBLE 53 BITS)
 * CODED IN C BY K.C. NG, 1/8/85; 
 * REVISED BY K.C. NG on 2/8/85, 2/11/85, 3/7/85, 3/24/85.
 *
 * Required system supported functions :
 *	copysign(x,y)
 *	finite(x)
 *
 * Required kernel function:
D 3
 *	E(x)	...exp(x)-1
E 3
I 3
 *	expm1(x)	...exp(x)-1
E 3
 *
 * Method :
 *	1. reduce x to non-negative by tanh(-x) = - tanh(x).
D 3
 *	2. For appropriate values of small, 
 *					          -E(-2x)
 *	    0     <  x <=     1   :  tanh(x) := ------------
 *					         E(-2x) + 2
 *							 2
 *	    1     <= x <= 22.0    :  tanh(x) := 1 -  ------------
 *						      E(2x) + 2
 *	    22.0  <  x <= INF     :  tanh(x) := 1.
E 3
I 3
 *	2.
 *	    0      <  x <=  1.e-10 :  tanh(x) := x
 *					          -expm1(-2x)
 *	    1.e-10 <  x <=  1      :  tanh(x) := --------------
 *					         expm1(-2x) + 2
 *							  2
 *	    1      <= x <=  22.0   :  tanh(x) := 1 -  ---------------
 *						      expm1(2x) + 2
 *	    22.0   <  x <= INF     :  tanh(x) := 1.
E 3
 *
D 3
 *	Note: 22 are chosen so that fl(1.0+2/(E(2*22)+2)) == 1.
E 3
I 3
 *	Note: 22 was chosen so that fl(1.0+2/(expm1(2*22)+2)) == 1.
E 3
 *
 * Special cases:
D 3
 *	tanh(NAN) is NAN;
E 3
I 3
 *	tanh(NaN) is NaN;
E 3
 *	only tanh(0)=0 is exact for finite argument.
 *
 * Accuracy:
 *	tanh(x) returns the exact hyperbolic tangent of x nealy rounded.
 *	In a test run with 1,024,000 random arguments on a VAX, the maximum
 *	observed error was 2.22 ulps (units in the last place).
 */
E 2

D 2
double sinh(), cosh();

double
tanh(arg)
double arg;
E 2
I 2
double tanh(x)
double x;
E 2
{
D 2
	double sign;
E 2
I 2
D 3
	static double one=1.0, two=2.0;
	double E(), t,  copysign(), sign;
E 3
I 3
	static double one=1.0, two=2.0, small = 1.0e-10, big = 1.0e10;
	double expm1(), t, copysign(), sign;
E 3
	int finite();
E 2

D 2
	sign = 1.;
	if(arg < 0.){
		arg = -arg;
		sign = -1.;
	}
E 2
I 2
D 3
	if(x!=x) return(x);
E 3
I 3
#ifndef VAX
	if(x!=x) return(x);	/* x is NaN */
#endif
E 3
E 2

D 2
	if(arg > 21.)
		return(sign);
E 2
I 2
	sign=copysign(one,x);
	x=copysign(x,one);
	if(x < 22.0) 
	    if( x > one )
D 3
		return(copysign(one-two/(E(x+x)+two),sign));
	    else
		{t= -E(-(x+x)); return(copysign(t/(two-t),sign));}
E 2

E 3
I 3
		return(copysign(one-two/(expm1(x+x)+two),sign));
	    else if ( x > small )
		{t= -expm1(-(x+x)); return(copysign(t/(two-t),sign));}
	    else		/* raise the INEXACT flag for non-zero x */
		{big+x; return(copysign(x,sign));}
E 3
D 2
	return(sign*sinh(arg)/cosh(arg));
E 2
I 2
	else if(finite(x))
D 3
	    return (sign+1.0E-37); /* raise the inexact flag */

E 3
I 3
	    return (sign+1.0E-37); /* raise the INEXACT flag */
E 3
	else
	    return(sign);	/* x is +- INF */
E 2
}
I 2
D 3

E 3
E 2
E 1
