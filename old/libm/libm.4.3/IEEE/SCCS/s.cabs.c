h38305
s 00001/00001/00201
d D 1.3 87/06/29 22:56:41 sam 3 2
c tahoe machine depencencies from pixar!bill
e
s 00087/00085/00115
d D 1.2 85/08/21 13:50:08 miriam 2 1
c Revision by Prof. Kahan.
e
s 00200/00000/00000
d D 1.1 85/05/23 17:12:30 miriam 1 0
c date and time created 85/05/23 17:12:30 by miriam
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
/* HYPOT(X,Y) 
 * RETURN THE SQUARE ROOT OF X^2 + Y^2
E 2
I 2
/* CABS(Z)
 * RETURN THE ABSOLUTE VALUE OF THE COMPLEX NUMBER  Z = X + iY
E 2
 * DOUBLE PRECISION (VAX D format 56 bits, IEEE DOUBLE 53 BITS)
 * CODED IN C BY K.C. NG, 11/28/84.
I 2
 * REVISED BY K.C. NG, 7/12/85.
E 2
 *
 * Required kernel function :
D 2
 *	cabs(x,y)
E 2
I 2
 *	hypot(x,y)
E 2
 *
 * Method :
D 2
 *	hypot(x,y) = cabs(x,y) .
E 2
I 2
 *	cabs(z) = hypot(x,y) .
E 2
 */

D 2
double hypot(x,y)
double x, y;
E 2
I 2
double cabs(z)
struct { double x, y;} z;
E 2
{
D 2
	double cabs();
	return(cabs(x,y));
E 2
I 2
	double hypot();
	return(hypot(z.x,z.y));
E 2
}

D 2
/* CABS(REAL,IMAG)
 * RETURN THE ABSOLUTE VALUE OF THE COMPLEX NUMBER  REAL + i*IMAG
E 2
I 2

/* HYPOT(X,Y)
 * RETURN THE SQUARE ROOT OF X^2 + Y^2  WHERE Z=X+iY
E 2
 * DOUBLE PRECISION (VAX D format 56 bits, IEEE DOUBLE 53 BITS)
 * CODED IN C BY K.C. NG, 11/28/84; 
D 2
 * REVISED BY K.C. NG on 2/7/85, 2/22/85, 3/7/85, 3/30/85, 4/16/85.
E 2
I 2
 * REVISED BY K.C. NG, 7/12/85.
E 2
 *
 * Required system supported functions :
 *	copysign(x,y)
 *	finite(x)
 *	scalb(x,N)
 *	sqrt(x)
 *
 * Method :
D 2
 *	1. replace real by |real| and imag by |imag|, and swap real and
 *	   imag if imag > real (hence real is never smaller than imag).
 *	2. Let X=real and Y=imag, cabs(X,Y) is computed by:
 *	   Case I, X/Y > 2
E 2
I 2
 *	1. replace x by |x| and y by |y|, and swap x and
 *	   y if y > x (hence x is never smaller than y).
 *	2. Hypot(x,y) is computed by:
 *	   Case I, x/y > 2
E 2
 *		
D 2
 *				       Y
 *		cabs = X + -----------------------------
E 2
I 2
 *				       y
 *		hypot = x + -----------------------------
E 2
 *			 		    2
D 2
 *			    sqrt ( 1 + [X/Y]  )  +  X/Y
E 2
I 2
 *			    sqrt ( 1 + [x/y]  )  +  x/y
E 2
 *
D 2
 *	   Case II, X/Y <= 2 
 *				                   Y
 *		cabs = X + --------------------------------------------------
E 2
I 2
 *	   Case II, x/y <= 2 
 *				                   y
 *		hypot = x + --------------------------------------------------
E 2
 *				          		     2 
D 2
 *				     			[X/Y]   -  2
 *			   (sqrt(2)+1) + (X-Y)/Y + -----------------------------
E 2
I 2
 *				     			[x/y]   -  2
 *			   (sqrt(2)+1) + (x-y)/y + -----------------------------
E 2
 *			 		    			  2
D 2
 *			    			  sqrt ( 1 + [X/Y]  )  + sqrt(2)
E 2
I 2
 *			    			  sqrt ( 1 + [x/y]  )  + sqrt(2)
E 2
 *
 *
 *
 * Special cases:
D 2
 *	cabs(x,y) is INF if x or y is +INF or -INF; else
 *	cabs(x,y) is NAN if x or y is NAN.
E 2
I 2
 *	hypot(x,y) is INF if x or y is +INF or -INF; else
 *	hypot(x,y) is NAN if x or y is NAN.
E 2
 *
 * Accuracy:
D 2
 * 	cabs(x,y) returns the sqrt(x^2+y^2) with error less than 1 ulps (units
E 2
I 2
 * 	hypot(x,y) returns the sqrt(x^2+y^2) with error less than 1 ulps (units
E 2
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
#if defined(VAX) || defined(TAHOE)	/* VAX D format */
E 3
/* static double */
/* r2p1hi =  2.4142135623730950345E0     , Hex  2^  2   *  .9A827999FCEF32 */
/* r2p1lo =  1.4349369327986523769E-17   , Hex  2^-55   *  .84597D89B3754B */
/* sqrt2  =  1.4142135623730950622E0     ; Hex  2^  1   *  .B504F333F9DE65 */
static long    r2p1hix[] = { 0x8279411a, 0xef3299fc};
static long    r2p1lox[] = { 0x597d2484, 0x754b89b3};
static long     sqrt2x[] = { 0x04f340b5, 0xde6533f9};
#define   r2p1hi    (*(double*)r2p1hix)
#define   r2p1lo    (*(double*)r2p1lox)
#define    sqrt2    (*(double*)sqrt2x)
#else		/* IEEE double format */
static double
r2p1hi =  2.4142135623730949234E0     , /*Hex  2^1     *  1.3504F333F9DE6 */
r2p1lo =  1.2537167179050217666E-16   , /*Hex  2^-53   *  1.21165F626CDD5 */
sqrt2  =  1.4142135623730951455E0     ; /*Hex  2^  0   *  1.6A09E667F3BCD */
#endif

