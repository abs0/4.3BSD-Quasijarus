h57232
s 00010/00005/00482
d D 7.13 88/06/29 17:07:02 bostic 80 79
c install approved copyright notice
e
s 00002/00002/00485
d D 7.12 88/06/27 17:27:12 karels 79 78
c free those mbufs (need to iterate over chain)
e
s 00001/00001/00486
d D 7.11 88/05/26 09:38:22 karels 78 77
c lint
e
s 00002/00002/00485
d D 7.10 88/04/07 17:23:07 karels 77 76
c oops (worked on tahoe!)
e
s 00046/00028/00441
d D 7.9 88/03/15 21:12:35 karels 76 75
c don't copy first packet when fragmenting; use registers better
e
s 00033/00030/00436
d D 7.8 88/02/26 08:40:08 karels 75 74
c first fix for fragmentation of packets with options
e
s 00008/00002/00458
d D 7.7 87/12/07 17:45:49 bostic 74 73
c use Berkeley specific header
e
s 00001/00001/00459
d D 7.6 87/06/20 12:32:19 mckusick 73 72
c check for null mbuf ptr before freeing (4.3BSD/sys/{130,131,133})
e
s 00004/00001/00456
d D 7.5 87/05/24 22:20:55 karels 72 71
c use host unreachables within network (may be subnet unreach.)
e
s 00003/00002/00454
d D 7.4 87/05/07 14:44:59 karels 71 70
c correct comment
e
s 00001/00001/00455
d D 7.3 87/04/02 16:32:09 karels 70 69
c why check host flag for dest?
e
s 00001/00001/00455
d D 7.2 86/10/28 22:53:32 karels 69 68
c byte order changes for tahoe
e
s 00001/00001/00455
d D 7.1 86/06/05 00:28:23 mckusick 68 67
c 4.3BSD release version
e
s 00001/00001/00455
d D 6.16 86/05/11 16:10:11 karels 67 66
c typo
e
s 00001/00001/00455
d D 6.15 86/05/06 16:22:56 karels 66 65
c fix offset calculation when fragmenting fragmented packets
c (from borman)
e
s 00004/00001/00452
d D 6.14 86/04/19 23:08:11 karels 65 64
c with ROUTETOIF, check for pt-pt links first
e
s 00013/00011/00440
d D 6.13 86/02/23 23:24:34 karels 64 63
c lint
e
s 00010/00011/00441
d D 6.12 86/02/12 17:48:27 karels 63 62
c using sockaddr in route for dst; watch out for old route
c if only routing to interface
e
s 00031/00027/00421
d D 6.11 86/02/03 20:10:09 karels 62 61
c consolidate route caching, manipulation in IP
e
s 00011/00012/00437
d D 6.10 86/02/02 20:12:35 karels 61 60
c modify ip_pcbopts to make usable from raw ip
e
s 00211/00005/00238
d D 6.9 85/09/16 23:11:54 karels 60 59
c add code to insert IP options in outgoing packets,
c allow user-settable IP options
e
s 00022/00001/00221
d D 6.8 85/06/24 15:48:56 karels 59 58
c copyright; leave hack for patching address until tested otherwise
e
s 00008/00018/00214
d D 6.7 85/03/18 15:43:58 karels 58 57
c move net addresses from interface to protocol layer;
c move ip_id swapping to ip_forward; zap freed route so rtalloc doesn't
c hand it back again
e
s 00009/00009/00223
d D 6.6 84/08/29 15:36:41 bloom 57 56
c Include file changes.  No more ../h
e
s 00008/00008/00224
d D 6.5 84/06/22 22:25:40 sam 56 55
c slight cleanup -- this is inet, so use sockaddr_in's
e
s 00006/00003/00226
d D 6.4 84/05/25 14:26:28 karels 55 54
c propagate IP_MF when fragmenting forwarded packets; paren error in checking
c route
e
s 00006/00000/00223
d D 6.3 83/12/15 15:18:33 karels 54 53
c abandon old route if marked ~RTF_UP, reallocate.
e
s 00001/00001/00222
d D 6.2 83/10/22 14:48:57 sam 53 52
c wasn't handling routes to host properly (from bill croft)
e
s 00000/00000/00223
d D 6.1 83/07/29 07:11:51 sam 52 51
c 4.2 distribution
e
s 00001/00003/00222
d D 1.49 83/05/27 13:45:21 sam 51 50
c lint found this one...
e
s 00003/00001/00222
d D 1.48 83/05/15 17:20:28 sam 50 49
c one more time, this time mtpr.h is vax specific
e
s 00020/00019/00203
d D 1.47 83/05/12 15:03:59 sam 49 48
c fix ip packet forwarding to not stomp on headers when fragmented;
e
s 00007/00004/00215
d D 1.46 83/02/10 22:11:34 sam 48 47
c remove /usr/include dependencies
e
s 00005/00007/00214
d D 1.45 83/01/17 20:21:00 sam 47 46
c do broadcast mapping in drivers; sanity check against bind botch
e
s 00001/00001/00220
d D 1.44 83/01/08 16:24:35 sam 46 45
c casting problem
e
s 00017/00006/00204
d D 1.43 83/01/04 23:36:09 sam 45 43
c clean up some stuff; map Internet broadcast address to 
c hardware broadcast address and don't allow fragmentation on broadcasts
e
s 00017/00006/00204
d R 1.43 83/01/04 23:19:51 sam 44 43
c clean up some stuff; map broadcast addresses to interface values
c and don't allow broadcast packets to be fragmented
e
s 00001/00001/00209
d D 1.42 82/12/30 12:33:13 sam 43 42
c missing parameter
e
s 00000/00006/00210
d D 1.41 82/10/30 13:03:29 root 42 41
c get rid of conditional htons/ntohs etc
e
s 00000/00000/00216
d D 1.40 82/10/20 01:22:55 root 41 40
c lint
e
s 00001/00001/00215
d D 1.39 82/10/17 22:47:39 root 40 39
c lint
e
s 00003/00003/00213
d D 1.38 82/10/17 14:55:32 root 39 38
c fix lint
e
s 00001/00001/00215
d D 1.37 82/10/13 22:44:05 root 38 37
c move mtpr.h to vax directory
e
s 00004/00004/00212
d D 1.36 82/10/09 05:46:15 wnj 37 36
c localize header files
e
s 00000/00002/00216
d D 1.35 82/06/20 00:54:35 sam 36 35
c purge COUNT stuff now that we can use gprof
e
s 00001/00001/00217
d D 1.34 82/06/13 23:01:52 sam 35 34
c add class a/b/c net #'s and purge logical host kludge code
e
s 00045/00020/00173
d D 1.33 82/06/12 23:19:33 wnj 34 33
c now the routing code might wokr
e
s 00025/00013/00168
d D 1.32 82/04/10 18:26:42 sam 33 32
c invert output path to pass back error indications
e
s 00005/00004/00176
d D 1.31 82/03/31 20:36:50 sam 32 31
c routing tried and working, add logical host stuff
e
s 00006/00002/00174
d D 1.30 82/03/30 19:57:29 sam 31 30
c routing code now operational
e
s 00009/00028/00167
d D 1.29 82/03/30 11:32:45 sam 30 29
c with routing, but not forwarding
e
s 00015/00009/00180
d D 1.28 82/03/29 11:32:44 sam 29 28
c first cut (incomplete) at routing
e
s 00043/00010/00146
d D 1.27 82/03/28 14:23:00 sam 28 27
c convert interfaces to sockaddr's and add hooks for routing
e
s 00005/00001/00151
d D 1.26 82/03/15 04:44:20 wnj 27 26
c interfac queueing, restrictions on packets, tcp keep alives done 
c properly, bug fix to raw
e
s 00006/00006/00146
d D 1.25 82/02/18 11:59:30 root 26 25
c fixes to fragmentation code (feldman)
e
s 00008/00003/00144
d D 1.24 82/02/12 15:16:48 wnj 25 24
c getting reassembly to work
e
s 00001/00001/00146
d D 1.23 82/01/19 07:29:56 root 24 23
c m_get(0) -> m_get(M_DONTWAIT)
e
s 00001/00001/00146
d D 1.22 81/12/11 22:15:09 root 23 22
c lint
e
s 00005/00001/00142
d D 1.21 81/12/09 20:44:30 wnj 22 21
c bug fixes for hlen
e
s 00033/00058/00110
d D 1.20 81/11/26 11:56:47 wnj 21 20
c before carry to ARPAVAX
e
s 00001/00000/00167
d D 1.19 81/11/24 07:53:44 wnj 20 19
c minor fixups pre tcp<->spec coordination
e
s 00000/00001/00167
d D 1.18 81/11/23 00:06:27 wnj 19 18
c caller now sets ip_ttl (&& ip_len!)
e
s 00001/00000/00167
d D 1.17 81/11/21 15:20:57 wnj 18 17
c define IMPLOOP
e
s 00001/00001/00166
d D 1.16 81/11/20 14:41:51 wnj 17 16
c more lint
e
s 00009/00005/00158
d D 1.15 81/11/20 00:46:56 wnj 16 15
c linted
e
s 00099/00065/00064
d D 1.14 81/11/18 15:37:30 wnj 15 14
c more cleanup
e
s 00015/00013/00114
d D 1.13 81/11/16 14:17:07 wnj 14 13
c more lint
e
s 00002/00001/00125
d D 1.12 81/11/15 12:59:50 wnj 13 12
c listing
e
s 00007/00007/00119
d D 1.11 81/11/08 16:24:52 wnj 12 11
c first listing
e
s 00002/00000/00124
d D 1.10 81/11/02 19:48:15 wnj 11 10
c setsoftnet() in IMPLOOP so it will work
e
s 00001/00001/00123
d D 1.9 81/11/01 22:32:08 wnj 10 9
c minor fixups
e
s 00015/00015/00109
d D 1.8 81/10/31 14:33:19 wnj 9 8
c checksum macro for ip output
e
s 00001/00001/00123
d D 1.7 81/10/31 12:01:28 wnj 8 7
c faster imp code...
e
s 00046/00129/00078
d D 1.6 81/10/30 19:27:11 wnj 7 6
c name changes pre rearrange
e
s 00018/00015/00189
d D 1.5 81/10/29 20:26:54 wnj 6 4
c cleanup of header files
e
s 00075/00134/00070
d R 1.5 81/10/26 02:09:37 wnj 5 4
c first compile of major cleanup
e
s 00002/00002/00202
d D 1.4 81/10/23 11:43:56 wnj 4 3
c working with snd_copy incr ref cnt
e
s 00003/00000/00201
d D 1.3 81/10/21 19:06:40 wnj 3 2
c cleanup the headers
e
s 00049/00048/00152
d D 1.2 81/10/18 15:52:37 wnj 2 1
c cleanup imp_snd, arpa_ether, more robuts memall, remove netprepr
e
s 00200/00000/00000
d D 1.1 81/10/14 09:56:57 wnj 1 0
c date and time created 81/10/14 09:56:57 by wnj
e
u
U
t
T
I 18
D 21
#define IMPLOOP
E 21
E 18
I 1
D 15
/* %M% %I% %E% */
E 15
I 15
D 59
/*	%M%	%I%	%E%	*/
E 59
I 59
/*
D 68
 * Copyright (c) 1982 Regents of the University of California.
E 68
I 68
D 79
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 79
I 79
 * Copyright (c) 1982, 1986, 1988 Regents of the University of California.
E 79
E 68
D 74
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 74
I 74
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 80
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 80
I 80
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
E 80
E 74
 *
 *	%W% (Berkeley) %G%
 */
