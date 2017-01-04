h52835
s 00010/00005/00102
d D 7.5 88/06/29 17:07:07 bostic 21 20
c install approved copyright notice
e
s 00002/00002/00105
d D 7.4 88/01/07 11:33:35 karels 20 19
c rename endians
e
s 00008/00002/00099
d D 7.3 87/12/07 17:45:53 bostic 19 18
c use Berkeley specific header
e
s 00005/00001/00096
d D 7.2 86/10/28 22:53:35 karels 18 17
c byte order changes for tahoe
e
s 00001/00001/00096
d D 7.1 86/06/05 00:28:44 mckusick 17 16
c 4.3BSD release version
e
s 00025/00005/00072
d D 6.5 85/09/16 23:13:05 karels 16 15
c IP option structure for src routing; more statistics
e
s 00007/00001/00070
d D 6.4 85/06/08 12:41:09 mckusick 15 14
c Add copyright
e
s 00002/00000/00069
d D 6.3 85/05/23 09:47:26 karels 14 13
c count packets forwarded, dropped
e
s 00003/00003/00066
d D 6.2 84/08/29 15:02:10 karels 13 12
c add SO_BROADCAST
e
s 00000/00000/00069
d D 6.1 83/07/29 07:11:57 sam 12 11
c 4.2 distribution
e
s 00000/00004/00069
d D 4.11 83/07/06 18:10:00 sam 11 10
c sun purge
e
s 00005/00000/00068
d D 4.10 83/05/12 15:04:18 sam 10 9
c fix ip packet forwarding to not stomp on headers when fragmented;
e
s 00003/00000/00065
d D 4.9 83/02/23 00:27:59 sam 9 8
c more statistics
e
s 00000/00001/00065
d D 4.8 83/02/05 15:51:47 sam 8 7
c ip_freef now void
e
s 00006/00000/00060
d D 4.7 82/12/28 21:04:49 sam 7 6
c bit field incompatibilities with sun
e
s 00002/00000/00058
d D 4.6 82/11/13 23:11:38 sam 6 5
c merge 4.1b with 4.1c
e
s 00002/00001/00056
d D 4.5 81/12/02 16:58:49 wnj 5 4
c yet more lint
e
s 00000/00000/00057
d D 4.4 81/11/26 11:56:54 wnj 4 3
c before carry to ARPAVAX
e
s 00009/00004/00048
d D 4.3 81/11/18 15:37:36 wnj 3 2
c more cleanup
e
s 00008/00008/00044
d D 4.2 81/11/15 12:59:55 wnj 2 1
c listing
e
s 00052/00000/00000
d D 4.1 81/11/14 16:51:59 wnj 1 0
c date and time created 81/11/14 16:51:59 by wnj
e
u
U
t
T
I 1
D 15
/*	%M%	%I%	%E%	*/
E 15
I 15
/*
D 17
 * Copyright (c) 1982 Regents of the University of California.
E 17
I 17
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 17
D 19
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 19
I 19
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 21
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 21
I 21
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
E 21
E 19
 *
 *	%W% (Berkeley) %G%
 */
E 15

/*
 * Overlay for ip header used by other protocols (tcp, udp).
 */
struct ipovly {
D 2
	caddr_t	ipo_next, ipo_prev;	/* for protocol sequence q's */
	u_char	ipo_x1;			/* (unused) */
	u_char	ipo_pr;			/* protocol */
	short	ipo_len;		/* protocol length */
	struct	ip_addr ipo_s;		/* source internet address */
	struct	ip_addr ipo_d;		/* destination internet address */
E 2
I 2
	caddr_t	ih_next, ih_prev;	/* for protocol sequence q's */
	u_char	ih_x1;			/* (unused) */
	u_char	ih_pr;			/* protocol */
D 3
	short	ih_len;		/* protocol length */
	struct	ip_addr ih_src;		/* source internet address */
	struct	ip_addr ih_dst;		/* destination internet address */
E 3
I 3
	short	ih_len;			/* protocol length */
	struct	in_addr ih_src;		/* source internet address */
	struct	in_addr ih_dst;		/* destination internet address */
E 3
E 2
};

/*
 * Ip reassembly queue structure.  Each fragment
 * being reassembled is attached to one of these structures.
 * They are timed out after ipq_ttl drops to 0, and may also
 * be reclaimed if memory becomes tight.
 */
