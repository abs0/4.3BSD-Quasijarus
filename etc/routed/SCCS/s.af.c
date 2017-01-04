h53334
s 00010/00005/00137
d D 5.8 88/06/18 13:56:22 bostic 26 25
c install approved copyright notice
e
s 00009/00003/00133
d D 5.7 88/02/16 18:50:41 bostic 25 24
c add Berkeley specific headers
e
s 00004/00002/00132
d D 5.6 87/06/15 20:46:29 karels 24 22
c IN_BADCLASS => IN_EXPERIMENTAL (from header)
e
s 00002/00000/00134
d R 5.6 87/06/15 15:34:17 karels 23 22
c IN_BADCLASS => IN_EXPERIMENTAL (from header)
e
s 00002/00002/00132
d D 5.5 87/05/28 11:26:02 karels 22 21
c rework interface metrics to invert perspective; other misc. fixes
e
s 00010/00015/00124
d D 5.4 86/04/20 23:33:40 karels 21 20
c changes to allow subnets to remain local, propogate net route
c where subnets don't go, and allow external routes from /etc/gateways
c to block routed from installing routes from elsewhere
e
s 00011/00072/00128
d D 5.3 86/02/23 19:33:46 karels 20 19
c don't rely on AF_MAX (comes from kernel include): check for nil explicitly,
c use our own idea of table size.  Use syslog to (optionally) log bad packets.
c Don't respond to routing inquiries from a router unless we are suppliers
c (really want to respondto everything but broadcasts, but haven't got
c the "to" address.)
e
s 00003/00000/00197
d D 5.2 85/10/31 11:57:00 karels 19 18
c argh, need to check zero fields or bcmp will fail (rtlookup != rtfind)
e
s 00007/00001/00190
d D 5.1 85/06/04 16:34:30 dist 18 17
c Add copyright
e
s 00007/00002/00184
d D 4.17 85/06/03 09:48:13 karels 17 16
c new subnets; make sure inet port # is 0, else we're confused
e
s 00000/00004/00186
d D 4.16 85/02/25 13:46:26 karels 16 15
c remove 4.1a compat
e
s 00001/00001/00189
d D 4.15 84/07/20 12:35:33 karels 15 14
c typo
e
s 00004/00002/00186
d D 4.14 84/05/03 13:45:56 karels 14 13
c optimizations: simplify inet_checkhost, use faster hashing,
c in-line expansions of ntohl et al.
e
s 00006/00002/00182
d D 4.13 84/04/10 21:39:57 karels 13 12
c subnet routing
e
s 00026/00004/00158
d D 4.12 84/03/07 21:56:16 karels 12 11
c more consistency checks; watch those unsigned moduli
e
s 00001/00001/00161
d D 4.11 83/05/25 17:50:35 sam 11 10
c protocol change; byte swap those fields which need it;  also add 
c a version stamp to allow future changes
e
s 00017/00020/00145
d D 4.10 83/01/11 14:37:45 sam 10 9
c 4.1c conversion contortions
e
s 00009/00023/00156
d D 4.9 82/11/02 22:29:54 sam 9 8
c major rewrite -- too much to describe here
e
s 00003/00003/00176
d D 4.8 82/10/07 18:10:53 sam 8 7
c use routines added to libc.a
e
s 00005/00009/00174
d D 4.7 82/08/19 14:08:59 sam 7 6
c class B & C net #'s weren't handled correctly
e
s 00003/00003/00180
d D 4.6 82/06/17 10:58:28 sam 6 5
c add class b & c net #'s
e
s 00005/00003/00178
d D 4.5 82/06/10 20:11:49 sam 5 4
c aid tracing on send errors
e
s 00001/00001/00180
d D 4.4 82/06/09 21:20:37 sam 4 3
c routed now uses 2 ports
e
s 00029/00009/00152
d D 4.3 82/06/09 00:44:58 wnj 3 2
c wnj changes
e
s 00026/00004/00135
d D 4.2 82/06/05 16:52:17 sam 2 1
c add port check stuff for trace packet verification
e
s 00139/00000/00000
d D 4.1 82/05/22 22:26:16 sam 1 0
c date and time created 82/05/22 22:26:16 by sam
e
u
U
t
T
I 18
/*
 * Copyright (c) 1983 Regents of the University of California.
D 25
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 25
I 25
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 26
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 26
I 26
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
E 26
E 25
 */

