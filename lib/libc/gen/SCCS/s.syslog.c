h22868
s 00010/00006/00203
d D 5.16 88/06/27 17:34:15 bostic 25 24
c install approved copyright notice
e
s 00016/00013/00193
d D 5.15 88/05/31 10:49:08 karels 24 23
c use connect instead of sendto (for chrooted programs)
e
s 00001/00001/00205
d D 5.14 88/05/20 17:28:26 karels 23 22
c ... and do it right
e
s 00017/00008/00189
d D 5.13 88/03/24 16:51:28 karels 22 21
c pri 0 is legal; clear facility bits before computing pri mask;
c check for nonsensical values
e
s 00005/00005/00192
d D 5.12 87/10/22 17:45:34 bostic 21 20
c ANSI C; sprintf now returns an int.
e
s 00001/00001/00196
d D 5.11 87/09/30 12:19:50 bostic 20 19
c long/int bug; bug report 4.3BSD/lib/24
e
s 00002/00002/00195
d D 5.10 87/04/20 12:17:30 karels 19 18
c use header macro
e
s 00006/00004/00191
d D 5.9 86/05/07 15:18:41 karels 18 16
c fix problems created by using vfork
e
s 00007/00005/00190
d R 5.9 86/05/07 14:36:48 karels 17 16
c fix problems created by using vfork
e
s 00005/00004/00190
d D 5.8 86/04/24 09:21:47 karels 16 15
c add LOG_NOWAIT, correct console logging
e
s 00004/00003/00190
d D 5.7 86/03/13 20:36:45 karels 15 14
c oops, too much Fortran lately
e
s 00002/00002/00191
d D 5.6 86/03/09 19:59:20 donn 14 13
c added LIBC_SCCS condition for sccs ids
e
s 00003/00002/00190
d D 5.5 86/03/08 20:25:22 karels 13 12
c don't need to print priority on console; s/fork/vfork
e
s 00003/00002/00189
d D 5.4 85/10/13 15:21:46 eric 12 11
c use LOG_NDELAY to \immediately/ open log; LOG_ODELAY is the default
e
s 00005/00000/00186
d D 5.3 85/09/17 22:24:16 eric 11 10
c timeout on attempts to open the console if the log is unavailable
e
s 00034/00021/00152
d D 5.2 85/09/17 18:37:08 eric 10 9
c changes to support facility/level mode of priorities
e
s 00007/00001/00166
d D 5.1 85/05/30 10:51:50 dist 9 8
c Add copyright
e
s 00003/00001/00164
d D 4.7 85/02/20 11:02:26 ralph 8 7
c make the default priority mask ignore kernel priorities.
e
s 00014/00006/00151
d D 4.6 85/02/04 15:16:00 ralph 7 6
c changes for more priorities & added LOG_ODELAY to delay open.
e
s 00010/00010/00147
d D 4.5 84/12/14 14:53:56 ralph 6 5
c changes for more priorities and use mask instead of range.
e
s 00017/00015/00140
d D 4.4 84/08/16 10:11:16 ralph 5 4
c standardize log format, save errno.
e
s 00001/00000/00154
d D 4.3 84/05/04 14:58:15 ralph 4 3
c close socket on exec() since descriptor var is static and gets cleared
e
s 00096/00087/00058
d D 4.2 84/04/25 11:36:33 ralph 3 1
c uses UNIX domain sockets now.
e
s 00002/00000/00145
d R 4.2 83/06/24 00:30:13 sam 2 1
c missing closes on files
e
s 00145/00000/00000
d D 4.1 83/05/27 11:12:45 sam 1 0
c date and time created 83/05/27 11:12:45 by sam
e
u
U
t
T
I 9
/*
D 22
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 22
I 22
 * Copyright (c) 1983, 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 25
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 25
I 25
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
E 25
E 22
 */

E 9
I 1
D 14
#ifndef lint
E 14
I 14
#if defined(LIBC_SCCS) && !defined(lint)
E 14
D 5
static char SccsId[] =	"%W% (Berkeley) %G%";
E 5
I 5
static char sccsid[] = "%W% (Berkeley) %G%";
E 5
D 9
#endif
E 9
I 9
D 14
#endif not lint
E 14
I 14
D 22
#endif LIBC_SCCS and not lint
E 22
I 22
#endif /* LIBC_SCCS and not lint */
E 22
E 14
E 9
D 25

E 25
I 22

