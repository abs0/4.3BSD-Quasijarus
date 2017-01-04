h41946
s 00032/00027/00194
d D 4.5 85/08/21 10:35:36 miriam 5 4
c Revision by Prof. Kahan.
e
s 00006/00001/00215
d D 4.4 85/06/03 16:10:01 miriam 4 3
c Return reserve operand for vax
e
s 00207/00032/00009
d D 4.3 85/05/23 15:01:05 miriam 3 2
c From Prof. Kahan
e
s 00002/00000/00039
d D 4.2 83/06/30 13:48:21 sam 2 1
c machine dependent
e
s 00039/00000/00000
d D 4.1 82/12/25 10:46:51 sam 1 0
c date and time created 82/12/25 10:46:51 by sam
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
	computes a^b.
	uses log and exp
*/
E 3
I 3
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 3

D 3
#include	<errno.h>
int errno;
double log(), exp();
E 3
I 3
/* POW(X,Y)  
 * RETURN X**Y 
 * DOUBLE PRECISION (VAX D format 56 bits, IEEE DOUBLE 53 BITS)
 * CODED IN C BY K.C. NG, 1/8/85; 
D 5
 * REVISED BY K.C. NG on 5/12/85.
E 5
I 5
 * REVISED BY K.C. NG on 7/10/85.
E 5
 *
 * Required system supported functions:
 *      scalb(x,n)      
 *      logb(x)         
 *	copysign(x,y)	
 *	finite(x)	
 *	drem(x,y)
 *
 * Required kernel functions:
 *	exp__E(a,c)	...return  exp(a+c) - 1 - a*a/2
 *	log__L(x)	...return  (log(1+x) - 2s)/s, s=x/(2+x) 
 *	pow_p(x,y)	...return  +(anything)**(finite non zero)
 *
 * Method
 *	1. Compute and return log(x) in three pieces:
 *		log(x) = n*ln2 + hi + lo,
 *	   where n is an integer.
 *	2. Perform y*log(x) by simulating muti-precision arithmetic and 
 *	   return the answer in three pieces:
 *		y*log(x) = m*ln2 + hi + lo,
 *	   where m is an integer.
 *	3. Return x**y = exp(y*log(x))
 *		= 2^m * ( exp(hi+lo) ).
 *
 * Special cases:
 *	(anything) ** 0  is 1 ;
 *	(anything) ** 1  is itself;
D 5
 *	(anything) ** NAN is NAN;
 *	NAN ** (anything except 0) is NAN;
E 5
I 5
 *	(anything) ** NaN is NaN;
 *	NaN ** (anything except 0) is NaN;
E 5
 *	+-(anything > 1) ** +INF is +INF;
 *	+-(anything > 1) ** -INF is +0;
 *	+-(anything < 1) ** +INF is +0;
 *	+-(anything < 1) ** -INF is +INF;
D 5
 *	+-1 ** +-INF is NAN and signal INVALID;
 *	+0 ** +(anything except 0, NAN)  is +0;
 *	-0 ** +(anything except 0, NAN, odd integer)  is +0;
 *	+0 ** -(anything except 0, NAN)  is +INF and signal DIV-BY-ZERO;
 *	-0 ** -(anything except 0, NAN, odd integer)  is +INF with signal;
E 5
I 5
 *	+-1 ** +-INF is NaN and signal INVALID;
 *	+0 ** +(anything except 0, NaN)  is +0;
 *	-0 ** +(anything except 0, NaN, odd integer)  is +0;
 *	+0 ** -(anything except 0, NaN)  is +INF and signal DIV-BY-ZERO;
 *	-0 ** -(anything except 0, NaN, odd integer)  is +INF with signal;
E 5
 *	-0 ** (odd integer) = -( +0 ** (odd integer) );
D 5
 *	+INF ** +(anything except 0,NAN) is +INF;
 *	+INF ** -(anything except 0,NAN) is +0;
E 5
I 5
 *	+INF ** +(anything except 0,NaN) is +INF;
 *	+INF ** -(anything except 0,NaN) is +0;
E 5
 *	-INF ** (odd integer) = -( +INF ** (odd integer) );
 *	-INF ** (even integer) = ( +INF ** (even integer) );
D 5
 *	-INF ** -(anything except integer,NAN) is NAN with signal;
E 5
I 5
 *	-INF ** -(anything except integer,NaN) is NaN with signal;
E 5
 *	-(x=anything) ** (k=integer) is (-1)**k * (x ** k);
D 5
 *	-(anything except 0) ** (non-integer) is NAN with signal;
E 5
I 5
 *	-(anything except 0) ** (non-integer) is NaN with signal;
E 5
 *
 * Accuracy:
 *	pow(x,y) returns x**y nearly rounded. In particular, on a SUN, a VAX,
 *	and a Zilog Z8000,
 *			pow(integer,integer)
 *	always returns the correct integer provided it is representable.
 *	In a test run with 100,000 random arguments with 0 < x, y < 20.0
 *	on a VAX, the maximum observed error was 1.79 ulps (units in the 
 *	last place).
 *
 * Constants :
 * The hexadecimal values are the intended ones for the following constants.
 * The decimal values may be used, provided that the compiler will convert
 * from decimal to binary accurately enough to produce the hexadecimal values
 * shown.
 */
