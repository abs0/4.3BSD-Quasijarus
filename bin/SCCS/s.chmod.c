h36919
s 00076/00131/00177
d D 5.7 88/04/21 11:37:37 bostic 12 11
c add getopt; clean up tree traversal; lint cleanups
e
s 00001/00001/00307
d D 5.6 87/12/21 12:30:57 bostic 11 10
c make ANSI C compatible; besides, structs don't fit in registers...
e
s 00027/00015/00281
d D 5.5 86/05/22 11:04:36 mckusick 10 9
c do not follow symbolic links; clarify error messages
e
s 00121/00077/00175
d D 5.4 85/08/31 17:44:44 sam 9 8
c add -f flag for install; cleanup -R code
e
s 00003/00002/00249
d D 5.3 85/06/18 12:58:48 mckusick 8 7
c fix mode propagation
e
s 00004/00007/00247
d D 5.2 85/06/09 12:08:42 mckusick 7 6
c make ``chmod -x ...'' work right
e
s 00009/00001/00245
d D 5.1 85/04/30 14:50:10 dist 6 5
c Add copyright
e
s 00013/00019/00233
d D 4.5 85/03/20 16:58:34 mckusick 5 4
c delete -X flag; replace with X mode to indicate conditional execute setting
e
s 00005/00002/00247
d D 4.4 84/06/18 14:54:22 ralph 4 3
c chmod follows links so don't use lstat.
e
s 00015/00006/00234
d D 4.3 84/03/31 21:43:20 layer 3 2
c -X flag:  set execute bits if set anywhere in mode
e
s 00000/00002/00240
d D 4.2 84/03/28 21:02:45 layer 2 1
c Don't fiddle with the modes with the -R flag...
e
s 00242/00000/00000
d D 4.1 84/03/26 15:26:11 layer 1 0
c date and time created 84/03/26 15:26:11 by layer
e
u
U
t
T
I 1
D 6
static char *sccsid = "%W% %G%";
E 6
I 6
/*
D 12
 * Copyright (c) 1980 Regents of the University of California.
E 12
I 12
 * Copyright (c) 1980, 1988 Regents of the University of California.
E 12
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
I 12
char copyright[] =
"%Z% Copyright (c) 1980, 1988 Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */

#ifndef lint
E 12
static char sccsid[] = "%W% (Berkeley) %G%";
D 9
#endif not lint
E 9
I 9
D 12
#endif
E 12
I 12
#endif /* not lint */
E 12
E 9
E 6

/*
 * chmod options mode files
 * where
D 5
 *	mode	is [ugoa][+-=][rwxstugo] or a octal number
E 5
I 5
D 9
 *	mode	is [ugoa][+-=][rwxXstugo] or a octal number
E 5
 *	options are -R
E 9
I 9
 *	mode is [ugoa][+-=][rwxXstugo] or an octal number
 *	options are -Rf
E 9
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/dir.h>

D 9
#define	USER	05700	/* user's bits */
#define	GROUP	02070	/* group's bits */
#define	OTHER	00007	/* other's bits */
#define	ALL	01777	/* all (note absence of setuid, etc) */

#define	READ	00444	/* read permit */
#define	WRITE	00222	/* write permit */
#define	EXEC	00111	/* exec permit */
#define	SETID	06000	/* set[ug]id */
#define	STICKY	01000	/* sticky bit */

E 9
D 12
char	*modestring, *ms;
int	um;
int	status;
D 3
int	rflag = 0, debug = 0;
E 3
I 3
D 5
int	rflag, debug, Xflag;
E 5
I 5
D 9
int	rflag, debug;
E 9
I 9
int	fflag;
int	rflag;
E 12
I 12
static int	fflag, rflag, retval, um;
static char	*modestring, *ms;
E 12
E 9
E 5
E 3

D 9
main(argc,argv)
char **argv;
E 9
I 9
main(argc, argv)
D 12
	char *argv[];
E 12
I 12
	int argc;
	char **argv;
E 12
E 9
{
D 9
	register i;
E 9
D 3
	register char *p;
E 3
I 3
D 12
	register char *p, *flags;
E 3
D 9
	struct	stat st;
E 9
I 9
	register int i;
	struct stat st;
E 12
I 12
	extern char *optarg;
	extern int optind, opterr;
	int ch;
E 12
E 9

I 5
D 9
usage:
E 9
E 5
D 12
	if (argc < 3) {
D 9
		fprintf(stderr
D 3
			,"Usage: chmod [-R] [ugoa][+-=][rwxstugo] file ...\n");
E 3
I 3
D 5
			,"Usage: chmod [-RX] [ugoa][+-=][rwxstugo] file ...\n");
E 5
I 5
			,"Usage: chmod [-R] [ugoa][+-=][rwxXstugo] file ...\n");
