h46378
s 00010/00005/00031
d D 7.3 88/06/29 17:34:31 bostic 3 2
c install approved copyright notice
e
s 00001/00001/00035
d D 7.2 88/01/21 16:33:37 karels 2 1
c remove ENDIAN!
e
s 00036/00000/00000
d D 7.1 88/01/07 10:56:23 bostic 1 0
c date and time created 88/01/07 10:56:23 by bostic
e
u
U
t
T
I 1
/*
 * Copyright (c) 1987 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 3
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 3
I 3
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
E 3
 *
 *	%W% (Berkeley) %G%
 */

/*
 * Definitions for byte order,
 * according to byte significance from low address to high.
 */
#define	LITTLE_ENDIAN	1234	/* least-significant byte first (vax) */
#define	BIG_ENDIAN	4321	/* most-significant byte first (IBM, net) */
#define	PDP_ENDIAN	3412	/* LSB first in word, MSW first in long (pdp) */

#define	BYTE_ORDER	BIG_ENDIAN	/* byte order on tahoe */

/*
 * Macros for network/external number representation conversion.
 */
D 2
#if ENDIAN == BIG && !defined(lint)
E 2
I 2
#if BYTE_ORDER == BIG_ENDIAN && !defined(lint)
E 2
#define	ntohl(x)	(x)
#define	ntohs(x)	(x)
#define	htonl(x)	(x)
#define	htons(x)	(x)
#else
unsigned short	ntohs(), htons();
unsigned long	ntohl(), htonl();
#endif
E 1
