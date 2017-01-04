h45613
s 00026/00026/00281
d D 5.12 88/07/06 17:02:08 bostic 16 15
c do declarations in KNF
e
s 00010/00005/00297
d D 5.11 88/06/29 21:54:29 bostic 15 14
c install approved copyright notice
e
s 00042/00048/00260
d D 5.10 87/12/04 14:34:15 bostic 14 13
c if rename successful wasn't setting owner/mode; removed call to rename,
c redid logic to be a little more straight forward.  Berkeley headers.
e
s 00003/00003/00305
d D 5.9 87/11/02 09:04:37 bostic 13 12
c fix st_mode comparisons
e
s 00015/00013/00293
d D 5.8 87/09/10 13:08:28 bostic 12 10
c install shouldn't know about errno/sys_errlst[];
e
s 00001/00001/00305
d D 5.7 87/08/09 12:44:08 bostic 10 8
c rindex takes char pointer, not char
e
s 00003/00003/00303
d R 5.7 87/08/09 12:43:28 bostic 9 8
c rindex gets char pointer, not char
e
s 00012/00010/00294
d D 5.6 87/08/03 16:57:43 bostic 8 6
c no more default owner/group, use whoever running it; fix bug 
c where didn't set mode if successful rename; fix lseek argument order
e
s 00010/00009/00295
d R 5.6 87/08/03 16:53:41 bostic 7 6
c no more default owner/group, use whoever is running it unless 
c otherwise specified; fix bug where didn't set mode if successful rename
e
s 00127/00088/00177
d D 5.5 87/07/31 10:55:21 bostic 6 4
c rewritten to handle multiple files to a directory; fix so can 
c strip already stripped binaries
e
s 00124/00088/00177
d R 5.5 87/07/30 21:05:41 bostic 5 4
c rewrote to handle multiple files to a directory
e
s 00004/00002/00261
d D 5.4 87/07/25 10:15:05 bostic 4 3
c do it right, not according to K&R...
e
s 00014/00007/00249
d D 5.3 87/07/23 06:43:39 bostic 3 2
c check for special file target, allow "/dev/null" install
e
s 00046/00038/00210
d D 5.2 87/07/17 21:05:57 bostic 2 1
c provide "bad" exit routine; do all processing possible before 
c actually opening target; minor cleanups
e
s 00248/00000/00000
d D 5.1 87/07/17 14:52:06 bostic 1 0
c date and time created 87/07/17 14:52:06 by bostic
e
u
U
t
T
I 1
/*
 * Copyright (c) 1987 Regents of the University of California.
D 14
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 14
I 14
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 15
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific written prior permission. This software
 * is provided ``as is'' without express or implied warranty.
E 15
I 15
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
E 15
E 14
 */

#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1987 Regents of the University of California.\n\
 All rights reserved.\n";
D 14
#endif not lint
E 14
I 14
#endif /* not lint */
E 14

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 14
#endif not lint
E 14
I 14
#endif /* not lint */
E 14

#include <sys/param.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <a.out.h>
#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <ctype.h>

D 14
#define	YES		1			/* yes/true */
I 6
#define	NO		0			/* no/false */
E 14
I 14
#define	YES	1			/* yes/true */
#define	NO	0			/* no/false */
E 14
E 6
D 2
#define	DEF_GROUP	"root"			/* default group */
#define	DEF_OWNER	"staff"			/* default owner */
E 2
I 2
D 8
#define	DEF_GROUP	"staff"			/* default group */
#define	DEF_OWNER	"root"			/* default owner */
E 8
E 2

D 6
static int	docopy, dostrip,
		mode = 0755;
static char	*group = DEF_GROUP,
D 2
		*owner = DEF_OWNER;
E 2
I 2
		*owner = DEF_OWNER,
		*path;
E 6
I 4
D 12
extern int	errno;
extern char	*sys_errlist[];
E 12
I 12
#define	PERROR(head, msg) { \
	fputs(head, stderr); \
	perror(msg); \
}
E 12
E 4
E 2

