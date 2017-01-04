h09337
s 00010/00005/00303
d D 5.17 88/06/27 17:14:09 bostic 27 26
c install approved copyright notice
e
s 00009/00003/00299
d D 5.16 88/03/07 21:17:15 bostic 26 25
c added Berkeley specific header
e
s 00001/00001/00301
d D 5.15 87/11/07 15:45:42 karels 25 24
c minor cleanup
e
s 00001/00001/00301
d D 5.14 87/10/22 17:43:22 bostic 24 23
c ANSI C; sprintf now returns an int.
e
s 00008/00007/00294
d D 5.13 87/09/30 12:27:22 bostic 23 22
c null pointer fix; bug report 4.3BSD/lib/23
e
s 00002/00001/00299
d D 5.12 87/09/30 10:44:55 bostic 22 21
c signals are longs; bug report 4.3BSD/lib/38
e
s 00041/00025/00259
d D 5.11 86/05/06 14:35:11 bloom 21 20
c separate reading of file into its own routine, lpd needed it
e
s 00040/00016/00244
d D 5.10 86/03/30 16:38:13 karels 20 19
c set socket pgrp to avoid races; block SIGURG till done;
c try alternate addresses
e
s 00002/00002/00258
d D 5.9 86/03/09 20:27:05 donn 19 18
c added LIBC_SCCS condition for sccs ids
e
s 00001/00001/00259
d D 5.8 85/10/25 10:28:13 bloom 18 17
c bind has only 3 args now
e
s 00001/00001/00259
d D 5.7 85/09/17 20:07:56 karels 17 16
c I know it works, but ...
e
s 00007/00005/00253
d D 5.6 85/09/10 20:36:17 karels 16 15
c make rresvport always quiet, rcmd do perror on failure;
c don't lose more file descriptors
e
s 00017/00001/00241
d D 5.5 85/09/09 19:42:50 bloom 15 14
c check ownership of .rhosts
e
s 00002/00001/00240
d D 5.4 85/09/09 16:29:08 bloom 14 13
c fix problem with hostname returning name w/o a domain
e
s 00052/00005/00189
d D 5.3 85/09/06 16:50:46 bloom 13 12
c fix ruserok to handle case independent comparisons and for domain naming
e
s 00005/00003/00189
d D 5.2 85/09/06 11:47:13 karels 12 11
c no retries or perror if EADDRNOTAVAIL, so can fail gracefully if no net
e
s 00008/00002/00184
d D 5.1 85/05/30 14:23:08 dist 11 10
c Add copyright
e
s 00016/00006/00170
d D 4.10 85/05/30 12:01:05 bloom 10 9
c make .rhosts a bit more forgiving
e
s 00009/00011/00167
d D 4.9 84/12/07 09:28:19 ralph 9 8
c fix file closes so multiple rcmd's work.
e
s 00000/00006/00178
d D 4.8 83/03/19 14:21:21 sam 8 7
c purge socketaddr call in favor of getsockname
e
s 00009/00008/00175
d D 4.7 83/02/23 13:51:23 sam 7 6
c super user uses only .rhosts for validation
e
s 00005/00001/00178
d D 4.6 83/01/22 18:59:54 sam 6 5
c a bit more careful about write errors
e
s 00008/00012/00171
d D 4.5 83/01/13 17:50:56 sam 5 4
c eliminate socketaddr and options
e
s 00002/00002/00181
d D 4.4 82/12/17 17:06:43 sam 4 3
c pass port numbers around in network order
e
s 00050/00027/00133
d D 4.3 82/11/14 13:55:34 sam 3 2
c merge off 4.1b with 4.1c; and random conversion to netdb library
e
s 00010/00018/00150
d D 4.2 82/10/07 23:42:06 sam 2 1
c use new date base routines
e
s 00168/00000/00000
d D 4.1 82/04/02 10:28:51 wnj 1 0
c date and time created 82/04/02 10:28:51 by wnj
e
u
U
t
T
I 11
/*
 * Copyright (c) 1983 Regents of the University of California.
D 26
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 26
I 26
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 27
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 27
I 27
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
E 27
E 26
 */

