h07197
s 00010/00005/00623
d D 5.4 88/06/29 20:19:30 bostic 17 16
c install approved copyright notice
e
s 00009/00003/00619
d D 5.3 88/02/01 11:34:41 bostic 16 15
c add new Berkeley headers
e
s 00008/00015/00614
d D 5.2 86/03/28 04:45:19 lepreau 15 14
c use qsort instead of N**2 linear exchange sort from csh
e
s 00008/00002/00621
d D 5.1 85/06/06 08:50:20 dist 14 13
c Add copyright
e
s 00008/00002/00615
d D 4.13 85/04/03 10:17:25 ralph 13 12
c fix problems with '\' for except_pat.
e
s 00033/00019/00584
d D 4.12 85/02/04 14:34:02 ralph 12 11
c use yyerror instead of quitting on first error.
e
s 00003/00002/00600
d D 4.11 84/12/06 14:56:54 ralph 11 10
c bug fix from Jay Lepreau for null expansion.
e
s 00039/00047/00563
d D 4.10 84/02/09 16:06:26 ralph 10 9
c read entire distfile and sort entries by host.
e
s 00001/00002/00609
d D 4.9 83/12/19 14:44:54 ralph 9 8
c making lint happier
e
s 00006/00004/00605
d D 4.8 83/11/30 15:18:16 ralph 8 7
c fixing case when not expanding `~'.
e
s 00153/00138/00456
d D 4.7 83/11/29 16:00:19 ralph 7 6
c bug fixes and added `special' command.
e
s 00001/00000/00593
d D 4.6 83/11/01 17:23:15 ralph 6 5
c minor bug for ~ expansion.
e
s 00017/00013/00576
d D 4.5 83/11/01 14:29:32 ralph 5 4
c fixes for -r and -w.
e
s 00007/00009/00582
d D 4.4 83/10/20 12:14:43 ralph 4 3
c added -r option to remove extra files.
e
s 00052/00034/00539
d D 4.3 83/10/10 16:15:33 ralph 3 2
c stable version that works.
e
s 00431/00051/00142
d D 4.2 83/09/27 14:38:36 ralph 2 1
c First stable version.
e
s 00193/00000/00000
d D 4.1 83/09/07 13:19:40 ralph 1 0
c date and time created 83/09/07 13:19:40 by ralph
e
u
U
t
T
I 14
/*
 * Copyright (c) 1983 Regents of the University of California.
D 16
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 16
I 16
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 17
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 17
I 17
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
E 17
E 16
 */

E 14
I 1
#ifndef lint
D 14
static	char *sccsid = "%W% (Berkeley) %E%";
#endif
E 14
I 14
static char sccsid[] = "%W% (Berkeley) %G%";
D 16
#endif not lint
E 16
I 16
#endif /* not lint */
E 16
E 14

#include "defs.h"

I 12
#define	GAVSIZ	NCARGS / 6
E 12
D 2
static struct block *hashtab[HASHSIZE];
static int nhashed = 0;
E 2
I 2
D 7
char	shchars[] = "{[*?";
E 7
I 7
#define LC '{'
#define RC '}'
E 7
E 2

D 2
/*
 * Lookup name in the table and return a pointer to it.
 * if insert, insert or replace name with value.
 */
E 2
I 2
D 7
int	argc;
char	**argv;
char	*path, *pathp, *lastpathp;
int	nleft;
E 7
I 7
static char	shchars[] = "${[*?";
E 7
E 2

