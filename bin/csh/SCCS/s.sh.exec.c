h65211
s 00001/00001/00344
d D 5.4 88/05/19 15:38:39 bostic 15 14
c install C version of _doprnt
e
s 00002/00003/00343
d D 5.3 87/06/25 09:15:10 bostic 14 13
c csh long/int mismatches; bug report 4.3BSD/bin/45
e
s 00003/00003/00343
d D 5.2 85/06/06 13:08:31 edward 13 12
c cleaning up after bozos
e
s 00008/00002/00338
d D 5.1 85/06/04 10:57:16 dist 12 11
c Add copyright
e
s 00001/00000/00339
d D 4.11 85/02/28 11:13:39 karels 11 10
c missing initialization
e
s 00065/00042/00274
d D 4.10 84/12/13 14:39:02 edward 10 9
c performance
e
s 00000/00000/00316
d D 4.9 84/08/31 09:30:55 ralph 9 8
c use new signal calls instead of compatibility routines.
e
s 00001/00001/00315
d D 4.8 83/07/01 03:50:55 sam 8 7
c include fix
e
s 00004/00002/00312
d D 4.7 83/06/11 16:49:06 sam 7 6
c different approach, try signal compatibility package
e
s 00003/00002/00311
d D 4.6 83/06/10 23:58:59 sam 6 5
c new signals; no libjobs; still loses SIGINT by getting it masked 
c sometimes, but we check it in before we lose something
e
s 00000/00000/00313
d D 4.5 82/12/30 17:34:53 sam 5 4
c finally works (updated for 4.1c and merged with sun)
e
s 00001/00001/00312
d D 4.4 82/05/07 18:20:29 mckusick 4 3
c update to new fs
e
s 00013/00017/00300
d D 4.3 82/02/12 15:29:51 mckusic 3 2
c convret to new directory format
e
s 00001/00000/00316
d D 4.2 81/08/20 23:48:28 mckusic 2 1
c save history on "exec command
e
s 00316/00000/00000
d D 4.1 80/10/09 12:40:50 bill 1 0
c date and time created 80/10/09 12:40:50 by bill
e
u
U
t
T
I 12
/*
 * Copyright (c) 1980 Regents of the University of California.
D 13
 * All rights reserved.  The Berkeley software License Agreement
E 13
I 13
 * All rights reserved.  The Berkeley Software License Agreement
E 13
 * specifies the terms and conditions for redistribution.
 */

E 12
I 1
D 10
static	char *sccsid = "%Z%%M% %I% %G%";
E 10
I 10
#ifndef lint
D 12
static	char *sccsid = "%W% (Berkeley) %G%";
#endif
E 12
I 12
D 13
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 13
I 13
static char *sccsid = "%W% (Berkeley) %G%";
#endif
E 13
E 12
E 10

#include "sh.h"
I 3
D 4
#include <ndir.h>
E 4
I 4
D 8
#include <dir.h>
E 8
I 8
#include <sys/dir.h>
E 8
E 4
E 3

/*
 * C shell
 */

/*
 * System level search and execute of a command.
 * We look in each directory for the specified command name.
 * If the name contains a '/' then we execute only the full path name.
 * If there is no search path then we execute only full path names.
 */

/* 
 * As we search for the command we note the first non-trivial error
 * message for presentation to the user.  This allows us often
 * to show that a file has the wrong mode/no access when the file
 * is not in the last component of the search path, so we must
 * go on after first detecting the error.
 */
char	*exerr;			/* Execution error message */
char	*expath;		/* Path for exerr */

