h02827
s 00010/00005/00147
d D 7.4 88/06/27 18:53:09 bostic 34 33
c install approved copyright notice
e
s 00008/00002/00144
d D 7.3 87/12/30 11:59:24 bostic 33 32
c add Berkeley header
e
s 00014/00014/00132
d D 7.2 87/06/17 22:08:30 karels 32 31
c use longs for sockbuf counters, it fits!
e
s 00001/00001/00145
d D 7.1 86/06/04 23:28:09 mckusick 31 30
c 4.3BSD release version
e
s 00000/00002/00146
d D 6.11 86/02/23 23:00:57 karels 30 29
c lint
e
s 00004/00002/00144
d D 6.10 86/02/17 01:15:03 karels 29 28
c return read/writable if there's an error to be noticed
e
s 00003/00003/00143
d D 6.9 85/12/19 16:45:02 karels 28 27
c more cleanups; make so_oobmark unsigned too
e
s 00002/00001/00144
d D 6.8 85/12/18 14:31:18 sklower 27 26
c use signed arithmetic in calculating sbspace.
e
s 00006/00006/00139
d D 6.7 85/12/11 18:54:35 karels 26 25
c (gulp) make sockbufs use unsigned shorts for buffer counts
e
s 00007/00001/00138
d D 6.6 85/06/08 15:08:01 mckusick 25 24
c Add copyright
e
s 00001/00000/00138
d D 6.5 84/12/20 15:40:59 karels 24 23
c define SB_MAX
e
s 00002/00000/00136
d D 6.4 84/08/21 10:16:29 karels 23 22
c add RIGHTS type for mbufs, use m_act correctly for queuing datagrams
c (for sam)
e
s 00001/00001/00135
d D 6.3 84/03/22 20:05:05 karels 22 21
c don't need to send all at once if NBIO (only PR_ATOMIC)
e
s 00002/00002/00134
d D 6.2 84/01/11 15:58:38 cooper 21 20
c redefined sorwakeup and sowwakeup to use new sowakeup function
e
s 00000/00000/00136
d D 6.1 83/07/29 06:14:04 sam 20 19
c 4.2 distribution
e
s 00001/00001/00135
d D 4.19 82/07/24 18:20:31 root 19 18
c restore sccs ids
e
s 00000/00000/00136
d D 4.18 82/07/24 18:19:15 root 18 17
c from calder
e
s 00032/00008/00104
d D 4.17 82/07/24 18:09:24 root 17 16
c merge with calder
e
s 00000/00001/00112
d D 4.16 82/04/10 23:44:48 sam 16 15
c purge so_addr and add PRU_SOCKADDR as replacement
e
s 00013/00009/00100
d D 4.15 82/03/15 04:48:53 wnj 15 14
c name changes; get/sethostname
e
s 00002/00002/00107
d D 4.14 82/01/19 07:17:39 root 14 13
c core ()ization
e
s 00004/00001/00105
d D 4.13 82/01/19 04:36:28 root 13 12
c more sophisticated socket writeable criterion
e
s 00003/00001/00103
d D 4.12 82/01/17 01:04:05 wnj 12 11
c outofband
e
s 00002/00001/00102
d D 4.11 82/01/13 10:54:26 wnj 11 10
c add so_linger
e
s 00001/00001/00102
d D 4.10 81/12/02 17:26:23 wnj 10 9
c more cleanup
e
s 00002/00002/00101
d D 4.9 81/11/26 11:54:17 wnj 9 8
c before carry to arpavax
e
s 00003/00002/00100
d D 4.8 81/11/20 14:27:54 wnj 8 7
c more lint
e
s 00002/00002/00100
d D 4.7 81/11/20 01:18:47 wnj 7 6
c so_addr
e
s 00005/00010/00097
d D 4.6 81/11/20 00:48:02 wnj 6 5
c linted
e
s 00000/00000/00107
d D 4.5 81/11/18 15:47:07 wnj 5 4
c more cleanup
e
s 00005/00001/00102
d D 4.4 81/11/16 14:24:49 wnj 4 3
c more lint
e
s 00071/00005/00032
d D 4.3 81/11/14 16:51:19 wnj 3 2
c just before overlay of ip
e
s 00000/00000/00037
d D 4.2 81/11/08 16:40:12 wnj 2 1
c first listing
e
s 00037/00000/00000
d D 4.1 81/11/07 16:35:48 wnj 1 0
c date and time created 81/11/07 16:35:48 by wnj
e
u
U
t
T
I 1
D 8
/* %M% %I% %E% */
E 8
I 8
D 17
/*	%M%	%I%	%E%	*/
E 17
I 17
D 19
/*	socketvar.h	4.17	82/07/21	*/
E 19
I 19
D 25
/*	%M%	%I%	%E%	*/
E 25
I 25
/*
D 31
 * Copyright (c) 1982 Regents of the University of California.
E 31
I 31
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 31
D 33
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 33
I 33
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 34
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 34
I 34
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
E 34
E 33
 *
 *	%W% (Berkeley) %G%
 */
