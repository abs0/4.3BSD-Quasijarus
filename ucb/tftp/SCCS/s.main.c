h18676
s 00010/00005/00644
d D 5.7 88/06/29 20:49:21 bostic 16 15
c install approved copyright notice
e
s 00011/00005/00638
d D 5.6 88/03/28 13:51:43 bostic 15 14
c add Berkeley specific header
e
s 00002/00001/00641
d D 5.5 86/02/07 15:04:34 minshall 14 13
c Fix a few of the lint errors.
e
s 00008/00003/00634
d D 5.4 86/02/07 11:22:22 minshall 13 12
c minor fixup, and keep from looping on eof from stdin.
e
s 00119/00063/00518
d D 5.3 86/02/06 15:01:45 minshall 12 11
c Install version from Jim Guyton <guyton@rand-unix>.
e
s 00006/00002/00575
d D 5.2 86/01/10 02:14:28 lepreau 11 10
c Don't loop on eof on tty; Map eof -> quit always.
e
s 00013/00001/00564
d D 5.1 85/06/06 09:22:03 dist 10 9
c Add copyright
e
s 00011/00041/00554
d D 4.9 84/04/12 22:25:01 sam 9 8
c take fixes from rws@mit-ai (follow protocol)
e
s 00001/00000/00594
d D 4.8 84/04/12 20:23:23 sam 8 7
c check in for karels
e
s 00003/00001/00591
d D 4.7 83/08/11 22:44:31 sam 7 6
c standardize sccs keyword lines
e
s 00084/00019/00508
d D 4.6 83/06/12 01:26:38 sam 6 5
c too much to say...let's just say it seems to work now
e
s 00001/00001/00526
d D 4.5 82/12/25 21:21:42 sam 5 4
c port numbers now byte swapped
e
s 00001/00001/00526
d D 4.4 82/11/15 18:34:32 sam 4 3
c add domain specification
e
s 00010/00015/00517
d D 4.3 82/11/14 15:21:29 sam 3 2
c convert to 4.1c sys calls and directory layout
e
s 00046/00030/00486
d D 4.2 82/10/08 00:58:22 sam 2 1
c convert to new library routines
e
s 00516/00000/00000
d D 4.1 82/08/16 22:20:29 sam 1 0
c date and time created 82/08/16 22:20:29 by sam
e
u
U
t
T
I 10
/*
D 12
 * Copyright (c) 1983 Regents of the University of California.
E 12
I 12
D 15
 * Copyright (c) 1985 Regents of the University of California.
E 12
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 15
I 15
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 16
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 16
I 16
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
E 16
E 15
 */

E 10
I 1
D 7
/*	%M%	%I%	%E%	*/
E 7
I 7
#ifndef lint
I 10
char copyright[] =
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
 All rights reserved.\n";
D 15
#endif not lint
E 15
I 15
#endif /* not lint */
E 15

#ifndef lint
E 10
static char sccsid[] = "%W% (Berkeley) %G%";
D 10
#endif
E 10
I 10
D 15
#endif not lint
E 15
I 15
#endif /* not lint */
E 15
E 10
E 7

I 12
/* Many bug fixes are from Jim Guyton <guyton@rand-unix> */

E 12
/*
 * TFTP User Program -- Command Interface.
 */
#include <sys/types.h>
D 3
#include <net/in.h>
E 3
#include <sys/socket.h>
I 6
#include <sys/file.h>
E 6
I 3

#include <netinet/in.h>

E 3
#include <signal.h>
#include <stdio.h>
#include <errno.h>
#include <setjmp.h>
#include <ctype.h>
I 2
#include <netdb.h>
E 2

I 6
#define	TIMEOUT		5		/* secs between rexmt's */

