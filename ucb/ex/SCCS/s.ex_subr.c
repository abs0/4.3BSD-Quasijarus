h62482
s 00038/00038/00928
d D 7.12 03/04/13 15:19:05 msokolov 22 21
c 8-bit ex
e
s 00050/00028/00916
d D 7.11 87/03/09 12:46:33 conrad 21 20
c make ex/vi work on vms
e
s 00001/00001/00943
d D 7.10 85/06/07 18:20:30 bloom 20 19
c fix sccsid and copyright for xstr
e
s 00010/00002/00934
d D 7.9 85/05/31 13:57:00 dist 19 17
c Add copyright
e
s 00010/00002/00806
d D 5.1.1.1 85/05/31 12:08:15 dist 18 6
c Add copyright
e
s 00002/00002/00934
d D 7.8 85/03/17 13:40:04 sam 17 16
c can't stand ugly code
e
s 00005/00000/00931
d D 7.7 85/02/21 17:47:30 bloom 16 15
c add support for window size changes
e
s 00004/00057/00927
d D 7.6 84/03/28 15:33:01 ralph 15 14
c use C library error message array
e
s 00002/00000/00982
d D 7.5 83/07/09 11:00:04 sam 14 13
c old SIGTSTP bugaboo
e
s 00001/00000/00981
d D 7.4 83/07/02 00:28:26 sam 13 12
c missing #endif
e
s 00000/00001/00981
d D 7.3 83/06/10 12:08:45 ralph 12 11
c fixed Not Edited and not Modified when errors occur.
e
s 00001/00001/00981
d D 7.2 81/07/26 20:04:09 mark 11 10
c fixes for 3b
e
s 00003/00002/00979
d D 7.1 81/07/08 22:30:53 mark 10 9
c release 3.7 - a few bug fixes and a few new features.
e
s 00152/00000/00829
d D 6.3 80/11/08 21:22:17 mark 9 8
c moved signal catching routines to ex_subr.c so they'll be in root ovly
e
s 00026/00006/00803
d D 6.2 80/11/06 14:48:54 mark 8 7
c fixed syserror to handle quotas right on v7
e
s 00002/00001/00807
d D 6.1 80/10/19 01:21:21 mark 7 6
c preliminary release 3.6 10/18/80
e
s 00000/00000/00808
d D 5.1 80/08/20 16:11:19 mark 6 5
c Release 3.5, August 20, 1980
e
s 00002/00001/00806
d D 4.2 80/08/01 20:41:08 mark 5 4
c Bill added more buffers, and I put in sccs.
e
s 00039/00002/00768
d D 4.1 80/08/01 00:15:06 mark 4 3
c release 3.4, June 24, 1980
e
s 00013/00003/00757
d D 3.1 80/07/31 23:39:22 mark 3 2
c release 3.3, Feb 2, 1980
e
s 00018/00002/00742
d D 2.1 80/07/31 23:19:20 mark 2 1
c release 3.2, Jan 4, 1980
e
s 00744/00000/00000
d D 1.1 80/07/31 23:00:25 mark 1 0
c date and time created 80/07/31 23:00:25 by mark
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
D 10
D 18
/* Copyright (c) 1980 Regents of the University of California */
static char *sccsid = "%W% %G%";
E 18
I 18
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 18
E 10
I 10
D 19
/* Copyright (c) 1981 Regents of the University of California */
static char *sccsid = "%W%	%G%";
E 19
I 19
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
D 20
static char sccsid[] = "%W% (Berkeley) %G%";
E 20
I 20
static char *sccsid = "%W% (Berkeley) %G%";
E 20
#endif not lint

E 19
E 10
E 5
#include "ex.h"
#include "ex_re.h"
#include "ex_tty.h"
#include "ex_vis.h"

/*
 * Random routines, in alphabetical order.
 */

any(c, s)
	int c;
D 22
	register char *s;
E 22
I 22
	register u_char *s;
E 22
{
	register int x;

	while (x = *s++)
		if (x == c)
			return (1);
	return (0);
}

