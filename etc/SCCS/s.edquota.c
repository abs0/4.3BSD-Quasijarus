h00791
s 00010/00005/00409
d D 5.6 88/06/18 14:34:13 bostic 12 11
c install approved copyright notice
e
s 00010/00004/00404
d D 5.5 88/05/20 12:08:55 bostic 11 10
c add Berkeley specific header
e
s 00004/00004/00404
d D 5.4 88/02/27 14:45:45 bostic 10 9
c 2.10BSD long/int fixes
e
s 00004/00004/00404
d D 5.3 85/11/04 19:04:50 bloom 9 8
c rewrite to avoid division by zero
e
s 00015/00013/00393
d D 5.2 85/09/09 19:21:40 serge 8 7
c allow editing of user's quota on file systems where he has 0 blocks
e
s 00014/00002/00392
d D 5.1 85/05/30 19:54:08 mckusick 7 6
c Add copyright
e
s 00013/00006/00381
d D 4.6 85/05/24 17:03:05 mckusick 6 5
c warn of kernels not compiled for quotas
e
s 00005/00013/00382
d D 4.5 83/06/12 01:41:18 sam 5 4
c new signals
e
s 00039/00015/00356
d D 4.4 83/05/27 16:06:33 mckusick 4 3
c add -p (prototype) flag to allow bulk quota setting
e
s 00002/00002/00369
d D 4.3 83/05/25 16:03:15 mckusick 3 2
c new defines in file.h
e
s 00026/00026/00345
d D 4.2 83/05/25 14:50:16 mckusick 2 1
c fix bug in updating quota files; change to work in 1K units
e
s 00371/00000/00000
d D 4.1 83/05/24 14:34:12 mckusick 1 0
c date and time created 83/05/24 14:34:12 by mckusick
e
u
U
t
T
I 7
/*
 * Copyright (c) 1980 Regents of the University of California.
D 11
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 11
I 11
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 12
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 12
I 12
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
E 12
E 11
 */

E 7
I 1
#ifndef lint
D 7
static char sccsid[] = "%W% (Berkeley, from Melbourne) %G%";
#endif
E 7
I 7
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
D 11
#endif not lint
E 11
I 11
#endif /* not lint */
E 11

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 11
#endif not lint
E 11
I 11
#endif /* not lint */
E 11
E 7

/*
 * Disk quota editor.
 */
#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <pwd.h>
#include <ctype.h>
#include <fstab.h>

#include <sys/param.h>
D 2
#define	QUOTA
E 2
I 2
D 4
#define QUOTA
E 2
#include <sys/quota.h>
E 4
#include <sys/stat.h>
#include <sys/file.h>
I 4
D 5
#define QUOTA
E 5
#include <sys/quota.h>
E 4

D 2
#ifdef MELBOURNE
#define	DEFEDITOR	"/bin/ed"
#else
E 2
#define	DEFEDITOR	"/usr/ucb/vi"
D 2
#endif
E 2

struct	dquot dq[NMOUNT];
struct	dquot odq[NMOUNT];
char	dqf[NMOUNT][MAXPATHLEN + 1];
char	odqf[NMOUNT][MAXPATHLEN + 1];

char	tmpfil[] = "/tmp/EdP.aXXXXX";
I 2
char	*qfname = "quotas";
E 2
D 4
char	*arg0;
E 4
char	*getenv();

main(argc, argv)
	char **argv;
{
I 4
	int uid;
	char *arg0;
E 4

	mktemp(tmpfil);
	close(creat(tmpfil, 0600));
	chown(tmpfil, getuid(), getgid());
	arg0 = *argv++;
	if (argc < 2) {
D 4
		fprintf(stderr, "Usage: %s username ...\n", arg0);
E 4
I 4
		fprintf(stderr, "Usage: %s [-p username] username ...\n", arg0);
E 4
		unlink(tmpfil);
		exit(1);
	}
	--argc;
	if (getuid()) {
		fprintf(stderr, "%s: permission denied\n", arg0);
		unlink(tmpfil);
		exit(1);
	}
D 4
	while (--argc >= 0)
		doedit(*argv++);
E 4
I 4
	if (argc > 2 && strcmp(*argv, "-p") == 0) {
		argc--, argv++;
		uid = getentry(*argv++);
		if (uid < 0) {
			unlink(tmpfil);
			exit(1);
		}
		getprivs(uid);
		argc--;
		while (argc-- > 0) {
			uid = getentry(*argv++);
			if (uid < 0)
				continue;
			getdiscq(uid, odq, odqf);
			putprivs(uid);
		}
		unlink(tmpfil);
		exit(0);
	}
	while (--argc >= 0) {
		uid = getentry(*argv++);
		if (uid < 0)
			continue;
		getprivs(uid);
		if (editit())
			putprivs(uid);
	}
E 4
	unlink(tmpfil);
	exit(0);
}