D 2
double cabs(real,imag)
double real, imag;
E 2
I 2
double hypot(x,y)
double x, y;
E 2
{
	static double zero=0, one=1, 
		      small=1.0E-18;	/* fl(1+small)==1 */
	static ibig=30;	/* fl(1+2**(2*ibig))==1 */
	double copysign(),scalb(),logb(),sqrt(),t,r;
	int finite(), exp;

D 2
	if(finite(real))
	    if(finite(imag))
E 2
I 2
	if(finite(x))
	    if(finite(y))
E 2
	    {	
D 2
		real=copysign(real,one);
		imag=copysign(imag,one);
		if(imag > real) 
		    { t=real; real=imag; imag=t; }
		if(real == zero) return(zero);
		if(imag == zero) return(real);
		exp= logb(real);
		if(exp-(int)logb(imag) > ibig ) 	
			/* raise inexact flag and return |real| */
		   { one+small; return(real); }
E 2
I 2
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
E 2

D 2
	    /* start computing sqrt(real^2 + imag^2) */
		r=real-imag;
		if(r>imag) { 	/* real/imag > 2 */
		    r=real/imag;
E 2
I 2
	    /* start computing sqrt(x^2 + y^2) */
		r=x-y;
		if(r>y) { 	/* x/y > 2 */
		    r=x/y;
E 2
		    r=r+sqrt(one+r*r); }
D 2
		else {		/* 1 <= real/imag <= 2 */
		    r/=imag; t=r*(r+2.0);
E 2
I 2
		else {		/* 1 <= x/y <= 2 */
		    r/=y; t=r*(r+2.0);
E 2
		    r+=t/(sqrt2+sqrt(2.0+t));
		    r+=r2p1lo; r+=r2p1hi; }

D 2
		r=imag/r;
		return(real+r);
E 2
I 2
		r=y/r;
		return(x+r);
E 2

	    }

D 2
	    else if(imag==imag)   	   /* imag is +-INF */
		     return(copysign(imag,one));
E 2
I 2
	    else if(y==y)   	   /* y is +-INF */
		     return(copysign(y,one));
E 2
	    else 
D 2
		     return(imag);	   /* imag is NaN and x is finite */
E 2
I 2
		     return(y);	   /* y is NaN and x is finite */
E 2

D 2
	else if(real==real) 		   /* real is +-INF */
	         return (copysign(real,one));
	else if(finite(imag))
	         return(real);		   /* real is NaN, imag is finite */
	else if(imag!=imag) return(imag);  /* real and imag is NaN */
	else return(copysign(imag,one));   /* imag is INF */
E 2
I 2
	else if(x==x) 		   /* x is +-INF */
	         return (copysign(x,one));
	else if(finite(y))
	         return(x);		   /* x is NaN, y is finite */
	else if(y!=y) return(y);  /* x and y is NaN */
	else return(copysign(y,one));   /* y is INF */
E 2
}

D 2
/* A faster but less accurate version of cabs(real,imag) */
E 2
I 2
/* A faster but less accurate version of cabs(x,y) */
E 2
#if 0
D 2
double cabs(real,imag)
double real, imag;
E 2
I 2
double hypot(x,y)
double x, y;
E 2
{
	static double zero=0, one=1;
		      small=1.0E-18;	/* fl(1+small)==1 */
	static ibig=30;	/* fl(1+2**(2*ibig))==1 */
	double copysign(),scalb(),logb(),sqrt(),temp;
	int finite(), exp;

D 2
	if(finite(real))
	    if(finite(imag))
E 2
I 2
	if(finite(x))
	    if(finite(y))
E 2
	    {	
D 2
		real=copysign(real,one);
		imag=copysign(imag,one);
		if(imag > real) 
		    { temp=real; real=imag; imag=temp; }
		if(real == zero) return(zero);
		if(imag == zero) return(real);
		exp= logb(real);
		real=scalb(real,-exp);
		if(exp-(int)logb(imag) > ibig ) 
			/* raise inexact flag and return |real| */
		   { one+small; return(scalb(real,exp)); }
		else imag=scalb(imag,-exp);
		return(scalb(sqrt(real*real+imag*imag),exp));
E 2
I 2
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
E 2
	    }

D 2
	    else if(imag==imag)   	   /* imag is +-INF */
		     return(copysign(imag,one));
E 2
I 2
	    else if(y==y)   	   /* y is +-INF */
		     return(copysign(y,one));
E 2
	    else 
D 2
		     return(imag);	   /* imag is NaN and x is finite */
E 2
I 2
		     return(y);	   /* y is NaN and x is finite */
E 2

D 2
	else if(real==real) 		   /* real is +-INF */
	         return (copysign(real,one));
	else if(finite(imag))
	         return(real);		   /* real is NaN, imag is finite */
	else if(imag!=imag) return(imag);  /* real and imag is NaN */
	else return(copysign(imag,one));   /* imag is INF */
E 2
I 2
	else if(x==x) 		   /* x is +-INF */
	         return (copysign(x,one));
	else if(finite(y))
	         return(x);		   /* x is NaN, y is finite */
	else if(y!=y) return(y);  	/* x and y is NaN */
	else return(copysign(y,one));   /* y is INF */
E 2
}
#endif
E 1
