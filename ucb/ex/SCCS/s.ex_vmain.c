h49994
s 00008/00008/01292
d D 7.10 03/04/13 15:19:26 msokolov 22 21
c 8-bit ex
e
s 00013/00013/01287
d D 7.9 88/01/02 23:12:34 bostic 21 20
c fix CTRL macro for ANSI C
e
s 00013/00013/01287
d D 7.8 87/03/09 12:46:14 conrad 20 19
c make ex/vi work on vms
e
s 00001/00001/01299
d D 7.7 85/06/07 18:22:33 bloom 19 18
c fix sccsid and copyright for xstr
e
s 00010/00002/01290
d D 7.6 85/05/31 14:02:42 dist 18 16
c Add copyright
e
s 00010/00002/01266
d D 5.3.1.1 85/05/31 12:12:36 dist 17 9
c Add copyright
e
s 00001/00001/01291
d D 7.5 85/03/19 19:13:34 mckusick 16 15
c fix for ^B from sun!shannon
e
s 00005/00001/01287
d D 7.4 84/04/10 22:12:37 peter 15 14
c if lisp is set allow `-'s in tagged words (since this is the style);
c and in general allow reasonably long tags.
e
s 00001/00001/01287
d D 7.3 83/06/10 10:07:56 ralph 14 13
c updating sccs files due to restoring an older SCCS directory
e
s 00001/00001/01287
d D 7.2 81/10/31 14:50:11 mark 13 12
c fixed C/70 bug with peekc being saved in a char
e
s 00002/00002/01286
d D 7.1 81/07/08 22:33:29 mark 12 11
c release 3.7 - a few bug fixes and a few new features.
e
s 00012/00000/01276
d D 6.2 80/10/23 16:15:18 mark 11 10
c fixed various bugs prior to 3.6 release
e
s 00013/00005/01263
d D 6.1 80/10/19 01:22:15 mark 10 9
c preliminary release 3.6 10/18/80
e
s 00001/00001/01267
d D 5.3 80/09/12 08:32:12 mark 9 8
c separated TIOCLGET and SIGTSTP since Cory only has the former
e
s 00002/00004/01266
d D 5.2 80/08/28 20:26:07 mark 8 7
c Release 3.5, 8/28/80, previous "release" not released
c fixed rewind, deleted misfeature where arguments to :, ^^,
c ]], [[, ``, '', /, and ? reset the window size.
e
s 00000/00000/01270
d D 5.1 80/08/20 16:13:58 mark 7 6
c Release 3.5, August 20, 1980
e
s 00002/00013/01268
d D 4.3 80/08/20 02:21:19 mark 6 5
c took out 't misfeature on ^^ when Bill agreed.
e
s 00002/00001/01279
d D 4.2 80/08/01 20:42:54 mark 5 4
c Bill added more buffers, and I put in sccs.
e
s 00046/00008/01234
d D 4.1 80/08/01 00:17:40 mark 4 3
c release 3.4, June 24, 1980
e
s 00072/00026/01170
d D 3.1 80/07/31 23:41:33 mark 3 2
c release 3.3, Feb 2, 1980
e
s 00006/00001/01190
d D 2.1 80/07/31 23:20:45 mark 2 1
c release 3.2, Jan 4, 1980
e
s 01191/00000/00000
d D 1.1 80/07/31 23:00:46 mark 1 0
c date and time created 80/07/31 23:00:46 by mark
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
D 12
D 17
/* Copyright (c) 1980 Regents of the University of California */
static char *sccsid = "%W% %G%";
E 17
I 17
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 17
E 12
I 12
D 18
/* Copyright (c) 1981 Regents of the University of California */
static char *sccsid = "%W%	%G%";
E 18
I 18
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
D 19
static char sccsid[] = "%W% (Berkeley) %G%";
E 19
I 19
static char *sccsid = "%W% (Berkeley) %G%";
E 19
#endif not lint

E 18
E 12
E 5
#include "ex.h"
#include "ex_tty.h"
#include "ex_vis.h"

/*
 * This is the main routine for visual.
 * We here decode the count and possible named buffer specification
 * preceding a command and interpret a few of the commands.
 * Commands which involve a target (i.e. an operator) are decoded
 * in the routine operate in ex_voperate.c.
 */

#define	forbid(a)	{ if (a) goto fonfon; }

vmain()
{
	register int c, cnt, i;
D 22
	char esave[TUBECOLS];
	char *oglobp;
E 22
I 22
	u_char esave[TUBECOLS];
	u_char *oglobp;
E 22
D 13
	char d;
E 13
I 13
	short d;
E 13
	line *addr;
D 3
	int ind;
E 3
I 3
	int ind, nlput;
	int shouldpo = 0;
E 3
	int onumber, olist, (*OPline)(), (*OPutchar)();

I 4
	vch_mac = VC_NOTINMAC;

E 4
	/*
	 * If we started as a vi command (on the command line)
	 * then go process initial commands (recover, next or tag).
	 */
	if (initev) {
		oglobp = globp;
		globp = initev;
		hadcnt = cnt = 0;
		i = tchng;
		addr = dot;
		goto doinit;
	}

	/*
	 * NB:
	 *
	 * The current line is always in the line buffer linebuf,
	 * and the cursor at the position cursor.  You should do
	 * a vsave() before moving off the line to make sure the disk
	 * copy is updated if it has changed, and a getDOT() to get
	 * the line back if you mung linebuf.  The motion
	 * routines in ex_vwind.c handle most of this.
	 */
	for (;;) {
		/*
		 * Decode a visual command.
		 * First sync the temp file if there has been a reasonable
		 * amount of change.  Clear state for decoding of next
		 * command.
		 */
		TSYNC();
		vglobp = 0;
		vreg = 0;
		hold = 0;
I 10
		seenprompt = 1;
E 10
		wcursor = 0;
		Xhadcnt = hadcnt = 0;
		Xcnt = cnt = 1;
		splitw = 0;
		if (i = holdupd) {
			if (state == VISUAL)
				ignore(peekkey());
			holdupd = 0;
/*
D 20
			if (LINE(0) < ZERO) {
E 20
I 20
			if (LINE(0) < ex_ZERO) {
E 20
				vclear();
				vcnt = 0;
				i = 3;
			}
*/
			if (state != VISUAL) {
				vcnt = 0;
				vsave();
				vrepaint(cursor);
			} else if (i == 3)
				vredraw(WTOP);
			else
				vsync(WTOP);
			vfixcurs();
		}

		/*
		 * Gobble up counts and named buffer specifications.
		 */
		for (;;) {
looptop:
#ifdef MDEBUG
			if (trace)
				fprintf(trace, "pc=%c",peekkey());
#endif
			if (isdigit(peekkey()) && peekkey() != '0') {
				hadcnt = 1;
				cnt = vgetcnt();
				forbid (cnt <= 0);
			}
			if (peekkey() != '"')
				break;
			ignore(getkey()), c = getkey();
			/*
			 * Buffer names be letters or digits.
			 * But not '0' as that is the source of
			 * an 'empty' named buffer spec in the routine
			 * kshift (see ex_temp.c).
			 */
			forbid (c == '0' || !isalpha(c) && !isdigit(c));
			vreg = c;
		}
reread:
		/*
		 * Come to reread from below after some macro expansions.
		 * The call to map allows use of function key pads
		 * by performing a terminal dependent mapping of inputs.
		 */
#ifdef MDEBUG
		if (trace)
			fprintf(trace,"pcb=%c,",peekkey());
#endif
		op = getkey();
I 4
		maphopcnt = 0;
E 4
		do {
			/*
			 * Keep mapping the char as long as it changes.
			 * This allows for double mappings, e.g., q to #,
			 * #1 to something else.
			 */
			c = op;
			op = map(c,arrows);
#ifdef MDEBUG
			if (trace)
				fprintf(trace,"pca=%c,",c);
#endif
			/*
			 * Maybe the mapped to char is a count. If so, we have
			 * to go back to the "for" to interpret it. Likewise
			 * for a buffer name.
			 */
			if ((isdigit(c) && c!='0') || c == '"') {
				ungetkey(c);
				goto looptop;
			}
I 3
D 10
			if (!value(REMAP))
E 10
I 10
			if (!value(REMAP)) {
				c = op;
E 10
				break;
I 10
			}
E 10
I 4
			if (++maphopcnt > 256)
				error("Infinite macro loop");
E 4
E 3
		} while (c != op);

		/*
		 * Begin to build an image of this command for possible
		 * later repeat in the buffer workcmd.  It will be copied
		 * to lastcmd by the routine setLAST
		 * if/when completely specified.
		 */
		lastcp = workcmd;
		if (!vglobp)
			*lastcp++ = c;

		/*
		 * First level command decode.
		 */
		switch (c) {

		/*
		 * ^L		Clear screen e.g. after transmission error.
		 */
D 3
		case CTRL(l):
			vclear();
			vdirty(0, vcnt);
			/* fall into... */
E 3

		/*
		 * ^R		Retype screen, getting rid of @ lines.
		 *		If in open, equivalent to ^L.
I 3
		 *		On terminals where the right arrow key sends
		 *		^L we make ^R act like ^L, since there is no
		 *		way to get ^L.  These terminals (adm31, tvi)
		 *		are intelligent so ^R is useless.  Soroc
		 *		will probably foul this up, but nobody has
		 *		one of them.
E 3
		 */
I 3
D 21
		case CTRL(l):
E 3
		case CTRL(r):
I 3
			if (c == CTRL(l) || (KR && *KR==CTRL(l))) {
E 21
I 21
		case CTRL('l'):
		case CTRL('r'):
			if (c == CTRL('l') || (KR && *KR==CTRL('l'))) {
E 21
				vclear();
				vdirty(0, vcnt);
			}
E 3
			if (state != VISUAL) {
				/*
				 * Get a clean line, throw away the
				 * memory of what is displayed now,
				 * and move back onto the current line.
				 */
				vclean();
				vcnt = 0;
				vmoveto(dot, cursor, 0);
				continue;
			}
			vredraw(WTOP);
			/*
			 * Weird glitch -- when we enter visual
			 * in a very small window we may end up with
			 * no lines on the screen because the line
			 * at the top is too long.  This forces the screen
			 * to be expanded to make room for it (after
			 * we have printed @'s ick showing we goofed).
			 */
			if (vcnt == 0)
				vrepaint(cursor);
			vfixcurs();
			continue;

		/*
		 * $		Escape just cancels the current command
		 *		with a little feedback.
		 */
		case ESCAPE:
			beep();
			continue;

		/*
		 * @   		Macros. Bring in the macro and put it
		 *		in vmacbuf, point vglobp there and punt.
		 */
		 case '@':
D 3
			c = getkey();
E 3
I 3
			c = getesc();
			if (c == 0)
				continue;
E 3
			if (c == '@')
				c = lastmac;
			if (isupper(c))
				c = tolower(c);
			forbid(!islower(c));
			lastmac = c;
			vsave();
			CATCH
D 22
				char tmpbuf[BUFSIZ];
E 22
I 22
				u_char tmpbuf[BUFSIZ];
E 22

				regbuf(c,tmpbuf,sizeof(vmacbuf));
D 3
				macpush(tmpbuf);
E 3
I 3
				macpush(tmpbuf, 1);
E 3
			ONERR
				lastmac = 0;
				splitw = 0;
				getDOT();
				vrepaint(cursor);
				continue;
			ENDCATCH
			vmacp = vmacbuf;
			goto reread;

		/*
		 * .		Repeat the last (modifying) open/visual command.
		 */
		case '.':
			/*
			 * Check that there was a last command, and
			 * take its count and named buffer unless they
			 * were given anew.  Special case if last command
			 * referenced a numeric named buffer -- increment
			 * the number and go to a named buffer again.
			 * This allows a sequence like "1pu.u.u...
			 * to successively look for stuff in the kill chain
			 * much as one does in EMACS with C-Y and M-Y.
			 */
			forbid (lastcmd[0] == 0);
			if (hadcnt)
				lastcnt = cnt;
			if (vreg)
				lastreg = vreg;
			else if (isdigit(lastreg) && lastreg < '9')
				lastreg++;
			vreg = lastreg;
			cnt = lastcnt;
			hadcnt = lasthad;
			vglobp = lastcmd;
			goto reread;

		/*
		 * ^U		Scroll up.  A count sticks around for
		 *		future scrolls as the scroll amount.
		 *		Attempt to hold the indentation from the
		 *		top of the screen (in logical lines).
		 *
		 * BUG:		A ^U near the bottom of the screen
		 *		on a dumb terminal (which can't roll back)
		 *		causes the screen to be cleared and then
		 *		redrawn almost as it was.  In this case
		 *		one should simply move the cursor.
		 */
D 21
		case CTRL(u):
E 21
I 21
		case CTRL('u'):
E 21
			if (hadcnt)
D 20
				vSCROLL = cnt;
			cnt = vSCROLL;
E 20
I 20
				ex_vSCROLL = cnt;
			cnt = ex_vSCROLL;
E 20
			if (state == VISUAL)
				ind = vcline, cnt += ind;
			else
				ind = 0;
			vmoving = 0;
			vup(cnt, ind, 1);
			vnline(NOSTR);
			continue;

		/*
		 * ^D		Scroll down.  Like scroll up.
		 */
D 21
		case CTRL(d):
E 21
I 21
		case CTRL('d'):
E 21
I 11
#ifdef TRACE
		if (trace)
			fprintf(trace, "before vdown in ^D, dot=%d, wdot=%d, dol=%d\n", lineno(dot), lineno(wdot), lineno(dol));
#endif
E 11
			if (hadcnt)
D 20
				vSCROLL = cnt;
			cnt = vSCROLL;
E 20
I 20
				ex_vSCROLL = cnt;
			cnt = ex_vSCROLL;
E 20
			if (state == VISUAL)
				ind = vcnt - vcline - 1, cnt += ind;
			else
				ind = 0;
			vmoving = 0;
			vdown(cnt, ind, 1);
I 11
#ifdef TRACE
		if (trace)
			fprintf(trace, "before vnline in ^D, dot=%d, wdot=%d, dol=%d\n", lineno(dot), lineno(wdot), lineno(dol));
#endif
E 11
			vnline(NOSTR);
I 11
#ifdef TRACE
		if (trace)
			fprintf(trace, "after vnline in ^D, dot=%d, wdot=%d, dol=%d\n", lineno(dot), lineno(wdot), lineno(dol));
#endif
E 11
			continue;

		/*
		 * ^E		Glitch the screen down (one) line.
		 *		Cursor left on same line in file.
		 */
D 21
		case CTRL(e):
E 21
I 21
		case CTRL('e'):
E 21
			if (state != VISUAL)
				continue;
			if (!hadcnt)
				cnt = 1;
			/* Bottom line of file already on screen */
			forbid(lineDOL()-lineDOT() <= vcnt-1-vcline);
			ind = vcnt - vcline - 1 + cnt;
			vdown(ind, ind, 1);
			vnline(cursor);
			continue;

		/*
		 * ^Y		Like ^E but up
		 */
D 21
		case CTRL(y):
E 21
I 21
		case CTRL('y'):
E 21
			if (state != VISUAL)
				continue;
			if (!hadcnt)
				cnt = 1;
			forbid(lineDOT()-1<=vcline); /* line 1 already there */
			ind = vcline + cnt;
			vup(ind, ind, 1);
			vnline(cursor);
			continue;


		/*
		 * m		Mark position in mark register given
		 *		by following letter.  Return is
		 *		accomplished via ' or `; former
		 *		to beginning of line where mark
		 *		was set, latter to column where marked.
		 */
		case 'm':
			/*
			 * Getesc is generally used when a character
			 * is read as a latter part of a command
			 * to allow one to hit rubout/escape to cancel
			 * what you have typed so far.  These characters
			 * are mapped to 0 by the subroutine.
			 */
			c = getesc();
			if (c == 0)
				continue;

			/*
			 * Markreg checks that argument is a letter
			 * and also maps ' and ` to the end of the range
			 * to allow '' or `` to reference the previous
			 * context mark.
			 */
			c = markreg(c);
			forbid (c == 0);
			vsave();
			names[c - 'a'] = (*dot &~ 01);
			ncols[c - 'a'] = cursor;
			anymarks = 1;
			continue;

		/*
		 * ^F		Window forwards, with 2 lines of continuity.
D 4
		 *		Count gives new screen size.
E 4
I 4
		 *		Count repeats.
E 4
		 */
