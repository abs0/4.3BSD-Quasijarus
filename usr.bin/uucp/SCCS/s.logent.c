h21318
s 00102/00122/00115
d D 5.9 88/05/04 13:53:03 rick 9 8
c totally rewritten. syslog interface added for non bsd sites
e
s 00002/00002/00235
d D 5.8 88/04/05 12:06:45 rick 8 7
c use syslog for errors
e
s 00008/00006/00229
d D 5.7 88/02/24 19:59:49 rick 7 6
c log pid on uuxqt and uux
e
s 00017/00015/00218
d D 5.6 85/10/09 16:08:14 bloom 6 5
c still more fixes from rick@seismo
e
s 00003/00003/00230
d D 5.5 85/06/20 09:57:31 bloom 5 4
c fixes from rick adams
e
s 00072/00058/00161
d D 5.4 85/04/10 15:19:56 ralph 4 3
c more changes from rick adams.
e
s 00059/00018/00160
d D 5.3 85/01/22 14:09:22 ralph 3 2
c bug fixes and changes from Rick Adams
e
s 00001/00001/00177
d D 5.2 83/07/02 18:25:17 sam 2 1
c include fixes
e
s 00178/00000/00000
d D 5.1 83/07/02 17:57:15 sam 1 0
c date and time created 83/07/02 17:57:15 by sam
e
u
U
t
T
I 1
#ifndef lint
D 8
static char sccsid[] = "%W% (Berkeley) %G%";
E 8
I 8
static char sccsid[] = "%W%	(Berkeley) %G%";
E 8
#endif

#include "uucp.h"
D 4
#include <sys/types.h>
E 4
I 3
#ifdef BSD4_2
E 3
D 2
#include <time.h>
E 2
I 2
#include <sys/time.h>
I 3
#else
#include <time.h>
#endif
#if defined(USG) || defined(BSD4_2)
#include <fcntl.h>
#endif
E 3
E 2

I 9
extern int errno;
extern int sys_nerr;
extern char *sys_errlist[];

E 9
D 5
extern	time_t	time();

E 5
D 4
/* This logfile stuff was awful -- it did output to an
 * unbuffered stream.
 *
 * This new version just open the single logfile and writes
 * the record in the stdio buffer.  Once that's done, it
 * positions itself at the end of the file (lseek), and
 * writes the buffer out.  This could mangle things but
 * it isn't likely. -- ittvax!swatt
 *
D 3
 * If the files could be opened with "guaranteed append to end",
 * the lseeks could be removed.
 * Using fseek would be slightly cleaner,
 * but would mangle things slightly more often.
E 3
I 3
 * Under USG UNIX & 4.2BSD, the files are opened with "guaranteed append to end"
 * and the lseeks are removed.
E 3
 */


E 4
D 3
FILE *Lp = NULL;
FILE *Sp = NULL;
E 3
I 3
static FILE *Lp = NULL;
static FILE *Sp = NULL;
E 3
D 9
static Ltried = 0;
static Stried = 0;
E 9
I 9
#ifndef USE_SYSLOG
static FILE *Ep = NULL;
#endif /* !USE_SYSLOG */
static int pid = 0;
E 9

I 5
/*LINTLIBRARY*/

E 5
D 4
/*******
 *	logent(text, status)	make log entry
 *	char *text, *status;
 *
 *	return code - none
E 4
I 4
/*
 *	make log entry
E 4
 */
D 4

