h22638
s 00087/00027/00322
d D 5.2 87/09/11 16:18:25 jak 6 5
c Added TERMPATH support, with default path of "~/.termcap /etc/termcap"
e
s 00007/00001/00342
d D 5.1 85/06/05 11:30:29 dist 5 4
c Add copyright
e
s 00008/00008/00335
d D 4.4 85/01/09 14:14:49 serge 4 3
c check terminal type against $TERMCAP in tgetent() correctly
e
s 00006/00003/00337
d D 4.3 84/12/23 17:21:54 sam 3 2
c correct file descriptor initialization; reset hopcount when 
c unwinding recursive calls; from brl
e
s 00001/00001/00339
d D 4.2 84/11/06 09:30:49 ralph 2 1
c check for '\0' not q == NULL.
e
s 00340/00000/00000
d D 4.1 83/06/27 13:57:03 sam 1 0
c date and time created 83/06/27 13:57:03 by sam
e
u
U
t
T
I 5
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 5
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 5
#endif
E 5
I 5
#endif not lint
E 5

#define	BUFSIZ		1024
#define MAXHOP		32	/* max number of tc= indirections */
D 6
#define	E_TERMCAP	"/etc/termcap"
E 6
I 6
#define	PBUFSIZ		512	/* max length of filename path */
#define	PVECSIZ		32	/* max number of names in path */
#define DEF_PATH	".termcap /etc/termcap"
E 6

#include <ctype.h>
/*
 * termcap - routines for dealing with the terminal capability data base
 *
 * BUG:		Should use a "last" pointer in tbuf, so that searching
 *		for capabilities alphabetically would not be a n**2/2
 *		process when large numbers of capabilities are given.
 * Note:	If we add a last pointer now we will screw up the
 *		tc capability. We really should compile termcap.
 *
 * Essentially all the work here is scanning and decoding escapes
 * in string capabilities.  We don't use stdio because the editor
 * doesn't, and because living w/o it is not hard.
 */

static	char *tbuf;
static	int hopcount;	/* detect infinite loops in termcap, init 0 */
I 6
static	char pathbuf[PBUFSIZ];		/* holds raw path of filenames */
static	char *pathvec[PVECSIZ];		/* to point to names in pathbuf */
static	char **pvec;			/* holds usable tail of path vector */
E 6
char	*tskip();
char	*tgetstr();
char	*tdecode();
char	*getenv();

/*
D 6
 * Get an entry for terminal name in buffer bp,
 * from the termcap file.  Parse is very rudimentary;
 * we just notice escaped newlines.
E 6
I 6
 * Get an entry for terminal name in buffer bp from the termcap file.
E 6
 */
