h57127
s 00010/00005/00223
d D 7.8 88/06/29 17:07:49 bostic 36 35
c install approved copyright notice
e
s 00072/00000/00156
d D 7.7 88/02/27 17:19:27 karels 35 31
c add ifdef for IP_MAXPACKET
e
s 00000/00000/00224
d R 7.6.1.3 88/02/27 13:17:30 karels 34 33
c add #ifdef for IP_MAXPACKET
e
s 00021/00000/00203
d D 7.6.1.2 88/02/22 10:22:42 karels 33 32
c move stats known in 4.[23] to top on ifdef for netstat compat
e
s 00047/00000/00156
d D 7.6.1.1 88/02/07 19:56:50 karels 32 31
c branch for FTP release (#ifdefs for non-4.3)
e
s 00008/00002/00148
d D 7.6 87/12/07 17:46:57 bostic 31 30
c use Berkeley specific header
e
s 00007/00003/00143
d D 7.5 87/09/04 09:37:34 karels 30 29
c two-phase slow start; pack again
e
s 00002/00001/00144
d D 7.4 87/08/10 20:53:38 karels 29 28
c Phil Karn's retransmit algorithm, using t_rxtcur for current rexmt value;
c slow start from beginning if connection not local; get rtt estimate on SYN
e
s 00007/00002/00138
d D 7.3 87/06/30 23:15:43 karels 28 27
c redo retransmit calculations as srtt + 2*smoothed variance
c (from Van Jacobson)
e
s 00053/00005/00087
d D 7.2 87/02/19 17:01:37 karels 27 26
c new stats
e
s 00001/00001/00091
d D 7.1 86/06/05 00:33:11 mckusick 26 25
c 4.3BSD release version
e
s 00002/00001/00090
d D 6.7 86/04/13 21:43:46 karels 25 24
c more correct fix for TCP FIN seq problem: need to predecrement send_nxt
c when resending FIN (for ack, etc.) but not retransmitting
e
s 00005/00005/00086
d D 6.6 86/01/13 17:26:53 karels 24 23
c add flag to avoid delay of short packets (Nagle algorithm)
e
s 00001/00000/00090
d D 6.5 85/10/23 18:22:02 karels 23 22
c maintain estimates of peer's send and receive buffer sizes;
c don't wait for bigger window if he hasn't got one
e
s 00002/00001/00088
d D 6.4 85/09/16 23:29:29 karels 22 21
c move ip options to inpcb; read oob data once only; add var
c for smarter delack code (maybe)
e
s 00007/00001/00082
d D 6.3 85/06/08 12:46:05 mckusick 21 20
c Add copyright
e
s 00004/00001/00079
d D 6.2 84/11/14 10:17:17 karels 20 19
c add snd_cwndw to decrease outstanding data after a source quench
e
s 00000/00000/00080
d D 6.1 83/07/29 07:13:19 sam 19 18
c 4.2 distribution
e
s 00002/00000/00078
d D 4.18 83/01/17 18:05:40 sam 18 17
c stuff from bill to insure no references are kept to free'd cb's
e
s 00000/00012/00078
d D 4.17 82/12/20 12:37:51 sam 17 16
c forgot to purge this stuff somehow
e
s 00002/00001/00088
d D 4.16 82/01/18 19:44:00 wnj 16 15
c out-of-band fixed up
e
s 00017/00006/00072
d D 4.15 82/01/17 21:20:52 wnj 15 14
c more work on out-of-band
e
s 00003/00000/00075
d D 4.14 82/01/17 01:00:15 wnj 14 13
c out of band
e
s 00004/00004/00071
d D 4.13 81/12/12 12:59:40 root 13 12
c with crud (first working version)
e
s 00001/00001/00074
d D 4.12 81/12/09 21:13:15 wnj 12 11
c rcv_wnd to short
e
s 00009/00006/00066
d D 4.11 81/12/02 17:00:32 wnj 11 10
c yet more lint
e
s 00000/00004/00072
d D 4.10 81/11/29 22:03:35 wnj 10 9
c lint and interface cleanups
e
s 00017/00077/00059
d D 4.9 81/11/26 11:58:45 wnj 9 8
c before carry to ARPAVAX
e
s 00023/00038/00113
d D 4.8 81/11/25 16:10:39 wnj 8 7
c listing
e
s 00089/00118/00062
d D 4.7 81/11/24 17:34:16 wnj 7 6
c start rewrite
e
s 00011/00014/00169
d D 4.6 81/11/24 07:54:25 wnj 6 5
c minor fixups pre tcp<->spec coordination
e
s 00009/00000/00174
d D 4.5 81/11/18 15:38:38 wnj 5 4
c more cleanup
e
s 00002/00002/00172
d D 4.4 81/11/16 14:18:21 wnj 4 3
c more lint
e
s 00029/00004/00145
d D 4.3 81/11/15 13:00:56 wnj 3 2
c listing
e
s 00017/00021/00132
d D 4.2 81/11/14 16:38:59 wnj 2 1
c before overlay
e
s 00153/00000/00000
d D 4.1 81/11/08 16:36:27 wnj 1 0
c date and time created 81/11/08 16:36:27 by wnj
e
u
U
f b 
t
T
I 1
D 21
/*	%M%	%I%	%E%	*/
E 21
I 21
/*
D 26
 * Copyright (c) 1982 Regents of the University of California.
E 26
I 26
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 26
D 31
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 31
I 31
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 36
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 36
I 36
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
E 36
E 31
 *
 *	%W% (Berkeley) %G%
 */
E 21

/*
I 35
 * TCP configuration:  This is a half-assed attempt to make TCP
 * self-configure for a few varieties of 4.2 and 4.3-based unixes.
 * If you don't have a) a 4.3bsd vax or b) a 3.x Sun (x<6), check
 * this carefully (it's probably not right).  Please send me mail
 * if you run into configuration problems.
 *  - Van Jacobson (van@lbl-csam.arpa)
 */

#ifndef BSD
#define BSD 42	/* if we're not 4.3, pretend we're 4.2 */
#define OLDSTAT	/* set if we have to use old netstat binaries */
#endif

/* #define OLDSTAT	/* set if we have to use old netstat binaries */

#if sun || BSD < 43
#define TCP_COMPAT_42	/* set if we have to interop w/4.2 systems */
#endif

#ifndef SB_MAX
#ifdef	SB_MAXCOUNT
#define	SB_MAX	SB_MAXCOUNT	/* Sun has to be a little bit different... */
#else
#define SB_MAX	32767		/* XXX */
#endif	SB_MAXCOUNT
#endif	SB_MAX

#ifndef IP_MAXPACKET
#define	IP_MAXPACKET	65535		/* maximum packet size */
#endif

/*
 * Bill Nowicki pointed out that the page size (CLBYTES) has
 * nothing to do with the mbuf cluster size.  So, we followed
 * Sun's lead and made the new define MCLBYTES stand for the mbuf
 * cluster size.  The following define makes up backwards compatible
 * with 4.3 and 4.2.  If CLBYTES is >1024 on your machine, check
 * this against the mbuf cluster definitions in /usr/include/sys/mbuf.h.
 */
#ifndef MCLBYTES
#define	MCLBYTES CLBYTES	/* XXX */
#endif

/*
 * The routine in_localaddr is broken in Sun's 3.4.  We redefine ours
 * (in tcp_input.c) so we use can it but won't have a name conflict.
 */
#ifdef sun
#define in_localaddr tcp_in_localaddr
#endif

/* --------------- end of TCP config ---------------- */

/*
E 35
I 32
 * TCP configuration:  This is a half-assed attempt to make TCP
 * self-configure for a few varieties of 4.2 and 4.3-based unixes.
 * If you don't have a) a 4.3bsd vax or b) a 3.x Sun (x<6), check
 * this carefully (it's probably not right).  Please send me mail
 * if you run into configuration problems.
 *  - Van Jacobson (van@lbl-csam.arpa)
 */

#ifndef BSD
#define BSD 42	/* if we're not 4.3, pretend we're 4.2 */
I 33
#define OLDSTAT	/* set if we have to use old netstat binaries */
E 33
#endif

I 33
/* #define OLDSTAT	/* set if we have to use old netstat binaries */

E 33
#if sun || BSD < 43
#define TCP_COMPAT_42	/* set if we have to interop w/4.2 systems */
#endif

#ifndef SB_MAX
#ifdef	SB_MAXCOUNT
#define	SB_MAX	SB_MAXCOUNT	/* Sun has to be a little bit different... */
#else
#define SB_MAX	32767		/* XXX */
#endif	SB_MAXCOUNT
#endif	SB_MAX

/*
 * Bill Nowicki pointed out that the page size (CLBYTES) has
 * nothing to do with the mbuf cluster size.  So, we followed
 * Sun's lead and made the new define MCLBYTES stand for the mbuf
 * cluster size.  The following define makes up backwards compatible
 * with 4.3 and 4.2.  If CLBYTES is >1024 on your machine, check
 * this against the mbuf cluster definitions in /usr/include/sys/mbuf.h.
 */
#ifndef MCLBYTES
#define	MCLBYTES CLBYTES	/* XXX */
#endif

/*
 * The routine in_localaddr is broken in Sun's 3.4.  We redefine ours
 * (in tcp_input.c) so we use can it but won't have a name conflict.
 */
#ifdef sun
#define in_localaddr tcp_in_localaddr
#endif

/* --------------- end of TCP config ---------------- */

/*
E 32
 * Kernel variables for tcp.
 */

/*
I 3
D 9
 * Tcp+ip header, after ip options removed.
 */
struct tcpiphdr {
	struct 	ipovly ti_i;		/* overlaid ip structure */
	struct	tcphdr ti_t;		/* tcp header */
};
#define	ti_next		ti_i.ih_next
#define	ti_prev		ti_i.ih_prev
#define	ti_x1		ti_i.ih_x1
#define	ti_pr		ti_i.ih_pr
#define	ti_len		ti_i.ih_len
#define	ti_src		ti_i.ih_src
#define	ti_dst		ti_i.ih_dst
#define	ti_sport	ti_t.th_sport
#define	ti_dport	ti_t.th_dport
#define	ti_seq		ti_t.th_seq
#define	ti_ackno	ti_t.th_ackno
#define	ti_x2		ti_t.th_x2
#define	ti_off		ti_t.th_off
#define	ti_flags	ti_t.th_flags
#define	ti_win		ti_t.th_win
#define	ti_sum		ti_t.th_sum
#define	ti_urp		ti_t.th_urp

/*
I 7
 * TCP sequence numbers are 32 bit integers operated
 * on with modular arithmetic.  These macros can be
 * used to compare such integers.
 */
#define	SEQ_LT(a,b)	((int)((a)-(b)) < 0)
#define	SEQ_LEQ(a,b)	((int)((a)-(b)) <= 0)
#define	SEQ_GT(a,b)	((int)((a)-(b)) > 0)
#define	SEQ_GEQ(a,b)	((int)((a)-(b)) >= 0)

/*
 * Definitions of the TCP timers.  These timers are counted
 * down PR_SLOWHZ times a second.
 */
D 8
#define	TCPT_NTIMERS	7
E 8
I 8
#define	TCPT_NTIMERS	4
E 8

D 8
#define	TCPT_INIT	0		/* initialization */
#define	TCPT_REXMT	1		/* retransmit */
#define	TCPT_REXMTTL	2		/* retransmit too long */
E 8
I 8
#define	TCPT_REXMT	0		/* retransmit */
#define	TCPT_2MSL	1		/* 2*msl quiet time timer */
#define	TCPT_PERSIST	2		/* retransmit persistance */
E 8
#define	TCPT_KEEP	3		/* keep alive */
D 8
#define	TCPT_KEEPTTL	4		/* keep alive too long */
#define	TCPT_PERSIST	5		/* retransmit persistance */
#define	TCPT_2MSL	6		/* 2*msl quiet time timer */
E 8

/*
E 9
E 7
E 3
D 11
 * Tcp control block.
E 11
I 11
 * Tcp control block, one per tcp; fields:
E 11
 */
D 2
struct tcb {
	struct tcb_hd {
		struct	th *seg_next,*seg_prev;		/* seq queue */
		struct	tcb *tcb_next,*tcb_prev;	/* other tcb's */
	} tcb_hd;
	struct	th *t_template;		/* skeletal packet for transmit */
	struct	socket *t_socket;	/* back pointer to socket */
	struct	mbuf *seg_unack;	/* unacked message queue */
	struct	host *t_host;
	short	seqcnt;
	short	xxx;
E 2
I 2
struct tcpcb {
D 8
	struct	tcpiphdr *seg_next,*seg_prev;	/* seq queue */
D 7
	struct	tcpiphdr *t_template;	/* skeletal packet for transmit */
	struct	inpcb *t_inpcb;
E 2
	seq_t	iss;			/* initial send seq # */
	seq_t	irs;			/* initial recv seq # */
	seq_t	rcv_urp;		/* rcv urgent pointer */
	seq_t	rcv_nxt;		/* next seq # to rcv */
	seq_t	rcv_end;		/* rcv eol pointer */
	seq_t	snd_off;		/* seq # of first datum in send buf */
	seq_t	seq_fin;		/* seq # of FIN sent */
	seq_t	snd_end;		/* send eol pointer */
	seq_t	snd_urp;		/* snd urgent pointer */
	seq_t	snd_lst;		/* seq # of last sent datum */
	seq_t	snd_nxt;		/* seq # of next datum to send */
	seq_t	snd_una;		/* seq # of first unacked datum */
	seq_t	snd_wl;			/* seq # of last sent window */
	seq_t	snd_hi;			/* highest seq # sent */
	seq_t	snd_wnd;		/* send window max */
	seq_t	t_rexmt_val;		/* val saved in rexmt timer */
	seq_t	t_rtl_val;		/* val saved in rexmt too long timer */
	seq_t	t_xmt_val;		/* seq # sent when xmt timer started */
	seq_t	rcv_adv;		/* advertised window */
I 2
	struct	mbuf *seg_unack;	/* unacked message queue */
	short	seqcnt;
E 2
	u_short	tc_flags;		/* flags and state; see below */
	u_short	t_options;
#define	TO_EOL		0x01		/* eol mode */
#define	TO_URG		0x02		/* urgent mode */
E 7
I 7
	short	seqcnt;			/* count of chars in seq queue */
E 7
D 2
	u_short	t_lport;		/* local port */
	u_short	t_fport;		/* foreign port */
E 2
	u_char	t_state;		/* state of this connection */
E 8
I 8
	struct	tcpiphdr *seg_next;	/* sequencing queue */
	struct	tcpiphdr *seg_prev;
D 13
	int	t_state;		/* state of this connection */
E 13
I 13
	short	t_state;		/* state of this connection */
E 13
D 9
	int	seqcnt;			/* count of chars in seq queue */
E 8
D 7
	u_char	t_xmtime;		/* current rexmt time */
/* timers... must be in order */
D 2
	short	t_init;			/* initialization too long */
E 2
I 2
	short	t_init;			/* init */
E 2
	short	t_rexmt;		/* retransmission */
	short	t_rexmttl;		/* retransmit too long */
	short	t_persist;		/* retransmit persistance */
	short	t_finack;		/* fin acknowledged */
	short	t_xmt;			/* round trip transmission time */
/* end timers */
};

/* tc_flags values */
#define	TC_ACK_DUE	0x0001		/* must we send ACK */
#define	TC_CANCELLED	0x0002		/* retransmit timer cancelled */
D 2
#define	TC_DROPPED_TXT	0x0004		/* dropped incoming data */
E 2
I 2
D 6
/* ... */
E 2
#define	TC_FIN_RCVD	0x0008		/* FIN received */
#define	TC_FORCE_ONE	0x0010		/* force sending of one byte */
#define	TC_NEW_WINDOW	0x0020		/* received new window size */
#define	TC_REXMT	0x0040		/* this msg is a retransmission */
#define	TC_SND_FIN	0x0080		/* FIN should be sent */
#define	TC_SND_RST	0x0100		/* RST should be sent */
#define	TC_SND_URG	0x0200		/* urgent data to send */
#define	TC_SYN_ACKED	0x0400		/* SYN has been ACKed */
#define	TC_SYN_RCVD	0x0800		/* SYN has been received */
#define	TC_USR_CLOSED	0x1000		/* user has closed connection */
#define	TC_WAITED_2_ML	0x2000		/* wait time for FIN ACK is up */
#define	TC_NET_KEEP	0x4000		/* don't free this net input */
#define	TC_USR_ABORT	0x8000		/* user has closed and does not expect
E 6
I 6
#define	TC_FIN_RCVD	0x0004		/* FIN received */
#define	TC_FORCE_ONE	0x0008		/* force sending of one byte */
#define	TC_NEW_WINDOW	0x0010		/* received new window size */
#define	TC_REXMT	0x0020		/* this msg is a retransmission */
#define	TC_SND_FIN	0x0040		/* FIN should be sent */
#define	TC_SND_RST	0x0080		/* RST should be sent */
#define	TC_SND_URG	0x0100		/* urgent data to send */
#define	TC_SYN_ACKED	0x0200		/* SYN has been ACKed */
#define	TC_SYN_RCVD	0x0400		/* SYN has been received */
#define	TC_USR_CLOSED	0x0800		/* user has closed connection */
#define	TC_USR_ABORT	0x1000		/* user has closed and does not expect
E 6
					   to receive any more data */
E 7
I 7
	short	t_timers[TCPT_NTIMERS];	/* tcp timers */
D 8
	u_char	t_options;		/* connection options: */
E 8
I 8
	short	t_options;		/* connection options: */
E 8
#define	TO_PUSH		0x01			/* push mode */
#define	TO_URG		0x02			/* urgent mode */
#define	TO_KEEP		0x04			/* use keep-alives */
E 9
I 9
D 11
	int	t_seqcnt;		/* count of chars in seq queue */
E 11
	short	t_timer[TCPT_NTIMERS];	/* tcp timers */
I 11
	short	t_rxtshift;		/* log(2) of rexmt exp. backoff */
E 11
D 29
	struct	mbuf *t_tcpopt;		/* tcp options */
E 29
I 29
	short	t_rxtcur;		/* current retransmit value */
D 30
	short	t_unused;		/* XXX */
E 30
I 30
	short	t_dupacks;		/* consecutive dup acks recd */
E 30
E 29
D 22
	struct	mbuf *t_ipopt;		/* ip options */
E 22
D 25
	short	t_maxseg;		/* maximum segment size */
E 25
I 25
	u_short	t_maxseg;		/* maximum segment size */
E 25
I 11
D 13
	short	t_force;		/* 1 if forcing out a byte */
E 13
I 13
	char	t_force;		/* 1 if forcing out a byte */
E 13
E 11
E 9
	u_char	t_flags;
D 9
#define	TF_OWEACK	0x01			/* owe ack to peer */
D 8
	struct	mbuf *seg_unack;	/* unacked message queue */
E 8
I 8
#define	TF_DELACK	0x02			/* delaying ack to peer */
E 9
I 9
D 24
#define	TF_ACKNOW	0x01			/* ack peer immediately */
#define	TF_DELACK	0x02			/* ack, but try to delay it */
D 15
#define	TF_PUSH		0x04			/* push mode */
#define	TF_URG		0x08			/* urgent mode */
D 11
#define	TF_KEEP		0x10			/* use keep-alives */
E 11
I 11
#define	TF_DONTKEEP	0x10			/* don't use keep-alives */
E 15
I 15
#define	TF_DONTKEEP	0x04			/* don't use keep-alives */
#define	TF_NOOPT	0x08			/* don't use tcp options */
E 24
I 24
#define	TF_ACKNOW	0x01		/* ack peer immediately */
#define	TF_DELACK	0x02		/* ack, but try to delay it */
#define	TF_NODELAY	0x04		/* don't delay packets to coalesce */
#define	TF_NOOPT	0x08		/* don't use tcp options */
I 25
#define	TF_SENTFIN	0x10		/* have sent FIN */
E 25
E 24
D 17
#ifdef TCPTRUEOOB
#define	TF_DOOOB	0x10			/* do use out of band data */
#endif
E 17
E 15
E 11
E 9
E 8
	struct	tcpiphdr *t_template;	/* skeletal packet for transmit */
	struct	inpcb *t_inpcb;		/* back pointer to internet pcb */
E 7
/*
D 7
 * TCP timers.
E 7
I 7
 * The following fields are used as in the protocol specification.
 * See RFC783, Dec. 1981, page 21.
E 7
 */
D 7
#define	TINIT		0
#define	TREXMT		1
#define	TREXMTTL	2
#define	TPERSIST	3
#define	TFINACK		4
#define	TNTIMERS	5
E 7
I 7
/* send sequence variables */
	tcp_seq	snd_una;		/* send unacknowledged */
	tcp_seq	snd_nxt;		/* send next */
D 13
	u_short	snd_wnd;		/* send window */
E 13
	tcp_seq	snd_up;			/* send urgent pointer */
	tcp_seq	snd_wl1;		/* window update seg seq number */
	tcp_seq	snd_wl2;		/* window update seg ack number */
	tcp_seq	iss;			/* initial send sequence number */
I 13
	u_short	snd_wnd;		/* send window */
E 13
/* receive sequence variables */
D 13
	tcp_seq	rcv_nxt;		/* receive next */
E 13
D 12
	u_short	rcv_wnd;		/* receive window */
E 12
I 12
D 24
	short	rcv_wnd;		/* receive window */
E 24
I 24
	u_short	rcv_wnd;		/* receive window */
E 24
I 13
	tcp_seq	rcv_nxt;		/* receive next */
E 13
E 12
	tcp_seq	rcv_up;			/* receive urgent pointer */
	tcp_seq	irs;			/* initial receive sequence number */
/*
 * Additional variables for this implementation.
 */
D 8
/* send variables */
	tcp_seq	snd_off;	/*??*/	/* seq # of first datum in send buf */
	tcp_seq	seq_fin;	/*??*/	/* seq # of FIN sent */
	tcp_seq	snd_hi;		/*??*/	/* highest seq # sent */
	tcp_seq	snd_end;	/*??*/	/* send eol pointer */
	tcp_seq	snd_lst;	/*??*/	/* seq # of last sent datum */
	tcp_seq	snd_wl;		/*??*/	/* seq # of last sent window */
	tcp_seq	snd_wnd;	/*??*/	/* send window max */
/* retransmit variables */
	tcp_seq	t_rexmt_val;	/*??*/	/* val saved in rexmt timer */
	tcp_seq	t_rtl_val;	/*??*/	/* val saved in rexmt too long timer */
	tcp_seq	t_xmt_val;	/*??*/	/* seq # sent when xmt timer started */
	u_char	t_xmtime;	/*??*/	/* current rexmt time */
	short	t_xmt;		/*??*/	/* round trip transmission time */
E 8
/* receive variables */
D 8
	tcp_seq	rcv_end;	/*??*/	/* rcv eol pointer */
	tcp_seq	rcv_adv;	/*??*/	/* advertised window */
E 8
I 8
	tcp_seq	rcv_adv;		/* advertised window */
/* retransmit variables */
D 9
	tcp_seq	snd_max;		/* highest sequence number sent */
E 9
I 9
	tcp_seq	snd_max;		/* highest sequence number sent
E 9
D 20
					   used to recognize retransmits */
E 20
I 20
					 * used to recognize retransmits
					 */
D 30
/* congestion control (for source quench) */
E 30
I 30
/* congestion control (for slow start, source quench, retransmit after loss) */
E 30
	u_short	snd_cwnd;		/* congestion-controlled window */
I 30
	u_short snd_ssthresh;		/* snd_cwnd size threshhold for
					 * for slow start exponential to
					 * linear switch */
E 30
E 20
I 9
D 11
	tcp_seq	rxt_seq;
	short	rxt_time;
	short	rxt_cnt;
E 11
I 11
D 28
/* transmit timing stuff */
E 28
I 28
/*
 * transmit timing stuff.
 * srtt and rttvar are stored as fixed point; for convenience in smoothing,
 * srtt has 3 bits to the right of the binary point, rttvar has 2.
I 30
 * "Variance" is actually smoothed difference.
E 30
 */
E 28
	short	t_idle;			/* inactivity time */
	short	t_rtt;			/* round trip time */
I 22
D 30
	u_short max_rcvd;		/* most peer has sent into window */
E 30
E 22
	tcp_seq	t_rtseq;		/* sequence number being timed */
D 28
	float	t_srtt;			/* smoothed round-trip time */
E 28
I 28
	short	t_srtt;			/* smoothed round-trip time */
	short	t_rttvar;		/* variance in round-trip time */
I 30
	u_short max_rcvd;		/* most peer has sent into window */
E 30
E 28
I 23
	u_short	max_sndwnd;		/* largest window peer has offered */
E 23
I 14
D 15
/* out-of-band data; treat char before urgent pointer as out-of-band */
	char	t_haveoob;		/* have some */
	char	t_oobc;			/* the character */
E 15
I 15
/* out-of-band data */
	char	t_oobflags;		/* have some */
I 16
	char	t_iobc;			/* input character */
E 16
#define	TCPOOB_HAVEDATA	0x01
I 22
#define	TCPOOB_HADDATA	0x02
E 22
D 17

#ifdef TCPTRUEOOB
#define	TCPOOB_OWEACK	0x02
#define	TCPOOB_NEEDACK	0x04
D 16
	char	t_iobc;			/* input character */
E 16
	u_char	t_iobseq;		/* input receive sequence number */
I 16
	tcp_seq	t_oobmark;		/* output mark position */
E 16
	char	t_oobc;			/* output character */
	u_char	t_oobseq;		/* output transmit sequence number */
#endif
E 17
E 15
E 14
E 11
E 9
E 8
};
E 7

I 9
D 10
#define	tcp_finisacked(tp)	0		/* XXX */

E 10
E 9
I 2
#define	intotcpcb(ip)	((struct tcpcb *)(ip)->inp_ppcb)
#define	sototcpcb(so)	(intotcpcb(sotoinpcb(so)))
D 10

E 2
D 7
/*
 * Tcp machine predicates
 */
#define	ack_ok(x, y) \
D 3
    (((y)->th_flags&TH_ACK)==0 || \
      ((x)->iss < (y)->t_ackno && (y)->t_ackno <= (x)->snd_hi))
E 3
I 3
    (((y)->ti_flags&TH_ACK)==0 || \
      ((x)->iss < (y)->ti_ackno && (y)->ti_ackno <= (x)->snd_hi))
E 3

#define	syn_ok(x, y) \
D 3
    ((y)->th_flags&TH_SYN)
E 3
I 3
    ((y)->ti_flags&TH_SYN)
E 3

#define	ack_fin(x, y) \
D 3
    ((x)->seq_fin > (x)->iss && (y)->t_ackno > (x)->seq_fin)
E 3
I 3
    ((x)->seq_fin > (x)->iss && (y)->ti_ackno > (x)->seq_fin)
E 3

#define	rcv_empty(x) \
    (((x)->tc_flags&TC_USR_ABORT) || \
D 2
      ((x)->t_socket->so_rcv.sb_mb == NULL && \
       (x)->tcb_hd.seg_next == (x)->tcb_hd.seg_prev))
E 2
I 2
      ((x)->t_inpcb->inp_socket->so_rcv.sb_mb == NULL && \
       (x)->seg_next == (x)->seg_prev))
