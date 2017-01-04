h27596
s 00010/00005/00118
d D 5.3 88/06/30 17:45:12 bostic 9 8
c install approved copyright notice
e
s 00016/00013/00107
d D 5.2 88/04/29 12:28:45 bostic 8 7
c add Berkeley specific copyright                            
e
s 00000/00000/00120
d D 5.1 87/11/30 18:33:54 bostic 7 6
c tahoe release
e
s 00012/00012/00108
d D 1.6 87/07/13 19:20:28 zliu 6 5
c clean-ups.
e
s 00008/00003/00112
d D 1.5 87/07/10 10:36:22 zliu 5 4
c adding _0x macro for TAHOE.
e
s 00003/00003/00112
d D 1.4 87/07/07 01:31:45 zliu 4 3
c first shot at TAHOE.
e
s 00002/00002/00113
d D 1.3 86/03/16 19:08:31 elefunt 3 2
c All instances of "double static" got converted to "static double",
c as it should be.
e
s 00002/00001/00113
d D 1.2 85/09/11 23:53:39 elefunt 2 1
c 4.3BSD version dated 09/11/85.
e
s 00114/00000/00000
d D 1.1 85/09/06 17:52:43 zliu 1 0
c date and time created 85/09/06 17:52:43 by zliu
e
u
U
t
T
I 1
D 8
/* 
E 8
I 8
/*
E 8
 * Copyright (c) 1985 Regents of the University of California.
D 8
 * 
 * Use and reproduction of this software are granted  in  accordance  with
 * the terms and conditions specified in  the  Berkeley  Software  License
 * Agreement (in particular, this entails acknowledgement of the programs'
 * source, and inclusion of this notice) with the additional understanding
 * that  all  recipients  should regard themselves as participants  in  an
 * ongoing  research  project and hence should  feel  obligated  to report
 * their  experiences (good or bad) with these elementary function  codes,
 * using "sendbug 4bsd-bugs@BERKELEY", to the authors.
E 8
I 8
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 9
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 9
I 9
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
E 9
 *
 * All recipients should regard themselves as participants in an ongoing
 * research project and hence should feel obligated to report their
 * experiences (good or bad) with these elementary function codes, using
 * the sendbug(8) program, to the authors.
E 8
 */

#ifndef lint
D 2
static char sccsid[] = "%W% (ELEFUNT) %G%";
E 2
I 2
D 8
static char sccsid[] =
"%Z%%M%	1.2 (Berkeley) 8/21/85; %I% (ucb.elefunt) %G%";
E 2
D 6
#endif not lint
E 6
I 6
#endif	/* not lint */
E 8
I 8
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 8
E 6

/* COSH(X)
 * RETURN THE HYPERBOLIC COSINE OF X
 * DOUBLE PRECISION (VAX D format 56 bits, IEEE DOUBLE 53 BITS)
 * CODED IN C BY K.C. NG, 1/8/85; 
 * REVISED BY K.C. NG on 2/8/85, 2/23/85, 3/7/85, 3/29/85, 4/16/85.
 *
 * Required system supported functions :
 *	copysign(x,y)
 *	scalb(x,N)
 *
 * Required kernel function:
 *	exp(x) 
 *	exp__E(x,c)	...return exp(x+c)-1-x for |x|<0.3465
 *
 * Method :
 *	1. Replace x by |x|. 
 *	2. 
 *		                                        [ exp(x) - 1 ]^2 
 *	    0        <= x <= 0.3465  :  cosh(x) := 1 + -------------------
 *			       			           2*exp(x)
 *
 *		                                   exp(x) +  1/exp(x)
 *	    0.3465   <= x <= 22      :  cosh(x) := -------------------
 *			       			           2
 *	    22       <= x <= lnovfl  :  cosh(x) := exp(x)/2 
 *	    lnovfl   <= x <= lnovfl+log(2)
 *				     :  cosh(x) := exp(x)/2 (avoid overflow)
 *	    log(2)+lnovfl <  x <  INF:  overflow to INF
 *
 *	Note: .3465 is a number near one half of ln2.
 *
 * Special cases:
 *	cosh(x) is x if x is +INF, -INF, or NaN.
 *	only cosh(0)=1 is exact for finite x.
 *
 * Accuracy:
 *	cosh(x) returns the exact hyperbolic cosine of x nearly rounded.
 *	In a test run with 768,000 random arguments on a VAX, the maximum
 *	observed error was 1.23 ulps (units in the last place).
 *
 * Constants:
 * The hexadecimal values are the intended ones for the following constants.
 * The decimal values may be used, provided that the compiler will convert
 * from decimal to binary accurately enough to produce the hexadecimal values
 * shown.
 */

