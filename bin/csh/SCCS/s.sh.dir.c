h21580
s 00002/00001/00472
d D 5.4 88/04/14 09:56:08 bostic 8 7
c use SHDIAG, not "2", already mucked with descriptors
e
s 00002/00002/00471
d D 5.3 85/06/11 18:59:44 edward 7 6
c cd <varname> bug reported by Jay Lapreau
e
s 00003/00003/00470
d D 5.2 85/06/06 13:11:17 edward 6 5
c cleaning up after bozos
e
s 00008/00002/00465
d D 5.1 85/06/04 10:55:50 dist 5 4
c Add copyright
e
s 00147/00041/00320
d D 4.4 85/05/02 17:51:13 edward 4 3
c expand symbolic link before ..
e
s 00014/00012/00347
d D 4.3 84/12/13 14:42:16 edward 3 2
c performance
e
s 00006/00001/00353
d D 4.2 83/02/03 09:12:14 sam 2 1
c getwd moved to libc.a and error return changed
e
s 00354/00000/00000
d D 4.1 80/10/09 12:40:27 bill 1 0
c date and time created 80/10/09 12:40:27 by bill
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
D 3
static	char *sccsid = "%Z%%M% %I% %G%";
E 3
I 3
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
E 3

#include "sh.h"
#include "sh.dir.h"

/*
 * C Shell - directory management
 */

struct	directory *dfind();
char	*dfollow();
I 4
char	*dcanon();
E 4
struct	directory dhead;		/* "head" of loop */
int	printd;				/* force name to be printed */
static	char *fakev[] = { "dirs", NOSTR };

/*
 * dinit - initialize current working directory
 */
dinit(hp)
	char *hp;
{
	register char *cp;
	register struct directory *dp;
D 4
	char path[BUFSIZ];
E 4
I 4
	char path[MAXPATHLEN];
E 4

	if (loginsh && hp)
		cp = hp;
D 2
	else
E 2
I 2
	else {
E 2
		cp = getwd(path);
I 2
		if (cp == NULL) {
D 3
			write(2, path, strlen(path));
E 3
I 3
D 8
			(void) write(2, path, strlen(path));
E 8
I 8
#define	WDERR	"csh: can't get current directory.\n"
			(void) write(SHDIAG, WDERR, strlen(WDERR));
E 8
E 3
			exit(1);
		}
	}
E 2
	dp = (struct directory *)calloc(sizeof (struct directory), 1);
	dp->di_name = savestr(cp);
	dp->di_count = 0;
	dhead.di_next = dhead.di_prev = dp;
	dp->di_next = dp->di_prev = &dhead;
	printd = 0;
	dnewcwd(dp);
}

/*
 * dodirs - list all directories in directory loop
 */
dodirs(v)
	char **v;
{
	register struct directory *dp;
	bool lflag;
	char *hp = value("home");

	if (*hp == '\0')
		hp = NOSTR;
	if (*++v != NOSTR)
		if (eq(*v, "-l") && *++v == NOSTR)
			lflag = 1;
		else
			error("Usage: dirs [ -l ]");
	else
		lflag = 0;
	dp = dcwd;
	do {
		if (dp == &dhead)
			continue;
		if (!lflag && hp != NOSTR) {
			dtildepr(hp, dp->di_name);
		} else
			printf("%s", dp->di_name);
		printf(" ");
	} while ((dp = dp->di_prev) != dcwd);
	printf("\n");
}

dtildepr(home, dir)
	register char *home, *dir;
{

	if (!eq(home, "/") && prefix(home, dir))
		printf("~%s", dir + strlen(home));
	else
		printf("%s", dir);
}

/*
 * dochngd - implement chdir command.
 */
dochngd(v)
	char **v;
{
	register char *cp;
	register struct directory *dp;

	printd = 0;
	if (*++v == NOSTR) {
		if ((cp = value("home")) == NOSTR || *cp == 0)
			bferr("No home directory");
		if (chdir(cp) < 0)
			bferr("Can't change to home directory");
		cp = savestr(cp);
	} else if ((dp = dfind(*v)) != 0) {
		printd = 1;
		if (chdir(dp->di_name) < 0)
			Perror(dp->di_name);
		dcwd->di_prev->di_next = dcwd->di_next;
		dcwd->di_next->di_prev = dcwd->di_prev;
		goto flushcwd;
	} else
		cp = dfollow(*v);
	dp = (struct directory *)calloc(sizeof (struct directory), 1);
	dp->di_name = cp;
	dp->di_count = 0;
	dp->di_next = dcwd->di_next;
	dp->di_prev = dcwd->di_prev;
	dp->di_prev->di_next = dp;
	dp->di_next->di_prev = dp;
flushcwd:
	dfree(dcwd);
	dnewcwd(dp);
}

