h56331
s 00010/00005/00152
d D 5.3 88/06/30 17:45:14 bostic 11 10
c install approved copyright notice
e
s 00016/00013/00141
d D 5.2 88/04/29 12:28:47 bostic 10 9
c add Berkeley specific copyright                            
e
s 00000/00000/00154
d D 5.1 87/11/30 18:33:56 bostic 9 8
c tahoe release
e
s 00009/00009/00145
d D 1.8 87/07/13 19:20:30 zliu 8 7
c clean-ups.
e
s 00015/00010/00139
d D 1.7 87/07/10 10:36:24 zliu 7 6
c adding _0x macro for TAHOE.
e
s 00002/00002/00147
d D 1.6 87/07/07 01:31:47 zliu 6 5
c first shot at TAHOE.
e
s 00001/00001/00148
d D 1.5 86/10/18 00:52:36 elefunt 5 4
c guarantee monotonicity
e
s 00037/00015/00112
d D 1.4 86/06/14 15:00:26 elefunt 4 3
c replace old algorithm by a faster one.  K.C. Ng   6/14/86
e
s 00002/00002/00125
d D 1.3 86/03/16 19:08:35 elefunt 3 2
c All instances of "double static" got converted to "static double",
c as it should be.
e
s 00002/00001/00125
d D 1.2 85/09/11 23:53:47 elefunt 2 1
c 4.3BSD version dated 09/11/85.
e
s 00126/00000/00000
d D 1.1 85/09/06 17:52:46 zliu 1 0
c date and time created 85/09/06 17:52:46 by zliu
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
"%Z%%M%	4.3 (Berkeley) 8/21/85; %I% (ucb.elefunt) %G%";
E 2
D 8
#endif not lint
E 8
I 8
#endif	/* not lint */
E 10
I 10
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 10
E 8

/* EXP(X)
 * RETURN THE EXPONENTIAL OF X
 * DOUBLE PRECISION (IEEE 53 bits, VAX D FORMAT 56 BITS)
 * CODED IN C BY K.C. NG, 1/19/85; 
D 4
 * REVISED BY K.C. NG on 2/6/85, 2/15/85, 3/7/85, 3/24/85, 4/16/85.
E 4
I 4
 * REVISED BY K.C. NG on 2/6/85, 2/15/85, 3/7/85, 3/24/85, 4/16/85, 6/14/86.
E 4
 *
 * Required system supported functions:
 *	scalb(x,n)	
 *	copysign(x,y)	
 *	finite(x)
 *
D 4
 * Kernel function:
 *	exp__E(x,c)
 *
E 4
 * Method:
 *	1. Argument Reduction: given the input x, find r and integer k such 
 *	   that
 *	                   x = k*ln2 + r,  |r| <= 0.5*ln2 .  
 *	   r will be represented as r := z+c for better accuracy.
 *
D 4
 *	2. Compute expm1(r)=exp(r)-1 by 
E 4
I 4
 *	2. Compute exp(r) by 
E 4
 *
D 4
 *			expm1(r=z+c) := z + exp__E(z,r)
E 4
I 4
 *		exp(r) = 1 + r + r*R1/(2-R1),
 *	   where
 *		R1 = x - x^2*(p1+x^2*(p2+x^2*(p3+x^2*(p4+p5*x^2)))).
E 4
 *
D 4
 *	3. exp(x) = 2^k * ( expm1(r) + 1 ).
E 4
I 4
 *	3. exp(x) = 2^k * exp(r) .
E 4
 *
 * Special cases:
 *	exp(INF) is INF, exp(NaN) is NaN;
 *	exp(-INF)=  0;
 *	for finite argument, only exp(0)=1 is exact.
 *
 * Accuracy:
 *	exp(x) returns the exponential of x nearly rounded. In a test run
 *	with 1,156,000 random arguments on a VAX, the maximum observed
D 4
 *	error was .768 ulps (units in the last place).
E 4
I 4
 *	error was 0.869 ulps (units in the last place).
E 4
 *
 * Constants:
 * The hexadecimal values are the intended ones for the following constants.
 * The decimal values may be used, provided that the compiler will convert
 * from decimal to binary accurately enough to produce the hexadecimal values
 * shown.
 */