E 59
E 15
I 3

E 3
D 57
#include "../h/param.h"
D 6
#include "../bbnnet/net.h"
I 3
#include "../bbnnet/mbuf.h"
#include "../bbnnet/host.h"
E 3
#include "../bbnnet/tcp.h"
#include "../bbnnet/ip.h"
#include "../bbnnet/imp.h"
#include "../bbnnet/ucb.h"
E 6
I 6
#include "../h/mbuf.h"
I 11
D 38
#include "../h/mtpr.h"
E 38
I 38
D 48
#include "../vax/mtpr.h"
E 48
I 48
#include "../h/errno.h"
E 48
E 38
E 11
#include "../h/socket.h"
I 9
D 10
#include "../inet/cksum.h"
E 10
I 10
D 12
#include "../inet/inet_cksum.h"
E 10
E 9
#include "../inet/inet.h"
#include "../inet/inet_systm.h"
#include "../inet/imp.h"
#include "../inet/inet_host.h"
#include "../inet/ip.h"
#include "../inet/tcp.h"
E 12
I 12
D 15
#include "../net/inet_cksum.h"
E 15
I 15
#include "../h/socketvar.h"
E 57
I 57
#include "param.h"
#include "mbuf.h"
#include "errno.h"
I 60
#include "protosw.h"
E 60
#include "socket.h"
#include "socketvar.h"
E 57
I 48

#include "../net/if.h"
#include "../net/route.h"

E 48
E 15
D 21
#include "../net/inet.h"
#include "../net/inet_systm.h"
#include "../net/imp.h"
E 21
I 21
D 37
#include "../net/in.h"
#include "../net/in_systm.h"
E 37
I 37
D 57
#include "../netinet/in.h"
#include "../netinet/in_systm.h"
E 37
D 48
#include "../net/if.h"
E 48
E 21
D 16
#include "../net/inet_host.h"
E 16
D 37
#include "../net/ip.h"
D 13
#include "../net/tcp.h"
E 13
I 13
#include "../net/ip_var.h"
E 37
I 37
#include "../netinet/ip.h"
#include "../netinet/ip_var.h"
E 57
I 57
#include "in.h"
I 60
#include "in_pcb.h"
E 60
#include "in_systm.h"
I 58
#include "in_var.h"
E 58
#include "ip.h"
#include "ip_var.h"
E 57
E 37
I 28
D 48
#include "../net/route.h"
I 33
#include <errno.h>
E 48
I 48

D 50
#include "../machine/mtpr.h"
E 50
I 50
#ifdef vax
D 69
#include "../vax/mtpr.h"
E 69
I 69
#include "../machine/mtpr.h"
E 69
#endif
E 50
E 48
E 33
E 28
E 13
E 12
E 6

I 60
struct mbuf *ip_insertoptions();

/*
 * IP output.  The packet in mbuf chain m contains a skeletal IP
D 71
 * header (as ipovly).  The mbuf chain containing the packet will
 * be freed.  The mbuf opt, if present, will not be freed.
E 71
I 71
 * header (with len, off, ttl, proto, tos, src, dst).
 * The mbuf chain containing the packet will be freed.
 * The mbuf opt, if present, will not be freed.
E 71
 */
E 60
I 34
D 51
int	ipnorouteprint = 0;

E 51
E 34
D 2
/*****************************************************************************
*                                                                            *
*         internet level output:  called from higher level protocol          *
*         or "raw internet driver."  passed a pointer to an mbuf             *
*         chain containing the message to be sent, a partially filled        *
*         in ip leader, and room for an 1822 leader and 2 pointers.          *
*         this routine does fragmentation and mapping of ip parameters       *
*         to 1822 ones.                                                      *
*                                                                            *
*****************************************************************************/

E 2
D 15
ip_output(mp)
D 2
struct mbuf *mp;
E 2
I 2
	struct mbuf *mp;
E 15
I 15
D 21
ip_output(m)
E 21
I 21
D 27
ip_output(m, opt)
E 27
I 27
D 28
ip_output(m, opt, allowbroadcast)
E 28
I 28
D 49
ip_output(m, opt, ro, allowbroadcast)
E 49
I 49
D 75
ip_output(m, opt, ro, flags)
E 49
E 28
E 27
E 21
	struct mbuf *m;
E 75
I 75
ip_output(m0, opt, ro, flags)
	struct mbuf *m0;
E 75
I 21
	struct mbuf *opt;
