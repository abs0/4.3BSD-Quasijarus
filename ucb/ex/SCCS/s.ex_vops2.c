h59303
s 00024/00024/00885
d D 6.11 03/04/13 15:19:33 msokolov 18 17
c 8-bit ex
e
s 00010/00010/00899
d D 6.10 88/01/02 23:12:40 bostic 17 16
c fix CTRL macro for ANSI C
e
s 00027/00022/00882
d D 6.9 87/03/09 12:46:18 conrad 16 15
c make ex/vi work on vms
e
s 00001/00001/00903
d D 6.8 85/06/07 18:24:22 bloom 15 14
c fix sccsid and copyright for xstr
e
s 00010/00002/00894
d D 6.7 85/05/31 15:13:42 dist 14 12
c Add copyright
e
s 00010/00002/00873
d D 5.1.1.1 85/05/31 12:14:25 dist 13 6
c Add copyright
e
s 00003/00000/00893
d D 6.6 85/02/21 17:34:17 bloom 12 11
c support window size changes
e
s 00000/00000/00893
d D 6.5 81/07/26 20:05:18 mark 11 10
c fixes for 3b
e
s 00001/00002/00892
d D 6.4 81/07/10 23:38:12 mark 10 9
c got rid of call to FIONREAD
e
s 00007/00005/00887
d D 6.3 81/07/08 22:34:55 mark 9 8
c release 3.7 - a few bug fixes and a few new features.
e
s 00006/00001/00886
d D 6.2 80/10/23 16:18:52 mark 8 7
c fixed various bugs prior to 3.6 release
e
s 00027/00015/00860
d D 6.1 80/10/19 01:22:48 mark 7 6
c preliminary release 3.6 10/18/80
e
s 00000/00000/00875
d D 5.1 80/08/20 16:15:17 mark 6 5
c Release 3.5, August 20, 1980
e
s 00002/00001/00873
d D 4.2 80/08/01 20:43:44 mark 5 4
c Bill added more buffers, and I put in sccs.
e
s 00097/00009/00777
d D 4.1 80/08/01 00:18:45 mark 4 3
c release 3.4, June 24, 1980
e
s 00009/00005/00777
d D 3.1 80/07/31 23:43:11 mark 3 2
c release 3.3, Feb 2, 1980
e
s 00001/00001/00781
d D 2.1 80/07/31 23:21:30 mark 2 1
c release 3.2, Jan 4, 1980
e
s 00782/00000/00000
d D 1.1 80/07/31 23:00:56 mark 1 0
c date and time created 80/07/31 23:00:56 by mark
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
 * Low level routines for operations sequences,
 * and mostly, insert mode (and a subroutine
 * to read an input line, including in the echo area.)
 */
D 9
char	*vUA1, *vUA2;
char	*vUD1, *vUD2;
E 9
I 9
D 18
extern char	*vUA1, *vUA2;		/* mjm: extern; also in ex_vops.c */
extern char	*vUD1, *vUD2;		/* mjm: extern; also in ex_vops.c */
E 18
I 18
extern u_char	*vUA1, *vUA2;		/* mjm: extern; also in ex_vops.c */
extern u_char	*vUD1, *vUD2;		/* mjm: extern; also in ex_vops.c */
E 18
E 9

/*
 * Obleeperate characters in hardcopy
 * open with \'s.
 */
bleep(i, cp)
	register int i;
D 18
	char *cp;
E 18
I 18
	u_char *cp;
E 18
{

	i -= column(cp);
	do
D 16
		putchar('\\' | QUOTE);
E 16
I 16
D 18
		ex_putchar('\\' | QUOTE);
E 18
I 18
		ex_putchar('\\');
E 18
E 16
	while (--i >= 0);
	rubble = 1;
}

/*
 * Common code for middle part of delete
 * and change operating on parts of lines.
 */
