h01383
s 00024/00011/00038
d D 1.2 85/08/21 10:09:01 miriam 2 1
c Revision by Prof. Kahan.
e
s 00049/00000/00000
d D 1.1 85/05/23 14:02:40 miriam 1 0
c date and time created 85/05/23 14:02:40 by miriam
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

/* ATANH(X)
 * RETURN THE HYPERBOLIC ARC TANGENT OF X
 * DOUBLE PRECISION (VAX D format 56 bits, IEEE DOUBLE 53 BITS)
 * CODED IN C BY K.C. NG, 1/8/85; 
D 2
 * REVISED BY K.C. NG on 2/7/85, 3/7/85.
E 2
I 2
 * REVISED BY K.C. NG on 2/7/85, 3/7/85, 8/18/85.
E 2
 *
 * Required kernel function:
D 2
 *	L(x) 	...return log(1+x)
E 2
I 2
 *	log1p(x) 	...return log(1+x)
E 2
 *
 * Method :
 *	Return 
D 2
 *                         log(1+x) - log(1-x)   L(x) - L(-x)
 *		atanh(x) = ------------------- = ------------ .
 *                                  2                 2
E 2
I 2
 *                          1              2x                          x
 *		atanh(x) = --- * log(1 + -------) = 0.5 * log1p(2 * --------)
 *                          2             1 - x                      1 - x
E 2
 *
 * Special cases:
D 2
 *	atanh(x) is NAN if |x| > 1 with signal;
 *	atanh(NAN) is that NAN with no signal;
E 2
I 2
 *	atanh(x) is NaN if |x| > 1 with signal;
 *	atanh(NaN) is that NaN with no signal;
E 2
 *	atanh(+-1) is +-INF with signal.
 *
 * Accuracy:
 *	atanh(x) returns the exact hyperbolic arc tangent of x nearly rounded.
D 2
 *	In a test run with 200,000 random arguments on a VAX, the maximum
 *	observed error was 1.45 ulps (units in the last place).
E 2
I 2
 *	In a test run with 512,000 random arguments on a VAX, the maximum
 *	observed error was 1.87 ulps (units in the last place) at
 *	x= -3.8962076028810414000e-03.
E 2
 */
I 2
#ifdef VAX
#include <errno.h>
#endif
E 2

double atanh(x)
double x;
{
D 2
	double L();
	return( (L(x)-L(-x))/2.0 );
E 2
I 2
	double copysign(),log1p(),z;
	z = copysign(0.5,x);
	x = copysign(x,1.0);
#ifdef VAX
	if (x == 1.0) {
	    extern double infnan();
	    return(copysign(1.0,z)*infnan(ERANGE));	/* sign(x)*INF */
	}
#endif
	x = x/(1.0-x);
	return( z*log1p(x+x) );
E 2
}
E 1