I 28
	struct route *ro;
E 28
I 27
D 49
	int allowbroadcast;
E 49
I 49
	int flags;
E 49
E 27
E 21
E 15
E 2
{
D 15
	register i, rnd;
	register struct mbuf *m, *n;
	register struct ip *p;
	struct mbuf *mm;
	int hlen, adj, max, len, off;
E 15
I 15
D 60
	register struct ip *ip = mtod(m, struct ip *);
E 60
I 60
D 75
	register struct ip *ip;
E 75
I 75
	register struct ip *ip, *mhip;
E 75
E 60
I 21
	register struct ifnet *ifp;
E 21
D 22
	int len, hlen = ip->ip_hl << 2, off;
E 22
I 22
D 29
	int len, hlen = sizeof (struct ip), off;
E 29
I 29
D 30
	int len, hlen = sizeof (struct ip), off, direct;
E 29
I 28
	struct sockaddr_in tempaddr;	/* temp kludge */
E 30
I 30
D 33
	int len, hlen = sizeof (struct ip), off;
E 33
I 33
D 75
	int len, hlen = sizeof (struct ip), off, error = 0;
E 75
I 75
	register struct mbuf *m = m0;
	register int hlen = sizeof (struct ip);
	int len, off, error = 0;
E 75
E 33
E 30
	struct route iproute;
I 29
D 56
	struct sockaddr *dst;
E 56
I 56
	struct sockaddr_in *dst;
E 56
E 29
E 28
E 22
E 15

D 36
COUNT(IP_OUTPUT);
E 36
I 22
D 60
	if (opt)				/* XXX */
D 23
		m_free(opt);			/* XXX */
E 23
I 23
		(void) m_free(opt);		/* XXX */
E 60
I 60
D 75
	if (opt)
		m = ip_insertoptions(m, opt, &hlen);
E 75
I 75
	if (opt) {
		m = ip_insertoptions(m, opt, &len);
		hlen = len;
	}
E 75
	ip = mtod(m, struct ip *);
E 60
E 23
E 22
D 9
	p = (struct ip *)((int)mp + mp->m_off); /* -> ip header */
D 2
	hlen = sizeof(struct ip);               /* header length */
E 2
I 2
	hlen = sizeof (struct ip);               /* header length */
E 9
I 9
D 15
	p = mtod(mp, struct ip *);
	hlen = sizeof (struct ip);
E 9
E 2

E 15
D 2
	/* fill in unspecified fields and byte swap others */

	p->ip_v = IPVERSION;    
E 2
I 2
	/*
D 15
	 * Fill in and byte swap ip header.
E 15
I 15
	 * Fill in IP header.
E 15
	 */
D 15
	p->ip_v = IPVERSION;
E 2
	p->ip_hl = hlen >> 2;
D 6
	p->ip_off = 0 | (p->ip_off & ip_df);
E 6
I 6
	p->ip_off = 0 | (p->ip_off & IP_DF);
E 6
	p->ip_ttl = MAXTTL;
I 13
D 14
/*###35 [cc] ip_id undefined %%%*/
E 14
E 13
D 6
	p->ip_id = netcb.n_ip_cnt++;
E 6
I 6
	p->ip_id = ip_id++;
E 15
I 15
D 49
	ip->ip_v = IPVERSION;
E 49
D 55
	ip->ip_hl = hlen >> 2;
E 55
D 49
	ip->ip_off &= IP_DF;
D 19
	ip->ip_ttl = MAXTTL;
E 19
D 21
	ip->ip_id = ip_id++;
E 21
I 21
	ip->ip_id = htons(ip_id++);
E 49
I 49
	if ((flags & IP_FORWARDING) == 0) {
		ip->ip_v = IPVERSION;
		ip->ip_off &= IP_DF;
		ip->ip_id = htons(ip_id++);
D 55
	}
E 55
I 55
		ip->ip_hl = hlen >> 2;
D 58
	} else
		ip->ip_id = htons(ip->ip_id);
E 58
I 58
D 60
	}
E 60
I 60
	} else
		hlen = ip->ip_hl << 2;
E 60
E 58
E 55
E 49
E 21
E 15
E 6

