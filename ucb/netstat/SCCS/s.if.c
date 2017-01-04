h58847
s 00012/00007/00324
d D 5.8 88/06/29 20:42:01 bostic 17 16
c install approved copyright notice
e
s 00032/00008/00299
d D 5.7 88/05/14 10:16:54 karels 16 15
c print drops on request
e
s 00009/00003/00298
d D 5.6 88/02/07 20:38:15 karels 15 14
c new copyrights
e
s 00024/00023/00277
d D 5.5 87/08/31 10:09:15 karels 14 12
c widen fields so numeric addresses aren't truncated
e
s 00024/00023/00277
d R 5.5 87/08/29 18:54:34 karels 13 12
c widen fields so numeric addresses aren't truncated
e
s 00046/00020/00254
d D 5.4 86/08/11 11:48:26 kupfer 12 11
c Use alarm() instead of sleep(). Some lint.
e
s 00007/00002/00267
d D 5.3 86/04/23 12:20:20 karels 11 10
c format changes and other fixes
e
s 00010/00000/00259
d D 5.2 85/06/15 22:24:37 sklower 10 9
c print xns interfaces and route reasonably
e
s 00008/00002/00251
d D 5.1 85/06/04 15:35:10 dist 9 8
c Add copyright
e
s 00075/00021/00178
d D 4.7 85/06/03 13:28:43 karels 8 7
c new subnets, interface addressing
e
s 00011/00003/00188
d D 4.6 84/11/20 17:19:24 edward 7 5
c -I to specify which interface we care about
e
s 00007/00002/00189
d R 4.6 84/11/20 16:45:14 edward 6 5
c -I flag to specify interface
e
s 00000/00002/00191
d D 4.5 84/09/17 11:26:06 ralph 5 4
c don't call setbuf.
e
s 00003/00001/00190
d D 4.4 82/11/14 15:11:26 sam 4 3
c convert to 4.1c directory layout
e
s 00004/00002/00187
d D 4.3 82/10/07 18:41:06 sam 3 2
c fix network # printout
e
s 00106/00027/00083
d D 4.2 82/10/06 10:30:31 sam 2 1
c add netdb and interval display on interface stats
e
s 00110/00000/00000
d D 4.1 82/08/25 22:21:40 sam 1 0
c date and time created 82/08/25 22:21:40 by sam
e
u
U
t
T
I 9
/*
D 15
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 15
I 15
D 17
 * Copyright (c) 1983,1988 Regents of the University of California.
E 17
I 17
 * Copyright (c) 1983, 1988 Regents of the University of California.
E 17
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 17
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 17
I 17
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
E 17
E 15
 */

E 9
I 1
#ifndef lint
D 9
static char sccsid[] = "%W% %E%";
#endif
E 9
I 9
static char sccsid[] = "%W% (Berkeley) %G%";
D 17
#endif not lint
E 17
I 17
#endif /* not lint */
E 17
E 9

#include <sys/types.h>
#include <sys/socket.h>
D 4
#include <net/in.h>
E 4
I 4

E 4
#include <net/if.h>
I 4
#include <netinet/in.h>
I 8
#include <netinet/in_var.h>
I 10
#include <netns/ns.h>
E 10
E 8

E 4
I 2
#include <stdio.h>
I 12
#include <signal.h>
E 12
E 2

I 12
#define	YES	1
#define	NO	0

E 12
extern	int kmem;
extern	int tflag;
I 16
extern	int dflag;
E 16
extern	int nflag;
I 7
extern	char *interface;
extern	int unit;
E 7
D 8
extern	char *routename();
E 8
I 8
D 12
extern	char *routename(), *netname();
E 12
I 12
extern	char *routename(), *netname(), *ns_phost();
E 12
E 8

/*
 * Print a description of the network interfaces.
D 2
 * If interval is non-zero, repeat display every 
 * interval seconds, showing statistics collected
 * over that interval.  First line printed is always
 * cumulative.
E 2
 */
