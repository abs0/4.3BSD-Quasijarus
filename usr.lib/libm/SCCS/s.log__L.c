h10702
s 00010/00005/00101
d D 5.3 88/06/30 17:45:32 bostic 8 7
c install approved copyright notice
e
s 00016/00013/00090
d D 5.2 88/04/29 12:42:01 bostic 7 6
c add Berkeley specific header
e
s 00000/00000/00103
d D 5.1 87/11/30 18:34:08 bostic 6 5
c tahoe release
e
s 00010/00010/00093
d D 1.5 87/07/13 19:20:46 zliu 5 4
c clean-ups.
e
s 00013/00008/00090
d D 1.4 87/07/10 10:36:34 zliu 4 3
c adding _0x macro for TAHOE.
e
s 00002/00002/00096
d D 1.3 87/07/07 01:32:05 zliu 3 2
c first shot at TAHOE.
e
s 00002/00001/00096
d D 1.2 85/09/11 23:54:35 elefunt 2 1
c 4.3BSD version dated 09/11/85.
e
s 00097/00000/00000
d D 1.1 85/09/06 17:53:03 zliu 1 0
c date and time created 85/09/06 17:53:03 by zliu
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

/* log__L(Z)
 *		LOG(1+X) - 2S			       X
 * RETURN      ---------------  WHERE Z = S*S,  S = ------- , 0 <= Z <= .0294...
 *		      S				     2 + X
 *		     
 * DOUBLE PRECISION (VAX D FORMAT 56 bits or IEEE DOUBLE 53 BITS)
 * KERNEL FUNCTION FOR LOG; TO BE USED IN LOG1P, LOG, AND POW FUNCTIONS
 * CODED IN C BY K.C. NG, 1/19/85; 
 * REVISED BY K.C. Ng, 2/3/85, 4/16/85.
 *
 * Method :
 *	1. Polynomial approximation: let s = x/(2+x). 
 *	   Based on log(1+x) = log(1+s) - log(1-s)
 *		 = 2s + 2/3 s**3 + 2/5 s**5 + .....,
 *
 *	   (log(1+x) - 2s)/s is computed by
 *
 *	       z*(L1 + z*(L2 + z*(... (L7 + z*L8)...)))
 *
 *	   where z=s*s. (See the listing below for Lk's values.) The 
 *	   coefficients are obtained by a special Remez algorithm. 
 *
 * Accuracy:
 *	Assuming no rounding error, the maximum magnitude of the approximation 
 *	error (absolute) is 2**(-58.49) for IEEE double, and 2**(-63.63)
 *	for VAX D format.
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
/* L1     =  6.6666666666666703212E-1    , Hex  2^  0   *  .AAAAAAAAAAAAC5 */
/* L2     =  3.9999999999970461961E-1    , Hex  2^ -1   *  .CCCCCCCCCC2684 */
/* L3     =  2.8571428579395698188E-1    , Hex  2^ -1   *  .92492492F85782 */
/* L4     =  2.2222221233634724402E-1    , Hex  2^ -2   *  .E38E3839B7AF2C */
/* L5     =  1.8181879517064680057E-1    , Hex  2^ -2   *  .BA2EB4CC39655E */
/* L6     =  1.5382888777946145467E-1    , Hex  2^ -2   *  .9D8551E8C5781D */
/* L7     =  1.3338356561139403517E-1    , Hex  2^ -2   *  .8895B3907FCD92 */
/* L8     =  1.2500000000000000000E-1    , Hex  2^ -2   *  .80000000000000 */
D 4
static long        L1x[] = { 0xaaaa402a, 0xaac5aaaa};
static long        L2x[] = { 0xcccc3fcc, 0x2684cccc};
static long        L3x[] = { 0x49243f92, 0x578292f8};
static long        L4x[] = { 0x8e383f63, 0xaf2c39b7};
static long        L5x[] = { 0x2eb43f3a, 0x655ecc39};
static long        L6x[] = { 0x85513f1d, 0x781de8c5};
static long        L7x[] = { 0x95b33f08, 0xcd92907f};
static long        L8x[] = { 0x00003f00, 0x00000000};
E 4
I 4
static long        L1x[] = { _0x(aaaa,402a), _0x(aac5,aaaa)};
static long        L2x[] = { _0x(cccc,3fcc), _0x(2684,cccc)};
static long        L3x[] = { _0x(4924,3f92), _0x(5782,92f8)};
static long        L4x[] = { _0x(8e38,3f63), _0x(af2c,39b7)};
static long        L5x[] = { _0x(2eb4,3f3a), _0x(655e,cc39)};
static long        L6x[] = { _0x(8551,3f1d), _0x(781d,e8c5)};
static long        L7x[] = { _0x(95b3,3f08), _0x(cd92,907f)};
static long        L8x[] = { _0x(0000,3f00), _0x(0000,0000)};
E 4
#define       L1    (*(double*)L1x)
#define       L2    (*(double*)L2x)
#define       L3    (*(double*)L3x)
#define       L4    (*(double*)L4x)
#define       L5    (*(double*)L5x)
#define       L6    (*(double*)L6x)
#define       L7    (*(double*)L7x)
#define       L8    (*(double*)L8x)
D 5
#else	/* IEEE double */
E 5
I 5
#else	/* defined(vax)||defined(tahoe)	*/
E 5
static double
L1     =  6.6666666666667340202E-1    , /*Hex  2^ -1   *  1.5555555555592 */
L2     =  3.9999999999416702146E-1    , /*Hex  2^ -2   *  1.999999997FF24 */
L3     =  2.8571428742008753154E-1    , /*Hex  2^ -2   *  1.24924941E07B4 */
L4     =  2.2222198607186277597E-1    , /*Hex  2^ -3   *  1.C71C52150BEA6 */
L5     =  1.8183562745289935658E-1    , /*Hex  2^ -3   *  1.74663CC94342F */
L6     =  1.5314087275331442206E-1    , /*Hex  2^ -3   *  1.39A1EC014045B */
L7     =  1.4795612545334174692E-1    ; /*Hex  2^ -3   *  1.2F039F0085122 */
D 5
#endif
E 5
I 5
#endif	/* defined(vax)||defined(tahoe)	*/
E 5

double log__L(z)
double z;
{
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
    return(z*(L1+z*(L2+z*(L3+z*(L4+z*(L5+z*(L6+z*(L7+z*L8))))))));
D 5
#else	/* IEEE double */
E 5
I 5
#else	/* defined(vax)||defined(tahoe) */
E 5
    return(z*(L1+z*(L2+z*(L3+z*(L4+z*(L5+z*(L6+z*L7)))))));
D 5
#endif
E 5
I 5
#endif	/* defined(vax)||defined(tahoe) */
E 5
}
E 1