backtab(i)
	register int i;
{
	register int j;

	j = i % value(SHIFTWIDTH);
	if (j == 0)
		j = value(SHIFTWIDTH);
	i -= j;
	if (i < 0)
		i = 0;
	return (i);
}

change()
{

	tchng++;
	chng = tchng;
}

/*
 * Column returns the number of
 * columns occupied by printing the
 * characters through position cp of the
 * current line.
 */
column(cp)
D 22
	register char *cp;
E 22
I 22
	register u_char *cp;
E 22
{

	if (cp == 0)
		cp = &linebuf[LBSIZE - 2];
D 22
	return (qcolumn(cp, (char *) 0));
E 22
I 22
	return (qcolumn(cp, (u_char *) 0));
E 22
}

I 4
/*
 * Ignore a comment to the end of the line.
 * This routine eats the trailing newline so don't call newline().
 */
comment()
{
	register int c;

	do {
D 21
		c = getchar();
E 21
I 21
		c = ex_getchar();
E 21
	} while (c != '\n' && c != EOF);
	if (c == EOF)
		ungetchar(c);
}

E 4
Copy(to, from, size)
D 22
	register char *from, *to;
E 22
I 22
	register u_char *from, *to;
E 22
	register int size;
{

	if (size > 0)
		do
			*to++ = *from++;
		while (--size > 0);
}

copyw(to, from, size)
	register line *from, *to;
	register int size;
{
D 21

E 21
	if (size > 0)
		do
			*to++ = *from++;
		while (--size > 0);
}

copywR(to, from, size)
	register line *from, *to;
	register int size;
{

	while (--size >= 0)
		to[size] = from[size];
}

ctlof(c)
	int c;
{

D 22
	return (c == TRIM ? '?' : c | ('A' - 1));
E 22
I 22
	return (c == DELETE ? '?' : c | ('A' - 1));
E 22
}

dingdong()
{

	if (VB)
		putpad(VB);
	else if (value(ERRORBELLS))
D 22
		putch('\207');
E 22
I 22
		putch('\007');
E 22
}

fixindent(indent)
	int indent;
{
	register int i;
D 22
	register char *cp;
E 22
I 22
	register u_char *cp;
E 22

	i = whitecnt(genbuf);
	cp = vpastwh(genbuf);
	if (*cp == 0 && i == indent && linebuf[0] == 0) {
		genbuf[0] = 0;
		return (i);
	}
	CP(genindent(i), cp);
	return (i);
}

filioerr(cp)
D 22
	char *cp;
E 22
I 22
	u_char *cp;
E 22
{
	register int oerrno = errno;

	lprintf("\"%s\"", cp);
	errno = oerrno;
	syserror();
}

D 22
char *
E 22
I 22
u_char *
E 22
genindent(indent)
	register int indent;
{
D 22
	register char *cp;
E 22
I 22
	register u_char *cp;
E 22

	for (cp = genbuf; indent >= value(TABSTOP); indent -= value(TABSTOP))
		*cp++ = '\t';
	for (; indent > 0; indent--)
		*cp++ = ' ';
	return (cp);
}

getDOT()
{

	getline(*dot);
}

line *
getmark(c)
	register int c;
{
	register line *addr;
	
	for (addr = one; addr <= dol; addr++)
		if (names[c - 'a'] == (*addr &~ 01)) {
			return (addr);
		}
	return (0);
}

getn(cp)
D 22
	register char *cp;
E 22
I 22
	register u_char *cp;
E 22
{
	register int i = 0;

	while (isdigit(*cp))
		i = i * 10 + *cp++ - '0';
	if (*cp)
		return (0);
	return (i);
}

ignnEOF()
{
D 21
	register int c = getchar();
E 21
I 21
	register int c = ex_getchar();
E 21

	if (c == EOF)
		ungetchar(c);
I 4
	else if (c=='"')
		comment();
E 4
}

iswhite(c)
	int c;
{

	return (c == ' ' || c == '\t');
}

junk(c)
	register int c;
{

	if (c && !value(BEAUTIFY))
		return (0);
D 22
	if (c >= ' ' && c != TRIM)
E 22
I 22
	if (c >= ' ' && c != DELETE)
E 22
		return (0);
	switch (c) {

	case '\t':
	case '\n':
	case '\f':
		return (0);

	default:
		return (1);
	}
}