E 3

D 3
double
pow(arg1,arg2)
double arg1, arg2;
E 3
I 3
#ifdef VAX	/* VAX D format */
#include <errno.h>
D 5
extern errno;
I 4
static long	NaN_[] = {0x8000, 0x0};
#define NaN	(*(double *) NaN_)
E 5
I 5
extern double infnan();
E 5

E 4
/* double static */
/* ln2hi  =  6.9314718055829871446E-1    , Hex  2^  0   *  .B17217F7D00000 */
/* ln2lo  =  1.6465949582897081279E-12   , Hex  2^-39   *  .E7BCD5E4F1D9CC */
/* invln2 =  1.4426950408889634148E0     , Hex  2^  1   *  .B8AA3B295C17F1 */
/* sqrt2  =  1.4142135623730950622E0     ; Hex  2^  1   *  .B504F333F9DE65 */
static long     ln2hix[] = { 0x72174031, 0x0000f7d0};
static long     ln2lox[] = { 0xbcd52ce7, 0xd9cce4f1};
static long    invln2x[] = { 0xaa3b40b8, 0x17f1295c};
static long     sqrt2x[] = { 0x04f340b5, 0xde6533f9};
#define    ln2hi    (*(double*)ln2hix)
#define    ln2lo    (*(double*)ln2lox)
#define   invln2    (*(double*)invln2x)
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
invln2 =  1.4426950408889633870E0     , /*Hex  2^  0   *  1.71547652B82FE */
sqrt2  =  1.4142135623730951455E0     ; /*Hex  2^  0   *  1.6A09E667F3BCD */
#endif

double static zero=0.0, half=1.0/2.0, one=1.0, two=2.0, negone= -1.0;

