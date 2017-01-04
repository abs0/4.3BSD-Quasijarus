h15236
s 00012/00007/00119
d D 4.11 88/06/18 13:17:09 bostic 14 13
c install approved copyright notice
e
s 00012/00006/00114
d D 4.10 87/11/30 21:00:32 bostic 13 12
c Berkeley code; add header
e
s 00101/00070/00019
d D 4.9 87/11/05 16:36:25 bostic 12 11
c add getopt; remove unused variables; use correct constants for 
c path length; simplify error checking; match usage statement to manual page 
c generally hack like I keep swearing I won't do
e
s 00002/00002/00087
d D 4.8 87/11/05 16:32:18 bostic 11 9
c fix "ln -s file1 file2 file3"; bug report 4.3BSD/bin/95
e
s 00002/00002/00087
d R 4.8 87/11/05 10:09:55 bostic 10 9
c fix "ln -s /etc/motd /etc/group /etc/passwd"; bug report 
c 4.3BSD/bin/95
e
s 00001/00001/00088
d D 4.7 87/10/22 09:51:07 bostic 9 8
c ANSI C; sprintf now returns an int.
e
s 00001/00001/00088
d D 4.6 85/11/15 09:29:05 lepreau 8 7
c avoid "ln -s nosuchfile non-writeable-dir" give misleading
c msg "nosuchfile: ENOENT..."
e
s 00003/00001/00086
d D 4.5 83/06/30 14:34:53 sam 7 6
c from sun
e
s 00006/00001/00081
d D 4.4 82/11/08 09:54:56 mckusick 6 5
c special case EEXIST for ln -s
e
s 00003/00003/00079
d D 4.3 82/03/31 12:02:02 root 5 4
c dont need lstat any more
e
s 00017/00007/00065
d D 4.2 82/03/15 04:11:16 root 4 3
c symbolic links
e
s 00000/00000/00072
d D 4.1 80/10/01 16:38:58 bill 3 2
c Define 4.1
e
s 00033/00040/00039
d D 3.2 80/08/24 13:26:28 bill 2 1
c fixed several bugs
e
s 00079/00000/00000
d D 3.1 80/08/15 01:55:16 bill 1 0
c date and time created 80/08/15 01:55:16 by bill
e
u
U
t
T
I 1
D 11
static	char sccsid[] = "%Z%%M% %I% %G%";
E 11
I 11
D 12
static char sccsid[] = "%W% (Berkeley) %G%";
E 12
E 11
/*
D 2
 * ln [ -f ] file ... name
 *
 * name must be dir if more than one file given
E 2
I 2
D 12
 * ln
E 12
I 12
D 14
 * Copyright (c) 1987 Regents of the University of California.
E 14
I 14
 * Copyright (c) 1987 Regents of the University of California.
E 14
D 13
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 13
I 13
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 14
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific written prior permission. This software
 * is provided ``as is'' without express or implied warranty.
E 14
I 14
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
E 14
E 13
E 12
E 2
 */
D 2

E 2
D 12
#include <stdio.h>
#include <sys/types.h>
E 12
I 12

D 13
#ifndef	lint
E 13
I 13
#ifndef lint
E 13
char copyright[] =
D 14
"%Z% Copyright (c) 1987 Regents of the University of California.\n\
E 14
I 14
"%Z% Copyright (c) 1987 Regents of the University of California.\n\
E 14
 All rights reserved.\n";
D 13
#endif	/* !lint */
E 13
I 13
#endif /* not lint */
E 13

D 13
#ifndef	lint
E 13
I 13
#ifndef lint
E 13
static char sccsid[] = "%W% (Berkeley) %G%";
D 13
#endif	/* !lint */
E 13
I 13
#endif /* not lint */
E 13

#include <sys/param.h>
E 12
#include <sys/stat.h>
I 12
#include <stdio.h>
E 12
I 6
#include <errno.h>
E 6

D 2
struct stat	stbuf;
E 2
I 2
D 12
struct	stat stb;
int	fflag;		/* force flag set? */
I 4
int	sflag;
E 4
char	name[BUFSIZ];
char	*rindex();
I 6
extern	int errno;
E 12
I 12
static int	fflag,				/* undocumented force flag */
		sflag,				/* symbolic, not hard, link */
		(*linkf)();			/* system link call */
