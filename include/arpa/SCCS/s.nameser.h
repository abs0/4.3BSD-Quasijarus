h26050
s 00004/00002/00249
d D 5.23 2011/12/23 06:41:08 msokolov 28 27
c AD and CD header bits
e
s 00019/00001/00232
d D 5.22 2011/12/23 06:32:00 msokolov 27 26
c added some post-RFC1035 RR types
e
s 00016/00001/00217
d D 5.21 2011/07/14 03:23:52 msokolov 26 25
c struct rrfixed added
e
s 00002/00000/00216
d D 5.20 04/01/25 17:30:39 msokolov 25 24
c bring back historical C_CS and add C_HS
e
s 00001/00000/00215
d D 5.19 04/01/25 00:13:30 msokolov 24 23
c add T_TXT from RFC 1035
e
s 00013/00002/00202
d D 5.18 88/06/27 16:37:43 bostic 23 22
c install approved copyright notice
e
s 00035/00000/00169
d D 5.17 87/11/17 10:05:17 karels 22 21
c add macros get get/put short/long.
e
s 00002/00002/00167
d D 5.16 87/07/15 18:19:05 dpk 21 20
c deleted CQUERY's, added STATUS Query. (dpk&pvm)
e
s 00002/00002/00167
d D 5.15 87/02/12 18:03:33 kjd 20 19
c fix getshort and getlong
e
s 00001/00001/00168
d D 5.14 87/02/11 13:51:02 kjd 19 18
c add support for encore
e
s 00016/00003/00153
d D 5.13 86/11/05 10:34:40 kjd 18 17
c add needed defines for dynamic updateing from Mike schwartz@wally.cs.washington.edu
e
s 00010/00010/00146
d D 5.12 86/07/07 11:01:33 kjd 17 16
c fix opcodes, 100 decimal doesn't fit into 4 bits very well
e
s 00001/00001/00155
d D 5.11 86/02/14 18:16:36 kjd 16 15
c Add define for CCI Power 32 - defined (tahoe)
e
s 00001/00000/00155
d D 5.10 86/02/03 23:09:27 kjd 15 14
c Add class field c_chaos
e
s 00001/00000/00154
d D 5.9 86/01/08 11:28:16 kjd 14 13
c Add MX record
e
s 00009/00009/00145
d D 5.8 86/01/07 13:53:42 kjd 13 12
c make non standard numbers in a range to give standard numbers room to grow
e
s 00001/00001/00153
d D 5.7 85/11/01 11:35:05 kjd 12 11
c change define to defined
e
s 00002/00001/00152
d D 5.6 85/10/31 19:43:44 kjd 11 10
c Add a few more cpu's to define
e
s 00000/00001/00153
d D 5.5 85/10/30 17:27:07 kjd 10 9
c Remove C_CS network class,  NIC said it goes bye bye
e
s 00009/00004/00145
d D 5.4 85/10/29 19:36:49 mckusick 9 8
c force people doing ports to define their machine's bit order
e
s 00016/00000/00133
d D 5.3 85/10/07 20:42:59 kjd 8 5
c add #ifdef BIT_ZERO_ON_LEFT for Gould and other nuxi machines, Thanks to mike@brl
e
s 00002/00002/00131
d R 5.3 85/09/13 18:09:18 bloom 7 5
c use getservbyname instead of compiling in port number
e
s 00002/00002/00131
d R 5.3 85/09/13 17:11:43 bloom 6 5
c don't compile in port numbers
e
s 00000/00006/00133
d D 5.2 85/07/29 17:50:56 kjd 5 4
c Remove HTONS definition, should use system htons()
e
s 00008/00001/00131
d D 5.1 85/05/30 09:37:30 dist 4 3
c Add copyright
e
s 00003/00000/00129
d D 4.3 85/03/27 14:34:40 ralph 3 2
c added getshort() and getlong() for machine independence.
e
s 00005/00000/00124
d D 4.2 85/03/18 14:01:51 ralph 2 1
c define NAMESERVER_PORT for connections
e
s 00124/00000/00000
d D 4.1 85/03/01 10:19:37 ralph 1 0
c date and time created 85/03/01 10:19:37 by ralph
e
u
U
t
T
I 1
D 4
/*	%M%	%I%	%E%	*/
E 4
I 4
/*
 * Copyright (c) 1983 Regents of the University of California.
D 23
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 23
I 23
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
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
E 23
 *
 *	%W% (Berkeley) %G%
 */

