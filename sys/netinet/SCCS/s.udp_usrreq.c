h50137
s 00010/00005/00394
d D 7.7 88/06/29 17:07:55 bostic 83 82
c install approved copyright notice
e
s 00002/00002/00397
d D 7.6 88/05/26 09:38:29 karels 82 81
c lint
e
s 00001/00001/00398
d D 7.5 88/03/11 10:37:15 karels 81 80
c don't assume two's complement (good luck, Louis!)
e
s 00008/00002/00391
d D 7.4 87/12/07 17:47:10 bostic 80 79
c use Berkeley specific header
e
s 00001/00002/00392
d D 7.3 87/07/02 17:21:48 karels 79 78
c one sofree ought to do it, and don't mark socket disconnected
c just after sofree'ing it (just in case)
e
s 00002/00001/00392
d D 7.2 87/06/04 22:03:47 karels 78 77
c add patchable udp ttl
e
s 00001/00001/00392
d D 7.1 86/06/05 00:33:46 mckusick 77 76
c 4.3BSD release version
e
s 00013/00001/00380
d D 6.21 86/02/25 21:54:00 karels 76 75
c wake him up if we're talking to him
e
s 00001/00005/00380
d D 6.20 86/02/24 21:23:28 karels 75 74
c bug: don't soisdisconnected on datagram sockets, want to reconnect
e
s 00005/00000/00380
d D 6.19 86/02/08 15:30:38 karels 74 73
c ifdefs for 4.2 compat
e
s 00001/00001/00379
d D 6.18 86/02/05 16:52:02 karels 73 72
c smaller TTL
e
s 00003/00023/00377
d D 6.17 86/02/03 20:10:33 karels 72 71
c consolidate route caching, manipulation in IP
e
s 00004/00002/00396
d D 6.16 86/02/02 18:25:42 karels 71 70
c add arg to icmp_error (incoming interface of offending packet;
c to make source address of redirects correct)
e
s 00026/00031/00372
d D 6.15 85/09/16 23:31:32 karels 70 69
c save copy of ip header of received packet, in case want to error;
c don't toss socket on error; ctlinput takes a sockaddr; allow IP options
c on output
e
s 00007/00001/00396
d D 6.14 85/06/08 12:46:36 mckusick 69 68
c Add copyright
e
s 00016/00006/00381
d D 6.13 85/05/28 08:29:05 karels 68 66
c remove ip_ctlinput, do all the work in higher level ctlinput's
e
s 00016/00006/00381
d R 6.13 85/05/27 22:33:03 karels 67 66
c remove ip_ctlinput, do all the work in higher level ctlinput's
e
s 00004/00005/00383
d D 6.12 85/05/27 20:37:52 karels 66 65
c broadcast recognition is different now; use MGET macro; small simplifications
e
s 00005/00002/00383
d D 6.11 85/04/29 18:03:34 karels 65 63
c turn on checksum checking; don't calculate checksum on output
c if not checking on input
e
s 00005/00002/00383
d R 6.11 85/04/29 10:42:54 karels 64 63
c turn on checksum checking; don't calculate checksum on output
c if not checking on input
e
s 00008/00003/00377
d D 6.10 85/03/18 15:24:28 karels 63 62
c in_control gets PRU_CONTROLS; bigger TCP send/recv buffers,
c bigger UDP recv buffers
e
s 00021/00021/00359
d D 6.9 84/09/05 17:24:21 karels 62 61
c add SO_BROADCAST
e
s 00021/00020/00359
d D 6.8 84/09/04 21:48:52 sam 61 60
c allow broadcasts based on SO_BROADCAST; this permits unpriviledged 
c users to send broadcast messages so long as they specify ahead of time their 
c intent
e
s 00017/00017/00362
d D 6.7 84/08/29 15:38:38 bloom 60 59
c Include file changes.  No more ../h
e
s 00007/00001/00372
d D 6.6 84/08/21 10:22:10 karels 59 58
c add sostat
e
s 00016/00013/00357
d D 6.5 84/07/31 18:03:12 karels 58 57
c block input while doing temporary connect;
c don't free mbuf on rcvoob (done later); allow broadcasts without routing
e
s 00019/00003/00351
d D 6.4 84/06/22 22:12:21 sam 57 56
c cache routes on send
e
s 00005/00004/00349
d D 6.3 83/11/14 13:20:02 karels 56 54
c shorten mbuf on end if longer than udp length (not beginning);
c don't check checksums on input if checksum is 0;
c on output, checksum of 0 becomes -1
e
s 00004/00001/00352
d R 6.3 83/11/06 18:28:42 sam 55 54
c more udp checksum problems (from rws@mit)
e
s 00003/00003/00350
d D 6.2 83/10/13 14:26:32 sam 54 52
c must byte swap ip overlay header's length field before checksum;
e
s 00002/00002/00351
d R 6.2 83/10/06 11:20:24 sam 53 52
c must byte swap length field in ip overlay header before checksum; 
c from cak@purdue
e
s 00000/00000/00353
d D 6.1 83/07/29 07:13:27 sam 52 51
c 4.2 distribution
e
s 00004/00000/00349
d D 4.51 83/07/25 21:55:51 sam 51 50
c getpeer
e
s 00014/00005/00335
d D 4.50 83/06/14 22:11:18 sam 50 49
c socketpair
e
s 00003/00001/00337
d D 4.49 83/06/12 19:49:01 sam 49 48
c revamp network ioctls
e
s 00008/00004/00330
d D 4.48 83/05/27 13:47:27 sam 48 47
c merge wnj changes plus lint
e
s 00003/00003/00331
d D 4.47 83/05/12 15:04:55 sam 47 46
c fix ip packet forwarding to not stomp on headers when fragmented;
e
s 00013/00005/00321
d D 4.46 83/05/03 17:23:05 sam 46 45
c random stuff
e
s 00036/00016/00290
d D 4.45 83/02/16 18:21:09 sam 45 44
c fix dropping mbufs
e
s 00004/00002/00302
d D 4.44 83/02/10 22:13:19 sam 44 43
c remove /usr/include dependencies
e
s 00001/00002/00303
d D 4.43 83/01/13 18:32:13 sam 43 42
c nor more opt parameter to usrreq
e
s 00006/00011/00299
d D 4.42 83/01/04 23:18:45 sam 42 41
c clean some stuff up and purge some crud
e
s 00001/00001/00309
d D 4.41 82/12/14 17:17:16 sam 41 40
c typed mbufs
e
s 00001/00001/00309
d D 4.40 82/11/03 01:09:09 root 40 39
c misc 4.1c fixes
e
s 00001/00001/00309
d D 4.39 82/10/22 00:02:58 root 39 38
c lint
e
s 00001/00001/00309
d D 4.38 82/10/21 21:06:39 root 38 37
c lint
e
s 00001/00001/00309
d D 4.37 82/10/20 01:24:01 root 37 36
c lint
e
s 00001/00001/00309
d D 4.36 82/10/17 22:48:49 root 36 35
c lint
e
s 00003/00001/00307
d D 4.35 82/10/17 14:57:17 root 35 34
c fix lint
e
s 00002/00000/00306
d D 4.34 82/10/16 17:44:45 root 34 33
c insert SBCHECK calls looking for panic:receive problem
e
s 00008/00008/00298
d D 4.33 82/10/09 05:49:57 wnj 33 32
c localize header files
e
s 00023/00011/00283
d D 4.32 82/09/26 18:30:41 root 32 31
c first working version
e
s 00008/00013/00286
d D 4.31 82/08/22 21:21:15 root 31 30
c protocol bug
e
s 00000/00005/00299
d D 4.30 82/06/20 00:56:38 sam 30 29
c purge COUNT stuff now that we can use gprof
e
s 00009/00003/00295
d D 4.29 82/06/12 23:20:26 wnj 29 28
c now the routing code might wokr
e
s 00031/00009/00267
d D 4.28 82/04/25 18:36:04 sam 28 27
c icmp works with tcp and friends
e
s 00023/00005/00253
d D 4.27 82/04/24 20:38:48 sam 27 26
c icmp and ctlinput working -- missing protocol specific ctlinput's
e
s 00004/00001/00254
d D 4.26 82/04/10 23:42:33 sam 26 25
c purge so_addr from socket structure and start cleaning up raw code
e
s 00015/00017/00240
d D 4.25 82/04/10 18:27:33 sam 25 24
c invert output path to pass back error indications
e
s 00001/00001/00256
d D 4.24 82/03/29 11:34:21 sam 24 23
c first cut (incomplete) at routing
e
s 00002/00001/00255
d D 4.23 82/03/28 14:24:00 sam 23 22
c convert interfaces to sockaddr's and add hooks for routing
e
s 00002/00001/00254
d D 4.22 82/03/15 04:45:31 wnj 22 21
c interfac queueing, restrictions on packets, tcp keep alives done 
c properly, bug fix to raw
e
s 00003/00001/00252
d D 4.21 82/03/03 11:07:23 root 21 20
c wildcard addresses
e
s 00011/00004/00242
d D 4.20 82/02/27 17:48:02 wnj 20 19
c multi-homing and wildcards
e
s 00001/00001/00245
d D 4.19 82/01/19 07:30:23 root 19 18
c m_get(0) -> m_get(M_DONTWAIT)
e
s 00003/00003/00243
d D 4.18 81/12/23 14:05:34 root 18 17
c new m_pullup (returning m)
e
s 00007/00009/00239
d D 4.17 81/12/12 12:59:45 root 17 16
c with crud (first working version)
e
s 00002/00014/00246
d D 4.16 81/12/09 20:51:29 wnj 16 15
c remove crud
e
s 00017/00007/00243
d D 4.15 81/12/09 20:46:03 wnj 15 14
c with crud
e
s 00000/00010/00250
d D 4.14 81/12/03 17:30:46 wnj 14 13
c cleanup
e
s 00007/00007/00253
d D 4.13 81/12/02 17:00:40 wnj 13 12
c yet more lint
e
s 00001/00001/00259
d D 4.12 81/11/29 22:03:49 wnj 12 11
c lint and interface cleanups
e
s 00012/00006/00248
d D 4.11 81/11/26 11:58:55 wnj 11 10
c before carry to ARPAVAX
e
s 00000/00001/00254
d D 4.10 81/11/24 07:54:30 wnj 10 9
c minor fixups pre tcp<->spec coordination
e
s 00006/00031/00249
d D 4.9 81/11/23 00:11:41 wnj 9 8
c cleanup
e
s 00050/00020/00230
d D 4.8 81/11/23 00:09:35 wnj 8 7
c many fixups (and crud) to first working version
e
s 00030/00031/00220
d D 4.7 81/11/20 00:47:53 wnj 7 6
c linted
e
s 00122/00039/00129
d D 4.6 81/11/18 15:38:44 wnj 6 5
c more cleanup
e
s 00020/00012/00148
d D 4.5 81/11/16 14:18:26 wnj 5 4
c more lint
e
s 00032/00008/00128
d D 4.4 81/11/15 13:01:05 wnj 4 3
c listing
e
s 00072/00013/00064
d D 4.3 81/11/14 16:41:14 wnj 3 2
c before overlay
e
s 00015/00004/00062
d D 4.2 81/11/08 16:27:20 wnj 2 1
c first listing
e
s 00066/00000/00000
d D 4.1 81/11/07 17:55:05 wnj 1 0
c date and time created 81/11/07 17:55:05 by wnj
e
u
U
t
T
I 1
D 2
/* %M% %I% %E% */
E 2
I 2
D 31
/*	%M%	%I%	%E%	*/
E 31
I 31
D 32
/*	udp_usrreq.c	4.31	82/08/15	*/
E 32
I 32
D 69
/*	%M%	%I%	%E%	*/
E 69
I 69
/*
D 77
 * Copyright (c) 1982 Regents of the University of California.
E 77
I 77
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 77
D 80
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 80
I 80
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 83
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 83
I 83
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
E 83
E 80
 *
 *	%W% (Berkeley) %G%
 */