E 2

E 7
D 9
#define	ISSINCR		128		/* increment for iss each second */
E 9
I 9
#define	TCP_ISSINCR	128		/* increment for iss each second */
E 10
E 9
D 8
#define	TCPSIZE		20		/* size of TCP leader (bytes) */
E 8

I 27
/*
 * TCP statistics.
 * Many of these should be kept per connection,
 * but that's inconvenient at the moment.
 */
E 27
I 7
D 8
#define	TCP_TTL		30		/* time to live for TCP segs: 30s */
E 8
I 8
D 9
#define	TCP_TTL		60		/* time to live for TCP segs */
E 8
E 7
/*
D 7
 * THESE NEED TO BE JUSTIFIED!
 *
 * *2 here is because slow timeout routine called every 1/2 second.
E 7
I 7
 * TCPSC constants give various timeouts in ``slow-clock'' ticks.
E 7
 */
I 2
D 7
#define	T_INIT		(30*2)
E 2
#define	T_2ML		(10*2)		/* 2*maximum packet lifetime */
#define	T_PERS		(5*2)		/* persist time */
#define	T_REXMT		(1*2)		/* base for retransmission time */
#define	T_REXMTTL	(30*2)		/* retransmit too long timeout */
#define	T_REMAX		(30*2)		/* maximum retransmission time */
E 7
I 7
D 8
#define	TCPSC_MSL	(TCP_TTL*PR_SLOWHZ)	/* max seg lifetime */
#define	TCPSC_REXMT	(1*PR_SLOWHZ)		/* base retransmit time */
#define	TCPSC_REXMTTL	(TCP_TTL*2*PR_SLOWHZ)	/* retransmit too long */
#define	TCPSC_KEEP	(TCP_TTL*4*PR_SLOWHZ)	/* keep alive */
#define	TCPSC_KEEPTTL	(4*TCPSC_KEEP)		/* keep alive too long */
#define	TCPSC_PERSIST	(5*PR_SLOWHZ)		/* retransmit persistance */
#define	TCPSC_2MSL	(TCP_TTL*2*PR_SLOWHZ)	/* 2*msl quiet time timer */
E 8
I 8
#define	TCPSC_MSL	(120*PR_SLOWHZ)		/* max seg lifetime */
#define	TCPSC_REXMT	(  1*PR_SLOWHZ)		/* base retransmit time */
#define	TCPSC_KEEP	(240*PR_SLOWHZ)		/* keep alive */
#define	TCPSC_PERSIST	(  5*PR_SLOWHZ)		/* retransmit persistance */
E 8
E 7