D 6
#ifdef VAX	/* VAX D format */
E 6
I 6
D 8
#if (defined(VAX)||defined(TAHOE))	/* VAX D format */
I 7
#ifdef VAX
E 8
I 8
#if defined(vax)||defined(tahoe)	/* VAX D format */
#ifdef vax
E 8
#define _0x(A,B)	0x/**/A/**/B
D 8
#else	/* VAX */
E 8
I 8
#else	/* vax */
E 8
#define _0x(A,B)	0x/**/B/**/A
D 8
#endif	/* VAX */
E 8
I 8
#endif	/* vax */
E 8
E 7
E 6
D 3
/* double static */
E 3
I 3
/* static double */
E 3
/* ln2hi  =  6.9314718055829871446E-1    , Hex  2^  0   *  .B17217F7D00000 */
/* ln2lo  =  1.6465949582897081279E-12   , Hex  2^-39   *  .E7BCD5E4F1D9CC */
/* lnhuge =  9.4961163736712506989E1     , Hex  2^  7   *  .BDEC1DA73E9010 */
/* lntiny = -9.5654310917272452386E1     , Hex  2^  7   * -.BF4F01D72E33AF */
/* invln2 =  1.4426950408889634148E0     ; Hex  2^  1   *  .B8AA3B295C17F1 */
I 4
/* p1     =  1.6666666666666602251E-1    , Hex  2^-2    *  .AAAAAAAAAAA9F1 */
/* p2     = -2.7777777777015591216E-3    , Hex  2^-8    * -.B60B60B5F5EC94 */
/* p3     =  6.6137563214379341918E-5    , Hex  2^-13   *  .8AB355792EF15F */
/* p4     = -1.6533902205465250480E-6    , Hex  2^-19   * -.DDEA0E2E935F84 */
/* p5     =  4.1381367970572387085E-8    , Hex  2^-24   *  .B1BB4B95F52683 */
E 4
D 7
static long     ln2hix[] = { 0x72174031, 0x0000f7d0};
static long     ln2lox[] = { 0xbcd52ce7, 0xd9cce4f1};
static long    lnhugex[] = { 0xec1d43bd, 0x9010a73e};
static long    lntinyx[] = { 0x4f01c3bf, 0x33afd72e};
static long    invln2x[] = { 0xaa3b40b8, 0x17f1295c};
I 4
static long        p1x[] = { 0xaaaa3f2a, 0xa9f1aaaa};
static long        p2x[] = { 0x0b60bc36, 0xec94b5f5};
static long        p3x[] = { 0xb355398a, 0xf15f792e};
static long        p4x[] = { 0xea0eb6dd, 0x5f842e93};
static long        p5x[] = { 0xbb4b3431, 0x268395f5};
E 7
I 7
static long     ln2hix[] = { _0x(7217,4031), _0x(0000,f7d0)};
static long     ln2lox[] = { _0x(bcd5,2ce7), _0x(d9cc,e4f1)};
static long    lnhugex[] = { _0x(ec1d,43bd), _0x(9010,a73e)};
static long    lntinyx[] = { _0x(4f01,c3bf), _0x(33af,d72e)};
static long    invln2x[] = { _0x(aa3b,40b8), _0x(17f1,295c)};
static long        p1x[] = { _0x(aaaa,3f2a), _0x(a9f1,aaaa)};
static long        p2x[] = { _0x(0b60,bc36), _0x(ec94,b5f5)};
static long        p3x[] = { _0x(b355,398a), _0x(f15f,792e)};
static long        p4x[] = { _0x(ea0e,b6dd), _0x(5f84,2e93)};
static long        p5x[] = { _0x(bb4b,3431), _0x(2683,95f5)};
E 7
E 4
#define    ln2hi    (*(double*)ln2hix)
#define    ln2lo    (*(double*)ln2lox)
#define   lnhuge    (*(double*)lnhugex)
#define   lntiny    (*(double*)lntinyx)
#define   invln2    (*(double*)invln2x)
I 4
#define       p1    (*(double*)p1x)
#define       p2    (*(double*)p2x)
#define       p3    (*(double*)p3x)
#define       p4    (*(double*)p4x)
#define       p5    (*(double*)p5x)