intpr(interval, ifnetaddr)
	int interval;
	off_t ifnetaddr;
{
	struct ifnet ifnet;
I 8
	union {
		struct ifaddr ifa;
		struct in_ifaddr in;
	} ifaddr;
	off_t ifaddraddr;
E 8
	char name[16];

	if (ifnetaddr == 0) {
		printf("ifnet: symbol not defined\n");
		return;
	}
	if (interval) {
D 12
		sidewaysintpr(interval, ifnetaddr);
E 12
I 12
		sidewaysintpr((unsigned)interval, ifnetaddr);
E 12
		return;
	}
	klseek(kmem, ifnetaddr, 0);
D 12
	read(kmem, &ifnetaddr, sizeof ifnetaddr);
E 12
I 12
	read(kmem, (char *)&ifnetaddr, sizeof ifnetaddr);
E 12
D 2
	printf("%-5.5s %-5.5s %-8.8s %-12.12s %-7.7s %-5.5s %-7.7s %-5.5s",
E 2
I 2
D 3
	printf("%-5.5s %-5.5s %-8.8s  %-12.12s %-7.7s %-5.5s %-7.7s %-5.5s",
E 3
I 3
D 14
	printf("%-5.5s %-5.5s %-10.10s  %-12.12s %-7.7s %-5.5s %-7.7s %-5.5s",
E 14
I 14
	printf("%-5.5s %-5.5s %-11.11s %-15.15s %8.8s %5.5s %8.8s %5.5s",
E 14
E 3
E 2
		"Name", "Mtu", "Network", "Address", "Ipkts", "Ierrs",
		"Opkts", "Oerrs");
D 14
	printf(" %-6.6s", "Collis");
E 14
I 14
	printf(" %5s", "Coll");
E 14
	if (tflag)
D 14
		printf(" %-6.6s", "Timer");
E 14
I 14
		printf(" %s", "Time");
I 16
	if (dflag)
		printf(" %s", "Drop");
E 16
E 14
	putchar('\n');
D 8
	while (ifnetaddr) {
E 8
I 8
	ifaddraddr = 0;
	while (ifnetaddr || ifaddraddr) {
E 8
		struct sockaddr_in *sin;
		register char *cp;
I 8
		int n;
E 8
		char *index();
I 3
D 12
		struct in_addr in, inet_makeaddr();
E 12
I 12
		struct in_addr inet_makeaddr();
E 12
E 3

D 8
		klseek(kmem, ifnetaddr, 0);
		read(kmem, &ifnet, sizeof ifnet);
		klseek(kmem, (int)ifnet.if_name, 0);
		read(kmem, name, 16);
		name[15] = '\0';
I 7
		ifnetaddr = (off_t) ifnet.if_next;
		if (interface != 0 &&
		    (strcmp(name, interface) != 0 || unit != ifnet.if_unit))
			continue;
E 7
		cp = index(name, '\0');
		*cp++ = ifnet.if_unit + '0';
		if ((ifnet.if_flags&IFF_UP) == 0)
			*cp++ = '*';
		*cp = '\0';
E 8
I 8
		if (ifaddraddr == 0) {
			klseek(kmem, ifnetaddr, 0);
D 12
			read(kmem, &ifnet, sizeof ifnet);
E 12
I 12
			read(kmem, (char *)&ifnet, sizeof ifnet);
E 12
			klseek(kmem, (off_t)ifnet.if_name, 0);
			read(kmem, name, 16);
			name[15] = '\0';
			ifnetaddr = (off_t) ifnet.if_next;
			if (interface != 0 &&
			    (strcmp(name, interface) != 0 || unit != ifnet.if_unit))
				continue;
			cp = index(name, '\0');
			*cp++ = ifnet.if_unit + '0';
			if ((ifnet.if_flags&IFF_UP) == 0)
				*cp++ = '*';
			*cp = '\0';
			ifaddraddr = (off_t)ifnet.if_addrlist;
		}
E 8
		printf("%-5.5s %-5d ", name, ifnet.if_mtu);
D 8
		sin = (struct sockaddr_in *)&ifnet.if_addr;
D 2
		printf("%-8.8s ", routename(ifnet.if_net));
E 2
I 2
D 3
		printf("%-8.8s  ", routename(ifnet.if_net));
E 3
I 3
		in = inet_makeaddr(ifnet.if_net, INADDR_ANY);
		printf("%-10.10s  ", routename(in));
E 3
E 2
		printf("%-12.12s %-7d %-5d %-7d %-5d %-6d",
		    routename(sin->sin_addr),
E 8
I 8
		if (ifaddraddr == 0) {
D 14
			printf("%-10.10s  ", "none");
			printf("%-12.12s ", "none");
E 14
I 14
			printf("%-11.11s ", "none");
			printf("%-15.15s ", "none");
E 14
		} else {
			klseek(kmem, ifaddraddr, 0);
D 12
			read(kmem, &ifaddr, sizeof ifaddr);
E 12
I 12
			read(kmem, (char *)&ifaddr, sizeof ifaddr);
E 12
			ifaddraddr = (off_t)ifaddr.ifa.ifa_next;
			switch (ifaddr.ifa.ifa_addr.sa_family) {
			case AF_UNSPEC:
D 14
				printf("%-10.10s  ", "none");
				printf("%-12.12s ", "none");
E 14
I 14
				printf("%-11.11s ", "none");
				printf("%-15.15s ", "none");
E 14
				break;
			case AF_INET:
				sin = (struct sockaddr_in *)&ifaddr.in.ia_addr;
#ifdef notdef
				/* can't use inet_makeaddr because kernel
				 * keeps nets unshifted.
				 */
				in = inet_makeaddr(ifaddr.in.ia_subnet,
					INADDR_ANY);
D 14
				printf("%-10.10s  ", netname(in));
E 14
I 14
				printf("%-11.11s ", netname(in));
E 14
#else
D 14
				printf("%-10.10s  ",
E 14
I 14
				printf("%-11.11s ",
E 14
					netname(htonl(ifaddr.in.ia_subnet),
						ifaddr.in.ia_subnetmask));
#endif
D 14
				printf("%-12.12s ", routename(sin->sin_addr));
E 14
I 14
				printf("%-15.15s ", routename(sin->sin_addr));
E 14
I 10
				break;
			case AF_NS:
				{
				struct sockaddr_ns *sns =
				(struct sockaddr_ns *)&ifaddr.in.ia_addr;
D 11
				printf("ns:%-8d ",
					ntohl(ns_netof(sns->sns_addr)));
E 11
I 11
D 12
				long net;
E 12
I 12
				u_long net;
E 12
D 14
				char host[8];
E 14
I 14
				char netnum[8];
E 14
I 12
				char *ns_phost();

E 12
				*(union ns_net *) &net = sns->sns_addr.x_net;
D 14
				sprintf(host, "%lxH", ntohl(net));
				upHex(host);
				printf("ns:%-8s ", host);
D 12

E 11
				printf("%-12s ",ns_phost(sns));
E 12
I 12
				printf("%-12s ", ns_phost(sns));
E 14
I 14
				sprintf(netnum, "%lxH", ntohl(net));
				upHex(netnum);
				printf("ns:%-8s ", netnum);
				printf("%-15s ", ns_phost(sns));
E 14
E 12
				}
E 10
				break;
			default:
				printf("af%2d: ", ifaddr.ifa.ifa_addr.sa_family);
				for (cp = (char *)&ifaddr.ifa.ifa_addr +
				    sizeof(struct sockaddr) - 1;
				    cp >= ifaddr.ifa.ifa_addr.sa_data; --cp)
					if (*cp != 0)
						break;
				n = cp - (char *)ifaddr.ifa.ifa_addr.sa_data + 1;
				cp = (char *)ifaddr.ifa.ifa_addr.sa_data;
D 14
				if (n <= 6)
E 14
I 14
				if (n <= 7)
E 14
					while (--n)
						printf("%02d.", *cp++ & 0xff);
				else
					while (--n)
						printf("%02d", *cp++ & 0xff);
				printf("%02d ", *cp & 0xff);
				break;
			}
		}
D 14
		printf("%-7d %-5d %-7d %-5d %-6d",
E 14
I 14
		printf("%8d %5d %8d %5d %5d",
E 14
E 8
		    ifnet.if_ipackets, ifnet.if_ierrors,
		    ifnet.if_opackets, ifnet.if_oerrors,
		    ifnet.if_collisions);
		if (tflag)
D 14
			printf(" %-6d", ifnet.if_timer);
E 14
I 14
			printf(" %3d", ifnet.if_timer);
I 16
		if (dflag)
			printf(" %3d", ifnet.if_snd.ifq_drops);
E 16
E 14
		putchar('\n');
D 7
		ifnetaddr = (off_t) ifnet.if_next;
E 7
	}
}

I 2
#define	MAXIF	10
struct	iftot {
	char	ift_name[16];		/* interface name */
	int	ift_ip;			/* input packets */
	int	ift_ie;			/* input errors */
	int	ift_op;			/* output packets */
	int	ift_oe;			/* output errors */
	int	ift_co;			/* collisions */
I 16
	int	ift_dr;			/* drops */
E 16
} iftot[MAXIF];

I 12
u_char	signalled;			/* set if alarm goes off "early" */

E 12
/*
 * Print a running summary of interface statistics.
D 12
 * Repeat display every interval seconds, showing
 * statistics collected over that interval.  First
 * line printed at top of screen is always cumulative.
E 12
I 12
 * Repeat display every interval seconds, showing statistics
 * collected over that interval.  Assumes that interval is non-zero.
 * First line printed at top of screen is always cumulative.
E 12
 */
E 2
sidewaysintpr(interval, off)
D 12
	int interval;
E 12
I 12
	unsigned interval;
E 12
	off_t off;
{
	struct ifnet ifnet;
D 2
	char name[16];
E 2
I 2
	off_t firstifnet;
D 5
	extern char _sobuf[];
E 5
	register struct iftot *ip, *total;
	register int line;
	struct iftot *lastif, *sum, *interesting;
D 12
	int maxtraffic;
E 12
I 12
	int oldmask;
	int catchalarm();
E 12
E 2

I 2
D 5
	setbuf(stdout, _sobuf);
E 5
E 2
	klseek(kmem, off, 0);
D 2
	read(kmem, &off, sizeof (off_t));
	return;
	/*NOTREACHED*/
	printf("%-5.5s\t%-5.5s  %-10.10s  %-10.10s %-7.7s %-5.5s %-7.7s %-5.5s",
		"Name", "Ipkts", "Ierrs", "Opkts", "Oerrs");
	printf("  %-6.6s", "collis");
	while (off) {
		struct sockaddr_in *sin;
E 2
I 2
D 12
	read(kmem, &firstifnet, sizeof (off_t));
E 12
I 12
	read(kmem, (char *)&firstifnet, sizeof (off_t));
E 12
	lastif = iftot;
	sum = iftot + MAXIF - 1;
	total = sum - 1;
I 7
	interesting = iftot;
E 7
	for (off = firstifnet, ip = iftot; off;) {
		char *cp;
E 2

		klseek(kmem, off, 0);
D 12
		read(kmem, &ifnet, sizeof ifnet);
		klseek(kmem, (int)ifnet.if_name, 0);
E 12
I 12
		read(kmem, (char *)&ifnet, sizeof ifnet);
		klseek(kmem, (off_t)ifnet.if_name, 0);
E 12
D 2
		read(kmem, name, 16);
		sin = (struct sockaddr_in *)&ifnet.if_addr;
		printf("%s%d%c:\t%5d  ",
		    name, ifnet.if_unit, ifnet.if_flags & IFF_UP ? '\0' : '*',
		    ifnet.if_mtu);
		printf("%-10.10s %-10.10s %7d %5d %7d %5d  %6d",
		    inetname(ifnet.if_net),
		    inetname(sin->sin_addr),
		    ifnet.if_ipackets, ifnet.if_ierrors,
		    ifnet.if_opackets, ifnet.if_oerrors,
		    ifnet.if_collisions);
		putchar('\n');
E 2
I 2
		ip->ift_name[0] = '(';
		read(kmem, ip->ift_name + 1, 15);
I 7
		if (interface && strcmp(ip->ift_name + 1, interface) == 0 &&
		    unit == ifnet.if_unit)
			interesting = ip;
E 7
		ip->ift_name[15] = '\0';
		cp = index(ip->ift_name, '\0');
		sprintf(cp, "%d)", ifnet.if_unit);
		ip++;
		if (ip >= iftot + MAXIF - 2)
			break;
E 2
		off = (off_t) ifnet.if_next;
	}
I 2
	lastif = ip;
I 12

	(void)signal(SIGALRM, catchalarm);
	signalled = NO;
	(void)alarm(interval);
E 12
D 7
	interesting = iftot;
E 7
banner:
D 16
	printf("    input   %-6.6s    output       ", interesting->ift_name);
	if (lastif - iftot > 0)
D 7
		printf("    input   (Total)    output       ");
E 7
I 7
D 14
		printf("   input  (Total)    output       ");
E 14
I 14
		printf("     input  (Total)    output");
E 16
I 16
	printf("   input    %-6.6s    output       ", interesting->ift_name);
	if (lastif - iftot > 0) {
		if (dflag)
			printf("      ");
		printf("     input   (Total)    output");
	}
E 16
E 14
E 7
	for (ip = iftot; ip < iftot + MAXIF; ip++) {
		ip->ift_ip = 0;
		ip->ift_ie = 0;
		ip->ift_op = 0;
		ip->ift_oe = 0;
		ip->ift_co = 0;
I 16
		ip->ift_dr = 0;
E 16
	}
	putchar('\n');
D 14
	printf("%-7.7s %-5.5s %-7.7s %-5.5s %-5.5s ",
E 14
I 14
	printf("%8.8s %5.5s %8.8s %5.5s %5.5s ",
E 14
		"packets", "errs", "packets", "errs", "colls");
I 16
	if (dflag)
		printf("%5.5s ", "drops");
E 16
	if (lastif - iftot > 0)
D 14
		printf("%-7.7s %-5.5s %-7.7s %-5.5s %-5.5s ",
E 14
I 14
D 16
		printf("%8.8s %5.5s %8.8s %5.5s %5.5s ",
E 16
I 16
		printf(" %8.8s %5.5s %8.8s %5.5s %5.5s",
E 16
E 14
			"packets", "errs", "packets", "errs", "colls");
I 16
	if (dflag)
		printf(" %5.5s", "drops");
E 16
	putchar('\n');
	fflush(stdout);
	line = 0;
loop:
	sum->ift_ip = 0;
	sum->ift_ie = 0;
	sum->ift_op = 0;
	sum->ift_oe = 0;
	sum->ift_co = 0;
I 16
	sum->ift_dr = 0;
E 16
	for (off = firstifnet, ip = iftot; off && ip < lastif; ip++) {
		klseek(kmem, off, 0);
D 12
		read(kmem, &ifnet, sizeof ifnet);
E 12
I 12
		read(kmem, (char *)&ifnet, sizeof ifnet);
E 12
D 16
		if (ip == interesting)
D 14
			printf("%-7d %-5d %-7d %-5d %-5d ",
E 14
I 14
			printf("%8d %5d %8d %5d %5d ",
E 16
I 16
		if (ip == interesting) {
			printf("%8d %5d %8d %5d %5d",
E 16
E 14
				ifnet.if_ipackets - ip->ift_ip,
				ifnet.if_ierrors - ip->ift_ie,
				ifnet.if_opackets - ip->ift_op,
				ifnet.if_oerrors - ip->ift_oe,
				ifnet.if_collisions - ip->ift_co);
I 16
			if (dflag)
				printf(" %5d",
				    ifnet.if_snd.ifq_drops - ip->ift_dr);
		}
E 16
		ip->ift_ip = ifnet.if_ipackets;
		ip->ift_ie = ifnet.if_ierrors;
		ip->ift_op = ifnet.if_opackets;
		ip->ift_oe = ifnet.if_oerrors;
		ip->ift_co = ifnet.if_collisions;
I 16
		ip->ift_dr = ifnet.if_snd.ifq_drops;
E 16
		sum->ift_ip += ip->ift_ip;
		sum->ift_ie += ip->ift_ie;
		sum->ift_op += ip->ift_op;
		sum->ift_oe += ip->ift_oe;
		sum->ift_co += ip->ift_co;
I 16
		sum->ift_dr += ip->ift_dr;
E 16
		off = (off_t) ifnet.if_next;
	}
D 16
	if (lastif - iftot > 0)
D 14
		printf("%-7d %-5d %-7d %-5d %-5d\n",
E 14
I 14
		printf("%8d %5d %8d %5d %5d ",
E 16
I 16
	if (lastif - iftot > 0) {
		printf("  %8d %5d %8d %5d %5d",
E 16
E 14
			sum->ift_ip - total->ift_ip,
			sum->ift_ie - total->ift_ie,
			sum->ift_op - total->ift_op,
			sum->ift_oe - total->ift_oe,
			sum->ift_co - total->ift_co);
I 16
		if (dflag)
			printf(" %5d", sum->ift_dr - total->ift_dr);
	}
E 16
	*total = *sum;
I 14
	putchar('\n');
E 14
	fflush(stdout);
	line++;
D 12
	if (interval)
		sleep(interval);
E 12
I 12
	oldmask = sigblock(sigmask(SIGALRM));
	if (! signalled) {
		sigpause(0);
	}
	sigsetmask(oldmask);
	signalled = NO;
	(void)alarm(interval);
E 12
	if (line == 21)
		goto banner;
	goto loop;
	/*NOTREACHED*/
I 12
}

/*
 * Called if an interval expires before sidewaysintpr has completed a loop.
 * Sets a flag to not wait for the alarm.
 */
catchalarm()
{
	signalled = YES;
E 12
E 2
}
E 1
