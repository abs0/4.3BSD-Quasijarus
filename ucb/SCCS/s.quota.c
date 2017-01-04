h00195
s 00010/00005/00290
d D 5.6 88/06/29 21:51:00 bostic 11 10
c install approved copyright notice
e
s 00010/00004/00285
d D 5.5 88/05/20 12:31:52 bostic 10 9
c add Berkeley specific header
e
s 00018/00018/00271
d D 5.4 86/02/24 05:05:29 lepreau 9 8
c reset overquota flags for each fs; lint
e
s 00003/00003/00286
d D 5.3 85/11/04 19:03:25 bloom 8 7
c rewrite to avoid division by zero
e
s 00021/00006/00268
d D 5.2 85/09/10 21:53:25 serge 7 6
c do EOF -> 0 quota conversion
e
s 00014/00002/00260
d D 5.1 85/05/30 19:57:00 mckusick 6 5
c Add copyright
e
s 00014/00010/00248
d D 4.5 85/05/30 12:40:42 mckusick 5 4
c check for non-existent quotas
e
s 00002/00002/00256
d D 4.4 83/06/21 11:40:26 sam 4 3
c make field a tad wider
e
s 00006/00006/00252
d D 4.3 83/05/25 16:01:19 mckusick 3 2
c update for new defines in sys/file.h; output in terms of 1K blocks
e
s 00005/00005/00253
d D 4.2 83/05/24 15:59:01 mckusick 2 1
c clean-ups for new fstab
e
s 00258/00000/00000
d D 4.1 83/05/24 15:51:08 mckusick 1 0
c date and time created 83/05/24 15:51:08 by mckusick
e
u
U
t
T
I 6
/*
 * Copyright (c) 1980 Regents of the University of California.
D 10
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 10
I 10
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 11
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 11
I 11
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
E 11
E 10
 */

E 6
I 1
#ifndef lint
D 6
static char sccsid[] = "%W% (Berkeley, from Melbourne) %G%";
#endif
E 6
I 6
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
D 10
#endif not lint
E 10
I 10
#endif /* not lint */
E 10

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 10
#endif not lint
E 10
I 10
#endif /* not lint */
E 10
E 6

/*
 * Disk quota reporting program.
 */
#include <stdio.h>
#include <fstab.h>
#include <ctype.h>
#include <pwd.h>
I 5
#include <errno.h>
E 5

#include <sys/param.h>
D 2
#define	QUOTA
E 2
#include <sys/quota.h>
#include <sys/file.h>
#include <sys/stat.h>

int	qflag;
int	vflag;
int	done;
int	morethanone;
I 2
char	*qfname = "quotas";
E 2

