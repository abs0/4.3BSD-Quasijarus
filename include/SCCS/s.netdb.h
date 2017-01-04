h22074
s 00011/00006/00063
d D 5.10 88/06/27 16:40:45 bostic 12 11
c install approved copyright notice
e
s 00013/00005/00056
d D 5.9 88/04/05 10:44:09 karels 11 10
c change NO_ADDRESS to NO_DATA
e
s 00001/00003/00060
d D 5.8 87/11/18 09:24:01 bostic 10 9
c don't declare h_errno
e
s 00001/00001/00062
d D 5.7 86/05/12 11:38:44 kjd 9 8
c Fix comment for NO_ADDRESS
e
s 00004/00004/00059
d D 5.6 86/05/09 22:04:06 lepreau 8 7
c n_net is unsigned long, not int.
e
s 00001/00000/00062
d D 5.5 85/11/11 11:41:19 kjd 7 6
c Add fourth error return NO_ADDRESS
e
s 00010/00000/00052
d D 5.4 85/11/04 18:49:18 kjd 6 4
c Add error return codes for gethostby*() routines
e
s 00001/00002/00050
d R 5.4 85/08/26 21:12:10 mckusick 5 4
c back out -r5.2 since the code DOES NOT WORK with this change!
c Kevin what are your doing!?!?!
e
s 00001/00001/00051
d D 5.3 85/08/25 13:37:05 mckusick 4 3
c kdj, you really ought to make sure that your backwards compatibility
c is syntactically correct.
e
s 00002/00001/00050
d D 5.2 85/08/07 18:41:51 kjd 3 2
c Add h_addr_list to hostent
e
s 00008/00001/00043
d D 5.1 85/06/18 18:36:50 mckusick 2 1
c Add copyright
e
s 00044/00000/00000
d D 4.1 82/10/05 16:46:51 sam 1 0
c date and time created 82/10/05 16:46:51 by sam
e
u
U
f b 
t
T
I 1
D 2
/*	%M%	%I%	%E%	*/
E 2
I 2
/*
D 11
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 11
I 11
D 12
 * Copyright (c) 1980,1983,1988 Regents of the University of California.
E 12
I 12
 * Copyright (c) 1980, 1983, 1988 Regents of the University of California.
E 12
 * All rights reserved.
E 11
 *
I 11
 * Redistribution and use in source and binary forms are permitted
D 12
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 12
I 12
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
E 12
 *
E 11
 *	%W% (Berkeley) %G%
 */

E 2
/*
 * Structures returned by network
 * data base library.  All addresses
 * are supplied in host order, and
 * returned in network order (suitable
 * for use in system calls).
 */
struct	hostent {
	char	*h_name;	/* official name of host */
	char	**h_aliases;	/* alias list */
	int	h_addrtype;	/* host address type */
	int	h_length;	/* length of address */
D 3
	char	*h_addr;	/* address */
E 3
I 3
	char	**h_addr_list;	/* list of addresses from name server */
D 4
#define	h_addr	h_addr_list[0]; /* address, for backward compatiblity */
E 4
I 4
#define	h_addr	h_addr_list[0]	/* address, for backward compatiblity */
E 4
E 3
};

/*
 * Assumption here is that a network number
 * fits in 32 bits -- probably a poor one.
 */
struct	netent {
D 8
	char	*n_name;	/* official name of net */
	char	**n_aliases;	/* alias list */
	int	n_addrtype;	/* net address type */
	int	n_net;		/* network # */
E 8
I 8
	char		*n_name;	/* official name of net */
	char		**n_aliases;	/* alias list */
	int		n_addrtype;	/* net address type */
	unsigned long	n_net;		/* network # */
E 8
};

struct	servent {
	char	*s_name;	/* official service name */
	char	**s_aliases;	/* alias list */
	int	s_port;		/* port # */
	char	*s_proto;	/* protocol to use */
};

struct	protoent {
	char	*p_name;	/* official protocol name */
	char	**p_aliases;	/* alias list */
	int	p_proto;	/* protocol # */
};

struct hostent	*gethostbyname(), *gethostbyaddr(), *gethostent();
struct netent	*getnetbyname(), *getnetbyaddr(), *getnetent();
struct servent	*getservbyname(), *getservbyport(), *getservent();
struct protoent	*getprotobyname(), *getprotobynumber(), *getprotoent();
I 6

/*
 * Error return codes from gethostbyname() and gethostbyaddr()
I 11
 * (left in extern int h_errno).
E 11
 */

D 10
extern  int h_errno;	

E 10
D 11
#define	HOST_NOT_FOUND	1 /* Authoritive Answer Host not found */
E 11
I 11
#define	HOST_NOT_FOUND	1 /* Authoritative Answer Host not found */
E 11
#define	TRY_AGAIN	2 /* Non-Authoritive Host not found, or SERVERFAIL */
#define	NO_RECOVERY	3 /* Non recoverable errors, FORMERR, REFUSED, NOTIMP */
I 7
D 9
#define NO_ADDRESS	4 /* Valid host name, no address, look for MF record */
E 9
I 9
D 10
#define NO_ADDRESS	4 /* Valid host name, no address, look for MX record */
E 10
I 10
D 11
#define	NO_ADDRESS	4 /* Valid host name, no address, look for MX record */
E 11
I 11
#define	NO_DATA		4 /* Valid name, no data record of requested type */
#define	NO_ADDRESS	NO_DATA		/* no address, look for MX record */
E 11
E 10
E 9
E 7
E 6
E 1
