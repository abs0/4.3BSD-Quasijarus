h55930
s 00010/00005/00214
d D 5.11 88/06/18 14:34:06 bostic 16 15
c install approved copyright notice
e
s 00032/00024/00187
d D 5.10 88/04/23 12:33:13 bostic 15 14
c break out chown error into separate routine
e
s 00037/00021/00174
d D 5.9 88/04/22 12:18:07 bostic 14 13
c don't check group membership until after failure; don't do stat
c unless recursive, minor cleanups
e
s 00144/00146/00051
d D 5.8 88/04/21 11:04:00 bostic 13 12
c replacement code for chown and chgrp; major differences are use of
c getopt(3), much faster tree traversal code, fixed checking of group
c membership; complete rewrite, added Berkeley specific header
e
s 00002/00000/00195
d D 5.7 88/04/18 16:46:25 mckusick 12 11
c fail on null owner names (4.3BSD/etc/127)
e
s 00002/00002/00193
d D 5.6 86/05/29 15:30:43 mckusick 11 10
c fix those typos!
e
s 00002/00002/00193
d D 5.5 86/05/22 11:44:36 mckusick 10 9
c check mode properly
e
s 00020/00014/00175
d D 5.4 86/05/22 10:06:21 mckusick 9 8
c do not follow symbolic links; clean up error messages
e
s 00011/00015/00178
d D 5.3 86/04/29 19:50:22 bloom 8 7
c a dot without a group in the user field caused problems
e
s 00127/00097/00066
d D 5.2 85/08/31 17:45:13 sam 7 6
c cleanup
e
s 00015/00001/00148
d D 5.1 85/06/06 11:01:54 dist 6 5
c Add copyright
e
s 00002/00002/00147
d D 4.5 85/03/20 18:00:50 mckusick 5 4
c fix usage message
e
s 00106/00018/00043
d D 4.4 85/03/20 14:33:04 mckusick 4 3
c add -R option to work recursively (from layer)
e
s 00001/00001/00060
d D 4.3 83/11/23 15:18:28 mckusick 3 2
c chown does not follow symbolic links, so must use lstat to get gid
e
s 00007/00002/00054
d D 4.2 83/03/08 17:58:39 mckusick 2 1
c add -f option so install will not complain
e
s 00056/00000/00000
d D 4.1 80/10/01 17:25:32 bill 1 0
c date and time created 80/10/01 17:25:32 by bill
e
u
U
t
T
I 1
D 6
static char *sccsid = "%W% (Berkeley) %G%";
E 6
I 6
/*
D 13
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 13
I 13
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 16
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 16
I 16
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
E 16
E 13
 */

#ifndef lint
char copyright[] =
D 13
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
E 13
I 13
"%Z% Copyright (c) 1988 Regents of the University of California.\n\
E 13
 All rights reserved.\n";
D 7
#endif not lint
E 7
I 7
D 13
#endif
E 13
I 13
#endif /* not lint */
E 13
E 7

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 7
#endif not lint
E 7
I 7
D 13
#endif
E 13
I 13
#endif /* not lint */
E 13
E 7
E 6
I 4

E 4
D 13
/*
D 4
 * chown uid file ...
E 4
I 4
D 5
 * chown [-fr] uid[.gid] file ...
E 5
I 5
 * chown [-fR] uid[.gid] file ...
E 5
E 4
 */

#include <stdio.h>
#include <ctype.h>
#include <sys/types.h>
E 13
I 13
#include <sys/param.h>
E 13
#include <sys/stat.h>
D 13
#include <pwd.h>
E 13
I 4
#include <sys/dir.h>
I 13
#include <pwd.h>
E 13
#include <grp.h>
I 7
D 13
#include <strings.h>
E 13
I 13
#include <stdio.h>
#include <ctype.h>
E 13
E 7
E 4

D 7
struct	passwd	*pwd,*getpwnam();
struct	stat	stbuf;
E 7
I 7
D 13
struct	passwd *pwd;
struct	passwd *getpwnam();
struct	stat stbuf;
E 7
int	uid;
int	status;
I 2
D 4
int	fflag;
E 4
I 4
D 7
int	fflag, rflag;
E 7
I 7
int	fflag;
int	rflag;
E 13
I 13
static int ischown, uid, gid, fflag, rflag, retval;
D 14
static char *myname;
E 14
I 14
static char *gname, *myname;
E 14
E 13
E 7
E 4
E 2