E 4
D 8
#else	/* IEEE double */
E 8
I 8
#else	/* defined(vax)||defined(tahoe)	*/
E 8
D 3
double static
E 3
I 3
static double
I 4
p1     =  1.6666666666666601904E-1    , /*Hex  2^-3    *  1.555555555553E */
p2     = -2.7777777777015593384E-3    , /*Hex  2^-9    * -1.6C16C16BEBD93 */
p3     =  6.6137563214379343612E-5    , /*Hex  2^-14   *  1.1566AAF25DE2C */
p4     = -1.6533902205465251539E-6    , /*Hex  2^-20   * -1.BBD41C5D26BF1 */
p5     =  4.1381367970572384604E-8    , /*Hex  2^-25   *  1.6376972BEA4D0 */
E 4
E 3
ln2hi  =  6.9314718036912381649E-1    , /*Hex  2^ -1   *  1.62E42FEE00000 */
ln2lo  =  1.9082149292705877000E-10   , /*Hex  2^-33   *  1.A39EF35793C76 */
lnhuge =  7.1602103751842355450E2     , /*Hex  2^  9   *  1.6602B15B7ECF2 */
lntiny = -7.5137154372698068983E2     , /*Hex  2^  9   * -1.77AF8EBEAE354 */
invln2 =  1.4426950408889633870E0     ; /*Hex  2^  0   *  1.71547652B82FE */
D 8
#endif
E 8
I 8
#endif	/* defined(vax)||defined(tahoe)	*/
E 8

double exp(x)
double x;
{
D 4
	double scalb(), copysign(), exp__E(), z,hi,lo,c;
E 4
I 4
	double scalb(), copysign(), z,hi,lo,c;
E 4
	int k,finite();

D 6
#ifndef VAX
E 6
I 6
D 8
#if (!defined(VAX)&&!defined(TAHOE))
E 8
I 8
#if !defined(vax)&&!defined(tahoe)
E 8
E 6
	if(x!=x) return(x);	/* x is NaN */
D 8
#endif
E 8
I 8
#endif	/* !defined(vax)&&!defined(tahoe) */
E 8
	if( x <= lnhuge ) {
		if( x >= lntiny ) {

		    /* argument reduction : x --> x - k*ln2 */

			k=invln2*x+copysign(0.5,x);	/* k=NINT(x/ln2) */

D 4
			/* express x-k*ln2 as z+c */
E 4
I 4
		    /* express x-k*ln2 as hi-lo and let x=hi-lo rounded */

E 4
			hi=x-k*ln2hi;
D 4
			z=hi-(lo=k*ln2lo);
			c=(hi-z)-lo;
E 4
I 4
			x=hi-(lo=k*ln2lo);
E 4

D 4
		    /* return 2^k*[expm1(x) + 1]  */
			z += exp__E(z,c);
			return (scalb(z+1.0,k));  
E 4
I 4
		    /* return 2^k*[1+x+x*c/(2+c)]  */
			z=x*x;
			c= x - z*(p1+z*(p2+z*(p3+z*(p4+z*p5))));
D 5
			return  scalb(1.0+(hi-(lo-x*c/(2.0-c))),k);
E 5
I 5
			return  scalb(1.0+(hi-(lo-(x*c)/(2.0-c))),k);
E 5

E 4
		}
		/* end of x > lntiny */

		else 
		     /* exp(-big#) underflows to zero */
		     if(finite(x))  return(scalb(1.0,-5000));

		     /* exp(-INF) is zero */
		     else return(0.0);
	}
	/* end of x < lnhuge */

	else 
	/* exp(INF) is INF, exp(+big#) overflows to INF */
	    return( finite(x) ?  scalb(1.0,5000)  : x);
}
E 1
