h28210
s 00008/00002/00105
d D 5.2 88/02/18 17:03:44 bostic 6 5
c written by Kurt Shoens; added Berkeley specific header
e
s 00007/00001/00100
d D 5.1 85/06/06 10:46:53 dist 5 4
c Add copyright
e
s 00001/00005/00100
d D 1.4 83/08/11 22:14:39 sam 4 3
c standardize sccs keyword lines
e
s 00014/00002/00091
d D 1.3 82/09/02 12:37:31 mckusick 3 2
c added #define constants for EMPTY (a dummy machine name)
c and EMPTYID (machine id used by hosts that have gethostname())
e
s 00005/00005/00088
d D 1.2 82/07/28 15:35:23 kurt 2 1
c changed names of nettypetab and netkindtab to 
c ntypetab and nkindtab to satisfy pdp-11 name length restrictions 
c 
e
s 00093/00000/00000
d D 1.1 81/09/09 09:19:07 kurt 1 0
c date and time created 81/09/09 09:19:07 by kurt
e
u
U
f b 
f i 
t
T
I 1
D 4
#
E 4
I 4
D 5
/*	%M%	%I%	%E%	*/
E 5
I 5
/*
 * Copyright (c) 1980 Regents of the University of California.
D 6
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 6
I 6
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 6
 *
 *	%W% (Berkeley) %G%
 */
E 5
E 4

/*
 * This file contains the definitions of data structures used in
 * configuring the network behavior of Mail when replying.
D 4
 */

/*
 * Sccs ID %W% %G%
E 4
 */

/*
I 3
 * The following constants are used when you are running 4.1a bsd or
 * later on a local network.  Under control of the #define flag
 * GETHOST, the host name is determined dynamically using the
 * gethostname() system call.  The name thus found is inserted
 * into the host table slot whose name was originally EMPTY.
 */
#define	EMPTY		"** empty **"
#define	EMPTYID		'E'

/*
E 3
 * The following data structure is the host table.  You must have
 * an entry here for your own machine, plus any special stuff you
D 3
 * expect the mailer to know about.  Not all hosts need be here,
 * however:  Mail can dope out stuff about hosts on the fly by looking
E 3
I 3
 * expect the mailer to know about.  If you have #define'd GETHOST
 * in v7.local.h, you needn't add your machine to the host table.
 * Not all hosts need be here, however:
 * Mail can dope out stuff about hosts on the fly by looking
E 3
 * at addresses.  The machines needed here are:
 *	1) The local machine
 *	2) Any machines on the path to a network gateway
 *	3) Any machines with nicknames that you want to have considered
 *	   the same.
 * The machine id letters can be anything you like and are not seen
 * externally.  Be sure not to use characters with the 0200 bit set --
 * these have special meanings.
 */
struct netmach {
	char	*nt_machine;
	char	nt_mid;
	short	nt_type;
};

/*
 * Network type codes.  Basically, there is one for each different
 * network, if the network can be discerned by the separator character,
 * such as @ for the arpa net.  The purpose of these codes is to
 * coalesce cases where more than one character means the same thing,
 * such as % and @ for the arpanet.  Also, the host table uses a
 * bit map of these codes to show what it is connected to.
 * BN -- connected to Bell Net.
 * AN -- connected to ARPA net, SN -- connected to Schmidt net.
 */
#define	AN	1			/* Connected to ARPA net */
#define	BN	2			/* Connected to BTL net */
#define	SN	4			/* Connected to Schmidt net */

/*
 * Data structure for table mapping network characters to network types.
 */
D 2
struct nettypetab {
E 2
I 2
struct ntypetab {
E 2
	char	nt_char;		/* Actual character separator */
D 2
	int	nt_type;		/* Type bit code */
E 2
I 2
	int	nt_bcode;		/* Type bit code */
E 2
};

/*
 * Codes for the "kind" of a network.  IMPLICIT means that if there are
 * physically several machines on the path, one does not list them in the
 * address.  The arpa net is like this.  EXPLICIT means you list them,
 * as in UUCP.
 * By the way, this distinction means we lose if anyone actually uses the
 * arpa net subhost convention: name@subhost@arpahost
 */
#define	IMPLICIT	1
#define	EXPLICIT	2

/*
 * Table for mapping a network code to its type -- IMPLICIT routing or
 * IMPLICIT routing.
 */
D 2
struct netkindtab {
E 2
I 2
struct nkindtab {
E 2
	int	nk_type;		/* Its bit code */
	int	nk_kind;		/* Whether explicit or implicit */
};

/*
 * The following table gives the order of preference of the various
 * networks.  Thus, if we have a choice of how to get somewhere, we
 * take the preferred route.
 */
struct netorder {
	short	no_stat;
	char	no_char;
};

/*
 * External declarations for above defined tables.
 */
#ifndef CONFIGFILE
extern struct netmach netmach[1];
D 2
extern struct nettypetab nettypetab[1];
extern struct netkindtab netkindtab[1];
E 2
I 2
extern struct ntypetab ntypetab[1];
extern struct nkindtab nkindtab[1];
E 2
extern struct netorder netorder[1];
extern char *metanet;
#endif
E 1
