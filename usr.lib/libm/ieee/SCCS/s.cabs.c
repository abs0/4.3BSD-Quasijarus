h03565
s 00010/00005/00215
d D 5.3 88/06/30 17:22:59 bostic 11 10
c install approved copyright notice
e
s 00016/00013/00204
d D 5.2 88/04/29 12:23:20 bostic 10 9
c add Berkeley specific copyright
e
s 00000/00000/00217
d D 5.1 87/11/30 18:42:12 bostic 9 8
c tahoe release
e
s 00029/00022/00188
d D 1.7 87/08/03 16:19:33 zliu 8 6
c rearrange code; added z_abs();
e
s 00029/00022/00188
d R 1.7 87/08/03 15:58:46 zliu 7 6
c rearrange code; added z_abs().
e
s 00009/00011/00201
d D 1.6 87/07/13 19:36:44 zliu 6 5
c clean-ups.
e
s 00004/00000/00208
d D 1.5 87/07/11 13:39:51 zliu 5 4
c making error handling consistent in support.c by calling
c infnan() in sqrt() and drem(); ifdef out those finite and (x!=x)'s.
e
s 00008/00003/00200
d D 1.4 87/07/10 10:51:56 zliu 4 3
c adding _0x macro for TAHOE.
e
s 00001/00001/00202
d D 1.3 87/07/07 01:06:09 zliu 3 2
c first shot at TAHOE.
e
s 00002/00001/00201
d D 1.2 85/09/12 20:21:49 elefunt 2 1
c 4.3BSD version dated 09/12/85.
e
s 00202/00000/00000
d D 1.1 85/09/06 17:51:25 zliu 1 0
c date and time created 85/09/06 17:51:25 by zliu
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
"%Z%%M%	1.2 (Berkeley) 8/21/85; %I% (ucb.elefunt) %G%";
E 2
D 6
#endif not lint
E 6
I 6
#endif	/* not lint */
E 10
I 10
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 10
E 6

D 8
/* CABS(Z)
 * RETURN THE ABSOLUTE VALUE OF THE COMPLEX NUMBER  Z = X + iY
 * DOUBLE PRECISION (VAX D format 56 bits, IEEE DOUBLE 53 BITS)
 * CODED IN C BY K.C. NG, 11/28/84.
 * REVISED BY K.C. NG, 7/12/85.
 *
 * Required kernel function :
 *	hypot(x,y)
 *
 * Method :
 *	cabs(z) = hypot(x,y) .
 */

double cabs(z)
struct { double x, y;} z;
{
	double hypot();
	return(hypot(z.x,z.y));
}


E 8
/* HYPOT(X,Y)
 * RETURN THE SQUARE ROOT OF X^2 + Y^2  WHERE Z=X+iY
 * DOUBLE PRECISION (VAX D format 56 bits, IEEE DOUBLE 53 BITS)
 * CODED IN C BY K.C. NG, 11/28/84; 
 * REVISED BY K.C. NG, 7/12/85.
 *
 * Required system supported functions :
 *	copysign(x,y)
 *	finite(x)
 *	scalb(x,N)
 *	sqrt(x)
 *
 * Method :
 *	1. replace x by |x| and y by |y|, and swap x and
 *	   y if y > x (hence x is never smaller than y).
 *	2. Hypot(x,y) is computed by:
 *	   Case I, x/y > 2
 *		
 *				       y
 *		hypot = x + -----------------------------
 *			 		    2
 *			    sqrt ( 1 + [x/y]  )  +  x/y
 *
 *	   Case II, x/y <= 2 
 *				                   y
 *		hypot = x + --------------------------------------------------
 *				          		     2 
 *				     			[x/y]   -  2
 *			   (sqrt(2)+1) + (x-y)/y + -----------------------------
 *			 		    			  2
 *			    			  sqrt ( 1 + [x/y]  )  + sqrt(2)
 *
 *
 *
 * Special cases:
 *	hypot(x,y) is INF if x or y is +INF or -INF; else
 *	hypot(x,y) is NAN if x or y is NAN.
 *
 * Accuracy:
 * 	hypot(x,y) returns the sqrt(x^2+y^2) with error less than 1 ulps (units
 *	in the last place). See Kahan's "Interval Arithmetic Options in the
 *	Proposed IEEE Floating Point Arithmetic Standard", Interval Mathematics
 *      1980, Edited by Karl L.E. Nickel, pp 99-128. (A faster but less accurate
 *	code follows in	comments.) In a test run with 500,000 random arguments
 *	on a VAX, the maximum observed error was .959 ulps.
 *
 * Constants:
 * The hexadecimal values are the intended ones for the following constants.
 * The decimal values may be used, provided that the compiler will convert
 * from decimal to binary accurately enough to produce the hexadecimal values
 * shown.
 */