D 4
#ifdef VAX
E 4
I 4
D 6
#if (defined(VAX)||defined(TAHOE))
I 5
#ifdef VAX
E 6
I 6
#if defined(vax)||defined(tahoe)
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
E 5
E 4
D 3
/* double static  */
E 3
I 3
/* static double  */
E 3
/* mln2hi =  8.8029691931113054792E1     , Hex  2^  7   *  .B00F33C7E22BDB */
/* mln2lo = -4.9650192275318476525E-16   , Hex  2^-50   * -.8F1B60279E582A */
/* lnovfl =  8.8029691931113053016E1     ; Hex  2^  7   *  .B00F33C7E22BDA */
D 5
static long    mln2hix[] = { 0x0f3343b0, 0x2bdbc7e2};
static long    mln2lox[] = { 0x1b60a70f, 0x582a279e};
static long    lnovflx[] = { 0x0f3343b0, 0x2bdac7e2};
E 5
I 5
static long    mln2hix[] = { _0x(0f33,43b0), _0x(2bdb,c7e2)};
static long    mln2lox[] = { _0x(1b60,a70f), _0x(582a,279e)};
static long    lnovflx[] = { _0x(0f33,43b0), _0x(2bda,c7e2)};
E 5
#define   mln2hi    (*(double*)mln2hix)
#define   mln2lo    (*(double*)mln2lox)
#define   lnovfl    (*(double*)lnovflx)
D 6
#else	/* IEEE double */
E 6
I 6
#else	/* defined(vax)||defined(tahoe) */
E 6
D 3
double static 
E 3
I 3
static double
E 3
mln2hi =  7.0978271289338397310E2     , /*Hex  2^ 10   *  1.62E42FEFA39EF */
mln2lo =  2.3747039373786107478E-14   , /*Hex  2^-45   *  1.ABC9E3B39803F */
lnovfl =  7.0978271289338397310E2     ; /*Hex  2^  9   *  1.62E42FEFA39EF */
D 6
#endif
E 6
I 6
#endif	/* defined(vax)||defined(tahoe) */
E 6

D 4
#ifdef VAX
E 4
I 4
D 6
#if (defined(VAX)||defined(TAHOE))
E 6
I 6
#if defined(vax)||defined(tahoe)
E 6
E 4
static max = 126                      ;
D 6
#else	/* IEEE double */
E 6
I 6
#else	/* defined(vax)||defined(tahoe) */
E 6
static max = 1023                     ;
D 6
#endif
E 6
I 6
#endif	/* defined(vax)||defined(tahoe) */
E 6

double cosh(x)
double x;
{	
	static double half=1.0/2.0,one=1.0, small=1.0E-18; /* fl(1+small)==1 */
	double scalb(),copysign(),exp(),exp__E(),t;

D 4
#ifndef VAX
E 4
I 4
D 6
#if (!defined(VAX)&&!defined(TAHOE))
E 6
I 6
#if !defined(vax)&&!defined(tahoe)
E 6
E 4
	if(x!=x) return(x);	/* x is NaN */
D 6
#endif
E 6
I 6
#endif	/* !defined(vax)&&!defined(tahoe) */
E 6
	if((x=copysign(x,one)) <= 22)
	    if(x<0.3465) 
		if(x<small) return(one+x);
		else {t=x+exp__E(x,0.0);x=t+t; return(one+t*t/(2.0+x)); }

	    else /* for x lies in [0.3465,22] */
	        { t=exp(x); return((t+one/t)*half); }

	if( lnovfl <= x && x <= (lnovfl+0.7)) 
        /* for x lies in [lnovfl, lnovfl+ln2], decrease x by ln(2^(max+1)) 
         * and return 2^max*exp(x) to avoid unnecessary overflow 
         */
	    return(scalb(exp((x-mln2hi)-mln2lo), max)); 

	else 
	    return(exp(x)*half);	/* for large x,  cosh(x)=exp(x)/2 */
}
E 1
