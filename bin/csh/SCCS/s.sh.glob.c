h43309
s 00000/00001/00749
d D 5.5 87/12/22 02:59:00 bostic 15 14
c {,} construct should allow '\' to escape comma; bug report 4.3BSD/bin/112
e
s 00006/00004/00744
d D 5.4 86/05/13 01:27:04 lepreau 14 13
c make qsort compare routine extern so sh.file.c can use it
e
s 00011/00015/00737
d D 5.3 86/03/29 07:27:22 lepreau 13 12
c replace internal N**2 linear exchange sort with qsort; minor cmap changes
c associated with sh.h change
e
s 00003/00003/00749
d D 5.2 85/06/06 13:10:38 edward 12 11
c cleaning up after bozos
e
s 00008/00002/00744
d D 5.1 85/06/04 10:59:38 dist 11 10
c Add copyright
e
s 00001/00001/00745
d D 4.9 85/02/28 11:12:02 ralph 10 9
c fix quoted chars in path (e.g., 'foo'/*.c clear quote bits on foo)
e
s 00002/00002/00744
d D 4.8 85/01/17 09:21:14 bloom 9 8
c bus error trying to modify shared null string in trim()
e
s 00056/00061/00690
d D 4.7 84/12/13 14:41:23 edward 8 7
c performance
e
s 00004/00004/00747
d D 4.6 84/08/31 09:31:47 ralph 7 6
c use new signal calls instead of compatibility routines.
e
s 00007/00003/00744
d D 4.5 83/07/03 20:15:02 sam 6 4
c fix for noglob from wnj
e
s 00007/00003/00744
d R 4.5 83/07/01 03:53:01 sam 5 4
c fixes from wnj; 
e
s 00001/00001/00746
d D 4.4 82/05/07 18:21:28 mckusick 4 3
c update to new fs
e
s 00021/00033/00726
d D 4.3 82/02/12 15:29:59 mckusic 3 2
c convret to new directory format
e
s 00003/00002/00756
d D 4.2 81/03/11 18:51:52 wnj 2 1
c minor bug fixes
e
s 00758/00000/00000
d D 4.1 80/10/09 12:41:03 bill 1 0
c date and time created 80/10/09 12:41:03 by bill
e
u
U
t
T
I 11
/*
 * Copyright (c) 1980 Regents of the University of California.
D 12
 * All rights reserved.  The Berkeley software License Agreement
E 12
I 12
 * All rights reserved.  The Berkeley Software License Agreement
E 12
 * specifies the terms and conditions for redistribution.
 */

E 11
I 1
D 8
static	char *sccsid = "%Z%%M% %I% %G%";
E 8
I 8
#ifndef lint
D 11
static	char *sccsid = "%W% (Berkeley) %G%";
#endif
E 11
I 11
D 12
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 12
I 12
static char *sccsid = "%W% (Berkeley) %G%";
#endif
E 12
E 11
E 8
I 3

E 3
#include "sh.h"
I 8
D 13
#include "sh.char.h"
E 13
E 8
I 3
D 4
#include <ndir.h>
E 4
I 4
D 6
#include <dir.h>
E 6
I 6
#include <sys/dir.h>
E 6
E 4
E 3

/*
 * C Shell
 */

int	globcnt;

D 8
char	*globchars =	"`{[*?";

E 8
char	*gpath, *gpathp, *lastgpathp;
int	globbed;
bool	noglob;
bool	nonomatch;
char	*entp;
char	**sortbas;
I 13
D 14
int	argcmp();
E 14
I 14
int	sortscmp();
E 14
E 13

I 13
#define sort()	qsort((char *)sortbas, &gargv[gargc] - sortbas, \
D 14
		      sizeof(*sortbas), argcmp), sortbas = &gargv[gargc]
E 14
I 14
		      sizeof(*sortbas), sortscmp), sortbas = &gargv[gargc]
E 14


