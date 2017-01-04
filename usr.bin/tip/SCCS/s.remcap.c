h59587
s 00007/00001/00391
d D 5.1 85/04/30 12:35:04 dist 9 8
c Add copyright
e
s 00035/00067/00357
d D 4.8 83/06/25 01:14:05 sam 8 7
c so much...clean up after ralph's merge of wendel and mo code;
c purge VMUNIX include since changes for signals make it no longer portable 
c to systems other than 4.2; fix ventel for no echo strapping; do setjmps 
c instead of assuming interrupted system calls; purge lcmd, if people use 
e
s 00067/00014/00357
d D 4.7 83/06/15 13:52:39 ralph 7 6
c changes for local info, parity, vadic auto dialers
e
s 00000/00000/00371
d D 4.6 81/11/29 22:50:32 sam 6 5
c reformatting
e
s 00002/00000/00369
d D 4.5 81/07/13 10:55:37 sam 5 4
c 2 #ifdef VMUNIX's that were missed
e
s 00002/00000/00367
d D 4.4 81/07/11 14:04:52 sam 4 3
c cleanup after "hw" attribute addition (instead of shannon mods)
e
s 00013/00009/00354
d D 4.3 81/05/21 11:58:48 sam 3 2
c changes to make remcap appear just like termcap, except for names
e
s 00155/00037/00208
d D 4.2 81/05/20 15:44:06 sam 2 1
c upgrade to 4bsd termcap; changes from shannon w/ some of my own
e
s 00245/00000/00000
d D 4.1 81/05/09 16:45:19 root 1 0
c date and time created 81/05/09 16:45:19 by root
e
u
U
t
T
I 9
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 9
I 1
D 8
/*	%M%	%I%	%E%	*/
/* Copyright (c) 1979 Regents of the University of California */
I 7
/*
 *	Modified 9/27/82 - Michael Wendel
 *			   General Instrument R&D
 *		Looks in user Remote file first.
 *		Looks in system Remote file for each tc= entry
 *		that cannot be resolved in the user Remote file.
 *		Finally looks into the system Remote file to
 *		resolve remote name.
 *		User remote file will supplement the system file
 *		since all the entries in the user file occur
 *		ahead of duplicate entries from the system file.
 */
E 7
I 4
#ifndef BUFSIZ
E 4
D 2
#define	BUFSIZ	512
E 2
I 2
#define	BUFSIZ	1024
E 8
I 8
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
E 8
I 4
D 9
#endif
E 9
I 9
#endif not lint
E 9
E 4
D 8
#define MAXHOP	32	/* max number of tc= indirections */
E 8
E 2

D 8
#include <ctype.h>
I 5
#ifdef VMUNIX
E 5
I 2
#include "local/uparm.h"
I 5
#endif
E 8
E 5
E 2
/*
D 2
 * remcap - routines for dealing with the remote host description
 *	    data base
E 2
I 2
 * remcap - routines for dealing with the remote host data base
E 2
 *
I 2
D 8
 *	Made from termcap with the following defines.
E 8
I 8
 * derived from termcap
E 8
 */
D 8
#define REMOTE		/* special for tip */
I 7
#define SYSREMOTE	"/etc/remote"  /* system remote file */
E 8
I 8
#include <sys/file.h>
#include <ctype.h>
E 8
E 7

D 8
#ifdef REMOTE
E 8
I 8
#ifndef BUFSIZ
#define	BUFSIZ		1024
#endif
#define MAXHOP		32		/* max number of tc= indirections */
#define SYSREMOTE	"/etc/remote"	/* system remote file */

E 8
#define	tgetent		rgetent
#define	tnchktc		rnchktc
#define	tnamatch	rnamatch
#define	tgetnum		rgetnum
#define	tgetflag	rgetflag
#define	tgetstr		rgetstr
D 8
#undef	E_TERMCAP
E 8
D 3
#define	E_TERMCAP	"/etc/remote"
#define	V6		/* don't look in environment */
E 3
I 3
D 7
#define	E_TERMCAP	RM = "/etc/remote"
E 7
I 7
#define	E_TERMCAP	RM = SYSREMOTE
E 7
#define V_TERMCAP	"REMOTE"
#define V_TERM		"HOST"

