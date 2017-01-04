/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
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
 */

#ifndef lint
static char sccsid[] = "@(#)glob.c	5.1 (Berkeley) 6/10/03";
#endif /* not lint */

/*
 * This is a special light version of C-shell glob for ftpd LIST/NLST.
 */

#include <sys/param.h>
#include <sys/dir.h>

#include <stdio.h>

char	*malloc(), *strcpy(), *strcat();

char	*globchars = "{[*?";

isaglob(pat)
	char *pat;
{
	register char *cp;

	for (cp = pat; *cp; cp++)
		if (any(*cp, globchars))
			return(1);
	return(0);
}

glob(pattern, gav, room)
	register char *pattern;
	char **gav;
	int room;
{
	register struct direct *dp;
	register DIR *dirp;
	register char *buf;
	int gac;

	dirp = opendir(".");
	if (dirp == NULL)
		return(-1);
	gac = 0;
	while ((dp = readdir(dirp)) != NULL) {
		if (dp->d_ino == 0)
			continue;
		if (match(dp->d_name, pattern)) {
			buf = malloc(dp->d_namlen + 1);
			if (buf == NULL)
				break;
			strcpy(buf, dp->d_name);
			*gav++ = buf;
			gac++;
			if (!--room)
				break;
		}
	}
	closedir(dirp);
	return(gac);
}

static
execbrc(p, s)
	char *p, *s;
{
	char restbuf[BUFSIZ + 2];
	register char *pe, *pm, *pl;
	int brclev = 0;
	char *lm, savec;

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
		continue;
	}
pend:
	brclev = 0;
	for (pl = pm = p; pm <= pe; pm++)
	switch (*pm) {

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
		(void) strcpy(lm, pl);
		(void) strcat(restbuf, pe + 1);
		*pm = savec;
		if (amatch(s, restbuf))
			return (1);
		pl = pm + 1;
		if (brclev)
			return (0);
		continue;

	case '[':
		for (pm++; *pm && *pm != ']'; pm++)
			continue;
		if (!*pm)
			pm--;
		continue;
	}
	if (brclev)
		goto doit;
	return (0);
}

static
match(s, p)
	char *s, *p;
{
	register int c;

	if (*s == '.' && *p != '.')
		return (0);
	c = amatch(s, p);
	return (c);
}

static
amatch(s, p)
	register u_char *s, *p;
{
	register int scc;
	int ok, lc;
	int c, cc;

	for (;;) {
		scc = *s++;
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
				if (ok)
					p--;
				else
					return 0;
			continue;

		case '*':
			if (!*p)
				return (1);
			s--;
			do {
				if (amatch(s, p))
					return (1);
			} while (*s++);
			return (0);

		case 0:
			return (scc == 0);

		default:
			if (c != scc)
				return (0);
			continue;

		case '?':
			if (scc == 0)
				return (0);
			continue;
		}
	}
}

any(c, s)
	register int c;
	register char *s;
{

	while (*s)
		if (*s++ == c)
			return(1);
	return(0);
}