tgetent(bp, name)
	char *bp, *name;
{
I 6
	register char *p;
E 6
	register char *cp;
	register int c;
D 6
	register int i = 0, cnt = 0;
	char ibuf[BUFSIZ];
D 4
	char *cp2;
E 4
	int tf;
E 6
I 6
	char *term, *home, *termpath;
	char **fname = pathvec;
E 6

I 6
	pvec = pathvec;
E 6
	tbuf = bp;
D 3
	tf = 0;
E 3
I 3
D 6
	tf = -1;
E 6
I 6
	p = pathbuf;
E 6
E 3
#ifndef V6
	cp = getenv("TERMCAP");
	/*
	 * TERMCAP can have one of two things in it. It can be the
	 * name of a file to use instead of /etc/termcap. In this
	 * case it better start with a "/". Or it can be an entry to
	 * use so we don't have to read the file. In this case it
D 6
	 * has to already have the newlines crunched out.
E 6
I 6
	 * has to already have the newlines crunched out.  If TERMCAP
	 * does not hold a file name then a path of names is searched
	 * instead.  The path is found in the TERMPATH variable, or
	 * becomes "$HOME/.termcap /etc/termcap" if no TERMPATH exists.
E 6
	 */
D 6
	if (cp && *cp) {
D 4
		if (*cp!='/') {
			cp2 = getenv("TERM");
			if (cp2==(char *) 0 || strcmp(name,cp2)==0) {
E 4
I 4
		if (*cp == '/') {
			tf = open(cp, 0);
		} else {
			tbuf = cp;
			c = tnamatch(name);
			tbuf = bp;
			if (c) {
E 4
				strcpy(bp,cp);
				return(tnchktc());
D 4
			} else {
				tf = open(E_TERMCAP, 0);
E 4
			}
E 6
I 6
	if (!cp || *cp != '/') {	/* no TERMCAP or it holds an entry */
		if (termpath = getenv("TERMPATH"))
			strncpy(pathbuf, termpath, PBUFSIZ);
		else {
			if (home = getenv("HOME")) {	/* set up default */
				p += strlen(home);	/* path, looking in */
				strcpy(pathbuf, home);	/* $HOME first */
				*p++ = '/';
			}	/* if no $HOME look in current directory */
			strncpy(p, DEF_PATH, PBUFSIZ - (p - pathbuf));
E 6
D 4
		} else
			tf = open(cp, 0);
E 4
I 4
		}
E 4
	}
D 3
	if (tf==0)
E 3
I 3
D 6
	if (tf < 0)
E 3
		tf = open(E_TERMCAP, 0);
E 6
I 6
	else				/* user-defined name in TERMCAP */
		strncpy(pathbuf, cp, PBUFSIZ);	/* still can be tokenized */
E 6
#else
D 6
	tf = open(E_TERMCAP, 0);
E 6
I 6
	strncpy(pathbuf, "/etc/termcap", PBUFSIZ);
E 6
#endif
D 6
	if (tf < 0)
		return (-1);
E 6
I 6
	*fname++ = pathbuf;	/* tokenize path into vector of names */
	while (*++p)
		if (*p == ' ' || *p == ':') {
			*p = '\0';
			while (*++p)
				if (*p != ' ' && *p != ':')
					break;
			if (*p == '\0')
				break;
			*fname++ = p;
			if (fname >= pathvec + PVECSIZ) {
				fname--;
				break;
			}
		}
	*fname = (char *) 0;			/* mark end of vector */
	if (cp && *cp && *cp != '/') {
		tbuf = cp;
		c = tnamatch(name);
		tbuf = bp;
		if (c) {
			strcpy(bp,cp);
			return (tnchktc());
		}
	}
	return (tfindent(bp, name));	/* find terminal entry in path */
}

/*
 * tfindent - reads through the list of files in pathvec as if they were one
 * continuous file searching for terminal entries along the way.  It will
 * participate in indirect recursion if the call to tnchktc() finds a tc=
 * field, which is only searched for in the current file and files ocurring
 * after it in pathvec.  The usable part of this vector is kept in the global
 * variable pvec.  Terminal entries may not be broken across files.  Parse is
 * very rudimentary; we just notice escaped newlines.
 */
tfindent(bp, name)
	char *bp, *name;
{
	register char *cp;
	register int c;
	register int i, cnt;
	char ibuf[BUFSIZ];
	int opencnt = 0;
	int tf;

	tbuf = bp;
nextfile:
	i = cnt = 0;
	while (*pvec && (tf = open(*pvec, 0)) < 0)
		pvec++;
	if (!*pvec)
		return (opencnt ? 0 : -1);
	opencnt++;
E 6
	for (;;) {
		cp = bp;
		for (;;) {
			if (i == cnt) {
				cnt = read(tf, ibuf, BUFSIZ);
				if (cnt <= 0) {
					close(tf);
D 6
					return (0);
E 6
I 6
					pvec++;
					goto nextfile;
E 6
				}
				i = 0;
			}
			c = ibuf[i++];
			if (c == '\n') {
				if (cp > bp && cp[-1] == '\\'){
					cp--;
					continue;
				}
				break;
			}
			if (cp >= bp+BUFSIZ) {
				write(2,"Termcap entry too long\n", 23);
				break;
			} else
				*cp++ = c;
		}
		*cp = 0;

		/*
		 * The real work for the match.
		 */
		if (tnamatch(name)) {
			close(tf);
			return(tnchktc());
		}
	}
}

/*
 * tnchktc: check the last entry, see if it's tc=xxx. If so,
 * recursively find xxx and append that entry (minus the names)
 * to take the place of the tc=xxx entry. This allows termcap
 * entries to say "like an HP2621 but doesn't turn on the labels".
 * Note that this works because of the left to right scan.
 */
tnchktc()
{
	register char *p, *q;
	char tcname[16];	/* name of similar terminal */
	char tcbuf[BUFSIZ];
	char *holdtbuf = tbuf;
	int l;

	p = tbuf + strlen(tbuf) - 2;	/* before the last colon */
	while (*--p != ':')
		if (p<tbuf) {
			write(2, "Bad termcap entry\n", 18);
			return (0);
		}
	p++;
	/* p now points to beginning of last field */
	if (p[0] != 't' || p[1] != 'c')
		return(1);
	strcpy(tcname,p+3);
	q = tcname;
D 2
	while (q && *q != ':')
E 2
I 2
	while (*q && *q != ':')
E 2
		q++;
	*q = 0;
	if (++hopcount > MAXHOP) {
		write(2, "Infinite tc= loop\n", 18);
		return (0);
	}
D 3
	if (tgetent(tcbuf, tcname) != 1)
E 3
I 3
D 6
	if (tgetent(tcbuf, tcname) != 1) {
E 6
I 6
	if (tfindent(tcbuf, tcname) != 1) {
E 6
		hopcount = 0;		/* unwind recursion */
E 3
		return(0);
I 3
	}
E 3
	for (q=tcbuf; *q != ':'; q++)
		;
	l = p - holdtbuf + strlen(q);
	if (l > BUFSIZ) {
		write(2, "Termcap entry too long\n", 23);
		q[BUFSIZ - (p-tbuf)] = 0;
	}
	strcpy(p, q+1);
	tbuf = holdtbuf;
I 3
	hopcount = 0;			/* unwind recursion */
E 3
	return(1);
}

/*
 * Tnamatch deals with name matching.  The first field of the termcap
 * entry is a sequence of names separated by |'s, so we compare
 * against each such name.  The normal : terminator after the last
 * name (before the first field) stops us.
 */
tnamatch(np)
	char *np;
{
	register char *Np, *Bp;

	Bp = tbuf;
	if (*Bp == '#')
		return(0);
	for (;;) {
		for (Np = np; *Np && *Bp == *Np; Bp++, Np++)
			continue;
		if (*Np == 0 && (*Bp == '|' || *Bp == ':' || *Bp == 0))
			return (1);
		while (*Bp && *Bp != ':' && *Bp != '|')
			Bp++;
		if (*Bp == 0 || *Bp == ':')
			return (0);
		Bp++;
	}
}

/*
 * Skip to the next field.  Notice that this is very dumb, not
 * knowing about \: escapes or any such.  If necessary, :'s can be put
 * into the termcap file in octal.
 */
static char *
tskip(bp)
	register char *bp;
{

	while (*bp && *bp != ':')
		bp++;
	if (*bp == ':')
		bp++;
	return (bp);
}

/*
 * Return the (numeric) option id.
 * Numeric options look like
 *	li#80
 * i.e. the option string is separated from the numeric value by
 * a # character.  If the option is not found we return -1.
 * Note that we handle octal numbers beginning with 0.
 */
tgetnum(id)
	char *id;
{
	register int i, base;
	register char *bp = tbuf;

	for (;;) {
		bp = tskip(bp);
		if (*bp == 0)
			return (-1);
		if (*bp++ != id[0] || *bp == 0 || *bp++ != id[1])
			continue;
		if (*bp == '@')
			return(-1);
		if (*bp != '#')
			continue;
		bp++;
		base = 10;
		if (*bp == '0')
			base = 8;
		i = 0;
		while (isdigit(*bp))
			i *= base, i += *bp++ - '0';
		return (i);
	}
}

/*
 * Handle a flag option.
 * Flag options are given "naked", i.e. followed by a : or the end
 * of the buffer.  Return 1 if we find the option, or 0 if it is
 * not given.
 */
tgetflag(id)
	char *id;
{
	register char *bp = tbuf;

	for (;;) {
		bp = tskip(bp);
		if (!*bp)
			return (0);
		if (*bp++ == id[0] && *bp != 0 && *bp++ == id[1]) {
			if (!*bp || *bp == ':')
				return (1);
			else if (*bp == '@')
				return(0);
		}
	}
}

/*
 * Get a string valued option.
 * These are given as
 *	cl=^Z
 * Much decoding is done on the strings, and the strings are
 * placed in area, which is a ref parameter which is updated.
 * No checking on area overflow.
 */
char *
tgetstr(id, area)
	char *id, **area;
{
	register char *bp = tbuf;

	for (;;) {
		bp = tskip(bp);
		if (!*bp)
			return (0);
		if (*bp++ != id[0] || *bp == 0 || *bp++ != id[1])
			continue;
		if (*bp == '@')
			return(0);
		if (*bp != '=')
			continue;
		bp++;
		return (tdecode(bp, area));
	}
}

/*
 * Tdecode does the grung work to decode the
 * string capability escapes.
 */
static char *
tdecode(str, area)
	register char *str;
	char **area;
{
	register char *cp;
	register int c;
	register char *dp;
	int i;

	cp = *area;
	while ((c = *str++) && c != ':') {
		switch (c) {

		case '^':
			c = *str++ & 037;
			break;

		case '\\':
			dp = "E\033^^\\\\::n\nr\rt\tb\bf\f";
			c = *str++;
nextc:
			if (*dp++ == c) {
				c = *dp++;
				break;
			}
			dp++;
			if (*dp)
				goto nextc;
			if (isdigit(c)) {
				c -= '0', i = 2;
				do
					c <<= 3, c |= *str++ - '0';
				while (--i && isdigit(*str));
			}
			break;
		}
		*cp++ = c;
	}
	*cp++ = 0;
	str = *area;
	*area = cp;
	return (str);
}
E 1