E 3
char	*RM;
I 3
D 8
#else
#define	V_TERMCAP	"TERMCAP"
#define V_TERM		"TERM"
E 3
#endif
E 8

/*
 * termcap - routines for dealing with the terminal capability data base
 *
E 2
 * BUG:		Should use a "last" pointer in tbuf, so that searching
 *		for capabilities alphabetically would not be a n**2/2
 *		process when large numbers of capabilities are given.
I 2
 * Note:	If we add a last pointer now we will screw up the
 *		tc capability. We really should compile termcap.
E 2
 *
 * Essentially all the work here is scanning and decoding escapes
D 2
 * in string capabilities.*/
E 2
I 2
 * in string capabilities.  We don't use stdio because the editor
 * doesn't, and because living w/o it is not hard.
 */
E 2

I 7
D 8
static char *sccsid = "%W% %G%";
E 8
E 7
D 2
static	char *rbuf;
char	*rskip();
char	*rgetstr();
char	*rdecode();
E 2
I 2
static	char *tbuf;
static	int hopcount;	/* detect infinite loops in termcap, init 0 */
char	*tskip();
char	*tgetstr();
char	*tdecode();
E 2
char	*getenv();
I 7
D 8
static	char	*remotefile;
E 8
I 8
static	char *remotefile;
E 8
E 7
D 2
char	*RM;		/* remote file */
E 2

/*
D 2
 * Get an entry for host name in buffer bp,
 * from the remcap file.  Parse is very rudimentary;
E 2
I 2
 * Get an entry for terminal name in buffer bp,
 * from the termcap file.  Parse is very rudimentary;
E 2
 * we just notice escaped newlines.
 */
D 2
rgetent(bp, name)
E 2
I 2
tgetent(bp, name)
E 2
	char *bp, *name;
{
D 7
	register char *cp;
E 7
I 7
D 8
	char lbuf[BUFSIZ];
	int	rc1, rc2;
	char *cp;
	char *p;
E 8
I 8
	char lbuf[BUFSIZ], *cp, *p;
	int rc1, rc2;
E 8

	remotefile = cp = getenv(V_TERMCAP);
	if (cp == (char *)0 || strcmp(cp, SYSREMOTE) == 0) {
		remotefile = cp = SYSREMOTE;
D 8
		return(getent(bp, name, cp));
E 8
I 8
		return (getent(bp, name, cp));
E 8
	} else {
		if ((rc1 = getent(bp, name, cp)) != 1)
			*bp = '\0';
		remotefile = cp = SYSREMOTE;
		rc2 = getent(lbuf, name, cp);
		if (rc1 != 1 && rc2 != 1)
D 8
			return(rc2);
E 8
I 8
			return (rc2);
E 8
		if (rc2 == 1) {
			p = lbuf;
			if (rc1 == 1)
				while (*p++ != ':')
					;
			if (strlen(bp) + strlen(p) > BUFSIZ) {
				write(2, "Remcap entry too long\n", 23);
D 8
				return(-1);
E 8
I 8
				return (-1);
E 8
			}
			strcat(bp, p);
		}
		tbuf = bp;
D 8
		return(1);
E 8
I 8
		return (1);
E 8
	}
}

