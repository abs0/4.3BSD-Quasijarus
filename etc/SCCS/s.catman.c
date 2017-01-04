h47404
s 00001/00001/00258
d D 5.8 87/04/06 10:00:53 bostic 16 15
c sprintf format/argument count mismatch
e
s 00010/00011/00249
d D 5.7 86/05/27 19:01:24 mckusick 15 14
c replace hard links with symlinks so that out of date pages 
c can be easily detected (from ks@purdue)
e
s 00002/00002/00258
d D 5.6 86/02/24 05:55:52 lepreau 14 13
c back to world-writable dirs and cat? files.  Hwoever, if a dirs
c exists we don't change its mode.
e
s 00085/00038/00175
d D 5.5 86/01/13 17:02:47 donn 13 12
c Add 'manpath' feature.  Also some delinting.  (From Utah.)
e
s 00001/00001/00212
d D 5.4 85/10/15 20:14:51 mckusick 12 11
c really only unlink regular files (from I stay up all night reading code, Torek)
e
s 00004/00004/00209
d D 5.3 85/08/09 13:53:49 mckusick 11 10
c cat? is not world writeable
e
s 00035/00005/00178
d D 5.2 85/08/07 17:30:41 mckusick 10 9
c link together .so'ed man pages in case man src is not present (from ks@purdue)
e
s 00014/00002/00169
d D 5.1 85/06/06 11:01:10 dist 9 8
c Add copyright
e
s 00003/00006/00168
d D 4.8 85/04/07 01:55:31 sam 8 7
c fix arg processing (boy am I hot tonight)
e
s 00038/00016/00136
d D 4.7 85/04/07 01:23:55 sam 7 6
c support alternate manual directories; check chdir
e
s 00002/00002/00150
d D 4.6 84/02/23 11:20:02 ralph 6 5
c check sections `n' and `l' too.
e
s 00003/00003/00149
d D 4.5 83/07/01 03:11:56 sam 5 4
c include fixes
e
s 00013/00002/00139
d D 4.4 83/03/06 23:17:33 sam 4 3
c mkdir fixes
e
s 00041/00031/00100
d D 4.3 83/02/26 14:14:30 sam 3 2
c check for extra chars done wrong
e
s 00019/00016/00112
d D 4.2 82/05/12 16:34:52 edward 2 1
c Changed to use opendir, etc
e
s 00128/00000/00000
d D 4.1 80/10/01 17:25:12 bill 1 0
c date and time created 80/10/01 17:25:12 by bill
e
u
U
t
T
I 9
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 9
I 3
#ifndef lint
E 3
I 1
D 9
static char *sccsid = "%W% (Berkeley) %G%";
D 3
# include	<stdio.h>
D 2
# include	<sys/types.h>
# include	<dir.h>
E 2
I 2
# include	<sys/param.h>
E 2
# include	<stat.h>
I 2
# include	<dir.h>
E 2
# include	<ctype.h>
E 3
I 3
#endif
E 9
I 9
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 9
E 3

D 3
# define	reg	register
# define	bool	char
E 3
I 3
/*
 * catman: update cat'able versions of manual pages
 *  (whatis database also)
 */
#include <stdio.h>
#include <sys/types.h>
D 5
#include <stat.h>
#include <time.h>
#include <dir.h>
E 5
I 5
#include <sys/stat.h>
I 13
#include <sys/file.h>
E 13
#include <sys/time.h>
#include <sys/dir.h>
E 5
#include <ctype.h>
E 3

D 3
# define	SYSTEM(str)	(pflag ? printf("%s\n", str) : system(str))
E 3
I 3
D 13
#define	SYSTEM(str)	(pflag ? printf("%s\n", str) : system(str))
E 3

E 13
D 3
char		buf[BUFSIZ],
		pflag = 0,
		nflag = 0,
		wflag = 0;
E 3
I 3
char	buf[BUFSIZ];
char	pflag;
char	nflag;
char	wflag;
char	man[MAXNAMLEN+6] = "manx/";
I 13
int	exstat = 0;
E 13
char	cat[MAXNAMLEN+6] = "catx/";
I 10
D 15
char	lncat[MAXNAMLEN+6] = "catx/";
E 15
I 15
char	lncat[MAXNAMLEN+9] = "../catx/";
E 15
E 10
I 7
D 13
char	*mandir = "/usr/man";
E 7
char	*rindex();
E 13
I 13
char	*manpath = "/usr/man";
char	*sections = "12345678ln";
char	*makewhatis = "/usr/lib/makewhatis";
char	*index(), *rindex();
char	*strcpy();
char	*getenv();
E 13
E 3

