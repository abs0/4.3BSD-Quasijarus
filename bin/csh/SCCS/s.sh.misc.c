h51269
s 00003/00026/00380
d D 5.3 86/03/29 07:37:21 lepreau 7 6
c Minor speedups & cleanups:
c replace letter() et al with ctype-like cmap macros and expand cmap to short
c for new LET and DIG bits; use bzero in private calloc; make btell a macro.
e
s 00003/00003/00403
d D 5.2 85/06/06 13:10:06 edward 6 5
c cleaning up after bozos
e
s 00008/00002/00398
d D 5.1 85/06/04 11:05:44 dist 5 4
c Add copyright
e
s 00096/00063/00304
d D 4.4 84/12/13 14:40:33 edward 4 3
c performance
e
s 00000/00007/00367
d D 4.3 84/08/31 09:31:25 ralph 3 2
c use new signal calls instead of compatibility routines.
e
s 00002/00000/00372
d D 4.2 84/07/06 22:41:52 sam 2 1
c turn copy() into bcopy(); fix up profiling
e
s 00372/00000/00000
d D 4.1 80/10/09 12:41:25 bill 1 0
c date and time created 80/10/09 12:41:25 by bill
e
u
U
t
T
I 5
/*
 * Copyright (c) 1980 Regents of the University of California.
D 6
 * All rights reserved.  The Berkeley software License Agreement
E 6
I 6
 * All rights reserved.  The Berkeley Software License Agreement
E 6
 * specifies the terms and conditions for redistribution.
 */

E 5
I 1
D 4
static	char *sccsid = "%Z%%M% %I% %G%";
E 4
I 4
#ifndef lint
D 5
static	char *sccsid = "%W% (Berkeley) %G%";
#endif
E 5
I 5
D 6
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 6
I 6
static char *sccsid = "%W% (Berkeley) %G%";
#endif
E 6
E 5
E 4

#include "sh.h"

/*
 * C Shell
 */

D 7
letter(c)
	register char c;
{

	return (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c == '_');
}

digit(c)
	register char c;
{

	return (c >= '0' && c <= '9');
}

alnum(c)
	register char c;
{
	return (letter(c) || digit(c));
}

E 7
any(c, s)
	register int c;
	register char *s;
{

	while (*s)
		if (*s++ == c)
			return(1);
	return(0);
}

I 4
onlyread(cp)
	char *cp;
{
	extern char end[];

	return (cp < end);
}

xfree(cp)
	char *cp;
{
	extern char end[];

	if (cp >= end && cp < (char *) &cp)
		free(cp);
}

E 4
char *
I 4
savestr(s)
	register char *s;
{
	char *n;
	register char *p;

	if (s == 0)
		s = "";
	for (p = s; *p++;)
		;
	n = p = xalloc((unsigned) (p - s));
	while (*p++ = *s++)
		;
	return (n);
}

char *
E 4
calloc(i, j)
	register unsigned i;
	unsigned j;
{
D 7
	register char *cp, *dp;
E 7
I 7
	char *cp;
E 7
D 4
#ifdef debug
	static char *av[2] = {0, 0};
#endif
E 4

	i *= j;
D 4
	cp = (char *) malloc(i);
	if (cp == 0) {
		child++;
#ifndef debug
		error("Out of memory");
#else
		showall(av);
		printf("i=%d, j=%d: ", i/j, j);
		printf("Out of memory\n");
		chdir("/usr/bill/cshcore");
		abort();
#endif
	}
	dp = cp;
E 4
I 4
D 7
	dp = cp = xalloc(i);
E 4
	if (i != 0)
		do
			*dp++ = 0;
		while (--i);
E 7
I 7
	cp = xalloc(i);
	bzero(cp, (int)i);
E 7
	return (cp);
}

I 4
nomem(i)
	unsigned i;
{
#ifdef debug
	static char *av[2] = {0, 0};
#endif

	child++;
#ifndef debug
	error("Out of memory");
#ifdef lint
	i = i;
#endif
#else
	showall(av);
	printf("i=%d: Out of memory\n", i);
	chdir("/usr/bill/cshcore");
	abort();
#endif
	return 0;		/* fool lint */
}

E 4
D 3
cfree(p)
	char *p;
{

	free(p);
}

E 3
char **
blkend(up)
	register char **up;
{

	while (*up)
		up++;
	return (up);
}
 
blkpr(av)
	register char **av;
{

	for (; *av; av++) {
		printf("%s", *av);
		if (av[1])
			printf(" ");
	}
}

blklen(av)
	register char **av;
{
	register int i = 0;

	while (*av++)
		i++;
	return (i);
}

char **
blkcpy(oav, bv)
	char **oav;
	register char **bv;
{
	register char **av = oav;

	while (*av++ = *bv++)
		continue;
	return (oav);
}

char **
blkcat(up, vp)
	char **up, **vp;
{

D 4
	blkcpy(blkend(up), vp);
E 4
I 4
	(void) blkcpy(blkend(up), vp);
E 4
	return (up);
}

blkfree(av0)
	char **av0;
{
	register char **av = av0;

D 4
	while (*av)
		xfree(*av++);
	xfree((char *)av0);
E 4
I 4
	for (; *av; av++)
		XFREE(*av)
	XFREE((char *)av0)
E 4
}

char **
saveblk(v)
	register char **v;
{
D 4
	register int len = blklen(v) + 1;
	register char **newv = (char **) calloc(len, sizeof (char **));
E 4
I 4
	register char **newv =
		(char **) calloc((unsigned) (blklen(v) + 1), sizeof (char **));
E 4
	char **onewv = newv;

	while (*v)
		*newv++ = savestr(*v++);
	return (onewv);
}