E 25
E 19
E 17
E 8

/*
 * Kernel structure per socket.
 * Contains send and receive buffer queues,
 * handle on protocol and pointer to protocol
 * private data and error information.
 */
struct socket {
	short	so_type;		/* generic type, see socket.h */
	short	so_options;		/* from socket call, see socket.h */
I 11
	short	so_linger;		/* time to linger while closing */
E 11
I 3
	short	so_state;		/* internal state flags SS_*, below */
D 6
	short	so_isfilerefd;		/* no file table reference */
E 6
E 3
	caddr_t	so_pcb;			/* protocol control block */
	struct	protosw *so_proto;	/* protocol handle */
I 17
/*
 * Variables for connection queueing.
 * Socket where accepts occur is so_head in all subsidiary sockets.
 * If so_head is 0, socket is not related to an accept.
 * For head socket so_q0 queues partially completed connections,
 * while so_q is a queue of connections ready to be accepted.
 * If a connection is aborted and it has so_head set, then
 * it has to be pulled out of either so_q0 or so_q.
 * We allow connections to queue up based on current queue lengths
 * and limit on number of queued connections for this socket.
 */
	struct	socket *so_head;	/* back pointer to accept socket */
	struct	socket *so_q0;		/* queue of partial connections */
D 32
	short	so_q0len;		/* partials on so_q0 */
E 32
	struct	socket *so_q;		/* queue of incoming connections */
I 32
	short	so_q0len;		/* partials on so_q0 */
E 32
	short	so_qlen;		/* number of connections on so_q */
	short	so_qlimit;		/* max number queued connections */
I 32
	short	so_timeo;		/* connection timeout */
	u_short	so_error;		/* error affecting connection */
	short	so_pgrp;		/* pgrp for signals */
	u_long	so_oobmark;		/* chars to oob mark */
E 32
/*
 * Variables for socket buffering.
 */
E 17
	struct	sockbuf {
D 3
		short	sb_cc;		/* characters in buffer */
		short	sb_hiwat;	/* max chars for buffer */
		short	sb_mbcnt;	/* # mbufs in use */
		short	sb_mbmax;	/* max # mbufs to use */
E 3
I 3
D 26
		short	sb_cc;		/* actual chars in buffer */
		short	sb_hiwat;	/* max actual char count */
		short	sb_mbcnt;	/* chars of mbufs used */
		short	sb_mbmax;	/* max chars of mbufs to use */
E 3
		short	sb_lowat;	/* low water mark (not used yet) */
E 26
I 26
D 32
		u_short	sb_cc;		/* actual chars in buffer */
		u_short	sb_hiwat;	/* max actual char count */
		u_short	sb_mbcnt;	/* chars of mbufs used */
		u_short	sb_mbmax;	/* max chars of mbufs to use */
		u_short	sb_lowat;	/* low water mark (not used yet) */
E 26
		short	sb_timeo;	/* timeout (not used yet) */
E 32
I 32
		u_long	sb_cc;		/* actual chars in buffer */
		u_long	sb_hiwat;	/* max actual char count */
		u_long	sb_mbcnt;	/* chars of mbufs used */
		u_long	sb_mbmax;	/* max chars of mbufs to use */
		u_long	sb_lowat;	/* low water mark (not used yet) */
E 32
		struct	mbuf *sb_mb;	/* the mbuf chain */
		struct	proc *sb_sel;	/* process selecting read/write */
I 32
		short	sb_timeo;	/* timeout (not used yet) */
E 32
		short	sb_flags;	/* flags, see below */
	} so_rcv, so_snd;
I 24
D 26
#define	SB_MAX		32767		/* max chars in sockbuf */
E 26
I 26
D 32
#define	SB_MAX		65535		/* max chars in sockbuf */
E 32
I 32
#define	SB_MAX		(64*1024)	/* max chars in sockbuf */
E 32
E 26
E 24
D 7
#define	SB_LOCK		0x01		/* lock on data queue (so_rcv only) */
#define	SB_WANT		0x02		/* someone is waiting to lock */
E 7
I 7
D 8
#define	SB_LOCK		0x01		/* lock on data queue (so_rcv only) */ #define	SB_WANT		0x02		/* someone is waiting to lock */
E 8
I 8
#define	SB_LOCK		0x01		/* lock on data queue (so_rcv only) */
#define	SB_WANT		0x02		/* someone is waiting to lock */
E 8
E 7
#define	SB_WAIT		0x04		/* someone is waiting for data/space */
#define	SB_SEL		0x08		/* buffer is selected */
#define	SB_COLL		0x10		/* collision selecting */
D 12
	/* need something for async wakeup */
E 12
D 32
	short	so_timeo;		/* connection timeout */
D 10
	u_short	so_error;		/* error indicator */
E 10
I 10
	u_short	so_error;		/* error affecting connection */
E 10
I 7
D 16
	struct	sockaddr so_addr;	/* socket address */
E 16
I 12
D 28
	short	so_oobmark;		/* chars to oob mark */
E 28
I 28
	u_short	so_oobmark;		/* chars to oob mark */
E 28
	short	so_pgrp;		/* pgrp for signals */
E 32
E 12
E 7
};

