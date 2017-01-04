/*
 * Copyright (c) 1983 Regents of the University of California.
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
 *
 *	@(#)nameser.h	5.23 (Berkeley) 12/23/2011
 */

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

/*
 * Internet nameserver port number
 */
#define NAMESERVER_PORT	53

/*
 * Currently defined opcodes
 */
#define QUERY		0x0		/* standard query */
#define IQUERY		0x1		/* inverse query */
#define STATUS		0x2		/* nameserver status query */
/*#define xxx		0x3		/* 0x3 reserved */
	/* non standard */
#define UPDATEA		0x9		/* add resource record */
#define UPDATED		0xa		/* delete a specific resource record */
#define UPDATEDA	0xb		/* delete all nemed resource record */
#define UPDATEM		0xc		/* modify a specific resource record */
#define UPDATEMA	0xd		/* modify all named resource record */

#define ZONEINIT	0xe		/* initial zone transfer */
#define ZONEREF		0xf		/* incremental zone referesh */

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
#define NOCHANGE	0xf		/* update failed to change db */

/*
 * Type values for resources and queries
 */
#define T_A		1		/* host address */
#define T_NS		2		/* authoritative server */
#define T_MD		3		/* mail destination */
#define T_MF		4		/* mail forwarder */
#define T_CNAME		5		/* canonical name */
#define T_SOA		6		/* start of authority zone */
#define T_MB		7		/* mailbox domain name */
#define T_MG		8		/* mail group member */
#define T_MR		9		/* mail rename name */
#define T_NULL		10		/* null resource record */
#define T_WKS		11		/* well known service */
#define T_PTR		12		/* domain name pointer */
#define T_HINFO		13		/* host information */
#define T_MINFO		14		/* mailbox information */
#define T_MX		15		/* mail routing information */
#define	T_TXT		16		/* general purpose RR */
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
	/* non standard */
#define T_UINFO		100		/* user (finger) information */
#define T_UID		101		/* user ID */
#define T_GID		102		/* group ID */
#define T_UNSPEC	103		/* Unspecified format (binary data) */
	/* Query type values which do not appear in resource records */
#define T_AXFR		252		/* transfer zone of authority */
#define T_MAILB		253		/* transfer mailbox records */
#define T_MAILA		254		/* transfer mail agent records */
#define T_ANY		255		/* wildcard match */

/*
 * Values for class field
 */

#define C_IN		1		/* the arpa internet */
#define	C_CS		2		/* historical CSNET */
#define C_CHAOS		3		/* for chaos net at MIT */
#define	C_HS		4		/* Hesiod */
	/* Query class values which do not appear in resource records */
#define C_ANY		255		/* wildcard match */

/*
 * Status return codes for T_UNSPEC conversion routines
 */
#define CONV_SUCCESS 0
#define CONV_OVERFLOW -1
#define CONV_BADFMT -2
#define CONV_BADCKSUM -3
#define CONV_BADBUFLEN -4

/*
 * Structure for query header, the order of the fields is machine and
 * compiler dependent, in our case, the bits within a byte are assignd 
 * least significant first, while the order of transmition is most 
 * significant first.  This requires a somewhat confusing rearrangement.
 */

typedef struct {
	u_short	id;		/* query identification number */
#if defined (sun) || defined (sel) || defined (pyr) || defined (is68k) \
|| defined (tahoe) || defined (BIT_ZERO_ON_LEFT)
	/* Bit zero on left:  Gould and similar architectures */
			/* fields in third byte */
	u_char	qr:1;		/* response flag */
	u_char	opcode:4;	/* purpose of message */
	u_char	aa:1;		/* authoritive answer */
	u_char	tc:1;		/* truncated message */
	u_char	rd:1;		/* recursion desired */
			/* fields in fourth byte */
	u_char	ra:1;		/* recursion available */
	u_char	pr:1;		/* primary server required (non standard) */
	u_char	ad:1;		/* authentic data (DNSSEC) */
	u_char	cd:1;		/* checking disabled (DNSSEC) */
	u_char	rcode:4;	/* response code */
#else
#if defined (vax) || defined(ns32000) || defined (BIT_ZERO_ON_RIGHT)
	/* Bit zero on right:  VAX */
			/* fields in third byte */
	u_char	rd:1;		/* recursion desired */
	u_char	tc:1;		/* truncated message */
	u_char	aa:1;		/* authoritive answer */
	u_char	opcode:4;	/* purpose of message */
	u_char	qr:1;		/* response flag */
			/* fields in fourth byte */
	u_char	rcode:4;	/* response code */
	u_char	cd:1;		/* checking disabled (DNSSEC) */
	u_char	ad:1;		/* authentic data (DNSSEC) */
	u_char	pr:1;		/* primary server required (non standard) */
	u_char	ra:1;		/* recursion available */
#else
	/* you must determine what the correct bit order is for your compiler */
	UNDEFINED_BIT_ORDER;
#endif
#endif
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
 */
struct rrec {
	short	r_zone;			/* zone number */
	short	r_class;		/* class number */
	short	r_type;			/* type number */
	u_long	r_ttl;			/* time to live */
	int	r_size;			/* size of data area */
	char	*r_data;		/* pointer to data */
};

extern	u_short	_getshort();
extern	u_long	_getlong();

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