vdcMID()
{
D 18
	register char *cp;
E 18
I 18
	register u_char *cp;
E 18

	squish();
	setLAST();
D 3
	vundkind = VCHNG, CP(vutmp, linebuf);
E 3
I 3
	if (FIXUNDO)
		vundkind = VCHNG, CP(vutmp, linebuf);
E 3
	if (wcursor < cursor)
		cp = wcursor, wcursor = cursor, cursor = cp;
	vUD1 = vUA1 = vUA2 = cursor; vUD2 = wcursor;
	return (column(wcursor - 1));
}

/*
 * Take text from linebuf and stick it
 * in the VBSIZE buffer BUF.  Used to save
 * deleted text of part of line.
 */
takeout(BUF)
D 18
	char *BUF;
E 18
I 18
	u_char *BUF;
E 18
{
D 18
	register char *cp;
E 18
I 18
	register u_char *cp;
E 18

	if (wcursor < linebuf)
		wcursor = linebuf;
	if (cursor == wcursor) {
		beep();
		return;
	}
	if (wcursor < cursor) {
		cp = wcursor;
		wcursor = cursor;
		cursor = cp;
	}
D 16
	setBUF(BUF);
E 16
I 16
	ex_setBUF(BUF);
E 16
D 18
	if ((BUF[0] & (QUOTE|TRIM)) == OVERBUF)
E 18
I 18
	if (BUF[0] == OVERBUF)
E 18
		beep();
}

/*
 * Are we at the end of the printed representation of the
 * line?  Used internally in hardcopy open.
 */
ateopr()
{
	register int i, c;
D 18
	register char *cp = vtube[destline] + destcol;
E 18
I 18
	register u_char *cp = vtube[destline] + destcol;
E 18

	for (i = WCOLS - destcol; i > 0; i--) {
		c = *cp++;
		if (c == 0)
			return (1);
D 18
		if (c != ' ' && (c & QUOTE) == 0)
E 18
I 18
		if (c != ' ' && !isC1(c))
E 18
			return (0);
	}
	return (1);
}

/*
 * Append.
 *
 * This routine handles the top level append, doing work
 * as each new line comes in, and arranging repeatability.
 * It also handles append with repeat counts, and calculation
 * of autoindents for new lines.
 */
bool	vaifirst;
bool	gobbled;
D 18
char	*ogcursor;
E 18
I 18
u_char	*ogcursor;
E 18

vappend(ch, cnt, indent)
D 9
	char ch;
E 9
I 9
	int ch;		/* mjm: char --> int */
