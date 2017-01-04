h55592
s 00010/00005/00039
d D 5.6 88/06/18 13:56:24 bostic 8 7
c install approved copyright notice
e
s 00008/00002/00036
d D 5.5 88/02/16 18:50:43 bostic 7 6
c add Berkeley specific headers
e
s 00001/00001/00037
d D 5.4 87/05/28 11:26:04 karels 6 5
c rework interface metrics to invert perspective; other misc. fixes
e
s 00003/00002/00035
d D 5.3 86/04/20 23:33:52 karels 5 4
c changes to allow subnets to remain local, propogate net route
c where subnets don't go, and allow external routes from /etc/gateways
c to block routed from installing routes from elsewhere
e
s 00003/00001/00034
d D 5.2 86/02/23 19:33:52 karels 4 3
c don't rely on AF_MAX (comes from kernel include): check for nil explicitly,
c use our own idea of table size.  Use syslog to (optionally) log bad packets.
c Don't respond to routing inquiries from a router unless we are suppliers
c (really want to respondto everything but broadcasts, but haven't got
c the "to" address.)
e
s 00007/00001/00028
d D 5.1 85/06/04 16:38:54 dist 3 2
c Add copyright
e
s 00002/00001/00027
d D 4.2 84/03/07 21:56:22 karels 2 1
c more consistency checks; watch those unsigned moduli
e
s 00028/00000/00000
d D 4.1 83/01/11 14:35:34 sam 1 0
c date and time created 83/01/11 14:35:34 by sam
e
u
U
t
T
I 1
D 3
/*	%M%	%I%	%E%	*/
E 3
I 3
/*
 * Copyright (c) 1983 Regents of the University of California.
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
E 3

/*
 * Routing table management daemon.
 */

/*
 * Per address family routines.
 */
struct afswitch {
	int	(*af_hash)();		/* returns keys based on address */
	int	(*af_netmatch)();	/* verifies net # matching */
	int	(*af_output)();		/* interprets address for sending */
	int	(*af_portmatch)();	/* packet from some other router? */
D 2
	int	(*af_portcheck)();	/* packet from priviledged peer? */
E 2
I 2
	int	(*af_portcheck)();	/* packet from privileged peer? */
E 2
D 5
	int	(*af_checkhost)();	/* tells if address for host or net */
I 2
	int	(*af_ishost)();		/* tells if address is valid */
E 5
I 5
	int	(*af_checkhost)();	/* tells if address is valid */
	int	(*af_rtflags)();	/* get flags for route (host or net) */
D 6
	int	(*af_sendsubnet)();	/* check bounds of subnet broadcast */
E 6
I 6
	int	(*af_sendroute)();	/* check bounds of subnet broadcast */
E 6
E 5
E 2
	int	(*af_canon)();		/* canonicalize address for compares */
I 4
	char	*(*af_format)();	/* convert address to string */
E 4
};

/*
 * Structure returned by af_hash routines.
 */
struct afhash {
	u_int	afh_hosthash;		/* host based hash */
	u_int	afh_nethash;		/* network based hash */
};

D 4
struct	afswitch afswitch[AF_MAX];	/* table proper */
E 4
I 4
struct	afswitch afswitch[];		/* table proper */
int	af_max;				/* number of entries in table */
E 4
E 1
