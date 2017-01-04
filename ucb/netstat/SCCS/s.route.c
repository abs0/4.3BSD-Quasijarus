h42272
s 00013/00008/00354
d D 5.14 88/06/29 20:42:11 bostic 24 23
c install approved copyright notice
e
s 00009/00003/00353
d D 5.13 88/02/07 20:38:23 karels 23 22
c new copyrights
e
s 00005/00005/00351
d D 5.12 87/12/12 18:13:03 karels 22 21
c use MAXHOSTNAMELEN, not "50", print if_name correctly
e
s 00008/00008/00348
d D 5.11 87/08/29 18:54:55 karels 21 20
c readjust field widths
e
s 00012/00013/00344
d D 5.10 87/04/28 19:44:01 karels 20 19
c we paid for it, we might as well use it (and initialize it)
c (why did this work on vax?)
e
s 00001/00000/00356
d D 5.9 87/02/03 22:19:43 karels 19 18
c add M flag
e
s 00005/00005/00351
d D 5.8 86/12/15 17:10:42 sam 18 17
c all statistics are unsigned
e
s 00018/00015/00338
d D 5.7 86/08/11 11:51:12 kupfer 17 16
c Some lint.
e
s 00093/00051/00260
d D 5.6 86/04/23 12:20:27 karels 16 15
c format changes and other fixes
e
s 00002/00001/00309
d D 5.5 85/09/18 17:59:52 karels 15 14
c oops
e
s 00042/00017/00268
d D 5.4 85/09/18 16:47:37 karels 14 13
c add dynamic route flag; truncate domain names if same as ours;
c simplify subnet guessing, so as not to guess forever
e
s 00002/00002/00283
d D 5.3 85/08/16 19:40:25 sklower 13 12
c Add XNS statistics and control blocks; fix bug printing port numbers
e
s 00066/00003/00219
d D 5.2 85/06/15 22:24:30 sklower 12 11
c print xns interfaces and route reasonably
e
s 00008/00002/00214
d D 5.1 85/06/04 15:47:00 dist 11 10
c Add copyright
e
s 00064/00061/00152
d D 4.10 85/06/03 13:29:21 karels 10 9
c new subnets, interface addressing
e
s 00016/00012/00197
d D 4.9 84/10/31 11:39:02 karels 9 8
c get rthashsize from kernel
e
s 00003/00000/00206
d D 4.8 84/05/17 11:17:42 karels 8 7
c subnet fixes
e
s 00041/00006/00165
d D 4.7 84/05/11 12:23:38 karels 7 6
c print subnet addresses correctly; wider address fields
e
s 00030/00001/00141
d D 4.6 83/05/30 21:10:26 sam 6 5
c routing statistics
e
s 00003/00001/00139
d D 4.5 82/11/14 15:11:55 sam 5 4
c convert to 4.1c directory layout
e
s 00002/00002/00138
d D 4.4 82/10/07 18:14:28 sam 4 3
c use routines now in libc.a
e
s 00003/00002/00137
d D 4.3 82/10/06 17:52:51 sam 3 2
c add address format
e
s 00003/00002/00136
d D 4.2 82/10/05 22:18:13 sam 2 1
c new library routines
e
s 00138/00000/00000
d D 4.1 82/08/25 22:21:47 sam 1 0
c date and time created 82/08/25 22:21:47 by sam
e
u
U
t
T
I 11
/*
D 23
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 23
I 23
D 24
 * Copyright (c) 1983,1988 Regents of the University of California.
E 24
I 24
 * Copyright (c) 1983, 1988 Regents of the University of California.
E 24
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 24
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 24
I 24
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
E 24
E 23
 */

E 11
I 1
#ifndef lint
D 11
static char sccsid[] = "%W% %E%";
#endif
E 11
I 11
D 12
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 12
I 12
D 16
static char sccsid[] = "%W% %E%";
E 16
I 16
D 24
static char sccsid[] = "%W% (Berkeley) %E%";
E 16
#endif
E 24
I 24
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 24
E 12
E 11

