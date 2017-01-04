h09606
s 00012/00007/00418
d D 5.14 88/06/29 20:42:05 bostic 30 29
c install approved copyright notice
e
s 00005/00001/00420
d D 5.13 88/05/14 10:16:52 karels 29 28
c print drops on request
e
s 00074/00094/00347
d D 5.12 88/03/01 18:31:06 bostic 28 27
c add getopt, general cleanup, make it work with dead kernels
e
s 00009/00003/00432
d D 5.11 88/02/07 20:38:19 karels 27 26
c new copyrights
e
s 00010/00006/00425
d D 5.10 88/02/07 20:25:01 karels 26 25
c new IMP stuff
e
s 00001/00003/00430
d D 5.9 87/07/27 17:14:27 bostic 25 24
c checked in for karels; use defined constant for KERNBASE
e
s 00093/00016/00340
d D 5.8 86/08/11 12:17:24 kupfer 24 22
c Implement -p. Some lint.
e
s 00094/00017/00339
d R 5.8 86/08/11 11:49:36 kupfer 23 22
c Implement -p. Some lint.
e
s 00017/00013/00339
d D 5.7 86/05/22 14:44:08 karels 22 21
c oops, don't want unix sockets under stats
e
s 00014/00010/00338
d D 5.6 86/05/08 14:52:43 karels 21 20
c integrate unix domain, get the addresses right
e
s 00001/00000/00347
d D 5.5 86/03/04 23:28:26 lepreau 20 19
c missing exit(0);
e
s 00000/00000/00347
d D 5.4 86/01/18 12:47:50 karels 19 18
x 18
c rm bbnnet
e
s 00044/00013/00334
d D 5.3 85/09/18 16:58:38 karels 18 17
c for walsh
e
s 00048/00002/00299
d D 5.2 85/08/16 19:59:29 sklower 17 15
c Allow user to single out which address family he is interested in;
c and add support for XNS statistics and control blocks.
e
s 00048/00002/00299
d R 5.2 85/08/16 19:40:18 sklower 16 15
c Add XNS statistics and control blocks; fix bug printing port numbers
e
s 00014/00002/00287
d D 5.1 85/06/04 15:45:12 dist 15 14
c Add copyright
e
s 00017/00001/00272
d D 4.13 84/11/20 17:19:16 edward 14 12
c -I to specify which interface we care about
e
s 00011/00000/00273
d R 4.13 84/11/20 16:45:22 edward 13 12
c -I flag to specify interface
e
s 00004/00001/00269
d D 4.12 84/10/31 11:38:54 karels 12 11
c get rthashsize from kernel
e
s 00019/00002/00251
d D 4.11 84/06/03 11:13:41 sam 11 10
c addr unix domain sockets with -u flag
e
s 00001/00001/00252
d D 4.10 84/03/12 20:14:45 leres 10 9
c When cracking flags, use the carefully constructed char pointer instead
c of only switching on the second character in the argument.
e
s 00014/00001/00239
d D 4.9 83/05/30 21:10:20 sam 9 8
c routing statistics
e
s 00002/00002/00238
d D 4.8 83/05/01 18:58:00 sam 8 7
c same thing, only more portable
e
s 00002/00001/00238
d D 4.7 83/03/23 20:54:35 sam 7 6
c btoc rounds instead of truncating
e
s 00006/00002/00233
d D 4.6 83/03/11 11:30:25 sam 6 5
c add icmp statistics printing
e
s 00003/00001/00232
d D 4.5 83/02/09 17:03:21 sam 5 4
c from sun
e
s 00001/00001/00232
d D 4.4 82/12/24 20:25:33 sam 4 3
c pte.h moved
e
s 00025/00009/00208
d D 4.3 82/12/05 23:51:28 sam 3 2
c put back -s option
e
s 00007/00006/00210
d D 4.2 82/10/06 10:30:26 sam 2 1
c add netdb and interval display on interface stats
e
s 00216/00000/00000
d D 4.1 82/08/25 22:21:44 sam 1 0
c date and time created 82/08/25 22:21:44 by sam
e
u
U
t
T
I 15
/*
D 27
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 27
I 27
D 30
 * Copyright (c) 1983,1988 Regents of the University of California.
E 30
I 30
 * Copyright (c) 1983, 1988 Regents of the University of California.
E 30
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 30
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 30
I 30
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
E 30
E 27
 */