I 6
static struct passwd	*pp;
static struct group	*gp;
static int	docopy, dostrip,
		mode = 0755;
D 8
static char	pathbuf[MAXPATHLEN];
E 8
I 8
static char	*group, *owner,
		pathbuf[MAXPATHLEN];
E 8

E 6
main(argc, argv)
D 16
	int	argc;
	char	**argv;
E 16
I 16
	int argc;
	char **argv;
E 16
{
D 4
	extern char	*optarg, *sys_errlist[];
	extern int	optind, errno;
E 4
I 4
D 16
	extern char	*optarg;
	extern int	optind;
E 4
D 6
	register int	to_fd;
E 6
	struct stat	from_sb, to_sb;
D 6
	struct passwd	*pp;
	struct group	*gp;
D 3
	int	ch;
E 3
I 3
	int	ch, devnull;
E 3
D 2
	char	*path, pbuf[MAXPATHLEN];
E 2
I 2
	char	pbuf[MAXPATHLEN];
E 6
I 6
	int	ch, no_target;
D 8
	char	*group, *owner, *to_name;
E 8
I 8
	char	*to_name;
E 16
I 16
	extern char *optarg;
	extern int optind;
	struct stat from_sb, to_sb;
	int ch, no_target;
	char *to_name;
E 16
E 8
E 6
E 2

I 6
D 8
	group = DEF_GROUP;
	owner = DEF_OWNER;
E 8
E 6
	while ((ch = getopt(argc, argv, "cg:m:o:s")) != EOF)
		switch((char)ch) {
		case 'c':
			docopy = YES;
			break;
		case 'g':
			group = optarg;
			break;
		case 'm':
			mode = atoo(optarg);
			break;
		case 'o':
			owner = optarg;
			break;
		case 's':
			dostrip = YES;
			break;
		case '?':
		default:
			usage();
		}
	argc -= optind;
	argv += optind;
D 6
	if (argc != 2)
E 6
I 6
	if (argc < 2)
E 6
		usage();

I 2
	/* get group and owner id's */
D 8
	if (!(gp = getgrnam(group))) {
E 8
I 8
	if (group && !(gp = getgrnam(group))) {
E 8
		fprintf(stderr, "install: unknown group %s.\n", group);
		exit(1);
	}
D 8
	if (!(pp = getpwnam(owner))) {
E 8
I 8
	if (owner && !(pp = getpwnam(owner))) {
E 8
		fprintf(stderr, "install: unknown user %s.\n", owner);
		exit(1);
	}

E 2
D 6
	/* check source */
	if (stat(argv[0], &from_sb)) {
		fprintf(stderr, "install: fstat: %s: %s\n", argv[0], sys_errlist[errno]);
		exit(1);
E 6
I 6
	no_target = stat(to_name = argv[argc - 1], &to_sb);
D 13
	if (!no_target && to_sb.st_mode & S_IFDIR) {
E 13
I 13
	if (!no_target && (to_sb.st_mode & S_IFMT) == S_IFDIR) {
E 13
		for (; *argv != to_name; ++argv)
			install(*argv, to_name, YES);
		exit(0);
E 6
	}
D 3
	if (!(from_sb.st_mode & S_IFREG)) {
E 3
I 3
D 6
	/* special case for removing files */
	devnull = !strcmp(argv[0], "/dev/null");
	if (!devnull && !(from_sb.st_mode & S_IFREG)) {
E 3
		fprintf(stderr, "install: %s isn't a regular file.\n", argv[0]);
		exit(1);
	}
E 6

D 6
	/* build target path, find out if target is same as source */
	if (!stat(path = argv[1], &to_sb)) {
		if (to_sb.st_mode & S_IFDIR) {
D 3
			(void)sprintf(path = pbuf, "%s/%s", argv[1], argv[0]);
E 3
I 3
			char	*C, *rindex();
E 6
I 6
	/* can't do file1 file2 directory/file */
	if (argc != 2)
		usage();
E 6

D 6
			(void)sprintf(path = pbuf, "%s/%s", argv[1], (C = rindex(argv[0], '/')) ? ++C : argv[0]);
E 3
			if (stat(path, &to_sb))
				goto nocompare;
E 6
I 6
	if (!no_target) {
		if (stat(*argv, &from_sb)) {
			fprintf(stderr, "install: can't find %s.\n", *argv);
			exit(1);
E 6
D 3
			if (to_sb.st_mode & S_IFDIR) {
				fprintf(stderr, "install: %s is a directory.\n", path);
				exit(1);
			}
E 3
		}
I 3
D 13
		if (!(to_sb.st_mode & S_IFREG)) {
E 13
I 13
		if ((to_sb.st_mode & S_IFMT) != S_IFREG) {
E 13
D 6
			fprintf(stderr, "install: %s isn't a regular file.\n", path);
E 6
I 6
			fprintf(stderr, "install: %s isn't a regular file.\n", to_name);
E 6
			exit(1);
		}
E 3
		if (to_sb.st_dev == from_sb.st_dev && to_sb.st_ino == from_sb.st_ino) {
D 6
			fprintf(stderr, "install: %s and %s are the same file.\n", argv[0], path);
E 6
I 6
			fprintf(stderr, "install: %s and %s are the same file.\n", *argv, to_name);
E 6
			exit(1);
		}
		/* unlink now... avoid ETXTBSY errors later */
D 6
		(void)unlink(path);
E 6
I 6
		(void)unlink(to_name);
E 6
	}
I 6
	install(*argv, to_name, NO);
	exit(0);
}
E 6

D 6
nocompare:
D 2
	/* get group and owner id's */
	if (!(gp = getgrnam(group))) {
		fprintf(stderr, "install: unknown group %s.\n", group);
		exit(1);
	}
	if (!(pp = getpwnam(owner))) {
		fprintf(stderr, "install: unknown user %s.\n", owner);
		exit(1);
	}

E 2
	/* open target, set mode, owner, group */
	if ((to_fd = open(path, O_CREAT|O_WRONLY|O_TRUNC, 0)) < 0) {
		fprintf(stderr, "install: %s: %s\n", path, sys_errlist[errno]);
E 6
I 6
/*
 * install --
 *	build a path name and install the file
 */
static
install(from_name, to_name, isdir)
D 16
	char	*from_name, *to_name;
	int	isdir;
E 16
I 16
	char *from_name, *to_name;
	int isdir;
E 16
{
D 16
	struct stat	from_sb;
	int	devnull, from_fd, to_fd;
D 14
	char	*C,
		*rindex();
E 14
I 14
	char	*C, *rindex();
E 16
I 16
	struct stat from_sb;
	int devnull, from_fd, to_fd;
	char *C, *rindex();
E 16
E 14

D 14
	if ((from_fd = open(from_name, O_RDONLY, 0)) < 0) {
D 12
		fprintf(stderr, "install: open: %s: %s\n", from_name, sys_errlist[errno]);
E 12
I 12
		PERROR("install: open: ", from_name);
E 12
E 6
		exit(1);
	}
I 6

E 14
	/* if try to install "/dev/null" to a directory, fails */
D 14
	devnull = isdir ? NO : !strcmp(from_name, "/dev/null");
	if (!devnull) {
		if (fstat(from_fd, &from_sb)) {
E 14
I 14
	if (isdir || strcmp(from_name, "/dev/null")) {
		if (stat(from_name, &from_sb)) {
E 14
			fprintf(stderr, "install: can't find %s.\n", from_name);
			exit(1);
		}
D 13
		if (!(from_sb.st_mode & S_IFREG)) {
E 13
I 13
		if ((from_sb.st_mode & S_IFMT) != S_IFREG) {
E 13
			fprintf(stderr, "install: %s isn't a regular file.\n", from_name);
			exit(1);
		}
I 14
		/* build the target path */
		if (isdir) {
			(void)sprintf(pathbuf, "%s/%s", to_name, (C = rindex(from_name, '/')) ? ++C : from_name);
			to_name = pathbuf;
		}
		devnull = NO;
E 14
	}
I 14
	else
		devnull = YES;
E 14

D 14
	/* build the path */
	if (isdir) {
D 10
		(void)sprintf(pathbuf, "%s/%s", to_name, (C = rindex(*from_name, '/')) ? ++C : from_name);
E 10
I 10
		(void)sprintf(pathbuf, "%s/%s", to_name, (C = rindex(from_name, '/')) ? ++C : from_name);
E 10
		to_name = pathbuf;
	}

E 14
	/* unlink now... avoid ETXTBSY errors later */
	(void)unlink(to_name);

D 14
	/* open target, set owner, group, mode */
E 14
I 14
	/* create target */
E 14
	if ((to_fd = open(to_name, O_CREAT|O_WRONLY|O_TRUNC, 0)) < 0) {
D 12
		fprintf(stderr, "install: %s: %s\n", to_name, sys_errlist[errno]);
E 12
I 12
		PERROR("install: ", to_name);
E 12
		exit(1);
	}
I 14
	if (!devnull) {
		if ((from_fd = open(from_name, O_RDONLY, 0)) < 0) {
			(void)unlink(to_name);
			PERROR("install: open: ", from_name);
			exit(1);
		}
		if (dostrip)
			strip(from_fd, from_name, to_fd, to_name);
		else
			copy(from_fd, from_name, to_fd, to_name);
		(void)close(from_fd);
		if (!docopy)
			(void)unlink(from_name);
	}
	/* set owner, group, mode for target */
E 14
E 6
	if (fchmod(to_fd, mode)) {
D 6
		fprintf(stderr, "install: fchmod: %s: %s\n", path, sys_errlist[errno]);
E 6
I 6
D 12
		fprintf(stderr, "install: fchmod: %s: %s\n", to_name, sys_errlist[errno]);
E 12
I 12
		PERROR("install: fchmod: ", to_name);
E 12
E 6
D 2
		(void)unlink(path);
		exit(1);
E 2
I 2
		bad();
E 2
	}
D 8
	if (fchown(to_fd, pp->pw_uid, gp->gr_gid)) {
E 8
I 8
D 14
	if ((group || owner) && fchown(to_fd, owner ? pp->pw_uid : -1, group ? gp->gr_gid : -1)) {
E 14
I 14
	if ((group || owner) && fchown(to_fd, owner ? pp->pw_uid : -1,
	    group ? gp->gr_gid : -1)) {
E 14
E 8
D 6
		fprintf(stderr, "install: fchown: %s: %s\n", path, sys_errlist[errno]);
E 6
I 6
D 12
		fprintf(stderr, "install: fchown: %s: %s\n", to_name, sys_errlist[errno]);
E 12
I 12
		PERROR("install: fchown: ", to_name);
E 12
E 6
D 2
		(void)unlink(path);
		exit(1);
E 2
I 2
		bad();
E 2
	}
I 3
D 14

D 6
	if (devnull)
		exit(0);
E 6
I 6
	if (devnull) {
		(void)close(to_fd);
		return;
	}
E 6
E 3

	if (dostrip) {
D 6
		strip(to_fd, argv[0], path);
E 6
I 6
		strip(from_fd, from_name, to_fd, to_name);
E 6
		if (docopy)
D 6
			exit(0);
E 6
I 6
			goto done;
E 6
	}
	else if (docopy) {
D 6
		copy(argv[0], to_fd, path);
		exit(0);
E 6
I 6
		copy(from_fd, from_name, to_fd, to_name);
		goto done;
E 6
	}
D 6
	else if (rename(argv[0], path))
		copy(argv[0], to_fd, path);
	(void)unlink(argv[0]);
	exit(0);
}
E 6
I 6
	else if (rename(from_name, to_name))
		copy(from_fd, from_name, to_fd, to_name);
I 8
	else if (chmod(to_name, mode)) {
D 12
		fprintf(stderr, "install: chmod: %s: %s\n", to_name, sys_errlist[errno]);
E 12
I 12
		PERROR("install: chmod: ", to_name);
E 12
		bad();
	}
E 8
	(void)unlink(from_name);
E 6

D 6
/*
 * copy --
 *	copy from one file to another
 */
static
copy(from_name, to_fd, to_name)
	register int	to_fd;
	char	*from_name, *to_name;
{
	register int	n, from_fd;
	char	buf[MAXBSIZE];

	if ((from_fd = open(from_name, O_RDONLY, 0)) < 0) {
		fprintf(stderr, "install: open: %s: %s\n", from_name, sys_errlist[errno]);
D 2
		(void)unlink(to_name);
		exit(1);
E 2
I 2
		bad();
E 2
	}
	while ((n = read(from_fd, buf, sizeof(buf))) > 0)
		if (write(to_fd, buf, n) != n) {
			fprintf(stderr, "install: write: %s: %s\n", to_name, sys_errlist[errno]);
D 2
			(void)unlink(to_name);
E 2
I 2
			bad();
E 2
		}
	if (n == -1) {
D 2
		fprintf(stderr, "install: read: %s: %s\n", to_name, sys_errlist[errno]);
		(void)unlink(to_name);
E 2
I 2
		fprintf(stderr, "install: read: %s: %s\n", from_name, sys_errlist[errno]);
		bad();
E 2
	}
E 6
I 6
done:	(void)close(from_fd);
E 14
	(void)close(to_fd);
E 6
}

/*
 * strip --
 *	copy file, strip(1)'ing it at the same time
 */
static
D 6
strip(to_fd, from_name, to_name)
	register int	to_fd;
E 6
I 6
strip(from_fd, from_name, to_fd, to_name)
D 16
	register int	from_fd, to_fd;
E 6
	char	*from_name, *to_name;
E 16
I 16
	register int from_fd, to_fd;
	char *from_name, *to_name;
E 16
{
D 16
	typedef struct exec	EXEC;
	register long	size;
D 6
	register int	n, from_fd;
E 6
I 6
	register int	n;
E 6
	EXEC	head;
	char	buf[MAXBSIZE];
I 8
	off_t	lseek();
E 16
I 16
	typedef struct exec EXEC;
	register long size;
	register int n;
	EXEC head;
	char buf[MAXBSIZE];
	off_t lseek();
E 16
E 8

D 6
	if ((from_fd = open(from_name, O_RDONLY, 0)) < 0) {
		fprintf(stderr, "install: open: %s: %s\n", from_name, sys_errlist[errno]);
D 2
		(void)unlink(to_name);
		exit(1);
E 2
I 2
		bad();
E 2
	}
E 6
	if (read(from_fd, (char *)&head, sizeof(head)) < 0 || N_BADMAG(head)) {
		fprintf(stderr, "install: %s not in a.out format.\n", from_name);
D 2
		(void)unlink(to_name);
		exit(1);
E 2
I 2
		bad();
E 2
	}
	if (head.a_syms || head.a_trsize || head.a_drsize) {
		size = (long)head.a_text + head.a_data;
		head.a_syms = head.a_trsize = head.a_drsize = 0;
		if (head.a_magic == ZMAGIC)
			size += getpagesize() - sizeof(EXEC);
		if (write(to_fd, (char *)&head, sizeof(EXEC)) != sizeof(EXEC)) {
D 12
			fprintf(stderr, "install: write: %s: %s\n", to_name, sys_errlist[errno]);
E 12
I 12
			PERROR("install: write: ", to_name);
E 12
D 2
			(void)unlink(to_name);
			exit(1);
E 2
I 2
			bad();
E 2
		}
		for (; size; size -= n)
I 14
			/* sizeof(buf) guaranteed to fit in an int */
E 14
			if ((n = read(from_fd, buf, (int)MIN(size, sizeof(buf)))) <= 0)
				break;
			else if (write(to_fd, buf, n) != n) {
D 12
				fprintf(stderr, "install: write: %s: %s\n", to_name, sys_errlist[errno]);
E 12
I 12
				PERROR("install: write: ", to_name);
E 12
D 2
				(void)unlink(to_name);
				exit(1);
E 2
I 2
				bad();
E 2
			}
I 2
		if (size) {
			fprintf(stderr, "install: read: %s: premature EOF.\n", from_name);
			bad();
		}
E 2
		if (n == -1) {
D 12
			fprintf(stderr, "install: read: %s: %s\n", from_name, sys_errlist[errno]);
E 12
I 12
			PERROR("install: read: ", from_name);
E 12
D 2
			(void)unlink(to_name);
			exit(1);
E 2
I 2
			bad();
E 2
		}
	}
I 6
	else {
D 8
		(void)lseek(from_fd, L_SET, 0L);
E 8
I 8
		(void)lseek(from_fd, 0L, L_SET);
E 8
		copy(from_fd, from_name, to_fd, to_name);
	}
E 6
}

/*
I 6
 * copy --
 *	copy from one file to another
 */
static
copy(from_fd, from_name, to_fd, to_name)
D 16
	register int	from_fd, to_fd;
	char	*from_name, *to_name;
E 16
I 16
	register int from_fd, to_fd;
	char *from_name, *to_name;
E 16
{
D 16
	register int	n;
	char	buf[MAXBSIZE];
E 16
I 16
	register int n;
	char buf[MAXBSIZE];
E 16

	while ((n = read(from_fd, buf, sizeof(buf))) > 0)
		if (write(to_fd, buf, n) != n) {
D 12
			fprintf(stderr, "install: write: %s: %s\n", to_name, sys_errlist[errno]);
E 12
I 12
			PERROR("install: write: ", to_name);
E 12
			bad();
		}
	if (n == -1) {
D 12
		fprintf(stderr, "install: read: %s: %s\n", from_name, sys_errlist[errno]);
E 12
I 12
		PERROR("install: read: ", from_name);
E 12
		bad();
	}
}

/*
E 6
 * atoo --
 *	octal string to int
 */
static
D 2
atoo(C)
	register char	*C;		/* argument string */
E 2
I 2
atoo(str)
D 16
	register char	*str;
E 16
I 16
	register char *str;
E 16
E 2
{
D 2
	register int	val;		/* return value */
E 2
I 2
D 16
	register int	val;
E 16
I 16
	register int val;
E 16
E 2

D 2
	for (val = 0; isdigit(*C); ++C)
		val = val * 8 + *C - '0';
E 2
I 2
	for (val = 0; isdigit(*str); ++str)
		val = val * 8 + *str - '0';
E 2
	return(val);
}

/*
D 6
 * usage --
 *	print a usage message and die
E 6
I 6
 * bad --
 *	remove created target and die
E 6
 */
static
D 6
usage()
E 6
I 6
bad()
E 6
{
D 6
	fputs("usage: install [-cs] [-g group] [-m mode] [-o owner] source destination\n", stderr);
E 6
I 6
	(void)unlink(pathbuf);
E 6
I 2
	exit(1);
}

/*
D 6
 * bad --
 *	remove created target and die
E 6
I 6
 * usage --
 *	print a usage message and die
E 6
 */
static
D 6
bad()
E 6
I 6
usage()
E 6
{
D 6
	(void)unlink(path);
E 6
I 6
D 12
	fputs("usage: install [-cs] [-g group] [-m mode] [-o owner] f1 f2;\n\tor f1 ... fn directory\n", stderr);
E 12
I 12
	fputs("usage: install [-cs] [-g group] [-m mode] [-o owner] file1 file2;\n\tor file1 ... fileN directory\n", stderr);
E 12
E 6
E 2
	exit(1);
}
E 1