/*
D 3
 * Option bits and socket types are defined in socket.h.
E 3
I 3
 * Socket state bits.
E 3
 */
I 3
D 15
#define	SS_USERGONE		0x01	/* no file table ref any more */
#define	SS_ISCONNECTED		0x02	/* socket connected to a peer */
D 6
#define	SS_ISCONNECTING		0x03	/* in process of connecting to peer */
#define	SS_ISDISCONNECTING	0x04	/* in process of disconnecting */
#define	SS_CANTSENDMORE		0x08	/* can't send more data to peer */
#define	SS_CANTRCVMORE		0x10	/* can't receive more data from peer */
#define	SS_CONNAWAITING		0x20	/* connections awaiting acceptance */
E 6
I 6
#define	SS_ISCONNECTING		0x04	/* in process of connecting to peer */
#define	SS_ISDISCONNECTING	0x08	/* in process of disconnecting */
#define	SS_CANTSENDMORE		0x10	/* can't send more data to peer */
#define	SS_CANTRCVMORE		0x20	/* can't receive more data from peer */
#define	SS_CONNAWAITING		0x40	/* connections awaiting acceptance */
I 12
#define	SS_RCVATMARK		0x80	/* at mark on input */
E 15
I 15
D 17
#define	SS_USERGONE		0x001	/* no file table ref any more */
E 17
I 17
#define	SS_NOFDREF		0x001	/* no file table ref any more */
E 17
#define	SS_ISCONNECTED		0x002	/* socket connected to a peer */
#define	SS_ISCONNECTING		0x004	/* in process of connecting to peer */
#define	SS_ISDISCONNECTING	0x008	/* in process of disconnecting */
#define	SS_CANTSENDMORE		0x010	/* can't send more data to peer */
#define	SS_CANTRCVMORE		0x020	/* can't receive more data from peer */
D 17
#define	SS_CONNAWAITING		0x040	/* connections awaiting acceptance */
#define	SS_RCVATMARK		0x080	/* at mark on input */
E 17
I 17
#define	SS_RCVATMARK		0x040	/* at mark on input */
E 17
E 15
E 12
E 6

I 15
D 17
#define	SS_PRIV			0x100	/* privileged for broadcast, raw... */
#define	SS_NBIO			0x200	/* non-blocking ops */
#define	SS_ASYNC		0x400	/* async i/o notify */
E 17
I 17
#define	SS_PRIV			0x080	/* privileged for broadcast, raw... */
#define	SS_NBIO			0x100	/* non-blocking ops */
#define	SS_ASYNC		0x200	/* async i/o notify */
E 17

I 17

E 17
E 15
/*
 * Macros for sockets and socket buffering.
 */

/* how much space is there in a socket buffer (so->so_snd or so->so_rcv) */
#define	sbspace(sb) \
D 27
    (MIN((sb)->sb_hiwat-(sb)->sb_cc, ((sb)->sb_mbmax-(sb)->sb_mbcnt)))
E 27
I 27
D 28
    (MIN((((int)(sb)->sb_hiwat)-(int)(sb)->sb_cc),\
	 (((int)(sb)->sb_mbmax)-(int)(sb)->sb_mbcnt)))
E 28
I 28
D 32
    (MIN((int)((sb)->sb_hiwat - (sb)->sb_cc),\
	 (int)((sb)->sb_mbmax - (sb)->sb_mbcnt)))
