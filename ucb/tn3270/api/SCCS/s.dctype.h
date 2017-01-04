h58311
s 00011/00001/00022
d D 3.2 88/03/28 13:46:52 bostic 4 3
c add Berkeley specific header
e
s 00000/00000/00023
d D 3.1 87/08/11 10:17:43 minshall 3 2
c New version numbering.
e
s 00001/00001/00022
d D 1.2 87/07/17 10:01:39 minshall 2 1
c Install sccs headers and copyright notices.
e
s 00023/00000/00000
d D 1.1 86/11/11 22:54:09 minshall 1 0
c date and time created 86/11/11 22:54:09 by minshall
e
u
U
t
T
I 1
/*
D 2
 *	@(#)ectype.h	3.1  10/29/86
E 2
I 2
D 4
 * %W% (Berkeley) %G%
E 4
I 4
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 *
 *	%W% (Berkeley) %G%
E 4
E 2
 */

#define	INCLUDED_ECTYPE

#define	D_UPPER	0x01
#define	D_LOWER	0x02
#define	D_DIGIT	0x04
#define	D_SPACE	0x08
#define	D_PUNCT	0x10
#define	D_PRINT 0x20

#define	Disalpha(c)	(dctype[(c)]&(D_UPPER|D_LOWER))
#define	Disupper(c)	(dctype[(c)]&D_UPPER)
#define	Dislower(c)	(dctype[(c)]&D_LOWER)
#define	Disdigit(c)	(dctype[(c)]&D_DIGIT)
#define	Disalnum(c)	(dctype[(c)]&(D_UPPER|D_LOWER|D_DIGIT))
#define	Disspace(c)	(dctype[(c)]&D_SPACE)	/* blank or null */
#define	Dispunct(c)	(dctype[(c)]&D_PUNCT)
#define	Disprint(c)	(dctype[(c)]&D_PRINT)

extern unsigned char dctype[192];
E 1
