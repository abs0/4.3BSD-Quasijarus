h50539
s 00010/00005/00446
d D 5.10 88/06/18 14:34:40 bostic 21 20
c install approved copyright notice
e
s 00010/00004/00441
d D 5.9 88/05/20 12:15:00 bostic 20 19
c add Berkeley specific header
e
s 00001/00001/00444
d D 5.8 87/10/22 10:37:29 bostic 19 18
c ANSI C; sprintf now returns an int.
e
s 00004/00005/00441
d D 5.7 87/02/23 17:40:04 mckusick 18 17
c convert SBLOCK to SBOFF; generalize use of dev_bsize
e
s 00038/00018/00408
d D 5.6 85/11/03 16:40:57 serge 17 14
c improve performance by using two FILE pointers instead of one
e
s 00032/00018/00408
d R 5.6 85/11/02 21:33:37 serge 16 14
c improve performance by using two FILE pointers instead of one
e
s 00031/00017/00409
d R 5.6 85/11/02 20:22:13 serge 15 14
c improve performance by using two FILE pointers instead of one
e
s 00003/00003/00423
d D 5.5 85/09/16 21:54:23 serge 14 13
c use raw device even if disk name begins with 'r'
e
s 00112/00043/00314
d D 5.4 85/09/15 17:57:44 serge 13 9
c added fsck like -p flag (from ulysses!amw)
e
s 00112/00043/00314
d R 5.4 85/09/15 17:52:31 serge 12 9
c added fsck like -p flag (from ulysses!amw)
e
s 00107/00041/00316
d R 5.4 85/09/15 17:08:41 serge 11 9
c added fsck like -p flag (from ulysses!amw)
e
s 00105/00039/00318
d R 5.4 85/09/15 17:01:05 serge 10 9
c add fsck like -p flag (from ulysses!amw)
e
s 00032/00019/00325
d D 5.3 85/09/09 19:34:46 serge 9 8
c do not unset quotas of users who have 0 blocks on file system
e
s 00008/00002/00336
d D 5.2 85/06/17 20:42:30 mckusick 8 7
c avoid brain damage in stdio
e
s 00014/00002/00324
d D 5.1 85/05/30 19:54:39 mckusick 7 6
c Add copyright
e
s 00009/00001/00317
d D 4.6 85/05/24 17:00:53 mckusick 6 5
c in verbose mode, warn of kernels not compiled for quotas
e
s 00009/00004/00309
d D 4.5 85/03/19 16:22:57 mckusick 5 4
c zero out quotas for deleted uids
e
s 00002/00002/00311
d D 4.4 83/06/22 16:24:01 mckusick 4 3
c have to use the value before zeroing it!
e
s 00029/00006/00284
d D 4.3 83/05/27 15:16:55 mckusick 3 2
c translate uid's to names; zero out blocks after using them
e
s 00182/00206/00108
d D 4.2 83/05/24 13:13:11 mckusick 2 1
c use fstab, add -a and -v flags
e
s 00314/00000/00000
d D 4.1 83/05/22 14:52:26 mckusick 1 0
c date and time created 83/05/22 14:52:26 by mckusick
e
u
U
t
T
I 7
/*
 * Copyright (c) 1980 Regents of the University of California.
D 20
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 20
I 20
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 21
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 21
I 21
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
E 21
E 20
 */

E 7
I 1
D 2
#ifndef lit
static char sccsid[] = "%W% (Melbourne) %G%";
E 2
I 2
#ifndef lint
D 7
static char sccsid[] = "%W% (Berkeley, Melbourne) %G%";
E 2
#endif
E 7
I 7
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
D 20
#endif not lint
E 20
I 20
#endif /* not lint */
E 20

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 20
#endif not lint
E 20
I 20
#endif /* not lint */
E 20
E 7

/*
 * Fix up / report on disc quotas & usage
 */
