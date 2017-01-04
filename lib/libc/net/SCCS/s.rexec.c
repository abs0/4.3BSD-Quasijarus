h00365
s 00010/00005/00120
d D 5.5 88/06/27 17:14:34 bostic 13 12
c install approved copyright notice
e
s 00009/00003/00116
d D 5.4 88/03/07 21:17:27 bostic 12 11
c added Berkeley specific header
e
s 00001/00001/00118
d D 5.3 87/10/22 17:43:28 bostic 11 10
c ANSI C; sprintf now returns an int.
e
s 00002/00002/00117
d D 5.2 86/03/09 20:27:31 donn 10 9
c added LIBC_SCCS condition for sccs ids
e
s 00008/00002/00111
d D 5.1 85/05/30 12:08:11 dist 9 8
c Add copyright
e
s 00001/00001/00112
d D 4.8 83/08/18 08:17:28 karels 8 7
c from carl again; third arg to connect was missing
e
s 00002/00002/00111
d D 4.7 83/08/17 10:04:02 sam 7 6
c from carl
e
s 00008/00002/00105
d D 4.6 83/03/19 14:21:33 sam 6 5
c purge socketaddr call in favor of getsockname
e
s 00000/00001/00107
d D 4.5 82/12/17 17:06:11 sam 5 4
c pass port numbers around in network order 
e
s 00029/00028/00079
d D 4.4 82/11/14 13:55:41 sam 4 3
c merge off 4.1b with 4.1c; and random conversion to netdb library
e
s 00087/00023/00020
d D 4.3 82/04/01 10:32:52 root 3 2
c new version with unit 2 and signals
e
s 00001/00001/00042
d D 4.2 82/03/05 00:39:48 wnj 2 1
c static sin
e
s 00043/00000/00000
d D 4.1 82/02/21 14:16:33 mckusick 1 0
c date and time created 82/02/21 14:16:33 by mckusick
e
u
U
t
T
I 9
/*
 * Copyright (c) 1980 Regents of the University of California.
D 12
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 12
I 12
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 13
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 13
I 13
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
E 13
E 12
 */

E 9
I 1
D 3
/* Copyright (c) 1982 Regents of the University of California */
E 3
I 3
D 10
#ifndef lint
E 10
I 10
#if defined(LIBC_SCCS) && !defined(lint)
E 10
D 9
static char sccsid[] = "%W% %E%";
#endif
E 9
I 9
static char sccsid[] = "%W% (Berkeley) %G%";
D 10
#endif not lint
E 10
I 10
D 12
#endif LIBC_SCCS and not lint
E 12
I 12
#endif /* LIBC_SCCS and not lint */
E 12
E 10
E 9
E 3

D 3
static char sccsid[] = "%Z%%M% %I% %G%";

E 3
D 4
#include <stdio.h>
E 4
#include <sys/types.h>
#include <sys/socket.h>
D 4
#include <net/in.h>
E 4
I 4

#include <netinet/in.h>

#include <stdio.h>
#include <netdb.h>
E 4
D 3
#include <wellknown.h>
E 3
I 3
#include <errno.h>
E 3

D 3
char	*index(), *malloc(), *getpass(), *getlogin();
D 2
struct	sockaddr_in sin = { AF_INET };
E 2
I 2
static	struct sockaddr_in sin = { AF_INET };
E 3
I 3
extern	errno;
D 11
char	*index(), *sprintf();
E 11
I 11
char	*index();
E 11
int	rexecoptions;
char	*getpass(), *getlogin();
E 3
E 2

D 3
rexec(ahost, port, cmd, name, pass)
	char **ahost, *cmd, *name, *pass;
E 3
I 3
rexec(ahost, rport, name, pass, cmd, fd2p)
	char **ahost;
	int rport;
	char *name, *pass, *cmd;
	int *fd2p;
