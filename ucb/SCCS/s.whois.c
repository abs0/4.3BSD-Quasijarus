h05056
s 00001/00000/00087
d D 5.3 88/02/08 14:38:40 leres 6 5
c Must zero sockaddr_in sin before using.
e
s 00001/00001/00086
d D 5.2 85/11/01 14:36:08 bloom 5 4
c sri-nic -> sri-nic.arpa
e
s 00014/00002/00073
d D 5.1 85/05/31 09:40:53 dist 4 2
c Add copyright
e
s 00002/00002/00073
d R 4.3 85/03/25 20:15:24 sam 3 2
c need .arpa for name server
e
s 00005/00008/00070
d D 4.2 83/06/10 09:30:24 ralph 2 1
c fixed argument count test so -h host works.
e
s 00078/00000/00000
d D 4.1 82/12/31 10:49:20 sam 1 0
c date and time created 82/12/31 10:49:20 by sam
e
u
U
t
T
I 4
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 4
I 1
#ifndef lint
D 4
static char sccsid[] = "%W% %E%";
#endif
E 4
I 4
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 4

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

#include <stdio.h>
#include <netdb.h>

D 5
#define	NICHOST	"sri-nic"
E 5
I 5
#define	NICHOST	"sri-nic.arpa"
E 5

main(argc, argv)
	int argc;
	char *argv[];
{
	int s;
	register FILE *sfi, *sfo;
	register char c;
	char *host = NICHOST;
	struct sockaddr_in sin;
	struct hostent *hp;
	struct servent *sp;

	argc--, argv++;
D 2
	if (argc > 2) {
usage:
		fprintf(stderr, "usage: whois [ -h host ] name\n");
		exit(1);
	}
	if (strcmp(*argv, "-h") == 0) {
E 2
I 2
	if (argc > 2 && strcmp(*argv, "-h") == 0) {
E 2
		argv++, argc--;
		host = *argv++;
		argc--;
	}
D 2
	if (argc != 1)
		goto usage;
E 2
I 2
	if (argc != 1) {
		fprintf(stderr, "usage: whois [ -h host ] name\n");
		exit(1);
	}
E 2
	hp = gethostbyname(host);
	if (hp == NULL) {
		fprintf(stderr, "whois: %s: host unknown\n", host);
		exit(1);
	}
	host = hp->h_name;
	s = socket(hp->h_addrtype, SOCK_STREAM, 0, 0);
	if (s < 0) {
		perror("whois: socket");
		exit(2);
	}
I 6
	bzero((caddr_t)&sin, sizeof (sin));
E 6
	sin.sin_family = hp->h_addrtype;
	if (bind(s, &sin, sizeof (sin), 0) < 0) {
		perror("whois: bind");
		exit(3);
	}
	bcopy(hp->h_addr, &sin.sin_addr, hp->h_length);
	sp = getservbyname("whois", "tcp");
	if (sp == NULL) {
		fprintf(stderr, "whois: whois/tcp: unknown service\n");
		exit(4);
	}
	sin.sin_port = sp->s_port;
	if (connect(s, &sin, sizeof (sin), 0) < 0) {
		perror("whois: connect");
		exit(5);
	}
	sfi = fdopen(s, "r");
	sfo = fdopen(s, "w");
	if (sfi == NULL || sfo == NULL) {
		perror("fdopen");
		close(s);
		exit(1);
	}
	fprintf(sfo, "%s\r\n", *argv);
	fflush(sfo);
	while ((c = getc(sfi)) != EOF)
		putchar(c);
}
E 1
