h44683
s 00010/00005/00309
d D 5.7 88/06/30 18:00:11 bostic 18 17
c install approved copyright notice
e
s 00009/00003/00305
d D 5.6 88/05/05 18:08:34 bostic 17 16
c written by Ralph Campbell; add Berkeley specific header
e
s 00002/00004/00306
d D 5.5 87/03/19 14:38:01 mckusick 16 15
c SBLOCK => SBOFF
e
s 00005/00003/00305
d D 5.4 86/06/06 11:18:45 mckusick 15 14
c save data file name in a separate buffer in case it needs to be removed
e
s 00007/00000/00301
d D 5.3 86/04/15 15:16:17 bloom 14 13
c use our version of host name to avoid problems with local and remote
c end having different ideas of the machine name
e
s 00006/00000/00295
d D 5.2 85/11/17 15:54:25 eric 13 12
c clean up logging
e
s 00007/00001/00288
d D 5.1 85/06/06 10:08:48 dist 12 11
c Add copyright
e
s 00003/00004/00286
d D 4.8 84/08/13 16:47:25 ralph 11 9
c fix uninitialized loop variable
e
s 00001/00000/00290
d R 4.8 84/08/13 16:37:08 ralph 10 9
c initialize loop variable
e
s 00121/00035/00169
d D 4.7 84/07/25 09:08:55 ralph 9 8
c use syslog(). Check for free space before transfering file.
e
s 00004/00001/00200
d D 4.6 83/07/17 00:12:18 sam 8 7
c put sccs id's to some use
e
s 00003/00001/00198
d D 4.5 83/06/17 15:09:45 ralph 7 6
c fixed `fc' and `fs' when 0177777 is needed.
e
s 00002/00002/00197
d D 4.4 83/06/15 14:57:56 sam 6 5
c open and flock defines changed
e
s 00004/00002/00195
d D 4.3 83/06/02 12:23:47 ralph 5 4
c made local variables static to improve separation between functions.
e
s 00008/00002/00189
d D 4.2 83/05/16 14:12:32 ralph 4 1
c bug fixes and changes for lpc command.
e
s 00007/00002/00189
d R 4.2 83/05/16 13:40:29 ralph 3 1
c bug fixes and changes for lpc command.
e
s 00000/00002/00189
d R 4.2 83/05/13 11:53:50 ralph 2 1
c bug fixes and changes for lpc command.
e
s 00191/00000/00000
d D 4.1 83/04/29 11:31:04 ralph 1 0
c date and time created 83/04/29 11:31:04 by ralph
e
u
U
t
T
I 12
/*
 * Copyright (c) 1983 Regents of the University of California.
D 17
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 17
I 17
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 18
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 18
I 18
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
E 18
E 17
 */

E 12
I 1
D 8
/*	%M%	%I%	%E%	*/
E 8
I 8
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 12
#endif
E 12
I 12
D 17
#endif not lint
E 17
I 17
#endif /* not lint */
E 17
E 12

E 8
/*
 * Receive printer jobs from the network, queue them and
 * start the printer daemon.
 */

#include "lp.h"
I 9
#include <sys/fs.h>
E 9

D 5
char    tfname[40];		/* tmp copy of cf before linking */
char    *dfname;		/* data files */
E 5
I 5
D 9
static char    tfname[40];	/* tmp copy of cf before linking */
static char    *dfname;		/* data files */
E 9
I 9
char	*sp = "";
#define ack()	(void) write(1, sp, 1);
E 9
E 5

I 9
char    tfname[40];		/* tmp copy of cf before linking */
D 15
char    *dfname;		/* data files */
E 15
I 15
char    dfname[40];		/* data files */
E 15
int	minfree;		/* keep at least minfree blocks available */
char	*ddev;			/* disk device (for checking free space) */
int	dfd;			/* file system device descriptor */

char	*find_dev();

