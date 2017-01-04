h30720
s 00010/00005/00373
d D 7.7 88/06/29 17:06:38 bostic 68 67
c install approved copyright notice
e
s 00008/00002/00370
d D 7.6 87/12/07 17:45:17 bostic 67 66
c use Berkeley specific header
e
s 00002/00002/00370
d D 7.5 87/08/24 21:46:34 karels 66 65
c remove redundant assignments
e
s 00002/00002/00370
d D 7.4 87/07/30 13:52:34 karels 65 64
c useless register declarations
e
s 00007/00002/00365
d D 7.3 86/12/22 10:19:31 karels 64 63
c once again, try to get local address right: this time for DONTROUTE
c on point-to-point links (need to zero sin_port before calling ifa_ifwithdstaddr
e
s 00012/00012/00355
d D 7.2 86/09/04 19:32:57 karels 63 62
c rewrote too much last time... use ifp even if old route was good
e
s 00001/00001/00366
d D 7.1 86/06/05 00:25:55 mckusick 62 61
c 4.3BSD release version
e
s 00023/00014/00344
d D 6.17 86/05/27 19:30:10 karels 61 60
c watch for DONTROUTE when choosing local address
e
s 00034/00038/00324
d D 6.16 86/04/23 11:09:37 karels 60 59
c don't bother checking whether local on connect,
c just use routing; if interface route was changed, want to use other IF.
e
s 00001/00001/00361
d D 6.15 86/03/04 13:53:39 karels 59 58
c lint
e
s 00003/00003/00359
d D 6.14 86/02/23 23:23:38 karels 58 57
c lint
e
s 00003/00001/00359
d D 6.13 86/02/21 14:49:11 karels 57 56
c don't use direct interface address if it's down
e
s 00003/00004/00357
d D 6.12 86/02/12 17:49:05 karels 56 55
c minor cleanups
e
s 00002/00001/00359
d D 6.11 86/02/01 21:17:19 karels 55 54
c reserve a port range for unprivileged servers
e
s 00025/00001/00335
d D 6.10 85/11/20 15:47:14 karels 54 53
c change tcp notification of transmission problems so that ip
c can delete routes created by redirect that have gone bad
e
s 00009/00009/00327
d D 6.9 85/09/16 22:51:24 karels 53 52
c free ip options when detaching; notify routine to in_pcbnotify
c is now optional; lint; zap a goto
e
s 00007/00001/00329
d D 6.8 85/06/08 12:37:56 mckusick 52 51
c Add copyright
e
s 00020/00011/00310
d D 6.7 85/04/18 09:45:40 karels 51 49
c more fixes
e
s 00020/00011/00310
d R 6.7 85/04/16 09:57:40 karels 50 49
c fixes
e
s 00026/00013/00295
d D 6.6 85/03/18 15:36:06 karels 49 48
c move net addresses from interface to protocol layer
e
s 00001/00001/00307
d D 6.5 84/11/27 13:59:59 karels 48 47
c from Jim McKie
e
s 00026/00008/00282
d D 6.4 84/11/14 10:14:36 karels 47 46
c generalize in_pcbnotify, use it to cause reallocation of routes
c after receipt of a redirect
e
s 00027/00006/00263
d D 6.3 84/10/19 15:02:43 karels 46 45
c bind local address according to routing (caching the route);
c pick maximum seg sizes (offered and accepted) based on interface mtu,
c with default if not local
e
s 00011/00011/00258
d D 6.2 84/08/29 15:35:56 bloom 45 44
c Include file changes.  No more ../h
e
s 00000/00000/00269
d D 6.1 83/07/29 07:11:14 sam 44 43
c 4.2 distribution
e
s 00004/00001/00265
d D 4.42 83/07/26 22:40:21 sam 43 42
c from wnj; auto-anchor local port on connect
e
s 00014/00000/00252
d D 4.41 83/07/25 21:55:25 sam 42 41
c getpeer
e
s 00004/00002/00248
d D 4.40 83/01/22 23:40:37 sam 41 39
c hack to allow FTP to rebind local addresses
e
s 00004/00002/00248
d R 4.40 83/01/22 22:48:27 sam 40 39
c hack for FTP and the rest of the Internet gang
e
s 00002/00001/00248
d D 4.39 83/01/22 22:15:34 sam 39 38
c allow reuse of TCP port numbers even when TIME_WAIT sockets exist
e
s 00013/00013/00236
d D 4.38 83/01/04 23:17:52 sam 38 37
c clean some stuff up and purge some crud
e
s 00001/00001/00248
d D 4.37 82/12/14 17:14:43 sam 37 36
c typed mbufs
e
s 00000/00016/00249
d D 4.36 82/11/03 01:08:07 root 36 35
c misc 4.1c fixes
e
s 00001/00004/00264
d D 4.35 82/10/30 13:02:51 root 35 34
c get rid of conditional htons/ntohs etc
e
s 00000/00000/00268
d D 4.34 82/10/20 01:22:15 root 34 33
c lint
e
s 00001/00001/00267
d D 4.33 82/10/17 14:54:43 root 33 32
c fix lint
e
s 00003/00003/00265
d D 4.32 82/10/09 05:45:04 wnj 32 31
c localize header files
e
s 00042/00146/00226
d D 4.31 82/09/26 18:29:29 root 31 30
c first working version
e
s 00000/00000/00372
d D 4.30 82/07/24 18:17:53 root 30 29
c restore sccs ids
e
s 00090/00002/00282
d D 4.29 82/07/24 18:12:43 root 29 28
c 
e
s 00000/00006/00284
d D 4.28 82/06/20 00:53:55 sam 28 27
c purge COUNT stuff now that we can use gprof
e
s 00001/00001/00289
d D 4.27 82/06/13 23:01:32 sam 27 26
c add class a/b/c net #'s and purge logical host kludge code
e
s 00041/00002/00249
d D 4.26 82/04/24 20:37:59 sam 26 25
c icmp and ctlinput working -- missing protocol specific ctlinput's
e
s 00013/00018/00238
d D 4.25 82/04/10 23:41:16 sam 25 24
c purge so_addr from socket structure and start cleaning up raw code
e
s 00001/00001/00255
d D 4.24 82/03/30 11:32:18 sam 24 23
c with routing, but not forwarding
e
s 00011/00003/00245
d D 4.23 82/03/29 11:32:18 sam 23 22
c first cut (incomplete) at routing
e
s 00011/00006/00237
d D 4.22 82/03/28 14:22:31 sam 22 21
c convert interfaces to sockaddr's and add hooks for routing
e
s 00006/00007/00237
d D 4.21 82/03/23 15:51:16 wnj 21 20
c more kludges stuff for so_addr (ick)
e
s 00002/00002/00242
d D 4.20 82/03/13 12:52:12 sam 20 19
c lint
e
s 00025/00005/00219
d D 4.19 82/03/11 23:09:16 wnj 19 18
c minor bug fixes
e
s 00008/00009/00216
d D 4.18 82/03/03 11:06:48 root 18 17
c wildcard addresses
e
s 00073/00041/00152
d D 4.17 82/02/27 17:47:11 wnj 17 16
c multi-homing and wildcards
e
s 00002/00002/00191
d D 4.16 82/02/15 11:33:51 root 16 15
c clean up 1's and 0's in mbuf calls
e
s 00011/00000/00182
d D 4.15 81/12/21 10:27:43 root 15 14
c add foreign address building function
e
s 00005/00003/00177
d D 4.14 81/12/19 12:36:28 wnj 14 13
c local address 0 gives preferred local net
e
s 00006/00005/00174
d D 4.13 81/12/11 22:14:04 root 13 12
c cleanup
e
s 00019/00022/00160
d D 4.12 81/12/03 17:29:32 wnj 12 11
c cleanup
e
s 00064/00016/00118
d D 4.11 81/12/02 16:58:26 wnj 11 10
c yet more lint
e
s 00001/00001/00133
d D 4.10 81/11/29 21:59:23 wnj 10 9
c lint and interface cleanups
e
s 00003/00003/00131
d D 4.9 81/11/26 11:56:20 wnj 9 8
c before carry to ARPAVAX
e
s 00002/00004/00132
d D 4.8 81/11/21 21:28:02 wnj 8 7
c fix in_pcbfree to close properly
e
s 00012/00010/00124
d D 4.7 81/11/21 15:20:07 wnj 7 6
c minor bugs (inp vs xp, insque arg order, pointer init)
e
s 00001/00001/00133
d D 4.6 81/11/20 14:41:40 wnj 6 5
c more lint
e
s 00004/00000/00130
d D 4.5 81/11/20 01:18:38 wnj 5 4
c so_addr
e
s 00082/00042/00048
d D 4.4 81/11/20 00:46:33 wnj 4 3
c linted
e
s 00016/00001/00074
d D 4.3 81/11/18 15:36:57 wnj 3 2
c more cleanup
e
s 00019/00016/00056
d D 4.2 81/11/16 14:16:35 wnj 2 1
c more lint
e
s 00072/00000/00000
d D 4.1 81/11/15 14:34:06 wnj 1 0
c date and time created 81/11/15 14:34:06 by wnj
e
u
U
t
T
I 1
D 16
/* %M% %I% %E% */
E 16
I 16
D 52
/*	%M%	%I%	%E%	*/
E 52
I 52
/*
D 62
 * Copyright (c) 1982 Regents of the University of California.
E 62
I 62
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 62
D 67
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 67
I 67
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 68
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 68
I 68
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
E 68
E 67
 *
 *	%W% (Berkeley) %G%
 */
E 52
E 16

D 45
#include "../h/param.h"
I 4
#include "../h/systm.h"
#include "../h/dir.h"
#include "../h/user.h"
E 4
#include "../h/mbuf.h"
#include "../h/socket.h"
#include "../h/socketvar.h"
D 9
#include "../net/inet.h"
#include "../net/inet_systm.h"
E 9
I 9
D 32
#include "../net/in.h"
#include "../net/in_systm.h"
E 32
I 32
#include "../netinet/in.h"
#include "../netinet/in_systm.h"
E 45
I 45
#include "param.h"
#include "systm.h"
#include "dir.h"
#include "user.h"
#include "mbuf.h"
#include "socket.h"
#include "socketvar.h"
I 54
#include "ioctl.h"
E 54
#include "in.h"
#include "in_systm.h"
E 45
E 32
E 9
I 2
D 4
#include "../net/inet_host.h"
E 4
I 4
#include "../net/if.h"
I 23
#include "../net/route.h"
E 23
E 4
D 9
#include "../net/inet_pcb.h"
E 9
I 9
D 32
#include "../net/in_pcb.h"
E 32
I 32
D 45
#include "../netinet/in_pcb.h"
E 32
I 19
#include "../h/protosw.h"
E 45
I 45
#include "in_pcb.h"
I 49
#include "in_var.h"
E 49
#include "protosw.h"
E 45
E 19
E 9
E 2

D 4
struct inpcb *
in_pcballoc()
E 4
I 4
D 31
/*
I 11
 * Routines to manage internet protocol control blocks.
 *
 * At PRU_ATTACH time a protocol control block is allocated in
 * in_pcballoc() and inserted on a doubly-linked list of such blocks
 * for the protocol.  A port address is either requested (and verified
 * to not be in use) or assigned at this time.  We also allocate
 * space in the socket sockbuf structures here, although this is
 * not a clearly correct place to put this function.
 *
 * A connectionless protocol will have its protocol control block
 * removed at PRU_DETACH time, when the socket will be freed (freeing
 * the space reserved) and the block will be removed from the list of
 * blocks for its protocol.
 *
 * A connection-based protocol may be connected to a remote peer at
 * PRU_CONNECT time through the routine in_pcbconnect().  In the normal
 * case a PRU_DISCONNECT occurs causing a in_pcbdisconnect().
 * It is also possible that higher-level routines will opt out of the
 * relationship with the connection before the connection shut down
 * is complete.  This often occurs in protocols like TCP where we must
 * hold on to the protocol control block for a unreasonably long time
 * after the connection is used up to avoid races in later connection
 * establishment.  To handle this we allow higher-level routines to
D 29
 * disassociate themselves from the socket, marking it SS_USERGONE while
E 29
I 29
 * disassociate themselves from the socket, marking it SS_NOFDREF while
E 29
 * the disconnect is in progress.  We notice that this has happened
 * when the disconnect is complete, and perform the PRU_DETACH operation,
 * freeing the socket.
I 12
 *
 * TODO:
 *	use hashing
E 12
 */
E 31
I 13
struct	in_addr zeroin_addr;
E 13

I 29
D 36
in_pcbreserve(so, sndcc, rcvcc)
	struct socket *so;
	int sndcc, rcvcc;
{

	if (sbreserve(&so->so_snd, sndcc) == 0)
		goto bad;
	if (sbreserve(&so->so_rcv, rcvcc) == 0)
		goto bad2;
	return (0);
bad2:
	sbrelease(&so->so_snd);
bad:
	return (ENOBUFS);
}

E 36
in_pcballoc(so, head)
	struct socket *so;
	struct inpcb *head;
{
	struct mbuf *m;
	register struct inpcb *inp;

D 37
	m = m_getclr(M_DONTWAIT);
E 37
I 37
	m = m_getclr(M_DONTWAIT, MT_PCB);
E 37
D 38
	if (m == 0)
E 38
I 38
	if (m == NULL)
E 38
		return (ENOBUFS);
	inp = mtod(m, struct inpcb *);
	inp->inp_head = head;
	inp->inp_socket = so;
	insque(inp, head);
	so->so_pcb = (caddr_t)inp;
	return (0);
}
	
D 31
in_pcbbind(inp, sin)
E 31
I 31
in_pcbbind(inp, nam)
E 31
	register struct inpcb *inp;
D 31
	struct sockaddr_in *sin;
E 31
I 31
	struct mbuf *nam;
E 31
{
	register struct socket *so = inp->inp_socket;
	register struct inpcb *head = inp->inp_head;
I 31
	register struct sockaddr_in *sin;
E 31
	u_short lport = 0;

D 49
	if (ifnet == 0)
E 49
I 49
	if (in_ifaddr == 0)
E 49
		return (EADDRNOTAVAIL);
D 31
	if (sin) {
		if (sin->sin_family != AF_INET)
			return (EAFNOSUPPORT);
		if (sin->sin_addr.s_addr) {
			int tport = sin->sin_port;
E 31
I 31
D 38
	if (inp->inp_lport || inp->inp_laddr.s_addr)
E 38
I 38
	if (inp->inp_lport || inp->inp_laddr.s_addr != INADDR_ANY)
E 38
		return (EINVAL);
	if (nam == 0)
		goto noname;
	sin = mtod(nam, struct sockaddr_in *);
	if (nam->m_len != sizeof (*sin))
		return (EINVAL);
D 38
	if (sin->sin_addr.s_addr) {
E 38
I 38
	if (sin->sin_addr.s_addr != INADDR_ANY) {
E 38
		int tport = sin->sin_port;
E 31

D 31
			sin->sin_port = 0;		/* yech... */
			if (if_ifwithaddr((struct sockaddr *)sin) == 0)
				return (EADDRNOTAVAIL);
			sin->sin_port = tport;
		}
		lport = sin->sin_port;
		if (lport) {
			u_short aport = lport;
			int wild = 0;
#if vax
			aport = htons(aport);
#endif
			/* GROSS */
			if (aport < IPPORT_RESERVED && u.u_uid != 0)
				return (EACCES);
			if ((so->so_proto->pr_flags & PR_CONNREQUIRED) == 0 ||
			    (so->so_options & SO_ACCEPTCONN) == 0)
				wild = INPLOOKUP_WILDCARD;
			if (in_pcblookup(head,
			    zeroin_addr, 0, sin->sin_addr, lport, wild))
				return (EADDRINUSE);
		}
E 31
I 31
		sin->sin_port = 0;		/* yech... */
D 49
		if (if_ifwithaddr((struct sockaddr *)sin) == 0)
E 49
I 49
		if (ifa_ifwithaddr((struct sockaddr *)sin) == 0)
E 49
			return (EADDRNOTAVAIL);
		sin->sin_port = tport;
E 31
	}
D 31
	if (sin)
		inp->inp_laddr = sin->sin_addr;
	if (lport == 0)
		do {
			if (head->inp_lport++ < IPPORT_RESERVED)
				head->inp_lport = IPPORT_RESERVED;
			lport = htons(head->inp_lport);
		} while (in_pcblookup(head,
			    zeroin_addr, 0, inp->inp_laddr, lport, 0));
	inp->inp_lport = lport;
	return (0);
}
E 31
I 31
	lport = sin->sin_port;
	if (lport) {
D 35
		u_short aport = lport;
E 35
I 35
D 48
		u_short aport = htons(lport);
E 48
I 48
		u_short aport = ntohs(lport);
E 48
E 35
		int wild = 0;
E 31

D 31
/* BEGIN DEPRECATED */
E 29
/*
E 11
 * Allocate a protocol control block, space
 * for send and receive data, and local host information.
 * Return error.  If no error make socket point at pcb.
 */
D 11
in_pcballoc(so, head, sndcc, rcvcc, sin)
E 11
I 11
in_pcbattach(so, head, sndcc, rcvcc, sin)
E 11
	struct socket *so;
	struct inpcb *head;
	int sndcc, rcvcc;
	struct sockaddr_in *sin;
E 4
{
D 4

E 4
	struct mbuf *m;
I 4
D 7
	register struct inpcb *inp;
E 7
I 7
D 13
	register struct inpcb *inp, *xp;
E 13
I 13
	register struct inpcb *inp;
E 13
E 7
D 17
	struct ifnet *ifp;
D 13
	u_long lport;
E 13
I 13
	u_short lport;
E 17
I 17
	u_short lport = 0;
E 17
E 13
E 4

I 11
D 28
COUNT(IN_PCBATTACH);
E 28
I 17
	if (ifnet == 0)
		return (EADDRNOTAVAIL);
E 17
E 11
I 4
	if (sin) {
		if (sin->sin_family != AF_INET)
			return (EAFNOSUPPORT);
I 14
D 17
		if (ifnet && sin->sin_addr.s_addr == 0)
			sin->sin_addr = ifnet->if_addr;
E 14
		ifp = if_ifwithaddr(sin->sin_addr);
E 17
I 17
D 23
		if (sin->sin_addr.s_addr &&
D 20
		    if_ifwithaddr(sin->sin_addr.s_addr) == 0)
E 20
I 20
D 22
		    if_ifwithaddr(sin->sin_addr) == 0)
E 22
I 22
		    if_ifwithaddr((struct sockaddr *)sin) == 0)
E 22
E 20
			return (EADDRNOTAVAIL);
E 23
I 23
		if (sin->sin_addr.s_addr) {
			int tport = sin->sin_port;

			sin->sin_port = 0;		/* yech... */
			if (if_ifwithaddr((struct sockaddr *)sin) == 0)
				return (EADDRNOTAVAIL);
			sin->sin_port = tport;
		}
E 23
E 17
D 14
		if (ifp == 0)
			return (EADDRNOTAVAIL);
E 14
		lport = sin->sin_port;
D 12
		if (lport) {
D 7
			inp = head->inp_next;
			for (; inp != head; inp = inp->inp_next) 
				if (inp->inp_laddr.s_addr ==
E 7
I 7
			xp = head->inp_next;
D 10
			for (; xp != head; xp = inp->inp_next) 
E 10
I 10
			for (; xp != head; xp = xp->inp_next) 
E 10
				if (xp->inp_laddr.s_addr ==
E 7
				    sin->sin_addr.s_addr &&
D 7
				    inp->inp_lport == lport &&
				    inp->inp_faddr.s_addr == 0)
E 7
I 7
				    xp->inp_lport == lport &&
				    xp->inp_faddr.s_addr == 0)
E 7
					return (EADDRINUSE);
		}
E 12
I 12
D 17
		if (lport &&
D 13
		    in_pcblookup(head, 0, 0, sin->sin_addr.s_addr, lport))
E 13
I 13
		    in_pcblookup(head, zeroin_addr, 0, sin->sin_addr, lport))
E 13
			return (EADDRINUSE);
E 12
	} else {
D 14
		ifp = if_ifwithaddr(ifnet->if_addr);
E 14
I 14
		ifp = ifnet;
E 14
		lport = 0;
E 17
I 17
		if (lport) {
			u_short aport = lport;
I 19
			int wild = 0;
E 31
E 19
D 33
#if vax
E 33
I 33
D 35
#if vax || pdp11 || ns16032
E 33
D 31
			aport = htons(aport);
E 31
I 31
		aport = htons(aport);
E 31
#endif
E 35
D 31
			/* GROSS */
			if (aport < IPPORT_RESERVED && u.u_uid != 0)
D 26
				return (EPERM);
E 26
I 26
				return (EACCES);
E 26
I 19
			if ((so->so_proto->pr_flags & PR_CONNREQUIRED) == 0 ||
			    (so->so_options & SO_ACCEPTCONN) == 0)
				wild = INPLOOKUP_WILDCARD;
E 19
			if (in_pcblookup(head,
D 19
			    zeroin_addr, 0, sin->sin_addr, lport, 0))
E 19
I 19
			    zeroin_addr, 0, sin->sin_addr, lport, wild))
E 19
				return (EADDRINUSE);
		}
E 31
I 31
		/* GROSS */
		if (aport < IPPORT_RESERVED && u.u_uid != 0)
			return (EACCES);
D 39
		if ((so->so_proto->pr_flags & PR_CONNREQUIRED) == 0)
E 39
I 39
D 41
		if ((so->so_proto->pr_flags & PR_CONNREQUIRED) == 0 ||
		    (so->so_options & SO_ACCEPTCONN) == 0)
E 41
I 41
		/* even GROSSER, but this is the Internet */
		if ((so->so_options & SO_REUSEADDR) == 0 &&
		    ((so->so_proto->pr_flags & PR_CONNREQUIRED) == 0 ||
		     (so->so_options & SO_ACCEPTCONN) == 0))
E 41
E 39
			wild = INPLOOKUP_WILDCARD;
		if (in_pcblookup(head,
		    zeroin_addr, 0, sin->sin_addr, lport, wild))
			return (EADDRINUSE);
E 31
E 17
	}
