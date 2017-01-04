h23718
s 00001/00001/00658
d D 5.9 87/10/22 09:51:43 bostic 33 32
c ANSI C; sprintf now returns an int.
e
s 00006/00006/00653
d D 5.8 87/09/11 11:40:32 bostic 32 31
c use S/T if exec bit not set; bug report 4.3BSD/bin/57
e
s 00091/00125/00568
d D 5.7 87/07/01 13:05:42 bostic 31 29
c use getopt(3), use uid_t/gid_t, minor lint work, cache group id's 
c in same fashion as uid's.
e
s 00065/00064/00629
d R 5.7 87/06/22 12:32:30 bostic 30 29
c lint, getopt
e
s 00000/00000/00693
d D 5.6 86/05/12 14:38:55 karels 29 28
x 26
c undo -S
e
s 00001/00001/00701
d D 5.5 86/03/04 05:14:51 lepreau 28 27
c XTABS is a 2 bit field
e
s 00001/00001/00701
d D 5.4 85/11/25 13:30:35 mckusick 27 26
c file systems grow larger
e
s 00011/00002/00691
d D 5.3 85/09/04 18:32:51 bloom 26 25
c add sort by size and bug fix (from serge@arpa)
e
s 00001/00001/00692
d D 5.2 85/07/26 10:36:52 bloom 25 24
c fix problem with -R listing incorrect directories
e
s 00014/00002/00679
d D 5.1 85/04/30 14:57:30 dist 24 23
c Add copyright
e
s 00018/00042/00663
d D 4.22 85/03/04 13:40:07 bloom 23 21
c major performance improvement
e
s 00011/00034/00671
d R 4.22 85/02/21 17:32:15 bloom 22 21
c don't waste time with getpwent, use getpwuid (a major win with
c a large password file
e
s 00007/00001/00698
d D 4.21 85/02/20 11:23:20 bloom 21 20
c use window size ioctl for output width
e
s 00006/00008/00693
d D 4.20 83/09/22 22:10:33 sam 20 19
c bug with large uids
e
s 00008/00007/00693
d D 4.19 83/08/19 16:19:19 sam 19 18
c incorrect max login name size
e
s 00001/00001/00699
d D 4.18 83/08/15 15:56:56 karels 18 17
c always complain if file can't be lstat'ed
e
s 00004/00002/00696
d D 4.17 83/08/14 22:53:00 sam 17 16
c default to lstat's when symbolic link points to oblivion
e
s 00019/00011/00679
d D 4.16 83/08/14 00:45:47 sam 16 15
c fix ralph's blunder
e
s 00011/00019/00679
d D 4.15 83/08/09 11:02:10 ralph 15 14
c fixed ls -L -f -F for symbolic links
e
s 00000/00000/00698
d D 4.14 83/07/01 23:57:30 wnj 14 13
c include problems
e
s 00001/00001/00697
d D 4.13 83/06/30 14:38:11 sam 13 12
c include fix
e
s 00001/00001/00697
d D 4.12 83/05/24 11:06:30 sam 12 11
c blew last delta, things changed while robert was away
e
s 00017/00028/00681
d D 4.11 83/05/22 18:06:27 sam 11 10
c user block count in inode (from kre)
e
s 00026/00003/00683
d D 4.10 83/05/10 12:53:20 mckusick 10 9
c fix -l to list groups with gid > NGID by name
e
s 00025/00002/00661
d D 4.9 83/05/09 18:02:34 mckusick 9 8
c fix -l so that it works with uid's that are >NUID
e
s 00009/00001/00654
d D 4.8 82/12/03 20:23:36 mckusick 8 7
c follow symbolic links that point to directories
e
s 00009/00001/00646
d D 4.7 82/11/14 16:33:00 sam 7 6
c convert to 4.1c sys calls and directory layout
e
s 00001/00001/00646
d D 4.6 82/05/07 16:20:29 mckusick 6 5
c update to new fs
e
s 00004/00004/00643
d D 4.5 82/03/31 11:44:38 root 5 4
c L option; use lstat by default
e
s 00001/00001/00646
d D 4.4 82/03/27 18:47:16 wnj 4 3
c too many args to sprintf in fmtentry
e
s 00002/00000/00645
d D 4.3 82/03/15 05:09:29 root 3 2
c ls -F prints links followed by @
e
s 00006/00006/00639
d D 4.2 82/03/05 15:16:18 root 2 1
c -l on dev and error message fixes
e
s 00645/00000/00000
d D 4.1 82/03/05 02:29:00 wnj 1 0
c date and time created 82/03/05 02:29:00 by wnj
e
u
U
t
T
I 24
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 24
I 1
#ifndef lint
D 11
static	char *sccsid = "%W% %E%";
E 11
I 11
D 24
static	char *sccsid = "%W% (Berkeley) %G%";
E 11
#endif
E 24
I 24
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 24

