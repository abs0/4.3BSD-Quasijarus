h16474
s 00000/00000/00405
d D 7.4.1.1 87/03/20 10:22:48 karels 80 79
x 78
c fix from 7.4 for diffing/patching against 7.2
e
s 00001/00002/00423
d D 7.4 87/03/20 10:13:38 karels 79 78
c don't slide data back if resending data+FIN
e
s 00020/00001/00405
d D 7.3 87/02/19 17:01:11 karels 78 77
c new stats
e
s 00002/00002/00404
d D 7.2 86/08/20 09:31:16 karels 77 76
c don't send premature FIN
e
s 00001/00001/00405
d D 7.1 86/06/05 00:31:17 mckusick 76 75
c 4.3BSD release version
e
s 00039/00019/00367
d D 6.18 86/04/13 21:43:30 karels 75 74
c more correct fix for TCP FIN seq problem: need to predecrement send_nxt
c when resending FIN (for ack, etc.) but not retransmitting
e
s 00011/00010/00375
d D 6.17 86/04/12 13:42:40 karels 74 73
c conservative fix for increasing FIN
e
s 00031/00019/00354
d D 6.16 86/03/12 18:36:56 karels 73 71
c change fix to handle shrinking windows (previous was too far down);
c reorder for convenience and put common case earliest; fix comments
c (STILL CONTAINS DEBUG CODE logging persists at offset)
e
s 00031/00021/00352
d R 6.16 86/03/12 11:07:32 karels 72 71
c change fix to handle shrinking windows (previous was too far down);
c reorder for convenience and put common case earliest; fix comments
c (STILL CONTAINS DEBUG CODE logging persists at offset)
e
s 00003/00004/00370
d D 6.15 86/03/03 11:26:57 karels 71 70
c one more time: don't clear persist on an ack-only packet
e
s 00002/00002/00372
d D 6.14 86/02/23 23:26:09 karels 70 69
c lint
e
s 00002/00007/00372
d D 6.13 86/02/03 20:10:21 karels 69 68
c consolidate route caching, manipulation in IP
e
s 00056/00047/00323
d D 6.12 86/01/22 09:28:50 karels 68 67
c don't delay send if we have more than one segment to send,
c but last is fractional; count the registers and reorder the tests;
c more window anti-shrink code; sundry cleanups
e
s 00004/00000/00366
d D 6.11 85/10/23 18:21:45 karels 67 66
c maintain estimates of peer's send and receive buffer sizes;
c don't wait for bigger window if he hasn't got one
e
s 00004/00002/00362
d D 6.10 85/09/16 23:19:44 karels 66 65
c ip options move to inpcb
e
s 00007/00001/00357
d D 6.9 85/06/08 12:43:45 mckusick 65 64
c Add copyright
e
s 00033/00016/00325
d D 6.8 85/05/27 22:27:13 karels 64 63
c make persist do sensible things if window is small, but nonzero
e
s 00006/00005/00335
d D 6.7 84/11/14 10:20:03 karels 63 62
c add snd_cwndw to decrease outstanding data after a source quench;
c fix retransmission change (1 seg when timer goes off,
c then back to normal after an ack)
e
s 00010/00005/00330
d D 6.6 84/11/01 13:48:11 karels 62 61
c send only one segment when retransmitting; don't send more small
c packets if any are unacknowledged (per jbn/RFC 896)
e
s 00006/00002/00329
d D 6.5 84/10/19 15:04:07 karels 61 60
c bind local address according to routing (caching the route);
c pick maximum seg sizes (offered and accepted) based on interface mtu,
c with default if not local
e
s 00000/00001/00331
d D 6.4 84/10/18 11:09:28 karels 60 59
c fix round-trip timing: rexmt timer shouldn't screw rtt up,
c but careful when retransmitting timed segment
e
s 00019/00019/00313
d D 6.3 84/08/29 15:37:44 bloom 59 58
c Include file changes.  No more ../h
e
s 00009/00009/00323
d D 6.2 83/11/04 20:39:37 sam 58 57
c logic bug, from rws@mit
e
s 00000/00000/00332
d D 6.1 83/07/29 07:12:37 sam 57 56
c 4.2 distribution
e
s 00002/00001/00330
d D 4.55 83/05/27 13:46:41 sam 56 55
c lint
e
s 00000/00003/00331
d D 4.54 83/05/12 20:51:08 sam 55 54
c proper fix applied, get rid of this kludge
e
s 00007/00002/00327
d D 4.53 83/05/12 15:04:30 sam 54 53
c fix ip packet forwarding to not stomp on headers when fragmented;
e
s 00002/00002/00327
d D 4.52 83/03/25 11:43:52 sam 53 52
c tag mbuf properly; bogus change from before
e
s 00004/00002/00325
d D 4.51 83/02/10 22:12:25 sam 52 51
c remove /usr/include dependencies
e
s 00002/00004/00325
d D 4.50 83/01/04 23:18:16 sam 51 50
c clean some stuff up and purge some crud
e
s 00002/00002/00327
d D 4.49 82/12/14 17:16:51 sam 50 49
c typed mbufs
e
s 00000/00012/00329
d D 4.48 82/10/30 13:04:20 root 49 48
c get rid of conditional htons/ntohs etc
e
s 00005/00005/00336
d D 4.47 82/10/17 14:56:34 root 48 47
c fix lint
e
s 00012/00012/00329
d D 4.46 82/10/09 05:47:48 wnj 47 46
c localize header files
e
s 00003/00047/00338
d D 4.45 82/10/05 18:50:48 root 46 45
c m_get inits m_off; remove TCPTRUEOOB
e
s 00000/00001/00385
d D 4.44 82/08/02 08:56:33 feldman 45 44
c remove irrelevant comment
e
s 00008/00001/00378
d D 4.43 82/08/02 00:07:04 root 44 43
c changes for UNIX ipc domain and for PUSH set when possible
e
s 00000/00001/00379
d D 4.42 82/06/20 00:55:52 sam 43 42
c purge COUNT stuff now that we can use gprof
e
s 00005/00002/00375
d D 4.41 82/06/12 23:15:46 wnj 42 41
c advance snd_max even when persisting
e
s 00005/00005/00372
d D 4.40 82/06/11 08:25:27 wnj 41 40
c first attempts at fixing persist
e
s 00086/00036/00291
d D 4.39 82/06/08 10:38:47 wnj 40 38
c fixes to persist timer handling
e
s 00068/00029/00298
d R 4.39 82/06/06 21:16:20 wnj 39 38
c fixes to persist timer
e
s 00008/00008/00319
d D 4.38 82/04/10 18:26:54 sam 38 37
c invert output path to pass back error indications
e
s 00002/00002/00325
d D 4.37 82/03/29 11:33:35 sam 37 36
c first cut (incomplete) at routing
e
s 00002/00001/00325
d D 4.36 82/03/28 14:23:37 sam 36 35
c convert interfaces to sockaddr's and add hooks for routing
e
s 00025/00002/00301
d D 4.35 82/03/20 20:11:03 wnj 35 34
c suppress silly-windowness
e
s 00001/00001/00302
d D 4.34 82/03/15 04:45:10 wnj 34 33
c interfac queueing, restrictions on packets, tcp keep alives done 
c properly, bug fix to raw
e
s 00002/00002/00301
d D 4.33 82/03/13 12:53:21 sam 33 32
c lint
e
s 00002/00003/00301
d D 4.32 82/03/12 16:18:28 sam 32 31
c lint
e
s 00001/00001/00303
d D 4.31 82/01/19 07:30:08 root 31 30
c m_get(0) -> m_get(M_DONTWAIT)
e
s 00006/00002/00298
d D 4.30 82/01/18 19:43:34 wnj 30 29
c out-of-band fixed up
e
s 00091/00013/00209
d D 4.29 82/01/17 21:20:09 wnj 29 28
c more work on out-of-band
e
s 00005/00004/00217
d D 4.28 82/01/17 01:02:06 wnj 28 27
c attempt at out of band
e
s 00003/00002/00218
d D 4.27 81/12/22 23:17:39 root 27 26
c correct checks: for not sending FIN; for setting persist tier
e
s 00007/00008/00213
d D 4.26 81/12/21 11:57:54 root 26 25
c fix handling of FIN
e
s 00002/00001/00219
d D 4.25 81/12/20 21:40:07 wnj 25 24
c race in if_en.c; no PERSIST before SYN; implement LETDATADRAIN
e
s 00007/00000/00213
d D 4.24 81/12/20 15:22:26 root 24 23
c add trace call
e
s 00002/00012/00211
d D 4.23 81/12/12 18:05:16 root 23 22
c clean out printf
e
s 00037/00031/00186
d D 4.22 81/12/12 12:59:03 root 22 21
c with crud (first working version)
e
s 00039/00009/00178
d D 4.21 81/12/02 16:59:37 wnj 21 20
c yet more lint
e
s 00007/00005/00180
d D 4.20 81/11/29 22:01:52 wnj 20 19
c lint and interface cleanups
e
s 00068/00057/00117
d D 4.19 81/11/26 11:57:48 wnj 19 18
c before carry to ARPAVAX
e
s 00137/00163/00037
d D 4.18 81/11/25 16:10:08 wnj 18 17
c listing
e
s 00001/00077/00199
d D 4.17 81/11/24 17:33:49 wnj 17 16
c start rewrite
e
s 00002/00002/00274
d D 4.16 81/11/23 00:08:38 wnj 16 15
c no flipping of sport/dport
e
s 00007/00009/00269
d D 4.15 81/11/20 00:47:26 wnj 15 14
c linted
e
s 00004/00005/00274
d D 4.14 81/11/18 15:38:14 wnj 14 13
c more cleanup
e
s 00011/00010/00268
d D 4.13 81/11/16 14:17:48 wnj 13 12
c more lint
e
s 00032/00031/00246
d D 4.12 81/11/15 13:00:30 wnj 12 11
c listing
e
s 00037/00105/00240
d D 4.11 81/11/14 16:40:32 wnj 11 10
c before overlay
e
s 00033/00022/00312
d D 4.10 81/11/08 16:25:39 wnj 10 9
c first listing
e
s 00002/00002/00332
d D 4.9 81/11/04 00:29:35 wnj 9 8
c more cleanups, fields in ucb.h
e
s 00003/00003/00331
d D 4.8 81/11/01 22:32:27 wnj 8 7
c minor fixups
e
s 00003/00003/00331
d D 4.7 81/10/31 15:54:11 wnj 7 6
c bug fixes and last chksum
e
s 00004/00002/00330
d D 4.6 81/10/31 14:52:31 wnj 6 5
c faster cksum
e
s 00006/00024/00326
d D 4.5 81/10/31 14:15:57 wnj 5 4
c return early in tcp_send, avoiding tcp_sndcopy; use MAX, MFREE in tcp_input
e
s 00001/00002/00349
d D 4.4 81/10/31 12:01:36 wnj 4 3
c faster imp code...
e
s 00000/00000/00351
d D 4.3 81/10/30 20:42:33 wnj 3 2
c cleanup
e
s 00087/00155/00264
d D 4.2 81/10/30 20:19:28 wnj 2 1
c further cleanup
e
s 00419/00000/00000
d D 4.1 81/10/30 19:56:58 wnj 1 0
c date and time created 81/10/30 19:56:58 by wnj
e
u
U
f b 
t
T
I 1
D 15
/* %M% %I% %E% */
E 15
I 15
D 65
/*	%M%	%I%	%E%	*/
E 65
I 65
/*
D 76
 * Copyright (c) 1982 Regents of the University of California.
E 76
I 76
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 76
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 65
E 15

D 59
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/mbuf.h"
I 21
#include "../h/protosw.h"
E 21
#include "../h/socket.h"
I 6
D 8
#include "../inet/cksum.h"
E 8
I 8
D 10
#include "../inet/inet_cksum.h"
E 8
E 6
#include "../inet/inet.h"
#include "../inet/inet_host.h"
#include "../inet/inet_systm.h"
#include "../inet/imp.h"
#include "../inet/ip.h"
#include "../inet/tcp.h"
#include "../inet/tcp_fsm.h"
E 10
I 10
#include "../h/socketvar.h"
D 14
#include "../net/inet_cksum.h"
E 14
D 19
#include "../net/inet.h"
D 15
#include "../net/inet_host.h"
E 15
I 11
#include "../net/inet_pcb.h"
E 11
#include "../net/inet_systm.h"
#include "../net/imp.h"
E 19
I 19
D 47
#include "../net/in.h"
E 47
I 47
D 52
#include "../netinet/in.h"
E 52
I 52
#include "../h/errno.h"
E 59
I 59
#include "param.h"
#include "systm.h"
#include "mbuf.h"
#include "protosw.h"
#include "socket.h"
#include "socketvar.h"
#include "errno.h"
E 59

E 52
E 47
I 37
#include "../net/route.h"
I 52

D 59
#include "../netinet/in.h"
E 52
E 37
D 47
#include "../net/in_pcb.h"
#include "../net/in_systm.h"
E 19
#include "../net/ip.h"
I 12
#include "../net/ip_var.h"
E 12
#include "../net/tcp.h"
E 47
I 47
#include "../netinet/in_pcb.h"
#include "../netinet/in_systm.h"
#include "../netinet/ip.h"
#include "../netinet/ip_var.h"
#include "../netinet/tcp.h"
E 59
I 59
#include "in.h"
#include "in_pcb.h"
#include "in_systm.h"
#include "ip.h"
#include "ip_var.h"
#include "tcp.h"
E 59
E 47
D 19
#include "../net/tcp_var.h"
E 19
I 19
#define	TCPOUTFLAGS
E 19
D 47
#include "../net/tcp_fsm.h"
I 19
#include "../net/tcp_seq.h"
#include "../net/tcp_timer.h"
#include "../net/tcp_var.h"
#include "../net/tcpip.h"
I 24
#include "../net/tcp_debug.h"
E 47
I 47
D 59
#include "../netinet/tcp_fsm.h"
#include "../netinet/tcp_seq.h"
#include "../netinet/tcp_timer.h"
#include "../netinet/tcp_var.h"
#include "../netinet/tcpip.h"
#include "../netinet/tcp_debug.h"
E 59
I 59
#include "tcp_fsm.h"
#include "tcp_seq.h"
#include "tcp_timer.h"
#include "tcp_var.h"
#include "tcpip.h"
#include "tcp_debug.h"
E 59
E 47
I 36
D 37
#include "../net/route.h"
E 37
E 36
E 24
E 19
D 20
#include "/usr/include/errno.h"
E 20
I 20
D 38
#include "../errno.h"
E 38
I 38
D 52
#include <errno.h>
E 52
E 38
E 20
E 10

I 22
D 51
char *tcpstates[]; /* XXX */
I 29