I 14
D 17
	if (ifp == 0)
		return (EADDRNOTAVAIL);
E 17
E 14
E 4
D 12
	m = m_getclr(M_WAIT);
E 12
I 12
D 16
	m = m_getclr(0);
E 16
I 16
D 31
	m = m_getclr(M_DONTWAIT);
E 16
E 12
D 4
	m->m_off = MMINOFF;
	return (mtod(m, struct inpcb *));
E 4
I 4
	if (m == 0)
D 7
		return (0);
E 7
I 7
		return (ENOBUFS);
E 7
	if (sbreserve(&so->so_snd, sndcc) == 0)
		goto bad;
	if (sbreserve(&so->so_rcv, rcvcc) == 0)
		goto bad2;
	inp = mtod(m, struct inpcb *);
I 12
	inp->inp_head = head;
E 12
D 17
	inp->inp_laddr = ifp->if_addr;
E 17
I 17
	if (sin)
		inp->inp_laddr = sin->sin_addr;
E 31
I 31
	inp->inp_laddr = sin->sin_addr;
noname:
E 31
E 17
D 12
	if (lport)
		goto gotport;
again:
	if (head->inp_lport++ < 1024)
		head->inp_lport = 1024;
D 7
	for (inp = head->inp_next; inp != head; inp = inp->inp_next)
		if (inp->inp_lport == head->inp_lport)