E 9
recvjob()
{
I 4
	struct stat stb;
E 4
	char *bp = pbuf;
D 9
	int status;
E 9
I 9
	int status, rcleanup();
E 9

D 4
	name = "recvjob";

E 4
	/*
	 * Perform lookup for printer name or abbreviation
	 */
	if ((status = pgetent(line, printer)) < 0)
D 9
		fatal("cannot open printer description file");
E 9
I 9
		frecverr("cannot open printer description file");
E 9
	else if (status == 0)
D 9
		fatal("unknown printer");
E 9
I 9
		frecverr("unknown printer %s", printer);
E 9
	if ((LF = pgetstr("lf", &bp)) == NULL)
		LF = DEFLOGF;
	if ((SD = pgetstr("sd", &bp)) == NULL)
		SD = DEFSPOOL;
I 4
	if ((LO = pgetstr("lo", &bp)) == NULL)
		LO = DEFLOCK;
E 4

I 13
	(void) close(2);			/* set up log file */
	if (open(LF, O_WRONLY|O_APPEND, 0664) < 0) {
		syslog(LOG_ERR, "%s: %m", LF);
		(void) open("/dev/null", O_WRONLY);
	}

E 13
D 9
	(void) close(2);
D 6
	(void) open(LF, FWRONLY|FAPPEND, 0);
E 6
I 6
	(void) open(LF, O_WRONLY|O_APPEND);
E 9
E 6
	if (chdir(SD) < 0)
D 9
		fatal("cannot chdir to %s", SD);
I 4
	if (stat(LO, &stb) == 0 && (stb.st_mode & 010)) {
		/* queue is disabled */
		putchar('\1');		/* return error code */
		exit(1);
	}
E 9
I 9
		frecverr("%s: %s: %m", printer, SD);
	if (stat(LO, &stb) == 0) {
		if (stb.st_mode & 010) {
			/* queue is disabled */
			putchar('\1');		/* return error code */
			exit(1);
		}
	} else if (stat(SD, &stb) < 0)
		frecverr("%s: %s: %m", printer, SD);
	minfree = read_number("minfree");
	ddev = find_dev(stb.st_dev, S_IFBLK);
	if ((dfd = open(ddev, O_RDONLY)) < 0)
		syslog(LOG_WARNING, "%s: %s: %m", printer, ddev);
	signal(SIGTERM, rcleanup);
	signal(SIGPIPE, rcleanup);
E 9
E 4

	if (readjob())
		printjob();
}

D 9
char	*sp = "";
#define ack()	(void) write(1, sp, 1);
E 9
I 9
char *
find_dev(dev, type)
	register dev_t dev;
	register int type;
{
	register DIR *dfd = opendir("/dev");
	struct direct *dir;
	struct stat stb;
	char devname[MAXNAMLEN+6];
	char *dp;
E 9

I 9
	strcpy(devname, "/dev/");
	while ((dir = readdir(dfd))) {
		strcpy(devname + 5, dir->d_name);
		if (stat(devname, &stb))
			continue;
		if ((stb.st_mode & S_IFMT) != type)
			continue;
		if (dev == stb.st_rdev) {
			closedir(dfd);
			dp = (char *)malloc(strlen(devname)+1);
			strcpy(dp, devname);
			return(dp);
		}
	}
	closedir(dfd);
	frecverr("cannot find device %d, %d", major(dev), minor(dev));
	/*NOTREACHED*/
}

E 9
/*
 * Read printer jobs sent by lpd and copy them to the spooling directory.
 * Return the number of jobs successfully transfered.
 */
I 5
D 9
static
E 5
readjob(printer)
	char *printer;
E 9
I 9
readjob()
E 9
{
	register int size, nfiles;
	register char *cp;

	ack();
	nfiles = 0;
	for (;;) {
		/*
		 * Read a command to tell us what to do
		 */
		cp = line;
		do {
			if ((size = read(1, cp, 1)) != 1) {
				if (size < 0)
D 9
					fatal("Lost connection");
E 9
I 9
					frecverr("%s: Lost connection",printer);
E 9
				return(nfiles);
			}
		} while (*cp++ != '\n');
		*--cp = '\0';
		cp = line;
		switch (*cp++) {
		case '\1':	/* cleanup because data sent was bad */
D 9
			cleanup();
E 9
I 9
			rcleanup();
E 9
			continue;

		case '\2':	/* read cf file */
			size = 0;
			while (*cp >= '0' && *cp <= '9')
				size = size * 10 + (*cp++ - '0');
			if (*cp++ != ' ')
				break;
I 14
			/*
			 * host name has been authenticated, we use our
			 * view of the host name since we may be passed
			 * something different than what gethostbyaddr()
			 * returns
			 */
			strcpy(cp + 6, from);
E 14
			strcpy(tfname, cp);
			tfname[0] = 't';
I 9
			if (!chksize(size)) {
				(void) write(1, "\2", 1);
				continue;
			}
E 9
			if (!readfile(tfname, size)) {
D 9
				cleanup();
E 9
I 9
				rcleanup();
E 9
				continue;
			}
			if (link(tfname, cp) < 0)
D 9
				fatal("cannot rename %s", tfname);
E 9
I 9
				frecverr("%s: %m", tfname);
E 9
			(void) unlink(tfname);
			tfname[0] = '\0';
			nfiles++;
			continue;

		case '\3':	/* read df file */
			size = 0;
			while (*cp >= '0' && *cp <= '9')
				size = size * 10 + (*cp++ - '0');
			if (*cp++ != ' ')
				break;
I 9
			if (!chksize(size)) {
				(void) write(1, "\2", 1);
				continue;
			}
E 9
D 15
			(void) readfile(dfname = cp, size);
E 15
I 15
			strcpy(dfname, cp);
			(void) readfile(dfname, size);
E 15
			continue;
		}
D 9
		fatal("protocol screwup");
E 9
I 9
		frecverr("protocol screwup");
E 9
	}
}

