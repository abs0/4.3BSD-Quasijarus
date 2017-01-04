h04888
s 00010/00005/00066
d D 5.3 88/06/30 17:45:09 bostic 5 4
c install approved copyright notice
e
s 00016/00013/00055
d D 5.2 88/04/29 12:28:42 bostic 4 3
c add Berkeley specific copyright                            
e
s 00000/00000/00068
d D 5.1 87/11/30 18:33:52 bostic 3 2
c tahoe release
e
s 00002/00001/00066
d D 1.2 85/09/11 23:53:32 elefunt 2 1
c 4.3BSD version dated 09/11/85.
e
s 00067/00000/00000
d D 1.1 85/09/06 17:52:40 zliu 1 0
c date and time created 85/09/06 17:52:40 by zliu
e
u
U
t
T
I 1
D 4
/* 
E 4
I 4
/*
E 4
 * Copyright (c) 1985 Regents of the University of California.
D 4
 * 
 * Use and reproduction of this software are granted  in  accordance  with
 * the terms and conditions specified in  the  Berkeley  Software  License
 * Agreement (in particular, this entails acknowledgement of the programs'
 * source, and inclusion of this notice) with the additional understanding
 * that  all  recipients  should regard themselves as participants  in  an
 * ongoing  research  project and hence should  feel  obligated  to report
 * their  experiences (good or bad) with these elementary function  codes,
 * using "sendbug 4bsd-bugs@BERKELEY", to the authors.
E 4
I 4
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 5
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 5
I 5
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
E 5
 *
 * All recipients should regard themselves as participants in an ongoing
 * research project and hence should feel obligated to report their
 * experiences (good or bad) with these elementary function codes, using
 * the sendbug(8) program, to the authors.
E 4
 */

#ifndef lint
D 2
static char sccsid[] = "%W% (ELEFUNT) %G%";
E 2
I 2
D 4
static char sccsid[] =
"%Z%%M%	1.1 (Berkeley) 8/21/85; %I% (ucb.elefunt) %G%";
E 2
#endif not lint
E 4
I 4
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 4

/* ATAN(X)
 * RETURNS ARC TANGENT OF X
 * DOUBLE PRECISION (IEEE DOUBLE 53 bits, VAX D FORMAT 56 bits)
 * CODED IN C BY K.C. NG, 4/16/85, REVISED ON 6/10/85.
 *
 * Required kernel function:
 *	atan2(y,x) 
 *
 * Method:                  
 *	atan(x) = atan2(x,1.0). 
 *
 * Special case:
 *	if x is NaN, return x itself.
 *
 * Accuracy:
 * 1)  If atan2() uses machine PI, then
 * 
 *	atan(x) returns (PI/pi) * (the exact arc tangent of x) nearly rounded;
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
 *	0.86 ulps.      (comparing against (PI/pi)*(exact atan(x))).
 *
 * 2)  If atan2() uses true pi, then
 *
 *	atan(x) returns the exact atan(x) with error below about 2 ulps.
 *
 *	In a test run with more than 1,024,000 random arguments on a VAX, the 
 *	maximum observed error in ulps (units in the last place) was
 *	0.85 ulps.
 */

double atan(x)
double x;
{
	double atan2(),one=1.0;
	return(atan2(x,one));
}
E 1