E 7
I 7
	for (xp = head->inp_next; xp != head; xp = xp->inp_next)
		if (xp->inp_lport == head->inp_lport)
E 7
			goto again;
D 11
	lport = head->inp_lport;
E 11
I 11
	lport = htons(head->inp_lport);
E 11
gotport:
I 7
	inp->inp_socket = so;
E 12
I 12
	if (lport == 0)
		do {
D 17
			if (head->inp_lport++ < 1024)
				head->inp_lport = 1024;
E 17
I 17
D 55
			if (head->inp_lport++ < IPPORT_RESERVED)
E 55
I 55
			if (head->inp_lport++ < IPPORT_RESERVED ||
			    head->inp_lport > IPPORT_USERRESERVED)
E 55
				head->inp_lport = IPPORT_RESERVED;
E 17
			lport = htons(head->inp_lport);
D 13
		} while (in_pcblookup(head, 0, 0, inp->inp_laddr, lport));
E 13
I 13
D 17
		} while (in_pcblookup(head, zeroin_addr, 0, inp->inp_laddr, lport));
E 17
I 17
		} while (in_pcblookup(head,
			    zeroin_addr, 0, inp->inp_laddr, lport, 0));
E 17
E 13
E 12
E 7
	inp->inp_lport = lport;
I 12
D 31
	inp->inp_socket = so;