/*
D 10
 * Xhash is an array of HSHSIZ chars, which are used to hash execs.
 * If it is allocated, then to tell whether ``name'' is (possibly)
 * present in the i'th component of the variable path, you look at
 * the i'th bit of xhash[hash("name")].  This is setup automatically
E 10
I 10
 * Xhash is an array of HSHSIZ bits (HSHSIZ / 8 chars), which are used
 * to hash execs.  If it is allocated (havhash true), then to tell
 * whether ``name'' is (possibly) present in the i'th component
 * of the variable path, you look at the bit in xhash indexed by
 * hash(hashname("name"), i).  This is setup automatically
E 10
 * after .login is executed, and recomputed whenever ``path'' is
 * changed.
I 10
 * The two part hash function is designed to let texec() call the
 * more expensive hashname() only once and the simple hash() several
 * times (once for each path component checked).
 * Byte size is assumed to be 8.
E 10
 */
D 10
int	havhash;
#define	HSHSIZ	511
char	xhash[HSHSIZ];
E 10
I 10
#define	HSHSIZ		8192			/* 1k bytes */
#define HSHMASK		(HSHSIZ - 1)
#define HSHMUL		243
char	xhash[HSHSIZ / 8];
#define hash(a, b)	((a) * HSHMUL + (b) & HSHMASK)
#define bit(h, b)	((h)[(b) >> 3] & 1 << ((b) & 7))	/* bit test */
#define bis(h, b)	((h)[(b) >> 3] |= 1 << ((b) & 7))	/* bit set */
E 10
#ifdef VFORK
int	hits, misses;
#endif

/* Dummy search path for just absolute search when no path */
char	*justabs[] =	{ "", 0 };

doexec(t)
	register struct command *t;
{
	char *sav;
	register char *dp, **pv, **av;
	register struct varent *v;
	bool slash = any('/', t->t_dcom[0]);
D 10
	int hashval, i;
E 10
I 10
	int hashval, hashval1, i;
E 10
	char *blk[2];

	/*
	 * Glob the command name.  If this does anything, then we
	 * will execute the command only relative to ".".  One special
	 * case: if there is no PATH, then we execute only commands
	 * which start with '/'.
	 */
	dp = globone(t->t_dcom[0]);
	sav = t->t_dcom[0];
	exerr = 0; expath = t->t_dcom[0] = dp;
	xfree(sav);
	v = adrof("path");
	if (v == 0 && expath[0] != '/')
		pexerr();
	slash |= gflag;

	/*
	 * Glob the argument list, if necessary.
	 * Otherwise trim off the quote bits.
	 */
	gflag = 0; av = &t->t_dcom[1];
D 10
	rscan(av, tglob);
E 10
I 10
	tglob(av);
E 10
	if (gflag) {
		av = glob(av);
		if (av == 0)
			error("No match");
	}
	blk[0] = t->t_dcom[0];
	blk[1] = 0;
	av = blkspl(blk, av);
#ifdef VFORK
	Vav = av;
#endif
D 10
	scan(av, trim);
E 10
I 10
	trim(av);
E 10

	xechoit(av);		/* Echo command if -x */
D 10
	closech();		/* Close random fd's */
E 10
I 10
	/*
	 * Since all internal file descriptors are set to close on exec,
	 * we don't need to close them explicitly here.  Just reorient
	 * ourselves for error messages.
	 */
	SHIN = 0; SHOUT = 1; SHDIAG = 2; OLDSTD = 0;
E 10

	/*
D 6
	 * We must do this after any possible forking (like `foo`
E 6
I 6
	 * We must do this AFTER any possible forking (like `foo`
E 6
	 * in glob) so that this shell can still do subprocesses.
	 */
D 6
	sigsys(SIGCHLD, SIG_IGN);	/* sigsys for vforks sake */
E 6
I 6
D 7
	signal(SIGCHLD, SIG_IGN);
	sigsetmask(0);			/* sanity */
E 7
I 7
D 10
#ifdef notdef
	sigsys(SIGCHLD, SIG_IGN);	/* sigsys for vforks sake */
#endif
	sigsetmask(0);
E 10
I 10
D 14
	(void) sigsetmask(0);
E 14
I 14
	(void) sigsetmask(0L);
E 14
E 10
E 7
E 6

	/*
	 * If no path, no words in path, or a / in the filename
	 * then restrict the command search.
	 */
	if (v == 0 || v->vec[0] == 0 || slash)
		pv = justabs;
	else
		pv = v->vec;
	sav = strspl("/", *av);		/* / command name for postpending */
#ifdef VFORK
	Vsav = sav;
#endif
	if (havhash)
D 10
		hashval = xhash[hash(*av)];
E 10
I 10
		hashval = hashname(*av);
E 10
	i = 0;
#ifdef VFORK
	hits++;
#endif
	do {
D 10
		if (!slash && pv[0][0] == '/' && havhash && (hashval & (1 << (i % 8))) == 0)
			goto cont;
E 10
I 10
		if (!slash && pv[0][0] == '/' && havhash) {
			hashval1 = hash(hashval, i);
			if (!bit(xhash, hashval1))
				goto cont;
		}
E 10
		if (pv[0][0] == 0 || eq(pv[0], "."))	/* don't make ./xxx */
			texec(*av, av);
		else {
			dp = strspl(*pv, sav);
#ifdef VFORK
			Vdp = dp;
#endif
			texec(dp, av);
#ifdef VFORK
			Vdp = 0;
#endif
			xfree(dp);
		}
#ifdef VFORK
		misses++;
#endif
cont:
		pv++;
		i++;
	} while (*pv);
#ifdef VFORK
	hits--;
#endif
#ifdef VFORK
	Vsav = 0;
	Vav = 0;
#endif
	xfree(sav);
D 10
	xfree(av);
E 10
I 10
	xfree((char *)av);
E 10
	pexerr();
}