E 15
I 1
#ifndef lint
D 11
static char sccsid[] = "%W% %E%";
E 11
I 11
D 15
static char sccsid[] = "%W% (Berkeley) %E%";
E 11
#endif
E 15
I 15
char copyright[] =
D 30
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
E 30
I 30
"%Z% Copyright (c) 1983, 1988 Regents of the University of California.\n\
E 30
 All rights reserved.\n";
D 28
#endif not lint
E 28
I 28
#endif /* not lint */
E 28

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 28
#endif not lint
E 28
I 28
#endif /* not lint */
E 28
E 15

#include <sys/param.h>
I 8
#include <sys/vmmac.h>
I 17
#include <sys/socket.h>
I 28
#include <sys/file.h>
E 28
E 17
E 8
D 4
#include <sys/pte.h>
E 4
I 4
#include <machine/pte.h>
E 4
#include <ctype.h>
#include <errno.h>
#include <netdb.h>
#include <nlist.h>
#include <stdio.h>

struct nlist nl[] = {
#define	N_MBSTAT	0
	{ "_mbstat" },
#define	N_IPSTAT	1
	{ "_ipstat" },
#define	N_TCB		2
	{ "_tcb" },
#define	N_TCPSTAT	3
	{ "_tcpstat" },
#define	N_UDB		4
	{ "_udb" },
#define	N_UDPSTAT	5
	{ "_udpstat" },
#define	N_RAWCB		6
	{ "_rawcb" },
#define	N_SYSMAP	7
	{ "_Sysmap" },
#define	N_SYSSIZE	8
	{ "_Syssize" },
#define	N_IFNET		9
	{ "_ifnet" },
D 26
#define	N_HOSTS		10
	{ "_hosts" },
E 26
I 26
#define	N_IMP		10
	{ "_imp_softc" },
E 26
#define	N_RTHOST	11
	{ "_rthost" },
#define	N_RTNET		12
	{ "_rtnet" },
D 6
	0,
E 6
I 6
#define	N_ICMPSTAT	13
	{ "_icmpstat" },
I 9
#define	N_RTSTAT	14
	{ "_rtstat" },
I 11
#define	N_NFILE		15
	{ "_nfile" },
#define	N_FILE		16
	{ "_file" },
#define	N_UNIXSW	17
	{ "_unixsw" },
I 12
#define N_RTHASHSIZE	18
	{ "_rthashsize" },
I 17
#define N_IDP		19
	{ "_nspcb"},
#define N_IDPSTAT	20
	{ "_idpstat"},
#define N_SPPSTAT	21
	{ "_spp_istat"},
#define N_NSERR		22
	{ "_ns_errstat"},
I 26
#define N_NIMP		23
	{ "_nimp"},
E 26
I 18

    /* BBN Internet protocol implementation */
#define	N_TCP		23
	{ "_tcp" },
#define	N_UDP		24
	{ "_udp" },
#define N_RDP		25
	{ "_rdp" },
#define	N_RDPSTAT	26
	{ "_rdpstat" },

E 18
E 17
E 12
E 11
E 9
	"",
E 6
};

I 11
/* internet protocols */
E 11
I 3
D 18
extern	int protopr();
E 18
I 18
extern	int protopr(), bbnprotopr();
E 18
D 6
extern	int tcp_stats(), udp_stats(), ip_stats();
E 6
I 6
extern	int tcp_stats(), udp_stats(), ip_stats(), icmp_stats();
I 24
/* ns protocols */
E 24
I 18
extern	int tcpstats(), udpstats(), ipstats(), icmpstats(), rdpstats();
E 18
I 17
extern	int nsprotopr();
extern	int spp_stats(), idp_stats(), nserr_stats();
E 17
E 6