E 12
D 7
	insque(head, inp);
E 7
I 7
	insque(inp, head);
E 7
	so->so_pcb = (caddr_t)inp;
E 31
I 5
D 17
	sin = (struct sockaddr_in *)&so->so_addr;
	sin->sin_family = AF_INET;
	sin->sin_addr = inp->inp_laddr;
	sin->sin_port = inp->inp_lport;
E 17
I 17
D 25
	in_setsockaddr(inp);
E 25
E 17
E 5
	return (0);
D 31
bad2:
	sbrelease(&so->so_snd);
bad:
D 6
	m_free(m);
E 6
I 6
	(void) m_free(m);
E 6
	return (ENOBUFS);
E 31
E 4
}
I 29
D 31
/* END DEPRECATED */
E 31
E 29

I 19
/*
 * Connect from a socket to a specified address.
 * Both address and port must be specified in argument sin.
 * If don't have a local address for this socket yet,
 * then pick one.
 */
E 19
I 3
D 4
in_pcbenter(head, new)
	struct inpcb *head, *new;
E 4
I 4
D 11
in_pcbsetpeer(inp, sin)
E 11
I 11
D 31
in_pcbconnect(inp, sin)
E 31
I 31
in_pcbconnect(inp, nam)
E 31
E 11
D 65
	struct inpcb *inp;
E 65
I 65
	register struct inpcb *inp;
E 65
D 31
	struct sockaddr_in *sin;
E 31
I 31
	struct mbuf *nam;
