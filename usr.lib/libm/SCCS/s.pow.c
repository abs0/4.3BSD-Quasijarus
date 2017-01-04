h55220
s 00010/00005/00236
d D 5.3 88/06/30 17:45:35 bostic 11 10
c install approved copyright notice
e
s 00016/00013/00225
d D 5.2 88/04/29 12:42:04 bostic 10 9
c add Berkeley specific header
e
s 00000/00000/00238
d D 5.1 87/11/30 18:34:10 bostic 9 8
c tahoe release
e
s 00024/00024/00214
d D 1.7 87/07/13 19:20:48 zliu 8 7
c clean-ups.
e
s 00007/00000/00231
d D 1.6 87/07/10 22:17:38 zliu 7 5
c TAHOE's code generator doesn't give us correct code for such
c constructs as (double)sx*sy.  work-around: force temporary store.
e
s 00007/00000/00231
d R 1.6 87/07/10 22:05:33 zliu 6 5
c (double)sx*sy bug on TAHOE work-around: force temporary storage.
e
s 00009/00005/00222
d D 1.5 87/07/10 10:36:35 zliu 5 4
c adding _0x macro for TAHOE.
e
s 00006/00006/00221
d D 1.4 87/07/07 01:32:08 zliu 4 3
c first shot at TAHOE.
e
s 00003/00003/00224
d D 1.3 86/03/16 19:08:50 elefunt 3 2
c All instances of "double static" got converted to "static double",
c as it should be.
e
s 00002/00001/00225
d D 1.2 85/09/11 23:54:39 elefunt 2 1
c 4.3BSD version dated 09/11/85.
e
s 00226/00000/00000
d D 1.1 85/09/06 17:53:04 zliu 1 0
c date and time created 85/09/06 17:53:04 by zliu
e
u
U
t
T
I 1
D 10
/* 
E 10
I 10
/*
E 10
 * Copyright (c) 1985 Regents of the University of California.
D 10
 * 
 * Use and reproduction of this software are granted  in  accordance  with
 * the terms and conditions specified in  the  Berkeley  Software  License
 * Agreement (in particular, this entails acknowledgement of the programs'
 * source, and inclusion of this notice) with the additional understanding
 * that  all  recipients  should regard themselves as participants  in  an
 * ongoing  research  project and hence should  feel  obligated  to report
 * their  experiences (good or bad) with these elementary function  codes,
 * using "sendbug 4bsd-bugs@BERKELEY", to the authors.
E 10
I 10
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 11
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 11
I 11
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
E 11
 *
 * All recipients should regard themselves as participants in an ongoing
 * research project and hence should feel obligated to report their
 * experiences (good or bad) with these elementary function codes, using
 * the sendbug(8) program, to the authors.
E 10
 */

#ifndef lint
D 2
static char sccsid[] = "%W% (ELEFUNT) %G%";
E 2
I 2
D 10
static char sccsid[] =
"%Z%%M%	4.5 (Berkeley) 8/21/85; %I% (ucb.elefunt) %G%";
E 2
D 8
#endif not lint
E 8
I 8
#endif	/* not lint */
E 10
I 10
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 10
E 8

/* POW(X,Y)  
 * RETURN X**Y 
 * DOUBLE PRECISION (VAX D format 56 bits, IEEE DOUBLE 53 BITS)
 * CODED IN C BY K.C. NG, 1/8/85; 
 * REVISED BY K.C. NG on 7/10/85.
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
 *	(anything) ** NaN is NaN;
 *	NaN ** (anything except 0) is NaN;
 *	+-(anything > 1) ** +INF is +INF;
 *	+-(anything > 1) ** -INF is +0;
 *	+-(anything < 1) ** +INF is +0;
 *	+-(anything < 1) ** -INF is +INF;
 *	+-1 ** +-INF is NaN and signal INVALID;
 *	+0 ** +(anything except 0, NaN)  is +0;
 *	-0 ** +(anything except 0, NaN, odd integer)  is +0;
 *	+0 ** -(anything except 0, NaN)  is +INF and signal DIV-BY-ZERO;
 *	-0 ** -(anything except 0, NaN, odd integer)  is +INF with signal;
 *	-0 ** (odd integer) = -( +0 ** (odd integer) );
 *	+INF ** +(anything except 0,NaN) is +INF;
 *	+INF ** -(anything except 0,NaN) is +0;
 *	-INF ** (odd integer) = -( +INF ** (odd integer) );
 *	-INF ** (even integer) = ( +INF ** (even integer) );
 *	-INF ** -(anything except integer,NaN) is NaN with signal;
 *	-(x=anything) ** (k=integer) is (-1)**k * (x ** k);
 *	-(anything except 0) ** (non-integer) is NaN with signal;
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

D 4
#ifdef VAX	/* VAX D format */
E 4
I 4
D 8
#if (defined(VAX)||defined(TAHOE))	/* VAX D format */
E 8
I 8
#if defined(vax)||defined(tahoe)	/* VAX D format */
E 8
E 4
#include <errno.h>
extern double infnan();
D 5

