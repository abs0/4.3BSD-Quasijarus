h40940
s 00011/00006/00053
d D 7.3 88/06/29 17:13:22 bostic 7 6
c install approved copyright notice
e
s 00010/00004/00049
d D 7.2 88/01/20 15:15:15 sklower 6 5
c Change licensing/use notice.
e
s 00001/00001/00052
d D 7.1 86/06/05 00:36:42 mckusick 5 4
c 4.3BSD release version
e
s 00003/00003/00050
d D 6.4 86/06/02 14:48:24 karels 4 3
c lint
e
s 00001/00001/00052
d D 6.3 86/02/03 17:40:38 sklower 3 2
c Correct erroneous copyright information.
e
s 00007/00001/00046
d D 6.2 85/06/08 12:50:18 mckusick 2 1
c Add copyright
e
s 00047/00000/00000
d D 6.1 85/05/30 19:10:55 sklower 1 0
c date and time created 85/05/30 19:10:55 by sklower
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
D 3
 * Copyright (c) 1982 Regents of the University of California.
E 3
I 3
D 5
 * Copyright (c) 1985 Regents of the University of California.
E 5
I 5
D 6
 * Copyright (c) 1985, 1986 Regents of the University of California.
E 5
E 3
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 6
I 6
 * Copyright (c) 1984, 1985, 1986, 1987 Regents of the University of California.
 * All rights reserved.
E 6
 *
D 6
 *	%W% (Berkeley) %G%
E 6
I 6
 * Redistribution and use in source and binary forms are permitted
D 7
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 7
I 7
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
E 7
 *
D 7
 *      %W% (Berkeley) %G%
E 7
I 7
 *	%W% (Berkeley) %G%
E 7
E 6
 */
E 2

/*
 * Interface address, xerox version.  One of these structures
 * is allocated for each interface with an internet address.
 * The ifaddr structure contains the protocol-independent part
 * of the structure and is assumed to be first.
 */

struct ns_ifaddr {
	struct	ifaddr ia_ifa;		/* protocol-independent info */
#define	ia_addr	ia_ifa.ifa_addr
#define	ia_broadaddr	ia_ifa.ifa_broadaddr
#define	ia_dstaddr	ia_ifa.ifa_dstaddr
#define	ia_ifp		ia_ifa.ifa_ifp
	union	ns_net	ia_net;		/* network number of interface */
	int	ia_flags;
	struct	ns_ifaddr *ia_next;	/* next in list of internet addresses */
};

/*
 * Given a pointer to an ns_ifaddr (ifaddr),
 * return a pointer to the addr as a sockadd_ns.
 */

#define	IA_SNS(ia) ((struct sockaddr_ns *)(&((struct ns_ifaddr *)ia)->ia_addr))
/*
 * ia_flags
 */
#define	IFA_ROUTE	0x01		/* routing entry installed */

/* This is not the right place for this but where is? */
#define	ETHERTYPE_NS	0x0600

#ifdef	NSIP
struct nsip_req {
	struct sockaddr rq_ns;	/* must be ns format destination */
	struct sockaddr rq_ip;	/* must be ip format gateway */
	short rq_flags;
};
#endif

#ifdef	KERNEL
D 4
extern	struct ns_ifaddr *ns_ifaddr;
extern	struct ns_ifaddr *ns_iaonnetof();
extern	struct ifqueue	nsintrq;	/* XNS input packet queue */
E 4
I 4
struct	ns_ifaddr *ns_ifaddr;
struct	ns_ifaddr *ns_iaonnetof();
struct	ifqueue	nsintrq;	/* XNS input packet queue */
E 4
#endif
E 1
