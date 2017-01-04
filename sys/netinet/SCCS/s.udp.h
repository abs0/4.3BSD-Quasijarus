h00734
s 00010/00005/00019
d D 7.3 88/06/29 17:07:53 bostic 8 7
c install approved copyright notice
e
s 00008/00002/00016
d D 7.2 87/12/07 17:47:08 bostic 7 6
c use Berkeley specific header
e
s 00001/00001/00017
d D 7.1 86/06/05 00:33:34 mckusick 6 5
c 4.3BSD release version
e
s 00007/00001/00011
d D 6.2 85/06/08 12:46:23 mckusick 5 4
c Add copyright
e
s 00000/00000/00012
d D 6.1 83/07/29 07:13:25 sam 4 3
c 4.2 distribution
e
s 00001/00000/00011
d D 4.3 81/11/18 15:38:42 wnj 3 2
c more cleanup
e
s 00009/00007/00002
d D 4.2 81/11/15 13:01:02 wnj 2 1
c listing
e
s 00009/00000/00000
d D 4.1 81/11/14 16:52:24 wnj 1 0
c date and time created 81/11/14 16:52:24 by wnj
e
u
U
t
T
I 1
D 5
/*	%M%	%I%	%E%	*/
E 5
I 5
/*
D 6
 * Copyright (c) 1982 Regents of the University of California.
E 6
I 6
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 6
D 7
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
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
E 7
 *
 *	%W% (Berkeley) %G%
 */
E 5

D 2
struct udpiphdr {
	struct	ipovly u_ip;

	struct	udpiphdr *u_x[2];	/* space holders */
	u_char	u_x1;			/* unused */
	u_char	u_pr;			/* protocol */

E 2
I 2
/*
 * Udp protocol header.
I 3
 * Per RFC 768, September, 1981.
E 3
 */
struct udphdr {
	u_short	uh_sport;		/* source port */
	u_short	uh_dport;		/* destination port */
	short	uh_ulen;		/* udp length */
	u_short	uh_sum;			/* udp checksum */
};
E 2
E 1