D 2
struct block *
lookup(name, insert, value)
	char *name;
	int insert;
	struct block *value;
{
	register unsigned n;
	register char *cp;
	register struct block *b;
E 2
I 2
D 7
int	argcnt;
int	expany;		/* any expansions done? */
char	*entp;
char	**sortbase;
E 7
I 7
D 10
static int	which;		/* bit mask of types to expand */
static int	argc;		/* expanded arg count */
static char	**argv;		/* expanded arg vectors */
static char	*path;
static char	*pathp;
static char	*lastpathp;
D 8
static char	*tilde;		/* null if expanding tilde */
E 8
I 8
static char	*tilde;		/* "~user" if not expanding tilde, else "" */
E 8
static char	*tpathp;
static int	nleft;
E 10
I 10
int	which;		/* bit mask of types to expand */
int	eargc;		/* expanded arg count */
char	**eargv;	/* expanded arg vectors */
char	*path;
char	*pathp;
char	*lastpathp;
char	*tilde;		/* "~user" if not expanding tilde, else "" */
char	*tpathp;
int	nleft;
E 10
E 7
E 2

I 7
D 10
static int	expany;		/* any expansions done? */
static char	*entp;
static char	**sortbase;
E 10
I 10
int	expany;		/* any expansions done? */
char	*entp;
char	**sortbase;
E 10

E 7
D 2
	if (debug)
		printf("lookup(%s, %d, %x)\n", name, insert, value);

	n = 0;
	for (cp = name; *cp; )
		n += *cp++;
	n %= HASHSIZE;

	for (b = hashtab[n]; b != NULL; b = b->b_next) {
		if (strcmp(name, b->b_name))
			continue;
		if (insert) {
			warn("%s redefined\n", name);
			b->b_args = value->b_args;
			free(value->b_name);
			free(value);
		}
		return(b);
	}

	if (!insert)
		fatal("%s not defined", name);

	value->b_next = hashtab[n];
	hashtab[n] = value;
	return(value);
}

E 2
char	*index();
I 15
int	argcmp();
E 15
I 3
D 10
struct block *copy();
E 10
E 3

I 15
#define sort()	qsort((char *)sortbase, &eargv[eargc] - sortbase, \
		      sizeof(*sortbase), argcmp), sortbase = &eargv[eargc]

E 15
/*
D 2
 * Take a list of names and expand any macros found.
E 2
I 2
 * Take a list of names and expand any macros, etc.
I 7
 * wh = E_VARS if expanding variables.
 * wh = E_SHELL if expanding shell characters.
 * wh = E_TILDE if expanding `~'.
 * or any of these or'ed together.
I 12
 *
 * Major portions of this were snarfed from csh/sh.glob.c.
E 12
E 7
E 2
 */
D 10
struct block *
E 10
I 10
struct namelist *
E 10
D 2
expand(list)
E 2
I 2
D 7
expand(list, noshexp)
E 7
I 7
expand(list, wh)
E 7
E 2
D 10
	struct block *list;
E 10
I 10
	struct namelist *list;
E 10
I 2
D 7
	int noshexp;
E 7
I 7
	int wh;
