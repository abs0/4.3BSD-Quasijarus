h00031
s 00010/00005/00148
d D 5.3 88/06/30 17:45:05 bostic 7 6
c install approved copyright notice
e
s 00016/00013/00137
d D 5.2 88/04/29 12:28:39 bostic 6 5
c add Berkeley specific copyright                            
e
s 00000/00000/00150
d D 5.1 87/11/30 18:33:50 bostic 5 4
c tahoe release
e
s 00005/00005/00145
d D 1.4 87/07/13 19:20:24 zliu 4 3
c clean-ups.
e
s 00002/00002/00148
d D 1.3 87/07/07 01:31:41 zliu 3 2
c first shot at TAHOE.
e
s 00002/00001/00148
d D 1.2 85/09/11 23:53:22 elefunt 2 1
c 4.3BSD version dated 09/11/85.
e
s 00149/00000/00000
d D 1.1 85/09/06 17:52:38 zliu 1 0
c date and time created 85/09/06 17:52:38 by zliu
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
"%Z%%M%	1.1 (Berkeley) 8/21/85; %I% (ucb.elefunt) %G%";
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

/* ASIN(X)
 * RETURNS ARC SINE OF X
 * DOUBLE PRECISION (IEEE DOUBLE 53 bits, VAX D FORMAT 56 bits)
 * CODED IN C BY K.C. NG, 4/16/85, REVISED ON 6/10/85.
 *
 * Required system supported functions:
 *	copysign(x,y)
 *	sqrt(x)
 *
 * Required kernel function:
 *	atan2(y,x) 
 *
 * Method :                  
 *	asin(x) = atan2(x,sqrt(1-x*x)); for better accuracy, 1-x*x is 
 *		  computed as follows
 *			1-x*x                     if x <  0.5, 
 *			2*(1-|x|)-(1-|x|)*(1-|x|) if x >= 0.5.
 *
 * Special cases:
 *	if x is NaN, return x itself;
 *	if |x|>1, return NaN.
 *
 * Accuracy:
 * 1)  If atan2() uses machine PI, then
 * 
 *	asin(x) returns (PI/pi) * (the exact arc sine of x) nearly rounded;
 *	and PI is the exact pi rounded to machine precision (see atan2 for
 *      details):
 *
 *	in decimal:
 *		pi = 3.141592653589793 23846264338327 ..... 
 *    53 bits   PI = 3.141592653589793 115997963 ..... ,
 *    56 bits   PI = 3.141592653589793 227020265 ..... ,  
 *
 *	in hexadecimal:
 *		pi = 3.243F6A8885A308D313198A2E....
 *    53 bits   PI = 3.243F6A8885A30  =  2 * 1.921FB54442D18	error=.276ulps
 *    56 bits   PI = 3.243F6A8885A308 =  4 * .C90FDAA22168C2    error=.206ulps
 *	
 *	In a test run with more than 200,000 random arguments on a VAX, the 
 *	maximum observed error in ulps (units in the last place) was
 *	2.06 ulps.      (comparing against (PI/pi)*(exact asin(x)));
 *
 * 2)  If atan2() uses true pi, then
 *
 *	asin(x) returns the exact asin(x) with error below about 2 ulps.
 *
 *	In a test run with more than 1,024,000 random arguments on a VAX, the 
 *	maximum observed error in ulps (units in the last place) was
 *      1.99 ulps.
 */

double asin(x)
double x;
{
	double s,t,copysign(),atan2(),sqrt(),one=1.0;
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
	s=copysign(x,one);
	if(s <= 0.5)
	    return(atan2(x,sqrt(one-x*x)));
	else 
	    { t=one-s; s=t+t; return(atan2(x,sqrt(s-t*t))); }

}

/* ACOS(X)
 * RETURNS ARC COS OF X
 * DOUBLE PRECISION (IEEE DOUBLE 53 bits, VAX D FORMAT 56 bits)
 * CODED IN C BY K.C. NG, 4/16/85, REVISED ON 6/10/85.
 *
 * Required system supported functions:
 *	copysign(x,y)
 *	sqrt(x)
 *
 * Required kernel function:
 *	atan2(y,x) 
 *
 * Method :                  
 *			      ________
 *                           / 1 - x
 *	acos(x) = 2*atan2(  / -------- , 1 ) .
 *                        \/   1 + x
 *
 * Special cases:
 *	if x is NaN, return x itself;
 *	if |x|>1, return NaN.
 *
 * Accuracy:
 * 1)  If atan2() uses machine PI, then
 * 
 *	acos(x) returns (PI/pi) * (the exact arc cosine of x) nearly rounded;
 *	and PI is the exact pi rounded to machine precision (see atan2 for
 *      details):
 *
 *	in decimal:
 *		pi = 3.141592653589793 23846264338327 ..... 
 *    53 bits   PI = 3.141592653589793 115997963 ..... ,
 *    56 bits   PI = 3.141592653589793 227020265 ..... ,  
 *
 *	in hexadecimal:
 *		pi = 3.243F6A8885A308D313198A2E....
 *    53 bits   PI = 3.243F6A8885A30  =  2 * 1.921FB54442D18	error=.276ulps
 *    56 bits   PI = 3.243F6A8885A308 =  4 * .C90FDAA22168C2    error=.206ulps
 *	
 *	In a test run with more than 200,000 random arguments on a VAX, the 
 *	maximum observed error in ulps (units in the last place) was
 *	2.07 ulps.      (comparing against (PI/pi)*(exact acos(x)));
 *
 * 2)  If atan2() uses true pi, then
 *
 *	acos(x) returns the exact acos(x) with error below about 2 ulps.
 *
 *	In a test run with more than 1,024,000 random arguments on a VAX, the 
 *	maximum observed error in ulps (units in the last place) was
 *	2.15 ulps.
 */

double acos(x)
double x;
{
	double t,copysign(),atan2(),sqrt(),one=1.0;
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
	if(x!=x) return(x);
D 4
#endif
E 4
I 4
#endif	/* !defined(vax)&&!defined(tahoe) */
E 4
	if( x != -1.0)
	    t=atan2(sqrt((one-x)/(one+x)),one);
	else
	    t=atan2(one,0.0);	/* t = PI/2 */
	return(t+t);
}
E 1
