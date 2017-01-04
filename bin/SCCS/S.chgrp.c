h48523
s 00001/00001/00203
d D 5.9 87/12/21 12:30:10 bostic 18 17
c make ANSI C compatible; besides, structs don't fit in registers...
e
s 00003/00003/00201
d D 5.8 86/10/28 20:36:50 mckusick 17 16
c one uid and gid persists throughout a recursive descent
e
s 00002/00002/00202
d D 5.7 86/06/04 11:04:40 mckusick 16 15
c fix those typos!
e
s 00002/00002/00202
d D 5.6 86/05/22 11:18:49 mckusick 15 14
c bug in checking type of file
e
s 00022/00016/00182
d D 5.5 86/05/22 09:57:32 mckusick 14 12
c do not follow symbolic links; do not try to change owner
e
s 00005/00005/00193
d R 5.5 86/05/22 09:30:16 mckusick 13 12
c do not follow symbolic links; do not try to change owner
e
s 00001/00001/00197
d D 5.4 86/02/20 11:30:43 karels 12 11
c typo
e
s 00006/00001/00192
d D 5.3 86/01/21 19:42:29 karels 11 10
c let's not give away too much
e
s 00100/00068/00093
d D 5.2 85/08/31 17:44:59 sam 10 9
c cleanup
e
s 00008/00002/00153
d D 5.1 85/04/30 14:50:18 dist 9 8
c Add copyright
e
s 00072/00017/00083
d D 4.8 85/03/20 14:39:34 mckusick 8 7
c add -R flag for recursive descent (from layer)
e
s 00001/00001/00099
d D 4.7 83/11/23 15:23:13 mckusick 7 6
c chgrp (using chown) does not follow symbolic links, so must use lstat to get uid
e
s 00001/00001/00099
d D 4.6 83/05/10 15:50:23 mckusick 6 5
c finish adding -f option
e
s 00010/00001/00090
d D 4.5 83/04/28 11:14:02 ralph 5 4
c added -f option like the -f option for chown.
e
s 00001/00001/00090
d D 4.4 83/01/20 16:14:13 sam 4 3
c oops
e
s 00051/00037/00040
d D 4.3 82/03/31 11:29:46 root 3 2
c fixes for jkf
e
s 00030/00007/00047
d D 4.2 82/03/05 03:16:00 wnj 2 1
c new with multiple groups
e
s 00054/00000/00000
d D 4.1 80/10/01 17:25:28 bill 1 0
c date and time created 80/10/01 17:25:28 by bill
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
D 2
static char *sccsid = "%W% (Berkeley) %G%";
E 2
I 2
D 9
static	char *sccsid = "%W% %E%";
I 3
#endif
E 9
I 9
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 9

E 3
E 2
/*
D 8
 * chgrp gid file ...
E 8
I 8
 * chgrp -fR gid file ...
E 8
 */

#include <stdio.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <grp.h>
I 2
#include <pwd.h>
I 8
#include <sys/dir.h>
E 8
E 2

D 2
struct	group	*gr,*getgrnam();
E 2
I 2
D 3
struct	group	*gr, *getgrnam(), *getgrgid();
struct passwd *getpwuid(), *pwd;
E 2
struct	stat	stbuf;
E 3
I 3
struct	group *gr, *getgrnam(), *getgrgid();
struct	passwd *getpwuid(), *pwd;
struct	stat stbuf;
E 3
D 2
int	gid;
E 2
I 2
int	gid, uid;
E 2
int	status;
I 5
D 8
int	fflag;
E 8
I 8
int	fflag, rflag;
E 8
E 5
I 2
D 3
char	ingroup;
E 3
I 3
/* VARARGS */
int	fprintf();
E 3
E 2

main(argc, argv)
D 3
char *argv[];
E 3
I 3
	int argc;
	char *argv[];
