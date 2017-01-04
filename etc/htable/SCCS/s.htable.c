h00871
s 00010/00005/00592
d D 5.8 88/06/18 14:00:48 bostic 20 19
c install approved copyright notice
e
s 00019/00022/00578
d D 5.7 88/02/23 15:25:44 bostic 19 18
c portability fixes from Bill Nowicki (nowicki@sun.com); add Berkeley
c specific header
e
s 00002/00001/00598
d D 5.6 87/10/22 11:15:42 bostic 18 17
c ANSI C; sprintf now returns an int.
e
s 00001/00000/00598
d D 5.5 86/04/15 08:25:19 bloom 17 16
c add proper return to savegateway() from Mike Muuss (mike@brl.mil)
e
s 00000/00000/00598
d D 5.4 85/07/15 09:51:01 karels 16 15
x 12
c remove .ARPA hack; breaks with domain names
e
s 00006/00000/00594
d D 5.3 85/06/21 19:18:25 mckusick 15 14
c botched copyright
e
s 00001/00001/00593
d D 5.2 85/05/28 14:07:25 dist 14 13
c add copyright
e
s 00007/00001/00587
d D 5.1 85/05/28 13:59:50 dist 13 12
c add copyright
e
s 00002/00000/00586
d D 4.12 84/03/22 20:55:58 karels 12 11
c kludge lower() to stop at first '.', to preserve .ARPA in caps
e
s 00010/00010/00576
d D 4.11 84/02/16 17:24:01 karels 11 10
c allow comments in localgateways file
e
s 00001/00003/00585
d D 4.10 84/02/09 13:04:24 karels 10 9
c don't install gateways to networks we're on
e
s 00009/00008/00579
d D 4.9 84/01/02 21:04:44 karels 9 8
c sigh... network numbers for putnet *all* in host byte order
e
s 00010/00007/00577
d D 4.8 83/12/30 16:59:06 karels 8 7
c putnet arg is in host byte order
e
s 00001/00000/00583
d D 4.7 83/11/03 16:50:09 karels 7 6
c fix addlocal
e
s 00335/00068/00248
d D 4.6 83/11/03 12:21:54 karels 6 5
c calculate connectivity of gateways to find multi-hop gateways;
c read localgateways and use in eliminating dups and gateways remote from them;
c take local nets and connected nets in args, not compiled in.
e
s 00001/00001/00315
d D 4.5 83/06/18 19:04:45 sam 5 4
c correct include order
e
s 00020/00000/00296
d D 4.4 83/05/20 11:17:15 mo 4 3
c added code to copy comment lines to get date stamp from nic file
e
s 00037/00006/00259
d D 4.3 83/05/04 14:32:45 sam 3 2
c make gateways file (partially)
e
s 00161/00034/00104
d D 4.2 82/11/15 01:27:03 sam 2 1
c major reorganization; still doesn't make /etc/gateways correctly
e
s 00138/00000/00000
d D 4.1 82/10/20 21:26:49 sam 1 0
c date and time created 82/10/20 21:26:49 by sam
e
u
U
t
T
I 13
/*
D 14
 * Copyright (c) 1980 Regents of the University of California.
E 14
I 14
 * Copyright (c) 1983 Regents of the University of California.
E 14
D 19
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 19
I 19
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 20
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 20
I 20
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
E 20
E 19
 */

E 13
I 1
#ifndef lint
I 15
char copyright[] =
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
 All rights reserved.\n";
D 19
#endif not lint
E 19
I 19
#endif /* not lint */
E 19

#ifndef lint
E 15
static char sccsid[] = "%W% (Berkeley) %G%";
D 13
#endif
E 13
I 13
D 19
#endif not lint
E 19
I 19
#endif /* not lint */
E 19
E 13

/*
 * htable - convert NIC host table into a UNIX format.
 * NIC format is described in RFC 810, 1 March 1982.
 */
#include <stdio.h>
#include <ctype.h>
D 2
#include "htable.h"
E 2
I 2
#include <errno.h>
I 3
#include <netdb.h>
D 5
#include <sys/socket.h>
E 5

E 3
#include "htable.h"		/* includes <sys/types.h> */
E 2

I 5
#include <sys/socket.h>
E 5
D 2
FILE *hf;
FILE *gf;
E 2
I 2
D 19
#include <netinet/in.h>
E 19
I 19
#include <arpa/inet.h>
E 19
E 2

I 3
D 6
#define	INTERNET	10	/* gag */