E 18
I 1
#ifndef lint
D 11
static char sccsid[] = "%W% %G%";
E 11
I 11
static char sccsid[] = "%W% (Berkeley) %G%";
E 11
D 18
#endif
E 18
I 18
D 25
#endif not lint
E 25
I 25
#endif /* not lint */
E 25
E 18

D 9
#include <sys/types.h>
#include <sys/socket.h>
#include <net/in.h>
E 9
D 5

E 5
D 10
#include "router.h"
E 10
I 10
#include "defs.h"
E 10
D 9
#include "rip.h"
E 9

I 5
D 9
extern char packet[MAXPACKETSIZE], *sys_errlist[];
extern int trace, errno;
#define	tprintf	if (trace) printf

E 9
E 5
/*
 * Address family support routines
 */
D 20
int	null_hash(), null_netmatch(), null_output(),
D 2
	null_portmatch(), null_checkhost(), null_canon();
E 2
I 2
	null_portmatch(), null_portcheck(),
D 12
	null_checkhost(), null_canon();
E 12
I 12
	null_checkhost(), null_ishost(), null_canon();
E 20
E 12
E 2
int	inet_hash(), inet_netmatch(), inet_output(),
D 2
	inet_portmatch(), inet_checkhost(), inet_canon();
E 2
I 2
	inet_portmatch(), inet_portcheck(),
D 12
	inet_checkhost(), inet_canon();
E 12
I 12
D 21
	inet_checkhost(), inet_ishost(), inet_canon();
E 21
I 21
D 22
	inet_checkhost(), inet_rtflags(), inet_sendsubnet(), inet_canon();
E 22
I 22
	inet_checkhost(), inet_rtflags(), inet_sendroute(), inet_canon();
E 22
E 21
E 12
E 2
D 20
#define NIL \
	{ null_hash,		null_netmatch,		null_output, \
D 2
	  null_portmatch,	null_checkhost,		null_canon }
E 2
I 2
	  null_portmatch,	null_portcheck,		null_checkhost, \
D 12
	  null_canon }
E 12
I 12
	  null_ishost,		null_canon }
E 20
I 20
char	*inet_format();
I 21

E 21
#define NIL	{ 0 }
E 20
E 12
E 2
#define	INET \
	{ inet_hash,		inet_netmatch,		inet_output, \
D 2
	  inet_portmatch,	inet_checkhost,		inet_canon }
E 2
I 2
	  inet_portmatch,	inet_portcheck,		inet_checkhost, \
D 12
	  inet_canon }
E 12
I 12
D 20
	  inet_ishost,		inet_canon }
E 20
I 20
D 21
	  inet_ishost,		inet_canon, 		inet_format }
E 21
I 21
D 22
	  inet_rtflags,		inet_sendsubnet,	inet_canon, \
E 22
I 22
	  inet_rtflags,		inet_sendroute,		inet_canon, \
E 22
	  inet_format \
	}
E 21
E 20
E 12
E 2

D 21
struct afswitch afswitch[AF_MAX] =
D 20
	{ NIL, NIL, INET, INET, NIL, NIL, NIL, NIL, NIL, NIL, NIL };
E 20
I 20
	{ NIL, NIL, INET, };
E 21
I 21
struct afswitch afswitch[AF_MAX] = {
	NIL,		/* 0- unused */
	NIL,		/* 1- Unix domain, unused */
	INET,		/* Internet */
};
E 21
E 20

I 20
int af_max = sizeof(afswitch) / sizeof(afswitch[0]);

E 20
I 13
struct sockaddr_in inet_default = { AF_INET, INADDR_ANY };

E 13
inet_hash(sin, hp)
	register struct sockaddr_in *sin;
	struct afhash *hp;
{
I 17
	register u_long n;
E 17

D 6
	hp->afh_nethash = sin->sin_addr.s_net;
E 6
I 6
D 7
	hp->afh_nethash = IN_NETOF(sin->sin_addr);
E 7
I 7
D 8
	hp->afh_nethash = in_netof(sin->sin_addr);
E 8
I 8
D 17
	hp->afh_nethash = inet_netof(sin->sin_addr);
E 17
I 17
	n = inet_netof(sin->sin_addr);
	if (n)
	    while ((n & 0xff) == 0)
		n >>= 8;
	hp->afh_nethash = n;
E 17
E 8
E 7
E 6
D 3
	hp->afh_hosthash = ntohl(sin->sin_addr.s_addr);
E 3
I 3
D 10
	hp->afh_hosthash = sin->sin_addr.s_addr;
#if vax || pdp11
	hp->afh_hosthash = ntohl(hp->afh_hosthash);
#endif
E 10
I 10
	hp->afh_hosthash = ntohl(sin->sin_addr.s_addr);
E 10
	hp->afh_hosthash &= 0x7fffffff;
E 3
}