E 3
{
D 2
	register c;
E 2
I 2
	register c, i;
I 8
D 10
	register char *flags;
E 10
I 10
	register char *cp;
E 10
E 8
D 3
	char	*getlogin(), *name;
E 3
E 2

D 3
	if(argc < 3) {
E 3
I 3
	argc--, argv++;
I 5
D 8
	if (argc > 0 && strcmp(argv[0], "-f") == 0) {
		fflag++;
E 8
I 8
D 10
	if (*argv[0] == '-') {
		for (flags = argv[0]; *flags; ++flags)
			switch (*flags) {
			  case '-':			break;
			  case 'f': 	fflag++;	break;
			  case 'R':	rflag++;	break;
			  default:
				printf("chgrp: unknown option: %s\n", *flags);
				exit(255);
			}
E 10
I 10
	while (argc > 0 && argv[0][0] == '-') {
		for (cp = &argv[0][1]; *cp; cp++) switch (*cp) {

		case 'f':
			fflag++;
			break;

		case 'R':
			rflag++;
			break;

		default:
D 12
			fatal(255, "unknown option: %s", *cp);
E 12
I 12
			fatal(255, "unknown option: %c", *cp);
E 12
			/*NOTREACHED*/
		}
E 10
E 8
		argv++, argc--;
	}
E 5
	if (argc < 2) {
E 3
D 5
		printf("usage: chgrp gid file ...\n");
E 5
I 5
D 8
		printf("usage: chgrp [-f] gid file ...\n");
E 5
D 3
		exit(4);
E 3
I 3
		exit(2);
E 8
I 8
		fprintf(stderr, "usage: chgrp [-fR] gid file ...\n");
		exit(255);
E 8
E 3
	}
I 2
	uid = getuid();
E 2
D 3
	if(isnumber(argv[1])) {
E 3
I 3
	if (isnumber(argv[0])) {
E 3
D 4
		gid = atoi(argv[1]);
E 4
I 4
		gid = atoi(argv[0]);
E 4
I 2
D 3
		if (uid && (gr=getgrgid(gid)) == NULL) {
			printf("unknown group: %s\n",argv[1]);
			exit(4);
E 3
I 3
		gr = getgrgid(gid);
D 10
		if (uid && gr == NULL) {
D 8
			printf("%s: unknown group\n", argv[0]);
			exit(2);
E 8
I 8
			fprintf(stderr, "%s: unknown group\n", argv[0]);
			exit(255);
E 8
E 3
		}
E 10
I 10
		if (uid && gr == NULL)
			fatal(255, "%s: unknown group", argv[0]);
E 10
E 2
	} else {
D 3
		if((gr=getgrnam(argv[1])) == NULL) {
			printf("unknown group: %s\n",argv[1]);
			exit(4);
E 3
I 3
		gr = getgrnam(argv[0]);
D 10
		if (gr == NULL) {
D 8
			printf("%s: unknown group\n", argv[0]);
			exit(2);
E 8
I 8
			fprintf(stderr, "%s: unknown group\n", argv[0]);
			exit(255);
E 8
E 3
		}
E 10
I 10
		if (gr == NULL)
			fatal(255, "%s: unknown group", argv[0]);
E 10
		gid = gr->gr_gid;
	}
I 2
D 3
	if (!(name = getlogin())) {
		pwd = getpwuid(uid);
		name = pwd->pw_name;
E 3
I 3
	pwd = getpwuid(uid);
D 10
	if (pwd == NULL) {
		fprintf(stderr, "Who are you?\n");
D 8
		exit(2);
E 8
I 8
		exit(255);
E 8
E 3
	}
E 10
I 10
	if (pwd == NULL)
		fatal(255, "Who are you?");
E 10
D 3
	for (i=0; uid && gr->gr_mem[i]; i++)
		if (!(strcmp(name, gr->gr_mem[i])))
			ingroup = 1;
	if (!ingroup && uid) {
		printf("illegal group: %s\n",argv[1]);
		exit(4);
E 3
I 3
	if (uid && pwd->pw_gid != gid) {
		for (i=0; gr->gr_mem[i]; i++)
			if (!(strcmp(pwd->pw_name, gr->gr_mem[i])))
				goto ok;
I 5
		if (fflag)
			exit(0);
E 5
D 10
		fprintf(stderr, "You are not a member of the %s group.\n",
D 8
		    argv[0]);
		exit(2);
E 8
I 8
		    		argv[0]);
		exit(255);
E 10
I 10
		fatal(255, "You are not a member of the %s group", argv[0]);
E 10
E 8
E 3
	}
E 2
D 3
	for(c=2; c<argc; c++) {
		stat(argv[c], &stbuf);
E 3
I 3
ok:
	for (c = 1; c < argc; c++) {
D 7
		if (stat(argv[c], &stbuf)) {
E 7
I 7
D 10
		if (lstat(argv[c], &stbuf)) {
E 7
			perror(argv[c]);
E 10
I 10
		/* do stat for directory arguments */
D 14
		if (stat(argv[c], &stbuf)) {
			status += error("can't access %s", argv[c]);
E 14
I 14
		if (lstat(argv[c], &stbuf)) {
			status += Perror(argv[c]);
E 14
E 10
			continue;
		}
E 3
D 2
		if(chown(argv[c], stbuf.st_uid, gid) < 0) {
			perror(argv[c]);
E 2
I 2
		if (uid && uid != stbuf.st_uid) {
I 5
D 10
			if (fflag)
				continue;
E 5
D 3
			printf("%s: not owner\n", argv[c]);
E 3
I 3
D 8
			fprintf(stderr, "You are not the owner of %s\n",
			    argv[c]);
E 3
E 2
			status = 1;
E 8
I 8
			fprintf(stderr, "You are not the owner of %s\n"
				      , argv[c]);
			++status;
E 10
I 10
			status += error("You are not the owner of %s", argv[c]);
E 10
E 8
D 2
		}
E 2
I 2
D 3
		} else
			chown(argv[c], stbuf.st_uid, gid);
E 3
I 3
			continue;
		}
D 6
		if (chown(argv[c], stbuf.st_uid, gid))
E 6
I 6
D 8
		if (chown(argv[c], stbuf.st_uid, gid) && !fflag)
E 8
I 8
D 10
		if (rflag && stbuf.st_mode & S_IFDIR)
E 10
I 10
D 15
		if (rflag && stbuf.st_mode & S_IFDIR) {
E 15
I 15
D 16
		if (rflag && (stbuf.st_mode & S_IFMT) == S_IFDIR) {
E 16
I 16
		if (rflag && ((stbuf.st_mode & S_IFMT) == S_IFDIR)) {
E 16
E 15
E 10
D 17
			status += chownr(argv[c], stbuf.st_uid, gid);
E 17
I 17
			status += chownr(argv[c]);
E 17
D 10
		else if (chown(argv[c], stbuf.st_uid, gid) && !fflag)
E 8
E 6
			perror(argv[c]);
E 10
I 10
			continue;
		}
D 14
		if (chown(argv[c], stbuf.st_uid, gid)) {
			status += error("can't change %s", argv[c]);
E 14
I 14
		if (chown(argv[c], -1, gid)) {
			status += Perror(argv[c]);
E 14
			continue;
		}
E 10
E 3
E 2
	}
	exit(status);
}

isnumber(s)
D 3
char *s;
E 3
I 3
	char *s;
E 3
{
D 3
	register c;
E 3
I 3
	register int c;
E 3

D 3
	while(c = *s++)
		if(!isdigit(c))
			return(0);
	return(1);
E 3
I 3
	while (c = *s++)
		if (!isdigit(c))
			return (0);
	return (1);
I 8
}

D 17
chownr(dir, uid, gid)
E 17
I 17
chownr(dir)
E 17
D 10
	char	*dir;
E 10
I 10
	char *dir;
E 10
{
D 10
	register DIR		*dirp;
	register struct direct	*dp;
	register struct stat	st;
	char			savedir[1024];
E 10
I 10
	register DIR *dirp;
	register struct direct *dp;
D 18
	register struct stat st;
E 18
I 18
	struct stat st;
E 18
	char savedir[1024];
	int ecode;
E 10

D 10
	if (getwd(savedir) == 0) {
		fprintf(stderr, "chgrp: %s\n", savedir);
		exit(255);
	}
	if (chown(dir, uid, gid) < 0 && !fflag) {
		perror(dir);
		return(1);
	}

	chdir(dir);
	if ((dirp = opendir(".")) == NULL) {
		perror(dir);
		exit(status);
	}
E 10
I 10
	if (getwd(savedir) == 0)
		fatal(255, "%s", savedir);
	/*
D 11
	 * Change what we are given before doing it's contents.
E 11
I 11
	 * Change what we are given before doing its contents.
E 11
	 */
D 14
	if (chown(dir, uid, gid) < 0 && error("can't change %s", dir))
E 14
I 14
	if (chown(dir, -1, gid) < 0 && Perror(dir))
E 14
		return (1);
D 14
	if (chdir(dir) < 0)
		return (Perror(dir));
	if ((dirp = opendir(".")) == NULL)
		return (Perror(dir));
E 14
I 14
	if (chdir(dir) < 0) {
		Perror(dir);
		return (1);
	}
	if ((dirp = opendir(".")) == NULL) {
		Perror(dir);
		return (1);
	}
E 14
E 10
	dp = readdir(dirp);
	dp = readdir(dirp); /* read "." and ".." */
D 10

E 10
I 10
	ecode = 0;
E 10
	for (dp = readdir(dirp); dp != NULL; dp = readdir(dirp)) {
D 10
		if (lstat(dp->d_name, &st) < 0) {
			fprintf(stderr, "chgrp: can't access %s\n", dp->d_name);
			return(1);
E 10
I 10
D 14
		if (stat(dp->d_name, &st) < 0) {
			ecode = error("can't access %s", dp->d_name);
E 14
I 14
		if (lstat(dp->d_name, &st) < 0) {
			ecode = Perror(dp->d_name);
E 14
			if (ecode)
				break;
I 11
			continue;
		}
		if (uid && uid != st.st_uid) {
			ecode = error("You are not the owner of %s",
				dp->d_name);
E 11
			continue;
E 10
		}
D 10
		if (st.st_mode & S_IFDIR)
			chownr(dp->d_name, st.st_uid, gid);
		else
			if (chown(dp->d_name, st.st_uid, gid) < 0 && !fflag) {
				perror(dp->d_name);
				return(1);
			}
E 10
I 10
D 15
		if (st.st_mode&S_IFDIR) {
E 15
I 15
D 16
		if ((stbuf.st_mode & S_IFMT) == S_IFDIR) {
E 16
I 16
		if ((st.st_mode & S_IFMT) == S_IFDIR) {
E 16
E 15
D 17
			ecode = chownr(dp->d_name, st.st_uid, gid);
E 17
I 17
			ecode = chownr(dp->d_name);
E 17
			if (ecode)
				break;
			continue;
		}
D 14
		if (chown(dp->d_name, st.st_uid, gid) < 0 &&
		    (ecode = error("can't change %s", dp->d_name)))
E 14
I 14
		if (chown(dp->d_name, -1, gid) < 0 &&
		    (ecode = Perror(dp->d_name)))
E 14
			break;
E 10
	}
	closedir(dirp);
D 10
	chdir(savedir);
	return(0);
E 10
I 10
	if (chdir(savedir) < 0)
		fatal(255, "can't change back to %s", savedir);
	return (ecode);
}

error(fmt, a)
	char *fmt, *a;
{

	if (!fflag) {
		fprintf(stderr, "chgrp: ");
		fprintf(stderr, fmt, a);
		putc('\n', stderr);
	}
	return (!fflag);
}

fatal(status, fmt, a)
	int status;
	char *fmt, *a;
{

	fflag = 0;
	(void) error(fmt, a);
	exit(status);
}

Perror(s)
	char *s;
{

D 14
	fprintf(stderr, "chgrp: ");
	perror(s);
	return (1);
E 14
I 14
	if (!fflag) {
		fprintf(stderr, "chgrp: ");
		perror(s);
	}
	return (!fflag);
E 14
E 10
E 8
E 3
}
I 2
D 3


E 3
E 2
E 1