E 69
E 32
E 31
E 2

D 60
#include "../h/param.h"
I 3
#include "../h/dir.h"
#include "../h/user.h"
E 3
#include "../h/mbuf.h"
I 8
D 10
#define	PRUREQUESTS
E 10
E 8
D 2
#include "../inet/inet.h"
#include "../inet/inet_systm.h"
#include "../inet/udp.h"
E 2
I 2
#include "../h/protosw.h"
I 3
#include "../h/socket.h"
#include "../h/socketvar.h"
I 5
D 6
#include "../h/inaddr.h"
E 6
E 5
E 3
D 11
#include "../net/inet.h"
I 3
D 7
#include "../net/inet_host.h"
E 7
#include "../net/inet_pcb.h"
E 3
#include "../net/inet_systm.h"
E 11
I 11
D 33
#include "../net/in.h"
E 33
I 33
D 44
#include "../netinet/in.h"
E 44
I 44
#include "../h/errno.h"
I 59
#include "../h/stat.h"
E 60
I 60
#include "param.h"
#include "dir.h"
#include "user.h"
#include "mbuf.h"
#include "protosw.h"
#include "socket.h"
#include "socketvar.h"
#include "errno.h"
#include "stat.h"
E 60
E 59

E 44
E 33
I 27
#include "../net/if.h"
E 27
I 24
#include "../net/route.h"
I 44

D 60
#include "../netinet/in.h"
E 44
E 24
D 33
#include "../net/in_pcb.h"
#include "../net/in_systm.h"
E 11
I 4
#include "../net/ip.h"
#include "../net/ip_var.h"
I 27
#include "../net/ip_icmp.h"
E 27
E 4
I 3
#include "../net/udp.h"
#include "../net/udp_var.h"
E 33
I 33
#include "../netinet/in_pcb.h"
#include "../netinet/in_systm.h"
#include "../netinet/ip.h"
#include "../netinet/ip_var.h"
#include "../netinet/ip_icmp.h"
#include "../netinet/udp.h"
#include "../netinet/udp_var.h"
E 60
I 60
#include "in.h"
#include "in_pcb.h"
#include "in_systm.h"
#include "ip.h"
#include "ip_var.h"
#include "ip_icmp.h"
#include "udp.h"
#include "udp_var.h"
E 60
E 33
I 25
D 44
#include <errno.h>
E 44
E 25
I 23
D 24
#include "../net/route.h"
E 24
E 23
E 3
E 2