E 32
I 32
    (MIN((long)((sb)->sb_hiwat - (sb)->sb_cc),\
	 (long)((sb)->sb_mbmax - (sb)->sb_mbcnt)))
E 32
E 28
E 27

/* do we have to send all at once on a socket? */
#define	sosendallatonce(so) \
D 11
    (((so)->so_options & SO_NBIO) || ((so)->so_proto->pr_flags & PR_ATOMIC))
E 11
I 11
D 15
    (((so)->so_options & SO_NONBLOCKING) || ((so)->so_proto->pr_flags & PR_ATOMIC))
E 15
I 15
D 22
    (((so)->so_state & SS_NBIO) || ((so)->so_proto->pr_flags & PR_ATOMIC))
E 22
I 22
    ((so)->so_proto->pr_flags & PR_ATOMIC)
E 22
E 15
E 11

/* can we read something from so? */
#define	soreadable(so) \
D 17
    ((so)->so_rcv.sb_cc || ((so)->so_state & (SS_CANTRCVMORE|SS_CONNAWAITING)))
E 17
I 17
D 29
    ((so)->so_rcv.sb_cc || ((so)->so_state & SS_CANTRCVMORE) || (so)->so_qlen)
E 29
I 29
    ((so)->so_rcv.sb_cc || ((so)->so_state & SS_CANTRCVMORE) || \
	(so)->so_qlen || (so)->so_error)
E 29
E 17

I 4
/* can we write something to so? */
#define	sowriteable(so) \
D 13
    (sbspace(&(so)->so_snd) > 0 || ((so)->so_state & SS_CANTSENDMORE))
E 13
I 13
D 14
    ((sbspace(&(so)->so_snd) > 0 && \
E 14
I 14
    (sbspace(&(so)->so_snd) > 0 && \
E 14
	(((so)->so_state&SS_ISCONNECTED) || \
D 14
	  (so)->so_proto->pr_flags&PR_CONNREQUIRED)==0) || \
E 14
I 14
	  ((so)->so_proto->pr_flags&PR_CONNREQUIRED)==0) || \
E 14
D 29
     ((so)->so_state & SS_CANTSENDMORE))
E 29
I 29
     ((so)->so_state & SS_CANTSENDMORE) || \
     (so)->so_error)
E 29
E 13

E 4
/* adjust counters in sb reflecting allocation of m */
#define	sballoc(sb, m) { \
	(sb)->sb_cc += (m)->m_len; \
	(sb)->sb_mbcnt += MSIZE; \
	if ((m)->m_off > MMAXOFF) \
D 9
		(sb)->sb_mbcnt += PGSIZE; \
E 9
I 9
		(sb)->sb_mbcnt += CLBYTES; \
E 9
}

/* adjust counters in sb reflecting freeing of m */
#define	sbfree(sb, m) { \
	(sb)->sb_cc -= (m)->m_len; \
	(sb)->sb_mbcnt -= MSIZE; \
	if ((m)->m_off > MMAXOFF) \
D 9
		(sb)->sb_mbcnt -= PGSIZE; \
E 9
I 9
		(sb)->sb_mbcnt -= CLBYTES; \
E 9
}

/* set lock on sockbuf sb */
#define sblock(sb) { \
	while ((sb)->sb_flags & SB_LOCK) { \
		(sb)->sb_flags |= SB_WANT; \
		sleep((caddr_t)&(sb)->sb_flags, PZERO+1); \
	} \
	(sb)->sb_flags |= SB_LOCK; \
}

/* release lock on sockbuf sb */
#define	sbunlock(sb) { \
	(sb)->sb_flags &= ~SB_LOCK; \
	if ((sb)->sb_flags & SB_WANT) { \
		(sb)->sb_flags &= ~SB_WANT; \
		wakeup((caddr_t)&(sb)->sb_flags); \
	} \
}

D 21
#define	sorwakeup(so)	sbwakeup(&(so)->so_rcv)
#define	sowwakeup(so)	sbwakeup(&(so)->so_snd)
E 21
I 21
#define	sorwakeup(so)	sowakeup((so), &(so)->so_rcv)
#define	sowwakeup(so)	sowakeup((so), &(so)->so_snd)
E 21
I 17

#ifdef KERNEL
struct	socket *sonewconn();
I 23
D 30
struct	mbuf *sbdrop();
struct	mbuf *sbdroprecord();
E 30
E 23
#endif
E 17
D 6

#ifdef KERNEL
D 4
struct	mbuf *sb_copy();
E 4
I 4
struct	mbuf *sbcopy();
E 4
#endif
E 6
E 3
E 1
