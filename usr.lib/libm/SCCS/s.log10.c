h30990
s 00010/00005/00080
d D 5.3 88/06/30 17:45:25 bostic 8 7
c install approved copyright notice
e
s 00016/00013/00069
d D 5.2 88/04/29 12:41:58 bostic 7 6
c add Berkeley specific header
e
s 00000/00000/00082
d D 5.1 87/11/30 18:34:05 bostic 6 5
c tahoe release
e
s 00010/00010/00072
d D 1.5 87/07/13 19:20:44 zliu 5 4
c clean-ups.
e
s 00006/00001/00076
d D 1.4 87/07/10 10:36:31 zliu 4 3
c adding _0x macro for TAHOE.
e
s 00002/00002/00075
d D 1.3 87/07/07 01:32:02 zliu 3 2
c first shot at TAHOE.
e
s 00002/00001/00075
d D 1.2 85/09/11 23:54:25 elefunt 2 1
c 4.3BSD version dated 09/11/85.
e
s 00076/00000/00000
d D 1.1 85/09/06 17:53:00 zliu 1 0
c date and time created 85/09/06 17:53:00 by zliu
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

/* LOG10(X)
 * RETURN THE BASE 10 LOGARITHM OF x
 * DOUBLE PRECISION (VAX D format 56 bits, IEEE DOUBLE 53 BITS)
 * CODED IN C BY K.C. NG, 1/20/85; 
 * REVISED BY K.C. NG on 1/23/85, 3/7/85, 4/16/85.
 * 
 * Required kernel function:
 *	log(x)
 *
 * Method :
 *			     log(x)
 *		log10(x) = ---------  or  [1/log(10)]*log(x)
 *			    log(10)
 *
 *    Note:
 *	  [log(10)]   rounded to 56 bits has error  .0895  ulps,
 *	  [1/log(10)] rounded to 53 bits has error  .198   ulps;
 *	  therefore, for better accuracy, in VAX D format, we divide 
 *	  log(x) by log(10), but in IEEE Double format, we multiply 
 *	  log(x) by [1/log(10)].
 *
 * Special cases:
 *	log10(x) is NaN with signal if x < 0; 
 *	log10(+INF) is +INF with no signal; log10(0) is -INF with signal;
 *	log10(NaN) is that NaN with no signal.
 *
 * Accuracy:
 *	log10(X) returns the exact log10(x) nearly rounded. In a test run
 *	with 1,536,000 random arguments on a VAX, the maximum observed
 *	error was 1.74 ulps (units in the last place).
 *
 * Constants:
 * The hexadecimal values are the intended ones for the following constants.
 * The decimal values may be used, provided that the compiler will convert
 * from decimal to binary accurately enough to produce the hexadecimal values
 * shown.
 */

D 3
#ifdef VAX	/* VAX D format (56 bits) */
E 3
I 3
D 5
#if (defined(VAX)||defined(TAHOE))	/* VAX D format (56 bits) */
I 4
#ifdef VAX
E 5
I 5
#if defined(vax)||defined(tahoe)	/* VAX D format (56 bits) */
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
/* ln10hi =  2.3025850929940456790E0     ; Hex   2^  2   *  .935D8DDDAAA8AC */
D 4
static long    ln10hix[] = { 0x5d8d4113, 0xa8acddaa};
E 4
I 4
static long    ln10hix[] = { _0x(5d8d,4113), _0x(a8ac,ddaa)};
E 4
#define   ln10hi    (*(double*)ln10hix)
D 5
#else	/* IEEE double */
E 5
I 5
#else	/* defined(vax)||defined(tahoe)	*/
E 5
static double
ivln10 =  4.3429448190325181667E-1    ; /*Hex   2^ -2   *  1.BCB7B1526E50E */
D 5
#endif
E 5
I 5
#endif	/* defined(vax)||defined(tahoe)	*/
E 5

double log10(x)
double x;
{
	double log();

D 3
#ifdef VAX
E 3
I 3
D 5
#if (defined(VAX)||defined(TAHOE))
E 5
I 5
#if defined(vax)||defined(tahoe)
E 5
E 3
	return(log(x)/ln10hi);
D 5
#else	/* IEEE double */
E 5
I 5
#else	/* defined(vax)||defined(tahoe) */
E 5
	return(ivln10*log(x));
D 5
#endif
E 5
I 5
#endif	/* defined(vax)||defined(tahoe) */
E 5
}
E 1
