h05141
s 00010/00017/00025
d D 1.2 88/03/28 13:46:42 bostic 2 1
c add Berkeley specific header
e
s 00042/00000/00000
d D 1.1 87/05/10 11:28:03 minshall 1 0
c date and time created 87/05/10 11:28:03 by minshall
e
u
U
t
T
I 1
/*
D 2
 *	Copyright 1984, 1985 by the Regents of the University of
 *	California and by Gregory Glenn Minshall.
E 2
I 2
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
E 2
 *
D 2
 *	Permission to use, copy, modify, and distribute these
 *	programs and their documentation for any purpose and
 *	without fee is hereby granted, provided that this
 *	copyright and permission appear on all copies and
 *	supporting documentation, the name of the Regents of
 *	the University of California not be used in advertising
 *	or publicity pertaining to distribution of the programs
 *	without specific prior permission, and notice be given in
 *	supporting documentation that copying and distribution is
 *	by permission of the Regents of the University of California
 *	and by Gregory Glenn Minshall.  Neither the Regents of the
 *	University of California nor Gregory Glenn Minshall make
 *	representations about the suitability of this software
 *	for any purpose.  It is provided "as is" without
 *	express or implied warranty.
E 2
I 2
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 *
 *	%W% (Berkeley) %G%
E 2
 */

#define	INCLUDED_ASCEBC

/*
 * ascii/ebcdic translation information
 */

#define	NASCII	128		/* number of ascii characters */
#define	NASCEBC	  4		/* number of ascii to ebcdic tables */

#define AE_NO	 -1		/* no translation - user has already done it */
#define	AE_PR	  0		/* ascii to ebcdic "print" translation */
#define	AE_IN	  1		/* ascii to ebcdic "input" translation */
#define	AE_SP	  2		/* ascii to ebcdic special translation */
#define AE_TX	  3		/* ascii to ebcdic pure text translation */

#define	NEBC	256		/* number of ebcdic characters */
#define	NEBCASC	  1		/* number of ebcdic to ascii tables */

extern unsigned char
	ascebc[NASCEBC][NASCII],
	ebcasc[NEBCASC][NEBC];
E 1
