h61180
s 00011/00006/00053
d D 7.3 88/06/29 17:13:34 bostic 9 8
c install approved copyright notice
e
s 00010/00004/00049
d D 7.2 88/01/20 15:15:27 sklower 8 7
c Change licensing/use notice.
e
s 00001/00001/00052
d D 7.1 86/06/05 00:37:53 mckusick 7 6
c 4.3BSD release version
e
s 00002/00002/00051
d D 6.6 86/06/02 14:48:47 karels 6 5
c lint
e
s 00001/00001/00052
d D 6.5 86/02/03 17:40:53 sklower 5 4
c Correct erroneous copyright information.
e
s 00001/00001/00052
d D 6.4 85/09/26 14:57:58 sklower 4 3
c minor correct to enhance route caching on datagrams.
e
s 00001/00000/00052
d D 6.3 85/07/26 14:02:37 sklower 3 2
c add flag to disable error process on DG sockets
e
s 00007/00001/00045
d D 6.2 85/06/08 12:51:36 mckusick 2 1
c Add copyright
e
s 00046/00000/00000
d D 6.1 85/05/30 19:11:04 sklower 1 0
c date and time created 85/05/30 19:11:04 by sklower
e
u
U
t
T
I 1
D 2
/*      %M%     %I%     %E%     */
E 2
I 2
/*
D 5
 * Copyright (c) 1982 Regents of the University of California.
E 5
I 5
D 7
 * Copyright (c) 1984, 1985 Regents of the University of California.
E 7
I 7
D 8
 * Copyright (c) 1984, 1985, 1986 Regents of the University of California.
E 7
E 5
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 8
I 8
 * Copyright (c) 1984, 1985, 1986, 1987 Regents of the University of California.
 * All rights reserved.
E 8
 *
D 8
 *	%W% (Berkeley) %G%
E 8
I 8
 * Redistribution and use in source and binary forms are permitted
D 9
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 9
I 9
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
D 9
 *      %W% (Berkeley) %G%
E 9
I 9
 *	%W% (Berkeley) %G%
E 9
E 8
 */
E 2

/*
 * Ns protocol interface control block.
 */
struct nspcb {
	struct	nspcb *nsp_next;	/* doubly linked list */
	struct	nspcb *nsp_prev;
	struct	nspcb *nsp_head;
	struct	socket *nsp_socket;	/* back pointer to socket */
	struct	ns_addr nsp_faddr;	/* destination address */
	struct	ns_addr nsp_laddr;	/* socket's address */
	caddr_t	nsp_pcb;		/* protocol specific stuff */
	struct	route nsp_route;	/* routing information */
D 4
	union	ns_net nsp_lastnet;	/* validate cached route for dg socks*/
E 4
I 4
	struct	ns_addr nsp_lastdst;	/* validate cached route for dg socks*/
E 4
	long	nsp_notify_param;	/* extra info passed via ns_pcbnotify*/
	short	nsp_flags;
	u_char	nsp_dpt;		/* default packet type for idp_output*/
	u_char	nsp_rpt;		/* last received packet type by
								idp_input() */
};

/* possible flags */

#define NSP_IN_ABORT	0x1		/* calling abort through socket */
#define NSP_RAWIN	0x2		/* show headers on input */
#define NSP_RAWOUT	0x4		/* show header on output */
I 3
#define NSP_ALL_PACKETS	0x8		/* Turn off higher proto processing */
E 3

#define	NS_WILDCARD	1

#define nsp_lport nsp_laddr.x_port
#define nsp_fport nsp_faddr.x_port

#define	sotonspcb(so)		((struct nspcb *)((so)->so_pcb))

/*
 * Nominal space allocated to a ns socket.
 */
#define	NSSNDQ		2048
#define	NSRCVQ		2048


#ifdef KERNEL
D 6
extern struct nspcb nspcb;			/* head of list */
extern struct nspcb *ns_pcblookup();
E 6
I 6
struct	nspcb nspcb;			/* head of list */
struct	nspcb *ns_pcblookup();
E 6
#endif
E 1
