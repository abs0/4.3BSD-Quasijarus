h31689
s 00010/00005/00275
d D 7.14 88/06/29 17:07:39 bostic 65 64
c install approved copyright notice
e
s 00000/00001/00280
d D 7.13 88/05/14 11:22:07 karels 64 62
c ack immediately when segment is received out of order;
c remove tcpnodelack
e
s 00000/00000/00283
d D 7.11.1.2 88/03/16 09:34:18 karels 63 61
i 62
c update branch
e
s 00010/00005/00271
d D 7.12 88/03/16 09:05:06 karels 62 59
c much longer keepalive timer (don't start probes for 2 hr);
c fix input window test again (accept acks from FINS at left edge and responses
c to keepalives, but dropafterack otherwise; also fixes Phil Karn's problem
c with failure to respond to new SYN to left of window); can't use tcp_drop
c after RST, or we'll send RST in response
e
s 00002/00000/00276
d D 7.11.1.1 88/02/07 20:00:07 karels 61 59
c branch for FTP release (#ifdefs for non-4.3)
e
s 00002/00000/00276
d R 7.12 88/02/07 19:56:42 karels 60 59
c branch for FTP release (#ifdefs for non-4.3)
e
s 00008/00002/00268
d D 7.11 87/12/07 17:46:43 bostic 59 58
c use Berkeley specific header
e
s 00022/00000/00248
d D 7.10 87/09/04 09:37:59 karels 58 57
c two-phase slow start
e
s 00016/00012/00232
d D 7.9 87/08/10 20:53:36 karels 57 56
c Phil Karn's retransmit algorithm, using t_rxtcur for current rexmt value;
c slow start from beginning if connection not local; get rtt estimate on SYN
e
s 00001/00001/00243
d D 7.8 87/06/30 23:31:10 karels 56 55
c missed one
e
s 00010/00001/00234
d D 7.7 87/06/30 23:21:29 karels 55 54
c remove patchable keeplen, put old keepalives on opt TCP_COMPAT_42
e
s 00008/00014/00227
d D 7.6 87/06/30 23:15:39 karels 54 53
c redo retransmit calculations as srtt + 2*smoothed variance
c (from Van Jacobson)
e
s 00009/00000/00232
d D 7.5 87/06/06 20:20:42 karels 53 52
c slow-start changes from van
e
s 00002/00005/00230
d D 7.4 87/06/04 22:01:07 karels 52 51
c need data in keepalives for now for 4.2/ultrix compat
e
s 00008/00002/00227
d D 7.3 87/04/02 16:32:34 karels 51 50
c hack keepalives for now (for Ultrix, at least)
e
s 00018/00009/00211
d D 7.2 87/02/19 16:54:32 karels 50 49
c new stats; change keepalives to use rcv_nxt instead of rcv_nxt-1
c with no data (so we won't ignore the resets)
e
s 00001/00001/00219
d D 7.1 86/06/05 00:32:06 mckusick 49 48
c 4.3BSD release version
e
s 00003/00003/00217
d D 6.14 86/04/19 20:59:22 karels 48 47
c fix up FIN_WAIT_2 timeout: don't send keepalives, as the reset
c won't be received, but will reset idle time; don't reset idle time unless
c packet received
e
s 00001/00001/00219
d D 6.13 86/04/12 20:34:54 karels 47 46
c rename tcp compat so can use separately
e
s 00007/00006/00213
d D 6.12 86/04/01 12:03:59 karels 46 45
c readjust timer values so rerouting on connection attempt
c happens before timeout
e
s 00004/00000/00215
d D 6.11 86/02/08 15:30:29 karels 45 44
c ifdefs for 4.2 compat
e
s 00009/00014/00206
d D 6.10 86/01/13 16:14:09 karels 44 43
c faster backoff: multiply by beta, increase backoff (nearer exponential),
c convert to int
e
s 00001/00001/00219
d D 6.9 85/11/20 15:47:33 karels 43 42
c change tcp notification of transmission problems so that ip
c can delete routes created by redirect that have gone bad
e
s 00011/00005/00209
d D 6.8 85/09/16 23:22:52 karels 42 41
c more retransmits (wait longer than routed!); close FIN_WAIT_2's
c if user has closed and is inactive; fix comments
e
s 00007/00001/00207
d D 6.7 85/06/08 12:44:49 mckusick 41 40
c Add copyright
e
s 00004/00002/00204
d D 6.6 85/05/27 22:35:56 karels 40 39
c don't cancel round-trip timer on REXMT until 1 successful measurement
e
s 00007/00002/00199
d D 6.5 84/11/14 10:26:15 karels 39 38
c reallocate route if losing
e
s 00003/00003/00198
d D 6.4 84/11/01 13:40:12 karels 38 37
c don't loop in slowtimo if inpcb has no tcpcb
e
s 00005/00001/00196
d D 6.3 84/10/31 14:03:21 karels 37 35
c fix round-trip timing: rexmt timer shouldn't screw rtt up,
c but careful when retransmitting timed segment
e
s 00006/00001/00196
d R 6.3 84/10/18 11:09:41 karels 36 35
c fix round-trip timing: rexmt timer shouldn't screw rtt up,
c but careful when retransmitting timed segment
e
s 00018/00018/00179
d D 6.2 84/08/29 15:38:07 bloom 35 34
c Include file changes.  No more ../h
e
s 00000/00000/00197
d D 6.1 83/07/29 07:12:54 sam 34 33
c 4.2 distribution
e
s 00001/00002/00196
d D 4.32 83/05/27 13:46:06 sam 33 32
c lint
e
s 00002/00001/00196
d D 4.31 83/02/10 22:12:47 sam 32 31
c remove /usr/include dependencies
e
s 00011/00009/00186
d D 4.30 83/01/17 18:03:25 sam 31 30
c stuff from bill to insure no references are kept to free'd cb's
e
s 00000/00003/00195
d D 4.29 83/01/04 23:18:39 sam 30 29
c clean some stuff up and purge some crud
e
s 00005/00004/00193
d D 4.28 82/10/20 01:23:32 root 29 28
c lint
e
s 00002/00001/00195
d D 4.27 82/10/17 22:48:22 root 28 27
c lint
e
s 00011/00011/00185
d D 4.26 82/10/09 05:48:21 wnj 27 26
c localize header files
e
s 00000/00013/00196
d D 4.25 82/10/05 18:51:19 root 26 25
c m_get inits m_off; remove TCPTRUEOOB
e
s 00001/00001/00208
d D 4.24 82/06/26 22:04:14 sam 25 24
c use <errno.h>
e
s 00000/00004/00209
d D 4.23 82/06/20 00:56:13 sam 24 23
c purge COUNT stuff now that we can use gprof
e
s 00001/00000/00212
d D 4.22 82/06/12 23:20:00 wnj 23 22
c now the routing code might wokr
e
s 00001/00003/00211
d D 4.21 82/06/08 10:40:02 wnj 22 20
c fixes vis. a vis. persist timer
e
s 00001/00003/00211
d R 4.21 82/06/06 21:16:38 wnj 21 20
c fixes to persist timer
e
s 00014/00004/00200
d D 4.20 82/04/04 13:46:25 root 20 19
c slower backoff than exponential
e
s 00001/00000/00203
d D 4.19 82/03/29 11:33:56 sam 19 18
c first cut (incomplete) at routing
e
s 00007/00005/00196
d D 4.18 82/03/24 21:56:37 root 18 17
c fix keep alives and timeouts: checksum problem and doing keeps
c on all connections by mistake (still needs more work to do keeps more 
c persistantly!)
e
s 00013/00003/00188
d D 4.17 82/03/19 02:18:52 root 17 16
c fix to keep alive segments
e
s 00012/00006/00179
d D 4.16 82/03/15 04:45:24 wnj 16 15
c interfac queueing, restrictions on packets, tcp keep alives done 
c properly, bug fix to raw
e
s 00005/00004/00180
d D 4.15 82/02/25 13:13:15 wnj 15 14
c fixup rexmt timing
e
s 00007/00005/00177
d D 4.14 82/02/03 19:33:20 wnj 14 13
c bug fixes (but PERSIST still screwy)
e
s 00001/00001/00181
d D 4.13 82/01/19 01:57:11 wnj 13 12
c en.c: no more kludge; timer: no more printf on rexmt
e
s 00014/00001/00168
d D 4.12 82/01/17 21:20:25 wnj 12 11
c more work on out-of-band
e
s 00005/00001/00164
d D 4.11 82/01/13 10:43:57 wnj 11 10
c a number of minor changes
e
s 00021/00002/00144
d D 4.10 81/12/21 11:57:03 root 10 9
c patchable tcp_delack; fix rxtshift calculation
e
s 00001/00000/00145
d D 4.9 81/12/20 21:40:15 wnj 9 8
c race in if_en.c; no PERSIST before SYN; implement LETDATADRAIN
e
s 00002/00000/00143
d D 4.8 81/12/19 12:44:48 wnj 8 7
c watch out for tp==0
e
s 00000/00006/00143
d D 4.7 81/12/12 18:05:31 root 7 6
c clean out printf
e
s 00012/00001/00137
d D 4.6 81/12/12 12:59:18 root 6 5
c with crud (first working version)
e
s 00041/00013/00097
d D 4.5 81/12/02 17:00:06 wnj 5 4
c yet more lint
e
s 00001/00003/00109
d D 4.4 81/11/29 22:02:32 wnj 4 3
c lint and interface cleanups
e
s 00018/00011/00094
d D 4.3 81/11/26 11:58:11 wnj 3 2
c before carry to ARPAVAX
e
s 00022/00057/00083
d D 4.2 81/11/25 16:10:20 wnj 2 1
c listing
e
s 00140/00000/00000
d D 4.1 81/11/24 17:35:58 wnj 1 0
c date and time created 81/11/24 17:35:58 by wnj
e
u
U
f b 
t
T
I 1
D 22
/* %M% %I% %E% */
E 22
I 22
D 41
/*	%M%	%I%	%E%	*/
E 41
I 41
/*
D 49
 * Copyright (c) 1982 Regents of the University of California.
E 49
I 49
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 49
D 59
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 59
I 59
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 65
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 65
I 65
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
E 65
E 59
 *
 *	%W% (Berkeley) %G%
 */
E 41
E 22

D 35
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
D 27
#include "../net/in.h"
E 27
I 27
D 29
#include "../netinet/in.h"
E 29
I 29
D 32
#include <errno.h>
E 32
I 32
#include "../h/errno.h"
E 35
I 35
#include "param.h"
#include "systm.h"
#include "mbuf.h"
#include "socket.h"
#include "socketvar.h"
#include "protosw.h"
#include "errno.h"
E 35
E 32

#include "../net/if.h"
E 29
E 27
I 19
#include "../net/route.h"
I 32

E 32
I 29
D 35
#include "../netinet/in.h"
E 29
E 19
D 27
#include "../net/in_pcb.h"
#include "../net/in_systm.h"
E 27
I 27
#include "../netinet/in_pcb.h"
#include "../netinet/in_systm.h"
E 27
E 3
D 29
#include "../net/if.h"
E 29
D 3
#include "../net/imp.h"
E 3
D 27
#include "../net/ip.h"
#include "../net/ip_var.h"
#include "../net/tcp.h"
#include "../net/tcp_fsm.h"
I 3
#include "../net/tcp_seq.h"
#include "../net/tcp_timer.h"
E 3
#include "../net/tcp_var.h"
I 3
#include "../net/tcpip.h"
E 27
I 27
#include "../netinet/ip.h"
#include "../netinet/ip_var.h"
#include "../netinet/tcp.h"
#include "../netinet/tcp_fsm.h"
#include "../netinet/tcp_seq.h"
#include "../netinet/tcp_timer.h"
#include "../netinet/tcp_var.h"
#include "../netinet/tcpip.h"
E 35
I 35
#include "in.h"
#include "in_pcb.h"
#include "in_systm.h"
#include "ip.h"
#include "ip_var.h"
#include "tcp.h"
#include "tcp_fsm.h"
#include "tcp_seq.h"
#include "tcp_timer.h"
#include "tcp_var.h"
#include "tcpip.h"
E 35
E 27
E 3
D 4
#include "/usr/include/errno.h"
E 4
I 4
D 25
#include "../errno.h"
E 25
I 25
D 29
#include <errno.h>
E 29
E 25
E 4

I 10
D 12
int	tcpdelack = 0;
E 12
I 12
D 64
int	tcpnodelack = 0;
E 64
I 62
int	tcp_keepidle = TCPTV_KEEP_IDLE;
int	tcp_keepintvl = TCPTV_KEEPINTVL;
int	tcp_maxidle;
E 62
E 12
E 10
/*
 * Fast timeout routine for processing delayed acks
 */
tcp_fasttimo()
{
D 10

E 10
I 10
	register struct inpcb *inp;
	register struct tcpcb *tp;
	int s = splnet();
E 10
I 3
D 24
COUNT(TCP_FASTTIMO);
E 24
I 10

D 14
	for (inp = tcb.inp_next; inp != &tcb; inp = inp->inp_next)
E 14
I 14
	inp = tcb.inp_next;
	if (inp)
	for (; inp != &tcb; inp = inp->inp_next)
E 14
		if ((tp = (struct tcpcb *)inp->inp_ppcb) &&
		    (tp->t_flags & TF_DELACK)) {
			tp->t_flags &= ~TF_DELACK;
			tp->t_flags |= TF_ACKNOW;
I 50
			tcpstat.tcps_delack++;
E 50
			(void) tcp_output(tp);
		}
	splx(s);
E 10
E 3
}

/*
 * Tcp protocol timeout routine called every 500 ms.
 * Updates the timers in all active tcb's and
 * causes finite state machine actions if timers expire.
 */
tcp_slowtimo()
{
D 16
	register struct inpcb *ip;
E 16
I 16
	register struct inpcb *ip, *ipnxt;
E 16
	register struct tcpcb *tp;
	int s = splnet();
D 4
	register short *tmp;
E 4
	register int i;
D 3
COUNT(TCP_TIMEO);
E 3
I 3
D 24
COUNT(TCP_SLOWTIMO);
E 24
E 3

I 62
	tcp_maxidle = TCPTV_KEEPCNT * tcp_keepintvl;
E 62
	/*
	 * Search through tcb's and update active timers.
	 */
D 6
	for (ip = tcb.inp_next; ip != &tcb; ip = ip->inp_next) {
E 6
I 6
	ip = tcb.inp_next;
	if (ip == 0) {
		splx(s);
		return;
	}
D 16
	for (; ip != &tcb; ip = ip->inp_next) {
E 16
I 16
D 38
	while (ip != &tcb) {
E 38
I 38
	for (; ip != &tcb; ip = ipnxt) {
		ipnxt = ip->inp_next;
E 38
E 16
E 6
		tp = intotcpcb(ip);
I 8
		if (tp == 0)
			continue;
I 16
D 38
		ipnxt = ip->inp_next;
E 38
E 16
E 8
D 3
		tmp = &tp->t_init;
E 3
D 2
		for (i = 0; i < TNTIMERS; i++) {
E 2
I 2
		for (i = 0; i < TCPT_NTIMERS; i++) {
E 2
D 3
			if (*tmp && --*tmp == 0)
E 3
I 3
D 16
			if (tp->t_timer[i] && --tp->t_timer[i] == 0)
E 16
I 16
			if (tp->t_timer[i] && --tp->t_timer[i] == 0) {
E 16
E 3
				(void) tcp_usrreq(tp->t_inpcb->inp_socket,
				    PRU_SLOWTIMO, (struct mbuf *)0,
D 28
				    (caddr_t)i);
E 28
I 28
D 33
				    (struct mbuf *)i,
D 29
				    (struct sockopt *)0);
E 29
I 29
				    (struct socketopt *)0);
E 33
I 33
				    (struct mbuf *)i, (struct mbuf *)0);
E 33
E 29
E 28
I 16
				if (ipnxt->inp_prev != ip)
					goto tpgone;
			}
E 16
D 4
			tmp++;
E 4
		}
I 5
		tp->t_idle++;
		if (tp->t_rtt)
			tp->t_rtt++;
I 16
tpgone:
D 38
		ip = ipnxt;
E 38
I 38
		;
E 38
E 16
E 5
D 3
		tp->t_xmt++;
E 3
	}
D 2
	tcp_iss += ISSINCR/2;		/* increment iss */
E 2
I 2
	tcp_iss += TCP_ISSINCR/PR_SLOWHZ;		/* increment iss */
I 45
D 47
#ifdef COMPAT_42
E 47
I 47
#ifdef TCP_COMPAT_42
E 47
	if ((int)tcp_iss < 0)
		tcp_iss = 0;				/* XXX */
#endif
E 45
E 2
	splx(s);
}

/*
D 2
 * Cancel all timers for tcp tp.
E 2
I 2
 * Cancel all timers for TCP tp.
E 2
 */
D 3
tcp_tcancel(tp)
E 3
I 3
tcp_canceltimers(tp)
E 3
	struct tcpcb *tp;
{
D 2
	register short *tmp = &tp->t_init;
E 2
	register int i;

I 3
D 24
COUNT(TCP_CANCELTIMERS);
E 24
I 6
D 7
printf("tcp_canceltimers %x\n", tp);
E 7
E 6
E 3
D 2
	for (i = 0; i < TNTIMERS; i++)
		*tmp++ = 0;
E 2
I 2
	for (i = 0; i < TCPT_NTIMERS; i++)
		tp->t_timer[i] = 0;
E 2
}

I 15
D 20
int	tcprexmtprint;
E 20
I 20
D 44
float	tcp_backoff[TCP_MAXRXTSHIFT] =
D 42
    { 1.0, 1.2, 1.4, 1.7, 2.0, 3.0, 5.0, 8.0, 16.0, 32.0 };
E 42
I 42
    { 1.0, 1.2, 1.4, 1.7, 2.0, 3.0, 5.0, 8.0, 16.0, 32.0, 32.0, 32.0 };
E 42
D 30
int	tcprexmtprint = 0;
E 30
int	tcpexprexmtbackoff = 0;
E 44
I 44
D 54
int	tcp_backoff[TCP_MAXRXTSHIFT+1] =
    { 1, 2, 4, 6, 8, 10, 15, 20, 30, 30, 30, 30, 30 };
E 54
I 54
D 57
int	tcp_backoff[TCP_MAXRXTSHIFT] =
    { 2, 4, 8, 16, 32, 64, 64, 64, 64, 64, 64, 64 };
E 57
I 57
int	tcp_backoff[TCP_MAXRXTSHIFT + 1] =
    { 1, 2, 4, 8, 16, 32, 64, 64, 64, 64, 64, 64, 64 };
E 57
E 54
I 51
D 52
#ifdef TCP_COMPAT_42
int	tcp_keeplen = 1;
#else
int	tcp_keeplen = 0;
#endif
E 52
I 52

D 57
int	tcp_keeplen = 1;	/* must be nonzero for 4.2 compat- XXX */
E 52

E 57
E 51
E 44
E 20
E 15
/*
D 5
 * TCP timer went off processing.
E 5
I 5
 * TCP timer processing.
E 5
 */
I 31
struct tcpcb *
E 31
D 2
tcp_timers(tp, timertype)
E 2
I 2
tcp_timers(tp, timer)
E 2
	register struct tcpcb *tp;
D 2
	int timertype;
E 2
I 2
	int timer;
E 2
{
I 44
	register int rexmt;
E 44

D 24
COUNT(TCP_TIMERS);
E 24
I 6
D 7
printf("tcp_timers %x %d\n", tp, timer);
E 7
E 6
D 3
	switch (timertype) {
E 3
I 3
	switch (timer) {
E 3

I 5
	/*
D 42
	 * 2 MSL timeout in shutdown went off.  Delete connection
	 * control block.
E 42
I 42
	 * 2 MSL timeout in shutdown went off.  If we're closed but
	 * still waiting for peer to close and connection has been idle
	 * too long, or if 2MSL time is up from TIME_WAIT, delete connection
	 * control block.  Otherwise, check again in a bit.
E 42
	 */
E 5
D 2
	case TFINACK:		/* fin-ack timer */
		switch (tp->t_state) {
E 2
I 2
	case TCPT_2MSL:
D 31
		tcp_close(tp);
		return;
E 31
I 31
D 42
		tp = tcp_close(tp);
E 42
I 42
		if (tp->t_state != TCPS_TIME_WAIT &&
D 62
		    tp->t_idle <= TCPTV_MAXIDLE)
			tp->t_timer[TCPT_2MSL] = TCPTV_KEEP;
E 62
I 62
		    tp->t_idle <= tcp_maxidle)
			tp->t_timer[TCPT_2MSL] = tcp_keepintvl;
E 62
		else
			tp = tcp_close(tp);
E 42
		break;
E 31
E 2

I 5
	/*
	 * Retransmission timer went off.  Message has not
	 * been acked within retransmit interval.  Back off
D 39
	 * to a longer retransmit interval and retransmit all
	 * unacknowledged messages in the window.
E 39
I 39
	 * to a longer retransmit interval and retransmit one segment.
E 39
	 */
E 5
D 2
		case TIME_WAIT:
			/*
			 * We can be sure our ACK of foreign FIN was rcvd,
			 * and can close if no data left for user.
			 */
			if (rcv_empty(tp)) {
				tcp_disconnect(tp);
				return (CLOSED);
			}
			return (RCV_WAIT);			/* 17 */

		case CLOSING:
			tp->tc_flags |= TC_WAITED_2_ML;
			return (SAME);

		default:
			return (SAME);
E 2
I 2
	case TCPT_REXMT:
I 3
D 5
#if 0
E 3
		tp->t_xmtime <<= 1;
D 3
		if (tp->t_xmtime > TCPT_TOOLONG) {
E 3
I 3
		if (tp->t_xmtime > TCPSC_TOOLONG) {
E 3
			tcp_drop(tp, ETIMEDOUT);
			return;
E 2
		}
I 3
#endif
E 3
I 2
		tcp_output(tp);
E 5
I 5
D 54
		tp->t_rxtshift++;
I 14
		if (tp->t_rxtshift > TCP_MAXRXTSHIFT) {
E 54
I 54
D 57
		if (tp->t_rxtshift >= TCP_MAXRXTSHIFT) {
E 57
I 57
		if (++tp->t_rxtshift > TCP_MAXRXTSHIFT) {
			tp->t_rxtshift = TCP_MAXRXTSHIFT;
E 57
E 54
I 50
			tcpstat.tcps_timeoutdrop++;
E 50
D 31
			tcp_drop(tp, ETIMEDOUT);
			return;
E 31
I 31
			tp = tcp_drop(tp, ETIMEDOUT);
			break;
E 31
		}
I 50
		tcpstat.tcps_rexmttimeo++;
E 50
I 39
D 46
		/*
		 * If losing, let the lower level know
		 * and try for a better route.
		 */
D 42
		if (tp->t_rxtshift > TCP_MAXRXTSHIFT / 2)
E 42
I 42
		if (tp->t_rxtshift > TCP_MAXRXTSHIFT / 3)
E 42
D 43
			in_rtchange(tp->t_inpcb);
E 43
I 43
			in_losing(tp->t_inpcb);
E 46
E 43
E 39
E 14
D 44
		TCPT_RANGESET(tp->t_timer[TCPT_REXMT],
D 10
		    ((int)(2 * tp->t_srtt)) << tp->t_rxtshift,
E 10
I 10
D 15
		    ((int)(2 * tp->t_srtt)),
E 10
		    TCPTV_MIN, TCPTV_MAX);
E 15
I 15
		    (int)tp->t_srtt, TCPTV_MIN, TCPTV_MAX);
E 15
I 10
D 20
		TCPT_RANGESET(tp->t_timer[TCPT_REXMT],
		    tp->t_timer[TCPT_REXMT] << tp->t_rxtshift,
		    TCPTV_MIN, TCPTV_MAX);
E 20
I 20
		if (tcpexprexmtbackoff) {
			TCPT_RANGESET(tp->t_timer[TCPT_REXMT],
			    tp->t_timer[TCPT_REXMT] << tp->t_rxtshift,
E 44
I 44
D 54
		if (tp->t_srtt == 0)
			rexmt = tcp_beta * TCPTV_SRTTDFLT;
		else
			rexmt = (int)(tcp_beta * tp->t_srtt);
		rexmt *= tcp_backoff[tp->t_rxtshift - 1];
E 54
I 54
		rexmt = ((tp->t_srtt >> 2) + tp->t_rttvar) >> 1;
		rexmt *= tcp_backoff[tp->t_rxtshift];
D 57
		tp->t_rxtshift++;
E 54
		TCPT_RANGESET(tp->t_timer[TCPT_REXMT], rexmt,
E 44
D 56
			    TCPTV_MIN, TCPTV_MAX);
E 56
I 56
			    TCPTV_MIN, TCPTV_REXMTMAX);
E 57
I 57
		TCPT_RANGESET(tp->t_rxtcur, rexmt, TCPTV_MIN, TCPTV_REXMTMAX);
		tp->t_timer[TCPT_REXMT] = tp->t_rxtcur;
E 57
E 56
I 46
		/*
D 57
		 * If losing, let the lower level know
		 * and try for a better route.
E 57
I 57
		 * If losing, let the lower level know and try for
		 * a better route.  Also, if we backed off this far,
		 * our srtt estimate is probably bogus.  Clobber it
		 * so we'll take the next rtt measurement as our srtt;
		 * move the current srtt into rttvar to keep the current
		 * retransmit times until then.
E 57
		 */
D 57
		if (tp->t_rxtshift >= TCP_MAXRXTSHIFT / 4 ||
		    rexmt >= 10 * PR_SLOWHZ)
E 57
I 57
		if (tp->t_rxtshift > TCP_MAXRXTSHIFT / 4) {
I 61
#if BSD>=43
E 61
E 57
			in_losing(tp->t_inpcb);
I 61
#endif
E 61
I 57
			tp->t_rttvar += (tp->t_srtt >> 2);
			tp->t_srtt = 0;
		}
E 57
E 46
D 44
		} else {
			TCPT_RANGESET(tp->t_timer[TCPT_REXMT],
			    tp->t_timer[TCPT_REXMT] *
			        tcp_backoff[tp->t_rxtshift - 1],
			    TCPTV_MIN, TCPTV_MAX);
		}
E 44
E 20
D 14
		if (tp->t_timer[TCPT_REXMT] > TCPTV_MAXIDLE / 2) {
			tcp_drop(tp, ETIMEDOUT);
			return;
		}
E 14
E 10
I 9
D 13
printf("rexmt set to %d\n", tp->t_timer[TCPT_REXMT]);
E 13
I 13
D 15
/* printf("rexmt set to %d\n", tp->t_timer[TCPT_REXMT]); */
E 15
I 15
D 30
if (tcprexmtprint)
printf("rexmt set to %d\n", tp->t_timer[TCPT_REXMT]);
E 30
E 15
E 13
E 9
I 6
D 7
printf("rexmt timer now %d\n", tp->t_timer[TCPT_REXMT]);
E 7
E 6
		tp->snd_nxt = tp->snd_una;
D 37
		/* this only transmits one segment! */
E 37
I 37
		/*
D 40
		 * If timing a segment in this window, stop the timer.
E 40
I 40
D 54
		 * If timing a segment in this window,
		 * and we have already gotten some timing estimate,
		 * stop the timer.
E 54
I 54
		 * If timing a segment in this window, stop the timer.
E 54
E 40
		 */
D 40
		if (tp->t_rtt && SEQ_GT(tp->t_rtseq, tp->snd_una))
E 40
I 40
D 54
		if (tp->t_rtt && tp->t_srtt)
E 40
			tp->t_rtt = 0;
E 54
I 54
		tp->t_rtt = 0;
E 54
I 53
		/*
		 * Close the congestion window down to one segment
		 * (we'll open it by one segment for each ack we get).
		 * Since we probably have a window's worth of unacked
		 * data accumulated, this "slow start" keeps us from
		 * dumping all that data as back-to-back packets (which
		 * might overwhelm an intermediate gateway).
I 58
		 *
		 * There are two phases to the opening: Initially we
		 * open by one mss on each ack.  This makes the window
		 * size increase exponentially with time.  If the
		 * window is larger than the path can handle, this
		 * exponential growth results in dropped packet(s)
		 * almost immediately.  To get more time between 
		 * drops but still "push" the network to take advantage
		 * of improving conditions, we switch from exponential
		 * to linear window opening at some threshhold size.
		 * For a threshhold, we use half the current window
		 * size, truncated to a multiple of the mss.
		 *
		 * (the minimum cwnd that will give us exponential
		 * growth is 2 mss.  We don't allow the threshhold
		 * to go below this.)
E 58
		 */
I 58
		{
		u_int win = MIN(tp->snd_wnd, tp->snd_cwnd) / 2 / tp->t_maxseg;
		if (win < 2)
			win = 2;
E 58
		tp->snd_cwnd = tp->t_maxseg;
I 58
		tp->snd_ssthresh = win * tp->t_maxseg;
		}
E 58
E 53
E 37
		(void) tcp_output(tp);
E 5
D 31
		return;
E 31
I 31
		break;
E 31
E 2

I 5
	/*
	 * Persistance timer into zero window.
	 * Force a byte to be output, if possible.
	 */
E 5
D 2
	case TREXMT:		/* retransmission timer */
		if (tp->t_rexmt_val > tp->snd_una) {	 	/* 34 */
			/*
			 * Set so for a retransmission, increase rexmt time
			 * in case of multiple retransmissions.
			 */
			tp->snd_nxt = tp->snd_una;
			tp->tc_flags |= TC_REXMT;
			tp->t_xmtime = tp->t_xmtime << 1;
			if (tp->t_xmtime > T_REMAX)
				tp->t_xmtime = T_REMAX;
			(void) tcp_send(tp);
		}
		return (SAME);
E 2
I 2
	case TCPT_PERSIST:
I 50
		tcpstat.tcps_persisttimeo++;
E 50
I 23
		tcp_setpersist(tp);
E 23
D 5
		if (tcp_output(tp) == 0)
			tp->snd_wnd++, (void) tcp_output(tp), tp->snd_wnd--;
I 3
		/* reset? */
E 5
I 5
		tp->t_force = 1;
		(void) tcp_output(tp);
		tp->t_force = 0;
D 22
		TCPT_RANGESET(tp->t_timer[TCPT_PERSIST],
D 15
		    2 * tp->t_srtt, TCPTV_PERSMIN, TCPTV_MAX);
E 15
I 15
		    tcp_beta * tp->t_srtt, TCPTV_PERSMIN, TCPTV_MAX);
E 22
E 15
I 6
D 7
printf("persist timer now %d\n", tp->t_timer[TCPT_PERSIST]);
E 7
E 6
E 5
D 31
		return;
E 31
I 31
		break;
E 31
E 3
E 2

I 5
	/*
	 * Keep-alive timer went off; send something
	 * or drop connection if idle for too long.
	 */
E 5
D 2
	case TREXMTTL:		/* retransmit too long */
		if (tp->t_rtl_val > tp->snd_una) {		/* 36 */
			tcp_error(tp, ETIMEDOUT);
			return (CLOSED);
		}
		return (SAME);

	case TPERSIST:		/* persist timer */
		/*
		 * Force a byte send through closed window.
		 */
		tp->tc_flags |= TC_FORCE_ONE;
		(void) tcp_send(tp);
		return (SAME);
E 2
I 2
	case TCPT_KEEP:
I 50
		tcpstat.tcps_keeptimeo++;
E 50
I 3
D 5
		/* reset? */
E 5
I 5
D 18
		if (tp->t_state < TCPS_ESTABLISHED ||
		    tp->t_idle >= TCPTV_MAXIDLE) {
I 6
D 7
printf("drop because of keep alive\n");
E 7
E 6
			tcp_drop(tp, ETIMEDOUT);
			return;
		}
E 18
I 18
		if (tp->t_state < TCPS_ESTABLISHED)
			goto dropit;
E 18
I 6
D 7
printf("send keep alive\n");
E 7
E 6
D 11
		tcp_respond(tp->t_template, tp->rcv_nxt, tp->snd_una-1, 0);
E 11
I 11
D 16
		if (tp->t_inpcb->inp_socket->so_options & SO_NOKEEPALIVE)
			tp->t_idle = 0;
		else
E 16
I 16
D 17
		if (tp->t_inpcb->inp_socket->so_options & SO_KEEPALIVE)
E 17
I 17
D 48
		if (tp->t_inpcb->inp_socket->so_options & SO_KEEPALIVE) {
E 48
I 48
		if (tp->t_inpcb->inp_socket->so_options & SO_KEEPALIVE &&
		    tp->t_state <= TCPS_CLOSE_WAIT) {
E 48
I 18
D 62
		    	if (tp->t_idle >= TCPTV_MAXIDLE)
E 62
I 62
		    	if (tp->t_idle >= tcp_keepidle + tcp_maxidle)
E 62
				goto dropit;
E 18
			/*
D 50
			 * Saying tp->rcv_nxt-1 lies about what
			 * we have received, and by the protocol spec
			 * requires the correspondent TCP to respond.
			 * Saying tp->snd_una-1 causes the transmitted
			 * byte to lie outside the receive window; this
			 * is important because we don't necessarily
			 * have a byte in the window to send (consider
			 * a one-way stream!)
E 50
I 50
			 * Send a packet designed to force a response
			 * if the peer is up and reachable:
			 * either an ACK if the connection is still alive,
			 * or an RST if the peer has closed the connection
			 * due to timeout or reboot.
			 * Using sequence number tp->snd_una-1
			 * causes the transmitted zero-length segment
			 * to lie outside the receive window;
			 * by the protocol spec, this requires the
			 * correspondent TCP to respond.
E 50
			 */
I 50
			tcpstat.tcps_keepprobe++;
I 55
#ifdef TCP_COMPAT_42
			/*
			 * The keepalive packet must have nonzero length
			 * to get a 4.2 host to respond.
			 */
E 55
E 50
E 17
E 16
D 51
			tcp_respond(tp,
D 17
			    tp->t_template, tp->rcv_nxt, tp->snd_una-1, 0);
I 16
		else
E 17
I 17
D 50
			    tp->t_template, tp->rcv_nxt-1, tp->snd_una-1, 0);
E 50
I 50
			    tp->t_template, tp->rcv_nxt, tp->snd_una-1, 0);
E 51
I 51
			tcp_respond(tp, tp->t_template,
D 55
			    tp->rcv_nxt - tcp_keeplen, tp->snd_una - 1, 0);
E 55
I 55
			    tp->rcv_nxt - 1, tp->snd_una - 1, 0);
#else
			tcp_respond(tp, tp->t_template,
			    tp->rcv_nxt, tp->snd_una - 1, 0);
#endif
E 55
E 51
E 50
D 48
		} else
E 17
			tp->t_idle = 0;
E 48
I 48
D 62
		}
E 48
E 16
E 11
		tp->t_timer[TCPT_KEEP] = TCPTV_KEEP;
E 62
I 62
			tp->t_timer[TCPT_KEEP] = tcp_keepintvl;
		} else
			tp->t_timer[TCPT_KEEP] = tcp_keepidle;
E 62
I 18
D 31
		return;
E 31
I 31
		break;
E 31
	dropit:
I 50
		tcpstat.tcps_keepdrops++;
E 50
D 31
		tcp_drop(tp, ETIMEDOUT);
E 18
E 5
E 3
		return;
E 31
I 31
		tp = tcp_drop(tp, ETIMEDOUT);
		break;
E 31
I 12
D 26

#ifdef TCPTRUEOOB
	/*
	 * Out-of-band data retransmit timer.
	 */
	case TCPT_OOBREXMT:
		if (tp->t_flags & TF_NOOPT)
			return;
		(void) tcp_output(tp);
		TCPT_RANGESET(tp->t_timer[TCPT_OOBREXMT],
		    2 * tp->t_srtt, TCPTV_MIN, TCPTV_MAX);
		return;
#endif
E 26
E 12
E 2
	}
I 31
	return (tp);
E 31
D 2
	panic("tcp_timers");
	/*NOTREACHED*/
E 2
}
E 1