D 4
doedit(name)
	register char *name;
E 4
I 4
getentry(name)
	char *name;
E 4
{
D 4
	register uid;
	register struct passwd *pw;
E 4
I 4
	struct passwd *pw;
	int uid;
E 4

	if (alldigits(name))
		uid = atoi(name);
	else if (pw = getpwnam(name))
		uid = pw->pw_uid;
	else {
D 4
		fprintf(stderr, "%s: no such user\n");
E 4
I 4
		fprintf(stderr, "%s: no such user\n", name);
E 4
		sleep(1);
D 4
		return;
E 4
I 4
		return (-1);
E 4
	}
D 4
	getprivs(uid);
	if (editit())
		putprivs(uid);
E 4
I 4
	return (uid);
E 4
}

editit()
{
D 10
	register pid, xpid;
D 5
	int stat;
E 5
I 5
	int stat, omask;
E 10
I 10
	register int pid, xpid;
	long omask;
	int stat;
E 10
E 5

D 5
	sighold(SIGINT);
	sighold(SIGQUIT);
	sighold(SIGHUP);

E 5
I 5
D 10
#define	mask(s)	(1<<((s)-1))
	omask = sigblock(mask(SIGINT)|mask(SIGQUIT)|mask(SIGHUP));
E 10
I 10
	omask = sigblock(sigmask(SIGINT)|sigmask(SIGQUIT)|sigmask(SIGHUP));
E 10
E 5
 top:
	if ((pid = fork()) < 0) {
		extern errno;

		if (errno == EPROCLIM) {
			fprintf(stderr, "You have too many processes\n");
			return(0);
		}
		if (errno == EAGAIN) {
			sleep(1);
			goto top;
		}
		perror("fork");
		return (0);
	}
	if (pid == 0) {
		register char *ed;

D 5
		sigrelse(SIGINT);
		sigrelse(SIGQUIT);
		sigrelse(SIGHUP);
E 5
I 5
		sigsetmask(omask);
E 5
		setgid(getgid());
		setuid(getuid());
D 5

E 5
		if ((ed = getenv("EDITOR")) == (char *)0)
			ed = DEFEDITOR;
		execlp(ed, ed, tmpfil, 0);
		perror(ed);
		exit(1);
	}
	while ((xpid = wait(&stat)) >= 0)
		if (xpid == pid)
			break;
D 5
	sigrelse(SIGINT);
	sigrelse(SIGQUIT);
	sigrelse(SIGHUP);
E 5
I 5
	sigsetmask(omask);
E 5
	return (!stat);
}

getprivs(uid)
	register uid;
{
	register i;
	FILE *fd;

	getdiscq(uid, dq, dqf);
	for (i = 0; i < NMOUNT; i++) {
		odq[i] = dq[i];
		strcpy(odqf[i], dqf[i]);
	}
	if ((fd = fopen(tmpfil, "w")) == NULL) {
		fprintf(stderr, "edquota: ");
		perror(tmpfil);
		exit(1);
	}
	for (i = 0; i < NMOUNT; i++) {
		if (*dqf[i] == '\0')
			continue;
		fprintf(fd,
"fs %s blocks (soft = %d, hard = %d) inodes (soft = %d, hard = %d)\n"
			, dqf[i]
D 2
			, dq[i].dq_bsoftlimit
			, dq[i].dq_bhardlimit
E 2
I 2
D 9
			, dq[i].dq_bsoftlimit / btodb(1024)
			, dq[i].dq_bhardlimit / btodb(1024)
E 9
I 9
			, dbtob(dq[i].dq_bsoftlimit) / 1024
			, dbtob(dq[i].dq_bhardlimit) / 1024
E 9
E 2
			, dq[i].dq_isoftlimit
			, dq[i].dq_ihardlimit
		);
	}
	fclose(fd);
}

