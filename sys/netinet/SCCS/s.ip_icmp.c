h56887
s 00010/00005/00428
d D 7.8 88/06/29 17:06:49 bostic 64 63
c install approved copyright notice
e
s 00008/00002/00425
d D 7.7 87/12/07 17:45:36 bostic 63 62
c use Berkeley specific header
e
s 00001/00001/00426
d D 7.6 87/08/31 12:15:42 karels 62 61
c we'll get this right eventually!
e
s 00004/00003/00423
d D 7.5 87/06/04 22:22:30 karels 61 59
c allow icmp errors about non-error icmp messages
e
s 00004/00003/00423
d R 7.5 87/06/04 21:59:18 karels 60 59
c allow icmp errors about non-error icmp messages
e
s 00001/00001/00425
d D 7.4 87/05/24 22:20:23 karels 59 58
c let's use net order in mask replies
e
s 00001/00000/00425
d D 7.3 87/04/28 18:24:30 karels 58 57
c set the ttl for icmp errors, returns
e
s 00001/00001/00424
d D 7.2 87/01/10 16:06:06 karels 57 56
c typo
e
s 00001/00001/00424
d D 7.1 86/06/05 00:27:10 mckusick 56 55
c 4.3BSD release version
e
s 00001/00001/00424
d D 6.20 86/05/31 21:05:01 karels 55 54
c lint
e
s 00003/00002/00422
d D 6.19 86/05/21 22:36:29 karels 54 53
c always set src address to one of ours on icmp errors, even if we don't
c have an address for the incoming interface (picky, picky!)
e
s 00004/00002/00420
d D 6.18 86/04/19 21:00:59 karels 53 52
c receive more errant ICMP's at raw socket; correct notification
c for net redirects
e
s 00034/00038/00388
d D 6.17 86/04/12 23:02:33 karels 52 51
c give the IP header to raw sockets, also pass thru error ICMP's
c already handled in the kernel
e
s 00002/00002/00424
d D 6.16 86/02/23 23:23:51 karels 51 50
c lint
e
s 00032/00059/00394
d D 6.15 86/02/02 20:07:36 karels 50 49
c simplify and fix icmp source route returns; add ifnet arg to icmp_error
c (get the correct from address on redirects)
e
s 00003/00003/00450
d D 6.14 86/01/13 17:22:37 karels 49 48
c millisecond time resolution with microtime
e
s 00147/00037/00306
d D 6.13 85/09/16 23:01:28 karels 48 47
c drop min length restriction on ip packets for errors;
c only one error per fragmented message; fix length calculations for short
c IP packets; additional arg to icmp_error for redirects; ctlinput routines
c take pointers to sockaddrs, not icmp's; pass interface pointer in, so can
c use correct return address (and dst if was sent without src address);
c network address mask request and reply; rearrange IP src rt options for
c returning ICMP request
e
s 00007/00001/00336
d D 6.12 85/06/08 12:39:47 mckusick 47 46
c Add copyright
e
s 00002/00002/00335
d D 6.11 85/05/27 22:01:32 karels 46 45
c use pfctlinput instead of ip_ctlinput to hit everyone
e
s 00001/00000/00336
d D 6.10 85/04/16 09:58:11 karels 45 44
c maintain outhist when echoing
e
s 00020/00008/00316
d D 6.9 85/03/18 15:34:08 karels 44 43
c move net addresses from interface to protocol layer;
c attempt IREQ replies
e
s 00002/00000/00322
d D 6.8 84/11/14 10:14:46 karels 43 42
c generalize in_pcbnotify, use it to cause reallocation of routes
c after receipt of a redirect
e
s 00012/00012/00310
d D 6.7 84/08/29 15:36:12 bloom 42 41
c Include file changes.  No more ../h
e
s 00012/00006/00310
d D 6.6 84/08/28 18:25:16 karels 41 40
c on net redirect, pass net address (not host address)
e
s 00008/00006/00308
d D 6.5 84/03/13 08:31:30 karels 40 39
c can't pullup whole packet if long echo; get at least any returned
c ip header/data
e
s 00001/00001/00313
d D 6.4 84/01/31 16:36:34 karels 39 38
c correct initial length check
e
s 00017/00011/00297
d D 6.3 84/01/11 16:22:06 karels 38 35
c need pullup in icmp_input; add arg to rtredirect to distinguish
c host from net redirects; echo, timestamp and info req. replies don't
c require same min. length as error advice.
e
s 00017/00011/00297
d R 6.3 84/01/11 16:21:00 karels 37 35
c need pullup in icmp_input; add arg to rtredirect to distinguish
e
s 00016/00010/00298
d R 6.3 83/12/15 15:04:16 karels 36 35
c need pullup in icmp_input; add arg to rtredirect to distinguish
c host from net redirects; echo, timestamp and info req. replies don't
c require same min. length as error advice.
e
s 00043/00014/00265
d D 6.2 83/09/19 14:21:08 mckusick 35 34
c clean-ups from wnj
e
s 00000/00000/00279
d D 6.1 83/07/29 07:11:30 sam 34 33
c 4.2 distribution
e
s 00002/00002/00277
d D 4.32 83/05/27 13:45:58 sam 33 32
c lint
e
s 00001/00001/00278
d D 4.31 83/05/01 18:31:18 sam 32 31
c too many mfree's
e
s 00014/00001/00265
d D 4.30 83/03/12 19:35:59 sam 31 30
c routing redirects handled in kernel, then put in raw input
e
s 00035/00012/00231
d D 4.29 83/03/10 21:18:04 sam 30 29
c add statistics
e
s 00001/00000/00242
d D 4.28 83/02/22 23:47:07 sam 29 28
c time stamps, echo replys, etc. had ip_len short
e
s 00002/00001/00240
d D 4.27 83/02/10 22:11:00 sam 28 27
c remove /usr/include dependencies
e
s 00001/00001/00240
d D 4.26 82/12/14 17:14:56 sam 27 26
c typed mbufs
e
s 00009/00008/00232
d D 4.25 82/11/13 23:11:32 sam 26 24
c merge 4.1b with 4.1c
e
s 00010/00009/00231
d R 4.25 82/11/05 09:00:50 sam 25 24
c merge from monet
e
s 00001/00001/00239
d D 4.24 82/11/03 01:08:22 root 24 23
c misc 4.1c fixes
e
s 00000/00004/00240
d D 4.23 82/10/30 13:03:01 root 23 22
c get rid of conditional htons/ntohs etc
e
s 00004/00002/00240
d D 4.22 82/10/20 01:22:25 root 22 21
c lint
e
s 00002/00002/00240
d D 4.21 82/10/17 22:47:17 root 21 20
c lint
e
s 00002/00002/00240
d D 4.20 82/10/17 14:54:54 root 20 19
c fix lint
e
s 00004/00004/00238
d D 4.19 82/10/09 05:45:29 wnj 19 18
c localize header files
e
s 00003/00002/00239
d D 4.18 82/09/12 03:21:16 root 18 17
c time now a structure
e
s 00000/00005/00241
d D 4.17 82/06/20 00:54:07 sam 17 16
c purge COUNT stuff now that we can use gprof
e
s 00002/00002/00244
d D 4.16 82/05/02 17:05:03 sam 16 15
c clean up some icmp stuff; add EHOSTDOWN & EHOSTUNREACH
e
s 00024/00004/00222
d D 4.15 82/04/25 18:35:28 sam 15 14
c icmp works with tcp and friends
e
s 00072/00064/00154
d D 4.14 82/04/24 20:38:07 sam 14 13
c icmp and ctlinput working -- missing protocol specific ctlinput's
e
s 00001/00002/00217
d D 4.13 82/04/07 17:44:47 wnj 13 12
c properly free mbuf space
e
s 00001/00001/00218
d D 4.12 82/01/19 07:29:51 root 12 11
c m_get(0) -> m_get(M_DONTWAIT)
e
s 00001/00005/00218
d D 4.11 81/12/22 23:12:19 root 11 10
c just drop packet cleanly
e
s 00006/00009/00217
d D 4.10 81/12/03 17:29:41 wnj 10 9
c cleanup
e
s 00001/00001/00225
d D 4.9 81/11/29 21:59:37 wnj 9 8
c lint and interface cleanups
e
s 00013/00005/00213
d D 4.8 81/11/26 11:56:27 wnj 8 7
c before carry to ARPAVAX
e
s 00001/00001/00217
d D 4.7 81/11/23 00:01:53 wnj 7 6
c set ip_ttl
e
s 00002/00002/00216
d D 4.6 81/11/20 14:41:44 wnj 6 5
c more lint
e
s 00004/00003/00214
d D 4.5 81/11/18 15:37:07 wnj 5 4
c more cleanup
e
s 00017/00011/00200
d D 4.4 81/11/16 14:16:44 wnj 4 3
c more lint
e
s 00001/00001/00210
d D 4.3 81/11/14 16:39:55 wnj 3 2
c before overlay
e
s 00044/00046/00167
d D 4.2 81/11/08 16:24:26 wnj 2 1
c first listing
e
s 00213/00000/00000
d D 4.1 81/11/07 17:55:36 wnj 1 0
c date and time created 81/11/07 17:55:36 by wnj
e
u
U
f b 
t
T
I 1
D 6
/* %M% %I% %E% */
E 6
I 6
D 47
/*	%M%	%I%	%E%	*/
E 47
I 47
/*
D 56
 * Copyright (c) 1982 Regents of the University of California.
E 56
I 56
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 56
D 63
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 63
I 63
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 64
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 64
I 64
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
E 64
E 63
 *
 *	%W% (Berkeley) %G%
 */