E 11
I 1
D 19
#ifndef lint
E 19
I 19
#if defined(LIBC_SCCS) && !defined(lint)
E 19
D 3
static char sccsid[] = "%W% %E%";
E 3
I 3
D 11
static char sccsid[] = "%W% %G%";
E 3
#endif
E 11
I 11
static char sccsid[] = "%W% (Berkeley) %G%";
D 19
#endif not lint
E 19
I 19
D 26
#endif LIBC_SCCS and not lint
E 26
I 26
#endif /* LIBC_SCCS and not lint */
E 26
E 19
E 11

#include <stdio.h>
D 13
#include <sys/types.h>
E 13
I 13
#include <ctype.h>
I 15
#include <pwd.h>
E 15
#include <sys/param.h>
I 20
#include <sys/file.h>
#include <sys/signal.h>
E 20
E 13
#include <sys/socket.h>
I 15
#include <sys/stat.h>
E 15
D 3
#include <net/in.h>
#include <errno.h>
E 3
I 3

#include <netinet/in.h>

E 3
I 2
#include <netdb.h>
I 3
#include <errno.h>
E 3
E 2

extern	errno;
D 24
char	*index(), *sprintf();
E 24
I 24
char	*index();
E 24
D 5
int	rcmdoptions;
E 5

rcmd(ahost, rport, locuser, remuser, cmd, fd2p)
	char **ahost;
D 21
	int rport;
E 21
I 21
	u_short rport;