/*
 * dfollow - change to arg directory; fall back on cdpath if not valid
 */
char *
dfollow(cp)
	register char *cp;
{
D 4
	register char **cdp;
E 4
I 4
	register char *dp;
E 4
	struct varent *c;
D 4
	
E 4
I 4

E 4
	cp = globone(cp);
D 4
	if (chdir(cp) == 0)
E 4
I 4
	if (chdir(cp) >= 0)
E 4
		goto gotcha;
	if (cp[0] != '/' && !prefix("./", cp) && !prefix("../", cp)
	    && (c = adrof("cdpath"))) {
D 4
		for (cdp = c->vec; *cdp; cdp++) {
			char buf[BUFSIZ];
E 4
I 4
		char **cdp;
		register char *p;
		char buf[MAXPATHLEN];
E 4

D 3
			strcpy(buf, *cdp);
			strcat(buf, "/");
			strcat(buf, cp);
E 3
I 3
D 4
			(void) strcpy(buf, *cdp);
			(void) strcat(buf, "/");
			(void) strcat(buf, cp);
E 4
I 4
		for (cdp = c->vec; *cdp; cdp++) {
			for (dp = buf, p = *cdp; *dp++ = *p++;)
				;
			dp[-1] = '/';
			for (p = cp; *dp++ = *p++;)
				;
E 4
E 3
			if (chdir(buf) >= 0) {
				printd = 1;
				xfree(cp);
				cp = savestr(buf);
				goto gotcha;
			}
		}
	}
D 4
	if (adrof(cp)) {
		char *dp = value(cp);

		if (dp[0] == '/' || dp[0] == '.')
			if (chdir(dp) >= 0) {
				xfree(cp);
				cp = savestr(dp);
				printd = 1;
				goto gotcha;
			}
E 4
I 4
D 7
	if ((dp = value(cp))[0] &&
	    (dp[0] == '/' || dp[0] == '.' && chdir(dp) >= 0)) {
E 7
I 7
	dp = value(cp);
	if ((dp[0] == '/' || dp[0] == '.') && chdir(dp) >= 0) {
E 7
		xfree(cp);
		cp = savestr(dp);
		printd = 1;
		goto gotcha;
E 4
	}
D 4
	xfree(cp);
E 4
I 4
	xfree(cp);			/* XXX, use after free */
E 4
	Perror(cp);

gotcha:
	if (*cp != '/') {
D 3
		char *dp = calloc(strlen(cp) + strlen(dcwd->di_name) + 2, 1);
		strcpy(dp, dcwd->di_name);
		strcat(dp, "/");
		strcat(dp, cp);
E 3
I 3
D 4
		char *dp = calloc((unsigned) (strlen(cp) + strlen(dcwd->di_name) + 2), 1);
		(void) strcpy(dp, dcwd->di_name);
		(void) strcat(dp, "/");
		(void) strcat(dp, cp);
E 4
I 4
		register char *p, *q;
		int cwdlen;

		/*
		 * All in the name of efficiency?
		 */
		for (p = dcwd->di_name; *p++;)
			;
		if ((cwdlen = p - dcwd->di_name - 1) == 1)	/* root */
			cwdlen = 0;
		for (p = cp; *p++;)
			;
		dp = xalloc((unsigned) (cwdlen + (p - cp) + 1));
		for (p = dp, q = dcwd->di_name; *p++ = *q++;)
			;
		if (cwdlen)
			p[-1] = '/';
		else
			p--;			/* don't add a / after root */
		for (q = cp; *p++ = *q++;)
			;
E 4
E 3
		xfree(cp);
		cp = dp;
D 4
	}
	dcanon(cp);
	return (cp);
E 4
I 4
		dp += cwdlen;
	} else
		dp = cp;
	return dcanon(cp, dp);
E 4
}

/*
 * dopushd - push new directory onto directory stack.
 *	with no arguments exchange top and second.
 *	with numeric argument (+n) bring it to top.
 */
dopushd(v)
	char **v;
{
	register struct directory *dp;

	printd = 1;
	if (*++v == NOSTR) {
		if ((dp = dcwd->di_prev) == &dhead)
			dp = dhead.di_prev;
		if (dp == dcwd)
			bferr("No other directory");
		if (chdir(dp->di_name) < 0)
			Perror(dp->di_name);
		dp->di_prev->di_next = dp->di_next;
		dp->di_next->di_prev = dp->di_prev;
		dp->di_next = dcwd->di_next;
		dp->di_prev = dcwd;
		dcwd->di_next->di_prev = dp;
		dcwd->di_next = dp;
	} else if (dp = dfind(*v)) {
		if (chdir(dp->di_name) < 0)
			Perror(dp->di_name);
	} else {
		register char *cp;

		cp = dfollow(*v);
		dp = (struct directory *)calloc(sizeof (struct directory), 1);
		dp->di_name = cp;
		dp->di_count = 0;
		dp->di_prev = dcwd;
		dp->di_next = dcwd->di_next;
		dcwd->di_next = dp;
		dp->di_next->di_prev = dp;
	}
	dnewcwd(dp);
}

/*
 * dfind - find a directory if specified by numeric (+n) argument
 */
struct directory *
dfind(cp)
	register char *cp;
{
	register struct directory *dp;
	register int i;
	register char *ep;

	if (*cp++ != '+')
		return (0);
	for (ep = cp; digit(*ep); ep++)
		continue;
	if (*ep)
		return (0);
	i = getn(cp);
	if (i <= 0)
		return (0);
	for (dp = dcwd; i != 0; i--) {
		if ((dp = dp->di_prev) == &dhead)
			dp = dp->di_prev;
		if (dp == dcwd)
			bferr("Directory stack not that deep");
	}
	return (dp);
}

/*
 * dopopd - pop a directory out of the directory stack
 *	with a numeric argument just discard it.
 */
dopopd(v)
	char **v;
{
	register struct directory *dp, *p;

	printd = 1;
	if (*++v == NOSTR)
		dp = dcwd;
	else if ((dp = dfind(*v)) == 0)
		bferr("Bad directory");
	if (dp->di_prev == &dhead && dp->di_next == &dhead)
		bferr("Directory stack empty");
	if (dp == dcwd) {
		if ((p = dp->di_prev) == &dhead)
			p = dhead.di_prev;
		if (chdir(p->di_name) < 0)
			Perror(p->di_name);
	}
	dp->di_prev->di_next = dp->di_next;
	dp->di_next->di_prev = dp->di_prev;
	if (dp == dcwd)
		dnewcwd(p);
	else
		dodirs(fakev);
	dfree(dp);
}

/*
 * dfree - free the directory (or keep it if it still has ref count)
 */
dfree(dp)
	register struct directory *dp;
{

	if (dp->di_count != 0)
		dp->di_next = dp->di_prev = 0;
	else
		xfree(dp->di_name), xfree((char *)dp);
}

/*
 * dcanon - canonicalize the pathname, removing excess ./ and ../ etc.
 *	we are of course assuming that the file system is standardly
 *	constructed (always have ..'s, directories have links)
 */
D 4
dcanon(cp)
	char *cp;
E 4
I 4
char *
dcanon(cp, p)
	register char *cp, *p;
E 4
{
D 4
	register char *p, *sp;
	register bool slash;
E 4
I 4
	register char *sp;
	register char *p1, *p2;		/* general purpose */
	bool slash;
E 4

	if (*cp != '/')
		abort();
D 4
	for (p = cp; *p; ) {		/* for each component */
E 4
I 4
	while (*p) {			/* for each component */
E 4
		sp = p;			/* save slash address */
D 4
		while(*++p == '/')	/* flush extra slashes */
E 4
I 4
		while (*++p == '/')	/* flush extra slashes */
E 4
			;
		if (p != ++sp)
D 3
			strcpy(sp, p);
E 3
I 3
D 4
			(void) strcpy(sp, p);
E 4
I 4
			for (p1 = sp, p2 = p; *p1++ = *p2++;)
				;
E 4
E 3
		p = sp;			/* save start of component */
		slash = 0;
D 4
		while(*++p)		/* find next slash or end of path */
E 4
I 4
		while (*++p)		/* find next slash or end of path */
E 4
			if (*p == '/') {
				slash = 1;
				*p = 0;
				break;
			}
		if (*sp == '\0')	/* if component is null */
			if (--sp == cp)	/* if path is one char (i.e. /) */
				break;
			else
				*sp = '\0';
D 4
		else if (eq(".", sp)) {
E 4
I 4
		else if (sp[0] == '.' && sp[1] == 0) {
E 4
			if (slash) {
D 3
				strcpy(sp, ++p);
E 3
I 3
D 4
				(void) strcpy(sp, ++p);
E 4
I 4
				for (p1 = sp, p2 = p + 1; *p1++ = *p2++;)
					;
E 4
E 3
				p = --sp;
			} else if (--sp != cp)
				*sp = '\0';
D 4
		} else if (eq("..", sp)) {
			if (--sp != cp)
E 4
I 4
		} else if (sp[0] == '.' && sp[1] == '.' && sp[2] == 0) {
			char link[MAXPATHLEN];
			int cc;
			char *newcp;

			/*
			 * We have something like "yyy/xxx/..", where "yyy"
			 * can be null or a path starting at /, and "xxx"
			 * is a single component.
			 * Before compressing "xxx/..", we want to expand
			 * "yyy/xxx", if it is a symbolic link.
			 */
			*--sp = 0;	/* form the pathname for readlink */
			if (sp != cp &&
			    (cc = readlink(cp, link, sizeof link)) >= 0) {
				link[cc] = '\0';
				if (slash)
					*p = '/';
				/*
				 * Point p to the '/' in "/..", and restore
				 * the '/'.
				 */
				*(p = sp) = '/';
				/*
				 * find length of p
				 */
				for (p1 = p; *p1++;)
					;
				if (*link != '/') {
					/*
					 * Relative path, expand it between
					 * the "yyy/" and the "/..".
					 * First, back sp up to the character
					 * past "yyy/".
					 */
					while (*--sp != '/')
						;
					sp++;
					*sp = 0;
					/*
					 * New length is
					 * "yyy/" + link + "/.." and rest
					 */
					p1 = newcp = xalloc((unsigned)
						((sp - cp) + cc + (p1 - p)));
					/*
					 * Copy new path into newcp
					 */
					for (p2 = cp; *p1++ = *p2++;)
						;
					for (p1--, p2 = link; *p1++ = *p2++;)
						;
					for (p1--, p2 = p; *p1++ = *p2++;)
						;
					/*
					 * Restart canonicalization at
					 * expanded "/xxx".
					 */
					p = sp - cp - 1 + newcp;
				} else {
					/*
					 * New length is link + "/.." and rest
					 */
					p1 = newcp = xalloc((unsigned)
						(cc + (p1 - p)));
					/*
					 * Copy new path into newcp
					 */
					for (p2 = link; *p1++ = *p2++;)
						;
					for (p1--, p2 = p; *p1++ = *p2++;)
						;
					/*
					 * Restart canonicalization at beginning
					 */
					p = newcp;
				}
				xfree(cp);
				cp = newcp;
				continue;	/* canonicalize the link */
			}
			*sp = '/';
			if (sp != cp)
E 4
				while (*--sp != '/')
					;
			if (slash) {
D 3
				strcpy(++sp, ++p);
E 3
I 3
D 4
				(void) strcpy(++sp, ++p);
E 3
				p = --sp;
E 4
I 4
				for (p1 = sp + 1, p2 = p + 1; *p1++ = *p2++;)
					;
				p = sp;
E 4
			} else if (cp == sp)
				*++sp = '\0';
			else
				*sp = '\0';
		} else if (slash)
			*p = '/';
	}
I 4
	return cp;
E 4
}

/*
 * dnewcwd - make a new directory in the loop the current one
 */
dnewcwd(dp)
	register struct directory *dp;
{

	dcwd = dp;
	set("cwd", savestr(dcwd->di_name));
	if (printd)
		dodirs(fakev);
}
E 1