killed()
{

	killcnt(addr2 - addr1 + 1);
}

killcnt(cnt)
	register int cnt;
{

	if (inopen) {
		notecnt = cnt;
		notenam = notesgn = "";
		return;
	}
	if (!notable(cnt))
		return;
D 21
	printf("%d lines", cnt);
E 21
I 21
	ex_printf("%d lines", cnt);
E 21
	if (value(TERSE) == 0) {
D 21
		printf(" %c%s", Command[0] | ' ', Command + 1);
E 21
I 21
		ex_printf(" %c%s", Command[0] | ' ', Command + 1);
E 21
		if (Command[strlen(Command) - 1] != 'e')
D 21
			putchar('e');
		putchar('d');
E 21
I 21
			ex_putchar('e');
		ex_putchar('d');
E 21
	}
	putNFL();
}

lineno(a)
	line *a;
{

	return (a - zero);
}

lineDOL()
{

	return (lineno(dol));
}

lineDOT()
{

	return (lineno(dot));
}

markDOT()
{

	markpr(dot);
}

markpr(which)
	line *which;
{

	if ((inglobal == 0 || inopen) && which <= endcore) {
		names['z'-'a'+1] = *which & ~01;
		if (inopen)
			ncols['z'-'a'+1] = cursor;
	}
}

markreg(c)
	register int c;
{

	if (c == '\'' || c == '`')
		return ('z' + 1);
	if (c >= 'a' && c <= 'z')
		return (c);
	return (0);
}

/*
 * Mesg decodes the terse/verbose strings. Thus
 *	'xxx@yyy' -> 'xxx' if terse, else 'xxx yyy'
 *	'xxx|yyy' -> 'xxx' if terse, else 'yyy'
 * All others map to themselves.
 */
D 22
char *
E 22
I 22
u_char *
E 22
mesg(str)
D 22
	register char *str;
E 22
I 22
	register u_char *str;
E 22
{
D 22
	register char *cp;
E 22
I 22
	register u_char *cp;
E 22

	str = strcpy(genbuf, str);
	for (cp = str; *cp; cp++)
		switch (*cp) {

		case '@':
			if (value(TERSE))
				*cp = 0;
			else
				*cp = ' ';
			break;

		case '|':
			if (value(TERSE) == 0)
				return (cp + 1);
			*cp = 0;
			break;
		}
	return (str);
}

/*VARARGS2*/
merror(seekpt, i)
D 2
#ifdef lint
E 2
I 2
D 21
#ifdef VMUNIX
E 21
I 21
#ifndef EXSTRINGS
E 21
E 2
D 22
	char *seekpt;
E 22
I 22
	u_char *seekpt;
E 22
#else
I 2
# ifdef lint
D 22
	char *seekpt;
E 22
I 22
	u_char *seekpt;
E 22
# else
E 2
	int seekpt;
I 2
# endif
E 2
#endif
	int i;
{
D 22
	register char *cp = linebuf;
E 22
I 22
	register u_char *cp = linebuf;
E 22

	if (seekpt == 0)
		return;
	merror1(seekpt);
	if (*cp == '\n')
		putnl(), cp++;
D 11
	if (inopen && CE)
E 11
I 11
	if (inopen > 0 && CE)
E 11
		vclreol();
	if (SO && SE)
		putpad(SO);
D 21
	printf(mesg(cp), i);
E 21
I 21
	ex_printf(mesg(cp), i);
E 21
	if (SO && SE)
		putpad(SE);
}

merror1(seekpt)
D 2
#ifdef lint
E 2
I 2
D 21
#ifdef VMUNIX
E 21
I 21
#ifndef EXSTRINGS
E 21
E 2
D 22
	char *seekpt;
E 22
I 22
	u_char *seekpt;
E 22
#else
I 2
# ifdef lint
D 22
	char *seekpt;
E 22
I 22
	u_char *seekpt;
E 22
# else
E 2
	int seekpt;