D 21
		case CTRL(f):
E 21
I 21
		case CTRL('f'):
E 21
			vsave();
D 4
			if (hadcnt)
				vsetsiz(cnt);
E 4
			if (vcnt > 2) {
D 4
				dot += (vcnt - vcline) - 2;
E 4
I 4
D 10
				dot += (vcnt - vcline) - 2 + (cnt-1)*basWLINES;
E 10
I 10
				addr = dot + (vcnt - vcline) - 2 + (cnt-1)*basWLINES;
				forbid(addr > dol);
				dot = addr;
E 10
E 4
				vcnt = vcline = 0;
			}
			vzop(0, 0, '+');
			continue;

		/*
		 * ^B		Window backwards, with 2 lines of continuity.
		 *		Inverse of ^F.
		 */
D 21
		case CTRL(b):
E 21
I 21
		case CTRL('b'):
E 21
			vsave();
D 4
			if (hadcnt)
				vsetsiz(cnt);
E 4
			if (one + vcline != dot && vcnt > 2) {
D 4
				dot -= vcline - 2;
E 4
I 4
D 10
				dot -= vcline - 2 + (cnt-1)*basWLINES;
E 10
I 10
D 14
				addr = dot - vcline - 2 + (cnt-1)*basWLINES;
E 14
I 14
D 16
				addr = dot - vcline + 2 + (cnt-1)*basWLINES;
E 16
I 16
				addr = dot - vcline + 2 - (cnt-1)*basWLINES;
E 16
E 14
				forbid (addr <= zero);
				dot = addr;
E 10
E 4
				vcnt = vcline = 0;
			}
			vzop(0, 0, '^');
			continue;

		/*
		 * z		Screen adjustment, taking a following character:
		 *			z<CR>		current line to top
		 *			z<NL>		like z<CR>
		 *			z-		current line to bottom
		 *		also z+, z^ like ^F and ^B.
		 *		A preceding count is line to use rather
		 *		than current line.  A count between z and
		 *		specifier character changes the screen size
		 *		for the redraw.
		 *
		 */
		case 'z':
			if (state == VISUAL) {
				i = vgetcnt();
				if (i > 0)
					vsetsiz(i);
				c = getesc();
				if (c == 0)
					continue;
			}
			vsave();
			vzop(hadcnt, cnt, c);
			continue;

		/*
		 * Y		Yank lines, abbreviation for y_ or yy.
		 *		Yanked lines can be put later if no
		 *		changes intervene, or can be put in named
		 *		buffers and put anytime in this session.
		 */
		case 'Y':
			ungetkey('_');
			c = 'y';
			break;

		/*
		 * J		Join lines, 2 by default.  Count is number
		 *		of lines to join (no join operator sorry.)
		 */
		case 'J':
			forbid (dot == dol);
			if (cnt == 1)
				cnt = 2;
			if (cnt > (i = dol - dot + 1))
				cnt = i;
			vsave();