I 7
D 8
#define	TCPSC_REMAX	(TCP_TTL*PR_SLOWHZ)	/* maximum rexmt time */
E 8
I 8
#define	TCPSC_KEEPTTL	(  4*TCPSC_KEEP)	/* keep alive too long */
#define	TCPSC_2MSL	(  2*TCPSC_MSL)		/* 2*msl quiet time timer */

#define	TCPSC_TOOLONG	(480*PR_SLOWHZ)
E 8

E 9
E 7
I 5
struct	tcpstat {
I 35
#ifdef OLDSTAT
	/*
	 * Declare statistics the same as in 4.3
	 * at the start of tcpstat (same size and
	 * position) for netstat.
	 */
	int	tcps_rcvbadsum;
	int	tcps_rcvbadoff;
	int	tcps_rcvshort;
	int	tcps_badsegs;
	int	tcps_unack;
#define	tcps_badsum	tcps_rcvbadsum
#define	tcps_badoff	tcps_rcvbadoff
#define	tcps_hdrops	tcps_rcvshort

#endif OLDSTAT
E 35
I 33
#ifdef OLDSTAT
	/*
	 * Declare statistics the same as in 4.3
	 * at the start of tcpstat (same size and
	 * position) for netstat.
	 */
	int	tcps_rcvbadsum;
	int	tcps_rcvbadoff;
	int	tcps_rcvshort;
	int	tcps_badsegs;
	int	tcps_unack;
#define	tcps_badsum	tcps_rcvbadsum
#define	tcps_badoff	tcps_rcvbadoff
#define	tcps_hdrops	tcps_rcvshort

#endif OLDSTAT
E 33
D 27
	int	tcps_badsum;
	int	tcps_badoff;
	int	tcps_hdrops;
	int	tcps_badsegs;
	int	tcps_unack;
E 27
I 27
	u_long	tcps_connattempt;	/* connections initiated */
	u_long	tcps_accepts;		/* connections accepted */
	u_long	tcps_connects;		/* connections established */
	u_long	tcps_drops;		/* connections dropped */
	u_long	tcps_conndrops;		/* embryonic connections dropped */
	u_long	tcps_closed;		/* conn. closed (includes drops) */
	u_long	tcps_segstimed;		/* segs where we tried to get rtt */
	u_long	tcps_rttupdated;	/* times we succeeded */
	u_long	tcps_delack;		/* delayed acks sent */
	u_long	tcps_timeoutdrop;	/* conn. dropped in rxmt timeout */
	u_long	tcps_rexmttimeo;	/* retransmit timeouts */
	u_long	tcps_persisttimeo;	/* persist timeouts */
	u_long	tcps_keeptimeo;		/* keepalive timeouts */
	u_long	tcps_keepprobe;		/* keepalive probes sent */
	u_long	tcps_keepdrops;		/* connections dropped in keepalive */