I 6
/*
 * UDP protocol implementation.
 * Per RFC 768, August, 1980.
 */
E 6
I 2
udp_init()
{

I 11
D 30
COUNT(UDP_INIT);
E 30
E 11
I 3
D 4
	udb.inp_next = udb.inp_prev = &udp;
E 4
I 4
	udb.inp_next = udb.inp_prev = &udb;
E 4
E 3
}

I 74
#ifndef	COMPAT_42
E 74
I 4
D 54
int	udpcksum;
E 54
I 54
D 56
int	udpcksum = 1;
E 56
I 56
D 65
int	udpcksum = 0;
E 65
I 65
int	udpcksum = 1;
I 74
#else
int	udpcksum = 0;		/* XXX */
#endif
I 78
int	udp_ttl = UDP_TTL;
E 78

E 74
E 65
E 56
E 54
I 6
struct	sockaddr_in udp_in = { AF_INET };
E 6

E 4
E 2
D 6
udp_input(m)
	struct mbuf *m;
E 6
I 6
D 71
udp_input(m0)
E 71
I 71
udp_input(m0, ifp)
E 71
	struct mbuf *m0;
I 71
	struct ifnet *ifp;
E 71
E 6
{
I 4
	register struct udpiphdr *ui;
E 4
I 3
	register struct inpcb *inp;
D 4
	int raddr, rport;
	int addr, port;
E 4
I 4
D 5
	u_short lport, fport;
	int ulen;
E 5
I 5
D 6
	u_short lport, fport, ulen;
E 6
I 6
	register struct mbuf *m;
D 31
	int len, ulen;
E 31
I 31
	int len;
I 70
	struct ip ip;
E 70
E 31
E 6
E 5
E 4
E 3

I 11
D 30
COUNT(UDP_INPUT);
E 30
E 11
I 6
	/*
D 17
	 * Get ip and udp header together in first mbuf.
E 17
I 17
	 * Get IP and UDP header together in first mbuf.
E 17
	 */
I 8
D 9
	printf("udp_input: ");
E 9
E 8
	m = m0;
E 6
I 3
D 4
	inp = inpcb_lookup(&udb, addr, port);
E 4
I 4
D 8
	ui = mtod(m, struct udpiphdr *);
D 6
	if (ui->ui_len > sizeof (struct ip))		/* XXX */
E 6
I 6
	if (ui->ui_len > sizeof (struct ip))
E 6
D 7
		ip_stripoptions((struct ip *)ui);
E 7
I 7
		ip_stripoptions((struct ip *)ui, (char *)0);
E 8
E 7
D 6
	ulen = ((struct ip *)ui)->ip_len;
	ui->ui_len = htons(ulen);
	ui->ui_prev = ui->ui_next = 0;
	ui->ui_x1 = 0;
	lport = ntohs(ui->ui_dport);
	fport = ntohs(ui->ui_sport);
	if (sizeof (struct udpiphdr) > m->m_len)
	    { printf("udp header overflow\n"); m_freem(m); return; }
E 6
I 6
D 18
	if (m->m_len < sizeof (struct udpiphdr) &&
	    m_pullup(m, sizeof (struct udpiphdr)) == 0) {
E 18
I 18
	if ((m->m_off > MMAXOFF || m->m_len < sizeof (struct udpiphdr)) &&
	    (m = m_pullup(m, sizeof (struct udpiphdr))) == 0) {
E 18
		udpstat.udps_hdrops++;
I 8
D 9
		printf("hdrop m_len %d\n", m->m_len);
E 9
E 8
D 18
		goto bad;
E 18
I 18
		return;
E 18
	}
I 8
	ui = mtod(m, struct udpiphdr *);
D 17
	if (ui->ui_len > sizeof (struct ip))
E 17
I 17
	if (((struct ip *)ui)->ip_hl > (sizeof (struct ip) >> 2))
E 17
D 15
		ip_stripoptions((struct ip *)ui, (char *)0);
E 15
I 15
		ip_stripoptions((struct ip *)ui, (struct mbuf *)0);
E 15
E 8

	/*
D 17
	 * Make mbuf data length reflect udp length.
	 * If not enough data to reflect udp length, drop.
E 17
I 17
	 * Make mbuf data length reflect UDP length.
	 * If not enough data to reflect UDP length, drop.
E 17
	 */
D 7
	ulen = ntohs(ui->ui_ulen);
E 7
I 7
D 31
	ulen = ntohs((u_short)ui->ui_ulen);
E 7
D 15
	len = sizeof (struct udpiphdr) + ulen;
E 15
I 15
	len = sizeof (struct udphdr) + ulen;
E 31
I 31
	len = ntohs((u_short)ui->ui_ulen);
E 31
D 16
printf("len %d, ulen %d, ((struct ip *)ui)->ip_len %d\n",
    len, ulen, ((struct ip *)ui)->ip_len);
E 16
E 15
I 8
D 9
	printf("ulen %d, len %d\n", ulen, len);
E 9
E 8
	if (((struct ip *)ui)->ip_len != len) {
		if (len > ((struct ip *)ui)->ip_len) {
I 8
D 9
			printf("udp badlen\n");
E 9
E 8
			udpstat.udps_badlen++;
			goto bad;
		}
D 56
		m_adj(m, ((struct ip *)ui)->ip_len - len);
E 56
I 56
		m_adj(m, len - ((struct ip *)ui)->ip_len);
E 56
D 70
		/* (struct ip *)ui->ip_len = len; */
E 70
I 70
		/* ((struct ip *)ui)->ip_len = len; */
E 70
	}
I 70
	/*
	 * Save a copy of the IP header in case we want restore it for ICMP.
	 */
	ip = *(struct ip*)ui;
E 70

	/*
D 17
	 * Checksum extended udp header and data.
E 17
I 17
	 * Checksum extended UDP header and data.
E 17
	 */
E 6
D 56
	if (udpcksum) {
E 56
I 56
	if (udpcksum && ui->ui_sum) {
E 56
D 5
		inet_cksum(m, sizeof (struct ip) + ulen);
E 5
I 5
D 6
		(void) inet_cksum(m, sizeof (struct ip) + ulen);
E 5
		if (ui->ui_sum) {
E 6
I 6
		ui->ui_next = ui->ui_prev = 0;
		ui->ui_x1 = 0;
D 7
		ui->ui_len = htons(sizeof (struct udpiphdr) + ulen);
E 7
I 7
D 15
		ui->ui_len = htons((u_short)(sizeof (struct udpiphdr) + ulen));
E 7
D 8
		if (ui->ui_sum = inet_cksum(m, len)) {
E 8
I 8
D 11
		if ((ui->ui_sum = inet_cksum(m, len)) != 0xffff) {
E 11
I 11
		if ((ui->ui_sum = in_cksum(m, len)) != 0xffff) {
E 15
I 15
D 31
		ui->ui_len = htons((u_short)(sizeof (struct udphdr) + ulen));
		if (ui->ui_sum = in_cksum(m, len)) {
E 31
I 31
D 66
		ui->ui_len = htons((u_short)len);
E 66
I 66
		ui->ui_len = ui->ui_ulen;
E 66
		if (ui->ui_sum = in_cksum(m, len + sizeof (struct ip))) {
E 31
E 15
E 11
E 8
			udpstat.udps_badsum++;
E 6
D 46
			printf("udp cksum %x\n", ui->ui_sum);
E 46
			m_freem(m);
			return;
		}
	}
D 5
	inp = inpcb_lookup(&ui->ui_src, fport, &ui->ui_dst, lport);
E 5
I 5
D 6
	inp = in_pcblookup(&udb, &ui->ui_src, fport, &ui->ui_dst, lport);
E 6
I 6

	/*
D 15
	 * Convert addresses and ports to host format.
E 15
D 20
	 * Locate pcb for datagram.
E 20
I 20
D 31
	 * Locate pcb for datagram.  On wildcard match, update
	 * control block to anchor network and host address.
E 31
I 31
	 * Locate pcb for datagram.
E 31
E 20
	 */
D 8
	ui->ui_src.s_addr = ntohl(ui->ui_src.s_addr);
	ui->ui_dst.s_addr = ntohl(ui->ui_dst.s_addr);
	ui->ui_sport = ntohs(ui->ui_sport);
	ui->ui_dport = ntohs(ui->ui_dport);
E 8
I 8
D 9
	printf("src %x dst %x sport %x dport %x\n",
	    ui->ui_src.s_addr, ui->ui_dst.s_addr, ui->ui_sport, ui->ui_dport);
E 9
E 8
	inp = in_pcblookup(&udb,
D 20
	    ui->ui_src, ui->ui_sport, ui->ui_dst, ui->ui_dport);
E 20
I 20
D 21
	    ui->ui_src, ui->ui_sport, ui->ui_dst, ui->ui_dport, 1);
E 21
I 21
	    ui->ui_src, ui->ui_sport, ui->ui_dst, ui->ui_dport,
		INPLOOKUP_WILDCARD);
E 21
E 20
E 6
E 5
E 4
D 8
	if (inp == 0)
E 8
I 8
D 9
	if (inp == 0) {
		printf("pcb not found\n");
E 9
I 9
D 27
	if (inp == 0)
E 9
E 8
D 4
		goto bad;
	/* sostuff(inp->inp_socket, m, raddr, rport); */
E 4
I 4
D 6
		goto notwanted;
	/* stuff on queue using some subroutine */
E 6
I 6
		goto bad;
E 27
I 27
	if (inp == 0) {
D 42
		struct in_addr broadcastaddr;
E 27
I 8
D 9
	}
E 9
E 8

I 27
D 35
		broadcastaddr = if_makeaddr(ui->ui_dst.s_net, INADDR_ANY);
E 35
I 35
		broadcastaddr =
D 37
		    if_makeaddr(in_netof(ui->ui_dst.s_net), INADDR_ANY);
E 37
I 37
D 38
		    if_makeaddr(in_netof((int)ui->ui_dst.s_net), INADDR_ANY);
E 38
I 38
D 39
		    if_makeaddr(in_netof(ui->ui_dst.s_net), INADDR_ANY);
E 39
I 39
		    if_makeaddr(in_netof(ui->ui_dst), INADDR_ANY);
E 39
E 38
E 37
E 35
D 28
		if (ui->ui_dst.s_addr != broadcastaddr.s_addr)
E 28
I 28
		if (ui->ui_dst.s_addr == broadcastaddr.s_addr)
E 42
I 42
		/* don't send ICMP response for broadcast packet */
D 66
		if (in_lnaof(ui->ui_dst) == INADDR_ANY)
E 66
I 66
		if (in_broadcast(ui->ui_dst))
E 66
E 42
E 28
			goto bad;
I 70
		*(struct ip *)ui = ip;
E 70
D 71
		icmp_error((struct ip *)ui, ICMP_UNREACH, ICMP_UNREACH_PORT);
E 71
I 71
		icmp_error((struct ip *)ui, ICMP_UNREACH, ICMP_UNREACH_PORT,
		    ifp);
E 71
		return;
	}

E 27
	/*
	 * Construct sockaddr format source address.
	 * Stuff source address and datagram in user buffer.
	 */
	udp_in.sin_port = ui->ui_sport;
	udp_in.sin_addr = ui->ui_src;
D 7
	if (sbappendaddr(inp->inp_socket, &udp_in, m) == 0)
E 7
I 7
D 8
	if (sbappendaddr(&inp->inp_socket->so_snd, (struct sockaddr *)&udp_in, m) == 0)
E 8
I 8
	m->m_len -= sizeof (struct udpiphdr);
	m->m_off += sizeof (struct udpiphdr);
I 34
D 42
SBCHECK(&inp->inp_socket->so_rcv, "udpinput before");
E 42
E 34
I 15
D 16
printf("sbappendaddr called with m %x m->m_len %d m->m_off %d\n",
m, m->m_len, m->m_off);
printf("*mtod(m, char *) %x\n", *mtod(m, char *));
E 16
E 15
D 48
	if (sbappendaddr(&inp->inp_socket->so_rcv, (struct sockaddr *)&udp_in, m) == 0)
E 48
I 48
	if (sbappendaddr(&inp->inp_socket->so_rcv, (struct sockaddr *)&udp_in,
	    m, (struct mbuf *)0) == 0)
E 48
E 8
E 7
		goto bad;
I 34
D 42
SBCHECK(&inp->inp_socket->so_rcv, "udpinput after");
E 42
E 34
I 8
	sorwakeup(inp->inp_socket);
E 8
E 6
E 4
	return;
D 4
bad:
E 4
I 4
D 6
notwanted:
E 6
I 6
bad:
E 6
E 4
	m_freem(m);
D 6
	/* gen icmp? */
E 6
E 3
}

I 76
/*
 * Notify a udp user of an asynchronous error;
 * just wake up so that he can collect error status.
 */
udp_notify(inp)
	register struct inpcb *inp;
{

	sorwakeup(inp->inp_socket);
	sowwakeup(inp->inp_socket);
}

E 76
I 3
D 27
udp_ctlinput(m)
	struct mbuf *m;
E 27
I 27
D 28
udp_ctlinput(cmd, arg)
	int cmd;
	caddr_t arg;
E 27
{

I 11
COUNT(UDP_CTLINPUT);
E 11
I 8
D 16
	printf("udp_ctlinput\n");
E 16
E 8
D 27
	m_freem(m);
E 27
I 27
}

E 28
D 70
udp_abort(inp)
	struct inpcb *inp;
{
	struct socket *so = inp->inp_socket;

	in_pcbdisconnect(inp);
	soisdisconnected(so);
I 28
}

udp_ctlinput(cmd, arg)
E 70
I 70
udp_ctlinput(cmd, sa)
E 70
	int cmd;
D 70
	caddr_t arg;
E 70
I 70
	struct sockaddr *sa;
E 70
{
D 68
	struct in_addr *sin;
E 68
I 68
D 70
	struct in_addr *in;
E 70
E 68
	extern u_char inetctlerrmap[];
I 70
	struct sockaddr_in *sin;
E 70
I 68
	int in_rtchange();
E 68
D 30
COUNT(UDP_CTLINPUT);
E 30

D 70
	if (cmd < 0 || cmd > PRC_NCMDS)
E 70
I 70
	if ((unsigned)cmd > PRC_NCMDS)
E 70
		return;
I 70
	if (sa->sa_family != AF_INET && sa->sa_family != AF_IMPLINK)
		return;
	sin = (struct sockaddr_in *)sa;
	if (sin->sin_addr.s_addr == INADDR_ANY)
		return;

E 70
	switch (cmd) {

D 70
	case PRC_ROUTEDEAD:
E 70
I 70
	case PRC_QUENCH:
E 70
		break;

I 70
	case PRC_ROUTEDEAD:
E 70
D 68
	case PRC_QUENCH:
E 68
I 68
	case PRC_REDIRECT_NET:
	case PRC_REDIRECT_HOST:
D 70
		in = &((struct icmp *)arg)->icmp_ip.ip_dst;
		in_pcbnotify(&udb, in, 0, in_rtchange);
E 70
I 70
	case PRC_REDIRECT_TOSNET:
	case PRC_REDIRECT_TOSHOST:
		in_pcbnotify(&udb, &sin->sin_addr, 0, in_rtchange);
E 70
E 68
		break;

D 68
	/* these are handled by ip */
E 68
D 70
	case PRC_IFDOWN:
I 68
		in = &((struct sockaddr_in *)arg)->sin_addr;
		goto notify;

E 68
	case PRC_HOSTDEAD:
	case PRC_HOSTUNREACH:
D 68
		break;
E 68
I 68
		in = (struct in_addr *)arg;
		goto notify;
E 68

E 70
	default:
D 68
		sin = &((struct icmp *)arg)->icmp_ip.ip_dst;
D 36
		in_pcbnotify(&udb, sin, inetctlerrmap[cmd], udp_abort);
E 36
I 36
		in_pcbnotify(&udb, sin, (int)inetctlerrmap[cmd], udp_abort);
E 68
I 68
		if (inetctlerrmap[cmd] == 0)
			return;		/* XXX */
D 70
		in = &((struct icmp *)arg)->icmp_ip.ip_dst;
notify:
		in_pcbnotify(&udb, in, (int)inetctlerrmap[cmd], udp_abort);
E 70
I 70
		in_pcbnotify(&udb, &sin->sin_addr, (int)inetctlerrmap[cmd],
D 76
			(int (*)())0);
E 76
I 76
			udp_notify);
E 76
E 70
E 68
E 36
	}
E 28
E 27
}

E 3
D 5
udp_advise(m)
E 5
I 5
D 6
udp_ctlinput(m)
E 5
	struct mbuf *m;
E 6
I 6
D 17
/*ARGSUSED*/
E 17
D 7
udp_output(inp, raddr, rport, m0)
E 7
I 7
udp_output(inp, m0)
E 7
D 72
	struct inpcb *inp;
E 72
I 72
	register struct inpcb *inp;
E 72
D 7
	struct in_addr *raddr;
	u_short rport;
E 7
	struct mbuf *m0;
E 6
{
I 6
	register struct mbuf *m;
	register struct udpiphdr *ui;
I 29
D 61
	register struct socket *so;
E 29
	register int len = 0;
E 61
I 61
D 62
	register int len;
E 62
I 62
D 72
	register struct socket *so;
E 72
	register int len = 0;
E 62
E 61
I 47
D 57
	int flags;
E 57
I 57
D 72
	register struct route *ro;
E 72
I 61
D 62
	int opts;
E 62
E 61
E 57
E 47
E 6

I 11
D 30
COUNT(UDP_OUTPUT);
E 30
E 11
D 6
	m_freem(m);
}
E 6
I 6
	/*
	 * Calculate data length and get a mbuf
D 17
	 * for udp and ip headers.
E 17
I 17
	 * for UDP and IP headers.
E 17
	 */
I 61
D 62
	len = 0;
E 62
E 61
	for (m = m0; m; m = m->m_next)
		len += m->m_len;
I 8
D 9
	printf("udp_output len %d: ", len);
E 9
E 8
D 19
	m = m_get(0);
E 19
I 19
D 41
	m = m_get(M_DONTWAIT);
E 41
I 41
D 66
	m = m_get(M_DONTWAIT, MT_HEADER);
E 66
I 66
	MGET(m, M_DONTWAIT, MT_HEADER);
E 66
E 41
E 19
D 8
	if (m == 0)
E 8
I 8
D 9
	if (m == 0) {
		printf("no mbufs\n");
E 9
I 9
D 25
	if (m == 0)
E 9
E 8
		goto bad;
E 25
I 25
	if (m == 0) {
		m_freem(m0);
		return (ENOBUFS);
	}
E 25
I 8
D 9
	}
E 9
E 8
E 6

I 5
D 6
/*ARGSUSED*/
E 5
D 3
udp_output(xx, m)
E 3
I 3
udp_output(raddr, rport, m)
	int raddr, rport;
E 3
	struct mbuf *m;
{
E 6
I 6
	/*
D 17
	 * Fill in mbuf with extended udp header
E 17
I 17
	 * Fill in mbuf with extended UDP header
E 17
	 * and addresses and length put into network format.
	 */
	m->m_off = MMAXOFF - sizeof (struct udpiphdr);
	m->m_len = sizeof (struct udpiphdr);
	m->m_next = m0;
	ui = mtod(m, struct udpiphdr *);
	ui->ui_next = ui->ui_prev = 0;
	ui->ui_x1 = 0;
	ui->ui_pr = IPPROTO_UDP;
D 7
	ui->ui_len = htons(sizeof (struct udphdr) + len);
	ui->ui_src.s_addr = htonl(inp->inp_lhost);
	ui->ui_dst.s_addr = htonl(raddr->s_addr);
E 7
I 7
D 8
	ui->ui_len = htons((u_short)(sizeof (struct udphdr) + len));
	ui->ui_src.s_addr = htonl(inp->inp_laddr.s_addr);
	ui->ui_dst.s_addr = htonl(inp->inp_faddr.s_addr);
E 7
	ui->ui_sport = htons(inp->inp_lport);
	ui->ui_dport = htons(inp->inp_fport);
E 8
I 8
D 31
	ui->ui_len = sizeof (struct udpiphdr) + len;
E 31
I 31
D 54
	ui->ui_len = len + sizeof (struct udphdr);
E 54
I 54
	ui->ui_len = htons((u_short)len + sizeof (struct udphdr));
E 54
E 31
	ui->ui_src = inp->inp_laddr;
	ui->ui_dst = inp->inp_faddr;
	ui->ui_sport = inp->inp_lport;
	ui->ui_dport = inp->inp_fport;
E 8
D 7
	ui->ui_ulen = htons(len);
E 7
I 7
D 29
	ui->ui_ulen = htons((u_short)len);
E 29
I 29
D 31
	ui->ui_ulen = len;
#if vax
	ui->ui_ulen = htons(ui->ui_ulen);
#endif
E 31
I 31
D 54
	ui->ui_ulen = htons((u_short)ui->ui_len);
E 54
I 54
	ui->ui_ulen = ui->ui_len;
E 54
E 31
E 29
I 8
D 9
	printf("src %x dst %x sport %x dport %x",
	    ui->ui_src.s_addr, ui->ui_dst.s_addr, ui->ui_sport, ui->ui_dport);
E 9
E 8
E 7
E 6

I 3
D 6
	/* setup header */
E 6
I 6
	/*
	 * Stuff checksum and output datagram.
	 */
	ui->ui_sum = 0;
D 11
	ui->ui_sum = inet_cksum(m, sizeof (struct udpiphdr) + len);
E 11
I 11
D 56
	ui->ui_sum = in_cksum(m, sizeof (struct udpiphdr) + len);
E 56
I 56
D 65
	if ((ui->ui_sum = in_cksum(m, sizeof (struct udpiphdr) + len)) == 0)
E 65
I 65
	if (udpcksum) {
	    if ((ui->ui_sum = in_cksum(m, sizeof (struct udpiphdr) + len)) == 0)
E 65
D 81
		ui->ui_sum = -1;
E 81
I 81
		ui->ui_sum = 0xffff;
E 81
I 65
D 66
	} else
		ui->ui_sum = 0;
E 66
I 66
	}
E 66
E 65
E 56
E 11
I 8
D 9
	printf(" cksum %x\n", ui->ui_sum);
E 9
	((struct ip *)ui)->ip_len = sizeof (struct udpiphdr) + len;
D 73
	((struct ip *)ui)->ip_ttl = MAXTTL;
E 73
I 73
D 78
	((struct ip *)ui)->ip_ttl = UDP_TTL;
E 78
I 78
	((struct ip *)ui)->ip_ttl = udp_ttl;
E 78
E 73
E 8
E 6
D 11
	ip_output(m);
E 11
I 11
D 12
	ip_output(m, (struct mbuf *)0);
E 12
I 12
D 22
	(void) ip_output(m, (struct mbuf *)0);
E 22
I 22
D 23
	(void) ip_output(m, (struct mbuf *)0,
E 23
I 23
D 25
	(void) ip_output(m, (struct mbuf *)0, 0,
E 23
	    inp->inp_socket->so_state & SS_PRIV);
E 22
E 12
E 11
I 6
	return;
bad:
	m_freem(m);
E 25
I 25
D 29
	return (ip_output(m, (struct mbuf *)0, 0,
	    inp->inp_socket->so_state & SS_PRIV));
E 29
I 29
D 61
	so = inp->inp_socket;
D 47
	return (ip_output(m, (struct mbuf *)0,
	    (so->so_options & SO_DONTROUTE) ? &routetoif : (struct route *)0,
	    so->so_state & SS_PRIV));
E 47
I 47
D 57
	flags = (so->so_options & SO_DONTROUTE) | (so->so_state & SS_PRIV);
	return (ip_output(m, (struct mbuf *)0, (struct route *)0, flags));
E 57
I 57
	if (so->so_options & SO_DONTROUTE)
		return (ip_output(m, (struct mbuf *)0, (struct route *)0,
D 58
		    IP_ROUTETOIF));
E 58
I 58
		    (so->so_state & SS_PRIV) | IP_ROUTETOIF));
E 58
	/*
	 * Use cached route for previous datagram if
	 * this is also to the same destination. 
	 *
	 * NB: We don't handle broadcasts because that
	 *     would require 3 subroutine calls.
	 */
	ro = &inp->inp_route;
E 61
I 61
D 62
	opts = inp->inp_socket->so_options & (SO_DONTROUTE|SO_BROADCAST);
	if ((opts & SO_DONTROUTE) == 0) {
		/*
		 * Use cached route from previous datagram if
		 * this is also to the same destination. 
		 *
		 * NB: We don't handle broadcasts because that
		 *     would require 3 subroutine calls.
		 */
		ro = &inp->inp_route;
E 62
I 62
D 72
	so = inp->inp_socket;
	if (so->so_options & SO_DONTROUTE)
D 70
		return (ip_output(m, (struct mbuf *)0, (struct route *)0,
E 70
I 70
		return (ip_output(m, inp->inp_options, (struct route *)0,
E 70
		    (so->so_options & SO_BROADCAST) | IP_ROUTETOIF));
	/*
	 * Use cached route for previous datagram if
	 * this is also to the same destination. 
	 *
	 * NB: We don't handle broadcasts because that
	 *     would require 3 subroutine calls.
	 */
	ro = &inp->inp_route;
E 62
E 61
#define	satosin(sa)	((struct sockaddr_in *)(sa))
D 61
	if (ro->ro_rt &&
	    satosin(&ro->ro_dst)->sin_addr.s_addr != ui->ui_dst.s_addr) {
		RTFREE(ro->ro_rt);
		ro->ro_rt = (struct rtentry *)0;
	}
	return (ip_output(m, (struct mbuf *)0, ro, so->so_state & SS_PRIV));
E 61
I 61
D 62
		if (ro->ro_rt &&
		   satosin(&ro->ro_dst)->sin_addr.s_addr != ui->ui_dst.s_addr) {
			RTFREE(ro->ro_rt);
			ro->ro_rt = (struct rtentry *)0;
		}
	} else
		ro = (struct route *)0;
	return (ip_output(m, (struct mbuf *)0, ro, opts));
E 62
I 62
	if (ro->ro_rt &&
	    satosin(&ro->ro_dst)->sin_addr.s_addr != ui->ui_dst.s_addr) {
		RTFREE(ro->ro_rt);
		ro->ro_rt = (struct rtentry *)0;
	}
D 70
	return (ip_output(m, (struct mbuf *)0, ro, 
E 70
I 70
	return (ip_output(m, inp->inp_options, ro, 
E 70
	    so->so_options & SO_BROADCAST));
E 72
I 72
	return (ip_output(m, inp->inp_options, &inp->inp_route,
	    inp->inp_socket->so_options & (SO_DONTROUTE | SO_BROADCAST)));
E 72
E 62
E 61
E 57
E 47
E 29
E 25
E 6
E 3
}

I 63
D 82
int	udp_sendspace = 2048;		/* really max datagram size */
int	udp_recvspace = 4 * (1024+sizeof(struct sockaddr_in)); /* 4 1K dgrams */
E 82
I 82
u_long	udp_sendspace = 2048;		/* really max datagram size */
u_long	udp_recvspace = 4 * (1024+sizeof(struct sockaddr_in)); /* 4 1K dgrams */
E 82

E 63
I 35
/*ARGSUSED*/
E 35
I 5
D 17
/*ARGSUSED*/
E 17
E 5
D 3
udp_usrreq(up, req, m, addr)
	struct socket *up;
E 3
I 3
D 32
udp_usrreq(so, req, m, addr)
E 32
I 32
D 43
udp_usrreq(so, req, m, nam, opt)
E 43
I 43
D 48
udp_usrreq(so, req, m, nam)
E 48
I 48
udp_usrreq(so, req, m, nam, rights)
E 48
E 43
E 32
	struct socket *so;
E 3
	int req;
D 32
	struct mbuf *m;
D 5
	struct in_addr *addr;
E 5
I 5
	caddr_t addr;
E 32
I 32
D 48
	struct mbuf *m, *nam;
E 48
I 48
	struct mbuf *m, *nam, *rights;
E 48
D 43
	struct socketopt *opt;
E 43
E 32
E 5
{
I 3
	struct inpcb *inp = sotoinpcb(so);
I 6
D 7
	struct sockaddr_in *sin;
E 7
E 6
D 25
	int error;
E 25
I 25
	int error = 0;
E 25
E 3

I 63
	if (req == PRU_CONTROL)
		return (in_control(so, (int)m, (caddr_t)nam,
			(struct ifnet *)rights));
E 63
I 48
	if (rights && rights->m_len) {
		error = EINVAL;
		goto release;
	}
E 48
I 11
D 30
COUNT(UDP_USRREQ);
E 30
E 11
I 8
D 9
	printf("udp_usrreq %x %s\n", inp, prurequests[req]);
	if (inp == 0 && req != PRU_ATTACH) {
		printf("inp == 0 not on ATTACH\n");
E 9
I 9
D 45
	if (inp == 0 && req != PRU_ATTACH)
E 9
		return (EINVAL);
E 45
I 45
	if (inp == NULL && req != PRU_ATTACH) {
		error = EINVAL;
		goto release;
	}
E 45
I 15
D 16
printf("udp_usrreq %d\n", req);
E 16
E 15
D 9
	}
E 9
E 8
	switch (req) {

	case PRU_ATTACH:
I 3
D 45
		if (inp != 0)
			return (EINVAL);
E 45
I 45
		if (inp != NULL) {
			error = EINVAL;
			break;
		}
E 45
D 4
		inp = in_pcballoc();
E 4
I 4
D 5
		inp = inpcb_alloc();
E 5
I 5
D 7
		inp = in_pcballoc();
E 5
E 4
		if (inp == NULL)
			return (ENOBUFS);
E 7
I 7
D 13
		error = in_pcballoc(so, &udb, 2048, 2048, (struct sockaddr_in *)addr);
E 13
I 13
D 25
		error = in_pcbattach(so, &udb, 2048, 2048, (struct sockaddr_in *)addr);
E 13
D 8
		if (error)
E 8
I 8
D 9
		if (error) {
			printf("in_pcballoc failed %d\n", error);
E 9
I 9
		if (error)
E 9
E 8
			return (error);
E 25
I 25
D 32
		error = in_pcbattach(so, &udb, 2048, 2048,
				(struct sockaddr_in *)addr);
E 32
I 32
		error = in_pcballoc(so, &udb);
		if (error)
			break;
D 40
		error = in_pcbreserve(so, 2048, 2048);
E 40
I 40
D 63
		error = soreserve(so, 2048, 2048);
E 63
I 63
		error = soreserve(so, udp_sendspace, udp_recvspace);
E 63
E 40
		if (error)
			break;
E 32
E 25
E 7
D 8
		so->so_pcb = (caddr_t)inp;
E 8
I 8
D 9
		}
E 9
E 8
		break;
E 3

	case PRU_DETACH:
I 3
D 45
		if (inp == 0)
			return (ENOTCONN);
E 45
I 45
D 75
		if (inp == NULL) {
			error = ENOTCONN;
			break;
		}
E 75
E 45
D 5
		sofree(inp->inp_socket);
		udp_detach(inp);
E 5
I 5
D 13
		in_pcbfree(inp);
E 13
I 13
		in_pcbdetach(inp);
E 13
E 5
		break;
E 3

I 32
	case PRU_BIND:
		error = in_pcbbind(inp, nam);
		break;

	case PRU_LISTEN:
		error = EOPNOTSUPP;
		break;

E 32
	case PRU_CONNECT:
I 3
D 7
		if (inp->inp_fhost)
E 7
I 7
D 42
		if (inp->inp_faddr.s_addr)
E 42
I 42
D 45
		if (inp->inp_faddr.s_addr != INADDR_ANY)
E 42
E 7
			return (EISCONN);
E 45
I 45
		if (inp->inp_faddr.s_addr != INADDR_ANY) {
			error = EISCONN;
			break;
		}
E 45
D 5
		inp->inp_fhost = in_hmake((struct in_addr *)addr, &error);
E 5
I 5
D 6
		inp->inp_fhost = in_hosteval((struct inaddr *)addr, &error);
E 6
I 6
D 7
		in_hosteval(inp, (struct sockaddr *)addr, &error);
E 6
E 5
		if (inp->inp_fhost == 0)
E 7
I 7
D 13
		error = in_pcbsetpeer(inp, (struct sockaddr_in *)addr);
E 13
I 13
D 32
		error = in_pcbconnect(inp, (struct sockaddr_in *)addr);
E 32
I 32
		error = in_pcbconnect(inp, nam);
E 32
E 13
D 8
		if (error)
E 8
I 8
D 9
		if (error) {
			printf("in_pcbsetpeer failed %d\n", error);
E 9
I 9
D 25
		if (error)
E 9
E 8
E 7
			return (error);
I 8
D 9
		}
E 9
E 8
		soisconnected(so);
E 25
I 25
		if (error == 0)
			soisconnected(so);
E 25
		break;
E 3

I 50
	case PRU_CONNECT2:
		error = EOPNOTSUPP;
		break;

E 50
I 6
	case PRU_ACCEPT:
D 45
		return (EOPNOTSUPP);
E 45
I 45
		error = EOPNOTSUPP;
		break;
E 45

E 6
	case PRU_DISCONNECT:
D 3

	case PRU_ISCONN:

	case PRU_ISDISCONN:
E 3
I 3
D 7
		if (inp->inp_fhost == 0)
E 7
I 7
D 42
		if (inp->inp_faddr.s_addr == 0)
E 42
I 42
D 45
		if (inp->inp_faddr.s_addr == INADDR_ANY)
E 42
E 7
			return (ENOTCONN);
E 45
I 45
		if (inp->inp_faddr.s_addr == INADDR_ANY) {
			error = ENOTCONN;
			break;
		}
E 45
D 5
		h_free(inp->inp_fhost);
E 5
I 5
D 7
		in_hostfree(inp->inp_fhost);
E 5
		inp->inp_fhost = 0;
E 7
I 7
D 13
		inp->inp_faddr.s_addr = 0;
E 13
I 13
		in_pcbdisconnect(inp);
E 13
E 7
D 75
		soisdisconnected(so);
E 75
I 75
		so->so_state &= ~SS_ISCONNECTED;		/* XXX */
E 75
E 3
		break;

I 5
D 6
	case PRU_FLUSH:
		return (EOPNOTSUPP);

E 6
	case PRU_SHUTDOWN:
		socantsendmore(so);
		break;

E 5
D 3
	case PRU_RCVD:
		break;

E 3
D 20
	case PRU_SEND:
E 20
I 20
	case PRU_SEND: {
		struct in_addr laddr;
I 58
		int s;
E 58

E 20
D 3
		udp_output(0, m);
E 3
I 3
D 6
#if 0
E 6
D 32
		if (addr) {
E 32
I 32
		if (nam) {
E 32
I 20
			laddr = inp->inp_laddr;
E 20
D 7
			if (inp->inp_fhost)
E 7
I 7
D 15
			if (inp->inp_faddr.s_addr)
E 15
I 15
D 16
			if (inp->inp_faddr.s_addr) {
				printf("EISCONN\n");
E 16
I 16
D 42
			if (inp->inp_faddr.s_addr)
E 42
I 42
D 45
			if (inp->inp_faddr.s_addr != INADDR_ANY)
E 42
E 16
E 15
E 7
				return (EISCONN);
E 45
I 45
			if (inp->inp_faddr.s_addr != INADDR_ANY) {
				error = EISCONN;
				break;
			}
I 58
			/*
			 * Must block input while temporarily connected.
			 */
			s = splnet();
E 58
E 45
I 15
D 16
			}
E 16
E 15
D 6
			udp_output(addr->in_fhost, addr->in_fport, m);
E 6
I 6
D 7
			sin = (struct sockaddr_in *)addr;
			if (sin->sin_family != AF_INET)
				return (EAFNOSUPPORT);
			udp_output(inp, sin->sin_addr, sin->sin_port, m);
E 6
		} else
D 5
			udp_output(inp->inp_fhost->h_addr, ip->inp_fport, m);
E 5
D 6
#endif
I 5
			udp_output(inp->inp_fhost->h_addr, ip->inp_fport, m);
E 6
I 6
			udp_output(inp,
			    inp->inp_fhost->h_addr, inp->inp_fport, m);
E 7
I 7
D 13
			error = in_pcbsetpeer(inp, (struct sockaddr_in *)addr);
E 13
I 13
D 32
			error = in_pcbconnect(inp, (struct sockaddr_in *)addr);
E 32
I 32
			error = in_pcbconnect(inp, nam);
E 32
E 13
D 8
			if (error)
E 8
I 8
D 9
			if (error) {
				printf("send setpeer failed %d\n", error);
E 9
I 9
D 15
			if (error)
E 15
I 15
D 16
			if (error) {
				printf("pcbconnect error %d\n", error);
E 16
I 16
D 58
			if (error)
E 58
I 58
			if (error) {
				splx(s);
E 58
E 16
E 15
E 9
E 8
D 25
				return (error);
E 25
I 25
				break;
I 58
			}
E 58
E 25
I 15
D 16
			}
E 16
E 15
I 8
D 9
			}
E 9
E 8
		} else {
D 42
			if (inp->inp_faddr.s_addr == 0)
E 42
I 42
D 45
			if (inp->inp_faddr.s_addr == INADDR_ANY)
E 42
				return (ENOTCONN);
E 45
I 45
			if (inp->inp_faddr.s_addr == INADDR_ANY) {
				error = ENOTCONN;
				break;
			}
E 45
		}
I 15
D 16
printf("to udp_output\n");
E 16
E 15
I 8
D 9
		printf("udp send m %x m_len %d * %c (%o)\n",
		    m, m->m_len, *(mtod(m, caddr_t)), *(mtod(m, caddr_t)));
E 9
E 8
D 25
		udp_output(inp, m);
E 25
I 25
		error = udp_output(inp, m);
I 45
		m = NULL;
E 45
E 25
D 20
		if (addr)
E 20
I 20
D 32
		if (addr) {
E 32
I 32
		if (nam) {
E 32
E 20
D 13
			inp->inp_faddr.s_addr = 0;
E 13
I 13
			in_pcbdisconnect(inp);
I 58
D 63
			splx(s);
E 63
E 58
I 20
			inp->inp_laddr = laddr;
I 63
			splx(s);
E 63
I 21
D 26
			in_setsockaddr(inp);
E 26
E 21
		}
		}
E 20
E 13
E 7
E 6
E 5
E 3
		break;

	case PRU_ABORT:
D 3
	case PRU_CLEAR:
E 3
I 3
D 13
		in_pcbfree(inp);
E 13
I 13
D 79
		in_pcbdetach(inp);
E 13
		sofree(so);
E 79
		soisdisconnected(so);
I 79
		in_pcbdetach(inp);
E 79
E 3
		break;

D 46
	case PRU_CONTROL:
D 3
		break;
E 3
I 3
D 45
		return (EOPNOTSUPP);
E 45
I 45
		error =  EOPNOTSUPP;
		break;
E 45
I 26

E 46
	case PRU_SOCKADDR:
D 32
		in_setsockaddr((struct sockaddr_in *)addr, inp);
E 32
I 32
		in_setsockaddr(inp, nam);
E 32
		break;
E 26
E 3

I 51
	case PRU_PEERADDR:
		in_setpeeraddr(inp, nam);
		break;

I 59
	case PRU_SENSE:
		/*
		 * stat: don't bother with a blocksize.
		 */
		return (0);

E 59
E 51
D 50
	default:
I 46
		printf("request %d\n", req);
E 46
D 48
		panic("udp_usrreq");
E 48
I 46

E 50
D 49
	case PRU_RCVD:
E 49
D 58
	case PRU_CONTROL:
I 49
D 50
		return (EOPNOTSUPP);
E 50
I 50
		m = NULL;
		error = EOPNOTSUPP;
		break;
E 50

D 50
	case PRU_RCVD:
E 50
E 49
	case PRU_SENSE:
I 50
		m = NULL;
		/* fall thru... */

	case PRU_RCVD:
E 50
	case PRU_RCVOOB:
E 58
	case PRU_SENDOOB:
	case PRU_FASTTIMO:
	case PRU_SLOWTIMO:
	case PRU_PROTORCV:
	case PRU_PROTOSEND:
		error =  EOPNOTSUPP;
		break;
I 58

D 63
	case PRU_CONTROL:
E 63
D 59
	case PRU_SENSE:
E 59
	case PRU_RCVD:
	case PRU_RCVOOB:
		return (EOPNOTSUPP);	/* do not free mbuf's */
E 58
I 50

	default:
		panic("udp_usrreq");
E 50
E 46
I 2
	}
I 45
release:
	if (m != NULL)
		m_freem(m);
E 45
I 3
D 25
	return (0);
E 25
I 25
	return (error);
E 25
E 3
}
D 14

I 7
/*ARGSUSED*/
E 7
D 6
udp_sense()
E 6
I 6
udp_sense(m)
	struct mbuf *m;
E 6
{
I 6
D 7
	return (EOPNOTSUPP);
E 7
E 6

I 11
COUNT(UDP_SENSE);
E 11
I 8
	printf("udp_sense\n");
E 8
I 7
	return (EOPNOTSUPP);
E 7
E 2
}
E 14
E 1
