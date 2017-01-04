h22232
s 00010/00005/00036
d D 7.3 88/06/27 18:59:27 bostic 8 7
c install approved copyright notice
e
s 00008/00002/00033
d D 7.2 87/12/30 11:57:21 bostic 7 6
c add Berkeley header
e
s 00001/00001/00034
d D 7.1 86/06/04 23:38:45 mckusick 6 5
c 4.3BSD release version
e
s 00007/00001/00028
d D 6.2 85/06/08 12:25:39 mckusick 5 4
c Add copyright
e
s 00000/00000/00029
d D 6.1 83/07/29 07:08:31 sam 4 3
c 4.2 distribution
e
s 00006/00020/00023
d D 4.3 82/03/30 11:31:10 sam 3 2
c with routing, but not forwarding
e
s 00000/00000/00043
d D 4.2 82/03/28 14:20:44 sam 2 1
c convert interfaces to sockaddr's and add hooks for routing
e
s 00043/00000/00000
d D 4.1 82/03/27 22:57:38 sam 1 0
c date and time created 82/03/27 22:57:38 by sam
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
 * Copyright (c) 1980 Regents of the University of California.
E 6
I 6
 * Copyright (c) 1980, 1986 Regents of the University of California.
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

/*
D 3
 * Address family routines
 * Used in handling generic sockaddr structures.
E 3
I 3
 * Address family routines,
 * used in handling generic sockaddr structures.
E 3
 *
 * Hash routine is called
 *	af_hash(addr, h);
D 3
 * where addr is a sockaddr * and h is a afhash * value
 * parameter.  Returns two hash keys for searching.  Keys
 * are not expected to be unique, full comparison on the
 * sockaddr must be performed for a successful match.
E 3
I 3
 *	struct sockaddr *addr; struct afhash *h;
 * producing an afhash structure for addr.
E 3
 *
D 3
 * N.B.: hash keys must lie in distinct ranges, this is
 *	 done by shifting the net key to the upper word
 *	 with the host key occupying the lower word; the
 *	 routing code uses this fact
 *
E 3
 * Netmatch routine is called
 *	af_netmatch(addr1, addr2);
 * where addr1 and addr2 are sockaddr *.  Returns 1 if network
 * values match, 0 otherwise.
D 3
 *
 * Currently used in if.c and route.c, soon in raw code.
E 3
 */
struct afswitch {
	int	(*af_hash)();
	int	(*af_netmatch)();
};

struct afhash {
D 3
	long	afh_hostkey;
	int	afh_hosthash;
	int	afh_nethash;
	long	afh_netkey;
E 3
I 3
	u_int	afh_hosthash;
	u_int	afh_nethash;
E 3
};
D 3

#define	AFMASK	0xffff		/* all values must fall in here */
#define	AFSHIFT	16		/* key's lie in distinct ranges */
E 3

#ifdef KERNEL
struct	afswitch afswitch[];
#endif
E 1
