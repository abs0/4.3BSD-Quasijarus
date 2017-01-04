h02273
s 00008/00001/00042
d D 5.5 87/05/12 22:13:25 karels 7 6
c add list of local domains
e
s 00010/00009/00033
d D 5.4 86/02/22 09:09:06 bloom 6 5
c add stayopen flag to options
e
s 00008/00002/00034
d D 5.3 85/10/09 19:46:45 kjd 5 3
c Add support for resolver to query multiple name servers
e
s 00007/00002/00034
d R 5.3 85/10/09 19:31:33 kjd 4 3
c Add support for resolver to query multiple name servers
e
s 00000/00006/00036
d D 5.2 85/07/31 14:22:24 kjd 3 2
c Move definition of CONFFILE to res_init.c
e
s 00008/00001/00034
d D 5.1 85/05/30 09:39:54 dist 2 1
c Add copyright
e
s 00034/00000/00000
d D 4.1 85/03/01 10:19:53 ralph 1 0
c date and time created 85/03/01 10:19:53 by ralph
e
u
U
t
T
I 5

E 5
I 1
D 2
/*	%M%	%I%	%E%	*/
E 2
I 2
/*
D 7
 * Copyright (c) 1983 Regents of the University of California.
E 7
I 7
 * Copyright (c) 1983, 1987 Regents of the University of California.
E 7
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */

E 2
/*
 * Global defines and variables for resolver stub.
 */

D 3
/*
 * Resolver configuration file. Contains the address of the
 * inital name server to query and the default domain for
 * non fully qualified domain names.
 */
#define CONFFILE "/usr/local/lib/resolv.conf"
E 3

I 5
#define	MAXNS		3		/* max # name servers we'll track */
I 7
#define	MAXDNSRCH	3		/* max # default domain levels to try */
#define	LOCALDOMAINPARTS 2		/* min levels in name that is "local" */
E 7

I 7
#define	RES_TIMEOUT	4		/* seconds between retries */
E 7

E 5
struct state {
D 5
	int	retrans;		/* retransmition time interval */
E 5
I 5
	int	retrans;	 	/* retransmition time interval */
E 5
	int	retry;			/* number of times to retransmit */
D 6
	int	options;		/* option flags - see below. */
E 6
I 6
	long	options;		/* option flags - see below. */
E 6
D 5
	struct	sockaddr_in nsaddr;	/* address of name server */
E 5
I 5
	int	nscount;		/* number of name servers */
	struct	sockaddr_in nsaddr_list[MAXNS];	/* address of name server */
#define	nsaddr	nsaddr_list[0]		/* for backward compatibility */
E 5
	u_short	id;			/* current packet id */
	char	defdname[MAXDNAME];	/* default domain */
I 7
	char	*dnsrch[MAXDNSRCH+1];	/* components of domain to search */
E 7
};

/*
 * Resolver options
 */
D 6
#define RES_INIT	0x001		/* address initialized */
#define RES_DEBUG	0x002		/* print debug messages */
#define RES_AAONLY	0x004		/* authoritative answers only */
#define RES_USEVC	0x008		/* use virtual circuit */
#define RES_PRIMARY	0x010		/* query primary server only */
#define RES_IGNTC	0x020		/* ignore trucation errors */
#define RES_RECURSE	0x040		/* recursion desired */
#define RES_DEFNAMES	0x080		/* use default domain name */
E 6
I 6
#define RES_INIT	0x0001		/* address initialized */
#define RES_DEBUG	0x0002		/* print debug messages */
#define RES_AAONLY	0x0004		/* authoritative answers only */
#define RES_USEVC	0x0008		/* use virtual circuit */
#define RES_PRIMARY	0x0010		/* query primary server only */
#define RES_IGNTC	0x0020		/* ignore trucation errors */
#define RES_RECURSE	0x0040		/* recursion desired */
#define RES_DEFNAMES	0x0080		/* use default domain name */
#define RES_STAYOPEN	0x0100		/* Keep TCP socket open */
I 7
#define RES_DNSRCH	0x0200		/* search up local domain tree */

#define RES_DEFAULT	(RES_RECURSE | RES_DEFNAMES | RES_DNSRCH)
E 7
E 6

extern struct state _res;
extern char *p_cdname(), *p_rr(), *p_type(), *p_class();
E 1