/*
 * ls
 *
D 11
 * 4.2bsd version for symbolic links and variable length directory entries.
E 11
I 11
 * 4.2bsd version for symbolic links, variable length
 * directory entries, block size in the inode, etc.
E 11
 */
D 11

E 11
#include <sys/param.h>
#include <sys/stat.h>
D 6
#include <ndir.h>
E 6
I 6
D 13
#include <dir.h>
E 13
I 13
#include <sys/dir.h>
E 13
E 6
#include <stdio.h>
#include <sgtty.h>

D 11
#define	kbytes(size)	((size + 1023) / 1024)
E 11
I 11
#define	kbytes(size)	(((size) + 1023) / 1024)
E 11

struct afile {
	char	ftype;		/* file type, e.g. 'd', 'c', 'f' */
	ino_t	fnum;		/* inode number of file */
	short	fflags;		/* mode&~S_IFMT, perhaps ISARG */
	short	fnl;		/* number of links */
D 31
	short	fuid;		/* owner id */
	short	fgid;		/* group id */
	long	fsize;		/* file size */
E 31
I 31
	uid_t	fuid;		/* owner id */
	gid_t	fgid;		/* group id */
	off_t	fsize;		/* file size */
E 31
I 11
	long	fblks;		/* number of blocks used */
E 11
	time_t	fmtime;		/* time (modify or access or create) */
	char	*fname;		/* file name */
	char	*flinkto;	/* symbolic link value */
};

#define ISARG	0x8000		/* extra ``mode'' */

struct subdirs {
	char	*sd_name;
	struct	subdirs *sd_next;
} *subdirs;

D 15
int	aflg, dflg, gflg, lflg, sflg, tflg, uflg, iflg, fflg, cflg, rflg = 1;
E 15
I 15
D 16
int	aflg, dflg, gflg, lflg, sflg, tflg, uflg, iflg, cflg, rflg = 1;
E 16
I 16
int	aflg, dflg, gflg, lflg, sflg, tflg, uflg, iflg, fflg, cflg, rflg = 1;
E 16
E 15
D 5
int	qflg, Aflg, Fflg, Rflg, Cflg, hflg;
E 5
I 5
D 26
int	qflg, Aflg, Cflg, Fflg, Lflg, Rflg;
E 26
I 26
int	qflg, Aflg, Cflg, Fflg, Lflg, Rflg, Sflg;
E 26
E 5

int	usetabs;

time_t	now, sixmonthsago;

char	*dotp = ".";

I 21
D 23
struct winsize win;
E 23
I 23
struct	winsize win;
E 23
int	twidth;

E 21
struct	afile *gstat();
int	fcmp();
char	*cat(), *savestr();
char	*fmtentry();
char	*getname(), *getgroup();

char	*ctime();
char	*malloc(), *calloc(), *realloc();
D 33
char	*sprintf(), *strcpy(), *strcat();
E 33
I 33
char	*strcpy(), *strcat();
E 33