E 9
	int cnt, indent;
{
	register int i;
D 18
	register char *gcursor;
E 18
I 18
	register u_char *gcursor;
E 18
	bool escape;
D 7
	int repcnt;
E 7
I 7
	int repcnt, savedoomed;
E 7
	short oldhold = hold;
I 16
#ifdef	SIGWINCH
E 16
I 12
	int oldmask;
I 16
#endif
E 16
E 12

	/*
	 * Before a move in hardopen when the line is dirty
	 * or we are in the middle of the printed representation,
	 * we retype the line to the left of the cursor so the
	 * insert looks clean.
	 */
	if (ch != 'o' && state == HARDOPEN && (rubble || !ateopr())) {
		rubble = 1;
		gcursor = cursor;
		i = *gcursor;
		*gcursor = ' ';
		wcursor = gcursor;
		vmove();
		*gcursor = i;
	}
	vaifirst = indent == 0;

	/*
	 * Handle replace character by (eventually)
	 * limiting the number of input characters allowed
	 * in the vgetline routine.
	 */
	if (ch == 'r')
		repcnt = 2;
	else
		repcnt = 0;

	/*
	 * If an autoindent is specified, then
	 * generate a mixture of blanks to tabs to implement
	 * it and place the cursor after the indent.
	 * Text read by the vgetline routine will be placed in genbuf,
	 * so the indent is generated there.
	 */
	if (value(AUTOINDENT) && indent != 0) {
		gcursor = genindent(indent);
		*gcursor = 0;
		vgotoCL(qcolumn(cursor - 1, genbuf));
	} else {
		gcursor = genbuf;
		*gcursor = 0;
		if (ch == 'o')
			vfixcurs();
	}

	/*
	 * Prepare for undo.  Pointers delimit inserted portion of line.
	 */
	vUA1 = vUA2 = cursor;

	/*
	 * If we are not in a repeated command and a ^@ comes in
	 * then this means the previous inserted text.
	 * If there is none or it was too long to be saved,
	 * then beep() and also arrange to undo any damage done
	 * so far (e.g. if we are a change.)
	 */
	if ((vglobp && *vglobp == 0) || peekbr()) {
D 18
		if ((INS[0] & (QUOTE|TRIM)) == OVERBUF) {
E 18
I 18
		if (INS[0] == OVERBUF) {
E 18
			beep();
			if (!splitw)
				ungetkey('u');
			doomed = 0;
			hold = oldhold;
			return;
		}
		/*
		 * Unread input from INS.
		 * An escape will be generated at end of string.
		 * Hold off n^^2 type update on dumb terminals.
		 */
		vglobp = INS;
		hold |= HOLDQIK;
	} else if (vglobp == 0)
		/*
		 * Not a repeated command, get
		 * a new inserted text for repeat.
		 */
		INS[0] = 0;

	/*
	 * For wrapmargin to hack away second space after a '.'
	 * when the first space caused a line break we keep
	 * track that this happened in gobblebl, which says
	 * to gobble up a blank silently.
	 */
	gobblebl = 0;

I 16
#ifdef	SIGWINCH
E 16
I 12
	oldmask = sigblock(sigmask(SIGWINCH));
I 16
#endif
E 16
E 12
	/*
	 * Text gathering loop.
	 * New text goes into genbuf starting at gcursor.
	 * cursor preserves place in linebuf where text will eventually go.
	 */
	if (*cursor == 0 || state == CRTOPEN)
		hold |= HOLDROL;
	for (;;) {
		if (ch == 'r' && repcnt == 0)
			escape = 0;
		else {
D 7
			gcursor = vgetline(repcnt, gcursor, &escape);
E 7
I 7
			gcursor = vgetline(repcnt, gcursor, &escape, ch);
E 7

			/*
			 * After an append, stick information
			 * about the ^D's and ^^D's and 0^D's in
			 * the repeated text buffer so repeated
			 * inserts of stuff indented with ^D as backtab's
			 * can work.
			 */
			if (HADUP)
				addtext("^");
			else if (HADZERO)
				addtext("0");
			while (CDCNT > 0)
				addtext("\204"), CDCNT--;
			if (gobbled)
				addtext(" ");
			addtext(ogcursor);
		}
		repcnt = 0;

		/*
		 * Smash the generated and preexisting indents together
		 * and generate one cleanly made out of tabs and spaces
		 * if we are using autoindent.
		 */
		if (!vaifirst && value(AUTOINDENT)) {
			i = fixindent(indent);
			if (!HADUP)
				indent = i;
			gcursor = strend(genbuf);
		}

		/*
		 * Limit the repetition count based on maximum
		 * possible line length; do output implied
		 * by further count (> 1) and cons up the new line
		 * in linebuf.
		 */
		cnt = vmaxrep(ch, cnt);
		CP(gcursor + 1, cursor);
		do {
			CP(cursor, genbuf);
			if (cnt > 1) {
				int oldhold = hold;

				Outchar = vinschar;
				hold |= HOLDQIK;
D 16
				printf("%s", genbuf);
E 16
I 16
				ex_printf("%s", genbuf);
E 16
				hold = oldhold;
				Outchar = vputchar;
			}
			cursor += gcursor - genbuf;
		} while (--cnt > 0);
		endim();
		vUA2 = cursor;
		if (escape != '\n')
			CP(cursor, gcursor + 1);

		/*
		 * If doomed characters remain, clobber them,
		 * and reopen the line to get the display exact.
		 */
		if (state != HARDOPEN) {
			DEPTH(vcline) = 0;
I 7
			savedoomed = doomed;
E 7
			if (doomed > 0) {
				register int cind = cindent();

				physdc(cind, cind + doomed);
				doomed = 0;
			}
			i = vreopen(LINE(vcline), lineDOT(), vcline);
I 7
D 8
			doomed = savedoomed;
E 8
I 8
#ifdef TRACE
			if (trace)
				fprintf(trace, "restoring doomed from %d to %d\n", doomed, savedoomed);
#endif
			if (ch == 'R')
				doomed = savedoomed;
E 8
E 7
		}

		/*
		 * All done unless we are continuing on to another line.
		 */
		if (escape != '\n')
			break;

		/*
		 * Set up for the new line.
		 * First save the current line, then construct a new
		 * first image for the continuation line consisting
		 * of any new autoindent plus the pushed ahead text.
		 */
		killU();
		addtext(gobblebl ? " " : "\n");
		vsave();
		cnt = 1;
		if (value(AUTOINDENT)) {
#ifdef LISPCODE
			if (value(LISP))
				indent = lindent(dot + 1);
			else
#endif
			     if (!HADUP && vaifirst)
				indent = whitecnt(linebuf);
			vaifirst = 0;
			strcLIN(vpastwh(gcursor + 1));
			gcursor = genindent(indent);
			*gcursor = 0;
			if (gcursor + strlen(linebuf) > &genbuf[LBSIZE - 2])
				gcursor = genbuf;
			CP(gcursor, linebuf);
		} else {
			CP(genbuf, gcursor + 1);
			gcursor = genbuf;
		}

		/*
		 * If we started out as a single line operation and are now
		 * turning into a multi-line change, then we had better yank
		 * out dot before it changes so that undo will work
		 * correctly later.
		 */
D 3
		if (vundkind == VCHNG) {
E 3
I 3
		if (FIXUNDO && vundkind == VCHNG) {
E 3
			vremote(1, yank, 0);
			undap1--;
		}

		/*
		 * Now do the append of the new line in the buffer,
		 * and update the display.  If slowopen
		 * we don't do very much.
		 */
		vdoappend(genbuf);
		vundkind = VMANYINS;
		vcline++;
		if (state != VISUAL)
			vshow(dot, NOLINE);
		else {
			i += LINE(vcline - 1);
			vopen(dot, i);
			if (value(SLOWOPEN))
				vscrap();
			else
				vsync1(LINE(vcline));
		}
		strcLIN(gcursor);
		*gcursor = 0;
		cursor = linebuf;
		vgotoCL(qcolumn(cursor - 1, genbuf));
	}

	/*
	 * All done with insertion, position the cursor
	 * and sync the screen.
	 */
	hold = oldhold;
	if (cursor > linebuf)
		cursor--;
	if (state != HARDOPEN)
		vsyncCL();
	else if (cursor > linebuf)
		back1();
	doomed = 0;
	wcursor = cursor;
	vmove();
I 16
#ifdef	SIGWINCH
E 16
I 12
	(void)sigsetmask(oldmask);
I 16
#endif
E 16
E 12
}

/*
 * Subroutine for vgetline to back up a single character position,
 * backwards around end of lines (vgoto can't hack columns which are
 * less than 0 in general).
 */
back1()
{

	vgoto(destline - 1, WCOLS + destcol - 1);
}

/*
 * Get a line into genbuf after gcursor.
 * Cnt limits the number of input characters
 * accepted and is used for handling the replace
 * single character command.  Aescaped is the location
 * where we stick a termination indicator (whether we
 * ended with an ESCAPE or a newline/return.
 *
 * We do erase-kill type processing here and also
 * are careful about the way we do this so that it is
 * repeatable.  (I.e. so that your kill doesn't happen,
 * when you repeat an insert if it was escaped with \ the
D 7
 * first time you did it.
E 7
I 7
 * first time you did it.  commch is the command character
 * involved, including the prompt for readline.
E 7
 */
D 18
char *
E 18
I 18
u_char *
E 18
D 7
vgetline(cnt, gcursor, aescaped)
E 7
I 7
vgetline(cnt, gcursor, aescaped, commch)
E 7
	int cnt;
D 18
	register char *gcursor;
E 18
I 18
	register u_char *gcursor;
E 18
	bool *aescaped;
I 7
D 18
	char commch;
E 18
I 18
	u_char commch;
E 18
E 7
{
	register int c, ch;
D 18
	register char *cp;
E 18
I 18
	register u_char *cp;
E 18
D 7
	int x, y, iwhite;
E 7
I 7
	int x, y, iwhite, backsl=0;
E 7
D 18
	char *iglobp;
I 4
	char cstr[2];
E 18
I 18
	u_char *iglobp;
	u_char cstr[2];
E 18
E 4
	int (*OO)() = Outchar;

	/*
	 * Clear the output state and counters
	 * for autoindent backwards motion (counts of ^D, etc.)
	 * Remember how much white space at beginning of line so
	 * as not to allow backspace over autoindent.
	 */
	*aescaped = 0;
	ogcursor = gcursor;
	flusho();
	CDCNT = 0;
	HADUP = 0;
	HADZERO = 0;
	gobbled = 0;
	iwhite = whitecnt(genbuf);
	iglobp = vglobp;

	/*
	 * Carefully avoid using vinschar in the echo area.
	 */
	if (splitw)
		Outchar = vputchar;
	else {
		Outchar = vinschar;
		vprepins();
	}
	for (;;) {
I 7
		backsl = 0;
E 7
		if (gobblebl)
			gobblebl--;
		if (cnt != 0) {
			cnt--;
			if (cnt == 0)
				goto vadone;
		}
D 4
		ch = c = getkey() & (QUOTE|TRIM);
E 4
I 4
		c = getkey();
		if (c != ATTN)
D 18
			c &= (QUOTE|TRIM);
E 18
I 18
			c &= TRIM8;
E 18
		ch = c;
		maphopcnt = 0;
E 4
D 3
		if (value(MAPINPUT))
			while ((ch = map(c, arrows)) != c)
E 3
I 3
D 7
		if (vglobp == 0 && Peekkey == 0)
E 7
I 7
D 16
		if (vglobp == 0 && Peekkey == 0 && commch != 'r')
E 16
I 16
		if (vglobp == 0 && Peek_key == 0 && commch != 'r')
E 16
E 7
			while ((ch = map(c, immacs)) != c) {
E 3
				c = ch;
I 3
				if (!value(REMAP))
					break;
I 4
				if (++maphopcnt > 256)
					error("Infinite macro loop");
E 4
			}
E 3
		if (!iglobp) {

			/*
			 * Erase-kill type processing.
			 * Only happens if we were not reading
			 * from untyped input when we started.
			 * Map users erase to ^H, kill to -1 for switch.
			 */
I 4
#ifndef USG3TTY
E 4
			if (c == tty.sg_erase)
D 17
				c = CTRL(h);
E 17
I 17
				c = CTRL('h');
E 17
			else if (c == tty.sg_kill)
				c = -1;
I 4
#else
			if (c == tty.c_cc[VERASE])
D 17
				c = CTRL(h);
E 17
I 17
				c = CTRL('h');
E 17
			else if (c == tty.c_cc[VKILL])
				c = -1;
#endif
E 4
			switch (c) {

			/*
			 * ^?		Interrupt drops you back to visual
			 *		command mode with an unread interrupt
			 *		still in the input buffer.
			 *
			 * ^\		Quit does the same as interrupt.
			 *		If you are a ex command rather than
			 *		a vi command this will drop you
			 *		back to command mode for sure.
			 */
			case ATTN:
			case QUIT:
				ungetkey(c);
				goto vadone;

			/*
			 * ^H		Backs up a character in the input.
			 *
			 * BUG:		Can't back around line boundaries.
			 *		This is hard because stuff has
			 *		already been saved for repeat.
			 */
D 17
			case CTRL(h):
E 17
I 17
			case CTRL('h'):
E 17
bakchar:
				cp = gcursor - 1;
				if (cp < ogcursor) {
					if (splitw) {
						/*
						 * Backspacing over readecho
						 * prompt. Pretend delete but
						 * don't beep.
						 */
						ungetkey(c);
						goto vadone;
					}
					beep();
					continue;
				}
				goto vbackup;

			/*
			 * ^W		Back up a white/non-white word.
			 */
D 17
			case CTRL(w):
E 17
I 17
			case CTRL('w'):
E 17
				wdkind = 1;
				for (cp = gcursor; cp > ogcursor && isspace(cp[-1]); cp--)
					continue;
				for (c = wordch(cp - 1);
				    cp > ogcursor && wordof(c, cp - 1); cp--)
					continue;
				goto vbackup;

			/*
			 * users kill	Kill input on this line, back to
			 *		the autoindent.
			 */
			case -1:
				cp = ogcursor;
vbackup:
				if (cp == gcursor) {
					beep();
					continue;
				}
				endim();
				*cp = 0;
				c = cindent();
				vgotoCL(qcolumn(cursor - 1, genbuf));
				if (doomed >= 0)
					doomed += c - cindent();
				gcursor = cp;
				continue;

			/*
			 * \		Followed by erase or kill
			 *		maps to just the erase or kill.
			 */
			case '\\':
				x = destcol, y = destline;
D 16
				putchar('\\');
E 16
I 16
				ex_putchar('\\');
E 16
				vcsync();
				c = getkey();
I 4
#ifndef USG3TTY
E 4
D 7
				if (c == tty.sg_erase || c == tty.sg_kill) {
E 7
I 7
				if (c == tty.sg_erase || c == tty.sg_kill)
E 7
I 4
#else
				if (c == tty.c_cc[VERASE]
D 7
				    || c == tty.c_cc[VKILL]) {
E 7
I 7
				    || c == tty.c_cc[VKILL])
E 7
#endif
I 7
				{
E 7
E 4
					vgoto(y, x);
					if (doomed >= 0)
						doomed++;
					goto def;
				}
				ungetkey(c), c = '\\';
D 7
				goto noput;
E 7
I 7
				backsl = 1;
				break;
E 7

			/*
			 * ^Q		Super quote following character
			 *		Only ^@ is verboten (trapped at
			 *		a lower level) and \n forces a line
			 *		split so doesn't really go in.
			 *
			 * ^V		Synonym for ^Q
			 */
D 17
			case CTRL(q):
			case CTRL(v):
E 17
I 17
			case CTRL('q'):
			case CTRL('v'):
E 17
				x = destcol, y = destline;
D 16
				putchar('^');
E 16
I 16
				ex_putchar('^');
E 16
				vgoto(y, x);
				c = getkey();
#ifdef TIOCSETC
				if (c == ATTN)
					c = nttyc.t_intrc;
#endif
				if (c != NL) {
					if (doomed >= 0)
						doomed++;
					goto def;
				}
				break;
			}
		}

		/*
		 * If we get a blank not in the echo area
		 * consider splitting the window in the wrapmargin.
		 */
D 4
		if (c == ' ' && !splitw) {
			if (gobblebl) {
E 4
I 4
		if (c != NL && !splitw) {
			if (c == ' ' && gobblebl) {
E 4
				gobbled = 1;
				continue;
			}
D 4
			if (value(WRAPMARGIN) && outcol >= OCOLUMNS - value(WRAPMARGIN)) {
				c = NL;
				gobblebl = 2;
E 4
I 4
D 7
			if (/* c <= ' ' && */ value(WRAPMARGIN) &&
				outcol >= OCOLUMNS - value(WRAPMARGIN)) {
E 7
I 7
			if (value(WRAPMARGIN) &&
				(outcol >= OCOLUMNS - value(WRAPMARGIN) ||
				 backsl && outcol==0) &&
				commch != 'r') {
E 7
				/*
				 * At end of word and hit wrapmargin.
				 * Move the word to next line and keep going.
				 */
				wdkind = 1;
				*gcursor++ = c;
I 7
				if (backsl)
					*gcursor++ = getkey();
E 7
				*gcursor = 0;
				/*
				 * Find end of previous word if we are past it.
				 */
				for (cp=gcursor; cp>ogcursor && isspace(cp[-1]); cp--)
					;
D 7
				if (outcol - (gcursor-cp) >= OCOLUMNS - value(WRAPMARGIN)) {
E 7
I 7
				if (outcol+(backsl?OCOLUMNS:0) - (gcursor-cp) >= OCOLUMNS - value(WRAPMARGIN)) {
E 7
					/*
					 * Find beginning of previous word.
					 */
					for (; cp>ogcursor && !isspace(cp[-1]); cp--)
						;
					if (cp <= ogcursor) {
						/*
						 * There is a single word that
						 * is too long to fit.  Just
						 * let it pass, but beep for
						 * each new letter to warn
						 * the luser.
						 */
						c = *--gcursor;
						*gcursor = 0;
						beep();
						goto dontbreak;
					}
					/*
					 * Save it for next line.
					 */
					macpush(cp, 0);
					cp--;
				}
				macpush("\n", 0);
				/*
				 * Erase white space before the word.
				 */
				while (cp > ogcursor && isspace(cp[-1]))
					cp--;	/* skip blank */
				gobblebl = 3;
				goto vbackup;
E 4
			}
I 4
		dontbreak:;
E 4
		}
I 4

		/*
		 * Word abbreviation mode.
		 */
		cstr[0] = c;
		if (anyabbrs && gcursor > ogcursor && !wordch(cstr) && wordch(gcursor-1)) {
D 16
				int wdtype, abno;
E 16
I 16
			int wdtype, abno;
E 16

D 16
				cstr[1] = 0;
				wdkind = 1;
				cp = gcursor - 1;
				for (wdtype = wordch(cp - 1);
				    cp > ogcursor && wordof(wdtype, cp - 1); cp--)
					;
				*gcursor = 0;
				for (abno=0; abbrevs[abno].mapto; abno++) {
					if (eq(cp, abbrevs[abno].cap)) {
						macpush(cstr, 0);
						macpush(abbrevs[abno].mapto);
						goto vbackup;
					}
E 16
I 16
			cstr[1] = 0;
			wdkind = 1;
			cp = gcursor - 1;
			for (wdtype = wordch(cp - 1);
			    cp > ogcursor && wordof(wdtype, cp - 1); cp--)
				;
			*gcursor = 0;
			for (abno=0; abbrevs[abno].mapto; abno++) {
				if (eq(cp, abbrevs[abno].cap)) {
					macpush(cstr, 0);
					macpush(abbrevs[abno].mapto, 1);
					goto vbackup;
E 16
				}
I 16
			}
E 16
		}

E 4
		switch (c) {

		/*
		 * ^M		Except in repeat maps to \n.
		 */
		case CR:
			if (vglobp)
				goto def;
			c = '\n';
			/* presto chango ... */

		/*
		 * \n		Start new line.
		 */
		case NL:
			*aescaped = c;
			goto vadone;

		/*
		 * escape	End insert unless repeat and more to repeat.
		 */
		case ESCAPE:
			if (lastvgk)
				goto def;
			goto vadone;

		/*
		 * ^D		Backtab.
		 * ^T		Software forward tab.
		 *
		 *		Unless in repeat where this means these
		 *		were superquoted in.
		 */
D 17
		case CTRL(d):
		case CTRL(t):
E 17
I 17
		case CTRL('d'):
		case CTRL('t'):
E 17
			if (vglobp)
				goto def;
			/* fall into ... */

		/*
		 * ^D|QUOTE	Is a backtab (in a repeated command).
		 */
D 17
		case CTRL(d) | QUOTE:
E 17
I 17
		case CTRL('d') | QUOTE:
E 17
			*gcursor = 0;
			cp = vpastwh(genbuf);
			c = whitecnt(genbuf);
D 17
			if (ch == CTRL(t)) {
E 17
I 17
			if (ch == CTRL('t')) {
E 17
				/*
				 * ^t just generates new indent replacing
				 * current white space rounded up to soft
				 * tab stop increment.
				 */
				if (cp != gcursor)
					/*
					 * BUG:		Don't hack ^T except
					 *		right after initial
					 *		white space.
					 */
					continue;
				cp = genindent(iwhite = backtab(c + value(SHIFTWIDTH) + 1));
				ogcursor = cp;
				goto vbackup;
			}
			/*
			 * ^D works only if we are at the (end of) the
			 * generated autoindent.  We count the ^D for repeat
			 * purposes.
			 */
			if (c == iwhite && c != 0)
				if (cp == gcursor) {
					iwhite = backtab(c);
					CDCNT++;
					ogcursor = cp = genindent(iwhite);
					goto vbackup;
				} else if (&cp[1] == gcursor &&
				    (*cp == '^' || *cp == '0')) {
					/*
					 * ^^D moves to margin, then back
					 * to current indent on next line.
					 *
					 * 0^D moves to margin and then
					 * stays there.
					 */
					HADZERO = *cp == '0';
					ogcursor = cp = genbuf;
					HADUP = 1 - HADZERO;
					CDCNT = 1;
					endim();
					back1();
D 3
					vputc(' ');
E 3
I 3
					vputchar(' ');
E 3
					goto vbackup;
				}
			if (vglobp && vglobp - iglobp >= 2 &&
			    (vglobp[-2] == '^' || vglobp[-2] == '0')
			    && gcursor == ogcursor + 1)
				goto bakchar;
			continue;

		default:
			/*
			 * Possibly discard control inputs.
			 */
			if (!vglobp && junk(c)) {
				beep();
				continue;
			}
def:
D 7
			putchar(c);
I 4
			flush();
E 4
noput:
E 7
I 7
			if (!backsl) {
I 9
D 16
				int cnt;
E 9
				putchar(c);
E 16
I 16
				ex_putchar(c);
E 16
D 9
				flush();
E 9
I 9
D 10
				if (ioctl(0, FIONREAD, &cnt) != 0 || cnt==0)
					flush();
E 10
I 10
				flush();
E 10
E 9
			}
E 7
			if (gcursor > &genbuf[LBSIZE - 2])
				error("Line too long");
D 18
			*gcursor++ = c & TRIM;
E 18
I 18
			*gcursor++ = c;
E 18
			vcsync();
D 4
#ifdef LISPCODE
E 4
			if (value(SHOWMATCH) && !iglobp)
				if (c == ')' || c == '}')
					lsmatch(gcursor);
D 4
#endif
E 4
			continue;
		}
	}
vadone:
	*gcursor = 0;
D 4
	Outchar = OO;
E 4
I 4
	if (Outchar != termchar)
		Outchar = OO;
E 4
	endim();
	return (gcursor);
}

int	vgetsplit();
D 18
char	*vsplitpt;
E 18
I 18
u_char	*vsplitpt;
E 18

/*
 * Append the line in buffer at lp
 * to the buffer after dot.
 */
vdoappend(lp)
D 18
	char *lp;
E 18
I 18
	u_char *lp;
E 18
{
	register int oing = inglobal;

	vsplitpt = lp;
	inglobal = 1;
	ignore(append(vgetsplit, dot));
	inglobal = oing;
}

/*
 * Subroutine for vdoappend to pass to append.
 */
vgetsplit()
{

	if (vsplitpt == 0)
		return (EOF);
	strcLIN(vsplitpt);
	vsplitpt = 0;
	return (0);
}

/*
 * Vmaxrep determines the maximum repetitition factor
 * allowed that will yield total line length less than
D 2
 * 512 characters and also does hacks for the R command.
E 2
I 2
 * LBSIZE characters and also does hacks for the R command.
E 2
 */
vmaxrep(ch, cnt)
D 18
	char ch;
E 18
I 18
	u_char ch;
E 18
	register int cnt;
{
	register int len, replen;

	if (cnt > LBSIZE - 2)
		cnt = LBSIZE - 2;
	replen = strlen(genbuf);
	if (ch == 'R') {
		len = strlen(cursor);
		if (replen < len)
			len = replen;
		CP(cursor, cursor + len);
		vUD2 += len;
	}
	len = strlen(linebuf);
	if (len + cnt * replen <= LBSIZE - 2)
		return (cnt);
	cnt = (LBSIZE - 2 - len) / replen;
	if (cnt == 0) {
		vsave();
		error("Line too long");
	}
	return (cnt);
}
E 1