getent(bp, name, cp)
	char *bp, *name, *cp;
{
E 7
	register int c;
	register int i = 0, cnt = 0;
D 8
	char ibuf[BUFSIZ];
I 2
	char *cp2;
E 8
I 8
	char ibuf[BUFSIZ], *cp2;
E 8
E 2
	int tf;

D 2
	rbuf = bp;
E 2
I 2
	tbuf = bp;
	tf = 0;
D 8
#ifndef V6
E 8
D 3
	cp = getenv("TERMCAP");
E 3
I 3
D 7
	cp = getenv(V_TERMCAP);
E 7
E 3
	/*
	 * TERMCAP can have one of two things in it. It can be the
	 * name of a file to use instead of /etc/termcap. In this
	 * case it better start with a "/". Or it can be an entry to
	 * use so we don't have to read the file. In this case it
	 * has to already have the newlines crunched out.
	 */
	if (cp && *cp) {
		if (*cp!='/') {
D 3
			cp2 = getenv("TERM");
E 3
I 3
			cp2 = getenv(V_TERM);
E 3
D 8
			if (cp2==(char *) 0 || strcmp(name,cp2)==0) {
E 8
I 8
			if (cp2 == (char *)0 || strcmp(name,cp2) == 0) {
E 8
				strcpy(bp,cp);
D 8
				return(tnchktc());
			} else {
				tf = open(E_TERMCAP, 0);
			}
E 8
I 8
				return (tnchktc());
			} else
				tf = open(E_TERMCAP, O_RDONLY);
E 8
		} else
I 3
D 8
#ifdef REMOTE
			tf = open(RM = cp, 0);
#else
E 3
			tf = open(cp, 0);
I 3
#endif
E 8
I 8
			tf = open(RM = cp, O_RDONLY);
E 8
E 3
	}
D 8
	if (tf==0)
		tf = open(E_TERMCAP, 0);
#else
D 3
#ifdef REMOTE
E 2
	if ((RM = getenv("REMOTE")) == (char *)0)
D 2
		RM = "/etc/remote";
	if ((tf = open(RM, 0)) < 0)
E 2
I 2
		RM = E_TERMCAP;
	tf = open(RM, 0);
#endif
E 3
	tf = open(E_TERMCAP, 0);
#endif
E 8
I 8
	if (tf == 0)
		tf = open(E_TERMCAP, O_RDONLY);
E 8
	if (tf < 0)
E 2
		return (-1);
	for (;;) {
		cp = bp;
		for (;;) {
			if (i == cnt) {
				cnt = read(tf, ibuf, BUFSIZ);
				if (cnt <= 0) {
					close(tf);
					return (0);
				}
				i = 0;
			}
			c = ibuf[i++];
			if (c == '\n') {
D 7
				if (cp > bp && cp[-1] == '\\'){
E 7
I 7
				if (cp > bp && cp[-1] == '\\') {
E 7
					cp--;
					continue;
				}
				break;
			}
D 2
			*cp++ = c;
E 2
I 2
			if (cp >= bp+BUFSIZ) {
D 7
				write(2,"Termcap entry too long\n", 23);
E 7
I 7
				write(2,"Remcap entry too long\n", 23);
E 7
				break;
			} else
				*cp++ = c;
E 2
		}
		*cp = 0;

		/*
		 * The real work for the match.
		 */
D 2
		if (rnamatch(name)) {
E 2
I 2
		if (tnamatch(name)) {
E 2
			close(tf);
D 2
			return (1);
E 2
I 2
D 8
			return(tnchktc());
E 8
I 8
			return (tnchktc());
E 8
E 2
		}
	}
}

/*
D 2
 * Rnamatch deals with name matching.  The first field of the remcap
E 2
I 2
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
I 7
	char *cp;
E 7

	p = tbuf + strlen(tbuf) - 2;	/* before the last colon */
	while (*--p != ':')
		if (p<tbuf) {
D 7
			write(2, "Bad termcap entry\n", 18);
E 7
I 7
			write(2, "Bad remcap entry\n", 18);
E 7
			return (0);
		}
	p++;
	/* p now points to beginning of last field */
	if (p[0] != 't' || p[1] != 'c')
D 8
		return(1);
E 8
I 8
		return (1);
E 8
D 7
	strcpy(tcname,p+3);
E 7
I 7
	strcpy(tcname, p+3);
E 7
	q = tcname;
D 7
	while (q && *q != ':')
E 7
I 7
	while (*q && *q != ':')
E 7
		q++;
	*q = 0;
	if (++hopcount > MAXHOP) {
		write(2, "Infinite tc= loop\n", 18);
		return (0);
	}
D 7
	if (tgetent(tcbuf, tcname) != 1)
		return(0);
	for (q=tcbuf; *q != ':'; q++)
E 7
I 7
	if (getent(tcbuf, tcname, remotefile) != 1) {
		if (strcmp(remotefile, SYSREMOTE) == 0)
D 8
			return(0);
E 8
I 8
			return (0);
E 8
		else if (getent(tcbuf, tcname, SYSREMOTE) != 1)
D 8
			return(0);
E 8
I 8
			return (0);
E 8
	}
	for (q = tcbuf; *q++ != ':'; )
E 7
		;
	l = p - holdtbuf + strlen(q);
	if (l > BUFSIZ) {
D 7
		write(2, "Termcap entry too long\n", 23);
		q[BUFSIZ - (p-tbuf)] = 0;
E 7
I 7
		write(2, "Remcap entry too long\n", 23);
		q[BUFSIZ - (p-holdtbuf)] = 0;
E 7
	}
D 7
	strcpy(p, q+1);
E 7
I 7
	strcpy(p, q);
E 7
	tbuf = holdtbuf;
D 8
	return(1);
E 8
I 8
	return (1);
E 8
}

/*
 * Tnamatch deals with name matching.  The first field of the termcap
E 2
 * entry is a sequence of names separated by |'s, so we compare
 * against each such name.  The normal : terminator after the last
 * name (before the first field) stops us.
 */
D 2
rnamatch(np)
E 2
I 2
tnamatch(np)
E 2
	char *np;
{
	register char *Np, *Bp;

D 2
	Bp = rbuf;
E 2
I 2
	Bp = tbuf;
	if (*Bp == '#')
D 8
		return(0);
E 8
I 8
		return (0);
E 8
E 2
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
D 2
 * into the printcap file in octal.
E 2
I 2
 * into the termcap file in octal.
E 2
 */
static char *
D 2
rskip(bp)
E 2
I 2
tskip(bp)
E 2
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
D 2
rgetnum(id)
E 2
I 2
tgetnum(id)
E 2
	char *id;
{
	register int i, base;
D 2
	register char *bp = rbuf;
E 2
I 2
	register char *bp = tbuf;
E 2

	for (;;) {
D 2
		bp = rskip(bp);
E 2
I 2
		bp = tskip(bp);
E 2
		if (*bp == 0)
			return (-1);
		if (*bp++ != id[0] || *bp == 0 || *bp++ != id[1])
			continue;
I 2
		if (*bp == '@')
D 8
			return(-1);
E 8
I 8
			return (-1);
E 8
E 2
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
D 2
rgetflag(id)
E 2
I 2
tgetflag(id)
E 2
	char *id;
{
D 2
	register char *bp = rbuf;
E 2
I 2
	register char *bp = tbuf;
E 2

	for (;;) {
D 2
		bp = rskip(bp);
E 2
I 2
		bp = tskip(bp);
E 2
		if (!*bp)
			return (0);
D 2
		if (*bp++ == id[0] && *bp != 0 && *bp++ == id[1] && (!*bp || *bp == ':'))
			return (1);
E 2
I 2
		if (*bp++ == id[0] && *bp != 0 && *bp++ == id[1]) {
			if (!*bp || *bp == ':')
				return (1);
			else if (*bp == '@')
D 8
				return(0);
E 8
I 8
				return (0);
E 8
		}
E 2
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
D 2
rgetstr(id, area)
E 2
I 2
tgetstr(id, area)
E 2
	char *id, **area;
{
D 2
	register char *bp = rbuf;
E 2
I 2
	register char *bp = tbuf;
E 2

	for (;;) {
D 2
		bp = rskip(bp);
E 2
I 2
		bp = tskip(bp);
E 2
		if (!*bp)
			return (0);
		if (*bp++ != id[0] || *bp == 0 || *bp++ != id[1])
			continue;
I 2
		if (*bp == '@')
D 8
			return(0);
E 8
I 8
			return (0);
E 8
E 2
		if (*bp != '=')
			continue;
		bp++;
D 2
		return (rdecode(bp, area));
E 2
I 2
		return (tdecode(bp, area));
E 2
	}
}

/*
 * Tdecode does the grung work to decode the
 * string capability escapes.
 */
D 2
char *
rdecode(str, area)
E 2
I 2
static char *
tdecode(str, area)
E 2
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