E 4
/*
 * Define constants based on rfc883
 */
#define PACKETSZ	512		/* maximum packet size */
#define MAXDNAME	256		/* maximum domain name */
#define MAXCDNAME	255		/* maximum compressed domain name */
#define MAXLABEL	63		/* maximum length of domain label */
	/* Number of bytes of fixed size data in query structure */
#define QFIXEDSZ	4
	/* number of bytes of fixed size data in resource record */
#define RRFIXEDSZ	10

D 5
#ifdef vax
#define HTONS(s)	(((s >> 8) & 0xff) | ((s & 0xff) << 8))
#else
#define HTONS(s)
#endif

E 5
/*
I 2
 * Internet nameserver port number
 */
#define NAMESERVER_PORT	53

/*
E 2
 * Currently defined opcodes
 */
D 17
#define QUERY		0		/* standard query */
#define IQUERY		1		/* inverse query */
#define CQUERYM		2		/* completion query (multiple) */
#define CQUERYU		3		/* completion query (unique) */
E 17
I 17
#define QUERY		0x0		/* standard query */
#define IQUERY		0x1		/* inverse query */
D 21
#define CQUERYM		0x2		/* completion query (multiple) */
#define CQUERYU		0x3		/* completion query (unique) */
E 21
I 21
#define STATUS		0x2		/* nameserver status query */
/*#define xxx		0x3		/* 0x3 reserved */
E 21
E 17
	/* non standard */
D 13
#define UPDATEA		11		/* add resource record */
#define UPDATED		12		/* delete resource record */
#define UPDATEM		13		/* modify resource record */
#define ZONEINIT	14		/* initial zone transfer */
#define ZONEREF		15		/* incremental zone referesh */
E 13
I 13
D 17
#define UPDATEA		100		/* add resource record */
#define UPDATED		101		/* delete resource record */
#define UPDATEM		102		/* modify resource record */
#define ZONEINIT	103		/* initial zone transfer */
#define ZONEREF		104		/* incremental zone referesh */
E 17
I 17
D 18
#define UPDATEA		0xb		/* add resource record */
#define UPDATED		0xc		/* delete resource record */
#define UPDATEM		0xd		/* modify resource record */
E 18
I 18
#define UPDATEA		0x9		/* add resource record */
#define UPDATED		0xa		/* delete a specific resource record */
#define UPDATEDA	0xb		/* delete all nemed resource record */
#define UPDATEM		0xc		/* modify a specific resource record */
#define UPDATEMA	0xd		/* modify all named resource record */

E 18
#define ZONEINIT	0xe		/* initial zone transfer */
#define ZONEREF		0xf		/* incremental zone referesh */
E 17
E 13

/*
 * Currently defined response codes
 */
#define NOERROR		0		/* no error */
#define FORMERR		1		/* format error */
#define SERVFAIL	2		/* server failure */
#define NXDOMAIN	3		/* non existent domain */
#define NOTIMP		4		/* not implemented */
#define REFUSED		5		/* query refused */
	/* non standard */
D 13
#define NOCHANGE	15		/* update failed to change db */
E 13
I 13
D 17
#define NOCHANGE	100		/* update failed to change db */
E 17
I 17
#define NOCHANGE	0xf		/* update failed to change db */
E 17
E 13

/*
 * Type values for resources and queries
 */
#define T_A		1		/* host address */
#define T_NS		2		/* authoritative server */
#define T_MD		3		/* mail destination */
#define T_MF		4		/* mail forwarder */
D 27
#define T_CNAME		5		/* connonical name */
E 27
I 27
#define T_CNAME		5		/* canonical name */
E 27
#define T_SOA		6		/* start of authority zone */
#define T_MB		7		/* mailbox domain name */
#define T_MG		8		/* mail group member */
#define T_MR		9		/* mail rename name */
#define T_NULL		10		/* null resource record */
#define T_WKS		11		/* well known service */
#define T_PTR		12		/* domain name pointer */
#define T_HINFO		13		/* host information */
#define T_MINFO		14		/* mailbox information */
I 14
#define T_MX		15		/* mail routing information */
I 24
#define	T_TXT		16		/* general purpose RR */
I 27
	/* some post-RFC1035 additions */