E 5
I 5
D 8
#ifdef VAX
E 8
I 8
#ifdef vax
E 8
#define _0x(A,B)	0x/**/A/**/B
D 8
#else	/* VAX */
E 8
I 8
#else	/* vax */
E 8
#define _0x(A,B)	0x/**/B/**/A
D 8
#endif	/* VAX */
E 8
I 8
#endif	/* vax */
E 8
E 5
D 3
/* double static */
E 3
I 3
/* static double */
E 3
/* ln2hi  =  6.9314718055829871446E-1    , Hex  2^  0   *  .B17217F7D00000 */
/* ln2lo  =  1.6465949582897081279E-12   , Hex  2^-39   *  .E7BCD5E4F1D9CC */
/* invln2 =  1.4426950408889634148E0     , Hex  2^  1   *  .B8AA3B295C17F1 */
/* sqrt2  =  1.4142135623730950622E0     ; Hex  2^  1   *  .B504F333F9DE65 */
D 5
static long     ln2hix[] = { 0x72174031, 0x0000f7d0};
static long     ln2lox[] = { 0xbcd52ce7, 0xd9cce4f1};
static long    invln2x[] = { 0xaa3b40b8, 0x17f1295c};
static long     sqrt2x[] = { 0x04f340b5, 0xde6533f9};
E 5
I 5
static long     ln2hix[] = { _0x(7217,4031), _0x(0000,f7d0)};
static long     ln2lox[] = { _0x(bcd5,2ce7), _0x(d9cc,e4f1)};
static long    invln2x[] = { _0x(aa3b,40b8), _0x(17f1,295c)};
static long     sqrt2x[] = { _0x(04f3,40b5), _0x(de65,33f9)};
E 5
#define    ln2hi    (*(double*)ln2hix)
#define    ln2lo    (*(double*)ln2lox)
#define   invln2    (*(double*)invln2x)
#define    sqrt2    (*(double*)sqrt2x)
D 8
#else	/* IEEE double */
E 8
I 8
#else	/* defined(vax)||defined(tahoe)	*/
E 8
D 3
double static
E 3
I 3
static double
E 3
ln2hi  =  6.9314718036912381649E-1    , /*Hex  2^ -1   *  1.62E42FEE00000 */
ln2lo  =  1.9082149292705877000E-10   , /*Hex  2^-33   *  1.A39EF35793C76 */
invln2 =  1.4426950408889633870E0     , /*Hex  2^  0   *  1.71547652B82FE */
sqrt2  =  1.4142135623730951455E0     ; /*Hex  2^  0   *  1.6A09E667F3BCD */
D 8
#endif
E 8
I 8
#endif	/* defined(vax)||defined(tahoe)	*/
E 8

D 3
double static zero=0.0, half=1.0/2.0, one=1.0, two=2.0, negone= -1.0;
E 3
I 3
static double zero=0.0, half=1.0/2.0, one=1.0, two=2.0, negone= -1.0;
E 3