E 9
I 9
		fprintf(stderr,
		    "Usage: chmod [-Rf] [ugoa][+-=][rwxXstugo] file ...\n");
E 9
E 5
E 3
		exit(-1);
	}
I 3
D 9

E 9
E 3
	argv++, --argc;
D 3
	if (strcmp(argv[0], "-R") == 0) {
		rflag++;
		argv++, --argc;
E 3
I 3
D 9
	if (*argv[0] == '-') {
D 7
		for (flags = argv[0]; *flags; ++flags)
			switch (*flags) {
			  case '-':			break;
			  case 'R':	rflag++;	break;
D 5
			  case 'X': 	Xflag++;	break;
E 5
I 5
			  default: 	argc = 0;	goto usage;
E 5
			}
		argv++, argc--;
E 7
I 7
		if (strcmp(argv[0], "-R") == 0) {
E 9
I 9
	while (argc > 0 && argv[0][0] == '-') {
		for (p = &argv[0][1]; *p; p++) switch (*p) {

E 12
I 12
	/*
	 * since "-[rwx]" etc. are valid file modes, we don't let getopt(3)
	 * print error messages, and we mess around with optind as necessary.
	 */
	opterr = 0;
	while ((ch = getopt(argc, argv, "Rf")) != EOF)
		switch((char)ch) {
E 12
		case 'R':
E 9
			rflag++;
D 9
			argv++, argc--;
E 9
I 9
			break;
D 12

E 12
		case 'f':
			fflag++;
			break;
D 12

E 12
I 12
		case '?':
E 12
		default:
I 12
			--optind;
E 12
			goto done;
E 9
		}
I 9
D 12
		argc--, argv++;
E 12
I 12
done:	argv += optind;
	argc -= optind;

	if (argc < 2) {
		fputs("usage: chmod [-Rf] [ugoa][+-=][rwxXstugo] file ...\n",
		    stderr);
		exit(-1);
E 12
E 9
E 7
E 3
	}
I 3
D 9

E 9
I 9
D 12
done:
E 9
E 3
	modestring = argv[0];
E 12
I 12

	modestring = *argv;
E 12
D 9

E 9
	um = umask(0);
D 12
	(void) newmode(0);
	for (i = 1; i < argc; i++) {
		p = argv[i];
I 9
		/* do stat for directory arguments */
E 9
D 4
		if (lstat(p, &st) < 0) {
E 4
I 4
D 10
		if (stat(p, &st) < 0) {
E 4
D 9
			fprintf(stderr, "chmod: can't access %s\n", p);
			++status;
E 9
I 9
			status += error("can't access %s", p);
E 10
I 10
		if (lstat(p, &st) < 0) {
			status += Perror(p);
E 10
E 9
			continue;
		}
D 9
		if (rflag && st.st_mode & S_IFDIR) {
E 9
I 9
D 10
		if (rflag && st.st_mode&S_IFDIR) {
E 10
I 10
		if (rflag && (st.st_mode&S_IFMT) == S_IFDIR) {
E 10
E 9
			status += chmodr(p, newmode(st.st_mode));
D 9
		} else if (chmod(p, newmode(st.st_mode)) < 0) {
			fprintf(stderr, "chmod: can't change %s\n", p);
			++status;
E 9
			continue;
		}
I 10
		if ((st.st_mode&S_IFMT) == S_IFLNK && stat(p, &st) < 0) {
			status += Perror(p);
			continue;
		}
E 10
I 9
		if (chmod(p, newmode(st.st_mode)) < 0) {
D 10
			status += error("can't change %s", p);
E 10
I 10
			status += Perror(p);
E 10
			continue;
		}
E 9
	}
	exit(status);
E 12
I 12
	(void)newmode((u_short)0);

	while (*++argv)
		change(*argv);
	exit(retval);
E 12
}

D 12
chmodr(dir, mode)
D 9
	char	*dir;
E 9
I 9
	char *dir;
E 12
I 12
change(file)
	char *file;
E 12
E 9
{
D 5
#define CHECK(name,sbuf)\
D 4
	if (lstat(name, sbuf) < 0) {\
E 4
I 4
	if (stat(name, sbuf) < 0) {\
E 4
		fprintf(stderr, "chmod: can't access %s\n", dp->d_name);\
		return(1);\
	}
	
E 5
D 9
	register DIR		*dirp;
	register struct direct	*dp;
	register struct stat	st;
	char			savedir[1024];
E 9
I 9
	register DIR *dirp;
	register struct direct *dp;
D 11
	register struct stat st;
E 11
I 11
D 12
	struct stat st;
E 11
	char savedir[1024];
	int ecode;
E 12
I 12
	struct stat buf;
E 12
E 9

D 9
	if (getwd(savedir) == 0) {
		fprintf(stderr, "chmod: %s\n", savedir);
		exit(255);
	}

E 9
I 9
D 12
	if (getwd(savedir) == 0)
		fatal(255, "%s", savedir);
E 9
	/*
D 9
	** chmod what we are given before doing it's contents
	*/
	chmod(dir, newmode(mode));
	
	chdir(dir);
	if ((dirp = opendir(".")) == NULL) {
		perror(dir);
		return(1);
	}
E 9
I 9
	 * Change what we are given before doing it's contents
	 */
D 10
	if (chmod(dir, newmode(mode)) < 0 && error("can't change %s", dir))
E 10
I 10
	if (chmod(dir, newmode(mode)) < 0 && Perror(dir))
E 10
		return (1);
D 10
	if (chdir(dir) < 0)
		return (Perror(dir));
	if ((dirp = opendir(".")) == NULL)
		return (Perror(dir));
E 10
I 10
	if (chdir(dir) < 0) {
		Perror(dir);
		return (1);
E 12
I 12
	if (lstat(file, &buf) || chmod(file, newmode(buf.st_mode))) {
		err(file);
		return;
E 12
	}
D 12
	if ((dirp = opendir(".")) == NULL) {
		Perror(dir);
		return (1);
	}
E 10
E 9
	dp = readdir(dirp);
	dp = readdir(dirp); /* read "." and ".." */
I 9
	ecode = 0;
E 9
	for (dp = readdir(dirp); dp != NULL; dp = readdir(dirp)) {
D 5
		CHECK(dp->d_name, &st);
E 5
I 5
D 9
		if (stat(dp->d_name, &st) < 0) {
			fprintf(stderr, "chmod: can't access %s\n", dp->d_name);
			return(1);
E 9
I 9
		if (lstat(dp->d_name, &st) < 0) {
D 10
			ecode = error("can't access %s", dp->d_name);
E 10
I 10
			ecode = Perror(dp->d_name);
E 10
			if (ecode)
				break;
			continue;
E 12
I 12
	if (rflag && ((buf.st_mode & S_IFMT) == S_IFDIR)) {
		if (chdir(file) < 0 || !(dirp = opendir("."))) {
			err(file);
			return;
E 12
E 9
		}
E 5
D 8
		chmod(dp->d_name, newmode(st.st_mode));
E 8
D 9
		if (st.st_mode & S_IFDIR)
D 8
			chmodr(dp->d_name, mode);
E 8
I 8
			chmodr(dp->d_name, newmode(st.st_mode));
		else
			chmod(dp->d_name, newmode(st.st_mode));
E 9
I 9
D 10
		if (st.st_mode&S_IFDIR) {
E 10
I 10
D 12
		if ((st.st_mode&S_IFMT) == S_IFDIR) {
E 10
			ecode = chmodr(dp->d_name, newmode(st.st_mode));
			if (ecode)
				break;
			continue;
E 12
I 12
		for (dp = readdir(dirp); dp; dp = readdir(dirp)) {
			if (dp->d_name[0] == '.' && (!dp->d_name[1] ||
			    dp->d_name[1] == '.' && !dp->d_name[2]))
				continue;
			change(dp->d_name);
E 12
		}
I 10
D 12
		if ((st.st_mode&S_IFMT) == S_IFLNK)
			continue;
E 10
		if (chmod(dp->d_name, newmode(st.st_mode)) < 0 &&
D 10
		    (ecode = error("can't change %s", dp->d_name)))
E 10
I 10
		    (ecode = Perror(dp->d_name)))
E 10
			break;
E 12
I 12
		closedir(dirp);
		if (chdir("..")) {
			err("..");
			exit(fflag ? 0 : -1);
		}
E 12
E 9
E 8
	}
D 12
	closedir(dirp);
D 9
	chdir(savedir);
	return(0);
E 9
I 9
	if (chdir(savedir) < 0)
		fatal(255, "can't change back to %s", savedir);
	return (ecode);
E 12
E 9
}

I 9
D 12
error(fmt, a)
	char *fmt, *a;
{

	if (!fflag) {
		fprintf(stderr, "chmod: ");
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
E 12
I 12
err(s)
E 12
	char *s;
{
D 12

D 10
	fprintf(stderr, "chmod: ");
	perror(s);
	return (1);
E 10
I 10
	if (!fflag) {
		fprintf(stderr, "chmod: ");
		perror(s);
	}
	return (!fflag);
E 12
I 12
	if (fflag)
		return;
	fputs("chmod: ", stderr);
	perror(s);
	retval = -1;
E 12
E 10
}

E 9
newmode(nm)
D 9
unsigned nm;
E 9
I 9
D 12
	unsigned nm;
E 12
I 12
	u_short nm;
E 12
E 9
{
D 12
	register o, m, b;
	int savem;
E 12
I 12
	register int o, m, b;
E 12

	ms = modestring;
D 12
	savem = nm;
E 12
	m = abs();
D 5
	if (!*ms) {
		nm = m;
		goto ret;
	}
E 5
I 5
D 9
	if (!*ms)
		return(m);
E 9
I 9
	if (*ms == '\0')
		return (m);
E 9
E 5
	do {
		m = who();
		while (o = what()) {
D 12
			b = where(nm);
E 12
I 12
			b = where((int)nm);
E 12
			switch (o) {
			case '+':
				nm |= b & m;
				break;
			case '-':
				nm &= ~(b & m);
				break;
			case '=':
				nm &= ~m;
				nm |= b & m;
				break;
			}
		}
	} while (*ms++ == ',');
D 9
	if (*--ms) {
		fprintf(stderr, "chmod: invalid mode\n");
		exit(255);
	}
D 5
ret:
I 3
	if (Xflag && ((savem & S_IFDIR) || (savem & S_IEXEC)))
		nm = nm | ((nm & 0444) >> 2);
E 5
E 3
D 2
	if ((savem & S_IFDIR) || (savem & S_IEXEC))
		nm = nm | ((nm & 0444) >> 2);
E 2
	return(nm);
E 9
I 9
D 12
	if (*--ms)
		fatal(255, "invalid mode");
	return (nm);
E 12
I 12
	if (*--ms) {
		fputs("chmod: invalid mode.\n", stderr);
		exit(-1);
	}
	return ((int)nm);
E 12
E 9
}

abs()
{
D 12
	register c, i;
E 12
I 12
	register int c, i;
E 12

	i = 0;
	while ((c = *ms++) >= '0' && c <= '7')
		i = (i << 3) + (c - '0');
	ms--;
D 9
	return(i);
E 9
I 9
	return (i);
E 9
}

I 9
#define	USER	05700	/* user's bits */
#define	GROUP	02070	/* group's bits */
#define	OTHER	00007	/* other's bits */
#define	ALL	01777	/* all (note absence of setuid, etc) */

#define	READ	00444	/* read permit */
#define	WRITE	00222	/* write permit */
#define	EXEC	00111	/* exec permit */
#define	SETID	06000	/* set[ug]id */
#define	STICKY	01000	/* sticky bit */

E 9
who()
{
D 12
	register m;
E 12
I 12
	register int m;
E 12

	m = 0;
	for (;;) switch (*ms++) {
	case 'u':
		m |= USER;
		continue;
	case 'g':
		m |= GROUP;
		continue;
	case 'o':
		m |= OTHER;
		continue;
	case 'a':
		m |= ALL;
		continue;
	default:
		ms--;
		if (m == 0)
			m = ALL & ~um;
D 9
		return m;
E 9
I 9
		return (m);
E 9
	}
}

what()
{
D 12

E 12
	switch (*ms) {
	case '+':
	case '-':
	case '=':
D 9
		return *ms++;
E 9
I 9
		return (*ms++);
E 9
	}
D 9
	return(0);
E 9
I 9
	return (0);
E 9
}

where(om)
D 9
register om;
E 9
I 9
D 12
	register om;
E 12
I 12
	register int om;
E 12
E 9
{
D 12
	register m;
E 12
I 12
	register int m;
E 12

 	m = 0;
	switch (*ms) {
	case 'u':
		m = (om & USER) >> 6;
		goto dup;
	case 'g':
		m = (om & GROUP) >> 3;
		goto dup;
	case 'o':
		m = (om & OTHER);
	dup:
		m &= (READ|WRITE|EXEC);
		m |= (m << 3) | (m << 6);
		++ms;
D 9
		return m;
E 9
I 9
		return (m);
E 9
	}
	for (;;) switch (*ms++) {
	case 'r':
		m |= READ;
		continue;
	case 'w':
		m |= WRITE;
		continue;
	case 'x':
		m |= EXEC;
I 4
		continue;
	case 'X':
D 5
		Xflag++;
E 5
I 5
		if ((om & S_IFDIR) || (om & EXEC))
			m |= EXEC;
E 5
E 4
		continue;
	case 's':
		m |= SETID;
		continue;
	case 't':
		m |= STICKY;
		continue;
	default:
		ms--;
D 9
		return m;
E 9
I 9
		return (m);
E 9
	}
}
E 1