I 24
#define NULLPROTOX	((struct protox *) 0)
E 24
E 3
struct protox {
D 3
	short	pr_index;	/* index into nlist of cb head */
	short	pr_wanted;	/* 1 if wanted, 0 otherwise */
	char	*pr_name;	/* well-known name */
E 3
I 3
	u_char	pr_index;		/* index into nlist of cb head */
	u_char	pr_sindex;		/* index into nlist of stat block */
	u_char	pr_wanted;		/* 1 if wanted, 0 otherwise */
	int	(*pr_cblocks)();	/* control blocks printing routine */
	int	(*pr_stats)();		/* statistics printing routine */
	char	*pr_name;		/* well-known name */
E 3
D 18
} protox[] = {
E 18
I 18
};

struct  protox berkprotox[] = {
E 18
D 3
	{ N_TCB,	1,	"tcp" },
	{ N_UDB,	1,	"udp" },
	{ -1,		0,	0 }
E 3
I 3
	{ N_TCB,	N_TCPSTAT,	1,	protopr,
	  tcp_stats,	"tcp" },
	{ N_UDB,	N_UDPSTAT,	1,	protopr,
	  udp_stats,	"udp" },
	{ -1,		N_IPSTAT,	1,	0,
	  ip_stats,	"ip" },
I 6
	{ -1,		N_ICMPSTAT,	1,	0,
	  icmp_stats,	"icmp" },
E 6
	{ -1,		-1,		0,	0,
	  0,		0 }
E 3
};

I 18
struct protox bbnprotox[] = {
	{ N_TCP,	N_TCPSTAT,	1,	bbnprotopr,
	  tcpstats,	"tcp" },
	{ N_UDP,	N_UDPSTAT,	1,	bbnprotopr,
	  udpstats,	"udp" },
	{ N_RDP,	N_RDPSTAT,	1,	bbnprotopr,
	  rdpstats,	"rdp" },
	{ N_RAWCB,	0,		1,	bbnprotopr,
	  0,		"raw" },
	{ -1,		N_IPSTAT,	1,	0,
	  ipstats,	"ip" },
	{ -1,		N_ICMPSTAT,	1,	0,
	  icmpstats,	"icmp" },
	{ -1,		-1,		0,	0,
	  0,		0 }
};

E 18
I 17
struct protox nsprotox[] = {
	{ N_IDP,	N_IDPSTAT,	1,	nsprotopr,
	  idp_stats,	"idp" },
	{ N_IDP,	N_SPPSTAT,	1,	nsprotopr,
	  spp_stats,	"spp" },
	{ -1,		N_NSERR,	1,	0,
	  nserr_stats,	"ns_err" },
	{ -1,		-1,		0,	0,
	  0,		0 }
};

E 17
struct	pte *Sysmap;

char	*system = "/vmunix";
char	*kmemf = "/dev/kmem";
int	kmem;
int	kflag;
int	Aflag;
int	aflag;
int	hflag;
int	iflag;
int	mflag;
int	nflag;
I 24
int	pflag;
E 24
int	rflag;
int	sflag;
int	tflag;
I 29
int	dflag;
E 29
I 11
D 21
int	uflag;
E 21
I 17
D 24
int	fflag;
E 24
E 17
E 11
int	interval;
D 11
char	usage[] = "[ -Aaihmnrst ] [ interval ] [ system ] [ core ]";
E 11
I 11
D 14
char	usage[] = "[ -Aaihmnrstu ] [ interval ] [ system ] [ core ]";
E 14
I 14
char	*interface;
int	unit;
D 17
char	usage[] = "[ -Aaihmnrstu ] [-I interface] [ interval ] [ system ] [ core ]";
E 17
I 17
D 21
char	usage[] = "[ -Aaihmnrstu ] [-f address_family] [-I interface] [ interval ] [ system ] [ core ]";
E 21
I 21
D 24
char	usage[] = "[ -Aaihmnrst ] [-f address_family] [-I interface] [ interval ] [ system ] [ core ]";
E 24
I 24
D 28
char	usage[] = "[ -Aaihmnrst ] [-f family] [-p proto] [-I interface] [ interval ] [ system ] [ core ]";
E 28
E 24
E 21
E 17
E 14
E 11

