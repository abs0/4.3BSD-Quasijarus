h36368
s 00010/00005/00032
d D 5.3 88/06/30 17:45:34 bostic 7 6
c install approved copyright notice
e
s 00018/00001/00019
d D 5.2 88/04/29 12:42:02 bostic 6 5
c add Berkeley specific header
e
s 00000/00000/00020
d D 5.1 87/11/30 18:34:09 bostic 5 4
c tahoe release
e
s 00002/00002/00018
d D 1.3 87/07/18 12:13:15 zliu 4 3
c ifdef vax||tahoe...
e
s 00002/00002/00018
d D 1.2 85/09/11 23:59:01 elefunt 3 1
c 4.3BSD version dated 09/11/85.
e
s 00000/00000/00020
d R 1.2 85/09/11 23:52:58 elefunt 2 1
c 4.3BSD version dated 09/11/85.
e
s 00020/00000/00000
d D 1.1 85/09/06 17:52:32 zliu 1 0
c date and time created 85/09/06 17:52:32 by zliu
e
u
U
t
T
I 1
D 3
/* %M% %I% (ELEFUNT) %G% */
E 3
I 3
D 6
/*	%M%	4.6	9/11/85; %I% (ucb.elefunt) %G% */
E 6
I 6
/*
 * Copyright (c) 1985 Regents of the University of California.
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
 *
 *	%W% (Berkeley) %G%
 */
E 6
E 3

extern double asinh(), acosh(), atanh();
extern double erf(), erfc();
extern double exp(), expm1(), log(), log10(), log1p(), pow();
extern double fabs(), floor(), ceil(), rint();
D 3
extern double lgama();
E 3
I 3
extern double lgamma();
E 3
extern double hypot(), cabs();
extern double copysign(), drem(), logb(), scalb();
extern int finite();
D 4
#ifdef vax
E 4
I 4
#if defined(vax)||defined(tahoe)
E 4
extern double infnan();
D 4
#endif
E 4
I 4
#endif	/* defined(vax)||defined(tahoe) */
E 4
extern double j0(), j1(), jn(), y0(), y1(), yn();
extern double sin(), cos(), tan(), asin(), acos(), atan(), atan2();
extern double sinh(), cosh(), tanh();
extern double cbrt(), sqrt();
extern double modf(), ldexp(), frexp(), atof();

#define HUGE	1.701411733192644270e38
E 1