I 2
# endif
E 2
#endif
{

I 2
D 21
#ifdef VMUNIX
E 21
I 21
#ifndef EXSTRINGS
E 21
	strcpy(linebuf, seekpt);
#else
E 2
	lseek(erfile, (long) seekpt, 0);
	if (read(erfile, linebuf, 128) < 2)
		CP(linebuf, "ERROR");
I 2
#endif
E 2
}

morelines()
{
I 21
#ifdef UNIX_SBRK
	char *sbrk();
E 21

	if ((int) sbrk(1024 * sizeof (line)) == -1)
		return (-1);
	endcore += 1024;
	return (0);
I 21
#else
	/*
	 * We can never be guaranteed that we can get more memory
	 * beyond "endcore".  So we just punt every time.
	 */
	return -1;
#endif
E 21
}

nonzero()
{

	if (addr1 == zero) {
		notempty();
		error("Nonzero address required@on this command");
	}
}

notable(i)
	int i;
{

	return (hush == 0 && !inglobal && i > value(REPORT));
}


notempty()
{

	if (dol == zero)
		error("No lines@in the buffer");
}


netchHAD(cnt)
	int cnt;
{

	netchange(lineDOL() - cnt);
}

netchange(i)
	register int i;
{
D 22
	register char *cp;
E 22
I 22
	register u_char *cp;
E 22

	if (i > 0)
		notesgn = cp = "more ";
	else
		notesgn = cp = "fewer ", i = -i;
	if (inopen) {
		notecnt = i;
		notenam = "";
		return;
	}
	if (!notable(i))
		return;
D 21
	printf(mesg("%d %slines@in file after %s"), i, cp, Command);
E 21
I 21
	ex_printf(mesg("%d %slines@in file after %s"), i, cp, Command);
E 21
	putNFL();
}

putmark(addr)
	line *addr;
{

	putmk1(addr, putline());
}

putmk1(addr, n)
	register line *addr;
	int n;
{
	register line *markp;
I 4
	register oldglobmk;
E 4

I 4
	oldglobmk = *addr & 1;
E 4
	*addr &= ~1;
	for (markp = (anymarks ? names : &names['z'-'a'+1]);
	  markp <= &names['z'-'a'+1]; markp++)
		if (*markp == *addr)
			*markp = n;
D 4
	*addr = n;
E 4
I 4
	*addr = n | oldglobmk;
E 4
}

D 22
char *
E 22
I 22
u_char *
E 22
plural(i)
	long i;
{

	return (i == 1 ? "" : "s");
}

int	qcount();
short	vcntcol;

qcolumn(lim, gp)
D 22
	register char *lim, *gp;
E 22
I 22
	register u_char *lim, *gp;
E 22
{
	register int x;
	int (*OO)();

	OO = Outchar;
	Outchar = qcount;
	vcntcol = 0;
	if (lim != NULL)
		x = lim[1], lim[1] = 0;
	pline(0);
	if (lim != NULL)
		lim[1] = x;
	if (gp)
		while (*gp)
D 21
			putchar(*gp++);
E 21
I 21
			ex_putchar(*gp++);
E 21
	Outchar = OO;
	return (vcntcol);
}

int
qcount(c)
	int c;
{

	if (c == '\t') {
		vcntcol += value(TABSTOP) - vcntcol % value(TABSTOP);
		return;
	}
	vcntcol++;
}

reverse(a1, a2)
	register line *a1, *a2;
{
	register line t;

	for (;;) {
		t = *--a2;
		if (a2 <= a1)
			return;
		*a2 = *a1;
		*a1++ = t;
	}
}

save(a1, a2)
	line *a1;
	register line *a2;
{
	register int more;

I 3
	if (!FIXUNDO)
		return;
#ifdef TRACE
	if (trace)
		vudump("before save");
#endif
E 3
	undkind = UNDNONE;
	undadot = dot;
	more = (a2 - a1 + 1) - (unddol - dol);
	while (more > (endcore - truedol))
		if (morelines() < 0)
I 21
#ifdef UNIX_SBRK
E 21
D 7
			error("Out of memory@saving lines for undo - try using ed or re");
E 7
I 7
			error("Out of memory@saving lines for undo - try using ed");
I 21
#else
			error("Out of memory@saving lines for undo - try increasing linelimit");
#endif
E 21
E 7
	if (more)
		(*(more > 0 ? copywR : copyw))(unddol + more + 1, unddol + 1,
		    (truedol - unddol));
	unddol += more;
	truedol += more;
	copyw(dol + 1, a1, a2 - a1 + 1);
	undkind = UNDALL;
	unddel = a1 - 1;
	undap1 = a1;
	undap2 = a2 + 1;
I 3
#ifdef TRACE
	if (trace)
		vudump("after save");
#endif
E 3
}

