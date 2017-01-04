h29311
s 00010/00005/00096
d D 5.4 88/06/30 17:23:01 bostic 8 7
c install approved copyright notice
e
s 00016/00013/00085
d D 5.3 88/04/29 12:23:21 bostic 7 6
c add Berkeley specific copyright
e
s 00001/00001/00097
d D 5.2 88/04/04 12:16:25 bostic 6 5
c comment didn't reflect code; bug report 4.3BSD/usr.lib/86
e
s 00000/00000/00098
d D 5.1 87/11/30 18:42:13 bostic 5 4
c tahoe release
e
s 00005/00005/00093
d D 1.4 87/07/13 19:49:16 zliu 4 3
c clean-ups.
e
s 00001/00001/00097
d D 1.3 87/07/10 10:40:57 zliu 3 2
c excluding TAHOE also...
e
s 00002/00001/00096
d D 1.2 85/09/12 20:21:57 elefunt 2 1
c 4.3BSD version dated 09/12/85.
e
s 00097/00000/00000
d D 1.1 85/09/06 17:51:26 zliu 1 0
c date and time created 85/09/06 17:51:26 by zliu
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
"%Z%%M%	1.1 (Berkeley) 5/23/85; %I% (ucb.elefunt) %G%";
E 2
D 4
#endif not lint
E 4
I 4
#endif	/* not lint */
E 7
I 7
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 7
E 4

/* kahan's cube root (53 bits IEEE double precision)
 * for IEEE machines only
 * coded in C by K.C. Ng, 4/30/85
 *
 * Accuracy:
 *	better than 0.667 ulps according to an error analysis. Maximum
 * error observed was 0.666 ulps in an 1,000,000 random arguments test.
 *
 * Warning: this code is semi machine dependent; the ordering of words in
 * a floating point number must be known in advance. I assume that the
 * long interger at the address of a floating point number will be the
 * leading 32 bits of that floating point number (i.e., sign, exponent,
 * and the 20 most significant bits).
 * On a National machine, it has different ordering; therefore, this code 
 * must be compiled with flag -DNATIONAL. 
 */
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

static unsigned long B1 = 715094163, /* B1 = (682-0.03306235651)*2**20 */
	             B2 = 696219795; /* B2 = (664-0.03306235651)*2**20 */
static double
	    C= 19./35.,
	    D= -864./1225.,
	    E= 99./70.,
	    F= 45./28.,
	    G= 5./14.;

double cbrt(x) 
double x;
{
	double r,s,t=0.0,w;
	unsigned long *px = (unsigned long *) &x,
	              *pt = (unsigned long *) &t,
		      mexp,sign;

D 4
#ifdef NATIONAL /* ordering of words in a floating points number */
E 4
I 4
#ifdef national /* ordering of words in a floating points number */
E 4
	int n0=1,n1=0;
D 4
#else
E 4
I 4
#else	/* national */
E 4
	int n0=0,n1=1;
D 4
#endif
E 4
I 4
#endif	/* national */
E 4

	mexp=px[n0]&0x7ff00000;
	if(mexp==0x7ff00000) return(x); /* cbrt(NaN,INF) is itself */
	if(x==0.0) return(x);		/* cbrt(0) is itself */

	sign=px[n0]&0x80000000; /* sign= sign(x) */
	px[n0] ^= sign;		/* x=|x| */


    /* rough cbrt to 5 bits */
	if(mexp==0) 		/* subnormal number */
	  {pt[n0]=0x43500000; 	/* set t= 2**54 */
	   t*=x; pt[n0]=pt[n0]/3+B2;
	  }
	else
	  pt[n0]=px[n0]/3+B1;	


    /* new cbrt to 23 bits, may be implemented in single precision */
	r=t*t/x;
	s=C+r*t;
	t*=G+F/(s+E+D/s);	

    /* chopped to 20 bits and make it larger than cbrt(x) */ 
	pt[n1]=0; pt[n0]+=0x00000001;


    /* one step newton iteration to 53 bits with error less than 0.667 ulps */
	s=t*t;		/* t*t is exact */
	r=x/s;
	w=t+t;
D 6
	r=(r-t)/(w+r);	/* r-s is exact */
E 6
I 6
	r=(r-t)/(w+r);	/* r-t is exact */
E 6
	t=t+t*r;


    /* retore the sign bit */
	pt[n0] |= sign;
	return(t);
}
#endif
E 1