E 51
E 29
E 22
D 2
send(tp)                        /* send data */
E 2
I 2
/*
I 29
D 46
 * Initial options: indicate max segment length 1/2 of space
 * allocated for receive; if TCPTRUEOOB is defined, indicate
 * willingness to do true out-of-band.
E 46
I 46
 * Initial options.
E 46
 */
D 46
#ifndef TCPTRUEOOB
E 46
u_char	tcp_initopt[4] = { TCPOPT_MAXSEG, 4, 0x0, 0x0, };
D 46
#else
u_char	tcp_initopt[6] = { TCPOPT_MAXSEG, 4, 0x0, 0x0, TCPOPT_WILLOOB, 2 };
#endif
E 46

/*
E 29
D 18
 * Special routines to send control messages.
 */
tcp_sndctl(tp)
D 11
	struct tcb *tp;
E 11
I 11
	struct tcpcb *tp;
E 11
{
COUNT(TCP_SNDCTL);

        if (tcp_send(tp))
		return (1);
	tcp_sndnull(tp);
D 10
	return(0);
E 10
I 10
	return (0);
E 10
}

tcp_sndwin(tp)
D 11
	struct tcb *tp;
E 11
I 11
	struct tcpcb *tp;
E 11
{
	int ihave, hehas;
I 10
D 11
	register struct socket *so = tp->t_socket;
E 11
E 10
COUNT(TCP_SNDWIN);

	if (tp->rcv_adv) {
I 11
		register struct socket *so = tp->t_inpcb->inp_socket;

E 11
D 10
		ihave = tp->t_ucb->uc_rhiwat -
		    (tp->t_ucb->uc_rcc + tp->seqcnt);
E 10
I 10
		ihave = so->so_rcv.sb_hiwat -
		    (so->so_rcv.sb_cc + tp->seqcnt);
E 10
		hehas = tp->rcv_adv - tp->rcv_nxt;
D 4
		if (hehas > 32 &&
		   (100*(ihave-hehas)/tp->t_ucb->uc_rhiwat) < 35)
E 4
I 4
D 10
		if ((100*(ihave-hehas)/tp->t_ucb->uc_rhiwat) < 35)
E 10
I 10
		if ((100*(ihave-hehas)/so->so_rcv.sb_hiwat) < 35)
E 10
E 4
			return;
	}
        if (tcp_send(tp))
D 13
		return (1);
E 13
I 13
		return;
E 13
	tcp_sndnull(tp);
D 13
	return (0);
E 13
}

tcp_sndnull(tp)
E 2
D 11
	register struct tcb *tp;
E 11
I 11
	register struct tcpcb *tp;
E 11
{
I 2
COUNT(TCP_SNDNULL);

D 13
	tcp_output(tp, 0, 0, (struct mbuf *)0);
E 13
I 13
	(void) tcp_output(tp, 0, 0, (struct mbuf *)0);
E 13
        tp->tc_flags &= ~TC_ACK_DUE;
}

D 17
tcp_sndrst(tp, n)
D 11
	register struct tcb *tp;
	register struct th *n;
E 11
I 11
	register struct tcpcb *tp;
	register struct tcpiphdr *n;
E 11
{
COUNT(TCP_SNDRST);

        /* don't send a reset in response to a reset */
D 12
	if (n->th_flags&TH_RST)
E 12
I 12
	if (n->ti_flags&TH_RST)
E 12
		return;
	tp->tc_flags |= TC_SND_RST;
D 12
	if (n->th_flags&TH_ACK)
		tp->snd_nxt = n->t_ackno;
E 12
I 12
	if (n->ti_flags&TH_ACK)
		tp->snd_nxt = n->ti_ackno;
E 12
	tp->tc_flags &= ~TC_SYN_RCVD;
	tcp_sndnull(tp);
	tp->tc_flags &= ~TC_SND_RST;
}

E 17
/*
 * Tcp segment output routine.
E 18
I 18
D 22
 * Tcp output routine: figure out what should be sent
 * and, if nothing, send a null segment anyways if force is nonzero
 * (e.g. to be sure to send an ACK).
 *
 * This routine can be called only after SYNs have been exchanged.
E 22
I 22
 * Tcp output routine: figure out what should be sent and send it.
E 22
E 18
 */
D 18
tcp_send(tp)
E 18
I 18
tcp_output(tp)
E 18
D 11
	register struct tcb *tp;
E 11
I 11
	register struct tcpcb *tp;
