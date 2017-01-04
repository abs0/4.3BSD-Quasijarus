h44312
s 00014/00002/00016
d D 3.2 88/03/28 13:46:41 bostic 4 3
c add Berkeley specific header
e
s 00000/00000/00018
d D 3.1 87/08/11 10:17:47 minshall 3 2
c New version numbering.
e
s 00002/00000/00016
d D 1.2 87/07/17 10:01:44 minshall 2 1
c Install sccs headers and copyright notices.
e
s 00016/00000/00000
d D 1.1 87/06/19 12:37:12 minshall 1 0
c date and time created 87/06/19 12:37:12 by minshall
e
u
U
t
T
I 1
/*
D 4
 * Definitions of translate tables used for ascii<->ebcdic translation.
E 4
I 4
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
E 4
I 2
 *
D 4
 * %W% (Berkeley) %G%
E 4
I 4
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 *
 *	%W% (Berkeley) %G%
 */

/*
 * Definitions of translate tables used for ascii<->ebcdic translation.
E 4
E 2
 */

#define	INCLUDED_ASCEBC

/*
 * ascii/ebcdic translation information
 */

#define	NASCII	128		/* number of ascii characters */

#define	NEBC	256		/* number of ebcdic characters */

extern unsigned char
	asc_ebc[NASCII], ebc_asc[NEBC];
E 1
