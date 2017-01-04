h08329
s 00010/00005/00039
d D 7.3 88/06/29 17:06:41 bostic 11 10
c install approved copyright notice
e
s 00008/00002/00036
d D 7.2 87/12/07 17:45:23 bostic 10 9
c use Berkeley specific header
e
s 00001/00001/00037
d D 7.1 86/06/05 00:26:18 mckusick 9 8
c 4.3BSD release version
e
s 00001/00000/00037
d D 6.3 85/09/16 22:51:58 karels 8 7
c add ip iptions to inpcb
e
s 00007/00001/00030
d D 6.2 85/06/08 12:38:33 mckusick 7 6
c Add copyright
e
s 00000/00000/00031
d D 6.1 83/07/29 07:11:20 sam 6 5
c 4.2 distribution
e
s 00000/00000/00031
d D 4.5 82/10/20 01:22:22 root 5 4
c lint
e
s 00001/00000/00030
d D 4.4 82/03/29 11:32:27 sam 4 3
c first cut (incomplete) at routing
e
s 00003/00000/00027
d D 4.3 82/03/03 11:06:45 root 3 2
c wildcard addresses
e
s 00002/00000/00025
d D 4.2 81/12/03 17:29:38 wnj 2 1
c cleanup
e
s 00025/00000/00000
d D 4.1 81/11/20 00:52:27 wnj 1 0
c date and time created 81/11/20 00:52:27 by wnj
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
D 9
 * Copyright (c) 1982 Regents of the University of California.
E 9
I 9
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 9
D 10
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 10
I 10
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 11
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 11
I 11
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
E 11
E 10
 *
 *	%W% (Berkeley) %G%
 */
E 7

/*
 * Common structure pcb for internet protocol implementation.
 * Here are stored pointers to local and foreign host table
 * entries, local and foreign socket numbers, and pointers
 * up (to a socket structure) and down (to a protocol-specific)
 * control block.
 */
struct inpcb {
	struct	inpcb *inp_next,*inp_prev;
					/* pointers to other pcb's */
I 2
	struct	inpcb *inp_head;	/* pointer back to chain of inpcb's
					   for this protocol */
E 2
	struct	in_addr inp_faddr;	/* foreign host table entry */
	u_short	inp_fport;		/* foreign port */
	struct	in_addr inp_laddr;	/* local host table entry */
	u_short	inp_lport;		/* local port */
	struct	socket *inp_socket;	/* back pointer to socket */
	caddr_t	inp_ppcb;		/* pointer to per-protocol pcb */
I 4
	struct	route inp_route;	/* placeholder for routing entry */
I 8
	struct	mbuf *inp_options;	/* IP options */
E 8
E 4
};

I 3
#define	INPLOOKUP_WILDCARD	1
#define	INPLOOKUP_SETLOCAL	2

E 3
#define	sotoinpcb(so)	((struct inpcb *)(so)->so_pcb)

#ifdef KERNEL
struct	inpcb *in_pcblookup();
#endif
E 1