I 4
			vmacchng(1);
E 4
			setLAST();
			cursor = strend(linebuf);
			vremote(cnt, join, 0);
			notenam = "join";
			vmoving = 0;
			killU();
			vreplace(vcline, cnt, 1);
			if (!*cursor && cursor > linebuf)
				cursor--;
			if (notecnt == 2)
				notecnt = 0;
			vrepaint(cursor);
			continue;

		/*
		 * S		Substitute text for whole lines, abbrev for c_.
		 *		Count is number of lines to change.
		 */
		case 'S':
			ungetkey('_');
			c = 'c';
			break;

		/*
		 * O		Create a new line above current and accept new
		 *		input text, to an escape, there.
		 *		A count specifies, for dumb terminals when
		 *		slowopen is not set, the number of physical
		 *		line space to open on the screen.
		 *
		 * o		Like O, but opens lines below.
		 */
		case 'O':
		case 'o':
D 10
			voOpen(c, cnt);
E 10
I 4
			vmacchng(1);
I 10
			voOpen(c, cnt);
E 10
E 4
			continue;

		/*
		 * C		Change text to end of line, short for c$.
		 */
		case 'C':
			if (*cursor) {
				ungetkey('$'), c = 'c';
				break;
			}
			goto appnd;

		/*
		 * ~	Switch case of letter under cursor
		 */
		case '~':
			{
D 22
				char mbuf[4];
E 22
I 22
				u_char mbuf[4];
E 22
I 4
				setLAST();
E 4
				mbuf[0] = 'r';
				mbuf[1] = *cursor;
				mbuf[2] = cursor[1]==0 ? 0 : ' ';
				mbuf[3] = 0;
				if (isalpha(mbuf[1]))
					mbuf[1] ^= ' ';	/* toggle the case */
D 3
				macpush(mbuf);
E 3
I 3
				macpush(mbuf, 1);
E 3
			}
			continue;


		/*
		 * A		Append at end of line, short for $a.
		 */
		case 'A':
			operate('$', 1);