putprivs(uid)
	register uid;
{
	register i, j;
	int n;
	FILE *fd;
	char line[BUFSIZ];

	fd = fopen(tmpfil, "r");
	if (fd == NULL) {
		fprintf(stderr, "Can't re-read temp file!!\n");
		return;
	}
	for (i = 0; i < NMOUNT; i++) {
		char *cp, *dp, *next();

		if (fgets(line, sizeof (line), fd) == NULL)
			break;
		cp = next(line, " \t");
		if (cp == NULL)
			break;
		*cp++ = '\0';
		while (*cp && *cp == '\t' && *cp == ' ')
			cp++;
		dp = cp, cp = next(cp, " \t");
		if (cp == NULL)
			break;
		*cp++ = '\0';
		while (*cp && *cp == '\t' && *cp == ' ')
			cp++;
		strcpy(dqf[i], dp);
		n = sscanf(cp,
"blocks (soft = %d, hard = %d) inodes (soft = %hd, hard = %hd)\n"
			, &dq[i].dq_bsoftlimit
			, &dq[i].dq_bhardlimit
			, &dq[i].dq_isoftlimit
			, &dq[i].dq_ihardlimit
		);
D 2
		if (n != 4)
			break;
E 2
I 2
		if (n != 4) {
			fprintf(stderr, "%s: bad format\n", cp);
			continue;
		}
D 9
		dq[i].dq_bsoftlimit *= btodb(1024);
		dq[i].dq_bhardlimit *= btodb(1024);
E 9
I 9
		dq[i].dq_bsoftlimit = btodb(dq[i].dq_bsoftlimit * 1024);
		dq[i].dq_bhardlimit = btodb(dq[i].dq_bhardlimit * 1024);
E 9
E 2
	}
	fclose(fd);
	n = i;
	for (i = 0; i < n; i++) {
		if (*dqf[i] == '\0')
			break;
		for (j = 0; j < NMOUNT; j++) {
			if (strcmp(dqf[i], odqf[j]) == 0)
				break;
		}
		if (j >= NMOUNT)
			continue;
		*odqf[j] = '\0';
D 8
		if (dq[i].dq_isoftlimit == odq[j].dq_isoftlimit &&
		    dq[i].dq_ihardlimit == odq[j].dq_ihardlimit &&
		    dq[i].dq_bsoftlimit == odq[j].dq_bsoftlimit &&
		    dq[i].dq_bhardlimit == odq[j].dq_bhardlimit) {
D 2
			for (j = i; j < 15; j++) {
E 2
I 2
			for (j = i; j < NMOUNT; j++) {
E 2
				dq[j] = dq[j+1];
				strcpy(dqf[j], dqf[j+1]);
			}
			*dqf[j] = '\0';
			i--;
			continue;
		}
E 8
		/*
		 * This isn't really good enough, it is quite likely
		 * to have changed while we have been away editing,
		 * but it's not important enough to worry about at
		 * the minute.
		 */
		dq[i].dq_curblocks = odq[j].dq_curblocks;
		dq[i].dq_curinodes = odq[j].dq_curinodes;
		/*
		 * If we've upped the inode or disk block limits
		 * and the guy is out of warnings, reinitialize.
		 */
		if (dq[i].dq_bsoftlimit > odq[j].dq_bsoftlimit &&
		    dq[i].dq_bwarn == 0)
			dq[i].dq_bwarn = MAX_DQ_WARN;
		if (dq[i].dq_isoftlimit > odq[j].dq_isoftlimit &&
		    dq[i].dq_iwarn == 0)
			dq[i].dq_iwarn = MAX_IQ_WARN;
	}
	if (i < NMOUNT) {
		for (j = 0; j < NMOUNT; j++) {
			if (*odqf[j] == '\0')
				continue;
			strcpy(dqf[i], odqf[j]);
			dq[i].dq_isoftlimit = 0;
			dq[i].dq_ihardlimit = 0;
			dq[i].dq_bsoftlimit = 0;
			dq[i].dq_bhardlimit = 0;
			/*
			 * Same applies as just above
			 * but matters not at all, as we are just
			 * turning quota'ing off for this filesys.
			 */
			dq[i].dq_curblocks = odq[j].dq_curblocks;
			dq[i].dq_curinodes = odq[j].dq_curinodes;
			if (++i >= NMOUNT)
				break;
		}
	}
	if (*dqf[0])
		putdiscq(uid, dq, dqf);
}

char *
next(cp, match)
	register char *cp;
	char *match;
{
	register char *dp;

	while (cp && *cp) {
		for (dp = match; dp && *dp; dp++)
			if (*dp == *cp)
				return (cp);
		cp++;
	}
	return ((char *)0);
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

getdiscq(uid, dq, dqf)
	register uid;
	register struct dquot *dq;
	register char (*dqf)[MAXPATHLEN + 1];
{
	register struct fstab *fs;
D 2
	char qfname[MAXPATHLEN + 1];
E 2
I 2
	char qfilename[MAXPATHLEN + 1];
I 6
	struct stat statb;
	struct dqblk dqblk;
	dev_t fsdev;
	int fd;
	static int warned = 0;
	extern int errno;
E 6
E 2

	setfsent();
	while (fs = getfsent()) {
D 6
		struct	stat statb;
		struct	dqblk dqblk;
		dev_t	fsdev;

E 6
		if (stat(fs->fs_spec, &statb) < 0)
			continue;
		fsdev = statb.st_rdev;
D 2
		if (fs->fs_quotafile == 0 || *fs->fs_quotafile == '\0')
E 2
I 2
		sprintf(qfilename, "%s/%s", fs->fs_file, qfname);
		if (stat(qfilename, &statb) < 0 || statb.st_dev != fsdev)
E 2
			continue;
D 2
		sprintf(qfname, "%s/%s", fs->fs_file, fs->fs_quotafile);
		if (stat(qfname, &statb) < 0 || statb.st_dev != fsdev)
			continue;
E 2
		if (quota(Q_GETDLIM, uid, fsdev, &dqblk) != 0) {
D 2
			register fd = open(qfname, FRDONLY);
E 2
I 2
D 3
			register fd = open(qfilename, FRDONLY);
E 3
I 3
D 6
			register fd = open(qfilename, O_RDONLY);
E 3
E 2

E 6
I 6
	    		if (errno == EINVAL && !warned) {
				warned++;
				fprintf(stderr, "Warning: %s\n",
				    "Quotas are not compiled into this kernel");
				sleep(3);
			}
			fd = open(qfilename, O_RDONLY);
E 6
			if (fd < 0)
				continue;
D 3
			lseek(fd, (long)(uid * sizeof dqblk), FSEEK_ABSOLUTE);
E 3
I 3
			lseek(fd, (long)(uid * sizeof dqblk), L_SET);
E 3
D 8
			if (read(fd, &dqblk, sizeof dqblk) != sizeof (dqblk)) {
E 8
I 8
			switch (read(fd, &dqblk, sizeof dqblk)) {
			case 0:			/* EOF */
				/*
				 * Convert implicit 0 quota (EOF)
				 * into an explicit one (zero'ed dqblk)
				 */
				bzero((caddr_t)&dqblk, sizeof dqblk);
				break;

			case sizeof dqblk:	/* OK */
				break;

			default:		/* ERROR */
				fprintf(stderr, "edquota: read error in ");
				perror(qfilename);
E 8
				close(fd);
				continue;
			}
			close(fd);
D 2
#ifdef notdef
			if (dqblk.dqb_isoftlimit == 0 && dqblk.dqb_bsoftlimit == 0)
				continue;
#endif
E 2
		}
		dq->dq_dqb = dqblk;
		dq->dq_dev = fsdev;
		strcpy(*dqf, fs->fs_file);
		dq++, dqf++;
	}
	endfsent();
	**dqf = '\0';
}

putdiscq(uid, dq, dqf)
	register uid;
	register struct dquot *dq;
	register char (*dqf)[MAXPATHLEN + 1];
{
	register fd, cnt;
	struct stat sb;
	struct fstab *fs;

	cnt = 0;
	for (cnt = 0; ++cnt <= NMOUNT && **dqf; dq++, dqf++) {
		fs = getfsfile(*dqf);
D 2
		if (fs == NULL)
			goto nofile;
		strcat(*dqf, fs->fs_quotafile);
		if (stat(*dqf, &sb) >= 0 && (fd = open(*dqf, 1)) >= 0) {
E 2
I 2
		if (fs == NULL) {
			fprintf(stderr, "%s: not in /etc/fstab\n", *dqf);
			continue;
		}
		strcat(*dqf, "/");
		strcat(*dqf, qfname);
		if (stat(*dqf, &sb) >= 0)
			quota(Q_SETDLIM, uid, sb.st_dev, &dq->dq_dqb);
		if ((fd = open(*dqf, 1)) < 0) {
			perror(*dqf);
		} else {
E 2
			lseek(fd, (long)uid * (long)sizeof (struct dqblk), 0);
			if (write(fd, &dq->dq_dqb, sizeof (struct dqblk)) !=
			    sizeof (struct dqblk)) {
				fprintf(stderr, "edquota: ");
				perror(*dqf);
			}
			close(fd);
		}
D 2
nofile:
		quota(Q_SETDLIM, uid, sb.st_dev, &dq->dq_dqb);
E 2
	}
}
E 1