pexerr()
{

	/* Couldn't find the damn thing */
	setname(expath);
	/* xfree(expath); */
	if (exerr)
		bferr(exerr);
	bferr("Command not found");
}

D 10
/* Last resort shell */
char	*lastsh[] =	{ SHELLPATH, 0 };

E 10
/*
 * Execute command f, arg list t.
 * Record error message if not found.
 * Also do shell scripts here.
 */
texec(f, t)
	char *f;
	register char **t;
{
	register struct varent *v;
	register char **vp;
	extern char *sys_errlist[];
I 10
	char *lastsh[2];
E 10

	execv(f, t);
	switch (errno) {

	case ENOEXEC:
		/*
		 * If there is an alias for shell, then
		 * put the words of the alias in front of the
		 * argument list replacing the command name.
		 * Note no interpretation of the words at this point.
		 */
		v = adrof1("shell", &aliases);
		if (v == 0) {
#ifdef OTHERSH
			register int ff = open(f, 0);
			char ch;
#endif

			vp = lastsh;
			vp[0] = adrof("shell") ? value("shell") : SHELLPATH;
I 11
			vp[1] = (char *) NULL;
E 11
#ifdef OTHERSH
			if (ff != -1 && read(ff, &ch, 1) == 1 && ch != '#')
				vp[0] = OTHERSH;
D 10
			close(ff);
E 10
I 10
			(void) close(ff);
E 10
#endif
		} else
			vp = v->vec;
		t[0] = f;
		t = blkspl(vp, t);		/* Splice up the new arglst */
		f = *t;
		execv(f, t);
		xfree((char *)t);
		/* The sky is falling, the sky is falling! */

	case ENOMEM:
		Perror(f);

	case ENOENT:
		break;

	default:
		if (exerr == 0) {
			exerr = sys_errlist[errno];
			expath = savestr(f);
		}
	}
}

I 10
/*ARGSUSED*/
E 10
execash(t, kp)
I 10
	char **t;
E 10
	register struct command *kp;
{

D 10
	didcch++;
E 10
I 2
	rechist();
E 2
D 10
	signal(SIGINT, parintr);
	signal(SIGQUIT, parintr);
	signal(SIGTERM, parterm);		/* if doexec loses, screw */
E 10
I 10
	(void) signal(SIGINT, parintr);
	(void) signal(SIGQUIT, parintr);
	(void) signal(SIGTERM, parterm);	/* if doexec loses, screw */
E 10
	lshift(kp->t_dcom, 1);
	exiterr++;
	doexec(kp);
	/*NOTREACHED*/
}