appnd:
			c = 'a';
			/* fall into ... */

		/*
		 * a		Appends text after cursor.  Text can continue
		 *		through arbitrary number of lines.
		 */
		case 'a':
			if (*cursor) {
				if (state == HARDOPEN)
D 20
					putchar(*cursor);
E 20
I 20
					ex_putchar(*cursor);
E 20
				cursor++;
			}
			goto insrt;

		/*
		 * I		Insert at beginning of whitespace of line,
		 *		short for ^i.
		 */
		case 'I':
			operate('^', 1);
			c = 'i';
			/* fall into ... */

		/*
		 * R		Replace characters, one for one, by input
		 *		(logically), like repeated r commands.
		 *
		 * BUG:		This is like the typeover mode of many other
		 *		editors, and is only rarely useful.  Its
		 *		implementation is a hack in a low level
		 *		routine and it doesn't work very well, e.g.
		 *		you can't move around within a R, etc.
		 */
		case 'R':
			/* fall into... */

		/*
		 * i		Insert text to an escape in the buffer.
		 *		Text is arbitrary.  This command reminds of
		 *		the i command in bare teco.
		 */
		case 'i':
insrt:
			/*
			 * Common code for all the insertion commands.
			 * Save for redo, position cursor, prepare for append
			 * at command and in visual undo.  Note that nothing
			 * is doomed, unless R when all is, and save the
			 * current line in a the undo temporary buffer.
			 */