E 47
E 6

D 42
#include "../h/param.h"
I 5
#include "../h/systm.h"
E 5
#include "../h/mbuf.h"
D 2
#include "../inet/inet.h"
#include "../inet/inet_systm.h"
#include "../inet/ip.h"
E 2
I 2
D 4
#include "../h/inaddr.h"
E 4
I 4
#include "../h/protosw.h"
I 14
#include "../h/socket.h"
I 22
D 28
#include <time.h>
E 28
I 28
#include "../h/time.h"
E 28
#include "../h/kernel.h"
E 42
I 42
#include "param.h"
#include "systm.h"
#include "mbuf.h"
#include "protosw.h"
#include "socket.h"
#include "time.h"
#include "kernel.h"
E 42

#include "../net/route.h"
I 44
#include "../net/if.h"
E 44
I 28

E 28
E 22
E 14
D 18
#include "../h/clock.h"
E 18
E 4
D 8
#include "../net/inet.h"
#include "../net/inet_systm.h"
E 8
I 8
D 19
#include "../net/in.h"
#include "../net/in_systm.h"
E 8
#include "../net/ip.h"
#include "../net/ip_icmp.h"
E 19
I 19
D 42
#include "../netinet/in.h"
#include "../netinet/in_systm.h"
#include "../netinet/ip.h"
#include "../netinet/ip_icmp.h"
I 30
#include "../netinet/icmp_var.h"
E 42
I 42
#include "in.h"
#include "in_systm.h"
I 44
#include "in_var.h"
E 44
#include "ip.h"
#include "ip_icmp.h"
#include "icmp_var.h"
E 42
E 30
E 19
I 18
D 22
#include <time.h>
#include "../h/kernel.h"
E 22
E 18
E 2

I 35
#ifdef ICMPPRINTFS
E 35
/*
 * ICMP routines: error generation, receive packet processing, and
 * routines to turnaround packets back to the originator, and
 * host table maintenance routines.
 */
I 15
D 16
int	icmpprintfs = 1;
E 16
I 16
int	icmpprintfs = 0;
I 35
#endif
E 35
E 16
E 15

/*
D 14
 * Generate an error packet of type error in response to bad packet ip.
E 14
I 14
 * Generate an error packet of type error
 * in response to bad packet ip.
E 14
 */
D 48
icmp_error(oip, type, code)
E 48
I 48
D 50
/*VARARGS3*/
icmp_error(oip, type, code, dest)
E 50
I 50
/*VARARGS4*/
icmp_error(oip, type, code, ifp, dest)
E 50
E 48
	struct ip *oip;
D 14
	int type;
E 14
I 14
D 30
	int type, code;
E 30
I 30
D 33
	u_int type, code;
E 33
I 33
	int type, code;
I 50
	struct ifnet *ifp;
E 50
I 48
	struct in_addr dest;
