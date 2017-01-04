h52282
s 00069/00018/01488
d D 5.15 06/02/13 03:58:16 msokolov 41 40
c support for Ethernet-attached printers
e
s 00066/00000/01440
d D 5.14 04/09/03 21:50:25 msokolov 40 39
c pp and jp capabilities for printer prep and job prep
c job prep implemented
e
s 00016/00001/01424
d D 5.13 04/09/03 19:02:24 msokolov 39 38
c lpr -O mechanism for specifying processing options for advanced printers
e
s 00004/00000/01421
d D 5.12 04/08/22 21:19:44 msokolov 38 37
c ea capability adds -x and -y arguments to the Fortran filter too
e
s 00070/00002/01351
d D 5.11 04/08/21 19:19:35 msokolov 37 36
c implement bf (banner filter) capability
e
s 00023/00010/01330
d D 5.10 04/08/04 06:08:23 msokolov 36 35
c add ea and pi capabilities to support smarter filters
e
s 00032/00000/01308
d D 5.9 04/07/30 08:31:38 msokolov 35 34
c new ct boolen capability to ensure printer readiness with ^T
e
s 00017/00005/01291
d D 5.8 04/07/29 19:35:31 msokolov 34 33
c adopt some filter-related fixes from CSRG's 1995 work
e
s 00001/00002/01295
d D 5.7 04/07/29 19:06:58 msokolov 33 32
c beware that when opening a not-ready tty line it'll hang and wait
c rather than return an error
e
s 00010/00005/01287
d D 5.6 88/06/30 18:00:07 bostic 32 31
c install approved copyright notice
e
s 00010/00004/01282
d D 5.5 88/05/05 18:08:26 bostic 31 30
c written by Ralph Campbell; add Berkeley specific header
e
s 00005/00000/01281
d D 5.4 85/11/17 15:53:55 eric 30 29
c clean up logging
e
s 00041/00005/01240
d D 5.3 85/11/11 15:34:05 tef 29 28
c Can now specify both lp= and rm=/rp= in same printcap entry; lpd
c will figure out if printer is on local machine or not and do the right thing.
e
s 00001/00001/01244
d D 5.2 85/09/17 19:26:42 eric 28 27
c facilities in syslog
e
s 00007/00001/01238
d D 5.1 85/06/06 10:07:47 dist 27 26
c Add copyright
e
s 00007/00001/01232
d D 4.24 85/02/27 16:19:41 ralph 26 25
c added 'hl' flag to printcap to print the banner last.
e
s 00131/00061/01102
d D 4.23 84/12/05 14:09:07 ralph 25 24
c close -s (symbolic links) security bug.
e
s 00001/00000/01162
d D 4.22 84/11/07 10:01:18 ralph 24 23
c reset width too.
e
s 00001/00001/01161
d D 4.21 84/10/23 09:47:13 ralph 23 22
c truncate error file before starting filter.
e
s 00001/00000/01161
d D 4.20 84/10/23 09:18:09 ralph 22 21
c reset indent before next job.
e
s 00008/00000/01153
d D 4.19 84/09/06 15:24:21 ralph 21 20
c change to new tty driver if xs or xc used.
e
s 00119/00129/01034
d D 4.18 84/07/25 09:08:14 ralph 20 19
c use syslog(). Check for free space before transfering file.
e
s 00014/00004/01149
d D 4.17 84/02/10 11:58:01 ralph 19 18
c don't log errs if remote queue off, use SO_KEEPALIVE to timeout conn.
e
s 00058/00027/01095
d D 4.16 84/01/05 16:13:16 ralph 18 17
c mail filters errors back to the user.
e
s 00008/00008/01114
d D 4.15 83/11/18 10:34:03 ralph 17 16
c use strncpy for jobname, class, etc. to prevent overflows.
e
s 00004/00001/01118
d D 4.14 83/08/18 15:23:26 ralph 16 15
c signal to minor daemon caused /dev/printer to be removed.
e
s 00001/00001/01118
d D 4.13 83/08/02 08:41:47 ralph 15 14
c fixed -c option to `if' filter
e
s 00017/00014/01102
d D 4.12 83/07/27 09:27:15 ralph 14 13
c bug fixes for `rs' printcap entry
e
s 00004/00001/01112
d D 4.11 83/07/17 00:12:01 sam 13 12
c put sccs id's to some use
e
s 00001/00000/01112
d D 4.10 83/06/29 17:09:32 ralph 12 11
c changed to use unix domain ipc.
e
s 00005/00002/01107
d D 4.9 83/06/22 09:31:12 ralph 11 10
c added -n option to print ditroff files.
e
s 00030/00017/01079
d D 4.8 83/06/17 15:07:49 ralph 10 9
c fixed `fc' and `fs' when 0177777 is needed.
e
s 00012/00008/01084
d D 4.7 83/06/15 14:57:32 sam 9 8
c open and flock defines changed
e
s 00040/00026/01052
d D 4.6 83/06/02 12:24:00 ralph 8 7
c made local variables static to improve separation between functions.
e
s 00009/00003/01069
d D 4.5 83/05/23 09:40:11 ralph 7 6
c forgot to close file in sendfile under some error conditions.
e
s 00012/00006/01060
d D 4.4 83/05/19 14:37:39 ralph 6 4
c add `fo' option and now pass indent parameter to `if' filter.
e
s 00002/00001/01065
d R 4.4 83/05/19 11:49:31 ralph 5 4
c added `fo' flag to print form feed after first open of printer.
e
s 00001/00001/01065
d D 4.3 83/05/18 16:45:49 ralph 4 3
c fixed lprm segmentation fault when remote is down.
e
s 00195/00109/00871
d D 4.2 83/05/16 13:40:08 ralph 3 1
c bug fixes and changes for lpc command.
e
s 00193/00107/00873
d R 4.2 83/05/13 11:53:24 ralph 2 1
c bug fixes and changes for lpc command.
e
s 00980/00000/00000
d D 4.1 83/04/29 11:29:35 ralph 1 0
c date and time created 83/04/29 11:29:35 by ralph
e
u
U
t
T
I 27
/*
 * Copyright (c) 1983 Regents of the University of California.
D 31
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 31
I 31
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 32
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 32
I 32
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
E 32
E 31
 */

E 27
I 1
D 13
/*	%M%	%I%	%E%	*/
E 13
I 13
#ifndef lint
D 29
static char sccsid[] = "%W% (Berkeley) %G%";
E 29
I 29
D 31
static char sccsid[] = "@(#)printjob.c	5.2 (Berkeley) 9/17/85";
E 29
D 27
#endif
E 27
I 27
#endif not lint
E 31
I 31
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 31
E 27

E 13
/*
 * printjob -- print jobs in the queue.
 *
 *	NOTE: the lock file is used to pass information to lpq and lprm.
 *	it does not need to be removed because file locks are dynamic.
 */

#include "lp.h"

D 8
#define DORETURN	0	/* absorb fork error */
#define DOABORT		1	/* abort if dofork fails */
E 8
I 8
D 20
#define DORETURN	0		/* absorb fork error */
#define DOABORT		1		/* abort if dofork fails */
E 20
I 20
#define DORETURN	0	/* absorb fork error */
#define DOABORT		1	/* abort if dofork fails */
E 20
E 8

I 25
/*
 * Error tokens
 */
#define REPRINT		-2
#define ERROR		-1
#define	OK		0
#define	FATALERR	1
#define	NOACCT		2
#define	FILTERERR	3
#define	ACCESS		4

E 25
D 8
char	title[80];		/* ``pr'' title */
FILE	*cfp;			/* control file */
int	pfd;			/* printer file descriptor */
int	ofd;			/* output filter file descriptor */
int	lfd;			/* lock file descriptor */
int	pid;			/* pid of lpd process */
int	prchild;		/* id of pr process */
int	child;			/* id of any filters */
int	ofilter;		/* id of output filter, if any */
D 6
int	tof = 1;		/* top of form; init true if open does ff */
E 6
I 6
int	tof;			/* true if at top of form */
E 6
int	remote;			/* non zero if sending files to remote */
E 8
I 8
D 20
static char	title[80];		/* ``pr'' title */
static FILE	*cfp;			/* control file */
static int	pfd;			/* printer file descriptor */
static int	ofd;			/* output filter file descriptor */
static int	lfd;			/* lock file descriptor */
static int	pid;			/* pid of lpd process */
static int	prchild;		/* id of pr process */
static int	child;			/* id of any filters */
static int	ofilter;		/* id of output filter, if any */
static int	tof;			/* true if at top of form */
I 14
static int	count;			/* Number of files actually printed */
E 14
static int	remote;			/* true if sending files to remote */
E 20
I 20
char	title[80];		/* ``pr'' title */
FILE	*cfp;			/* control file */
int	pfd;			/* printer file descriptor */
int	ofd;			/* output filter file descriptor */
int	lfd;			/* lock file descriptor */
int	pid;			/* pid of lpd process */
int	prchild;		/* id of pr process */
int	child;			/* id of any filters */
int	ofilter;		/* id of output filter, if any */
int	tof;			/* true if at top of form */
int	remote;			/* true if sending files to remote */
I 25
dev_t	fdev;			/* device of file pointed to by symlink */
ino_t	fino;			/* inode of file pointed to by symlink */
E 25
E 20
E 8

I 14
D 20
static char	fromhost[32];		/* user's host machine */
E 14
D 8
extern	banner();		/* big character printer */
char	logname[32];		/* user's login name */
char	jobname[32];		/* job or file name */
char	class[32];		/* classification field */
D 3
char	width[10] = "-w";	/* page width for `pr' */
char	length[10] = "-l";	/* page length for `pr' */
E 3
I 3
char	width[10] = "-w";	/* page width in characters */
char	length[10] = "-l";	/* page length in lines */
char	pxwidth[10] = "-x";	/* page width in pixels */
char	pxlength[10] = "-y";	/* page length in pixels */
I 6
char	indent[10] = "-i0";	/* indentation size in characters */
E 8
I 8
static char	logname[32];		/* user's login name */
D 17
static char	jobname[32];		/* job or file name */
E 17
I 17
static char	jobname[100];		/* job or file name */
E 17
static char	class[32];		/* classification field */
static char	width[10] = "-w";	/* page width in characters */
static char	length[10] = "-l";	/* page length in lines */
static char	pxwidth[10] = "-x";	/* page width in pixels */
static char	pxlength[10] = "-y";	/* page length in pixels */
static char	indent[10] = "-i0";	/* indentation size in characters */
I 18
static char	tmpfile[] = "errsXXXXXX"; /* file name for filter output */
E 20
I 20
char	fromhost[32];		/* user's host machine */
char	logname[32];		/* user's login name */
char	jobname[100];		/* job or file name */
char	class[32];		/* classification field */
I 39
char	options[64];		/* processing options */
E 39
char	width[10] = "-w";	/* page width in characters */
char	length[10] = "-l";	/* page length in lines */
char	pxwidth[10] = "-x";	/* page width in pixels */
char	pxlength[10] = "-y";	/* page length in pixels */
char	indent[10] = "-i0";	/* indentation size in characters */
char	tmpfile[] = "errsXXXXXX"; /* file name for filter output */
E 20
E 18
E 8
E 6
E 3