I 4
			vmacchng(1);
E 4
			setLAST();
			vcursat(cursor);
			prepapp();
			vnoapp();
			doomed = c == 'R' ? 10000 : 0;
D 3
			vundkind = VCHNG;
E 3
I 3
			if(FIXUNDO)
				vundkind = VCHNG;
			vmoving = 0;
E 3
			CP(vutmp, linebuf);

			/*
			 * If this is a repeated command, then suppress
			 * fake insert mode on dumb terminals which looks
			 * ridiculous and wastes lots of time even at 9600B.
			 */
			if (vglobp)
				hold = HOLDQIK;
			vappend(c, cnt, 0);
			continue;

		/*
		 * ^?		An attention, normally a ^?, just beeps.
		 *		If you are a vi command within ex, then
		 *		two ATTN's will drop you back to command mode.
		 */
		case ATTN:
			beep();
			if (initev || peekkey() != ATTN)
				continue;
			/* fall into... */

		/*
		 * ^\		A quit always gets command mode.
		 */
		case QUIT:
			/*
			 * Have to be careful if we were called
			 *	g/xxx/vi
			 * since a return will just start up again.
			 * So we simulate an interrupt.
			 */
			if (inglobal)
				onintr();
			/* fall into... */

I 3
#ifdef notdef
E 3
		/*
		 * q		Quit back to command mode, unless called as
		 *		vi on command line in which case dont do it
		 */
		case 'q':	/* quit */
			if (initev) {
				vsave();
				CATCH
					error("Q gets ex command mode, :q leaves vi");
				ENDCATCH
				splitw = 0;
				getDOT();
				vrepaint(cursor);
				continue;
			}
I 3
#endif
E 3
			/* fall into... */

		/*
		 * Q		Is like q, but always gets to command mode
		 *		even if command line invocation was as vi.
		 */
		case 'Q':
			vsave();
I 4
			/*
			 * If we are in the middle of a macro, throw away
			 * the rest and fix up undo.
			 * This code copied from getbr().
			 */
			if (vmacp) {
				vmacp = 0;
				if (inopen == -1)	/* don't screw up undo for esc esc */
					vundkind = VMANY;
				inopen = 1;	/* restore old setting now that macro done */
			}
E 4
			return;

I 3

E 3
		/*
I 3
		 * ZZ		Like :x
		 */
		 case 'Z':
			forbid(getkey() != 'Z');
			oglobp = globp;
			globp = "x";
			vclrech(0);
			goto gogo;
			
		/*
E 3
		 * P		Put back text before cursor or before current
		 *		line.  If text was whole lines goes back
		 *		as whole lines.  If part of a single line
		 *		or parts of whole lines splits up current
		 *		line to form many new lines.
		 *		May specify a named buffer, or the delete
		 *		saving buffers 1-9.
		 *
		 * p		Like P but after rather than before.
		 */
		case 'P':
		case 'p':
			vmoving = 0;
I 4
#ifdef notdef
E 4
I 2
D 3
			forbid (inopen < 0);
E 3
I 3
			forbid (!vreg && value(UNDOMACRO) && inopen < 0);
I 4
#endif
E 4
E 3
E 2
			/*
			 * If previous delete was partial line, use an
			 * append or insert to put it back so as to
			 * use insert mode on intelligent terminals.
			 */
			if (!vreg && DEL[0]) {
D 22
				forbid ((DEL[0] & (QUOTE|TRIM)) == OVERBUF);
E 22
I 22
				forbid (DEL[0] == OVERBUF);
E 22
				vglobp = DEL;
				ungetkey(c == 'p' ? 'a' : 'i');
				goto reread;
			}

			/*
			 * If a register wasn't specified, then make
			 * sure there is something to put back.
			 */
			forbid (!vreg && unddol == dol);
I 4
			/*
			 * If we just did a macro the whole buffer is in
			 * the undo save area.  We don't want to put THAT.
			 */
			forbid (vundkind == VMANY && undkind==UNDALL);
E 4
			vsave();
I 4
			vmacchng(1);
