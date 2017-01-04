h57531
s 00010/00005/00121
d D 7.7 88/06/29 17:06:47 bostic 27 25
c install approved copyright notice
e
s 00015/00000/00126
d D 7.6.1.1 88/03/15 12:09:20 karels 26 25
c branch for network release (byte order #ifdefs)
e
s 00002/00000/00124
d D 7.6 88/02/22 10:44:07 karels 25 24
c add IP_MAXPACKET
e
s 00006/00006/00118
d D 7.5 88/01/07 11:33:33 karels 24 23
c rename endians
e
s 00008/00002/00116
d D 7.4 87/12/07 17:45:33 bostic 23 22
c use Berkeley specific header
e
s 00001/00001/00117
d D 7.3 86/12/15 10:10:38 karels 22 21
c increase FRAGTTL
e
s 00011/00001/00107
d D 7.2 86/10/28 22:53:30 karels 21 20
c byte order changes for tahoe
e
s 00001/00001/00107
d D 7.1 86/06/05 00:26:55 mckusick 20 19
c 4.3BSD release version
e
s 00008/00000/00100
d D 6.6 85/09/16 22:53:40 karels 19 18
c parameterize IP option offsets
e
s 00007/00001/00093
d D 6.5 85/06/08 12:39:27 mckusick 18 17
c Add copyright
e
s 00002/00000/00092
d D 6.4 84/10/19 15:03:07 karels 17 16
c bind local address according to routing (caching the route);
c pick maximum seg sizes (offered and accepted) based on interface mtu,
c with default if not local
e
s 00001/00001/00091
d D 6.3 84/05/22 11:08:13 karels 16 15
c allow more than 3 hops for TCP!
e
s 00005/00005/00087
d D 6.2 84/02/15 13:00:08 karels 15 14
c ip option classes are 2 bits
e
s 00000/00000/00092
d D 6.1 83/07/29 07:11:27 sam 14 13
c 4.2 distribution
e
s 00001/00005/00091
d D 1.12 83/07/06 18:09:55 sam 13 12
c sun purge
e
s 00006/00000/00090
d D 1.11 82/12/28 21:04:38 sam 12 11
c bit field incompatibilities with sun
e
s 00001/00000/00089
d D 1.10 82/03/30 11:32:25 sam 11 10
c with routing, but not forwarding
e
s 00002/00002/00087
d D 1.9 81/11/18 15:37:03 wnj 10 9
c more cleanup
e
s 00000/00000/00089
d D 1.8 81/11/15 12:59:33 wnj 9 8
c listing
e
s 00004/00042/00085
d D 1.7 81/11/14 16:39:50 wnj 8 7
c before overlay
e
s 00004/00004/00123
d D 1.6 81/11/08 16:24:21 wnj 7 6
c first listing
e
s 00089/00018/00038
d D 1.5 81/10/29 20:26:41 wnj 6 5
c cleanup of header files
e
s 00007/00002/00049
d D 1.4 81/10/28 22:11:53 wnj 5 3
c shorts, pragmatically, for ip_len and ip_off
e
s 00015/00011/00040
d R 1.4 81/10/26 02:09:16 wnj 4 3
c first compile of major cleanup
e
s 00036/00032/00015
d D 1.3 81/10/21 19:06:27 wnj 3 2
c cleanup the headers
e
s 00005/00000/00042
d D 1.2 81/10/14 19:12:14 wnj 2 1
c new version: macros and fast cksum
e
s 00042/00000/00000
d D 1.1 81/10/14 09:57:25 wnj 1 0
c date and time created 81/10/14 09:57:25 by wnj
e
u
U
f b 
t
T
I 1
D 13
/* %M% %I% %E% */
E 13
I 13
D 18
/*	%M%	%I%	%E%	*/
E 18
I 18
/*
D 20
 * Copyright (c) 1982 Regents of the University of California.
E 20
I 20
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 20
D 23
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 23
I 23
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 27
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 27
I 27
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
E 27
E 23
 *
 *	%W% (Berkeley) %G%
 */
I 26
#ifndef BYTE_ORDER
/*
 * Definitions for byte order,
 * according to byte significance from low address to high.
 */
#define	LITTLE_ENDIAN	1234	/* least-significant byte first (vax) */
#define	BIG_ENDIAN	4321	/* most-significant byte first (IBM, net) */
#define	PDP_ENDIAN	3412	/* LSB first in word, MSW first in long (pdp) */

#ifdef vax
#define	BYTE_ORDER	LITTLE_ENDIAN
#else
#define	BYTE_ORDER	BIG_ENDIAN	/* mc68000, tahoe, most others */
#endif
#endif BYTE_ORDER
E 26
E 18
E 13
D 3
struct ip {                     /* ip leader */
	unsigned char ip_hl:4,          /* header length */
		ip_v:4;                 /* version */
	unsigned char ip_tos;           /* type of service */
#define ip_mff ip_tos                   /* more fragments flag (input) */
	unsigned short ip_len;          /* total length */
	unsigned short ip_id;           /* identification */
	unsigned short ip_off;          /* fragment offset field */
#define ip_df 0x4000                    /* dont fragment flag */
#define ip_mf 0x2000                    /* more fragments flag (output) */
	unsigned char ip_ttl;           /* time to live */
	unsigned char ip_p;             /* protocol */
	unsigned short ip_sum;          /* checksum */
#define ip_end ip_sum                   /* fragment end */
E 3
I 3

I 6
/*
 * Definitions for internet protocol version 4.
 * Per RFC 791, September 1981.
 */
#define	IPVERSION	4

/*
 * Structure of an internet header, naked of options.
 *
D 8
 * SHOULD MAKE A VERSION OF THIS FOR KERNEL SO USER
 * VERSION CAN BE union FREE AND INITIALIZABLE.
E 8
I 8
 * We declare ip_len and ip_off to be short, rather than u_short
 * pragmatically since otherwise unsigned comparisons can result
 * against negative integers quite easily, and fail in subtle ways.
E 8
 */
E 6
struct ip {
I 12
D 21
#ifdef vax
E 21
I 21
D 24
#if ENDIAN == LITTLE
E 24
I 24
#if BYTE_ORDER == LITTLE_ENDIAN 
E 24
E 21
E 12
	u_char	ip_hl:4,		/* header length */
		ip_v:4;			/* version */
I 12
D 13
#endif
#ifdef sun
	u_char	ip_v:4,			/* version */
		ip_hl:4;		/* header length */
E 13
#endif
I 21
D 24
#if ENDIAN == BIG
E 24
I 24
#if BYTE_ORDER == BIG_ENDIAN 
E 24
	u_char	ip_v:4,			/* version */
		ip_hl:4;		/* header length */
#endif
E 21
E 12
	u_char	ip_tos;			/* type of service */
D 6
#define	ip_mff	ip_tos			/* more fragments flag (input) */
E 6
I 6
D 8
/* we copy the IP_MF to ip_tos on input */
#define	ip_mff	ip_tos			/* more fragments flag */
E 6
D 5
	u_short	ip_len;			/* total length */
E 5
I 5
/* by rights, ip_len should be a u_short, but this makes operations */
/* on it very dangerous as comparisons become unsigned and comparing */
/* against negative numbers then fails... we don't expect any > 32767 */
/* byte packets, so pragmatically delcare it to be a short */
E 8
	short	ip_len;			/* total length */
E 5
	u_short	ip_id;			/* identification */
D 5
	u_short	ip_off;			/* fragment offset field */
E 5
I 5
D 8
/* ip_off should also, by rights, be u_short, ala ip_len */
E 8
	short	ip_off;			/* fragment offset field */
E 5
D 6
#define	ip_df 0x4000			/* dont fragment flag */
#define	ip_mf 0x2000			/* more fragments flag (output) */
E 6
I 6
#define	IP_DF 0x4000			/* dont fragment flag */
#define	IP_MF 0x2000			/* more fragments flag */
E 6
	u_char	ip_ttl;			/* time to live */
	u_char	ip_p;			/* protocol */
	u_short	ip_sum;			/* checksum */
D 6
#define	ip_end	ip_sum			/* fragment end */
E 6
E 3
D 8
	union {
D 3
		struct socket ip_s;     /* source address */
		struct ip *ip_nxt;      /* ->next fragment */      
E 3
I 3
D 7
		struct socket ip_s;	/* source address */
E 7
I 7
		struct ip_addr ip_s;	/* source address */
E 7
		struct ip *ip_nxt;	/* next fragment */
E 3
	} I_sun;
D 3
#define ip_src  I_sun.ip_s
#define ip_next I_sun.ip_nxt
E 3
I 3
#define	ip_src	I_sun.ip_s
#define	ip_next	I_sun.ip_nxt
E 3
	union {
D 3
		struct socket ip_d;     /* destination address */
		struct ip *ip_prv;      /* ->prev fragment */
E 3
I 3
D 7
		struct socket ip_d;	/* destination address */
E 7
I 7
		struct ip_addr ip_d;	/* destination address */
E 7
		struct ip *ip_prv;	/* prev fragment */
E 3
	} I_dun;
D 3
#define ip_dst  I_dun.ip_d
#define ip_prev I_dun.ip_prv
E 3
I 3
#define	ip_dst	I_dun.ip_d
#define	ip_prev I_dun.ip_prv
E 8
I 8
D 10
	struct	ip_addr ip_src,ip_dst;	/* source and dest address */
E 10
I 10
	struct	in_addr ip_src,ip_dst;	/* source and dest address */
E 10
E 8
E 3
};

I 25
#define	IP_MAXPACKET	65535		/* maximum packet size */

E 25
D 3
struct ipq {                    /* ip reass.q header */
	struct ip iqx;                  /* dummy ip element for top of list */
	struct ipq *iq_next;            /* -> next chain on q */
	struct ipq *iq_prev;            /* -> prev chain on q */
	struct ip iqh;                  /* fragment header */
E 3
I 3
/*
D 6
 * Ip reassembly queue.
E 6
I 6
 * Definitions for options.
E 6
 */
I 6
#define	IPOPT_COPIED(o)		((o)&0x80)
D 15
#define	IPOPT_CLASS(o)		((o)&0x40)
#define	IPOPT_NUMBER(o)		((o)&0x3f)
E 15
I 15
#define	IPOPT_CLASS(o)		((o)&0x60)
#define	IPOPT_NUMBER(o)		((o)&0x1f)
E 15

#define	IPOPT_CONTROL		0x00
D 15
#define	IPOPT_RESERVED1		0x10
#define	IPOPT_DEBMEAS		0x20
#define	IPOPT_RESERVED2		0x30
E 15
I 15
#define	IPOPT_RESERVED1		0x20
#define	IPOPT_DEBMEAS		0x40
#define	IPOPT_RESERVED2		0x60
E 15

#define	IPOPT_EOL		0		/* end of option list */
#define	IPOPT_NOP		1		/* no operation */

#define	IPOPT_RR		7		/* record packet route */
#define	IPOPT_TS		68		/* timestamp */
#define	IPOPT_SECURITY		130		/* provide s,c,h,tcc */
#define	IPOPT_LSRR		131		/* loose source route */
#define	IPOPT_SATID		136		/* satnet id */
#define	IPOPT_SSRR		137		/* strict source route */

/*
I 19
 * Offsets to fields in options other than EOL and NOP.
 */
#define	IPOPT_OPTVAL		0		/* option ID */
#define	IPOPT_OLEN		1		/* option length */
#define IPOPT_OFFSET		2		/* offset within option */
#define	IPOPT_MINOFF		4		/* min value of above */

/*
E 19
 * Time stamp option structure.
 */
struct	ip_timestamp {
	u_char	ipt_code;		/* IPOPT_TS */
	u_char	ipt_len;		/* size of structure (variable) */
	u_char	ipt_ptr;		/* index of current entry */
I 21
D 24
#if ENDIAN == LITTLE
E 24
I 24
#if BYTE_ORDER == LITTLE_ENDIAN 
E 24
E 21
	u_char	ipt_flg:4,		/* flags, see below */
		ipt_oflw:4;		/* overflow counter */
I 21
#endif
D 24
#if ENDIAN == BIG
E 24
I 24
#if BYTE_ORDER == BIG_ENDIAN 
E 24
	u_char	ipt_oflw:4,		/* overflow counter */
		ipt_flg:4;		/* flags, see below */
#endif
E 21
D 24
	union {
E 24
I 24
	union ipt_timestamp {
E 24
		n_long	ipt_time[1];
		struct	ipt_ta {
D 7
			struct socket ipt_addr;
E 7
I 7
D 10
			struct ip_addr ipt_addr;
E 10
I 10
			struct in_addr ipt_addr;
E 10
E 7
			n_long ipt_time;
		} ipt_ta[1];
D 24
	}
E 24
I 24
	} ipt_timestamp;
E 24
};

/* flag bits for ipt_flg */
#define	IPOPT_TS_TSONLY		0		/* timestamps only */
#define	IPOPT_TS_TSANDADDR	1		/* timestamps and addresses */
#define	IPOPT_TS_PRESPEC	2		/* specified modules only */

/* bits for security (not byte swapped) */
#define	IPOPT_SECUR_UNCLASS	0x0000
#define	IPOPT_SECUR_CONFID	0xf135
#define	IPOPT_SECUR_EFTO	0x789a
#define	IPOPT_SECUR_MMMM	0xbc4d
#define	IPOPT_SECUR_RESTR	0xaf13
#define	IPOPT_SECUR_SECRET	0xd788
#define	IPOPT_SECUR_TOPSECRET	0x6bc5

/*
D 8
 * Ip reassembly queue structure.  Each fragment
 * being reassambled is attached to one of these structures.
 * They are timed out after ipq_ttl drops to 0, and may also
 * be reclaimed if memory becomes tight.
 */
E 6
struct ipq {
D 6
	struct	ip iqx;		/* dummy ip element for top of list */
	struct	ipq *iq_next;	/* -> next chain on q */
	struct	ipq *iq_prev;	/* -> prev chain on q */
	struct	ip iqh;		/* fragment header */
E 6
I 6
	struct	ipq *next,*prev;	/* to other reass headers */
	u_char	ipq_ttl;		/* time for reass q to live */
	u_char	ipq_p;			/* protocol of this fragment */
	u_short	ipq_id;			/* sequence id for reassembly */
	struct	ip *ipq_next,*ipq_prev;	/* to ip headers of fragments */
D 7
	struct	socket ipq_src,ipq_dst;
E 7
I 7
	struct	ip_addr ipq_src,ipq_dst;
E 7
E 6
E 3
};

D 3
#define IPVERSION 4             /* internet protocol version number */
#define IPLOLINK 155            /* internet link numbers */
#define IPHILINK 158
#define IPLINK IPLOLINK
#define MAXTTL 255              /* maximum time to live (seconds) */
E 3
I 3
D 6
#define	IPVERSION	4		/* internet protocol version number */
#define	IPLOLINK	155		/* internet link numbers */
#define	IPHILINK	158
#define	IPLINK		IPLOLINK
E 6
I 6
/*
E 8
 * Internet implementation parameters.
 */
E 6
#define	MAXTTL		255		/* maximum time to live (seconds) */
I 6
D 22
#define	IPFRAGTTL	15		/* time to live for frag chains */
E 22
I 22
#define	IPFRAGTTL	60		/* time to live for frags, slowhz */
E 22
I 11
D 16
#define	IPTTLDEC	5		/* subtracted when forwarding */
E 16
I 16
#define	IPTTLDEC	1		/* subtracted when forwarding */
I 17

#define	IP_MSS		576		/* default maximum segment size */
E 17
E 16
E 11
E 6
E 3
D 8

I 2
D 6
#define	ip_bswap(p) { \
	p->ip_len = ntohs(p->ip_len); \
	p->ip_id = ntohs(p->ip_id); \
	p->ip_off = ntohs(p->ip_off); }

E 6
I 6
#ifdef KERNEL
struct	ipq	ipq;			/* ip reass. queue */
struct	ipq	*ip_freef();
u_short	ip_id;				/* ip packet ctr, for ids */
#endif
E 8
E 6
E 2
E 1