save12()
{

	save(addr1, addr2);
}

saveall()
{

	save(one, dol);
}

span()
{

	return (addr2 - addr1 + 1);
}

D 21
sync()
E 21
I 21
ex_sync()
E 21
{

	chng = 0;
	tchng = 0;
	xchng = 0;
}


skipwh()
{
	register int wh;

	wh = 0;
	while (iswhite(peekchar())) {
		wh++;
		ignchar();
	}
	return (wh);
}

/*VARARGS2*/
smerror(seekpt, cp)
#ifdef lint
D 22
	char *seekpt;
E 22
I 22
	u_char *seekpt;
E 22
#else
	int seekpt;
#endif
D 22
	char *cp;
E 22
I 22
	u_char *cp;
E 22
{

	if (seekpt == 0)
		return;
	merror1(seekpt);
	if (inopen && CE)
		vclreol();
	if (SO && SE)
		putpad(SO);
	lprintf(mesg(linebuf), cp);
	if (SO && SE)
		putpad(SE);
}

D 15
#define	std_nerrs (sizeof std_errlist / sizeof std_errlist[0])

#define	error(i)	i

#ifdef lint
char	*std_errlist[] = {
#else
I 2
D 3
#ifdef VMUNIX
E 3
I 3
# ifdef VMUNIX
E 3
char	*std_errlist[] = {
D 3
#else
E 3
I 3
# else
E 3
E 2
short	std_errlist[] = {
I 2
D 3
#endif
E 3
I 3
# endif
E 3
E 2
#endif
	error("Error 0"),
	error("Not super-user"),
	error("No such file or directory"),
	error("No such process"),
	error("Interrupted system call"),
	error("Physical I/O error"),
	error("No such device or address"),
	error("Argument list too long"),
	error("Exec format error"),
	error("Bad file number"),
	error("No children"),
	error("No more processes"),
	error("Not enough core"),
	error("Permission denied"),
	error("Bad address"),
	error("Block device required"),
	error("Mount device busy"),
	error("File exists"),
	error("Cross-device link"),
	error("No such device"),
	error("Not a directory"),
	error("Is a directory"),
	error("Invalid argument"),
	error("File table overflow"),
	error("Too many open files"),
	error("Not a typewriter"),
	error("Text file busy"),
	error("File too large"),
	error("No space left on device"),
	error("Illegal seek"),
	error("Read-only file system"),
	error("Too many links"),
D 8
	error("Broken pipe")
#ifndef QUOTA
	, error("Math argument")
	, error("Result too large")
#else
	, error("Quota exceeded")
E 8
I 8
	error("Broken pipe"),
#ifndef V6
	error("Math argument"),
	error("Result too large"),
E 8
#endif
I 8
	error("Quota exceeded")		/* Berkeley quota systems only */
E 8
};

#undef	error

E 15
D 22
char *
E 22
I 22
u_char *
E 22
strend(cp)
D 22
	register char *cp;
E 22
I 22
	register u_char *cp;
E 22
{

	while (*cp)
		cp++;
	return (cp);
}

strcLIN(dp)
D 22
	char *dp;
E 22
I 22
	u_char *dp;
E 22
{

	CP(linebuf, dp);
}

syserror()
{
	register int e = errno;
I 21
#ifndef	vms
E 21
I 15
	extern int sys_nerr;
	extern char *sys_errlist[];
I 21
#else
	extern noshare int sys_nerr;
	extern noshare char *sys_errlist[];
#endif
E 21
E 15

	dirtcnt = 0;
D 21
	putchar(' ');
E 21
I 21
	ex_putchar(' ');
E 21
I 7
D 12
	edited = 0;	/* for temp file errors, for example */
E 12
E 7
D 15
	if (e >= 0 && errno <= std_nerrs)
		error(std_errlist[e]);
E 15
I 15
	if (e >= 0 && e <= sys_nerr)
		error(sys_errlist[e]);
E 15
	else
I 21
#ifdef vms
		if (e == EVMSERR) {
			error("VMS system error %d", vaxc$errno);
			perror("vmserror");
		}
		else
#endif
E 21
		error("System error %d", e);
}

I 4
/*
 * Return the column number that results from being in column col and
 * hitting a tab, where tabs are set every ts columns.  Work right for
 * the case where col > COLUMNS, even if ts does not divide COLUMNS.
 */
tabcol(col, ts)
int col, ts;
{
	int offset, result;

	if (col >= COLUMNS) {
		offset = COLUMNS * (col/COLUMNS);
		col -= offset;
	} else
		offset = 0;
	result = col + ts - (col % ts) + offset;
	return (result);
}

E 4
D 22
char *
E 22
I 22
u_char *
E 22
vfindcol(i)
	int i;
{
D 22
	register char *cp;
E 22
I 22
	register u_char *cp;
E 22
	register int (*OO)() = Outchar;

	Outchar = qcount;
	ignore(qcolumn(linebuf - 1, NOSTR));
	for (cp = linebuf; *cp && vcntcol < i; cp++)
D 21
		putchar(*cp);
E 21
I 21
		ex_putchar(*cp);
E 21
	if (cp != linebuf)
		cp--;
	Outchar = OO;
	return (cp);
}

D 22
char *
E 22
I 22
u_char *
E 22
vskipwh(cp)
D 22
	register char *cp;
E 22
I 22
	register u_char *cp;
E 22
{

	while (iswhite(*cp) && cp[1])
		cp++;
	return (cp);
}


D 22
char *
E 22
I 22
u_char *
E 22
vpastwh(cp)
D 22
	register char *cp;
E 22
I 22
	register u_char *cp;
E 22
{

	while (iswhite(*cp))
		cp++;
	return (cp);
}

whitecnt(cp)
D 22
	register char *cp;
E 22
I 22
	register u_char *cp;
E 22
{
	register int i;

	i = 0;
	for (;;)
		switch (*cp++) {

		case '\t':
			i += value(TABSTOP) - i % value(TABSTOP);
			break;

		case ' ':
			i++;
			break;

		default:
			return (i);
		}
}

#ifdef lint
Ignore(a)
D 22
	char *a;
E 22
I 22
	u_char *a;
E 22
{

	a = a;
}

Ignorf(a)
	int (*a)();
{

	a = a;
}
#endif

markit(addr)
	line *addr;
{

	if (addr != dot && addr >= one && addr <= dol)
		markDOT();
I 8
}

/*
 * The following code is defensive programming against a bug in the
 * pdp-11 overlay implementation.  Sometimes it goes nuts and asks
 * for an overlay with some garbage number, which generates an emt
 * trap.  This is a less than elegant solution, but it is somewhat
 * better than core dumping and losing your work, leaving your tty
 * in a weird state, etc.
 */
int _ovno;
onemt()
{
D 21
	int oovno;

E 21
	signal(SIGEMT, onemt);
D 21
	oovno = _ovno;
E 21
	/* 2 and 3 are valid on 11/40 type vi, so */
	if (_ovno < 0 || _ovno > 3)
		_ovno = 0;
	error("emt trap, _ovno is %d @ - try again");
E 8
}
I 9

/*
 * When a hangup occurs our actions are similar to a preserve
 * command.  If the buffer has not been [Modified], then we do
 * nothing but remove the temporary files and exit.
 * Otherwise, we sync the temp file and then attempt a preserve.
 * If the preserve succeeds, we unlink our temp files.
 * If the preserve fails, we leave the temp files as they are
 * as they are a backup even without preservation if they
 * are not removed.
 */
onhup()
{

	/*
	 * USG tty driver can send multiple HUP's!!
	 */
	signal(SIGINT, SIG_IGN);
	signal(SIGHUP, SIG_IGN);
	if (chng == 0) {
		cleanup(1);
D 21
		exit(0);
E 21
I 21
		ex_exit(0);
E 21
	}
	if (setexit() == 0) {
		if (preserve()) {
			cleanup(1);
D 21
			exit(0);
E 21
I 21
			ex_exit(0);
E 21
		}
	}
D 21
	exit(1);
E 21
I 21
	ex_exit(1);
E 21
}

/*
 * An interrupt occurred.  Drain any output which
 * is still in the output buffering pipeline.
 * Catch interrupts again.  Unless we are in visual
 * reset the output state (out of -nl mode, e.g).
 * Then like a normal error (with the \n before Interrupt
 * suppressed in visual mode).
 */
onintr()
{

#ifndef CBREAK
	signal(SIGINT, onintr);
#else
	signal(SIGINT, inopen ? vintr : onintr);
#endif
I 10
	alarm(0);	/* in case we were called from map */
E 10
	draino();
	if (!inopen) {
		pstop();
		setlastchar('\n');
#ifdef CBREAK
	}
#else
	} else
		vraw();
#endif
	error("\nInterrupt" + inopen);
}

/*
 * If we are interruptible, enable interrupts again.
 * In some critical sections we turn interrupts off,
 * but not very often.
 */
setrupt()
{

	if (ruptible) {
#ifndef CBREAK
		signal(SIGINT, onintr);
#else
		signal(SIGINT, inopen ? vintr : onintr);
#endif
#ifdef SIGTSTP
		if (dosusp)
			signal(SIGTSTP, onsusp);
#endif
	}
}

preserve()
{

#ifdef VMUNIX
	tflush();
#endif
	synctmp();
D 21
	pid = fork();
E 21
I 21
	pid = vfork();
E 21
	if (pid < 0)
		return (0);
	if (pid == 0) {
		close(0);
		dup(tfile);
D 22
		execl(EXPRESERVE, "expreserve", (char *) 0);
E 22
I 22
		execl(EXPRESERVE, "expreserve", (u_char *) 0);
E 22
D 21
		exit(1);
E 21
I 21
		ex_exit(1);
E 21
	}
	waitfor();
	if (rpid == pid && status == 0)
		return (1);
	return (0);
}

#ifndef V6
D 21
exit(i)
E 21
I 21
ex_exit(i)
E 21
	int i;
{

# ifdef TRACE
	if (trace)
		fclose(trace);
# endif
	_exit(i);
}
#endif

#ifdef SIGTSTP
/*
 * We have just gotten a susp.  Suspend and prepare to resume.
 */
onsusp()
{
	ttymode f;
I 14
D 21
	int omask;
E 21
I 16
	struct winsize win;
E 16
E 14

	f = setty(normf);
	vnfl();
	putpad(TE);
	flush();

I 14
	(void) sigsetmask(0);
E 14
	signal(SIGTSTP, SIG_DFL);
	kill(0, SIGTSTP);

	/* the pc stops here */

	signal(SIGTSTP, onsusp);
	vcontin(0);
D 21
	setty(f);
E 21
I 21
	ignore(setty(f));
E 21
	if (!inopen)
D 21
		error(0);
E 21
I 21
D 22
		error((char *) 0);
E 22
I 22
		error((u_char *) 0);
E 22
E 21
	else {
I 21
#ifdef	TIOCGWINSZ
E 21
I 16
		if (ioctl(0, TIOCGWINSZ, &win) >= 0)
D 17
			if (win.ws_row != winsz.ws_row 
					|| win.ws_col != winsz.ws_col)
E 17
I 17
			if (win.ws_row != winsz.ws_row ||
			    win.ws_col != winsz.ws_col)
E 17
				winch();
I 21
#endif
E 21
E 16
		if (vcnt < 0) {
			vcnt = -vcnt;
			if (state == VISUAL)
				vclear();
			else if (state == CRTOPEN)
				vcnt = 0;
		}
		vdirty(0, LINES);
		vrepaint(cursor);
	}
}
I 13
#endif
E 13
E 9
D 4

E 4
E 1