struct ipq {
	struct	ipq *next,*prev;	/* to other reass headers */
	u_char	ipq_ttl;		/* time for reass q to live */
	u_char	ipq_p;			/* protocol of this fragment */
	u_short	ipq_id;			/* sequence id for reassembly */
	struct	ipasfrag *ipq_next,*ipq_prev;
					/* to ip headers of fragments */
D 3
	struct	ip_addr ipq_src,ipq_dst;
E 3
I 3
	struct	in_addr ipq_src,ipq_dst;
E 3
};

/*
 * Ip header, when holding a fragment.
I 6
 *
 * Note: ipf_next must be at same offset as ipq_next above
E 6
 */
struct	ipasfrag {
I 7
D 18
#ifdef vax
E 18
I 18
D 20
#if ENDIAN == LITTLE
E 20
I 20
#if BYTE_ORDER == LITTLE_ENDIAN 
E 20
E 18
E 7
	u_char	ip_hl:4,
		ip_v:4;
I 18
#endif
D 20
#if ENDIAN == BIG
E 20
I 20
#if BYTE_ORDER == BIG_ENDIAN 
E 20
	u_char	ip_v:4,
		ip_hl:4;
E 18
I 7
#endif
D 11
#ifdef sun
	u_char	ip_v:4,
		ip_hl:4;
#endif
E 11
E 7
	u_char	ipf_mff;		/* copied from (ip_off&IP_MF) */
	short	ip_len;
	u_short	ip_id;
	short	ip_off;
	u_char	ip_ttl;
	u_char	ip_p;
	u_short	ip_sum;
D 2
	struct	ipf *ipf_next;		/* next fragment */
	struct	ipf *ipf_prev;		/* previous fragment */
E 2
I 2
	struct	ipasfrag *ipf_next;	/* next fragment */
	struct	ipasfrag *ipf_prev;	/* previous fragment */
E 2
};

I 16
/*
 * Structure stored in mbuf in inpcb.ip_options
 * and passed to ip_output when ip options are in use.
 * The actual length of the options (including ipopt_dst)
 * is in m_len.
 */
#define MAX_IPOPTLEN	40

struct ipoption {
	struct	in_addr ipopt_dst;	/* first-hop dst if source routed */
	char	ipopt_list[MAX_IPOPTLEN];	/* options proper */
};

E 16
I 3
struct	ipstat {
D 5
	int	ips_badsum;
E 5
I 5
D 16
	int	ips_badsum;		/* checksum bad */
	int	ips_tooshort;		/* packet too short */
I 9
	int	ips_toosmall;		/* not enough data */
	int	ips_badhlen;		/* ip header length < data size */
	int	ips_badlen;		/* ip length < ip header length */
E 16
I 16
	long	ips_total;		/* total packets received */
	long	ips_badsum;		/* checksum bad */
	long	ips_tooshort;		/* packet too short */
	long	ips_toosmall;		/* not enough data */
	long	ips_badhlen;		/* ip header length < data size */
	long	ips_badlen;		/* ip length < ip header length */
	long	ips_fragments;		/* fragments received */
	long	ips_fragdropped;	/* frags dropped (dups, out of space) */
	long	ips_fragtimeout;	/* fragments timed out */
E 16
I 14
	long	ips_forward;		/* packets forwarded */
	long	ips_cantforward;	/* packets rcvd for unreachable dest */
I 16
	long	ips_redirectsent;	/* packets forwarded on same net */
E 16
E 14
E 9
E 5
};

E 3
#ifdef KERNEL
I 10
/* flags passed to ip_output as last parameter */
D 13
#define	IP_FORWARDING		0x1	/* most of ip header exists */
#define	IP_ROUTETOIF		0x10	/* same as SO_DONTROUTE */
#define	IP_ALLOWBROADCAST	SS_PRIV	/* can send broadcast packets */
E 13
I 13
#define	IP_FORWARDING		0x1		/* most of ip header exists */
#define	IP_ROUTETOIF		SO_DONTROUTE	/* bypass routing tables */
#define	IP_ALLOWBROADCAST	SO_BROADCAST	/* can send broadcast packets */
E 13

E 10
I 3
struct	ipstat	ipstat;
E 3
struct	ipq	ipq;			/* ip reass. queue */
D 8
struct	ipq	*ip_freef();
E 8
u_short	ip_id;				/* ip packet ctr, for ids */
I 16

struct	mbuf *ip_srcroute();
E 16
#endif
E 1