E 48
E 33
E 30
E 14
{
D 4
	int oiplen = oip->ip_hl << 2;
E 4
I 4
D 14
	unsigned oiplen = oip->ip_hl << 2;
E 4
D 2
	struct icmp *icp = (struct icp *)((int)oip + oiplen);
E 2
I 2
	struct icmp *icp = (struct icmp *)((int)oip + oiplen);
E 14
I 14
	register unsigned oiplen = oip->ip_hl << 2;
	register struct icmp *icp;
E 14
E 2
	struct mbuf *m;
	struct ip *nip;
I 48
D 51
	int icmplen;
E 51
I 51
	unsigned icmplen;
E 51
E 48
I 8
D 17
COUNT(ICMP_ERROR);
E 17
E 8

I 35
#ifdef ICMPPRINTFS
E 35
I 15
	if (icmpprintfs)
		printf("icmp_error(%x, %d, %d)\n", oip, type, code);
I 35
#endif
E 35
I 30
D 50
	icmpstat.icps_error++;
E 50
I 50
	if (type != ICMP_REDIRECT)
		icmpstat.icps_error++;
E 50
E 30
E 15
	/*
D 48
	 * Make sure that the old IP packet had 8 bytes of data to return;
	 * if not, don't bother.  Also don't EVER error if the old
	 * packet protocol was ICMP.
E 48
I 48
	 * Don't send error if not the first fragment of message.
D 61
	 * Don't EVER error if the old packet protocol was ICMP.
	 * (Could do ECHO, etc, but not error indications.)
E 61
I 61
	 * Don't error if the old packet protocol was ICMP
	 * error message, only known informational types.
E 61
E 48
	 */
D 15
	if (oip->ip_len - oiplen < 8 || oip->ip_p == IPPROTO_ICMP)
E 15
I 15
D 30
	if (oip->ip_len < 8 || oip->ip_p == IPPROTO_ICMP)
E 30
I 30
D 48
	if (oip->ip_len < 8) {
		icmpstat.icps_oldshort++;
E 48
I 48
	if (oip->ip_off &~ (IP_MF|IP_DF))
E 48
E 30
E 15
		goto free;
I 30
D 48
	}
	if (oip->ip_p == IPPROTO_ICMP) {
E 48
I 48
D 61
	if (oip->ip_p == IPPROTO_ICMP && type != ICMP_REDIRECT) {
E 61
I 61
	if (oip->ip_p == IPPROTO_ICMP && type != ICMP_REDIRECT &&
	  !ICMP_INFOTYPE(((struct icmp *)((caddr_t)oip + oiplen))->icmp_type)) {
E 61
E 48
		icmpstat.icps_oldicmp++;
		goto free;
	}
E 30

	/*
D 14
	 * Get a new mbuf, and fill in a ICMP header at the bottom
	 * of the mbuf, followed by the old IP header and 8 bytes
	 * of its data.
E 14
I 14
	 * First, formulate icmp message
E 14
	 */
D 12
	m = m_get(0);
E 12
I 12
D 27
	m = m_get(M_DONTWAIT);
E 27
I 27
	m = m_get(M_DONTWAIT, MT_HEADER);
E 27
E 12
D 30
	if (m == 0)
E 30
I 30
	if (m == NULL)
E 30
		goto free;
D 14
	m->m_off = MMAXOFF - (oiplen + 8);
E 14
I 14
D 48
	m->m_len = oiplen + 8 + ICMP_MINLEN;
E 48
I 48
	icmplen = oiplen + MIN(8, oip->ip_len);
	m->m_len = icmplen + ICMP_MINLEN;
E 48
	m->m_off = MMAXOFF - m->m_len;
	icp = mtod(m, struct icmp *);
I 30
D 33
	if (type > ICMP_IREQREPLY)
E 33
I 33
D 48
	if ((u_int)type > ICMP_IREQREPLY)
E 48
I 48
	if ((u_int)type > ICMP_MAXTYPE)
E 48
E 33
		panic("icmp_error");
	icmpstat.icps_outhist[type]++;
E 30
E 14
	icp->icmp_type = type;
I 14
D 48
	icp->icmp_void = 0;
E 48
I 48
	if (type == ICMP_REDIRECT)
		icp->icmp_gwaddr = dest;
	else
		icp->icmp_void = 0;
E 48
E 14
	if (type == ICMP_PARAMPROB) {
D 14
		icp->icmp_code = 0;
E 14
		icp->icmp_pptr = code;
D 14
	} else
		icp->icmp_code = code;
E 14
I 14
		code = 0;
	}
	icp->icmp_code = code;
E 14
D 2
	bcopy((caddr_t)oip, (caddr_t)&icp->icmp_ip.icmp_ip, oiplen + 8);
E 2
I 2
D 48
	bcopy((caddr_t)oip, (caddr_t)&icp->icmp_ip, oiplen + 8);
E 48
I 48
	bcopy((caddr_t)oip, (caddr_t)&icp->icmp_ip, icmplen);
E 48
I 15
	nip = &icp->icmp_ip;
	nip->ip_len += oiplen;
D 20
#if vax || pdp11
E 20
I 20
D 23
#if vax || pdp11 || ns16032
E 23
E 20
	nip->ip_len = htons((u_short)nip->ip_len);
D 23
#endif
E 23
E 15
E 2

	/*
D 14
	 * Now prepend an IP header and reflect this packet back to
	 * the source.
E 14
I 14
D 52
	 * Now, copy old ip header in front of icmp
	 * message.  This allows us to reuse any source
	 * routing info present.
E 52
I 52
	 * Now, copy old ip header in front of icmp message.
E 52
E 14
	 */
I 48
	if (m->m_len + oiplen > MLEN)
		oiplen = sizeof(struct ip);
	if (m->m_len + oiplen > MLEN)
		panic("icmp len");
E 48
D 14
	m->m_off -= sizeof (struct ip);
	m->m_len += sizeof (struct ip);
D 2
	nip = (struct ip *)mtod(m);
	*nip = *ip;
	icmp_reflect(ip);
E 2
I 2
	nip = (struct ip *)mtod(m, struct ip *);
	*nip = *oip;
E 14
I 14
	m->m_off -= oiplen;
I 52
	m->m_len += oiplen;
E 52
	nip = mtod(m, struct ip *);
	bcopy((caddr_t)oip, (caddr_t)nip, oiplen);
D 52
	nip->ip_len = m->m_len + oiplen;
E 52
I 52
	nip->ip_len = m->m_len;
E 52
	nip->ip_p = IPPROTO_ICMP;
D 52
	/* icmp_send adds ip header to m_off and m_len, so we deduct here */
	m->m_off += oiplen;
E 52
E 14
D 48
	icmp_reflect(nip);
E 48
I 48
D 50
	icmp_reflect(nip, in_ifaddr->ia_ifp);
E 50
I 50
	icmp_reflect(nip, ifp);
E 50
E 48
I 10
D 13
	return;
E 13
E 10
E 2

I 13
free:
E 13
D 14
	/*
	 * Discard mbufs of original datagram
	 */
E 14
D 13
free:
E 13
	m_freem(dtom(oip));
}

I 14
D 35
static char icmpmap[] = {
	-1,		 -1,		-1,
	PRC_UNREACH_NET, PRC_QUENCH, 	PRC_REDIRECT_NET,
	-1,		 -1,		-1,
	-1,		 -1,		PRC_TIMXCEED_INTRANS,
	PRC_PARAMPROB,	 -1,		-1,
	-1,		 -1
};

E 35
static struct sockproto icmproto = { AF_INET, IPPROTO_ICMP };
static struct sockaddr_in icmpsrc = { AF_INET };
static struct sockaddr_in icmpdst = { AF_INET };
I 48
static struct sockaddr_in icmpgw = { AF_INET };
struct in_ifaddr *ifptoia();
E 48

E 14
/*
D 2
 * Processor a received ICMP message.
E 2
I 2
 * Process a received ICMP message.
E 2
 */
D 48
icmp_input(m)
E 48
I 48
icmp_input(m, ifp)
E 48
D 53
	struct mbuf *m;
E 53
I 53
	register struct mbuf *m;
E 53
I 48
	struct ifnet *ifp;
E 48
{
D 2
	int hlen = ip->ip_hl << 2;
	register struct ip *ip = (struct ip *)mtod(m);
E 2
	register struct icmp *icp;
I 2
	register struct ip *ip = mtod(m, struct ip *);
D 14
	int hlen = ip->ip_hl << 2;
E 2
	int icmplen = ip->ip_len - hlen;
I 2
	int i;
E 14
I 14
D 15
	int icmplen = ip->ip_len, hlen = ip->ip_hl << 2, i;
E 15
I 15
D 26
	int icmplen = ip->ip_len, hlen = ip->ip_hl << 2, i, (*ctlfunc)();
E 26
I 26
	int icmplen = ip->ip_len, hlen = ip->ip_hl << 2;
D 30
	int i, (*ctlfunc)(), type;
E 30
I 30
D 40
	int (*ctlfunc)(), code, i;
E 40
I 40
	register int i;
I 48
	struct in_ifaddr *ia;
E 48
	int (*ctlfunc)(), code;
E 40
E 30
E 26
E 15
E 14
I 10
	extern u_char ip_protox[];
I 41
D 44
	extern struct in_addr if_makeaddr();
E 44
I 44
	extern struct in_addr in_makeaddr();
E 44
E 41
E 10
I 8
D 17
COUNT(ICMP_INPUT);
E 17
E 8
E 2

	/*
	 * Locate icmp structure in mbuf, and check
	 * that not corrupted and of at least minimum length.
	 */
I 35
#ifdef ICMPPRINTFS
E 35
I 15
	if (icmpprintfs)
		printf("icmp_input from %x, len %d\n", ip->ip_src, icmplen);
I 35
#endif
E 35
E 15
I 14
D 30
	if (icmplen < ICMP_MINLEN)
E 30
I 30
D 38
	if (icmplen < ICMP_MINLEN) {
E 38
I 38
D 39
	if (icmplen < sizeof(struct ip) + ICMP_MINLEN) {
E 39
I 39
	if (icmplen < ICMP_MINLEN) {
E 39
E 38
		icmpstat.icps_tooshort++;
E 30
		goto free;
I 30
	}
I 38
D 40
	if ((m->m_off > MMAXOFF || m->m_len < icmplen)
	   && (m = m_pullup(m, icmplen)) == 0) {
E 40
I 40
D 48
	/* THIS LENGTH CHECK STILL MISSES ANY IP OPTIONS IN ICMP_IP */
	i = MIN(icmplen, ICMP_ADVLENMIN + hlen);
E 48
I 48
	i = hlen + MIN(icmplen, ICMP_ADVLENMIN);
E 48
 	if ((m->m_off > MMAXOFF || m->m_len < i) &&
 		(m = m_pullup(m, i)) == 0)  {
E 40
		icmpstat.icps_tooshort++;
		return;
	}
I 40
 	ip = mtod(m, struct ip *);
E 40
E 38
E 30
E 14
	m->m_len -= hlen;
	m->m_off += hlen;
D 38
	/* need routine to make sure header is in this mbuf here */
E 38
D 2
	icp = (struct icmp *)mtod(m);
E 2
I 2
D 14
	icp = (struct icmp *)mtod(m, struct icmp *);
E 14
I 14
	icp = mtod(m, struct icmp *);
E 14
E 2
D 40
	i = icp->icmp_cksum;
	icp->icmp_cksum = 0;
D 2
	if (i != cksum(m, icmplen) || icmplen < ICMP_MINLEN)
		goto bad;
E 2
I 2
D 8
	if (i != inet_cksum(m, icmplen) || icmplen < ICMP_MINLEN)
E 8
I 8
D 14
	if (i != in_cksum(m, icmplen) || icmplen < ICMP_MINLEN)
E 14
I 14
	if (i != in_cksum(m, icmplen)) {
E 40
I 40
	if (in_cksum(m, icmplen)) {
E 40
D 30
		printf("icmp: cksum %x\n", i);
E 30
I 30
		icmpstat.icps_checksum++;
E 30
E 14
E 8
		goto free;
I 14
	}
I 52
	m->m_len += hlen;
	m->m_off -= hlen;
E 52
E 14
E 2

I 35
#ifdef ICMPPRINTFS
E 35
	/*
	 * Message type specific processing.
	 */
I 15
	if (icmpprintfs)
		printf("icmp_input, type %d code %d\n", icp->icmp_type,
D 35
			icp->icmp_code);
E 35
I 35
		    icp->icmp_code);
#endif
E 35
E 15
D 2
	switch (ipc->icmp_type) {
E 2
I 2
D 14
	switch (icp->icmp_type) {
E 14
I 14
D 30
	switch (i = icp->icmp_type) {
E 30
I 30
D 48
	if (icp->icmp_type > ICMP_IREQREPLY)
E 48
I 48
	if (icp->icmp_type > ICMP_MAXTYPE)
E 48
D 53
		goto free;
E 53
I 53
		goto raw;
E 53
	icmpstat.icps_inhist[icp->icmp_type]++;
I 35
	code = icp->icmp_code;
E 35
	switch (icp->icmp_type) {
E 30
E 14
E 2

	case ICMP_UNREACH:
I 35
		if (code > 5)
			goto badcode;
		code += PRC_UNREACH_NET;
		goto deliver;

E 35
	case ICMP_TIMXCEED:
I 35
		if (code > 1)
			goto badcode;
		code += PRC_TIMXCEED_INTRANS;
		goto deliver;

E 35
	case ICMP_PARAMPROB:
I 35
		if (code)
			goto badcode;
		code = PRC_PARAMPROB;
		goto deliver;

E 35
D 14
	case ICMP_SOURCEQUENCH:
E 14
D 31
	case ICMP_REDIRECT:
E 31
I 14
	case ICMP_SOURCEQUENCH:
I 35
		if (code)
			goto badcode;
		code = PRC_QUENCH;
	deliver:
E 35
E 14
		/*
D 35
		 * Problem with previous datagram; advise
		 * higher level routines.
E 35
I 35
		 * Problem with datagram; advise higher level routines.
E 35
		 */
I 15
D 20
#if vax || pdp11
E 20
I 20
D 23
#if vax || pdp11 || ns16032
E 23
E 20
D 21
		icp->icmp_ip.ip_len = ntohs(icp->icmp_ip.ip_len);
E 21
I 21
		icp->icmp_ip.ip_len = ntohs((u_short)icp->icmp_ip.ip_len);
E 21
D 23
#endif
E 23
E 15
D 2
		if (icmplen < ICMP_MINADVLEN || icmplen < ICMP_ADVLEN(ipc))
			goto drop;
		icmp_advise(ip, ipc);
E 2
I 2
D 30
		if (icmplen < ICMP_ADVLENMIN || icmplen < ICMP_ADVLEN(icp))
E 30
I 30
		if (icmplen < ICMP_ADVLENMIN || icmplen < ICMP_ADVLEN(icp)) {
			icmpstat.icps_badlen++;
E 30
			goto free;
I 30
		}
I 35
#ifdef ICMPPRINTFS
E 35
E 30
D 4
		icmp_advise(ip, icp);
E 4
I 4
D 10
		icmp_ctlinput(ip);
E 10
I 10
D 14
		(*protosw[ip_protox[ip->ip_p]].pr_ctlinput)(m);
E 14
I 14
D 15
		(*protosw[ip_protox[ip->ip_p]].pr_ctlinput)
			(icmpmap[i] + icp->icmp_code, (caddr_t)icp);
E 15
I 15
		if (icmpprintfs)
			printf("deliver to protocol %d\n", icp->icmp_ip.ip_p);
I 26
D 30
		type = i == ICMP_PARAMPROB ? 0 : icp->icmp_code;
E 30
I 30
D 35
		code = icp->icmp_type == ICMP_PARAMPROB ? 0 : icp->icmp_code;
E 35
I 35
#endif
I 48
		icmpsrc.sin_addr = icp->icmp_ip.ip_dst;
E 48
E 35
E 30
E 26
D 24
		if (ctlfunc = protosw[ip_protox[icp->icmp_ip.ip_p]].pr_ctlinput)
E 24
I 24
		if (ctlfunc = inetsw[ip_protox[icp->icmp_ip.ip_p]].pr_ctlinput)
E 24
D 26
			(*ctlfunc)(icmpmap[i] + icp->icmp_code, (caddr_t)icp);
E 26
I 26
D 30
			(*ctlfunc)(icmpmap[i] + type, (caddr_t)icp);
E 30
I 30
D 35
			(*ctlfunc)(icmpmap[icp->icmp_type]+code, (caddr_t)icp);
E 35
I 35
D 48
			(*ctlfunc)(code, (caddr_t)icp);
E 48
I 48
			(*ctlfunc)(code, (struct sockaddr *)&icmpsrc);
E 48
E 35
E 30
E 26
E 15
E 14
E 10
E 4
E 2
D 52
		goto free;
E 52
I 52
		break;
E 52

I 35
	badcode:
		icmpstat.icps_badcode++;
D 52
		goto free;
E 52
I 52
		break;
E 52

E 35
	case ICMP_ECHO:
		icp->icmp_type = ICMP_ECHOREPLY;
		goto reflect;

	case ICMP_TSTAMP:
D 2
		if (icmplen < ICMP_MINLEN + sizeof ())
			goto bad;
E 2
I 2
D 30
		if (icmplen < ICMP_TSLEN)
E 30
I 30
		if (icmplen < ICMP_TSLEN) {
			icmpstat.icps_badlen++;
E 30
D 52
			goto free;
E 52
I 52
			break;
E 52
I 30
		}
E 30
E 2
		icp->icmp_type = ICMP_TSTAMPREPLY;
D 2
		millitime(&icp->icmp_rtime);
E 2
I 2
D 4
		ip_time(&icp->icmp_rtime);
E 4
I 4
D 5
		icp->icmp_rtime = ip_time();
E 5
I 5
		icp->icmp_rtime = iptime();
E 5
E 4
E 2
		icp->icmp_ttime = icp->icmp_rtime;	/* bogus, do later! */
		goto reflect;
		
	case ICMP_IREQ:
I 35
D 44
#ifdef notdef
E 35
		/* fill in source address zero fields! */
E 44
I 44
#define	satosin(sa)	((struct sockaddr_in *)(sa))
D 48
		if (in_netof(ip->ip_src) == 0)
			ip->ip_src = in_makeaddr(
			    in_netof(satosin(&in_ifaddr->ia_addr)->sin_addr),
E 48
I 48
		if (in_netof(ip->ip_src) == 0 && (ia = ifptoia(ifp)))
			ip->ip_src = in_makeaddr(in_netof(IA_SIN(ia)->sin_addr),
E 48
			    in_lnaof(ip->ip_src));
		icp->icmp_type = ICMP_IREQREPLY;
E 44
		goto reflect;
I 35
D 44
#else
		goto free;		/* not yet implemented: ignore */
#endif
E 44
E 35

I 48
	case ICMP_MASKREQ:
		if (icmplen < ICMP_MASKLEN || (ia = ifptoia(ifp)) == 0)
D 52
			goto free;
E 52
I 52
			break;
E 52
D 57
		icp->icmp_type = ICMP_IREQREPLY;
E 57
I 57
		icp->icmp_type = ICMP_MASKREPLY;
E 57
D 59
		icp->icmp_mask = ia->ia_netmask;
E 59
I 59
D 62
		icp->icmp_mask = ntohl(ia->ia_netmask);
E 62
I 62
		icp->icmp_mask = htonl(ia->ia_subnetmask);
E 62
E 59
		if (ip->ip_src.s_addr == 0) {
			if (ia->ia_ifp->if_flags & IFF_BROADCAST)
			    ip->ip_src = satosin(&ia->ia_broadaddr)->sin_addr;
			else if (ia->ia_ifp->if_flags & IFF_POINTOPOINT)
			    ip->ip_src = satosin(&ia->ia_dstaddr)->sin_addr;
		}
D 52
		goto reflect;
E 52
I 52
reflect:
		ip->ip_len += hlen;	/* since ip_input deducts this */
		icmpstat.icps_reflect++;
		icmpstat.icps_outhist[icp->icmp_type]++;
		icmp_reflect(ip, ifp);
		return;
E 52

E 48
I 31
	case ICMP_REDIRECT:
E 31
D 38
	case ICMP_ECHOREPLY:
	case ICMP_TSTAMPREPLY:
	case ICMP_IREQREPLY:
E 38
D 2
		if (icmplen < ICMP_MINADVLEN || icmplen < ICMP_ADVLEN(ipc))
			goto drop;
E 2
I 2
D 30
		if (icmplen < ICMP_ADVLENMIN || icmplen < ICMP_ADVLEN(icp))
E 30
I 30
		if (icmplen < ICMP_ADVLENMIN || icmplen < ICMP_ADVLEN(icp)) {
			icmpstat.icps_badlen++;
E 30
D 52
			goto free;
E 52
I 52
			break;
E 52
I 31
		}
		/*
		 * Short circuit routing redirects to force
		 * immediate change in the kernel's routing
		 * tables.  The message is also handed to anyone
		 * listening on a raw socket (e.g. the routing
D 41
		 * daemon for use in updating it's tables).
E 41
I 41
		 * daemon for use in updating its tables).
E 41
		 */
I 48
		icmpgw.sin_addr = ip->ip_src;
E 48
D 38
		if (icp->icmp_type == ICMP_REDIRECT) {
			icmpsrc.sin_addr = icp->icmp_ip.ip_dst;
			icmpdst.sin_addr = icp->icmp_gwaddr;
			rtredirect((struct sockaddr *)&icmpsrc,
			  (struct sockaddr *)&icmpdst);
E 31
I 30
		}
E 38
I 38
D 41
		icmpsrc.sin_addr = icp->icmp_ip.ip_dst;
E 41
		icmpdst.sin_addr = icp->icmp_gwaddr;
I 48
#ifdef	ICMPPRINTFS
		if (icmpprintfs)
			printf("redirect dst %x to %x\n", icp->icmp_ip.ip_dst,
				icp->icmp_gwaddr);
#endif
E 48
D 41
		rtredirect((struct sockaddr *)&icmpsrc,
		  (struct sockaddr *)&icmpdst,
		  (code == ICMP_REDIRECT_NET || code == ICMP_REDIRECT_TOSNET) ?
		   RTF_GATEWAY : (RTF_GATEWAY | RTF_HOST));
E 41
I 41
		if (code == ICMP_REDIRECT_NET || code == ICMP_REDIRECT_TOSNET) {
			icmpsrc.sin_addr =
D 44
			 if_makeaddr(in_netof(icp->icmp_ip.ip_dst), INADDR_ANY);
E 44
I 44
			 in_makeaddr(in_netof(icp->icmp_ip.ip_dst), INADDR_ANY);
E 44
			rtredirect((struct sockaddr *)&icmpsrc,
D 48
			  (struct sockaddr *)&icmpdst, RTF_GATEWAY);
I 43
D 46
			ip_ctlinput(PRC_REDIRECT_NET, (caddr_t)icp);
E 46
I 46
			pfctlinput(PRC_REDIRECT_NET, (caddr_t)icp);
E 48
I 48
			  (struct sockaddr *)&icmpdst, RTF_GATEWAY,
			  (struct sockaddr *)&icmpgw);
I 53
			icmpsrc.sin_addr = icp->icmp_ip.ip_dst;
E 53
			pfctlinput(PRC_REDIRECT_NET,
			  (struct sockaddr *)&icmpsrc);
E 48
E 46
E 43
		} else {
			icmpsrc.sin_addr = icp->icmp_ip.ip_dst;
			rtredirect((struct sockaddr *)&icmpsrc,
D 48
			  (struct sockaddr *)&icmpdst, RTF_GATEWAY | RTF_HOST);
I 43
D 46
			ip_ctlinput(PRC_REDIRECT_HOST, (caddr_t)icp);
E 46
I 46
			pfctlinput(PRC_REDIRECT_HOST, (caddr_t)icp);
E 48
I 48
			  (struct sockaddr *)&icmpdst, RTF_GATEWAY | RTF_HOST,
			  (struct sockaddr *)&icmpgw);
			pfctlinput(PRC_REDIRECT_HOST,
			  (struct sockaddr *)&icmpsrc);
E 48
E 46
E 43
		}
E 41
D 52
		/* FALL THROUGH */
E 52
I 52
		break;
E 52

I 52
	/*
	 * No kernel processing for the following;
	 * just fall through to send to raw listener.
	 */
E 52
	case ICMP_ECHOREPLY:
	case ICMP_TSTAMPREPLY:
	case ICMP_IREQREPLY:
I 48
	case ICMP_MASKREPLY:
E 48
E 38
E 30
E 2
D 14
		icmp_gotreply(icp);
E 14
I 14
D 52
		icmpsrc.sin_addr = ip->ip_src;
		icmpdst.sin_addr = ip->ip_dst;
		raw_input(dtom(icp), &icmproto, (struct sockaddr *)&icmpsrc,
		  (struct sockaddr *)&icmpdst);
E 14
D 32
		goto free;
E 32
I 32
		return;
E 32

E 52
	default:
D 52
		goto free;
E 52
I 52
		break;
E 52
	}
D 52
reflect:
I 29
	ip->ip_len += hlen;		/* since ip_input deducts this */
I 30
	icmpstat.icps_reflect++;
I 45
	icmpstat.icps_outhist[icp->icmp_type]++;
E 45
E 30
E 29
D 48
	icmp_reflect(ip);
E 48
I 48
	icmp_reflect(ip, ifp);
E 52
I 52

I 53
raw:
E 53
	icmpsrc.sin_addr = ip->ip_src;
	icmpdst.sin_addr = ip->ip_dst;
	raw_input(m, &icmproto, (struct sockaddr *)&icmpsrc,
	    (struct sockaddr *)&icmpdst);
E 52
E 48
I 26
	return;
I 52

E 52
E 26
free:
D 52
	m_freem(dtom(ip));
E 52
I 52
	m_freem(m);
E 52
}

/*
 * Reflect the ip packet back to the source
I 14
D 48
 * TODO: rearrange ip source routing options.
E 48
E 14
 */
D 48
icmp_reflect(ip)
E 48
I 48
icmp_reflect(ip, ifp)
E 48
D 50
	struct ip *ip;
E 50
I 50
	register struct ip *ip;
E 50
I 48
	struct ifnet *ifp;
E 48
{
D 2
	struct inet_addr t;
E 2
I 2
D 5
	struct ip_addr t;
E 5
I 5
D 44
	struct in_addr t;
E 44
I 44
D 48
	register struct in_addr t;
E 48
	register struct in_ifaddr *ia;
I 48
D 50
	register u_char *cp;
	int opt, optlen, cnt;
E 50
	struct in_addr t;
D 50
	struct in_addr *p, *q;
E 50
I 50
D 55
	struct mbuf *m, *opts = 0, *ip_srcroute();
E 55
I 55
	struct mbuf *opts = 0, *ip_srcroute();
E 55
I 52
	int optlen = (ip->ip_hl << 2) - sizeof(struct ip);
E 52
E 50
E 48
E 44
I 8
D 17
COUNT(ICMP_REFLECT);
E 17
E 8
E 5
E 2

I 2
D 14
	t = ip->ip_src; ip->ip_dst = ip->ip_src; ip->ip_src = t;
E 2
	/*
	 * This is a little naive... do we have to munge the options
	 * to reverse source routing?
	 */
E 14
I 14
	t = ip->ip_dst;
I 44
D 48
	if (t.s_addr == INADDR_ANY)
		t = IA_SIN(in_ifaddr)->sin_addr;
	else for (ia = in_ifaddr; ia; ia = ia->ia_next)
		if (t.s_addr == satosin(&ia->ia_broadaddr)->sin_addr.s_addr &&
		    (ia->ia_ifp->if_flags & IFF_BROADCAST)) {
			t = IA_SIN(ia)->sin_addr;
			break;
		}
E 48
E 44
	ip->ip_dst = ip->ip_src;
I 48
	/*
	 * If the incoming packet was addressed directly to us,
	 * use dst as the src for the reply.  Otherwise (broadcast
	 * or anonymous), use the address which corresponds
	 * to the incoming interface.
	 */
	for (ia = in_ifaddr; ia; ia = ia->ia_next) {
		if (t.s_addr == IA_SIN(ia)->sin_addr.s_addr)
			break;
		if ((ia->ia_ifp->if_flags & IFF_BROADCAST) &&
		    t.s_addr == satosin(&ia->ia_broadaddr)->sin_addr.s_addr)
			break;
	}
	if (ia == (struct in_ifaddr *)0)
		ia = ifptoia(ifp);
D 54
	if (ia)
		t = IA_SIN(ia)->sin_addr;
E 54
I 54
	if (ia == (struct in_ifaddr *)0)
		ia = in_ifaddr;
	t = IA_SIN(ia)->sin_addr;
E 54
E 48
	ip->ip_src = t;
I 58
	ip->ip_ttl = MAXTTL;
E 58
I 48

D 50
	/*
	 * If the incoming packet was source-routed,
	 * we need to reverse the route and set the next-hop destination.
	 * We can dispense with the error checking
	 * as ip_dooptions has been through here before.
	 */
E 50
D 52
	if ((ip->ip_hl << 2) > sizeof(struct ip)) {
D 50
		cp = (u_char *)(ip + 1);
		cnt = (ip->ip_hl << 2) - sizeof (struct ip);
		for (; cnt > 0; cnt -= optlen, cp += optlen) {
			opt = cp[IPOPT_OPTVAL];
			if (opt == IPOPT_EOL)
				break;
			if (opt == IPOPT_NOP)
				optlen = 1;
			else
				optlen = cp[IPOPT_OLEN];
			if (opt == IPOPT_LSRR || opt == IPOPT_SSRR) {
				p = (struct in_addr *)
				    (cp + cp[IPOPT_OFFSET] - 1) - 1;
				q = (struct in_addr *)(cp + IPOPT_MINOFF - 1);
				/*
				 * First switch the last route entry
				 * (first hop for return) with ip_dst
				 * (final hop on return).
				 */
				bcopy((caddr_t)p, (caddr_t)&t, sizeof(t));
				bcopy((caddr_t)&ip->ip_dst, (caddr_t)p,
				   sizeof(struct in_addr));
				ip->ip_dst = t;
				p--;
				/*
				 * Then reverse remaining route entries.
				 */
				while (p > q) {
					bcopy((caddr_t)p, (caddr_t)&t,
					    sizeof(struct in_addr));
					bcopy((caddr_t)q, (caddr_t)p,
					    sizeof(struct in_addr));
					bcopy((caddr_t)&t, (caddr_t)q,
					    sizeof(struct in_addr));
					p--;
					q++;
				}
				cp[IPOPT_OFFSET] = IPOPT_MINOFF;
				break;
			}
		}
E 50
I 50
		int optlen = (ip->ip_hl << 2) - sizeof(struct ip);

E 52
I 52
	if (optlen > 0) {
E 52
		/*
		 * Retrieve any source routing from the incoming packet
D 52
		 * and strip out other options.  Adjust the IP
		 * and mbuf lengths.  The length of the options is added
		 * to the mbuf here, as it was already subtracted
		 * in icmp_input, and ip_stripoptions will subtract it again.
		 * Adjust the mbuf offset to point to the new location
		 * of the icmp header.
E 52
I 52
		 * and strip out other options.  Adjust the IP length.
E 52
		 */
		opts = ip_srcroute();
D 52
		m = dtom(ip);
		m->m_off -= optlen;
		m->m_len += optlen;
E 52
		ip->ip_len -= optlen;
		ip_stripoptions(ip, (struct mbuf *)0);
E 50
	}
E 48
E 14
D 2
	t = ip->ip_src.s_addr;
	ip->ip_dst.s_addr = ip->ip_src.d_addr;
	ip->ip_src.d_addr = t;
E 2
D 50
	icmp_send(ip);
E 50
I 50
	icmp_send(ip, opts);
	if (opts)
D 51
		m_free(opts);
E 51
I 51
		(void)m_free(opts);
E 51
E 50
I 48
}

struct in_ifaddr *
ifptoia(ifp)
	struct ifnet *ifp;
{
	register struct in_ifaddr *ia;

	for (ia = in_ifaddr; ia; ia = ia->ia_next)
		if (ia->ia_ifp == ifp)
			return (ia);
	return ((struct in_ifaddr *)0);
E 48
}

I 14
D 16
int	generateicmpmsgs = 0;
E 16
I 16
D 26
int	generateicmpmsgs = 1;
E 16

E 26
E 14
/*
D 14
 * Send an icmp packet back to the ip level, after
 * supplying a checksum.
E 14
I 14
 * Send an icmp packet back to the ip level,
 * after supplying a checksum.
E 14
 */
D 2
icmp_send(ip, ipc)
E 2
I 2
D 4
icmp_send(ip, icp)
E 4
I 4
D 50
icmp_send(ip)
E 4
E 2
	struct ip *ip;
E 50
I 50
icmp_send(ip, opts)
	register struct ip *ip;
	struct mbuf *opts;
E 50
D 2
	struct icmp *ipc;
E 2
I 2
D 4
	struct icmp *icp;
E 4
E 2
{
I 4
D 11
	struct icmp *icp = 0;					/* XXX */
E 11
I 8
D 14
COUNT(ICMP_SEND);
E 14
I 14
D 26
	register int hlen = ip->ip_hl << 2;
E 26
I 26
	register int hlen;
E 26
	register struct icmp *icp;
D 26
	register struct mbuf *m = dtom(ip);
E 26
I 26
	register struct mbuf *m;
E 26
E 14
E 8
E 4

D 2
	ipc->ipc_cksum = 0;
	ipc->ipc_cksum = cksum(m, impclen);
E 2
I 2
D 11
	icp->icmp_cksum = 0;
D 3
	icp->icmp_inet_cksum = cksum(dtom(ip), 0);		/* ### */
E 3
I 3
D 8
	icp->icmp_cksum = inet_cksum(dtom(ip), 0);		/* XXX */
E 8
I 8
	icp->icmp_cksum = in_cksum(dtom(ip), 0);		/* XXX */
E 8
E 3
E 2
D 7
	/* what about ttl? */
E 7
I 7
	ip->ip_ttl = MAXTTL;
E 7
D 4
	ip_output(ip);
E 4
I 4
D 8
	ip_output(dtom(ip));
E 8
I 8
D 9
	ip_output(dtom(ip), (struct mbuf *)0);
E 9
I 9
	(void) ip_output(dtom(ip), (struct mbuf *)0);
E 11
I 11
D 14
	m_freem(dtom(ip));
E 11
E 9
E 8
E 4
}

D 10
/*
 * Advise a higher level protocol of a problem reported by
 * a gateway or another host.
 */
D 4
icmp_advise(ip, icp)
E 4
I 4
icmp_ctlinput(ip)
E 4
	struct ip *ip;
E 10
I 10
icmp_ctlinput(m)
	struct mbuf *m;
E 10
D 4
	struct icmp *icp;
E 4
{
I 4
D 10
	extern u_char ip_protox[];		/* XXX */
E 10
I 8
COUNT(ICMP_CTLINPUT);
E 8
E 4
D 2
	int (*f)(), tcp_advise(), udp_advise(), raw_advise();
E 2

D 2
	switch (ip->ip_p) {
	case IPPROTO_TCP:
		f = tcp_advise;
		break;

	case IPPROTO_UDP:
		f = udp_advise;
		break;

	default:
		f = raw_advise;
		break;
	}
	(*f)(ip, icp);
E 2
I 2
D 4
	/* pass through protocol specific switch */
	/* (*f)(ip, icp); */
E 4
I 4
D 10
	(*protosw[ip_protox[ip->ip_p]].pr_ctlinput)(ip);
E 10
I 10
	m_freem(m);
E 10
E 4
E 2
}

/*
 * Got a reply, e.g. to an echo message or a timestamp
 * message; nothing is done with these yet.
 */
/*ARGSUSED*/
icmp_gotreply(icp)
	struct icmp *icp;
I 2
{

I 8
COUNT(ICMP_GOTREPLY);
E 8
}

icmp_drain()
{

I 8
COUNT(ICMP_DRAIN);
E 14
I 14
D 17
COUNT(ICMP_SEND);
E 17
D 26
	if (!generateicmpmsgs)
		return;
E 26
I 26
	m = dtom(ip);
	hlen = ip->ip_hl << 2;
I 52
	m->m_off += hlen;
	m->m_len -= hlen;
E 52
E 26
	icp = mtod(m, struct icmp *);
	icp->icmp_cksum = 0;
	icp->icmp_cksum = in_cksum(m, ip->ip_len - hlen);
	m->m_off -= hlen;
	m->m_len += hlen;
I 35
#ifdef ICMPPRINTFS
E 35
I 15
	if (icmpprintfs)
		printf("icmp_send dst %x src %x\n", ip->ip_dst, ip->ip_src);
I 35
#endif
E 35
E 15
D 21
	(void) ip_output(m, 0, 0, 0);
E 21
I 21
D 50
	(void) ip_output(m, (struct mbuf *)0, (struct route *)0, 0);
E 50
I 50
	(void) ip_output(m, opts, (struct route *)0, 0);
E 50
E 21
E 14
E 8
}

I 4
n_time
E 4
D 5
ip_time()
E 5
I 5
iptime()
E 5
E 2
{
I 4
D 49
	int s = spl6();
E 49
I 49
	struct timeval atv;
E 49
D 6
	long t;
E 6
I 6
	u_long t;
E 6
E 4

I 8
D 17
COUNT(IPTIME);
E 17
E 8
I 4
D 18
	t = (time % SECDAY) * 1000 + lbolt * hz;
E 18
I 18
D 49
	t = (time.tv_sec % (24*60*60)) * 1000 + time.tv_usec / 1000;
E 18
	splx(s);
E 49
I 49
	microtime(&atv);
	t = (atv.tv_sec % (24*60*60)) * 1000 + atv.tv_usec / 1000;
E 49
	return (htonl(t));
E 4
}
E 1
