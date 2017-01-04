h25624
s 00010/00005/00131
d D 5.3 88/06/29 18:55:13 bostic 6 5
c install approved copyright notice
e
s 00008/00002/00128
d D 5.2 88/05/05 18:05:45 bostic 5 4
c written by Eric Allman; add Berkeley specific header
e
s 00000/00000/00130
d D 5.1 86/06/06 09:18:51 bloom 4 3
c pull up to version 5.1
e
s 00008/00000/00122
d D 1.3 86/03/24 23:57:55 mckusick 3 2
c add copyright
e
s 00041/00000/00081
d D 1.2 81/11/22 17:05:23 root 2 1
c new version with tabs, CB virt term, other enhancements (MRH)
e
s 00081/00000/00000
d D 1.1 81/11/22 16:53:26 root 1 0
c date and time created 81/11/22 16:53:26 by root
e
u
U
t
T
I 1
/*
I 3
 * Copyright (c) 1980 Regents of the University of California.
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

/*
E 3
**  SYSTEM DEPENDENT TERMINAL DELAY TABLES
**
**	Evans Hall VAX
**
**	This file maintains the correspondence between the delays
**	defined in /etc/termcap and the delay algorithms on a
**	particular system.  For each type of delay, the bits used
**	for that delay must be specified (in XXbits) and a table
**	must be defined giving correspondences between delays and
**	algorithms.  Algorithms which are not fixed delays (such
**	as dependent on current column or line number) must be
**	cludged in some way at this time.
*/



/*
**  Carriage Return delays
*/

int	CRbits = CRDELAY;
struct delay	CRdelay[] =
{
	0,	CR0,
	9,	CR3,
	80,	CR1,
	160,	CR2,
	-1
};

/*
**  New Line delays
*/

int	NLbits = NLDELAY;
struct delay	NLdelay[] =
{
	0,	NL0,
	66,	NL1,		/* special M37 delay */
	100,	NL2,
	-1
};


/*
**  Back Space delays
*/

int	BSbits = BSDELAY;
struct delay	BSdelay[] =
{
	0,	BS0,
	-1
};


/*
**  TaB delays
*/

int	TBbits = TBDELAY;
struct delay	TBdelay[] =
{
	0,	TAB0,
	11,	TAB1,		/* special M37 delay */
	-1
};


/*
**  Form Feed delays
*/

int	FFbits = VTDELAY;
struct delay	FFdelay[] =
{
	0,	FF0,
	2000,	FF1,
	-1
};
I 2

#ifdef CBVIRTTERM
/*
 * Map from the universal tables in termcap to the particular numbers
 * this system uses.  The lack of standardization of terminal numbers
 * is a botch but such is life.
 */
struct vt_map {
	char stdnum;
	char localnum;
} vt_map[] = {
#ifdef	TERM_TEC
	1, TERM_TEC,
#endif
#ifdef	TERM_V61
	2, TERM_V61,
#endif
#ifdef	TERM_V10
	3, TERM_V10,
#endif
#ifdef	TERM_TEX
	4, TERM_TEX,
#endif
#ifdef	TERM_D40
	5, TERM_D40,
#endif
#ifdef	TERM_H45
	6, TERM_H45,
#endif
#ifdef	TERM_D42
	7, TERM_D42,
#endif
#ifdef TERM_C100
	8, TERM_C100,
#endif
#ifdef TERM_MIME
	9, TERM_MIME,
#endif
	0,0
};
#endif
E 2
E 1
