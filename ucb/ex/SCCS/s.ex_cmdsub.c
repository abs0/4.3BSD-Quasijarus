h23414
s 00029/00029/01263
d D 7.10 03/04/13 15:18:49 msokolov 18 17
c 8-bit ex
e
s 00002/00002/01290
d D 7.9 88/01/02 23:12:21 bostic 17 16
c fix CTRL macro for ANSI C
e
s 00020/00020/01272
d D 7.8 87/03/09 12:47:04 conrad 16 15
c make ex/vi work on vms
e
s 00001/00001/01291
d D 7.7 85/06/07 18:18:47 bloom 15 14
c fix sccsid and copyright for xstr
e
s 00010/00002/01282
d D 7.6 85/05/31 13:53:15 dist 14 12
c Add copyright
e
s 00010/00002/01268
d D 5.1.1.1 85/05/31 11:58:10 dist 13 6
c Add copyright
e
s 00022/00028/01262
d D 7.5 85/05/31 11:49:58 bloom 12 11
c Stdio can't be used for tags.  New version of tag code
e
s 00008/00001/01282
d D 7.4 85/03/27 12:00:58 bloom 11 10
c use optimal size for i/o
e
s 00001/00001/01282
d D 7.3 85/03/19 19:06:07 mckusick 10 9
c merge from sun!shannon
e
s 00001/00001/01282
d D 7.2 81/10/31 14:49:40 mark 9 8
c fixed C/70 bug with peekc being saved in a char
e
s 00010/00010/01273
d D 7.1 81/07/08 22:29:03 mark 8 7
c release 3.7 - a few bug fixes and a few new features.
e
s 00015/00002/01268
d D 6.1 80/10/19 01:20:35 mark 7 6
c preliminary release 3.6 10/18/80
e
s 00000/00000/01270
d D 5.1 80/08/20 16:09:06 mark 6 5
c Release 3.5, August 20, 1980
e
s 00002/00001/01268
d D 4.2 80/08/01 20:39:26 mark 5 4
c Bill added more buffers, and I put in sccs.
e
s 00035/00014/01234
d D 4.1 80/08/01 00:10:47 mark 4 3
c release 3.4, June 24, 1980
e
s 00184/00079/01064
d D 3.1 80/07/31 23:36:43 mark 3 2
c release 3.3, Feb 2, 1980
e
s 00011/00005/01132
d D 2.1 80/07/31 23:18:00 mark 2 1
c release 3.2, Jan 4, 1980
e
s 01137/00000/00000
d D 1.1 80/07/31 23:00:10 mark 1 0
c date and time created 80/07/31 23:00:10 by mark
e
u
U
t
T
I 1
D 5
/* Copyright (c) 1979 Regents of the University of California */
E 5
I 5
D 8
D 13
/* Copyright (c) 1980 Regents of the University of California */
static char *sccsid = "%W% %G%";
E 13
I 13
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 13
E 8
I 8
D 14
/* Copyright (c) 1981 Regents of the University of California */
static char *sccsid = "%W%	%G%";
E 14
I 14
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
D 15
static char sccsid[] = "%W% (Berkeley) %G%";
E 15
I 15
static char *sccsid = "%W% (Berkeley) %G%";
E 15
#endif not lint

E 14
E 8
E 5
#include "ex.h"
#include "ex_argv.h"
#include "ex_temp.h"
#include "ex_tty.h"
I 4
#include "ex_vis.h"
E 4

/*
 * Command mode subroutines implementing
 *	append, args, copy, delete, join, move, put,
 *	shift, tag, yank, z and undo
 */

bool	endline = 1;
line	*tad1;
I 4
static	jnoop();
E 4

/*
 * Append after line a lines returned by function f.
 * Be careful about intermediate states to avoid scramble
 * if an interrupt comes in.
 */
