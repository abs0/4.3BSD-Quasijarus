h15169
s 00024/00021/00676
d D 6.11 03/04/13 15:19:22 msokolov 18 17
c 8-bit ex
e
s 00006/00006/00691
d D 6.10 88/01/02 23:12:31 bostic 17 16
c fix CTRL macro for ANSI C
e
s 00027/00024/00670
d D 6.9 87/03/09 12:46:21 conrad 16 15
c make ex/vi work on vms
e
s 00001/00001/00693
d D 6.8 85/06/07 18:22:00 bloom 15 14
c fix sccsid and copyright for xstr
e
s 00010/00002/00684
d D 6.7 85/05/31 14:00:34 dist 14 12
c Add copyright
e
s 00010/00002/00651
d D 5.1.1.1 85/05/31 12:11:34 dist 13 6
c Add copyright
e
s 00005/00001/00681
d D 6.6 85/01/23 14:23:47 ralph 12 11
c don't replace current line if ESC ^C is typed.
e
s 00005/00001/00677
d D 6.5 83/06/18 17:24:57 sam 11 10
c do longjmp's only when we should
e
s 00003/00000/00675
d D 6.4 83/06/15 13:51:40 sam 10 9
c new signals
e
s 00026/00011/00649
d D 6.3 81/07/08 22:32:58 mark 9 8
c release 3.7 - a few bug fixes and a few new features.
e
s 00009/00002/00651
d D 6.2 80/10/23 16:14:43 mark 8 7
c fixed various bugs prior to 3.6 release
e
s 00001/00001/00652
d D 6.1 80/10/19 01:22:04 mark 7 6
c preliminary release 3.6 10/18/80
e
s 00000/00000/00653
d D 5.1 80/08/20 16:13:25 mark 6 5
c Release 3.5, August 20, 1980
e
s 00002/00001/00651
d D 4.2 80/08/01 20:42:36 mark 5 4
c Bill added more buffers, and I put in sccs.
e
s 00091/00011/00561
d D 4.1 80/08/01 00:17:12 mark 4 3
c release 3.4, June 24, 1980
e
s 00043/00017/00529
d D 3.1 80/07/31 23:41:01 mark 3 2
c release 3.3, Feb 2, 1980
e
s 00022/00010/00524
d D 2.1 80/07/31 23:20:25 mark 2 1
c release 3.2, Jan 4, 1980
e
s 00534/00000/00000
d D 1.1 80/07/31 23:00:43 mark 1 0
c date and time created 80/07/31 23:00:43 by mark
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
D 9
D 13
/* Copyright (c) 1980 Regents of the University of California */
E 9
I 9
D 14
/* Copyright (c) 1981 Regents of the University of California */
E 9
static char *sccsid = "%W% %G%";
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
E 5
#include "ex.h"
#include "ex_tty.h"
#include "ex_vis.h"

/*
 * Input routines for open/visual.
 * We handle upper case only terminals in visual and reading from the
 * echo area here as well as notification on large changes
 * which appears in the echo area.
 */

/*
 * Return the key.
 */
ungetkey(c)
D 9
	char c;
E 9
I 9
	int c;		/* mjm: char --> int */
E 9
{

D 16
	if (Peekkey != ATTN)
		Peekkey = c;
E 16
I 16
	if (Peek_key != ATTN)
		Peek_key = c;
E 16
}

/*
 * Return a keystroke, but never a ^@.
 */
getkey()
{
D 9
	register char c;
E 9
I 9
	register int c;		/* mjm: char --> int */
E 9

	do {
		c = getbr();
		if (c==0)
			beep();
	} while (c == 0);
	return (c);
}

/*
 * Tell whether next keystroke would be a ^@.
 */
peekbr()
{

D 16
	Peekkey = getbr();
	return (Peekkey == 0);
E 16
I 16
	Peek_key = getbr();
	return (Peek_key == 0);
E 16
}

short	precbksl;
I 10
jmp_buf	readbuf;
I 11
int	doingread = 0;
E 11
E 10

/*
 * Get a keystroke, including a ^@.
 * If an key was returned with ungetkey, that
 * comes back first.  Next comes unread input (e.g.
 * from repeating commands with .), and finally new
 * keystrokes.
 *
 * The hard work here is in mapping of \ escaped
 * characters on upper case only terminals.
 */