E 13
char **
glob(v)
	register char **v;
{
	char agpath[BUFSIZ];
	char *agargv[GAVSIZ];

	gpath = agpath; gpathp = gpath; *gpathp = 0;
	lastgpathp = &gpath[sizeof agpath - 2];
	ginit(agargv); globcnt = 0;
#ifdef GDEBUG
	printf("glob entered: "); blkpr(v); printf("\n");
#endif
	noglob = adrof("noglob") != 0;
	nonomatch = adrof("nonomatch") != 0;
	globcnt = noglob | nonomatch;
	while (*v)
		collect(*v++);
#ifdef GDEBUG
	printf("glob done, globcnt=%d, gflag=%d: ", globcnt, gflag); blkpr(gargv); printf("\n");
#endif
	if (globcnt == 0 && (gflag&1)) {
		blkfree(gargv), gargv = 0;
		return (0);
	} else
		return (gargv = copyblk(gargv));
}

ginit(agargv)
	char **agargv;
{

	agargv[0] = 0; gargv = agargv; sortbas = agargv; gargc = 0;
	gnleft = NCARGS - 4;
}

collect(as)
	register char *as;
{
	register int i;

	if (any('`', as)) {
#ifdef GDEBUG
		printf("doing backp of %s\n", as);
#endif
D 8
		dobackp(as, 0);
E 8
I 8
		(void) dobackp(as, 0);
E 8
#ifdef GDEBUG
		printf("backp done, acollect'ing\n");
#endif
		for (i = 0; i < pargc; i++)
D 6
			if (noglob)
E 6
I 6
			if (noglob) {
E 6
				Gcat(pargv[i], "");
D 6
			else
E 6
I 6
				sortbas = &gargv[gargc];
			} else
E 6
				acollect(pargv[i]);
		if (pargv)
			blkfree(pargv), pargv = 0;
#ifdef GDEBUG
		printf("acollect done\n");
#endif
D 2
	} else if (noglob)
E 2
I 2
	} else if (noglob || eq(as, "{") || eq(as, "{}")) {
E 2
		Gcat(as, "");
D 2
	else
E 2
I 2
		sort();
	} else
E 2
		acollect(as);
}

acollect(as)
	register char *as;
{
	register int ogargc = gargc;

	gpathp = gpath; *gpathp = 0; globbed = 0;
	expand(as);
	if (gargc == ogargc) {
		if (nonomatch) {
			Gcat(as, "");
			sort();
		}
	} else
		sort();
}

D 13
sort()
E 13
I 13
D 14
static
argcmp(a1, a2)
E 14
I 14
/*
 * String compare for qsort.  Also used by filec code in sh.file.c.
 */
sortscmp(a1, a2)
E 14
	char **a1, **a2;
E 13
{
D 13
	register char **p1, **p2, *c;
	char **Gvp = &gargv[gargc];
E 13

D 13
	p1 = sortbas;
	while (p1 < Gvp-1) {
		p2 = p1;
		while (++p2 < Gvp)
			if (strcmp(*p1, *p2) > 0)
				c = *p1, *p1 = *p2, *p2 = c;
		p1++;
	}
	sortbas = Gvp;
E 13
I 13
	 return (strcmp(*a1, *a2));
E 13
}

