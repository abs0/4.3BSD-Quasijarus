h38566
s 00015/00013/00087
d D 4.3 85/08/21 10:36:52 miriam 3 2
c Revision by Prof. Kahan.
e
s 00091/00060/00009
d D 4.2 85/05/23 15:04:42 miriam 2 1
c From Prof. Kahan
e
s 00069/00000/00000
d D 4.1 82/12/25 10:46:53 sam 1 0
c date and time created 82/12/25 10:46:53 by sam
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
	sinh(arg) returns the hyperbolic sine of its floating-
	point argument.
E 2
I 2
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 2

D 2
	The exponential function is called for arguments
	greater in magnitude than 0.5.
E 2
I 2
/* SINH(X)
 * RETURN THE HYPERBOLIC SINE OF X
 * DOUBLE PRECISION (VAX D format 56 bits, IEEE DOUBLE 53 BITS)
 * CODED IN C BY K.C. NG, 1/8/85; 
D 3
 * REIVESD BY K.C. NG on 2/8/85, 3/7/85, 3/24/85, 4/16/85.
E 3
I 3
 * REVISED BY K.C. NG on 2/8/85, 3/7/85, 3/24/85, 4/16/85.
E 3
 *
 * Required system supported functions :
 *	copysign(x,y)
 *	scalb(x,N)
 *
 * Required kernel functions:
D 3
 *	E(x)	...return exp(x)-1
E 3
I 3
 *	expm1(x)	...return exp(x)-1
E 3
 *
 * Method :
 *	1. reduce x to non-negative by sinh(-x) = - sinh(x).
 *	2. 
 *
D 3
 *		                                     E(x) + E(x)/(E(x)+1)
 *	    0        <= x <= lnovfl    :  sinh(x) := ----------------------
 *			       			              2
 *	    lnovfl   <= x <= lnovfl+ln2:  sinh(x) := E(x)/2 (avoid overflow)
 *	    lnovfl+ln2 <  x <  INF     :  overflow to INF
E 3
I 3
 *	                                      expm1(x) + expm1(x)/(expm1(x)+1)
 *	    0 <= x <= lnovfl     : sinh(x) := --------------------------------
 *			       		                      2
 *     lnovfl <= x <= lnovfl+ln2 : sinh(x) := expm1(x)/2 (avoid overflow)
 * lnovfl+ln2 <  x <  INF        :  overflow to INF
E 3
 *	
 *
 * Special cases:
D 3
 *	sinh(x) is x if x is +INF, -INF, or NAN.
E 3
I 3
 *	sinh(x) is x if x is +INF, -INF, or NaN.
E 3
 *	only sinh(0)=0 is exact for finite argument.
 *
 * Accuracy:
 *	sinh(x) returns the exact hyperbolic sine of x nearly rounded. In
 *	a test run with 1,024,000 random arguments on a VAX, the maximum
 *	observed error was 1.93 ulps (units in the last place).
 *
 * Constants:
 * The hexadecimal values are the intended ones for the following constants.
 * The decimal values may be used, provided that the compiler will convert
 * from decimal to binary accurately enough to produce the hexadecimal values
 * shown.
 */
#ifdef VAX
/* double static */
/* mln2hi =  8.8029691931113054792E1     , Hex  2^  7   *  .B00F33C7E22BDB */
/* mln2lo = -4.9650192275318476525E-16   , Hex  2^-50   * -.8F1B60279E582A */
/* lnovfl =  8.8029691931113053016E1     ; Hex  2^  7   *  .B00F33C7E22BDA */
static long    mln2hix[] = { 0x0f3343b0, 0x2bdbc7e2};
static long    mln2lox[] = { 0x1b60a70f, 0x582a279e};
static long    lnovflx[] = { 0x0f3343b0, 0x2bdac7e2};
#define   mln2hi    (*(double*)mln2hix)
#define   mln2lo    (*(double*)mln2lox)
#define   lnovfl    (*(double*)lnovflx)
#else	/* IEEE double */
double static 
mln2hi =  7.0978271289338397310E2     , /*Hex  2^ 10   *  1.62E42FEFA39EF */
mln2lo =  2.3747039373786107478E-14   , /*Hex  2^-45   *  1.ABC9E3B39803F */
lnovfl =  7.0978271289338397310E2     ; /*Hex  2^  9   *  1.62E42FEFA39EF */
#endif
E 2

D 2
	A series is used for arguments smaller in magnitude than 0.5.
	The coefficients are #2029 from Hart & Cheney. (20.36D)
E 2
I 2
#ifdef VAX
static max = 126                      ;
#else	/* IEEE double */
static max = 1023                     ;
#endif
E 2

D 2
	cosh(arg) is computed from the exponential function for
	all arguments.
*/
E 2

D 2
double	exp();

static double p0  = -0.6307673640497716991184787251e+6;
static double p1  = -0.8991272022039509355398013511e+5;
static double p2  = -0.2894211355989563807284660366e+4;
static double p3  = -0.2630563213397497062819489e+2;
static double q0  = -0.6307673640497716991212077277e+6;
static double q1   = 0.1521517378790019070696485176e+5;
static double q2  = -0.173678953558233699533450911e+3;

double
sinh(arg)
double arg;
E 2
I 2
double sinh(x)
double x;
E 2
{
D 2
	double temp, argsq;
	register sign;
E 2
I 2
	static double  one=1.0, half=1.0/2.0 ;
D 3
	double E(), t, scalb(), copysign(), sign;
	if(x!=x) return(x);
E 3
I 3
	double expm1(), t, scalb(), copysign(), sign;
#ifndef VAX
	if(x!=x) return(x);	/* x is NaN */
#endif
E 3
	sign=copysign(one,x);
	x=copysign(x,one);
	if(x<lnovfl)
D 3
	    {t=E(x); return(copysign((t+t/(one+t))*half,sign));}
E 3
I 3
	    {t=expm1(x); return(copysign((t+t/(one+t))*half,sign));}
E 3
E 2

D 2
	sign = 1;
	if(arg < 0) {
		arg = - arg;
		sign = -1;
	}
E 2
I 2
	else if(x <= lnovfl+0.7)
		/* subtract x by ln(2^(max+1)) and return 2^max*exp(x) 
	    		to avoid unnecessary overflow */
D 3
	    return(copysign(scalb(one+E((x-mln2hi)-mln2lo),max),sign));
E 3
I 3
	    return(copysign(scalb(one+expm1((x-mln2hi)-mln2lo),max),sign));
E 3
E 2

D 2
	if(arg > 21.) {
		temp = exp(arg)/2;
		if (sign>0)
			return(temp);
		else
			return(-temp);
	}

	if(arg > 0.5) {
		return(sign*(exp(arg) - exp(-arg))/2);
	}

	argsq = arg*arg;
	temp = (((p3*argsq+p2)*argsq+p1)*argsq+p0)*arg;
	temp /= (((argsq+q2)*argsq+q1)*argsq+q0);
	return(sign*temp);
}

double
cosh(arg)
double arg;
{
	if(arg < 0)
		arg = - arg;
	if(arg > 21.) {
		return(exp(arg)/2);
	}

	return((exp(arg) + exp(-arg))/2);
E 2
I 2
	else  /* sinh(+-INF) = +-INF, sinh(+-big no.) overflow to +-INF */
D 3
	    return( E(x)*sign );
E 3
I 3
	    return( expm1(x)*sign );
E 3
E 2
}
E 1
