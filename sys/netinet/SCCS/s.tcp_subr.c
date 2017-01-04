h13871
s 00010/00005/00310
d D 7.14 88/06/29 17:07:36 bostic 64 62
c install approved copyright notice
e
s 00011/00000/00315
d D 7.13.1.1 88/02/07 19:56:40 karels 63 62
c branch for FTP release (#ifdefs for non-4.3)
e
s 00008/00002/00307
d D 7.13 87/12/07 17:46:39 bostic 62 61
c use Berkeley specific header
e
s 00003/00000/00306
d D 7.12 87/10/09 16:59:29 karels 61 60
c init t_rxtcur
e
s 00002/00001/00304
d D 7.11 87/09/04 09:38:35 karels 60 59
c two-phase slow start; don't wait for mbufs from intr.
e
s 00000/00002/00305
d D 7.10 87/07/30 13:53:06 karels 59 58
c t_tcpopt is gone
e
s 00005/00005/00302
d D 7.9 87/07/03 10:52:00 karels 58 57
c typo
e
s 00005/00002/00302
d D 7.8 87/06/30 23:21:26 karels 57 56
c remove patchable keeplen, put old keepalives on opt TCP_COMPAT_42
e
s 00007/00003/00297
d D 7.7 87/06/30 23:15:37 karels 56 55
c redo retransmit calculations as srtt + 2*smoothed variance
c (from Van Jacobson)
e
s 00002/00003/00298
d D 7.6 87/06/06 20:20:40 karels 55 54
c slow-start changes from van
e
s 00005/00003/00296
d D 7.5 87/06/04 22:00:13 karels 54 53
c patchable tcp ttl
e
s 00005/00003/00294
d D 7.4 87/04/02 16:32:36 karels 53 52
c hack keepalives for now (for Ultrix, at least)
e
s 00005/00003/00292
d D 7.3 87/02/19 16:54:29 karels 52 51
c new stats; change keepalives to use rcv_nxt instead of rcv_nxt-1
c with no data (so we won't ignore the resets)
e
s 00013/00001/00282
d D 7.2 86/11/30 22:17:22 karels 51 50
c wake up sleepers when error is detected
e
s 00001/00001/00282
d D 7.1 86/06/05 00:31:51 mckusick 50 49
c 4.3BSD release version
e
s 00008/00006/00275
d D 6.8 86/03/11 12:02:58 karels 49 48
c yaml (yet another mbuf leak)
e
s 00020/00033/00261
d D 6.7 85/09/16 23:20:48 karels 48 47
c ctlinput now takes pointers to sockaddrs; don't close on all errors
e
s 00007/00001/00287
d D 6.6 85/06/08 12:44:26 mckusick 47 46
c Add copyright
e
s 00020/00008/00268
d D 6.5 85/05/27 22:32:55 karels 46 45
c remove ip_ctlinput, do all the work in higher level ctlinput's
e
s 00016/00000/00260
d D 6.4 84/11/14 10:17:22 karels 45 44
c add snd_cwndw to decrease outstanding data after a source quench
e
s 00002/00008/00258
d D 6.3 84/11/01 13:43:35 karels 44 43
c initialize t_srtt; use TCP_MSS define for default maxseg
e
s 00019/00019/00247
d D 6.2 84/08/29 15:37:58 bloom 43 42
c Include file changes.  No more ../h
e
s 00000/00000/00266
d D 6.1 83/07/29 07:12:49 sam 42 41
c 4.2 distribution
e
s 00007/00002/00259
d D 4.41 83/05/12 20:50:31 sam 41 40
c free queued segments carefully, runs at splnet, not splimp
e
s 00005/00003/00256
d D 4.40 83/02/10 22:12:39 sam 40 39
c remove /usr/include dependencies
e
s 00006/00003/00253
d D 4.39 83/01/17 18:02:59 sam 39 38
c stuff from bill to insure no references are kept to free'd cb's
e
s 00004/00004/00252
d D 4.38 83/01/04 23:18:30 sam 38 37
c clean some stuff up and purge some crud
e
s 00008/00001/00248
d D 4.37 82/12/16 12:14:34 sam 37 36
c fix default max seg size problem
e
s 00003/00003/00246
d D 4.36 82/12/14 17:17:09 sam 36 35
c typed mbufs
e
s 00002/00002/00247
d D 4.35 82/11/13 23:11:41 sam 35 34
c merge 4.1b with 4.1c
e
s 00004/00012/00245
d D 4.34 82/10/30 13:04:35 root 34 33
c get rid of conditional htons/ntohs etc
e
s 00001/00001/00256
d D 4.33 82/10/21 21:06:25 root 33 32
c lint
e
s 00003/00002/00254
d D 4.32 82/10/17 22:48:15 root 32 31
c lint
e
s 00002/00002/00254
d D 4.31 82/10/17 14:56:48 root 31 30
c fix lint
e
s 00012/00012/00244
d D 4.30 82/10/09 05:48:09 wnj 30 29
c localize header files
e
s 00000/00001/00256
d D 4.29 82/10/05 18:51:10 root 29 28
c m_get inits m_off; remove TCPTRUEOOB
e
s 00001/00001/00256
d D 4.28 82/06/26 22:03:55 sam 28 27
c use <errno.h>
e
s 00000/00008/00257
d D 4.27 82/06/20 00:56:06 sam 27 26
c purge COUNT stuff now that we can use gprof
e
s 00001/00001/00264
d D 4.26 82/04/30 12:19:22 sam 26 25
c patch constants
e
s 00024/00000/00241
d D 4.25 82/04/25 18:35:57 sam 25 24
c icmp works with tcp and friends
e
s 00009/00004/00232
d D 4.24 82/04/24 20:38:42 sam 24 23
c icmp and ctlinput working -- missing protocol specific ctlinput's
e
s 00001/00001/00235
d D 4.23 82/04/04 13:44:32 root 23 22
c fix race in tcp_close
e
s 00001/00001/00235
d D 4.22 82/04/04 13:36:26 root 22 21
c convert trailer format; fix backoff to back off more slowly 
c fix bug in raw pup: len not byte swapped
e
s 00006/00003/00230
d D 4.21 82/03/29 11:33:49 sam 21 20
c first cut (incomplete) at routing
e
s 00002/00001/00231
d D 4.20 82/03/28 14:23:51 sam 20 19
c convert interfaces to sockaddr's and add hooks for routing
e
s 00001/00001/00231
d D 4.19 82/03/24 21:56:31 root 19 18
c fix keep alives and timeouts: checksum problem and doing keeps
c on all connections by mistake (still needs more work to do keeps more 
c persistantly!)
e
s 00007/00005/00225
d D 4.18 82/03/15 04:45:18 wnj 18 17
c interfac queueing, restrictions on packets, tcp keep alives done 
c properly, bug fix to raw
e
s 00001/00001/00229
d D 4.17 82/03/13 12:53:31 sam 17 16
c lint
e
s 00001/00000/00229
d D 4.16 82/03/11 23:09:47 wnj 16 15
c minor bug fixes
e
s 00002/00002/00227
d D 4.15 82/02/15 11:33:45 root 15 14
c clean up 1's and 0's in mbuf calls
e
s 00001/00001/00228
d D 4.14 82/01/19 07:30:18 root 14 13
c m_get(0) -> m_get(M_DONTWAIT)
e
s 00001/00000/00228
d D 4.13 82/01/17 21:20:20 wnj 13 12
c more work on out-of-band
e
s 00010/00003/00218
d D 4.12 82/01/13 10:43:51 wnj 12 11
c a number of minor changes
e
s 00003/00003/00218
d D 4.11 81/12/21 11:59:18 root 11 10
c send RST on drop whenever had SYN; other check of FIN is spurious
e
s 00001/00002/00220
d D 4.10 81/12/20 15:23:05 root 10 9
c fix shutdown code
e
s 00004/00002/00218
d D 4.9 81/12/19 12:45:21 wnj 9 8
c clean up disconnect semantics
e
s 00000/00007/00220
d D 4.8 81/12/12 18:05:25 root 8 7
c clean out printf
e
s 00017/00005/00210
d D 4.7 81/12/12 12:59:12 root 7 6
c with crud (first working version)
e
s 00000/00000/00215
d D 4.6 81/12/03 17:30:27 wnj 6 5
c cleanup
e
s 00032/00010/00183
d D 4.5 81/12/02 16:59:53 wnj 5 4
c yet more lint
e
s 00002/00012/00191
d D 4.4 81/11/29 22:02:16 wnj 4 3
c lint and interface cleanups
e
s 00052/00042/00151
d D 4.3 81/11/26 11:58:02 wnj 3 2
c before carry to ARPAVAX
e
s 00094/00000/00099
d D 4.2 81/11/25 16:10:17 wnj 2 1
c listing
e
s 00099/00000/00000
d D 4.1 81/11/24 17:35:27 wnj 1 0
c date and time created 81/11/24 17:35:27 by wnj
e
u
U
f b 
t
T
I 1
D 11
/* %M% %I% %E% */
E 11
I 11
D 47
/*	%M%	%I%	%E%	*/
E 47
I 47
/*
D 50
 * Copyright (c) 1982 Regents of the University of California.
E 50
I 50
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 50
D 62
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 62
I 62
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
E 62
 *
 *	%W% (Berkeley) %G%
 */
E 47
E 11

D 43
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/mbuf.h"
#include "../h/socket.h"
#include "../h/socketvar.h"
#include "../h/protosw.h"
D 3
#include "../net/inet.h"
#include "../net/inet_pcb.h"
#include "../net/inet_systm.h"
E 3
I 3
D 30
#include "../net/in.h"
E 30
I 30
D 40
#include "../netinet/in.h"
E 40
I 40
#include "../h/errno.h"
E 43
I 43
#include "param.h"
#include "systm.h"
#include "mbuf.h"
#include "socket.h"
#include "socketvar.h"
#include "protosw.h"
#include "errno.h"
E 43

E 40
E 30
I 21
#include "../net/route.h"
I 40
#include "../net/if.h"

D 43
#include "../netinet/in.h"
E 40
E 21
D 30
#include "../net/in_pcb.h"
#include "../net/in_systm.h"
E 30
I 30
#include "../netinet/in_pcb.h"
#include "../netinet/in_systm.h"
E 30
E 3
D 40
#include "../net/if.h"
E 40
D 3
#include "../net/imp.h"
E 3
D 30
#include "../net/ip.h"
#include "../net/ip_var.h"
I 25
#include "../net/ip_icmp.h"
E 25
#include "../net/tcp.h"
D 5
#define TCPFSTAB
E 5
#include "../net/tcp_fsm.h"
I 3
#include "../net/tcp_seq.h"
#include "../net/tcp_timer.h"
E 3
#include "../net/tcp_var.h"
I 3
#include "../net/tcpip.h"
E 30
I 30
#include "../netinet/ip.h"
#include "../netinet/ip_var.h"
#include "../netinet/ip_icmp.h"
#include "../netinet/tcp.h"
#include "../netinet/tcp_fsm.h"
#include "../netinet/tcp_seq.h"
#include "../netinet/tcp_timer.h"
#include "../netinet/tcp_var.h"
#include "../netinet/tcpip.h"
E 43
I 43
#include "in.h"
#include "in_pcb.h"
#include "in_systm.h"
#include "ip.h"
#include "ip_var.h"
#include "ip_icmp.h"
#include "tcp.h"
#include "tcp_fsm.h"
#include "tcp_seq.h"
#include "tcp_timer.h"
#include "tcp_var.h"
#include "tcpip.h"
E 43
E 30
I 20
D 21
#include "../net/route.h"
E 21
E 20
E 3
D 4
#include "/usr/include/errno.h"
E 4
I 4
D 28
#include "../errno.h"
E 28
I 28
D 40
#include <errno.h>
E 40
E 28
E 4

I 54
int	tcp_ttl = TCP_TTL;
D 56
float	tcp_alpha = TCP_ALPHA;
float	tcp_beta = TCP_BETA;
E 56

E 54
/*
 * Tcp initialization
 */
tcp_init()
{

I 3
D 27
COUNT(TCP_INIT);
E 27
E 3
	tcp_iss = 1;		/* wrong */
	tcb.inp_next = tcb.inp_prev = &tcb;
I 5
D 54
	tcp_alpha = TCP_ALPHA;
	tcp_beta = TCP_BETA;
E 54
E 5
}

/*
 * Create template to be used to send tcp packets on a connection.
 * Call after host entry created, allocates an mbuf and fills
 * in a skeletal tcp/ip header, minimizing the amount of work
 * necessary when the connection is used.
 */
struct tcpiphdr *
tcp_template(tp)
	struct tcpcb *tp;
{
	register struct inpcb *inp = tp->t_inpcb;
	register struct mbuf *m;
	register struct tcpiphdr *n;

D 27
COUNT(TCP_TEMPLATE);
E 27
I 7
D 8
printf("tcp_template %x\n", tp);
E 8
E 7
D 15
	m = m_get(1);
E 15
I 15
D 36
	m = m_get(M_WAIT);
E 36
I 36
D 49
	m = m_get(M_WAIT, MT_HEADER);
E 36
E 15
D 38
	if (m == 0)
E 38
I 38
	if (m == NULL)
E 38
		return (0);
	m->m_off = MMAXOFF - sizeof (struct tcpiphdr);
	m->m_len = sizeof (struct tcpiphdr);
	n = mtod(m, struct tcpiphdr *);
E 49
I 49
	if ((n = tp->t_template) == 0) {
D 60
		m = m_get(M_WAIT, MT_HEADER);
E 60
I 60
		m = m_get(M_DONTWAIT, MT_HEADER);
E 60
		if (m == NULL)
			return (0);
		m->m_off = MMAXOFF - sizeof (struct tcpiphdr);
		m->m_len = sizeof (struct tcpiphdr);
		n = mtod(m, struct tcpiphdr *);
	}
E 49
	n->ti_next = n->ti_prev = 0;
	n->ti_x1 = 0;
	n->ti_pr = IPPROTO_TCP;
	n->ti_len = htons(sizeof (struct tcpiphdr) - sizeof (struct ip));
	n->ti_src = inp->inp_laddr;
	n->ti_dst = inp->inp_faddr;
	n->ti_sport = inp->inp_lport;
	n->ti_dport = inp->inp_fport;
	n->ti_seq = 0;
D 3
	n->ti_ackno = 0;
E 3
I 3
	n->ti_ack = 0;
E 3
	n->ti_x2 = 0;
	n->ti_off = 5;
	n->ti_flags = 0;
	n->ti_win = 0;
	n->ti_sum = 0;
	n->ti_urp = 0;
	return (n);
}

/*
D 3
 * Reflect a control message back to sender of tcp segment ti,
E 3
I 3
D 5
 * Send a reset message back to send of TCP segment ti,
E 3
 * with ack, seq and flags fields as specified by parameters.
E 5
I 5
 * Send a single message to the TCP at address specified by
 * the given TCP/IP header.  If flags==0, then we make a copy
 * of the tcpiphdr at ti and send directly to the addressed host.
 * This is used to force keep alive messages out using the TCP
 * template for a connection tp->t_template.  If flags are given
 * then we send a message back to the TCP which originated the
 * segment ti, and discard the mbuf containing it and any other
 * attached mbufs.
 *
 * In any case the ack and sequence number of the transmitted
 * segment are as specified by the parameters.
E 5
 */
D 3
tcp_reflect(ti, ack, seq, flags)
E 3
I 3
D 12
tcp_respond(ti, ack, seq, flags)
E 12
I 12
tcp_respond(tp, ti, ack, seq, flags)
	struct tcpcb *tp;
E 12
E 3
	register struct tcpiphdr *ti;
D 3
	tcpseq_t ack, seq;
E 3
I 3
	tcp_seq ack, seq;
E 3
	int flags;
{
I 3
D 5
	struct mbuf *m = dtom(ti);
E 5
I 5
D 53
	struct mbuf *m;
E 53
I 53
	register struct mbuf *m;
E 53
I 12
D 18
	int win = 0;
E 18
I 18
	int win = 0, tlen;
I 21
	struct route *ro = 0;
I 53
D 57
	extern int tcp_keeplen;
E 57
E 53
E 21
E 18
E 12
E 5
E 3

I 3
D 27
COUNT(TCP_RESPOND);
E 27
I 11
D 12
printf("tcp_respond\n");
E 12
I 12
D 21
	if (tp)
E 21
I 21
	if (tp) {
E 21
		win = sbspace(&tp->t_inpcb->inp_socket->so_rcv);
I 21
		ro = &tp->t_inpcb->inp_route;
	}
E 21
E 12
E 11
I 7
D 8
printf("tcp_respond ack %x seq %x flags %x\n", ack, seq, flags);
E 8
E 7
E 3
D 5
	m_freem(m->m_next);
	m->m_next = 0;
	m->m_len = sizeof(struct tcpiphdr);
E 5
I 5
	if (flags == 0) {
D 14
		m = m_get(0);
E 14
I 14
D 36
		m = m_get(M_DONTWAIT);
E 36
I 36
		m = m_get(M_DONTWAIT, MT_HEADER);
E 36
E 14
D 38
		if (m == 0)
E 38
I 38
		if (m == NULL)
E 38
			return;
D 29
		m->m_off = MMINOFF;
E 29
D 18
		m->m_len = sizeof (struct tcpiphdr);
E 18
I 18
D 53
		m->m_len = sizeof (struct tcpiphdr) + 1;
E 53
I 53
D 57
		tlen = tcp_keeplen;
E 57
I 57
#ifdef TCP_COMPAT_42
		tlen = 1;
#else
		tlen = 0;
#endif
E 57
		m->m_len = sizeof (struct tcpiphdr) + tlen;
E 53
E 18
		*mtod(m, struct tcpiphdr *) = *ti;
		ti = mtod(m, struct tcpiphdr *);
		flags = TH_ACK;
I 18
D 52
		tlen = 1;
E 52
E 18
	} else {
I 7
		m = dtom(ti);
E 7
		m_freem(m->m_next);
		m->m_next = 0;
I 16
		m->m_off = (int)ti - (int)m;
I 53
		tlen = 0;
E 53
E 16
		m->m_len = sizeof (struct tcpiphdr);
E 5
D 3
#define xchg(a,b) j=a; a=b; b=j
	xchg(ti->ti_dst.s_addr, ti->ti_src.s_addr);
	xchg(ti->ti_dport, ti->ti_sport);
E 3
I 3
#define xchg(a,b,type) { type t; t=a; a=b; b=t; }
D 5
	xchg(ti->ti_dst.s_addr, ti->ti_src.s_addr, u_long);
	xchg(ti->ti_dport, ti->ti_sport, u_short);
E 5
I 5
		xchg(ti->ti_dst.s_addr, ti->ti_src.s_addr, u_long);
		xchg(ti->ti_dport, ti->ti_sport, u_short);
E 5
E 3
#undef xchg
I 18
D 52
		tlen = 0;
E 52
E 18
I 5
	}
I 52
D 53
	tlen = 0;
E 53
E 52
E 5
D 3
	ti->ti_ack = htonl(ack);
E 3
I 3
	ti->ti_next = ti->ti_prev = 0;
	ti->ti_x1 = 0;
D 7
	ti->ti_len = htons(sizeof (struct tcphdr));
E 3
	ti->ti_seq = htonl(seq);
I 3
	ti->ti_ack = htonl(ack);
E 7
I 7
D 18
	ti->ti_len = sizeof (struct tcphdr);
E 18
I 18
D 34
	ti->ti_len = sizeof (struct tcphdr) + tlen;
E 18
	ti->ti_seq = seq;
	ti->ti_ack = ack;
D 31
#if vax
E 31
I 31
#if vax || pdp11 || ns16032
E 31
D 17
	ti->ti_len = htons(ti->ti_len);
E 17
I 17
	ti->ti_len = htons((u_short)ti->ti_len);
E 17
	ti->ti_seq = htonl(ti->ti_seq);
	ti->ti_ack = htonl(ti->ti_ack);
#endif
E 34
I 34
D 35
	ti->ti_len = htons(sizeof (struct tcphdr) + tlen);
E 35
I 35
	ti->ti_len = htons((u_short)(sizeof (struct tcphdr) + tlen));
E 35
	ti->ti_seq = htonl(seq);
	ti->ti_ack = htonl(ack);
E 34
E 7
	ti->ti_x2 = 0;
	ti->ti_off = sizeof (struct tcphdr) >> 2;
E 3
	ti->ti_flags = flags;
D 3

	ti->ti_len = htons(sizeof (struct tcphdr));
	ti->ti_off = 5;
	ti->ti_sum = inet_cksum(m, sizeof(struct tcpiphdr));
E 3
I 3
D 12
	ti->ti_win = ti->ti_urp = 0;
E 12
I 12
D 34
	ti->ti_win = win;
D 31
#if vax
E 31
I 31
#if vax || pdp11 || ns16032
E 31
	ti->ti_win = htons(ti->ti_win);
#endif
E 34
I 34
D 35
	ti->ti_win = htons(win);
E 35
I 35
	ti->ti_win = htons((u_short)win);
E 35
E 34
	ti->ti_urp = 0;
E 12
I 7
D 8
printf("before cksum m->m_len %d\n", m->m_len);
E 8
E 7
D 19
	ti->ti_sum = in_cksum(m, sizeof(struct tcpiphdr));
E 19
I 19
	ti->ti_sum = in_cksum(m, sizeof (struct tcpiphdr) + tlen);
E 19
E 3
D 18
	((struct ip *)ti)->ip_len = sizeof(struct tcpiphdr);
E 18
I 18
	((struct ip *)ti)->ip_len = sizeof (struct tcpiphdr) + tlen;
E 18
D 3
	((struct ip *)ti)->ip_ttl = MAXTTL;
	ip_output(m);
E 3
I 3
D 54
	((struct ip *)ti)->ip_ttl = TCP_TTL;
E 54
I 54
	((struct ip *)ti)->ip_ttl = tcp_ttl;
E 54
I 7
D 8
printf("to ip_output ip_len %d, m %x\n", ((struct ip *)ti)->ip_len, m);
E 8
E 7
D 4
	ip_output(m, (struct mbuf *)0);
E 4
I 4
D 18
	(void) ip_output(m, (struct mbuf *)0);
E 18
I 18
D 20
	(void) ip_output(m, (struct mbuf *)0, 0);
E 20
I 20
D 21
	(void) ip_output(m, (struct mbuf *)0, 0, 0);
E 21
I 21
	(void) ip_output(m, (struct mbuf *)0, ro, 0);
E 21
E 20
E 18
E 4
E 3
}
I 2

I 3
/*
 * Create a new TCP control block, making an
 * empty reassembly queue and hooking it to the argument
 * protocol control block.
 */
E 3
struct tcpcb *
tcp_newtcpcb(inp)
	struct inpcb *inp;
{
D 15
	struct mbuf *m = m_getclr(0);
E 15
I 15
D 36
	struct mbuf *m = m_getclr(M_DONTWAIT);
E 36
I 36
	struct mbuf *m = m_getclr(M_DONTWAIT, MT_PCB);
E 36
E 15
	register struct tcpcb *tp;
D 27
COUNT(TCP_NEWTCPCB);
E 27

I 7
D 8
printf("tcp_newtcpcb %x\n", inp);
E 8
E 7
D 38
	if (m == 0)
		return (0);
E 38
I 38
	if (m == NULL)
		return ((struct tcpcb *)0);
E 38
	tp = mtod(m, struct tcpcb *);
D 3

	/*
	 * Make empty reassembly queue.
	 */
E 3
	tp->seg_next = tp->seg_prev = (struct tcpiphdr *)tp;
D 3

	/*
	 * Initialize sequence numbers and round trip retransmit timer.
	 */
	tp->t_xmtime = T_REXMT;
	tp->snd_end = tp->seq_fin = tp->snd_nxt = tp->snd_hi = tp->snd_una =
	    tp->iss = tcp_iss;
	tp->snd_off = tp->iss + 1;
	tcp_iss += (ISSINCR >> 1) + 1;

	/*
	 * Hook to inpcb.
	 */
E 3
I 3
D 26
	tp->t_maxseg = 1024;
E 26
I 26
D 37
	tp->t_maxseg = 576;		/* satisfy the rest of the world */
E 37
I 37
D 44
	/*
	 * If the default maximum IP packet size is 576 bytes
	 * and a standard IP header is 20 bytes, with a TCP
	 * header of 20 bytes plus the options necessary to
	 * upgrade it to something higher, then initialize the
	 * maximum segment size to 576 - (20 + 20 + 8 + slop).
	 */
	tp->t_maxseg = 512;		/* satisfy the rest of the world */
E 44
I 44
	tp->t_maxseg = TCP_MSS;
E 44
E 37
E 26
I 13
D 22
	tp->t_flags = TF_NOOPT;		/* until all TCP's take options */
E 22
I 22
	tp->t_flags = 0;		/* sends options! */
E 22
E 13
E 3
	tp->t_inpcb = inp;
I 44
D 56
	tp->t_srtt = TCPTV_SRTTBASE;
E 56
I 56
	/*
D 58
	 * Init srtt to 0, so we can tell that we have no rtt estimate.
	 * Set rttvar so that srtt + 2 * rttvar gives reasonable initial
	 * retransmit time.
E 58
I 58
	 * Init srtt to TCPTV_SRTTBASE (0), so we can tell that we have no
	 * rtt estimate.  Set rttvar so that srtt + 2 * rttvar gives
	 * reasonable initial retransmit time.
E 58
	 */
D 58
	tp->t_srtt = 0;
	tp->t_rttvar = TCPTV_SRTTBASE << 2;
E 58
I 58
	tp->t_srtt = TCPTV_SRTTBASE;
	tp->t_rttvar = TCPTV_SRTTDFLT << 2;
I 61
	TCPT_RANGESET(tp->t_rxtcur, 
	    ((TCPTV_SRTTBASE >> 2) + (TCPTV_SRTTDFLT << 2)) >> 1,
	    TCPTV_MIN, TCPTV_REXMTMAX);
E 61
E 58
E 56
I 45
	tp->snd_cwnd = sbspace(&inp->inp_socket->so_snd);
I 60
	tp->snd_ssthresh = 65535;		/* XXX */
E 60
E 45
E 44
	inp->inp_ppcb = (caddr_t)tp;
	return (tp);
}

I 3
/*
 * Drop a TCP connection, reporting
 * the specified error.  If connection is synchronized,
 * then send a RST to peer.
 */
I 39
struct tcpcb *
E 39
E 3
tcp_drop(tp, errno)
D 39
	struct tcpcb *tp;
E 39
I 39
	register struct tcpcb *tp;
E 39
	int errno;
{
	struct socket *so = tp->t_inpcb->inp_socket;

D 27
COUNT(TCP_DROP);
E 27
I 7
D 8
printf("tcp_drop %x %d\n", tp, errno);
E 8
E 7
D 11
	if (TCPS_HAVERCVDSYN(tp->t_state) &&
D 3
	    TCPS_OURFINISACKED(tp->t_state) == 0) {
E 3
I 3
	    TCPS_OURFINNOTACKED(tp->t_state)) {
E 11
I 11
	if (TCPS_HAVERCVDSYN(tp->t_state)) {
E 11
E 3
		tp->t_state = TCPS_CLOSED;
D 33
		tcp_output(tp);
E 33
I 33
		(void) tcp_output(tp);
E 33
D 52
	}
E 52
I 52
		tcpstat.tcps_drops++;
	} else
		tcpstat.tcps_conndrops++;
E 52
	so->so_error = errno;
D 3
	socantrcvmore(so);
	socantsndmore(so);
E 3
D 39
	tcp_close(tp);
E 39
I 39
	return (tcp_close(tp));
E 39
I 5
D 10
	in_pcbdetach(tp->t_inpcb);
E 10
E 5
}

I 24
D 48
tcp_abort(inp)
	struct inpcb *inp;
{
D 32
	tcp_close(inp->inp_ppcb);
E 32
I 32

D 39
	tcp_close((struct tcpcb *)inp->inp_ppcb);
E 39
I 39
	(void) tcp_close((struct tcpcb *)inp->inp_ppcb);
E 39
E 32
}

E 48
E 24
I 3
/*
 * Close a TCP control block:
 *	discard all space held by the tcp
 *	discard internet protocol block
 *	wake up any sleepers
 */
I 39
struct tcpcb *
E 39
E 3
tcp_close(tp)
	register struct tcpcb *tp;
{
	register struct tcpiphdr *t;
I 3
D 9
	struct socket *so = tp->t_inpcb->inp_socket;
E 9
I 9
	struct inpcb *inp = tp->t_inpcb;
	struct socket *so = inp->inp_socket;
I 41
	register struct mbuf *m;
E 41
E 9
E 3

D 27
COUNT(TCP_CLOSE);
E 27
I 7
D 8
printf("tcp_close %x\n", tp);
E 8
E 7
D 3
	tcp_canceltimers(tp);
E 3
	t = tp->seg_next;
D 41
	for (; t != (struct tcpiphdr *)tp; t = (struct tcpiphdr *)t->ti_next)
		m_freem(dtom(t));
E 41
I 41
	while (t != (struct tcpiphdr *)tp) {
		t = (struct tcpiphdr *)t->ti_next;
		m = dtom(t->ti_prev);
		remque(t->ti_prev);
		m_freem(m);
	}
E 41
D 3
	if (tp->t_template) {
E 3
I 3
	if (tp->t_template)
E 3
		(void) m_free(dtom(tp->t_template));
D 3
		tp->t_template = 0;
	}
E 3
I 3
D 59
	if (tp->t_tcpopt)
		(void) m_free(dtom(tp->t_tcpopt));
E 59
D 48
	if (tp->t_ipopt)
		(void) m_free(dtom(tp->t_ipopt));
E 48
E 3
D 5
	in_pcbfree(tp->t_inpcb);
E 5
	(void) m_free(dtom(tp));
I 9
	inp->inp_ppcb = 0;
D 10
	in_pcbdisconnect(inp);
E 10
I 10
D 23
	in_pcbdetach(inp);
E 23
E 10
E 9
I 3
D 7
	socantrcvmore(so);
	socantsendmore(so);
E 7
I 7
	soisdisconnected(so);
I 23
	in_pcbdetach(inp);
I 52
	tcpstat.tcps_closed++;
E 52
I 39
	return ((struct tcpcb *)0);
E 39
E 23
E 7
I 5
D 9
	in_pcbdisconnect(tp->t_inpcb);
E 9
E 5
E 3
}

D 4
/*ARGSUSED*/
tcp_sense(m)
	struct mbuf *m;
{

COUNT(TCP_SENSE);
	return (EOPNOTSUPP);
}

E 4
tcp_drain()
{
D 4
	register struct inpcb *ip;
E 4

D 27
COUNT(TCP_DRAIN);
E 27
}

I 51
/*
 * Notify a tcp user of an asynchronous error;
 * just wake up so that he can collect error status.
 */
tcp_notify(inp)
	register struct inpcb *inp;
{

	wakeup((caddr_t) &inp->inp_socket->so_timeo);
	sorwakeup(inp->inp_socket);
	sowwakeup(inp->inp_socket);
}
E 51
D 24
tcp_ctlinput(m)
	struct mbuf *m;
E 24
I 24
D 48
tcp_ctlinput(cmd, arg)
E 48
I 48
tcp_ctlinput(cmd, sa)
E 48
	int cmd;
D 48
	caddr_t arg;
E 48
I 48
	struct sockaddr *sa;
E 48
E 24
{
I 25
D 46
	struct in_addr *sin;
E 46
I 46
D 48
	struct in_addr *in;
E 48
E 46
	extern u_char inetctlerrmap[];
I 48
	struct sockaddr_in *sin;
E 48
I 45
D 46
	int tcp_quench();
E 46
I 46
	int tcp_quench(), in_rtchange();
E 46
E 45
E 25
D 24

E 24
D 27
COUNT(TCP_CTLINPUT);
E 27
I 25

D 48
	if (cmd < 0 || cmd > PRC_NCMDS)
E 48
I 48
	if ((unsigned)cmd > PRC_NCMDS)
E 48
		return;
I 48
	if (sa->sa_family != AF_INET && sa->sa_family != AF_IMPLINK)
		return;
	sin = (struct sockaddr_in *)sa;
	if (sin->sin_addr.s_addr == INADDR_ANY)
		return;

E 48
	switch (cmd) {

D 48
	case PRC_ROUTEDEAD:
		break;

E 48
	case PRC_QUENCH:
I 45
D 46
		sin = &((struct icmp *)arg)->icmp_ip.ip_dst;
		in_pcbnotify(&tcb, sin, 0, tcp_quench);
E 46
I 46
D 48
		in = &((struct icmp *)arg)->icmp_ip.ip_dst;
		in_pcbnotify(&tcb, in, 0, tcp_quench);
E 48
I 48
		in_pcbnotify(&tcb, &sin->sin_addr, 0, tcp_quench);
E 48
E 46
E 45
		break;

I 48
	case PRC_ROUTEDEAD:
E 48
D 46
	/* these are handled by ip */
E 46
I 46
	case PRC_REDIRECT_NET:
	case PRC_REDIRECT_HOST:
D 48
		in = &((struct icmp *)arg)->icmp_ip.ip_dst;
		in_pcbnotify(&tcb, in, 0, in_rtchange);
E 48
I 48
	case PRC_REDIRECT_TOSNET:
	case PRC_REDIRECT_TOSHOST:
I 63
#if BSD>=43
E 63
		in_pcbnotify(&tcb, &sin->sin_addr, 0, in_rtchange);
I 63
#endif
E 63
E 48
		break;

E 46
D 48
	case PRC_IFDOWN:
I 46
		in = &((struct sockaddr_in *)arg)->sin_addr;
		goto notify;

E 46
	case PRC_HOSTDEAD:
	case PRC_HOSTUNREACH:
D 46
		break;
E 46
I 46
		in = (struct in_addr *)arg;
		goto notify;
E 46

E 48
	default:
D 46
		sin = &((struct icmp *)arg)->icmp_ip.ip_dst;
D 32
		in_pcbnotify(&tcb, sin, inetctlerrmap[cmd], tcp_abort);
E 32
I 32
		in_pcbnotify(&tcb, sin, (int)inetctlerrmap[cmd], tcp_abort);
E 46
I 46
		if (inetctlerrmap[cmd] == 0)
			return;		/* XXX */
D 48
		in = &((struct icmp *)arg)->icmp_ip.ip_dst;
notify:
		in_pcbnotify(&tcb, in, (int)inetctlerrmap[cmd], tcp_abort);
E 48
I 48
		in_pcbnotify(&tcb, &sin->sin_addr, (int)inetctlerrmap[cmd],
D 51
			(int (*)())0);
E 51
I 51
			tcp_notify);
E 51
E 48
E 46
E 32
	}
I 45
}
I 63

#if BSD<43
/* XXX fake routine */
tcp_abort(inp)
	struct inpcb *inp;
{
	return;
}
#endif
E 63

/*
 * When a source quench is received, close congestion window
D 55
 * to 80% of the outstanding data (but not less than one segment).
E 55
I 55
 * to one segment.  We will gradually open it again as we proceed.
E 55
 */
tcp_quench(inp)
	struct inpcb *inp;
{
	struct tcpcb *tp = intotcpcb(inp);

D 48
	tp->snd_cwnd = MAX(8 * (tp->snd_nxt - tp->snd_una) / 10, tp->t_maxseg);
E 48
I 48
	if (tp)
D 55
	    tp->snd_cwnd = MAX(8 * (tp->snd_nxt - tp->snd_una) / 10,
		tp->t_maxseg);
E 55
I 55
		tp->snd_cwnd = tp->t_maxseg;
E 55
E 48
E 45
E 25
D 24
	m_freem(m);
E 24
}
E 2
E 1