expand(as)
	char *as;
{
	register char *cs;
	register char *sgpathp, *oldcs;
	struct stat stb;

	sgpathp = gpathp;
	cs = as;
	if (*cs == '~' && gpathp == gpath) {
		addpath('~');
		for (cs++; letter(*cs) || digit(*cs) || *cs == '-';)
			addpath(*cs++);
		if (!*cs || *cs == '/') {
			if (gpathp != gpath + 1) {
				*gpathp = 0;
				if (gethdir(gpath + 1))
					error("Unknown user: %s", gpath + 1);
D 8
				strcpy(gpath, gpath + 1);
E 8
I 8
				(void) strcpy(gpath, gpath + 1);
E 8
			} else
D 8
				strcpy(gpath, value("home"));
E 8
I 8
				(void) strcpy(gpath, value("home"));
E 8
			gpathp = strend(gpath);
		}
	}
D 8
	while (!any(*cs, globchars)) {
E 8
I 8
D 13
	while (!cmap(*cs, _GLOB)) {
E 13
I 13
	while (!isglob(*cs)) {
E 13
E 8
		if (*cs == 0) {
			if (!globbed)
				Gcat(gpath, "");
			else if (stat(gpath, &stb) >= 0) {
				Gcat(gpath, "");
				globcnt++;
			}
			goto endit;
		}
		addpath(*cs++);
	}
	oldcs = cs;
	while (cs > as && *cs != '/')
		cs--, gpathp--;
	if (*cs == '/')
		cs++, gpathp++;
	*gpathp = 0;
	if (*oldcs == '{') {
D 8
		execbrc(cs, NOSTR);
E 8
I 8
		(void) execbrc(cs, NOSTR);
E 8
		return;
	}
	matchdir(cs);
endit:
	gpathp = sgpathp;
	*gpathp = 0;
}

matchdir(pattern)
	char *pattern;
{
	struct stat stb;
D 3
	struct direct dirbuf[BUFSIZ / sizeof (struct direct)];
	char d_name[DIRSIZ+1];
	register int dirf, cnt;
E 3
I 3
	register struct direct *dp;
D 8
	DIR *dirp;
	register int cnt;
E 8
I 8
	register DIR *dirp;
E 8
E 3

D 3
	dirf = open(gpath, 0);
	if (dirf < 0) {
E 3
I 3
	dirp = opendir(gpath);
	if (dirp == NULL) {
E 3
		if (globbed)
			return;
D 3
		goto patherr;
E 3
I 3
		goto patherr2;
E 3
	}
D 3
	if (fstat(dirf, &stb) < 0)
		goto patherr;
E 3
I 3
	if (fstat(dirp->dd_fd, &stb) < 0)
		goto patherr1;
E 3
	if (!isdir(stb)) {
		errno = ENOTDIR;
D 3
		goto patherr;
E 3
I 3
		goto patherr1;
E 3
	}
D 3
	while ((cnt = read(dirf, (char *) dirbuf, sizeof dirbuf)) >= sizeof dirbuf[0]) {
		register struct direct *ep = dirbuf;

		for (cnt /= sizeof (struct direct); cnt > 0; cnt--, ep++) {
			if (ep->d_ino == 0)
				continue;
			copdent(d_name, ep->d_name);
			if (match(d_name, pattern)) {
				Gcat(gpath, d_name);
				globcnt++;
			}
E 3
I 3
	while ((dp = readdir(dirp)) != NULL) {
		if (dp->d_ino == 0)
			continue;
		if (match(dp->d_name, pattern)) {
			Gcat(gpath, dp->d_name);
			globcnt++;
E 3
		}
	}
D 3
	close(dirf);
E 3
I 3
	closedir(dirp);
E 3
	return;

D 3
patherr:
E 3
I 3
patherr1:
	closedir(dirp);
patherr2:
E 3
	Perror(gpath);
D 3
}

copdent(to, from)
	register char *to, *from;
{
	register int cnt = DIRSIZ;

	do
		*to++ = *from++;
	while (--cnt);
	*to = 0;
E 3
}

execbrc(p, s)
	char *p, *s;
{
	char restbuf[BUFSIZ + 2];
	register char *pe, *pm, *pl;
	int brclev = 0;
	char *lm, savec, *sgpathp;

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
			error("Missing ]");
		continue;
	}
pend:
	if (brclev || !*pe)
		error("Missing }");
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

D 15
	case ','|QUOTE:
E 15
	case ',':
		if (brclev)
			continue;
doit:
		savec = *pm;
		*pm = 0;
D 8
		strcpy(lm, pl);
		strcat(restbuf, pe + 1);
E 8
I 8
		(void) strcpy(lm, pl);
		(void) strcat(restbuf, pe + 1);
E 8
		*pm = savec;
		if (s == 0) {
			sgpathp = gpathp;
			expand(restbuf);
			gpathp = sgpathp;
			*gpathp = 0;
		} else if (amatch(s, restbuf))
			return (1);
		sort();
		pl = pm + 1;
		continue;

	case '[':
		for (pm++; *pm && *pm != ']'; pm++)
			continue;
		if (!*pm)
			error("Missing ]");
		continue;
	}
	return (0);
}

match(s, p)
	char *s, *p;
{
	register int c;
	register char *sentp;
	char sglobbed = globbed;

	if (*s == '.' && *p != '.')
		return (0);
	sentp = entp;
	entp = s;
	c = amatch(s, p);
	entp = sentp;
	globbed = sglobbed;
	return (c);
}

amatch(s, p)
	register char *s, *p;
{
	register int scc;
	int ok, lc;
	char *sgpathp;
	struct stat stb;
	int c, cc;

	globbed = 1;
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
			if (cc == 0)
				error("Missing ]");
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

		case 0:
			return (scc == 0);

		default:
D 7
			if (c != scc)
E 7
I 7
			if ((c & TRIM) != scc)
E 7
				return (0);
			continue;

		case '?':
			if (scc == 0)
				return (0);
			continue;

		case '/':
			if (scc)
				return (0);
slash:
			s = entp;
			sgpathp = gpathp;
			while (*s)
				addpath(*s++);
			addpath('/');
			if (stat(gpath, &stb) == 0 && isdir(stb))
				if (*p == 0) {
					Gcat(gpath, "");
					globcnt++;
				} else
					expand(p);
			gpathp = sgpathp;
			*gpathp = 0;
			return (0);
		}
	}
}

Gmatch(s, p)
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
			if (cc == 0)
				bferr("Missing ]");
			continue;

		case '*':
			if (!*p)
				return (1);
			for (s--; *s; s++)
				if (Gmatch(s, p))
					return (1);
			return (0);

		case 0:
			return (scc == 0);

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

Gcat(s1, s2)
D 8
	register char *s1, *s2;
E 8
I 8
	char *s1, *s2;
E 8
{
I 8
	register char *p, *q;
	int n;
E 8

D 8
	gnleft -= strlen(s1) + strlen(s2) + 1;
E 8
I 8
	for (p = s1; *p++;)
		;
	for (q = s2; *q++;)
		;
	gnleft -= (n = (p - s1) + (q - s2) - 1);
E 8
	if (gnleft <= 0 || ++gargc >= GAVSIZ)
		error("Arguments too long");
	gargv[gargc] = 0;
D 8
	gargv[gargc - 1] = strspl(s1, s2);
E 8
I 8
	p = gargv[gargc - 1] = xalloc((unsigned)n);
	for (q = s1; *p++ = *q++;)
		;
	for (p--, q = s2; *p++ = *q++;)
		;
E 8
}

addpath(c)
	char c;
{

	if (gpathp >= lastgpathp)
		error("Pathname too long");
D 10
	*gpathp++ = c;
E 10
I 10
	*gpathp++ = c & TRIM;
E 10
	*gpathp = 0;
}

rscan(t, f)
	register char **t;
	int (*f)();
{
D 8
	register char *p, c;
E 8
I 8
	register char *p;
E 8

D 8
	while (p = *t++) {
		if (f == tglob)
			if (*p == '~')
				gflag |= 2;
			else if (eq(p, "{") || eq(p, "{}"))
				continue;
		while (c = *p++)
			(*f)(c);
	}
E 8
I 8
	while (p = *t++)
		while (*p)
			(*f)(*p++);
E 8
}

D 8
scan(t, f)
E 8
I 8
trim(t)
E 8
	register char **t;
D 8
	int (*f)();
E 8
{
D 8
	register char *p, c;
E 8
I 8
	register char *p;
E 8

	while (p = *t++)
D 8
		while (c = *p)
			*p++ = (*f)(c);
E 8
I 8
D 9
		while (*p++ &= TRIM)
			;
E 9
I 9
		while (*p)
			*p++ &= TRIM;
E 9
E 8
}

D 8
tglob(c)
	register char c;
E 8
I 8
tglob(t)
	register char **t;
E 8
{
I 8
	register char *p, c;
E 8

D 8
	if (any(c, globchars))
		gflag |= c == '{' ? 2 : 1;
	return (c);
E 8
I 8
	while (p = *t++) {
		if (*p == '~')
			gflag |= 2;
		else if (*p == '{' && (p[1] == '\0' || p[1] == '}' && p[2] == '\0'))
			continue;
		while (c = *p++)
D 13
			if (cmap(c, _GLOB))
E 13
I 13
			if (isglob(c))
E 13
				gflag |= c == '{' ? 2 : 1;
	}
E 8
}

D 8
trim(c)
	char c;
{

	return (c & TRIM);
}

tback(c)
	char c;
{

	if (c == '`')
		gflag = 1;
}

E 8
char *
globone(str)
	register char *str;
{
	char *gv[2];
	register char **gvp;
	register char *cp;

	gv[0] = str;
	gv[1] = 0;
	gflag = 0;
D 8
	rscan(gv, tglob);
E 8
I 8
	tglob(gv);
E 8
	if (gflag) {
		gvp = glob(gv);
		if (gvp == 0) {
			setname(str);
			bferr("No match");
		}
		cp = *gvp++;
		if (cp == 0)
			cp = "";
		else if (*gvp) {
			setname(str);
			bferr("Ambiguous");
		} else
			cp = strip(cp);
/*
		if (cp == 0 || *gvp) {
			setname(str);
			bferr(cp ? "Ambiguous" : "No output");
		}
*/
		xfree((char *)gargv); gargv = 0;
	} else {
D 8
		scan(gv, trim);
E 8
I 8
		trim(gv);
E 8
		cp = savestr(gv[0]);
	}
	return (cp);
}

/*
 * Command substitute cp.  If literal, then this is
 * a substitution from a << redirection, and so we should
 * not crunch blanks and tabs, separating words only at newlines.
 */
char **
dobackp(cp, literal)
	char *cp;
	bool literal;
{
	register char *lp, *rp;
	char *ep;
	char word[BUFSIZ];
	char *apargv[GAVSIZ + 2];

	if (pargv) {
		abort();
		blkfree(pargv);
	}
	pargv = apargv;
	pargv[0] = NOSTR;
	pargcp = pargs = word;
	pargc = 0;
	pnleft = BUFSIZ - 4;
	for (;;) {
		for (lp = cp; *lp != '`'; lp++) {
			if (*lp == 0) {
				if (pargcp != pargs)
					pword();
#ifdef GDEBUG
				printf("leaving dobackp\n");
#endif
				return (pargv = copyblk(pargv));
			}
			psave(*lp);
		}
		lp++;
		for (rp = lp; *rp && *rp != '`'; rp++)
			if (*rp == '\\') {
				rp++;
				if (!*rp)
					goto oops;
			}
		if (!*rp)
oops:
			error("Unmatched `");
		ep = savestr(lp);
		ep[rp - lp] = 0;
		backeval(ep, literal);
#ifdef GDEBUG
		printf("back from backeval\n");
#endif
		cp = rp + 1;
	}
}

backeval(cp, literal)
	char *cp;
	bool literal;
{
	int pvec[2];
	int quoted = (literal || (cp[0] & QUOTE)) ? QUOTE : 0;
	char ibuf[BUFSIZ];
	register int icnt = 0, c;
	register char *ip;
	bool hadnl = 0;
	char *fakecom[2];
	struct command faket;

	faket.t_dtyp = TCOM;
	faket.t_dflg = 0;
	faket.t_dlef = 0;
	faket.t_drit = 0;
	faket.t_dspr = 0;
	faket.t_dcom = fakecom;
	fakecom[0] = "` ... `";
	fakecom[1] = 0;
	/*
	 * We do the psave job to temporarily change the current job
	 * so that the following fork is considered a separate job.
	 * This is so that when backquotes are used in a
	 * builtin function that calls glob the "current job" is not corrupted.
	 * We only need one level of pushed jobs as long as we are sure to
	 * fork here.
	 */
	psavejob();
	/*
	 * It would be nicer if we could integrate this redirection more
	 * with the routines in sh.sem.c by doing a fake execute on a builtin
	 * function that was piped out.
	 */
	mypipe(pvec);
	if (pfork(&faket, -1) == 0) {
		struct wordent paraml;
		struct command *t;

D 8
		close(pvec[0]);
		dmove(pvec[1], 1);
		dmove(SHDIAG, 2);
E 8
I 8
		(void) close(pvec[0]);
		(void) dmove(pvec[1], 1);
		(void) dmove(SHDIAG, 2);
E 8
		initdesc();
		arginp = cp;
		while (*cp)
			*cp++ &= TRIM;
D 8
		lex(&paraml);
E 8
I 8
		(void) lex(&paraml);
E 8
		if (err)
			error(err);
		alias(&paraml);
		t = syntax(paraml.next, &paraml, 0);
		if (err)
			error(err);
		if (t)
			t->t_dflg |= FPAR;
I 6
D 7
		sigignore(SIGTSTP);
		sigignore(SIGTTIN);
		sigignore(SIGTTOU);
E 7
I 7
D 8
		signal(SIGTSTP, SIG_IGN);
		signal(SIGTTIN, SIG_IGN);
		signal(SIGTTOU, SIG_IGN);
E 8
I 8
		(void) signal(SIGTSTP, SIG_IGN);
		(void) signal(SIGTTIN, SIG_IGN);
		(void) signal(SIGTTOU, SIG_IGN);
E 8
E 7
E 6
		execute(t, -1);
		exitstat();
	}
	xfree(cp);
D 8
	close(pvec[1]);
E 8
I 8
	(void) close(pvec[1]);
E 8
	do {
		int cnt = 0;
		for (;;) {
			if (icnt == 0) {
				ip = ibuf;
				icnt = read(pvec[0], ip, BUFSIZ);
				if (icnt <= 0) {
					c = -1;
					break;
				}
			}
			if (hadnl)
				break;
			--icnt;
			c = (*ip++ & TRIM);
			if (c == 0)
				break;
			if (c == '\n') {
				/*
				 * Continue around the loop one
				 * more time, so that we can eat
				 * the last newline without terminating
				 * this word.
				 */
				hadnl = 1;
				continue;
			}
			if (!quoted && (c == ' ' || c == '\t'))
				break;
			cnt++;
			psave(c | quoted);
		}
		/*
		 * Unless at end-of-file, we will form a new word
		 * here if there were characters in the word, or in
		 * any case when we take text literally.  If
		 * we didn't make empty words here when literal was
		 * set then we would lose blank lines.
		 */
		if (c != -1 && (cnt || literal))
			pword();
		hadnl = 0;
	} while (c >= 0);
#ifdef GDEBUG
	printf("done in backeval, pvec: %d %d\n", pvec[0], pvec[1]);
	printf("also c = %c <%o>\n", c, c);
#endif
D 8
	close(pvec[0]);
E 8
I 8
	(void) close(pvec[0]);
E 8
	pwait();
	prestjob();
}

psave(c)
	char c;
{

	if (--pnleft <= 0)
		error("Word too long");
	*pargcp++ = c;
}

pword()
{

	psave(0);
	if (pargc == GAVSIZ)
		error("Too many words from ``");
	pargv[pargc++] = savestr(pargs);
	pargv[pargc] = NOSTR;
#ifdef GDEBUG
	printf("got word %s\n", pargv[pargc-1]);
#endif
	pargcp = pargs;
	pnleft = BUFSIZ - 4;
}
E 1