I 28
D 30
#ifdef notdef
E 30
E 28
D 7
	if (p->ip_len > MTU) {          /* must fragment */
D 6
		if (p->ip_off & ip_df)
E 6
I 6
		if (p->ip_off & IP_DF)
E 6
D 2
			return(FALSE);
E 2
I 2
			return (0);
E 2
		max = MTU - hlen;       /* maximum data length in fragment */
		len = p->ip_len - hlen; /* data length */
		off = 0;                /* fragment offset */
		m = mp;

		while (len > 0) {

			/* correct the header */

			p->ip_off |= off >> 3;

			/* find the end of the fragment */

			i = -hlen;
			while (m != NULL) {
				i += m->m_len;
				if (i > max)
					break;
				n = m;
				m = m->m_next;
			}

			if (i < max || m == NULL) {     /* last fragment */
D 6
				p->ip_off = p->ip_off & ~ip_mf;
E 6
I 6
				p->ip_off = p->ip_off &~ IP_MF;
E 6
				p->ip_len = i + hlen;
E 7
I 7
D 14
	if (p->ip_len <= MTU)
		return (ip_send(p));
E 14
I 14
D 15
	if (p->ip_len <= MTU) {
		ip_send(p);
E 15
I 15
	/*
I 21
D 29
	 * Find interface for this packet.
E 29
I 29
D 34
	 * Find interface for this packet in the routing
	 * table.  Note each interface has placed itself
D 31
	 * in there at boot time, so call on route degenerates
	 * to if_ifonnetof(ip->ip_dst.s_net).
E 31
I 31
	 * in there at boot time, so calls to rtalloc
	 * degenerate to if_ifonnetof(ip->ip_dst.s_net).
E 34
I 34
	 * Route packet.
E 34
E 31
E 29
	 */
D 28
	ifp = if_ifonnetof(ip->ip_dst);
	if (ifp == 0) {
		ifp = if_gatewayfor(ip->ip_dst);
		if (ifp == 0)
			goto bad;
E 28
I 28
	if (ro == 0) {
		ro = &iproute;
		bzero((caddr_t)ro, sizeof (*ro));
E 28
	}
I 34
D 56
	dst = &ro->ro_dst;
E 56
I 56
	dst = (struct sockaddr_in *)&ro->ro_dst;
I 63
	/*
	 * If there is a cached route,
	 * check that it is to the same destination
	 * and is still up.  If not, free it and try again.
	 */
	if (ro->ro_rt && ((ro->ro_rt->rt_flags & RTF_UP) == 0 ||
	   dst->sin_addr.s_addr != ip->ip_dst.s_addr)) {
		RTFREE(ro->ro_rt);
		ro->ro_rt = (struct rtentry *)0;
	}
E 63
E 56
E 34
I 27
D 28
	if (!allowbroadcast && ifp->if_broadaddr.s_addr != 0 &&
	    ifp->if_broadaddr.s_addr == ip->ip_dst.s_addr)
E 28
I 28
	if (ro->ro_rt == 0) {
D 30
		ro->ro_dest.sin_addr = ip->ip_dst;
		ro->ro_dest.sin_family = AF_INET;
D 29
		route(ro);
E 29
I 29
		direct = allocroute(ro);
E 30
I 30
D 56
		ro->ro_dst.sa_family = AF_INET;
		((struct sockaddr_in *)&ro->ro_dst)->sin_addr = ip->ip_dst;
E 56
I 56
		dst->sin_family = AF_INET;
		dst->sin_addr = ip->ip_dst;
E 56
I 34
D 62
		/*
D 49
		 * If routing to interface only, short circuit routing lookup.
E 49
I 49
		 * If routing to interface only,
		 * short circuit routing lookup.
E 49
		 */
D 49
		if (ro == &routetoif) {
			/* check ifp is AF_INET??? */
E 49
I 49
		if (flags & IP_ROUTETOIF) {
E 49
D 35
			ifp = if_ifonnetof(ip->ip_dst.s_net);
E 35
I 35
D 40
			ifp = if_ifonnetof(IN_NETOF(ip->ip_dst));
E 40
I 40
D 58
			ifp = if_ifonnetof(in_netof(ip->ip_dst));
E 40
E 35
D 49
			if (ifp == 0)
				goto unreachable;
E 49
I 49
			if (ifp == 0) {
E 58
I 58
			struct in_ifaddr *ia;
			ia = in_iaonnetof(in_netof(ip->ip_dst));
			if (ia == 0) {
E 58
				error = ENETUNREACH;
				goto bad;
			}
I 58
			ifp = ia->ia_ifp;
E 58
E 49
			goto gotif;
E 62
I 62
	}
	/*
	 * If routing to interface only,
	 * short circuit routing lookup.
	 */
	if (flags & IP_ROUTETOIF) {
		struct in_ifaddr *ia;
D 65
		ia = in_iaonnetof(in_netof(ip->ip_dst));
E 65
I 65

D 67
		ia = (struct in_ifadddr *)ifa_ifwithdstaddr(dst);
E 67
I 67
D 78
		ia = (struct in_ifaddr *)ifa_ifwithdstaddr(dst);
E 78
I 78
		ia = (struct in_ifaddr *)ifa_ifwithdstaddr((struct sockaddr *)dst);
E 78
E 67
		if (ia == 0)
			ia = in_iaonnetof(in_netof(ip->ip_dst));
E 65
		if (ia == 0) {
			error = ENETUNREACH;
			goto bad;
E 62
		}
E 34
D 62
		rtalloc(ro);
I 54
D 55
	} else if (ro->ro_rt->rt_flags & RTF_UP == 0) {
E 55
I 55
	} else if ((ro->ro_rt->rt_flags & RTF_UP) == 0) {
E 62
I 62
		ifp = ia->ia_ifp;
	} else {
E 62
E 55
D 63
		/*
D 62
		 * The old route has gone away; try for a new one.
E 62
I 62
		 * If there is a cached route,
		 * check that it is to the same destination
		 * and is still up.  If not, free it and try again.
E 62
		 */
D 62
		rtfree(ro->ro_rt);
I 58
		ro->ro_rt = NULL;
E 58
		rtalloc(ro);
E 62
I 62
		if (ro->ro_rt && ((ro->ro_rt->rt_flags & RTF_UP) == 0 ||
		   dst->sin_addr.s_addr != ip->ip_dst.s_addr)) {
			RTFREE(ro->ro_rt);
			ro->ro_rt = (struct rtentry *)0;
			dst->sin_addr = ip->ip_dst;
		}
E 63
		if (ro->ro_rt == 0)
			rtalloc(ro);
		if (ro->ro_rt == 0 || (ifp = ro->ro_rt->rt_ifp) == 0) {
D 72
			error = ENETUNREACH;
E 72
I 72
			if (in_localaddr(ip->ip_dst))
				error = EHOSTUNREACH;
			else
				error = ENETUNREACH;
E 72
			goto bad;
		}
		ro->ro_rt->rt_use++;
D 70
		if (ro->ro_rt->rt_flags & (RTF_GATEWAY|RTF_HOST))
E 70
I 70
		if (ro->ro_rt->rt_flags & RTF_GATEWAY)
E 70
			dst = (struct sockaddr_in *)&ro->ro_rt->rt_gateway;
E 62
E 54
I 31
D 32
		if (ro != &iproute)
			ro->ro_rt->rt_refcnt++;
E 32
E 31
E 30
E 29
	}
D 30
	if (ro->ro_rt == 0 || (ifp = ro->ro_rt->rt_ifp) == 0)
E 30
I 30
D 34
	if (ro->ro_rt == 0 || (ifp = ro->ro_rt->rt_ifp) == 0) {
D 32
printf("no route to %x\n", ip->ip_dst.s_addr);
E 32
I 32
D 33
		printf("no route to %x (from %x, len %d)\n",
		    ip->ip_dst.s_addr, ip->ip_src.s_addr, ip->ip_len);
E 33
I 33
		extern int ipprintfs;
E 34
I 34
D 49
	if (ro->ro_rt == 0 || (ifp = ro->ro_rt->rt_ifp) == 0)
		goto unreachable;
E 49
I 49
D 62
	if (ro->ro_rt == 0 || (ifp = ro->ro_rt->rt_ifp) == 0) {
		error = ENETUNREACH;
		goto bad;
	}
E 49
	ro->ro_rt->rt_use++;
D 53
	if (ro->ro_rt->rt_flags & RTF_GATEWAY)
E 53
I 53
	if (ro->ro_rt->rt_flags & (RTF_GATEWAY|RTF_HOST))
E 53
D 56
		dst = &ro->ro_rt->rt_gateway;
E 56
I 56
		dst = (struct sockaddr_in *)&ro->ro_rt->rt_gateway;
E 56
gotif:
E 62
I 59
#ifndef notdef
	/*
	 * If source address not specified yet, use address
	 * of outgoing interface.
	 */
	if (ip->ip_src.s_addr == INADDR_ANY) {
		register struct in_ifaddr *ia;

		for (ia = in_ifaddr; ia; ia = ia->ia_next)
			if (ia->ia_ifp == ifp) {
				ip->ip_src = IA_SIN(ia)->sin_addr;
				break;
			}
	}
#endif
E 59
I 47
D 58
#ifndef notdef
E 58
E 47
	/*
D 58
	 * If source address not specified yet, use address
	 * of outgoing interface.
	 */
D 45
	if (ip->ip_src.s_addr == 0)
E 45
I 45
D 47
	if (ip->ip_src.s_addr == INADDR_ANY)
E 47
I 47
	if (in_lnaof(ip->ip_src) == INADDR_ANY)
E 47
E 45
		ip->ip_src.s_addr =
		    ((struct sockaddr_in *)&ifp->if_addr)->sin_addr.s_addr;
I 47
#endif
E 47
E 34

D 34
		if (ipprintfs)
			printf("no route to %x (from %x, len %d)\n",
			    ip->ip_dst.s_addr, ip->ip_src.s_addr, ip->ip_len);
		error = ENETUNREACH;
E 33
E 32
E 30
E 28
		goto bad;
I 29
D 30
	dst = direct ? (struct sockaddr *)&ro->ro_dest :
		&ro->ro_rt->rt_gateway;
E 29
I 28
#else
	/* interim kludge before routing fallout */
	ifp = if_ifonnetof(ip->ip_dst.s_net);
	if (ifp == 0)
		goto bad;
	tempaddr.sin_family = AF_INET;
	tempaddr.sin_addr = ip->ip_dst;
#endif
E 28
E 27

E 30
I 30
D 32
}
E 32
I 32
	}
E 32
D 33
	dst = ro->ro_rt->rt_flags&RTF_DIRECT ?
E 33
I 33
	dst = ro->ro_rt->rt_flags & RTF_DIRECT ?
E 33
	    (struct sockaddr *)&ro->ro_dst : &ro->ro_rt->rt_gateway;
I 32
	if (ro == &iproute)
		RTFREE(ro->ro_rt);
E 34
I 34
	/*
E 58
D 45
	 * Have interface for packet.  Allow
	 * broadcasts only by authorized users.
E 45
I 45
D 47
	 * Map broadcast address to hardware's broadcast
	 * address and verify user is allowed to send
E 47
I 47
	 * Look for broadcast address and
	 * and verify user is allowed to send
E 47
	 * such a packet.
E 45
	 */
E 34
E 32
E 30
I 28
D 45
	if (!allowbroadcast && (ifp->if_flags & IFF_BROADCAST)) {
E 45
I 45
D 51
	if (in_lnaof(dst) == INADDR_ANY) {
E 51
I 51
D 56
	if (in_lnaof(((struct sockaddr_in *)dst)->sin_addr) == INADDR_ANY) {
E 56
I 56
D 58
	if (in_lnaof(dst->sin_addr) == INADDR_ANY) {
E 58
I 58
	if (in_broadcast(dst->sin_addr)) {
E 58
E 56
E 51
E 45
D 47
		struct sockaddr_in *sin;

E 47
D 45
		sin = (struct sockaddr_in *)&ifp->if_broadaddr;
D 33
		if (sin->sin_addr.s_addr == ip->ip_dst.s_addr)
E 33
I 33
		if (sin->sin_addr.s_addr == ip->ip_dst.s_addr) {
E 45
I 45
		if ((ifp->if_flags & IFF_BROADCAST) == 0) {
			error = EADDRNOTAVAIL;
			goto bad;
		}
D 49
		if (!allowbroadcast) {
E 49
I 49
		if ((flags & IP_ALLOWBROADCAST) == 0) {
E 49
E 45
D 34
			error = EPERM;		/* ??? */
E 34
I 34
			error = EACCES;
E 34
E 33
			goto bad;
I 33
		}
I 45
		/* don't allow broadcast messages to be fragmented */
		if (ip->ip_len > ifp->if_mtu) {
			error = EMSGSIZE;
			goto bad;
		}
D 47
		sin = (struct sockaddr_in *)&ifp->if_broadaddr;
D 46
		dst.sin_addr = sin->sin_addr;
E 46
I 46
		((struct sockaddr_in *)dst)->sin_addr = sin->sin_addr;
E 47
E 46
E 45
E 33
	}

E 28
	/*
E 21
	 * If small enough for interface, can just send directly.
	 */
D 21
	if (ip->ip_len <= MTU) {
		ip_send(ip);
E 15
		return;
E 21
I 21
	if (ip->ip_len <= ifp->if_mtu) {
I 22
D 39
#if vax
E 39
I 39
D 42
#if vax || pdp11 || ns16032
E 42
E 39
E 22
		ip->ip_len = htons((u_short)ip->ip_len);
		ip->ip_off = htons((u_short)ip->ip_off);
I 22
D 42
#endif
E 42
E 22
		ip->ip_sum = 0;
		ip->ip_sum = in_cksum(m, hlen);
I 31
D 34
		ro->ro_rt->rt_use++;
E 31
D 28
		return ((*ifp->if_output)(ifp, m, PF_INET));
E 28
I 28
D 29
		return ((*ifp->if_output)(ifp, m,
E 29
D 30
#ifdef notdef
E 30
D 29
		  &ro->ro_rt->rt_dest));
E 29
I 29
		return ((*ifp->if_output)(ifp, m, dst));
E 34
I 34
D 56
		error = (*ifp->if_output)(ifp, m, dst);
E 56
I 56
		error = (*ifp->if_output)(ifp, m, (struct sockaddr *)dst);
E 56
		goto done;
E 34
E 29
D 30
#else
D 29
		  (struct sockaddr *)&tempaddr));
E 29
I 29
		return ((*ifp->if_output)(ifp, m,
			(struct sockaddr *)&tempaddr));
E 29
#endif
E 30
E 28
E 21
	}
E 14
D 15
	if (p->ip_off & IP_DF)
D 14
		return (0);
E 14
I 14
		return;
E 14
	max = MTU - hlen;
	len = p->ip_len - hlen;
	off = 0;
	m = mp;
	while (len > 0) {
		p->ip_off |= off >> 3;
		i = -hlen;
		while (m != NULL) {
			i += m->m_len;
			if (i > max)
E 7
				break;
D 7

			} else {                        /* more fragments */

				/* allocate header mbuf for next fragment */

				if ((mm = m_get(1)) == NULL)    /* no more bufs */
D 2
					return(FALSE);
E 2
I 2
					return(0);
E 2

D 6
				p->ip_off |= ip_mf;
E 6
I 6
				p->ip_off |= IP_MF;
E 6

				/* terminate fragment at 8 byte boundary (round down) */

				i -= m->m_len;
        			rnd = i & ~7;           /* fragment length */
				adj = i - rnd;          /* leftover in mbuf */
D 2
				p->ip_len = rnd + hlen; 
E 2
I 2
				p->ip_len = rnd + hlen;
E 2

D 2
				/* setup header for next fragment and 
E 2
I 2
				/* setup header for next fragment and
E 2
				   append remaining fragment data */

D 2
				n->m_next = NULL;                   
				mm->m_next = m;        
E 2
I 2
				n->m_next = NULL;
				mm->m_next = m;
E 2
				m = mm;
D 4
				m->m_off = MSIZE - hlen - adj;
E 4
I 4
				m->m_off = MMAXOFF - hlen - adj;
E 4
				m->m_len = hlen + adj;

				/* copy old header to new */

				bcopy(p, (caddr_t)((int)m + m->m_off), hlen);

				/* copy leftover data from previous frag */

				if (adj) {
					n->m_len -= adj;
					bcopy((caddr_t)((int)n + n->m_len + n->m_off),
					      (caddr_t)((int)m + m->m_off + hlen), adj);
				}
			}

			ip_send(p);             /* pass frag to local net level */

			p = (struct ip *)((int)m + m->m_off);   /* -> new hdr */
			len -= rnd;
			off += rnd;
E 7
I 7
			n = m;
			m = m->m_next;
E 15
I 15

	/*
	 * Too large for interface; fragment if possible.
	 * Must be able to put at least 8 bytes per fragment.
	 */
D 33
	if (ip->ip_off & IP_DF)
E 33
I 33
	if (ip->ip_off & IP_DF) {
		error = EMSGSIZE;
E 33
		goto bad;
I 33
	}
E 33
D 21
	len = (MTU-hlen) &~ 7;
E 21
I 21
	len = (ifp->if_mtu - hlen) &~ 7;
E 21
D 33
	if (len < 8)
E 33
I 33
	if (len < 8) {
		error = EMSGSIZE;
E 33
		goto bad;
I 33
	}
E 33

I 76
    {
	int mhlen, firstlen = len;
	struct mbuf **mnext = &m->m_act;

E 76
	/*
D 76
	 * Discard IP header from logical mbuf for m_copy's sake.
	 * Loop through length of segment, make a copy of each
	 * part and output.
E 76
I 76
	 * Loop through length of segment after first fragment,
	 * make new header and copy data of each part and link onto chain.
E 76
	 */
D 75
	m->m_len -= sizeof (struct ip);
	m->m_off += sizeof (struct ip);
D 26
	for (off = 0; off < ip->ip_len; off += len) {
E 26
I 26
	for (off = 0; off < ip->ip_len-hlen; off += len) {
E 26
D 24
		struct mbuf *mh = m_get(0);
E 24
I 24
D 43
		struct mbuf *mh = m_get(M_DONTWAIT);
E 43
I 43
		struct mbuf *mh = m_get(M_DONTWAIT, MT_HEADER);
E 43
E 24
		struct ip *mhip;
E 75
I 75
D 76
	m->m_len -= hlen;
	m->m_off += hlen;
E 76
	m0 = m;
D 76
	for (off = 0; off < ip->ip_len - hlen; off += len) {
		int mhlen;
E 75

E 76
I 76
	mhlen = sizeof (struct ip);
	for (off = hlen + len; off < ip->ip_len; off += len) {
E 76
D 33
		if (mh == 0)
E 33
I 33
D 75
		if (mh == 0) {
E 75
I 75
		MGET(m, M_DONTWAIT, MT_HEADER);
		if (m == 0) {
E 75
			error = ENOBUFS;
E 33
D 79
			goto bad;
E 79
I 79
			goto sendorfree;
E 79
I 33
		}
E 33
D 75
		mh->m_off = MMAXOFF - hlen;
		mhip = mtod(mh, struct ip *);
E 75
I 75
		m->m_off = MMAXOFF - hlen;
		mhip = mtod(m, struct ip *);
E 75
		*mhip = *ip;
D 16
		if (ip->ip_hl > sizeof (struct ip) >> 2) {
E 16
I 16
		if (hlen > sizeof (struct ip)) {
E 16
D 75
			int olen = ip_optcopy(ip, mhip, off);
			mh->m_len = sizeof (struct ip) + olen;
E 75
I 75
D 76
			mhlen = ip_optcopy(ip, mhip, off) + sizeof (struct ip);
E 76
I 76
			mhlen = ip_optcopy(ip, mhip) + sizeof (struct ip);
E 76
			mhip->ip_hl = mhlen >> 2;
E 75
D 76
		} else
D 75
			mh->m_len = sizeof (struct ip);
E 75
I 75
			mhlen = sizeof (struct ip);
E 76
I 76
		}
E 76
		m->m_len = mhlen;
E 75
D 25
		mhip->ip_off = off;
E 25
I 25
D 66
		mhip->ip_off = off >> 3;
E 66
I 66
D 76
		mhip->ip_off = (off >> 3) + (ip->ip_off & ~IP_MF);
E 76
I 76
		mhip->ip_off = ((off - hlen) >> 3) + (ip->ip_off & ~IP_MF);
E 76
E 66
I 55
		if (ip->ip_off & IP_MF)
			mhip->ip_off |= IP_MF;
E 55
E 25
D 26
		if (off + len >= ip->ip_len)
D 25
			mhip->ip_len = ip->ip_len - off;
E 25
I 25
			len = mhip->ip_len = ip->ip_len - off;
E 26
I 26
D 75
		if (off + len >= ip->ip_len-hlen)
			len = mhip->ip_len = ip->ip_len - hlen - off;
E 26
E 25
		else {
			mhip->ip_len = len;
E 75
I 75
D 76
		if (off + len >= ip->ip_len - hlen)
			len = ip->ip_len - hlen - off;
E 76
I 76
		if (off + len >= ip->ip_len)
			len = ip->ip_len - off;
E 76
		else
E 75
			mhip->ip_off |= IP_MF;
E 15
E 7
D 75
		}
I 20
D 21
		mhip->ip_len += sizeof (struct ip);
E 21
I 21
D 25
		mhip->ip_len = htons((u_short)(mhip->ip_len + sizeof (struct ip)));
E 25
I 25
		mhip->ip_len += sizeof (struct ip);
D 39
#if vax
E 39
I 39
D 42
#if vax || pdp11 || ns16032
E 42
E 39
		mhip->ip_len = htons((u_short)mhip->ip_len);
D 42
#endif
E 42
E 25
E 21
E 20
I 7
D 15
		if (i < max || m == NULL) {
			p->ip_off = p->ip_off &~ IP_MF;
			p->ip_len = i + hlen;
D 14
			return (ip_send(p));
E 14
I 14
			ip_send(p);
			return;
E 15
I 15
		mh->m_next = m_copy(m, off, len);
		if (mh->m_next == 0) {
D 17
			m_free(mh);
E 17
I 17
			(void) m_free(mh);
E 75
I 75
		mhip->ip_len = htons((u_short)(len + mhlen));
		m->m_next = m_copy(m0, off, len);
		if (m->m_next == 0) {
D 76
			(void) m_free(m);
E 76
E 75
I 33
			error = ENOBUFS;	/* ??? */
E 33
E 17
D 76
			goto bad;
E 76
I 76
			goto sendorfree;
E 76
E 15
E 14
		}
I 25
D 39
#if vax
E 39
I 39
D 42
#if vax || pdp11 || ns16032
E 42
E 39
E 25
D 15
		if ((mm = m_get(1)) == NULL)    /* no more bufs */
D 14
			return(0);
E 14
I 14
			return;
E 14
		p->ip_off |= IP_MF;
		i -= m->m_len;
		rnd = i & ~7;
		adj = i - rnd;
		p->ip_len = rnd + hlen;
		n->m_next = NULL;
		mm->m_next = m;
		m = mm;
		m->m_off = MMAXOFF - hlen - adj;
		m->m_len = hlen + adj;
D 14
		bcopy(p, (caddr_t)((int)m + m->m_off), hlen);
E 14
I 14
		bcopy((caddr_t)p, mtod(m, caddr_t), (unsigned)hlen);
E 14
		if (adj) {
			n->m_len -= adj;
D 14
			bcopy((caddr_t)((int)n + n->m_len + n->m_off),
			      (caddr_t)((int)m + m->m_off + hlen), adj);
E 14
I 14
			bcopy(mtod(n, caddr_t) + n->m_len,
			    mtod(m, caddr_t) + hlen, (unsigned) adj);
E 15
I 15
D 16
		ip_send(mh);
E 16
I 16
D 21
		ip_send(mhip);
E 21
I 21
D 26
		ip->ip_off = htons((u_short)ip->ip_off);
E 26
I 26
		mhip->ip_off = htons((u_short)mhip->ip_off);
E 26
I 25
D 42
#endif
E 42
E 25
D 26
		ip->ip_sum = 0;
		ip->ip_sum = in_cksum(m, hlen);
E 26
I 26
		mhip->ip_sum = 0;
D 75
		mhip->ip_sum = in_cksum(mh, hlen);
I 31
D 34
		ro->ro_rt->rt_use++;
E 34
E 31
E 26
D 28
		if ((*ifp->if_output)(ifp, mh, PF_INET) == 0)
E 28
I 28
D 29
		if ((*ifp->if_output)(ifp, mh,
E 29
D 30
#ifdef notdef
E 30
D 29
		  &ro->ro_rt->rt_dest) == 0)
E 29
I 29
D 33
		if ((*ifp->if_output)(ifp, mh, dst) == 0)
E 29
D 30
#else
D 29
		  (struct sockaddr *)&tempaddr) == 0)
E 29
I 29
		if ((*ifp->if_output)(ifp, mh, 
		    (struct sockaddr *)&tempaddr) == 0)
E 29
#endif
E 30
E 28
			goto bad;
E 33
I 33
D 56
		if (error = (*ifp->if_output)(ifp, mh, dst))
E 56
I 56
		if (error = (*ifp->if_output)(ifp, mh, (struct sockaddr *)dst))
E 75
I 75
		mhip->ip_sum = in_cksum(m, mhlen);
D 76
		if (error = (*ifp->if_output)(ifp, m, (struct sockaddr *)dst))
E 75
E 56
			break;
E 76
I 76
		*mnext = m;
		mnext = &m->m_act;
E 76
E 33
E 21
E 16
	}
I 34
D 58
	m_freem(m);
	goto done;

E 58
D 49
unreachable:
	if (ipnorouteprint)
		printf("no route to %x (from %x, len %d)\n",
		    ip->ip_dst.s_addr, ip->ip_src.s_addr, ip->ip_len);
	error = ENETUNREACH;
E 49
E 34
I 21
D 33
	m_freem(m);
	return (1);
E 33
E 21
D 76
bad:
D 75
	m_freem(m);
E 75
I 75
	m_freem(m0);
E 76
I 76
	/*
	 * Update first fragment by trimming what's been copied out
	 * and updating header, then send each fragment (in order).
	 */
	m_adj(m0, hlen + firstlen - ip->ip_len);
D 77
	ip->ip_len = hlen + firstlen;
	ip->ip_off |= IP_MF;
E 77
I 77
	ip->ip_len = htons((u_short)(hlen + firstlen));
	ip->ip_off = htons((u_short)(ip->ip_off | IP_MF));
E 77
	ip->ip_sum = 0;
	ip->ip_sum = in_cksum(m0, hlen);
sendorfree:
	for (m = m0; m; m = m0) {
		m0 = m->m_act;
		m->m_act = 0;
		if (error == 0)
			error = (*ifp->if_output)(ifp, m,
			    (struct sockaddr *)dst);
		else
			m_freem(m);
	}
    }
E 76
E 75
I 34
done:
D 49
	if (ro == &iproute && ro->ro_rt)
E 49
I 49
	if (ro == &iproute && (flags & IP_ROUTETOIF) == 0 && ro->ro_rt)
E 49
		RTFREE(ro->ro_rt);
E 34
I 21
D 33
	return (0);
E 33
I 33
	return (error);
I 76
bad:
	m_freem(m0);
	goto done;
E 76
E 33
E 21
}

/*
I 60
 * Insert IP options into preformed packet.
 * Adjust IP destination as required for IP source routing,
 * as indicated by a non-zero in_addr at the start of the options.
 */
struct mbuf *
ip_insertoptions(m, opt, phlen)
	register struct mbuf *m;
	struct mbuf *opt;
	int *phlen;
{
	register struct ipoption *p = mtod(opt, struct ipoption *);
	struct mbuf *n;
	register struct ip *ip = mtod(m, struct ip *);
D 64
	int optlen;
E 64
I 64
	unsigned optlen;
E 64

	optlen = opt->m_len - sizeof(p->ipopt_dst);
	if (p->ipopt_dst.s_addr)
		ip->ip_dst = p->ipopt_dst;
	if (m->m_off >= MMAXOFF || MMINOFF + optlen > m->m_off) {
		MGET(n, M_DONTWAIT, MT_HEADER);
		if (n == 0)
			return (m);
		m->m_len -= sizeof(struct ip);
		m->m_off += sizeof(struct ip);
		n->m_next = m;
		m = n;
		m->m_off = MMAXOFF - sizeof(struct ip) - optlen;
		m->m_len = optlen + sizeof(struct ip);
		bcopy((caddr_t)ip, mtod(m, caddr_t), sizeof(struct ip));
	} else {
		m->m_off -= optlen;
		m->m_len += optlen;
		ovbcopy((caddr_t)ip, mtod(m, caddr_t), sizeof(struct ip));
	}
	ip = mtod(m, struct ip *);
D 64
	bcopy((caddr_t)p->ipopt_list, (caddr_t)(ip + 1), optlen);
E 64
I 64
	bcopy((caddr_t)p->ipopt_list, (caddr_t)(ip + 1), (unsigned)optlen);
E 64
	*phlen = sizeof(struct ip) + optlen;
	ip->ip_len += optlen;
	return (m);
}

/*
E 60
D 76
 * Copy options from ip to jp.
D 16
 * If off is 0 all options are copies
E 16
I 16
 * If off is 0 all options are copied
E 16
 * otherwise copy selectively.
E 76
I 76
 * Copy options from ip to jp,
 * omitting those not copied during fragmentation.
E 76
 */
D 76
ip_optcopy(ip, jp, off)
E 76
I 76
ip_optcopy(ip, jp)
E 76
	struct ip *ip, *jp;
D 76
	int off;
E 76
{
	register u_char *cp, *dp;
	int opt, optlen, cnt;

I 16
D 36
COUNT(IP_OPTCOPY);
E 36
E 16
	cp = (u_char *)(ip + 1);
	dp = (u_char *)(jp + 1);
	cnt = (ip->ip_hl << 2) - sizeof (struct ip);
	for (; cnt > 0; cnt -= optlen, cp += optlen) {
		opt = cp[0];
		if (opt == IPOPT_EOL)
			break;
		if (opt == IPOPT_NOP)
			optlen = 1;
		else
D 60
			optlen = cp[1];
E 60
I 60
			optlen = cp[IPOPT_OLEN];
E 60
D 76
		if (optlen > cnt)			/* XXX */
			optlen = cnt;			/* XXX */
		if (off == 0 || IPOPT_COPIED(opt)) {
E 76
I 76
		/* bogus lengths should have been caught by ip_dooptions */
		if (optlen > cnt)
			optlen = cnt;
		if (IPOPT_COPIED(opt)) {
E 76
D 16
			bcopy(cp, dp, optlen);
E 16
I 16
			bcopy((caddr_t)cp, (caddr_t)dp, (unsigned)optlen);
E 16
			dp += optlen;
E 15
E 14
		}
D 15
		ip_send(p);
		p = (struct ip *)((int)m + m->m_off);
		len -= rnd;
		off += rnd;
E 15
E 7
D 2
	} 
E 2
I 2
	}
I 14
D 15
	return;
E 15
I 15
	for (optlen = dp - (u_char *)(jp+1); optlen & 0x3; optlen++)
		*dp++ = IPOPT_EOL;
	return (optlen);
I 60
}

/*
 * IP socket option processing.
 */
ip_ctloutput(op, so, level, optname, m)
	int op;
	struct socket *so;
	int level, optname;
	struct mbuf **m;
{
	int error = 0;
	struct inpcb *inp = sotoinpcb(so);

	if (level != IPPROTO_IP)
		error = EINVAL;
	else switch (op) {

	case PRCO_SETOPT:
		switch (optname) {
		case IP_OPTIONS:
D 61
			return (ip_pcbopts(inp, *m));
E 61
I 61
			return (ip_pcbopts(&inp->inp_options, *m));
E 61

		default:
			error = EINVAL;
			break;
		}
		break;

	case PRCO_GETOPT:
		switch (optname) {
		case IP_OPTIONS:
			*m = m_get(M_WAIT, MT_SOOPTS);
			if (inp->inp_options) {
				(*m)->m_off = inp->inp_options->m_off;
				(*m)->m_len = inp->inp_options->m_len;
				bcopy(mtod(inp->inp_options, caddr_t),
D 64
				    mtod(*m, caddr_t), (*m)->m_len);
E 64
I 64
				    mtod(*m, caddr_t), (unsigned)(*m)->m_len);
E 64
			} else
				(*m)->m_len = 0;
			break;
		default:
			error = EINVAL;
			break;
		}
		break;
	}
D 73
	if (op == PRCO_SETOPT)
E 73
I 73
	if (op == PRCO_SETOPT && *m)
E 73
D 64
		m_free(*m);
E 64
I 64
		(void)m_free(*m);
E 64
	return (error);
}

/*
D 61
 * Set up IP options in inpcb for insertion in output packets.
 * Store in mbuf, adding pseudo-option with destination address
 * if source routed.
E 61
I 61
 * Set up IP options in pcb for insertion in output packets.
 * Store in mbuf with pointer in pcbopt, adding pseudo-option
 * with destination address if source routed.
E 61
 */
D 61
ip_pcbopts(inp, m)
	struct inpcb *inp;
	struct mbuf *m;
E 61
I 61
ip_pcbopts(pcbopt, m)
	struct mbuf **pcbopt;
	register struct mbuf *m;
E 61
{
	register cnt, optlen;
	register u_char *cp;
	u_char opt;

	/* turn off any old options */
D 61
	if (inp->inp_options)
		m_free(inp->inp_options);
	inp->inp_options = 0;

E 61
I 61
	if (*pcbopt)
D 64
		m_free(*pcbopt);
E 64
I 64
		(void)m_free(*pcbopt);
E 64
	*pcbopt = 0;
E 61
	if (m == (struct mbuf *)0 || m->m_len == 0) {
		/*
		 * Only turning off any previous options.
		 */
		if (m)
D 64
			m_free(m);
E 64
I 64
			(void)m_free(m);
E 64
		return (0);
	}

#ifndef	vax
	if (m->m_len % sizeof(long))
		goto bad;
#endif
	/*
	 * IP first-hop destination address will be stored before
	 * actual options; move other options back
	 * and clear it when none present.
	 */
#if	MAX_IPOPTLEN >= MMAXOFF - MMINOFF
	if (m->m_off + m->m_len + sizeof(struct in_addr) > MAX_IPOPTLEN)
		goto bad;
#else
	if (m->m_off + m->m_len + sizeof(struct in_addr) > MMAXOFF)
		goto bad;
#endif
	cnt = m->m_len;
	m->m_len += sizeof(struct in_addr);
	cp = mtod(m, u_char *) + sizeof(struct in_addr);
D 64
	ovbcopy(mtod(m, caddr_t), cp, cnt);
E 64
I 64
	ovbcopy(mtod(m, caddr_t), (caddr_t)cp, (unsigned)cnt);
E 64
	bzero(mtod(m, caddr_t), sizeof(struct in_addr));

	for (; cnt > 0; cnt -= optlen, cp += optlen) {
		opt = cp[IPOPT_OPTVAL];
		if (opt == IPOPT_EOL)
			break;
		if (opt == IPOPT_NOP)
			optlen = 1;
		else {
			optlen = cp[IPOPT_OLEN];
			if (optlen <= IPOPT_OLEN || optlen > cnt)
				goto bad;
		}
		switch (opt) {

		default:
			break;

		case IPOPT_LSRR:
		case IPOPT_SSRR:
			/*
			 * user process specifies route as:
			 *	->A->B->C->D
			 * D must be our final destination (but we can't
			 * check that since we may not have connected yet).
			 * A is first hop destination, which doesn't appear in
			 * actual IP option, but is stored before the options.
			 */
			if (optlen < IPOPT_MINOFF - 1 + sizeof(struct in_addr))
				goto bad;
			m->m_len -= sizeof(struct in_addr);
			cnt -= sizeof(struct in_addr);
			optlen -= sizeof(struct in_addr);
			cp[IPOPT_OLEN] = optlen;
			/*
			 * Move first hop before start of options.
			 */
D 64
			bcopy(&cp[IPOPT_OFFSET+1], mtod(m, caddr_t),
E 64
I 64
			bcopy((caddr_t)&cp[IPOPT_OFFSET+1], mtod(m, caddr_t),
E 64
			    sizeof(struct in_addr));
			/*
			 * Then copy rest of options back
			 * to close up the deleted entry.
			 */
D 64
			ovbcopy(&cp[IPOPT_OFFSET+1] + sizeof(struct in_addr),
			    &cp[IPOPT_OFFSET+1], cnt + sizeof(struct in_addr));
E 64
I 64
			ovbcopy((caddr_t)(&cp[IPOPT_OFFSET+1] +
			    sizeof(struct in_addr)),
			    (caddr_t)&cp[IPOPT_OFFSET+1],
			    (unsigned)cnt + sizeof(struct in_addr));
E 64
			break;
		}
	}
D 61
	inp->inp_options = m;
E 61
I 61
	*pcbopt = m;
E 61
	return (0);

bad:
D 64
	m_free(m);
E 64
I 64
	(void)m_free(m);
E 64
	return (EINVAL);
E 60
E 15
E 14
E 2
D 7

	return(ip_send(p));     /* pass datagram to local net level */
E 7
}
D 21

I 16
/* REST OF CODE HERE IS GARBAGE */

E 16
D 7
ip_send(p)      /* format header and send message to 1822 level */
struct ip *p;
E 7
I 7
D 9
ip_send(p)
	struct ip *p;
E 9
I 9
ip_send(ip)
D 15
	register struct ip *ip;		/* known to be r11 */
E 15
I 15
	register struct ip *ip;
E 15
E 9
E 7
{
	register struct mbuf *m;
	register struct imp *l;
I 9
D 15
	register int hlen = ip->ip_hl << 2;
E 15
I 15
	int hlen = ip->ip_hl << 2;
E 15
E 9
I 2
	int s;
E 2
COUNT(IP_SEND);

D 7
	m = dtom(p);                    /* ->header mbuf */

	/* set up 1822 leader fields for transmit */

E 7
I 7
D 9
	m = dtom(p);
E 9
I 9
	m = dtom(ip);
E 9
E 7
D 14
	l = (struct imp *)((int)m + m->m_off - L1822);
E 14
I 14
	l = (struct imp *)(mtod(m, caddr_t) - L1822);
E 14
D 7
/*
	l->i_hst = p->ip_dst.s_host;
	l->i_impno = p->ip_dst.s_imp;
	l->i_mlen = p->ip_len + L1822;
	l->i_link = IPLINK;
	l->i_type = 0;
	l->i_htype = 0;
	l->i_stype = 0;
*/
E 7
D 2
	l->i_shost = arpa_ether(p->ip_src.s_host);
	l->i_dhost = arpa_ether(p->ip_dst.s_host);
E 2
I 2
D 9
	if ((l->i_shost = p->ip_src.s_host) == 0)
		l->i_shost = 253;
	if ((l->i_dhost = p->ip_dst.s_host) == 0)
		l->i_dhost = 253;
E 9
I 9
	l->i_shost = ip->ip_src.s_host;
	l->i_dhost = ip->ip_dst.s_host;
E 9
E 2
	l->i_type = IPTYPE;
D 7

	/* finish ip leader by calculating checksum and doing
	   necessary byte-swapping  */

E 7
D 9
	p->ip_sum = 0;
D 6
 	ip_bswap(p);
E 6
I 6
	p->ip_len = htons(p->ip_len);
	p->ip_id = htons(p->ip_id);
	p->ip_off = htons(p->ip_off);
E 6
D 2
	p->ip_sum = cksum(m, sizeof(struct ip));     
E 2
I 2
	p->ip_sum = cksum(m, sizeof(struct ip));
E 2
D 7

E 7
	m->m_off -= L1822;              /* -> 1822 leader */
E 9
I 9
	ip->ip_sum = 0;
D 14
	ip->ip_len = htons(ip->ip_len);
E 14
I 14
	ip->ip_len = htons((u_short)ip->ip_len);
E 14
	ip->ip_id = htons(ip->ip_id);
D 14
	ip->ip_off = htons(ip->ip_off);
E 14
I 14
	ip->ip_off = htons((u_short)ip->ip_off);
E 14
D 15
	CKSUM_IPSET(m, ip, r11, hlen);
E 15
I 15
	ip->ip_sum = inet_cksum(m, hlen);
E 15
	m->m_off -= L1822;
E 9
	m->m_len += L1822;
D 7

E 7
D 2
	return(imp_snd(m));             /* pass frag to 1822 */
E 2
I 2
	m->m_act = NULL;
D 7

E 7
#ifndef IMPLOOP
D 7

	/* put output message on queue */

E 7
D 6
	s = spl_imp();
E 6
I 6
	s = splimp();
E 6
	if (imp_stat.outq_head != NULL)
		imp_stat.outq_tail->m_act = m;
	else
		imp_stat.outq_head = m;
	imp_stat.outq_tail = m;
	splx(s);
D 7

	/* if no outstanding output, start some */

E 7
	if (!imp_stat.outactive)
D 8
		imp_output(0);
E 8
I 8
		enstart(0);
E 8
D 7

E 7
#else
D 7
	/* software looping: put msg chain on input queue */

E 7
	if (imp_stat.inq_head != NULL)
		imp_stat.inq_tail->m_act = m;
	else
		imp_stat.inq_head = m;
	imp_stat.inq_tail = m;
I 11
	setsoftnet();
E 11
D 7

E 7
#endif IMPLOOP
D 14
	return (1);
E 14
E 2
D 7
}

ip_setup(up, m, len)            /* setup an ip header for raw write */
register struct ucb *up;
register struct mbuf *m;
int len;
{
	register struct ip *ip;
COUNT(IP_SETUP);

D 4
	m->m_off = MSIZE - sizeof(struct ip);
E 4
I 4
	m->m_off = MMAXOFF - sizeof(struct ip);
E 4
	m->m_len = sizeof(struct ip);

	ip = (struct ip *)((int)m + m->m_off);

	ip->ip_tos = 0;
	ip->ip_id = 0;
	ip->ip_off = 0;
	ip->ip_p = up->uc_lolink;
	ip->ip_len = len + sizeof(struct ip);

D 6
	ip->ip_src.s_addr = netcb.n_lhost.s_addr;
E 6
I 6
	ip->ip_src.s_addr = n_lhost.s_addr;
E 6
        ip->ip_dst.s_addr = up->uc_host->h_addr.s_addr;
E 7
D 2
}


/*
 * Convert logical host on imp to ethernet address.
 * (Primitive; use gateway table in next version.)
 *	0/78	arpavax		253
 *	1/78	ucb-c70		-
 *	-	csvax		252
 *	-	ucb-comet	223
 */
arpa_ether(n)
	int n;
{
COUNT(ARPA_ETHER);
	switch (n) {
	case 0:			/* arpavax */
		return 253;
	default:
		return n;
	}
E 2
}
I 16

/* END GARBAGE */
E 21
E 16
E 1