I 2
D 3
char		*rindex();

E 3
E 2
main(ac, av)
D 3
int	ac;
char	*av[]; {
E 3
I 3
	int ac;
	char *av[];
{
D 13
	register char *msp, *csp, *sp;
	register char *sections;
	register int exstat = 0;
	register char changed = 0;
E 13
I 13
	char *mp, *nextp;
E 13
E 3

I 13
	if ((mp = getenv("MANPATH")) != NULL)
		manpath = mp;

E 13
D 2
	reg char	*tsp, *msp, *csp, *man, *cat, *sp;
	reg FILE	*mdir, *inf;
E 2
I 2
D 3
	reg char	*tsp, *msp, *csp, *sp;
	reg FILE	*inf;
	reg DIR		*mdir;
E 2
	reg long	time;
	reg char	*sections;
	reg int		exstat = 0;
	reg bool	changed = 0;
D 2
	static struct dir	dir;
	static struct stat	sbuf;
E 2
I 2
	static char	man[MAXNAMLEN+6] = "manx/";
	static char	cat[MAXNAMLEN+6] = "catx/";
	reg struct direct *dir;
	struct stat	sbuf;
E 2

E 3
D 7
	while (ac > 1) {
		av++;
		if (strcmp(*av, "-p") == 0)
E 7
I 7
	ac--, av++;
D 8
	while (ac > 1 && av[0][0] == '-') {
E 8
I 8
	while (ac > 0 && av[0][0] == '-') {
E 8
		switch (av[0][1]) {

		case 'p':
E 7
			pflag++;
D 7
		else if (strcmp(*av, "-n") == 0)
E 7
I 7
			break;

		case 'n':
E 7
			nflag++;
D 7
		else if (strcmp(*av, "-w") == 0)
E 7
I 7
			break;

		case 'w':
E 7
			wflag++;
D 7
		else if (*av[0] == '-')
			goto usage;
		else
E 7
			break;
D 7
		ac--;
E 7
I 7

		case 'M':
		case 'P':
			if (ac < 1) {
D 13
				fprintf(stderr, "%s: missing directory\n",
E 13
I 13
				fprintf(stderr, "%s: missing path\n",
E 13
				    av[0]);
				exit(1);
			}
			ac--, av++;
D 13
			mandir = *av;
E 13
I 13
			manpath = *av;
E 13
			break;

		default:
			goto usage;
		}
		ac--, av++;
E 7
	}
D 8
	if (ac == 2)
		sections = *av;
	else if (ac < 2)
D 6
		sections = "12345678";
E 6
I 6
		sections = "12345678ln";
E 6
	else {
E 8
I 8
	if (ac > 1) {
E 8
usage:
D 7
		printf("usage: catman [ -p ] [ -n ] [ -w ] [ sections ]\n");
E 7
I 7
		printf("usage: catman [ -p ] [ -n ] [ -w ] [ -M path ] [ sections ]\n");
E 7
		exit(-1);
	}
I 8
D 13
	sections = (ac == 1) ? *av : "12345678ln";
E 13
I 13
	if (ac == 1)
		sections = *av;
	for (mp = manpath; mp && ((nextp = index(mp, ':')), 1); mp = nextp) {
		if (nextp)
			*nextp++ = '\0';
		doit(mp);
	}
	exit(exstat);
}

doit(mandir)
	char *mandir;
{
	register char *msp, *csp, *sp;
	int changed = 0;
	int status;

E 13
E 8
	if (wflag)
		goto whatis;
D 7
	chdir("/usr/man");
E 7
I 7
	if (chdir(mandir) < 0) {
D 13
		fprintf(stderr, "catman: "), perror(mandir);
		exit(1);
E 13
I 13
		sprintf(buf, "catman: %s", mandir);
		perror(buf);
		/* exstat = 1; */
		return;
E 13
	}
I 13
	if (pflag)
		printf("cd %s\n", mandir);
E 13
E 7
D 2
	man = "manx/xxxxxxxxxxxxxx";
	cat = "catx/xxxxxxxxxxxxxx";
E 2
	msp = &man[5];
	csp = &cat[5];
D 10
	umask(0);
E 10
I 10
D 11
	umask(022);
E 11
I 11
D 13
	umask(02);
E 13
I 13
D 14
	(void) umask(02);
E 14
I 14
	(void) umask(0);
E 14
E 13
E 11
E 10
	for (sp = sections; *sp; sp++) {
I 3
		register DIR *mdir;
		register struct direct *dir;
		struct stat sbuf;

E 3
		man[3] = cat[3] = *sp;
		*msp = *csp = '\0';
D 2
		if ((mdir = fopen(man, "r")) == NULL) {
			fprintf(stderr, "fopen:");
E 2
I 2
		if ((mdir = opendir(man)) == NULL) {
D 13
			fprintf(stderr, "opendir:");
E 2
			perror(man);
			exstat = 1;
E 13
I 13
			sprintf(buf, "catman: opendir: %s", man);
			perror(buf);
			/* exstat = 1; */
E 13
			continue;
		}
		if (stat(cat, &sbuf) < 0) {
D 4
			sprintf(buf, "mkdir %s", cat);
			SYSTEM(buf);
E 4
I 4
D 13
			char buf[MAXNAMLEN + 6], *cp, *rindex();
E 13
I 13
			register char *cp;
E 13

D 13
			strcpy(buf, cat);
E 13
I 13
			(void) strcpy(buf, cat);
E 13
			cp = rindex(buf, '/');
			if (cp && cp[1] == '\0')
				*cp = '\0';
			if (pflag)
				printf("mkdir %s\n", buf);
D 11
			else if (mkdir(buf, 0777) < 0) {
E 11
I 11
D 14
			else if (mkdir(buf, 0775) < 0) {
E 14
I 14
			else if (mkdir(buf, 0777) < 0) {
E 14
E 11
				sprintf(buf, "catman: mkdir: %s", cat);
				perror(buf);
I 13
				exstat = 1;
E 13
				continue;
			}
E 4
D 13
			stat(cat, &sbuf);
E 13
I 13
			(void) stat(cat, &sbuf);
E 13
		}
D 11
		if ((sbuf.st_mode & 0777) != 0777)
			chmod(cat, 0777);
E 11
I 11
D 13
		if ((sbuf.st_mode & 0777) != 0775)
			chmod(cat, 0775);
E 13
I 13
		if (access(cat, R_OK|W_OK|X_OK) == -1) {
			sprintf(buf, "catman: %s", cat);
			perror(buf);
			exstat = 1;
			continue;
		}
		if ((sbuf.st_mode & S_IFMT) != S_IFDIR) {
			fprintf(stderr, "catman: %s: Not a directory\n", cat);
			exstat = 1;
			continue;
		}
E 13
E 11
D 2
		while (fread((char *) &dir, sizeof dir, 1, mdir) > 0) {
			if (dir.d_ino == 0 || dir.d_name[0] == '.')
E 2
I 2
		while ((dir = readdir(mdir)) != NULL) {
I 3
			time_t time;
D 13
			char *tsp;
E 13
I 13
			register char *tsp;
E 13
			FILE *inf;
I 10
			int  makelink;
E 10

E 3
			if (dir->d_ino == 0 || dir->d_name[0] == '.')
E 2
				continue;
			/*
D 3
			 * make sure this is a man file, i.e., that it
E 3
I 3
			 * Make sure this is a man file, i.e., that it
E 3
			 * ends in .[0-9] or .[0-9][a-z]
			 */
D 2
			tsp = rindex(dir.d_name, '.');
E 2
I 2
			tsp = rindex(dir->d_name, '.');
E 2
			if (tsp == NULL)
				continue;
D 3
			if (!isdigit(*++tsp) || ((*++tsp && !isalpha(*tsp)) || *++tsp))
E 3
I 3
D 6
			if (!isdigit(*++tsp))
E 6
I 6
			if (!isdigit(*++tsp) && *tsp != *sp)
E 6
E 3
				continue;
D 3

E 3
I 3
			if (*++tsp && !isalpha(*tsp))
				continue;
			if (*tsp && *++tsp)
				continue;
E 3
D 2
			strncpy(msp, dir.d_name, DIRSIZ);
E 2
I 2
D 13
			strcpy(msp, dir->d_name);
E 13
I 13
			(void) strcpy(msp, dir->d_name);
E 13
E 2
			if ((inf = fopen(man, "r")) == NULL) {
D 13
				perror(man);
E 13
I 13
D 16
				sprintf(buf, "catman: %s");
E 16
I 16
				sprintf(buf, "catman: %s", man);
E 16
				perror(buf);
E 13
				exstat = 1;
				continue;
			}
I 10
			makelink = 0;
E 10
			if (getc(inf) == '.' && getc(inf) == 's'
			    && getc(inf) == 'o') {
D 10
				fclose(inf);
				continue;
E 10
I 10
				if (getc(inf) != ' ' ||
D 15
				    fgets(lncat, sizeof(lncat), inf)==NULL) {
E 15
I 15
				    fgets(lncat+3, sizeof(lncat)-3, inf)==NULL) {
E 15
					fclose(inf);
					continue;
				}
				if (lncat[strlen(lncat)-1] == '\n')
					lncat[strlen(lncat)-1] = '\0';
D 15
				if (strncmp(lncat, "man", 3) != 0) {
E 15
I 15
				if (strncmp(lncat+3, "man", 3) != 0) {
E 15
					fclose(inf);
					continue;
				}
D 15
				lncat[0] = 'c';
				lncat[1] = 'a';
				lncat[2] = 't';
E 15
I 15
				bcopy("../cat", lncat, sizeof("../cat")-1);
E 15
				makelink = 1;
E 10
			}
			fclose(inf);
D 2
			strncpy(csp, dir.d_name, DIRSIZ);
E 2
I 2
D 13
			strcpy(csp, dir->d_name);
E 13
I 13
			(void) strcpy(csp, dir->d_name);
E 13
E 2
			if (stat(cat, &sbuf) >= 0) {
				time = sbuf.st_mtime;
D 13
				stat(man, &sbuf);
E 13
I 13
				(void) stat(man, &sbuf);
E 13
				if (time >= sbuf.st_mtime)
					continue;
D 13
				unlink(cat);
E 13
I 13
				(void) unlink(cat);
E 13
			}
D 10
			sprintf(buf, "nroff -man %s > %s", man, cat);
			SYSTEM(buf);
E 10
I 10
			if (makelink) {
				/*
				 * Don't unlink a directory by accident.
				 */
D 15
				if (stat(lncat, &sbuf) >= 0 &&
D 12
				    ((sbuf.st_mode&S_IFMT)==S_IFCHR))
E 12
I 12
				    ((sbuf.st_mode&S_IFMT)==S_IFREG))
E 15
I 15
				if (stat(lncat+3, &sbuf) >= 0 &&
				    (((sbuf.st_mode&S_IFMT)==S_IFREG) ||
				     ((sbuf.st_mode&S_IFMT)==S_IFLNK)))
E 15
E 12
D 13
					unlink(cat);
E 13
I 13
					(void) unlink(cat);
E 13
				if (pflag)
D 15
					printf("ln %s %s\n", lncat, cat);
E 15
I 15
					printf("ln -s %s %s\n", lncat, cat);
E 15
				else
D 13
					link(lncat, cat);
E 13
I 13
D 15
					if (link(lncat, cat) == -1) {
						sprintf(buf, "catman: link: %s", cat);
E 15
I 15
					if (symlink(lncat, cat) == -1) {
						sprintf(buf, "catman: symlink: %s", cat);
E 15
						perror(buf);
						exstat = 1;
						continue;
					}
E 13
			}
			else {
				sprintf(buf, "nroff -man %s > %s", man, cat);
D 13
				SYSTEM(buf);
E 13
I 13
				if (pflag)
					printf("%s\n", buf);
				else if ((status = system(buf)) != 0) {
					fprintf(stderr, "catman: nroff: %s: exit status %d: Owooooo!\n", cat, status);
					exstat = 1;
					continue;
				}
E 13
			}
E 10
			changed = 1;
		}
D 2
		fclose(mdir);
E 2
I 2
		closedir(mdir);
E 2
	}
	if (changed && !nflag) {
whatis:
D 7
		if (pflag)
			printf("/bin/sh /usr/lib/makewhatis\n");
		else {
			execl("/bin/sh", "/bin/sh", "/usr/lib/makewhatis", 0);
E 7
I 7
D 13
		if (!pflag) {
			execl("/bin/sh", "/bin/sh",
			    "/usr/lib/makewhatis", mandir, 0);
E 7
			perror("/bin/sh /usr/lib/makewhatis");
E 13
I 13
		sprintf(buf, "%s %s", makewhatis, mandir);
		if (pflag)
			printf("%s\n", buf);
		else if ((status = system(buf)) != 0) {
			fprintf(stderr, "catman: %s: exit status %d\n",
			    buf, status);
E 13
			exstat = 1;
D 7
		}
E 7
I 7
D 13
		} else
			printf("/bin/sh /usr/lib/makewhatis %s\n", mandir);
E 13
I 13
		}
E 13
E 7
	}
D 13
	exit(exstat);
E 13
I 13
	return;
E 13
}
E 1