E 4
			setLAST();
			i = 0;
			if (vreg && partreg(vreg) || !vreg && pkill[0]) {
				/*
				 * Restoring multiple lines which were partial
				 * lines; will leave cursor in middle
				 * of line after shoving restored text in to
				 * split the current line.
				 */
				i++;
				if (c == 'p' && *cursor)
					cursor++;
			} else {
				/*
				 * In whole line case, have to back up dot
				 * for P; also want to clear cursor so
				 * cursor will eventually be positioned
				 * at the beginning of the first put line.
				 */
				cursor = 0;
				if (c == 'P') {
					dot--, vcline--;
					c = 'p';
				}
			}
			killU();

			/*
			 * The call to putreg can potentially
			 * bomb since there may be nothing in a named buffer.
			 * We thus put a catch in here.  If we didn't and
			 * there was an error we would end up in command mode.
			 */
I 3
			addr = dol;	/* old dol */
E 3
			CATCH
				vremote(1, vreg ? putreg : put, vreg);
			ONERR
				if (vreg == -1) {
					splitw = 0;
					if (op == 'P')
						dot++, vcline++;
					goto pfixup;
				}
			ENDCATCH
			splitw = 0;
I 3
			nlput = dol - addr + 1;
E 3
			if (!i) {
				/*
				 * Increment undap1, undap2 to make up
				 * for their incorrect initialization in the
				 * routine vremote before calling put/putreg.
				 */
D 3
				undap1++, undap2++;
E 3
I 3
				if (FIXUNDO)
					undap1++, undap2++;
E 3
				vcline++;
D 3
			}
E 3
I 3
				nlput--;
E 3

D 3
			/*
			 * After a put want current line first line,
			 * and dot was made the last line put in code run
			 * so far.  This is why we increment vcline above,
			 * and decrease (usually) dot here.
			 */
			dot = undap1;
			vreplace(vcline, i, undap2 - undap1);
E 3
I 3
				/*
				 * After a put want current line first line,
				 * and dot was made the last line put in code
				 * run so far.  This is why we increment vcline
				 * above and decrease dot here.
				 */
				dot -= nlput - 1;
			}
#ifdef TRACE
			if (trace)
				fprintf(trace, "vreplace(%d, %d, %d), undap1=%d, undap2=%d, dot=%d\n", vcline, i, nlput, lineno(undap1), lineno(undap2), lineno(dot));
#endif
			vreplace(vcline, i, nlput);
E 3
			if (state != VISUAL) {
				/*
				 * Special case in open mode.
				 * Force action on the screen when a single
				 * line is put even if it is identical to
				 * the current line, e.g. on YP; otherwise
				 * you can't tell anything happened.
				 */
				vjumpto(dot, cursor, '.');
				continue;
			}
pfixup:
			vrepaint(cursor);
			vfixcurs();
			continue;

		/*
D 6
		 * ^^		Return to previous context.  Like a 't
		 *		if that mark is set since tag sets that
		 *		mark if it stays in same file.  Else
		 *		like a :e #, and thus can be used after a
E 6
I 6
		 * ^^		Return to previous file.
		 *		Like a :e #, and thus can be used after a
E 6
		 *		"No Write" diagnostic.
D 6
		 *
		 *		Note: this doesn't correspond with documentation
		 *		Is this comment misleading?
E 6
		 */
D 21
		case CTRL(^):
E 21
I 21
		case CTRL('^'):
E 21
D 8
			if (hadcnt)
				vsetsiz(cnt);
E 8
I 8
			forbid (hadcnt);
E 8
D 6
			addr = getmark('t');
			if (addr != 0) {
				markit(addr);
				vupdown(addr - dot, NOSTR);
				continue;
			}
E 6
			vsave();
			ckaw();
			oglobp = globp;
D 2
			globp = "e! #";
E 2
I 2
			if (value(AUTOWRITE))
				globp = "e! #";
			else
				globp = "e #";
E 2
			goto gogo;

		/*
		 * ^]		Takes word after cursor as tag, and then does
		 *		tag command.  Read ``go right to''.
		 */
D 21
		case CTRL(]):
E 21
I 21
		case CTRL(']'):
E 21
			grabtag();
			oglobp = globp;
			globp = "tag";
			goto gogo;

		/*
		 * &		Like :&
		 */
		 case '&':
			oglobp = globp;
			globp = "&";
			goto gogo;
			
		/*
		 * ^G		Bring up a status line at the bottom of
		 *		the screen, like a :file command.
		 *
		 * BUG:		Was ^S but doesn't work in cbreak mode
		 */
D 21
		case CTRL(g):
E 21
I 21
		case CTRL('g'):
E 21
			oglobp = globp;
			globp = "file";
gogo:
			addr = dot;
			vsave();
			goto doinit;

I 4
D 9
#ifdef TIOCLGET
E 9
I 9
#ifdef SIGTSTP
E 9
E 4
		/*
I 4
		 * ^Z:	suspend editor session and temporarily return
D 10
		 * 	to shell.  Only works on Berkeley tty driver.
E 10
I 10
		 * 	to shell.  Only works with Berkeley/IIASA process
		 *	control in kernel.
E 10
		 */
D 21
		case CTRL(z):
E 21
I 21
		case CTRL('z'):
E 21
			forbid(dosusp == 0 || !ldisc);
			vsave();
			oglobp = globp;
			globp = "stop";
			goto gogo;
#endif

		/*
E 4
		 * :		Read a command from the echo area and
		 *		execute it in command mode.
		 */
		case ':':