double pow(x,y)  	
double x,y;
{
	double drem(),pow_p(),copysign(),t;
	int finite();

	if     (y==zero)      return(one);
	else if(y==one
D 4
#ifndef VAX
E 4
I 4
D 8
#if (!defined(VAX)&&!defined(TAHOE))
E 8
I 8
#if !defined(vax)&&!defined(tahoe)
E 8
E 4
		||x!=x
D 8
#endif
E 8
I 8
#endif	/* !defined(vax)&&!defined(tahoe) */
E 8
		) return( x );      /* if x is NaN or y=1 */
D 4
#ifndef VAX
E 4
I 4
D 8
#if (!defined(VAX)&&!defined(TAHOE))
E 8
I 8
#if !defined(vax)&&!defined(tahoe)
E 8
E 4
	else if(y!=y)         return( y );      /* if y is NaN */
D 8
#endif
E 8
I 8
#endif	/* !defined(vax)&&!defined(tahoe) */
E 8
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
	else {			/* return NaN */
D 4
#ifdef VAX
E 4
I 4
D 8
#if (defined(VAX)||defined(TAHOE))
E 8
I 8
#if defined(vax)||defined(tahoe)
E 8
E 4
	    return (infnan(EDOM));	/* NaN */
D 8
#else	/* IEEE double */
E 8
I 8
#else	/* defined(vax)||defined(tahoe) */
E 8
	    return(zero/zero);
D 8
#endif
E 8
I 8
#endif	/* defined(vax)||defined(tahoe) */
E 8
	}
}

/* pow_p(x,y) return x**y for x with sign=1 and finite y */
static double pow_p(x,y)       
double x,y;
{
        double logb(),scalb(),copysign(),log__L(),exp__E();
        double c,s,t,z,tx,ty;
I 7
D 8
#ifdef TAHOE
E 8
I 8
#ifdef tahoe
E 8
	double tahoe_tmp;
D 8
#endif
E 8
I 8
#endif	/* tahoe */
E 8
E 7
        float sx,sy;
	long k=0;
        int n,m;

	if(x==zero||!finite(x)) {           /* if x is +INF or +0 */
D 4
#ifdef VAX
E 4
I 4
D 8
#if (defined(VAX)||defined(TAHOE))
E 8
I 8
#if defined(vax)||defined(tahoe)
E 8
E 4
	     return((y>zero)?x:infnan(ERANGE));	/* if y<zero, return +INF */
D 8
#else
E 8
I 8
#else	/* defined(vax)||defined(tahoe) */
E 8
	     return((y>zero)?x:one/x);
D 8
#endif
E 8
I 8
#endif	/* defined(vax)||defined(tahoe) */
E 8
	}
	if(x==1.0) return(x);	/* if x=1.0, return 1 since y is finite */

    /* reduce x to z in [sqrt(1/2)-1, sqrt(2)-1] */
        z=scalb(x,-(n=logb(x)));  
D 4
#ifndef VAX	/* IEEE double */	/* subnormal number */
E 4
I 4
D 8
#if (!defined(VAX)&&!defined(TAHOE))	/* IEEE double; subnormal number */
E 8
I 8
#if !defined(vax)&&!defined(tahoe)	/* IEEE double; subnormal number */
E 8
E 4
        if(n <= -1022) {n += (m=logb(z)); z=scalb(z,-m);} 
D 8
#endif
E 8
I 8
#endif	/* !defined(vax)&&!defined(tahoe) */
E 8
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
I 7
D 8
#ifdef TAHOE
E 8
I 8
#ifdef tahoe
E 8
		s = (tahoe_tmp = sx)*sy-k*ln2hi;
D 8
#else
E 8
I 8
#else	/* tahoe */
E 8
E 7
		s=(double)sx*sy-k*ln2hi;        /* (sy+ty)*(sx+tx)-kln2 */
I 7
D 8
#endif
E 8
I 8
#endif	/* tahoe */
E 8
E 7
		z=(tx*ty-k*ln2lo);
		tx=tx*sy; ty=sx*ty;
		t=ty+z; t+=tx; t+=s;
		c= -((((t-s)-tx)-ty)-z);

	    /* return exp(y*log(x)) */
		t += exp__E(t,c); return(scalb(one+t,m));
	     }
	/* end of if log(y*log(x)) > -60.0 */
	    
	    else
		/* exp(+- tiny) = 1 with inexact flag */
			{ln2hi+ln2lo; return(one);}
	    else if(copysign(one,y)*(n+invln2*t) <zero)
		/* exp(-(big#)) underflows to zero */
	        	return(scalb(one,-5000)); 
	    else
	        /* exp(+(big#)) overflows to INF */
	    		return(scalb(one, 5000)); 

}
E 1