D 3
#ifdef VAX	/* VAX D format */
E 3
I 3
D 6
#if (defined(VAX)||defined(TAHOE))	/* VAX D format */
I 4
#ifdef VAX
E 6
I 6
#if defined(vax)||defined(tahoe)	/* VAX D format */
#ifdef vax
E 6
#define _0x(A,B)	0x/**/A/**/B
D 6
#else	/* VAX */
E 6
I 6
#else	/* vax */
E 6
#define _0x(A,B)	0x/**/B/**/A
D 6
#endif	/* VAX */
E 6
I 6
#endif	/* vax */
E 6
E 4
E 3
/* static double */
/* r2p1hi =  2.4142135623730950345E0     , Hex  2^  2   *  .9A827999FCEF32 */
/* r2p1lo =  1.4349369327986523769E-17   , Hex  2^-55   *  .84597D89B3754B */
/* sqrt2  =  1.4142135623730950622E0     ; Hex  2^  1   *  .B504F333F9DE65 */
D 4
static long    r2p1hix[] = { 0x8279411a, 0xef3299fc};
static long    r2p1lox[] = { 0x597d2484, 0x754b89b3};
static long     sqrt2x[] = { 0x04f340b5, 0xde6533f9};
E 4
I 4
static long    r2p1hix[] = { _0x(8279,411a), _0x(ef32,99fc)};
static long    r2p1lox[] = { _0x(597d,2484), _0x(754b,89b3)};
static long     sqrt2x[] = { _0x(04f3,40b5), _0x(de65,33f9)};
E 4
#define   r2p1hi    (*(double*)r2p1hix)
#define   r2p1lo    (*(double*)r2p1lox)
#define    sqrt2    (*(double*)sqrt2x)
D 6
#else		/* IEEE double format */
E 6
I 6
#else	/* defined(vax)||defined(tahoe)	*/
E 6
static double
r2p1hi =  2.4142135623730949234E0     , /*Hex  2^1     *  1.3504F333F9DE6 */
r2p1lo =  1.2537167179050217666E-16   , /*Hex  2^-53   *  1.21165F626CDD5 */
sqrt2  =  1.4142135623730951455E0     ; /*Hex  2^  0   *  1.6A09E667F3BCD */
D 6
#endif
E 6
I 6
#endif	/* defined(vax)||defined(tahoe)	*/
E 6

D 8
double hypot(x,y)
E 8
I 8
double
hypot(x,y)
E 8
double x, y;
{
	static double zero=0, one=1, 
		      small=1.0E-18;	/* fl(1+small)==1 */
	static ibig=30;	/* fl(1+2**(2*ibig))==1 */
	double copysign(),scalb(),logb(),sqrt(),t,r;
	int finite(), exp;

I 5
D 6
#if (!defined(VAX)&&!defined(TAHOE))
E 6
E 5
	if(finite(x))
	    if(finite(y))
	    {	
I 5
D 6
#endif
E 6
E 5
		x=copysign(x,one);
		y=copysign(y,one);
		if(y > x) 
		    { t=x; x=y; y=t; }
		if(x == zero) return(zero);
		if(y == zero) return(x);
		exp= logb(x);
		if(exp-(int)logb(y) > ibig ) 	
			/* raise inexact flag and return |x| */
		   { one+small; return(x); }

	    /* start computing sqrt(x^2 + y^2) */
		r=x-y;
		if(r>y) { 	/* x/y > 2 */
		    r=x/y;
		    r=r+sqrt(one+r*r); }
		else {		/* 1 <= x/y <= 2 */
		    r/=y; t=r*(r+2.0);
		    r+=t/(sqrt2+sqrt(2.0+t));
		    r+=r2p1lo; r+=r2p1hi; }

		r=y/r;
		return(x+r);

I 5
D 6
#if (!defined(VAX)&&!defined(TAHOE))
E 6
E 5
	    }

	    else if(y==y)   	   /* y is +-INF */
		     return(copysign(y,one));
	    else 
		     return(y);	   /* y is NaN and x is finite */

	else if(x==x) 		   /* x is +-INF */
	         return (copysign(x,one));
	else if(finite(y))
	         return(x);		   /* x is NaN, y is finite */
I 6
#if !defined(vax)&&!defined(tahoe)
E 6
	else if(y!=y) return(y);  /* x and y is NaN */
I 6
#endif	/* !defined(vax)&&!defined(tahoe) */
E 6
	else return(copysign(y,one));   /* y is INF */
I 8
}

/* CABS(Z)
 * RETURN THE ABSOLUTE VALUE OF THE COMPLEX NUMBER  Z = X + iY
 * DOUBLE PRECISION (VAX D format 56 bits, IEEE DOUBLE 53 BITS)
 * CODED IN C BY K.C. NG, 11/28/84.
 * REVISED BY K.C. NG, 7/12/85.
 *
 * Required kernel function :
 *	hypot(x,y)
 *
 * Method :
 *	cabs(z) = hypot(x,y) .
 */

double
cabs(z)
struct { double x, y;} z;
{
	return hypot(z.x,z.y);
}

double
z_abs(z)
struct { double x,y;} *z;
{
	return hypot(z->x,z->y);
E 8
I 5
D 6
#endif
E 6
E 5
}

/* A faster but less accurate version of cabs(x,y) */
#if 0
double hypot(x,y)
double x, y;
{
	static double zero=0, one=1;
		      small=1.0E-18;	/* fl(1+small)==1 */
	static ibig=30;	/* fl(1+2**(2*ibig))==1 */
	double copysign(),scalb(),logb(),sqrt(),temp;
	int finite(), exp;

	if(finite(x))
	    if(finite(y))
	    {	
		x=copysign(x,one);
		y=copysign(y,one);
		if(y > x) 
		    { temp=x; x=y; y=temp; }
		if(x == zero) return(zero);
		if(y == zero) return(x);
		exp= logb(x);
		x=scalb(x,-exp);
		if(exp-(int)logb(y) > ibig ) 
			/* raise inexact flag and return |x| */
		   { one+small; return(scalb(x,exp)); }
		else y=scalb(y,-exp);
		return(scalb(sqrt(x*x+y*y),exp));
	    }

	    else if(y==y)   	   /* y is +-INF */
		     return(copysign(y,one));
	    else 
		     return(y);	   /* y is NaN and x is finite */

	else if(x==x) 		   /* x is +-INF */
	         return (copysign(x,one));
	else if(finite(y))
	         return(x);		   /* x is NaN, y is finite */
	else if(y!=y) return(y);  	/* x and y is NaN */
	else return(copysign(y,one));   /* y is INF */
}
#endif
E 1