#define	T_RP		17		/* RFC 1183 */
#define	T_AFSDB		18		/* RFC 1183 */
#define	T_X25		19		/* RFC 1183 */
#define	T_ISDN		20		/* RFC 1183 */
#define	T_RT		21		/* RFC 1183 */
#define	T_SIG		24		/* I don't really understand DNSSEC */
#define	T_KEY		25		/* ditto */
#define	T_PX		26		/* X.400 stuff */
#define	T_AAAA		28		/* IPv6 */
#define	T_LOC		29		/* RFC 1876 */
#define	T_NXT		30		/* obsolete??? */
#define	T_SRV		33		/* RFC 2052, 2782 */
#define	T_NAPTR		35		/* ??? */
#define	T_KX		36		/* ??? */
#define	T_A6		38		/* does anyone use it? */
#define	T_DNAME		39		/* ditto */
#define	T_OPT		41		/* EDNS fake RR */
E 27
E 24
E 14
	/* non standard */
D 13
#define T_UINFO		15		/* user (finger) information */
#define T_UID		16		/* user ID */
#define T_GID		17		/* group ID */
E 13
I 13
#define T_UINFO		100		/* user (finger) information */
#define T_UID		101		/* user ID */
#define T_GID		102		/* group ID */
I 18
#define T_UNSPEC	103		/* Unspecified format (binary data) */
E 18
E 13
	/* Query type values which do not appear in resource records */
#define T_AXFR		252		/* transfer zone of authority */
#define T_MAILB		253		/* transfer mailbox records */
#define T_MAILA		254		/* transfer mail agent records */
#define T_ANY		255		/* wildcard match */

/*
 * Values for class field
 */

#define C_IN		1		/* the arpa internet */
I 25
#define	C_CS		2		/* historical CSNET */
E 25
I 15
#define C_CHAOS		3		/* for chaos net at MIT */
I 25
#define	C_HS		4		/* Hesiod */
E 25
E 15
D 10
#define C_CS		2		/* the computer science network */
E 10
	/* Query class values which do not appear in resource records */
#define C_ANY		255		/* wildcard match */
I 18

/*
 * Status return codes for T_UNSPEC conversion routines
 */
#define CONV_SUCCESS 0
#define CONV_OVERFLOW -1
#define CONV_BADFMT -2
#define CONV_BADCKSUM -3
#define CONV_BADBUFLEN -4
E 18

/*
 * Structure for query header, the order of the fields is machine and
 * compiler dependent, in our case, the bits within a byte are assignd 
 * least significant first, while the order of transmition is most 
 * significant first.  This requires a somewhat confusing rearrangement.
 */

