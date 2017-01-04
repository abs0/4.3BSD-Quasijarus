h44424
s 00010/00005/00044
d D 7.3 88/06/29 17:06:45 bostic 8 7
c install approved copyright notice
e
s 00008/00002/00041
d D 7.2 87/12/07 17:45:31 bostic 7 6
c use Berkeley specific header
e
s 00001/00001/00042
d D 7.1 86/06/05 00:26:46 mckusick 6 5
c 4.3BSD release version
e
s 00006/00005/00037
d D 6.5 86/06/02 14:30:19 karels 5 4
c lint
e
s 00002/00002/00040
d D 6.4 86/02/23 23:23:48 karels 4 3
c lint
e
s 00001/00000/00041
d D 6.3 85/10/14 17:20:03 karels 3 2
c recognize other attempts to broadcast
e
s 00007/00001/00034
d D 6.2 85/06/08 12:39:16 mckusick 2 1
c Add copyright
e
s 00035/00000/00000
d D 6.1 85/03/18 15:31:17 karels 1 0
c separate internet addressing from interface layer
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%E%	*/
E 2
I 2
/*
D 5
 * Copyright (c) 1982 Regents of the University of California.
E 5
I 5
D 6
 * Copyright (c) 1985 Regents of the University of California.
E 6
I 6
 * Copyright (c) 1985, 1986 Regents of the University of California.
E 6
E 5
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
E 2

/*
D 5
 * Interface address, internet version.  One of these structures
 * is allocated for each interface with an internet address.
E 5
I 5
 * Interface address, Internet version.  One of these structures
 * is allocated for each interface with an Internet address.
E 5
 * The ifaddr structure contains the protocol-independent part
 * of the structure and is assumed to be first.
 */
struct in_ifaddr {
	struct	ifaddr ia_ifa;		/* protocol-independent info */
#define	ia_addr	ia_ifa.ifa_addr
#define	ia_broadaddr	ia_ifa.ifa_broadaddr
#define	ia_dstaddr	ia_ifa.ifa_dstaddr
#define	ia_ifp		ia_ifa.ifa_ifp
	u_long	ia_net;			/* network number of interface */
	u_long	ia_netmask;		/* mask of net part */
	u_long	ia_subnet;		/* subnet number, including net */
	u_long	ia_subnetmask;		/* mask of net + subnet */
I 3
	struct	in_addr ia_netbroadcast; /* broadcast addr for (logical) net */
E 3
	int	ia_flags;
	struct	in_ifaddr *ia_next;	/* next in list of internet addresses */
};
/*
 * Given a pointer to an in_ifaddr (ifaddr),
 * return a pointer to the addr as a sockadd_in.
 */
#define	IA_SIN(ia) ((struct sockaddr_in *)(&((struct in_ifaddr *)ia)->ia_addr))
/*
 * ia_flags
 */
#define	IFA_ROUTE	0x01		/* routing entry installed */

#ifdef	KERNEL
D 4
extern	struct in_ifaddr *in_ifaddr;
extern	struct in_ifaddr *in_iaonnetof();
E 4
I 4
D 5
struct in_ifaddr *in_ifaddr;
struct in_ifaddr *in_iaonnetof();
E 5
I 5
struct	in_ifaddr *in_ifaddr;
struct	in_ifaddr *in_iaonnetof();
struct	ifqueue	ipintrq;		/* ip packet input queue */
E 5
E 4
#endif
E 1