I 17
#include <stdio.h>
#include <strings.h>

E 17
D 14
#include <sys/types.h>
E 14
I 14
#include <sys/param.h>
E 14
#include <sys/socket.h>
#include <sys/mbuf.h>
I 5

E 5
#include <net/if.h>
D 5
#include <net/in.h>
E 5
D 9
#define	KERNEL		/* to get routehash and RTHASHSIZ */
E 9
#include <net/route.h>
I 5
#include <netinet/in.h>

I 12
#include <netns/ns.h>

E 12
E 5
#include <netdb.h>

extern	int kmem;
extern	int nflag;
D 10
extern	char *routename();
E 10
I 10
D 12
extern	char *routename(), *netname();
E 12
I 12
D 17
extern	char *routename(), *netname(), *ns_print();
E 17
I 17
extern	char *routename(), *netname(), *ns_print(), *plural();
extern	char *malloc();
E 17
E 12
E 10

/*
 * Definitions for showing gateway flags.
 */
struct bits {
	short	b_mask;
	char	b_val;
} bits[] = {
	{ RTF_UP,	'U' },
	{ RTF_GATEWAY,	'G' },
	{ RTF_HOST,	'H' },
I 14
	{ RTF_DYNAMIC,	'D' },
I 19
	{ RTF_MODIFIED,	'M' },
E 19
E 14
	{ 0 }
};

/*
 * Print routing tables.
 */
D 9
routepr(hostaddr, netaddr)
	off_t hostaddr, netaddr;
E 9
I 9
routepr(hostaddr, netaddr, hashsizeaddr)
	off_t hostaddr, netaddr, hashsizeaddr;