E 6
D 2
struct	sockaddr_in sin = { AF_INET, IPPORT_TFTP };
E 2
I 2
D 3
struct	sockaddr_in sin = { AF_INET };
E 3
I 3
D 9
struct	sockaddr_in sin;
E 9
I 9
D 12
struct	sockaddr_in sin = { AF_INET };
E 12
I 12
struct	sockaddr_in sin;
E 12
E 9
E 3
E 2
int	f;
I 12
short   port;
E 12
D 3
int	options;
E 3
int	trace;
I 12
int	verbose;
E 12
D 9
int	verbose;
E 9
int	connected;
char	mode[32];
char	line[200];
int	margc;
char	*margv[20];
char	*prompt = "tftp";
jmp_buf	toplevel;
int	intr();
I 2
struct	servent *sp;
E 2

D 9
int	quit(), help(), setverbose(), settrace(), status();
E 9
I 9
D 12
int	quit(), help(), settrace(), status();
E 9
D 6
int	get(), put(), setpeer(), setmode();
E 6
I 6
int	get(), put(), setpeer(), setmode(), setrexmt(), settimeout();
E 12
I 12
int	quit(), help(), setverbose(), settrace(), status();
int     get(), put(), setpeer(), modecmd(), setrexmt(), settimeout();
int     setbinary(), setascii();
E 12
E 6

#define HELPINDENT (sizeof("connect"))

struct cmd {
	char	*name;
	char	*help;
	int	(*handler)();
};

I 12
char	vhelp[] = "toggle verbose mode";
E 12
D 9
char	vhelp[] = "toggle verbose mode";
E 9
char	thelp[] = "toggle packet tracing";
char	chelp[] = "connect to remote tftp";
char	qhelp[] = "exit tftp";
char	hhelp[] = "print help information";
char	shelp[] = "send file";
char	rhelp[] = "receive file";
char	mhelp[] = "set file transfer mode";
char	sthelp[] = "show current status";
I 6
char	xhelp[] = "set per-packet retransmission timeout";
char	ihelp[] = "set total retransmission timeout";
I 12
char    ashelp[] = "set mode to netascii";
char    bnhelp[] = "set mode to octet";
E 12
E 6

struct cmd cmdtab[] = {
	{ "connect",	chelp,		setpeer },
D 12
	{ "mode",	mhelp,		setmode },
E 12
I 12
	{ "mode",       mhelp,          modecmd },
E 12
	{ "put",	shelp,		put },
	{ "get",	rhelp,		get },
	{ "quit",	qhelp,		quit },
I 12
	{ "verbose",	vhelp,		setverbose },
E 12
D 9
	{ "verbose",	vhelp,		setverbose },
E 9
	{ "trace",	thelp,		settrace },
	{ "status",	sthelp,		status },
I 12
	{ "binary",     bnhelp,         setbinary },
	{ "ascii",      ashelp,         setascii },
E 12
I 6
	{ "rexmt",	xhelp,		setrexmt },
	{ "timeout",	ihelp,		settimeout },
E 6
	{ "?",		hhelp,		help },
	0
};

struct	cmd *getcmd();
char	*tail();
char	*index();
char	*rindex();

main(argc, argv)
	char *argv[];
{
I 12
	struct sockaddr_in sin;
E 12
I 6
D 9
	struct sockaddr_in sin;
E 9
	int top;

E 6
D 2
	register struct requestpkt *tp;
	register int n;

E 2
I 2
	sp = getservbyname("tftp", "udp");
	if (sp == 0) {
		fprintf(stderr, "tftp: udp/tftp: unknown service\n");
		exit(1);
	}
D 3
	sin.sin_port = htons(sp->s_port);
E 2
	if (argc > 1 && !strcmp(argv[1], "-d")) {
		options |= SO_DEBUG;
		argc--, argv++;
	}
	f = socket(SOCK_DGRAM, 0, 0, options);
E 3
I 3
D 4
	f = socket(0, SOCK_DGRAM, 0, 0);
E 4
I 4
D 14
	f = socket(AF_INET, SOCK_DGRAM, 0, 0);
E 14
I 14
	f = socket(AF_INET, SOCK_DGRAM, 0);
E 14
E 4
E 3
	if (f < 0) {
D 6
		perror("socket");
E 6
I 6
		perror("tftp: socket");
E 6
		exit(3);
	}
I 12
	bzero((char *)&sin, sizeof (sin));
	sin.sin_family = AF_INET;
E 12
I 6
D 9
	bzero((char *)&sin, sizeof (sin));
	sin.sin_family = AF_INET;
E 9
	if (bind(f, &sin, sizeof (sin)) < 0) {
		perror("tftp: bind");
		exit(1);
	}
E 6
D 2
#if vax || pdp11
	sin.sin_port = htons(sin.sin_port);
#endif
E 2
D 9
	strcpy(mode, "netascii");
E 9
I 9
D 12
	strcpy(mode, "octet");
E 12
I 12
	strcpy(mode, "netascii");
E 12
E 9
I 6
	signal(SIGINT, intr);
E 6
	if (argc > 1) {
		if (setjmp(toplevel) != 0)
			exit(0);
		setpeer(argc, argv);
	}
D 6
	setjmp(toplevel);
E 6
I 6
	top = setjmp(toplevel) == 0;
E 6
	for (;;)
D 6
		command(1);
E 6
I 6
		command(top);
E 6
}

