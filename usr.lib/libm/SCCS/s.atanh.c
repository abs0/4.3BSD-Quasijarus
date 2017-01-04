h16950
s 00010/00005/00061
d D 5.3 88/06/30 17:45:10 bostic 7 6
c install approved copyright notice
e
s 00016/00013/00050
d D 5.2 88/04/29 12:28:43 bostic 6 5
c add Berkeley specific copyright                            
e
s 00000/00000/00063
d D 5.1 87/11/30 18:33:53 bostic 5 4
c tahoe release
e
s 00005/00005/00058
d D 1.4 87/07/13 19:20:27 zliu 4 3
c clean-ups.
e
s 00002/00002/00061
d D 1.3 87/07/07 01:31:44 zliu 3 2
c first shot at TAHOE.
e
s 00002/00001/00061
d D 1.2 85/09/11 23:53:35 elefunt 2 1
c 4.3BSD version dated 09/11/85.
e
s 00062/00000/00000
d D 1.1 85/09/06 17:52:42 zliu 1 0
c date and time created 85/09/06 17:52:42 by zliu
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
"%Z%%M%	1.2 (Berkeley) 8/21/85; %I% (ucb.elefunt) %G%";
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

/* ATANH(X)
 * RETURN THE HYPERBOLIC ARC TANGENT OF X
 * DOUBLE PRECISION (VAX D format 56 bits, IEEE DOUBLE 53 BITS)
 * CODED IN C BY K.C. NG, 1/8/85; 
 * REVISED BY K.C. NG on 2/7/85, 3/7/85, 8/18/85.
 *
 * Required kernel function:
 *	log1p(x) 	...return log(1+x)
 *
 * Method :
 *	Return 
 *                          1              2x                          x
 *		atanh(x) = --- * log(1 + -------) = 0.5 * log1p(2 * --------)
 *                          2             1 - x                      1 - x
 *
 * Special cases:
 *	atanh(x) is NaN if |x| > 1 with signal;
 *	atanh(NaN) is that NaN with no signal;
 *	atanh(+-1) is +-INF with signal.
 *
 * Accuracy:
 *	atanh(x) returns the exact hyperbolic arc tangent of x nearly rounded.
 *	In a test run with 512,000 random arguments on a VAX, the maximum
 *	observed error was 1.87 ulps (units in the last place) at
 *	x= -3.8962076028810414000e-03.
 */
D 3
#ifdef VAX
E 3
I 3
D 4
#if (defined(VAX)||defined(TAHOE))
E 4
I 4
#if defined(vax)||defined(tahoe)
E 4
E 3
#include <errno.h>
D 4
#endif
E 4
I 4
#endif	/* defined(vax)||defined(tahoe) */
E 4

double atanh(x)
double x;
{
	double copysign(),log1p(),z;
	z = copysign(0.5,x);
	x = copysign(x,1.0);
D 3
#ifdef VAX
E 3
I 3
D 4
#if (defined(VAX)||defined(TAHOE))
E 4
I 4
#if defined(vax)||defined(tahoe)
E 4
E 3
	if (x == 1.0) {
	    extern double infnan();
	    return(copysign(1.0,z)*infnan(ERANGE));	/* sign(x)*INF */
	}
D 4
#endif
E 4
I 4
#endif	/* defined(vax)||defined(tahoe) */
E 4
	x = x/(1.0-x);
	return( z*log1p(x+x) );
}
E 1