main(argc, argv)
	char *argv[];
{
	register char *cp;
I 5
	extern int errno;
E 5

I 5
D 9
	if (quota(Q_SYNC, 0, 0, 0) < 0 && errno == EINVAL) {
E 9
I 9
	if (quota(Q_SYNC, 0, 0, (caddr_t)0) < 0 && errno == EINVAL) {
E 9
		fprintf(stderr, "There are no quotas on this system\n");
		exit(0);
	}
E 5
	argc--,argv++;
	while (argc > 0) {
		if (argv[0][0] == '-')
			for (cp = &argv[0][1]; *cp; cp++) switch (*cp) {

			case 'v':
				vflag++;
				break;

			case 'q':
				qflag++;
				break;

			default:
				fprintf(stderr, "quota: %c: unknown option\n",
					*cp);
				exit(1);
			}
		else
			break;
		argc--, argv++;
	}
	morethanone = argc > 1;
	if (argc == 0) {
		showuid(getuid());
		exit(0);
	}
	for (; argc > 0; argc--, argv++) {
		if (alldigits(*argv))
			showuid(atoi(*argv));
		else
			showname(*argv);
	}
}

showuid(uid)
	int uid;
{
	struct passwd *pwd = getpwuid(uid);

	if (pwd == NULL)
		showquotas(uid, "(no account)");
	else
		showquotas(uid, pwd->pw_name);
}

showname(name)
	char *name;
{
	struct passwd *pwd = getpwnam(name);

	if (pwd == NULL) {
		fprintf(stderr, "quota: %s: unknown user\n", name);
		return;
	}
	showquotas(pwd->pw_uid, name);
}

showquotas(uid, name)
	int uid;
	char *name;
{
D 9
	register char c, *p;
E 9
	register struct fstab *fs;
D 5
	int myuid;
E 5
I 5
D 9
	register char *msgi = (char *)0, *msgb = (char *)0;
E 9
I 9
	register char *msgi, *msgb;
E 9
	register enab = 1;
	dev_t	fsdev;
	struct	stat statb;
	struct	dqblk dqblk;
	int myuid, fd;
	char qfilename[MAXPATHLEN + 1], iwarn[8], dwarn[8];
E 5

	myuid = getuid();
	if (uid != myuid && myuid != 0) {
		printf("quota: %s (uid %d): permission denied\n", name, uid);
		return;
	}
	done = 0;
D 9
	setfsent();
E 9
I 9
	(void) setfsent();
E 9
	while (fs = getfsent()) {
D 5
		register char *msgi = (char *)0, *msgb = (char *)0;
		register enab = 1;
		dev_t	fsdev;
		struct	stat statb;
		struct	dqblk dqblk;
D 2
		char qfname[MAXPATHLEN + 1], iwarn[8], dwarn[8];
E 2
I 2
		char qfilename[MAXPATHLEN + 1], iwarn[8], dwarn[8];
E 2

E 5
		if (stat(fs->fs_spec, &statb) < 0)
			continue;
I 9
		msgi = msgb = (char *) 0;
E 9
		fsdev = statb.st_rdev;
D 2
		(void) sprintf(qfname, "%s/%s", fs->fs_file, fs->fs_quotafile);
		if (stat(qfname, &statb) < 0 || statb.st_dev != fsdev)
E 2
I 2
		(void) sprintf(qfilename, "%s/%s", fs->fs_file, qfname);
		if (stat(qfilename, &statb) < 0 || statb.st_dev != fsdev)
E 2
			continue;
D 9
		if (quota(Q_GETDLIM, uid, fsdev, &dqblk) != 0) {
E 9
I 9
		if (quota(Q_GETDLIM, uid, fsdev, (caddr_t)&dqblk) != 0) {
E 9
D 2
			register fd = open(qfname, FRDONLY);
E 2
I 2
D 3
			register fd = open(qfilename, FRDONLY);
E 3
I 3
D 5
			register fd = open(qfilename, O_RDONLY);
E 3
E 2

E 5
I 5
			fd = open(qfilename, O_RDONLY);
E 5
			if (fd < 0)
				continue;
D 3
			lseek(fd, (long)(uid * sizeof (dqblk)), FSEEK_ABSOLUTE);
E 3
I 3
D 9
			lseek(fd, (long)(uid * sizeof (dqblk)), L_SET);
E 3
D 7
			if (read(fd, &dqblk, sizeof dqblk) != sizeof (dqblk)) {
E 7
I 7
			switch (read(fd, &dqblk, sizeof dqblk)) {
E 9
I 9
			(void) lseek(fd, (off_t)(uid * sizeof (dqblk)), L_SET);
			switch (read(fd, (char *)&dqblk, sizeof dqblk)) {
E 9
			case 0:			/* EOF */
				/*
				 * Convert implicit 0 quota (EOF)
				 * into an explicit one (zero'ed dqblk).
				 */
				bzero((caddr_t)&dqblk, sizeof dqblk);
				break;

			case sizeof dqblk:	/* OK */
				break;

			default:		/* ERROR */
				fprintf(stderr, "quota: read error in ");
				perror(qfilename);
E 7
D 9
				close(fd);
E 9
I 9
				(void) close(fd);
E 9
				continue;
			}
D 9
			close(fd);
E 9
I 9
			(void) close(fd);
E 9
D 7
			if (dqblk.dqb_isoftlimit == 0 &&
E 7
I 7
			if (!vflag && dqblk.dqb_isoftlimit == 0 &&
E 7
			    dqblk.dqb_bsoftlimit == 0)
				continue;
			enab = 0;
		}
		if (dqblk.dqb_ihardlimit &&
		    dqblk.dqb_curinodes >= dqblk.dqb_ihardlimit)
			msgi = "File count limit reached on %s";
		else if (enab && dqblk.dqb_iwarn == 0)
			msgi = "Out of inode warnings on %s";
		else if (dqblk.dqb_isoftlimit &&
		    dqblk.dqb_curinodes >= dqblk.dqb_isoftlimit)
			msgi = "Too many files on %s";
		if (dqblk.dqb_bhardlimit &&
		    dqblk.dqb_curblocks >= dqblk.dqb_bhardlimit)
			msgb = "Block limit reached on %s";
		else if (enab && dqblk.dqb_bwarn == 0)
			msgb = "Out of block warnings on %s";
		else if (dqblk.dqb_bsoftlimit &&
		    dqblk.dqb_curblocks >= dqblk.dqb_bsoftlimit)
			msgb = "Over disc quota on %s";
		if (dqblk.dqb_iwarn < MAX_IQ_WARN)
D 9
			sprintf(iwarn, "%d", dqblk.dqb_iwarn);
E 9
I 9
			(void) sprintf(iwarn, "%d", dqblk.dqb_iwarn);
E 9
		else
			iwarn[0] = '\0';
		if (dqblk.dqb_bwarn < MAX_DQ_WARN)
D 9
			sprintf(dwarn, "%d", dqblk.dqb_bwarn);
E 9
I 9
			(void) sprintf(dwarn, "%d", dqblk.dqb_bwarn);
E 9
		else
			dwarn[0] = '\0';
		if (qflag) {
			if (msgi != (char *)0 || msgb != (char *)0)
				heading(uid, name);
			if (msgi != (char *)0)
				xprintf(msgi, fs->fs_file);
			if (msgb != (char *)0)
				xprintf(msgb, fs->fs_file);
			continue;
		}
		if (vflag || dqblk.dqb_curblocks || dqblk.dqb_curinodes) {
			heading(uid, name);
D 4
			printf("%8s%8d%c%7d%8d%8s%8d%c%7d%8d%8s\n"
E 4
I 4
			printf("%10s%8d%c%7d%8d%8s%8d%c%7d%8d%8s\n"
E 4
				, fs->fs_file
D 3
				, (dqblk.dqb_curblocks / (1024/DEV_BSIZE)) 
E 3
I 3
D 8
				, (dqblk.dqb_curblocks / btodb(1024)) 
E 8
I 8
				, dbtob(dqblk.dqb_curblocks) / 1024
E 8
E 3
				, (msgb == (char *)0) ? ' ' : '*'
D 3
				, (dqblk.dqb_bsoftlimit / (1024/DEV_BSIZE)) 
				, ((dqblk.dqb_bhardlimit-1) / (1024/DEV_BSIZE)) 
E 3
I 3
D 8
				, (dqblk.dqb_bsoftlimit / btodb(1024)) 
				, (dqblk.dqb_bhardlimit / btodb(1024)) 
E 8
I 8
				, dbtob(dqblk.dqb_bsoftlimit) / 1024
				, dbtob(dqblk.dqb_bhardlimit) / 1024
E 8
E 3
				, dwarn
				, dqblk.dqb_curinodes
				, (msgi == (char *)0) ? ' ' : '*'
				, dqblk.dqb_isoftlimit
D 3
				, dqblk.dqb_ihardlimit-1
E 3
I 3
				, dqblk.dqb_ihardlimit
E 3
				, iwarn
			);
		}
	}
D 9
	endfsent();
E 9
I 9
	(void) endfsent();
E 9
	if (!done && !qflag) {
		if (morethanone)
D 9
			putchar('\n');
E 9
I 9
			(void) putchar('\n');
E 9
		xprintf("Disc quotas for %s (uid %d):", name, uid);
		xprintf("none.");
	}
D 7
	xprintf(0);
E 7
I 7
	xprintf((char *)0);
E 7
}

heading(uid, name)
	int uid;
	char *name;
{

	if (done++)
		return;
D 7
	xprintf(0);
E 7
I 7
	xprintf((char *)0);
E 7
	if (qflag) {
		if (!morethanone)
			return;
		xprintf("User %s (uid %d):", name, uid);
D 7
		xprintf(0);
E 7
I 7
		xprintf((char *)0);
E 7
		return;
	}
D 9
	putchar('\n');
E 9
I 9
	(void) putchar('\n');
E 9
	xprintf("Disc quotas for %s (uid %d):", name, uid);
D 7
	xprintf(0);
E 7
I 7
	xprintf((char *)0);
E 7
D 4
	printf("%8s%8s %7s%8s%8s%8s %7s%8s%8s\n"
E 4
I 4
	printf("%10s%8s %7s%8s%8s%8s %7s%8s%8s\n"
E 4
		, "Filsys"
		, "current"
		, "quota"
		, "limit"
		, "#warns"
		, "files"
		, "quota"
		, "limit"
		, "#warns"
	);
}

I 7
/*VARARGS1*/
E 7
xprintf(fmt, arg1, arg2, arg3, arg4, arg5, arg6)
	char *fmt;
{
	char	buf[100];
	static int column;

	if (fmt == 0 && column || column >= 40) {
D 9
		putchar('\n');
E 9
I 9
		(void) putchar('\n');
E 9
		column = 0;
	}
	if (fmt == 0)
		return;
D 9
	sprintf(buf, fmt, arg1, arg2, arg3, arg4, arg5, arg6);
E 9
I 9
	(void) sprintf(buf, fmt, arg1, arg2, arg3, arg4, arg5, arg6);
E 9
	if (column != 0 && strlen(buf) < 39)
		while (column++ < 40)
D 9
			putchar(' ');
E 9
I 9
			(void) putchar(' ');
E 9
	else if (column) {
D 9
		putchar('\n');
E 9
I 9
		(void) putchar('\n');
E 9
		column = 0;
	}
	printf("%s", buf);
	column += strlen(buf);
}

alldigits(s)
	register char *s;
{
	register c;

	c = *s++;
	do {
		if (!isdigit(c))
			return (0);
	} while (c = *s++);
	return (1);
}
E 1
