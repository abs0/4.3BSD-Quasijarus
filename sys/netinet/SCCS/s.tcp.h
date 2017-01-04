h25003
s 00010/00005/00059
d D 7.5 88/06/29 17:07:12 bostic 37 35
c install approved copyright notice
e
s 00020/00002/00062
d D 7.4.1.1 88/02/07 19:56:27 karels 36 35
c branch for FTP release (#ifdefs for non-4.3)
e
s 00002/00002/00062
d D 7.4 88/01/07 11:33:36 karels 35 34
c rename endians
e
s 00008/00002/00056
d D 7.3 87/12/07 17:45:59 bostic 34 33
c use Berkeley specific header
e
s 00005/00001/00053
d D 7.2 86/10/28 22:53:37 karels 33 32
c byte order changes for tahoe
e
s 00001/00001/00053
d D 7.1 86/06/05 00:29:16 mckusick 32 31
c 4.3BSD release version
e
s 00007/00003/00047
d D 6.5 86/02/20 09:49:03 karels 31 30
c lint
e
s 00006/00000/00044
d D 6.4 86/01/13 17:27:59 karels 30 29
c add user option for nodelay; define maxseg option (unused now)
e
s 00007/00001/00037
d D 6.3 85/06/08 12:41:33 mckusick 29 28
c Add copyright
e
s 00007/00000/00031
d D 6.2 84/11/01 13:42:25 karels 28 27
c put TCP_MSS in header
e
s 00000/00000/00031
d D 6.1 83/07/29 07:12:03 sam 27 26
c 4.2 distribution
e
s 00001/00005/00030
d D 1.24 83/07/06 18:10:05 sam 26 25
c sun purge
e
s 00007/00002/00028
d D 1.23 82/12/28 21:04:52 sam 25 24
c bit field incompatibilities with sun
e
s 00000/00013/00030
d D 1.22 82/12/20 12:37:38 sam 24 23
c forgot to purge this stuff somehow
e
s 00001/00001/00042
d D 1.21 82/01/18 19:43:06 wnj 23 22
c out-of-band fixed up
e
s 00017/00000/00026
d D 1.20 82/01/17 21:19:33 wnj 22 21
c more work on out-of-band
e
s 00003/00002/00023
d D 1.19 81/11/26 11:56:56 wnj 21 20
c before carry to ARPAVAX
e
s 00006/00006/00019
d D 1.18 81/11/24 17:33:15 wnj 20 19
c start rewrite
e
s 00001/00000/00024
d D 1.17 81/11/18 15:37:44 wnj 19 18
c more cleanup
e
s 00011/00025/00013
d D 1.16 81/11/15 13:00:00 wnj 18 17
c listing
e
s 00003/00003/00035
d D 1.15 81/11/14 16:39:14 wnj 17 16
c before overlay
e
s 00002/00158/00036
d D 1.14 81/11/08 16:25:04 wnj 16 15
c first listing
e
s 00008/00003/00186
d D 1.13 81/11/04 00:29:16 wnj 15 14
c more cleanups, fields in ucb.h
e
s 00006/00005/00183
d D 1.12 81/11/03 21:54:17 wnj 14 13
c states now w/o fsm matrix; timers accessible by iteration
e
s 00007/00003/00181
d D 1.11 81/10/30 21:43:55 wnj 13 12
c more cleanup
e
s 00002/00000/00182
d D 1.10 81/10/30 18:04:12 wnj 12 11
c first 1m baud system
e
s 00023/00003/00159
d D 1.9 81/10/29 20:27:31 wnj 11 10
c cleanup of header files
e
s 00002/00000/00160
d D 1.8 81/10/29 16:01:46 wnj 10 9
c working but losing 1 mbuf per connection
e
s 00005/00000/00155
d D 1.7 81/10/28 23:00:48 wnj 9 8
c SEQ_* macros
e
s 00005/00001/00150
d D 1.6 81/10/28 22:10:25 wnj 8 5
c short len to avoid disasters
e
s 00000/00001/00154
d R 1.7 81/10/26 02:10:37 wnj 7 6
c first compile of major cleanup
e
s 00004/00000/00151
d R 1.6 81/10/25 16:02:37 wnj 6 5
c add fields for rcv_win rcv_unacnt rcv_usrcnt rcv_seqcnt
e
s 00037/00029/00114
d D 1.5 81/10/22 12:35:10 wnj 5 4
c fixup debugging stuff, elim work q once and for all
e
s 00029/00028/00114
d D 1.4 81/10/21 21:36:37 wnj 4 3
c bit fields -> flags
e
s 00129/00101/00013
d D 1.3 81/10/21 19:07:22 wnj 3 2
c cleanup the headers
e
s 00000/00000/00114
d D 1.2 81/10/18 15:53:19 wnj 2 1
c cleanup imp_snd, arpa_ether, more robuts memall, remove netprepr
e
s 00114/00000/00000
d D 1.1 81/10/14 09:57:29 wnj 1 0
c date and time created 81/10/14 09:57:29 by wnj
e
u
U
f b 
t
T
I 1
D 26
/* %M% %I% %E% */
E 26
I 26
D 29
/*	%M%	%I%	%E%	*/
E 29
I 29
/*
D 32
 * Copyright (c) 1982 Regents of the University of California.
E 32
I 32
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 32
D 34
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 34
I 34
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 37
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 37
I 37
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
E 37
E 34
 *
 *	%W% (Berkeley) %G%
 */
I 36
#ifndef BYTE_ORDER
/*
 * Definitions for byte order,
 * according to byte significance from low address to high.
 */
#define	LITTLE_ENDIAN	1234	/* least-significant byte first (vax) */
#define	BIG_ENDIAN	4321	/* most-significant byte first (IBM, net) */
#define	PDP_ENDIAN	3412	/* LSB first in word, MSW first in long (pdp) */
E 36
E 29
E 26
D 3
struct th {                     /* tcp header (fits over ip header) */
	struct th *t_next;              /* -> next tcp on rcv chain */
	struct th *t_prev;              /* -> prev tcp on rcv chain */
	unsigned char t_x1;             /* (unused) */
	unsigned char t_pr;             /* protocol */
	unsigned short t_len;           /* seg length */
	struct socket t_s;              /* source internet address */
	struct socket t_d;              /* destination internet address */
	unsigned short t_src;           /* source port */
	unsigned short t_dst;           /* destination port */
	sequence t_seq;                 /* sequence number */
	sequence t_ackno;               /* acknowledgement number */
#define t_end(x) (x->t_seq + x->t_len - 1)
	unsigned char
		t_x2:4,                 /* (unused) */
		t_off:4;                /* data offset */
	unsigned char
		t_fin:1,                /* fin flag */
		t_syn:1,                /* syn flag */
		t_rst:1,                /* reset flag */
		t_eol:1,                /* eol flag */
		t_ack:1,                /* ack flag */
		t_urg:1,                /* urgent flag */
		t_x3:2;                 /* (unused) */
	unsigned short t_win;           /* window */
	unsigned short t_sum;           /* checksum */
	unsigned short t_urp;           /* urgent pointer */
E 3
I 3

I 36
#ifdef vax
#define	BYTE_ORDER	LITTLE_ENDIAN
#else
#define	BYTE_ORDER	BIG_ENDIAN	/* mc68000, tahoe, most others */
#endif
#endif BYTE_ORDER

E 36
I 21
typedef	u_long	tcp_seq;
E 21
/*
D 11
 * Tcp header (fits over ip header).
E 11
I 11
D 18
 * Tcp header.  Fits over the ip header after option removed.
 *
 * SHOULD MAKE A CLEAN HEADER FOR USE BY USERS.
E 18
I 18
 * TCP header.
I 19
 * Per RFC 793, September, 1981.
E 19
E 18
E 11
 */
D 17
struct th {
	struct	th *t_next;		/* -> next tcp on rcv chain */
	struct	th *t_prev;		/* -> prev tcp on rcv chain */
E 17
I 17
D 18
struct tcpiphdr {
	struct	tcpiphdr *t_next;		/* -> next tcp on rcv chain */
	struct	tcpiphdr *t_prev;		/* -> prev tcp on rcv chain */
E 17
	u_char	t_x1;			/* (unused) */
	u_char	t_pr;			/* protocol */
D 8
	u_short	t_len;			/* seg length */
E 8
I 8
/* by rights, t_len should be a u_short, but this makes operations */
/* on it very dangerous as comparisons become unsigned and comparing */
/* against negative numbers then fails... we don't expect any > 32767 */
/* byte segments, so pragmatically delcare it to be a short */
	short	t_len;			/* seg length */
E 8
D 16
	struct	socket t_s;		/* source internet address */
	struct	socket t_d;		/* destination internet address */
E 16
I 16
	struct	ip_addr t_s;		/* source internet address */
	struct	ip_addr t_d;		/* destination internet address */
E 16
	u_short	t_src;			/* source port */
	u_short	t_dst;			/* destination port */
	seq_t	t_seq;			/* sequence number */
	seq_t	t_ackno;		/* acknowledgement number */
#define	t_end(x) (x->t_seq + x->t_len - 1)
E 18
I 18
struct tcphdr {
	u_short	th_sport;		/* source port */
	u_short	th_dport;		/* destination port */
D 21
	seq_t	th_seq;			/* sequence number */
	seq_t	th_ackno;		/* acknowledgement number */
E 21
I 21
	tcp_seq	th_seq;			/* sequence number */
	tcp_seq	th_ack;			/* acknowledgement number */
E 21
E 18
D 25
	u_char
D 18
		t_x2:4,			/* (unused) */
		t_off:4;		/* data offset */
E 18
I 18
		th_x2:4,		/* (unused) */
E 25
I 25
D 33
#ifdef vax
E 33
I 33
D 35
#if ENDIAN == LITTLE
E 35
I 35
D 36
#if BYTE_ORDER == LITTLE_ENDIAN 
E 36
I 36
#if BYTE_ORDER == LITTLE_ENDIAN
E 36
E 35
E 33
	u_char	th_x2:4,		/* (unused) */
E 25
		th_off:4;		/* data offset */
I 33
#endif
D 35
#if ENDIAN == BIG
E 35
I 35
D 36
#if BYTE_ORDER == BIG_ENDIAN 
E 36
I 36
#if BYTE_ORDER == BIG_ENDIAN
E 36
E 35
	u_char	th_off:4,		/* data offset */
		th_x2:4;		/* (unused) */
E 33
I 25
D 26
#endif
#ifdef sun
	u_char	th_off:4,		/* data offset */
		th_x2:4;		/* (unused) */
E 26
#endif
E 25
E 18
D 4
	u_char
		t_fin:1,		/* fin flag */
		t_syn:1,		/* syn flag */
		t_rst:1,		/* reset flag */
		t_eol:1,		/* eol flag */
		t_ack:1,		/* ack flag */
		t_urg:1,		/* urgent flag */
		t_x3:2;			/* (unused) */
E 4
I 4
	u_char	th_flags;
D 20
#define	TH_FIN	001
#define	TH_SYN	002
#define	TH_RST	004
#define	TH_EOL	010
#define	TH_ACK	020
#define	TH_URG	040
E 20
I 20
#define	TH_FIN	0x01
#define	TH_SYN	0x02
#define	TH_RST	0x04
#define	TH_PUSH	0x08
#define	TH_ACK	0x10
#define	TH_URG	0x20
E 20
E 4
D 18
	u_short	t_win;			/* window */
	u_short	t_sum;			/* checksum */
	u_short	t_urp;			/* urgent pointer */
E 18
I 18
	u_short	th_win;			/* window */
	u_short	th_sum;			/* checksum */
	u_short	th_urp;			/* urgent pointer */
E 18
E 3
};
I 22

#define	TCPOPT_EOL	0
#define	TCPOPT_NOP	1
#define	TCPOPT_MAXSEG	2
I 28

/*
D 31
 *  Default maximum segment size for TCP.
 *  With an IP MSS of 576, this is 536,
 *  but 512 is probably more convenient.
E 31
I 31
 * Default maximum segment size for TCP.
 * With an IP MSS of 576, this is 536,
 * but 512 is probably more convenient.
E 31
 */
I 31
#ifdef	lint
#define	TCP_MSS	536
#else
I 36
#ifndef IP_MSS
#define	IP_MSS	576
#endif
E 36
E 31
#define	TCP_MSS	MIN(512, IP_MSS - sizeof (struct tcpiphdr))
I 31
#endif
E 31
I 30

/*
 * User-settable options (used with setsockopt).
 */
#define	TCP_NODELAY	0x01	/* don't delay send to coalesce packets */
#define	TCP_MAXSEG	0x02	/* set maximum segment size */
E 30
E 28
D 24

#ifdef TCPTRUEOOB
/*
 * True out-of-band as value added option.
 * Advertise willingness with TCPOPT_WILOOB in
 * initial segment.  If peer is willing, will receive
 * such also.  Then can send TCPOPT_OOBDATA whenever oob data
 * exists; peer should ack with TCPOPT_OOBACK in segment.
 */
#define	TCPOPT_WILLOOB	64		/* bytes: 64, 2 */
D 23
#define	TCPOPT_OOBDATA	65		/* bytes: 65, 4, seq#, data */
E 23
I 23
#define	TCPOPT_OOBDATA	65		/* bytes: 65, 8, seq#, data, markseq */
E 23
#define	TCPOPT_OOBACK	66		/* bytes: 66, 3, ack# */
#endif
E 24
E 22
D 16

D 3
struct tcb {                    /* tcp control block */
E 3
I 3
/*
 * Tcp control block.
 */
struct tcb {
I 15
/* first four elements of this struct must match tcphead below */
E 15
	struct	th *t_rcv_next;		/* first el on rcv queue */
	struct	th *t_rcv_prev;		/* last el on rcv queue */
D 13
	struct	tcb *t_tcb_next;	/* next tcb */
	struct	tcb *t_tcb_prev;	/* next tcb */
E 13
I 13
	struct	tcb *tcb_next;		/* next tcb */
	struct	tcb *tcb_prev;		/* next tcb */
I 15
/* end must match */
	struct	th *t_template;		/* skeletal packet for transmit */
E 15
E 13
	struct	ucb *t_ucb;		/* ucb */
	struct	mbuf *t_rcv_unack;	/* unacked message queue */
I 10
	short	seqcnt;
	short	xxx;
E 10
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
E 3

D 3
	/* various pointers */
E 3
I 3
	/* various flags and state variables */
E 3

D 3
	struct th *t_rcv_next;          /* -> first el on rcv queue */
	struct th *t_rcv_prev;          /* -> last el on rcv queue */
	struct tcb *t_tcb_next;         /* -> next tcb */
	struct tcb *t_tcb_prev;         /* -> prev tcb */
	struct ucb *t_ucb;              /* -> ucb */
	struct mbuf *t_rcv_unack;       /* -> unacked message queue */
E 3
I 3
D 4
	u_short
		ack_due:1,		/* must we send ACK */
		cancelled:1,		/* retransmit timer cancelled */
		dropped_txt:1,		/* dropped incoming data */
		fin_rcvd:1,		/* FIN received */
		force_one:1,		/* force sending of one byte */
		new_window:1,		/* received new window size */
		rexmt:1,		/* this msg is a retransmission */
		snd_fin:1,		/* FIN should be sent */
		snd_rst:1,		/* RST should be sent */
		snd_urg:1,		/* urgent data to send */
		syn_acked:1,		/* SYN has been ACKed */
		syn_rcvd:1,		/* SYN has been received */
		usr_closed:1,		/* user has closed connection */
		waited_2_ml:1,		/* wait time for FIN ACK is up */
		net_keep:1,		/* don't free this net input */
		usr_abort:1;		/* user has closed and does not expect
E 4
I 4
	u_short	tc_flags;
#define	TC_ACK_DUE	0x0001		/* must we send ACK */
#define	TC_CANCELLED	0x0002		/* retransmit timer cancelled */
#define	TC_DROPPED_TXT	0x0004		/* dropped incoming data */
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
E 4
					   to receive any more data */
I 4

E 4
	u_short	t_lport;		/* local port */
	u_short	t_fport;		/* foreign port */
	u_char	t_state;		/* state of this connection */
	u_char	t_xmtime;		/* current rexmt time */
E 3

D 3
	/* sequence number variables */
E 3
I 3
	/* timers */
E 3

D 3
	sequence iss;                   /* initial send seq # */
	sequence irs;                   /* initial recv seq # */
	sequence rcv_urp;               /* rcv urgent pointer */
	sequence rcv_nxt;               /* next seq # to rcv */
	sequence rcv_end;               /* rcv eol pointer */
	sequence snd_off;               /* seq # of first datum in send buf */
	sequence seq_fin;               /* seq # of FIN sent */
	sequence snd_end;               /* send eol pointer */
	sequence snd_urp;               /* snd urgent pointer */
	sequence snd_lst;               /* seq # of last sent datum */
	sequence snd_nxt;               /* seq # of next datum to send */
	sequence snd_una;               /* seq # of first unacked datum */
	sequence snd_wl;                /* seq # of last sent window */
	sequence snd_hi;                /* highest seq # sent */
	sequence snd_wnd;               /* send window max */
	sequence t_rexmt_val;           /* value saved in rexmt timer */
	sequence t_rtl_val;             /* value saved in rexmt too long timer */
	sequence t_xmt_val;             /* seq # sent when xmt timer started */
E 3
I 3
	u_char	t_init;			/* initialization too long */
	u_char	t_rexmt;		/* retransmission */
	u_char	t_rexmttl;		/* retransmit too long */
	u_char	t_persist;		/* retransmit persistance */
	u_char	t_finack;		/* fin acknowledged */
	u_char	t_xmt;			/* round trip transmission time */
I 12

	seq_t	rcv_adv;		/* advertised window */
E 12
};
I 13
struct tcbhead {
	struct	th *t_rcv_next,*t_rcv_prev;
	struct	tcb *tcb_next,*tcb_prev;
};
E 13
E 3

D 3
	/* various flags and state variables */
E 3
I 3
D 5
#define	ISSINCR		128		/* increment for iss each second */
#define	TCPROTO		6		/* TCP-4 protocol number */
#define	TCPSIZE		20		/* size of TCP leader (bytes) */
#define	T_2ML		10		/* 2*maximum packet lifetime */
#define	T_PERS		5		/* persist time */
#define	T_INIT		30		/* init too long timeout */
#define	T_REXMT		1		/* base for retransmission time */
#define	T_REXMTTL	30		/* retransmit too long timeout */
#define	T_REMAX		30		/* maximum retransmission time */
#define	ACTIVE		1		/* active open */
#define	PASSIVE		0		/* passive open */
E 3

E 5
D 3
	unsigned short
		ack_due:1,              /* must we send ACK */
		cancelled:1,            /* retransmit timer cancelled */
		dropped_txt:1,          /* dropped incoming data */
		fin_rcvd:1,             /* FIN received */
		force_one:1,            /* force sending of one byte */
		new_window:1,           /* received new window size */
		rexmt:1,                /* this msg is a retransmission */
		snd_fin:1,              /* FIN should be sent */
		snd_rst:1,              /* RST should be sent */
		snd_urg:1,              /* urgent data to send */
		syn_acked:1,            /* SYN has been ACKed */
		syn_rcvd:1,             /* SYN has been received */
		usr_closed:1,           /* user has closed connection */
		waited_2_ml:1,          /* wait time for FIN ACK is up */
		net_keep:1,             /* don't free this net input */
		usr_abort:1;            /* user has closed and does not expect
					   to receive any more data */
E 3
I 3
/*
I 11
 * TCP timers.
 */
D 14
#define	TINIT		1
#define	TREXMT		2
#define	TREXMTTL	3
#define	TPERSIST	4
#define	TFINACK		5
E 14
I 14
#define	TINIT		0
#define	TREXMT		1
#define	TREXMTTL	2
#define	TPERSIST	3
#define	TFINACK		4
#define	TNTIMERS	5
E 14

/*
E 11
D 5
 * Tcp debugging record.
 */
struct t_debug {
	long	t_tod;			/* time of day */
	struct	tcb *t_tcb;		/* -> tcb */
	char	t_old;			/* old state */
	char	t_inp;			/* input */
	char	t_tim;			/* timer id */
	char	t_new;			/* new state */
	seq_t	t_sno;			/* seq_t number */
	seq_t	t_ano;			/* acknowledgement */
	u_short	t_wno;			/* window */
	u_short	t_lno;			/* length */
	u_char	t_flg;			/* message flags */
};
E 3

D 3
	unsigned short t_flag2;         /* (unused) */
	unsigned short t_lport;         /* local port */
	unsigned short t_fport;         /* foreign port */
	unsigned char t_state;          /* state of this connection */
	unsigned char t_xmtime;         /* current rexmt time */
	unsigned char t_sec;            /* security */
	unsigned char t_prec;           /* precedence */
	unsigned char t_compt;          /* compartment */
E 3
I 3
/*
E 5
 * Tcp machine predicates
 */
#define	ack_ok(x, y) \
D 4
    (!(y)->t_ack || ((x)->iss < (y)->t_ackno && (y)->t_ackno <= (x)->snd_hi))
E 4
I 4
    (((y)->th_flags&TH_ACK)==0 || \
      ((x)->iss < (y)->t_ackno && (y)->t_ackno <= (x)->snd_hi))
E 4
E 3

D 3
	/* timers */
E 3
I 3
#define	syn_ok(x, y) \
D 4
    ((y)->t_syn)
E 4
I 4
    ((y)->th_flags&TH_SYN)
E 4
E 3

D 3
	unsigned char t_init;           /* initialization too long */
	unsigned char t_rexmt;          /* retransmission */
	unsigned char t_rexmttl;        /* retransmit too long */
	unsigned char t_persist;        /* retransmit persistance */
	unsigned char t_finack;         /* fin acknowledged */
	unsigned char t_xmt;            /* round trip transmission time */
};          
	    
#define ISSINCR 128                     /* increment for iss each second */
#define TCPROTO 6                       /* TCP-4 protocol number */
#define TCPSIZE 20                      /* size of TCP leader (bytes) */
#define T_2ML   10                      /* 2*maximum packet lifetime */
#define T_PERS  5                       /* persist time */
#define T_INIT  30                      /* init too long timeout */
#define T_REXMT 1                       /* base for retransmission time */
#define T_REXMTTL 30                    /* retransmit too long timeout */
#define T_REMAX 30                      /* maximum retransmission time */
#define ACTIVE  1                       /* active open */
#define PASSIVE 0                       /* passive open */
E 3
I 3
#define	ack_fin(x, y) \
    ((x)->seq_fin > (x)->iss && (y)->t_ackno > (x)->seq_fin)
E 3

I 3
#define	rcv_empty(x) \
D 4
    ((x)->usr_abort || \
E 4
I 4
    (((x)->tc_flags&TC_USR_ABORT) || \
E 4
      ((x)->t_ucb->uc_rbuf == NULL && (x)->t_rcv_next == (x)->t_rcv_prev))
I 5

I 15
#define	ISSINCR		128		/* increment for iss each second */
#define	TCPSIZE		20		/* size of TCP leader (bytes) */

E 15
I 11
/*
 * THESE NEED TO BE JUSTIFIED!
 */
E 11
D 15
#define	ISSINCR		128		/* increment for iss each second */
#define	TCPROTO		6		/* TCP-4 protocol number */
#define	TCPSIZE		20		/* size of TCP leader (bytes) */
E 15
#define	T_2ML		10		/* 2*maximum packet lifetime */
#define	T_PERS		5		/* persist time */
#define	T_INIT		30		/* init too long timeout */
#define	T_REXMT		1		/* base for retransmission time */
#define	T_REXMTTL	30		/* retransmit too long timeout */
#define	T_REMAX		30		/* maximum retransmission time */
I 15

E 15
#define	ACTIVE		1		/* active open */
#define	PASSIVE		0		/* passive open */

#ifdef TCPDEBUG
#define	TDBSIZE		50
/*
 * Tcp debugging record.
 */
struct tcp_debug {
	long	td_tod;			/* time of day */
	struct	tcb *td_tcb;		/* -> tcb */
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
I 11
#endif

E 11
#ifdef KERNEL
D 11
int	tcpconsdebug;		/* set to 1 traces on console */
E 11
I 11
D 13
struct	tcb *tcb_head, *tcb_tail;	/* tcp tcb list */
E 13
I 13
struct	tcbhead tcb;			/* tcp tcb list head */
E 13
seq_t	tcp_iss;			/* tcp initial send seq # */
int	tcpconsdebug;			/* set to 1 traces on console */
#ifdef TCPDEBUG
E 11
struct	tcp_debug tcp_debug[TDBSIZE];
D 11
int	tdbx;			/* rotating index into tcp_debug */
E 11
#endif
I 11
int	tdbx;			/* rotating index into tcp_debug */
struct	th *tcp_template();
E 11
#endif
I 9

#define	SEQ_LT(a,b)	((int)((a)-(b)) < 0)
#define	SEQ_LEQ(a,b)	((int)((a)-(b)) <= 0)
#define	SEQ_GT(a,b)	((int)((a)-(b)) > 0)
#define	SEQ_GEQ(a,b)	((int)((a)-(b)) >= 0)
I 15
struct	th *tcp_template();
E 16
E 15
E 9
E 5
E 3
E 1