D 8
			if (hadcnt)
				vsetsiz(cnt);
E 8
I 8
			forbid (hadcnt);
E 8
			vsave();
			i = tchng;
			addr = dot;
			if (readecho(c)) {
				esave[0] = 0;
				goto fixup;
			}
I 4
			getDOT();
E 4
			/*
			 * Use the visual undo buffer to store the global
			 * string for command mode, since it is idle right now.
			 */
			oglobp = globp; strcpy(vutmp, genbuf+1); globp = vutmp;
doinit:
			esave[0] = 0;
			fixech();

			/*
			 * Have to finagle around not to lose last
			 * character after this command (when run from ex
			 * command mode).  This is clumsy.
			 */
			d = peekc; ungetchar(0);
I 3
			if (shouldpo) {
				/*
				 * So after a "Hit return..." ":", we do
				 * another "Hit return..." the next time
				 */
				pofix();
				shouldpo = 0;
			}
E 3
			CATCH
				/*
				 * Save old values of options so we can
				 * notice when they change; switch into
				 * cooked mode so we are interruptible.
				 */
				onumber = value(NUMBER);
				olist = value(LIST);
				OPline = Pline;
D 20
				OPutchar = Putchar;
E 20
I 20
				OPutchar = Put_char;
E 20
#ifndef CBREAK
				vcook();
#endif
				commands(1, 1);
				if (dot == zero && dol > zero)
					dot = one;
#ifndef CBREAK
				vraw();
#endif
			ONERR
#ifndef CBREAK
				vraw();
#endif
				copy(esave, vtube[WECHO], TUBECOLS);
			ENDCATCH
			fixol();
			Pline = OPline;
D 20
			Putchar = OPutchar;
E 20
I 20
			Put_char = OPutchar;
E 20
			ungetchar(d);
			globp = oglobp;

			/*
			 * If we ended up with no lines in the buffer, make
			 * a line, and don't consider the buffer changed.
			 */
			if (dot == zero) {
				fixzero();
D 20
				sync();
E 20
I 20
				ex_sync();
E 20
			}
			splitw = 0;

			/*
			 * Special case: did list/number options change?
			 */
			if (onumber != value(NUMBER))
D 20
				setnumb(value(NUMBER));
E 20
I 20
				ignorf(setnumb(value(NUMBER)));
E 20
			if (olist != value(LIST))
D 20
				setlist(value(LIST));
E 20
I 20
				ignorf(setlist(value(LIST)));
E 20

fixup:
			/*
			 * If a change occurred, other than
			 * a write which clears changes, then
			 * we should allow an undo even if .
			 * didn't move.
			 *
			 * BUG: You can make this wrong by
			 * tricking around with multiple commands
			 * on one line of : escape, and including
			 * a write command there, but its not
			 * worth worrying about.
			 */
D 3
			if (tchng && tchng != i)
E 3
I 3
			if (FIXUNDO && tchng && tchng != i)
E 3
				vundkind = VMANY, cursor = 0;

			/*
			 * If we are about to do another :, hold off
			 * updating of screen.
			 */
D 20
			if (vcnt < 0 && Peekkey == ':') {
E 20
I 20
			if (vcnt < 0 && Peek_key == ':') {
E 20
				getDOT();
I 3
				shouldpo = 1;
E 3
				continue;
			}
I 3
			shouldpo = 0;
E 3

			/*
			 * In the case where the file being edited is
			 * new; e.g. if the initial state hasn't been
			 * saved yet, then do so now.
			 */
			if (unddol == truedol) {
				vundkind = VNONE;
				Vlines = lineDOL();
				if (!inglobal)
					savevis();
				addr = zero;
				vcnt = 0;
				if (esave[0] == 0)
					copy(esave, vtube[WECHO], TUBECOLS);
			}

			/*
			 * If the current line moved reset the cursor position.
			 */
			if (dot != addr) {
				vmoving = 0;
				cursor = 0;
			}

			/*
			 * If current line is not on screen or if we are
			 * in open mode and . moved, then redraw.
			 */
			i = vcline + (dot - addr);
			if (i < 0 || i >= vcnt && i >= -vcnt || state != VISUAL && dot != addr) {
				if (state == CRTOPEN)
					vup1();
				if (vcnt > 0)
					vcnt = 0;
D 22
				vjumpto(dot, (char *) 0, '.');
E 22
I 22
				vjumpto(dot, (u_char *) 0, '.');
E 22
			} else {
				/*
				 * Current line IS on screen.
				 * If we did a [Hit return...] then
				 * restore vcnt and clear screen if in visual
				 */
				vcline = i;
				if (vcnt < 0) {
					vcnt = -vcnt;
					if (state == VISUAL)
						vclear();
D 3
					else if (state == CRTOPEN)
E 3
I 3
					else if (state == CRTOPEN) {
E 3
						vcnt = 0;
I 3
					}
E 3
				}

				/*
				 * Limit max value of vcnt based on $
				 */
				i = vcline + lineDOL() - lineDOT() + 1;
				if (i < vcnt)
					vcnt = i;
				
				/*
				 * Dirty and repaint.
				 */
				vdirty(0, LINES);
				vrepaint(cursor);
			}

			/*
			 * If in visual, put back the echo area
			 * if it was clobberred.
			 */
			if (state == VISUAL) {
				int sdc = destcol, sdl = destline;

				splitw++;
				vigoto(WECHO, 0);
				for (i = 0; i < TUBECOLS - 1; i++) {
					if (esave[i] == 0)
						break;
					vputchar(esave[i]);
				}
				splitw = 0;
				vgoto(sdl, sdc);
			}
			continue;

		/*
		 * u		undo the last changing command.
		 */
		case 'u':
D 4
			vundo();
E 4
I 4
			vundo(1);
E 4
			continue;

		/*
		 * U		restore current line to initial state.
		 */
		case 'U':
D 20
			vUndo();
E 20
I 20
			ex_vUndo();
E 20
			continue;

fonfon:
			beep();
			vmacp = 0;
I 2
			inopen = 1;	/* might have been -1 */
E 2
			continue;
		}

		/*
		 * Rest of commands are decoded by the operate
		 * routine.
		 */
		operate(c, cnt);
	}
}