xechoit(t)
	char **t;
{

	if (adrof("echo")) {
		flush();
		haderr = 1;
D 10
		blkpr(t), printf("\n");
E 10
I 10
D 15
		blkpr(t), putchar('\n');
E 15
I 15
		blkpr(t), cshputchar('\n');
E 15
E 10
		haderr = 0;
	}
}

D 10
dohash()
E 10
I 10
/*VARARGS0*//*ARGSUSED*/
D 14
dohash(v)
	char **v;
E 14
I 14
dohash()
E 14
E 10
{
	struct stat stb;
D 3
	struct direct dirbuf[BUFSIZ / sizeof (struct direct)];
	char d_name[DIRSIZ + 1];
	register int dirf, cnt;
E 3
I 3
	DIR *dirp;
	register struct direct *dp;
	register int cnt;
E 3
	int i = 0;
	struct varent *v = adrof("path");
	char **pv;
I 10
	int hashval;
E 10

	havhash = 1;
D 10
	for (cnt = 0; cnt < HSHSIZ; cnt++)
E 10
I 10
	for (cnt = 0; cnt < sizeof xhash; cnt++)
E 10
		xhash[cnt] = 0;
	if (v == 0)
		return;
D 10
	for (pv = v->vec; *pv; pv++, i = (i + 1) % 8) {
E 10
I 10
	for (pv = v->vec; *pv; pv++, i++) {
E 10
		if (pv[0][0] != '/')
			continue;
D 3
		dirf = open(*pv, 0);
		if (dirf < 0)
E 3
I 3
		dirp = opendir(*pv);
		if (dirp == NULL)
E 3
			continue;
D 3
		if (fstat(dirf, &stb) < 0 || !isdir(stb)) {
			close(dirf);
E 3
I 3
		if (fstat(dirp->dd_fd, &stb) < 0 || !isdir(stb)) {
			closedir(dirp);
E 3
			continue;
		}
D 3
		while ((cnt = read(dirf, (char *) dirbuf, sizeof dirbuf)) >= sizeof dirbuf[0]) {
			register struct direct *ep = dirbuf;

			for (cnt /= sizeof(struct direct); cnt > 0; cnt--, ep++) {
				if (ep->d_ino == 0)
					continue;
				copdent(d_name, ep->d_name);
				xhash[hash(d_name)] |= (1 << i);
			}
E 3
I 3
		while ((dp = readdir(dirp)) != NULL) {
			if (dp->d_ino == 0)
				continue;
D 10
			xhash[hash(dp->d_name)] |= (1 << i);
E 10
I 10
			if (dp->d_name[0] == '.' &&
			    (dp->d_name[1] == '\0' ||
			     dp->d_name[1] == '.' && dp->d_name[2] == '\0'))
				continue;
			hashval = hash(hashname(dp->d_name), i);
			bis(xhash, hashval);
E 10
E 3
		}
D 3
		close(dirf);
E 3
I 3
		closedir(dirp);
E 3
	}
}

dounhash()
{

	havhash = 0;
}

#ifdef VFORK
hashstat()
{

	if (hits+misses)
D 10
	printf("%d hits, %d misses, %2d%%\n", hits, misses, 100 * hits / (hits + misses));
E 10
I 10
		printf("%d hits, %d misses, %d%%\n",
			hits, misses, 100 * hits / (hits + misses));
E 10
}
#endif

D 10
hash(cp)
E 10
I 10
/*
 * Hash a command name.
 */
hashname(cp)
E 10
	register char *cp;
{
D 10
	register long hash = 0;
	int retval;
E 10
I 10
	register long h = 0;
E 10

	while (*cp)
D 10
		hash += hash + *cp++;
	if (hash < 0)
		hash = -hash;
	retval = hash % HSHSIZ;
	return (retval);
E 10
I 10
		h = hash(h, *cp++);
	return ((int) h);
E 10
}
E 1
