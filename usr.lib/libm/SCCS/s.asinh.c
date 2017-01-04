h52152
s 00010/00005/00087
d D 5.3 88/06/30 17:45:07 bostic 7 6
c install approved copyright notice
e
s 00016/00013/00076
d D 5.2 88/04/29 12:28:40 bostic 6 5
c add Berkeley specific copyright                            
e
s 00000/00000/00089
d D 5.1 87/11/30 18:33:51 bostic 5 4
c tahoe release
e
s 00009/00009/00080
d D 1.4 87/07/13 19:20:26 zliu 4 3
c clean-ups.
e
s 00009/00004/00080
d D 1.3 87/07/10 10:36:21 zliu 3 2
c adding _0x macro for TAHOE.
e
s 00002/00001/00082
d D 1.2 85/09/11 23:53:28 elefunt 2 1
c 4.3BSD version dated 09/11/85.
e
s 00083/00000/00000
d D 1.1 85/09/06 17:52:39 zliu 1 0
c date and time created 85/09/06 17:52:39 by zliu
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

/* ASINH(X)
 * RETURN THE INVERSE HYPERBOLIC SINE OF X
 * DOUBLE PRECISION (VAX D format 56 bits, IEEE DOUBLE 53 BITS)
 * CODED IN C BY K.C. NG, 2/16/85;
 * REVISED BY K.C. NG on 3/7/85, 3/24/85, 4/16/85.
 *
 * Required system supported functions :
 *	copysign(x,y)
 *	sqrt(x)
 *
 * Required kernel function:
 *	log1p(x) 		...return log(1+x)
 *
 * Method :
 *	Based on 
 *		asinh(x) = sign(x) * log [ |x| + sqrt(x*x+1) ]
 *	we have
 *	asinh(x) := x  if  1+x*x=1,
 *		 := sign(x)*(log1p(x)+ln2))	 if sqrt(1+x*x)=x, else
 *		 := sign(x)*log1p(|x| + |x|/(1/|x| + sqrt(1+(1/|x|)^2)) )  
 *
 * Accuracy:
 *	asinh(x) returns the exact inverse hyperbolic sine of x nearly rounded.
 *	In a test run with 52,000 random arguments on a VAX, the maximum 
 *	observed error was 1.58 ulps (units in the last place).
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
D 4
#if (defined(VAX)||defined(TAHOE))	/* VAX D format */
#ifdef VAX
E 4
I 4
#if defined(vax)||defined(tahoe)	/* VAX/TAHOE D format */
#ifdef vax
E 4
#define _0x(A,B)	0x/**/A/**/B
D 4
#else	/* VAX */
E 4
I 4
#else	/* vax */
E 4
#define _0x(A,B)	0x/**/B/**/A
D 4
#endif	/* VAX */
E 4
I 4
#endif	/* vax */
E 4
E 3
/* static double */
/* ln2hi  =  6.9314718055829871446E-1    , Hex  2^  0   *  .B17217F7D00000 */
/* ln2lo  =  1.6465949582897081279E-12   ; Hex  2^-39   *  .E7BCD5E4F1D9CC */
D 3
static long     ln2hix[] = { 0x72174031, 0x0000f7d0};
static long     ln2lox[] = { 0xbcd52ce7, 0xd9cce4f1};
E 3
I 3
static long     ln2hix[] = { _0x(7217,4031), _0x(0000,f7d0)};
static long     ln2lox[] = { _0x(bcd5,2ce7), _0x(d9cc,e4f1)};
E 3
#define    ln2hi    (*(double*)ln2hix)
#define    ln2lo    (*(double*)ln2lox)
D 4
#else	/* IEEE double */
E 4
I 4
#else	/* defined(vax)||defined(tahoe) */
E 4
static double
ln2hi  =  6.9314718036912381649E-1    , /*Hex  2^ -1   *  1.62E42FEE00000 */
ln2lo  =  1.9082149292705877000E-10   ; /*Hex  2^-33   *  1.A39EF35793C76 */
D 4
#endif
E 4
I 4
#endif	/* defined(vax)||defined(tahoe) */
E 4

double asinh(x)
double x;
{	
	double copysign(),log1p(),sqrt(),t,s;
	static double small=1.0E-10,	/* fl(1+small*small) == 1 */
		      big  =1.0E20,	/* fl(1+big) == big */
		      one  =1.0   ;	

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
	if((t=copysign(x,one))>small) 
	    if(t<big) {
	     	s=one/t; return(copysign(log1p(t+t/(s+sqrt(one+s*s))),x)); }
	    else	/* if |x| > big */
		{s=log1p(t)+ln2lo; return(copysign(s+ln2hi,x));}
	else	/* if |x| < small */
	    return(x);
}
E 1