typedef struct {
	u_short	id;		/* query identification number */
I 8
D 9
#ifdef BIT_ZERO_ON_LEFT
E 9
I 9
D 11
#if defined (sun) || defined (gould) || defined (BIT_ZERO_ON_LEFT)
E 11
I 11
D 12
#if defined (sun) || defined (sel) || defined (pyr) || define (is68k) \
E 12
I 12
#if defined (sun) || defined (sel) || defined (pyr) || defined (is68k) \
E 12
D 16
|| defined (BIT_ZERO_ON_LEFT)
E 16
I 16
|| defined (tahoe) || defined (BIT_ZERO_ON_LEFT)
E 16
E 11
E 9
	/* Bit zero on left:  Gould and similar architectures */
E 8
			/* fields in third byte */
I 8
	u_char	qr:1;		/* response flag */
	u_char	opcode:4;	/* purpose of message */
	u_char	aa:1;		/* authoritive answer */
	u_char	tc:1;		/* truncated message */
E 8
	u_char	rd:1;		/* recursion desired */
I 8
D 9
			/* fields in forth byte */
E 9
I 9
			/* fields in fourth byte */
E 9
	u_char	ra:1;		/* recursion available */
	u_char	pr:1;		/* primary server required (non standard) */
D 28
	u_char	unused:2;	/* unused bits */
E 28
I 28
	u_char	ad:1;		/* authentic data (DNSSEC) */
	u_char	cd:1;		/* checking disabled (DNSSEC) */
E 28
	u_char	rcode:4;	/* response code */
#else
D 9
	/* Bit zero on right:  VAX, PDP-11, etc */
E 9
I 9
D 19
#if defined (vax) || defined (BIT_ZERO_ON_RIGHT)
E 19
I 19
#if defined (vax) || defined(ns32000) || defined (BIT_ZERO_ON_RIGHT)
E 19
	/* Bit zero on right:  VAX */
E 9
			/* fields in third byte */
	u_char	rd:1;		/* recursion desired */
E 8
	u_char	tc:1;		/* truncated message */
	u_char	aa:1;		/* authoritive answer */
	u_char	opcode:4;	/* purpose of message */
	u_char	qr:1;		/* response flag */
D 9
			/* fields in forth byte */
E 9
I 9
			/* fields in fourth byte */
E 9
	u_char	rcode:4;	/* response code */
D 28
	u_char	unused:2;	/* unused bits */
E 28
I 28
	u_char	cd:1;		/* checking disabled (DNSSEC) */
	u_char	ad:1;		/* authentic data (DNSSEC) */
E 28
	u_char	pr:1;		/* primary server required (non standard) */
	u_char	ra:1;		/* recursion available */
I 9
#else
	/* you must determine what the correct bit order is for your compiler */
	UNDEFINED_BIT_ORDER;
#endif
E 9
I 8
#endif
E 8
			/* remaining bytes */
	u_short	qdcount;	/* number of question entries */
	u_short	ancount;	/* number of answer entries */
	u_short	nscount;	/* number of authority entries */
	u_short	arcount;	/* number of resource entries */
} HEADER;

/*
 * Defines for handling compressed domain names
 */
#define INDIR_MASK	0xc0

/*
D 26
 * Structure for passing resource records around.
E 26
I 26
 * Be very careful with the following structure: the compiler
 * will usually pad it to 12 bytes instead of 10!
 * However, the padding is at the end, so as long as you don't
 * use sizeof, you'll be OK.
 */
struct rrfixed {
	u_short	type;
	u_short	class;
	u_long	ttl;
	u_short	rdlength;
};

/*
 * This struct doesn't belong in a wire protocol definition
 * header, but apparently some bogus Berkeley code still uses it
 * and expects it to be in this header. :-(
E 26
 */
struct rrec {
	short	r_zone;			/* zone number */
	short	r_class;		/* class number */
	short	r_type;			/* type number */
	u_long	r_ttl;			/* time to live */
	int	r_size;			/* size of data area */
	char	*r_data;		/* pointer to data */
};
I 3

D 20
extern	u_short	getshort();
extern	u_long	getlong();
E 20
I 20
extern	u_short	_getshort();
extern	u_long	_getlong();
I 22

/*
 * Inline versions of get/put short/long.
 * Pointer is advanced; we assume that both arguments
 * are lvalues and will already be in registers.
 * cp MUST be u_char *.
 */
#define GETSHORT(s, cp) { \
	(s) = *(cp)++ << 8; \
	(s) |= *(cp)++; \
}

#define GETLONG(l, cp) { \
	(l) = *(cp)++ << 8; \
	(l) |= *(cp)++; (l) <<= 8; \
	(l) |= *(cp)++; (l) <<= 8; \
	(l) |= *(cp)++; \
}


#define PUTSHORT(s, cp) { \
	*(cp)++ = (s) >> 8; \
	*(cp)++ = (s); \
}

/*
 * Warning: PUTLONG destroys its first argument.
 */
#define PUTLONG(l, cp) { \
	(cp)[3] = l; \
	(cp)[2] = (l >>= 8); \
	(cp)[1] = (l >>= 8); \
	(cp)[0] = l >> 8; \
	(cp) += sizeof(u_long); \
}
E 22
E 20
E 3
E 1