E 22
/*
 * SYSLOG -- print message on log file
 *
 * This routine looks a lot like printf, except that it
 * outputs to the log file instead of the standard output.
D 3
 * Also, it prints the module name in front of lines,
 * and has some other formatting types (or will sometime).
 * Also, it adds a newline on the end of messages.
E 3
I 3
 * Also:
 *	adds a timestamp,
 *	prints the module name in front of the message,
 *	has some other formatting types (or will sometime),
 *	adds a newline on the end of the message.
E 3
 *
D 3
 * The output of this routine is intended to be read by
 * /etc/syslog, which will add timestamps.
E 3
I 3
 * The output of this routine is intended to be read by /etc/syslogd.
I 5
 *
 * Author: Eric Allman
 * Modified to use UNIX domain IPC by Ralph Campbell
E 5
E 3
 */
I 3

E 3
#include <sys/types.h>
#include <sys/socket.h>
D 3
#include <netinet/in.h>

E 3
I 3
#include <sys/file.h>
I 11
D 15
#include <signal.h>
E 11
E 3
#include <syslog.h>
E 15
I 15
#include <sys/signal.h>
#include <sys/syslog.h>
E 15
#include <netdb.h>
I 15
#include <strings.h>
E 15

D 3
#define	MAXLINE	1024		/* max message size */
#define BUFSLOP	20		/* space to allow for "extra stuff" */
#define NULL	0		/* manifest */
E 3
I 3
#define	MAXLINE	1024			/* max message size */
#define NULL	0			/* manifest */
E 3

I 7
D 10
#define mask(p)	(1 << (p))
#define IMPORTANT (mask(KERN_EMERG)|mask(KERN_ALERT)|mask(KERN_ERR)|mask(KERN_FAIL)\
	|mask(KERN_RECOV)|mask(KERN_INFO)|mask(LOG_EMERG)|mask(LOG_ALERT)\
	|mask(LOG_CRIT)|mask(LOG_ERR)|mask(LOG_FAIL))
E 10
I 10
D 19
#define PRIMASK(p)	(1 << ((p) & LOG_PRIMASK))
E 19
D 24
#define PRIFAC(p)	(((p) & LOG_FACMASK) >> 3)
I 22
					/* XXX should be in <syslog.h> */
E 24
E 22
#define IMPORTANT 	LOG_ERR
E 10

E 7
D 3
int	LogFile = -1;		/* fd for log */
int	LogStat	= 0;		/* status bits, set by initlog */
char	*LogTag = NULL;		/* string to tag the entry with */
int	LogMask = LOG_DEBUG;	/* lowest priority to be logged */
E 3
I 3
static char	logname[] = "/dev/log";
static char	ctty[] = "/dev/console";
E 3

D 3
struct sockaddr_in SyslogAddr;
static char *SyslogHost = LOG_HOST;
E 3
I 3
static int	LogFile = -1;		/* fd for log */
I 24
static int	connected;		/* have done connect */
E 24
static int	LogStat	= 0;		/* status bits, set by openlog() */
D 10
static char	*LogTag = NULL;		/* string to tag the entry with */
D 6
static int	LogMask = LOG_DEBUG;	/* lowest priority to be logged */
E 6
I 6
D 8
static int	LogMask = 0xffffffff;	/* mask of priorities to be logged */
E 8
I 8
		    			/* mask of priorities to be logged */
static int	LogMask = ~(mask(KERN_EMERG)|mask(KERN_ALERT)|mask(KERN_ERR)|
		    mask(KERN_FAIL)|mask(KERN_RECOV)|mask(KERN_INFO));
E 10
I 10
static char	*LogTag = "syslog";	/* string to tag the entry with */
static int	LogMask = 0xff;		/* mask of priorities to be logged */
static int	LogFacility = LOG_USER;	/* default facility code */
E 10
E 8
E 6
E 3

I 3
D 10
static struct sockaddr SyslogAddr;
E 10
I 10
static struct sockaddr SyslogAddr;	/* AF_UNIX address of local logger */
E 10

E 3
extern	int errno, sys_nerr;
extern	char *sys_errlist[];