	u_long	tcps_sndtotal;		/* total packets sent */
	u_long	tcps_sndpack;		/* data packets sent */
	u_long	tcps_sndbyte;		/* data bytes sent */
	u_long	tcps_sndrexmitpack;	/* data packets retransmitted */
	u_long	tcps_sndrexmitbyte;	/* data bytes retransmitted */
	u_long	tcps_sndacks;		/* ack-only packets sent */
	u_long	tcps_sndprobe;		/* window probes sent */
	u_long	tcps_sndurg;		/* packets sent with URG only */
	u_long	tcps_sndwinup;		/* window update-only packets sent */
	u_long	tcps_sndctrl;		/* control (SYN|FIN|RST) packets sent */

	u_long	tcps_rcvtotal;		/* total packets received */
	u_long	tcps_rcvpack;		/* packets received in sequence */
	u_long	tcps_rcvbyte;		/* bytes received in sequence */
I 35
#ifndef OLDSTAT
E 35
I 33
#ifndef OLDSTAT
E 33
	u_long	tcps_rcvbadsum;		/* packets received with ccksum errs */
	u_long	tcps_rcvbadoff;		/* packets received with bad offset */
	u_long	tcps_rcvshort;		/* packets received too short */
I 35
#endif
E 35
I 33
#endif
E 33
	u_long	tcps_rcvduppack;	/* duplicate-only packets received */
	u_long	tcps_rcvdupbyte;	/* duplicate-only bytes received */
	u_long	tcps_rcvpartduppack;	/* packets with some duplicate data */
	u_long	tcps_rcvpartdupbyte;	/* dup. bytes in part-dup. packets */
	u_long	tcps_rcvoopack;		/* out-of-order packets received */
	u_long	tcps_rcvoobyte;		/* out-of-order bytes received */
	u_long	tcps_rcvpackafterwin;	/* packets with data after window */
	u_long	tcps_rcvbyteafterwin;	/* bytes rcvd after window */
	u_long	tcps_rcvafterclose;	/* packets rcvd after "close" */
	u_long	tcps_rcvwinprobe;	/* rcvd window probe packets */
	u_long	tcps_rcvdupack;		/* rcvd duplicate acks */
	u_long	tcps_rcvacktoomuch;	/* rcvd acks for unsent data */
	u_long	tcps_rcvackpack;	/* rcvd ack packets */
	u_long	tcps_rcvackbyte;	/* bytes acked by rcvd acks */
	u_long	tcps_rcvwinupd;		/* rcvd window update packets */
E 27
};

