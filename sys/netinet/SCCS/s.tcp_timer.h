h11123
s 00010/00005/00103
d D 7.6 88/06/29 17:07:42 bostic 22 21
c install approved copyright notice
e
s 00015/00009/00093
d D 7.5 88/03/16 09:05:22 karels 21 20
c much longer keepalive timer (don't start probes for 2 hr);
c fix input window test again (accept acks from FINS at left edge and responses
c to keepalives, but dropafterack otherwise; also fixes Phil Karn's problem
c with failure to respond to new SYN to left of window); can't use tcp_drop
c after RST, or we'll send RST in response
e
s 00008/00002/00094
d D 7.4 87/12/07 17:46:48 bostic 20 19
c use Berkeley specific header
e
s 00008/00023/00088
d D 7.3 87/06/30 23:15:41 karels 19 18
c redo retransmit calculations as srtt + 2*smoothed variance
c (from Van Jacobson)
e
s 00002/00001/00109
d D 7.2 87/06/04 22:01:41 karels 18 17
c add patchable tcp ttl
e
s 00001/00001/00109
d D 7.1 86/06/05 00:32:21 mckusick 17 16
c 4.3BSD release version
e
s 00001/00001/00109
d D 6.7 86/04/05 09:14:18 karels 16 15
c longer TTL's
e
s 00001/00001/00109
d D 6.6 86/04/01 12:04:10 karels 15 14
c readjust timer values so rerouting on connection attempt
c happens before timeout
e
s 00003/00001/00107
d D 6.5 86/01/13 16:45:49 karels 14 13
c define srtt to be assumed before connect; update comment
e
s 00012/00010/00096
d D 6.4 85/09/16 23:23:02 karels 13 12
c more retransmits (wait longer than routed!); close FIN_WAIT_2's
c if user has closed and is inactive; fix comments
e
s 00007/00001/00099
d D 6.3 85/06/08 12:45:08 mckusick 12 11
c Add copyright
e
s 00002/00001/00098
d D 6.2 85/04/17 09:51:13 karels 11 10
c explicitly set srtt to 0 at start, so we know when we have
c timing info
e
s 00000/00000/00099
d D 6.1 83/07/29 07:12:59 sam 10 9
c 4.2 distribution
e
s 00002/00009/00097
d D 4.9 82/12/20 12:37:44 sam 9 8
c forgot to purge this stuff somehow
e
s 00006/00006/00100
d D 4.8 82/06/06 21:16:46 wnj 8 7
c fixes to persist timer
e
s 00002/00000/00104
d D 4.7 82/02/03 19:33:26 wnj 7 6
c bug fixes (but PERSIST still screwy)
e
s 00009/00002/00095
d D 4.6 82/01/17 21:20:31 wnj 6 5
c more work on out-of-band
e
s 00003/00001/00094
d D 4.5 82/01/13 10:44:00 wnj 5 4
c a number of minor changes
e
s 00001/00001/00094
d D 4.4 81/12/21 10:59:39 root 4 3
c flip order of KEEP/PERSIST
e
s 00007/00006/00088
d D 4.3 81/12/12 12:59:22 root 3 2
c with crud (first working version)
e
s 00075/00012/00019
d D 4.2 81/12/02 17:00:11 wnj 2 1
c yet more lint
e
s 00031/00000/00000
d D 4.1 81/11/29 22:20:02 wnj 1 0
c date and time created 81/11/29 22:20:02 by wnj
e
u
U
t
T
I 1
D 12
/*	%M%	%I%	%E%	*/
E 12
I 12
/*
D 17
 * Copyright (c) 1982 Regents of the University of California.
E 17
I 17
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 17
D 20
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 20
I 20
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 22
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 22
I 22
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
E 22
E 20
 *
 *	%W% (Berkeley) %G%
 */
E 12

/*
 * Definitions of the TCP timers.  These timers are counted
 * down PR_SLOWHZ times a second.
 */
D 6
#define	TCPT_NTIMERS	4
E 6
I 6
D 9
#define	TCPT_NTIMERS	5
E 9
I 9
#define	TCPT_NTIMERS	4
E 9
E 6

#define	TCPT_REXMT	0		/* retransmit */
D 2
#define	TCPT_2MSL	1		/* 2*msl quiet time timer */
#define	TCPT_PERSIST	2		/* retransmit persistance */
#define	TCPT_KEEP	3		/* keep alive */
E 2
I 2
#define	TCPT_PERSIST	1		/* retransmit persistance */
#define	TCPT_KEEP	2		/* keep alive */
#define	TCPT_2MSL	3		/* 2*msl quiet time timer */
I 6
D 9
#ifdef TCPTRUEOOB
#define	TCPT_OOBREXMT	4		/* out-of-band rexmt */
#endif
E 9
E 6
E 2

I 2
/*
 * The TCPT_REXMT timer is used to force retransmissions.
 * The TCP has the TCPT_REXMT timer set whenever segments
 * have been sent for which ACKs are expected but not yet
 * received.  If an ACK is received which advances tp->snd_una,
 * then the retransmit timer is cleared (if there are no more
 * outstanding segments) or reset to the base value (if there
 * are more ACKs expected).  Whenever the retransmit timer goes off,
D 13
 * we retransmit all unacknowledged segments, and do an exponential
 * backoff on the retransmit timer.
E 13
I 13
 * we retransmit one unacknowledged segment, and do a backoff
 * on the retransmit timer.
E 13
 *
 * The TCPT_PERSIST timer is used to keep window size information
D 8
 * flowing even if the window goes shut.  If an output is attempted when there
 * is data ready to transmit, but nothing gets sent because the window
 * is shut, then we start the TCPT_PERSIST timer, and at intervals
 * send a single byte into the peers window to force him to update
E 8
I 8
 * flowing even if the window goes shut.  If all previous transmissions
 * have been acknowledged (so that there are no retransmissions in progress),
D 13
 * and the window is shut, then we start the TCPT_PERSIST timer, and at
 * intervals send a single byte into the peers window to force him to update
E 8
 * our window information.  We do this at most as often as TCPT_PERSMIN
 * time intervals, but no more frequently than the current estimate of
 * round-trip packet time.  The TCPT_PERSIST timer is cleared whenever
 * we receive a window update from the peer.
E 13
I 13
 * and the window is too small to bother sending anything, then we start
 * the TCPT_PERSIST timer.  When it expires, if the window is nonzero,
 * we go to transmit state.  Otherwise, at intervals send a single byte
 * into the peer's window to force him to update our window information.
 * We do this at most as often as TCPT_PERSMIN time intervals,
 * but no more frequently than the current estimate of round-trip
 * packet time.  The TCPT_PERSIST timer is cleared whenever we receive
 * a window update from the peer.
E 13
 *
 * The TCPT_KEEP timer is used to keep connections alive.  If an
D 21
 * connection is idle (no segments received) for TCPTV_KEEP amount of time,
 * but not yet established, then we drop the connection.  If the connection
 * is established, then we force the peer to send us a segment by sending:
E 21
I 21
 * connection is idle (no segments received) for TCPTV_KEEP_INIT amount of time,
 * but not yet established, then we drop the connection.  Once the connection
 * is established, if the connection is idle for TCPTV_KEEP_IDLE time
 * (and keepalives have been enabled on the socket), we begin to probe
 * the connection.  We force the peer to send us a segment by sending:
E 21
 *	<SEQ=SND.UNA-1><ACK=RCV.NXT><CTL=ACK>
 * This segment is (deliberately) outside the window, and should elicit
 * an ack segment in response from the peer.  If, despite the TCPT_KEEP
 * initiated segments we cannot elicit a response from a peer in TCPT_MAXIDLE
D 21
 * amount of time, then we drop the connection.
E 21
I 21
 * amount of time probing, then we drop the connection.
E 21
I 6
D 9
 *
 * The OOBREXMT timer is to force retransmissions of out-of-band indications.
 * Because out-of-band data is considered critical, it does not exponential
 * backoff, but runs at a multiple of smoothed round trip time until acked.
E 9
E 6
 */

E 2
D 3
#define	TCP_TTL		60		/* time to live for TCP segs */
E 3
I 3
D 16
#define	TCP_TTL		15		/* time to live for TCP segs */
E 16
I 16
D 18
#define	TCP_TTL		30		/* time to live for TCP segs */
E 18
I 18
#define	TCP_TTL		30		/* default time to live for TCP segs */
D 21
int	tcp_ttl;			/* time to live for TCP segs */
E 21
E 18
E 16
E 3
/*
D 2
 * TCPSC constants give various timeouts in ``slow-clock'' ticks.
E 2
I 2
 * Time constants.
E 2
 */
D 2
#define	TCPSC_MSL	(120*PR_SLOWHZ)		/* max seg lifetime */
#define	TCPSC_REXMT	(  1*PR_SLOWHZ)		/* base retransmit time */
#define	TCPSC_KEEP	(240*PR_SLOWHZ)		/* keep alive */
#define	TCPSC_PERSIST	(  5*PR_SLOWHZ)		/* retransmit persistance */
E 2
I 2
D 3
#define	TCPTV_MSL	(120*PR_SLOWHZ)		/* max seg lifetime */
E 3
I 3
D 13
#define	TCPTV_MSL	( 30*PR_SLOWHZ)		/* max seg lifetime */
E 13
I 13
D 21
#define	TCPTV_MSL	( 15*PR_SLOWHZ)		/* max seg lifetime */
E 21
I 21
#define	TCPTV_MSL	( 30*PR_SLOWHZ)		/* max seg lifetime (hah!) */
E 21
E 13
E 3
D 11
#define	TCPTV_SRTTBASE	(  1*PR_SLOWHZ)		/* base roundtrip time */
E 11
I 11
#define	TCPTV_SRTTBASE	0			/* base roundtrip time;
						   if 0, no idea yet */
I 14
D 15
#define	TCPTV_SRTTDFLT	(  5*PR_SLOWHZ)		/* assumed RTT if no info */
E 15
I 15
#define	TCPTV_SRTTDFLT	(  3*PR_SLOWHZ)		/* assumed RTT if no info */
E 15

E 14
E 11
D 3
#define	TCPTV_KEEP	(240*PR_SLOWHZ)		/* keep alive - 4 mins */
E 3
I 3
D 8
#define	TCPTV_KEEP	( 60*PR_SLOWHZ)		/* keep alive - 1 min */
E 8
I 8
D 19
#define	TCPTV_KEEP	( 45*PR_SLOWHZ)		/* keep alive - 45 secs */
E 19
E 8
E 3
#define	TCPTV_PERSMIN	(  5*PR_SLOWHZ)		/* retransmit persistance */
I 19
#define	TCPTV_PERSMAX	( 60*PR_SLOWHZ)		/* maximum persist interval */
E 19
E 2

I 19
D 21
#define	TCPTV_KEEP	( 75*PR_SLOWHZ)		/* keep alive - 75 secs */
E 19
D 2
#define	TCPSC_KEEPTTL	(  4*TCPSC_KEEP)	/* keep alive too long */
#define	TCPSC_2MSL	(  2*TCPSC_MSL)		/* 2*msl quiet time timer */
E 2
I 2
D 8
#define	TCPTV_MAXIDLE	(  4*TCPTV_KEEP)	/* maximum allowable idle
E 8
I 8
#define	TCPTV_MAXIDLE	(  8*TCPTV_KEEP)	/* maximum allowable idle
E 8
						   time before drop conn */
E 21
I 21
#define	TCPTV_KEEP_INIT	( 75*PR_SLOWHZ)		/* initial connect keep alive */
#define	TCPTV_KEEP_IDLE	(120*60*PR_SLOWHZ)	/* dflt time before probing */
#define	TCPTV_KEEPINTVL	( 75*PR_SLOWHZ)		/* default probe interval */
#define	TCPTV_KEEPCNT	8			/* max probes before drop */
E 21
E 2

D 2
#define	TCPSC_TOOLONG	(480*PR_SLOWHZ)
E 2
I 2
#define	TCPTV_MIN	(  1*PR_SLOWHZ)		/* minimum allowable value */
D 3
#define	TCPTV_MAX	(480*PR_SLOWHZ)		/* maximum allowable value */
E 3
I 3
D 5
#define	TCPTV_MAX	(120*PR_SLOWHZ)		/* maximum allowable value */
E 5
I 5
D 19
#define	TCPTV_MAX	( 30*PR_SLOWHZ)		/* maximum allowable value */
E 19
I 19
#define	TCPTV_REXMTMAX	( 64*PR_SLOWHZ)		/* max allowable REXMT value */
E 19

#define	TCP_LINGERTIME	120			/* linger at most 2 minutes */
E 5
E 3
E 2

I 7
D 13
#define	TCP_MAXRXTSHIFT	10			/* maximum retransmits */
E 13
I 13
#define	TCP_MAXRXTSHIFT	12			/* maximum retransmits */
E 13

E 7
#ifdef	TCPTIMERS
char *tcptimers[] =
D 2
    { "INIT", "REXMT", "REXMTTL", "KEEP", "KEEPTTL", "PERSIST", "2MSL" };
E 2
I 2
D 4
    { "REXMT", "KEEP", "PERSIST", "2MSL" };
E 4
I 4
D 6
    { "REXMT", "PERSIST", "KEEP", "2MSL" };
E 6
I 6
D 9
    { "REXMT", "PERSIST", "KEEP", "2MSL", "OOBREXMT" };
E 9
I 9
    { "REXMT", "PERSIST", "KEEP", "2MSL" };
E 9
E 6
E 4
E 2
#endif
I 2

/*
D 19
 * Retransmission smoothing constants.
 * Smoothed round trip time is updated by
 *    tp->t_srtt = (tcp_alpha * tp->t_srtt) + ((1 - tcp_alpha) * tp->t_rtt)
 * each time a new value of tp->t_rtt is available.  The initial
 * retransmit timeout is then based on
 *    tp->t_timer[TCPT_REXMT] = tcp_beta * tp->t_srtt;
D 14
 * limited, however to be at least TCPTV_REXMTLO and at most TCPTV_REXMTHI.
E 14
I 14
 * limited, however to be at least TCPTV_MIN and at most TCPTV_MAX.
E 14
 */
float	tcp_alpha, tcp_beta;

/*
 * Initial values of tcp_alpha and tcp_beta.
 * These are conservative: averaging over a long
 * period of time, and allowing for large individual deviations from
 * tp->t_srtt.
 */
#define	TCP_ALPHA	0.9
#define	TCP_BETA	2.0

/*
E 19
 * Force a time value to be in a certain range.
 */
D 3
#define	TCPT_RANGESET(tv, value, tvmin, tvmax) \
E 3
I 3
#define	TCPT_RANGESET(tv, value, tvmin, tvmax) { \
E 3
	(tv) = (value); \
	if ((tv) < (tvmin)) \
		(tv) = (tvmin); \
D 19
	if ((tv) > (tvmax)) \
E 19
I 19
	else if ((tv) > (tvmax)) \
E 19
D 3
		(tv) = (tvmax);
E 3
I 3
		(tv) = (tvmax); \
}
I 19

#ifdef KERNEL
I 21
extern int tcp_keepidle;		/* time before keepalive probes begin */
extern int tcp_keepintvl;		/* time between keepalive probes */
extern int tcp_maxidle;			/* time to drop after starting probes */
extern int tcp_ttl;			/* time to live for TCP segs */
E 21
extern int tcp_backoff[];
#endif
E 19
E 3
E 2
E 1
