h27335
s 00013/00002/00028
d D 7.2 88/08/04 15:17:27 bostic 9 8
c add Berkeley specific copyright
e
s 00001/00001/00029
d D 7.1 86/06/05 01:35:32 mckusick 8 7
c 4.3BSD release version
e
s 00007/00001/00023
d D 6.3 85/06/08 13:55:03 mckusick 7 6
c Add copyright
e
s 00002/00000/00022
d D 6.2 85/05/01 09:09:34 karels 6 5
c move interface addresses into protocols; remove struct ether_addr again
e
s 00000/00000/00022
d D 6.1 83/07/29 07:37:48 sam 5 4
c 4.2 distribution
e
s 00008/00007/00014
d D 4.4 83/05/10 11:36:08 sam 4 3
c fix header byte swapping problems and incorrect Ethernet types
e
s 00001/00001/00020
d D 4.3 81/12/03 17:29:15 wnj 3 2
c cleanup
e
s 00003/00001/00018
d D 4.2 81/12/02 16:58:20 wnj 2 1
c yet more lint
e
s 00019/00000/00000
d D 4.1 81/11/30 10:09:58 wnj 1 0
c date and time created 81/11/30 10:09:58 by wnj
e
u
U
t
T
I 1
D 7
/*	%M%	%I%	%E%	*/
E 7
I 7
/*
D 8
 * Copyright (c) 1982 Regents of the University of California.
E 8
I 8
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 8
D 9
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 9
I 9
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
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
E 9
 *
 *	%W% (Berkeley) %G%
 */
E 7

/*
 * Structure of a Ethernet header.
 */
struct	en_header {
	u_char	en_shost;
	u_char	en_dhost;
	u_short	en_type;
};

I 2
D 4
#define	ENPUP_PUPTYPE	0x0400		/* PUP protocol */
E 2
#define	ENPUP_IPTYPE	0x0800		/* IP protocol */
E 4
I 4
#define	ENTYPE_PUP	0x0200		/* PUP protocol */
#define	ENTYPE_IP	0x0201		/* IP protocol */
E 4
D 3
/*
E 3
I 2

I 3
/*
E 3
E 2
D 4
 * The ENPUP_NTRAILER packet types starting at ENPUP_TRAIL have
 * (type-ENPUP_TRAIL)*512 bytes of data followed
D 2
 * by a PUP type (as given above).
E 2
I 2
 * by a PUP type (as given above) and then the (variable-length) header.
E 4
I 4
 * The ENTYPE_NTRAILER packet types starting at
 * ENTYPE_TRAIL have (type-ENTYPE_TRAIL)*512 bytes
 * of data followed by an Ethernet type (as given above)
 * and then the (variable-length) header.
E 4
E 2
 */
D 4
#define	ENPUP_TRAIL	0x1000		/* Trailer PUP */
#define	ENPUP_NTRAILER	16
E 4
I 4
#define	ENTYPE_TRAIL	0x1000		/* Trailer type */
#define	ENTYPE_NTRAILER	16
I 6

#define EN_BROADCAST	0		/* Hardware broadcast address */
E 6
E 4
E 1