E 5
D 7
#ifdef TCPDEBUG
#define	TDBSIZE		50
/*
 * Tcp debugging record.
 */
struct tcp_debug {
	long	td_tod;			/* time of day */
D 2
	struct	tcb *td_tcb;		/* -> tcb */
E 2
I 2
	struct	tcbcb *td_tcb;		/* -> tcb */
E 2
	char	td_old;			/* old state */
	char	td_inp;			/* input */
	char	td_tim;			/* timer id */
	char	td_new;			/* new state */
	seq_t	td_sno;			/* seq_t number */
	seq_t	td_ano;			/* acknowledgement */
	u_short	td_wno;			/* window */
	u_short	td_lno;			/* length */
	u_char	td_flg;			/* message flags */
};
#endif

E 7
#ifdef KERNEL
D 2
struct	tcb_hd tcb;			/* tcp tcb list head */
E 2
D 7
seq_t	tcp_iss;			/* tcp initial send seq # */
D 4
int	tcpconsdebug;			/* set to 1 traces on console */
E 4
I 2
struct	inpcb tcb;
I 5
struct	tcpstat tcpstat;
E 5
E 2
#ifdef TCPDEBUG
I 4
int	tcpconsdebug;			/* set to 1 traces on console */
E 4
struct	tcp_debug tcp_debug[TDBSIZE];
D 4
#endif
E 4
int	tdbx;			/* rotating index into tcp_debug */
E 7
I 7
D 9
tcp_seq	tcp_iss;		/* tcp initial send seq # */
E 9
struct	inpcb tcb;		/* head of queue of active tcpcb's */
struct	tcpstat tcpstat;	/* tcp statistics */
E 7
I 4
D 9
#endif
E 9
E 4
D 2
struct	th *tcp_template();
E 2
I 2
struct	tcpiphdr *tcp_template();
I 18
struct	tcpcb *tcp_close(), *tcp_drop();
struct	tcpcb *tcp_timers(), *tcp_disconnect(), *tcp_usrclosed();
E 18
E 2
D 9
#endif

D 7
#define	SEQ_LT(a,b)	((int)((a)-(b)) < 0)
#define	SEQ_LEQ(a,b)	((int)((a)-(b)) <= 0)
#define	SEQ_GT(a,b)	((int)((a)-(b)) > 0)
#define	SEQ_GEQ(a,b)	((int)((a)-(b)) >= 0)
E 7
I 7
#ifdef	TCPTIMERS
char *tcptimers[] =
    { "INIT", "REXMT", "REXMTTL", "KEEP", "KEEPTTL", "PERSIST", "2MSL" };
E 9
#endif
E 7
D 2
struct	th *tcp_template();
E 2
E 1