E 31
E 4
{
I 12
D 17
	struct inpcb *xp;
E 17
I 17
D 49
	struct ifnet *ifp;
E 49
I 49
	struct in_ifaddr *ia;
E 49
I 22
	struct sockaddr_in *ifaddr;
I 31
	register struct sockaddr_in *sin = mtod(nam, struct sockaddr_in *);
E 31
E 22
E 17
E 12
D 4
	register struct inpcb *inp;
E 4

I 31
	if (nam->m_len != sizeof (*sin))
		return (EINVAL);
E 31
I 11
D 28
COUNT(IN_PCBCONNECT);
E 28
E 11
D 4
	for (inp = head->inp_next; inp != head; inp = inp->inp_next)
		if (inp->inp_fhost->h_addr.s_addr == new->inp_fhost.s_addr &&
		    inp->inp_fport == new->inp_fport &&
		    inp->inp_lhost->h_addr.s_addr = new->inp_fhost.s_addr &&
		    inp->inp_lport == new->inp_lport)
			return (EADDRINUSE);
	insque(new, head);
E 4
I 4
	if (sin->sin_family != AF_INET)
		return (EAFNOSUPPORT);
D 38
	if (sin->sin_addr.s_addr == 0 || sin->sin_port == 0)
E 38
I 38
D 49
	if (sin->sin_addr.s_addr == INADDR_ANY || sin->sin_port == 0)
E 49
I 49
	if (sin->sin_port == 0)
E 49
E 38
		return (EADDRNOTAVAIL);
I 49
	if (in_ifaddr) {
I 51
		/*
		 * If the destination address is INADDR_ANY,
		 * use the primary local address.
		 * If the supplied address is INADDR_BROADCAST,
		 * and the primary interface supports broadcast,
		 * choose the broadcast address for that interface.
		 */
E 51
#define	satosin(sa)	((struct sockaddr_in *)(sa))
		if (sin->sin_addr.s_addr == INADDR_ANY)
D 51
		    sin->sin_addr.s_addr = IA_SIN(in_ifaddr)->sin_addr.s_addr;
		else if (sin->sin_addr.s_addr == INADDR_BROADCAST)
		    /* SHOULD CHECK FOR BROADCAST CAPABILITY */
		    sin->sin_addr.s_addr = satosin(&in_ifaddr->ia_broadaddr)->sin_addr.s_addr;
E 51
I 51
		    sin->sin_addr = IA_SIN(in_ifaddr)->sin_addr;
D 53
		else if (sin->sin_addr.s_addr == INADDR_BROADCAST &&
E 53
I 53
		else if (sin->sin_addr.s_addr == (u_long)INADDR_BROADCAST &&
E 53
		  (in_ifaddr->ia_ifp->if_flags & IFF_BROADCAST))
		    sin->sin_addr = satosin(&in_ifaddr->ia_broadaddr)->sin_addr;
E 51
	}
E 49
D 12
	/* should check not already in use... */
E 12
I 12
D 17
	xp = in_pcblookup(inp->inp_head, sin->sin_addr, sin->sin_port, inp->inp_laddr, inp->inp_lport);
D 13
	if (xp->inp_faddr)
E 13
I 13
	if (xp->inp_faddr.s_addr)
E 17
I 17
D 38
	if (inp->inp_laddr.s_addr == 0) {
E 38
I 38
	if (inp->inp_laddr.s_addr == INADDR_ANY) {
E 38
D 20
		ifp = if_ifonnetof(sin->sin_addr.s_addr);
E 20
I 20
D 22
		ifp = if_ifonnetof(sin->sin_addr);
E 20
		if (ifp == 0)
			ifp = ifnet;
E 22
I 22
D 27
		ifp = if_ifonnetof(sin->sin_addr.s_net);
E 27
I 27
D 49
		ifp = if_ifonnetof(in_netof(sin->sin_addr));
E 27
		if (ifp == 0) {
E 49
I 49
D 51
		ia = (struct in_ifaddr *)ifa_ifwithnet(sin);
E 51
I 51
D 56
		ia = (struct in_ifaddr *)ifa_ifwithnet((struct sockaddr *)sin);
E 56
I 56
D 60
		ia = in_iaonnetof(in_netof(sin->sin_addr));
E 56
E 51
D 57
		if (ia == (struct in_ifaddr *)0) {
E 57
I 57
		if (ia == (struct in_ifaddr *)0 ||
		    (ia->ia_ifp->if_flags & IFF_UP) == 0) {
E 57
E 49
I 26
D 46
			/*
			 * We should select the interface based on
			 * the route to be used, but for udp this would
			 * result in two calls to rtalloc for each packet
			 * sent; hardly worthwhile...
E 46
I 46
			register struct route *ro;
I 49
			struct ifnet *ifp;
E 60
I 60
		register struct route *ro;
		struct ifnet *ifp;
E 60
E 49

I 57
D 60
			ia = (struct in_ifaddr *)0;
E 57
			/* 
			 * If route is known or can be allocated now,
			 * our src addr is taken from the i/f, else punt.
E 46
			 */
E 26
D 46
			ifp = if_ifwithaf(AF_INET);
E 46
I 46
			ro = &inp->inp_route;
D 49
#define	satosin(sa)	((struct sockaddr_in *)(sa))
E 49
			if (ro->ro_rt &&
			    satosin(&ro->ro_dst)->sin_addr.s_addr !=
			    sin->sin_addr.s_addr) {
				RTFREE(ro->ro_rt);
				ro->ro_rt = (struct rtentry *)0;
			}
			if ((ro->ro_rt == (struct rtentry *)0) ||
			    (ifp = ro->ro_rt->rt_ifp) == (struct ifnet *)0) {
I 49
D 51
				struct ifnet *ifp;

E 51
E 49
				/* No route yet, so try to acquire one */
				ro->ro_dst.sa_family = AF_INET;
				((struct sockaddr_in *) &ro->ro_dst)->sin_addr =
					sin->sin_addr;
				rtalloc(ro);
D 56
				if (ro->ro_rt == 0)
E 56
I 56
				if (ro->ro_rt == (struct rtentry *)0)
E 56
D 49
					ifp = (struct ifnet *) 0;
E 49
I 49
D 51
				    ia = (struct in_ifaddr *) 0;
E 51
I 51
					ifp = (struct ifnet *)0;
E 51
E 49
				else
D 49
					ifp = ro->ro_rt->rt_ifp;
E 49
I 49
D 51
				    for (ia = in_ifaddr; ia; ia = ia->ia_next)
					if (ia->ia_ifp == ifp)
					    break;
E 51
I 51
					ifp = ro->ro_rt->rt_ifp;
E 51
E 49
			}
I 51
			if (ifp) {
				for (ia = in_ifaddr; ia; ia = ia->ia_next)
					if (ia->ia_ifp == ifp)
						break;
D 56
			} else
				ia = (struct in_ifaddr *)0;
E 56
I 56
			}
E 56
E 51
D 49
			if (ifp == 0)
				ifp = if_ifwithaf(AF_INET);
E 46
			if (ifp == 0)
E 49
I 49
			if (ia == 0)
				ia = in_ifaddr;
			if (ia == 0)
E 49
D 26
				return (EADDRNOTAVAIL);		/* XXX */
E 26
I 26
				return (EADDRNOTAVAIL);
E 60
I 60
		ia = (struct in_ifaddr *)0;
		/* 
		 * If route is known or can be allocated now,
		 * our src addr is taken from the i/f, else punt.
		 */
		ro = &inp->inp_route;
		if (ro->ro_rt &&
D 64
		    satosin(&ro->ro_dst)->sin_addr.s_addr !=
		    sin->sin_addr.s_addr) {
E 64
I 64
		    (satosin(&ro->ro_dst)->sin_addr.s_addr !=
			sin->sin_addr.s_addr || 
		    inp->inp_socket->so_options & SO_DONTROUTE)) {
E 64
			RTFREE(ro->ro_rt);
			ro->ro_rt = (struct rtentry *)0;
E 60
E 26
		}
I 60
D 61
		if ((ro->ro_rt == (struct rtentry *)0) ||
		    (ifp = ro->ro_rt->rt_ifp) == (struct ifnet *)0) {
E 61
I 61
		if ((inp->inp_socket->so_options & SO_DONTROUTE) == 0 && /*XXX*/
		    (ro->ro_rt == (struct rtentry *)0 ||
D 63
		    (ifp = ro->ro_rt->rt_ifp) == (struct ifnet *)0)) {
E 63
I 63
		    ro->ro_rt->rt_ifp == (struct ifnet *)0)) {
E 63
E 61
			/* No route yet, so try to acquire one */
			ro->ro_dst.sa_family = AF_INET;
			((struct sockaddr_in *) &ro->ro_dst)->sin_addr =
				sin->sin_addr;
			rtalloc(ro);
D 61
			if (ro->ro_rt == (struct rtentry *)0)
				ifp = (struct ifnet *)0;
			else
				ifp = ro->ro_rt->rt_ifp;
E 61
I 61
D 63
			/*
			 * If we found a route, use the address
			 * corresponding to the outgoing interface
			 * unless it is the loopback (in case a route
			 * to our address on another net goes to loopback).
			 */
			if (ro->ro_rt && (ifp = ro->ro_rt->rt_ifp) &&
			    (ifp->if_flags & IFF_LOOPBACK) == 0)
				for (ia = in_ifaddr; ia; ia = ia->ia_next)
					if (ia->ia_ifp == ifp)
						break;
E 63
E 61
		}
I 63
		/*
		 * If we found a route, use the address
		 * corresponding to the outgoing interface
		 * unless it is the loopback (in case a route
		 * to our address on another net goes to loopback).
		 */
		if (ro->ro_rt && (ifp = ro->ro_rt->rt_ifp) &&
		    (ifp->if_flags & IFF_LOOPBACK) == 0)
			for (ia = in_ifaddr; ia; ia = ia->ia_next)
				if (ia->ia_ifp == ifp)
					break;
E 63
D 61
		if (ifp) {
			for (ia = in_ifaddr; ia; ia = ia->ia_next)
				if (ia->ia_ifp == ifp)
					break;
E 61
I 61
		if (ia == 0) {
I 64
			int fport = sin->sin_port;

			sin->sin_port = 0;
E 64
			ia = (struct in_ifaddr *)
			    ifa_ifwithdstaddr((struct sockaddr *)sin);
I 64
			sin->sin_port = fport;
E 64
			if (ia == 0)
				ia = in_iaonnetof(in_netof(sin->sin_addr));
			if (ia == 0)
				ia = in_ifaddr;
			if (ia == 0)
				return (EADDRNOTAVAIL);
E 61
		}
D 61
		if (ia == 0)
			ia = in_ifaddr;
		if (ia == 0)
			return (EADDRNOTAVAIL);
E 61
E 60
D 49
		ifaddr = (struct sockaddr_in *)&ifp->if_addr;
E 49
I 49
		ifaddr = (struct sockaddr_in *)&ia->ia_addr;
E 49
E 22
D 18
		inp->inp_laddr = ifp->if_addr;
E 18
	}
	if (in_pcblookup(inp->inp_head,
D 19
	    sin->sin_addr, sin->sin_port, inp->inp_laddr, inp->inp_lport, 0))
E 19
I 19
	    sin->sin_addr,
	    sin->sin_port,
D 22
	    inp->inp_laddr.s_addr ? inp->inp_laddr : ifp->if_addr,
E 22
I 22
	    inp->inp_laddr.s_addr ? inp->inp_laddr : ifaddr->sin_addr,
E 22
	    inp->inp_lport,
	    0))
E 19
E 17
E 13
		return (EADDRINUSE);
I 18
D 21
	if (inp->inp_laddr.s_addr == 0)
E 21
I 21
D 25
	if (inp->inp_laddr.s_addr == 0) {
		struct sockaddr_in *sin2 =
		    (struct sockaddr_in *)&inp->inp_socket->so_addr;

E 25
I 25
D 38
	if (inp->inp_laddr.s_addr == 0)
E 38
I 38
D 43
	if (inp->inp_laddr.s_addr == INADDR_ANY)
E 43
I 43
	if (inp->inp_laddr.s_addr == INADDR_ANY) {
		if (inp->inp_lport == 0)
D 58
			in_pcbbind(inp, (struct mbuf *)0);
E 58
I 58
			(void)in_pcbbind(inp, (struct mbuf *)0);
E 58
E 43
E 38
E 25
E 21
D 22
		inp->inp_laddr = ifp->if_addr;
E 22
I 22
		inp->inp_laddr = ifaddr->sin_addr;
I 43
	}
E 43
E 22
I 21
D 25
		sin2->sin_addr = inp->inp_laddr;
	}
E 25
E 21
E 18
E 12
	inp->inp_faddr = sin->sin_addr;
	inp->inp_fport = sin->sin_port;
E 4
	return (0);
}

I 15
D 17
in_pcbconnaddr(inp, sp)
E 17
I 17
D 25
in_setsockaddr(inp)
E 17
	struct inpcb *inp;
D 17
	struct sockaddr *sp;
E 17
{
D 17
	register struct sockaddr_in *sin = (struct sockaddr_in *)sp;
E 17
I 17
	register struct sockaddr_in *sin =
	    (struct sockaddr_in *)&inp->inp_socket->so_addr;
E 17

	sin->sin_family = AF_INET;
D 17
	sin->sin_port = inp->inp_fport;
	sin->sin_addr = inp->inp_faddr;
E 17
I 17
	sin->sin_addr = inp->inp_laddr;
	sin->sin_port = inp->inp_lport;
E 17
}

E 25
E 15
E 3
D 11
in_pcbfree(inp)
E 11
I 11
in_pcbdisconnect(inp)
E 11
	struct inpcb *inp;
{
I 11

D 28
COUNT(IN_PCBDISCONNECT);
E 28
D 38
	inp->inp_faddr.s_addr = 0;
E 38
I 38
	inp->inp_faddr.s_addr = INADDR_ANY;
E 38
I 18
	inp->inp_fport = 0;
E 18
D 29
	if (inp->inp_socket->so_state & SS_USERGONE)
E 29
I 29
	if (inp->inp_socket->so_state & SS_NOFDREF)
E 29
		in_pcbdetach(inp);
}

in_pcbdetach(inp)
	struct inpcb *inp;
{
E 11
	struct socket *so = inp->inp_socket;

I 26
D 28
COUNT(IN_PCBDETACH);
E 28
E 26
D 4
	if (so->so_isfilerefd == 0)
E 4
I 4
D 8
	if (so->so_state & SS_USERGONE)
E 4
		sofree(so);
	else
		so->so_pcb = 0;
E 8
I 8
	so->so_pcb = 0;
	sofree(so);
I 53
	if (inp->inp_options)
D 58
		m_free(inp->inp_options);
E 58
I 58
		(void)m_free(inp->inp_options);
E 58
E 53
I 23
	if (inp->inp_route.ro_rt)
D 24
		freeroute(inp->inp_route.ro_rt);
E 24
I 24
		rtfree(inp->inp_route.ro_rt);
E 24
E 23
E 8
I 7
	remque(inp);
E 7
D 4
	if (inp->inp_lhost)
D 2
		h_free(inp->inp_lhost);
E 2
I 2
		in_hostfree(inp->inp_lhost);
E 2
	if (inp->inp_fhost)
D 2
		h_free(inp->inp_fhost);
	m_free(dtom(inp));
E 2
I 2
		in_hostfree(inp->inp_fhost);
E 4
	(void) m_free(dtom(inp));
I 25
}

D 31
in_setsockaddr(sin, inp)
	register struct sockaddr_in *sin;
E 31
I 31
in_setsockaddr(inp, nam)
E 31
	register struct inpcb *inp;
I 31
	struct mbuf *nam;
E 31
{
I 26
D 28
COUNT(IN_SETSOCKADDR);
E 28
E 26
D 31
	if (sin == 0 || inp == 0)
		panic("setsockaddr_in");
E 31
I 31
D 66
	register struct sockaddr_in *sin = mtod(nam, struct sockaddr_in *);
E 66
I 66
	register struct sockaddr_in *sin;
E 66
	
	nam->m_len = sizeof (*sin);
	sin = mtod(nam, struct sockaddr_in *);
E 31
	bzero((caddr_t)sin, sizeof (*sin));
	sin->sin_family = AF_INET;
	sin->sin_port = inp->inp_lport;
	sin->sin_addr = inp->inp_laddr;
I 26
}

I 42
in_setpeeraddr(inp, nam)
D 65
	register struct inpcb *inp;
E 65
I 65
	struct inpcb *inp;
E 65
	struct mbuf *nam;
{
D 66
	register struct sockaddr_in *sin = mtod(nam, struct sockaddr_in *);
E 66
I 66
	register struct sockaddr_in *sin;
E 66
	
	nam->m_len = sizeof (*sin);
	sin = mtod(nam, struct sockaddr_in *);
	bzero((caddr_t)sin, sizeof (*sin));
	sin->sin_family = AF_INET;
	sin->sin_port = inp->inp_fport;
	sin->sin_addr = inp->inp_faddr;
}

E 42
/*
D 47
 * Pass an error to all internet connections
 * associated with address sin.  Call the
 * protocol specific routine to clean up the
 * mess afterwards.
E 47
I 47
 * Pass some notification to all connections of a protocol
D 53
 * associated with address dst.  Call the
 * protocol specific routine to handle each connection.
E 53
I 53
 * associated with address dst.  Call the protocol specific
 * routine (if any) to handle each connection.
E 53
E 47
 */
D 47
in_pcbnotify(head, dst, errno, abort)
E 47
I 47
in_pcbnotify(head, dst, errno, notify)
E 47
	struct inpcb *head;
	register struct in_addr *dst;
D 47
	int errno, (*abort)();
E 47
I 47
	int errno, (*notify)();
E 47
{
	register struct inpcb *inp, *oinp;
	int s = splimp();

D 28
COUNT(INP_PCBNOTIFY);
E 28
	for (inp = head->inp_next; inp != head;) {
D 53
		if (inp->inp_faddr.s_addr != dst->s_addr) {
	next:
E 53
I 53
		if (inp->inp_faddr.s_addr != dst->s_addr ||
		    inp->inp_socket == 0) {
E 53
			inp = inp->inp_next;
			continue;
		}
D 53
		if (inp->inp_socket == 0)
			goto next;
E 53
D 47
		inp->inp_socket->so_error = errno;
E 47
I 47
		if (errno) 
			inp->inp_socket->so_error = errno;
E 47
		oinp = inp;
		inp = inp->inp_next;
D 47
		(*abort)(oinp);
E 47
I 47
D 53
		(*notify)(oinp);
E 53
I 53
		if (notify)
			(*notify)(oinp);
E 53
E 47
	}
	splx(s);
I 47
}

/*
I 54
 * Check for alternatives when higher level complains
 * about service problems.  For now, invalidate cached
 * routing information.  If the route was created dynamically
 * (by a redirect), time to try a default gateway again.
 */
in_losing(inp)
	struct inpcb *inp;
{
	register struct rtentry *rt;

	if ((rt = inp->inp_route.ro_rt)) {
		if (rt->rt_flags & RTF_DYNAMIC)
D 58
			rtrequest(SIOCDELRT, rt);
E 58
I 58
D 59
			(void) rtrequest(SIOCDELRT, rt);
E 59
I 59
			(void) rtrequest((int)SIOCDELRT, rt);
E 59
E 58
		rtfree(rt);
		inp->inp_route.ro_rt = 0;
		/*
		 * A new route can be allocated
		 * the next time output is attempted.
		 */
	}
}

/*
E 54
 * After a routing change, flush old routing
 * and allocate a (hopefully) better one.
 */
in_rtchange(inp)
D 54
	struct inpcb *inp;
E 54
I 54
	register struct inpcb *inp;
E 54
{
	if (inp->inp_route.ro_rt) {
		rtfree(inp->inp_route.ro_rt);
		inp->inp_route.ro_rt = 0;
		/*
		 * A new route can be allocated the next time
		 * output is attempted.
		 */
	}
D 53
	/* SHOULD NOTIFY HIGHER-LEVEL PROTOCOLS */
E 53
E 47
E 26
E 25
E 2
}

I 11
D 31
/*
D 19
 * Look for a control block to accept a segment.
E 19
I 19
D 21
 * Look for a control block to accept a segment, or to make
 * sure 
E 19
 * First choice is an exact address match.
D 17
 * Second choice is a match of local address, with
 * unspecified foreign address.
E 17
I 17
 * Second choice is a match with either the foreign or the local
 * address specified.
 *
E 21
 * SHOULD ALLOW MATCH ON MULTI-HOMING ONLY
E 17
 */
E 31
E 11
D 2
in_plookup(head, fhost, fport, lhost, lport)
E 2
I 2
struct inpcb *
D 4
in_pcblookup(head, fhost, fport, lhost, lport)
E 4
I 4
D 17
in_pcblookup(head, faddr, fport, laddr, lport)
E 17
I 17
D 18
in_pcblookup(head, faddr, fport, laddr, lport, enter)
E 18
I 18
in_pcblookup(head, faddr, fport, laddr, lport, flags)
E 18
E 17
E 4
E 2
	struct inpcb *head;
D 3
	struct ip_addr *fhost, *lhost;
E 3
I 3
D 4
	struct in_addr *fhost, *lhost;
E 4
I 4
	struct in_addr faddr, laddr;
E 4
E 3
	u_short fport, lport;
I 17
D 18
	int enter;
E 18
I 18
	int flags;
E 18
E 17
{
D 17
	register struct inpcb *inp;
I 11
	struct inpcb *match = 0;
E 17
I 17
	register struct inpcb *inp, *match = 0;
	int matchwild = 3, wildcard;
E 17
E 11

D 2
	for (inp = head->inp_next; inp != head; inp = inp->inp_next) {
		if (inp->inp_fhost->s_addr == fhost->s_addr &&
E 2
I 2
D 11
	for (inp = head->inp_next; inp != head; inp = inp->inp_next)
E 11
I 11
	for (inp = head->inp_next; inp != head; inp = inp->inp_next) {
D 17
		if (inp->inp_laddr.s_addr != laddr.s_addr ||
		    inp->inp_lport != lport)
E 17
I 17
		if (inp->inp_lport != lport)
E 17
			continue;
D 17
		if (inp->inp_faddr.s_addr == 0) {
			match = inp;
E 17
I 17
		wildcard = 0;
D 38
		if (inp->inp_laddr.s_addr != 0) {
D 19
			if (inp->inp_laddr.s_addr != laddr.s_addr)
E 19
I 19
			if (laddr.s_addr == 0)
E 38
I 38
		if (inp->inp_laddr.s_addr != INADDR_ANY) {
			if (laddr.s_addr == INADDR_ANY)
E 38
				wildcard++;
			else if (inp->inp_laddr.s_addr != laddr.s_addr)
E 19
				continue;
		} else {
D 38
			if (laddr.s_addr != 0)
E 38
I 38
			if (laddr.s_addr != INADDR_ANY)
E 38
				wildcard++;
		}
D 38
		if (inp->inp_faddr.s_addr != 0) {
D 18
			if (inp->inp_faddr.s_addr != faddr.s_addr)
E 18
I 18
D 19
			if (inp->inp_faddr.s_addr != faddr.s_addr ||
E 19
I 19
			if (faddr.s_addr == 0)
E 38
I 38
		if (inp->inp_faddr.s_addr != INADDR_ANY) {
			if (faddr.s_addr == INADDR_ANY)
E 38
				wildcard++;
			else if (inp->inp_faddr.s_addr != faddr.s_addr ||
E 19
			    inp->inp_fport != fport)
E 18
				continue;
		} else {
D 38
			if (faddr.s_addr != 0)
E 38
I 38
			if (faddr.s_addr != INADDR_ANY)
E 38
				wildcard++;
		}
D 18
		if (enter == 0 && wildcard)
E 18
I 18
		if (wildcard && (flags & INPLOOKUP_WILDCARD) == 0)
E 18
E 17
			continue;
I 17
		if (wildcard < matchwild) {
			match = inp;
			matchwild = wildcard;
			if (matchwild == 0)
				break;
E 17
		}
E 11
D 4
		if (inp->inp_fhost->h_addr.s_addr == fhost->s_addr &&
E 4
I 4
D 17
		if (inp->inp_faddr.s_addr == faddr.s_addr &&
E 4
E 2
D 11
		    inp->inp_fport == fport &&
D 2
		    inp->inp_lhost->s_addr == lhost->s_addr &&
E 2
I 2
D 4
		    inp->inp_lhost->h_addr.s_addr == lhost->s_addr &&
E 4
I 4
		    inp->inp_laddr.s_addr == laddr.s_addr &&
E 4
E 2
		    inp->inp_lport == lport)
E 11
I 11
		    inp->inp_fport == fport)
E 11
			return (inp);
E 17
I 17
D 18
	}
	if (match && enter) {
		match->inp_laddr = laddr;
		in_setsockaddr(match);
E 18
E 17
D 2
	for (inp = head->inp_next; inp != head; inp = inp->inp_next) {
		if ((inp->inp_fhost->s_addr == fhost->s_addr ||
E 2
I 2
D 11
	for (inp = head->inp_next; inp != head; inp = inp->inp_next)
D 4
		if ((inp->inp_fhost->h_addr.s_addr == fhost->s_addr ||
E 2
		     inp->inp_fhost == 0) &&
E 4
I 4
		if ((inp->inp_faddr.s_addr == faddr.s_addr ||
		     inp->inp_faddr.s_addr == 0) &&
E 4
		    (inp->inp_fport == fport || inp->inp_fport == 0) &&
D 2
		     inp->inp_lhost->s_addr == lhost->s_addr &&
E 2
I 2
D 4
		     inp->inp_lhost->h_addr.s_addr == lhost->s_addr &&
E 4
I 4
		     inp->inp_laddr.s_addr == laddr.s_addr &&
E 4
E 2
		    (inp->inp_lport == lport || inp->inp_lport == 0))
			return (inp);
	return (0);
E 11
I 11
	}
	return (match);
E 11
D 4
}

D 2
in_pcbgenport(head, ent)
	struct inpcb *head, *ent;
E 2
I 2
in_pcbgenport(head)
	struct inpcb *head;
E 2
{
	register struct inpcb *inp;

again:
D 2
	if (head->lport++ < 1024)
		head->lport = 1024;
E 2
I 2
	if (head->inp_lport++ < 1024)
		head->inp_lport = 1024;
E 2
	for (inp = head->inp_next; inp != head; inp = inp->inp_next)
D 2
		if (inp->inp_lport == head->lport)
E 2
I 2
		if (inp->inp_lport == head->inp_lport)
E 2
			goto again;
D 2
	return (head->lport);
E 2
I 2
	return (head->inp_lport);
E 4
E 2
}
E 1
