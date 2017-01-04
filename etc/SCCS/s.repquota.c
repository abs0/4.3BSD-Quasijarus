h57801
s 00010/00005/00231
d D 5.6 88/06/18 14:34:46 bostic 10 9
c install approved copyright notice
e
s 00010/00004/00226
d D 5.5 88/05/20 12:15:54 bostic 9 8
c add Berkeley specific header
e
s 00001/00002/00229
d D 5.4 86/03/05 20:16:47 mckusick 8 7
c do not print uid's with no blocks or files allocated
e
s 00003/00003/00228
d D 5.3 85/11/04 19:04:44 bloom 7 6
c rewrite to avoid division by zero
e
s 00012/00007/00219
d D 5.2 85/09/09 19:25:31 serge 6 5
c report quota for users who have 0 blocks on the file system
e
s 00014/00002/00212
d D 5.1 85/05/30 19:55:48 mckusick 5 4
c Add copyright
e
s 00009/00001/00205
d D 4.4 85/05/24 17:02:24 mckusick 4 3
c in verbose mode, warn of kernels not compiled for quotas
e
s 00003/00002/00203
d D 4.3 85/03/22 17:05:20 lepreau 3 2
c Use 1st, not last, passwd file entry for those with multiple entries per uid
e
s 00173/00076/00032
d D 4.2 83/05/27 15:14:06 mckusick 2 1
c Berkeleyize
e
s 00108/00000/00000
d D 4.1 83/05/25 15:03:54 mckusick 1 0
c date and time created 83/05/25 15:03:54 by mckusick
e
u
U
t
T
I 5
/*
 * Copyright (c) 1980 Regents of the University of California.
D 9
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 9
I 9
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 10
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 10
I 10
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
E 10
E 9
 */

E 5
I 1
#ifndef lint
D 2
static char sccsid[] = "%W% (Melbourne) %G%";
E 2
I 2
D 5
static char sccsid[] = "%W% (Berkeley, from Melbourne) %G%";
E 2
#endif
E 5
I 5
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
D 9
#endif not lint
E 9
I 9
#endif /* not lint */
E 9

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 9
#endif not lint
E 9
I 9
#endif /* not lint */
E 9
E 5

/*
 * Quota report
 */
#include <stdio.h>
I 4
#include <errno.h>
E 4
D 2
#include <ctype.h>
#include <pwd.h>
E 2
#include <sys/param.h>
D 2
#define	QUOTA
E 2
#include <sys/quota.h>
I 2
#include <sys/stat.h>
#include <fstab.h>
#include <pwd.h>
E 2

D 2
#define	NUID	3000
E 2
I 2
#define LOGINNAMESIZE 8
struct fileusage {
	struct fileusage *fu_next;
	struct dqblk fu_dqblk;
	u_short	fu_uid;
	char fu_name[LOGINNAMESIZE + 1];
};
#define FUHASH 997
struct fileusage *fuhead[FUHASH];
struct fileusage *lookup();
struct fileusage *adduid();
int highuid;
E 2

D 2
struct dqblk dq[NUID];
E 2
I 2
long done;
struct	passwd	*getpwent();
E 2

D 2
char	*dn[NUID];
int	nuids;
E 2
I 2
int	vflag;		/* verbose */
int	aflag;		/* all file systems */
E 2

I 2
char *qfname = "quotas";
D 6
char quotafile[MAXPATHLEN + 1];
E 6
struct dqblk zerodqblk;

E 2
main(argc, argv)
I 2
	int argc;
