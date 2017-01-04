h03775
s 00001/00000/00120
d D 7.7 07/05/18 19:46:53 msokolov 39 38
c IPPROTO_GRE defined
e
s 00010/00005/00110
d D 7.6 88/06/29 17:06:34 bostic 38 37
c install approved copyright notice
e
s 00001/00001/00114
d D 7.5 88/02/22 10:43:47 karels 37 36
c fix GGP (for what it's worth)
e
s 00008/00002/00107
d D 7.4 87/12/07 17:45:14 bostic 36 35
c use Berkeley specific header
e
s 00009/00001/00100
d D 7.3 87/06/04 21:48:43 karels 35 34
c add class D, experimental; don't forward those, net 0 or loopback
e
s 00003/00015/00098
d D 7.2 87/01/16 12:58:34 karels 34 33
c share ntoh? definitions
e
s 00001/00001/00112
d D 7.1 86/06/05 00:25:25 mckusick 33 32
c 4.3BSD release version
e
s 00006/00001/00107
d D 6.11 86/04/14 11:36:37 karels 32 31
c declare ntoh*, hton* if not nops, always for lint
e
s 00007/00007/00101
d D 6.10 86/02/23 23:23:34 karels 31 30
c lint
e
s 00003/00000/00105
d D 6.9 86/02/01 21:17:14 karels 30 29
c reserve a port range for unprivileged servers
e
s 00001/00000/00104
d D 6.8 85/09/16 22:43:33 karels 29 28
c lint
e
s 00007/00000/00097
d D 6.7 85/08/09 12:24:50 karels 28 27
c add IPPROTO_IP for ctloutput, _IDP for NSIP XXX, IP_OPTIONS
c to set IP options on output
e
s 00003/00024/00094
d D 6.6 85/06/19 08:32:35 karels 27 26
c remove old subnet defines
e
s 00007/00001/00111
d D 6.5 85/06/08 12:37:40 mckusick 26 25
c Add copyright
e
s 00005/00053/00107
d D 6.4 85/03/18 15:28:39 karels 25 24
c distinguish INADDR_BROADCAST from INADDR_ANY; remove old stuff
e
s 00001/00000/00159
d D 6.3 84/07/31 17:58:53 karels 24 23
c add EGP
e
s 00025/00000/00134
d D 6.2 84/04/12 11:32:07 karels 23 22
c subnet routing
e
s 00000/00000/00134
d D 6.1 83/07/29 07:11:10 sam 22 21
c 4.2 distribution
e
s 00001/00000/00133
d D 4.20 83/01/17 19:06:43 sam 21 19
c network disk protocol
e
s 00001/00000/00133
d R 4.20 83/01/17 15:55:16 sam 20 19
c add unofficial network disk protocol number
e
s 00000/00002/00133
d D 4.19 82/12/17 12:17:49 sam 19 18
c sun merge
e
s 00005/00000/00130
d D 4.18 82/11/03 01:08:03 root 18 17
c misc 4.1c fixes
e
s 00010/00000/00120
d D 4.17 82/10/31 14:42:03 root 17 16
c [hn]to[hn][ls] when not vax
e
s 00003/00004/00117
d D 4.16 82/10/20 01:22:09 root 16 15
c lint
e
s 00015/00024/00106
d D 4.15 82/10/17 14:54:28 root 15 14
c fix lint
e
s 00002/00000/00128
d D 4.14 82/06/30 21:33:11 wnj 14 13
c more servers
e
s 00015/00013/00113
d D 4.13 82/06/13 23:01:27 sam 13 12
c add class a/b/c net #'s and purge logical host kludge code
e
s 00026/00000/00100
d D 4.12 82/06/05 21:20:51 wnj 12 11
c macros for different classes of network
e
s 00017/00000/00083
d D 4.11 82/03/15 11:20:08 root 11 10
c no more wellknown.h
e
s 00002/00000/00081
d D 4.10 82/03/05 14:06:57 wnj 10 9
c minor fixes
e
s 00005/00001/00076
d D 4.9 82/02/27 17:47:06 wnj 9 8
c multi-homing and wildcards
e
s 00004/00004/00073
d D 4.8 82/02/03 10:36:51 sam 8 7
c clean up inaddr structure
e
s 00001/00001/00076
d D 4.7 82/01/24 18:35:30 wnj 7 6
c RAW protocol is 255, not -1
e
s 00000/00000/00077
d D 4.6 81/11/29 21:59:17 wnj 6 5
c lint and interface cleanups
e
s 00000/00000/00077
d D 4.5 81/11/26 11:56:12 wnj 5 4
c before carry to ARPAVAX
e
s 00011/00001/00066
d D 4.4 81/11/18 15:36:41 wnj 4 3
c more cleanup
e
s 00002/00000/00065
d D 4.3 81/11/15 12:59:19 wnj 3 2
c listing
e
s 00002/00001/00063
d D 4.2 81/11/08 16:24:12 wnj 2 1
c first listing
e
s 00064/00000/00000
d D 4.1 81/11/07 20:20:24 wnj 1 0
c date and time created 81/11/07 20:20:24 by wnj
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
D 26
/*	%M%	%I%	%E%	*/
E 26
I 26
/*
D 33
 * Copyright (c) 1982 Regents of the University of California.
E 33
I 33
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 33
D 36
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 36
I 36
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 38
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 38
I 38
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
E 38
E 36
 *
 *	%W% (Berkeley) %G%
 */
E 26
E 13

/*
 * Constants and structures defined by the internet system,
 * Per RFC 790, September 1981.
 */

/*
 * Protocols
 */
I 28
#define	IPPROTO_IP		0		/* dummy for IP */
E 28
I 2
D 7
#define	IPPROTO_RAW		-1
E 7
E 2
#define	IPPROTO_ICMP		1		/* control message protocol */
D 9
#define	IPPROTO_GG		2		/* gateway^2 (deprecated) */
E 9
I 9
D 37
#define	IPPROTO_GGP		2		/* gateway^2 (deprecated) */
E 37
I 37
#define	IPPROTO_GGP		3		/* gateway^2 (deprecated) */
E 37
E 9
#define	IPPROTO_TCP		6		/* tcp */
I 24
#define	IPPROTO_EGP		8		/* exterior gateway protocol */
E 24
#define	IPPROTO_PUP		12		/* pup */
#define	IPPROTO_UDP		17		/* user datagram protocol */
I 28
#define	IPPROTO_IDP		22		/* xns idp */
I 39
#define	IPPROTO_GRE		47		/* generic routing encap */
E 39
E 28
I 21
D 25
#define	IPPROTO_ND		77		/* UNOFFICIAL net disk proto */
E 25
E 21

I 7
#define	IPPROTO_RAW		255		/* raw IP packet */
E 7
I 3
#define	IPPROTO_MAX		256

E 3
D 25
/*
 * Port/socket numbers: network standard functions
 */
#define	IPPORT_ECHO		7
#define	IPPORT_DISCARD		9
#define	IPPORT_SYSTAT		11
#define	IPPORT_DAYTIME		13
#define	IPPORT_NETSTAT		15
#define	IPPORT_FTP		21
#define	IPPORT_TELNET		23
#define	IPPORT_SMTP		25
#define	IPPORT_TIMESERVER	37
#define	IPPORT_NAMESERVER	42
#define	IPPORT_WHOIS		43
#define	IPPORT_MTP		57
E 25

/*
D 25
 * Port/socket numbers: host specific functions
 */
#define	IPPORT_TFTP		69
#define	IPPORT_RJE		77
#define	IPPORT_FINGER		79
#define	IPPORT_TTYLINK		87
#define	IPPORT_SUPDUP		95

I 11
/*
 * UNIX TCP sockets
 */
#define	IPPORT_EXECSERVER	512
#define	IPPORT_LOGINSERVER	513
#define	IPPORT_CMDSERVER	514
I 14
#define	IPPORT_EFSSERVER	520
E 14

/*
 * UNIX UDP sockets
 */
#define	IPPORT_BIFFUDP		512
#define	IPPORT_WHOSERVER	513
I 14
#define	IPPORT_ROUTESERVER	520	/* 520+1 also used */
E 14

/*
E 25
 * Ports < IPPORT_RESERVED are reserved for
 * privileged processes (e.g. root).
I 30
 * Ports > IPPORT_USERRESERVED are reserved
 * for servers, not necessarily privileged.
E 30
 */
E 11
I 9
#define	IPPORT_RESERVED		1024
I 30
#define	IPPORT_USERRESERVED	5000
E 30

E 9
/*
 * Link numbers
 */
#define	IMPLINK_IP		155
#define	IMPLINK_LOWEXPER	156
#define	IMPLINK_HIGHEXPER	158

/*
D 25
 * Internet address (old style... should be updated)
E 25
I 25
 * Internet address (a structure for historical reasons)
E 25
 */
D 2
struct socket {			/* should be called inet_addr */
E 2
I 2
D 4
struct ip_addr {
E 4
I 4
struct in_addr {
E 4
E 2
D 25
	union {
		struct { u_char s_b1,s_b2,s_b3,s_b4; } S_un_b;
		struct { u_short s_w1,s_w2; } S_un_w;
D 8
		u_long s_l;
E 8
I 8
		u_long S_addr;
E 8
	} S_un;
D 8
#define	s_addr	S_un.s_l	/* can be used for most tcp & ip code */
E 8
I 8
#define	s_addr	S_un.S_addr	/* can be used for most tcp & ip code */
D 19
#ifdef vax
E 19
E 8
#define	s_host	S_un.S_un_b.s_b2	/* host on imp */
#define	s_net	S_un.S_un_b.s_b1	/* network */
#define	s_imp	S_un.S_un_w.s_w2	/* imp */
I 10
#define	s_impno	S_un.S_un_b.s_b4	/* imp # */
#define	s_lh	S_un.S_un_b.s_b3	/* logical host */
E 25
I 25
	u_long s_addr;
E 25
E 10
D 8
#define	s_lhost	S_un.S_un_b.s_b1	/* net library format host on imp */
#define	s_lnet	S_un.S_un_b.s_b2	/* net library format network */
E 8
I 8
D 19
#endif
E 19
E 8
I 4
};
I 9

I 12
/*
D 15
 * Macros for dealing with Class A/B/C network
 * numbers.  High 3 bits of uppermost byte indicates
 * how to interpret the remainder of the 32-bit
D 13
 * Internet address.
E 13
I 13
 * Internet address.  The macros may be used in time
 * time critical sections of code, while subroutine
 * versions also exist use in other places.
E 15
I 15
 * Definitions of bits in internet address integers.
I 27
 * On subnets, the decomposition of addresses to host and net parts
 * is done according to subnet mask, not the masks here.
E 27
E 15
E 13
 */
D 13
#ifdef vax || pdp11
E 13
I 13
D 15
#if vax || pdp11
#define	IN_CLASSA	0x00000080
E 13
#define	IN_CLASSA_NET	0x000000ff	/* 8 bits of net # */
#define	IN_CLASSA_LNA	0xffffff00
D 13
#define	IN_CLASSB	0x00000008
E 13
I 13
#define	IN_CLASSB	0x00000040
E 13
#define	IN_CLASSB_NET	0x0000ffff	/* 16 bits of net # */
#define	IN_CLASSB_LNA	0xffff0000
D 13
#define	IN_CLASSC	0x0000000c
E 13
#define	IN_CLASSC_NET	0x00ffffff	/* 24 bits of net # */
#define	IN_CLASSC_LNA	0xff000000
#endif
E 15
I 15
D 16
#define	IN_CLASSA(i)		(((i)&0x80000000)==0)
E 16
I 16
D 31
#define	IN_CLASSA(i)		((((long)(i))&0x80000000)==0)
E 31
I 31
#define	IN_CLASSA(i)		(((long)(i) & 0x80000000) == 0)
E 31
E 16
#define	IN_CLASSA_NET		0xff000000
#define	IN_CLASSA_NSHIFT	24
#define	IN_CLASSA_HOST		0x00ffffff
I 23
#define	IN_CLASSA_MAX		128
E 23
E 15

D 13
#define	inetpart(in) \
	((((in).s_addr&IN_CLASSC)==IN_CLASSC)?((in).s_addr&IN_CLASSC_NET):\
	 ((((in).s_addr&IN_CLASSB)==IN_CLASSB)?((in).s_addr&IN_CLASSB_NET):\
	  ((in).s_addr&IN_CLASSA_NET)))
#define	lnapart(in) \
	((((in).s_addr&IN_CLASSC)==IN_CLASSC)?((in).s_addr&IN_CLASSC_LNA) : \
	 ((((in).s_addr&IN_CLASSB)==IN_CLASSB)?((in).s_addr&IN_CLASSB_LNA) : \
	  ((in).s_addr&IN_CLASSA_LNA)))
E 13
I 13
D 15
#define	IN_NETOF(in) \
	(((in).s_addr&IN_CLASSA) == 0 ? (in).s_addr&IN_CLASSA_NET : \
		((in).s_addr&IN_CLASSB) == 0 ? (in).s_addr&IN_CLASSB_NET : \
			(in).s_addr&IN_CLASSC_NET)
#define	IN_LNAOF(in) \
	(((in).s_addr&IN_CLASSA) == 0 ? (in).s_addr&IN_CLASSA_LNA : \
		((in).s_addr&IN_CLASSB) == 0 ? (in).s_addr&IN_CLASSB_LNA : \
			(in).s_addr&IN_CLASSC_LNA)
E 15
I 15
D 16
#define	IN_CLASSB(i)		(((i)&0xc0000000)==0x80000000)
E 16
I 16
D 31
#define	IN_CLASSB(i)		((((long)(i))&0xc0000000)==0x80000000)
E 31
I 31
#define	IN_CLASSB(i)		(((long)(i) & 0xc0000000) == 0x80000000)
E 31
E 16
#define	IN_CLASSB_NET		0xffff0000
#define	IN_CLASSB_NSHIFT	16
#define	IN_CLASSB_HOST		0x0000ffff
I 23
#define	IN_CLASSB_MAX		65536
E 23

D 16
#define	IN_CLASSC(i)		(((i)&0xc0000000)==0xc0000000)
E 16
I 16
D 31
#define	IN_CLASSC(i)		((((long)(i))&0xc0000000)==0xc0000000)
E 31
I 31
D 35
#define	IN_CLASSC(i)		(((long)(i) & 0xc0000000) == 0xc0000000)
E 35
I 35
#define	IN_CLASSC(i)		(((long)(i) & 0xe0000000) == 0xc0000000)
E 35
E 31
E 16
#define	IN_CLASSC_NET		0xffffff00
#define	IN_CLASSC_NSHIFT	8
#define	IN_CLASSC_HOST		0x000000ff
D 16
#endif
E 16
E 15
E 13

I 35
#define	IN_CLASSD(i)		(((long)(i) & 0xf0000000) == 0xe0000000)
#define	IN_MULTICAST(i)		IN_CLASSD(i)

#define	IN_EXPERIMENTAL(i)	(((long)(i) & 0xe0000000) == 0xe0000000)
#define	IN_BADCLASS(i)		(((long)(i) & 0xf0000000) == 0xf0000000)

E 35
E 12
D 25
#define	INADDR_ANY	0x00000000
E 25
I 25
D 31
#define	INADDR_ANY		0x00000000
D 27
#define	INADDR_BROADCAST	0xffffffff
E 25
I 23

/*
 * Macros for subnetworks.  A subnet is distinguished by
 * 	(1) the network number is a `local' network number, and
 *	(2) the most significant bit of the host part is set.
 * Such addresses include one additional byte in the network number,
 * and use one less byte in the host part (i.e., a subnet of a Class A
 * network uses the rules for Class B net/host number extraction,
 * a Class B subnet is dealt with as if it were a Class C net).
 * Subnets of Class C nets are not supported.
 */
#define	SUBNETSHIFT		8  /* used to get main net number from subnet */

#define	IN_SUBNETA(i)		((((long)(i))&0x80800000)==0x00800000)
#define	IN_CLASSA_SUBNET	0xffff0000
#define	IN_CLASSA_SUBNSHIFT	(IN_CLASSA_NSHIFT - SUBNETSHIFT)
#define	IN_CLASSA_SUBHOST	0x0000ffff

#define	IN_SUBNETB(i)		((((long)(i))&0xc0008000)==0x80008000)
#define	IN_CLASSB_SUBNET	0xffffff00
#define	IN_CLASSB_SUBNSHIFT	(IN_CLASSB_NSHIFT - SUBNETSHIFT)
#define	IN_CLASSA_SUBHOST	0x0000ffff
#define	IN_CLASSB_SUBHOST	0x000000ff
E 27
I 27
#define	INADDR_BROADCAST	0xffffffff		/* must be masked */
E 31
I 31
#define	INADDR_ANY		(u_long)0x00000000
#define	INADDR_BROADCAST	(u_long)0xffffffff	/* must be masked */
I 34
#ifndef KERNEL
#define	INADDR_NONE		0xffffffff		/* -1 return */
#endif
I 35

#define	IN_LOOPBACKNET		127			/* official! */
E 35
E 34
E 31
E 27
E 23
E 9

/*
 * Socket address, internet style.
 */
struct sockaddr_in {
	short	sin_family;
	u_short	sin_port;
	struct	in_addr sin_addr;
	char	sin_zero[8];
E 4
};
I 28

/*
 * Options for use with [gs]etsockopt at the IP level.
 */
#define	IP_OPTIONS	1		/* set/get IP per-packet options */
E 28
I 17
D 34

D 31
#if !defined(vax)
E 31
I 31
D 32
#if !defined(vax) && !defined(ntohl)
E 32
I 32
#if !defined(vax) && !defined(ntohl) && !defined(lint)
E 32
E 31
/*
 * Macros for number representation conversion.
 */
#define	ntohl(x)	(x)
#define	ntohs(x)	(x)
#define	htonl(x)	(x)
#define	htons(x)	(x)
I 32
#endif

#if !defined(ntohl) && (defined(vax) || defined(lint))
u_short	ntohs(), htons();
u_long	ntohl(), htonl();
E 32
#endif
E 34
I 18

#ifdef KERNEL
extern	struct domain inetdomain;
extern	struct protosw inetsw[];
I 25
struct	in_addr in_makeaddr();
I 29
D 31
u_long	in_netof();
E 31
I 31
u_long	in_netof(), in_lnaof();
E 31
E 29
E 25
#endif
E 18
E 17
E 1