char *
strspl(cp, dp)
D 4
	register char *cp, *dp;
E 4
I 4
	char *cp, *dp;
E 4
{
D 4
	register char *ep = calloc(1, strlen(cp) + strlen(dp) + 1);
E 4
I 4
	char *ep;
	register char *p, *q;
E 4

D 4
	strcpy(ep, cp);
	strcat(ep, dp);
E 4
I 4
	for (p = cp; *p++;)
		;
	for (q = dp; *q++;)
		;
	ep = xalloc((unsigned) ((p - cp) + (q - dp) - 1));
	for (p = ep, q = cp; *p++ = *q++;)
		;
	for (p--, q = dp; *p++ = *q++;)
		;
E 4
	return (ep);
}

char **
blkspl(up, vp)
	register char **up, **vp;
{
D 4
	register char **wp = (char **) calloc(blklen(up) + blklen(vp) + 1, sizeof (char **));
E 4
I 4
	register char **wp =
		(char **) calloc((unsigned) (blklen(up) + blklen(vp) + 1),
			sizeof (char **));
E 4

D 4
	blkcpy(wp, up);
E 4
I 4
	(void) blkcpy(wp, up);
E 4
	return (blkcat(wp, vp));
}

lastchr(cp)
	register char *cp;
{

	if (!*cp)
		return (0);
	while (cp[1])
		cp++;
	return (*cp);
}

/*
 * This routine is called after an error to close up
 * any units which may have been left open accidentally.
 */
closem()
{
	register int f;

	for (f = 0; f < NOFILE; f++)
		if (f != SHIN && f != SHOUT && f != SHDIAG && f != OLDSTD &&
		    f != FSHTTY)
D 4
			close(f);
E 4
I 4
			(void) close(f);
E 4
}

D 4
/*
 * Close files before executing a file.
 * We could be MUCH more intelligent, since (on a version 7 system)
 * we need only close files here during a source, the other
 * shell fd's being in units 16-19 which are closed automatically!
 */
closech()
{
	register int f;

	if (didcch)
		return;
	didcch = 1;
	SHIN = 0; SHOUT = 1; SHDIAG = 2; OLDSTD = 0;
	for (f = 3; f < NOFILE; f++)
		close(f);
}

E 4
donefds()
{

D 4
	close(0), close(1), close(2);
E 4
I 4
	(void) close(0);
	(void) close(1);
	(void) close(2);
E 4
	didfds = 0;
}

/*
 * Move descriptor i to j.
 * If j is -1 then we just want to get i to a safe place,
 * i.e. to a unit > 2.  This also happens in dcopy.
 */
dmove(i, j)
	register int i, j;
{

	if (i == j || i < 0)
		return (i);
D 4
#ifdef V7
E 4
	if (j >= 0) {
D 4
		dup2(i, j);
E 4
I 4
		(void) dup2(i, j);
E 4
		return (j);
D 4
	} else
#endif
		j = dcopy(i, j);
E 4
I 4
	}
	j = dcopy(i, j);
E 4
	if (j != i)
D 4
		close(i);
E 4
I 4
		(void) close(i);
E 4
	return (j);
}

dcopy(i, j)
	register int i, j;
{

	if (i == j || i < 0 || j < 0 && i > 2)
		return (i);
D 4
#ifdef V7
E 4
	if (j >= 0) {
D 4
		dup2(i, j);
E 4
I 4
		(void) dup2(i, j);
E 4
		return (j);
	}
D 4
#endif
	close(j);
E 4
I 4
	(void) close(j);
E 4
	return (renum(i, j));
}

renum(i, j)
	register int i, j;
{
	register int k = dup(i);

	if (k < 0)
		return (-1);
	if (j == -1 && k > 2)
		return (k);
	if (k != j) {
		j = renum(k, j);
D 4
		close(k);
E 4
I 4
		(void) close(k);
E 4
		return (j);
	}
	return (k);
}

I 2
#ifndef copy
E 2
copy(to, from, size)
	register char *to, *from;
	register int size;
{

	if (size)
		do
			*to++ = *from++;
		while (--size != 0);
}
I 2
#endif
E 2

/*
 * Left shift a command argument list, discarding
 * the first c arguments.  Used in "shift" commands
 * as well as by commands like "repeat".
 */
lshift(v, c)
	register char **v;
	register int c;
{
	register char **u = v;

	while (*u && --c >= 0)
		xfree(*u++);
D 4
	blkcpy(v, u);
E 4
I 4
	(void) blkcpy(v, u);
E 4
}

number(cp)
	char *cp;
{

	if (*cp == '-') {
		cp++;
		if (!digit(*cp++))
			return (0);
	}
	while (*cp && digit(*cp))
		cp++;
	return (*cp == 0);
}

char **
copyblk(v)
	register char **v;
{
D 4
	register char **nv = (char **) calloc(blklen(v) + 1, sizeof (char **));
E 4
I 4
	register char **nv =
		(char **) calloc((unsigned) (blklen(v) + 1), sizeof (char **));
E 4

	return (blkcpy(nv, v));
}

char *
strend(cp)
	register char *cp;
{

	while (*cp)
		cp++;
	return (cp);
}

char *
strip(cp)
	char *cp;
{
	register char *dp = cp;

	while (*dp++ &= TRIM)
		continue;
	return (cp);
}

udvar(name)
	char *name;
{

	setname(name);
	bferr("Undefined variable");
}

prefix(sub, str)
	register char *sub, *str;
{

	for (;;) {
		if (*sub == 0)
			return (1);
		if (*str == 0)
			return (0);
		if (*sub++ != *str++)
			return (0);
	}
}
E 1
