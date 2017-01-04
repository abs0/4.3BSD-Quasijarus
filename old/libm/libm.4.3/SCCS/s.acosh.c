h20800
s 00017/00015/00066
d D 1.2 85/08/21 10:06:14 miriam 2 1
c Revision by Prof. Kahan.
e
s 00081/00000/00000
d D 1.1 85/05/23 13:57:27 miriam 1 0
c date and time created 85/05/23 13:57:27 by miriam
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

/* ACOSH(X)
 * RETURN THE INVERSE HYPERBOLIC COSINE OF X
 * DOUBLE PRECISION (VAX D FORMAT 56 BITS, IEEE DOUBLE 53 BITS)
 * CODED IN C BY K.C. NG, 2/16/85;
D 2
 * REVISED BY K.C. NG on 3/6/85, 3/24/85, 4/16/85.
E 2
I 2
 * REVISED BY K.C. NG on 3/6/85, 3/24/85, 4/16/85, 8/17/85.
E 2
 *
 * Required system supported functions :
 *	sqrt(x)
 *
 * Required kernel function:
D 2
 *	L(x) 		...return log(1+x)
E 2
I 2
 *	log1p(x) 		...return log(1+x)
E 2
 *
 * Method :
 *	Based on 
 *		acosh(x) = log [ x + sqrt(x*x-1) ]
 *	we have
D 2
 *		acosh(x) := L(x)+ln2,	if (x > 1.0E20); else		
 *		acosh(x) := L( sqrt(x-1) * (sqrt(x-1) + sqrt(x+1)) ) .
E 2
I 2
 *		acosh(x) := log1p(x)+ln2,	if (x > 1.0E20); else		
 *		acosh(x) := log1p( sqrt(x-1) * (sqrt(x-1) + sqrt(x+1)) ) .
E 2
 *	These formulae avoid the over/underflow complication.
 *
 * Special cases:
D 2
 *	acosh(x) is NAN with signal if x<1.
 *	acosh(NAN) is NAN without signal.
E 2
I 2
 *	acosh(x) is NaN with signal if x<1.
 *	acosh(NaN) is NaN without signal.
E 2
 *
 * Accuracy:
 *	acosh(x) returns the exact inverse hyperbolic cosine of x nearly 
D 2
 *	rounded. In a test run with 500,000 random arguments on a VAX, the
 *	maximum observed error was 3.20 ulps (units of the last place).
E 2
I 2
 *	rounded. In a test run with 512,000 random arguments on a VAX, the
 *	maximum observed error was 3.30 ulps (units of the last place) at
 *	x=1.0070493753568216 .
E 2
 *
 * Constants:
 * The hexadecimal values are the intended ones for the following constants.
 * The decimal values may be used, provided that the compiler will convert
 * from decimal to binary accurately enough to produce the hexadecimal values
 * shown.
 */

#ifdef VAX	/* VAX D format */
/* static double */
/* ln2hi  =  6.9314718055829871446E-1    , Hex  2^  0   *  .B17217F7D00000 */
/* ln2lo  =  1.6465949582897081279E-12   ; Hex  2^-39   *  .E7BCD5E4F1D9CC */
static long     ln2hix[] = { 0x72174031, 0x0000f7d0};
static long     ln2lox[] = { 0xbcd52ce7, 0xd9cce4f1};
#define    ln2hi    (*(double*)ln2hix)
#define    ln2lo    (*(double*)ln2lox)
D 2
#else		/* IEEE double format */
E 2
I 2
#else	/* IEEE double */
E 2
static double
ln2hi  =  6.9314718036912381649E-1    , /*Hex  2^ -1   *  1.62E42FEE00000 */
ln2lo  =  1.9082149292705877000E-10   ; /*Hex  2^-33   *  1.A39EF35793C76 */
#endif

double acosh(x)
double x;
{	
D 2
	double L(),sqrt(),t,big=1.E20; /* big+1==big */
E 2
I 2
	double log1p(),sqrt(),t,big=1.E20; /* big+1==big */
E 2

D 2
    /* x is NaN */
	if(x!=x) return(x);	
E 2
I 2
#ifndef VAX
	if(x!=x) return(x);	/* x is NaN */
#endif
E 2

D 2
    /* return L(2x) for large x */
	if(x>big) {t=L(x)+ln2lo; return(t+ln2hi);} 
E 2
I 2
    /* return log1p(x) + log(2) if x is large */
	if(x>big) {t=log1p(x)+ln2lo; return(t+ln2hi);} 
E 2

	t=sqrt(x-1.0);
D 2
	return(L(t*(t+sqrt(x+1.0))));
E 2
I 2
	return(log1p(t*(t+sqrt(x+1.0))));
E 2
}
E 1
