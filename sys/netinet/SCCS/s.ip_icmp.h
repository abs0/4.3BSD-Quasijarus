h27915
s 00010/00005/00107
d D 7.4 88/06/29 17:06:52 bostic 13 12
c install approved copyright notice
e
s 00008/00002/00104
d D 7.3 87/12/07 17:45:40 bostic 12 11
c use Berkeley specific header
e
s 00006/00000/00100
d D 7.2 87/06/04 21:59:21 karels 11 10
c allow icmp errors about non-error icmp messages
e
s 00001/00001/00099
d D 7.1 86/06/05 00:27:29 mckusick 10 9
c 4.3BSD release version
e
s 00002/00000/00098
d D 6.4 86/04/12 20:44:37 karels 9 8
c name the data field for echo, etc.
e
s 00007/00000/00091
d D 6.3 85/09/16 23:02:17 karels 8 7
c add mask request, reply
e
s 00007/00001/00084
d D 6.2 85/06/08 12:40:07 mckusick 7 6
c Add copyright
e
s 00000/00000/00085
d D 6.1 83/07/29 07:11:35 sam 6 5
c 4.2 distribution
e
s 00001/00001/00084
d D 4.5 82/04/25 18:35:35 sam 5 4
c icmp works with tcp and friends
e
s 00002/00000/00083
d D 4.4 82/04/24 20:38:14 sam 4 3
c icmp and ctlinput working -- missing protocol specific ctlinput's
e
s 00001/00001/00082
d D 4.3 81/12/03 17:29:46 wnj 3 2
c cleanup
e
s 00001/00001/00082
d D 4.2 81/11/18 15:37:12 wnj 2 1
c more cleanup
e
s 00083/00000/00000
d D 4.1 81/11/08 16:29:27 wnj 1 0
c date and time created 81/11/08 16:29:27 by wnj
e
u
U
t
T
I 1
D 7
/* %M% %I% %E% */
E 7
I 7
/*
D 10
 * Copyright (c) 1982 Regents of the University of California.
E 10
I 10
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 10
D 12
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 12
I 12
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 13
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 13
I 13
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
E 13
E 12
 *
 *	%W% (Berkeley) %G%
 */
E 7

/*
 * Interface Control Message Protocol Definitions.
 * Per RFC 792, September 1981.
 */

/*
 * Structure of an icmp header.
 */
struct icmp {
	u_char	icmp_type;		/* type of message, see below */
	u_char	icmp_code;		/* type sub code */
	u_short	icmp_cksum;		/* ones complement cksum of struct */
	union {
		u_char ih_pptr;			/* ICMP_PARAMPROB */
D 2
		struct ip_addr ih_gwaddr;	/* ICMP_REDIRECT */
E 2
I 2
		struct in_addr ih_gwaddr;	/* ICMP_REDIRECT */
E 2
		struct ih_idseq {
			n_short	icd_id;
			n_short	icd_seq;
		} ih_idseq;
I 4
		int ih_void;
E 4
	} icmp_hun;
#define	icmp_pptr	icmp_hun.ih_pptr
#define	icmp_gwaddr	icmp_hun.ih_gwaddr
#define	icmp_id		icmp_hun.ih_idseq.icd_id
#define	icmp_seq	icmp_hun.ih_idseq.icd_seq
I 4
#define	icmp_void	icmp_hun.ih_void
E 4
	union {
		struct id_ts {
			n_time its_otime;
			n_time its_rtime;
			n_time its_ttime;
		} id_ts;
		struct id_ip  {
			struct ip idi_ip;
			/* options and then 64 bits of data */
		} id_ip;
I 8
		u_long	id_mask;
I 9
		char	id_data[1];
E 9
E 8
	} icmp_dun;
#define	icmp_otime	icmp_dun.id_ts.its_otime
#define	icmp_rtime	icmp_dun.id_ts.its_rtime
#define	icmp_ttime	icmp_dun.id_ts.its_ttime
#define	icmp_ip		icmp_dun.id_ip.idi_ip
I 8
#define	icmp_mask	icmp_dun.id_mask
I 9
#define	icmp_data	icmp_dun.id_data
E 9
E 8
};

/*
 * Lower bounds on packet lengths for various types.
 * For the error advice packets must first insure that the
 * packet is large enought to contain the returned ip header.
 * Only then can we do the check to see if 64 bits of packet
 * data have been returned, since we need to check the returned
 * ip header length.
 */
#define	ICMP_MINLEN	8				/* abs minimum */
#define	ICMP_TSLEN	(8 + 3 * sizeof (n_time))	/* timestamp */
I 8
#define	ICMP_MASKLEN	12				/* address mask */
E 8
#define	ICMP_ADVLENMIN	(8 + sizeof (struct ip) + 8)	/* min */
D 5
#define	ICMP_ADVLEN(p)	(8 + ((p)->icmp_ip.ip_len << 2) + 8)
E 5
I 5
#define	ICMP_ADVLEN(p)	(8 + ((p)->icmp_ip.ip_hl << 2) + 8)
E 5
	/* N.B.: must separately check that ip_hl >= 5 */

/*
 * Definition of type and code field values.
 */
#define	ICMP_ECHOREPLY		0		/* echo reply */
#define	ICMP_UNREACH		3		/* dest unreachable, codes: */
#define		ICMP_UNREACH_NET	0		/* bad net */
#define		ICMP_UNREACH_HOST	1		/* bad host */
#define		ICMP_UNREACH_PROTOCOL	2		/* bad protocol */
#define		ICMP_UNREACH_PORT	3		/* bad port */
#define		ICMP_UNREACH_NEEDFRAG	4		/* IP_DF caused drop */
#define		ICMP_UNREACH_SRCFAIL	5		/* src route failed */
#define	ICMP_SOURCEQUENCH	4		/* packet lost, slow down */
#define	ICMP_REDIRECT		5		/* shorter route, codes: */
#define		ICMP_REDIRECT_NET	0		/* for network */
#define		ICMP_REDIRECT_HOST	1		/* for host */
#define		ICMP_REDIRECT_TOSNET	2		/* for tos and net */
#define		ICMP_REDIRECT_TOSHOST	3		/* for tos and host */
#define	ICMP_ECHO		8		/* echo service */
#define	ICMP_TIMXCEED		11		/* time exceeded, code: */
#define		ICMP_TIMXCEED_INTRANS	0		/* ttl==0 in transit */
#define		ICMP_TIMXCEED_REASS	1		/* ttl==0 in reass */
I 3
#define	ICMP_PARAMPROB		12		/* ip header bad */
E 3
#define	ICMP_TSTAMP		13		/* timestamp request */
#define	ICMP_TSTAMPREPLY	14		/* timestamp reply */
#define	ICMP_IREQ		15		/* information request */
#define	ICMP_IREQREPLY		16		/* information reply */
I 8
#define	ICMP_MASKREQ		17		/* address mask request */
#define	ICMP_MASKREPLY		18		/* address mask reply */

#define	ICMP_MAXTYPE		18
I 11

#define	ICMP_INFOTYPE(type) \
	((type) == ICMP_ECHOREPLY || (type) == ICMP_ECHO || \
	(type) == ICMP_TSTAMP || (type) == ICMP_TSTAMPREPLY || \
	(type) == ICMP_IREQ || (type) == ICMP_IREQREPLY || \
	(type) == ICMP_MASKREQ || (type) == ICMP_MASKREPLY)
E 11
E 8
D 3
#define	ICMP_PARAMPROB		12		/* ip header bad */
E 3
E 1