E 6
I 4
#define	DATELINES	3	/* these lines usually contain the date */
I 6
#define	MAXNETS		30	/* array size for local, connected nets */
E 6

E 4
E 3
I 2
FILE	*hf;			/* hosts file */
FILE	*gf;			/* gateways file */
FILE	*nf;			/* networks file */
I 6
struct gateway *savegateway(), *gatewayto();
E 6

I 6
int connected_nets[MAXNETS];
int nconnected;
int local_nets[MAXNETS];
int nlocal;
char *myname;

E 6
E 2
main(argc, argv)
	int argc;
	char *argv[];
{
D 6
	if (argc > 2) {
		fprintf(stderr, "usage: %s [ input-file ]\n",
			argv[0]);
		exit(1);
	}
E 6
I 6
	int errs;

E 6
	infile = "(stdin)";
D 6
	if (argc == 2) {
		infile = argv[1];
		if (freopen(infile, "r", stdin) == NULL) {
			perror(infile);
			exit(1);
E 6
I 6
	myname = argv[0];
	argc--;
	argv++;
	while (argc--) {
		if (*argv[0] == '-') {
			switch (argv[0][1]) {
			case 'c':
				nconnected = addlocal(argv[1], connected_nets);
				argv++;
				argc--;
				break;
			case 'l':
				nlocal = addlocal(argv[1], local_nets);
				argv++;
				argc--;
				break;
			default:
				usage();
				/*NOTREACHED*/
			}
		} else {
			infile = argv[0];
			if (freopen(infile, "r", stdin) == NULL) {
				perror(infile);
				exit(1);
			}
E 6
		}
I 6
		argv++;
E 6
	}
	hf = fopen("hosts", "w");
	if (hf == NULL) {
		perror("hosts");
		exit(1);
	}
D 2
	copylocal();
#ifdef GATEWAYS
	hf = fopen("gateways", "w");
	if (hf == NULL) {
E 2
I 2
	copylocal(hf, "localhosts");
	gf = fopen("gateways", "w");
	if (gf == NULL) {
E 2
		perror("gateways");
		exit(1);
	}
D 2
#endif
E 2
I 2
D 6
	copylocal(gf, "localgateways");
E 6
I 6
D 19
	copygateways(gf, "localgateways");
E 19
I 19
	copygateways("localgateways");
E 19
E 6
	nf = fopen("networks", "w");
	if (nf == NULL) {
		perror("networks");
		exit(1);
	}
	copylocal(nf, "localnetworks");
I 4
	copycomments(stdin, hf, DATELINES);
E 4
E 2
D 6
	exit(yyparse());
E 6
I 6
	errs = yyparse();
	dogateways();
	exit(errs);
E 6
}

I 6
usage()
{
	fprintf(stderr,
	"usage: %s [ -c connected-nets ] [-l local-nets ] [ input-file ]\n",
		myname);
	exit(1);
}

/*
 *  Turn a comma-separated list of network names or numbers in dot notation
 *  (e.g.  "arpanet, 128.32") into an array of net numbers.
 */
addlocal(arg, nets)
	char *arg;
	int *nets;
{
	register char *p, c;
	register int nfound = 0;

	do {
		p = arg;
		while (*p && *p != ',' && !isspace(*p))
			p++;
		c = *p;
		*p = 0;
		while (*arg && isspace(*arg))
			arg++;
		if (*arg == 0)
			continue;
		if (nfound == MAXNETS) {
			fprintf(stderr, "%s: Too many networks in list\n",
				myname);
			return (nfound);
		}
		if (getnetaddr(arg, &nets[nfound]))
			nfound++;
		else {
			fprintf(stderr, "%s: %s: unknown network\n",
				myname, arg);
			exit(1);
		}
I 7
		arg = p + 1;
E 7
	} while (c);
	return (nfound);
}

E 6
struct name *
newname(str)
	char *str;
{
	char *p;
	struct name *nm;

	p = malloc(strlen(str) + 1);
	strcpy(p, str);
D 2
	nm = alloc_name();
E 2
I 2
	nm = (struct name *)malloc(sizeof (struct name));
E 2
	nm->name_val = p;
	nm->name_link = NONAME;
	return (nm);
}

char *
lower(str)
	char *str;
{
	register char *cp = str;

	while (*cp) {
		if (isupper(*cp))
			*cp = tolower(*cp);
I 12
		if (*cp == '.')
			break;
E 12
		cp++;
	}
	return (str);
}

do_entry(keyword, addrlist, namelist, cputype, opsys, protos)
	int keyword;
	struct addr *addrlist;
	struct name *namelist, *cputype, *opsys, *protos;
{
	register struct addr *al, *al2;
D 2
	register struct name *nl, *nl2;
	register flag;
E 2
I 2
	register struct name *nl;
I 3
D 6
	struct addr *inetal;
	int count;
E 6
I 6
	struct addr *connect_addr;
	char *cp;
E 6
E 3
E 2

	switch (keyword) {

	case KW_NET:
D 2
		break;
E 2
I 2
		nl = namelist;
		if (nl == NONAME) {
			fprintf(stderr, "htable: net");
D 9
			putnet(stderr, addrlist->addr_val);
E 9
I 9
			putnet(stderr, inet_netof(addrlist->addr_val));
E 9
			fprintf(stderr, " missing names.\n");
			break;
		}
		fprintf(nf, "%-16.16s", lower(nl->name_val));
		al2 = addrlist;
		while (al = al2) {
			char *cp;
E 2

I 2
D 9
			putnet(nf, al->addr_val);
E 9
I 9
			putnet(nf, inet_netof(al->addr_val));
E 9
			cp = "\t%s";
			while (nl = nl->name_link) {
				fprintf(nf, cp, lower(nl->name_val));
				cp = " %s";
			}
			putc('\n', nf);
			al2 = al->addr_link;
			free((char *)al);
		}
D 6
		goto alreadyfree;
E 6
I 6
		break;
E 6

E 2
	case KW_GATEWAY:
I 2
D 3
		for (al = addrlist; al; al = al->addr_link) {
			register int net = inet_netof(al->addr_val);
E 3
I 3
D 6
		/*
		 * Kludge here: take only gateways directly connected to
		 * the Internet.  Should really calculate closure on
		 * connectivity matrix to identify gateways to all networks
		 * described in data base, but that's real work.
		 */
		/* locate Internet address, if one */
E 6
I 6
		/* locate locally connected address, if one */
E 6
		for (al = addrlist; al; al = al->addr_link)
D 6
			if (inet_netof(al->addr_val) == INTERNET)
E 6
I 6
			if (connectedto(inet_netof(al->addr_val)))
E 6
				break;
D 6
		if (al == NULL)
			break;
		inetal = al;
		for (count = 0, al = al->addr_link; al; al = al->addr_link) {
E 6
I 6
		if (al == NULL) {
			/*
			 * Not connected to known networks.  Save for later.
			 */
			struct gateway *gw, *firstgw = (struct gateway *) NULL;

			for (al = addrlist; al; al = al->addr_link) {
				register int net;

				net = inet_netof(al->addr_val);
				gw = savegateway(namelist, net,
				    al->addr_val, 0);
				if (firstgw == (struct gateway *) NULL)
					firstgw = gw;
				gw->g_firstent = firstgw;
			}
			freeaddrs(addrlist);
			goto dontfree;
		}
		/*
		 * Connected to a known network.
		 * Mark this as the gateway to all other networks
		 * that are on the addrlist (unless we already have
		 * gateways to them).
		 */
		connect_addr = al;
		for (al = addrlist; al; al = al->addr_link) {
E 6
			register int net;
D 6
			register struct netent *np;
E 6
E 3

I 3
D 6
			if (al == inetal)
E 6
I 6
D 10
			if (al == connect_addr)
E 6
				continue;
E 10
E 3
			/* suppress duplicates -- not optimal */
I 3
			net = inet_netof(al->addr_val);
E 3
D 6
			if (checkgateway(net))
				break;
I 3
			count++;
E 3
			fprintf(gf, "net ");
D 3
			putnet(gf, net);
E 3
I 3
			np = getnetbyaddr(net, AF_INET);
			if (np)
				fprintf(gf, "%s", np->n_name);
			else
				putnet(gf, net);
E 3
			/* this is a kludge */
D 3
			fprintf(gf, " destination %s metric 1 passive\n",
E 3
I 3
			fprintf(gf, " gateway %s metric 1 passive\n",
E 3
				lower(namelist->name_val));
D 3
			putaddr(hf, al->addr_val);
E 3
I 3
			savegateway(net);
E 6
I 6
D 10
			if (gatewayto(net))
E 10
I 10
			if (connectedto(net) || gatewayto(net))
E 10
				continue;
			printgateway(net, namelist->name_val, 1);
			(void) savegateway(namelist, net, al->addr_val, 1);
E 6
		}
D 6
		if (count > 0) {
			putaddr(hf, inetal->addr_val);
E 3
			fprintf(hf, "%s\t# gateway\n",
				lower(namelist->name_val));
E 6
I 6
		/*
		 * Put the gateway in the hosts file.
		 */
		putaddr(hf, connect_addr->addr_val);
		cp = "%s";
		for (nl = namelist; nl; nl = nl->name_link) {
			fprintf(hf, cp, lower(nl->name_val));
			cp = " %s";
E 6
D 3
			savegateway(net);
E 3
		}
E 2
D 6
		break;
E 6
I 6
		fprintf(hf, "\t# gateway\n");
		freeaddrs(addrlist);
		goto dontfree;
E 6

	case KW_HOST:
D 2
		for (al = addrlist; al; al = al2) {
			if (net(al->addr_val) != LOCALNET) {
				fprintf(hf, "%d.%d.%d.%d\t",
					net(al->addr_val), host(al->addr_val),
					lhost(al->addr_val), imp(al->addr_val));
				for (nl = namelist; nl; nl = nl->name_link)
					fprintf(hf, " %s", lower(nl->name_val));
E 2
I 2
		al2 = addrlist;
		while (al = al2) {
D 6
			if (inet_netof(al->addr_val) != LOCALNET) {
E 6
I 6
			if (!local(inet_netof(al->addr_val))) {
E 6
				char *cp;

				putaddr(hf, al->addr_val);
				cp = "%s";
				for (nl = namelist; nl; nl = nl->name_link) {
					fprintf(hf, cp, lower(nl->name_val));
					cp = " %s";
				}
E 2
				putc('\n', hf);
			}
			al2 = al->addr_link;
D 2
			free_addr(al);
E 2
I 2
			free((char *)al);
E 2
		}
D 2
		break;
E 2
I 2
D 6
		goto alreadyfree;
E 6
I 6
		break;
E 6
E 2

	default:
		fprintf(stderr, "Unknown keyword: %d.\n", keyword);
	}
D 2
	for (nl = namelist; nl; nl = nl2) {
		nl2 = nl->name_link;
		free_name(nl);
	}
	for (nl = protos; nl; nl = nl2) {
		nl2 = nl->name_link;
		free_name(nl);
	}
E 2
I 2
D 6
	al2 = addrlist;
	while (al = al2)
		al2 = al->addr_link, free((char *)al);
alreadyfree:
E 6
	freenames(namelist);
I 6
dontfree:
E 6
	freenames(protos);
E 2
}

I 6
printgateway(net, name, metric)
	int net;
	char *name;
	int metric;
{
	struct netent *np;

	fprintf(gf, "net ");
	np = getnetbyaddr(net, AF_INET);
	if (np)
		fprintf(gf, "%s", np->n_name);
	else
		putnet(gf, net);
	fprintf(gf, " gateway %s metric %d passive\n",
		lower(name), metric);
}

E 6
D 2
copylocal()
E 2
I 2
copylocal(f, filename)
	FILE *f;
	char *filename;
E 2
{
	register FILE *lhf;
	register cc;
	char buf[BUFSIZ];
I 2
	extern int errno;
E 2

D 2
	lhf = fopen("localhosts", "r");
E 2
I 2
	lhf = fopen(filename, "r");
E 2
	if (lhf == NULL) {
D 2
		perror("localhosts");
		fprintf(stderr, "(continuing)\n");
E 2
I 2
		if (errno != ENOENT) {
			perror(filename);
			exit(1);
		}
		fprintf(stderr, "Warning, no %s file.\n", filename);
E 2
		return;
	}
	while (cc = fread(buf, 1, sizeof(buf), lhf))
D 2
		fwrite(buf, 1, cc, hf);
E 2
I 2
		fwrite(buf, 1, cc, f);
E 2
	fclose(lhf);
}
I 2

I 6
D 19
copygateways(f, filename)
	FILE *f;
E 19
I 19
copygateways(filename)
E 19
	char *filename;
{
	register FILE *lhf;
D 9
	register cc;
E 9
	struct name *nl;
	char type[80];
	char dname[80];
	char gname[80];
	char junk[80];
I 11
	char buf[500];
E 11
D 19
	u_long addr;
E 19
I 19
	struct in_addr addr;
E 19
	int net, metric;
	extern int errno;

	lhf = fopen(filename, "r");
	if (lhf == NULL) {
		if (errno != ENOENT) {
			perror(filename);
			exit(1);
		}
		fprintf(stderr, "Warning, no %s file.\n", filename);
		return;
	}
	/* format: {net | host} XX gateway XX metric DD [passive]\n */
D 11
#define	readentry(fp) \
	fscanf((fp), "%s %s gateway %s metric %d %s\n", \
		type, dname, gname, &metric, junk)
E 11
D 9
	while (readentry(lhf) != EOF) {
E 9
I 9
	for (;;) {
		junk[0] = 0;
D 11
		if (readentry(lhf) == EOF)
E 11
I 11
		if (fgets(buf, sizeof(buf), lhf) == (char *)NULL)
E 11
			break;
I 11
		fputs(buf, gf);
		if (buf[0] == '#' ||
		    sscanf(buf, "%s %s gateway %s metric %d %s",
		    type, dname, gname, &metric, junk) < 5)
			continue;
E 11
E 9
		if (strcmp(type, "net"))
D 11
			goto dumpit;
E 11
I 11
			continue;
E 11
		if (!getnetaddr(dname, &net))
D 11
			goto dumpit;
E 11
I 11
			continue;
E 11
D 19
		if (!gethostaddr(gname, &addr))
E 19
I 19
		if (!gethostaddr(gname, &addr.s_addr))
E 19
D 11
			goto dumpit;
E 11
I 11
			continue;
E 11
		nl = newname(gname);
		(void) savegateway(nl, net, addr, metric);
D 11
dumpit:
		fprintf(gf, "%s %s gateway %s metric %d %s\n",
			type, dname, gname, metric, junk);
E 11
	}
	fclose(lhf);
}

getnetaddr(name, addr)
	char *name;
	int *addr;
{
	struct netent *np = getnetbyname(name);
D 19
	int n;
E 19

	if (np == 0) {
		*addr = inet_network(name);
		return (*addr != -1);
	} else {
		if (np->n_addrtype != AF_INET)
			return (0);
		*addr = np->n_net;
		return (1);
	}
}

gethostaddr(name, addr)
	char *name;
	u_long *addr;
{
	struct hostent *hp;

	hp = gethostbyname(name);
	if (hp) {
		*addr = *(u_long *)(hp->h_addr);
		return (1);
	}
	*addr = inet_addr(name);
	return (*addr != -1);
}

E 6
I 4
copycomments(in, out, ccount)
	FILE *in, *out;
	int ccount;
{
D 19
	char buf[BUFSIZ];
	int length;
E 19
	int count;
D 19
	char *fgets();
E 19
I 19
	char buf[BUFSIZ], *fgets();
E 19

	for (count=0; count < ccount; count++) {
		if ((fgets(buf, sizeof(buf), in) == NULL) || (buf[0] != ';'))
			return;
		buf[0] = '#';
		fputs(buf, out);
	}
	return;
}
E 4
#define	UC(b)	(((int)(b))&0xff)

I 8
/*
 * Print network number in internet-standard dot notation;
 * v is in host byte order.
 */
E 8
putnet(f, v)
	FILE *f;
D 9
	u_long v;
E 9
I 9
	register int v;
E 9
{
D 8
	register char *a = (char *)&v;

	if (UC(a[0]&0x80) == 0)
		fprintf(f, "%d", UC(a[0]));
	else if ((UC(a[0])&0x40) == 0)
		fprintf(f, "%d.%d", UC(a[0]), UC(a[1]));
E 8
I 8
	if (v < 128)
		fprintf(f, "%d", v);
	else if (v < 65536)
D 9
		fprintf(f, "%d.%d", (v >> 8) & 0xff, v & 0xff);
E 9
I 9
		fprintf(f, "%d.%d", UC(v >> 8), UC(v));
E 9
E 8
	else
D 8
		fprintf(f, "%d.%d.%d", UC(a[0]), UC(a[1]), UC(a[2]));
E 8
I 8
D 9
		fprintf(f, "%d.%d.%d", (v >> 16) & 0xff,
			(v >> 8) & 0xff, v & 0xff);
E 9
I 9
		fprintf(f, "%d.%d.%d", UC(v >> 16), UC(v >> 8), UC(v));
E 9
E 8
}

putaddr(f, v)
	FILE *f;
D 19
	u_long v;
E 19
I 19
	struct in_addr v;
E 19
{
D 19
	register char *a = (char *)&v;
	char buf[32];

D 18
	sprintf(buf,"%d.%d.%d.%d", UC(a[0]), UC(a[1]), UC(a[2]), UC(a[3]));
E 18
I 18
	(void) sprintf(buf,"%d.%d.%d.%d",
		UC(a[0]), UC(a[1]), UC(a[2]), UC(a[3]));
E 18
	fprintf(f, "%-16.16s", buf);
E 19
I 19
	fprintf(f, "%-16.16s", inet_ntoa(v));
E 19
}

freenames(list)
	struct name *list;
{
	register struct name *nl, *nl2;

	nl2 = list;
	while (nl = nl2) {
		nl2 = nl->name_link;
		free(nl->name_val);
		free((char *)nl);
	}
}
D 6
struct gateway {
	struct	gateway *g_link;
	int	g_net;
};
E 6

I 6
freeaddrs(list)
	struct addr *list;
{
	register struct addr *al, *al2;

	al2 = list;
	while (al = al2)
		al2 = al->addr_link, free((char *)al);
}

E 6
struct gateway *gateways = 0;
I 6
struct gateway *lastgateway = 0;
E 6

D 6
checkgateway(net)
E 6
I 6
struct gateway *
gatewayto(net)
E 6
	register int net;
{
	register struct gateway *gp;

	for (gp = gateways; gp; gp = gp->g_link)
D 6
		if (gp->g_net == net)
			return (1);
	return (0);
E 6
I 6
		if ((gp->g_net == net) && (gp->g_metric > 0))
			return (gp);
	return ((struct gateway *) NULL);
E 6
}

D 6
savegateway(net)
	int net;
E 6
I 6
struct gateway *
savegateway(namelist, net, addr, metric)
	struct name *namelist;
D 19
	u_long addr;
E 19
I 19
	struct in_addr addr;
E 19
	int net, metric;
E 6
{
	register struct gateway *gp;

	gp = (struct gateway *)malloc(sizeof (struct gateway));
	if (gp == 0) {
		fprintf(stderr, "htable: out of memory\n");
		exit(1);
	}
D 6
	gp->g_link = gateways;
E 6
I 6
	gp->g_link = (struct gateway *) NULL;
	if (lastgateway)
		lastgateway->g_link = gp;
	else
		gateways = gp;
	lastgateway = gp;
	gp->g_name = namelist;
E 6
	gp->g_net = net;
D 6
	gateways = gp;
E 6
I 6
	gp->g_addr = addr;
	gp->g_metric = metric;
	if (metric == 1)
		gp->g_dst = gp;
I 17
	return (gp);
E 17
E 6
}
D 6
	
E 6
I 6

connectedto(net)
	u_long net;
{
	register i;

	for (i = 0; i < nconnected; i++)
		if (connected_nets[i] == net)
			return(1);
	return(0);
}

local(net)
	u_long net;
{
	register i;

	for (i = 0; i < nlocal; i++)
		if (local_nets[i] == net)
			return(1);
	return(0);
}

#define	MAXHOPS	10

/*
 * Go through list of gateways, finding connections for gateways
 * that are not yet connected.
 */
dogateways()
{
	register struct gateway *gp, *gw, *ggp;
	register int hops, changed = 1;
	struct name *nl;
	char *cp;

	for (hops = 0; hops < MAXHOPS && changed; hops++, changed = 0) {
	    for (gp = gateways; gp; gp = gp->g_link)
		if ((gp->g_metric == 0) && (gw = gatewayto(gp->g_net))) {
		    /*
		     * Found a new connection.
		     * For each other network that this gateway is on,
		     * add a new gateway to that network.
		     */
		    changed = 1;
		    gp->g_dst = gw->g_dst;
		    gp->g_metric = gw->g_metric + 1;
		    for (ggp = gp->g_firstent; ggp->g_name == gp->g_name;
			ggp = ggp->g_link) {
			    if (ggp == gp)
				continue;
			    if (gatewayto(ggp->g_net))
				continue;
			    ggp->g_dst = gp->g_dst;
			    ggp->g_metric = gp->g_metric;
			    printgateway(ggp->g_net,
				    gw->g_dst->g_name->name_val, gp->g_metric);
		    }
		    /*
		     * Put the gateway in the hosts file,
		     * using the address for the connected net.
		     */
		    putaddr(hf, gp->g_addr);
		    cp = "%s";
		    for (nl = gp->g_name; nl; nl = nl->name_link) {
			    fprintf(hf, cp, lower(nl->name_val));
			    cp = " %s";
		    }
		    fprintf(hf, "\t# gateway\n");
		}
	}
}
E 6
E 2
E 1
