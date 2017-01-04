h53116
s 00010/00005/00087
d D 5.3 88/06/30 17:45:03 bostic 8 7
c install approved copyright notice
e
s 00017/00013/00075
d D 5.2 88/04/29 12:28:37 bostic 7 6
c add Berkeley specific copyright                            
e
s 00000/00000/00088
d D 5.1 87/11/30 18:33:48 bostic 6 5
c tahoe release
e
s 00009/00009/00079
d D 1.5 87/07/13 19:20:22 zliu 5 4
c clean-ups.
e
s 00007/00003/00081
d D 1.4 87/07/10 10:36:19 zliu 4 3
c adding _0x macro for TAHOE.
e
s 00002/00002/00082
d D 1.3 87/07/07 01:31:39 zliu 3 2
c first shot at TAHOE.
e
s 00002/00001/00082
d D 1.2 85/09/11 23:53:18 elefunt 2 1
c 4.3BSD version dated 09/11/85.
e
s 00083/00000/00000
d D 1.1 85/09/06 17:52:36 zliu 1 0
c date and time created 85/09/06 17:52:36 by zliu
e
u
U
t
T
I 1
D 7
/* 
E 7
I 7
/*
E 7
 * Copyright (c) 1985 Regents of the University of California.
D 7
 * 
 * Use and reproduction of this software are granted  in  accordance  with
 * the terms and conditions specified in  the  Berkeley  Software  License
 * Agreement (in particular, this entails acknowledgement of the programs'
 * source, and inclusion of this notice) with the additional understanding
 * that  all  recipients  should regard themselves as participants  in  an
 * ongoing  research  project and hence should  feel  obligated  to report
 * their  experiences (good or bad) with these elementary function  codes,
 * using "sendbug 4bsd-bugs@BERKELEY", to the authors.
E 7
I 7
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 8
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 8
I 8
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
E 8
 *
 * All recipients should regard themselves as participants in an ongoing
 * research project and hence should feel obligated to report their
 * experiences (good or bad) with these elementary function codes, using
 * the sendbug(8) program, to the authors.
E 7
 */

#ifndef lint
D 2
static char sccsid[] = "%W% (ELEFUNT) %G%";
E 2
I 2
D 7
static char sccsid[] =
"%Z%%M%	1.2 (Berkeley) 8/21/85; %I% (ucb.elefunt) %G%";
E 2
D 5
#endif not lint
E 5
I 5
#endif	/* not lint */
E 7
I 7
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */

E 7
E 5
D 4

E 4
/* ACOSH(X)
 * RETURN THE INVERSE HYPERBOLIC COSINE OF X
 * DOUBLE PRECISION (VAX D FORMAT 56 BITS, IEEE DOUBLE 53 BITS)
 * CODED IN C BY K.C. NG, 2/16/85;
 * REVISED BY K.C. NG on 3/6/85, 3/24/85, 4/16/85, 8/17/85.
 *
 * Required system supported functions :
 *	sqrt(x)
 *
 * Required kernel function:
 *	log1p(x) 		...return log(1+x)
 *
 * Method :
 *	Based on 
 *		acosh(x) = log [ x + sqrt(x*x-1) ]
 *	we have
 *		acosh(x) := log1p(x)+ln2,	if (x > 1.0E20); else		
 *		acosh(x) := log1p( sqrt(x-1) * (sqrt(x-1) + sqrt(x+1)) ) .
 *	These formulae avoid the over/underflow complication.
 *
 * Special cases:
 *	acosh(x) is NaN with signal if x<1.
 *	acosh(NaN) is NaN without signal.
 *
 * Accuracy:
 *	acosh(x) returns the exact inverse hyperbolic cosine of x nearly 
 *	rounded. In a test run with 512,000 random arguments on a VAX, the
 *	maximum observed error was 3.30 ulps (units of the last place) at
 *	x=1.0070493753568216 .
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
D 5
#if (defined(VAX)||defined(TAHOE))	/* VAX D format */
I 4
#ifdef VAX
E 5
I 5
#if defined(vax)||defined(tahoe)	/* VAX D format */
#ifdef vax
E 5
#define _0x(A,B)	0x/**/A/**/B
D 5
#else	/* VAX */
E 5
I 5
#else	/* vax */
E 5
#define _0x(A,B)	0x/**/B/**/A
D 5
#endif	/* VAX */
E 5
I 5
#endif	/* vax */
E 5
E 4
E 3
/* static double */
/* ln2hi  =  6.9314718055829871446E-1    , Hex  2^  0   *  .B17217F7D00000 */
/* ln2lo  =  1.6465949582897081279E-12   ; Hex  2^-39   *  .E7BCD5E4F1D9CC */
D 4
static long     ln2hix[] = { 0x72174031, 0x0000f7d0};
static long     ln2lox[] = { 0xbcd52ce7, 0xd9cce4f1};
E 4
I 4
static long     ln2hix[] = { _0x(7217,4031), _0x(0000,f7d0)};
static long     ln2lox[] = { _0x(bcd5,2ce7), _0x(d9cc,e4f1)};
E 4
#define    ln2hi    (*(double*)ln2hix)
#define    ln2lo    (*(double*)ln2lox)
D 5
#else	/* IEEE double */
E 5
I 5
#else	/* defined(vax)||defined(tahoe) */
E 5
static double
ln2hi  =  6.9314718036912381649E-1    , /*Hex  2^ -1   *  1.62E42FEE00000 */
ln2lo  =  1.9082149292705877000E-10   ; /*Hex  2^-33   *  1.A39EF35793C76 */
D 5
#endif
E 5
I 5
#endif	/* defined(vax)||defined(tahoe) */
E 5

double acosh(x)
double x;
{	
	double log1p(),sqrt(),t,big=1.E20; /* big+1==big */

D 3
#ifndef VAX
E 3
I 3
D 5
#if (!defined(VAX)&&!defined(TAHOE))
E 5
I 5
#if !defined(vax)&&!defined(tahoe)
E 5
E 3
	if(x!=x) return(x);	/* x is NaN */
D 5
#endif
E 5
I 5
#endif	/* !defined(vax)&&!defined(tahoe) */
E 5

    /* return log1p(x) + log(2) if x is large */
	if(x>big) {t=log1p(x)+ln2lo; return(t+ln2hi);} 

	t=sqrt(x-1.0);
	return(log1p(t*(t+sqrt(x+1.0))));
}
E 1
