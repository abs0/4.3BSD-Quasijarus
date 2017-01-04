h22496
s 00010/00005/00056
d D 7.3 88/06/27 18:59:40 bostic 12 11
c install approved copyright notice
e
s 00008/00002/00053
d D 7.2 87/12/30 11:57:36 bostic 11 10
c add Berkeley header
e
s 00001/00001/00054
d D 7.1 86/06/04 23:41:31 mckusick 10 9
c 4.3BSD release version
e
s 00001/00000/00054
d D 6.4 86/02/02 20:11:28 karels 9 8
c add per-protocol options in rawcb (freed at detach)
e
s 00007/00001/00047
d D 6.3 85/06/08 12:26:58 mckusick 8 7
c Add copyright
e
s 00001/00000/00047
d D 6.2 85/06/02 23:38:01 karels 7 6
c allow raw socket of any protocol if family has wildcard entry,
c with actual protocol number in raw_cb instead of protosw
e
s 00000/00000/00047
d D 6.1 83/07/29 07:08:46 sam 6 5
c 4.2 distribution
e
s 00002/00000/00045
d D 4.5 83/06/30 01:14:34 sam 5 4
c routing for raw stuff
e
s 00005/00003/00040
d D 4.4 82/04/10 23:41:27 sam 4 3
c purge so_addr from socket structure and start cleaning up raw code
e
s 00003/00002/00040
d D 4.3 82/02/02 19:34:17 sam 3 2
c fix comment
e
s 00003/00002/00039
d D 4.2 82/02/01 17:50:27 sam 2 1
c raw interfaces brought up to date
e
s 00041/00000/00000
d D 4.1 82/02/01 12:59:36 root 1 0
c date and time created 82/02/01 12:59:36 by root
e
u
U
t
T
I 1
D 8
/*	%M%	%I%	%E%	*/
E 8
I 8
/*
D 10
 * Copyright (c) 1980 Regents of the University of California.
E 10
I 10
 * Copyright (c) 1980, 1986 Regents of the University of California.
E 10
D 11
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 11
I 11
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 12
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 12
I 12
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
E 12
E 11
 *
 *	%W% (Berkeley) %G%
 */
E 8

/*
 * Raw protocol interface control block.  Used
 * to tie a socket to the generic raw interface.
 */
struct rawcb {
	struct	rawcb *rcb_next;	/* doubly linked list */
	struct	rawcb *rcb_prev;
	struct	socket *rcb_socket;	/* back pointer to socket */
D 4
	struct	sockaddr rcb_addr;	/* destination address */
E 4
I 4
	struct	sockaddr rcb_faddr;	/* destination address */
	struct	sockaddr rcb_laddr;	/* socket's address */
I 7
	struct	sockproto rcb_proto;	/* protocol family, protocol */
E 7
E 4
	caddr_t	rcb_pcb;		/* protocol specific stuff */
I 9
	struct	mbuf *rcb_options;	/* protocol specific options */
E 9
I 5
	struct	route rcb_route;	/* routing information */
E 5
	short	rcb_flags;
};

/*
 * Since we can't interpret canonical addresses,
 * we mark an address present in the flags field.
 */
D 4
#define	RAW_ADDR	01		/* got an address */
E 4
I 4
#define	RAW_LADDR	01
#define	RAW_FADDR	02
I 5
#define	RAW_DONTROUTE	04		/* no routing, default */
E 5
E 4

#define	sotorawcb(so)		((struct rawcb *)(so)->so_pcb)

/*
 * Nominal space allocated to a raw socket.
 */
#define	RAWSNDQ		2048
#define	RAWRCVQ		2048

/*
D 3
 * Format of raw interface header appended by
 * raw_input after call from protocol specific input routine.
E 3
I 3
 * Format of raw interface header prepended by
 * raw_input after call from protocol specific
 * input routine.
E 3
 */
struct raw_header {
D 2
	struct	sockproto raw_protocol;
	struct	sockaddr raw_address;
E 2
I 2
D 4
	struct	sockproto raw_protocol;	/* format of packet */
E 4
I 4
	struct	sockproto raw_proto;	/* format of packet */
E 4
	struct	sockaddr raw_dst;	/* dst address for rawintr */
	struct	sockaddr raw_src;	/* src address for sbappendaddr */
E 2
};

#ifdef KERNEL
struct rawcb rawcb;			/* head of list */
#endif
E 1