E 7
E 2
{
D 7
	register struct block *prev, *bp, *tp;
D 3
	register char *cp, *s;
E 3
I 3
	register char *cp;
E 7
I 7
D 10
	register struct block *bp, *prev;
E 10
I 10
	register struct namelist *nl, *prev;
E 10
E 7
E 3
	register int n;
D 3
	char *var, *tail;
E 3
I 3
D 7
	char *tail;
E 3
	int c;
E 7
I 2
	char pathbuf[BUFSIZ];
	char *argvbuf[GAVSIZ];
E 2

I 3
	if (debug) {
D 7
		printf("expand(%x, %d)\nlist = ", list, noshexp);
E 7
I 7
		printf("expand(%x, %d)\nlist = ", list, wh);
E 7
		prnames(list);
	}

E 3
D 7
	for (prev = NULL, bp = list; bp != NULL; prev = bp, bp = bp->b_next) {
	again:
		cp = index(bp->b_name, '$');
D 3
		if (cp == NULL || cp != bp->b_name && cp[-1] == '\\')
E 3
I 3
		if (cp == NULL)
E 3
			continue;
		*cp++ = '\0';
		if (*cp == '\0')
			fatal("no variable name after '$'");
		if (*cp == '{') {
			cp++;
			if ((tail = index(cp, '}')) == NULL)
				fatal("missing '}'");
			*tail++ = c = '\0';
			if (*cp == '\0')
				fatal("no variable name after '$'");
		} else {
			tail = cp + 1;
			c = *tail;
			*tail = '\0';
		}
D 2
		tp = lookup(cp, 0, NULL);
E 2
I 2
		tp = lookup(cp, NULL, 0);
I 3
		if (c != '\0')
			*tail = c;
E 3
E 2
		if ((tp = tp->b_args) != NULL) {
D 3
			struct block *first = tp;
E 3
I 3
			struct block *first = bp;
E 3

I 3
			for (bp = prev; tp != NULL; tp = tp->b_next) {
				if (bp == NULL)
					list = bp = copy(tp, first->b_name, tail);
				else {
					bp->b_next = copy(tp, first->b_name, tail);
					bp = bp->b_next;
				}
			}
			bp->b_next = first->b_next;
			free(first->b_name);
			free(first);
E 3
			if (prev == NULL)
D 3
				list = tp;
E 3
I 3
				bp = list;
E 3
			else
D 3
				prev->b_next = tp;
			if (c)
				*tail = c;
			makestr(tp, bp->b_name, tail);
			while (tp->b_next != NULL) {
				tp = tp->b_next;
				makestr(tp, bp->b_name, tail);
			}
			tp->b_next = bp->b_next;
			free(bp->b_name);
			free(bp);
			bp = first;
E 3
I 3
				bp = prev->b_next;
E 3
			goto again;
		} else {
			if (prev == NULL)
D 2
				list = tp = list->b_next;
E 2
I 2
				list = tp = bp->b_next;
E 2
			else
				prev->b_next = tp = bp->b_next;
			free(bp->b_name);
			free(bp);
			if (tp != NULL) {
				bp = tp;
				goto again;
			}
			break;
		}
	}
I 2

	if (noshexp)
E 7
I 7
D 13
	if (wh == 0)
E 13
I 13
	if (wh == 0) {
		register char *cp;

		for (nl = list; nl != NULL; nl = nl->n_next)
			for (cp = nl->n_name; *cp; cp++)
				*cp = *cp & TRIM;
E 13
E 7
		return(list);
I 13
	}
E 13

I 3
D 7
	if (debug) {
		printf("shexpand ");
		prnames(list);
	}

E 3
	path = pathp = pathbuf;
E 7
I 7
	which = wh;
	path = tpathp = pathp = pathbuf;
E 7
	*pathp = '\0';
	lastpathp = &path[sizeof pathbuf - 2];
I 7
D 8
	tilde = NULL;
E 8
I 8
	tilde = "";
E 8
E 7
D 10
	argc = 0;
	argv = sortbase = argvbuf;
	*argv = 0;
E 10
I 10
	eargc = 0;
	eargv = sortbase = argvbuf;
	*eargv = 0;
E 10
	nleft = NCARGS - 4;
D 7
	argcnt = 0;
	for (bp = list; bp != NULL; bp = bp->b_next)
		expsh(bp->b_name);
	for (bp = list; bp != NULL; bp = tp) {
		tp = bp->b_next;
E 7
I 7
	/*
D 10
	 * Walk the block list and expand names into argv[];
E 10
I 10
	 * Walk the name list and expand names into eargv[];
E 10
	 */
D 10
	for (bp = list; bp != NULL; bp = bp->b_next) {
		expstr(bp->b_name);
E 7
		free(bp->b_name);
		free(bp);
	}
E 10
I 10
	for (nl = list; nl != NULL; nl = nl->n_next)
		expstr(nl->n_name);
E 10
D 7
	prev = NULL;
E 7
I 7
	/*
D 10
	 * Take expanded list of names from argv[] and build a block list.
E 10
I 10
	 * Take expanded list of names from eargv[] and build a new list.
E 10
	 */
	list = prev = NULL;
E 7
D 10
	for (n = 0; n < argc; n++) {
		bp = ALLOC(block);
		if (bp == NULL)
			fatal("ran out of memory\n");
		bp->b_type = NAME;
		bp->b_next = bp->b_args = NULL;
		bp->b_name = argv[n];
E 10
I 10
	for (n = 0; n < eargc; n++) {
		nl = makenl(NULL);
		nl->n_name = eargv[n];
E 10
		if (prev == NULL)
D 10
			list = prev = bp;
E 10
I 10
			list = prev = nl;
E 10
		else {
D 10
			prev->b_next = bp;
			prev = bp;
E 10
I 10
			prev->n_next = nl;
			prev = nl;
E 10
		}
	}
I 7
	if (debug) {
		printf("expanded list = ");
		prnames(list);
	}
E 7
E 2
	return(list);
}

D 7
/*
D 3
 * Concat head, bp->b_name, and tail
E 3
I 3
 * Return a new NAME block named "head, bp->b_name, tail"
E 3
 */
D 3
makestr(bp, head, tail)
E 3
I 3
struct block *
copy(bp, head, tail)
E 3
	struct block *bp;
	char *head, *tail;
E 7
I 7
expstr(s)
	char *s;
E 7
{
D 7
	register int n;
	register char *cp;
I 3
	register struct block *np;
E 7
I 7
	register char *cp, *cp1;
D 10
	register struct block *tp;
E 10
I 10
	register struct namelist *tp;
E 10
D 9
	char *tail, *opathp;
E 9
I 9
	char *tail;
E 9
	char buf[BUFSIZ];
D 10
	int savec, oargc;
E 10
I 10
	int savec, oeargc;
E 10
	extern char homedir[];
E 7
E 3

D 3
	if (!*head && !*tail)
		return;
E 3
I 3
D 7
	np = ALLOC(block);
	if (np == NULL)
		fatal("ran out of memory\n");
	np->b_type = NAME;
	np->b_next = bp->b_args = NULL;
E 3
	n = strlen(bp->b_name) + strlen(head) + strlen(tail) + 1;
D 3
	cp = (char *) malloc(n);
E 3
I 3
	np->b_name = cp = malloc(n);
E 3
	if (cp == NULL)
		fatal("ran out of memory");
	sprintf(cp, "%s%s%s", head, bp->b_name, tail);
D 3
	free(bp->b_name);
	bp->b_name = cp;
E 3
I 3
	return(np);
E 3
}
E 7
I 7
	if (s == NULL || *s == '\0')
		return;
E 7

D 7
/*
 * If there are any Shell meta characters in the name,
 * expand into a list, after searching directory
D 2
 * For now, only do ~name.
E 2
 */
D 2
shexpand(buf, file)
E 2
I 2
expsh(s)
	register char *s;
{
D 3
	register int i;
E 3
	register int oargc = argc;

	if (!strcmp(s, "{") || !strcmp(s, "{}")) {
E 7
I 7
	if ((which & E_VARS) && (cp = index(s, '$')) != NULL) {
		*cp++ = '\0';
		if (*cp == '\0') {
D 12
			error("no variable name after '$'\n");
E 12
I 12
			yyerror("no variable name after '$'");
E 12
			return;
		}
		if (*cp == LC) {
			cp++;
			if ((tail = index(cp, RC)) == NULL) {
D 12
				error("unmatched %c\n", *cp);
E 12
I 12
				yyerror("unmatched '{'");
E 12
				return;
			}
			*tail++ = savec = '\0';
			if (*cp == '\0') {
D 12
				error("no variable name after '$'\n");
E 12
I 12
				yyerror("no variable name after '$'");
E 12
				return;
			}
		} else {
			tail = cp + 1;
			savec = *tail;
			*tail = '\0';
		}
		tp = lookup(cp, NULL, 0);
		if (savec != '\0')
			*tail = savec;
D 10
		if ((tp = tp->b_args) != NULL) {
			for (; tp != NULL; tp = tp->b_next) {
				sprintf(buf, "%s%s%s", s, tp->b_name, tail);
E 10
I 10
		if (tp != NULL) {
			for (; tp != NULL; tp = tp->n_next) {
				sprintf(buf, "%s%s%s", s, tp->n_name, tail);
E 10
				expstr(buf);
			}
			return;
		}
		sprintf(buf, "%s%s", s, tail);
		expstr(buf);
		return;
	}
	if ((which & ~E_VARS) == 0 || !strcmp(s, "{") || !strcmp(s, "{}")) {
E 7
		Cat(s, "");
		sort();
		return;
	}
D 7

	pathp = path;
	*pathp = 0;
E 7
I 7
	if (*s == '~') {
		cp = ++s;
		if (*cp == '\0' || *cp == '/') {
			tilde = "~";
			cp1 = homedir;
		} else {
			tilde = cp1 = buf;
			*cp1++ = '~';
			do
				*cp1++ = *cp++;
			while (*cp && *cp != '/');
			*cp1 = '\0';
			if (pw == NULL || strcmp(pw->pw_name, buf+1) != 0) {
				if ((pw = getpwnam(buf+1)) == NULL) {
D 12
					error("unknown user %s\n", buf+1);
E 12
I 12
					strcat(buf, ": unknown user name");
					yyerror(buf+1);
E 12
					return;
				}
			}
			cp1 = pw->pw_dir;
			s = cp;
		}
		for (cp = path; *cp++ = *cp1++; )
			;
		tpathp = pathp = cp - 1;
D 8
	} else
		pathp = path;
E 8
I 8
	} else {
		tpathp = pathp = path;
		tilde = "";
	}
E 8
	*pathp = '\0';
	if (!(which & E_SHELL)) {
		if (which & E_TILDE)
			Cat(path, s);
		else
			Cat(tilde, s);
		sort();
		return;
	}
D 10
	oargc = argc;
E 10
I 10
	oeargc = eargc;
E 10
E 7
	expany = 0;
D 7
	expstr(s);
E 7
I 7
	expsh(s);
D 9
	pathp = opathp;
E 9
E 7
D 10
	if (argc != oargc)
E 10
I 10
D 11
	if (eargc != oeargc)
E 10
		sort();
E 11
I 11
	if (eargc == oeargc)
		Cat(s, "");		/* "nonomatch" is set */
	sort();
E 11
}

D 15
/*
 * Bubble sort any new entries
 */
sort()
E 15
I 15
static
argcmp(a1, a2)
	char **a1, **a2;
E 15
{
D 15
	register char **p1, **p2, *c;
D 10
	char **ap = &argv[argc];
E 10
I 10
	char **ap = &eargv[eargc];
E 15
E 10

D 15
	p1 = sortbase;
	while (p1 < ap-1) {
		p2 = p1;
		while (++p2 < ap)
			if (strcmp(*p1, *p2) > 0)
				c = *p1, *p1 = *p2, *p2 = c;
		p1++;
	}
	sortbase = ap;
E 15
I 15
	return (strcmp(*a1, *a2));
E 15
}

D 7
expstr(s)
E 7
I 7
/*
 * If there are any Shell meta characters in the name,
 * expand into a list, after searching directory
 */
expsh(s)
E 7
	char *s;
{
	register char *cp;
	register char *spathp, *oldcp;
	struct stat stb;

	spathp = pathp;
	cp = s;
	while (!any(*cp, shchars)) {
		if (*cp == '\0') {
D 7
			if (!expany)
				Cat(path, "");
			else if (stat(path, &stb) >= 0) {
				Cat(path, "");
				argcnt++;
E 7
I 7
			if (!expany || stat(path, &stb) >= 0) {
				if (which & E_TILDE)
					Cat(path, "");
				else
					Cat(tilde, tpathp);
E 7
			}
			goto endit;
		}
		addpath(*cp++);
	}
	oldcp = cp;
	while (cp > s && *cp != '/')
		cp--, pathp--;
	if (*cp == '/')
		cp++, pathp++;
	*pathp = '\0';
	if (*oldcp == '{') {
		execbrc(cp, NULL);
		return;
	}
	matchdir(cp);
endit:
	pathp = spathp;
	*pathp = '\0';
}

matchdir(pattern)
	char *pattern;
{
	struct stat stb;
	register struct direct *dp;
	DIR *dirp;
D 3
	register int cnt;
E 3

	dirp = opendir(path);
	if (dirp == NULL) {
		if (expany)
			return;
		goto patherr2;
	}
	if (fstat(dirp->dd_fd, &stb) < 0)
		goto patherr1;
D 4
	if ((stb.st_mode & S_IFMT) != S_IFDIR) {
E 4
I 4
	if (!ISDIR(stb.st_mode)) {
E 4
		errno = ENOTDIR;
		goto patherr1;
	}
	while ((dp = readdir(dirp)) != NULL)
		if (match(dp->d_name, pattern)) {
D 7
			Cat(path, dp->d_name);
			argcnt++;
E 7
I 7
			if (which & E_TILDE)
				Cat(path, dp->d_name);
			else {
				strcpy(pathp, dp->d_name);
				Cat(tilde, tpathp);
				*pathp = '\0';
			}
E 7
		}
	closedir(dirp);
	return;

patherr1:
	closedir(dirp);
patherr2:
D 7
	fatal("%s: %s\n", path, sys_errlist[errno]);
E 7
I 7
D 12
	error("%s: %s\n", path, sys_errlist[errno]);
E 12
I 12
	strcat(path, ": ");
	strcat(path, sys_errlist[errno]);
	yyerror(path);
E 12
E 7
}

execbrc(p, s)
	char *p, *s;
{
	char restbuf[BUFSIZ + 2];
	register char *pe, *pm, *pl;
	int brclev = 0;
	char *lm, savec, *spathp;

	for (lm = restbuf; *p != '{'; *lm++ = *p++)
		continue;
	for (pe = ++p; *pe; pe++)
		switch (*pe) {

		case '{':
			brclev++;
			continue;

		case '}':
			if (brclev == 0)
				goto pend;
			brclev--;
			continue;

		case '[':
			for (pe++; *pe && *pe != ']'; pe++)
				continue;
			if (!*pe)
D 7
				fatal("Missing ]\n");
E 7
I 7
D 12
				error("Missing ]\n");
E 12
I 12
				yyerror("Missing ']'");
E 12
E 7
			continue;
		}
pend:
D 12
	if (brclev || !*pe)
		fatal("Missing }\n");
E 12
I 12
	if (brclev || !*pe) {
		yyerror("Missing '}'");
		return (0);
	}
E 12
	for (pl = pm = p; pm <= pe; pm++)
		switch (*pm & (QUOTE|TRIM)) {

		case '{':
			brclev++;
			continue;

		case '}':
			if (brclev) {
				brclev--;
				continue;
			}
			goto doit;

		case ',':
			if (brclev)
				continue;
doit:
			savec = *pm;
			*pm = 0;
			strcpy(lm, pl);
			strcat(restbuf, pe + 1);
			*pm = savec;
			if (s == 0) {
				spathp = pathp;
D 7
				expstr(restbuf);
E 7
I 7
				expsh(restbuf);
E 7
				pathp = spathp;
				*pathp = 0;
			} else if (amatch(s, restbuf))
				return (1);
			sort();
			pl = pm + 1;
			continue;

		case '[':
			for (pm++; *pm && *pm != ']'; pm++)
				continue;
			if (!*pm)
D 7
				fatal("Missing ]\n");
E 7
I 7
D 12
				error("Missing ]\n");
E 12
I 12
				yyerror("Missing ']'");
E 12
E 7
			continue;
		}
	return (0);
}

match(s, p)
	char *s, *p;
{
	register int c;
	register char *sentp;
	char sexpany = expany;

	if (*s == '.' && *p != '.')
		return (0);
	sentp = entp;
	entp = s;
	c = amatch(s, p);
	entp = sentp;
	expany = sexpany;
	return (c);
}

amatch(s, p)
	register char *s, *p;
{
	register int scc;
	int ok, lc;
	char *spathp;
	struct stat stb;
	int c, cc;

	expany = 1;
	for (;;) {
		scc = *s++ & TRIM;
		switch (c = *p++) {

		case '{':
			return (execbrc(p - 1, s - 1));

		case '[':
			ok = 0;
			lc = 077777;
			while (cc = *p++) {
				if (cc == ']') {
					if (ok)
						break;
					return (0);
				}
				if (cc == '-') {
					if (lc <= scc && scc <= *p++)
						ok++;
				} else
					if (scc == (lc = cc))
						ok++;
			}
D 12
			if (cc == 0)
				fatal("Missing ]\n");
E 12
I 12
			if (cc == 0) {
				yyerror("Missing ']'");
				return (0);
			}
E 12
			continue;

		case '*':
			if (!*p)
				return (1);
			if (*p == '/') {
				p++;
				goto slash;
			}
			for (s--; *s; s++)
				if (amatch(s, p))
					return (1);
			return (0);

		case '\0':
			return (scc == '\0');

		default:
D 12
			if (c != scc)
E 12
I 12
			if ((c & TRIM) != scc)
E 12
				return (0);
			continue;

		case '?':
			if (scc == '\0')
				return (0);
			continue;

		case '/':
			if (scc)
				return (0);
slash:
			s = entp;
			spathp = pathp;
			while (*s)
				addpath(*s++);
			addpath('/');
D 4
			if (stat(path, &stb) == 0 &&
			    (stb.st_mode & S_IFMT) == S_IFDIR)
E 4
I 4
			if (stat(path, &stb) == 0 && ISDIR(stb.st_mode))
E 4
				if (*p == '\0') {
D 7
					Cat(path, "");
					argcnt++;
E 7
I 7
					if (which & E_TILDE)
						Cat(path, "");
					else
						Cat(tilde, tpathp);
E 7
				} else
D 7
					expstr(p);
E 7
I 7
					expsh(p);
E 7
			pathp = spathp;
			*pathp = '\0';
			return (0);
		}
	}
}

smatch(s, p)
	register char *s, *p;
{
	register int scc;
	int ok, lc;
	int c, cc;

	for (;;) {
		scc = *s++ & TRIM;
		switch (c = *p++) {

		case '[':
			ok = 0;
			lc = 077777;
			while (cc = *p++) {
				if (cc == ']') {
					if (ok)
						break;
					return (0);
				}
				if (cc == '-') {
					if (lc <= scc && scc <= *p++)
						ok++;
				} else
					if (scc == (lc = cc))
						ok++;
			}
D 12
			if (cc == 0)
				fatal("Missing ]\n");
E 12
I 12
			if (cc == 0) {
				yyerror("Missing ']'");
				return (0);
			}
E 12
			continue;

		case '*':
			if (!*p)
				return (1);
			for (s--; *s; s++)
				if (smatch(s, p))
					return (1);
			return (0);

		case '\0':
			return (scc == '\0');

		default:
			if ((c & TRIM) != scc)
				return (0);
			continue;

		case '?':
			if (scc == 0)
				return (0);
			continue;

		}
	}
}

Cat(s1, s2)
	register char *s1, *s2;
{
	int len = strlen(s1) + strlen(s2) + 1;
D 3
	register char *s, *ep;
E 3
I 3
	register char *s;
E 3

	nleft -= len;
D 10
	if (nleft <= 0 || ++argc >= GAVSIZ)
E 10
I 10
	if (nleft <= 0 || ++eargc >= GAVSIZ)
E 10
D 7
		fatal("Arguments too long\n");
E 7
I 7
D 12
		error("Arguments too long\n");
E 12
I 12
		yyerror("Arguments too long");
E 12
E 7
D 10
	argv[argc] = 0;
D 3
	argv[argc - 1] = s = (char *) malloc(len);
E 3
I 3
	argv[argc - 1] = s = malloc(len);
E 10
I 10
	eargv[eargc] = 0;
	eargv[eargc - 1] = s = malloc(len);
E 10
E 3
	if (s == NULL)
		fatal("ran out of memory\n");
	while (*s++ = *s1++ & TRIM)
		;
	s--;
	while (*s++ = *s2++ & TRIM)
		;
}

addpath(c)
	char c;
{

	if (pathp >= lastpathp)
D 12
		fatal("Pathname too long\n");
	*pathp++ = c;
	*pathp = '\0';
E 12
I 12
		yyerror("Pathname too long");
	else {
D 13
		*pathp++ = c;
E 13
I 13
		*pathp++ = c & TRIM;
E 13
		*pathp = '\0';
	}
E 12
}

/*
 * Expand file names beginning with `~' into the
D 3
 * user's home directory path name.
E 3
I 3
 * user's home directory path name. Return a pointer in buf to the
 * part corresponding to `file'.
E 3
 */
I 3
char *
E 3
exptilde(buf, file)
E 2
	char buf[];
	register char *file;
{
	register char *s1, *s2, *s3;
D 5
	register struct passwd *pw;
	extern char *homedir;
E 5
I 5
	extern char homedir[];
E 5

	if (*file != '~') {
		strcpy(buf, file);
D 3
		return;
E 3
I 3
		return(buf);
E 3
	}
D 5
	file++;
	if (*file == '\0' || *file == '/') {
E 5
I 5
	if (*++file == '\0') {
E 5
		s2 = homedir;
I 5
		s3 = NULL;
	} else if (*file == '/') {
		s2 = homedir;
E 5
		s3 = file;
	} else {
I 6
		s3 = file;
E 6
D 5
		for (s3 = file; *s3 && *s3 != '/'; s3++)
			;
E 5
I 5
		while (*s3 && *s3 != '/')
			s3++;
E 5
		if (*s3 == '/')
			*s3 = '\0';
		else
			s3 = NULL;
D 2
		setpwent();
E 2
D 5
		pw = getpwnam(file);
		if (pw == NULL) {
D 2
			error("unknown user %s\n", file);
E 2
I 2
D 3
			fatal("unknown user %s\n", file);
E 3
I 3
			error("unknown user %s\n", file);
E 3
E 2
			if (s3 != NULL)
				*s3 = '/';
D 3
			return;
E 3
I 3
			return(NULL);
E 5
I 5
		if (pw == NULL || strcmp(pw->pw_name, file) != 0) {
			if ((pw = getpwnam(file)) == NULL) {
D 12
				error("unknown user %s\n", file);
E 12
I 12
				error("%s: unknown user name\n", file);
E 12
				if (s3 != NULL)
					*s3 = '/';
				return(NULL);
			}
E 5
E 3
		}
		if (s3 != NULL)
			*s3 = '/';
		s2 = pw->pw_dir;
	}
	for (s1 = buf; *s1++ = *s2++; )
		;
D 3
	if (s3 == NULL)
		return;
E 3
D 4
	s1--;
I 3
	if (s3 == NULL)
		return(s1);
E 3
	while (*s1++ = *s3++)
		;
I 3
	return(s1 - 1);
E 4
I 4
	s2 = --s1;
D 5
	if (s3 != NULL)
E 5
I 5
	if (s3 != NULL) {
		s2++;
E 5
		while (*s1++ = *s3++)
			;
I 5
	}
E 5
	return(s2);
E 4
E 3
}
E 1
