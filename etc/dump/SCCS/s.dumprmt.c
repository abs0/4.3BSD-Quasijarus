h14747
s 00006/00006/00244
d D 5.5 87/10/22 10:52:59 bostic 17 16
c ANSI C; sprintf now returns an int.
e
s 00000/00002/00250
d D 5.4 85/12/11 18:36:20 karels 16 15
c let's try SO_SNDBUF again
e
s 00001/00001/00251
d D 5.3 85/09/17 17:54:17 mckusick 15 14
c return a value from rmtopen()
e
s 00001/00001/00251
d D 5.2 85/06/18 21:07:02 mckusick 14 13
c dumpretore.h moves into protocols
e
s 00009/00001/00243
d D 5.1 85/06/05 08:46:48 dist 13 12
c Add copyright
e
s 00002/00000/00242
d D 1.10 85/05/07 19:01:56 mckusick 12 10
c get rid of setsockopt for now as it breaks rdump
e
s 00003/00001/00241
d R 1.10 85/05/07 18:47:20 mckusick 11 10
c get rid of setsockopt for now as it breaks rdump
e
s 00003/00002/00239
d D 1.9 85/03/24 18:05:56 mckusick 10 9
c retry setsockopt until an agreeable size is found
e
s 00012/00002/00229
d D 1.8 84/12/19 11:55:53 ralph 9 7
c use setsockopt to increase buffer size
e
s 00016/00004/00227
d R 1.8 84/12/19 11:47:11 ralph 8 7
c use setsockopt to increase buffer size.
e
s 00007/00001/00224
d D 1.7 84/04/12 09:33:40 karels 7 6
c don't assume that we're root
e
s 00001/00001/00224
d D 1.6 83/07/01 03:07:37 sam 6 5
c from sun
e
s 00001/00001/00224
d D 1.5 83/06/12 02:44:00 sam 5 4
c new signals == no libjobs
e
s 00014/00004/00211
d D 1.4 82/11/19 17:51:17 sam 4 3
c update to 4.1c and use netdb.h
e
s 00000/00007/00215
d D 1.3 82/10/11 16:36:32 mckusick 3 2
c get rid of msg() since it is already defined
e
s 00018/00020/00204
d D 1.2 82/05/20 15:13:06 sam 2 1
c forget about reconnecting on error
e
s 00224/00000/00000
d D 1.1 82/05/07 15:43:29 sam 1 0
c date and time created 82/05/07 15:43:29 by sam
e
u
U
t
T
I 1
D 13
static	char *sccsid = "%W% (Berkeley) %G%";
E 13
I 13
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 13
D 2
#include "dump.h"
E 2

I 2
D 4
#include <stdio.h>
E 4
#include <sys/param.h>
E 2
#include <sys/mtio.h>
#include <sys/ioctl.h>
I 9
#include <sys/socket.h>
#include <sys/inode.h>
E 9
D 4
#include <net/in.h>
E 4

I 4
#include <netinet/in.h>

#include <stdio.h>
I 7
#include <pwd.h>
E 7
#include <netdb.h>
I 9
D 14
#include <dumprestor.h>
E 14
I 14
#include <protocols/dumprestore.h>
E 14
E 9

E 4
#define	TS_CLOSED	0
#define	TS_OPEN		1

static	int rmtstate = TS_CLOSED;
int	rmtape;
int	rmtconnaborted();
char	*rmtpeer;

I 9
extern int ntrec;		/* blocking factor on tape */

E 9
rmthost(host)
	char *host;
{

	rmtpeer = host;
D 5
	sigset(SIGPIPE, rmtconnaborted);
E 5
I 5
	signal(SIGPIPE, rmtconnaborted);
E 5
	rmtgetconn();
	if (rmtape < 0)
D 2
		rmtreconnect();
E 2
I 2
D 9
		exit(1);
E 9
I 9
		return (0);
	return (1);
E 9
E 2
}

rmtconnaborted()
{

D 2
	msg("Lost connection to tape server.\n");
	if (rmtape >= 0) {
		close(rmtape);
		rmtape = -1;
	}
	exit(X_REWRITE);
E 2
I 2
D 9
	fprintf(stderr, "Lost connection to remote host.\n");
E 9
I 9
	fprintf(stderr, "rdump: Lost connection to remote host.\n");
E 9
	exit(1);
E 2
}

D 2
rmtreconnect()
{

	do {
		if (query("Retry conection to remote host?") == 0)
			exit(X_ABORT);
		rmtgetconn();
	} while (rmtape < 0);
}

E 2
rmtgetconn()
{
I 4
	static struct servent *sp = 0;
I 7
	struct passwd *pw;
	char *name = "root";
I 9
	int size;
E 9
E 7
E 4

D 4
	rmtape = rcmd(&rmtpeer, IPPORT_CMDSERVER,
	    "root", "root", "/etc/rmt", 0);
E 4
I 4
	if (sp == 0) {
		sp = getservbyname("shell", "tcp");
		if (sp == 0) {
			fprintf(stderr, "rdump: shell/tcp: unknown service\n");
			exit(1);
		}
	}
D 7
	rmtape = rcmd(&rmtpeer, sp->s_port, "root", "root", "/etc/rmt", 0);
E 7
I 7
	pw = getpwuid(getuid());
	if (pw && pw->pw_name)
		name = pw->pw_name;
	rmtape = rcmd(&rmtpeer, sp->s_port, name, name, "/etc/rmt", 0);
I 12
D 16
#ifdef notdef	/* broken */
E 16
E 12
I 9
	size = ntrec * TP_BSIZE;
D 10
	if (setsockopt(rmtape, SOL_SOCKET, SO_SNDBUF, &size, sizeof (size)) < 0)
		fprintf(stderr, "rdump: Warning: setsockopt buffer size failed.\n");
E 10
I 10
	while (size > TP_BSIZE &&
	    setsockopt(rmtape, SOL_SOCKET, SO_SNDBUF, &size, sizeof (size)) < 0)
		size -= TP_BSIZE;
I 12
D 16
#endif notdef
E 16
E 12
E 10
E 9
E 7
E 4
}