inet_netmatch(sin1, sin2)
	struct sockaddr_in *sin1, *sin2;
{

D 6
	return (sin1->sin_addr.s_net == sin2->sin_addr.s_net);
E 6
I 6
D 7
	return (IN_NETOF(sin1->sin_addr) == IN_NETOF(sin2->sin_addr));
E 7
I 7
D 8
	return (in_netof(sin1->sin_addr) == in_netof(sin2->sin_addr));
E 8
I 8
	return (inet_netof(sin1->sin_addr) == inet_netof(sin2->sin_addr));
E 8
E 7
E 6
}

/*
 * Verify the message is from the right port.
 */
inet_portmatch(sin)
D 9
	struct sockaddr_in *sin;
E 9
I 9
	register struct sockaddr_in *sin;
E 9
{
D 3
	int port = ntohs(sin->sin_port);

E 3
I 3
D 9
	int port = sin->sin_port;
E 9
	
D 10
#if vax || pdp11
D 9
	port = ntohs(port);
E 9
I 9
	sin->sin_port = ntohs(sin->sin_port);
E 10
I 10
D 16
#ifdef COMPAT
	if (ntohs(sin->sin_port) == ntohs(sp->s_port) + 1)
		return (1);
E 10
E 9
#endif
E 16
E 3
D 4
	return (port == IPPORT_ROUTESERVER);
E 4
I 4
D 9
	return (port == IPPORT_ROUTESERVER || port == IPPORT_ROUTESERVER+1);
E 9
I 9
D 10
	return (sin->sin_port == sp->s_port || sin->sin_port == sp->s_port+1);
E 10
I 10
	return (sin->sin_port == sp->s_port);
E 10
E 9
E 4
}

/*
I 2
 * Verify the message is from a "trusted" port.
 */
inet_portcheck(sin)
D 9
	struct sockaddr_in *sin;
E 9
I 9
D 10
	register struct sockaddr_in *sin;
E 10
I 10
	struct sockaddr_in *sin;
E 10
E 9
{
D 3
	int port = ntohs(sin->sin_port);
E 3
I 3
D 9
	int port = sin->sin_port;
E 9
E 3

I 3
D 10
#if vax || pdp11
D 9
	port = ntohs(port);
E 9
I 9
	sin->sin_port = ntohs(sin->sin_port);
E 9
#endif
E 3
D 9
	return (port <= IPPORT_RESERVED);
E 9
I 9
	return (sin->sin_port <= IPPORT_RESERVED);
E 10
I 10
	return (ntohs(sin->sin_port) <= IPPORT_RESERVED);
E 10
E 9
}

/*
E 2
 * Internet output routine.
 */
D 3
inet_output(sin, size)
E 3
I 3
D 10
inet_output(s, sin, size)
	int s;
E 10
I 10
inet_output(s, flags, sin, size)
	int s, flags;
E 10
E 3
	struct sockaddr_in *sin;
	int size;
{
D 3
	extern int s;
E 3
D 5
	extern char packet[MAXPACKETSIZE];
E 5
	struct sockaddr_in dst;

	dst = *sin;
	sin = &dst;
D 3
	if (sin->sin_port == 0)
		sin->sin_port = htons(IPPORT_ROUTESERVER);
E 3
I 3
D 9
	if (sin->sin_port == 0) {
		sin->sin_port = IPPORT_ROUTESERVER;
#if vax || pdp11
		sin->sin_port = htons(sin->sin_port);
#endif
	}
E 9
I 9
	if (sin->sin_port == 0)
D 10
		sin->sin_port = htons(sp->s_port);
E 9
E 3
	if (send(s, sin, packet, size) < 0)
D 5
		perror("send");
E 5
I 5
D 9
		tprintf("send to %x: %s\n", sin->sin_addr, sys_errlist[errno]);
E 9
I 9
		perror("send");
E 10
I 10
		sin->sin_port = sp->s_port;
	if (sendto(s, packet, size, flags, sin, sizeof (*sin)) < 0)
		perror("sendto");
E 10
E 9
E 5
}