E 12
E 6
E 2

D 2
int		fflag;		/* force flag set? */

char		_sobuf[BUFSIZ];

E 2
main(argc, argv)
D 2
register int	argc;
register char	*argv[];
E 2
I 2
D 12
	int argc;
	register char **argv;
E 12
I 12
	int	argc;
	char	**argv;
E 12
E 2
{
D 2
	register	i, r;
E 2
I 2
D 12
	register int i, r;
E 12
I 12
	extern int	optind;
	struct stat	buf;
	int	ch, exitval, link(), symlink();
	char	*sourcedir;
E 12
E 2

D 2
	if (argc > 1 && strcmp(argv[1], "-f") == 0) {
E 2
I 2
D 12
	argc--, argv++;
I 4
again:
E 4
	if (argc && strcmp(argv[0], "-f") == 0) {
E 2
		fflag++;
		argv++;
		argc--;
E 12
I 12
	while ((ch = getopt(argc, argv, "fs")) != EOF)
		switch((char)ch) {
		case 'f':
			fflag = 1;
			break;
		case 's':
			sflag = 1;
			break;
		case '?':
		default:
			usage();
		}

	argv += optind;
	argc -= optind;

	linkf = sflag ? symlink : link;

	switch(argc) {
	case 0:
		usage();
	case 1:				/* ln target */
		exit(linkit(argv[0], ".", 1));
	case 2:				/* ln target source */
		exit(linkit(argv[0], argv[1], 0));
	default:			/* ln target1 target2 directory */
		sourcedir = argv[argc - 1];
		if (stat(sourcedir, &buf)) {
			perror(sourcedir);
			exit(1);
		}
		if ((buf.st_mode & S_IFMT) != S_IFDIR)
			usage();
		for (exitval = 0; *argv != sourcedir; ++argv)
			exitval |= linkit(*argv, sourcedir, 1);
		exit(exitval);
E 12
	}
I 4
D 12
	if (argc && strcmp(argv[0], "-s") == 0) {
		sflag++;
		argv++;
		argc--;
	}
E 4
D 2
	if (argc < 2) 
E 2
I 2
	if (argc == 0) 
E 2
		goto usage;
D 2
	else if (argc == 2)
E 2
I 2
	else if (argc == 1) {
E 2
		argv[argc] = ".";
D 2
	if (argc > 3) {
		if (stat(argv[argc-1], &stbuf) < 0)
E 2
I 2
		argc++;
	}
D 4
	if (argc > 2) {
		if (stat(argv[argc-1], &stb) < 0)
E 4
I 4
D 11
	if (sflag == 0 && argc > 2) {
E 11
I 11
	if (argc > 2) {
E 11
D 5
		if (lstat(argv[argc-1], &stb) < 0)
E 5
I 5
		if (stat(argv[argc-1], &stb) < 0)
E 5
E 4
E 2
			goto usage;
D 2
		if ((stbuf.st_mode&S_IFMT) != S_IFDIR) 
E 2
I 2
		if ((stb.st_mode&S_IFMT) != S_IFDIR) 
E 2
			goto usage;
	}
	r = 0;
D 2
	for(i=1; i<argc-1;i++)
E 2
I 2
	for(i = 0; i < argc-1; i++)
E 2
		r |= linkit(argv[i], argv[argc-1]);
	exit(r);
usage:
D 2
	fprintf(stderr, "Usage: ln: f1 f2; or ln f1 ... fn d2\n");
E 2
I 2
D 4
	fprintf(stderr, "Usage: ln f1\nor: ln f1 f2\nln f1 ... fn d2\n");
E 4
I 4
	fprintf(stderr, "Usage: ln [ -s ] f1\nor: ln [ -s ] f1 f2\nln [ -s ] f1 ... fn d2\n");
E 4
E 2
	exit(1);
E 12
I 12
	/*NOTREACHED*/
E 12
}

I 4
D 12
int	link(), symlink();

E 4
linkit(from, to)
D 2
register char	*from, *to;
E 2
I 2
	char *from, *to;
E 12
I 12
static
linkit(target, source, isdir)
	char	*target, *source;
	int	isdir;
E 12
E 2
{
D 2
	register char	*p1, *p2, *bp;
E 2
I 2
D 12
	char *tail;
I 4
	int (*linkf)() = sflag ? symlink : link;
E 12
I 12
	extern int	errno;
	struct stat	buf;
	char	path[MAXPATHLEN],
		*cp, *rindex(), *strcpy();
E 12
E 4
E 2

D 12
	/* is target a directory? */
D 2
	if (fflag == 0 && stat(from, &stbuf) >= 0
	    && (stbuf.st_mode&S_IFMT) == S_IFDIR) {
E 2
I 2
D 4
	if (fflag == 0 && stat(from, &stb) >= 0
E 4
I 4
D 5
	if (sflag == 0 && fflag == 0 && lstat(from, &stb) >= 0
E 5
I 5
	if (sflag == 0 && fflag == 0 && stat(from, &stb) >= 0
E 5
E 4
	    && (stb.st_mode&S_IFMT) == S_IFDIR) {
E 2
		printf("%s is a directory\n", from);
D 2
		return 1;
E 2
I 2
		return (1);
E 12
I 12
	if (!sflag) {
		/* if target doesn't exist, quit now */
		if (stat(target, &buf)) {
			perror(target);
			return(1);
		}
		/* only symbolic links to directories, unless -f option used */
		if (!fflag && (buf.st_mode & S_IFMT) == S_IFDIR) {
			printf("%s is a directory.\n", target);
			return(1);
		}
E 12
E 2
	}
D 2
	if (stat(to, &stbuf) >=0 && (stbuf.st_mode&S_IFMT) == S_IFDIR) {
		p1 = from;
		p2 = to;
		bp = _sobuf;
		while(*bp++ = *p2++)
			continue;
		bp[-1] = '/';
		p2 = bp;
		while(*bp = *p1++)
			if (*bp++ == '/')
				bp = p2;
		to = _sobuf;
E 2
I 2
D 4
	if (stat(to, &stb) >=0 && (stb.st_mode&S_IFMT) == S_IFDIR) {
E 4
I 4
D 5
	if (lstat(to, &stb) >= 0 && (stb.st_mode&S_IFMT) == S_IFDIR) {
E 5
I 5
D 12
	if (stat(to, &stb) >= 0 && (stb.st_mode&S_IFMT) == S_IFDIR) {
E 5
E 4
		tail = rindex(from, '/');
		if (tail == 0)
			tail = from;
E 12
I 12

	/* if the source is a directory, append the target's name */
	if (isdir || !stat(source, &buf) && (buf.st_mode & S_IFMT) == S_IFDIR) {
		if (!(cp = rindex(target, '/')))
			cp = target;
E 12
		else
D 12
			tail++;
D 9
		sprintf(name, "%s/%s", to, tail);
E 9
I 9
		(void)sprintf(name, "%s/%s", to, tail);
E 9
		to = name;
E 12
I 12
			++cp;
		(void)sprintf(path, "%s/%s", source, cp);
		source = path;
E 12
E 2
	}
D 2
	else
		p1 = NULL;
E 2
D 4
	if (link(from, to) < 0) {
E 4
I 4
D 12
	if ((*linkf)(from, to) < 0) {
E 4
D 6
		perror(from);
E 6
I 6
D 8
		if (errno == EEXIST)
E 8
I 8
		if (errno == EEXIST || sflag)
E 8
			perror(to);
D 7
		else
E 7
I 7
		else if (access(from, 0) < 0)
E 7
			perror(from);
I 7
		else
			perror(to);
E 7
E 6
D 2
		return 1;
E 2
I 2
		return (1);
E 12
I 12

	if ((*linkf)(target, source)) {
		perror(source);
		return(1);
E 12
E 2
	}
D 4
	return(0);
E 4
I 4
D 12
	return (0);
E 12
I 12
	return(0);
}

static
usage()
{
	fputs("usage:\tln [-s] targetname [sourcename]\n\tln [-s] targetname1 targetname2 [... targetnameN] sourcedirectory\n", stderr);
	exit(1);
E 12
E 4
}
E 1