main(argc, argv)
	int argc;
	char *argv[];
{
D 31
	int i;
E 31
I 31
	extern int optind;
E 31
	struct afile *fp0, *fplast;
	register struct afile *fp;
	struct sgttyb sgbuf;
I 31
	int ch, i;
	time_t time();
E 31

D 31
	argc--, argv++;
	if (getuid() == 0)
		Aflg++;
E 31
I 31
	Aflg = !getuid();
E 31
	(void) time(&now); sixmonthsago = now - 6L*30L*24L*60L*60L; now += 60;
I 21
	twidth = 80;
E 21
	if (isatty(1)) {
D 11

E 11
		qflg = Cflg = 1;
		(void) gtty(1, &sgbuf);
I 21
		if (ioctl(1, TIOCGWINSZ, &win) != -1)
			twidth = (win.ws_col == 0 ? 80 : win.ws_col);
E 21
D 28
		if ((sgbuf.sg_flags & XTABS) == 0)
E 28
I 28
		if ((sgbuf.sg_flags & XTABS) != XTABS)
E 28
			usetabs = 1;
	} else
		usetabs = 1;
D 31
	while (argc > 0 && **argv == '-') {
		(*argv)++;
		while (**argv) switch (*(*argv)++) {

		case 'C':
			Cflg = 1; break;
		case 'q':
			qflg = 1; break;
E 31
I 31
	while ((ch = getopt(argc, argv, "1ACLFRacdfgilqrstu")) != EOF)
		switch((char)ch) {
E 31
		case '1':
			Cflg = 0; break;
D 31
		case 'a':
			aflg++; break;
E 31
		case 'A':
			Aflg++; break;
I 31
		case 'C':
			Cflg = 1; break;
		case 'L':
			Lflg++; break;
		case 'F':
			Fflg++; break;
		case 'R':
			Rflg++; break;
		case 'a':
			aflg++; break;
E 31
		case 'c':
			cflg++; break;
I 26
		case 'S':
			Sflg++; /* fall into... */
E 26
D 31
		case 's':
			sflg++; break;
E 31
		case 'd':
			dflg++; break;
I 31
		case 'f':
			fflg++; break;
E 31
		case 'g':
			gflg++; break;
I 31
		case 'i':
			iflg++; break;
E 31
		case 'l':
			lflg++; break;
I 31
		case 'q':
			qflg = 1; break;
E 31
		case 'r':
			rflg = -1; break;
I 31
		case 's':
			sflg++; break;
E 31
		case 't':
			tflg++; break;
		case 'u':
			uflg++; break;
D 31
		case 'i':
			iflg++; break;
I 16
		case 'f':
			fflg++; break;
E 16
D 15
		case 'f':
			fflg++; break;
E 15
D 5
		case 'h':
			hflg++; break;
E 5
I 5
		case 'L':
			Lflg++; break;
E 5
		case 'F':
		        Fflg++; break;
		case 'R':
		        Rflg++; break;
		}
		argc--, argv++;
E 31
I 31
		case '?':
		default:
			fputs("usage: ls [ -1ACLFRacdfgilqrstu ] [ file ]\n", stderr);
			exit(1);
E 31
	}
I 16
	if (fflg) { 
D 26
		aflg++; lflg = 0; sflg = 0; tflg = 0;
E 26
I 26
		aflg++; Sflg = 0; tflg = 0; /* -f: only turn off sort flags */
E 26
	}
E 16
D 15
	if (fflg) { 
		aflg++; lflg = 0; sflg = 0; tflg = 0;
	}
E 15
	if (lflg)
		Cflg = 0;
I 31
	argc -= optind;
	argv += optind;
E 31
	if (argc == 0) {
		argc++;
		argv = &dotp;
	}
D 31
	fp = (struct afile *)calloc(argc, sizeof (struct afile));
E 31
I 31
	fp = (struct afile *)calloc((u_int)argc, sizeof (struct afile));
E 31
	if (fp == 0) {
D 31
		fprintf(stderr, "ls: out of memory\n");
E 31
I 31
		fputs("ls: out of memory\n", stderr);
E 31
		exit(1);
	}
	fp0 = fp;
	for (i = 0; i < argc; i++) {
D 2
		if (gstat(fp, *argv, 1, (int *)0) == 0)
			continue;
		fp->fname = *argv;
		fp->fflags |= ISARG;
		fp++;
E 2
I 2
		if (gstat(fp, *argv, 1, (int *)0)) {
			fp->fname = *argv;
			fp->fflags |= ISARG;
			fp++;
		}
E 2
		argv++;
	}
	fplast = fp;
	qsort(fp0, fplast - fp0, sizeof (struct afile), fcmp);
	if (dflg) {
		formatf(fp0, fplast);
		exit(0);
	}
D 15
	if (fflg)
		fp = fp0;
	else {
		for (fp = fp0; fp < fplast && fp->ftype != 'd'; fp++)
			continue;
		formatf(fp0, fp);
	}
E 15
I 15
D 16
	for (fp = fp0; fp < fplast && fp->ftype != 'd'; fp++)
		continue;
	formatf(fp0, fp);
E 16
I 16
	if (fflg)
		fp = fp0;
	else {
		for (fp = fp0; fp < fplast && fp->ftype != 'd'; fp++)
			continue;
		formatf(fp0, fp);
	}
E 16
E 15
	if (fp < fplast) {
		if (fp > fp0)
D 31
			printf("\n");
E 31
I 31
			putchar('\n');
E 31
		for (;;) {
			formatd(fp->fname, argc > 1);
			while (subdirs) {
				struct subdirs *t;

				t = subdirs; subdirs = t->sd_next;
D 31
				printf("\n");
E 31
I 31
				putchar('\n');
E 31
				formatd(t->sd_name, 1);
				cfree(t->sd_name);
				cfree((char *)t);
			}
			if (++fp == fplast)
				break;
D 31
			printf("\n");
E 31
I 31
			putchar('\n');
E 31
		}
	}
	exit(0);
}

formatd(name, title)
	char *name;
	int title;
{
	register struct afile *fp;
	register struct subdirs *dp;
	struct afile *dfp0, *dfplast;
	int nkb;

	nkb = getdir(name, &dfp0, &dfplast);
	if (dfp0 == 0)
		return;
D 15
	if (fflg == 0)
		qsort(dfp0, dfplast - dfp0, sizeof (struct afile), fcmp);
E 15
I 15
D 16
	qsort(dfp0, dfplast - dfp0, sizeof (struct afile), fcmp);
E 16
I 16
	if (fflg == 0)
		qsort(dfp0, dfplast - dfp0, sizeof (struct afile), fcmp);
E 16
E 15
	if (title)
		printf("%s:\n", name);
	if (lflg || sflg)
D 31
		printf("total %ld\n", nkb);
E 31
I 31
		printf("total %d\n", nkb);
E 31
	formatf(dfp0, dfplast);
	if (Rflg)
D 25
		for (fp = dfplast; fp >= dfp0; fp--) {
E 25
I 25
		for (fp = dfplast - 1; fp >= dfp0; fp--) {
E 25
			if (fp->ftype != 'd' ||
			    !strcmp(fp->fname, ".") ||
			    !strcmp(fp->fname, ".."))
				continue;
			dp = (struct subdirs *)malloc(sizeof (struct subdirs));
			dp->sd_name = savestr(cat(name, fp->fname));
			dp->sd_next = subdirs; subdirs = dp;
		}
	for (fp = dfp0; fp < dfplast; fp++) {
		if ((fp->fflags&ISARG) == 0 && fp->fname)
			cfree(fp->fname);
		if (fp->flinkto)
			cfree(fp->flinkto);
	}
	cfree((char *)dfp0);
}

getdir(dir, pfp0, pfplast)
	char *dir;
	struct afile **pfp0, **pfplast;
{
	register struct afile *fp;
	DIR *dirp;
	register struct direct *dp;
D 11
	int nkb, nent = 20;
E 11
I 11
	int nb, nent = 20;
E 11

	dirp = opendir(dir);
	if (dirp == NULL) {
		*pfp0 = *pfplast = NULL;
		printf("%s unreadable\n", dir);		/* not stderr! */
		return (0);
	}
	fp = *pfp0 = (struct afile *)calloc(nent, sizeof (struct afile));
	*pfplast = *pfp0 + nent;
D 11
	nkb = 0;
E 11
I 11
	nb = 0;
E 11
	while (dp = readdir(dirp)) {
		if (dp->d_ino == 0)
			continue;
		if (aflg == 0 && dp->d_name[0]=='.' &&
		    (Aflg == 0 || dp->d_name[1]==0 ||
		     dp->d_name[1]=='.' && dp->d_name[2]==0))
			continue;
D 11
		if (gstat(fp, cat(dir, dp->d_name), Fflg+Rflg, &nkb) == 0)
E 11
I 11
		if (gstat(fp, cat(dir, dp->d_name), Fflg+Rflg, &nb) == 0)
E 11
			continue;
		fp->fnum = dp->d_ino;
		fp->fname = savestr(dp->d_name);
		fp++;
		if (fp == *pfplast) {
			*pfp0 = (struct afile *)realloc((char *)*pfp0,
			    2 * nent * sizeof (struct afile));
			if (*pfp0 == 0) {
D 31
				fprintf(stderr, "ls: out of memory\n");
E 31
I 31
				fputs("ls: out of memory\n", stderr);
E 31
				exit(1);
			}
			fp = *pfp0 + nent;
			*pfplast = fp + nent;
			nent *= 2;
		}
	}
	closedir(dirp);
	*pfplast = fp;
D 11
	return (nkb);
E 11
I 11
	return (kbytes(dbtob(nb)));
E 11
}

int	stat(), lstat();

struct afile *
D 11
gstat(fp, file, statarg, pnkb)
E 11
I 11
gstat(fp, file, statarg, pnb)
E 11
	register struct afile *fp;
	char *file;
D 11
	int statarg, *pnkb;
E 11
I 11
	int statarg, *pnb;
E 11
{
D 5
	int (*statf)() = hflg ? lstat : stat;
E 5
I 5
D 11
	int (*statf)() = Lflg ? stat : lstat;
E 11
I 11
D 12
	int (*statf)() = Lflg || Fflg ? lstat : stat;
E 12
I 12
D 15
	int (*statf)() = Lflg || Fflg ? stat : lstat;
E 15
I 15
D 16
	int (*statf)() = Lflg ? lstat : stat;
E 16
I 16
	int (*statf)() = Lflg ? stat : lstat;
E 16
E 15
E 12
E 11
E 5
	char buf[BUFSIZ]; int cc;
	static struct afile azerofile;

	*fp = azerofile;
	fp->fflags = 0;
	fp->fnum = 0;
	fp->ftype = '-';
	if (statarg || sflg || lflg || tflg) {
D 8
		struct stat stb;
E 8
I 8
		struct stat stb, stb1;
E 8

		if ((*statf)(file, &stb) < 0) {
D 15
			fprintf(stderr, "%s not found\n", file);
			return (0);
E 15
I 15
D 16
			if (Lflg == 0 && lstat(file, &stb) < 0) {
				fprintf(stderr, "%s not found\n", file);
				return (0);
			}
E 16
I 16
D 17
			fprintf(stderr, "%s not found\n", file);
			return (0);
E 17
I 17
D 18
			if (statf == stat && lstat(file, &stb) < 0) {
E 18
I 18
			if (statf == lstat || lstat(file, &stb) < 0) {
E 18
				fprintf(stderr, "%s not found\n", file);
				return (0);
			}
E 17
E 16
E 15
		}
I 11
		fp->fblks = stb.st_blocks;
E 11
I 2
		fp->fsize = stb.st_size;
E 2
		switch (stb.st_mode & S_IFMT) {

		case S_IFDIR:
			fp->ftype = 'd'; break;
		case S_IFBLK:
			fp->ftype = 'b'; fp->fsize = stb.st_rdev; break;
		case S_IFCHR:
			fp->ftype = 'c'; fp->fsize = stb.st_rdev; break;
I 7
		case S_IFSOCK:
			fp->ftype = 's'; fp->fsize = 0; break;
E 7
		case S_IFLNK:
			fp->ftype = 'l';
			if (lflg) {
				cc = readlink(file, buf, BUFSIZ);
				if (cc >= 0) {
					buf[cc] = 0;
					fp->flinkto = savestr(buf);
				}
I 8
				break;
			}
			if (stat(file, &stb1) < 0)
				break;
			if ((stb1.st_mode & S_IFMT) == S_IFDIR) {
				stb = stb1;
				fp->ftype = 'd';
				fp->fsize = stb.st_size;
I 11
				fp->fblks = stb.st_blocks;
E 11
E 8
			}
			break;
		}
		fp->fnum = stb.st_ino;
		fp->fflags = stb.st_mode & ~S_IFMT;
		fp->fnl = stb.st_nlink;
		fp->fuid = stb.st_uid;
		fp->fgid = stb.st_gid;
D 2
		fp->fsize = stb.st_size;
E 2
		if (uflg)
			fp->fmtime = stb.st_atime;
		else if (cflg)
			fp->fmtime = stb.st_ctime;
		else
			fp->fmtime = stb.st_mtime;
D 11
		if (pnkb)
D 7
			if (fp->ftype != 'b' && fp->ftype != 'c')
E 7
I 7
			if (fp->ftype != 'b' && fp->ftype != 'c' &&
			    fp->ftype != 's')
E 7
				*pnkb += kbytes(fp->fsize);
E 11
I 11
		if (pnb)
			*pnb += stb.st_blocks;
E 11
	}
	return (fp);
}

formatf(fp0, fplast)
	struct afile *fp0, *fplast;
{
	register struct afile *fp;
D 31
	int width = 0, w, nentry = fplast - fp0;
	int i, j, columns, lines;
E 31
I 31
	register int i, j, w;
	int width = 0, nentry = fplast - fp0;
	int columns, lines;
E 31
	char *cp;

	if (fp0 == fplast)
		return;
	if (lflg || Cflg == 0)
		columns = 1;
	else {
		for (fp = fp0; fp < fplast; fp++) {
			int len = strlen(fmtentry(fp));

			if (len > width)
				width = len;
		}
		if (usetabs)
			width = (width + 8) &~ 7;
		else
			width += 2;
D 21
		columns = 80 / width;
E 21
I 21
		columns = twidth / width;
E 21
		if (columns == 0)
			columns = 1;
	}
	lines = (nentry + columns - 1) / columns;
	for (i = 0; i < lines; i++) {
		for (j = 0; j < columns; j++) {
			fp = fp0 + j * lines + i;
			cp = fmtentry(fp);
D 31
			printf("%s", cp);
E 31
I 31
			fputs(cp, stdout);
E 31
			if (fp + lines >= fplast) {
D 31
				printf("\n");
E 31
I 31
				putchar('\n');
E 31
				break;
			}
			w = strlen(cp);
			while (w < width)
				if (usetabs) {
					w = (w + 8) &~ 7;
					putchar('\t');
				} else {
					w++;
					putchar(' ');
				}
		}
	}
}

fcmp(f1, f2)
	register struct afile *f1, *f2;
{

D 15
	if (dflg == 0 && fflg == 0) {
E 15
I 15
D 16
	if (dflg == 0) {
E 16
I 16
	if (dflg == 0 && fflg == 0) {
E 16
E 15
		if ((f1->fflags&ISARG) && f1->ftype == 'd') {
			if ((f2->fflags&ISARG) == 0 || f2->ftype != 'd')
				return (1);
		} else {
			if ((f2->fflags&ISARG) && f2->ftype == 'd')
				return (-1);
		}
	}
	if (tflg) {
		if (f2->fmtime == f1->fmtime)
			return (0);
		if (f2->fmtime > f1->fmtime)
I 26
			return (rflg);
		return (-rflg);
	}
	if (Sflg) {
		if (f2->fsize == f1->fsize)
			return (0);
		if (f2->fsize > f1->fsize)
E 26
			return (rflg);
		return (-rflg);
	}
	return (rflg * strcmp(f1->fname, f2->fname));
}

char *
cat(dir, file)
	char *dir, *file;
{
	static char dfile[BUFSIZ];
I 31
	register int dlen;
E 31

D 31
	if (strlen(dir)+1+strlen(file)+1 > BUFSIZ) {
		fprintf(stderr, "ls: filename too long\n");
E 31
I 31
	if ((dlen = strlen(dir))+1+strlen(file)+1 > BUFSIZ) {
		fputs("ls: filename too long\n", stderr);
E 31
		exit(1);
	}
D 31
	if (!strcmp(dir, "") || !strcmp(dir, ".")) {
		(void) strcpy(dfile, file);
		return (dfile);
	}
E 31
I 31
	if (!dir[0] || dir[0] == '.' && !dir[1])
		return(strcpy(dfile, file));
E 31
	(void) strcpy(dfile, dir);
D 31
	if (dir[strlen(dir) - 1] != '/' && *file != '/')
		(void) strcat(dfile, "/");
	(void) strcat(dfile, file);
E 31
I 31
	if (dir[dlen - 1] != '/' && *file != '/')
		dfile[dlen++] = '/';
	(void) strcpy(dfile + dlen, file);
E 31
	return (dfile);
}

char *
savestr(str)
	char *str;
{
	char *cp = malloc(strlen(str) + 1);

	if (cp == NULL) {
D 31
		fprintf(stderr, "ls: out of memory\n");
E 31
I 31
		fputs("ls: out of memory\n", stderr);
E 31
		exit(1);
	}
D 31
	(void) strcpy(cp, str);
	return (cp);
E 31
I 31
	return(strcpy(cp, str));
E 31
}

char	*fmtinum(), *fmtsize(), *fmtlstuff(), *fmtmode();

char *
fmtentry(fp)
	register struct afile *fp;
{
	static char fmtres[BUFSIZ];
	register char *cp, *dp;

D 4
	(void) sprintf(fmtres, "%s%s%s%s",
E 4
I 4
	(void) sprintf(fmtres, "%s%s%s",
E 4
	    iflg ? fmtinum(fp) : "",
	    sflg ? fmtsize(fp) : "",
	    lflg ? fmtlstuff(fp) : "");
	dp = &fmtres[strlen(fmtres)];
	for (cp = fp->fname; *cp; cp++)
		if (qflg && (*cp < ' ' || *cp >= 0177))
			*dp++ = '?';
		else
			*dp++ = *cp;
	if (Fflg) {
		if (fp->ftype == 'd')
			*dp++ = '/';
I 3
		else if (fp->ftype == 'l')
			*dp++ = '@';
I 7
		else if (fp->ftype == 's')
			*dp++ = '=';
E 7
E 3
		else if (fp->fflags & 0111)
			*dp++ = '*';
	}
	if (lflg && fp->flinkto) {
		(void) strcpy(dp, " -> "); dp += 4;
		for (cp = fp->flinkto; *cp; cp++)
			if (qflg && (*cp < ' ' || *cp >= 0177))
				*dp++ = '?';
			else
				*dp++ = *cp;
	}
	*dp++ = 0;
	return (fmtres);
}

char *
fmtinum(p)
	register struct afile *p;
{
	static char inumbuf[8];

D 27
	(void) sprintf(inumbuf, "%5d ", p->fnum);
E 27
I 27
D 31
	(void) sprintf(inumbuf, "%6d ", p->fnum);
E 31
I 31
	(void) sprintf(inumbuf, "%6ld ", p->fnum);
E 31
E 27
	return (inumbuf);
}

char *
fmtsize(p)
	register struct afile *p;
{
	static char sizebuf[32];

D 11
	switch (p->ftype) {

	case 'b':
	case 'c':
I 7
	case 's':
E 7
		(void) sprintf(sizebuf, "%4ld ", 0);
		break;

	default:
		(void) sprintf(sizebuf, "%4ld ", kbytes(p->fsize));
		break;
	}
E 11
I 11
	(void) sprintf(sizebuf, "%4ld ", kbytes(dbtob(p->fblks)));
E 11
	return (sizebuf);
}

char *
fmtlstuff(p)
	register struct afile *p;
{
	static char lstuffbuf[256];
	char gname[32], uname[32], fsize[32], ftime[32];
	register char *lp = lstuffbuf;

	/* type mode uname gname fsize ftime */
/* get uname */
	{ char *cp = getname(p->fuid);
	  if (cp)
		(void) sprintf(uname, "%-9.9s", cp);
	  else
D 31
		(void) sprintf(uname, "%-9d", p->fuid);
E 31
I 31
		(void) sprintf(uname, "%-9u", p->fuid);
E 31
	}
/* get gname */
	if (gflg) {
	  char *cp = getgroup(p->fgid);
	  if (cp)
		(void) sprintf(gname, "%-9.9s", cp);
	  else
D 31
		(void) sprintf(gname, "%-9d", p->fgid);
E 31
I 31
		(void) sprintf(gname, "%-9u", p->fgid);
E 31
	}
/* get fsize */
	if (p->ftype == 'b' || p->ftype == 'c')
		(void) sprintf(fsize, "%3d,%4d",
		    major(p->fsize), minor(p->fsize));
I 7
	else if (p->ftype == 's')
D 31
		(void) sprintf(fsize, "%8ld", 0);
E 31
I 31
		(void) sprintf(fsize, "%8ld", 0L);
E 31
E 7
	else
		(void) sprintf(fsize, "%8ld", p->fsize);
/* get ftime */
	{ char *cp = ctime(&p->fmtime);
	  if ((p->fmtime < sixmonthsago) || (p->fmtime > now))
		(void) sprintf(ftime, " %-7.7s %-4.4s ", cp+4, cp+20);
	  else
		(void) sprintf(ftime, " %-12.12s ", cp+4);
	}
/* splat */
	*lp++ = p->ftype;
	lp = fmtmode(lp, p->fflags);
	(void) sprintf(lp, "%3d %s%s%s%s",
	    p->fnl, uname, gflg ? gname : "", fsize, ftime);
	return (lstuffbuf);
}

int	m1[] = { 1, S_IREAD>>0, 'r', '-' };
int	m2[] = { 1, S_IWRITE>>0, 'w', '-' };
D 32
int	m3[] = { 2, S_ISUID, 's', S_IEXEC>>0, 'x', '-' };
E 32
I 32
int	m3[] = { 3, S_ISUID|(S_IEXEC>>0), 's', S_ISUID, 'S', S_IEXEC>>0, 'x', '-' };
E 32
int	m4[] = { 1, S_IREAD>>3, 'r', '-' };
int	m5[] = { 1, S_IWRITE>>3, 'w', '-' };
D 32
int	m6[] = { 2, S_ISGID, 's', S_IEXEC>>3, 'x', '-' };
E 32
I 32
int	m6[] = { 3, S_ISGID|(S_IEXEC>>3), 's', S_ISGID, 'S', S_IEXEC>>3, 'x', '-' };
E 32
int	m7[] = { 1, S_IREAD>>6, 'r', '-' };
int	m8[] = { 1, S_IWRITE>>6, 'w', '-' };
D 32
int	m9[] = { 2, S_ISVTX, 't', S_IEXEC>>6, 'x', '-' };
E 32
I 32
int	m9[] = { 3, S_ISVTX|(S_IEXEC>>6), 't', S_ISVTX, 'T', S_IEXEC>>6, 'x', '-' };
E 32

int	*m[] = { m1, m2, m3, m4, m5, m6, m7, m8, m9};

char *
fmtmode(lp, flags)
	char *lp;
D 31
	int flags;
E 31
I 31
	register int flags;
E 31
{
	int **mp;

	for (mp = &m[0]; mp < &m[sizeof(m)/sizeof(m[0])]; ) {
		register int *pairp = *mp++;
		register int n = *pairp++;

D 32
		while (--n >= 0 && (flags&*pairp++) == 0)
			pairp++;
		*lp++ = *pairp;
E 32
I 32
		while (--n >= 0 && (flags&*pairp) != *pairp)
			pairp += 2;
		*lp++ = pairp[n>=0];
E 32
	}
	return (lp);
}

/* rest should be done with nameserver or database */

#include <pwd.h>
#include <grp.h>
#include <utmp.h>

struct	utmp utmp;
I 19
#define	NMAX	(sizeof (utmp.ut_name))
#define SCPYN(a, b)	strncpy(a, b, NMAX)
E 19

D 23
#define NUID	2048
E 23
I 23
D 31
#define NUID	64	/* power of 2 */
#define UIDMASK	0x3f
E 23
#define NGID	300
E 31
I 31
#define NCACHE	64		/* power of 2 */
#define CAMASK	NCACHE - 1
E 31
D 19
#define	NMAX	(sizeof (utmp.ut_name))
E 19

D 23
char	names[NUID][NMAX+1];
E 23
I 23
D 31
struct ncache {
	int	uid;
	char	name[NMAX+1];
} nc[NUID];
E 23
D 10
char	groups[NGID][NMAX+1];
E 10
I 9
char	outrangename[NMAX+1];
int	outrangeuid = -1;
I 10
char	groups[NGID][NMAX+1];
char	outrangegroup[NMAX+1];
int	outrangegid = -1;
E 10
E 9

E 31
char *
getname(uid)
I 31
	uid_t uid;
E 31
{
D 31
	register struct passwd *pw;
D 23
	static init;
E 23
	struct passwd *getpwent();
E 31
I 23
	extern int _pw_stayopen;
D 31
	register int cp;
E 31
I 31
	static struct ncache {
		uid_t	uid;
		char	name[NMAX+1];
	} c_uid[NCACHE];
	register struct passwd *pw;
	register struct ncache *cp;
E 31
E 23

D 23
	if (uid >= 0 && uid < NUID && names[uid][0])
		return (&names[uid][0]);
D 9
	if (init == 2)
E 9
I 9
	if (uid >= 0 && uid == outrangeuid)
		return (outrangename);
I 20
rescan:
E 20
	if (init == 2) {
		if (uid < NUID)
			return (0);
		setpwent();
		while (pw = getpwent()) {
			if (pw->pw_uid != uid)
				continue;
			outrangeuid = pw->pw_uid;
D 19
			strncpy(outrangename, pw->pw_name, NUID);
E 19
I 19
			SCPYN(outrangename, pw->pw_name);
E 19
			endpwent();
			return (outrangename);
		}
		endpwent();
E 23
I 23
	_pw_stayopen = 1;
D 31
	cp = uid & UIDMASK;
	if (uid >= 0 && nc[cp].uid == uid && nc[cp].name[0])
		return (nc[cp].name);
	pw = getpwuid(uid);
	if (!pw)
E 23
E 9
		return (0);
I 9
D 23
	}
E 9
	if (init == 0)
		setpwent(), init = 1;
	while (pw = getpwent()) {
D 9
		if (pw->pw_uid < 0 || pw->pw_uid >= NUID)
E 9
I 9
		if (pw->pw_uid < 0 || pw->pw_uid >= NUID) {
			if (pw->pw_uid == uid) {
				outrangeuid = pw->pw_uid;
D 19
				strncpy(outrangename, pw->pw_name, NUID);
E 19
I 19
				SCPYN(outrangename, pw->pw_name);
E 19
				return (outrangename);
			}
E 9
			continue;
I 9
		}
E 9
		if (names[pw->pw_uid][0])
			continue;
D 19
		strncpy(names[pw->pw_uid], pw->pw_name, NMAX);
E 19
I 19
		SCPYN(names[pw->pw_uid], pw->pw_name);
E 19
D 20
		if (pw->pw_uid == uid) {
E 20
I 20
		if (pw->pw_uid == uid)
E 20
			return (&names[uid][0]);
D 20
		}
E 20
	}
	init = 2;
D 20
	endpwent();
	return (0);
E 20
I 20
	goto rescan;
E 23
I 23
	nc[cp].uid = uid;
	SCPYN(nc[cp].name, pw->pw_name);
	return (nc[cp].name);
E 31
I 31
	cp = c_uid + (uid & CAMASK);
	if (cp->uid == uid && *cp->name)
		return(cp->name);
	if (!(pw = getpwuid(uid)))
		return((char *)0);
	cp->uid = uid;
	SCPYN(cp->name, pw->pw_name);
	return(cp->name);
E 31
E 23
E 20
}

char *
getgroup(gid)
I 31
	gid_t gid;
E 31
{
I 31
	static struct ncache {
		gid_t	gid;
		char	name[NMAX+1];
	} c_gid[NCACHE];
E 31
	register struct group *gr;
D 31
	static init;
	struct group *getgrent();
E 31
I 31
	register struct ncache *cp;
E 31

D 31
	if (gid >= 0 && gid < NGID && groups[gid][0])
		return (&groups[gid][0]);
D 10
	if (init == 2)
E 10
I 10
	if (gid >= 0 && gid == outrangegid)
		return (outrangegroup);
I 20
rescan:
E 20
	if (init == 2) {
		if (gid < NGID)
			return (0);
		setgrent();
		while (gr = getgrent()) {
			if (gr->gr_gid != gid)
				continue;
			outrangegid = gr->gr_gid;
D 19
			strncpy(outrangegroup, gr->gr_name, NGID);
E 19
I 19
			SCPYN(outrangegroup, gr->gr_name);
E 19
			endgrent();
			return (outrangegroup);
		}
		endgrent();
E 10
		return (0);
I 10
	}
E 10
	if (init == 0)
		setgrent(), init = 1;
	while (gr = getgrent()) {
D 10
		if (gr->gr_gid < 0 || gr->gr_gid >= NGID)
E 10
I 10
		if (gr->gr_gid < 0 || gr->gr_gid >= NGID) {
			if (gr->gr_gid == gid) {
				outrangegid = gr->gr_gid;
D 19
				strncpy(outrangegroup, gr->gr_name, NGID);
E 19
I 19
				SCPYN(outrangegroup, gr->gr_name);
E 19
				return (outrangegroup);
			}
E 10
			continue;
I 10
		}
E 10
		if (groups[gr->gr_gid][0])
			continue;
D 19
		strncpy(groups[gr->gr_gid], gr->gr_name, NMAX);
E 19
I 19
		SCPYN(groups[gr->gr_gid], gr->gr_name);
E 19
D 20
		if (gr->gr_gid == gid) {
E 20
I 20
		if (gr->gr_gid == gid)
E 20
			return (&groups[gid][0]);
D 20
		}
E 20
	}
	init = 2;
D 20
	endgrent();
	return (0);
E 20
I 20
	goto rescan;
E 31
I 31
	cp = c_gid + (gid & CAMASK);
	if (cp->gid == gid && *cp->name)
		return(cp->name);
	if (!(gr = getgrgid(gid)))
		return((char *)0);
	cp->gid = gid;
	SCPYN(cp->name, gr->gr_name);
	return(cp->name);
E 31
E 20
}
E 1