E 11
{
E 2
D 10
	register struct ucb *up;
E 10
I 10
D 11
	register struct socket *so;
E 11
E 10
D 18
	register unsigned long last, wind;
E 18
I 11
	register struct socket *so = tp->t_inpcb->inp_socket;
E 11
D 18
	struct mbuf *m;
D 11
	int flags = 0, forced, sent;
	struct mbuf *tcp_sndcopy();
	int len;
E 11
I 11
	int flags = 0, forced, sent, len;
E 18
I 18
D 68
	register int len;
E 68
I 68
	register int len, win;
E 68
	struct mbuf *m0;
D 32
	int off, flags;
E 32
I 32
D 38
	int off, flags, win;
E 38
I 38
D 68
	int off, flags, win, error;
E 68
I 68
	int off, flags, error;
E 68
E 38
E 32
	register struct mbuf *m;
	register struct tcpiphdr *ti;
D 29
	int win;
E 29
I 29
D 32
	int win, force;
E 32
	u_char *opt;
	unsigned optlen = 0;
I 40
D 68
	int sendalot;
E 68
I 68
	int idle, sendalot;
E 68
E 40
E 29
E 18
E 11

D 2
COUNT(SEND);
E 2
I 2
D 18
COUNT(TCP_SEND);
E 2
D 10
	up = tp->t_ucb;
E 10
I 10
D 11
	so = tp->t_socket;
E 11
E 10
	tp->snd_lst = tp->snd_nxt;
	forced = 0;
	m = NULL;
D 2

	if (tp->snd_nxt == tp->iss) {           /* first data to be sent */
E 2
I 2
	if (tp->snd_nxt == tp->iss) {
E 2
		flags |= TH_SYN;
		tp->snd_lst++;
	}
D 2

	/* get seq # of last datum in send buffer */

E 2
	last = tp->snd_off;
D 10
	for (m = up->uc_sbuf; m != NULL; m = m->m_next)
E 10
I 10
	for (m = so->so_snd.sb_mb; m != NULL; m = m->m_next)
E 10
		last += m->m_len;
D 2

        /* no data to send in buffer */

E 2
	if (tp->snd_nxt > last) {
D 2

		/* should we send FIN?  don't unless haven't already sent one */

E 2
		if ((tp->tc_flags&TC_SND_FIN) &&
		    (tp->seq_fin == tp->iss || tp->snd_nxt <= tp->seq_fin)) {
E 18
I 18
D 43
COUNT(TCP_OUTPUT);
E 43
E 18
D 55

I 54
	if (tp->t_state == TCPS_CLOSED)
		return (EINVAL);
E 55
E 54
D 18
			flags |= TH_FIN;
			tp->seq_fin = tp->snd_lst++;
		}
I 5
D 7
		if (tp->snd_nxt >= tp->snd_lst)
			return (0);
E 7
E 5
D 2

	} else {                                  /* there is data to send */

		/* send data only if there is a window defined */

E 2
I 2
	} else {
E 2
		if (tp->tc_flags&TC_SYN_ACKED) {
D 2

E 2
			wind = tp->snd_una + tp->snd_wnd;
D 2

			/* use window to limit send */

E 2
D 13
			tp->snd_lst = min(last, wind);
E 13
I 13
			tp->snd_lst = MIN(last, wind);
E 13
D 2

			/* make sure we don't do ip fragmentation */

E 2
			if ((len = tp->snd_lst - tp->snd_nxt) > 1024)
				tp->snd_lst -= len - 1024;
D 2

			/* set persist timer */

E 2
			if (tp->snd_lst >= wind)
				tp->t_persist = T_PERS;
		}
D 2

		/* check if window is closed and must force a byte out */

E 2
		if ((tp->tc_flags&TC_FORCE_ONE) && (tp->snd_lst == wind)) {
			tp->snd_lst = tp->snd_nxt + 1;
			forced = 1;
D 5
		}
D 2

		/* copy data to send from send buffer */

E 2
		m = tcp_sndcopy(tp, max(tp->iss+1,tp->snd_nxt), tp->snd_lst);
E 5
I 5
D 7
		} else if (tp->snd_nxt >= tp->snd_lst)
E 7
I 7
		} else if (tp->snd_nxt >= tp->snd_lst && (tp->tc_flags&TC_SND_FIN) == 0)
E 7
			return (0);
D 11
		m = tcp_sndcopy(tp, MAX(tp->iss+1,tp->snd_nxt), tp->snd_lst);
E 11
I 11
D 13
		m = sb_copy(&so->so_snd,
		      MAX(tp->iss+1,tp->snd_nxt) - tp->snd_off,
		      tp->snd_lst - tp->snd_off);
E 13
I 13
D 14
		m = sbcopy(&so->so_snd,
E 14
I 14
D 15
		m = m_copy(&so->so_snd,
E 15
I 15
		m = m_copy(so->so_snd.sb_mb,
E 15
E 14
		      (int)(MAX(tp->iss+1,tp->snd_nxt) - tp->snd_off),
		      (int)(tp->snd_lst - tp->snd_off));
E 13
E 11
E 5
D 2

		/* see if EOL should be sent */

E 2
		if (tp->snd_end > tp->iss && tp->snd_end <= tp->snd_lst)
			flags |= TH_EOL;
D 2

		/* must send FIN and no more data left to send after this */

E 2
		if ((tp->tc_flags&TC_SND_FIN) && !forced &&
		    tp->snd_lst == last &&
		    (tp->seq_fin == tp->iss || tp->snd_nxt <= tp->seq_fin)) {
D 2

E 2
			flags |= TH_FIN;
			tp->seq_fin = tp->snd_lst++;
		}
E 18
I 18
	/*
D 19
	 * Determine length of data that can be transmitted.
	 * If will transmit to end of data and no more data
	 * is coming, then send FIN also.
	 * Make a copy of the data (if any).  If no data
	 * and not forced to transmit, just return.
E 19
I 19
D 35
	 * Determine length of data that can be transmitted,
E 35
I 35
	 * Determine length of data that should be transmitted,
E 35
	 * and flags that will be used.
	 * If there is some data or critical controls (SYN, RST)
	 * to send, then transmit; otherwise, investigate further.
E 19
	 */
I 68
	idle = (tp->snd_max == tp->snd_una);
E 68
I 40
again:
	sendalot = 0;
E 40
	off = tp->snd_nxt - tp->snd_una;
D 21
	len = MIN(so->so_snd.sb_cc, tp->snd_wnd) - off;
E 21
I 21
D 63
	len = MIN(so->so_snd.sb_cc, tp->snd_wnd+tp->t_force) - off;
E 63
I 63
D 64
	win = MIN(tp->snd_wnd, tp->snd_cwnd) + tp->t_force;
E 64
I 64
	win = MIN(tp->snd_wnd, tp->snd_cwnd);
I 73

E 73
	/*
	 * If in persist timeout with window of 0, send 1 byte.
D 68
	 * Otherwise, window is small but nonzero
	 * and timer expired, go to transmit state.
E 68
I 68
	 * Otherwise, if window is small but nonzero
	 * and timer expired, we will send what we can
	 * and go to transmit state.
E 68
	 */
	if (tp->t_force) {
D 73
		if (win == 0) 
E 73
I 73
D 75
if (win == 0 && off)
log(7, "persist offset %d\n", off);
E 75
		if (win == 0)
E 73
			win = 1;
		else {
			tp->t_timer[TCPT_PERSIST] = 0;
			tp->t_rxtshift = 0;
		}
	}
I 68

E 68
E 64
	len = MIN(so->so_snd.sb_cc, win) - off;
E 63
I 26
D 73
	if (len < 0)
D 32
		return;			/* past FIN */
E 32
I 32
D 38
		return (0);			/* past FIN */
E 38
I 38
		return (0);	/* ??? */	/* past FIN */
E 73
E 38
E 32
E 26
E 21
D 19
	if (len > tp->mtu)
		len = tp->mtu;
	if (len == so->so_snd.sb_cc && (so->so_state & SS_CANTSNDMORE))
		flags = TH_FIN;
	else
		flags = 0;
	if (len)
E 19
I 19
D 40
	if (len > tp->t_maxseg)
E 40
I 40
D 75
	if (len > tp->t_maxseg) {
E 40
		len = tp->t_maxseg;
I 40
D 62
		sendalot = 1;
E 62
I 62
		/*
D 64
		 * Don't send more than one segment if retransmitting.
E 64
I 64
		 * Don't send more than one segment if retransmitting
		 * (or persisting, but then we shouldn't be here).
E 64
		 */
D 63
		if (SEQ_GT(tp->snd_nxt, tp->snd_max))
E 63
I 63
		if (tp->t_rxtshift == 0)
E 63
			sendalot = 1;
E 62
	}
E 40
I 35

E 75
I 64
D 73
	win = sbspace(&so->so_rcv);
E 73
E 64
E 35
I 22
D 26
	if (len < 0)
		len = 0;		/* FIN can cause -1 */
E 26
E 22
	flags = tcp_outflags[tp->t_state];
I 21
D 27
	if (len < so->so_snd.sb_cc)
E 27
I 27
D 73
	if (tp->snd_nxt + len < tp->snd_una + so->so_snd.sb_cc)
E 73
I 73
D 77
	if (SEQ_LT(tp->snd_nxt + len, tp->snd_una + so->so_snd.sb_cc))
E 73
E 27
		flags &= ~TH_FIN;
E 77
E 21
D 26
	if (len || (flags & (TH_SYN|TH_RST)))
E 26
I 26
D 35
	if (len || (flags & (TH_SYN|TH_RST|TH_FIN)))
E 35
I 35
D 73
	if (flags & (TH_SYN|TH_RST|TH_FIN))
E 35
E 26
E 19
		goto send;
E 73
I 68

I 73
	if (len < 0) {
		/*
D 74
		 * If closing and all data acked, len will be -1;
		 * retransmit FIN if necessary.
E 74
I 74
		 * If FIN has been sent but not acked,
		 * but we haven't been called to retransmit,
D 75
		 * len will be -1; no need to transmit now.
E 75
I 75
		 * len will be -1; transmit if acking, otherwise no need.
E 75
E 74
		 * Otherwise, window shrank after we sent into it.
		 * If window shrank to 0, cancel pending retransmit
		 * and pull snd_nxt back to (closed) window.
		 * We will enter persist state below.
I 74
		 * If the window didn't close completely,
		 * just wait for an ACK.
E 74
		 */
D 74
		if (flags & TH_FIN)
			len = 0;
		else if (win == 0) {
			tp->t_timer[TCPT_REXMT] = 0;
			tp->snd_nxt = tp->snd_una;
			len = 0;
		} else
E 74
I 74
D 75
		if (flags & TH_FIN || win != 0)
E 75
I 75
		if (flags & TH_FIN) {
			if (tp->t_flags & TF_ACKNOW)
				len = 0;
			else
				return (0);
		} else if (win == 0) {
			tp->t_timer[TCPT_REXMT] = 0;
			tp->snd_nxt = tp->snd_una;
			len = 0;
		} else
E 75
E 74
			return (0);
I 74
D 75
		tp->t_timer[TCPT_REXMT] = 0;
		tp->snd_nxt = tp->snd_una;
		len = 0;
E 75
E 74
	}
I 75
	if (len > tp->t_maxseg) {
		len = tp->t_maxseg;
		/*
		 * Don't send more than one segment if retransmitting
		 * (or persisting, but then we shouldn't be here).
		 */
		if (tp->t_rxtshift == 0)
			sendalot = 1;
	}
I 77
	if (SEQ_LT(tp->snd_nxt + len, tp->snd_una + so->so_snd.sb_cc))
		flags &= ~TH_FIN;
E 77
E 75
	win = sbspace(&so->so_rcv);

I 75

E 75
E 73
	/*
I 75
	 * If our state indicates that FIN should be sent
	 * and we have not yet done so, or we're retransmitting the FIN,
	 * then we need to send.
	 */
	if (flags & TH_FIN &&
	    ((tp->t_flags & TF_SENTFIN) == 0 || tp->snd_nxt == tp->snd_una))
		goto send;
	/*
E 75
	 * Send if we owe peer an ACK.
	 */
D 73
	if (tp->t_flags&TF_ACKNOW)
E 73
I 73
	if (tp->t_flags & TF_ACKNOW)
E 73
		goto send;
I 73
D 75
	if (flags & (TH_SYN|TH_RST|TH_FIN))
E 75
I 75
	if (flags & (TH_SYN|TH_RST))
E 75
		goto send;
E 73
E 68
I 35
	if (SEQ_GT(tp->snd_up, tp->snd_una))
		goto send;
E 35

	/*
I 35
D 62
	 * Sender silly window avoidance.  If can send all data,
	 * a maximum segment, at least 1/4 of window do it,
E 62
I 62
	 * Sender silly window avoidance.  If connection is idle
	 * and can send all data, a maximum segment,
	 * at least a maximum default-size segment do it,
E 62
	 * or are forced, do it; otherwise don't bother.
I 67
	 * If peer's buffer is tiny, then send
	 * when window is at least half open.
E 67
I 64
	 * If retransmitting (possibly after persist timer forced us
	 * to send into a small window), then must resend.
E 64
	 */
	if (len) {
D 62
		if (len == tp->t_maxseg || off+len >= so->so_snd.sb_cc)
E 62
I 62
D 68
		if (len == tp->t_maxseg || len >= so->so_snd.sb_cc) /* off = 0*/
E 68
I 68
		if (len == tp->t_maxseg || len >= TCP_MSS)	/* a lot */
E 68
E 62
			goto send;
D 62
		if (len * 4 >= tp->snd_wnd)		/* a lot */
E 62
I 62
D 68
		if (len >= TCP_MSS)	/* a lot */
E 68
I 68
		if ((idle || tp->t_flags & TF_NODELAY) &&
		    len + off >= so->so_snd.sb_cc)
E 68
E 62
			goto send;
		if (tp->t_force)
I 67
			goto send;
		if (len >= tp->max_sndwnd / 2)
E 67
			goto send;
I 64
		if (SEQ_LT(tp->snd_nxt, tp->snd_max))
			goto send;
E 64
D 68
	}
E 68
I 68
D 73
	} else
		/*
		 * If window shrank after we sent into it,
		 * cancel pending retransmit.  We will enter
		 * persist state below.
		 */
		if (off == 0 && SEQ_LT(tp->snd_nxt, tp->snd_max))
			tp->t_timer[TCPT_REXMT] = 0;
E 73
I 73
	}
E 73
E 68

D 68
	/*
E 35
D 19
	 * No data to send: see if something else makes us want to send.
	 * First check if we owe peer and ack or have a unacked FIN to send.
E 19
I 19
D 26
	 * See if we owe peer an ACK or have a unacked FIN to send.
E 26
I 26
	 * Send if we owe peer an ACK.
E 26
E 19
	 */
D 19
	if (tp->t_flags & TF_OWEACK)
E 19
I 19
D 29
	if (tp->t_flags & TF_ACKNOW)
E 29
I 29
	if (tp->t_flags&TF_ACKNOW)
E 29
E 19
		goto send;
E 68
D 19
	if ((so->so_state & SS_CANTSNDMORE) &&
	    TCPS_OURFINISACKED(tp->t_state) == 0)
E 19
I 19
D 26
	if ((so->so_state & SS_CANTSENDMORE) &&
	    TCPS_OURFINNOTACKED(tp->t_state))
E 19
		goto send;
E 26
D 19
	if (tp->t_state == TCPS_SYN_SENT) {
		flags = TH_SYN;
		goto send;
E 18
	}
I 7
D 18
	if (tp->snd_nxt >= tp->snd_lst)
		return (0);
E 7
D 2

	if (tp->snd_nxt < tp->snd_lst) {        /* something to send */

		if (tp->tc_flags & TC_SND_URG)
			flags |= TH_URG;
		sent = tcp_output(tp, flags, tp->snd_lst - tp->snd_nxt, m);
		/* set timers for retransmission if necessary */

		if (!forced) {
			tp->t_rexmt = tp->t_xmtime;
			tp->t_rexmt_val = tp->snd_lst;

			if ((tp->tc_flags&TC_REXMT) == 0) {
				tp->t_rexmttl = T_REXMTTL;
				tp->t_rtl_val = tp->snd_lst;
			}

E 2
I 2
D 5
	if (tp->snd_nxt >= tp->snd_lst)
		return (0);
E 5
	if (tp->tc_flags & TC_SND_URG)
		flags |= TH_URG;
D 13
	sent = tcp_output(tp, flags, tp->snd_lst - tp->snd_nxt, m);
E 13
I 13
	sent = tcp_output(tp, flags, (int)(tp->snd_lst - tp->snd_nxt), m);
E 13
	if (!forced) {
		tp->t_rexmt = tp->t_xmtime;
		tp->t_rexmt_val = tp->snd_lst;
		if ((tp->tc_flags&TC_REXMT) == 0) {
			tp->t_rexmttl = T_REXMTTL;
			tp->t_rtl_val = tp->snd_lst;
E 2
		}
E 18
I 18
	if (tp->t_state == TCPS_CLOSED) {
		flags = TH_RST;
		goto send;
E 18
D 2

		/* update seq for next send if this one got out */

		if (sent)
			tp->snd_nxt = tp->snd_lst;


		/* if last timed message has been acked, start timing
		   this one */

		if ((tp->tc_flags&TC_SYN_ACKED) && tp->snd_una > tp->t_xmt_val) {
			tp->t_xmt = 0;
			tp->t_xmt_val = tp->snd_lst;
		}

		tp->tc_flags &= ~(TC_ACK_DUE|TC_REXMT|TC_FORCE_ONE);
		tp->snd_hi = max(tp->snd_nxt, tp->snd_hi);
		return (1);
E 2
	}
E 19
D 2

	return(0);
}

tcp_sndctl(tp)                            /* send a control msg */
	struct tcb *tp;
{
COUNT(SEND_CTL);
        if (!send(tp)) {
		tcp_sndnull(tp);
		return(0);
E 2
I 2
D 18
	if (sent)
		tp->snd_nxt = tp->snd_lst;
	if ((tp->tc_flags&TC_SYN_ACKED) &&
	    tp->snd_una > tp->t_xmt_val) {
		tp->t_xmt = 0;
		tp->t_xmt_val = tp->snd_lst;
E 2
	}
D 2
	return(1);
E 2
I 2
	tp->tc_flags &= ~(TC_ACK_DUE|TC_REXMT|TC_FORCE_ONE);
D 5
	tp->snd_hi = max(tp->snd_nxt, tp->snd_hi);
E 5
I 5
	tp->snd_hi = MAX(tp->snd_nxt, tp->snd_hi);
E 5
	return (1);
E 2
}
D 17

D 2
int	printhave = 0;

tcp_sndwin(tp)
	struct tcb *tp;
{
	int ihave;
	int hehas;

	if (tp->rcv_adv) {
		/* figure out window we would advertise */
		ihave = tp->t_ucb->uc_rhiwat -
		    (tp->t_ucb->uc_rcc + tp->seqcnt);
		hehas = tp->rcv_adv - tp->rcv_nxt;
		if (printhave)
		printf("ihave %d, hehas %d\n", ihave, hehas);
		if (hehas > 32 &&
		   (100*(ihave-hehas)/tp->t_ucb->uc_rhiwat) < 35)
			return;
		if (printhave)
		printf("update him\n");
	}
        if (send(tp))
		return (1);
	tcp_sndnull(tp);
	return (0);
}
tcp_sndnull(tp)				/* send only control information */
	register struct tcb *tp;
{
COUNT(SEND_NULL);

	tcp_output(tp, 0, 0, (struct mbuf *)0);
        tp->tc_flags &= ~TC_ACK_DUE;
}

tcp_sndrst(tp, n)                         /* send a reset */
	register struct tcb *tp;
	register struct th *n;
{
COUNT(SEND_RST);
        /* don't send a reset in response to a reset */

	if (n->th_flags&TH_RST)
		return;

	tp->tc_flags |= TC_SND_RST;

	if (n->th_flags&TH_ACK)
		tp->snd_nxt = n->t_ackno;

	tp->tc_flags &= ~TC_SYN_RCVD;
	tcp_sndnull(tp);
	tp->tc_flags &= ~TC_SND_RST;
}

E 2
/*
 * Create template to be used to send tcp packets on a connection.
 * Call after host entry created, allocates an mbuf and fills
 * in a skeletal tcp/ip header, minimizing the amount of work
 * necessary when the connection is used.
 */
D 11
struct th *
E 11
I 11
struct tcpiphdr *
E 11
tcp_template(tp)
D 11
	struct tcb *tp;
E 11
I 11
	struct tcpcb *tp;
E 11
{
D 10
	register struct host *h = tp->t_ucb->uc_host;
E 10
I 10
D 11
	register struct host *h = tp->t_host;
E 11
I 11
	register struct inpcb *inp = tp->t_inpcb;
D 15
	register struct in_host *h = inp->inp_fhost;
E 15
E 11
E 10
	register struct mbuf *m;
D 11
	register struct th *n;
	register struct ip *ip;
E 11
I 11
	register struct tcpiphdr *n;
E 11

D 15
	if (h == 0)
		return (0);
E 15
I 15
COUNT(TCP_TEMPLATE);
E 15
	m = m_get(1);
	if (m == 0)
		return (0);
D 11
	m->m_off = MMAXOFF - sizeof (struct th);
	m->m_len = sizeof (struct th);
	n = mtod(m, struct th *);
E 11
I 11
	m->m_off = MMAXOFF - sizeof (struct tcpiphdr);
	m->m_len = sizeof (struct tcpiphdr);
	n = mtod(m, struct tcpiphdr *);
E 11
D 12
	n->t_next = n->t_prev = 0;
	n->t_x1 = 0;
D 9
	n->t_pr = TCPROTO;
E 9
I 9
	n->t_pr = IPPROTO_TCP;
E 9
D 11
	n->t_len = htons(sizeof (struct th) - sizeof (struct ip));
E 11
I 11
	n->t_len = htons(sizeof (struct tcpiphdr) - sizeof (struct ip));
E 11
	n->t_s.s_addr = n_lhost.s_addr;
	n->t_d.s_addr = h->h_addr.s_addr;
D 11
	n->t_src = htons(tp->t_lport);
	n->t_dst = htons(tp->t_fport);
E 11
I 11
	n->t_src = htons(inp->inp_lport);
	n->t_dst = htons(inp->inp_fport);
E 11
	n->t_seq = 0;
	n->t_ackno = 0;
	n->t_x2 = 0;
	n->t_off = 5;
	n->th_flags = 0;
	n->t_win = 0;
	n->t_sum = 0;
	n->t_urp = 0;
E 12
I 12
	n->ti_next = n->ti_prev = 0;
	n->ti_x1 = 0;
	n->ti_pr = IPPROTO_TCP;
	n->ti_len = htons(sizeof (struct tcpiphdr) - sizeof (struct ip));
D 15
	n->ti_src.s_addr = n_lhost.s_addr;
	n->ti_dst.s_addr = h->h_addr.s_addr;
E 15
I 15
	n->ti_src = inp->inp_laddr;
	n->ti_dst = inp->inp_faddr;
E 15
D 16
	n->ti_sport = htons(inp->inp_lport);
	n->ti_dport = htons(inp->inp_fport);
E 16
I 16
	n->ti_sport = inp->inp_lport;
	n->ti_dport = inp->inp_fport;
E 16
	n->ti_seq = 0;
	n->ti_ackno = 0;
	n->ti_x2 = 0;
	n->ti_off = 5;
	n->ti_flags = 0;
	n->ti_win = 0;
	n->ti_sum = 0;
	n->ti_urp = 0;
E 12
	return (n);
}

E 17
tcp_output(tp, flags, len, dat)
D 11
	register struct tcb *tp;
E 11
I 11
	register struct tcpcb *tp;
E 11
	register int flags;
	int len;
	struct mbuf *dat;
{
I 6
D 11
	register struct th *t;			/* known to be r9 */
E 11
I 11
	register struct tcpiphdr *t;			/* known to be r9 */
E 11
E 6
	register struct mbuf *m;
I 11
	struct socket *so = tp->t_inpcb->inp_socket;
E 11
D 6
	register struct th *t;
E 6
	register struct ip *ip;
D 15
	int i;
E 15
D 17
#ifdef TCPDEBUG
	struct tcp_debug tdb;
#endif
E 17
D 8
COUNT(SEND_TCP);
E 8
I 8
COUNT(TCP_OUTPUT);
E 18
E 8
D 73

E 73
I 29
D 46
#ifdef TCPTRUEOOB
E 29
D 9
	if ((t = tp->t_ucb->uc_template) == 0)
E 9
I 9
D 18
	if ((t = tp->t_template) == 0)
E 9
		return (0);
E 18
I 18
	/*
I 29
	 * Send if an out of band data or ack should be transmitted.
	 */
	if (tp->t_oobflags&(TCPOOB_OWEACK|TCPOOB_NEEDACK)))
		goto send;
#endif
E 46
D 68

E 68
	/*
E 29
D 63
	 * Calculate available window in i, and also amount
E 63
I 63
D 68
	 * Calculate available window, and also amount
E 63
	 * of window known to peer (as advertised window less
E 68
I 68
	 * Compare available window to amount of window
	 * known to peer (as advertised window less
E 68
D 63
	 * next expected input.)  If this is 35% or more of the
	 * maximum possible window, then want to send a segment to peer.
E 63
I 63
	 * next expected input.)  If the difference is 35% or more of the
	 * maximum possible window, then want to send a window update to peer.
E 63
	 */
D 19
	i = sbspace(&so->so_rcv) - tp->seqcnt;
	if (i > 0 &&
	    ((100*(i-(tp->rcv_adv-tp->rcv_nxt))/so->so_rcv.sb_hiwat) >= 35))
E 19
I 19
D 68
	win = sbspace(&so->so_rcv);
E 68
	if (win > 0 &&
	    ((100*(win-(tp->rcv_adv-tp->rcv_nxt))/so->so_rcv.sb_hiwat) >= 35))
E 19
		goto send;

	/*
I 40
	 * TCP window updates are not reliable, rather a polling protocol
	 * using ``persist'' packets is used to insure receipt of window
	 * updates.  The three ``states'' for the output side are:
	 *	idle			not doing retransmits or persists
D 68
	 *	persisting		to move a zero window
E 68
I 68
	 *	persisting		to move a small or zero window
E 68
	 *	(re)transmitting	and thereby not persisting
	 *
	 * tp->t_timer[TCPT_PERSIST]
	 *	is set when we are in persist state.
	 * tp->t_force
	 *	is set when we are called to send a persist packet.
	 * tp->t_timer[TCPT_REXMT]
	 *	is set when we are retransmitting
	 * The output side is idle when both timers are zero.
	 *
D 64
	 * If send window is closed, there is data to transmit, and no
	 * retransmit or persist is pending, then go to persist state,
	 * arranging to force out a byte to get more current window information
	 * if nothing happens soon.
E 64
I 64
	 * If send window is too small, there is data to transmit, and no
	 * retransmit or persist is pending, then go to persist state.
	 * If nothing happens soon, send when timer expires:
	 * if window is nonzero, transmit what we can,
	 * otherwise force out a byte.
E 64
	 */
D 64
	if (tp->snd_wnd == 0 && so->so_snd.sb_cc &&
	    tp->t_timer[TCPT_REXMT] == 0 && tp->t_timer[TCPT_PERSIST] == 0) {
E 64
I 64
	if (so->so_snd.sb_cc && tp->t_timer[TCPT_REXMT] == 0 &&
	    tp->t_timer[TCPT_PERSIST] == 0) {
E 64
		tp->t_rxtshift = 0;
		tcp_setpersist(tp);
	}

	/*
E 40
	 * No reason to send a segment, just return.
	 */
I 22
D 23
printf("tcp_output: nothing to send\n");
E 23
E 22
D 20
	return;
E 20
I 20
	return (0);
E 20

send:
	/*
	 * Grab a header mbuf, attaching a copy of data to
	 * be transmitted, and initialize the header from
	 * the template for sends on this connection.
	 */
E 18
D 50
	MGET(m, 0);
E 50
I 50
D 53
	MGET(m, M_DONTWAIT, MT_DATA);
E 50
D 51
	if (m == 0)
E 51
I 51
	if (m == INADDR_ANY)
E 53
I 53
	MGET(m, M_DONTWAIT, MT_HEADER);
	if (m == NULL)
E 53
E 51
D 38
		return (0);
E 38
I 38
		return (ENOBUFS);
E 38
D 11
	m->m_off = MMAXOFF - sizeof(struct th);
	m->m_len = sizeof (struct th);
E 11
I 11
D 22
	m->m_off = MMAXOFF - sizeof(struct tcpiphdr);
E 22
I 22
	m->m_off = MMAXOFF - sizeof (struct tcpiphdr);
E 22
	m->m_len = sizeof (struct tcpiphdr);
E 11
D 18
	m->m_next = dat;
E 18
I 18
	if (len) {
I 78
		if (tp->t_force && len == 1)
			tcpstat.tcps_sndprobe++;
		else if (SEQ_LT(tp->snd_nxt, tp->snd_max)) {
			tcpstat.tcps_sndrexmitpack++;
			tcpstat.tcps_sndrexmitbyte += len;
		} else {
			tcpstat.tcps_sndpack++;
			tcpstat.tcps_sndbyte += len;
		}
E 78
		m->m_next = m_copy(so->so_snd.sb_mb, off, len);
		if (m->m_next == 0)
			len = 0;
I 22
D 23
if (m->m_next) printf("copy *mtod()=%x\n", *mtod(m->m_next, char *));
E 23
E 22
D 78
	}
E 78
I 78
	} else if (tp->t_flags & TF_ACKNOW)
		tcpstat.tcps_sndacks++;
	else if (flags & (TH_SYN|TH_FIN|TH_RST))
		tcpstat.tcps_sndctrl++;
	else if (SEQ_GT(tp->snd_up, tp->snd_una))
		tcpstat.tcps_sndurg++;
	else
		tcpstat.tcps_sndwinup++;

E 78
	ti = mtod(m, struct tcpiphdr *);
	if (tp->t_template == 0)
		panic("tcp_output");
D 20
	bcopy((caddr_t)tp->t_template, ti, sizeof (struct tcpiphdr));
E 20
I 20
	bcopy((caddr_t)tp->t_template, (caddr_t)ti, sizeof (struct tcpiphdr));
E 20

	/*
	 * Fill in fields, remembering maximum advertised
	 * window for use in delaying messages about window sizes.
I 75
	 * If resending a FIN, be sure not to use a new sequence number.
E 75
	 */
I 75
D 79
	if (flags & TH_FIN && tp->t_flags & TF_SENTFIN &&
	    tp->snd_nxt != tp->snd_una)
E 79
I 79
	if (flags & TH_FIN && tp->t_flags & TF_SENTFIN && len == 0)
E 79
		tp->snd_nxt--;
E 75
D 22
	ti->ti_seq = htonl(tp->snd_nxt);
D 19
	ti->ti_ackno = htonl(tp->rcv_nxt);
	/* OPTIONS */
E 18
	if (flags & TH_SYN)
D 18
		len--;
E 18
I 18
		ti->ti_flags = flags;
	else
		ti->ti_flags = flags | TH_ACK;
E 19
I 19
	ti->ti_ack = htonl(tp->rcv_nxt);
E 22
I 22
D 68
	ti->ti_seq = tp->snd_nxt;
	ti->ti_ack = tp->rcv_nxt;
D 48
#if vax
E 48
I 48
D 49
#if vax || pdp11 || ns16032
E 49
E 48
	ti->ti_seq = htonl(ti->ti_seq);
	ti->ti_ack = htonl(ti->ti_ack);
E 68
I 68
	ti->ti_seq = htonl(tp->snd_nxt);
	ti->ti_ack = htonl(tp->rcv_nxt);
E 68
D 49
#endif
E 49
E 22
D 29
	if (tp->t_tcpopt) {
E 29
I 29
	/*
	 * Before ESTABLISHED, force sending of initial options
	 * unless TCP set to not do any options.
	 */
D 68
	if (tp->t_state < TCPS_ESTABLISHED) {
E 68
I 68
	opt = NULL;
	if (tp->t_state < TCPS_ESTABLISHED && (tp->t_flags & TF_NOOPT) == 0) {
E 68
I 61
D 70
		int mss;
E 70
I 70
		u_short mss;
E 70

E 61
D 68
		if (tp->t_flags&TF_NOOPT)
			goto noopt;
E 68
I 61
		mss = MIN(so->so_rcv.sb_hiwat / 2, tcp_mss(tp));
D 68
		if (mss <= IP_MSS - sizeof(struct tcpiphdr))
			goto noopt;
E 61
		opt = tcp_initopt;
		optlen = sizeof (tcp_initopt);
D 46
		*(u_short *)(opt + 2) = so->so_rcv.sb_hiwat / 2;
E 46
I 46
D 61
		*(u_short *)(opt + 2) = MIN(so->so_rcv.sb_hiwat / 2, 1024);
E 46
D 48
#if vax
E 48
I 48
D 49
#if vax || pdp11 || ns16032
E 49
E 48
		*(u_short *)(opt + 2) = htons(*(u_short *)(opt + 2));
E 61
I 61
		*(u_short *)(opt + 2) = htons(mss);
E 61
D 49
#endif
E 49
	} else {
		if (tp->t_tcpopt == 0)
			goto noopt;
E 68
I 68
		if (mss > IP_MSS - sizeof(struct tcpiphdr)) {
			opt = tcp_initopt;
			optlen = sizeof (tcp_initopt);
			*(u_short *)(opt + 2) = htons(mss);
		}
	} else if (tp->t_tcpopt) {
E 68
		opt = mtod(tp->t_tcpopt, u_char *);
		optlen = tp->t_tcpopt->m_len;
	}
D 46
#ifndef TCPTRUEOOB
	if (opt)
#else
	if (opt || (tp->t_oobflags&(TCPOOB_OWEACK|TCPOOB_NEEDACK)))
#endif
	{
E 46
I 46
	if (opt) {
E 46
E 29
I 20
		m0 = m->m_next;
E 20
D 31
		m->m_next = m_get(0);
E 31
I 31
D 50
		m->m_next = m_get(M_DONTWAIT);
E 50
I 50
		m->m_next = m_get(M_DONTWAIT, MT_DATA);
E 50
E 31
		if (m->m_next == 0) {
			(void) m_free(m);
I 20
D 29
			m_freem(m);
E 29
I 29
			m_freem(m0);
E 29
E 20
D 38
			return (0);
E 38
I 38
			return (ENOBUFS);
E 38
		}
		m->m_next->m_next = m0;
D 29
		m->m_off = MMINOFF;
		m->m_len = tp->t_tcpopt->m_len;
		bcopy(mtod(tp->t_tcpopt, caddr_t), mtod(m, caddr_t),
D 20
		    tp->t_tcpopt->m_len);
E 20
I 20
		    (unsigned)tp->t_tcpopt->m_len);
E 20
		ti->ti_off = (sizeof (struct tcphdr)+tp->t_tcpopt->m_len) >> 2;
E 29
I 29
		m0 = m->m_next;
D 46
		m0->m_off = MMINOFF;
E 46
		m0->m_len = optlen;
D 33
		bcopy(opt, mtod(m0, caddr_t), optlen);
E 33
I 33
		bcopy((caddr_t)opt, mtod(m0, caddr_t), optlen);
E 33
		opt = (u_char *)(mtod(m0, caddr_t) + optlen);
D 46
#ifdef TCPTRUEOOB
		if (tp->t_oobflags&TCPOOB_OWEACK) {
printf("tp %x send OOBACK for %x\n", tp->t_iobseq);
			*opt++ = TCPOPT_OOBACK;
			*opt++ = 3;
			*opt++ = tp->t_iobseq;
			m0->m_len += 3;
			tp->t_oobflags &= ~TCPOOB_OWEACK;
			/* sender should rexmt oob to force ack repeat */
		}
		if (tp->t_oobflags&TCPOOB_NEEDACK) {
printf("tp %x send OOBDATA seq %x data %x\n", tp->t_oobseq, tp->t_oobc);
			*opt++ = TCPOPT_OOBDATA;
D 30
			*opt++ = 4;
E 30
I 30
			*opt++ = 8;
E 30
			*opt++ = tp->t_oobseq;
			*opt++ = tp->t_oobc;
D 30
			m0->m_len += 4;
E 30
I 30
			*(tcp_seq *)opt = tp->t_oobmark - tp->snd_nxt;
#ifdef vax
			*(tcp_seq *)opt = htonl((unsigned)*(tcp_seq *)opt);
#endif
			m0->m_len += 8;
E 30
			TCPT_RANGESET(tp->t_timer[TCPT_OOBREXMT],
			    tcp_beta * tp->t_srtt, TCPTV_MIN, TCPTV_MAX);
		}
#endif
E 46
		while (m0->m_len & 0x3) {
			*opt++ = TCPOPT_EOL;
			m0->m_len++;
		}
		optlen = m0->m_len;
		ti->ti_off = (sizeof (struct tcphdr) + optlen) >> 2;
E 29
	}
I 29
D 68
noopt:
E 68
E 29
	ti->ti_flags = flags;
E 19
D 64
	win = sbspace(&so->so_rcv);
I 35
	if (win < so->so_rcv.sb_hiwat / 4)	/* avoid silly window */
		win = 0;
E 35
	if (win > 0)
E 64
I 64
D 68
	if (win >= so->so_rcv.sb_hiwat / 4)	/* avoid silly window */
E 64
I 35
D 48
#if vax
E 48
I 48
D 49
#if vax || pdp11 || ns16032
E 49
E 48
E 35
D 20
		ti->ti_win = htons(win);
E 20
I 20
		ti->ti_win = htons((u_short)win);
E 68
I 68
	/*
	 * Calculate receive window.  Don't shrink window,
	 * but avoid silly window syndrome.
	 */
	if (win < so->so_rcv.sb_hiwat / 4 && win < tp->t_maxseg)
		win = 0;
	if (win < (int)(tp->rcv_adv - tp->rcv_nxt))
		win = (int)(tp->rcv_adv - tp->rcv_nxt);
	ti->ti_win = htons((u_short)win);
E 68
I 35
D 49
#else
		ti->ti_win = win;
#endif
E 49
E 35
E 20
D 19
	if (SEQ_GT(tp->snd_urp, tp->snd_nxt))
		ti->ti_urp = htons((u_short)(tp->snd_urp - tp->snd_nxt));
E 19
I 19
	if (SEQ_GT(tp->snd_up, tp->snd_nxt)) {
D 28
		ti->ti_urp = htons((u_short)(tp->snd_up - tp->snd_nxt));
E 28
I 28
D 68
		ti->ti_urp = tp->snd_up - tp->snd_nxt;
D 48
#if vax
E 48
I 48
D 49
#if vax || pdp11 || ns16032
E 49
E 48
		ti->ti_urp = htons(ti->ti_urp);
E 68
I 68
D 70
		ti->ti_urp = htons(tp->snd_up - tp->snd_nxt);
E 70
I 70
		ti->ti_urp = htons((u_short)(tp->snd_up - tp->snd_nxt));
E 70
E 68
D 49
#endif
E 49
E 28
E 19
		ti->ti_flags |= TH_URG;
	} else
		/*
		 * If no urgent pointer to send, then we pull
		 * the urgent pointer to the left edge of the send window
		 * so that it doesn't drift into the send window on sequence
		 * number wraparound.
		 */
D 19
		tp->snd_urp = tp->snd_una;		/* drag it along */
E 19
I 19
		tp->snd_up = tp->snd_una;		/* drag it along */
D 44
	/* PUSH */
E 44
I 44
	/*
	 * If anything to send and we can send it all, set PUSH.
	 * (This will keep happy those implementations which only
D 51
	 * give data to the user when a buffer fills or a PUSH comes in.
E 51
I 51
	 * give data to the user when a buffer fills or a PUSH comes in.)
E 51
	 */
D 45
/*	if (len && (ti->ti_flags & (TH_FIN|TH_RST|TH_SYN)) == 0) */
E 45
	if (len && off+len == so->so_snd.sb_cc)
		ti->ti_flags |= TH_PUSH;
E 44
E 19

	/*
	 * Put TCP length in extended header, and then
	 * checksum extended header and data.
	 */
D 29
	if (len)
		ti->ti_len = htons((u_short)(len + sizeof (struct tcphdr)));
D 19
	ti->ti_sum = inet_cksum(m, sizeof (struct tcpiphdr) + len);
E 19
I 19
	ti->ti_sum = in_cksum(m, sizeof (struct tcpiphdr) + len);
E 29
I 29
D 68
	if (len + optlen) {
		ti->ti_len = sizeof (struct tcphdr) + optlen + len;
D 48
#if vax
E 48
I 48
D 49
#if vax || pdp11 || ns16032
E 49
E 48
		ti->ti_len = htons((u_short)ti->ti_len);
D 49
#endif
E 49
	}
E 68
I 68
	if (len + optlen)
		ti->ti_len = htons((u_short)(sizeof(struct tcphdr) +
		    optlen + len));
E 68
D 33
	ti->ti_sum = in_cksum(m, sizeof (struct tcpiphdr) + optlen + len);
E 33
I 33
	ti->ti_sum = in_cksum(m, sizeof (struct tcpiphdr) + (int)optlen + len);
E 33
E 29
E 19

I 22
D 23
printf("tcp_output: ti %x flags %x seq %x ack %x win %d len %d sum %x\n",
ti, ti->ti_flags, htonl(ti->ti_seq), htonl(ti->ti_ack), htons(ti->ti_win), ti->ti_len, ti->ti_sum);

E 23
E 22
	/*
I 19
D 40
	 * Advance snd_nxt over sequence space of this segment
E 40
I 40
	 * In transmit state, time the transmission and arrange for
D 64
	 * the retransmit.  In persist state, reset persist time for
	 * next persist.
E 64
I 64
	 * the retransmit.  In persist state, just set snd_max.
E 64
E 40
	 */
D 40
	if (flags & (TH_SYN|TH_FIN))
D 22
		len++;
E 22
I 22
		tp->snd_nxt++;
E 22
	tp->snd_nxt += len;
E 40
I 40
D 64
	if (tp->t_force == 0) {
E 64
I 64
	if (tp->t_force == 0 || tp->t_timer[TCPT_PERSIST] == 0) {
E 64
		/*
D 41
		 * Advance snd_nxt over sequence space of this segment
E 41
I 41
		 * Advance snd_nxt over sequence space of this segment.
E 41
		 */
D 75
		if (flags & (TH_SYN|TH_FIN))
E 75
I 75
		if (flags & TH_SYN)
E 75
			tp->snd_nxt++;
I 75
		if (flags & TH_FIN) {
			tp->snd_nxt++;
			tp->t_flags |= TF_SENTFIN;
		}
E 75
		tp->snd_nxt += len;
I 42
D 58
		if (SEQ_GT(tp->snd_nxt, tp->snd_max))
E 58
I 58
		if (SEQ_GT(tp->snd_nxt, tp->snd_max)) {
E 58
			tp->snd_max = tp->snd_nxt;
E 42
E 40
D 58

D 40
	/*
D 21
	 * Arrange for retransmit and time this transmit if
	 * not already a retransmit and sending either data,
	 * SYN or FIN.
E 21
I 21
	 * If this transmission closes the window,
D 22
	 * start persistance timer at 2 round trip
	 * times but at least TCPTV_PERSMIN ticks.
E 22
I 22
	 * start persistance timer at 2 round trip times
	 * but at least TCPTV_PERSMIN ticks.
E 22
E 21
	 */
D 21
	if (SEQ_GT(tp->snd_nxt, tp->snd_max)) {
		tp->rxt_seq = tp->snd_nxt - len;
		tp->rxt_time = 0;
		tp->rxt_cnt = 0;
		tp->t_timer[TCPT_REXMT] = 0;		/* XXX */
E 21
I 21
D 22
	if (tp->snd_una + tp->snd_wnd >= tp->snd_nxt &&
	    tp->t_timer[TCPT_PERSIST] == 0) {
		tp->t_timer[TCPT_PERSIST] = 2 * tp->t_srtt;
		if (tp->t_timer[TCPT_PERSIST] < TCPTV_PERSMIN)
			tp->t_timer[TCPT_PERSIST] = TCPTV_PERSMIN;
		if (tp->t_timer[TCPT_PERSIST] > TCPTV_MAX)
			tp->t_timer[TCPT_PERSIST] = TCPTV_MAX;
	}
E 22
I 22
D 25
	if (SEQ_GT(tp->snd_nxt, tp->snd_una+tp->snd_wnd) &&
E 25
I 25
	if (TCPS_HAVERCVDSYN(tp->t_state) &&
D 27
	    SEQ_GT(tp->snd_nxt, tp->snd_una+tp->snd_wnd) &&
E 27
I 27
	    SEQ_GEQ(tp->snd_nxt, tp->snd_una+tp->snd_wnd) &&
E 27
E 25
	    tp->t_timer[TCPT_PERSIST] == 0)
		TCPT_RANGESET(tp->t_timer[TCPT_PERSIST],
		    2 * tp->t_srtt, TCPTV_PERSMIN, TCPTV_MAX);
E 40
I 40
		/*
		 * Time this transmission if not a retransmission and
		 * not currently timing anything.
		 */
		if (SEQ_GT(tp->snd_nxt, tp->snd_max) && tp->t_rtt == 0) {
			tp->t_rtt = 1;
			tp->t_rtseq = tp->snd_nxt - len;
E 58
I 58
			/*
			 * Time this transmission if not a retransmission and
			 * not currently timing anything.
			 */
			if (tp->t_rtt == 0) {
				tp->t_rtt = 1;
				tp->t_rtseq = tp->snd_nxt - len;
I 78
				tcpstat.tcps_segstimed++;
E 78
			}
E 58
		}
E 40
E 22

D 40
	/*
	 * Time this transmission if not a retransmission and
	 * not currently timing anything.
	 */
	if (SEQ_GT(tp->snd_nxt, tp->snd_max) && tp->t_rtt == 0) {
		tp->t_rtt = 1;
		tp->t_rtseq = tp->snd_nxt - len;
	}
E 40
I 40
		/*
D 64
		 * Set retransmit timer if not currently set.
E 64
I 64
		 * Set retransmit timer if not currently set,
D 71
		 * and not doing a keep-alive probe.
E 71
I 71
		 * and not doing an ack or a keep-alive probe.
E 71
E 64
D 68
		 * Initial value for retransmit timer to tcp_beta*tp->t_srtt.
E 68
I 68
		 * Initial value for retransmit timer is tcp_beta*tp->t_srtt.
E 68
D 73
		 * Initialize shift counter which is used for exponential
		 * backoff of retransmit time.
E 73
I 73
		 * Initialize shift counter which is used for backoff
		 * of retransmit time.
E 73
		 */
		if (tp->t_timer[TCPT_REXMT] == 0 &&
		    tp->snd_nxt != tp->snd_una) {
			TCPT_RANGESET(tp->t_timer[TCPT_REXMT],
D 74
			    tcp_beta * tp->t_srtt, TCPTV_MIN, TCPTV_MAX);
E 74
I 74
			  tcp_beta * (tp->t_srtt ? tp->t_srtt : TCPTV_SRTTDFLT),
			  TCPTV_MIN, TCPTV_MAX);
E 74
D 60
			tp->t_rtt = 0;
E 60
			tp->t_rxtshift = 0;
I 71
			tp->t_timer[TCPT_PERSIST] = 0;
E 71
		}
D 71
		tp->t_timer[TCPT_PERSIST] = 0;
I 42
	} else {
E 71
I 71
	} else
E 71
D 68
		if (SEQ_GT(tp->snd_una+1, tp->snd_max))
			tp->snd_max = tp->snd_una+1;
E 68
I 68
		if (SEQ_GT(tp->snd_nxt + len, tp->snd_max))
			tp->snd_max = tp->snd_nxt + len;
E 68
E 42
D 41
	} else
		tcp_setpersist(tp);
E 41
I 41
D 71
	}
E 71
E 41
E 40

	/*
D 40
	 * Set retransmit timer if not currently set.
D 22
	 * Initial value for retransmit timer to tcp_beta*tp->t_srtt,
	 * with a minimum of TCPTV_MIN and a max of TCPTV_MAX.
E 22
I 22
	 * Initial value for retransmit timer to tcp_beta*tp->t_srtt.
E 22
	 * Initialize shift counter which is used for exponential
	 * backoff of retransmit time.
	 */
D 22
	if (tp->t_timer[TCPT_REXMT] == 0) {
		tp->t_timer[TCPT_REXMT] = tcp_beta * tp->t_srtt;
		if (tp->t_timer[TCPT_REXMT] < TCPTV_MIN)
			tp->t_timer[TCPT_REXMT] = TCPTV_MIN;
		if (tp->t_timer[TCPT_REXMT] > TCPTV_MAX)
			tp->t_timer[TCPT_REXMT] = TCPTV_MAX;
E 22
I 22
	if (tp->t_timer[TCPT_REXMT] == 0 && tp->snd_nxt != tp->snd_una) {
		TCPT_RANGESET(tp->t_timer[TCPT_REXMT],
		    tcp_beta * tp->t_srtt, TCPTV_MIN, TCPTV_MAX);
I 27
		tp->t_rtt = 0;
E 27
D 23
printf("rexmt timer set to %d\n", tp->t_timer[TCPT_REXMT]);
E 23
E 22
		tp->t_rxtshift = 0;
E 21
	}
I 24

	/*
E 40
	 * Trace.
	 */
D 41
	if (tp->t_inpcb->inp_socket->so_options & SO_DEBUG)
E 41
I 41
	if (so->so_options & SO_DEBUG)
E 41
		tcp_trace(TA_OUTPUT, tp->t_state, tp, ti, 0);
E 24
I 22
D 23
else printf("REXMT timer is already %d, snd_nxt %x snd_una %x\n", tp->t_timer[TCPT_REXMT], tp->snd_nxt, tp->snd_una);
E 23
E 22

	/*
E 19
	 * Fill in IP length and desired time to live and
	 * send to IP level.
	 */
D 29
	((struct ip *)ti)->ip_len = len + sizeof (struct tcpiphdr);
E 29
I 29
	((struct ip *)ti)->ip_len = sizeof (struct tcpiphdr) + optlen + len;
E 29
	((struct ip *)ti)->ip_ttl = TCP_TTL;
D 19
	if (ip_output(m) == 0)
		return;
E 19
I 19
D 22
	if (ip_output(m, tp->t_ipopt) == 0)
E 22
I 22
D 23
	if (ip_output(m, tp->t_ipopt) == 0) {
printf("ip_output failed\n");
E 23
I 23
D 26
	if (ip_output(m, tp->t_ipopt) == 0)
E 26
I 26
D 28
	if (ip_output(m, tp->t_ipopt) == 0) {
printf("ip_output failed\n");
E 28
I 28
D 34
	if (ip_output(m, tp->t_ipopt) == 0)
E 34
I 34
D 36
	if (ip_output(m, tp->t_ipopt, 0) == 0)
E 36
I 36
D 37
	if (ip_output(m, tp->t_ipopt, 0, 0) == 0)
E 37
I 37
D 38
	if (ip_output(m, tp->t_ipopt, &tp->t_inpcb->inp_route, 0) == 0)
E 37
E 36
E 34
E 28
E 26
E 23
E 22
		return (0);
E 38
I 38
D 41
	if (error = ip_output(m, tp->t_ipopt, &tp->t_inpcb->inp_route, 0))
E 41
I 41
D 54
	if (error = ip_output(m, tp->t_ipopt, (so->so_options & SO_DONTROUTE) ?
	    &routetoif : &tp->t_inpcb->inp_route, 0))
E 54
I 54
D 69
	if (so->so_options & SO_DONTROUTE)
D 56
		error = ip_output(m, tp->t_ipopt, 0, IP_ROUTETOIF);
E 56
I 56
		error =
D 66
		   ip_output(m, tp->t_ipopt, (struct route *)0, IP_ROUTETOIF);
E 66
I 66
		   ip_output(m, tp->t_inpcb->inp_options, (struct route *)0,
			IP_ROUTETOIF);
E 66
E 56
	else
D 66
		error = ip_output(m, tp->t_ipopt, &tp->t_inpcb->inp_route, 0);
E 66
I 66
		error = ip_output(m, tp->t_inpcb->inp_options,
		    &tp->t_inpcb->inp_route, 0);
E 69
I 69
	error = ip_output(m, tp->t_inpcb->inp_options, &tp->t_inpcb->inp_route,
	    so->so_options & SO_DONTROUTE);
E 69
E 66
	if (error)
E 54
E 41
		return (error);
I 78
	tcpstat.tcps_sndtotal++;
E 78
E 38
I 26
D 28
}
E 28
E 26
I 22
D 23
	}
E 23
E 22
E 19

	/*
	 * Data sent (as far as we can tell).
	 * If this advertises a larger window than any other segment,
D 22
	 * then record its sequence to be used in suppressing messages.
E 22
I 22
	 * then remember the size of the advertised window.
E 22
D 19
	 * Advance snd_nxt to reflect transmitted sequence space,
	 * drop send for purpose of ACK requirements,
	 * and time transmission if not a retransmit.
E 19
I 19
D 68
	 * Drop send for purpose of ACK requirements.
E 68
I 68
	 * Any pending ACK has now been sent.
E 68
E 19
	 */
D 22
	if (win > 0 && SEQ_GT(tp->rcv_nxt+win, tp->rcv_adv))
E 22
I 22
D 23
	if (win > 0 && SEQ_GT(tp->rcv_nxt+win, tp->rcv_adv)) {
E 23
I 23
	if (win > 0 && SEQ_GT(tp->rcv_nxt+win, tp->rcv_adv))
E 23
E 22
		tp->rcv_adv = tp->rcv_nxt + win;
I 22
D 23
	}
E 23
E 22
D 19
	tp->snd_nxt += len;
	tp->t_flags &= ~(TF_OWEACK|TF_DELACK);
E 18
	if (flags & TH_FIN)
D 18
		len--;
I 13
	if (len < 0)
		panic("tcp_output");
E 13
D 11
	bcopy((caddr_t)t, mtod(m, caddr_t), sizeof (struct th));
	t = mtod(m, struct th *);
E 11
I 11
	bcopy((caddr_t)t, mtod(m, caddr_t), sizeof (struct tcpiphdr));
	t = mtod(m, struct tcpiphdr *);
E 11
	if (tp->tc_flags&TC_SND_RST) {
		flags &= ~TH_SYN;
		flags |= TH_RST;
E 18
I 18
		tp->snd_nxt++;
	if (SEQ_GT(tp->snd_nxt, tp->snd_hi)) {
		tp->snd_hi = tp->snd_nxt;
		/* TIME TRANSMIT */
E 18
	}
D 18
	if (tp->tc_flags&TC_SYN_RCVD)
		flags |= TH_ACK;
D 12
	t->th_flags = flags;
E 12
I 12
	t->ti_flags = flags;
E 12
	if (flags & TH_URG)
D 12
		t->t_urp = htons(tp->snd_urp);
	t->t_win =
E 12
I 12
D 13
		t->ti_urp = htons(tp->snd_urp);
E 13
I 13
		t->ti_urp = htons((u_short)tp->snd_urp);	/*XXX */
E 13
	t->ti_win =
E 12
D 10
	    tp->t_ucb->uc_rhiwat - (tp->t_ucb->uc_rcc + tp->seqcnt);
E 10
I 10
D 11
	    tp->t_socket->so_rcv.sb_hiwat -
		(tp->t_socket->so_rcv.sb_cc + tp->seqcnt);
E 11
I 11
	    so->so_rcv.sb_hiwat -
		(so->so_rcv.sb_cc + tp->seqcnt);
E 11
E 10
D 12
	if (tp->rcv_nxt + t->t_win > tp->rcv_adv)
		tp->rcv_adv = tp->rcv_nxt + t->t_win;
E 12
I 12
	if (tp->rcv_nxt + t->ti_win > tp->rcv_adv)
		tp->rcv_adv = tp->rcv_nxt + t->ti_win;
E 12
	if (len)
D 12
		t->t_len = htons(len + TCPSIZE);
	t->t_win = htons(t->t_win);
E 12
I 12
D 13
		t->ti_len = htons(len + TCPSIZE);
E 13
I 13
D 17
		t->ti_len = htons((u_short)(len + TCPSIZE));
E 17
I 17
		t->ti_len = htons((u_short)(len + sizeof (struct tcphdr)));
E 17
E 13
	t->ti_win = htons(t->ti_win);
E 12
D 17
#ifdef TCPDEBUG
D 10
	if ((tp->t_ucb->uc_flags & UDEBUG) || tcpconsdebug) {
E 10
I 10
D 11
	if ((tp->t_socket->so_options & SO_DEBUG) || tcpconsdebug) {
E 11
I 11
	if ((so->so_options & SO_DEBUG) || tcpconsdebug) {
E 11
E 10
D 12
		t->t_seq = tp->snd_nxt;
		t->t_ackno = tp->rcv_nxt;
E 12
I 12
		t->ti_seq = tp->snd_nxt;
		t->ti_ackno = tp->rcv_nxt;
E 12
		tdb_setup(tp, t, INSEND, &tdb);
		tdb_stuff(&tdb, -2);
	}
#endif
E 17
D 12
	t->t_seq = htonl(tp->snd_nxt);
	t->t_ackno = htonl(tp->rcv_nxt);
D 6
	t->t_sum = cksum(m, len + sizeof(struct th));
E 6
I 6
	t->t_sum = 0;		/* gratuitous? */
E 12
I 12
	t->ti_seq = htonl(tp->snd_nxt);
	t->ti_ackno = htonl(tp->rcv_nxt);
	t->ti_sum = 0;		/* gratuitous? */
E 12
D 11
	CKSUM_TCPSET(m, t, r9, sizeof (struct th) + len);
E 11
I 11
D 14
	CKSUM_TCPSET(m, t, r9, sizeof (struct tcpiphdr) + len);
E 14
I 14
	t->ti_sum = inet_cksum(m, sizeof (struct tcpiphdr) + len);
E 14
E 11
E 6
	ip = (struct ip *)t;
	ip->ip_v = IPVERSION;
	ip->ip_hl = 5;
	ip->ip_tos = 0;
D 11
	ip->ip_len = len + sizeof(struct th);
E 11
I 11
	ip->ip_len = len + sizeof(struct tcpiphdr);
E 11
	ip->ip_id = ip_id++;
	ip->ip_off = 0;
	ip->ip_ttl = MAXTTL;
D 14
	i = ip_send(ip);
D 2
#ifdef notdef
	if (tp->t_ucb->uc_flags & UDEBUG) {
		w.w_dat = (char *)t;
		w.w_stype = i;
		tcp_debug(tp, &w, INRECV, -1);
	}
#endif
E 2
D 10
	return(i);
E 10
I 10
	return (i);
E 14
I 14
	ip_send(ip);
	return (1);
E 18
I 18
	return;
E 19
I 19
	tp->t_flags &= ~(TF_ACKNOW|TF_DELACK);
D 22
	tp->snd_max = tp->snd_nxt;
E 22
I 22
D 42
	if (SEQ_GT(tp->snd_nxt, tp->snd_max))
		tp->snd_max = tp->snd_nxt;
E 42
I 40
D 68
	if (sendalot && tp->t_force == 0)
E 68
I 68
	if (sendalot)
E 68
		goto again;
E 40
E 22
D 38
	return (1);
E 38
I 38
	return (0);
I 40
}

tcp_setpersist(tp)
	register struct tcpcb *tp;
{

	if (tp->t_timer[TCPT_REXMT])
		panic("tcp_output REXMT");
	/*
	 * Start/restart persistance timer.
	 */
	TCPT_RANGESET(tp->t_timer[TCPT_PERSIST],
	    ((int)(tcp_beta * tp->t_srtt)) << tp->t_rxtshift,
	    TCPTV_PERSMIN, TCPTV_MAX);
	tp->t_rxtshift++;
	if (tp->t_rxtshift >= TCP_MAXRXTSHIFT)
		tp->t_rxtshift = 0;
E 40
E 38
E 19
E 18
E 14
E 10
D 11
}

firstempty(tp)
	register struct tcb *tp;
{
	register struct th *p, *q;
COUNT(FIRSTEMPTY);

D 10
	if ((p = tp->t_rcv_next) == (struct th *)tp || tp->rcv_nxt < p->t_seq)
E 10
I 10
	if ((p = tp->tcb_hd.seg_next) == (struct th *)tp ||
	    tp->rcv_nxt < p->t_seq)
E 10
		return (tp->rcv_nxt);
	while ((q = p->t_next) != (struct th *)tp &&
	    (t_end(p) + 1) == q->t_seq)
		p = q;
	return (t_end(p) + 1);
}

D 2
/* SHOULD BE A MACRO, AFTER KEEP TRACK OF ASS Q SPACE */

E 2
struct mbuf *
tcp_sndcopy(tp, start, end)
	struct tcb *tp;
	u_long start, end;
{
	register struct mbuf *m, *n, **np;
	u_long off;
	register int len;
	int adj;
	struct mbuf *top, *p;
D 8
COUNT(SND_COPY);
E 8
I 8
COUNT(TCP_SNDCOPY);
E 8

D 2
/*
	printf("st %x end %x off %x\n", start, end, tp->snd_off);
*/
E 2
	if (start >= end)    
D 10
		return(NULL);
E 10
I 10
		return (NULL);
E 10
	off = tp->snd_off;
D 10
	m = tp->t_ucb->uc_sbuf;
E 10
I 10
	m = tp->t_socket->so_snd.sb_mb;
E 10
	while (m != NULL && start >= (off + m->m_len)) {
		off += m->m_len;
		m = m->m_next;
	}
	np = &top;
	top = 0;
	adj = start - off;
	len = end - start;
	while (m && len > 0) {
		MGET(n, 1);
		*np = n;
		if (n == 0)
			goto nospace;
		n->m_len = MIN(len, m->m_len - adj);
		if (m->m_off > MMAXOFF) {
			p = mtod(m, struct mbuf *);
			n->m_off = ((int)p - (int)n) + adj;
			mprefcnt[mtopf(p)]++;
		} else {
			n->m_off = MMINOFF;
			bcopy(mtod(m, caddr_t)+adj, mtod(n, caddr_t),
			    n->m_len);
		}
		len -= n->m_len;
		adj = 0;
		m = m->m_next;
		/* SHOULD TRY PACKING INTO SMALL MBUFS HERE */
		np = &n->m_next;
	}
	/* SHOULD NEVER RUN OUT OF m WHEN LEN */
	if (len)
		printf("snd_copy: m %x len %d\n", m, len);
	return (top);
nospace:
	printf("snd_copy: no space\n");
	m_freem(top);
	return (0);
E 11
I 10
D 17
}

tcp_fasttimo()
{

I 15
COUNT(TCP_FASTTIMO);
	/* someday do delayed ack processing here */
E 17
E 15
E 10
D 5
}

tcp_enq(p, prev)
	register struct th *p;
	register struct th *prev;
{

	p->t_prev = prev;
	p->t_next = prev->t_next;
	prev->t_next->t_prev = p;
	prev->t_next = p;
}
 
tcp_deq(p)
	register struct th *p;
{

	p->t_prev->t_next = p->t_next;
	p->t_next->t_prev = p->t_prev;
E 5
}
E 1