/*
 * Read files send by lpd and copy them to the spooling directory.
 */
I 5
D 9
static
E 9
E 5
readfile(file, size)
	char *file;
	int size;
{
	register char *cp;
	char buf[BUFSIZ];
	register int i, j, amt;
	int fd, err;

D 6
	fd = open(file, FWRONLY|FCREATE, FILMOD);
E 6
I 6
	fd = open(file, O_WRONLY|O_CREAT, FILMOD);
E 6
	if (fd < 0)
D 9
		fatal("cannot create %s", file);
E 9
I 9
		frecverr("%s: %m", file);
E 9
	ack();
	err = 0;
	for (i = 0; i < size; i += BUFSIZ) {
		amt = BUFSIZ;
		cp = buf;
		if (i + amt > size)
			amt = size - i;
		do {
			j = read(1, cp, amt);
			if (j <= 0)
D 9
				fatal("Lost connection");
E 9
I 9
				frecverr("Lost connection");
E 9
			amt -= j;
			cp += j;
		} while (amt > 0);
		amt = BUFSIZ;
		if (i + amt > size)
			amt = size - i;
D 7
		if (err == 0 && write(fd, buf, amt) != amt)
E 7
I 7
		if (write(fd, buf, amt) != amt) {
E 7
			err++;
I 7
			break;
		}
E 7
	}
	(void) close(fd);
	if (err)
D 9
		fatal("%s: write error", file);
E 9
I 9
		frecverr("%s: write error", file);
E 9
	if (noresponse()) {		/* file sent had bad data in it */
		(void) unlink(file);
		return(0);
	}
	ack();
	return(1);
}

D 9
static
E 9
noresponse()
{
	char resp;

	if (read(1, &resp, 1) != 1)
D 9
		fatal("Lost connection");
E 9
I 9
		frecverr("Lost connection");
E 9
	if (resp == '\0')
		return(0);
	return(1);
}

/*
I 9
 * Check to see if there is enough space on the disk for size bytes.
 * 1 == OK, 0 == Not OK.
 */
chksize(size)
	int size;
{
	struct stat stb;
	register char *ddev;
	int spacefree;
	struct fs fs;

D 16
	if (dfd < 0 || lseek(dfd, (long)(SBLOCK * DEV_BSIZE), 0) < 0)
E 16
I 16
	if (dfd < 0 || lseek(dfd, (long)(SBOFF), 0) < 0)
E 16
		return(1);
	if (read(dfd, (char *)&fs, sizeof fs) != sizeof fs)
		return(1);
D 16
	spacefree = (fs.fs_cstotal.cs_nbfree * fs.fs_frag +
		fs.fs_cstotal.cs_nffree - fs.fs_dsize * fs.fs_minfree / 100) *
			fs.fs_fsize / 1024;
E 16
I 16
	spacefree = freespace(&fs, fs.fs_minfree) * fs.fs_fsize / 1024;
E 16
	size = (size + 1023) / 1024;
	if (minfree + size > spacefree)
		return(0);
	return(1);
}

read_number(fn)
	char *fn;
{
	char lin[80];
	register FILE *fp;

	if ((fp = fopen(fn, "r")) == NULL)
		return (0);
	if (fgets(lin, 80, fp) == NULL) {
		fclose(fp);
		return (0);
	}
	fclose(fp);
	return (atoi(lin));
}

/*
E 9
 * Remove all the files associated with the current job being transfered.
 */
D 9
static
cleanup()
E 9
I 9
rcleanup()
E 9
{
D 11
	register int i;
E 11

	if (tfname[0])
		(void) unlink(tfname);
D 15
	if (dfname)
E 15
I 15
	if (dfname[0])
E 15
		do {
			do
				(void) unlink(dfname);
D 11
			while (dfname[i]-- != 'A');
			dfname[i] = 'z';
		} while (dfname[i-2]-- != 'd');
E 11
I 11
			while (dfname[2]-- != 'A');
			dfname[2] = 'z';
		} while (dfname[0]-- != 'd');
I 15
	dfname[0] = '\0';
E 15
E 11
}

D 9
static
fatal(msg, a1)
E 9
I 9
frecverr(msg, a1, a2)
E 9
	char *msg;
{
D 9
	cleanup();
	log(msg, a1);
E 9
I 9
	rcleanup();
	syslog(LOG_ERR, msg, a1, a2);
E 9
	putchar('\1');		/* return error code */
	exit(1);
}
E 1