#include <stdio.h>
#include <ctype.h>
#include <signal.h>
I 6
#include <errno.h>
E 6
D 3
#include <pwd.h>
E 3
#include <sys/param.h>
#include <sys/inode.h>
#include <sys/fs.h>
D 3
#define	QUOTA
E 3
#include <sys/quota.h>
#include <sys/stat.h>
I 13
#include <sys/wait.h>
E 13
I 2
#include <fstab.h>
I 3
#include <pwd.h>
E 3
E 2

D 2
#define	ITABSZ	256
#define	NUID	3500
E 2
union {
	struct	fs	sblk;
D 2
	char	___[MAXBSIZE];
E 2
I 2
	char	dummy[MAXBSIZE];
E 2
} un;
#define	sblock	un.sblk
I 2

#define	ITABSZ	256
E 2
struct	dinode	itab[ITABSZ];
struct	dinode	*dp;
D 2
struct	dqblk	du[NUID];
char	*dn[NUID];
struct	dqblk	zeroes;
u_short	iuse[NUID];
u_long	buse[NUID];
E 2
D 13
long	blocks;
dev_t	dev;
E 13

I 3
#define LOGINNAMESIZE 8
E 3
D 2
int	bflg;
int	iflg;
int	rflg;
int	sflg;
E 2
I 2
struct fileusage {
I 3
	struct fileusage *fu_next;
E 3
	struct dqusage fu_usage;
	u_short	fu_uid;
D 3
	struct fileusage *fu_next;
E 3
I 3
	char fu_name[LOGINNAMESIZE + 1];
E 3
};
#define FUHASH 997
struct fileusage *fuhead[FUHASH];
struct fileusage *lookup();
struct fileusage *adduid();
int highuid;
E 2

D 2
int	fi;
unsigned	ino;
unsigned	nfiles;
int	highuid;

E 2
I 2
int fi;
ino_t ino;
long done;
E 2
struct	passwd	*getpwent();
struct	dinode	*ginode();
D 2
char	*malloc();
char	*copy();
E 2
I 2
char *malloc(), *makerawname();
E 2

I 2
int	vflag;		/* verbose */
int	aflag;		/* all file systems */
I 13
int	pflag;		/* fsck like parallel check */
E 13

char *qfname = "quotas";
char quotafile[MAXPATHLEN + 1];
I 3
struct dqblk zerodqbuf;
I 13
struct fileusage zerofileusage;
I 18
long dev_bsize = 1;
E 18
E 13
E 3

E 2
main(argc, argv)
I 2
	int argc;