E 2
	char **argv;
{
D 2
	register struct passwd *lp;
	register n;
	register i;
	register FILE *qf;
	char *copy();
	struct passwd *getpwent();
E 2
I 2
	register struct fstab *fs;
	register struct passwd *pw;
	register struct fileusage *fup;
	char quotafile[MAXPATHLEN];
	int i, errs = 0;
E 2

D 2
	argc--;
	if ((qf = fopen(*++argv, "r")) == NULL) {
		fprintf(stderr, "Can't open %s\n", *argv);
E 2
I 2
again:
	argc--, argv++;
	if (argc > 0 && strcmp(*argv, "-v") == 0) {
		vflag++;
		goto again;
	}
	if (argc > 0 && strcmp(*argv, "-a") == 0) {
		aflag++;
		goto again;
	}
	if (argc <= 0 && !aflag) {
		fprintf(stderr, "Usage:\n\t%s\n\t%s\n",
			"repquota [-v] -a",
			"repquota [-v] filesys ...");
E 2
		exit(1);
	}
D 2
	argc--, argv++;
	nuids = fread(dq, sizeof(struct dqblk), NUID, qf);
	fclose(qf);
	while ((lp = getpwent()) != (struct passwd *)0) {
		n = lp->pw_uid;
		if (n >= NUID)
E 2
I 2
	setpwent();
	while ((pw = getpwent()) != 0) {
		fup = lookup(pw->pw_uid);
D 3
		if (fup == 0)
E 3
I 3
		if (fup == 0) {
E 3
			fup = adduid(pw->pw_uid);
D 3
		strncpy(fup->fu_name, pw->pw_name, sizeof(fup->fu_name));
E 3
I 3
			strncpy(fup->fu_name, pw->pw_name, sizeof(fup->fu_name));
		}
E 3
	}
	endpwent();
	setfsent();
	while ((fs = getfsent()) != NULL) {
		if (aflag &&
		    (fs->fs_type == 0 || strcmp(fs->fs_type, "rq") != 0))
E 2
			continue;
D 2
		if (dn[n])
E 2
I 2
		if (!aflag &&
		    !(oneof(fs->fs_file, argv, argc) ||
		      oneof(fs->fs_spec, argv, argc)))
E 2
			continue;
D 2
		dn[n] = copy(lp->pw_name);
E 2
I 2
		(void) sprintf(quotafile, "%s/%s", fs->fs_file, qfname);
D 6
		errs += repquota(fs->fs_spec, quotafile);
E 6
I 6
		errs += repquota(fs->fs_spec, fs->fs_file, quotafile);
E 6
E 2
	}
I 2
	endfsent();
	for (i = 0; i < argc; i++)
		if ((done & (1 << i)) == 0)
			fprintf(stderr, "%s not found in /etc/fstab\n",
				argv[i]);
	exit(errs);
}
E 2

D 2
	for (n = 0; n < nuids; n++) {
		if (argc > 0) {
			for (i = 0; i < argc; i++) {
				register char *p;
E 2
I 2
D 6
repquota(fsdev, qffile)
E 6
I 6
repquota(fsdev, fsfile, qffile)
E 6
	char *fsdev;
I 6
	char *fsfile;
E 6
	char *qffile;
{
	register struct fileusage *fup;
	FILE *qf;
	u_short uid;
	struct dqblk dqbuf;
	struct stat statb;
I 4
	static int warned = 0;
	extern int errno;
E 4
E 2

D 2
				for (p = argv[i]; *p && isdigit(*p); p++)
					;
				if (*p)
					continue;
				if (n == atoi(argv[i]))
					goto rep;
			}
			if (!dn[n])
				continue;
			for (i = 0; i < argc; i++)
				if (strcmp(argv[i], dn[n]) == 0)
					break;
			if (i >= argc)
				continue;
		} else if (dq[n].dqb_curinodes == 0 && dq[n].dqb_curblocks == 0)
E 2
I 2
	if (vflag)
D 6
		fprintf(stdout, "*** Quota report for %s\n", fsdev);
E 6
I 6
		fprintf(stdout, "*** Quota report for %s (%s)\n", fsdev, fsfile);
E 6
	qf = fopen(qffile, "r");
	if (qf == NULL) {
		perror(qffile);
		return (1);
	}
	if (fstat(fileno(qf), &statb) < 0) {
		perror(qffile);
I 6
		fclose(qf);
E 6
		return (1);
	}
D 4
	quota(Q_SYNC, 0, statb.st_dev, 0);
E 4
I 4
	if (quota(Q_SYNC, 0, statb.st_dev, 0) < 0 &&
	    errno == EINVAL && !warned && vflag) {
		warned++;
		fprintf(stdout,
		    "*** Warning: Quotas are not compiled into this kernel\n");
	}
E 4
	for (uid = 0; ; uid++) {
		fread(&dqbuf, sizeof(struct dqblk), 1, qf);
		if (feof(qf))
			break;
D 6
		if (dqbuf.dqb_curinodes == 0 && dqbuf.dqb_curblocks == 0)
E 2
			continue;
E 6
D 2
	rep:
		if (dn[n])
			printf("%-10s", dn[n]);
E 2
I 2
		fup = lookup(uid);
I 6
		if ((fup == 0 || fup->fu_name[0] == 0) &&
		    dqbuf.dqb_curinodes == 0 && dqbuf.dqb_curblocks == 0)
			continue;
E 6
		if (fup == 0)
			fup = adduid(uid);
		fup->fu_dqblk = dqbuf;
	}
	printf("                        Block limits               File limits\n");
	printf("User            used    soft    hard  warn    used  soft  hard  warn\n");
	for (uid = 0; uid <= highuid; uid++) {
		fup = lookup(uid);
		if (fup == 0)
			continue;
D 6
		if (fup->fu_dqblk.dqb_curinodes == 0 &&
E 6
I 6
D 8
		if ((fup == 0 || fup->fu_name[0] == 0) &&
		    fup->fu_dqblk.dqb_curinodes == 0 &&
E 8
I 8
		if (fup->fu_dqblk.dqb_curinodes == 0 &&
E 8
E 6
		    fup->fu_dqblk.dqb_curblocks == 0)
			continue;
		if (fup->fu_name[0] != '\0')
			printf("%-10s", fup->fu_name);
E 2
		else
D 2
			printf("#%-9d", n);

		printf("%c%c %5d %5d %5d %5d %5d %5d %5d %5d\n"
			, dq[n].dqb_bsoftlimit && dq[n].dqb_curblocks >= dq[n].dqb_bsoftlimit
				? '+' : '-'
			, dq[n].dqb_isoftlimit && dq[n].dqb_curinodes >= dq[n].dqb_isoftlimit
				? '+' : '-'
			, dq[n].dqb_curblocks
			, dq[n].dqb_bsoftlimit
			, dq[n].dqb_bhardlimit
			, dq[n].dqb_bwarn
			, dq[n].dqb_curinodes
			, dq[n].dqb_isoftlimit
			, dq[n].dqb_ihardlimit
			, dq[n].dqb_iwarn
		);
E 2
I 2
			printf("#%-9d", uid);
		printf("%c%c%8d%8d%8d %5d   %5d %5d %5d %5d\n",
			fup->fu_dqblk.dqb_bsoftlimit && 
			    fup->fu_dqblk.dqb_curblocks >= 
			    fup->fu_dqblk.dqb_bsoftlimit ? '+' : '-',
			fup->fu_dqblk.dqb_isoftlimit &&
			    fup->fu_dqblk.dqb_curinodes >=
			    fup->fu_dqblk.dqb_isoftlimit ? '+' : '-',
D 7
			fup->fu_dqblk.dqb_curblocks / btodb(1024),
			fup->fu_dqblk.dqb_bsoftlimit / btodb(1024),
			fup->fu_dqblk.dqb_bhardlimit / btodb(1024),
E 7
I 7
			dbtob(fup->fu_dqblk.dqb_curblocks) / 1024,
			dbtob(fup->fu_dqblk.dqb_bsoftlimit) / 1024,
			dbtob(fup->fu_dqblk.dqb_bhardlimit) / 1024,
E 7
			fup->fu_dqblk.dqb_bwarn,
			fup->fu_dqblk.dqb_curinodes,
			fup->fu_dqblk.dqb_isoftlimit,
			fup->fu_dqblk.dqb_ihardlimit,
			fup->fu_dqblk.dqb_iwarn);
		fup->fu_dqblk = zerodqblk;
E 2
	}
I 6
	fclose(qf);
E 6
D 2
	exit(0);
E 2
I 2
	return (0);
E 2
}

D 2
char *
copy(s)
	char *s;
E 2
I 2
oneof(target, list, n)
	char *target, *list[];
	register int n;
E 2
{
D 2
	register char *p;
	register n;
	char *malloc();
E 2
I 2
	register int i;
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
	for (i = 0; i < n; i++)
		if (strcmp(target, list[i]) == 0) {
			done |= 1 << i;
			return (1);
		}
	return (0);
}

struct fileusage *
lookup(uid)
	u_short uid;
{
	register struct fileusage *fup;

	for (fup = fuhead[uid % FUHASH]; fup != 0; fup = fup->fu_next)
		if (fup->fu_uid == uid)
			return (fup);
	return ((struct fileusage *)0);
}

struct fileusage *
adduid(uid)
	u_short uid;
{
	struct fileusage *fup, **fhp;
I 6
	extern char *calloc();
E 6

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
E 1