main(argc, argv)
D 7
char *argv[];
E 7
I 7
D 13
	char *argv[];
E 13
I 13
	int argc;
	char **argv;
E 13
E 7
{
D 4
	register c;
E 4
I 4
D 13
	register int c, gid;
D 7
	register char *flags, *group;
E 7
I 7
	register char *cp, *group;
E 7
	struct group *grp;
E 13
I 13
	extern char *optarg;
	extern int optind;
	register char *cp;
	int ch;
	char *index(), *rindex();
E 13
E 4

D 7
	if(argc < 3) {
E 7
I 7
D 13
	argc--, argv++;
	while (argc > 0 && argv[0][0] == '-') {
		for (cp = &argv[0][1]; *cp; cp++) switch (*cp) {
E 13
I 13
	myname = (cp = rindex(*argv, '/')) ? cp + 1 : *argv;
	ischown = myname[2] == 'o';
E 13

I 13
	while ((ch = getopt(argc, argv, "Rf")) != EOF)
		switch((char)ch) {
		case 'R':
			rflag++;
			break;
E 13
		case 'f':
			fflag++;
			break;
I 13
		case '?':
		default:
			usage();
		}
	argv += optind;
	argc -= optind;
E 13

D 13
		case 'R':
			rflag++;
			break;
E 13
I 13
	if (argc < 2)
		usage();
E 13

D 13
		default:
			fatal(255, "unknown option: %c", *cp);
E 13
I 13
	if (ischown) {
		if (cp = index(*argv, '.')) {
			*cp++ = '\0';
			setgid(cp);
E 13
		}
D 13
		argv++, argc--;
E 13
I 13
		else
			gid = -1;
		setuid(*argv);
E 13
	}
D 13
	if (argc < 2) {
E 7
D 2
		printf("usage: chown uid file ...\n");
E 2
I 2
D 4
		printf("usage: chown -f uid file ...\n");
E 2
		exit(4);
E 4
I 4
D 5
		fprintf(stderr, "usage: chown [-fr] uid[.gid] file ...\n");
E 5
I 5
		fprintf(stderr, "usage: chown [-fR] owner[.group] file ...\n");
E 5
		exit(-1);
E 13
I 13
	else {
		uid = -1;
		setgid(*argv);
E 13
E 4
	}
I 8
D 13
	gid = -1;
E 8
I 2
D 4
	if (strcmp(argv[1], "-f") == 0) {
		fflag++;
E 4
I 4
D 7
	if (*argv[1] == '-') {
		for (flags = argv[1]; *flags; ++flags)
			switch (*flags) {
			  case '-':			break;
			  case 'f': 	fflag++;	break;
			  case 'R':	rflag++;	break;
			  default:
				printf("chown: unknown option: %c\n", *flags);
				exit(-2);
			}
E 4
		argv++, argc--;
E 7
I 7
	group = index(argv[0], '.');
	if (group != NULL) {
		*group++ = '\0';
		if (!isnumber(group)) {
			if ((grp = getgrnam(group)) == NULL)
				fatal(255, "unknown group: %s",group);
			gid = grp -> gr_gid;
D 8
			endgrent();
		} else
E 8
I 8
			(void) endgrent();
		} else if (*group != '\0')
E 8
			gid = atoi(group);
E 13
I 13

	while (*++argv)
		change(*argv);
	exit(retval);
}

static
setgid(s)
	register char *s;
{
D 14
	register int ngroups;
E 14
	struct group *gr, *getgrnam();
D 14
	int groups[NGROUPS];
	char *beg;
E 14

	if (!*s) {
		gid = -1;			/* argument was "uid." */
		return;
E 13
E 7
	}
E 2
D 4
	if(isnumber(argv[1])) {
E 4
I 4
D 7

	for (group = argv[1]; *group ; group++) {
		if (*group == '.') {
			*group = '\0';
			group++;
			if (isnumber(group))
				gid = atoi(group);
			else {
				if ((grp=getgrnam(group)) == NULL) {
					printf("unknown group: %s\n",group);
					exit(-3);
				}
				gid = grp -> gr_gid;
				endgrent();
			}
			goto owner;
		}
	}
	group = NULL;
	
owner:
	if (isnumber(argv[1])) {
E 4
		uid = atoi(argv[1]);
D 4
		goto cho;
E 4
I 4
	} else {
		if ((pwd=getpwnam(argv[1])) == NULL) {
			printf("unknown user id: %s\n",argv[1]);
			exit(-4);
		}
E 7
I 7
D 13
	if (!isnumber(argv[0])) {
		if ((pwd = getpwnam(argv[0])) == NULL)
			fatal(255, "unknown user id: %s",argv[0]);
E 7
		uid = pwd->pw_uid;
E 4
D 7
	}
D 4
	if((pwd=getpwnam(argv[1])) == NULL) {
		printf("unknown user id: %s\n",argv[1]);
		exit(4);
	}
	uid = pwd->pw_uid;
E 4

D 4
cho:
E 4
	for(c=2; c<argc; c++) {
D 3
		stat(argv[c], &stbuf);
E 3
I 3
D 4
		lstat(argv[c], &stbuf);
E 3
D 2
		if(chown(argv[c], uid, stbuf.st_gid) < 0) {
E 2
I 2
		if(chown(argv[c], uid, stbuf.st_gid) < 0 && !fflag) {
E 4
I 4
		if (lstat(argv[c], &stbuf) < 0) {
			printf("chown: couldn't stat %s\n", argv[c]);
			exit(-5);
E 7
I 7
	} else
		uid = atoi(argv[0]);
	for (c = 1; c < argc; c++) {
		/* do stat for directory arguments */
D 9
		if (stat(argv[c], &stbuf) < 0) {
			status += error("couldn't access %s", argv[c]);
E 9
I 9
		if (lstat(argv[c], &stbuf) < 0) {
			status += Perror(argv[c]);
E 9
			continue;
E 13
I 13
D 14
	for (beg = s; *s && isdigit(*s); ++s);
E 14
I 14
	for (gname = s; *s && isdigit(*s); ++s);
E 14
	if (!*s)
D 14
		gid = atoi(beg);
E 14
I 14
		gid = atoi(gname);
E 14
	else {
D 14
		if (!(gr = getgrnam(beg))) {
E 14
I 14
		if (!(gr = getgrnam(gname))) {
E 14
			if (fflag)
				exit(0);
			fprintf(stderr, "%s: unknown group id: %s\n",
D 14
			    myname, beg);
E 14
I 14
			    myname, gname);
E 14
			exit(-1);
E 13
E 7
		}
D 8
		if (group == NULL)
			gid = stbuf.st_gid;
E 8
D 7
		if (rflag && stbuf.st_mode & S_IFDIR)
			status += chownr(argv[c], group, uid, gid);
		else if (chown(argv[c], uid, gid) < 0 && !fflag) {
E 4
E 2
			perror(argv[c]);
D 4
			status = 1;
E 4
I 4
			status++;
E 7
I 7
D 10
		if (rflag && stbuf.st_mode&S_IFDIR) {
E 10
I 10
D 11
		if (rflag && (stbuf.st_mode&S_IFMT) == S_IFDIR) {
E 11
I 11
D 13
		if (rflag && ((stbuf.st_mode&S_IFMT) == S_IFDIR)) {
E 11
E 10
D 8
			status += chownr(argv[c], group != NULL, uid, gid);
E 8
I 8
			status += chownr(argv[c], uid, gid);
E 8
			continue;
E 7
E 4
		}
I 7
		if (chown(argv[c], uid, gid)) {
D 9
			status += error("couldn't change %s", argv[c]);
E 9
I 9
			status += Perror(argv[c]);
E 9
			continue;
		}
E 13
I 13
		gid = gr->gr_gid;
E 13
E 7
	}
D 13
	exit(status);
E 13
I 13
D 14
	/* check now; the kernel returns "EPERM" on later failure */
	ngroups = getgroups(NGROUPS, groups);
	while (--ngroups >= 0 && gid != groups[ngroups]);
	if (ngroups < 0) {
		if (fflag)
			exit(0);
		fprintf(stderr, "%s: you are not a member of group %s.\n",
		    myname, beg);
		exit(-1);
	}
E 14
E 13
}

D 13
isnumber(s)
D 7
char *s;
E 7
I 7
	char *s;
E 13
I 13
static
setuid(s)
	register char *s;
E 13
E 7
{
D 13
	register c;
E 13
I 13
	struct passwd *pwd, *getpwnam();
	char *beg;
E 13

I 12
D 13
	if (*s == '\0')
		return 0;
E 12
	while(c = *s++)
D 7
		if(!isdigit(c))
			return(0);
	return(1);
E 7
I 7
		if (!isdigit(c))
			return (0);
	return (1);
E 13
I 13
	if (!*s) {
		uid = -1;			/* argument was ".gid" */
		return;
	}
	for (beg = s; *s && isdigit(*s); ++s);
	if (!*s)
		uid = atoi(beg);
	else {
		if (!(pwd = getpwnam(beg))) {
			if (fflag)
				exit(0);
			fprintf(stderr, "chown: unknown user id: %s\n", beg);
			exit(-1);
		}
		uid = pwd->pw_uid;
	}
E 13
E 7
I 4
}

D 7
chownr(dir, dogrp, uid, gid_save)
	char	*dir;
E 7
I 7
D 8
chownr(dir, dogrp, uid, ogid)
E 8
I 8
D 13
chownr(dir, uid, gid)
E 8
	char *dir;
E 13
I 13
static
change(file)
	char *file;
E 13
E 7
{
D 7
	register DIR		*dirp;
	register struct direct	*dp;
	register struct stat	st;
	char			savedir[1024];
	int			gid;
E 7
I 7
	register DIR *dirp;
	register struct direct *dp;
D 8
	register struct stat st;
E 8
I 8
D 13
	struct stat st;
E 8
	char savedir[1024];
D 8
	int ecode, gid;
E 8
I 8
	int ecode;
	extern char *getwd();
E 13
I 13
	struct stat buf;
E 13
E 8
E 7

D 7
	if (getwd(savedir) == 0) {
		fprintf(stderr, "chown: %s\n", savedir);
		exit(-6);
	}
	if (chown(dir, uid, gid_save) < 0 && !fflag) {
		perror(dir);
		return(1);
	}

	chdir(dir);
	if ((dirp = opendir(".")) == NULL) {
		perror(dir);
		exit(status);
	}
E 7
I 7
D 8
	if (getwd(savedir) == 0)
E 8
I 8
D 13
	if (getwd(savedir) == (char *)0)
E 8
		fatal(255, "%s", savedir);
	/*
	 * Change what we are given before doing it's contents.
	 */
D 8
	if (chown(dir, uid, ogid) < 0 && error("can't change %s", dir))
E 8
I 8
D 9
	if (chown(dir, uid, gid) < 0 && error("can't change %s", dir))
E 9
I 9
	if (chown(dir, uid, gid) < 0 && Perror(dir))
E 9
E 8
		return (1);
D 9
	if (chdir(dir) < 0)
		return (Perror(dir));
	if ((dirp = opendir(".")) == NULL)
		return (Perror(dir));
E 9
I 9
	if (chdir(dir) < 0) {
		Perror(dir);
		return (1);
E 13
I 13
D 14
	if (lstat(file, &buf) || chown(file, uid, gid)) {
E 14
I 14
	if (chown(file, uid, gid)) {
D 15
		static int euid = -1, ngroups = -1;

		if (uid != -1 && euid == -1 && (euid = geteuid())) {
			if (fflag)
				exit(0);
			err(file);
			exit(-1);
		}
		/* check group membership; kernel just returns EPERM */
		if (gid != -1 && ngroups == -1) {
			int groups[NGROUPS];

			ngroups = getgroups(NGROUPS, groups);
			while (--ngroups >= 0 && gid != groups[ngroups]);
			if (ngroups < 0) {
				if (fflag)
					exit(0);
				fprintf(stderr,
				    "%s: you are not a member of group %s.\n",
				    myname, gname);
				exit(-1);
			}
		}
E 14
		err(file);
E 15
I 15
		chownerr(file);
E 15
		return;
E 13
	}
D 13
	if ((dirp = opendir(".")) == NULL) {
		Perror(dir);
		return (1);
	}
E 9
E 7
	dp = readdir(dirp);
	dp = readdir(dirp); /* read "." and ".." */
D 7

E 7
I 7
	ecode = 0;
E 7
	for (dp = readdir(dirp); dp != NULL; dp = readdir(dirp)) {
D 7
		if (lstat(dp->d_name, &st) < 0) {
			fprintf(stderr, "chown: can't access %s\n", dp->d_name);
			return(1);
E 7
I 7
D 9
		if (stat(dp->d_name, &st) < 0) {
			ecode = error("can't access %s", dp->d_name);
E 9
I 9
		if (lstat(dp->d_name, &st) < 0) {
			ecode = Perror(dp->d_name);
E 9
			if (ecode)
				break;
			continue;
E 13
I 13
D 14
	if (rflag && ((buf.st_mode & S_IFMT) == S_IFDIR)) {
E 14
I 14
	if (!rflag)
		return;
	if (lstat(file, &buf)) {
		err(file);
		return;
	}
	if ((buf.st_mode & S_IFMT) == S_IFDIR) {
E 14
		if (chdir(file) < 0 || !(dirp = opendir("."))) {
			err(file);
			return;
E 13
E 7
		}
D 8
		if (dogrp)
D 7
			gid = gid_save;
E 7
I 7
			gid = ogid;
E 7
		else
			gid = st.st_gid;
E 8
D 7
		if (st.st_mode & S_IFDIR)
			chownr(dp->d_name, dogrp, uid, gid);
		else
			if (chown(dp->d_name, uid, gid) < 0 && !fflag) {
				perror(dp->d_name);
				return(1);
			}
E 7
I 7
D 10
		if (st.st_mode&S_IFDIR) {
E 10
I 10
D 11
		if ((stbuf.st_mode&S_IFMT) == S_IFDIR) {
E 11
I 11
D 13
		if ((st.st_mode&S_IFMT) == S_IFDIR) {
E 11
E 10
D 8
			ecode = chownr(dp->d_name, dogrp, uid, gid);
E 8
I 8
			ecode = chownr(dp->d_name, uid, gid);
E 8
			if (ecode)
				break;
			continue;
E 13
I 13
		for (dp = readdir(dirp); dp; dp = readdir(dirp)) {
			if (dp->d_name[0] == '.' && (!dp->d_name[1] ||
			    dp->d_name[1] == '.' && !dp->d_name[2]))
				continue;
			change(dp->d_name);
E 13
		}
D 13
		if (chown(dp->d_name, uid, gid) < 0 &&
D 9
		    (ecode = error("can't change %s", dp->d_name)))
E 9
I 9
		    (ecode = Perror(dp->d_name)))
E 9
			break;
E 13
I 13
		closedir(dirp);
		if (chdir("..")) {
			err("..");
			exit(fflag ? 0 : -1);
		}
E 13
E 7
	}
I 15
}

static
chownerr(file)
	char *file;
{
	static int euid = -1, ngroups = -1;

	/* check for chown without being root */
	if (uid != -1 && euid == -1 && (euid = geteuid())) {
		if (fflag)
			exit(0);
		err(file);
		exit(-1);
	}
	/* check group membership; kernel just returns EPERM */
	if (gid != -1 && ngroups == -1) {
		int groups[NGROUPS];

		ngroups = getgroups(NGROUPS, groups);
		while (--ngroups >= 0 && gid != groups[ngroups]);
		if (ngroups < 0) {
			if (fflag)
				exit(0);
			fprintf(stderr,
			    "%s: you are not a member of group %s.\n",
			    myname, gname);
			exit(-1);
		}
	}
	err(file);
E 15
D 13
	closedir(dirp);
D 7
	chdir(savedir);
	return(0);
E 7
I 7
	if (chdir(savedir) < 0)
		fatal(255, "can't change back to %s", savedir);
	return (ecode);
E 13
}

D 13
error(fmt, a)
	char *fmt, *a;
E 13
I 13
static
err(s)
	char *s;
E 13
{
D 13

	if (!fflag) {
		fprintf(stderr, "chown: ");
		fprintf(stderr, fmt, a);
		putc('\n', stderr);
	}
	return (!fflag);
E 13
I 13
	if (fflag)
		return;
D 14
	fputs(ischown ? "chown: " : "chgrp: ", stderr);
E 14
I 14
	fprintf(stderr, "%s: ", myname);
E 14
	perror(s);
	retval = -1;
E 13
}

D 13
fatal(status, fmt, a)
	int status;
	char *fmt, *a;
E 13
I 13
static
usage()
E 13
{
D 13

	fflag = 0;
	(void) error(fmt, a);
	exit(status);
}

Perror(s)
	char *s;
{

D 9
	fprintf(stderr, "chown: ");
	perror(s);
	return (1);
E 9
I 9
	if (!fflag) {
		fprintf(stderr, "chown: ");
		perror(s);
	}
	return (!fflag);
E 13
I 13
	fprintf(stderr, "usage: %s [-Rf] %s file ...\n", myname,
	    ischown ? "owner[.group]" : "group");
	exit(-1);
E 13
E 9
E 7
E 4
}
E 1