I 17
int	af = AF_UNSPEC;
I 21

I 24
extern	char *malloc();
extern	off_t lseek();

E 24
E 21
E 17
main(argc, argv)
	int argc;
	char *argv[];
{
D 24
	int i;
E 24
D 28
	char *cp, *name;
E 28
I 28
	extern char *optarg;
	extern int optind;
E 28
	register struct protoent *p;
I 17
D 24
	register struct protox *tp;
E 17

E 24
I 24
	register struct protox *tp;	/* for printing cblocks & stats */
	struct protox *name2protox();	/* for -p */
D 28
	
E 24
	name = argv[0];
	argc--, argv++;
  	while (argc > 0 && **argv == '-') {
		for (cp = &argv[0][1]; *cp; cp++)
D 10
		switch(argv[0][1]) {
E 10
I 10
		switch(*cp) {
E 28
I 28
	int ch;
E 28
E 10

I 28
D 29
	while ((ch = getopt(argc, argv, "AI:af:himnp:rstu")) != EOF)
E 29
I 29
	while ((ch = getopt(argc, argv, "AI:af:himnp:drstu")) != EOF)
E 29
		switch((char)ch) {
E 28
		case 'A':
			Aflag++;
			break;
I 28
		case 'I': {
			char *cp;
E 28

I 28
			iflag++;
			for (cp = interface = optarg; isalpha(*cp); cp++);
			unit = atoi(cp);
			*cp = '\0';
			break;
		}
E 28
		case 'a':
			aflag++;
I 29
			break;
		case 'd':
			dflag++;
E 29
			break;
D 28

E 28
I 28
		case 'f':
			if (strcmp(optarg, "ns") == 0)
				af = AF_NS;
			else if (strcmp(optarg, "inet") == 0)
				af = AF_INET;
			else if (strcmp(optarg, "unix") == 0)
				af = AF_UNIX;
			else {
				fprintf(stderr, "%s: unknown address family\n", optarg);
				exit(10);
			}
			break;
E 28
		case 'h':
			hflag++;
			break;
D 28

E 28
		case 'i':
			iflag++;
			break;
D 28

E 28
		case 'm':
			mflag++;
			break;
D 28

E 28
		case 'n':
			nflag++;
			break;
D 28

E 28
I 28
		case 'p':
			if ((tp = name2protox(optarg)) == NULLPROTOX) {
				fprintf(stderr, "%s: unknown or uninstrumented protocol\n", optarg);
				exit(10);
			}
			pflag++;
			break;
E 28
		case 'r':
			rflag++;
			break;
D 28

E 28
		case 's':
			sflag++;
			break;
D 28

E 28
		case 't':
			tflag++;
			break;
D 28

E 28
I 11
		case 'u':
D 21
			uflag++;
E 21
I 21
			af = AF_UNIX;
E 21
I 14
			break;
I 28
		case '?':
		default:
			usage();
		}
	argv += optind;
	argc -= optind;
E 28

I 24
D 28
		case 'p':
			argv++;
			argc--;
			if (argc == 0)
				goto use;
			if ((tp = name2protox(*argv)) == NULLPROTOX) {
				fprintf(stderr, "%s: unknown or uninstrumented protocol\n",
					*argv);
				exit(10);
			}
			pflag++;
			break;

E 24
I 17
		case 'f':
			argv++;
			argc--;
D 21
			if (strcmp(*argv,"ns")==0) {
E 21
I 21
			if (strcmp(*argv, "ns") == 0)
E 21
				af = AF_NS;
D 21
			} else if (strcmp(*argv,"inet")==0) {
E 21
I 21
			else if (strcmp(*argv, "inet") == 0)
E 21
				af = AF_INET;
I 21
			else if (strcmp(*argv, "unix") == 0)
				af = AF_UNIX;
			else {
				fprintf(stderr, "%s: unknown address family\n",
					*argv);
				exit(10);
E 21
			}
			break;
			
E 17
		case 'I':
E 28
I 28
	if (argc > 0) {
		if (isdigit(argv[0][0])) {
			interval = atoi(argv[0]);
			if (interval <= 0)
				usage();
			argv++, argc--;
E 28
			iflag++;
D 28
			if (*(interface = cp + 1) == 0) {
				if ((interface = argv[1]) == 0)
					break;
				argv++;
				argc--;
E 28
I 28
		}
		if (argc > 0) {
			system = *argv;
			argv++, argc--;
			if (argc > 0) {
				kmemf = *argv;
				kflag++;
E 28
			}
D 28
			for (cp = interface; isalpha(*cp); cp++)
				;
			unit = atoi(cp);
			*cp-- = 0;
E 14
			break;

E 11
		default:
use:
			printf("usage: %s %s\n", name, usage);
			exit(1);
E 28
		}
D 28
		argv++, argc--;
E 28
	}
D 28
	if (argc > 0 && isdigit(argv[0][0])) {
		interval = atoi(argv[0]);
		if (interval <= 0)
			goto use;
		argv++, argc--;
I 2
		iflag++;
E 2
	}
	if (argc > 0) {
		system = *argv;
		argv++, argc--;
	}
	nlist(system, nl);
	if (nl[0].n_type == 0) {
E 28
I 28
	if (nlist(system, nl) < 0 || nl[0].n_type == 0) {
E 28
		fprintf(stderr, "%s: no namelist\n", system);
		exit(1);
	}
D 28
	if (argc > 0) {
		kmemf = *argv;
		kflag++;
	}
	kmem = open(kmemf, 0);
E 28
I 28
	kmem = open(kmemf, O_RDONLY);
E 28
	if (kmem < 0) {
D 28
		fprintf(stderr, "cannot open ");
E 28
		perror(kmemf);
		exit(1);
	}
	if (kflag) {
		off_t off;

D 28
		off = nl[N_SYSMAP].n_value & 0x7fffffff;
		lseek(kmem, off, 0);
		nl[N_SYSSIZE].n_value *= 4;
D 24
		Sysmap = (struct pte *)malloc(nl[N_SYSSIZE].n_value);
E 24
I 24
		Sysmap = (struct pte *)malloc((u_int)nl[N_SYSSIZE].n_value);
E 24
		if (Sysmap == 0) {
			perror("Sysmap");
E 28
I 28
		Sysmap = (struct pte *)
		   malloc((u_int)(nl[N_SYSSIZE].n_value * sizeof(struct pte)));
		if (!Sysmap) {
			fputs("netstat: can't get memory for Sysmap.\n", stderr);
E 28
			exit(1);
		}
D 24
		read(kmem, Sysmap, nl[N_SYSSIZE].n_value);
E 24
I 24
D 28
		read(kmem, (char *)Sysmap, (int)nl[N_SYSSIZE].n_value);
E 28
I 28
		off = nl[N_SYSMAP].n_value & ~KERNBASE;
		(void)lseek(kmem, off, L_SET);
		(void)read(kmem, (char *)Sysmap,
		    (int)(nl[N_SYSSIZE].n_value * sizeof(struct pte)));
E 28
E 24
	}
	if (mflag) {
D 24
		mbpr(nl[N_MBSTAT].n_value);
E 24
I 24
		mbpr((off_t)nl[N_MBSTAT].n_value);
E 24
I 11
		exit(0);
	}
I 24
	if (pflag) {
		if (tp->pr_stats)
D 28
			(*tp->pr_stats)(nl[tp->pr_sindex].n_value, 
E 28
I 28
			(*tp->pr_stats)(nl[tp->pr_sindex].n_value,
E 28
				tp->pr_name);
		else
			printf("%s: no stats routine\n", tp->pr_name);
		exit(0);
	}
I 26
	if (hflag) {
		hostpr(nl[N_IMP].n_value, nl[N_NIMP].n_value);
		exit(0);
	}
E 26
E 24
D 21
	if (uflag) {
		unixpr(nl[N_NFILE].n_value, nl[N_FILE].n_value,
		    nl[N_UNIXSW].n_value);
E 11
		exit(0);
	}
E 21
D 2
	if (iflag) {
		intpr(interval, nl[N_IFNET].n_value);
		exit(0);
	}
E 2
	/*
	 * Keep file descriptors open to avoid overhead
	 * of open/close on each call to get* routines.
	 */
D 2
	setprotoent(1);
E 2
	sethostent(1);
	setnetent(1);
D 2
	setservent(1);
E 2
I 2
	if (iflag) {
		intpr(interval, nl[N_IFNET].n_value);
		exit(0);
	}
E 2
D 26
	if (hflag) {
		hostpr(nl[N_HOSTS].n_value);
		exit(0);
	}
E 26
	if (rflag) {
D 9
		routepr(nl[N_RTHOST].n_value, nl[N_RTNET].n_value);
E 9
I 9
		if (sflag)
D 24
			rt_stats(nl[N_RTSTAT].n_value);
E 24
I 24
			rt_stats((off_t)nl[N_RTSTAT].n_value);
E 24
		else
D 12
			routepr(nl[N_RTHOST].n_value, nl[N_RTNET].n_value);
E 12
I 12
D 24
			routepr(nl[N_RTHOST].n_value, nl[N_RTNET].n_value,
				nl[N_RTHASHSIZE].n_value);
E 24
I 24
			routepr((off_t)nl[N_RTHOST].n_value, 
				(off_t)nl[N_RTNET].n_value,
				(off_t)nl[N_RTHASHSIZE].n_value);
E 24
E 12
E 9
		exit(0);
	}
I 17
    if (af == AF_INET || af == AF_UNSPEC) {
I 18
	struct protox *head;

	head = (nl[N_TCB].n_type == 0) ? bbnprotox : berkprotox;
E 18
E 17
I 2
	setprotoent(1);
	setservent(1);
E 2
D 18
	while (p = getprotoent()) {
E 18
D 17
		register struct protox *tp;
E 17

D 3
		for (tp = protox; tp->pr_index >= 0; tp++)
E 3
I 3
D 18
		for (tp = protox; tp->pr_name; tp++)
E 3
			if (strcmp(tp->pr_name, p->p_name) == 0)
				break;
D 3
		if (tp->pr_index < 0 || tp->pr_wanted == 0)
E 3
I 3
		if (tp->pr_name == 0 || tp->pr_wanted == 0)
E 18
I 18
	for (tp = head; tp->pr_name; tp++) {
		if (tp->pr_wanted == 0)
E 18
E 3
			continue;
D 3
		protopr(nl[tp->pr_index].n_value, p->p_name);
E 3
I 3
D 18
D 22
		if (sflag && tp->pr_stats) {
			(*tp->pr_stats)(nl[tp->pr_sindex].n_value, p->p_name);
			continue;
		}
		if (tp->pr_cblocks)
			(*tp->pr_cblocks)(nl[tp->pr_index].n_value, p->p_name);
E 22
I 22
		if (sflag) {
			if (tp->pr_stats)
				(*tp->pr_stats)(nl[tp->pr_sindex].n_value,
					p->p_name);
		} else
			if (tp->pr_cblocks)
				(*tp->pr_cblocks)(nl[tp->pr_index].n_value,
					p->p_name);
E 22
E 18
I 18

		if (sflag) {
			if (tp->pr_stats)
			    (*tp->pr_stats)(nl[tp->pr_sindex].n_value, tp->pr_name);
		} else if (tp->pr_cblocks)
			(*tp->pr_cblocks)(nl[tp->pr_index].n_value, tp->pr_name);
E 18
E 3
	}
	endprotoent();
I 17
    }
    if (af == AF_NS || af == AF_UNSPEC) {
	for (tp = nsprotox; tp->pr_name; tp++) {
D 22
		if (sflag && tp->pr_stats) {
			(*tp->pr_stats)(nl[tp->pr_sindex].n_value, tp->pr_name);
			continue;
		}
		if (tp->pr_cblocks)
			(*tp->pr_cblocks)(nl[tp->pr_index].n_value, tp->pr_name);
E 22
I 22
		if (sflag) {
			if (tp->pr_stats)
				(*tp->pr_stats)(nl[tp->pr_sindex].n_value,
					tp->pr_name);
		} else
			if (tp->pr_cblocks)
				(*tp->pr_cblocks)(nl[tp->pr_index].n_value,
					tp->pr_name);
E 22
	}
    }
I 21
D 22
    if (af == AF_UNIX || af == AF_UNSPEC)
E 22
I 22
    if ((af == AF_UNIX || af == AF_UNSPEC) && !sflag)
E 22
D 24
	    unixpr(nl[N_NFILE].n_value, nl[N_FILE].n_value,
		nl[N_UNIXSW].n_value);
E 24
I 24
	    unixpr((off_t)nl[N_NFILE].n_value, (off_t)nl[N_FILE].n_value,
		(struct protosw *)nl[N_UNIXSW].n_value);
I 26
    if (af == AF_UNSPEC && sflag)
	impstats(nl[N_IMP].n_value, nl[N_NIMP].n_value);
E 26
E 24
E 21
I 20
    exit(0);
E 20
E 17
}

/*
 * Seek into the kernel for a value.
 */
I 24
off_t
E 24
klseek(fd, base, off)
D 24
	int fd, base, off;
E 24
I 24
	int fd, off;
	off_t base;
E 24
{
D 24

E 24
	if (kflag) {
		/* get kernel pte */
I 5
D 25
#ifdef vax
E 5
		base &= 0x7fffffff;
D 5
		base = Sysmap[base >> 9].pg_pfnum * 512 + (base & 0x1ff);
E 5
I 5
#endif
E 25
I 25
		base &= ~KERNBASE;
E 25
D 7
		base = ctob(Sysmap[btoc(base)].pg_pfnum) + (base & (NBPG-1));
E 7
I 7
D 8
		base = ctob(Sysmap[base >> PGSHIFT].pg_pfnum) +
			(base & PGOFSET);
E 8
I 8
		base = ctob(Sysmap[btop(base)].pg_pfnum) + (base & PGOFSET);
E 8
E 7
E 5
	}
D 24
	lseek(fd, base, off);
E 24
I 24
	return (lseek(fd, base, off));
E 24
I 9
}

char *
plural(n)
	int n;
{

	return (n != 1 ? "s" : "");
I 24
}

/*
 * Find the protox for the given "well-known" name.
 */
struct protox *
knownname(name)
	char *name;
{
	struct protox *tp;
D 28
	
E 28
I 28

E 28
	for (tp = protox; tp->pr_name; tp++)
		if (strcmp(tp->pr_name, name) == 0)
			return(tp);
	for (tp = nsprotox; tp->pr_name; tp++)
		if (strcmp(tp->pr_name, name) == 0)
			return(tp);
	return(NULLPROTOX);
}

/*
 * Find the protox corresponding to name.
 */
struct protox *
name2protox(name)
	char *name;
{
	struct protox *tp;
	char **alias;			/* alias from p->aliases */
	struct protoent *p;
D 28
	
E 28
I 28

E 28
	/*
	 * Try to find the name in the list of "well-known" names. If that
	 * fails, check if name is an alias for an Internet protocol.
	 */
	if (tp = knownname(name))
		return(tp);
D 28
		
E 28
I 28

E 28
	setprotoent(1);			/* make protocol lookup cheaper */
	while (p = getprotoent()) {
		/* assert: name not same as p->name */
		for (alias = p->p_aliases; *alias; alias++)
			if (strcmp(name, *alias) == 0) {
				endprotoent();
				return(knownname(p->p_name));
			}
	}
	endprotoent();
	return(NULLPROTOX);
I 28
}

usage()
{
	fputs("usage: netstat [-Aan] [-f address_family] [system] [core]\n               [-himnrs] [-f address_family] [system] [core]\n               [-n] [-I interface] interval [system] [core]\n", stderr);
	exit(1);
E 28
E 24
E 9
}
E 1