printjob()
{
	struct stat stb;
	register struct queue *q, **qp;
	struct queue **queue;
	register int i, nitems;
	long pidoff;
D 20
	extern int onintr();
E 20
I 20
	int count = 0;
	extern int abortpr();
E 20

D 3
	name = "printjob";
E 3
	init();					/* set up capabilities */
I 12
	(void) write(1, "", 1);			/* ack that daemon is started */
I 30
	(void) close(2);			/* set up log file */
	if (open(LF, O_WRONLY|O_APPEND, 0664) < 0) {
		syslog(LOG_ERR, "%s: %m", LF);
		(void) open("/dev/null", O_WRONLY);
	}
E 30
E 12
D 8
	(void) close(2);			/* set up log file */
	(void) open(LF, FWRONLY|FAPPEND, 0);
D 3
	dup2(2, 1);
	pid = getpid();
E 3
I 3
	dup2(2, 1);				/* closes original connection */
E 8
I 8
D 20
	(void) close(1);			/* set up log file */
	(void) close(2);
D 9
	if (open(LF, FWRONLY|FAPPEND, 0) < 0)
		(void) open("/dev/null", FWRONLY);
E 9
I 9
	if (open(LF, O_WRONLY|O_APPEND) < 0)
		(void) open("/dev/null", O_WRONLY);
E 9
	dup(1);
E 20
I 20
	setgid(getegid());
E 20
E 8
	pid = getpid();				/* for use with lprm */
E 3
	setpgrp(0, pid);
I 16
D 20
	signal(SIGHUP, onintr);
E 16
D 3
	sigset(SIGINT, onintr);			/* for use with lprm */
E 3
I 3
D 9
	sigset(SIGINT, onintr);
E 9
I 9
	signal(SIGINT, onintr);
I 16
	signal(SIGQUIT, onintr);
	signal(SIGTERM, onintr);
E 20
I 20
	signal(SIGHUP, abortpr);
	signal(SIGINT, abortpr);
	signal(SIGQUIT, abortpr);
	signal(SIGTERM, abortpr);
E 20
E 16
E 9
E 3

I 18
	(void) mktemp(tmpfile);

E 18
	/*
	 * uses short form file names
	 */
	if (chdir(SD) < 0) {
D 20
		log("cannot chdir to %s", SD);
E 20
I 20
		syslog(LOG_ERR, "%s: %m", SD);
E 20
		exit(1);
	}
I 3
	if (stat(LO, &stb) == 0 && (stb.st_mode & 0100))
		exit(0);		/* printing disabled */
E 3
D 9
	if ((lfd = open(LO, FWRONLY|FCREATE|FTRUNCATE|FEXLOCK|FNBLOCK, 0664)) < 0) {
E 9
I 9
D 10
	lfd = open(LO, O_WRONLY|O_CREAT, 0664);
	if (lfd < 0 || flock(lfd, LOCK_EX|LOCK_NB) < 0) {
E 10
I 10
D 14
	lfd = open(LO, O_WRONLY|O_CREAT|O_TRUNC, 0644);
E 14
I 14
	lfd = open(LO, O_WRONLY|O_CREAT, 0644);
E 14
	if (lfd < 0) {
D 20
		log("cannot create %s", LO);
E 20
I 20
		syslog(LOG_ERR, "%s: %s: %m", printer, LO);
E 20
		exit(1);
	}
	if (flock(lfd, LOCK_EX|LOCK_NB) < 0) {
E 10
E 9
		if (errno == EWOULDBLOCK)	/* active deamon present */
			exit(0);
D 10
		log("cannot create %s", LO);
E 10
I 10
D 20
		log("cannot lock %s", LO);
E 20
I 20
		syslog(LOG_ERR, "%s: %s: %m", printer, LO);
E 20
E 10
		exit(1);
	}
I 9
	ftruncate(lfd, 0);
E 9
	/*
	 * write process id for others to know
	 */
	sprintf(line, "%u\n", pid);
	pidoff = i = strlen(line);
D 3
	if (write(lfd, line, i) != i)
E 3
I 3
	if (write(lfd, line, i) != i) {
E 3
D 20
		log("cannot write daemon pid");
E 20
I 20
		syslog(LOG_ERR, "%s: %s: %m", printer, LO);
E 20
D 3
	/*
	 * acquire line printer or remote connection
 	 */
restart:
	if (*LP) {
		for (i = 1; ; i = i < 32 ? i << 1 : i) {
			pfd = open(LP, RW ? FRDWR : FWRONLY, 0);
			if (pfd >= 0)
				break;
			if (errno == ENOENT) {
				log("cannot open %s", LP);
				exit(1);
			}
			if (i == 1)
				status("waiting for %s to become ready (offline ?)", printer);
			sleep(i);
		}
		if (isatty(pfd))
			setty();
		status("%s is ready and printing", printer);
	} else if (RM != NULL) {
		for (i = 1; ; i = i < 512 ? i << 1 : i) {
			pfd = getport();
			if (pfd >= 0) {
				(void) sprintf(line, "\2%s\n", RP);
				nitems = strlen(line);
				if (write(pfd, line, nitems) != nitems)
					break;
				if (noresponse())
					(void) close(pfd);
				else
					break;
			}
			if (i == 1)
				status("waiting for %s to come up", RM);
			sleep(i);
		}
		status("sending to %s", RM);
		remote = 1;
	} else {
		log("no line printer device or remote machine name");
E 3
		exit(1);
	}
	/*
D 3
	 * Start running as daemon instead of root
	 */
	setuid(DU);
	/*
	 * Start up an output filter, if needed.
	 */
	if (OF) {
		int p[2];
		char *cp;

		pipe(p);
		if ((ofilter = dofork(DOABORT)) == 0) {	/* child */
			dup2(p[0], 0);		/* pipe is std in */
			dup2(pfd, 1);		/* printer is std out */
			for (i = 3; i < NOFILE; i++)
				(void) close(i);
			if ((cp = rindex(OF, '/')) == NULL)
				cp = OF;
			else
				cp++;
			execl(OF, cp, 0);
			log("can't execl output filter %s", OF);
			exit(1);
		}
		(void) close(p[0]);		/* close input side */
		ofd = p[1];			/* use pipe for output */
	} else {
		ofd = pfd;
		ofilter = 0;
	}

	/*
E 3
	 * search the spool directory for work and sort by queue order.
	 */
D 3
again:
E 3
	if ((nitems = getq(&queue)) < 0) {
D 20
		log("can't scan spool directory %s", SD);
E 20
I 20
		syslog(LOG_ERR, "%s: can't scan %s", printer, SD);
E 20
		exit(1);
	}
D 3
	if (nitems == 0) {		/* EOF => no work to do */
		if (!SF && !tof)
			(void) write(ofd, FF, strlen(FF));
		if (TR != NULL)		/* output trailer */
			(void) write(ofd, TR, strlen(TR));
E 3
I 3
	if (nitems == 0)		/* no work to do */
E 3
		exit(0);
I 10
	if (stb.st_mode & 01) {		/* reset queue flag */
		if (fchmod(lfd, stb.st_mode & 0776) < 0)
D 20
			log("cannot chmod %s", LO);
E 20
I 20
			syslog(LOG_ERR, "%s: %s: %m", printer, LO);
E 20
	}
E 10
D 3
	}

E 3
I 3
	openpr();			/* open printer or remote */
again:
E 3
	/*
	 * we found something to do now do it --
	 *    write the name of the current control file into the lock file
	 *    so the spool queue program can tell what we're working on
	 */
	for (qp = queue; nitems--; free((char *) q)) {
		q = *qp++;
		if (stat(q->q_name, &stb) < 0)
			continue;
I 3
	restart:
E 3
		(void) lseek(lfd, pidoff, 0);
		(void) sprintf(line, "%s\n", q->q_name);
		i = strlen(line);
		if (write(lfd, line, i) != i)
D 20
			log("can't write (%d) control file name", errno);
E 20
I 20
			syslog(LOG_ERR, "%s: %s: %m", printer, LO);
E 20
		if (!remote)
			i = printit(q->q_name);
		else
			i = sendit(q->q_name);
D 3
		if (i > 0) {	/* restart daemon to reprint job */
E 3
I 3
		/*
D 10
		 * Check to see if we are supposed to stop printing.
E 10
I 10
		 * Check to see if we are supposed to stop printing or
		 * if we are to rebuild the queue.
E 10
		 */
D 10
		if (stat(LO, &stb) == 0 && (stb.st_mode & 0100))
			goto done;
E 10
I 10
		if (fstat(lfd, &stb) == 0) {
I 20
			/* stop printing before starting next job? */
E 20
			if (stb.st_mode & 0100)
				goto done;
I 20
			/* rebuild queue (after lpc topq) */
E 20
			if (stb.st_mode & 01) {
				for (free((char *) q); nitems--; free((char *) q))
					q = *qp++;
				if (fchmod(lfd, stb.st_mode & 0776) < 0)
D 20
					log("cannot chmod %s", LO);
E 20
I 20
					syslog(LOG_WARNING, "%s: %s: %m",
						printer, LO);
E 20
				break;
			}
		}
E 10
D 14
		/*
		 * Check to see if we should try reprinting the job.
		 */
		if (i > 0) {
E 14
I 14
D 25
		if (i == 0)		/* file ok and printed */
E 25
I 25
		if (i == OK)		/* file ok and printed */
E 25
			count++;
D 25
		else if (i > 0) {	/* try reprinting the job */
E 25
I 25
		else if (i == REPRINT) { /* try reprinting the job */
E 25
E 14
E 3
D 20
			log("restarting");
E 20
I 20
			syslog(LOG_INFO, "restarting %s", printer);
E 20
			if (ofilter > 0) {
				kill(ofilter, SIGCONT);	/* to be sure */
				(void) close(ofd);
				while ((i = wait(0)) > 0 && i != ofilter)
					;
				ofilter = 0;
			}
D 3
			(void) close(pfd);
			free((char *) q);
			while (nitems--)
				free((char *) *qp++);
			free((char *) queue);
E 3
I 3
			(void) close(pfd);	/* close printer */
D 18
			(void) lseek(lfd, pidoff, 0);
			if (write(lfd, "\n", 1) != 1)
				log("can't write (%d) control file name", errno);
E 18
I 18
			if (ftruncate(lfd, pidoff) < 0)
D 20
				log("can't truncate lock file (%d)", errno);
E 20
I 20
				syslog(LOG_WARNING, "%s: %s: %m", printer, LO);
E 20
E 18
			openpr();		/* try to reopen printer */
E 3
			goto restart;
		}
	}
	free((char *) queue);
I 3
	/*
	 * search the spool directory for more work.
	 */
	if ((nitems = getq(&queue)) < 0) {
D 20
		log("can't scan spool directory %s", SD);
E 20
I 20
		syslog(LOG_ERR, "%s: can't scan %s", printer, SD);
E 20
		exit(1);
	}
	if (nitems == 0) {		/* no more work to do */
	done:
D 14
		if (!SF && !tof)
			(void) write(ofd, FF, strlen(FF));
		if (TR != NULL)		/* output trailer */
			(void) write(ofd, TR, strlen(TR));
E 14
I 14
		if (count > 0) {	/* Files actually printed */
			if (!SF && !tof)
				(void) write(ofd, FF, strlen(FF));
			if (TR != NULL)		/* output trailer */
				(void) write(ofd, TR, strlen(TR));
		}
I 18
		(void) unlink(tmpfile);
E 18
E 14
		exit(0);
	}
E 3
	goto again;
}

char	fonts[4][50];	/* fonts for troff */

D 20
static char ifonts[4][18] = {
E 20
I 20
char ifonts[4][18] = {
E 20
	"/usr/lib/vfont/R",
	"/usr/lib/vfont/I",
	"/usr/lib/vfont/B",
	"/usr/lib/vfont/S"
};

/*
 * The remaining part is the reading of the control file (cf)
 * and performing the various actions.
D 25
 * Returns 0 if everthing was OK, 1 if we should try to reprint the job and
 * -1 if a non-recoverable error occured.
E 25
 */
I 8
D 20
static
E 20
E 8
printit(file)
	char *file;
{
	register int i;
D 25
	int bombed = 0;
E 25
I 25
	char *cp;
	int bombed = OK;
I 40
	int jp_run = 0;
E 40
E 25

	/*
D 25
	 * open control file
E 25
I 25
	 * open control file; ignore if no longer there.
E 25
	 */
	if ((cfp = fopen(file, "r")) == NULL) {
D 20
		log("control file (%s) open failure <errno = %d>", file, errno);
E 20
I 20
		syslog(LOG_INFO, "%s: %s: %m", printer, file);
E 20
D 25
		return(0);
E 25
I 25
		return(OK);
E 25
	}
	/*
	 * Reset troff fonts.
	 */
	for (i = 0; i < 4; i++)
		strcpy(fonts[i], ifonts[i]);
I 24
	strcpy(width+2, "0");
E 24
I 22
	strcpy(indent+2, "0");
I 39
	options[0] = '\0';
E 39
E 22

	/*
	 *      read the control file for work to do
	 *
	 *      file format -- first character in the line is a command
	 *      rest of the line is the argument.
	 *      valid commands are:
	 *
I 25
	 *		S -- "stat info" for symbolic link protection
E 25
	 *		J -- "job name" on banner page
	 *		C -- "class name" on banner page
	 *              L -- "literal" user's name to print on banner
	 *		T -- "title" for pr
	 *		H -- "host name" of machine where lpr was done
	 *              P -- "person" user's login name
D 6
	 *              I -- "indent" changes default indents driver
	 *                   must have stty/gtty avaialble
E 6
I 6
	 *              I -- "indent" amount to indent output
E 6
	 *              f -- "file name" name of text file to print
	 *		l -- "file name" text file with control chars
	 *		p -- "file name" text file to print with pr(1)
	 *		t -- "file name" troff(1) file to print
I 11
	 *		n -- "file name" ditroff(1) file to print
E 11
	 *		d -- "file name" dvi file to print
	 *		g -- "file name" plot(1G) file to print
	 *		v -- "file name" plain raster file to print
	 *		c -- "file name" cifplot file to print
	 *		1 -- "R font file" for troff
	 *		2 -- "I font file" for troff
	 *		3 -- "B font file" for troff
	 *		4 -- "S font file" for troff
	 *		N -- "name" of file (used by lpq)
	 *              U -- "unlink" name of file to remove
	 *                    (after we print it. (Pass 2 only)).
	 *		M -- "mail" to user when done printing
I 39
	 *		O -- "options" for advanced printers
E 39
	 *
	 *      getline reads a line and expands tabs to blanks
	 */

	/* pass 1 */

	while (getline(cfp))
		switch (line[0]) {
		case 'H':
D 14
			strcpy(host, line+1);
E 14
I 14
			strcpy(fromhost, line+1);
E 14
			if (class[0] == '\0')
D 17
				strcpy(class, line+1);
E 17
I 17
				strncpy(class, line+1, sizeof(class)-1);
E 17
			continue;

		case 'P':
D 17
			strcpy(logname, line+1);
E 17
I 17
			strncpy(logname, line+1, sizeof(logname)-1);
E 17
I 3
			if (RS) {			/* restricted */
				if (getpwnam(logname) == (struct passwd *)0) {
D 25
					bombed = 2;
E 25
I 25
					bombed = NOACCT;
E 25
D 18
					sendmail(bombed);
E 18
I 18
					sendmail(line+1, bombed);
E 18
					goto pass2;
				}
			}
E 3
			continue;

I 25
		case 'S':
			cp = line+1;
			i = 0;
			while (*cp >= '0' && *cp <= '9')
				i = i * 10 + (*cp++ - '0');
			fdev = i;
			cp++;
			i = 0;
			while (*cp >= '0' && *cp <= '9')
				i = i * 10 + (*cp++ - '0');
			fino = i;
			continue;

E 25
		case 'J':
			if (line[1] != '\0')
D 17
				strcpy(jobname, line+1);
E 17
I 17
				strncpy(jobname, line+1, sizeof(jobname)-1);
E 17
			else
				strcpy(jobname, " ");
			continue;

		case 'C':
			if (line[1] != '\0')
D 17
				strcpy(class, line+1);
E 17
I 17
				strncpy(class, line+1, sizeof(class)-1);
E 17
			else if (class[0] == '\0')
D 18
				gethostname(class, sizeof (class));
E 18
I 18
				gethostname(class, sizeof(class));
E 18
			continue;

I 39
		case 'O':	/* processing options for advanced printers */
			strncpy(options, line+1, sizeof(options)-1);
			continue;

E 39
		case 'T':	/* header title for pr */
D 17
			strcpy(title, line+1);
E 17
I 17
			strncpy(title, line+1, sizeof(title)-1);
E 17
			continue;

		case 'L':	/* identification line */
I 40
			if (JP && !jp_run) {
				run_job_prep();
				jp_run = 1;
			}
E 40
D 26
			if (!SH)
E 26
I 26
			if (!SH && !HL)
E 26
				banner(line+1, jobname);
			continue;

		case '1':	/* troff fonts */
		case '2':
		case '3':
		case '4':
			if (line[1] != '\0')
				strcpy(fonts[line[0]-'1'], line+1);
			continue;

		case 'W':	/* page width */
D 17
			strcpy(width+2, line+1);
E 17
I 17
			strncpy(width+2, line+1, sizeof(width)-3);
E 17
			continue;

I 6
		case 'I':	/* indent amount */
D 17
			strcpy(indent+2, line+1);
E 17
I 17
			strncpy(indent+2, line+1, sizeof(indent)-3);
E 17
			continue;

E 6
		default:	/* some file to print */
I 40
			if (JP && !jp_run) {
				run_job_prep();
				jp_run = 1;
			}
E 40
D 18
			if ((i = print(line[0], line+1)) > 0) {
E 18
I 18
			switch (i = print(line[0], line+1)) {
D 25
			case -1:
				if (!bombed)
					bombed = 1;
E 25
I 25
			case ERROR:
				if (bombed == OK)
					bombed = FATALERR;
E 25
				break;
D 25
			case 1:
E 25
I 25
			case REPRINT:
E 25
E 18
				(void) fclose(cfp);
D 25
				return(1);
D 18
			} else if (i < 0)
				bombed = 1;
E 18
I 18
			case 2:
				bombed = 3;
E 25
I 25
				return(REPRINT);
			case FILTERERR:
			case ACCESS:
				bombed = i;
E 25
				sendmail(logname, bombed);
			}
E 18
			title[0] = '\0';
			continue;

D 6
		case 'I':
E 6
		case 'N':
		case 'U':
		case 'M':
			continue;
		}

	/* pass 2 */

I 3
pass2:
E 3
	fseek(cfp, 0L, 0);
	while (getline(cfp))
		switch (line[0]) {
I 26
		case 'L':	/* identification line */
I 40
			if (JP && !jp_run) {
				run_job_prep();
				jp_run = 1;
			}
E 40
			if (!SH && HL)
				banner(line+1, jobname);
			continue;

E 26
		case 'M':
D 3
			sendmail(bombed);
E 3
I 3
D 18
			if (bombed != 2)		/* already sent if 2 */
				sendmail(bombed);
E 18
I 18
D 25
			if (bombed < 2)		/* already sent if >= 2 */
E 25
I 25
			if (bombed < NOACCT)	/* already sent if >= NOACCT */
E 25
				sendmail(line+1, bombed);
E 18
E 3
			continue;

		case 'U':
			(void) unlink(line+1);
		}
	/*
D 18
	 * clean-up incase another control file exists
E 18
I 18
	 * clean-up in case another control file exists
E 18
	 */
	(void) fclose(cfp);
	(void) unlink(file);
D 14
	return(0);
E 14
I 14
D 25
	return(bombed ? -1 : 0);
E 25
I 25
	return(bombed == OK ? OK : ERROR);
E 25
E 14
}

/*
 * Print a file.
D 11
 * Set up the chain [ PR [ | {IF, OF} ] ] or {IF, TF, CF, VF}.
E 11
I 11
 * Set up the chain [ PR [ | {IF, OF} ] ] or {IF, RF, TF, NF, DF, CF, VF}.
E 11
D 18
 * Return -1 if a non-recoverable error occured, 1 if a recoverable error and
E 18
I 18
 * Return -1 if a non-recoverable error occured,
 * 2 if the filter detected some errors (but printed the job anyway),
 * 1 if we should try to reprint this job and
E 18
 * 0 if all is well.
 * Note: all filters take stdin as the file, stdout as the printer,
 * stderr as the log file, and must not ignore SIGINT.
 */
I 8
D 20
static
E 20
E 8
print(format, file)
	int format;
	char *file;
{
D 18
	register int n, fi, fo;
E 18
I 18
	register int n;
E 18
	register char *prog;
I 18
	int fi, fo;
E 18
D 39
	char *av[15], buf[BUFSIZ];
E 39
I 39
	char *av[20], buf[BUFSIZ];
E 39
	int pid, p[2], stopped = 0;
	union wait status;
I 25
	struct stat stb;
E 25

D 9
	if ((fi = open(file, FRDONLY, 0)) < 0) {
E 9
I 9
D 20
	if ((fi = open(file, O_RDONLY)) < 0) {
E 9
		log("%s: open failure <errno = %d>", file, errno);
E 20
I 20
D 25
	if ((fi = open(file, O_RDONLY)) < 0)
E 20
		return(-1);
E 25
I 25
	if (lstat(file, &stb) < 0 || (fi = open(file, O_RDONLY)) < 0)
		return(ERROR);
	/*
	 * Check to see if data file is a symbolic link. If so, it should
	 * still point to the same file or someone is trying to print
	 * something he shouldn't.
	 */
	if ((stb.st_mode & S_IFMT) == S_IFLNK && fstat(fi, &stb) == 0 &&
	    (stb.st_dev != fdev || stb.st_ino != fino))
		return(ACCESS);
E 25
D 20
	}
E 20
	if (!SF && !tof) {		/* start on a fresh page */
		(void) write(ofd, FF, strlen(FF));
		tof = 1;
	}
	if (IF == NULL && (format == 'f' || format == 'l')) {
		tof = 0;
		while ((n = read(fi, buf, BUFSIZ)) > 0)
			if (write(ofd, buf, n) != n) {
				(void) close(fi);
D 25
				return(1);
E 25
I 25
				return(REPRINT);
E 25
			}
		(void) close(fi);
D 25
		return(0);
E 25
I 25
		return(OK);
E 25
	}
	switch (format) {
	case 'p':	/* print file using 'pr' */
		if (IF == NULL) {	/* use output filter */
			prog = PR;
			av[0] = "pr";
			av[1] = width;
			av[2] = length;
			av[3] = "-h";
			av[4] = *title ? title : " ";
			av[5] = 0;
			fo = ofd;
			goto start;
		}
I 36
		if (PI) {		/* if incorporates pr function */
			av[1] = "-p";
			av[2] = *title ? title : " ";
			n = 3;
			goto ifilter;
		}
E 36
		pipe(p);
		if ((prchild = dofork(DORETURN)) == 0) {	/* child */
			dup2(fi, 0);		/* file is stdin */
			dup2(p[1], 1);		/* pipe is stdout */
			for (n = 3; n < NOFILE; n++)
				(void) close(n);
			execl(PR, "pr", width, length, "-h", *title ? title : " ", 0);
D 20
			log("cannot execl %s", PR);
E 20
I 20
			syslog(LOG_ERR, "cannot execl %s", PR);
E 20
			exit(2);
		}
		(void) close(p[1]);		/* close output side */
		(void) close(fi);
		if (prchild < 0) {
			prchild = 0;
			(void) close(p[0]);
D 25
			return(-1);
E 25
I 25
			return(ERROR);
E 25
		}
		fi = p[0];			/* use pipe for input */
	case 'f':	/* print plain text file */
I 36
		n = 1;
	ifilter:
E 36
		prog = IF;
D 36
		av[1] = width;
		av[2] = length;
D 6
		n = 3;
E 6
I 6
		av[3] = indent;
		n = 4;
E 36
I 36
		av[n++] = width;
		av[n++] = length;
		av[n++] = indent;
		if (EA) {
			av[n++] = pxwidth;
			av[n++] = pxlength;
		}
E 36
E 6
		break;
	case 'l':	/* like 'f' but pass control characters */
D 36
		prog = IF;
E 36
D 15
		av[1] = "-l";
E 15
I 15
		av[1] = "-c";
E 15
D 36
		av[2] = width;
		av[3] = length;
D 6
		n = 4;
E 6
I 6
		av[4] = indent;
		n = 5;
E 6
		break;
E 36
I 36
		n = 2;
		goto ifilter;
E 36
I 3
	case 'r':	/* print a fortran text file */
		prog = RF;
		av[1] = width;
		av[2] = length;
		n = 3;
I 38
		if (EA) {
			av[n++] = pxwidth;
			av[n++] = pxlength;
		}
E 38
		break;
E 3
	case 't':	/* print troff output */
I 11
	case 'n':	/* print ditroff output */
E 11
D 3
	case 'd':	/* print troff output */
E 3
I 3
	case 'd':	/* print tex output */
E 3
		(void) unlink(".railmag");
D 3
		if ((fo = creat(".railmag", 0666)) < 0) {
E 3
I 3
		if ((fo = creat(".railmag", FILMOD)) < 0) {
E 3
D 20
			log("cannot create .railmag");
E 20
I 20
			syslog(LOG_ERR, "%s: cannot create .railmag", printer);
E 20
			(void) unlink(".railmag");
		} else {
			for (n = 0; n < 4; n++) {
				if (fonts[n][0] != '/')
					(void) write(fo, "/usr/lib/vfont/", 15);
				(void) write(fo, fonts[n], strlen(fonts[n]));
				(void) write(fo, "\n", 1);
			}
			(void) close(fo);
		}
D 11
		prog = (format == 't') ? TF : DF;
E 11
I 11
		prog = (format == 't') ? TF : (format == 'n') ? NF : DF;
E 11
D 3
		n = 1;
E 3
I 3
		av[1] = pxwidth;
		av[2] = pxlength;
		n = 3;
E 3
		break;
	case 'c':	/* print cifplot output */
		prog = CF;
D 3
		n = 1;
E 3
I 3
		av[1] = pxwidth;
		av[2] = pxlength;
		n = 3;
E 3
		break;
	case 'g':	/* print plot(1G) output */
		prog = GF;
D 3
		n = 1;
E 3
I 3
		av[1] = pxwidth;
		av[2] = pxlength;
		n = 3;
E 3
		break;
	case 'v':	/* print raster output */
		prog = VF;
D 3
		n = 1;
E 3
I 3
		av[1] = pxwidth;
		av[2] = pxlength;
		n = 3;
E 3
		break;
	default:
		(void) close(fi);
D 20
		log("illegal format character '%c'", format);
E 20
I 20
		syslog(LOG_ERR, "%s: illegal format character '%c'",
			printer, format);
E 20
D 25
		return(-1);
E 25
I 25
		return(ERROR);
E 25
	}
I 34
	if (prog == NULL) {
		(void) close(fi);
		syslog(LOG_ERR,
		   "%s: no filter found in printcap for format character '%c'",
		   printer, format);
		return(ERROR);
	}
E 34
	if ((av[0] = rindex(prog, '/')) != NULL)
		av[0]++;
	else
		av[0] = prog;
	av[n++] = "-n";
	av[n++] = logname;
	av[n++] = "-h";
D 14
	av[n++] = host;
E 14
I 14
	av[n++] = fromhost;
I 36
	if (EA) {
		av[n++] = "-P";
		av[n++] = printer;
I 39
		if (options[0]) {
			av[n++] = "-O";
			av[n++] = options;
		}
E 39
	}
E 36
E 14
	av[n++] = AF;
	av[n] = 0;
	fo = pfd;
	if (ofilter > 0) {		/* stop output filter */
		write(ofd, "\031\1", 2);
		while ((pid = wait3(&status, WUNTRACED, 0)) > 0 && pid != ofilter)
			;
		if (status.w_stopval != WSTOPPED) {
			(void) close(fi);
D 20
			log("output filter died (%d)", status.w_retcode);
E 20
I 20
			syslog(LOG_WARNING, "%s: output filter died (%d)",
				printer, status.w_retcode);
E 20
D 25
			return(1);
E 25
I 25
			return(REPRINT);
E 25
		}
		stopped++;
	}
start:
	if ((child = dofork(DORETURN)) == 0) {	/* child */
		dup2(fi, 0);
		dup2(fo, 1);
I 18
D 23
		n = open(tmpfile, O_WRONLY|O_CREAT, 0664);
E 23
I 23
		n = open(tmpfile, O_WRONLY|O_CREAT|O_TRUNC, 0664);
E 23
		if (n >= 0)
			dup2(n, 2);
E 18
		for (n = 3; n < NOFILE; n++)
			(void) close(n);
		execv(prog, av);
D 20
		log("cannot execl %s", prog);
E 20
I 20
		syslog(LOG_ERR, "cannot execv %s", prog);
E 20
		exit(2);
	}
	(void) close(fi);
	if (child < 0)
		status.w_retcode = 100;
	else
		while ((pid = wait(&status)) > 0 && pid != child)
			;
	child = 0;
	prchild = 0;
	if (stopped) {		/* restart output filter */
		if (kill(ofilter, SIGCONT) < 0) {
D 20
			log("cannot restart output filter");
E 20
I 20
			syslog(LOG_ERR, "cannot restart output filter");
E 20
			exit(1);
		}
	}
	tof = 0;
D 18
	if (!WIFEXITED(status) || status.w_retcode > 1) {
		log("Daemon Filter '%c' Malfunction (%d)", format, status.w_retcode);
E 18
I 18
	if (!WIFEXITED(status)) {
D 20
		log("Daemon filter '%c' terminated (%d)", format, status.w_termsig);
E 20
I 20
		syslog(LOG_WARNING, "%s: Daemon filter '%c' terminated (%d)",
			printer, format, status.w_termsig);
E 20
E 18
D 25
		return(-1);
D 18
	} else if (status.w_retcode == 1)
		return(1);
	tof = 1;
	return(0);
E 18
I 18
	} else if (status.w_retcode > 2) {
E 25
I 25
		return(ERROR);
	}
	switch (status.w_retcode) {
	case 0:
		tof = 1;
		return(OK);
	case 1:
		return(REPRINT);
I 34
	case 2:
		return(ERROR);
E 34
	default:
E 25
D 20
		log("Daemon filter '%c' exited (%d)", format, status.w_retcode);
E 20
I 20
		syslog(LOG_WARNING, "%s: Daemon filter '%c' exited (%d)",
			printer, format, status.w_retcode);
E 20
D 25
		return(-1);
	} else if (status.w_retcode == 0)
		tof = 1;
	return(status.w_retcode);
E 25
I 25
D 34
	case 2:
		return(ERROR);
E 34
I 34
		return(FILTERERR);
E 34
	}
E 25
E 18
}

/*
 * Send the daemon control file (cf) and any data files.
 * Return -1 if a non-recoverable error occured, 1 if a recoverable error and
 * 0 if all is well.
 */
I 8
D 20
static
E 20
E 8
sendit(file)
	char *file;
{
D 25
	register int linelen, err = 0;
	char last[132];
E 25
I 25
	register int i, err = OK;
	char *cp, last[BUFSIZ];
E 25

	/*
	 * open control file
	 */
D 20
	if ((cfp = fopen(file, "r")) == NULL) {
		log("control file (%s) open failure <errno = %d>", file, errno);
E 20
I 20
	if ((cfp = fopen(file, "r")) == NULL)
E 20
D 25
		return(0);
E 25
I 25
		return(OK);
E 25
D 20
	}
E 20
	/*
	 *      read the control file for work to do
	 *
	 *      file format -- first character in the line is a command
	 *      rest of the line is the argument.
	 *      commands of interest are:
	 *
	 *            a-z -- "file name" name of file to print
	 *              U -- "unlink" name of file to remove
	 *                    (after we print it. (Pass 2 only)).
	 */

	/*
	 * pass 1
	 */
	while (getline(cfp)) {
	again:
I 25
		if (line[0] == 'S') {
			cp = line+1;
			i = 0;
			while (*cp >= '0' && *cp <= '9')
				i = i * 10 + (*cp++ - '0');
			fdev = i;
			cp++;
			i = 0;
			while (*cp >= '0' && *cp <= '9')
				i = i * 10 + (*cp++ - '0');
			fino = i;
			continue;
		}
E 25
		if (line[0] >= 'a' && line[0] <= 'z') {
			strcpy(last, line);
D 25
			while (linelen = getline(cfp))
E 25
I 25
			while (i = getline(cfp))
E 25
				if (strcmp(last, line))
					break;
D 25
			if ((err = sendfile('\3', last+1)) > 0) {
				(void) fclose(cfp);
				return(1);
			} else if (err)
E 25
I 25
			switch (sendfile('\3', last+1)) {
			case OK:
				if (i)
					goto again;
E 25
				break;
D 25
			if (linelen)
				goto again;
E 25
I 25
			case REPRINT:
				(void) fclose(cfp);
				return(REPRINT);
			case ACCESS:
				sendmail(logname, ACCESS);
			case ERROR:
				err = ERROR;
			}
E 25
			break;
		}
	}
D 25
	if (!err && sendfile('\2', file) > 0) {
E 25
I 25
	if (err == OK && sendfile('\2', file) > 0) {
E 25
		(void) fclose(cfp);
D 25
		return(1);
E 25
I 25
		return(REPRINT);
E 25
	}
	/*
	 * pass 2
	 */
	fseek(cfp, 0L, 0);
	while (getline(cfp))
		if (line[0] == 'U')
			(void) unlink(line+1);
	/*
D 25
	 * clean-up incase another control file exists
E 25
I 25
	 * clean-up in case another control file exists
E 25
	 */
	(void) fclose(cfp);
	(void) unlink(file);
D 25
	return(0);
E 25
I 25
	return(err);
E 25
}

/*
 * Send a data file to the remote machine and spool it.
 * Return positive if we should try resending.
 */
I 8
D 20
static
E 20
E 8
sendfile(type, file)
	char type, *file;
{
	register int f, i, amt;
	struct stat stb;
	char buf[BUFSIZ];
D 20
	int sizerr;
E 20
I 20
	int sizerr, resp;
E 20

D 9
	if ((f = open(file, FRDONLY, 0)) < 0 || fstat(f, &stb) < 0) {
E 9
I 9
D 20
	if ((f = open(file, O_RDONLY)) < 0 || fstat(f, &stb) < 0) {
E 9
		log("file (%s) open failure <errno = %d>", file, errno);
E 20
I 20
D 25
	if ((f = open(file, O_RDONLY)) < 0 || fstat(f, &stb) < 0)
E 20
		return(-1);
E 25
I 25
	if (lstat(file, &stb) < 0 || (f = open(file, O_RDONLY)) < 0)
		return(ERROR);
	/*
	 * Check to see if data file is a symbolic link. If so, it should
	 * still point to the same file or someone is trying to print something
	 * he shouldn't.
	 */
	if ((stb.st_mode & S_IFMT) == S_IFLNK && fstat(f, &stb) == 0 &&
	    (stb.st_dev != fdev || stb.st_ino != fino))
		return(ACCESS);
E 25
D 20
	}
E 20
	(void) sprintf(buf, "%c%d %s\n", type, stb.st_size, file);
	amt = strlen(buf);
D 7
	if (write(pfd, buf, amt) != amt)
E 7
I 7
D 20
	if (write(pfd, buf, amt) != amt) {
		(void) close(f);
E 7
		return(1);
E 20
I 20
	for (i = 0;  ; i++) {
		if (write(pfd, buf, amt) != amt ||
		    (resp = response()) < 0 || resp == '\1') {
			(void) close(f);
D 25
			return(1);
E 25
I 25
			return(REPRINT);
E 25
		} else if (resp == '\0')
			break;
		if (i == 0)
			status("no space on remote; waiting for queue to drain");
		if (i == 10)
D 28
			syslog(LOG_SALERT, "%s: can't send to %s; queue full",
E 28
I 28
			syslog(LOG_ALERT, "%s: can't send to %s; queue full",
E 28
				printer, RM);
		sleep(5 * 60);
E 20
D 7
	if (noresponse())
E 7
I 7
	}
D 20
	if (noresponse()) {
		(void) close(f);
E 7
		return(1);
I 7
	}
E 20
I 20
	if (i)
		status("sending to %s", RM);
E 20
E 7
	sizerr = 0;
	for (i = 0; i < stb.st_size; i += BUFSIZ) {
		amt = BUFSIZ;
		if (i + amt > stb.st_size)
			amt = stb.st_size - i;
		if (sizerr == 0 && read(f, buf, amt) != amt)
			sizerr = 1;
D 7
		if (write(pfd, buf, amt) != amt)
E 7
I 7
		if (write(pfd, buf, amt) != amt) {
			(void) close(f);
E 7
D 25
			return(1);
E 25
I 25
			return(REPRINT);
E 25
I 7
		}
E 7
	}
	(void) close(f);
	if (sizerr) {
D 20
		log("%s: changed size", file);
E 20
I 20
		syslog(LOG_INFO, "%s: %s: changed size", printer, file);
E 20
D 25
		(void) write(pfd, "\1", 1);  /* tell recvjob to ignore this file */
D 20
		return(-1);
	}
	if (write(pfd, "", 1) != 1)
		return(1);
	if (noresponse())
		return(1);
	return(0);
E 20
I 20
		i = -1;
	} else if (write(pfd, "", 1) != 1)
		i = 1;
	else if (response())
		i = 1;
	else
		i = 0;
	return(i);
E 25
I 25
		/* tell recvjob to ignore this file */
		(void) write(pfd, "\1", 1);
		return(ERROR);
	}
	if (write(pfd, "", 1) != 1 || response())
		return(REPRINT);
	return(OK);
E 25
E 20
}

/*
 * Check to make sure there have been no errors and that both programs
 * are in sync with eachother.
 * Return non-zero if the connection was lost.
 */
D 20
static
noresponse()
E 20
I 20
response()
E 20
{
	char resp;

D 20
	if (read(pfd, &resp, 1) != 1 || resp != '\0') {
		log("lost connection or error in recvjob");
		return(1);
E 20
I 20
	if (read(pfd, &resp, 1) != 1) {
		syslog(LOG_INFO, "%s: lost connection", printer);
		return(-1);
E 20
	}
D 20
	return(0);
E 20
I 20
	return(resp);
E 20
}

/*
 * Banner printing stuff
 */
I 8
D 20
static
E 20
E 8
banner(name1, name2)
	char *name1, *name2;
{
	time_t tvec;
	extern char *ctime();
I 37
	char *date;
E 37

	time(&tvec);
I 37
	date = ctime(&tvec);
	date[24] = '\0';
	if (BF)
		return(banner_filter(name1, name2, date));
E 37
	if (!SF && !tof)
		(void) write(ofd, FF, strlen(FF));
	if (SB) {	/* short banner only */
		if (class[0]) {
			(void) write(ofd, class, strlen(class));
			(void) write(ofd, ":", 1);
		}
		(void) write(ofd, name1, strlen(name1));
		(void) write(ofd, "  Job: ", 7);
		(void) write(ofd, name2, strlen(name2));
		(void) write(ofd, "  Date: ", 8);
D 37
		(void) write(ofd, ctime(&tvec), 24);
E 37
I 37
		(void) write(ofd, date, 24);
E 37
		(void) write(ofd, "\n", 1);
	} else {	/* normal banner */
		(void) write(ofd, "\n\n\n", 3);
		scan_out(ofd, name1, '\0');
		(void) write(ofd, "\n\n", 2);
		scan_out(ofd, name2, '\0');
		if (class[0]) {
			(void) write(ofd,"\n\n\n",3);
			scan_out(ofd, class, '\0');
		}
		(void) write(ofd, "\n\n\n\n\t\t\t\t\tJob:  ", 15);
		(void) write(ofd, name2, strlen(name2));
		(void) write(ofd, "\n\t\t\t\t\tDate: ", 12);
D 37
		(void) write(ofd, ctime(&tvec), 24);
E 37
I 37
		(void) write(ofd, date, 24);
E 37
		(void) write(ofd, "\n", 1);
	}
	if (!SF)
		(void) write(ofd, FF, strlen(FF));
	tof = 1;
}

D 8
char *
E 8
I 8
D 20
static char *
E 20
I 20
char *
E 20
E 8
scnline(key, p, c)
	register char key, *p;
	char c;
{
	register scnwidth;

	for (scnwidth = WIDTH; --scnwidth;) {
		key <<= 1;
		*p++ = key & 0200 ? c : BACKGND;
	}
	return (p);
}

#define TRC(q)	(((q)-' ')&0177)

I 8
D 20
static
E 20
E 8
scan_out(scfd, scsp, dlm)
	int scfd;
	char *scsp, dlm;
{
	register char *strp;
	register nchrs, j;
	char outbuf[LINELEN+1], *sp, c, cc;
	int d, scnhgt;
	extern char scnkey[][HEIGHT];	/* in lpdchar.c */

	for (scnhgt = 0; scnhgt++ < HEIGHT+DROP; ) {
		strp = &outbuf[0];
		sp = scsp;
		for (nchrs = 0; ; ) {
			d = dropit(c = TRC(cc = *sp++));
			if ((!d && scnhgt > HEIGHT) || (scnhgt <= DROP && d))
				for (j = WIDTH; --j;)
					*strp++ = BACKGND;
			else
				strp = scnline(scnkey[c][scnhgt-1-d], strp, cc);
			if (*sp == dlm || *sp == '\0' || nchrs++ >= PW/(WIDTH+1)-1)
				break;
			*strp++ = BACKGND;
			*strp++ = BACKGND;
		}
		while (*--strp == BACKGND && strp >= outbuf)
			;
		strp++;
		*strp++ = '\n';	
		(void) write(scfd, outbuf, strp-outbuf);
	}
}

I 8
D 20
static
E 20
E 8
dropit(c)
	char c;
{
	switch(c) {

	case TRC('_'):
	case TRC(';'):
	case TRC(','):
	case TRC('g'):
	case TRC('j'):
	case TRC('p'):
	case TRC('q'):
	case TRC('y'):
		return (DROP);

	default:
		return (0);
	}
}

/*
I 37
 * print the banner using a filter
 */
banner_filter(name1, name2, date)
	char *name1, *name2, *date;
{
	register int n;
	char *av[15];
	int pid, p[2];
	register FILE *f;
	union wait status;

	if ((av[0] = rindex(BF, '/')) != NULL)
		av[0]++;
	else
		av[0] = BF;
	n = 1;
	av[n++] = "-P";
	av[n++] = printer;
I 39
	if (options[0]) {
		av[n++] = "-O";
		av[n++] = options;
	}
E 39
	av[n++] = pxwidth;
	av[n++] = pxlength;
	av[n] = NULL;
	pipe(p);
	if ((child = dofork(DORETURN)) == 0) {	/* child */
		dup2(p[0], 0);
		dup2(pfd, 1);
		for (n = 3; n < NOFILE; n++)
			(void) close(n);
		execv(BF, av);
		syslog(LOG_ERR, "cannot execv %s", BF);
		exit(2);
	}
	close(p[0]);
	if (child < 0) {
		child = 0;
		close(p[1]);
		return(ERROR);
	}
	f = fdopen(p[1], "w");
	fprintf(f, "L %s\n", name1);
	fprintf(f, "J %s\n", name2);
	fprintf(f, "D %s\n", date);
	if (class[0])
		fprintf(f, "C %s\n", class);
	fclose(f);
	while ((pid = wait(&status)) > 0 && pid != child)
		;
	child = 0;
	if (!WIFEXITED(status)) {
		syslog(LOG_WARNING, "%s: banner filter terminated (%d)",
			printer, status.w_termsig);
		return(ERROR);
	}
	if (status.w_retcode == 0)
		return(OK);
	else {
		syslog(LOG_WARNING, "%s: banner filter exited (%d)", printer,
			status.w_retcode);
		return(ERROR);
	}
}

/*
I 40
 * run the job prep program
 */
run_job_prep()
{
	register int n;
	char *av[15];
	int pid, p[2];
	union wait status;

	if ((av[0] = rindex(JP, '/')) != NULL)
		av[0]++;
	else
		av[0] = JP;
	n = 1;
	av[n++] = "-P";
	av[n++] = printer;
	if (options[0]) {
		av[n++] = "-O";
		av[n++] = options;
	}
	av[n] = NULL;
	if ((child = dofork(DORETURN)) == 0) {	/* child */
		dup2(pfd, 1);
		for (n = 3; n < NOFILE; n++)
			(void) close(n);
		execv(JP, av);
		syslog(LOG_ERR, "cannot execv %s", JP);
		exit(2);
	}
	if (child < 0) {
		child = 0;
		return(ERROR);
	}
	while ((pid = wait(&status)) > 0 && pid != child)
		;
	child = 0;
	if (!WIFEXITED(status)) {
		syslog(LOG_WARNING, "%s: job prep program terminated (%d)",
			printer, status.w_termsig);
		return(ERROR);
	}
	if (status.w_retcode == 0)
		return(OK);
	else {
		syslog(LOG_WARNING, "%s: job prep program exited (%d)", printer,
			status.w_retcode);
		return(ERROR);
	}
}

/*
E 40
E 37
 * sendmail ---
 *   tell people about job completion
 */
I 8
D 20
static
E 20
E 8
D 18
sendmail(bombed)
E 18
I 18
sendmail(user, bombed)
	char *user;
E 18
	int bombed;
{
D 18
	static int p[2];
E 18
	register int i;
D 18
	int stat;
E 18
I 18
	int p[2], s;
E 18
	register char *cp;
	char buf[100];
I 18
	struct stat stb;
	FILE *fp;
E 18

	pipe(p);
D 18
	if ((stat = dofork(DORETURN)) == 0) {		/* child */
E 18
I 18
	if ((s = dofork(DORETURN)) == 0) {		/* child */
E 18
		dup2(p[0], 0);
		for (i = 3; i < NOFILE; i++)
			(void) close(i);
		if ((cp = rindex(MAIL, '/')) != NULL)
			cp++;
		else
			cp = MAIL;
D 14
		sprintf(buf, "%s@%s", line+1, host);
E 14
I 14
D 18
		sprintf(buf, "%s@%s", line+1, fromhost);
E 18
I 18
		sprintf(buf, "%s@%s", user, fromhost);
E 18
E 14
		execl(MAIL, cp, buf, 0);
		exit(0);
D 18
	} else if (stat > 0) {				/* parent */
E 18
I 18
	} else if (s > 0) {				/* parent */
E 18
		dup2(p[1], 1);
D 14
		printf("To: %s\n", line+1);
E 14
I 14
D 18
		printf("To: %s@%s\n", line+1, fromhost);
E 18
I 18
		printf("To: %s@%s\n", user, fromhost);
E 18
E 14
D 34
		printf("Subject: printer job\n\n");
E 34
I 34
		if (*jobname)
			printf("Subject: %s printer job \"%s\"\n\n", printer,
				jobname);
		else
			printf("Subject: %s printer job\n\n", printer);
E 34
		printf("Your printer job ");
		if (*jobname)
			printf("(%s) ", jobname);
D 3
		if (bombed)
			printf("bombed\n");
		else
			printf("is done\n");
E 3
I 3
		switch (bombed) {
D 25
		case 0:
E 25
I 25
		case OK:
E 25
			printf("\ncompleted successfully\n");
			break;
		default:
D 25
		case 1:
E 25
I 25
		case FATALERR:
E 25
			printf("\ncould not be printed\n");
			break;
D 25
		case 2:
E 25
I 25
		case NOACCT:
E 25
			printf("\ncould not be printed without an account on %s\n", host);
			break;
I 18
D 25
		case 3:
E 25
I 25
		case FILTERERR:
E 25
			if (stat(tmpfile, &stb) < 0 || stb.st_size == 0 ||
			    (fp = fopen(tmpfile, "r")) == NULL) {
D 34
				printf("\nwas printed but had some errors\n");
E 34
I 34
				printf("\nhad some errors and may not have printed\n");
E 34
				break;
			}
D 34
			printf("\nwas printed but had the following errors:\n");
E 34
I 34
			printf("\nhad the following errors and may not have printed:\n");
E 34
			while ((i = getc(fp)) != EOF)
				putchar(i);
			(void) fclose(fp);
I 25
			break;
		case ACCESS:
			printf("\nwas not printed because it was not linked to the original file\n");
E 25
E 18
		}
E 3
		fflush(stdout);
		(void) close(1);
	}
	(void) close(p[0]);
	(void) close(p[1]);
D 18
	wait(&stat);
E 18
I 18
	wait(&s);
E 18
}

/*
 * dofork - fork with retries on failure
 */
I 8
D 20
static
E 20
E 8
dofork(action)
	int action;
{
	register int i, pid;

	for (i = 0; i < 20; i++) {
D 3
		if ((pid = fork()) < 0)
E 3
I 3
		if ((pid = fork()) < 0) {
E 3
			sleep((unsigned)(i*i));
D 3
		else
			return(pid);
E 3
I 3
			continue;
		}
		/*
		 * Child should run as daemon instead of root
		 */
		if (pid == 0)
			setuid(DU);
		return(pid);
E 3
	}
D 20
	log("can't fork");
E 20
I 20
	syslog(LOG_ERR, "can't fork");
E 20

	switch (action) {
	case DORETURN:
		return (-1);
	default:
D 20
		log("bad action (%d) to dofork", action);
E 20
I 20
		syslog(LOG_ERR, "bad action (%d) to dofork", action);
E 20
		/*FALL THRU*/
	case DOABORT:
		exit(1);
	}
	/*NOTREACHED*/
}

/*
D 16
 * Cleanup child processes when a SIGINT is caught.
E 16
I 16
D 20
 * Cleanup child processes when a signal is caught.
E 20
I 20
 * Kill child processes to abort current job.
E 20
E 16
 */
I 8
D 20
static
E 8
onintr()
E 20
I 20
abortpr()
E 20
{
I 18
	(void) unlink(tmpfile);
E 18
	kill(0, SIGINT);
	if (ofilter > 0)
		kill(ofilter, SIGCONT);
	while (wait(0) > 0)
		;
	exit(0);
}

I 8
D 20
static
E 20
E 8
init()
{
	int status;

D 10
	if ((status = pgetent(line, printer)) < 0) {
		log("can't open printer description file");
		exit(1);
	} else if (status == 0) {
		log("unknown printer");
		exit(1);
	}
E 10
I 10
D 29
	if ((status = pgetent(line, printer)) < 0)
		fatal("can't open printer description file");
	else if (status == 0)
		fatal("unknown printer");
E 29
I 29
	if ((status = pgetent(line, printer)) < 0) {
		syslog(LOG_ERR, "can't open printer description file");
		exit(1);
	} else if (status == 0) {
		syslog(LOG_ERR, "unknown printer: %s", printer);
		exit(1);
	}
E 29
E 10
	if ((LP = pgetstr("lp", &bp)) == NULL)
		LP = DEFDEVLP;
	if ((RP = pgetstr("rp", &bp)) == NULL)
D 3
		RP = printer;
E 3
I 3
		RP = DEFLP;
E 3
	if ((LO = pgetstr("lo", &bp)) == NULL)
		LO = DEFLOCK;
	if ((ST = pgetstr("st", &bp)) == NULL)
		ST = DEFSTAT;
	if ((LF = pgetstr("lf", &bp)) == NULL)
		LF = DEFLOGF;
	if ((SD = pgetstr("sd", &bp)) == NULL)
		SD = DEFSPOOL;
	if ((DU = pgetnum("du")) < 0)
		DU = DEFUID;
	if ((FF = pgetstr("ff", &bp)) == NULL)
		FF = DEFFF;
	if ((PW = pgetnum("pw")) < 0)
		PW = DEFWIDTH;
	sprintf(&width[2], "%d", PW);
	if ((PL = pgetnum("pl")) < 0)
		PL = DEFLENGTH;
	sprintf(&length[2], "%d", PL);
I 3
	if ((PX = pgetnum("px")) < 0)
		PX = 0;
	sprintf(&pxwidth[2], "%d", PX);
	if ((PY = pgetnum("py")) < 0)
		PY = 0;
	sprintf(&pxlength[2], "%d", PY);
E 3
	RM = pgetstr("rm", &bp);
I 29
	/*
	 * Figure out whether the local machine is the same as the remote 
	 * machine entry (if it exists).  If not, then ignore the local
	 * queue information.
	 */
	 if (RM != (char *) NULL) {
		char name[256];
		struct hostent *hp;

		/* get the standard network name of the local host */
		gethostname(name, sizeof(name));
		name[sizeof(name)-1] = '\0';
		hp = gethostbyname(name);
		if (hp == (struct hostent *) NULL) {
		    syslog(LOG_ERR,
			"unable to get network name for local machine %s",
			name);
		    goto localcheck_done;
		} else strcpy(name, hp->h_name);

		/* get the standard network name of RM */
		hp = gethostbyname(RM);
		if (hp == (struct hostent *) NULL) {
		    syslog(LOG_ERR,
			"unable to get hostname for remote machine %s", RM);
		    goto localcheck_done;
		}

		/* if printer is not on local machine, ignore LP */
		if (strcmp(name, hp->h_name) != 0) *LP = '\0';
	}
localcheck_done:

E 29
	AF = pgetstr("af", &bp);
	OF = pgetstr("of", &bp);
	IF = pgetstr("if", &bp);
I 3
	RF = pgetstr("rf", &bp);
E 3
	TF = pgetstr("tf", &bp);
I 11
	NF = pgetstr("nf", &bp);
E 11
	DF = pgetstr("df", &bp);
	GF = pgetstr("gf", &bp);
	VF = pgetstr("vf", &bp);
	CF = pgetstr("cf", &bp);
I 37
	BF = pgetstr("bf", &bp);
I 40
	PP = pgetstr("pp", &bp);
	JP = pgetstr("jp", &bp);
E 40
E 37
	TR = pgetstr("tr", &bp);
I 3
	RS = pgetflag("rs");
E 3
	SF = pgetflag("sf");
	SH = pgetflag("sh");
	SB = pgetflag("sb");
I 26
	HL = pgetflag("hl");
E 26
	RW = pgetflag("rw");
I 35
	CT = pgetflag("ct");
I 36
	EA = pgetflag("ea");
	PI = pgetflag("pi");
E 36
E 35
	BR = pgetnum("br");
	if ((FC = pgetnum("fc")) < 0)
		FC = 0;
	if ((FS = pgetnum("fs")) < 0)
		FS = 0;
	if ((XC = pgetnum("xc")) < 0)
		XC = 0;
	if ((XS = pgetnum("xs")) < 0)
		XS = 0;
I 6
	tof = !pgetflag("fo");
E 6
}

I 3
/*
 * Acquire line printer or remote connection.
 */
I 8
D 20
static
E 20
E 8
openpr()
{
	register int i, n;
I 19
D 20
	char resp;
E 20
I 20
	int resp;
I 41
	char *cp;
E 41
E 20
E 19

	if (*LP) {
I 33
D 41
		status("waiting for %s to become ready (offline ?)", printer);
E 33
		for (i = 1; ; i = i < 32 ? i << 1 : i) {
D 9
			pfd = open(LP, RW ? FRDWR : FWRONLY, 0);
E 9
I 9
			pfd = open(LP, RW ? O_RDWR : O_WRONLY);
E 9
			if (pfd >= 0)
				break;
			if (errno == ENOENT) {
D 20
				log("cannot open %s", LP);
E 20
I 20
				syslog(LOG_ERR, "%s: %m", LP);
E 20
				exit(1);
			}
D 33
			if (i == 1)
				status("waiting for %s to become ready (offline ?)", printer);
E 33
			sleep(i);
		}
		if (isatty(pfd))
			setty();
I 35
		if (CT)
			ctrlt_response_check();
E 35
		status("%s is ready and printing", printer);
E 41
I 41
		if (cp = index(LP, '@'))
			opennet(cp);
		else
			opentty();
E 41
	} else if (RM != NULL) {
D 20
		for (i = 1; ; i = i < 512 ? i << 1 : i) {
I 19
			resp = '\0';
E 20
I 20
		for (i = 1; ; i = i < 256 ? i << 1 : i) {
			resp = -1;
E 20
E 19
D 4
			pfd = getport();
E 4
I 4
D 41
			pfd = getport(RM);
E 41
I 41
			pfd = getport(RM, 0);
E 41
E 4
			if (pfd >= 0) {
				(void) sprintf(line, "\2%s\n", RP);
				n = strlen(line);
D 20
				if (write(pfd, line, n) != n)
E 20
I 20
				if (write(pfd, line, n) == n &&
				    (resp = response()) == '\0')
E 20
					break;
D 19
				if (noresponse())
E 19
I 19
D 20
				if (read(pfd, &resp, 1) != 1) {
					log("lost connection");
E 19
					(void) close(pfd);
D 19
				else
E 19
I 19
				} else if (resp == '\0')
E 19
					break;
E 20
I 19
				(void) close(pfd);
E 19
			}
D 19
			if (i == 1)
				status("waiting for %s to come up", RM);
E 19
I 19
			if (i == 1) {
D 20
				if (resp == '\0')
E 20
I 20
				if (resp < 0)
E 20
					status("waiting for %s to come up", RM);
D 20
				else
E 20
I 20
				else {
E 20
					status("waiting for queue to be enabled on %s", RM);
I 20
					i = 256;
				}
E 20
			}
E 19
			sleep(i);
		}
		status("sending to %s", RM);
		remote = 1;
I 19
D 20
		if (setsockopt(pfd, SOL_SOCKET, SO_KEEPALIVE, 0, 0) < 0)
			log("setsockopt (SO_KEEPALIVE) failed");
E 20
E 19
	} else {
D 20
		log("no line printer device or remote machine name");
E 20
I 20
		syslog(LOG_ERR, "%s: no line printer device or host name",
			printer);
E 20
		exit(1);
	}
	/*
	 * Start up an output filter, if needed.
	 */
	if (OF) {
		int p[2];
D 41
		char *cp;
E 41

		pipe(p);
		if ((ofilter = dofork(DOABORT)) == 0) {	/* child */
			dup2(p[0], 0);		/* pipe is std in */
			dup2(pfd, 1);		/* printer is std out */
			for (i = 3; i < NOFILE; i++)
				(void) close(i);
			if ((cp = rindex(OF, '/')) == NULL)
				cp = OF;
			else
				cp++;
			execl(OF, cp, width, length, 0);
D 20
			log("can't execl output filter %s", OF);
E 20
I 20
			syslog(LOG_ERR, "%s: %s: %m", printer, OF);
E 20
			exit(1);
		}
		(void) close(p[0]);		/* close input side */
		ofd = p[1];			/* use pipe for output */
	} else {
		ofd = pfd;
		ofilter = 0;
	}
I 41
}

/*
 * Printer is connected to an EIA port on this host
 */
opentty()
{
	register int i;

	status("waiting for %s to become ready (offline ?)", printer);
	for (i = 1; ; i = i < 32 ? i << 1 : i) {
		pfd = open(LP, RW ? O_RDWR : O_WRONLY);
		if (pfd >= 0)
			break;
		if (errno == ENOENT) {
			syslog(LOG_ERR, "%s: %m", LP);
			exit(1);
		}
		sleep(i);
	}
	if (isatty(pfd))
		setty();
	if (CT)
		ctrlt_response_check();
	status("%s is ready and printing", printer);
}

/*
 * Printer connected directly to the network
 * or to a terminal server on the net
 */
opennet(cp)
	char *cp;
{
	register int i;
	int resp, port;
	char save_ch;

	save_ch = *cp;
	*cp = '\0';
	port = atoi(LP);
	if (port <= 0) {
		syslog(LOG_ERR, "%s: bad port number: %s", printer, LP);
		exit(1);
	}
	*cp++ = save_ch;

	for (i = 1; ; i = i < 256 ? i << 1 : i) {
		resp = -1;
		pfd = getport(cp, port);
		if (pfd < 0 && errno == ECONNREFUSED)
			resp = 1;
		else if (pfd >= 0)
			break;
		if (i == 1) {
		   if (resp < 0)
			status("waiting for %s to come up", LP);
		   else
			status("waiting for access to printer on %s", LP);
		}
		sleep(i);
	}
	status("sending to %s port %d", cp, port);
E 41
}

E 3
struct bauds {
	int	baud;
	int	speed;
} bauds[] = {
	50,	B50,
	75,	B75,
	110,	B110,
	134,	B134,
	150,	B150,
	200,	B200,
	300,	B300,
	600,	B600,
	1200,	B1200,
	1800,	B1800,
	2400,	B2400,
	4800,	B4800,
	9600,	B9600,
	19200,	EXTA,
	38400,	EXTB,
	0,	0
};

/*
 * setup tty lines.
 */
I 8
D 20
static
E 20
E 8
setty()
{
	struct sgttyb ttybuf;
	register struct bauds *bp;

	if (ioctl(pfd, TIOCEXCL, (char *)0) < 0) {
D 20
		log("cannot set exclusive-use");
E 20
I 20
		syslog(LOG_ERR, "%s: ioctl(TIOCEXCL): %m", printer);
E 20
		exit(1);
	}
	if (ioctl(pfd, TIOCGETP, (char *)&ttybuf) < 0) {
D 20
		log("cannot get tty parameters");
E 20
I 20
		syslog(LOG_ERR, "%s: ioctl(TIOCGETP): %m", printer);
E 20
		exit(1);
	}
	if (BR > 0) {
		for (bp = bauds; bp->baud; bp++)
			if (BR == bp->baud)
				break;
		if (!bp->baud) {
D 20
			log("illegal baud rate %d", BR);
E 20
I 20
			syslog(LOG_ERR, "%s: illegal baud rate %d", printer, BR);
E 20
			exit(1);
		}
		ttybuf.sg_ispeed = ttybuf.sg_ospeed = bp->speed;
	}
D 10
	if (FC)
		ttybuf.sg_flags &= ~FC;
	if (FS)
		ttybuf.sg_flags |= FS;
E 10
I 10
	ttybuf.sg_flags &= ~FC;
	ttybuf.sg_flags |= FS;
E 10
	if (ioctl(pfd, TIOCSETP, (char *)&ttybuf) < 0) {
D 20
		log("cannot set tty parameters");
E 20
I 20
		syslog(LOG_ERR, "%s: ioctl(TIOCSETP): %m", printer);
E 20
		exit(1);
	}
I 21
	if (XC || XS) {
		int ldisc = NTTYDISC;

		if (ioctl(pfd, TIOCSETD, &ldisc) < 0) {
			syslog(LOG_ERR, "%s: ioctl(TIOCSETD): %m", printer);
			exit(1);
		}
	}
E 21
	if (XC) {
		if (ioctl(pfd, TIOCLBIC, &XC) < 0) {
D 20
			log("cannot set local tty parameters");
E 20
I 20
			syslog(LOG_ERR, "%s: ioctl(TIOCLBIC): %m", printer);
E 20
			exit(1);
		}
	}
	if (XS) {
		if (ioctl(pfd, TIOCLBIS, &XS) < 0) {
D 20
			log("cannot set local tty parameters");
E 20
I 20
			syslog(LOG_ERR, "%s: ioctl(TIOCLBIS): %m", printer);
E 20
			exit(1);
		}
I 35
	}
}

/*
 * Some printers have screwed serial interfaces with unusable
 * DTR lines.  Since we cannot use the DTR line to tell if the printer
 * is online, we would like to have some other way of telling,
 * rather than just assuming it's online and sending print jobs
 * into the bit bucket.
 *
 * Bidirectional PostScript printers respond with a status message
 * when sent a ^T.  This routine implements a mechanism for ensuring
 * that the printer is online based on this feature.
 */
ctrlt_response_check()
{
	register int i, cc;
	static int zero = 0;
	static char ctrlt = 0x14;
	char buf[BUFSIZ];

	for (i = 1; ; i = i < 32 ? i << 1 : i) {
		ioctl(pfd, TIOCFLUSH, &zero);	/* flush everything */
		write(pfd, &ctrlt, 1);
		usleep(500000);		/* give printer time to respond */
		cc = read(pfd, buf, BUFSIZ);
		if (cc >= 20 && !strncmp(buf, "%%[ status: idle ]%%", 20))
			break;
		sleep(i);
E 35
	}
I 3
}

/*VARARGS1*/
D 20
static
E 20
status(msg, a1, a2, a3)
	char *msg;
{
	register int fd;
	char buf[BUFSIZ];

	umask(0);
D 9
	if ((fd = open(ST, FWRONLY|FCREATE|FTRUNCATE|FEXLOCK, 0664)) < 0)
E 9
I 9
	fd = open(ST, O_WRONLY|O_CREAT, 0664);
D 20
	if (fd < 0 || flock(fd, LOCK_EX) < 0)
E 9
		fatal("cannot create status file");
E 20
I 20
	if (fd < 0 || flock(fd, LOCK_EX) < 0) {
		syslog(LOG_ERR, "%s: %s: %m", printer, ST);
		exit(1);
	}
E 20
I 9
	ftruncate(fd, 0);
E 9
	sprintf(buf, msg, a1, a2, a3);
	strcat(buf, "\n");
	(void) write(fd, buf, strlen(buf));
	(void) close(fd);
E 3
}
E 1