E 9
{
	struct mbuf mb;
	register struct rtentry *rt;
	register struct mbuf *m;
	register struct bits *p;
D 9
	struct netent *np;
	struct hostent *hp;
E 9
	char name[16], *flags;
D 9
	struct mbuf *routehash[RTHASHSIZ];
E 9
I 9
	struct mbuf **routehash;
E 9
	struct ifnet ifnet;
D 9
	int first = 1, i, doinghost = 1;
E 9
I 9
	int hashsize;
	int i, doinghost = 1;
E 9

	if (hostaddr == 0) {
		printf("rthost: symbol not in namelist\n");
		return;
	}
	if (netaddr == 0) {
		printf("rtnet: symbol not in namelist\n");
		return;
	}
I 9
	if (hashsizeaddr == 0) {
		printf("rthashsize: symbol not in namelist\n");
		return;
	}
	klseek(kmem, hashsizeaddr, 0);
D 17
	read(kmem, &hashsize, sizeof (hashsize));
E 17
I 17
	read(kmem, (char *)&hashsize, sizeof (hashsize));
E 17
	routehash = (struct mbuf **)malloc( hashsize*sizeof (struct mbuf *) );
E 9
	klseek(kmem, hostaddr, 0);
D 9
	read(kmem, routehash, sizeof (routehash));
E 9
I 9
D 17
	read(kmem, routehash, hashsize*sizeof (struct mbuf *));
E 17
I 17
	read(kmem, (char *)routehash, hashsize*sizeof (struct mbuf *));
E 17
E 9
	printf("Routing tables\n");
D 16
	printf("%-15.15s %-15.15s %-8.8s %-6.6s %-10.10s %s\n",
E 16
I 16
D 21
	printf("%-20.20s %-20.20s %-8.8s %-6.6s %-10.10s %s\n",
E 21
I 21
	printf("%-16.16s %-18.18s %-6.6s  %6.6s%8.8s  %s\n",
E 21
E 16
		"Destination", "Gateway",
D 21
		"Flags", "Refcnt", "Use", "Interface");
E 21
I 21
		"Flags", "Refs", "Use", "Interface");
E 21
again:
D 9
	for (i = 0; i < RTHASHSIZ; i++) {
E 9
I 9
	for (i = 0; i < hashsize; i++) {
E 9
		if (routehash[i] == 0)
			continue;
		m = routehash[i];
		while (m) {
			struct sockaddr_in *sin;
I 12
D 17
			struct sockaddr_ns *sns;
E 17
D 16
			long *l = (long *)&rt->rt_dst;
E 16
E 12

D 17
			klseek(kmem, m, 0);
			read(kmem, &mb, sizeof (mb));
E 17
I 17
			klseek(kmem, (off_t)m, 0);
			read(kmem, (char *)&mb, sizeof (mb));
E 17
			rt = mtod(&mb, struct rtentry *);
I 16
			if ((unsigned)rt < (unsigned)&mb ||
			    (unsigned)rt >= (unsigned)(&mb + 1)) {
				printf("???\n");
				return;
			}

E 16
I 12
			switch(rt->rt_dst.sa_family) {
D 16
		case AF_INET:
E 12
			sin = (struct sockaddr_in *)&rt->rt_dst;
D 6
			printf("%-15.15s ", routename(sin->sin_addr));
E 6
I 6
			printf("%-15.15s ",
D 10
			    sin->sin_addr.s_addr ?
				routename(sin->sin_addr) : "default");
E 10
I 10
			    (sin->sin_addr.s_addr == 0) ? "default" :
			    (rt->rt_flags & RTF_HOST) ?
			    routename(sin->sin_addr) : netname(sin->sin_addr, 0));
E 10
E 6
			sin = (struct sockaddr_in *)&rt->rt_gateway;
			printf("%-15.15s ", routename(sin->sin_addr));
I 12
			break;
		case AF_NS:
			printf("%-15s ",
			    ns_print((struct sockaddr_ns *)&rt->rt_dst));
			printf("%-15s ",
			    ns_print((struct sockaddr_ns *)&rt->rt_gateway));
			break;
		default:
			printf("%8.8x %8.8x %8.8x %8.8x",*l, l[1], l[2], l[3]);
			l = (long *)&rt->rt_gateway;
			printf("%8.8x %8.8x %8.8x %8.8x",*l, l[1], l[2], l[3]);
E 16
I 16
			case AF_INET:
				sin = (struct sockaddr_in *)&rt->rt_dst;
D 21
				printf("%-20.20s ",
E 21
I 21
				printf("%-16.16s ",
E 21
				    (sin->sin_addr.s_addr == 0) ? "default" :
				    (rt->rt_flags & RTF_HOST) ?
				    routename(sin->sin_addr) :
D 17
					netname(sin->sin_addr, 0));
E 17
I 17
					netname(sin->sin_addr, 0L));
E 17
				sin = (struct sockaddr_in *)&rt->rt_gateway;
D 21
				printf("%-20.20s ", routename(sin->sin_addr));
E 21
I 21
				printf("%-18.18s ", routename(sin->sin_addr));
E 21
				break;
			case AF_NS:
D 21
				printf("%-20s ",
E 21
I 21
				printf("%-16s ",
E 21
				    ns_print((struct sockaddr_ns *)&rt->rt_dst));
D 21
				printf("%-20s ",
E 21
I 21
				printf("%-18s ",
E 21
				    ns_print((struct sockaddr_ns *)&rt->rt_gateway));
				break;
			default:
				{
				u_short *s = (u_short *)rt->rt_dst.sa_data;
				printf("(%d)%x %x %x %x %x %x %x ",
				    rt->rt_dst.sa_family,
				    s[0], s[1], s[2], s[3], s[4], s[5], s[6]);
				s = (u_short *)rt->rt_gateway.sa_data;
				printf("(%d)%x %x %x %x %x %x %x ",
				    rt->rt_gateway.sa_family,
				    s[0], s[1], s[2], s[3], s[4], s[5], s[6]);
				}
E 16
			}
E 12
			for (flags = name, p = bits; p->b_mask; p++)
				if (p->b_mask & rt->rt_flags)
					*flags++ = p->b_val;
			*flags = '\0';
D 21
			printf("%-8.8s %-6d %-10d ", name,
E 21
I 21
			printf("%-6.6s %6d %8d ", name,
E 21
				rt->rt_refcnt, rt->rt_use);
			if (rt->rt_ifp == 0) {
				putchar('\n');
				m = mb.m_next;
				continue;
			}
D 17
			klseek(kmem, rt->rt_ifp, 0);
			read(kmem, &ifnet, sizeof (ifnet));
			klseek(kmem, (int)ifnet.if_name, 0);
E 17
I 17
			klseek(kmem, (off_t)rt->rt_ifp, 0);
			read(kmem, (char *)&ifnet, sizeof (ifnet));
			klseek(kmem, (off_t)ifnet.if_name, 0);
E 17
			read(kmem, name, 16);
D 21
			printf("%s%d\n", name, ifnet.if_unit);
E 21
I 21
D 22
			printf(" %s%d\n", name, ifnet.if_unit);
E 22
I 22
			printf(" %.15s%d\n", name, ifnet.if_unit);
E 22
E 21
			m = mb.m_next;
		}
	}
	if (doinghost) {
		klseek(kmem, netaddr, 0);
D 9
		read(kmem, routehash, sizeof (routehash));
E 9
I 9
D 17
		read(kmem, routehash, hashsize*sizeof (struct mbuf *));
E 17
I 17
		read(kmem, (char *)routehash, hashsize*sizeof (struct mbuf *));
E 17
E 9
		doinghost = 0;
		goto again;
	}
I 9
D 17
	free(routehash);
E 17
I 17
	free((char *)routehash);
E 17
E 9
}

char *
routename(in)
	struct in_addr in;
{
D 14
	char *cp = 0;
E 14
I 14
D 15
	register char *cp = 0;
E 15
I 15
	register char *cp;
E 15
E 14
D 22
	static char line[50];
E 22
I 22
	static char line[MAXHOSTNAMELEN + 1];
E 22
D 7
	int lna, net;
E 7
I 7
	struct hostent *hp;
I 14
	static char domain[MAXHOSTNAMELEN + 1];
	static int first = 1;
	char *index();
E 14
D 10
	struct netent *np;
	int lna, net, subnet;
E 10
E 7

I 14
	if (first) {
		first = 0;
		if (gethostname(domain, MAXHOSTNAMELEN) == 0 &&
		    (cp = index(domain, '.')))
			(void) strcpy(domain, cp + 1);
		else
			domain[0] = 0;
	}
I 15
	cp = 0;
E 15
E 14
D 4
	net = in_netof(in);
	lna = in_lnaof(in);
E 4
I 4
D 10
	net = inet_netof(in);
I 7
	subnet = inet_subnetof(in);
E 7
	lna = inet_lnaof(in);
E 10
E 4
	if (!nflag) {
D 10
		if (lna == INADDR_ANY) {
D 2
			struct netent *np = getnetaddr(net);
E 2
I 2
D 3
			struct netent *np = getnetbyaddr(net);
E 3
I 3
D 7
			struct netent *np = getnetbyaddr(net, AF_INET);
E 3
E 2

E 7
I 7
			np = getnetbyaddr(net, AF_INET);
E 7
			if (np)
				cp = np->n_name;
I 7
D 9
			else if (net == 0)
				cp = "default";
E 9
		} else if ((subnet != net) && ((lna & 0xff) == 0) &&
		    (np = getnetbyaddr(subnet, AF_INET))) {
			struct in_addr subnaddr, inet_makeaddr();
			subnaddr = inet_makeaddr(subnet, INADDR_ANY);
			if (bcmp(&in, &subnaddr, sizeof(in)) == 0)
				cp = np->n_name;
I 8
			else
				goto host;
E 8
E 7
		} else {
I 8
host:
E 8
D 2
			struct hostent *hp = gethostaddr(in.s_addr);
E 2
I 2
D 7
			struct hostent *hp;
E 2

E 7
I 2
D 3
			hp = gethostbyaddr(&in, sizeof (struct in_addr));
E 3
I 3
			hp = gethostbyaddr(&in, sizeof (struct in_addr),
				AF_INET);
E 3
E 2
			if (hp)
				cp = hp->h_name;
		}
E 10
I 10
D 17
		hp = gethostbyaddr(&in, sizeof (struct in_addr),
E 17
I 17
		hp = gethostbyaddr((char *)&in, sizeof (struct in_addr),
E 17
			AF_INET);
D 14
		if (hp)
E 14
I 14
		if (hp) {
			if ((cp = index(hp->h_name, '.')) &&
			    !strcmp(cp + 1, domain))
				*cp = 0;
E 14
			cp = hp->h_name;
I 14
		}
E 14
E 10
	}
	if (cp)
D 22
		strcpy(line, cp);
E 22
I 22
		strncpy(line, cp, sizeof(line) - 1);
E 22
	else {
D 10
		u_char *ucp = (u_char *)&in;
		if (lna == INADDR_ANY)
			sprintf(line, "%u.%u.%u", ucp[0], ucp[1], ucp[2]);
		else
			sprintf(line, "%u.%u.%u.%u", ucp[0], ucp[1],
				ucp[2], ucp[3]);
E 10
I 10
#define C(x)	((x) & 0xff)
		in.s_addr = ntohl(in.s_addr);
		sprintf(line, "%u.%u.%u.%u", C(in.s_addr >> 24),
			C(in.s_addr >> 16), C(in.s_addr >> 8), C(in.s_addr));
E 10
	}
	return (line);
I 6
}
I 10

E 10
D 7

E 7
/*
I 10
 * Return the name of the network whose address is given.
 * The address is assumed to be that of a net or subnet, not a host.
 */
char *
netname(in, mask)
	struct in_addr in;
	u_long mask;
{
	char *cp = 0;
D 22
	static char line[50];
E 22
I 22
	static char line[MAXHOSTNAMELEN + 1];
E 22
	struct netent *np = 0;
	u_long net;
	register i;
I 14
	int subnetshift;
E 14

D 20
	in.s_addr = ntohl(in.s_addr);
	if (!nflag && in.s_addr) {
E 20
I 20
	i = ntohl(in.s_addr);
	if (!nflag && i) {
E 20
D 14
		if (mask) {
			net = in.s_addr & mask;
			while ((mask & 1) == 0)
				mask >>= 1, net >>= 1;
			np = getnetbyaddr(net, AF_INET);
		}
		if (np == 0) {
E 14
I 14
		if (mask == 0) {
			if (IN_CLASSA(i)) {
				mask = IN_CLASSA_NET;
				subnetshift = 8;
			} else if (IN_CLASSB(i)) {
				mask = IN_CLASSB_NET;
				subnetshift = 8;
			} else {
				mask = IN_CLASSC_NET;
				subnetshift = 4;
			}
E 14
			/*
D 14
			 * Try for subnet addresses.
E 14
I 14
			 * If there are more bits than the standard mask
			 * would suggest, subnets must be in use.
			 * Guess at the subnet mask, assuming reasonable
			 * width subnet fields.
E 14
			 */
D 14
			for (i = 0; ((0xf<<i) & in.s_addr) == 0; i += 4)
				;
			for ( ; i; i -= 4)
			    if (np = getnetbyaddr((unsigned)in.s_addr >> i,
				    AF_INET))
					break;
E 14
I 14
D 20
			while (in.s_addr &~ mask)
E 20
I 20
			while (i &~ mask)
E 20
				mask = (long)mask >> subnetshift;
E 14
		}
I 14
D 20
		net = in.s_addr & mask;
E 20
I 20
		net = i & mask;
E 20
		while ((mask & 1) == 0)
			mask >>= 1, net >>= 1;
		np = getnetbyaddr(net, AF_INET);
E 14
		if (np)
			cp = np->n_name;
D 17
	}
E 17
I 17
	}	
E 17
	if (cp)
D 22
		strcpy(line, cp);
E 22
I 22
		strncpy(line, cp, sizeof(line) - 1);
E 22
D 20
	else if ((in.s_addr & 0xffffff) == 0)
		sprintf(line, "%u", C(in.s_addr >> 24));
	else if ((in.s_addr & 0xffff) == 0)
		sprintf(line, "%u.%u", C(in.s_addr >> 24) , C(in.s_addr >> 16));
	else if ((in.s_addr & 0xff) == 0)
		sprintf(line, "%u.%u.%u", C(in.s_addr >> 24),
			C(in.s_addr >> 16), C(in.s_addr >> 8));
E 20
I 20
	else if ((i & 0xffffff) == 0)
		sprintf(line, "%u", C(i >> 24));
	else if ((i & 0xffff) == 0)
		sprintf(line, "%u.%u", C(i >> 24) , C(i >> 16));
	else if ((i & 0xff) == 0)
		sprintf(line, "%u.%u.%u", C(i >> 24), C(i >> 16), C(i >> 8));
E 20
	else
D 20
		sprintf(line, "%u.%u.%u.%u", C(in.s_addr >> 24),
			C(in.s_addr >> 16), C(in.s_addr >> 8), C(in.s_addr));
E 20
I 20
		sprintf(line, "%u.%u.%u.%u", C(i >> 24),
			C(i >> 16), C(i >> 8), C(i));
E 20
	return (line);
}
I 14

E 14
/*
E 10
 * Print routing statistics
 */
rt_stats(off)
	off_t off;
{
	struct rtstat rtstat;

	if (off == 0) {
		printf("rtstat: symbol not in namelist\n");
		return;
	}
	klseek(kmem, off, 0);
	read(kmem, (char *)&rtstat, sizeof (rtstat));
	printf("routing:\n");
D 18
	printf("\t%d bad routing redirect%s\n",
E 18
I 18
	printf("\t%u bad routing redirect%s\n",
E 18
		rtstat.rts_badredirect, plural(rtstat.rts_badredirect));
D 18
	printf("\t%d dynamically created route%s\n",
E 18
I 18
	printf("\t%u dynamically created route%s\n",
E 18
		rtstat.rts_dynamic, plural(rtstat.rts_dynamic));
D 18
	printf("\t%d new gateway%s due to redirects\n",
E 18
I 18
	printf("\t%u new gateway%s due to redirects\n",
E 18
		rtstat.rts_newgateway, plural(rtstat.rts_newgateway));
D 18
	printf("\t%d destination%s found unreachable\n",
E 18
I 18
	printf("\t%u destination%s found unreachable\n",
E 18
		rtstat.rts_unreach, plural(rtstat.rts_unreach));
D 18
	printf("\t%d use%s of a wildcard route\n",
E 18
I 18
	printf("\t%u use%s of a wildcard route\n",
E 18
		rtstat.rts_wildcard, plural(rtstat.rts_wildcard));
I 12
}
I 16
short ns_nullh[] = {0,0,0};
E 16
short ns_bh[] = {-1,-1,-1};

char *
ns_print(sns)
struct sockaddr_ns *sns;
{
D 16
	register struct ns_addr *dna = &sns->sns_addr;
	long net = ntohl(ns_netof(*dna));
	static char mybuf[50];
	register char *p = mybuf;
	short port = dna->x_port;
E 16
I 16
	struct ns_addr work;
	union { union ns_net net_e; u_long long_e; } net;
	u_short port;
	static char mybuf[50], cport[10], chost[25];
	char *host = "";
D 17
	register char *p; register u_char *q; u_char *q_lim;
E 17
I 17
	register char *p; register u_char *q;
E 17
E 16

D 13
	sprintf(p,"%ld:", net);
E 13
I 13
D 16
	sprintf(p,"%lx:", net);
E 16
I 16
	work = sns->sns_addr;
	port = ntohs(work.x_port);
	work.x_port = 0;
	net.net_e  = work.x_net;
	if (ns_nullhost(work) && net.long_e == 0) {
		if (port ) {
			sprintf(mybuf, "*.%xH", port);
			upHex(mybuf);
		} else
			sprintf(mybuf, "*.*");
		return (mybuf);
	}
E 16
E 13

D 16
	while(*p)p++; /* find end of string */

	if (strncmp(ns_bh,dna->x_host.c_host,6)==0)
		sprintf(p,"any");
	else
		sprintf(p,"%x.%x.%x.%x.%x.%x",
			    dna->x_host.c_host[0], dna->x_host.c_host[1],
			    dna->x_host.c_host[2], dna->x_host.c_host[3],
			    dna->x_host.c_host[4], dna->x_host.c_host[5]);
	if (port) {
	while(*p)p++; /* find end of string */
D 13
		printf(":%d",port);
E 13
I 13
		sprintf(p,":%x",ntohs(port));
E 16
I 16
	if (bcmp(ns_bh, work.x_host.c_host, 6) == 0) { 
		host = "any";
	} else if (bcmp(ns_nullh, work.x_host.c_host, 6) == 0) {
		host = "*";
	} else {
		q = work.x_host.c_host;
		sprintf(chost, "%02x%02x%02x%02x%02x%02xH",
			q[0], q[1], q[2], q[3], q[4], q[5]);
		for (p = chost; *p == '0' && p < chost + 12; p++);
		host = p;
E 16
E 13
	}
I 16
	if (port)
		sprintf(cport, ".%xH", htons(port));
	else
		*cport = 0;

	sprintf(mybuf,"%xH.%s%s", ntohl(net.long_e), host, cport);
	upHex(mybuf);
E 16
	return(mybuf);
}
I 16

E 16
char *
ns_phost(sns)
struct sockaddr_ns *sns;
{
D 16
	register struct ns_addr *dna = &sns->sns_addr;
	long net = ntohl(ns_netof(*dna));
	static char mybuf[50];
	register char *p = mybuf;
	if (strncmp(ns_bh,dna->x_host.c_host,6)==0)
		sprintf(p,"any");
	else
		sprintf(p,"%x,%x,%x",
			   dna->x_host.s_host[0], dna->x_host.s_host[1],
			    dna->x_host.s_host[2]);
	return(mybuf);
E 16
I 16
	struct sockaddr_ns work;
	static union ns_net ns_zeronet;
	char *p;
	
	work = *sns;
	work.sns_addr.x_port = 0;
	work.sns_addr.x_net = ns_zeronet;

	p = ns_print(&work);
	if (strncmp("0H.", p, 3) == 0) p += 3;
	return(p);
}
upHex(p0)
char *p0;
{
	register char *p = p0;
	for (; *p; p++) switch (*p) {

	case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
		*p += ('A' - 'a');
	}
E 16
E 12
I 7
D 10
}

/*
 * Return the possible subnetwork number from an internet address.
 * If the address is of the form of a subnet address (most significant
 * bit of the host part is set), believe the subnet exists.
 * Otherwise, return the network number.
 * SHOULD FIND OUT WHETHER THIS IS A LOCAL NETWORK BEFORE LOOKING
 * INSIDE OF THE HOST PART.  We can only believe this if we have other
 * information (e.g., we can find a name for this number).
 */
inet_subnetof(in)
	struct in_addr in;
{
	register u_long i = ntohl(in.s_addr);

	if (IN_CLASSA(i)) {
		if (IN_SUBNETA(i))
			return ((i & IN_CLASSA_SUBNET) >> IN_CLASSA_SUBNSHIFT);
		else
			return ((i & IN_CLASSA_NET) >> IN_CLASSA_NSHIFT);
	} else if (IN_CLASSB(i)) {
		if (IN_SUBNETB(i))
			return ((i & IN_CLASSB_SUBNET) >> IN_CLASSB_SUBNSHIFT);
		else
			return ((i & IN_CLASSB_NET) >> IN_CLASSB_NSHIFT);
	} else
		return ((i & IN_CLASSC_NET) >> IN_CLASSC_NSHIFT);
E 10
E 7
E 6
}
E 1