/*
 * Grab the word after the cursor so we can look for it as a tag.
 */
grabtag()
{
D 22
	register char *cp, *dp;
E 22
I 22
	register u_char *cp, *dp;
E 22

	cp = vpastwh(cursor);
	if (*cp) {
		dp = lasttag;
		do {
			if (dp < &lasttag[sizeof lasttag - 2])
				*dp++ = *cp;
			cp++;
D 15
		} while (isalpha(*cp) || isdigit(*cp) || *cp == '_');
E 15
I 15
		} while (isalpha(*cp) || isdigit(*cp) || *cp == '_'
#ifdef LISPCODE
			|| (value(LISP) && *cp == '-')
#endif LISPCODE
			);
E 15
		*dp++ = 0;
	}
}

/*
 * Before appending lines, set up addr1 and
 * the command mode undo information.
 */
prepapp()
{

	addr1 = dot;
	deletenone();
	addr1++;
	appendnone();
}

/*
 * Execute function f with the address bounds addr1
 * and addr2 surrounding cnt lines starting at dot.
 */
vremote(cnt, f, arg)
	int cnt, (*f)(), arg;
{
	register int oing = inglobal;

	addr1 = dot;
	addr2 = dot + cnt - 1;
D 3
	if (inopen > 0)
		undap1 = undap2 = dot;
E 3
	inglobal = 0;
I 3
	if (FIXUNDO)
		undap1 = undap2 = dot;
E 3
	(*f)(arg);
	inglobal = oing;
D 3
	if (inopen > 0)
E 3
I 3
	if (FIXUNDO)
E 3
		vundkind = VMANY;
	vmcurs = 0;
}

/*
 * Save the current contents of linebuf, if it has changed.
 */
vsave()
{
D 22
	char temp[LBSIZE];
E 22
I 22
	u_char temp[LBSIZE];
E 22

	CP(temp, linebuf);
D 3
	if (vundkind == VCHNG || vundkind == VCAPU) {
E 3
I 3
	if (FIXUNDO && vundkind == VCHNG || vundkind == VCAPU) {
E 3
		/*
		 * If the undo state is saved in the temporary buffer
		 * vutmp, then we sync this into the temp file so that
		 * we will be able to undo even after we have moved off
		 * the line.  It would be possible to associate a line
		 * with vutmp but we assume that vutmp is only associated
		 * with line dot (e.g. in case ':') above, so beware.
		 */
		prepapp();
		strcLIN(vutmp);
		putmark(dot);
		vremote(1, yank, 0);
		vundkind = VMCHNG;
		notecnt = 0;
		undkind = UNDCHANGE;
	}
	/*
	 * Get the line out of the temp file and do nothing if it hasn't
	 * changed.  This may seem like a loss, but the line will
	 * almost always be in a read buffer so this may well avoid disk i/o.
	 */
	getDOT();
	if (strcmp(linebuf, temp) == 0)
		return;
	strcLIN(temp);
	putmark(dot);
}

#undef	forbid
#define	forbid(a)	if (a) { beep(); return; }

/*
 * Do a z operation.
 * Code here is rather long, and very uninteresting.
 */
vzop(hadcnt, cnt, c)
	bool hadcnt;
	int cnt;
	register int c;
{
	register line *addr;

	if (state != VISUAL) {
		/*
		 * Z from open; always like a z=.
		 * This code is a mess and should be cleaned up.
		 */
		vmoveitup(1, 1);
		vgoto(outline, 0);
		ostop(normf);
		setoutt();
		addr2 = dot;
		vclear();
		destline = WECHO;
		zop2(Xhadcnt ? Xcnt : value(WINDOW) - 1, '=');
		if (state == CRTOPEN)
			putnl();
		putNFL();
		termreset();
		Outchar = vputchar;
		ignore(ostart());
		vcnt = 0;
		outline = destline = 0;
		vjumpto(dot, cursor, 0);
		return;
	}
	if (hadcnt) {
		addr = zero + cnt;
		if (addr < one)
			addr = one;
		if (addr > dol)
			addr = dol;
		markit(addr);
	} else
		switch (c) {

		case '+':
			addr = dot + vcnt - vcline;
			break;

		case '^':
			addr = dot - vcline - 1;
			forbid (addr < one);
			c = '-';
			break;

		default:
			addr = dot;
			break;
		}
	switch (c) {

	case '.':
	case '-':
		break;

	case '^':
		forbid (addr <= one);
		break;

	case '+':
		forbid (addr >= dol);
		/* fall into ... */

	case CR:
	case NL:
		c = CR;
		break;

	default:
		beep();
		return;
	}
	vmoving = 0;
	vjumpto(addr, NOSTR, c);
}
E 1
