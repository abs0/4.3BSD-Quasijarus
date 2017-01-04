h07283
s 00011/00004/00524
d D 5.9 87/12/26 12:44:01 bostic 24 23
c fix external declarations for ANSI C; minor reformats
e
s 00014/00014/00514
d D 5.8 87/10/22 10:44:21 bostic 23 22
c ANSI C; sprintf now returns an int.
e
s 00002/00002/00526
d D 5.7 87/09/11 10:24:34 bostic 22 21
c initialize variable "i"; bug report tahoe/ucb/4
e
s 00169/00069/00359
d D 5.6 86/06/05 22:34:12 karels 21 20
c print ns routes sensibly
e
s 00113/00044/00315
d D 5.5 86/04/24 12:43:29 karels 20 19
c new -n flag (as expected this time), allow subnet names
c to be found, new syntax for forcing host or net, take net numbers
c without trailing 0's
e
s 00020/00003/00339
d D 5.4 86/02/18 16:28:29 karels 19 17
c minor cleanups
e
s 00002/00001/00341
d R 5.4 86/02/18 14:31:01 karels 18 17
c minor fixes
e
s 00012/00012/00330
d D 5.3 86/02/13 11:26:46 karels 17 16
c hacks to avoid calling nameserver if not running
e
s 00059/00023/00283
d D 5.2 86/01/30 19:41:23 karels 16 15
c try alternate addresses if primaries fail; explain as needed
e
s 00014/00002/00292
d D 5.1 85/06/04 16:44:59 dist 15 14
c Add copyright
e
s 00030/00049/00264
d D 4.14 85/06/03 09:33:59 karels 14 13
c remove broken subnet stuff, allow specification of host or net instead
e
s 00017/00007/00296
d D 4.13 84/10/31 11:19:41 karels 13 12
c get rthashsize from kernel
e
s 00003/00002/00300
d D 4.12 84/10/15 14:56:53 karels 12 11
c watch those null pointers
e
s 00003/00000/00299
d D 4.11 84/05/17 11:20:00 karels 11 10
c subnet fix
e
s 00006/00006/00293
d D 4.10 84/05/16 16:31:45 karels 10 9
c use net rather than host if both named the same
e
s 00069/00020/00230
d D 4.9 84/05/11 12:31:27 karels 9 8
c grok subnets
e
s 00006/00001/00244
d D 4.8 83/08/21 16:10:13 sam 8 7
c add pseudonym for default
e
s 00129/00012/00116
d D 4.7 83/05/05 11:09:23 sam 7 6
c add -f flag to flush tables of all gateway entries
e
s 00025/00009/00103
d D 4.6 83/01/06 23:56:19 sam 6 5
c fix it up for real
e
s 00002/00002/00110
d D 4.5 82/11/15 18:32:18 sam 5 4
c convert socket call to 4.1c
e
s 00004/00002/00108
d D 4.4 82/11/14 15:09:55 sam 4 3
c convert to 4.1c sys calls and directory layout
e
s 00014/00030/00096
d D 4.3 82/10/07 23:54:31 sam 3 2
c convert to new data base routines
e
s 00030/00008/00096
d D 4.2 82/08/19 17:38:05 sam 2 1
c update 
e
s 00104/00000/00000
d D 4.1 82/04/02 10:29:02 wnj 1 0
c date and time created 82/04/02 10:29:02 by wnj
e
u
U
t
T
I 15
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 15
I 1
#ifndef lint
D 8
static char sccsid[] = "%W% %E%";
E 8
I 8
D 15
static char sccsid[] = "%W% (Berkeley) %E%";
E 8
#endif
E 15
I 15
char copyright[] =
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 15

D 4
#include <stdio.h>
E 4
D 20
#include <sys/types.h>
E 20
I 20
#include <sys/param.h>
E 20
#include <sys/socket.h>
#include <sys/ioctl.h>
I 7
#include <sys/mbuf.h>
E 7
I 4

I 7
D 13
#define	KERNEL
E 13
E 7
E 4
#include <net/route.h>
D 4
#include <net/in.h>
E 4
I 4
#include <netinet/in.h>
I 21
#include <netns/ns.h>
E 21

#include <stdio.h>
E 4
#include <errno.h>
#include <ctype.h>
I 3
#include <netdb.h>
E 3

