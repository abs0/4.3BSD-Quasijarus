h03458
s 00019/00017/00130
d D 1.2 85/08/21 10:39:44 miriam 2 1
c Revision by Prof. Kahan.
e
s 00147/00000/00000
d D 1.1 85/05/23 15:20:29 miriam 1 0
c date and time created 85/05/23 15:20:29 by miriam
e
u
U
t
From Prof. Kahan at UC at Berkeley
T
I 1
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

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

D 2
/* E(X)
E 2
I 2
/* EXPM1(X)
E 2
 * RETURN THE EXPONENTIAL OF X MINUS ONE
 * DOUBLE PRECISION (IEEE 53 BITS, VAX D FORMAT 56 BITS)
 * CODED IN C BY K.C. NG, 1/19/85; 
 * REVISED BY K.C. NG on 2/6/85, 3/7/85, 3/21/85, 4/16/85.
 *
 * Required system supported functions:
 *	scalb(x,n)	
 *	copysign(x,y)	
 *	finite(x)
 *
 * Kernel function:
 *	exp__E(x,c)
 *
 * Method:
 *	1. Argument Reduction: given the input x, find r and integer k such 
 *	   that
 *	                   x = k*ln2 + r,  |r| <= 0.5*ln2 .  
 *	   r will be represented as r := z+c for better accuracy.
 *
D 2
 *	2. Compute E(r)=exp(r)-1 by 
E 2
I 2
 *	2. Compute EXPM1(r)=exp(r)-1 by 
E 2
 *
D 2
 *			E(r=z+c) := z + exp__E(z,c)
E 2
I 2
 *			EXPM1(r=z+c) := z + exp__E(z,c)
E 2
 *
D 2
 *	3. E(x) =  2^k * ( E(r) + 1-2^-k ).
E 2
I 2
 *	3. EXPM1(x) =  2^k * ( EXPM1(r) + 1-2^-k ).
E 2
 *
 * 	Remarks: 
 *	   1. When k=1 and z < -0.25, we use the following formula for
 *	      better accuracy:
D 2
 *			E(x) = 2 * ( (z+0.5) + exp__E(z,c) )
E 2
I 2
 *			EXPM1(x) = 2 * ( (z+0.5) + exp__E(z,c) )
E 2
 *	   2. To avoid rounding error in 1-2^-k where k is large, we use
D 2
 *			E(x) = 2^k * { [z+(exp__E(z,c)-2^-k )] + 1 }
E 2
I 2
 *			EXPM1(x) = 2^k * { [z+(exp__E(z,c)-2^-k )] + 1 }
E 2
 *	      when k>56. 
 *
 * Special cases:
D 2
 *	E(INF) is INF, E(NAN) is NAN;
 *	E(-INF)= -1;
 *	for finite argument, only E(0)=0 is exact.
E 2
I 2
 *	EXPM1(INF) is INF, EXPM1(NaN) is NaN;
 *	EXPM1(-INF)= -1;
 *	for finite argument, only EXPM1(0)=0 is exact.
E 2
 *
 * Accuracy:
D 2
 *	E(x) returns the exact (exp(x)-1) nearly rounded. In a test run with
E 2
I 2
 *	EXPM1(x) returns the exact (exp(x)-1) nearly rounded. In a test run with
E 2
 *	1,166,000 random arguments on a VAX, the maximum observed error was
 *	.872 ulps (units of the last place).
 *
 * Constants:
 * The hexadecimal values are the intended ones for the following constants.
 * The decimal values may be used, provided that the compiler will convert
 * from decimal to binary accurately enough to produce the hexadecimal values
 * shown.
 */

#ifdef VAX	/* VAX D format */
/* double static */
/* ln2hi  =  6.9314718055829871446E-1    , Hex  2^  0   *  .B17217F7D00000 */
/* ln2lo  =  1.6465949582897081279E-12   , Hex  2^-39   *  .E7BCD5E4F1D9CC */
/* lnhuge =  9.4961163736712506989E1     , Hex  2^  7   *  .BDEC1DA73E9010 */
/* invln2 =  1.4426950408889634148E0     ; Hex  2^  1   *  .B8AA3B295C17F1 */
static long     ln2hix[] = { 0x72174031, 0x0000f7d0};
static long     ln2lox[] = { 0xbcd52ce7, 0xd9cce4f1};
static long    lnhugex[] = { 0xec1d43bd, 0x9010a73e};
static long    invln2x[] = { 0xaa3b40b8, 0x17f1295c};
#define    ln2hi    (*(double*)ln2hix)
#define    ln2lo    (*(double*)ln2lox)
#define   lnhuge    (*(double*)lnhugex)
#define   invln2    (*(double*)invln2x)
D 2
#else		/* IEEE double format */
E 2
I 2
#else	/* IEEE double */
E 2
double static
ln2hi  =  6.9314718036912381649E-1    , /*Hex  2^ -1   *  1.62E42FEE00000 */
ln2lo  =  1.9082149292705877000E-10   , /*Hex  2^-33   *  1.A39EF35793C76 */
lnhuge =  7.1602103751842355450E2     , /*Hex  2^  9   *  1.6602B15B7ECF2 */
invln2 =  1.4426950408889633870E0     ; /*Hex  2^  0   *  1.71547652B82FE */
#endif

D 2
double E(x)
E 2
I 2
double expm1(x)
E 2
double x;
{
	double static one=1.0, half=1.0/2.0; 
	double scalb(), copysign(), exp__E(), z,hi,lo,c;
	int k,finite();
#ifdef VAX
	static prec=56;
D 2
#else  /* IEEE */
E 2
I 2
#else	/* IEEE double */
E 2
	static prec=53;
#endif
D 2
	if(x!=x) return(x);	/* x is NAN */
E 2
I 2
#ifndef VAX
	if(x!=x) return(x);	/* x is NaN */
#endif
E 2

	if( x <= lnhuge ) {
		if( x >= -40.0 ) {

		    /* argument reduction : x - k*ln2 */
			k= invln2 *x+copysign(0.5,x);	/* k=NINT(x/ln2) */
			hi=x-k*ln2hi ; 
			z=hi-(lo=k*ln2lo);
			c=(hi-z)-lo;

			if(k==0) return(z+exp__E(z,c));
			if(k==1)
			    if(z< -0.25) 
				{x=z+half;x +=exp__E(z,c); return(x+x);}
			    else
				{z+=exp__E(z,c); x=half+z; return(x+x);}
		    /* end of k=1 */

			else {
			    if(k<=prec)
			      { x=one-scalb(one,-k); z += exp__E(z,c);}
			    else if(k<100)
			      { x = exp__E(z,c)-scalb(one,-k); x+=z; z=one;}
			    else 
			      { x = exp__E(z,c)+z; z=one;}

			    return (scalb(x+z,k));  
			}
		}
		/* end of x > lnunfl */

		else 
D 2
		     /* E(-big#) rounded to -1 (inexact) */
E 2
I 2
		     /* expm1(-big#) rounded to -1 (inexact) */
E 2
		     if(finite(x))  
			 { ln2hi+ln2lo; return(-one);}

D 2
		     /* E(-INF) is -1 */
E 2
I 2
		     /* expm1(-INF) is -1 */
E 2
		     else return(-one);
	}
	/* end of x < lnhuge */

	else 
D 2
	/*  E(INF) is INF, E(+big#) overflows to INF */
E 2
I 2
	/*  expm1(INF) is INF, expm1(+big#) overflows to INF */
E 2
	    return( finite(x) ?  scalb(one,5000) : x);
}
E 1