syslog(pri, fmt, p0, p1, p2, p3, p4)
	int pri;
	char *fmt;
{
D 3
	char buf[MAXLINE+BUFSLOP], outline[MAXLINE + 1];
	register char *b, *f;
E 3
I 3
	char buf[MAXLINE + 1], outline[MAXLINE + 1];
	register char *b, *f, *o;
	register int c;
	long now;
D 5
	int pid;
E 5
I 5
	int pid, olderrno = errno;
E 5
E 3

D 3
	if (LogFile < 0)
		openlog(0, 0);
E 3
	/* see if we should just throw out this message */
D 5
	if (pri > LogMask)
E 5
I 5
D 6
	if (pri < LOG_ALERT || pri > LogMask)
E 6
I 6
D 7
	if (pri <= 0 || pri >= 32 || ((1 << pri) & LogMask) == 0)
E 7
I 7
D 10
	if (pri <= 0 || pri >= 32 || (mask(pri) & LogMask) == 0)
E 10
I 10
D 19
	if (pri <= 0 || PRIFAC(pri) >= LOG_NFACILITIES || (PRIMASK(pri) & LogMask) == 0)
E 19
I 19
D 22
	if (pri <= 0 || PRIFAC(pri) >= LOG_NFACILITIES ||
	    (LOG_MASK(pri) & LogMask) == 0)
E 22
I 22
D 24
	if ((unsigned) PRIFAC(pri) >= LOG_NFACILITIES ||
	    (LOG_MASK(pri & LOG_PRIMASK) & LogMask) == 0 ||
E 24
I 24
	if ((unsigned) LOG_FAC(pri) >= LOG_NFACILITIES ||
	    LOG_MASK(LOG_PRI(pri)) == 0 ||
E 24
D 23
	    (pri &~ (LOG_PRIMASK|LOG_PRIMASK)) != 0)
E 23
I 23
	    (pri &~ (LOG_PRIMASK|LOG_FACMASK)) != 0)
E 23
E 22
E 19
E 10
E 7
E 6
E 5
		return;
D 3
	for (b = buf, f = fmt; f && *f; b = buf) {
		register char c;
E 3
I 3
D 24
	if (LogFile < 0)
E 24
I 24
	if (LogFile < 0 || !connected)
E 24
D 7
		openlog(NULL, 0, 0);
E 7
I 7
D 12
		openlog(LogTag, LogStat & ~LOG_ODELAY, 0);
E 12
I 12
		openlog(LogTag, LogStat | LOG_NDELAY, 0);
E 12
I 10

	/* set default facility if none specified */
	if ((pri & LOG_FACMASK) == 0)
		pri |= LogFacility;

	/* build the message */
E 10
E 7
	o = outline;
D 5
	if (pri > 0) {
		sprintf(o, "<%d>", pri);
		o += strlen(o);
	}
E 5
I 5
D 21
	sprintf(o, "<%d>", pri);
E 21
I 21
	(void)sprintf(o, "<%d>", pri);
E 21
	o += strlen(o);
I 10
	time(&now);
D 21
	sprintf(o, "%.15s ", ctime(&now) + 4);
E 21
I 21
	(void)sprintf(o, "%.15s ", ctime(&now) + 4);
E 21
	o += strlen(o);
E 10
E 5
	if (LogTag) {
		strcpy(o, LogTag);
		o += strlen(o);
	}
	if (LogStat & LOG_PID) {
D 5
		sprintf(o, " (%d)", getpid());
E 5
I 5
D 21
		sprintf(o, "[%d]", getpid());
E 21
I 21
		(void)sprintf(o, "[%d]", getpid());
E 21
E 5
		o += strlen(o);
	}
D 10
	time(&now);
D 5
	sprintf(o, " %.15s -- ", ctime(&now) + 4);
E 5
I 5
	sprintf(o, ": %.15s-- ", ctime(&now) + 4);
E 5
	o += strlen(o);
E 10
I 10
	if (LogTag) {
		strcpy(o, ": ");
		o += 2;
	}
E 10
E 3

D 3
		if (pri > 0 && (LogStat & LOG_COOLIT) == 0) {
			sprintf(b, "<%d>", pri);
			b += strlen(b);
E 3
I 3
	b = buf;
	f = fmt;
	while ((c = *f++) != '\0' && c != '\n' && b < &buf[MAXLINE]) {
		if (c != '%') {
			*b++ = c;
			continue;
E 3
		}
D 3
		if (LogStat & LOG_PID) {
			sprintf(b, "%d ", getpid());
			b += strlen(b);
E 3
I 3
		if ((c = *f++) != 'm') {
			*b++ = '%';
			*b++ = c;
			continue;
E 3
		}
D 3
		if (LogTag) {
			sprintf(b, "%s: ", LogTag);
			b += strlen(b);
		}
		while ((c = *f++) != '\0' && c != '\n' && b < buf + MAXLINE) {
			if (c != '%') {
				*b++ = c;
				continue;
			}
			c = *f++;
			if (c != 'm') {
				*b++ = '%', *b++ = c, *b++ = '\0';
				continue;
			}
			if ((unsigned)errno > sys_nerr)
				sprintf(b, "error %d", errno);
			else
				strcat(b, sys_errlist[errno]);
			b += strlen(b);
		}
		if (c == '\0')
			f--;
		*b++ = '\n', *b = '\0';
		sprintf(outline, buf, p0, p1, p2, p3, p4);
		errno = 0;
		if (LogStat & LOG_DGRAM)
			(void) sendto(LogFile, outline, strlen(outline), 0,
				   &SyslogAddr, sizeof SyslogAddr);
E 3
I 3
D 5
		if ((unsigned)errno > sys_nerr)
			sprintf(b, "error %d", errno);
E 5
I 5
		if ((unsigned)olderrno > sys_nerr)
D 21
			sprintf(b, "error %d", olderrno);
E 21
I 21
			(void)sprintf(b, "error %d", olderrno);
E 21
E 5
E 3
		else
D 3
			(void) write(LogFile, outline, strlen(outline));
		if (errno)
			perror("syslog: sendto");
E 3
I 3
D 5
			strcpy(b, sys_errlist[errno]);
E 5
I 5
			strcpy(b, sys_errlist[olderrno]);
E 5
		b += strlen(b);
E 3
	}
I 3
	*b++ = '\n';
	*b = '\0';
D 21
	sprintf(o, buf, p0, p1, p2, p3, p4);
E 21
I 21
	(void)sprintf(o, buf, p0, p1, p2, p3, p4);
E 21
	c = strlen(outline);
	if (c > MAXLINE)
		c = MAXLINE;
I 10

	/* output the message to the local logger */
E 10
D 24
	if (sendto(LogFile, outline, c, 0, &SyslogAddr, sizeof SyslogAddr) >= 0)
E 24
I 24
	if (send(LogFile, outline, c, 0) >= 0)
E 24
		return;
D 7
	if (pri > LOG_CRIT)
E 7
I 7
D 10
	if (!(LogStat & LOG_CONS) && !(mask(pri) & IMPORTANT))
E 10
I 10
D 16
	if (!(LogStat & LOG_CONS) && (pri & LOG_PRIMASK) <= LOG_ERR)
E 16
I 16
	if (!(LogStat & LOG_CONS))
E 16
E 10
E 7
		return;
I 10

	/* output the message to the console */
E 10
D 13
	pid = fork();
E 13
I 13
	pid = vfork();
E 13
	if (pid == -1)
		return;
	if (pid == 0) {
I 18
		int fd;

E 18
I 11
		signal(SIGALRM, SIG_DFL);
D 20
		sigsetmask(sigblock(0) & ~sigmask(SIGALRM));
E 20
I 20
		sigsetmask(sigblock(0L) & ~sigmask(SIGALRM));
E 20
		alarm(5);
E 11
D 10
		LogFile = open(ctty, O_RDWR);
E 10
I 10
D 18
		LogFile = open(ctty, O_WRONLY);
E 18
I 18
		fd = open(ctty, O_WRONLY);
E 18
I 11
		alarm(0);
E 11
E 10
D 7
		write(LogFile, outline, c);
E 7
I 7
		strcat(o, "\r");
D 13
		write(LogFile, outline, c+1);
E 13
I 13
D 15
		o = outline + index(outline, '>') + 1;
E 15
I 15
		o = index(outline, '>') + 1;
E 15
D 16
		write(LogFile, outline, c + 1 - (o - outline));
E 16
I 16
D 18
		write(LogFile, o, c + 1 - (o - outline));
E 16
E 13
E 7
		close(LogFile);
		exit(0);
E 18
I 18
		write(fd, o, c + 1 - (o - outline));
		close(fd);
		_exit(0);
E 18
	}
D 5
	while (wait((int *)0) != pid)
E 5
I 5
D 16
	while ((c = wait((int *)0)) > 0 && c != pid)
E 5
		;
E 16
I 16
	if (!(LogStat & LOG_NOWAIT))
		while ((c = wait((int *)0)) > 0 && c != pid)
			;
E 16
E 3
}

/*
 * OPENLOG -- open system log
 */
D 3
openlog(ident, logstat)
E 3
I 3
D 10
openlog(ident, logstat, logmask)
E 10
I 10

openlog(ident, logstat, logfac)
E 10
E 3
	char *ident;
D 3
	int logstat;
E 3
I 3
D 10
	int logstat, logmask;
E 10
I 10
	int logstat, logfac;
E 10
E 3
{
D 3
	struct servent *sp;
	struct hostent *hp;
E 3
D 10

D 5
	LogTag = ident;
E 5
I 5
	LogTag = (ident != NULL) ? ident : "syslog";
E 10
I 10
	if (ident != NULL)
		LogTag = ident;
E 10
E 5
	LogStat = logstat;
I 3
D 6
	if (logmask > 0 && logmask <= LOG_DEBUG)
E 6
I 6
D 10
	if (logmask != 0)
E 6
		LogMask = logmask;
E 10
I 10
D 22
	if (logfac != 0)
		LogFacility = logfac & LOG_FACMASK;
E 22
I 22
	if (logfac != 0 && (logfac &~ LOG_FACMASK) == 0)
		LogFacility = logfac;
E 22
E 10
E 3
D 24
	if (LogFile >= 0)
		return;
D 3
	sp = getservbyname("syslog", "udp");
	hp = gethostbyname(SyslogHost);
	if (sp == NULL || hp == NULL)
		goto bad;
	LogFile = socket(AF_INET, SOCK_DGRAM, 0);
	if (LogFile < 0) {
		perror("syslog: socket");
		goto bad;
	}
	bzero(&SyslogAddr, sizeof SyslogAddr);
	SyslogAddr.sin_family = hp->h_addrtype;
	bcopy(hp->h_addr, (char *)&SyslogAddr.sin_addr, hp->h_length);
	SyslogAddr.sin_port = sp->s_port;
	LogStat |= LOG_DGRAM;
	return;
bad:
	LogStat |= LOG_COOLIT;
	LogStat &= ~LOG_DGRAM;
	LogMask = LOG_CRIT;
	LogFile = open("/dev/console", 1);
	if (LogFile < 0) {
		perror("syslog: /dev/console");
		LogFile = 2;
	}
E 3
I 3
	SyslogAddr.sa_family = AF_UNIX;
	strncpy(SyslogAddr.sa_data, logname, sizeof SyslogAddr.sa_data);
D 7
	LogFile = socket(AF_UNIX, SOCK_DGRAM, 0);
I 4
	fcntl(LogFile, F_SETFD, 1);
E 7
I 7
D 12
	if (!(LogStat & LOG_ODELAY)) {
E 12
I 12
	if (LogStat & LOG_NDELAY) {
E 12
		LogFile = socket(AF_UNIX, SOCK_DGRAM, 0);
		fcntl(LogFile, F_SETFD, 1);
E 24
I 24
	if (LogFile == -1) {
		SyslogAddr.sa_family = AF_UNIX;
		strncpy(SyslogAddr.sa_data, logname, sizeof SyslogAddr.sa_data);
		if (LogStat & LOG_NDELAY) {
			LogFile = socket(AF_UNIX, SOCK_DGRAM, 0);
			fcntl(LogFile, F_SETFD, 1);
		}
E 24
	}
I 24
	if (LogFile != -1 && !connected &&
	    connect(LogFile, &SyslogAddr, sizeof(SyslogAddr)) != -1)
		connected = 1;
E 24
E 7
E 4
E 3
}

/*
 * CLOSELOG -- close the system log
 */
I 12

E 12
closelog()
{

	(void) close(LogFile);
	LogFile = -1;
I 24
	connected = 0;
E 24
I 3
}

/*
 * SETLOGMASK -- set the log mask level
 */
D 6
setlogmask(pri)
	int pri;
E 6
I 6
setlogmask(pmask)
	int pmask;
E 6
{
D 6
	int opri;
E 6
I 6
	int omask;
E 6

D 6
	opri = LogMask;
D 5
	LogMask = pri;
E 5
I 5
	if (pri > 0 && pri <= LOG_DEBUG)
		LogMask = pri;
E 5
	return (opri);
E 6
I 6
	omask = LogMask;
	if (pmask != 0)
		LogMask = pmask;
	return (omask);
E 6
E 3
}
E 1