/*
D 7
 * Return 1 if the address is for an Internet host,
 * otherwise assume it's a network address (broadcast).
E 7
I 7
 * Return 1 if the address is believed
 * for an Internet host -- THIS IS A KLUDGE.
E 7
 */
inet_checkhost(sin)
	struct sockaddr_in *sin;
{
I 14
D 15
	u_long i = ntohl(sin->sin_addr);
E 15
I 15
	u_long i = ntohl(sin->sin_addr.s_addr);
E 15

E 14
I 12
D 24
#define	IN_BADCLASS(i)	(((long) (i) & 0xe0000000) == 0xe0000000)
E 24
I 24
#ifndef IN_EXPERIMENTAL
#define	IN_EXPERIMENTAL(i)	(((long) (i) & 0xe0000000) == 0xe0000000)
#endif
E 24
E 12
I 10

I 12
D 14
	if (IN_BADCLASS(ntohl(sin->sin_addr)))
E 14
I 14
D 17
	if (IN_BADCLASS(i))
E 17
I 17
D 24
	if (IN_BADCLASS(i) || sin->sin_port != 0)
E 24
I 24
	if (IN_EXPERIMENTAL(i) || sin->sin_port != 0)
E 24
E 17
E 14
D 13
		return(0);
	return (inet_netof(sin->sin_addr) != 0);
E 13
I 13
		return (0);
D 14
	if (sin->sin_addr.s_addr != 0 && inet_netof(sin->sin_addr) == 0)
E 14
I 14
	if (i != 0 && (i & 0xff000000) == 0)
E 14
		return (0);
I 19
	for (i = 0; i < sizeof(sin->sin_zero)/sizeof(sin->sin_zero[0]); i++)
		if (sin->sin_zero[i])
			return (0);
E 19
	return (1);
E 13
D 21
}

/*
 * Return 1 if the address is
 * for an Internet host, 0 for a network.
 */
inet_ishost(sin)
	struct sockaddr_in *sin;
{

E 12
E 10
D 7
	extern struct in_addr if_makeaddr();
	struct in_addr netaddr;

D 6
	netaddr = if_makeaddr((int)sin->sin_addr.s_net, INADDR_ANY);
E 6
I 6
	netaddr = if_makeaddr(IN_NETOF(sin->sin_addr), INADDR_ANY);
E 6
	return (netaddr.s_addr != sin->sin_addr.s_addr);
E 7
I 7
D 8
	return (in_lnaof(sin->sin_addr) != 0);
E 8
I 8
	return (inet_lnaof(sin->sin_addr) != 0);
E 21
E 8
E 7
}

inet_canon(sin)
	struct sockaddr_in *sin;
{
I 10

E 10
	sin->sin_port = 0;
}

D 20
/*ARGSUSED*/
null_hash(addr, hp)
	struct sockaddr *addr;
	struct afhash *hp;
E 20
I 20
char *
inet_format(sin)
	struct sockaddr_in *sin;
E 20
{
I 20
	char *inet_ntoa();
E 20

D 20
	hp->afh_nethash = hp->afh_hosthash = 0;
}

/*ARGSUSED*/
null_netmatch(a1, a2)
	struct sockaddr *a1, *a2;
{

	return (0);
}

/*ARGSUSED*/
D 3
null_output(a1, n)
E 3
I 3
D 10
null_output(s, a1, n)
	int s;
E 10
I 10
null_output(s, f, a1, n)
	int s, f;
E 10
E 3
	struct sockaddr *a1;
	int n;
{
I 3

E 3
	;
}

/*ARGSUSED*/
null_portmatch(a1)
I 2
	struct sockaddr *a1;
{
I 3

E 3
	return (0);
}

/*ARGSUSED*/
null_portcheck(a1)
I 12
	struct sockaddr *a1;
{

	return (0);
}

/*ARGSUSED*/
null_ishost(a1)
E 12
E 2
	struct sockaddr *a1;
{
I 3

E 3
	return (0);
}

/*ARGSUSED*/
null_checkhost(a1)
	struct sockaddr *a1;
{
I 3

E 3
	return (0);
}

/*ARGSUSED*/
null_canon(a1)
	struct sockaddr *a1;
{
I 3

E 3
	;
E 20
I 20
	return (inet_ntoa(sin->sin_addr));
E 20
}
E 1
