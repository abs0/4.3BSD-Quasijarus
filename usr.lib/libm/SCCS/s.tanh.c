h41060
s 00010/00005/00078
d D 5.3 88/06/30 17:45:39 bostic 7 6
c install approved copyright notice
e
s 00016/00013/00067
d D 5.2 88/04/29 12:42:08 bostic 6 5
c add Berkeley specific header
e
s 00000/00000/00080
d D 5.1 87/11/30 18:34:12 bostic 5 4
c tahoe release
e
s 00003/00003/00077
d D 1.4 87/07/13 19:20:51 zliu 4 3
c clean-ups.
e
s 00001/00001/00079
d D 1.3 87/07/07 01:32:13 zliu 3 2
c first shot at TAHOE.
e
s 00002/00001/00078
d D 1.2 85/09/11 23:54:50 elefunt 2 1
c 4.3BSD version dated 09/11/85.
e
s 00079/00000/00000
d D 1.1 85/09/06 17:53:08 zliu 1 0
c date and time created 85/09/06 17:53:08 by zliu
e
u
U
t
T
I 1
D 6
/* 
E 6
I 6
/*
E 6
 * Copyright (c) 1985 Regents of the University of California.
D 6
 * 
 * Use and reproduction of this software are granted  in  accordance  with
 * the terms and conditions specified in  the  Berkeley  Software  License
 * Agreement (in particular, this entails acknowledgement of the programs'
 * source, and inclusion of this notice) with the additional understanding
 * that  all  recipients  should regard themselves as participants  in  an
 * ongoing  research  project and hence should  feel  obligated  to report
 * their  experiences (good or bad) with these elementary function  codes,
 * using "sendbug 4bsd-bugs@BERKELEY", to the authors.
E 6
I 6
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 7
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 7
I 7
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
E 7
 *
 * All recipients should regard themselves as participants in an ongoing
 * research project and hence should feel obligated to report their
 * experiences (good or bad) with these elementary function codes, using
 * the sendbug(8) program, to the authors.
E 6
 */

#ifndef lint
D 2
static char sccsid[] = "%W% (ELEFUNT) %G%";
E 2
I 2
D 6
static char sccsid[] =
"%Z%%M%	4.3 (Berkeley) 8/21/85; %I% (ucb.elefunt) %G%";
E 2
D 4
#endif not lint
E 4
I 4
#endif	/* not lint */
E 6
I 6
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 6
E 4

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
 *	expm1(x)	...exp(x)-1
 *
 * Method :
 *	1. reduce x to non-negative by tanh(-x) = - tanh(x).
 *	2.
 *	    0      <  x <=  1.e-10 :  tanh(x) := x
 *					          -expm1(-2x)
 *	    1.e-10 <  x <=  1      :  tanh(x) := --------------
 *					         expm1(-2x) + 2
 *							  2
 *	    1      <= x <=  22.0   :  tanh(x) := 1 -  ---------------
 *						      expm1(2x) + 2
 *	    22.0   <  x <= INF     :  tanh(x) := 1.
 *
 *	Note: 22 was chosen so that fl(1.0+2/(expm1(2*22)+2)) == 1.
 *
 * Special cases:
 *	tanh(NaN) is NaN;
 *	only tanh(0)=0 is exact for finite argument.
 *
 * Accuracy:
 *	tanh(x) returns the exact hyperbolic tangent of x nealy rounded.
 *	In a test run with 1,024,000 random arguments on a VAX, the maximum
 *	observed error was 2.22 ulps (units in the last place).
 */

double tanh(x)
double x;
{
	static double one=1.0, two=2.0, small = 1.0e-10, big = 1.0e10;
	double expm1(), t, copysign(), sign;
	int finite();

D 3
#ifndef VAX
E 3
I 3
D 4
#if (!defined(VAX)&&!defined(TAHOE))
E 4
I 4
#if !defined(vax)&&!defined(tahoe)
E 4
E 3
	if(x!=x) return(x);	/* x is NaN */
D 4
#endif
E 4
I 4
#endif	/* !defined(vax)&&!defined(tahoe) */
E 4

	sign=copysign(one,x);
	x=copysign(x,one);
	if(x < 22.0) 
	    if( x > one )
		return(copysign(one-two/(expm1(x+x)+two),sign));
	    else if ( x > small )
		{t= -expm1(-(x+x)); return(copysign(t/(two-t),sign));}
	    else		/* raise the INEXACT flag for non-zero x */
		{big+x; return(copysign(x,sign));}
	else if(finite(x))
	    return (sign+1.0E-37); /* raise the INEXACT flag */
	else
	    return(sign);	/* x is +- INF */
}
E 1