getbr()
{
D 18
	char ch;
E 18
I 18
	u_char ch;
E 18
	register int c, d;
D 18
	register char *colp;
E 18
I 18
	register u_char *colp;
E 18
I 9
D 16
	int cnt;
E 16
E 9
I 4
#define BEEHIVE
#ifdef BEEHIVE
D 18
	static char Peek2key;
E 18
I 18
	static u_char Peek2key;
E 18
#endif
	extern short slevel, ttyindes;
E 4

getATTN:
D 16
	if (Peekkey) {
		c = Peekkey;
		Peekkey = 0;
E 16
I 16
	if (Peek_key) {
		c = Peek_key;
		Peek_key = 0;
E 16
		return (c);
	}
I 4
#ifdef BEEHIVE
	if (Peek2key) {
		c = Peek2key;
		Peek2key = 0;
		return (c);
	}
#endif
E 4
	if (vglobp) {
		if (*vglobp)
			return (lastvgk = *vglobp++);
		lastvgk = 0;
		return (ESCAPE);
	}
	if (vmacp) {
		if (*vmacp)
			return(*vmacp++);
		/* End of a macro or set of nested macros */
		vmacp = 0;
I 2
		if (inopen == -1)	/* don't screw up undo for esc esc */
			vundkind = VMANY;
E 2
		inopen = 1;	/* restore old setting now that macro done */
I 4
		vch_mac = VC_NOTINMAC;
E 4
D 2
		vundkind = VMANY;
E 2
	}
D 3
#ifdef TRACE
	if (trace)
		fflush(trace);
#endif
E 3
	flusho();
again:
I 10
	if (setjmp(readbuf))
		goto getATTN;
E 10
D 4
	if (read(0, &ch, 1) != 1) {
E 4
I 4
D 9
	if (read(slevel == 0 ? 0 : ttyindes, &ch, 1) != 1) {
E 9
I 9
D 11
	if ((c=read(slevel == 0 ? 0 : ttyindes, &ch, 1)) != 1) {
E 11
I 11
	doingread = 1;
I 16
#ifndef	vms
E 16
	c = read(slevel == 0 ? 0 : ttyindes, &ch, 1);
I 16
#else
	c = vms_read(slevel == 0 ? 0 : ttyindes, &ch, 1);
#endif
E 16
	doingread = 0;
	if (c != 1) {
E 11
E 9
E 4
		if (errno == EINTR)
			goto getATTN;
		error("Input read error");
	}
D 18
	c = ch & TRIM;
E 18
I 18
	c = ch;
	if (!value(EIGHTBIT) && !isascii(c))
		c &= TRIM7;
E 18
I 4
#ifdef BEEHIVE
	if (XB && slevel==0 && c == ESCAPE) {
		if (read(0, &Peek2key, 1) != 1)
			goto getATTN;
D 18
		Peek2key &= TRIM;
E 18
I 18
		if (!value(EIGHTBIT) && !isascii(Peek2key))
			Peek2key &= TRIM7;
E 18
		switch (Peek2key) {
		case 'C':	/* SPOW mode sometimes sends \EC for space */
			c = ' ';
			Peek2key = 0;
			break;
		case 'q':	/* f2 -> ^C */
D 17
			c = CTRL(c);
E 17
I 17
			c = CTRL('c');
E 17
			Peek2key = 0;
			break;
		case 'p':	/* f1 -> esc */
			Peek2key = 0;
			break;
		}
	}
#endif
E 4

#ifdef UCVISUAL
	/*
	 * The algorithm here is that of the UNIX kernel.
	 * See the description in the programmers manual.
	 */
	if (UPPERCASE) {
		if (isupper(c))
			c = tolower(c);
		if (c == '\\') {
			if (precbksl < 2)
				precbksl++;
			if (precbksl == 1)
				goto again;
		} else if (precbksl) {
			d = 0;
			if (islower(c))
				d = toupper(c);
			else {
				colp = "({)}!|^~'~";
				while (d = *colp++)
					if (d == c) {
						d = *colp++;
						break;
					} else
						colp++;
			}
			if (precbksl == 2) {
				if (!d) {
D 16
					Peekkey = c;
E 16
I 16
					Peek_key = c;
E 16
					precbksl = 0;
					c = '\\';
				}
			} else if (d)
				c = d;
			else {
D 16
				Peekkey = c;
E 16
I 16
				Peek_key = c;
E 16
				precbksl = 0;
				c = '\\';
			}
		}
		if (c != '\\')
			precbksl = 0;
	}
#endif
#ifdef TRACE
	if (trace) {
		if (!techoin) {
			tfixnl();
			techoin = 1;
			fprintf(trace, "*** Input: ");
		}
		tracec(c);
	}
#endif
	lastvgk = 0;
	return (c);
}

/*
 * Get a key, but if a delete, quit or attention
 * is typed return 0 so we will abort a partial command.
 */
getesc()
{
	register int c;

	c = getkey();
	switch (c) {

I 3
D 17
	case CTRL(v):
	case CTRL(q):
E 17
I 17
	case CTRL('v'):
	case CTRL('q'):
E 17
		c = getkey();
		return (c);

E 3
	case ATTN:
	case QUIT:
		ungetkey(c);
		return (0);

	case ESCAPE:
		return (0);
	}
	return (c);
}

/*
 * Peek at the next keystroke.
 */
peekkey()
{

D 16
	Peekkey = getkey();
	return (Peekkey);
E 16
I 16
	Peek_key = getkey();
	return (Peek_key);
E 16
}

/*
 * Read a line from the echo area, with single character prompt c.
 * A return value of 1 means the user blewit or blewit away.
 */
readecho(c)
D 18
	char c;
E 18
I 18
	u_char c;
E 18
{
D 18
	register char *sc = cursor;
E 18
I 18
	register u_char *sc = cursor;
E 18
	register int (*OP)();
	bool waste;
	register int OPeek;

	if (WBOT == WECHO)
		vclean();
	else
		vclrech(0);
	splitw++;
	vgoto(WECHO, 0);
D 16
	putchar(c);
E 16
I 16
	ex_putchar(c);
E 16
	vclreol();
	vgoto(WECHO, 1);
	cursor = linebuf; linebuf[0] = 0; genbuf[0] = c;
	if (peekbr()) {
D 18
		if (!INS[0] || (INS[0] & (QUOTE|TRIM)) == OVERBUF)
E 18
I 18
		if (!INS[0] || INS[0] == OVERBUF)
E 18
			goto blewit;
		vglobp = INS;
	}
	OP = Pline; Pline = normline;
D 7
	ignore(vgetline(0, genbuf + 1, &waste));
E 7
I 7
	ignore(vgetline(0, genbuf + 1, &waste, c));
E 7
I 4
	if (Outchar == termchar)
D 16
		putchar('\n');
E 16
I 16
		ex_putchar('\n');
E 16
E 4
	vscrap();
	Pline = OP;
D 16
	if (Peekkey != ATTN && Peekkey != QUIT && Peekkey != CTRL(h)) {
E 16
I 16
D 17
	if (Peek_key != ATTN && Peek_key != QUIT && Peek_key != CTRL(h)) {
E 17
I 17
	if (Peek_key != ATTN && Peek_key != QUIT && Peek_key != CTRL('h')) {
E 17
E 16
		cursor = sc;
		vclreol();
		return (0);
	}
blewit:
D 16
	OPeek = Peekkey==CTRL(h) ? 0 : Peekkey; Peekkey = 0;
E 16
I 16
D 17
	OPeek = Peek_key==CTRL(h) ? 0 : Peek_key; Peek_key = 0;
E 17
I 17
	OPeek = Peek_key==CTRL('h') ? 0 : Peek_key; Peek_key = 0;
E 17
E 16
	splitw = 0;
	vclean();
	vshow(dot, NOLINE);
	vnline(sc);
D 16
	Peekkey = OPeek;
E 16
I 16
	Peek_key = OPeek;
E 16
	return (1);
}

/*
 * A complete command has been defined for
 * the purposes of repeat, so copy it from
 * the working to the previous command buffer.
 */
setLAST()
{

D 4
	if (vglobp)
E 4
I 4
	if (vglobp || vmacp)
E 4
		return;
	lastreg = vreg;
	lasthad = Xhadcnt;
	lastcnt = Xcnt;
	*lastcp = 0;
	CP(lastcmd, workcmd);
}

/*
 * Gather up some more text from an insert.
 * If the insertion buffer oveflows, then destroy
 * the repeatability of the insert.
 */
addtext(cp)
D 18
	char *cp;
E 18
I 18
	u_char *cp;
E 18
{

	if (vglobp)
		return;
	addto(INS, cp);
D 18
	if ((INS[0] & (QUOTE|TRIM)) == OVERBUF)
E 18
I 18
	if (INS[0] == OVERBUF)
E 18
		lastcmd[0] = 0;
}

setDEL()
{

D 16
	setBUF(DEL);
E 16
I 16
	ex_setBUF(DEL);
E 16
}

/*
 * Put text from cursor upto wcursor in BUF.
 */
D 16
setBUF(BUF)
E 16
I 16
ex_setBUF(BUF)
E 16
D 18
	register char *BUF;
E 18
I 18
	register u_char *BUF;
E 18
{
	register int c;
D 18
	register char *wp = wcursor;
E 18
I 18
	register u_char *wp = wcursor;
E 18

	c = *wp;
	*wp = 0;
	BUF[0] = 0;
	addto(BUF, cursor);
	*wp = c;
}

addto(buf, str)
D 18
	register char *buf, *str;
E 18
I 18
	register u_char *buf, *str;
E 18
{

D 18
	if ((buf[0] & (QUOTE|TRIM)) == OVERBUF)
E 18
I 18
	if (buf[0] == OVERBUF)
E 18
		return;
	if (strlen(buf) + strlen(str) + 1 >= VBSIZE) {
		buf[0] = OVERBUF;
		return;
	}
	ignore(strcat(buf, str));
}

/*
 * Note a change affecting a lot of lines, or non-visible
 * lines.  If the parameter must is set, then we only want
 * to do this for open modes now; return and save for later
 * notification in visual.
 */
noteit(must)
	bool must;
{
	register int sdl = destline, sdc = destcol;

	if (notecnt < 2 || !must && state == VISUAL)
		return (0);
	splitw++;
	if (WBOT == WECHO)
		vmoveitup(1, 1);
	vigoto(WECHO, 0);
D 16
	printf("%d %sline", notecnt, notesgn);
E 16
I 16
	ex_printf("%d %sline", notecnt, notesgn);
E 16
	if (notecnt > 1)
D 16
		putchar('s');
E 16
I 16
		ex_putchar('s');
E 16
	if (*notenam) {
D 16
		printf(" %s", notenam);
E 16
I 16
		ex_printf(" %s", notenam);
E 16
		if (*(strend(notenam) - 1) != 'e')
D 16
			putchar('e');
		putchar('d');
E 16
I 16
			ex_putchar('e');
		ex_putchar('d');
E 16
	}
	vclreol();
	notecnt = 0;
	if (state != VISUAL)
		vcnt = vcline = 0;
	splitw = 0;
	if (state == ONEOPEN || state == CRTOPEN)
		vup1();
	destline = sdl; destcol = sdc;
	return (1);
}

/*
 * Rrrrringgggggg.
 * If possible, use flash (VB).
 */
beep()
{

	if (VB)
		vputp(VB, 0);
	else
D 17
		vputc(CTRL(g));
E 17
I 17
		vputc(CTRL('g'));
E 17
}

/*
 * Map the command input character c,
 * for keypads and labelled keys which do cursor
 * motions.  I.e. on an adm3a we might map ^K to ^P.
 * DM1520 for example has a lot of mappable characters.
 */

map(c,maps)
	register int c;
	register struct maps *maps;
{
	register int d;
D 18
	register char *p, *q;
	char b[10];	/* Assumption: no keypad sends string longer than 10 */
E 18
I 18
	register u_char *p, *q;
	u_char b[10];	/* Assumption: no keypad sends string longer than 10 */
E 18

	/*
	 * Mapping for special keys on the terminal only.
	 * BUG: if there's a long sequence and it matches
	 * some chars and then misses, we lose some chars.
	 *
	 * For this to work, some conditions must be met.
	 * 1) Keypad sends SHORT (2 or 3 char) strings
	 * 2) All strings sent are same length & similar
	 * 3) The user is unlikely to type the first few chars of
	 *    one of these strings very fast.
	 * Note: some code has been fixed up since the above was laid out,
	 * so conditions 1 & 2 are probably not required anymore.
	 * However, this hasn't been tested with any first char
	 * that means anything else except escape.
	 */
#ifdef MDEBUG
	if (trace)
		fprintf(trace,"map(%c): ",c);
#endif
I 4
	/*
	 * If c==0, the char came from getesc typing escape.  Pass it through
	 * unchanged.  0 messes up the following code anyway.
	 */
	if (c==0)
		return(0);

E 4
	b[0] = c;
	b[1] = 0;
	for (d=0; maps[d].mapto; d++) {
#ifdef MDEBUG
		if (trace)
D 4
			fprintf(trace,"d=%d, ",d);
E 4
I 4
			fprintf(trace,"\ntry '%s', ",maps[d].cap);
E 4
#endif
		if (p = maps[d].cap) {
			for (q=b; *p; p++, q++) {
#ifdef MDEBUG
				if (trace)
					fprintf(trace,"q->b[%d], ",q-b);
#endif
				if (*q==0) {
					/*
I 4
					 * Is there another char waiting?
					 *
E 4
					 * This test is oversimplified, but
					 * should work mostly. It handles the
					 * case where we get an ESCAPE that
					 * wasn't part of a keypad string.
					 */
					if ((c=='#' ? peekkey() : fastpeekkey()) == 0) {
#ifdef MDEBUG
D 3
					if (trace)
						fprintf(trace,"fpk=0: return %c",c);
E 3
I 3
						if (trace)
D 4
							fprintf(trace,"fpk=0: return %c",c);
E 4
I 4
D 9
							fprintf(trace,"fpk=0: return '%c'",c);
E 9
I 9
							fprintf(trace,"fpk=0: will return '%c'",c);
E 9
E 4
E 3
#endif
D 2
						macpush(&b[1]);
E 2
I 2
D 3
						macpush(&b[1],1);
E 3
I 3
						/*
I 4
						 * Nothing waiting.  Push back
						 * what we peeked at & return
						 * failure (c).
						 *
E 4
						 * We want to be able to undo
						 * commands, but it's nonsense
						 * to undo part of an insertion
						 * so if in input mode don't.
						 */
I 9
#ifdef MDEBUG
						if (trace)
							fprintf(trace, "Call macpush, b %d %d %d\n", b[0], b[1], b[2]);
#endif
E 9
						macpush(&b[1],maps == arrows);
I 9
#ifdef MDEBUG
						if (trace)
							fprintf(trace, "return %d\n", c);	
#endif
E 9
E 3
E 2
						return(c);
					}
					*q = getkey();
					q[1] = 0;
				}
				if (*p != *q)
					goto contin;
			}
D 2
			macpush(maps[d].mapto);
E 2
I 2
D 4
			macpush(maps[d].mapto,1);
E 4
I 4
			macpush(maps[d].mapto,maps == arrows);
E 4
E 2
			c = getkey();
#ifdef MDEBUG
D 4
	if (trace)
		fprintf(trace,"Success: return %c",c);
E 4
I 4
			if (trace)
				fprintf(trace,"Success: push(%s), return %c",maps[d].mapto, c);
E 4
#endif
			return(c);	/* first char of map string */
			contin:;
		}
	}
#ifdef MDEBUG
	if (trace)
D 4
		fprintf(trace,"Fail: return %c",c); /* DEBUG */
E 4
I 4
		fprintf(trace,"Fail: push(%s), return %c", &b[1], c);
E 4
#endif
D 2
	macpush(&b[1]);
E 2
I 2
	macpush(&b[1],0);
E 2
	return(c);
}

/*
 * Push st onto the front of vmacp. This is tricky because we have to
 * worry about where vmacp was previously pointing. We also have to
 * check for overflow (which is typically from a recursive macro)
 * Finally we have to set a flag so the whole thing can be undone.
I 2
 * canundo is 1 iff we want to be able to undo the macro.  This
 * is false for, for example, pushing back lookahead from fastpeekkey(),
 * since otherwise two fast escapes can clobber our undo.
E 2
 */
D 2
macpush(st)
E 2
I 2
macpush(st, canundo)
E 2
D 18
char *st;
E 18
I 18
u_char *st;
E 18
I 2
int canundo;
E 2
{
D 18
	char tmpbuf[BUFSIZ];
E 18
I 18
	u_char tmpbuf[BUFSIZ];
E 18

	if (st==0 || *st==0)
		return;
I 4
D 9
#ifdef notdef
E 4
I 3
	if (!value(UNDOMACRO))
		canundo = 0;
I 4
#endif
E 4
E 3
#ifdef TRACE
E 9
I 9
#ifdef MDEBUG
E 9
	if (trace)
D 3
		fprintf(trace, "macpush(%s)",st);
E 3
I 3
D 4
		fprintf(trace, "macpush(%s), canundo=%d",st,canundo);
E 4
I 4
		fprintf(trace, "macpush(%s), canundo=%d\n",st,canundo);
E 4
E 3
#endif
D 3
	if (strlen(vmacp) + strlen(st) > BUFSIZ)
E 3
I 3
	if ((vmacp ? strlen(vmacp) : 0) + strlen(st) > BUFSIZ)
E 3
		error("Macro too long@ - maybe recursive?");
D 2
	if (vmacp)
E 2
I 2
	if (vmacp) {
E 2
		strcpy(tmpbuf, vmacp);
I 2
D 3
		canundo = 0;	/* can't undo inside a macro anyway */
E 3
I 3
		if (!FIXUNDO)
			canundo = 0;	/* can't undo inside a macro anyway */
E 3
	}
E 2
	strcpy(vmacbuf, st);
	if (vmacp)
		strcat(vmacbuf, tmpbuf);
	vmacp = vmacbuf;
	/* arrange to be able to undo the whole macro */
D 2
	inopen = -1;	/* no need to save since it had to be 1 or -1 before */
	otchng = tchng;
	saveall();
	vundkind = VMANY;
E 2
I 2
	if (canundo) {
I 4
#ifdef notdef
E 4
D 3
		inopen = -1;	/* no need to save since it had to be 1 or -1 before */
E 3
		otchng = tchng;
		vsave();
		saveall();
I 3
		inopen = -1;	/* no need to save since it had to be 1 or -1 before */
E 3
		vundkind = VMANY;
I 4
#endif
		vch_mac = VC_NOCHANGE;
E 4
	}
I 3
}

E 3
E 2
#ifdef TRACE
I 4
visdump(s)
D 18
char *s;
E 18
I 18
u_char *s;
E 18
{
	register int i;

	if (!trace) return;

	fprintf(trace, "\n%s: basWTOP=%d, basWLINES=%d, WTOP=%d, WBOT=%d, WLINES=%d, WCOLS=%d, WECHO=%d\n",
		s, basWTOP, basWLINES, WTOP, WBOT, WLINES, WCOLS, WECHO);
	fprintf(trace, "   vcnt=%d, vcline=%d, cursor=%d, wcursor=%d, wdot=%d\n",
		vcnt, vcline, cursor-linebuf, wcursor-linebuf, wdot-zero);
	for (i=0; i<TUBELINES; i++)
		if (vtube[i] && *vtube[i])
			fprintf(trace, "%d: '%s'\n", i, vtube[i]);
	tvliny();
}

E 4
I 3
vudump(s)
D 18
char *s;
E 18
I 18
u_char *s;
E 18
{
E 3
D 4
	if (trace)
D 3
		fprintf(trace, "saveall for macro: undkind=%d, unddel=%d, undap1=%d, undap2=%d, dol=%d, unddol=%d, truedol=%d\n", undkind, lineno(unddel), lineno(undap1), lineno(undap2), lineno(dol), lineno(unddol), lineno(truedol));
#endif
E 3
I 3
		fprintf(trace, "%s: undkind=%d, vundkind=%d, unddel=%d, undap1=%d, undap2=%d, dot=%d, dol=%d, unddol=%d, truedol=%d\n", s, undkind, vundkind, lineno(unddel), lineno(undap1), lineno(undap2), lineno(dot), lineno(dol), lineno(unddol), lineno(truedol));
E 4
I 4
	register line *p;
I 8
D 18
	char savelb[1024];
E 18
I 18
	u_char savelb[1024];
E 18
E 8

	if (!trace) return;

	fprintf(trace, "\n%s: undkind=%d, vundkind=%d, unddel=%d, undap1=%d, undap2=%d,\n",
		s, undkind, vundkind, lineno(unddel), lineno(undap1), lineno(undap2));
	fprintf(trace, "  undadot=%d, dot=%d, dol=%d, unddol=%d, truedol=%d\n",
		lineno(undadot), lineno(dot), lineno(dol), lineno(unddol), lineno(truedol));
D 8
	fprintf(trace, "  [");
	for (p=zero+1; p<=truedol; p++)
E 8
I 8
	fprintf(trace, "  [\n");
	CP(savelb, linebuf);
	fprintf(trace, "linebuf = '%s'\n", linebuf);
	for (p=zero+1; p<=truedol; p++) {
E 8
		fprintf(trace, "%o ", *p);
I 8
		getline(*p);
		fprintf(trace, "'%s'\n", linebuf);
	}
E 8
	fprintf(trace, "]\n");
I 8
	CP(linebuf, savelb);
E 8
E 4
E 3
}
I 3
#endif
E 3

/*
 * Get a count from the keyed input stream.
 * A zero count is indistinguishable from no count.
 */
vgetcnt()
{
	register int c, cnt;

	cnt = 0;
	for (;;) {
		c = getkey();
		if (!isdigit(c))
			break;
		cnt *= 10, cnt += c - '0';
	}
	ungetkey(c);
	Xhadcnt = 1;
	Xcnt = cnt;
	return(cnt);
}

/*
 * fastpeekkey is just like peekkey but insists the character come in
 * fast (within 1 second). This will succeed if it is the 2nd char of
 * a machine generated sequence (such as a function pad from an escape
 * flavor terminal) but fail for a human hitting escape then waiting.
 */
fastpeekkey()
{
	int trapalarm();
I 12
	int (*Oint)();
E 12
	register int c;

I 2
D 3
	if (inopen == -1)	/* don't work inside macros! */
		return (0);
E 2
	signal(SIGALRM, trapalarm);
	alarm(1);
E 3
I 3
	/*
	 * If the user has set notimeout, we wait forever for a key.
	 * If we are in a macro we do too, but since it's already
	 * buffered internally it will return immediately.
	 * In other cases we force this to die in 1 second.
	 * This is pretty reliable (VMUNIX rounds it to .5 - 1.5 secs,
	 * but UNIX truncates it to 0 - 1 secs) but due to system delays
	 * there are times when arrow keys or very fast typing get counted
	 * as separate.  notimeout is provided for people who dislike such
	 * nondeterminism.
	 */
I 9
#ifdef MDEBUG
	if (trace)
		fprintf(trace,"\nfastpeekkey: ",c);
#endif
I 12
	Oint = signal(SIGINT, trapalarm);
E 12
E 9
	if (value(TIMEOUT) && inopen >= 0) {
		signal(SIGALRM, trapalarm);
I 9
#ifdef MDEBUG
		alarm(10);
		if (trace)
			fprintf(trace, "set alarm ");
#else
E 9
		alarm(1);
I 9
#endif
E 9
	}
E 3
	CATCH
		c = peekkey();
#ifdef MDEBUG
	if (trace)
		fprintf(trace,"[OK]",c);
#endif
		alarm(0);
	ONERR
		c = 0;
#ifdef MDEBUG
	if (trace)
D 9
		fprintf(trace,"[TOUT]",c);
E 9
I 9
		fprintf(trace,"[TIMEOUT]",c);
E 9
#endif
	ENDCATCH
#ifdef MDEBUG
	if (trace)
		fprintf(trace,"[fpk:%o]",c);
#endif
I 12
	signal(SIGINT,Oint);
E 12
	return(c);
}

trapalarm() {
	alarm(0);
D 12
	longjmp(vreslab,1);
E 12
I 12
	if (vcatch)
		longjmp(vreslab,1);
E 12
}
E 1