append(f, a)
	int (*f)();
	line *a;
{
	register line *a1, *a2, *rdot;
	int nline;

	nline = 0;
	dot = a;
D 3
	/*
	 * This is probably a bug, since it's different than the other tests
	 * in appendnone, delete, and deletenone. It is known to fail for
	 * the command :g/foo/r xxx (where there is one foo and the file
	 * xxx exists) and you try to undo it. I'm leaving it in for now
	 * because I'm afraid if I change it I'll break something.
	 */
	if (!inglobal && !inopen && f != getsub) {
E 3
I 3
	if(FIXUNDO && !inopen && f!=getsub) {
E 3
		undap1 = undap2 = dot + 1;
		undkind = UNDCHANGE;
	}
	while ((*f)() == 0) {
		if (truedol >= endcore) {
			if (morelines() < 0) {
D 3
				if (!inglobal && f == getsub) {
E 3
I 3
				if (FIXUNDO && f == getsub) {
E 3
					undap1 = addr1;
					undap2 = addr2 + 1;
				}
				error("Out of memory@- too many lines in file");
			}
		}
		nline++;
		a1 = truedol + 1;
		a2 = a1 + 1;
		dot++;
		undap2++;
		dol++;
		unddol++;
		truedol++;
		for (rdot = dot; a1 > rdot;)
			*--a2 = *--a1;
		*rdot = 0;
		putmark(rdot);
		if (f == gettty) {
			dirtcnt++;
			TSYNC();
		}
	}
	return (nline);
}

appendnone()
{

D 3
	if (inopen >= 0 && (inopen || !inglobal)) {
E 3
I 3
	if(FIXUNDO) {
E 3
		undkind = UNDCHANGE;
		undap1 = undap2 = addr1;
	}
}

/*
 * Print out the argument list, with []'s around the current name.
 */
pargs()
{
D 18
	register char **av = argv0, *as = args0;
E 18
I 18
	register u_char **av = argv0, *as = args0;
E 18
	register int ac;

	for (ac = 0; ac < argc0; ac++) {
		if (ac != 0)
D 10
			putchar(' ');
E 10
I 10
D 16
			putchar(' ' | QUOTE);
E 16
I 16
			ex_putchar(' ' | QUOTE);
E 16
E 10
		if (ac + argc == argc0 - 1)
D 16
			printf("[");
E 16
I 16
			ex_printf("[");
E 16
		lprintf("%s", as);
		if (ac + argc == argc0 - 1)
D 16
			printf("]");
E 16
I 16
			ex_printf("]");
E 16
		as = av ? *++av : strend(as) + 1;
	}
	noonl();
}

/*
 * Delete lines; two cases are if we are really deleting,
 * more commonly we are just moving lines to the undo save area.
 */
D 16
delete(hush)
E 16
I 16
ex_delete(hush)
E 16
	bool hush;
{
	register line *a1, *a2;

	nonzero();
D 3
	if (inopen >= 0 && (inopen || !inglobal)) {
E 3
I 3
	if(FIXUNDO) {
E 3
		register int (*dsavint)();

I 7
#ifdef TRACE
		if (trace)
			vudump("before delete");
#endif
E 7
		change();
		dsavint = signal(SIGINT, SIG_IGN);
		undkind = UNDCHANGE;
		a1 = addr1;
		squish();
		a2 = addr2;
		if (a2++ != dol) {
			reverse(a1, a2);
			reverse(a2, dol + 1);
			reverse(a1, dol + 1);
		}
		dol -= a2 - a1;
		unddel = a1 - 1;
		if (a1 > dol)
			a1 = dol;
		dot = a1;
		pkill[0] = pkill[1] = 0;
		signal(SIGINT, dsavint);
I 7
#ifdef TRACE
		if (trace)
			vudump("after delete");
#endif
E 7
	} else {
		register line *a3;
		register int i;

		change();
		a1 = addr1;
		a2 = addr2 + 1;
		a3 = truedol;
		i = a2 - a1;
		unddol -= i;
		undap2 -= i;
		dol -= i;
		truedol -= i;
		do
			*a1++ = *a2++;
		while (a2 <= a3);
		a1 = addr1;
		if (a1 > dol)
			a1 = dol;
		dot = a1;
	}
	if (!hush)
		killed();
}

deletenone()
{

D 3
	if (inopen >= 0 && (inopen || !inglobal)) {
E 3
I 3
	if(FIXUNDO) {
E 3
		undkind = UNDCHANGE;
		squish();
		unddel = addr1;
	}
}

/*
 * Crush out the undo save area, moving the open/visual
 * save area down in its place.
 */
squish()
{
	register line *a1 = dol + 1, *a2 = unddol + 1, *a3 = truedol + 1;

D 3
	if (inopen == -1)
		return;
	if (a1 < a2 && a2 < a3)
		do
			*a1++ = *a2++;
		while (a2 < a3);
	truedol -= unddol - dol;
	unddol = dol;
E 3
I 3
	if(FIXUNDO) {
		if (inopen == -1)
			return;
		if (a1 < a2 && a2 < a3)
			do
				*a1++ = *a2++;
			while (a2 < a3);
		truedol -= unddol - dol;
		unddol = dol;
	}
E 3
}

/*
 * Join lines.  Special hacks put in spaces, two spaces if
 * preceding line ends with '.', or no spaces if next line starts with ).
 */
static	int jcount, jnoop();

join(c)
	int c;
{
	register line *a1;
D 18
	register char *cp, *cp1;
E 18
I 18
	register u_char *cp, *cp1;
E 18

	cp = genbuf;
	*cp = 0;
	for (a1 = addr1; a1 <= addr2; a1++) {
		getline(*a1);
		cp1 = linebuf;
		if (a1 != addr1 && c == 0) {
			while (*cp1 == ' ' || *cp1 == '\t')
				cp1++;
			if (*cp1 && cp > genbuf && cp[-1] != ' ' && cp[-1] != '\t') {
				if (*cp1 != ')') {
					*cp++ = ' ';
					if (cp[-2] == '.')
						*cp++ = ' ';
				}
			}
		}
		while (*cp++ = *cp1++)
			if (cp > &genbuf[LBSIZE-2])
				error("Line overflow|Result line of join would be too long");
		cp--;
	}
	strcLIN(genbuf);
D 16
	delete(0);
E 16
I 16
	ex_delete(0);
E 16
	jcount = 1;
I 4
	if (FIXUNDO)
		undap1 = undap2 = addr1;
E 4
	ignore(append(jnoop, --addr1));
I 4
	if (FIXUNDO)
		vundkind = VMANY;
E 4
}

static
jnoop()
{

	return(--jcount);
}

/*
 * Move and copy lines.  Hard work is done by move1 which
 * is also called by undo.
 */
int	getcopy();

move()
{
	register line *adt;
	bool iscopy = 0;

	if (Command[0] == 'm') {
		setdot1();
		markpr(addr2 == dot ? addr1 - 1 : addr2 + 1);
	} else {
		iscopy++;
		setdot();
	}
	nonzero();
D 8
	adt = address(0);
E 8
I 8
D 18
	adt = address((char*)0);
E 18
I 18
	adt = address((u_char*)0);
E 18
E 8
	if (adt == 0)
		serror("%s where?|%s requires a trailing address", Command);
	newline();
	move1(iscopy, adt);
	killed();
}

move1(cflag, addrt)
	int cflag;
	line *addrt;
{
	register line *adt, *ad1, *ad2;
	int lines;

	adt = addrt;
	lines = (addr2 - addr1) + 1;
	if (cflag) {
		tad1 = addr1;
		ad1 = dol;
		ignore(append(getcopy, ad1++));
		ad2 = dol;
	} else {
		ad2 = addr2;
		for (ad1 = addr1; ad1 <= ad2;)
			*ad1++ &= ~01;
		ad1 = addr1;
	}
	ad2++;
	if (adt < ad1) {
		if (adt + 1 == ad1 && !cflag && !inglobal)
			error("That move would do nothing!");
		dot = adt + (ad2 - ad1);
		if (++adt != ad1) {
			reverse(adt, ad1);
			reverse(ad1, ad2);
			reverse(adt, ad2);
		}
	} else if (adt >= ad2) {
		dot = adt++;
		reverse(ad1, ad2);
		reverse(ad2, adt);
		reverse(ad1, adt);
	} else
		error("Move to a moved line");
	change();
	if (!inglobal)
D 3
		if (cflag) {
			undap1 = addrt + 1;
			undap2 = undap1 + lines;
			deletenone();
		} else {
			undkind = UNDMOVE;
			undap1 = addr1;
			undap2 = addr2;
			unddel = addrt;
			squish();
E 3
I 3
		if(FIXUNDO) {
			if (cflag) {
				undap1 = addrt + 1;
				undap2 = undap1 + lines;
				deletenone();
			} else {
				undkind = UNDMOVE;
				undap1 = addr1;
				undap2 = addr2;
				unddel = addrt;
				squish();
			}
E 3
		}
}

getcopy()
{

	if (tad1 > addr2)
		return (EOF);
	getline(*tad1++);
	return (0);
}

/*
 * Put lines in the buffer from the undo save area.
 */
getput()
{

	if (tad1 > unddol)
		return (EOF);
	getline(*tad1++);
	tad1++;
	return (0);
}

put()
{
	register int cnt;

I 3
	if (!FIXUNDO)
		error("Cannot put inside global/macro");
E 3
	cnt = unddol - dol;
	if (cnt && inopen && pkill[0] && pkill[1]) {
		pragged(1);
		return;
	}
	tad1 = dol + 1;
	ignore(append(getput, addr2));
	undkind = UNDPUT;
	notecnt = cnt;
	netchange(cnt);
}

/*
 * A tricky put, of a group of lines in the middle
 * of an existing line.  Only from open/visual.
 * Argument says pkills have meaning, e.g. called from
 * put; it is 0 on calls from putreg.
 */
pragged(kill)
	bool kill;
{
D 18
	extern char *cursor;
	register char *gp = &genbuf[cursor - linebuf];
E 18
I 18
	extern u_char *cursor;
	register u_char *gp = &genbuf[cursor - linebuf];
E 18

	/*
	 * This kind of stuff is TECO's forte.
	 * We just grunge along, since it cuts
	 * across our line-oriented model of the world
	 * almost scrambling our addled brain.
	 */
	if (!kill)
		getDOT();
	strcpy(genbuf, linebuf);
	getline(*unddol);
	if (kill)
		*pkill[1] = 0;
	strcat(linebuf, gp);
	putmark(unddol);
	getline(dol[1]);
	if (kill)
		strcLIN(pkill[0]);
	strcpy(gp, linebuf);
	strcLIN(genbuf);
	putmark(dol+1);
	undkind = UNDCHANGE;
	undap1 = dot;
	undap2 = dot + 1;
	unddel = dot - 1;
	undo(1);
}

/*
 * Shift lines, based on c.
 * If c is neither < nor >, then this is a lisp aligning =.
 */
shift(c, cnt)
	int c;
	int cnt;
{
	register line *addr;
D 18
	register char *cp;
	char *dp;
E 18
I 18
	register u_char *cp;
	u_char *dp;
E 18
	register int i;

D 3
	if (!inglobal)
E 3
I 3
	if(FIXUNDO)
E 3
		save12(), undkind = UNDCHANGE;
	cnt *= value(SHIFTWIDTH);
	for (addr = addr1; addr <= addr2; addr++) {
		dot = addr;
#ifdef LISPCODE
		if (c == '=' && addr == addr1 && addr != addr2)
			continue;
#endif
		getDOT();
		i = whitecnt(linebuf);
		switch (c) {

		case '>':
			if (linebuf[0] == 0)
				continue;
			cp = genindent(i + cnt);
			break;

		case '<':
			if (i == 0)
				continue;
			i -= cnt;
			cp = i > 0 ? genindent(i) : genbuf;
			break;

#ifdef LISPCODE
		default:
			i = lindent(addr);
			getDOT();
			cp = genindent(i);
			break;
#endif
		}
		if (cp + strlen(dp = vpastwh(linebuf)) >= &genbuf[LBSIZE - 2])
			error("Line too long|Result line after shift would be too long");
		CP(cp, dp);
		strcLIN(genbuf);
		putmark(addr);
	}
	killed();
}

/*
 * Find a tag in the tags file.
 * Most work here is in parsing the tags file itself.
 */
tagfind(quick)
	bool quick;
{
D 18
	char cmdbuf[BUFSIZ];
	char filebuf[FNSIZE];
I 3
	char tagfbuf[128];
E 18
I 18
	u_char cmdbuf[BUFSIZ];
	u_char filebuf[FNSIZE];
	u_char tagfbuf[128];
E 18
E 3
	register int c, d;
	bool samef = 1;
D 3
	bool notagsfile = 0;
	short master = -1;
	short omagic;
E 3
I 3
	int tfcount = 0;
	int omagic;
D 18
	char *fn, *fne;
E 18
I 18
	u_char *fn, *fne;
E 18
I 11
	struct stat sbuf;
E 11
D 8
#ifdef VMUNIX
E 8
I 8
D 12
#ifdef STDIO		/* mjm: was VMUNIX */
E 8
	/*
	 * We have lots of room so we bring in stdio and do
	 * a binary search on the tags file.
	 */
# undef EOF
# include <stdio.h>
# undef getchar
# undef putchar
	FILE *iof;
	char iofbuf[BUFSIZ];
E 12
I 12
#ifdef FASTTAG
	int iof;
D 18
	char iofbuf[MAXBSIZE];
E 18
I 18
	u_char iofbuf[MAXBSIZE];
E 18
E 12
	long mid;	/* assumed byte offset */
	long top, bot;	/* length of tag file */
D 11
	struct stat sbuf;
E 11
#endif
E 3

	omagic = value(MAGIC);
D 2
	value(MAGIC) = 0;	/* force nomagic mode for tags */
E 2
	if (!skipend()) {
D 18
		register char *lp = lasttag;
E 18
I 18
		register u_char *lp = lasttag;
E 18

		while (!iswhite(peekchar()) && !endcmd(peekchar()))
			if (lp < &lasttag[sizeof lasttag - 2])
D 16
				*lp++ = getchar();
E 16
I 16
				*lp++ = ex_getchar();
E 16
			else
				ignchar();
		*lp++ = 0;
		if (!endcmd(peekchar()))
badtag:
			error("Bad tag|Give one tag per line");
	} else if (lasttag[0] == 0)
		error("No previous tag");
D 16
	c = getchar();
E 16
I 16
	c = ex_getchar();
E 16
	if (!endcmd(c))
		goto badtag;
	if (c == EOF)
		ungetchar(c);
	clrstats();
D 3
	do {
		io = open(master ? "tags" : MASTERTAGS, 0);
		if (master && io < 0)
			notagsfile = 1;
E 3
I 3

	/*
	 * Loop once for each file in tags "path".
	 */
	CP(tagfbuf, svalue(TAGS));
	fne = tagfbuf - 1;
	while (fne) {
		fn = ++fne;
		while (*fne && *fne != ' ')
			fne++;
		if (*fne == 0)
			fne = 0;	/* done, quit after this time */
		else
			*fne = 0;	/* null terminate filename */
D 8
#ifdef VMUNIX
E 8
I 8
D 12
#ifdef STDIO		/* mjm: was VMUNIX */
E 8
		iof = fopen(fn, "r");
		if (iof == NULL)
E 12
I 12
#ifdef FASTTAG
		iof = topen(fn, iofbuf);
		if (iof == -1)
E 12
			continue;
		tfcount++;
D 12
		setbuf(iof, iofbuf);
		fstat(fileno(iof), &sbuf);
E 12
I 12
		fstat(iof, &sbuf);
E 12
		top = sbuf.st_size;
D 12
		if (top == 0L || iof == NULL)
E 12
I 12
		if (top == 0L )
E 12
			top = -1L;
		bot = 0L;
		while (top >= bot) {
#else
		/*
		 * Avoid stdio and scan tag file linearly.
		 */
		io = open(fn, 0);
		if (io<0)
			continue;
I 4
		tfcount++;
I 11
		if (fstat(io, &sbuf) < 0)
			bsize = LBSIZE;
		else {
			bsize = sbuf.st_blksize;
			if (bsize <= 0)
				bsize = LBSIZE;
		}
E 11
E 4
E 3
		while (getfile() == 0) {
I 3
#endif
			/* loop for each tags file entry */
E 3
D 18
			register char *cp = linebuf;
			register char *lp = lasttag;
			char *oglobp;
E 18
I 18
			register u_char *cp = linebuf;
			register u_char *lp = lasttag;
			u_char *oglobp;
E 18

I 3
D 8
#ifdef VMUNIX
E 8
I 8
D 12
#ifdef STDIO		/* mjm: was VMUNIX */
E 12
I 12
#ifdef FASTTAG
E 12
E 8
			mid = (top + bot) / 2;
D 12
			fseek(iof, mid, 0);
E 12
I 12
			tseek(iof, mid);
E 12
			if (mid > 0)	/* to get first tag in file to work */
D 7
				fgets(linebuf, sizeof linebuf, iof);	/* scan to next \n */
			fgets(linebuf, sizeof linebuf, iof);	/* get a line */
E 7
I 7
				/* scan to next \n */
D 12
				if(fgets(linebuf, sizeof linebuf, iof)==NULL)
E 12
I 12
				if(tgets(linebuf, sizeof linebuf, iof)==NULL)
E 12
					goto goleft;
			/* get the line itself */
D 12
			if(fgets(linebuf, sizeof linebuf, iof)==NULL)
E 12
I 12
			if(tgets(linebuf, sizeof linebuf, iof)==NULL)
E 12
				goto goleft;
E 7
D 12
			linebuf[strlen(linebuf)-1] = 0;	/* was '\n' */
E 12
I 12
#ifdef TDEBUG
D 16
			printf("tag: %o %o %o %s\n", bot, mid, top, linebuf);
E 16
I 16
			ex_printf("tag: %o %o %o %s\n", bot, mid, top, linebuf);
E 16
E 12
#endif
I 12
#endif
E 12
E 3
			while (*cp && *lp == *cp)
				cp++, lp++;
D 3
			if (*lp || !iswhite(*cp))
E 3
I 3
D 4
			if (*lp || !iswhite(*cp)) {
E 4
I 4
D 12
			if ((*lp || !iswhite(*cp)) && (value(TAGLENGTH)==0 || lp-lasttag < value(TAGLENGTH))) {
E 4
D 8
#ifdef VMUNIX
E 8
I 8
#ifdef STDIO		/* mjm: was VMUNIX */
E 12
I 12
			if ((*lp || !iswhite(*cp)) && (value(TAGLENGTH)==0 ||
			    lp-lasttag < value(TAGLENGTH))) {
#ifdef FASTTAG
E 12
E 8
				if (*lp > *cp)
					bot = mid + 1;
				else
I 7
goleft:
E 7
					top = mid - 1;
#endif
				/* Not this tag.  Try the next */
E 3
				continue;
I 3
			}

			/*
			 * We found the tag.  Decode the line in the file.
			 */
D 8
#ifdef VMUNIX
E 8
I 8
D 12
#ifdef STDIO		/* mjm: was VMUNIX */
E 8
			fclose(iof);
E 12
I 12
#ifdef FASTTAG
			tclose(iof);
E 12
#else
E 3
			close(io);
I 3
#endif
I 4
			/* Rest of tag if abbreviated */
			while (!iswhite(*cp))
				cp++;

E 4
			/* name of file */
E 3
			while (*cp && iswhite(*cp))
				cp++;
			if (!*cp)
badtags:
				serror("%s: Bad tags file entry", lasttag);
			lp = filebuf;
			while (*cp && *cp != ' ' && *cp != '\t') {
				if (lp < &filebuf[sizeof filebuf - 2])
					*lp++ = *cp;
				cp++;
			}
			*lp++ = 0;
I 3

E 3
			if (*cp == 0)
				goto badtags;
			if (dol != zero) {
				/*
				 * Save current position in 't for ^^ in visual.
				 */
				names['t'-'a'] = *dot &~ 01;
				if (inopen) {
D 4
					extern char *ncols['z'-'a'+1];
E 4
I 4
D 18
					extern char *ncols['z'-'a'+2];
E 4
					extern char *cursor;
E 18
I 18
					extern u_char *ncols['z'-'a'+2];
					extern u_char *cursor;
E 18

					ncols['t'-'a'] = cursor;
				}
			}
			strcpy(cmdbuf, cp);
			if (strcmp(filebuf, savedfile) || !edited) {
D 18
				char cmdbuf2[sizeof filebuf + 10];
E 18
I 18
				u_char cmdbuf2[sizeof filebuf + 10];
E 18

I 3
				/* Different file.  Do autowrite & get it. */
E 3
				if (!quick) {
					ckaw();
					if (chng && dol > zero)
						error("No write@since last change (:tag! overrides)");
				}
				oglobp = globp;
				strcpy(cmdbuf2, "e! ");
				strcat(cmdbuf2, filebuf);
				globp = cmdbuf2;
				d = peekc; ungetchar(0);
I 2
D 3
				/*
				 * BUG: if it isn't found (user edited header
				 * line) we get left in nomagic mode.
				 */
				value(MAGIC) = 0;
E 3
E 2
				commands(1, 1);
				peekc = d;
				globp = oglobp;
I 2
				value(MAGIC) = omagic;
E 2
				samef = 0;
			}
I 3

			/*
			 * Look for pattern in the current file.
			 */
E 3
			oglobp = globp;
			globp = cmdbuf;
			d = peekc; ungetchar(0);
			if (samef)
				markpr(dot);
I 3
			/*
			 * BUG: if it isn't found (user edited header
			 * line) we get left in nomagic mode.
			 */
E 3
I 2
			value(MAGIC) = 0;
E 2
			commands(1, 1);
			peekc = d;
			globp = oglobp;
			value(MAGIC) = omagic;
			return;
D 3
		}
	} while (++master == 0);
	if (notagsfile)
E 3
I 3
		}	/* end of "for each tag in file" */

		/*
		 * No such tag in this file.  Close it and try the next.
		 */
D 8
#ifdef VMUNIX
E 8
I 8
D 12
#ifdef STDIO		/* mjm: was VMUNIX */
E 8
		fclose(iof);
E 12
I 12
#ifdef FASTTAG
		tclose(iof);
E 12
#else
		close(io);
#endif
	}	/* end of "for each file in path" */
	if (tfcount <= 0)
E 3
		error("No tags file");
D 3
	serror("%s: No such tag@in tags file", lasttag);
E 3
I 3
	else
		serror("%s: No such tag@in tags file", lasttag);
E 3
}

/*
 * Save lines from addr1 thru addr2 as though
 * they had been deleted.
 */
yank()
{

I 3
	if (!FIXUNDO)
		error("Can't yank inside global/macro");
E 3
	save12();
	undkind = UNDNONE;
	killcnt(addr2 - addr1 + 1);
}

/*
 * z command; print windows of text in the file.
 *
 * If this seems unreasonably arcane, the reasons
 * are historical.  This is one of the first commands
 * added to the first ex (then called en) and the
 * number of facilities here were the major advantage
 * of en over ed since they allowed more use to be
 * made of fast terminals w/o typing .,.22p all the time.
 */
bool	zhadpr;
bool	znoclear;
short	zweight;

zop(hadpr)
	int hadpr;
{
	register int c, lines, op;
	bool excl;

	zhadpr = hadpr;
	notempty();
	znoclear = 0;
	zweight = 0;
	excl = exclam();
D 16
	switch (c = op = getchar()) {
E 16
I 16
	switch (c = op = ex_getchar()) {
E 16

	case '^':
		zweight = 1;
	case '-':
	case '+':
		while (peekchar() == op) {
			ignchar();
			zweight++;
		}
	case '=':
	case '.':
D 16
		c = getchar();
E 16
I 16
		c = ex_getchar();
E 16
		break;

	case EOF:
		znoclear++;
		break;

	default:
		op = 0;
		break;
	}
	if (isdigit(c)) {
		lines = c - '0';
		for(;;) {
D 16
			c = getchar();
E 16
I 16
			c = ex_getchar();
E 16
			if (!isdigit(c))
				break;
			lines *= 10;
			lines += c - '0';
		}
		if (lines < LINES)
			znoclear++;
		value(WINDOW) = lines;
		if (op == '=')
			lines += 2;
	} else
		lines = op == EOF ? value(SCROLL) : excl ? LINES - 1 : 2*value(SCROLL);
	if (inopen || c != EOF) {
		ungetchar(c);
		newline();
	}
	addr1 = addr2;
	if (addr2 == 0 && dot < dol && op == 0)
		addr1 = addr2 = dot+1;
	setdot();
	zop2(lines, op);
}

zop2(lines, op)
	register int lines;
	register int op;
{
	register line *split;

	split = NULL;
	switch (op) {

	case EOF:
		if (addr2 == dol)
			error("\nAt EOF");
	case '+':
		if (addr2 == dol)
			error("At EOF");
		addr2 += lines * zweight;
		if (addr2 > dol)
			error("Hit BOTTOM");
		addr2++;
	default:
		addr1 = addr2;
		addr2 += lines-1;
		dot = addr2;
		break;

	case '=':
	case '.':
		znoclear = 0;
		lines--;
		lines >>= 1;
		if (op == '=')
			lines--;
		addr1 = addr2 - lines;
		if (op == '=')
			dot = split = addr2;
		addr2 += lines;
		if (op == '.') {
			markDOT();
			dot = addr2;
		}
		break;

	case '^':
	case '-':
		addr2 -= lines * zweight;
		if (addr2 < one)
			error("Hit TOP");
		lines--;
		addr1 = addr2 - lines;
		dot = addr2;
		break;
	}
	if (addr1 <= zero)
		addr1 = one;
	if (addr2 > dol)
		addr2 = dol;
	if (dot > dol)
		dot = dol;
	if (addr1 > addr2)
		return;
	if (op == EOF && zhadpr) {
		getline(*addr1);
D 16
		putchar('\r' | QUOTE);
E 16
I 16
		ex_putchar('\r' | QUOTE);
E 16
		shudclob = 1;
	} else if (znoclear == 0 && CL != NOSTR && !inopen) {
		flush1();
		vclear();
	}
	if (addr2 - addr1 > 1)
		pstart();
	if (split) {
		plines(addr1, split - 1, 0);
		splitit();
		plines(split, split, 0);
		splitit();
		addr1 = split + 1;
	}
	plines(addr1, addr2, 0);
}

static
splitit()
{
	register int l;

	for (l = COLUMNS > 80 ? 40 : COLUMNS / 2; l > 0; l--)
D 16
		putchar('-');
E 16
I 16
		ex_putchar('-');
E 16
	putnl();
}

plines(adr1, adr2, movedot)
	line *adr1;
	register line *adr2;
	bool movedot;
{
	register line *addr;

	pofix();
	for (addr = adr1; addr <= adr2; addr++) {
		getline(*addr);
		pline(lineno(addr));
		if (inopen)
D 16
			putchar('\n' | QUOTE);
E 16
I 16
			ex_putchar('\n' | QUOTE);
E 16
		if (movedot)
			dot = addr;
	}
}

pofix()
{

	if (inopen && Outchar != termchar) {
		vnfl();
		setoutt();
	}
}

/*
 * Dudley doright to the rescue.
 * Undo saves the day again.
 * A tip of the hatlo hat to Warren Teitleman
 * who made undo as useful as do.
 *
 * Command level undo works easily because
 * the editor has a unique temporary file
 * index for every line which ever existed.
 * We don't have to save large blocks of text,
 * only the indices which are small.  We do this
 * by moving them to after the last line in the
 * line buffer array, and marking down info
 * about whence they came.
 *
 * Undo is its own inverse.
 */
undo(c)
	bool c;
{
	register int i;
	register line *jp, *kp;
	line *dolp1, *newdol, *newadot;

I 3
#ifdef TRACE
	if (trace)
		vudump("before undo");
#endif
E 3
	if (inglobal && inopen <= 0)
		error("Can't undo in global@commands");
	if (!c)
		somechange();
	pkill[0] = pkill[1] = 0;
	change();
	if (undkind == UNDMOVE) {
 		/*
		 * Command to be undone is a move command.
		 * This is handled as a special case by noting that
		 * a move "a,b m c" can be inverted by another move.
		 */
		if ((i = (jp = unddel) - undap2) > 0) {
			/*
			 * when c > b inverse is a+(c-b),c m a-1
			 */
			addr2 = jp;
			addr1 = (jp = undap1) + i;
			unddel = jp-1;
		} else {
			/*
			 * when b > c inverse is  c+1,c+1+(b-a) m b
			 */
			addr1 = ++jp;
			addr2 = jp + ((unddel = undap2) - undap1);
		}
		kp = undap1;
		move1(0, unddel);
		dot = kp;
		Command = "move";
		killed();
	} else {
		int cnt;

		newadot = dot;
		cnt = lineDOL();
		newdol = dol;
		dolp1 = dol + 1;
		/*
		 * Command to be undone is a non-move.
		 * All such commands are treated as a combination of
		 * a delete command and a append command.
		 * We first move the lines appended by the last command
		 * from undap1 to undap2-1 so that they are just before the
		 * saved deleted lines.
		 */
		if ((i = (kp = undap2) - (jp = undap1)) > 0) {
			if (kp != dolp1) {
				reverse(jp, kp);
				reverse(kp, dolp1);
				reverse(jp, dolp1);
			}
			/*
			 * Account for possible backward motion of target
			 * for restoration of saved deleted lines.
			 */
			if (unddel >= jp)
				unddel -= i;
			newdol -= i;
			/*
			 * For the case where no lines are restored, dot
			 * is the line before the first line deleted.
			 */
			dot = jp-1;
		}
		/*
		 * Now put the deleted lines, if any, back where they were.
		 * Basic operation is: dol+1,unddol m unddel
		 */
		if (undkind == UNDPUT) {
			unddel = undap1 - 1;
			squish();
		}
		jp = unddel + 1;
		if ((i = (kp = unddol) - dol) > 0) {
			if (jp != dolp1) {
				reverse(jp, dolp1);
				reverse(dolp1, ++kp);
				reverse(jp, kp);
			}
			/*
			 * Account for possible forward motion of the target
			 * for restoration of the deleted lines.
			 */
			if (undap1 >= jp)
				undap1 += i;
			/*
			 * Dot is the first resurrected line.
			 */
			dot = jp;
			newdol += i;
		}
		/*
		 * Clean up so we are invertible
		 */
		unddel = undap1 - 1;
		undap1 = jp;
		undap2 = jp + i;
		dol = newdol;
		netchHAD(cnt);
		if (undkind == UNDALL) {
			dot = undadot;
			undadot = newadot;
D 3
		}
		undkind = UNDCHANGE;
E 3
I 3
		} else
			undkind = UNDCHANGE;
E 3
	}
D 4
	if (dot == zero && dot != dol)
E 4
I 4
	/*
	 * Defensive programming - after a munged undadot.
	 * Also handle empty buffer case.
	 */
	if ((dot <= zero || dot > dol) && dot != dol)
E 4
		dot = one;
I 3
#ifdef TRACE
	if (trace)
		vudump("after undo");
#endif
E 3
}

/*
 * Be (almost completely) sure there really
 * was a change, before claiming to undo.
 */
somechange()
{
	register line *ip, *jp;

	switch (undkind) {

	case UNDMOVE:
		return;

	case UNDCHANGE:
		if (undap1 == undap2 && dol == unddol)
			break;
		return;

	case UNDPUT:
		if (undap1 != undap2)
			return;
		break;

	case UNDALL:
		if (unddol - dol != lineDOL())
			return;
		for (ip = one, jp = dol + 1; ip <= dol; ip++, jp++)
			if ((*ip &~ 01) != (*jp &~ 01))
				return;
		break;

	case UNDNONE:
		error("Nothing to undo");
	}
	error("Nothing changed|Last undoable command didn't change anything");
}

/*
 * Map command:
 * map src dest
 */
D 4
mapcmd(un)
E 4
I 4
mapcmd(un, ab)
E 4
	int un;	/* true if this is unmap command */
I 4
	int ab;	/* true if this is abbr command */
E 4
{
D 4
	char lhs[10], rhs[100];	/* max sizes resp. */
E 4
I 4
D 18
	char lhs[100], rhs[100];	/* max sizes resp. */
E 4
	register char *p;
E 18
I 18
	u_char lhs[100], rhs[100];	/* max sizes resp. */
	register u_char *p;
E 18
D 8
	register char c;
E 8
I 8
	register int c;		/* mjm: char --> int */
E 8
D 18
	char *dname;
E 18
I 18
	u_char *dname;
E 18
I 3
	struct maps *mp;	/* the map structure we are working on */
E 3

I 3
D 4
	mp = exclam() ? immacs : arrows;
E 4
I 4
	mp = ab ? abbrevs : exclam() ? immacs : arrows;
E 4
E 3
	if (skipend()) {
		int i;

		/* print current mapping values */
		if (peekchar() != EOF)
			ignchar();
I 4
		if (un)
			error("Missing lhs");
E 4
		if (inopen)
			pofix();
D 3
		for (i=0; arrows[i].mapto; i++)
			if (arrows[i].cap) {
				lprintf("%s", arrows[i].descr);
E 3
I 3
		for (i=0; mp[i].mapto; i++)
			if (mp[i].cap) {
				lprintf("%s", mp[i].descr);
E 3
D 16
				putchar('\t');
E 16
I 16
				ex_putchar('\t');
E 16
D 3
				lprintf("%s", arrows[i].cap);
E 3
I 3
				lprintf("%s", mp[i].cap);
E 3
D 16
				putchar('\t');
E 16
I 16
				ex_putchar('\t');
E 16
D 3
				lprintf("%s", arrows[i].mapto);
E 3
I 3
				lprintf("%s", mp[i].mapto);
E 3
				putNFL();
			}
		return;
	}

	ignore(skipwh());
	for (p=lhs; ; ) {
D 16
		c = getchar();
E 16
I 16
		c = ex_getchar();
E 16
D 17
		if (c == CTRL(v)) {
E 17
I 17
		if (c == CTRL('v')) {
E 17
D 16
			c = getchar();
E 16
I 16
			c = ex_getchar();
E 16
D 4
		} else if (any(c, " \t")) {
			if (un)
				eol();	/* will usually cause an error */
			else
				break;
		} else if (endcmd(c)) {
E 4
I 4
		} else if (!un && any(c, " \t")) {
			/* End of lhs */
			break;
		} else if (endcmd(c) && c!='"') {
E 4
			ungetchar(c);
			if (un) {
				newline();
I 4
				*p = 0;
E 4
D 3
				addmac(lhs, NOSTR, NOSTR);
E 3
I 3
				addmac(lhs, NOSTR, NOSTR, mp);
E 3
				return;
			} else
				error("Missing rhs");
		}
		*p++ = c;
	}
	*p = 0;

	if (skipend())
		error("Missing rhs");
	for (p=rhs; ; ) {
D 16
		c = getchar();
E 16
I 16
		c = ex_getchar();
E 16
D 17
		if (c == CTRL(v)) {
E 17
I 17
		if (c == CTRL('v')) {
E 17
D 16
			c = getchar();
E 16
I 16
			c = ex_getchar();
E 16
D 4
		} else if (endcmd(c)) {
E 4
I 4
		} else if (endcmd(c) && c!='"') {
E 4
			ungetchar(c);
			break;
		}
		*p++ = c;
	}
	*p = 0;
	newline();
	/*
	 * Special hack for function keys: #1 means key f1, etc.
	 * If the terminal doesn't have function keys, we just use #1.
	 */
	if (lhs[0] == '#') {
D 18
		char *fnkey;
		char *fkey();
		char funkey[3];
E 18
I 18
		u_char *fnkey;
		u_char *fkey();
		u_char funkey[3];
E 18

		fnkey = fkey(lhs[1] - '0');
		funkey[0] = 'f'; funkey[1] = lhs[1]; funkey[2] = 0;
		if (fnkey)
			strcpy(lhs, fnkey);
		dname = funkey;
	} else {
		dname = lhs;
	}
D 3
	addmac(lhs,rhs,dname);
E 3
I 3
	addmac(lhs,rhs,dname,mp);
E 3
}

/*
 * Add a macro definition to those that already exist. The sequence of
 * chars "src" is mapped into "dest". If src is already mapped into something
 * this overrides the mapping. There is no recursion. Unmap is done by
D 3
 * using NOSTR for dest.
E 3
I 3
 * using NOSTR for dest.  Dname is what to show in listings.  mp is
 * the structure to affect (arrows, etc).
E 3
 */
D 3
addmac(src,dest,dname)
E 3
I 3
addmac(src,dest,dname,mp)
E 3
D 18
	register char *src, *dest, *dname;
E 18
I 18
	register u_char *src, *dest, *dname;
E 18
I 3
	register struct maps *mp;
E 3
{
	register int slot, zer;

I 4
#ifdef TRACE
	if (trace)
		fprintf(trace, "addmac(src='%s', dest='%s', dname='%s', mp=%x\n", src, dest, dname, mp);
#endif
E 4
D 3
	if (dest) {
E 3
I 3
	if (dest && mp==arrows) {
E 3
		/* Make sure user doesn't screw himself */
		/*
D 2
		 * Prevent head and tail recursion. We really should be
		 * checking to see if src is a prefix or suffix of dest
E 2
I 2
		 * Prevent tail recursion. We really should be
		 * checking to see if src is a suffix of dest
E 2
D 3
		 * but we are too lazy here, so we don't bother unless
		 * src is only 1 char long.
E 3
I 3
		 * but this makes mapping involving escapes that
		 * is reasonable mess up.
E 3
		 */
D 2
		if (src[1] == 0 && (src[0] == dest[0] || src[0] == dest[strlen(dest)-1]))
			error("No recursion");
E 2
I 2
		if (src[1] == 0 && src[0] == dest[strlen(dest)-1])
			error("No tail recursion");
E 2
		/*
		 * We don't let the user rob himself of ":", and making
		 * multi char words is a bad idea so we don't allow it.
		 * Note that if user sets mapinput and maps all of return,
		 * linefeed, and escape, he can screw himself. This is
		 * so weird I don't bother to check for it.
		 */
		if (isalpha(src[0]) && src[1] || any(src[0],":"))
			error("Too dangerous to map that");
D 3
		/*
		 * If the src were null it would cause the dest to
		 * be mapped always forever. This is not good.
		 */
		if (src[0] == 0)
			error("Null lhs");
E 3
	}
I 3
	else if (dest) {
		/* check for tail recursion in input mode: fussier */
		if (eq(src, dest+strlen(dest)-strlen(src)))
			error("No tail recursion");
	}
	/*
	 * If the src were null it would cause the dest to
	 * be mapped always forever. This is not good.
	 */
	if (src == NOSTR || src[0] == 0)
		error("Missing lhs");
E 3

	/* see if we already have a def for src */
	zer = -1;
D 3
	for (slot=0; arrows[slot].mapto; slot++) {
		if (arrows[slot].cap) {
			if (eq(src, arrows[slot].cap))
E 3
I 3
	for (slot=0; mp[slot].mapto; slot++) {
		if (mp[slot].cap) {
D 4
			if (eq(src, mp[slot].cap))
E 4
I 4
			if (eq(src, mp[slot].cap) || eq(src, mp[slot].mapto))
E 4
E 3
				break;	/* if so, reuse slot */
		} else {
			zer = slot;	/* remember an empty slot */
		}
	}

	if (dest == NOSTR) {
		/* unmap */
D 3
		if (arrows[slot].cap) {
			arrows[slot].cap = NOSTR;
			arrows[slot].descr = NOSTR;
E 3
I 3
		if (mp[slot].cap) {
			mp[slot].cap = NOSTR;
			mp[slot].descr = NOSTR;
E 3
		} else {
			error("Not mapped|That macro wasn't mapped");
		}
		return;
	}

	/* reuse empty slot, if we found one and src isn't already defined */
D 3
	if (zer >= 0 && arrows[slot].mapto == 0)
E 3
I 3
	if (zer >= 0 && mp[slot].mapto == 0)
E 3
		slot = zer;

	/* if not, append to end */
	if (slot >= MAXNOMACS)
		error("Too many macros");
	if (msnext == 0)	/* first time */
		msnext = mapspace;
	/* Check is a bit conservative, we charge for dname even if reusing src */
	if (msnext - mapspace + strlen(dest) + strlen(src) + strlen(dname) + 3 > MAXCHARMACS)
		error("Too much macro text");
	CP(msnext, src);
D 3
	arrows[slot].cap = msnext;
E 3
I 3
	mp[slot].cap = msnext;
E 3
	msnext += strlen(src) + 1;	/* plus 1 for null on the end */
	CP(msnext, dest);
D 3
	arrows[slot].mapto = msnext;
E 3
I 3
	mp[slot].mapto = msnext;
E 3
	msnext += strlen(dest) + 1;
	if (dname) {
		CP(msnext, dname);
D 3
		arrows[slot].descr = msnext;
E 3
I 3
		mp[slot].descr = msnext;
E 3
		msnext += strlen(dname) + 1;
	} else {
		/* default descr to string user enters */
D 3
		arrows[slot].descr = src;
E 3
I 3
		mp[slot].descr = src;
E 3
	}
}

/*
 * Implements macros from command mode. c is the buffer to
 * get the macro from.
 */
cmdmac(c)
D 18
char c;
E 18
I 18
u_char c;
E 18
{
D 18
	char macbuf[BUFSIZ];
E 18
I 18
	u_char macbuf[BUFSIZ];
E 18
	line *ad, *a1, *a2;
D 18
	char *oglobp;
E 18
I 18
	u_char *oglobp;
E 18
D 9
	char pk;
E 9
I 9
	short pk;
E 9
	bool oinglobal;

	lastmac = c;
	oglobp = globp;
	oinglobal = inglobal;
	pk = peekc; peekc = 0;
	if (inglobal < 2)
		inglobal = 1;
	regbuf(c, macbuf, sizeof(macbuf));
	a1 = addr1; a2 = addr2;
	for (ad=a1; ad<=a2; ad++) {
		globp = macbuf;
		dot = ad;
		commands(1,1);
	}
	globp = oglobp;
	inglobal = oinglobal;
	peekc = pk;
}
E 1