double pow(x,y)  	
double x,y;
E 3
{
D 3
	double temp;
	long l;
E 3
I 3
	double drem(),pow_p(),copysign(),t;
	int finite();
E 3

I 2
D 3
#ifdef vax
E 2
	asm("	bispsw	$0xe0");
E 3
I 3
	if     (y==zero)      return(one);
D 5
	else if(y==one||x!=x) return( x );      /* if x is NAN or y=1 */
	else if(y!=y)         return( y );      /* if y is NAN */
E 5
I 5
	else if(y==one
#ifndef VAX
		||x!=x
#endif
		) return( x );      /* if x is NaN or y=1 */
#ifndef VAX
	else if(y!=y)         return( y );      /* if y is NaN */
#endif
E 5
	else if(!finite(y))                     /* if y is INF */
	     if((t=copysign(x,one))==one) return(zero/zero);
	     else if(t>one) return((y>zero)?y:zero);
	     else return((y<zero)?-y:zero);
	else if(y==two)       return(x*x);
	else if(y==negone)    return(one/x);

    /* sign(x) = 1 */
	else if(copysign(one,x)==one) return(pow_p(x,y));

    /* sign(x)= -1 */
	/* if y is an even integer */
	else if ( (t=drem(y,two)) == zero)	return( pow_p(-x,y) );

	/* if y is an odd integer */
	else if (copysign(t,one) == one) return( -pow_p(-x,y) );

	/* Henceforth y is not an integer */
	else if(x==zero)	/* x is -0 */
	    return((y>zero)?-x:one/(-x));
D 5
	else {			/* return NAN */
E 5
I 5
	else {			/* return NaN */
E 5
#ifdef VAX
D 5
	    errno = EDOM;
E 3
I 2
D 4
#endif
E 4
I 4
	    return (NaN);
#else
E 5
I 5
	    return (infnan(EDOM));	/* NaN */
#else	/* IEEE double */
E 5
E 4
E 2
D 3
	if(arg1 <= 0.) {
		if(arg1 == 0.) {
			if(arg2 <= 0.)
				goto domain;
			return(0.);
		}
		l = arg2;
		if(l != arg2)
			goto domain;
		temp = exp(arg2 * log(-arg1));
		if(l & 1)
			temp = -temp;
		return(temp);
E 3
I 3
	    return(zero/zero);
I 4
#endif
E 4
E 3
	}
D 3
	return(exp(arg2 * log(arg1)));
E 3
I 3
}
E 3

D 3
domain:
	errno = EDOM;
	return(0.);
E 3
I 3
/* pow_p(x,y) return x**y for x with sign=1 and finite y */
static double pow_p(x,y)       
double x,y;
{
        double logb(),scalb(),copysign(),log__L(),exp__E();
        double c,s,t,z,tx,ty;
        float sx,sy;
	long k=0;
        int n,m;

	if(x==zero||!finite(x)) {           /* if x is +INF or +0 */
#ifdef VAX
D 5
	     if (y<zero) errno = ERANGE;
#endif
E 5
I 5
	     return((y>zero)?x:infnan(ERANGE));	/* if y<zero, return +INF */
#else
E 5
	     return((y>zero)?x:one/x);
I 5
#endif
E 5
	}
I 5
	if(x==1.0) return(x);	/* if x=1.0, return 1 since y is finite */
E 5

    /* reduce x to z in [sqrt(1/2)-1, sqrt(2)-1] */
        z=scalb(x,-(n=logb(x)));  
D 5
#ifndef VAX 	/* subnormal number */
E 5
I 5
#ifndef VAX	/* IEEE double */	/* subnormal number */
E 5
        if(n <= -1022) {n += (m=logb(z)); z=scalb(z,-m);} 
#endif
        if(z >= sqrt2 ) {n += 1; z *= half;}  z -= one ;

    /* log(x) = nlog2+log(1+z) ~ nlog2 + t + tx */
	s=z/(two+z); c=z*z*half; tx=s*(c+log__L(s*s)); 
	t= z-(c-tx); tx += (z-t)-c;

   /* if y*log(x) is neither too big nor too small */
	if((s=logb(y)+logb(n+t)) < 12.0) 
	    if(s>-60.0) {

	/* compute y*log(x) ~ mlog2 + t + c */
        	s=y*(n+invln2*t);
                m=s+copysign(half,s);   /* m := nint(y*log(x)) */ 
		k=y; 
		if((double)k==y) {	/* if y is an integer */
		    k = m-k*n;
		    sx=t; tx+=(t-sx); }
		else	{		/* if y is not an integer */    
		    k =m;
	 	    tx+=n*ln2lo;
		    sx=(c=n*ln2hi)+t; tx+=(c-sx)+t; }
	   /* end of checking whether k==y */

                sy=y; ty=y-sy;          /* y ~ sy + ty */
		s=(double)sx*sy-k*ln2hi;        /* (sy+ty)*(sx+tx)-kln2 */
		z=(tx*ty-k*ln2lo);
		tx=tx*sy; ty=sx*ty;
		t=ty+z; t+=tx; t+=s;
		c= -((((t-s)-tx)-ty)-z);

	    /* return exp(y*log(x)) */
		t += exp__E(t,c); return(scalb(one+t,m));
	     }
	/* end of if log(y*log(x)) > -60.0 */
	    
	    else
D 5
		/* exp(+- tiny) = 1 */
			return(one);
E 5
I 5
		/* exp(+- tiny) = 1 with inexact flag */
			{ln2hi+ln2lo; return(one);}
E 5
	    else if(copysign(one,y)*(n+invln2*t) <zero)
		/* exp(-(big#)) underflows to zero */
	        	return(scalb(one,-5000)); 
	    else
	        /* exp(+(big#)) overflows to INF */
	    		return(scalb(one, 5000)); 

E 3
}
E 1
