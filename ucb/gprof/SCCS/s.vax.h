h23770
s 00010/00005/00039
d D 5.3 88/06/29 19:23:34 bostic 6 5
c install approved copyright notice
e
s 00008/00002/00036
d D 5.2 88/05/05 17:50:34 bostic 5 4
c add Berkeley specific header; written by K. McKusick and P. Kessler
e
s 00007/00001/00031
d D 5.1 85/06/04 13:31:52 dist 4 3
c Add copyright
e
s 00001/00001/00031
d D 1.3 83/08/11 22:36:53 sam 3 2
c standardize sccs keyword lines
e
s 00001/00000/00031
d D 1.2 83/03/31 13:07:44 mckusick 2 1
c account for entry mask
e
s 00031/00000/00000
d D 1.1 83/03/24 16:05:10 mckusick 1 0
c date and time created 83/03/24 16:05:10 by mckusick
e
u
U
t
T
I 1
D 3
    /* sccsid:  %W% (Berkeley) %G% */
E 3
I 3
D 4
/*	%M%	%I%	%E%	*/
E 4
I 4
/*
 * Copyright (c) 1983 Regents of the University of California.
D 5
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 5
I 5
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 6
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 6
I 6
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
E 6
E 5
 *
 *	%W% (Berkeley) %G%
 */
E 4
E 3

    /*
     *	opcode of the `calls' instruction
     */
#define	CALLS	0xfb

    /*
     *	offset (in bytes) of the code from the entry address of a routine.
     *	(see asgnsamples for use and explanation.)
     */
#define OFFSET_OF_CODE	2
I 2
#define	UNITS_TO_CODE	(OFFSET_OF_CODE / sizeof(UNIT))
E 2

    /*
     *	register for pc relative addressing
     */
#define	PC	0xf

enum opermodes {
    literal, indexed, reg, regdef, autodec, autoinc, autoincdef, 
    bytedisp, bytedispdef, worddisp, worddispdef, longdisp, longdispdef,
    immediate, absolute, byterel, bytereldef, wordrel, wordreldef,
    longrel, longreldef
};
typedef enum opermodes	operandenum;

struct modebyte {
    unsigned int	regfield:4;
    unsigned int	modefield:4;
};

E 1