rmtopen(tape, mode)
	char *tape;
	int mode;
{
	char buf[256];

D 17
	sprintf(buf, "O%s\n%d\n", tape, mode);
E 17
I 17
	(void)sprintf(buf, "O%s\n%d\n", tape, mode);
E 17
D 15
	rmtcall(tape, buf);
E 15
	rmtstate = TS_OPEN;
I 15
	return (rmtcall(tape, buf));
E 15
}

rmtclose()
{

	if (rmtstate != TS_OPEN)
		return;
	rmtcall("close", "C\n");
	rmtstate = TS_CLOSED;
}

rmtread(buf, count)
	char *buf;
	int count;
{
	char line[30];
	int n, i, cc;
I 2
	extern errno;
E 2

D 17
	sprintf(line, "R%d\n", count);
E 17
I 17
	(void)sprintf(line, "R%d\n", count);
E 17
	n = rmtcall("read", line);
D 2
	if (n < 0)
E 2
I 2
	if (n < 0) {
		errno = n;
E 2
		return (-1);
I 2
	}
E 2
	for (i = 0; i < n; i += cc) {
		cc = read(rmtape, buf+i, n - i);
D 2
		if (cc <= 0)
E 2
I 2
		if (cc <= 0) {
E 2
			rmtconnaborted();
I 2
		}
E 2
	}
	return (n);
}

rmtwrite(buf, count)
	char *buf;
	int count;
{
	char line[30];

D 17
	sprintf(line, "W%d\n", count);
E 17
I 17
	(void)sprintf(line, "W%d\n", count);
E 17
	write(rmtape, line, strlen(line));
	write(rmtape, buf, count);
	return (rmtreply("write"));
}

rmtwrite0(count)
	int count;
{
	char line[30];

D 17
	sprintf(line, "W%d\n", count);
E 17
I 17
	(void)sprintf(line, "W%d\n", count);
E 17
	write(rmtape, line, strlen(line));
}

rmtwrite1(buf, count)
	char *buf;
	int count;
{

	write(rmtape, buf, count);
}

rmtwrite2()
{
	int i;

	return (rmtreply("write"));
}

rmtseek(offset, pos)
	int offset, pos;
{
	char line[80];

D 17
	sprintf(line, "L%d\n%d\n", offset, pos);
E 17
I 17
	(void)sprintf(line, "L%d\n%d\n", offset, pos);
E 17
	return (rmtcall("seek", line));
}

struct	mtget mts;

struct mtget *
rmtstatus()
{
	register int i;
	register char *cp;

	if (rmtstate != TS_OPEN)
		return (0);
	rmtcall("status", "S\n");
	for (i = 0, cp = (char *)&mts; i < sizeof(mts); i++)
		*cp++ = rmtgetb();
	return (&mts);
}

rmtioctl(cmd, count)
	int cmd, count;
{
	char buf[256];

	if (count < 0)
		return (-1);
D 17
	sprintf(buf, "I%d\n%d\n", cmd, count);
E 17
I 17
	(void)sprintf(buf, "I%d\n%d\n", cmd, count);
E 17
D 6
	rmtcall("ioctl", buf);
E 6
I 6
	return (rmtcall("ioctl", buf));
E 6
}

rmtcall(cmd, buf)
	char *cmd, *buf;
{

	if (write(rmtape, buf, strlen(buf)) != strlen(buf))
		rmtconnaborted();
	return (rmtreply(cmd));
}

rmtreply(cmd)
	char *cmd;
{
	register int c;
	char code[30], emsg[BUFSIZ];

	rmtgets(code, sizeof (code));
	if (*code == 'E' || *code == 'F') {
		rmtgets(emsg, sizeof (emsg));
		msg("%s: %s\n", cmd, emsg, code + 1);
		if (*code == 'F') {
			rmtstate = TS_CLOSED;
			return (-1);
		}
		return (-1);
	}
	if (*code != 'A') {
		msg("Protocol to remote tape server botched (code %s?).\n",
		    code);
		rmtconnaborted();
	}
	return (atoi(code + 1));
}

rmtgetb()
{
	char c;

	if (read(rmtape, &c, 1) != 1)
		rmtconnaborted();
	return (c);
}

rmtgets(cp, len)
	char *cp;
	int len;
{

	while (len > 1) {
		*cp = rmtgetb();
		if (*cp == '\n') {
			cp[1] = 0;
			return;
		}
		cp++;
		len--;
	}
	msg("Protocol to remote tape server botched (in rmtgets).\n");
	rmtconnaborted();
I 2
}
D 3

msg(cp, a1, a2, a3)
	char *cp;
{

	fprintf(stderr, cp, a1, a2, a3);
E 2
}
E 3
E 1