D 2
char host_name[100];
E 2
I 2
D 12
char	*hostname;
char	hnamebuf[32];
E 12
I 12
char    hostname[100];
E 12
E 2

setpeer(argc, argv)
	int argc;
	char *argv[];
{
D 12
	register int c;
E 12
I 2
	struct hostent *host;
E 2

	if (argc < 2) {
		strcpy(line, "Connect ");
		printf("(to) ");
		gets(&line[strlen(line)]);
		makeargv();
		argc = margc;
		argv = margv;
	}
	if (argc > 3) {
		printf("usage: %s host-name [port]\n", argv[0]);
		return;
	}
D 2
	sin.sin_addr.s_addr = rhost(&argv[1]);
	if (sin.sin_addr.s_addr == (u_long)-1) {
		printf("%s: unknown host\n", argv[1]);
		connected = 0;
		return;
E 2
I 2
	host = gethostbyname(argv[1]);
	if (host) {
I 3
		sin.sin_family = host->h_addrtype;
E 3
		bcopy(host->h_addr, &sin.sin_addr, host->h_length);
D 12
		hostname = host->h_name;
E 12
I 12
		strcpy(hostname, host->h_name);
E 12
	} else {
I 3
		sin.sin_family = AF_INET;
E 3
		sin.sin_addr.s_addr = inet_addr(argv[1]);
		if (sin.sin_addr.s_addr == -1) {
			connected = 0;
			printf("%s: unknown host\n", argv[1]);
			return;
		}
D 12
		strcpy(hnamebuf, argv[1]);
		hostname = hnamebuf;
E 12
I 12
		strcpy(hostname, argv[1]);
E 12
E 2
	}
I 2
D 12
	sin.sin_port = sp->s_port;
E 12
I 12
	port = sp->s_port;
E 12
E 2
	if (argc == 3) {
D 12
		sin.sin_port = atoi(argv[2]);
		if (sin.sin_port < 0) {
E 12
I 12
		port = atoi(argv[2]);
		if (port < 0) {
E 12
			printf("%s: bad port number\n", argv[2]);
			connected = 0;
			return;
		}
I 5
D 12
		sin.sin_port = htons((u_short)sin.sin_port);
E 12
I 12
		port = htons(port);
E 12
E 5
I 2
	}
E 2
D 3
#if vax || pdp11
D 2
		sin.sin_port = htons(sin.sin_port);
E 2
I 2
	sin.sin_port = htons(sin.sin_port);
E 2
#endif
E 3
I 3
D 5
	sin.sin_port = htons((u_short)sin.sin_port);
E 5
E 3
D 2
	}
	strcpy(host_name, argv[1]);
E 2
	connected = 1;
}

struct	modes {
	char *m_name;
	char *m_mode;
} modes[] = {
D 9
	{ "ascii",	"netascii" },
	{ "binary",	"octect" },
	{ "mail",	"mail" },
E 9
I 9
D 12
	{ "binary",	"octet" },
	{ "image",	"octet" },
	{ "octet",	"octet" },
E 12
I 12
	{ "ascii",	"netascii" },
	{ "netascii",   "netascii" },
	{ "binary",     "octet" },
	{ "image",      "octet" },
D 13
	{ "octect",     "octet" },
E 13
I 13
	{ "octet",     "octet" },
E 13
/*      { "mail",       "mail" },       */
E 12
E 9
	{ 0,		0 }
};

D 12
setmode(argc, argv)
E 12
I 12
modecmd(argc, argv)
E 12
	char *argv[];
{
	register struct modes *p;
I 12
	char *sep;
E 12

D 12
	if (argc > 2) {
		char *sep;

		printf("usage: %s [", argv[0]);
		sep = " ";
		for (p = modes; p->m_name; p++) {
			printf("%s%s", sep, p->m_name);
			if (*sep == ' ')
				sep = " | ";
		}
		printf(" ]\n");
		return;
	}
E 12
	if (argc < 2) {
		printf("Using %s mode to transfer files.\n", mode);
		return;
	}
D 12
	for (p = modes; p->m_name; p++)
		if (strcmp(argv[1], p->m_name) == 0)
			break;
	if (p->m_name)
		strcpy(mode, p->m_mode);
	else
E 12
I 12
	if (argc == 2) {
		for (p = modes; p->m_name; p++)
			if (strcmp(argv[1], p->m_name) == 0)
				break;
		if (p->m_name) {
			setmode(p->m_mode);
			return;
		}
E 12
		printf("%s: unknown mode\n", argv[1]);
I 12
		/* drop through and print usage message */
	}

	printf("usage: %s [", argv[0]);
	sep = " ";
	for (p = modes; p->m_name; p++) {
		printf("%s%s", sep, p->m_name);
		if (*sep == ' ')
			sep = " | ";
	}
	printf(" ]\n");
	return;
E 12
}

I 12
setbinary(argc, argv)
char *argv[];
{       setmode("octet");
}

setascii(argc, argv)
char *argv[];
{       setmode("netascii");
}

setmode(newmode)
char *newmode;
{
	strcpy(mode, newmode);
	if (verbose)
		printf("mode set to %s\n", mode);
}


E 12
/*
 * Send file(s).
 */
put(argc, argv)
	char *argv[];
{
	int fd;
D 12
	register int n, addr;
E 12
I 12
	register int n;
E 12
	register char *cp, *targ;

	if (argc < 2) {
		strcpy(line, "send ");
		printf("(file) ");
		gets(&line[strlen(line)]);
		makeargv();
		argc = margc;
		argv = margv;
	}
	if (argc < 2) {
		putusage(argv[0]);
		return;
	}
	targ = argv[argc - 1];
	if (index(argv[argc - 1], ':')) {
D 2
		char *hostname;
E 2
I 2
		char *cp;
		struct hostent *hp;
E 2

		for (n = 1; n < argc - 1; n++)
			if (index(argv[n], ':')) {
				putusage(argv[0]);
				return;
			}
D 2
		hostname = argv[argc - 1];
		targ = index(hostname, ':');
E 2
I 2
		cp = argv[argc - 1];
		targ = index(cp, ':');
E 2
		*targ++ = 0;
D 2
		addr = rhost(&hostname);
		if (addr == -1) {
			printf("%s: Unknown host.\n", hostname);
E 2
I 2
		hp = gethostbyname(cp);
		if (hp == 0) {
			printf("%s: Unknown host.\n", cp);
E 2
			return;
		}
D 2
		sin.sin_addr.s_addr = addr;
E 2
I 2
D 3
		bcopy(hp->h_addr, &sin.sin_addr, hp->h_length);
E 3
I 3
		bcopy(hp->h_addr, (caddr_t)&sin.sin_addr, hp->h_length);
E 3
		sin.sin_family = hp->h_addrtype;
E 2
		connected = 1;
D 2
		strcpy(host_name, hostname);
E 2
I 2
D 12
		hostname = hp->h_name;
E 12
I 12
		strcpy(hostname, hp->h_name);
E 12
E 2
	}
	if (!connected) {
		printf("No target machine specified.\n");
		return;
	}
D 6
	sigset(SIGINT, intr);
E 6
	if (argc < 4) {
		cp = argc == 2 ? tail(targ) : argv[1];
D 6
		fd = open(cp);
E 6
I 6
		fd = open(cp, O_RDONLY);
E 6
		if (fd < 0) {
D 6
			perror(cp);
E 6
I 6
			fprintf(stderr, "tftp: "); perror(cp);
E 6
			return;
		}
D 9
		sendfile(fd, targ);
E 9
I 9
D 12
		(void) sendfile(fd, targ);
E 12
I 12
		if (verbose)
			printf("putting %s to %s:%s [%s]\n",
				cp, hostname, targ, mode);
		sin.sin_port = port;
		sendfile(fd, targ, mode);
E 12
E 9
		return;
	}
I 12
				/* this assumes the target is a directory */
				/* on a remote unix system.  hmmmm.  */
E 12
	cp = index(targ, '\0'); 
	*cp++ = '/';
	for (n = 1; n < argc - 1; n++) {
		strcpy(cp, tail(argv[n]));
D 6
		fd = open(argv[n], 0);
E 6
I 6
		fd = open(argv[n], O_RDONLY);
E 6
		if (fd < 0) {
D 6
			perror(argv[n]);
E 6
I 6
			fprintf(stderr, "tftp: "); perror(argv[n]);
E 6
			continue;
		}
D 9
		sendfile(fd, targ);
E 9
I 9
D 12
		(void) sendfile(fd, targ);
E 12
I 12
		if (verbose)
			printf("putting %s to %s:%s [%s]\n",
				argv[n], hostname, targ, mode);
		sin.sin_port = port;
		sendfile(fd, targ, mode);
E 12
E 9
	}
}

putusage(s)
	char *s;
{
	printf("usage: %s file ... host:target, or\n", s);
	printf("       %s file ... target (when already connected)\n", s);
}

/*
 * Receive file(s).
 */
get(argc, argv)
	char *argv[];
{
	int fd;
D 12
	register int n, addr;
E 12
I 12
	register int n;
E 12
	register char *cp;
	char *src;

	if (argc < 2) {
		strcpy(line, "get ");
		printf("(files) ");
		gets(&line[strlen(line)]);
		makeargv();
		argc = margc;
		argv = margv;
	}
	if (argc < 2) {
		getusage(argv[0]);
		return;
	}
D 12
	if (!connected)
		for (n = 1; n < argc - 1; n++)
E 12
I 12
	if (!connected) {
		for (n = 1; n < argc ; n++)
E 12
			if (index(argv[n], ':') == 0) {
				getusage(argv[0]);
				return;
			}
D 6
	sigset(SIGINT, intr);
E 6
D 12
	for (n = 1; argc == 2 || n < argc - 1; n++) {
E 12
I 12
	}
	for (n = 1; n < argc ; n++) {
E 12
		src = index(argv[n], ':');
		if (src == NULL)
			src = argv[n];
		else {
I 2
			struct hostent *hp;

E 2
			*src++ = 0;
D 2
			addr = rhost(&argv[n]);
			if (addr == -1) {
E 2
I 2
			hp = gethostbyname(argv[n]);
			if (hp == 0) {
E 2
				printf("%s: Unknown host.\n", argv[n]);
				continue;
			}
D 2
			sin.sin_addr.s_addr = addr;
E 2
I 2
D 3
			bcopy(hp->h_addr, &sin.sin_addr, hp->h_length);
E 3
I 3
			bcopy(hp->h_addr, (caddr_t)&sin.sin_addr, hp->h_length);
E 3
			sin.sin_family = hp->h_addrtype;
E 2
			connected = 1;
D 2
			strcpy(host_name, argv[n]);
E 2
I 2
D 12
			hostname = hp->h_name;
E 12
I 12
			strcpy(hostname, hp->h_name);
E 12
E 2
		}
		if (argc < 4) {
			cp = argc == 3 ? argv[2] : tail(src);
			fd = creat(cp, 0644);
			if (fd < 0) {
D 6
				perror(cp);
E 6
I 6
				fprintf(stderr, "tftp: "); perror(cp);
E 6
				return;
			}
D 9
			recvfile(fd, src);
E 9
I 9
D 12
			(void) recvfile(fd, src);
E 12
I 12
			if (verbose)
				printf("getting from %s:%s to %s [%s]\n",
					hostname, src, cp, mode);
			sin.sin_port = port;
			recvfile(fd, src, mode);
E 12
E 9
			break;
		}
D 12
		cp = index(argv[argc - 1], '\0');
		*cp++ = '/';
		strcpy(cp, tail(src));
		fd = creat(src, 0644);
E 12
I 12
		cp = tail(src);         /* new .. jdg */
		fd = creat(cp, 0644);
E 12
		if (fd < 0) {
D 6
			perror(src);
E 6
I 6
D 12
			fprintf(stderr, "tftp: "); perror(src);
E 12
I 12
			fprintf(stderr, "tftp: "); perror(cp);
E 12
E 6
			continue;
		}
D 9
		recvfile(fd, src);
E 9
I 9
D 12
		(void) recvfile(fd, src);
E 12
I 12
		if (verbose)
			printf("getting from %s:%s to %s [%s]\n",
				hostname, src, cp, mode);
		sin.sin_port = port;
		recvfile(fd, src, mode);
E 12
E 9
	}
}

getusage(s)
I 14
char * s;
E 14
{
	printf("usage: %s host:file host:file ... file, or\n", s);
	printf("       %s file file ... file if connected\n", s);
}

I 6
int	rexmtval = TIMEOUT;

setrexmt(argc, argv)
	char *argv[];
{
	int t;

	if (argc < 2) {
		strcpy(line, "Rexmt-timeout ");
		printf("(value) ");
		gets(&line[strlen(line)]);
		makeargv();
		argc = margc;
		argv = margv;
	}
	if (argc != 2) {
		printf("usage: %s value\n", argv[0]);
		return;
	}
	t = atoi(argv[1]);
	if (t < 0)
		printf("%s: bad value\n", t);
	else
		rexmtval = t;
}

int	maxtimeout = 5 * TIMEOUT;

settimeout(argc, argv)
	char *argv[];
{
	int t;

	if (argc < 2) {
		strcpy(line, "Maximum-timeout ");
		printf("(value) ");
		gets(&line[strlen(line)]);
		makeargv();
		argc = margc;
		argv = margv;
	}
	if (argc != 2) {
		printf("usage: %s value\n", argv[0]);
		return;
	}
	t = atoi(argv[1]);
	if (t < 0)
		printf("%s: bad value\n", t);
	else
		maxtimeout = t;
}

E 6
status(argc, argv)
	char *argv[];
{
	if (connected)
D 2
		printf("Connected to %s.\n", host_name);
E 2
I 2
		printf("Connected to %s.\n", hostname);
E 2
	else
		printf("Not connected.\n");
D 9
	printf("Mode: %s Verbose: %s Tracing: %s\n", mode,
		verbose ? "on" : "off", trace ? "on" : "off");
E 9
I 9
D 12
	printf("Mode: %s Tracing: %s\n", mode, trace ? "on" : "off");
E 12
I 12
	printf("Mode: %s Verbose: %s Tracing: %s\n", mode,
		verbose ? "on" : "off", trace ? "on" : "off");
E 12
E 9
I 6
	printf("Rexmt-interval: %d seconds, Max-timeout: %d seconds\n",
		rexmtval, maxtimeout);
E 6
}

intr()
{
I 6
D 12

E 12
I 12
	signal(SIGALRM, SIG_IGN);
E 12
I 8
	alarm(0);
E 8
E 6
	longjmp(toplevel, -1);
}

char *
tail(filename)
	char *filename;
{
	register char *s;
	
	while (*filename) {
		s = rindex(filename, '/');
		if (s == NULL)
			break;
		if (s[1])
			return (s + 1);
		*s = '\0';
	}
	return (filename);
}

/*
 * Command parser.
 */
command(top)
	int top;
{
	register struct cmd *c;

	if (!top)
		putchar('\n');
D 6
	else
		sigset(SIGINT, SIG_DFL);
E 6
	for (;;) {
		printf("%s> ", prompt);
D 11
		if (gets(line) == 0)
D 6
			break;
E 6
I 6
			continue;
E 11
I 11
D 12
		if (gets(line) == 0) {
			if (feof(stdin))
				quit();
			else
				continue;
		}
E 12
I 12
D 13
		if (gets(line) == 0)
			continue;
E 13
I 13
		if (gets(line) == 0) {
			if (feof(stdin)) {
				quit();
			} else {
				continue;
			}
		}
E 13
E 12
E 11
E 6
		if (line[0] == 0)
D 6
			break;
E 6
I 6
			continue;
E 6
		makeargv();
		c = getcmd(margv[0]);
		if (c == (struct cmd *)-1) {
			printf("?Ambiguous command\n");
			continue;
		}
		if (c == 0) {
			printf("?Invalid command\n");
			continue;
		}
		(*c->handler)(margc, margv);
D 6
		if (c->handler != help)
			break;
E 6
	}
D 6
	longjmp(toplevel, 1);
E 6
}

struct cmd *
getcmd(name)
	register char *name;
{
	register char *p, *q;
	register struct cmd *c, *found;
	register int nmatches, longest;

	longest = 0;
	nmatches = 0;
	found = 0;
	for (c = cmdtab; p = c->name; c++) {
		for (q = name; *q == *p++; q++)
			if (*q == 0)		/* exact match? */
				return (c);
		if (!*q) {			/* the name was a prefix */
			if (q - name > longest) {
				longest = q - name;
				nmatches = 1;
				found = c;
			} else if (q - name == longest)
				nmatches++;
		}
	}
	if (nmatches > 1)
		return ((struct cmd *)-1);
	return (found);
}

/*
 * Slice a string up into argc/argv.
 */
makeargv()
{
	register char *cp;
	register char **argp = margv;

	margc = 0;
	for (cp = line; *cp;) {
		while (isspace(*cp))
			cp++;
		if (*cp == '\0')
			break;
		*argp++ = cp;
		margc += 1;
		while (*cp != '\0' && !isspace(*cp))
			cp++;
		if (*cp == '\0')
			break;
		*cp++ = '\0';
	}
	*argp++ = 0;
}

/*VARARGS*/
quit()
{
	exit(0);
}

/*
 * Help command.
D 3
 * Call each command handler with argc == 0 and argv[0] == name.
E 3
 */
help(argc, argv)
	int argc;
	char *argv[];
{
	register struct cmd *c;

	if (argc == 1) {
		printf("Commands may be abbreviated.  Commands are:\n\n");
		for (c = cmdtab; c->name; c++)
			printf("%-*s\t%s\n", HELPINDENT, c->name, c->help);
		return;
	}
	while (--argc > 0) {
		register char *arg;
		arg = *++argv;
		c = getcmd(arg);
		if (c == (struct cmd *)-1)
			printf("?Ambiguous help command %s\n", arg);
		else if (c == (struct cmd *)0)
			printf("?Invalid help command %s\n", arg);
		else
			printf("%s\n", c->help);
	}
}

D 9
/*
 * Call routine with argc, argv set from args (terminated by 0).
 */
/* VARARGS2 */
call(routine, args)
	int (*routine)();
	int args;
{
	register int *argp;
	register int argc;

	for (argc = 0, argp = &args; *argp++ != 0; argc++)
		;
	(*routine)(argc, &args);
}

E 9
/*VARARGS*/
settrace()
{
	trace = !trace;
	printf("Packet tracing %s.\n", trace ? "on" : "off");
I 12
}

/*VARARGS*/
setverbose()
{
	verbose = !verbose;
	printf("Verbose mode %s.\n", verbose ? "on" : "off");
E 12
D 9
}

/*VARARGS*/
setverbose()
{
	verbose = !verbose;
	printf("Verbose mode %s.\n", verbose ? "on" : "off");
E 9
}
D 2

E 2
E 1