E 3
{
D 3
	int rem, addr;
E 3
I 3
D 4
	int s, addr, timo = 1;
E 4
I 4
	int s, timo = 1, s3;
E 4
	struct sockaddr_in sin, sin2, from;
	char c;
	short port;
I 4
	struct hostent *hp;
E 4
E 3

D 4
	addr = rhost(ahost);
	if (addr == -1) {
E 4
I 4
	hp = gethostbyname(*ahost);
	if (hp == 0) {
E 4
D 3
		printf("%s: unknown host\n", *ahost);
E 3
I 3
		fprintf(stderr, "%s: unknown host\n", *ahost);
E 3
		return (-1);
	}
D 3
	sin.sin_port = port;
	sin.sin_addr.s_addr = addr;
E 3
D 4
	ruserpass(*ahost, &name, &pass);
E 4
I 4
	*ahost = hp->h_name;
	ruserpass(hp->h_name, &name, &pass);
E 4
D 3
	rem = socket(SOCK_STREAM, 0, 0, SO_DEBUG);
	if (rem < 0) {
		perror("socket");
E 3
I 3
retry:
D 4
	sin.sin_family = AF_INET;
	sin.sin_port = 0;
	sin.sin_addr.s_addr = 0;
	s = socket(SOCK_STREAM, 0, &sin, rexecoptions|SO_KEEPALIVE);
	if (s < 0)
E 4
I 4
D 7
	s = socket(0, SOCK_STREAM, 0, 0);
E 7
I 7
	s = socket(AF_INET, SOCK_STREAM, 0);
E 7
	if (s < 0) {
		perror("rexec: socket");
E 4
E 3
		return (-1);
D 3
	}
	if (connect(rem, &sin) < 0) {
E 3
I 3
D 4
	sin.sin_addr.s_addr = addr;
E 4
I 4
	}
	sin.sin_family = hp->h_addrtype;
E 4
	sin.sin_port = rport;
D 4
#if vax
	sin.sin_port =
	    ((sin.sin_port << 8) & 0xff00) | ((sin.sin_port >> 8) & 0x00ff);
#endif
E 4
I 4
	bcopy(hp->h_addr, (caddr_t)&sin.sin_addr, hp->h_length);
D 5
	sin.sin_port = htons((u_short)rport);
E 5
E 4
D 8
	if (connect(s, &sin) < 0) {
E 8
I 8
	if (connect(s, &sin, sizeof(sin)) < 0) {
E 8
		if (errno == ECONNREFUSED && timo <= 16) {
			(void) close(s);
			sleep(timo);
			timo *= 2;
			goto retry;
		}
E 3
D 4
		perror(*ahost);
E 4
I 4
		perror(hp->h_name);
E 4
D 3
		close(rem);
E 3
		return (-1);
	}
D 3
	write(rem, name, strlen(name) + 1);
E 3
I 3
	if (fd2p == 0) {
		(void) write(s, "", 1);
		port = 0;
	} else {
		char num[8];
D 6
		int s2;
E 6
I 6
		int s2, sin2len;
E 6
		
D 4
		sin.sin_family = AF_INET;
		sin.sin_port = 0;
		sin.sin_addr.s_addr = 0;
		s2 = socket(SOCK_STREAM, 0, &sin, rexecoptions|SO_ACCEPTCONN);

E 4
I 4
D 7
		s2 = socket(0, SOCK_STREAM, 0, 0);
E 7
I 7
		s2 = socket(AF_INET, SOCK_STREAM, 0);
E 7
E 4
		if (s2 < 0) {
			(void) close(s);
			return (-1);
		}
I 4
		listen(s2, 1);
E 4
D 6
		socketaddr(s2, &sin2);
E 6
I 6
		sin2len = sizeof (sin2);
		if (getsockname(s2, (char *)&sin2, &sin2len) < 0 ||
		  sin2len != sizeof (sin2)) {
			perror("getsockname");
			(void) close(s2);
			goto bad;
		}
E 6
D 4
		port = sin2.sin_port;
#if vax
		port = ((port << 8) & 0xff00) | ((port >> 8) & 0x00ff);
#endif
E 4
I 4
		port = ntohs((u_short)sin2.sin_port);
E 4
		(void) sprintf(num, "%d", port);
		(void) write(s, num, strlen(num)+1);
D 4
		if (accept(s2, &from) < 0) {
E 4
I 4
		{ int len = sizeof (from);
		  s3 = accept(s2, &from, &len, 0);
		  close(s2);
		  if (s3 < 0) {
E 4
			perror("accept");
I 4
			port = 0;
E 4
			goto bad;
I 4
		  }
E 4
		}
D 4
		*fd2p = s2;
E 4
I 4
		*fd2p = s3;
E 4
	}
	(void) write(s, name, strlen(name) + 1);
E 3
	/* should public key encypt the password here */
D 3
	write(rem, pass, strlen(pass) + 1);
	if (cmd)
		write(rem, cmd, strlen(cmd) + 1);
	return (rem);
E 3
I 3
	(void) write(s, pass, strlen(pass) + 1);
	(void) write(s, cmd, strlen(cmd) + 1);
	if (read(s, &c, 1) != 1) {
		perror(*ahost);
		goto bad;
	}
	if (c != 0) {
		while (read(s, &c, 1) == 1) {
			(void) write(2, &c, 1);
			if (c == '\n')
				break;
		}
		goto bad;
	}
	return (s);
bad:
	if (port)
		(void) close(*fd2p);
	(void) close(s);
	return (-1);
E 3
}
E 1