E 2
	char **argv;
{
D 2
	register int n;
	register struct passwd *lp;
	register char *p;
	register long unsigned i;
	register c;
	register cg;
	FILE *qf;
	struct stat statb;
E 2
I 2
	register struct fstab *fs;
I 3
	register struct fileusage *fup;
	register struct passwd *pw;
E 3
	int i, errs = 0;
E 2

D 2
	while (--argc > 0 && *(p = *++argv) == '-')
		while (c = *++p) switch (c) {

		case 's':
			sflg++;
			break;

		case 'b':
			bflg++;
			break;

		case 'i':
			iflg++;
			break;

		case 'r':
			rflg++;
			break;
		}

	if (argc != 2) {
		fprintf(stderr, "Usage: fixquota filesys qfile\n");
		exit(1);
E 2
I 2
again:
	argc--, argv++;
	if (argc > 0 && strcmp(*argv, "-v") == 0) {
		vflag++;
		goto again;
E 2
	}
D 2

	fi = open(p, 0);
	if (fi < 0) {
		fprintf(stderr, "Can't open %s\n", p);
E 2
I 2
	if (argc > 0 && strcmp(*argv, "-a") == 0) {
		aflag++;
		goto again;
	}
I 13
	if (argc > 0 && strcmp(*argv, "-p") == 0) {
		pflag++;
		goto again;
	}
E 13
	if (argc <= 0 && !aflag) {
		fprintf(stderr, "Usage:\n\t%s\n\t%s\n",
D 13
			"quotacheck [-v] -a",
			"quotacheck [-v] filesys ...");
E 13
I 13
			"quotacheck [-v] [-p] -a",
			"quotacheck [-v] [-p] filesys ...");
E 13
E 2
		exit(1);
	}
I 3
D 9
	if (vflag) {
		setpwent();
		while ((pw = getpwent()) != 0) {
			fup = lookup(pw->pw_uid);
			if (fup == 0)
				fup = adduid(pw->pw_uid);
			strncpy(fup->fu_name, pw->pw_name,
				sizeof(fup->fu_name));
		}
		endpwent();
E 9
I 9

	setpwent();
	while ((pw = getpwent()) != 0) {
		fup = lookup(pw->pw_uid);
D 13
		if (fup == 0)
E 13
I 13
		if (fup == 0) {
E 13
			fup = adduid(pw->pw_uid);
D 13
		strncpy(fup->fu_name, pw->pw_name,
			sizeof(fup->fu_name));
E 13
I 13
			strncpy(fup->fu_name, pw->pw_name,
				sizeof(fup->fu_name));
		}
E 13
E 9
	}
I 9
	endpwent();

E 9
E 3
D 2

	if (iflg || bflg || rflg) {
		while((lp=getpwent()) != 0) {
			n = lp->pw_uid;
			if (n>=NUID)
				continue;
			if(dn[n])
				continue;
			dn[n] = copy(lp->pw_name);
		}
E 2
I 2
D 13
	setfsent();
	while ((fs = getfsent()) != NULL) {
		if (aflag &&
		    (fs->fs_type == 0 || strcmp(fs->fs_type, "rq") != 0))
			continue;
		if (!aflag &&
		    !(oneof(fs->fs_file, argv, argc) ||
		      oneof(fs->fs_spec, argv, argc)))
			continue;
		(void) sprintf(quotafile, "%s/%s", fs->fs_file, qfname);
D 9
		errs += chkquota(fs->fs_spec, quotafile);
E 9
I 9
		errs += chkquota(fs->fs_spec, fs->fs_file, quotafile);
E 13
I 13
	if (pflag)
		errs = preen(argc, argv);
	else {
		if (setfsent() == 0) {
			fprintf(stderr, "Can't open ");
			perror(FSTAB);
			exit(8);
		}
		while ((fs = getfsent()) != NULL) {
			if (aflag &&
			    (fs->fs_type == 0 ||
			     strcmp(fs->fs_type, FSTAB_RQ) != 0))
				continue;
			if (!aflag &&
			    !(oneof(fs->fs_file, argv, argc) ||
			      oneof(fs->fs_spec, argv, argc)))
				continue;
			(void) sprintf(quotafile, "%s/%s", fs->fs_file, qfname);
			errs += chkquota(fs->fs_spec, fs->fs_file, quotafile);
		}
		endfsent();
E 13
E 9
E 2
	}
I 2
D 13
	endfsent();
E 13
I 13

E 13
	for (i = 0; i < argc; i++)
		if ((done & (1 << i)) == 0)
D 14
			fprintf(stderr, "%s not found in /etc/fstab\n",
				argv[i]);
E 14
I 14
			fprintf(stderr, "%s not found in %s\n",
				argv[i], FSTAB);
E 14
	exit(errs);
}
E 2

I 13
preen(argc, argv)
	int argc;
	char **argv;
{
	register struct fstab *fs;
	register int passno, anygtr;
	register int errs;
	union wait status;

	passno = 1;
	errs = 0;
	do {
		anygtr = 0;

		if (setfsent() == 0) {
			fprintf(stderr, "Can't open ");
			perror(FSTAB);
			exit(8);
		}

		while ((fs = getfsent()) != NULL) {
			if (fs->fs_passno > passno)
				anygtr = 1;

			if (aflag &&
			    (fs->fs_type == 0 ||
			     strcmp(fs->fs_type, FSTAB_RQ) != 0))
				continue;

			if (!aflag &&
			    !(oneof(fs->fs_file, argv, argc) ||
			      oneof(fs->fs_spec, argv, argc)))
				continue;

			if (fs->fs_passno != passno)
				continue;

			switch (fork()) {
			case -1:
				perror("fork");
				exit(8);
				break;

			case 0:
D 19
				sprintf(quotafile, "%s/%s",
E 19
I 19
				(void) sprintf(quotafile, "%s/%s",
E 19
					fs->fs_file, qfname);
				exit(chkquota(fs->fs_spec,
					fs->fs_file, quotafile));
			}
		}

		while (wait(&status) != -1) 
			errs += status.w_retcode;

		passno++;
	} while (anygtr);

	return (errs);
}

E 13
D 2
	if (!(iflg || bflg))
		sflg++;
E 2
I 2
D 9
chkquota(fsdev, qffile)
E 9
I 9
chkquota(fsdev, fsfile, qffile)
E 9
	char *fsdev;
I 9
	char *fsfile;
E 9
	char *qffile;
{
	register struct fileusage *fup;
	dev_t quotadev;
D 17
	FILE *qf;
E 17
I 17
	register FILE *qfi, *qfo;
E 17
	u_short uid;
D 17
	int cg, i;
E 17
I 17
	int cg, i, fdo;
E 17
	char *rawdisk;
	struct stat statb;
	struct dqblk dqbuf;
I 6
	static int warned = 0;
	extern int errno;
E 6
E 2

D 2
	qf = fopen(*++argv, "r");
	if (qf != NULL) {
		fstat(fileno(qf), &statb);
		dev = statb.st_dev;
		quota(Q_SYNC, 0, dev, 0);
		n = fread(du, sizeof(struct dqblk), NUID, qf);
		if (n == EOF)
			n = 0;
		highuid = n-1;
		fclose(qf);
	} else {
		highuid = -1;
		dev = NODEV;
E 2
I 2
	rawdisk = makerawname(fsdev);
	if (vflag)
D 9
		fprintf(stdout, "*** Check quotas for %s\n", rawdisk);
E 9
I 9
D 13
		fprintf(stdout, "*** Check quotas for %s (%s)\n", rawdisk, fsfile);
E 13
I 13
		fprintf(stdout, "*** Checking quotas for %s (%s)\n", rawdisk, fsfile);
E 13
E 9
	fi = open(rawdisk, 0);
	if (fi < 0) {
		perror(rawdisk);
		return (1);
E 2
	}
D 2
/*ZZprintf("highuid = %d\n", highuid);*/

	for (n = 0; n <= highuid; n++) {
		iuse[n] = du[n].dqb_curinodes;
		buse[n] = du[n].dqb_curblocks;
		du[n].dqb_curinodes = du[n].dqb_curblocks = 0;
E 2
I 2
D 17
	qf = fopen(qffile, "r+");
	if (qf == NULL) {
E 17
I 17
	qfi = fopen(qffile, "r");
	if (qfi == NULL) {
E 17
		perror(qffile);
I 9
		close(fi);
E 9
		return (1);
E 2
	}
D 2

E 2
I 2
D 17
	if (fstat(fileno(qf), &statb) < 0) {
E 17
I 17
	if (fstat(fileno(qfi), &statb) < 0) {
E 17
		perror(qffile);
I 9
D 17
		fclose(qf);
E 17
I 17
		fclose(qfi);
E 17
		close(fi);
E 9
		return (1);
	}
	quotadev = statb.st_dev;
	if (stat(fsdev, &statb) < 0) {
		perror(fsdev);
I 9
D 17
		fclose(qf);
E 17
I 17
		fclose(qfi);
E 17
		close(fi);
E 9
		return (1);
	}
	if (quotadev != statb.st_rdev) {
		fprintf(stderr, "%s dev (0x%x) mismatch %s dev (0x%x)\n",
			qffile, quotadev, fsdev, statb.st_rdev);
I 9
D 17
		fclose(qf);
E 17
I 17
		fclose(qfi);
E 17
		close(fi);
E 9
		return (1);
	}
I 17
	/*
	 * Must do fdopen(open(qffile, 1), "w") instead of fopen(qffile, "w")
	 * because fopen(qffile, "w") would truncate the quota file.
	 */
	fdo = open(qffile, 1);
	if (fdo < 0 || (qfo = fdopen(fdo, "w")) == NULL) {
		perror(qffile);
		if (fdo >= 0)
			close(fdo);
		fclose(qfi);
		close(fi);
		return (1);
	}
E 17
D 6
	quota(Q_SYNC, 0, quotadev, 0);
E 6
I 6
D 13
	if (quota(Q_SYNC, 0, quotadev, 0) < 0 &&
E 13
I 13
	if (quota(Q_SYNC, 0, quotadev, (caddr_t)0) < 0 &&
E 13
	    errno == EINVAL && !warned && vflag) {
		warned++;
		fprintf(stdout,
		    "*** Warning: Quotas are not compiled into this kernel\n");
	}
E 6
E 2
	sync();
D 18
	bread(SBLOCK, (char *)&sblock, SBSIZE);
E 18
I 18
	bread(SBOFF, (char *)&sblock, SBSIZE);
	dev_bsize = sblock.fs_fsize / fsbtodb(&sblock, 1);
E 18
	ino = 0;
	for (cg = 0; cg < sblock.fs_ncg; cg++) {
D 2
/*ZZprintf("cg %d <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n", cg);*/
E 2
		dp = NULL;
		for (i = 0; i < sblock.fs_ipg; i++)
			acct(ginode());
	}
D 2
	if (sflg && highuid >= 0) {
		int sig;
		int ssig;

		sig = (int) signal(SIGINT, SIG_IGN);
		ssig = (int) signal(SIGTSTP, SIG_IGN);
		if ((qf = fopen(*argv, "a")) == NULL) {
			fprintf(stderr, "Can't create %s\n", *argv);
			exit(1);
E 2
I 2
	for (uid = 0; uid <= highuid; uid++) {
I 9
D 17
		fseek(qf, (long)uid * sizeof(struct dqblk), 0);
E 9
D 5
		fup = lookup(uid);
		if (fup == 0)
			continue;
		fseek(qf, uid * sizeof(struct dqblk), 0);
E 5
		i = fread(&dqbuf, sizeof(struct dqblk), 1, qf);
E 17
I 17
		i = fread(&dqbuf, sizeof(struct dqblk), 1, qfi);
E 17
		if (i == 0)
D 3
			bzero(&dqbuf, sizeof(struct dqblk));
E 3
I 3
			dqbuf = zerodqbuf;
I 5
		fup = lookup(uid);
D 13
		if (fup == 0) {
D 8
			if (!feof(qf)) {
E 8
I 8
			if ((dqbuf.dqb_curinodes != 0 ||
			    dqbuf.dqb_curblocks != 0) &&
			    !feof(qf)) {
				dqbuf.dqb_curinodes = 0;
				dqbuf.dqb_curblocks = 0;
E 8
D 9
				fseek(qf, uid * sizeof(struct dqblk), 0);
E 9
I 9
				fseek(qf, (long)uid * sizeof(struct dqblk), 0);
E 9
D 8
				fwrite(&zerodqbuf, sizeof(struct dqblk), 1, qf);
E 8
I 8
				fwrite(&dqbuf, sizeof(struct dqblk), 1, qf);
D 9
				fseek(qf, (uid + 1) * sizeof(struct dqblk), 0);
E 9
E 8
			}
			continue;
		}
E 13
I 13
		if (fup == 0)
			fup = &zerofileusage;
E 13
E 5
E 3
		if (dqbuf.dqb_curinodes == fup->fu_usage.du_curinodes &&
D 3
		    dqbuf.dqb_curblocks == fup->fu_usage.du_curblocks)
E 3
I 3
		    dqbuf.dqb_curblocks == fup->fu_usage.du_curblocks) {
			fup->fu_usage.du_curinodes = 0;
			fup->fu_usage.du_curblocks = 0;
I 17
			fseek(qfo, (long)sizeof(struct dqblk), 1);
E 17
E 3
			continue;
I 3
		}
E 3
		if (vflag) {
I 13
			if (pflag)
				printf("%s: ", rawdisk);
E 13
D 3
			fprintf(stdout, "uid %d fixed:", uid);
E 3
I 3
			if (fup->fu_name[0] != '\0')
D 13
				printf("%-10s fixed:", fup->fu_name);
E 13
I 13
				printf("%-8s fixed:", fup->fu_name);
E 13
			else
D 13
				printf("#%-9d fixed:", uid);
E 3
			fprintf(stdout, " inodes (old %d, new %d)",
			    dqbuf.dqb_curinodes, fup->fu_usage.du_curinodes);
			fprintf(stdout, " blocks (old %d, new %d)\n",
			    dqbuf.dqb_curblocks, fup->fu_usage.du_curblocks);
E 13
I 13
				printf("#%-7d fixed:", uid);
			if (dqbuf.dqb_curinodes != fup->fu_usage.du_curinodes)
D 17
				fprintf(stdout, "  inodes %d -> %d",
E 17
I 17
				fprintf(stdout, "\tinodes %d -> %d",
E 17
					dqbuf.dqb_curinodes, fup->fu_usage.du_curinodes);
			if (dqbuf.dqb_curblocks != fup->fu_usage.du_curblocks)
D 17
				fprintf(stdout, "  blocks %d -> %d",
E 17
I 17
				fprintf(stdout, "\tblocks %d -> %d",
E 17
					dqbuf.dqb_curblocks, fup->fu_usage.du_curblocks);
			fprintf(stdout, "\n");
E 13
E 2
		}
D 2

		rewind(qf);
		fwrite(du, sizeof(struct dqblk), highuid+1, qf);
		fclose(qf);
		signal(SIGTSTP, ssig);
		sysset();
		signal(SIGINT, sig);
E 2
I 2
		dqbuf.dqb_curinodes = fup->fu_usage.du_curinodes;
		dqbuf.dqb_curblocks = fup->fu_usage.du_curblocks;
I 3
D 4
		fup->fu_usage.du_curinodes = 0;
		fup->fu_usage.du_curblocks = 0;
E 4
E 3
D 9
		fseek(qf, uid * sizeof(struct dqblk), 0);
E 9
I 9
D 17
		fseek(qf, (long)uid * sizeof(struct dqblk), 0);
E 9
		fwrite(&dqbuf, sizeof(struct dqblk), 1, qf);
E 17
I 17
		fwrite(&dqbuf, sizeof(struct dqblk), 1, qfo);
E 17
I 8
D 9
		fseek(qf, (uid + 1) * sizeof(struct dqblk), 0);
E 9
E 8
		quota(Q_SETDUSE, uid, quotadev, &fup->fu_usage);
I 4
		fup->fu_usage.du_curinodes = 0;
		fup->fu_usage.du_curblocks = 0;
E 4
E 2
	}
I 9
D 17
	fflush(qf);
E 9
I 5
	ftruncate(fileno(qf), (highuid + 1) * sizeof(struct dqblk));
I 9
	fclose(qf);
E 17
I 17
	fflush(qfo);
	ftruncate(fileno(qfo), (off_t)((highuid + 1) * sizeof(struct dqblk)));
	fclose(qfi);
	fclose(qfo);
E 17
	close(fi);
E 9
E 5
D 2
	report();
E 2
I 2
	return (0);
E 2
}

acct(ip)
	register struct dinode *ip;
{
D 13
	register n;
E 13
I 2
	register struct fileusage *fup;
E 2

	if (ip == NULL)
		return;
	if (ip->di_mode == 0)
D 2
/*ZZ{printf(" unallocated\n");*/
E 2
		return;
D 2
/*ZZ}*/
	if (ip->di_uid >= NUID)
/*ZZ{printf(" uid oor\n");*/
		return;
/*ZZ}*/
	if (ip->di_uid > highuid) {
		for (n = highuid+1; n <= ip->di_uid; n++)
			du[n] = zeroes;
		highuid = ip->di_uid;
	}
	du[ip->di_uid].dqb_curinodes++;
E 2
I 2
D 13
	fup = lookup(ip->di_uid);
	if (fup == 0)
		fup = adduid(ip->di_uid);
E 13
I 13
	fup = adduid(ip->di_uid);
E 13
	fup->fu_usage.du_curinodes++;
E 2
	if ((ip->di_mode & IFMT) == IFCHR || (ip->di_mode & IFMT) == IFBLK)
D 2
/*ZZ{printf(" special\n");*/
E 2
		return;
D 2
/*ZZ}*/
	blocks = 0;
	for (n = 0; n < NDADDR; n++)
		if (ip->di_db[n])
			blocks += dblksize(&sblock, ip, n) / DEV_BSIZE;
	for (n = 0; n < NIADDR; n++)
		tloop(ip->di_ib[n], ip, n);
	du[ip->di_uid].dqb_curblocks += blocks;
	if (blocks != ip->di_blocks)
		printf("Ino %d: <calc %d, recorded %d>\n", ino, blocks, ip->di_blocks);
/*ZZprintf(" %d blks\n", blocks);*/
E 2
I 2
	fup->fu_usage.du_curblocks += ip->di_blocks;
E 2
}

D 2
tloop(bn, ip, f)
	long bn;
E 2
I 2
oneof(target, list, n)
	char *target, *list[];
	register int n;
E 2
{
D 2
	register i;
	long	iblk[MAXBSIZE/sizeof(long)];
E 2
I 2
	register int i;
E 2

D 2
	if (!bn)
		return;
	blocks += sblock.fs_bsize / DEV_BSIZE;
	bread(fsbtodb(&sblock, bn), iblk, sblock.fs_bsize);
	if (f) {
		for (i = 0; i < NINDIR(&sblock); i++)
			tloop(iblk[i], ip, f-1);
	} else {
		for (i = 0; i < NINDIR(&sblock); i++)
			if (iblk[i])
				blocks += sblock.fs_bsize / DEV_BSIZE;
	}
E 2
I 2
	for (i = 0; i < n; i++)
		if (strcmp(target, list[i]) == 0) {
			done |= 1 << i;
			return (1);
		}
	return (0);
E 2
}

struct dinode *
ginode()
{
	register unsigned long iblk;

	if (dp == NULL || ++dp >= &itab[ITABSZ]) {
		iblk = itod(&sblock, ino);
D 2
/*ZZprintf("dp = %x, itab=%x", dp, itab);*/
/*ZZprintf(" Reading inodes from fs blk %d ", iblk);*/
E 2
		bread(fsbtodb(&sblock, iblk), (char *)itab, sizeof itab);
		dp = &itab[ino % INOPB(&sblock)];
D 2
/*ZZprintf("dp = %x\n", dp, itab);*/
E 2
	}
D 2
/*ZZprintf("ino %d ", ino);*/
E 2
	if (ino++ < ROOTINO)
		return(NULL);
	return(dp);
}

bread(bno, buf, cnt)
	long unsigned bno;
	char *buf;
{
I 17
D 18
	extern	off_t lseek();
	register off_t pos;
E 18
E 17

D 2
	lseek(fi, (long)bno*DEV_BSIZE, 0);
E 2
I 2
D 17
	lseek(fi, (long)dbtob(bno), 0);
E 17
I 17
D 18
	pos = (off_t)dbtob(bno);
	if (lseek(fi, pos, 0) != pos) {
E 18
I 18
	if (lseek(fi, bno * dev_bsize, 0) < 0) {
E 18
		perror("lseek");
		exit(1);
	}

E 17
E 2
	if (read(fi, buf, cnt) != cnt) {
D 13
		printf("read error %u\n", bno);
E 13
I 13
		perror("read");
E 13
		exit(1);
	}
}

D 2
sysset()
E 2
I 2
struct fileusage *
lookup(uid)
	u_short uid;
E 2
{
D 2
	struct dqusage usage;
	register i;
E 2
I 2
	register struct fileusage *fup;
E 2

D 2
	for (i = 0; i <= highuid; i++) {
		if (du[i].dqb_curinodes != iuse[i] || du[i].dqb_curblocks != buse[i]) {
			if (du[i].dqb_isoftlimit == 0 && du[i].dqb_bsoftlimit == 0)
				continue;
			if (rflg) {
				if (dn[i])
					printf("%s", dn[i]);
				else
					printf("#%d", i);
				printf(": i %d->%d, b %d->%d\n"
					, iuse[i]
					, du[i].dqb_curinodes
					, buse[i]
					, du[i].dqb_curblocks
				);
			}
			usage.du_curinodes = du[i].dqb_curinodes;
			usage.du_curblocks = du[i].dqb_curblocks;
			quota(Q_SETDUSE, i, dev, &usage);
		}
	}
E 2
I 2
	for (fup = fuhead[uid % FUHASH]; fup != 0; fup = fup->fu_next)
		if (fup->fu_uid == uid)
			return (fup);
	return ((struct fileusage *)0);
E 2
}

D 2
report()
E 2
I 2
struct fileusage *
adduid(uid)
	u_short uid;
E 2
{
D 2
	register i;
E 2
I 2
	struct fileusage *fup, **fhp;
I 9
	extern char *calloc();
E 9
E 2

D 2
	if (iflg)
		for (i = 0; i <= highuid; i++)
			if (du[i].dqb_isoftlimit && du[i].dqb_curinodes >= du[i].dqb_isoftlimit) {
				if (dn[i])
					printf("%-10s", dn[i]);
				else
					printf("#%-9d", i);
				printf("%5d (iq = %d)\n", du[i].dqb_curinodes, du[i].dqb_isoftlimit);
			}

	if (bflg)
		for (i = 0; i <= highuid; i++)
			if (du[i].dqb_bsoftlimit && du[i].dqb_curblocks >= du[i].dqb_bsoftlimit) {
				if (dn[i])
					printf("%-10s", dn[i]);
				else
					printf("#%-9s", i);
				printf("%5d (quot = %d)\n", du[i].dqb_curblocks, du[i].dqb_bsoftlimit);
			}
E 2
I 2
	fup = lookup(uid);
	if (fup != 0)
		return (fup);
	fup = (struct fileusage *)calloc(1, sizeof(struct fileusage));
	if (fup == 0) {
		fprintf(stderr, "out of memory for fileusage structures\n");
		exit(1);
	}
	fhp = &fuhead[uid % FUHASH];
	fup->fu_next = *fhp;
	*fhp = fup;
	fup->fu_uid = uid;
	if (uid > highuid)
		highuid = uid;
	return (fup);
E 2
}

char *
D 2
copy(s)
	char *s;
E 2
I 2
makerawname(name)
	char *name;
E 2
{
D 2
	register char *p;
	register n;
E 2
I 2
	register char *cp;
	char tmp, ch, *rindex();
	static char rawname[MAXPATHLEN];
E 2

D 2
	for(n=0; s[n]; n++)
		;
	p = malloc((unsigned)n+1);
	for(n=0; p[n] = s[n]; n++)
		;
	return(p);
E 2
I 2
	strcpy(rawname, name);
D 9
	cp = rindex(rawname, '/') + 1;
	if (cp == (char *)1 || *cp == 'r')
E 9
I 9
	cp = rindex(rawname, '/');
D 14
	if (cp == NULL || cp[1] == 'r')
E 14
I 14
	if (cp == NULL)
E 14
E 9
		return (name);
I 9
	else
		cp++;
E 9
	for (ch = 'r'; *cp != '\0'; ) {
		tmp = *cp;
		*cp++ = ch;
		ch = tmp;
	}
	*cp++ = ch;
	*cp = '\0';
	return (rawname);
E 2
}
E 1