E 21
	char *locuser, *remuser, *cmd;
	int *fd2p;
{
D 3
	int s, addr, timo = 1;
E 3
I 3
D 20
	int s, timo = 1;
E 20
I 20
D 22
	int s, timo = 1, pid, oldmask;
E 22
I 22
	int s, timo = 1, pid;
	long oldmask;
E 22
E 20
E 3
	struct sockaddr_in sin, sin2, from;
	char c;
D 5
	short port;
E 5
I 3
	int lport = IPPORT_RESERVED - 1;
E 3
I 2
	struct hostent *hp;
E 2

I 20
	pid = getpid();
E 20
D 2
	addr = rhost(ahost);
	if (addr == -1) {
E 2
I 2
	hp = gethostbyname(*ahost);
	if (hp == 0) {
E 2
		fprintf(stderr, "%s: unknown host\n", *ahost);
		return (-1);
	}
I 2
	*ahost = hp->h_name;
E 2
D 20
retry:
D 3
	s = rresvport(rcmdoptions|SO_KEEPALIVE);
E 3
I 3
D 5
	s = rresvport(rcmdoptions|SO_KEEPALIVE, &lport);
E 5
I 5
	s = rresvport(&lport);
E 5
E 3
D 16
	if (s < 0)
E 16
I 16
	if (s < 0) {
		if (errno == EAGAIN)
			fprintf(stderr, "socket: All ports in use\n");
		else
			perror("rcmd: socket");
E 16
		return (-1);
I 16
	}
E 16
D 2
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = addr;
	sin.sin_port = rport;
#ifdef vax
	sin.sin_port = htons(sin.sin_port);
#endif
E 2
I 2
	sin.sin_family = hp->h_addrtype;
D 3
	bcopy(hp->h_addr, &sin.sin_addr, hp->h_length);
	sin.sin_port = htons(rport);
E 2
	if (connect(s, &sin) < 0) {
E 3
I 3
	bcopy(hp->h_addr, (caddr_t)&sin.sin_addr, hp->h_length);
D 4
	sin.sin_port = htons((u_short)rport);
E 4
I 4
	sin.sin_port = rport;
E 4
	if (connect(s, (caddr_t)&sin, sizeof (sin), 0) < 0) {
E 20
I 20
	oldmask = sigblock(sigmask(SIGURG));
	for (;;) {
		s = rresvport(&lport);
		if (s < 0) {
			if (errno == EAGAIN)
				fprintf(stderr, "socket: All ports in use\n");
			else
				perror("rcmd: socket");
			sigsetmask(oldmask);
			return (-1);
		}
		fcntl(s, F_SETOWN, pid);
		sin.sin_family = hp->h_addrtype;
		bcopy(hp->h_addr_list[0], (caddr_t)&sin.sin_addr, hp->h_length);
		sin.sin_port = rport;
		if (connect(s, (caddr_t)&sin, sizeof (sin), 0) >= 0)
			break;
E 20
I 9
		(void) close(s);
E 9
		if (errno == EADDRINUSE) {
D 9
			close(s);
E 9
			lport--;
D 20
			goto retry;
E 20
I 20
			continue;
E 20
		}
E 3
		if (errno == ECONNREFUSED && timo <= 16) {
D 9
			(void) close(s);
E 9
			sleep(timo);
			timo *= 2;
D 20
			goto retry;
E 20
I 20
			continue;
E 20
		}
I 20
		if (hp->h_addr_list[1] != NULL) {
			int oerrno = errno;

			fprintf(stderr,
			    "connect to address %s: ", inet_ntoa(sin.sin_addr));
			errno = oerrno;
			perror(0);
			hp->h_addr_list++;
			bcopy(hp->h_addr_list[0], (caddr_t)&sin.sin_addr,
			    hp->h_length);
			fprintf(stderr, "Trying %s...\n",
				inet_ntoa(sin.sin_addr));
			continue;
		}
E 20
D 3
		perror(*ahost);
E 3
I 3
		perror(hp->h_name);
I 20
		sigsetmask(oldmask);
E 20
E 3
		return (-1);
	}
I 3
	lport--;
E 3
	if (fd2p == 0) {
		write(s, "", 1);
D 5
		port = 0;
E 5
I 5
		lport = 0;
E 5
	} else {
		char num[8];
D 3
		int s2 = rresvport(rcmdoptions|SO_ACCEPTCONN);
E 3
I 3
D 5
		int s2 = rresvport(rcmdoptions|SO_ACCEPTCONN, &lport), s3;
E 5
I 5
		int s2 = rresvport(&lport), s3;
I 9
		int len = sizeof (from);
E 9
E 5
E 3

D 9
		if (s2 < 0) {
			(void) close(s);
			return (-1);
		}
E 9
I 9
		if (s2 < 0)
			goto bad;
E 9
I 3
		listen(s2, 1);
E 3
D 5
		socketaddr(s2, &sin2);
D 2
		port = sin2.sin_port;
#if vax
		port = htons((u_short)port);
#endif
E 2
I 2
		port = htons((u_short)sin2.sin_port);
E 2
		(void) sprintf(num, "%d", port);
E 5
I 5
		(void) sprintf(num, "%d", lport);
E 5
D 6
		(void) write(s, num, strlen(num)+1);
E 6
I 6
		if (write(s, num, strlen(num)+1) != strlen(num)+1) {
			perror("write: setting up stderr");
			(void) close(s2);
			goto bad;
		}
E 6
D 3
		if (accept(s2, &from) < 0) {
E 3
I 3
D 9
		{ int len = sizeof (from);
		  s3 = accept(s2, &from, &len, 0);
		  close(s2);
		  if (s3 < 0) {
E 9
I 9
		s3 = accept(s2, &from, &len, 0);
		(void) close(s2);
		if (s3 < 0) {
E 9
E 3
			perror("accept");
I 3
D 5
			port = 0;
E 5
I 5
			lport = 0;
E 5
E 3
			goto bad;
I 3
D 9
		  }
E 9
E 3
		}
D 2
#if vax
E 2
D 3
		from.sin_port = ntohs(from.sin_port);
E 3
I 3
		*fd2p = s3;
		from.sin_port = ntohs((u_short)from.sin_port);
E 3
D 2
#endif
E 2
		if (from.sin_family != AF_INET ||
		    from.sin_port >= IPPORT_RESERVED) {
			fprintf(stderr,
			    "socket: protocol failure in circuit setup.\n");
D 3
			goto bad;
E 3
I 3
			goto bad2;
E 3
		}
D 3
		*fd2p = s2;
E 3
	}
	(void) write(s, locuser, strlen(locuser)+1);
	(void) write(s, remuser, strlen(remuser)+1);
	(void) write(s, cmd, strlen(cmd)+1);
	if (read(s, &c, 1) != 1) {
		perror(*ahost);
D 3
		goto bad;
E 3
I 3
		goto bad2;
E 3
	}
	if (c != 0) {
		while (read(s, &c, 1) == 1) {
			(void) write(2, &c, 1);
			if (c == '\n')
				break;
		}
D 3
		goto bad;
E 3
I 3
		goto bad2;
E 3
	}
I 20
	sigsetmask(oldmask);
E 20
	return (s);
D 3
bad:
E 3
I 3
bad2:
E 3
D 5
	if (port)
E 5
I 5
	if (lport)
E 5
		(void) close(*fd2p);
I 3
bad:
E 3
	(void) close(s);
I 20
	sigsetmask(oldmask);
E 20
	return (-1);
}

D 3
rresvport(options)
	int options;
E 3
I 3
D 5
rresvport(options, alport)
	int options, *alport;
E 5
I 5
rresvport(alport)
	int *alport;
E 5
E 3
{
	struct sockaddr_in sin;
D 3
	short lport = IPPORT_RESERVED - 1;
E 3
	int s;

I 3
	sin.sin_family = AF_INET;
D 12
	sin.sin_addr.s_addr = 0;
D 4
	s = socket(0, SOCK_STREAM, 0, 0);
E 4
I 4
	s = socket(AF_INET, SOCK_STREAM, 0, 0);
E 12
I 12
	sin.sin_addr.s_addr = INADDR_ANY;
	s = socket(AF_INET, SOCK_STREAM, 0);
E 12
E 4
	if (s < 0)
		return (-1);
E 3
	for (;;) {
D 3
		sin.sin_family = AF_INET;
D 2
		sin.sin_port = lport;
E 2
I 2
		sin.sin_port = htons(lport);
E 2
		sin.sin_addr.s_addr = 0;
D 2
#ifdef vax
		sin.sin_port = htons(sin.sin_port);
#endif
E 2
		s = socket(SOCK_STREAM, 0, &sin, options);
		if (s >= 0)
E 3
I 3
		sin.sin_port = htons((u_short)*alport);
D 18
		if (bind(s, (caddr_t)&sin, sizeof (sin), 0) >= 0)
E 18
I 18
		if (bind(s, (caddr_t)&sin, sizeof (sin)) >= 0)
E 18
E 3
			return (s);
D 12
		if (errno != EADDRINUSE && errno != EADDRNOTAVAIL) {
E 12
I 12
D 16
		if (errno == EADDRNOTAVAIL)
			return (-1);
E 16
		if (errno != EADDRINUSE) {
E 12
D 16
			perror("socket");
E 16
I 9
			(void) close(s);
E 9
			return (-1);
		}
D 3
		lport--;
		if (lport == IPPORT_RESERVED/2) {
E 3
I 3
		(*alport)--;
		if (*alport == IPPORT_RESERVED/2) {
E 3
D 16
			fprintf(stderr, "socket: All ports in use\n");
E 16
I 9
			(void) close(s);
I 16
			errno = EAGAIN;		/* close */
E 16
E 9
			return (-1);
		}
	}
}

D 7
ruserok(rhost, ruser, luser)
	char *rhost, *ruser, *luser;
E 7
I 7
ruserok(rhost, superuser, ruser, luser)
	char *rhost;
	int superuser;
	char *ruser, *luser;
E 7
{
	FILE *hostf;
D 13
	char ahost[32];
E 13
I 13
	char fhost[MAXHOSTNAMELEN];
D 21
	char ahost[MAXHOSTNAMELEN];
E 21
E 13
	int first = 1;
I 13
	register char *sp, *p;
	int baselen = -1;
E 13

I 13
	sp = rhost;
	p = fhost;
	while (*sp) {
		if (*sp == '.') {
			if (baselen == -1)
				baselen = sp - rhost;
			*p++ = *sp++;
		} else {
			*p++ = isupper(*sp) ? tolower(*sp++) : *sp++;
		}
	}
	*p = '\0';
E 13
D 7
	hostf = fopen("/etc/hosts.equiv", "r");
E 7
I 7
	hostf = superuser ? (FILE *)0 : fopen("/etc/hosts.equiv", "r");
E 7
again:
	if (hostf) {
D 21
		while (fgets(ahost, sizeof (ahost), hostf)) {
I 10
D 13
			register char *p;
E 13
E 10
			char *user;
D 10
			if (index(ahost, '\n'))
				*index(ahost, '\n') = 0;
			user = index(ahost, ' ');
			if (user)
				*user++ = 0;
E 10
I 10

			p = ahost;
			while (*p != '\n' && *p != ' ' && *p != '\t' && *p != '\0')
D 13
				p++;
E 13
I 13
				*p++ = isupper(*p) ? tolower(*p) : *p;
E 13
			if (*p == ' ' || *p == '\t') {
				*p++ = '\0';
				while (*p == ' ' || *p == '\t')
					p++;
				user = p;
				while (*p != '\n' && *p != ' ' && *p != '\t' && *p != '\0')
					p++;
			} else
				user = p;
			*p = '\0';
E 10
D 13
			if (!strcmp(rhost, ahost) &&
E 13
I 13
			if (_checkhost(fhost, ahost, baselen) &&
E 13
D 7
			    !strcmp(ruser, user ? user : luser))
				goto ok;
E 7
I 7
D 10
			    !strcmp(ruser, user ? user : luser)) {
E 10
I 10
			    !strcmp(ruser, *user ? user : luser)) {
E 10
				(void) fclose(hostf);
				return (0);
			}
E 21
I 21
		if (!_validuser(hostf, fhost, luser, ruser, baselen)) {
			(void) fclose(hostf);
			return(0);
E 21
E 7
		}
		(void) fclose(hostf);
	}
	if (first == 1) {
I 15
		struct stat sbuf;
		struct passwd *pwd;
		char pbuf[MAXPATHLEN];

E 15
		first = 0;
D 15
		hostf = fopen(".rhosts", "r");
E 15
I 15
		if ((pwd = getpwnam(luser)) == NULL)
			return(-1);
		(void)strcpy(pbuf, pwd->pw_dir);
		(void)strcat(pbuf, "/.rhosts");
		if ((hostf = fopen(pbuf, "r")) == NULL)
			return(-1);
		(void)fstat(fileno(hostf), &sbuf);
		if (sbuf.st_uid && sbuf.st_uid != pwd->pw_uid) {
			fclose(hostf);
			return(-1);
		}
E 15
		goto again;
	}
	return (-1);
I 13
}

I 21
_validuser(hostf, rhost, luser, ruser, baselen)
char *rhost, *luser, *ruser;
FILE *hostf;
int baselen;
{
	char *user;
	char ahost[MAXHOSTNAMELEN];
	register char *p;

	while (fgets(ahost, sizeof (ahost), hostf)) {
		p = ahost;
		while (*p != '\n' && *p != ' ' && *p != '\t' && *p != '\0') {
			*p = isupper(*p) ? tolower(*p) : *p;
			p++;
		}
		if (*p == ' ' || *p == '\t') {
			*p++ = '\0';
			while (*p == ' ' || *p == '\t')
				p++;
			user = p;
			while (*p != '\n' && *p != ' ' && *p != '\t' && *p != '\0')
				p++;
		} else
			user = p;
		*p = '\0';
		if (_checkhost(rhost, ahost, baselen) &&
		    !strcmp(ruser, *user ? user : luser)) {
			return (0);
		}
	}
	return (-1);
}

E 21
_checkhost(rhost, lhost, len)
char *rhost, *lhost;
int len;
{
D 17
	static char ldomain[MAXHOSTNAMELEN];
E 17
I 17
	static char ldomain[MAXHOSTNAMELEN + 1];
E 17
	static char *domainp = NULL;
I 23
	static int nodomain = 0;
E 23
	register char *cp;

	if (len == -1)
		return(!strcmp(rhost, lhost));
	if (strncmp(rhost, lhost, len))
		return(0);
	if (!strcmp(rhost, lhost))
		return(1);
	if (*(lhost + len) != '\0')
		return(0);
I 23
	if (nodomain)
		return(0);
E 23
	if (!domainp) {
		if (gethostname(ldomain, sizeof(ldomain)) == -1) {
D 25
			domainp = (char *)1;
E 25
I 25
			nodomain = 1;
E 25
			return(0);
		}
		ldomain[MAXHOSTNAMELEN] = NULL;
D 14
		domainp = index(ldomain, '.') + 1;
E 14
I 14
D 23
		if ((domainp = index(ldomain, '.') + 1) == (char *)1)
E 23
I 23
		if ((domainp = index(ldomain, '.')) == (char *)NULL) {
			nodomain = 1;
E 23
			return(0);
E 14
D 23
		cp = domainp;
D 21
		while (*cp)
			*cp++ = isupper(*cp) ? tolower(*cp) : *cp;
E 21
I 21
		while (*cp) {
			*cp = isupper(*cp) ? tolower(*cp) : *cp;
			cp++;
E 23
		}
I 23
		for (cp = ++domainp; *cp; ++cp)
			if (isupper(*cp))
				*cp = tolower(*cp);
E 23
E 21
	}
D 23
	if (domainp == (char *)1)
		return(0);
E 23
	return(!strcmp(domainp, rhost + len +1));
E 13
D 7
ok:
	(void) fclose(hostf);
	return (0);
E 7
I 3
}
D 8

socketaddr(x, y)
{

	syscall(103,x,y);
E 3
}
E 8
E 1