struct	rtentry route;
D 14
int	options;
E 14
int	s;
I 14
D 20
int	forcehost, forcenet;
E 20
I 20
int	forcehost, forcenet, doflush, nflag;
E 20
E 14
struct	sockaddr_in sin = { AF_INET };
I 6
struct	in_addr inet_makeaddr();
I 19
char	*malloc();
E 19
E 6

main(argc, argv)
	int argc;
	char *argv[];
{

	if (argc < 2)
D 7
		printf("usage: route [ cmd ] [ args ]\n"), exit(1);
E 7
I 7
D 14
		printf("usage: route [ -f ] [ cmd args ]\n"), exit(1);
E 14
I 14
D 20
		printf("usage: route [ -f ] [ [ -h ] [ -n ] cmd args ]\n"),
E 20
I 20
		printf("usage: route [ -n ] [ -f ] [ cmd [ net | host ] args ]\n"),
E 20
		exit(1);
E 14
E 7
D 5
	s = socket(SOCK_RAW, 0, 0, options);
E 5
I 5
D 13
	s = socket(AF_INET, SOCK_RAW, 0, 0);
E 13
I 13
	s = socket(AF_INET, SOCK_RAW, 0);
E 13
E 5
	if (s < 0) {
D 5
		perror("socket");
E 5
I 5
		perror("route: socket");
E 5
		exit(1);
	}
	argc--, argv++;
D 7
	if (strcmp(*argv, "add") == 0)
		newroute(argc, argv);
	else if (strcmp(*argv, "delete") == 0)
		newroute(argc, argv);
	else if (strcmp(*argv, "change") == 0)
		changeroute(argc-1, argv+1);
	else
		printf("%s: huh?\n", *argv);
E 7
I 7
D 14
	if (strcmp(*argv, "-f") == 0) {
		argc--, argv++;
		flushroutes();
E 14
I 14
	for (; argc >  0 && argv[0][0] == '-'; argc--, argv++) {
		for (argv[0]++; *argv[0]; argv[0]++)
			switch (*argv[0]) {
			case 'f':
D 20
				flushroutes();
E 20
I 20
				doflush++;
E 20
				break;
D 20
			case 'h':
				forcehost++;
				break;
E 20
			case 'n':
D 20
				forcenet++;
E 20
I 20
				nflag++;
E 20
				break;
			}
E 14
	}
I 14
D 20
	if (forcehost && forcenet) {
		fprintf(stderr, "-n and -h are incompatible\n");
		exit(1);
	}
E 20
I 20
	if (doflush)
		flushroutes();
E 20
E 14
	if (argc > 0) {
		if (strcmp(*argv, "add") == 0)
			newroute(argc, argv);
		else if (strcmp(*argv, "delete") == 0)
			newroute(argc, argv);
		else if (strcmp(*argv, "change") == 0)
			changeroute(argc-1, argv+1);
		else
			printf("%s: huh?\n", *argv);
	}
E 7
}

I 7
/*
 * Purge all entries in the routing tables not
 * associated with network interfaces.
 */
#include <nlist.h>

struct nlist nl[] = {
#define	N_RTHOST	0
	{ "_rthost" },
#define	N_RTNET		1
	{ "_rtnet" },
I 13
#define N_RTHASHSIZE	2
	{ "_rthashsize" },
E 13
	"",
};

flushroutes()
{
	struct mbuf mb;
	register struct rtentry *rt;
	register struct mbuf *m;
D 13
	struct mbuf *routehash[RTHASHSIZ];
	int i, doinghost = 1, kmem;
E 13
I 13
	struct mbuf **routehash;
	int rthashsize, i, doinghost = 1, kmem;
E 13
D 20
	char *routename();
E 20
I 20
	char *routename(), *netname();
E 20

	nlist("/vmunix", nl);
	if (nl[N_RTHOST].n_value == 0) {
		printf("route: \"rthost\", symbol not in namelist\n");
		exit(1);
	}
	if (nl[N_RTNET].n_value == 0) {
		printf("route: \"rtnet\", symbol not in namelist\n");
		exit(1);
	}
I 13
	if (nl[N_RTHASHSIZE].n_value == 0) {
		printf("route: \"rthashsize\", symbol not in namelist\n");
		exit(1);
	}
E 13
	kmem = open("/dev/kmem", 0);
	if (kmem < 0) {
		perror("route: /dev/kmem");
		exit(1);
	}
I 13
	lseek(kmem, nl[N_RTHASHSIZE].n_value, 0);
	read(kmem, &rthashsize, sizeof (rthashsize));
	routehash = (struct mbuf **)malloc(rthashsize*sizeof (struct mbuf *));

E 13
	lseek(kmem, nl[N_RTHOST].n_value, 0);
D 13
	read(kmem, routehash, sizeof (routehash));
E 13
I 13
	read(kmem, routehash, rthashsize*sizeof (struct mbuf *));
E 13
	printf("Flushing routing tables:\n");
again:
D 13
	for (i = 0; i < RTHASHSIZ; i++) {
E 13
I 13
	for (i = 0; i < rthashsize; i++) {
E 13
		if (routehash[i] == 0)
			continue;
		m = routehash[i];
		while (m) {
			lseek(kmem, m, 0);
			read(kmem, &mb, sizeof (mb));
			rt = mtod(&mb, struct rtentry *);
			if (rt->rt_flags & RTF_GATEWAY) {
D 21
				struct sockaddr_in *sin;

				sin = (struct sockaddr_in *)&rt->rt_dst;
D 20
				printf("%-15.15s ", routename(sin->sin_addr));
E 20
I 20
				printf("%-15.15s ", doinghost ?
				    routename(sin->sin_addr) :
				    netname(sin->sin_addr));
E 20
				sin = (struct sockaddr_in *)&rt->rt_gateway;
				printf("%-15.15s ", routename(sin->sin_addr));
E 21
I 21
				printf("%-20.20s ", doinghost ?
				    routename(&rt->rt_dst) :
				    netname(&rt->rt_dst));
				printf("%-20.20s ", routename(&rt->rt_gateway));
E 21
				if (ioctl(s, SIOCDELRT, (caddr_t)rt) < 0)
					error("delete");
				else
					printf("done\n");
			}
			m = mb.m_next;
		}
	}
	if (doinghost) {
		lseek(kmem, nl[N_RTNET].n_value, 0);
D 13
		read(kmem, routehash, sizeof (routehash));
E 13
I 13
		read(kmem, routehash, rthashsize*sizeof (struct mbuf *));
E 13
		doinghost = 0;
		goto again;
	}
	close(kmem);
I 13
	free(routehash);
E 13
}

char *
D 21
routename(in)
	struct in_addr in;
E 21
I 21
routename(sa)
	struct sockaddr *sa;
E 21
{
D 20
	char *cp = 0;
E 20
I 20
	register char *cp;
E 20
	static char line[50];
D 9
	int lna, net;
E 9
I 9
	struct hostent *hp;
D 20
	struct netent *np;
D 14
	int lna, net, subnet;
E 14
I 14
	int lna, net;
I 17
	static int bynumber;
E 20
I 20
	static char domain[MAXHOSTNAMELEN + 1];
	static int first = 1;
	char *index();
I 21
	char *ns_print();
E 21
E 20
E 17
E 14
E 9

D 20
	net = inet_netof(in);
I 9
D 14
	subnet = inet_subnetof(in);
E 14
E 9
	lna = inet_lnaof(in);
E 20
I 20
	if (first) {
		first = 0;
		if (gethostname(domain, MAXHOSTNAMELEN) == 0 &&
		    (cp = index(domain, '.')))
			(void) strcpy(domain, cp + 1);
		else
			domain[0] = 0;
	}
D 21
	cp = 0;
E 20
D 14
	if (lna == INADDR_ANY) {
E 14
I 14
	if (in.s_addr == INADDR_ANY)
		cp = "default";
D 20
	if (cp == 0 && (lna == INADDR_ANY || forcenet)) {
E 14
D 9
		struct netent *np = getnetbyaddr(net, AF_INET);

E 9
I 9
		np = getnetbyaddr(net, AF_INET);
E 9
		if (np)
			cp = np->n_name;
D 9
	} else {
		struct hostent *hp;
E 9
I 9
D 14
		else if (net == 0)
			cp = "default";
	} else if ((subnet != net) && ((lna & 0xff) == 0) &&
	    (np = getnetbyaddr(subnet, AF_INET))) {
		struct in_addr subnaddr, inet_makeaddr();
E 9

D 9
		hp = gethostbyaddr(&in, sizeof (struct in_addr),
			AF_INET);
E 9
I 9
		subnaddr = inet_makeaddr(subnet, INADDR_ANY);
		if (bcmp(&in, &subnaddr, sizeof(in)) == 0)
			cp = np->n_name;
I 11
		else
			goto host;
E 11
	} else {
I 11
host:
E 14
I 14
	}
D 17
	if (cp == 0) {
E 17
I 17
	if (cp == 0 && bynumber == 0) {
E 17
E 14
E 11
		hp = gethostbyaddr(&in, sizeof (struct in_addr), AF_INET);
E 9
		if (hp)
E 20
I 20
	if (cp == 0 && !nflag) {
		hp = gethostbyaddr(&in, sizeof (struct in_addr),
			AF_INET);
		if (hp) {
			if ((cp = index(hp->h_name, '.')) &&
			    !strcmp(cp + 1, domain))
				*cp = 0;
E 20
			cp = hp->h_name;
E 21
I 21
	switch (sa->sa_family) {

	case AF_INET:
	    {	struct in_addr in;
		in = ((struct sockaddr_in *)sa)->sin_addr;

		cp = 0;
		if (in.s_addr == INADDR_ANY)
			cp = "default";
		if (cp == 0 && !nflag) {
			hp = gethostbyaddr(&in, sizeof (struct in_addr),
				AF_INET);
			if (hp) {
				if ((cp = index(hp->h_name, '.')) &&
				    !strcmp(cp + 1, domain))
					*cp = 0;
				cp = hp->h_name;
			}
E 21
I 17
D 20
		else if (h_errno == TRY_AGAIN)
			bynumber = 1;
E 20
I 20
		}
E 20
E 17
D 21
	}
	if (cp)
		strcpy(line, cp);
	else {
E 21
I 21
		if (cp)
			strcpy(line, cp);
		else {
E 21
D 20
		u_char *ucp = (u_char *)&in;
		if (lna == INADDR_ANY)
			sprintf(line, "%u.%u.%u", ucp[0], ucp[1], ucp[2]);
		else
			sprintf(line, "%u.%u.%u.%u", ucp[0], ucp[1],
				ucp[2], ucp[3]);
E 20
I 20
#define C(x)	((x) & 0xff)
D 21
		in.s_addr = ntohl(in.s_addr);
		sprintf(line, "%u.%u.%u.%u", C(in.s_addr >> 24),
			C(in.s_addr >> 16), C(in.s_addr >> 8), C(in.s_addr));
E 21
I 21
			in.s_addr = ntohl(in.s_addr);
D 23
			sprintf(line, "%u.%u.%u.%u", C(in.s_addr >> 24),
E 23
I 23
			(void)sprintf(line, "%u.%u.%u.%u", C(in.s_addr >> 24),
E 23
			   C(in.s_addr >> 16), C(in.s_addr >> 8), C(in.s_addr));
		}
		break;
	    }

	case AF_NS:
		return (ns_print((struct sockaddr_ns *)sa));

	default:
	    {	u_short *s = (u_short *)sa->sa_data;

D 23
		sprintf(line, "af %d: %x %x %x %x %x %x %x", sa->sa_family,
			s[0], s[1], s[2], s[3], s[4], s[5], s[6]);
E 23
I 23
		(void)sprintf(line, "af %d: %x %x %x %x %x %x %x",
		    sa->sa_family, s[0], s[1], s[2], s[3], s[4], s[5], s[6]);
E 23
		break;
	    }
E 21
E 20
	}
	return (line);
}

I 20
/*
 * Return the name of the network whose address is given.
 * The address is assumed to be that of a net or subnet, not a host.
 */
char *
D 21
netname(in)
	struct in_addr in;
E 21
I 21
netname(sa)
	struct sockaddr *sa;
E 21
{
	char *cp = 0;
	static char line[50];
	struct netent *np = 0;
	u_long net, mask;
D 22
	register i;
E 22
I 22
	register u_long i;
E 22
	int subnetshift;
I 24
	char *ns_print();
E 24

D 21
	in.s_addr = ntohl(in.s_addr);
	if (in.s_addr == 0)
		cp = "default";
	else if (!nflag) {
		if (IN_CLASSA(i)) {
			mask = IN_CLASSA_NET;
			subnetshift = 8;
		} else if (IN_CLASSB(i)) {
			mask = IN_CLASSB_NET;
			subnetshift = 8;
		} else {
			mask = IN_CLASSC_NET;
			subnetshift = 4;
E 21
I 21
	switch (sa->sa_family) {

	case AF_INET:
	    {	struct in_addr in;
		in = ((struct sockaddr_in *)sa)->sin_addr;

D 22
		in.s_addr = ntohl(in.s_addr);
E 22
I 22
		i = in.s_addr = ntohl(in.s_addr);
E 22
		if (in.s_addr == 0)
			cp = "default";
		else if (!nflag) {
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
			/*
			 * If there are more bits than the standard mask
			 * would suggest, subnets must be in use.
			 * Guess at the subnet mask, assuming reasonable
			 * width subnet fields.
			 */
			while (in.s_addr &~ mask)
				mask = (long)mask >> subnetshift;
			net = in.s_addr & mask;
			while ((mask & 1) == 0)
				mask >>= 1, net >>= 1;
			np = getnetbyaddr(net, AF_INET);
			if (np)
				cp = np->n_name;
E 21
		}
D 21
		/*
		 * If there are more bits than the standard mask
		 * would suggest, subnets must be in use.
		 * Guess at the subnet mask, assuming reasonable
		 * width subnet fields.
		 */
		while (in.s_addr &~ mask)
			mask = (long)mask >> subnetshift;
		net = in.s_addr & mask;
		while ((mask & 1) == 0)
			mask >>= 1, net >>= 1;
		np = getnetbyaddr(net, AF_INET);
		if (np)
			cp = np->n_name;
E 21
I 21
		if (cp)
			strcpy(line, cp);
		else if ((in.s_addr & 0xffffff) == 0)
D 23
			sprintf(line, "%u", C(in.s_addr >> 24));
E 23
I 23
			(void)sprintf(line, "%u", C(in.s_addr >> 24));
E 23
		else if ((in.s_addr & 0xffff) == 0)
D 23
			sprintf(line, "%u.%u", C(in.s_addr >> 24),
E 23
I 23
			(void)sprintf(line, "%u.%u", C(in.s_addr >> 24),
E 23
			    C(in.s_addr >> 16));
		else if ((in.s_addr & 0xff) == 0)
D 23
			sprintf(line, "%u.%u.%u", C(in.s_addr >> 24),
E 23
I 23
			(void)sprintf(line, "%u.%u.%u", C(in.s_addr >> 24),
E 23
			    C(in.s_addr >> 16), C(in.s_addr >> 8));
		else
D 23
			sprintf(line, "%u.%u.%u.%u", C(in.s_addr >> 24),
E 23
I 23
			(void)sprintf(line, "%u.%u.%u.%u", C(in.s_addr >> 24),
E 23
			    C(in.s_addr >> 16), C(in.s_addr >> 8),
			    C(in.s_addr));
		break;
	    }

	case AF_NS:
		return (ns_print((struct sockaddr_ns *)sa));
		break;

	default:
	    {	u_short *s = (u_short *)sa->sa_data;

D 23
		sprintf(line, "af %d: %x %x %x %x %x %x %x", sa->sa_family,
			s[0], s[1], s[2], s[3], s[4], s[5], s[6]);
E 23
I 23
		(void)sprintf(line, "af %d: %x %x %x %x %x %x %x",
		    sa->sa_family, s[0], s[1], s[2], s[3], s[4], s[5], s[6]);
E 23
		break;
	    }
E 21
	}
D 21
	if (cp)
		strcpy(line, cp);
	else if ((in.s_addr & 0xffffff) == 0)
		sprintf(line, "%u", C(in.s_addr >> 24));
	else if ((in.s_addr & 0xffff) == 0)
		sprintf(line, "%u.%u", C(in.s_addr >> 24) , C(in.s_addr >> 16));
	else if ((in.s_addr & 0xff) == 0)
		sprintf(line, "%u.%u.%u", C(in.s_addr >> 24),
			C(in.s_addr >> 16), C(in.s_addr >> 8));
	else
		sprintf(line, "%u.%u.%u.%u", C(in.s_addr >> 24),
			C(in.s_addr >> 16), C(in.s_addr >> 8), C(in.s_addr));
E 21
	return (line);
}

E 20
E 7
newroute(argc, argv)
	int argc;
	char *argv[];
{
	struct sockaddr_in *sin;
D 16
	char *cmd;
I 9
D 12
	int ishost;
E 12
I 12
	int ishost, metric = 0;
E 16
I 16
	char *cmd, *dest, *gateway;
	int ishost, metric = 0, ret, attempts, oerrno;
	struct hostent *hp;
	extern int errno;
E 16
E 12
E 9

D 2
	if (argc < 3) {
		printf("usage: %s destination gateway\n", argv[0]);
E 2
I 2
D 9
	if (argc < 3 || argc > 4) {
		printf("usage: %s destination gateway [ metric ]\n", argv[0]);
E 2
		return;
	}
E 9
D 2
	cmd = *argv++;
	getaddr(*argv++, &route.rt_dst);
	getaddr(*argv, &route.rt_gateway);
E 2
I 2
	cmd = argv[0];
I 20
	if ((strcmp(argv[1], "host")) == 0) {
		forcehost++;
		argc--, argv++;
	} else if ((strcmp(argv[1], "net")) == 0) {
		forcenet++;
		argc--, argv++;
	}
E 20
D 9
	getaddr(argv[1], &route.rt_dst);
	getaddr(argv[2], &route.rt_gateway);
E 9
I 9
	if (*cmd == 'a') {
		if (argc != 4) {
			printf("usage: %s destination gateway metric\n", cmd);
			printf("(metric of 0 if gateway is this host)\n");
			return;
		}
I 12
		metric = atoi(argv[3]);
E 12
	} else {
D 19
		if (argc != 3) {
E 19
I 19
		if (argc < 3) {
E 19
			printf("usage: %s destination gateway\n", cmd);
			return;
		}
	}
D 16
	ishost = getaddr(argv[1], &route.rt_dst);
E 16
I 16
	sin = (struct sockaddr_in *)&route.rt_dst;
D 17
	ishost = getaddr(argv[1], &route.rt_dst, &hp);
	if (hp)
		dest = hp->h_name;
	else
		dest = routename(sin->sin_addr);
E 17
I 17
D 20
	ishost = getaddr(argv[1], &route.rt_dst, &hp, &dest);
E 20
I 20
	ishost = getaddr(argv[1], &route.rt_dst, &hp, &dest, forcenet);
E 20
E 17
E 16
I 14
	if (forcehost)
		ishost = 1;
	if (forcenet)
		ishost = 0;
E 14
D 16
	(void) getaddr(argv[2], &route.rt_gateway);
E 9
E 2
	sin = (struct sockaddr_in *)&route.rt_dst;
E 16
I 16
	sin = (struct sockaddr_in *)&route.rt_gateway;
D 17
	(void) getaddr(argv[2], &route.rt_gateway, &hp);
	if (hp)
		gateway = hp->h_name;
	else
		gateway = routename(sin->sin_addr);
E 17
I 17
D 20
	(void) getaddr(argv[2], &route.rt_gateway, &hp, &gateway);
E 20
I 20
	(void) getaddr(argv[2], &route.rt_gateway, &hp, &gateway, 0);
E 20
E 17
E 16
	route.rt_flags = RTF_UP;
D 2
	if (sin->sin_addr.s_host || sin->sin_addr.s_imp)
E 2
I 2
D 3
	if (in_lnaof(sin->sin_addr) != 0)
E 3
I 3
D 9
	if (inet_lnaof(sin->sin_addr) != 0)
E 9
I 9
	if (ishost)
E 9
E 3
E 2
		route.rt_flags |= RTF_HOST;
D 2
	printf("%s %x: gateway %x\n", cmd, sin->sin_addr,
		((struct sockaddr_in *)&route.rt_gateway)->sin_addr);
E 2
I 2
D 9
	if (argc > 3 && atoi(argv[3]) > 0)
E 9
I 9
D 12
	if (atoi(argv[3]) > 0)
E 12
I 12
	if (metric > 0)
E 12
E 9
		route.rt_flags |= RTF_GATEWAY;
D 7
	printf("%s %x: gateway %x, flags %x\n", cmd, sin->sin_addr,
		((struct sockaddr_in *)&route.rt_gateway)->sin_addr,
		route.rt_flags);
E 7
I 7
D 16
	printf("%s %s: gateway ", cmd, routename(sin->sin_addr));
	sin = (struct sockaddr_in *)&route.rt_gateway;
	printf("%s, flags %x\n", routename(sin->sin_addr), route.rt_flags);
E 7
E 2
	if (ioctl(s, *cmd == 'a' ? SIOCADDRT : SIOCDELRT, (caddr_t)&route))
		error(cmd);
E 16
I 16
	for (attempts = 1; ; attempts++) {
		errno = 0;
		if ((ret = ioctl(s, *cmd == 'a' ? SIOCADDRT : SIOCDELRT,
		     (caddr_t)&route)) == 0)
			break;
		if (errno != ENETUNREACH && errno != ESRCH)
			break;
		if (hp && hp->h_addr_list[1]) {
			hp->h_addr_list++;
			bcopy(hp->h_addr_list[0], (caddr_t)&sin->sin_addr,
			    hp->h_length);
		} else
			break;
	}
	oerrno = errno;
	printf("%s %s %s: gateway %s", cmd, ishost? "host" : "net",
		dest, gateway);
	if (attempts > 1 && ret == 0)
	    printf(" (%s)",
		inet_ntoa(((struct sockaddr_in *)&route.rt_gateway)->sin_addr));
	if (ret == 0)
		printf("\n");
	else {
		printf(": ");
		fflush(stdout);
		errno = oerrno;
		error(0);
	}
E 16
}

changeroute(argc, argv)
	int argc;
	char *argv[];
{
	printf("not supported\n");
}

error(cmd)
	char *cmd;
{
I 24
	extern int errno;
E 24
D 16
	extern int errno;
E 16

D 24
	if (errno == ESRCH)
E 24
I 24
	switch(errno) {
	case ESRCH:
E 24
		fprintf(stderr, "not in table\n");
D 24
	else if (errno == EBUSY)
E 24
I 24
		break;
	case EBUSY:
E 24
		fprintf(stderr, "entry in use\n");
D 24
	else if (errno == ENOBUFS)
E 24
I 24
		break;
	case ENOBUFS:
E 24
		fprintf(stderr, "routing table overflow\n");
D 24
	else
E 24
I 24
		break;
	default:
E 24
		perror(cmd);
I 24
	}
E 24
}

I 19
char *
savestr(s)
	char *s;
{
	char *sav;

	sav = malloc(strlen(s) + 1);
	if (sav == NULL) {
		fprintf("route: out of memory\n");
		exit(1);
	}
	strcpy(sav, s);
	return (sav);
}

E 19
I 9
/*
 * Interpret an argument as a network address of some kind,
 * returning 1 if a host address, 0 if a network address.
 */
E 9
D 16
getaddr(s, sin)
E 16
I 16
D 17
getaddr(s, sin, hpp)
E 17
I 17
D 20
getaddr(s, sin, hpp, name)
E 20
I 20
getaddr(s, sin, hpp, name, isnet)
E 20
E 17
E 16
	char *s;
	struct sockaddr_in *sin;
I 16
	struct hostent **hpp;
I 17
	char **name;
I 20
	int isnet;
E 20
E 17
E 16
{
D 3
	sin->sin_family = AF_INET;
	if ((sin->sin_addr.s_addr = rhost(&s)) != -1)
E 3
I 3
	struct hostent *hp;
I 6
	struct netent *np;
	u_long val;
E 6

I 16
	*hpp = 0;
E 16
I 8
	if (strcmp(s, "default") == 0) {
		sin->sin_family = AF_INET;
		sin->sin_addr = inet_makeaddr(0, INADDR_ANY);
I 19
		*name = "default";
E 19
D 9
		return;
E 9
I 9
		return(0);
E 9
	}
I 16
	sin->sin_family = AF_INET;
D 20
	val = inet_addr(s);
	if (val != -1) {
		sin->sin_addr.s_addr = val;
I 17
		*name = s;
E 17
		return(inet_lnaof(sin->sin_addr) != INADDR_ANY);
E 20
I 20
	if (isnet == 0) {
		val = inet_addr(s);
		if (val != -1) {
			sin->sin_addr.s_addr = val;
			*name = s;
			return(inet_lnaof(sin->sin_addr) != INADDR_ANY);
		}
E 20
	}
	val = inet_network(s);
	if (val != -1) {
		sin->sin_addr = inet_makeaddr(val, INADDR_ANY);
I 17
		*name = s;
E 17
		return(0);
	}
E 16
E 8
D 10
	hp = gethostbyname(s);
D 6
	if (hp == 0) {
		sin->sin_addr.s_addr = inet_addr(s);
		if (sin->sin_addr.s_addr == -1) {
			fprintf(stderr, "%s: bad value\n", s);
			exit(1);
		}
		sin->sin_family = AF_INET;
E 6
I 6
	if (hp) {
		sin->sin_family = hp->h_addrtype;
		bcopy(hp->h_addr, &sin->sin_addr, hp->h_length);
E 6
E 3
D 9
		return;
E 9
I 9
		return(1);
E 9
D 3
	if (!isdigit(*s)) {
		fprintf(stderr, "%s: unknown host\n", s);
		exit(1);
E 3
	}
E 10
D 3
	sin->sin_addr.s_addr = atoi(s);
	if (sin->sin_addr.s_addr == -1) {
		fprintf(stderr, "%s: bad value\n", s);
		exit(1);
	}
I 2
}

/*
 * Return the local network address portion of an
 * internet address; handles class a/b/c network
 * number formats.
 */
in_lnaof(in)
	struct in_addr in;
{
#if vax || pdp11
#define	IN_LNAOF(in) \
	(((in).s_addr&IN_CLASSA) == 0 ? (in).s_addr&IN_CLASSA_LNA : \
		((in).s_addr&IN_CLASSB) == 0 ? (in).s_addr&IN_CLASSB_LNA : \
			(in).s_addr&IN_CLASSC_LNA)
	return ((int)htonl((u_long)IN_LNAOF(in)));
#else
	return (IN_LNAOF(in));
#endif
E 3
I 3
D 6
	sin->sin_family = hp->h_addrtype;
	bcopy(hp->h_addr, &sin->sin_addr, hp->h_length);
E 6
I 6
	np = getnetbyname(s);
	if (np) {
		sin->sin_family = np->n_addrtype;
		sin->sin_addr = inet_makeaddr(np->n_net, INADDR_ANY);
I 17
D 19
		*name = np->n_name;
E 19
I 19
		*name = savestr(np->n_name);
E 19
E 17
D 9
		return;
E 9
I 9
		return(0);
I 10
	}
	hp = gethostbyname(s);
	if (hp) {
I 16
		*hpp = hp;
E 16
		sin->sin_family = hp->h_addrtype;
		bcopy(hp->h_addr, &sin->sin_addr, hp->h_length);
I 17
D 19
		*name = hp->h_name;
E 19
I 19
		*name = savestr(hp->h_name);
E 19
E 17
		return(1);
E 10
E 9
D 16
	}
	sin->sin_family = AF_INET;
	val = inet_addr(s);
	if (val != -1) {
		sin->sin_addr.s_addr = val;
D 9
		return;
E 9
I 9
		return(inet_lnaof(sin->sin_addr) != INADDR_ANY);
E 9
	}
	val = inet_network(s);
	if (val != -1) {
		sin->sin_addr = inet_makeaddr(val, INADDR_ANY);
D 9
		return;
E 9
I 9
		return(0);
E 16
E 9
	}
	fprintf(stderr, "%s: bad value\n", s);
	exit(1);
I 21
}

short ns_nullh[] = {0,0,0};
short ns_bh[] = {-1,-1,-1};

char *
ns_print(sns)
struct sockaddr_ns *sns;
{
	struct ns_addr work;
	union { union ns_net net_e; u_long long_e; } net;
	u_short port;
	static char mybuf[50], cport[10], chost[25];
	char *host = "";
	register char *p; register u_char *q; u_char *q_lim;

	work = sns->sns_addr;
	port = ntohs(work.x_port);
	work.x_port = 0;
	net.net_e  = work.x_net;
	if (ns_nullhost(work) && net.long_e == 0) {
		if (port ) {
D 23
			sprintf(mybuf, "*.%xH", port);
E 23
I 23
			(void)sprintf(mybuf, "*.%xH", port);
E 23
			upHex(mybuf);
		} else
D 23
			sprintf(mybuf, "*.*");
E 23
I 23
			(void)sprintf(mybuf, "*.*");
E 23
		return (mybuf);
	}

	if (bcmp(ns_bh, work.x_host.c_host, 6) == 0) { 
		host = "any";
	} else if (bcmp(ns_nullh, work.x_host.c_host, 6) == 0) {
		host = "*";
	} else {
		q = work.x_host.c_host;
D 23
		sprintf(chost, "%02x%02x%02x%02x%02x%02xH",
E 23
I 23
		(void)sprintf(chost, "%02x%02x%02x%02x%02x%02xH",
E 23
			q[0], q[1], q[2], q[3], q[4], q[5]);
		for (p = chost; *p == '0' && p < chost + 12; p++);
		host = p;
	}
	if (port)
D 23
		sprintf(cport, ".%xH", htons(port));
E 23
I 23
		(void)sprintf(cport, ".%xH", htons(port));
E 23
	else
		*cport = 0;

D 23
	sprintf(mybuf,"%xH.%s%s", ntohl(net.long_e), host, cport);
E 23
I 23
	(void)sprintf(mybuf,"%xH.%s%s", ntohl(net.long_e), host, cport);
E 23
	upHex(mybuf);
	return(mybuf);
}

upHex(p0)
char *p0;
{
	register char *p = p0;
	for (; *p; p++) switch (*p) {

	case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
		*p += ('A' - 'a');
	}
E 21
I 9
D 14
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
E 14
E 9
E 6
E 3
E 2
}
E 1