E 4
D 9
logent(text, status)
char *text, *status;
E 9
I 9
FILE *
get_logfd(pname, logfilename)
char *pname;
char *logfilename;
E 9
{
I 9
	FILE *fp;
	int savemask;
E 9
I 4
#ifdef LOGBYSITE
	char lfile[MAXFULLNAME];
D 9
	static char LogRmtname[64];
E 9
#endif LOGBYSITE
D 9
	if (Rmtname[0] == '\0')
		strcpy(Rmtname, Myname);
E 4
	/* Open the log file if necessary */
E 9
I 9

	savemask = umask(LOGMASK);
E 9
I 4
#ifdef LOGBYSITE
D 9
	if (strcmp(Rmtname, LogRmtname)) {
		if (Lp != NULL)
			fclose(Lp);
		Lp = NULL;
		Ltried = 0;
E 9
I 9
	if (pname != NULL) {
		(void) sprintf(lfile, "%s/%s/%s", LOGBYSITE, pname, Rmtname);
		logfilename = lfile;
E 9
	}
#endif LOGBYSITE
E 4
D 9
	if (Lp == NULL) {
		if (!Ltried) {
			int savemask;
I 3
D 4
#if defined(USG) || defined(BSD4_2)
E 4
I 4
#ifdef F_SETFL
E 4
			int flags;
#endif
E 3
			savemask = umask(LOGMASK);
I 4
#ifdef LOGBYSITE
			(void) sprintf(lfile, "%s/%s/%s", LOGBYSITE, Progname, Rmtname);
			strcpy(LogRmtname, Rmtname);
			Lp = fopen (lfile, "a");
#else !LOGBYSITE
E 4
			Lp = fopen (LOGFILE, "a");
I 4
#endif LOGBYSITE
E 4
			umask(savemask);
I 3
D 4
#if defined(USG) || defined(BSD4_2)
E 4
I 4
#ifdef F_SETFL
E 4
			flags = fcntl(fileno(Lp), F_GETFL, 0);
			fcntl(fileno(Lp), F_SETFL, flags|O_APPEND);
#endif
E 3
		}
		Ltried = 1;
		if (Lp == NULL)
			return;
		fioclex(fileno(Lp));
	}

	/*  make entry in existing temp log file  */
	mlogent(Lp, status, text);
E 9
I 9
	fp = fopen(logfilename, "a");
	umask(savemask);
	if (fp) {
#ifdef		F_SETFL
		int flags;
		flags = fcntl(fileno(fp), F_GETFL, 0);
		fcntl(fileno(Lp), F_SETFL, flags|O_APPEND);
#endif		/* F_SETFL */
		fioclex(fileno(fp));
	} else /* we really want to log this, but it's the logging that failed*/
		perror(logfilename);
	return fp;
E 9
}
I 7
D 9
static int pid = 0;
E 9
E 7

D 4
/***
 *	mlogent(fp, status, text)  - make a log entry
E 4
I 4
/*
 *	make a log entry
E 4
 */
D 9

E 9
mlogent(fp, status, text)
char *text, *status;
register FILE *fp;
{
D 7
	static pid = 0;
E 7
	register struct tm *tp;
	extern struct tm *localtime();
D 6
	time_t clock;
E 6

I 3
	if (text == NULL)
		text = "";
	if (status == NULL)
		status = "";
E 3
D 7
	if (!pid)
E 7
I 7
	if (pid == 0)
E 7
		pid = getpid();
I 3
D 4
	if (Rmtname[0] == '\0')
		strcpy(Rmtname, Myname);
E 4
E 3
D 6
	time(&clock);
	tp = localtime(&clock);
	fprintf(fp, "%s %s ", User, Rmtname);
E 6
D 3
	fprintf(fp, "(%d/%d-%d:%02d-%d) ", tp->tm_mon + 1,
E 3
I 3
#ifdef USG
D 6
	fprintf(fp, "(%d/%d-%2.2d:%2.2d-%d) ", tp->tm_mon + 1,
E 3
		tp->tm_mday, tp->tm_hour, tp->tm_min, pid);
E 6
I 6
	time(&Now.time);
	Now.millitm = 0;
E 6
I 3
D 4
#endif
#ifndef USG
E 4
I 4
#else !USG
E 4
D 6
	fprintf(fp, "(%d/%d-%02d:%02d-%d) ", tp->tm_mon + 1,
		tp->tm_mday, tp->tm_hour, tp->tm_min, pid);
E 6
I 6
	ftime(&Now);
E 6
D 4
#endif
E 4
I 4
#endif !USG
I 6
	tp = localtime(&Now.time);
#ifdef USG
	fprintf(fp, "%s %s (%d/%d-%2.2d:%2.2d-%d) ",
#else !USG
	fprintf(fp, "%s %s (%d/%d-%02d:%02d-%d) ",
#endif !USG
		User, Rmtname, tp->tm_mon + 1, tp->tm_mday,
		tp->tm_hour, tp->tm_min, pid);
E 6
E 4
E 3
D 9
	fprintf(fp, "%s (%s)\n", status, text);
E 9
I 9
	fprintf(fp, "%s %s\n", status, text);
E 9

	/* Since it's buffered */
I 3
D 4
#ifndef USG
E 4
I 4
#ifndef F_SETFL
E 4
E 3
	lseek (fileno(fp), (long)0, 2);
I 3
D 4
#endif
E 4
I 4
#endif !F_SETFL
E 4
E 3
	fflush (fp);
D 3
	if (Debug > 0) {
E 3
I 3
	if (Debug) {
E 3
		fprintf(stderr, "%s %s ", User, Rmtname);
D 3
		fprintf(stderr, "(%d/%d-%d:%02d-%d) ", tp->tm_mon + 1,
E 3
I 3
#ifdef USG
		fprintf(stderr, "(%d/%d-%2.2d:%2.2d-%d) ", tp->tm_mon + 1,
E 3
			tp->tm_mday, tp->tm_hour, tp->tm_min, pid);
I 3
D 4
#endif
#ifndef USG
E 4
I 4
#else !USG
E 4
		fprintf(stderr, "(%d/%d-%02d:%02d-%d) ", tp->tm_mon + 1,
			tp->tm_mday, tp->tm_hour, tp->tm_min, pid);
D 4
#endif
E 4
I 4
#endif !USG
E 4
E 3
D 9
		fprintf(stderr, "%s (%s)\n", status, text);
E 9
I 9
		fprintf(stderr, "%s %s\n", status, text);
E 9
	}
}

D 4
/***
 *	logcls()	close log file
 *
 *	return codes:  none
E 4
I 4
/*
 *	close log file
E 4
 */
D 4

E 4
logcls()
{
	if (Lp != NULL)
		fclose(Lp);
	Lp = NULL;
D 9
	Ltried = 0;
E 9

	if (Sp != NULL)
		fclose (Sp);
	Sp = NULL;
D 9
	Stried = 0;
E 9
I 9
#ifndef USE_SYSLOG
	if (Ep != NULL)
		fclose (Ep);
	Ep = NULL;
#endif /* !USE_SYSLOG */
E 9
}

D 9

E 9
D 4
/***
 *	syslog(text)	make system log entry
 *	char *text;
 *
 *	return codes - none
E 4
I 4
/*
D 9
 *	make system log entry
E 4
 */
D 4

E 4
D 8
syslog(text)
E 8
I 8
log_xferstats(text)
E 8
char *text;
{
	register struct tm *tp;
	extern struct tm *localtime();
D 4
	time_t clock;
E 4
I 4
D 6
	struct timeb clock;
E 6
#ifdef LOGBYSITE
	char lfile[MAXFULLNAME];
	static char SLogRmtname[64];
E 4

I 4
	if (strcmp(Rmtname, SLogRmtname)) {
		if (Sp != NULL)
			fclose(Sp);
		Sp = NULL;
		Stried = 0;
	}
#endif LOGBYSITE
I 7
	if (!pid)
		pid = getpid();
E 7
E 4
	if (Sp == NULL) {
		if (!Stried) {
			int savemask;
I 3
D 4
#if defined(USG) || defined(BSD4_2)
E 4
I 4
#ifdef F_SETFL
E 4
			int flags;
D 4
#endif
E 4
I 4
#endif F_SETFL
E 4
E 3
			savemask = umask(LOGMASK);
D 4
			Sp = fopen(SYSLOG, "a");
E 4
I 4
#ifdef LOGBYSITE
			(void) sprintf(lfile, "%s/xferstats/%s", LOGBYSITE, Rmtname);
			strcpy(SLogRmtname, Rmtname);
			Sp = fopen (lfile, "a");
#else !LOGBYSITE
			Sp = fopen (SYSLOG, "a");
#endif LOGBYSITE
E 4
			umask(savemask);
I 3
D 4
#if defined(USG) || defined(BSD4_2)
E 4
I 4
#ifdef F_SETFL
E 4
			flags = fcntl(fileno(Sp), F_GETFL, 0);
			fcntl(fileno(Sp), F_SETFL, flags|O_APPEND);
D 4
#endif
E 4
I 4
#endif F_SETFL

E 4
E 3
		}
		Stried = 1;
		if (Sp == NULL)
			return;
		fioclex(fileno(Sp));
	}
D 3
			
E 3
I 3

E 3
D 4
	time(&clock);
	tp = localtime(&clock);
E 4
I 4
#ifdef USG
D 6
	time(&clock.time);
	clock.millitm = 0;
E 6
I 6
	time(&Now.time);
	Now.millitm = 0;
E 6
#else !USG
D 6
	ftime(&clock);
E 6
I 6
	ftime(&Now);
E 6
#endif !USG
D 6
	tp = localtime(&clock.time);
E 6
I 6
	tp = localtime(&Now.time);
E 6
E 4

	fprintf(Sp, "%s %s ", User, Rmtname);
D 3
	fprintf(Sp, "(%d/%d-%d:%02d) ", tp->tm_mon + 1,
E 3
I 3
#ifdef USG
D 7
	fprintf(Sp, "(%d/%d-%2.2d:%2.2d) ", tp->tm_mon + 1,
E 3
		tp->tm_mday, tp->tm_hour, tp->tm_min);
E 7
I 7
	fprintf(Sp, "(%d/%d-%2.2d:%2.2d-%d) ", tp->tm_mon + 1,
		tp->tm_mday, tp->tm_hour, tp->tm_min, pid);
E 7
I 3
D 4
#endif
#ifndef USG
E 4
I 4
D 6
	fprintf(Sp, "(%ld) %s\n", clock.time, text);
E 6
I 6
	fprintf(Sp, "(%ld) %s\n", Now.time, text);
E 6
#else !USG
E 4
D 7
	fprintf(Sp, "(%d/%d-%02d:%02d) ", tp->tm_mon + 1,
		tp->tm_mday, tp->tm_hour, tp->tm_min);
E 7
I 7
	fprintf(Sp, "(%d/%d-%02d:%02d-%d) ", tp->tm_mon + 1,
		tp->tm_mday, tp->tm_hour, tp->tm_min, pid);
E 7
D 4
#endif
E 3
	fprintf(Sp, "(%ld) %s\n", clock, text);
E 4
I 4
D 5
	fprintf(Sp, "(%ld.%02d) %s\n", clock.time, clock.millitm/10, text);
E 5
I 5
D 6
	fprintf(Sp, "(%ld.%02u) %s\n", clock.time, clock.millitm/10, text);
E 6
I 6
	fprintf(Sp, "(%ld.%02u) %s\n", Now.time, Now.millitm/10, text);
E 6
E 5
#endif !USG
E 4

	/* Position at end and flush */
I 4
#ifndef F_SETFL
E 4
	lseek (fileno(Sp), (long)0, 2);
I 4
#endif F_SETFL
E 4
	fflush (Sp);
}

/*
E 9
 * Arrange to close fd on exec(II).
 * Otherwise unwanted file descriptors are inherited
 * by other programs.  And that may be a security hole.
 */
D 3
#ifdef SYSIII
#include <fcntl.h>
#endif
#ifndef	SYSIII
E 3
I 3
#ifndef	USG
E 3
#include <sgtty.h>
#endif

fioclex(fd)
int fd;
{
	register int ret;

D 3
#ifdef	SYSIII
E 3
I 3
#if defined(USG) || defined(BSD4_2)
E 3
	ret = fcntl(fd, F_SETFD, 1);	/* Steve Bellovin says this does it */
D 3
#endif
#ifndef	SYSIII
E 3
I 3
#else
E 3
	ret = ioctl(fd, FIOCLEX, STBNULL);
#endif
	if (ret)
		DEBUG(2, "CAN'T FIOCLEX %d\n", fd);
}
I 9

logent(text, status)
char *text, *status;
{
	if (Lp == NULL)
		Lp = get_logfd(Progname, LOGFILE);

	mlogent(Lp, status, text);
}

/*
 *	make system log entry
 */
log_xferstats(text)
char *text;
{
	char tbuf[BUFSIZ];
	if (Sp == NULL)
		Sp = get_logfd("xferstats", SYSLOG);
	sprintf(tbuf, "(%ld.%02u)", Now.time, Now.millitm/10);
	mlogent(Sp, tbuf, text);
}

#ifndef USE_SYSLOG
/*
 * This is for sites that don't have a decent syslog() in their library
 * This routine would be a lot simpler if syslog() didn't permit %m
 * (or if printf did!)
 */
syslog(priority, format, p0, p1, p2, p3, p4)
int priority;
char *format;
{
	char nformat[BUFSIZ], sbuf[BUFSIZ];
	register char *s, *d;
	register int c;
	long now;

	s = format;
	d = nformat;
	while ((c = *s++) != '\0' && c != '\n' && d < &nformat[BUFSIZ]) {
		if (c != '%') {
			*d++ = c;
			continue;
		}
		if ((c = *s++) != 'm') {
			*d++ = '%';
			*d++ = c;
			continue;
		}
		if ((unsigned)errno > sys_nerr)
			sprintf(d, "error %d", errno);
		else
			strcpy(d, sys_errlist[errno]);
		d += strlen(d);
	}
	*d = '\0';

	if (Ep == NULL)
		Ep = get_logfd(NULL, ERRLOG);
	sprintf(sbuf, nformat, p0, p1, p2, p3, p4);
	mlogent(Ep, sbuf, "");
}
#endif /* !USE_SYSLOG */
E 9
E 1
