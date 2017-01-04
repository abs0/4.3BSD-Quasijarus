h22579
s 00015/00015/00932
d D 7.9 03/04/13 15:19:31 msokolov 19 18
c 8-bit ex
e
s 00025/00015/00922
d D 7.8 87/03/09 12:47:14 conrad 18 17
c make ex/vi work on vms
e
s 00001/00001/00936
d D 7.7 85/06/07 18:23:51 bloom 17 16
c fix sccsid and copyright for xstr
e
s 00000/00000/00937
d D 7.6 85/05/31 14:06:18 dist 16 15
c Add copyright
e
s 00000/00002/00937
d D 7.5 85/05/31 12:17:52 dist 15 13
i 14
c add copyright
e
s 00010/00002/00920
d D 5.1.1.1 85/05/31 12:13:46 dist 14 6
c Add copyright
e
s 00001/00001/00928
d D 7.4 85/03/27 12:07:53 bloom 13 12
c confusion with yanks at beginning of line
e
s 00003/00000/00926
d D 7.3 85/02/21 17:48:55 bloom 12 11
c add window size change support
e
s 00002/00001/00924
d D 7.2 81/10/31 14:50:04 mark 11 10
c fixed C/70 bug with peekc being saved in a char
e
s 00003/00003/00922
d D 7.1 81/07/08 22:34:29 mark 10 9
c release 3.7 - a few bug fixes and a few new features.
e
s 00000/00001/00925
d D 6.3 80/10/23 22:22:20 mark 9 8
c removed debugging vudump
e
s 00001/00000/00925
d D 6.2 80/10/23 16:17:08 mark 8 7
c fixed various bugs prior to 3.6 release
e
s 00004/00001/00921
d D 6.1 80/10/19 01:22:39 mark 7 6
c preliminary release 3.6 10/18/80
e
s 00000/00000/00922
d D 5.1 80/08/20 16:14:44 mark 6 5
c Release 3.5, August 20, 1980
e
s 00002/00001/00920
d D 4.2 80/08/01 20:43:30 mark 5 4
c Bill added more buffers, and I put in sccs.
e
s 00106/00007/00815
d D 4.1 80/08/01 00:18:29 mark 4 3
c release 3.4, June 24, 1980
e
s 00019/00009/00803
d D 3.1 80/07/31 23:42:33 mark 3 2
c release 3.3, Feb 2, 1980
e
s 00000/00000/00812
d D 2.1 80/07/31 23:21:16 mark 2 1
c release 3.2, Jan 4, 1980
e
s 00812/00000/00000
d D 1.1 80/07/31 23:00:53 mark 1 0
c date and time created 80/07/31 23:00:53 by mark
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
D 14
/* Copyright (c) 1980 Regents of the University of California */
static char *sccsid = "%W% %G%";
E 14
I 14
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
D 17
static char sccsid[] = "%W% (Berkeley) %G%";
E 17
I 17
static char *sccsid = "%W% (Berkeley) %G%";
E 17
#endif not lint

E 14
E 10
I 10
D 15
/* Copyright (c) 1981 Regents of the University of California */
static char *sccsid = "%W%	%G%";
E 15
E 10
E 5
#include "ex.h"
#include "ex_tty.h"
#include "ex_vis.h"

/*
 * This file defines the operation sequences which interface the
 * logical changes to the file buffer with the internal and external
 * display representations.
 */

/*
 * Undo.
 *
 * Undo is accomplished in two ways.  We often for small changes in the
 * current line know how (in terms of a change operator) how the change
 * occurred.  Thus on an intelligent terminal we can undo the operation
 * by another such operation, using insert and delete character
 * stuff.  The pointers vU[AD][12] index the buffer vutmp when this
 * is possible and provide the necessary information.
 *
 * The other case is that the change involved multiple lines or that
 * we have moved away from the line or forgotten how the change was
 * accomplished.  In this case we do a redisplay and hope that the
 * low level optimization routines (which don't look for winning
 * via insert/delete character) will not lose too badly.
 */
D 19
char	*vUA1, *vUA2;
char	*vUD1, *vUD2;
E 19
I 19
u_char	*vUA1, *vUA2;
u_char	*vUD1, *vUD2;
E 19

D 18
vUndo()
E 18
I 18
ex_vUndo()
E 18
{

	/*
	 * Avoid UU which clobbers ability to do u.
	 */
	if (vundkind == VCAPU || vUNDdot != dot) {
		beep();
		return;
	}
	CP(vutmp, linebuf);
	vUD1 = linebuf; vUD2 = strend(linebuf);
	putmk1(dot, vUNDsav);
	getDOT();
	vUA1 = linebuf; vUA2 = strend(linebuf);
	vundkind = VCAPU;
	if (state == ONEOPEN || state == HARDOPEN) {
		vjumpto(dot, vUNDcurs, 0);
		return;
	}
	vdirty(vcline, 1);
	vsyncCL();
I 4
	cursor = linebuf;
E 4
	vfixcurs();
}

D 4
vundo()
E 4
I 4
vundo(show)
bool show;	/* if true update the screen */
E 4
{
	register int cnt;
	register line *addr;
D 19
	register char *cp;
	char temp[LBSIZE];
E 19
I 19
	register u_char *cp;
	u_char temp[LBSIZE];
E 19
	bool savenote;
	int (*OO)();
	short oldhold = hold;

	switch (vundkind) {

	case VMANYINS:
		wcursor = 0;
		addr1 = undap1;
		addr2 = undap2 - 1;
		vsave();
		YANKreg('1');
		notecnt = 0;
		/* fall into ... */

	case VMANY:
	case VMCHNG:
		vsave();
		addr = dot - vcline;
		notecnt = 1;
		if (undkind == UNDPUT && undap1 == undap2) {
			beep();
D 3
			return;
E 3
I 3
			break;
E 3
		}
		/*
		 * Undo() call below basically replaces undap1 to undap2-1
		 * with dol through unddol-1.  Hack screen image to
		 * reflect this replacement.
		 */
D 4
		vreplace(undap1 - addr, undap2 - undap1,
		    undkind == UNDPUT ? 0 : unddol - dol);
E 4
I 4
		if (show)
			if (undkind == UNDMOVE)
				vdirty(0, LINES);
			else
				vreplace(undap1 - addr, undap2 - undap1,
				    undkind == UNDPUT ? 0 : unddol - dol);
I 8
D 9
vudump("before big undo");
E 9
E 8
E 4
		savenote = notecnt;
		undo(1);
D 4
		if (vundkind != VMCHNG || addr != dot)
E 4
I 4
		if (show && (vundkind != VMCHNG || addr != dot))
E 4
			killU();
		vundkind = VMANY;
		cnt = dot - addr;
		if (cnt < 0 || cnt > vcnt || state != VISUAL) {
D 4
			vjumpto(dot, NOSTR, '.');
E 4
I 4
			if (show)
				vjumpto(dot, NOSTR, '.');
E 4
D 3
			return;
E 3
I 3
			break;
E 3
		}
		if (!savenote)
			notecnt = 0;
D 4
		vcline = cnt;
		vrepaint(vmcurs);
E 4
I 4
		if (show) {
			vcline = cnt;
			vrepaint(vmcurs);
		}
E 4
		vmcurs = 0;
D 3
		return;
E 3
I 3
		break;
E 3

	case VCHNG:
	case VCAPU:
		vundkind = VCHNG;
		strcpy(temp, vutmp);
		strcpy(vutmp, linebuf);
		doomed = column(vUA2 - 1) - column(vUA1 - 1);
		strcLIN(temp);
		cp = vUA1; vUA1 = vUD1; vUD1 = cp;
		cp = vUA2; vUA2 = vUD2; vUD2 = cp;
I 4
		if (!show)
			break;
E 4
		cursor = vUD1;
		if (state == HARDOPEN) {
			doomed = 0;
			vsave();
			vopen(dot, WBOT);
			vnline(cursor);
D 3
			return;
E 3
I 3
			break;
E 3
		}
		/*
		 * Pseudo insert command.
		 */
		vcursat(cursor);
		OO = Outchar; Outchar = vinschar; hold |= HOLDQIK;
		vprepins();
		temp[vUA2 - linebuf] = 0;
		for (cp = &temp[vUA1 - linebuf]; *cp;)
D 18
			putchar(*cp++);
E 18
I 18
			ex_putchar(*cp++);
E 18
		Outchar = OO; hold = oldhold;
		endim();
		physdc(cindent(), cindent() + doomed);
		doomed = 0;
		vdirty(vcline, 1);
		vsyncCL();
		if (cursor > linebuf && cursor >= strend(linebuf))
			cursor--;
		vfixcurs();
D 3
		return;
E 3
I 3
		break;
E 3

	case VNONE:
		beep();
I 4
		break;
	}
}

/*
 * Routine to handle a change inside a macro.
 * Fromvis is true if we were called from a visual command (as
 * opposed to an ex command).  This has nothing to do with being
 * in open/visual mode as :s/foo/bar is not fromvis.
 */
vmacchng(fromvis)
bool fromvis;
{
	line *savedot, *savedol;
D 19
	char *savecursor;
I 7
	char savelb[LBSIZE];
E 19
I 19
	u_char *savecursor;
	u_char savelb[LBSIZE];
E 19
E 7
	int nlines, more;
D 18
	register line *a1, *a2;
	char ch;	/* DEBUG */
E 18
	int copyw(), copywR();

	if (!inopen)
		return;
	if (!vmacp)
		vch_mac = VC_NOTINMAC;
#ifdef TRACE
	if (trace)
		fprintf(trace, "vmacchng, vch_mac=%d, linebuf='%s', *dot=%o\n", vch_mac, linebuf, *dot);
#endif
	if (vmacp && fromvis)
		vsave();
#ifdef TRACE
	if (trace)
		fprintf(trace, "after vsave, linebuf='%s', *dot=%o\n", linebuf, *dot);
#endif
	switch(vch_mac) {
	case VC_NOCHANGE:
		vch_mac = VC_ONECHANGE;
		break;
	case VC_ONECHANGE:
		/* Save current state somewhere */
#ifdef TRACE
		vudump("before vmacchng hairy case");
#endif
		savedot = dot; savedol = dol; savecursor = cursor;
I 7
		CP(savelb, linebuf);
E 7
		nlines = dol - zero;
		while ((line *) endcore - truedol < nlines)
D 18
			morelines();
E 18
I 18
			if (morelines() < 0) {
				dot = savedot;
				dol = savedol;
				cursor = savecursor;
				CP(linebuf, savelb);
				error("Out of memory@- too many lines to undo");
			}
E 18
		copyw(truedol+1, zero+1, nlines);
		truedol += nlines;

#ifdef TRACE
		visdump("before vundo");
#endif
		/* Restore state as it was at beginning of macro */
		vundo(0);
#ifdef TRACE
		visdump("after vundo");
		vudump("after vundo");
#endif

		/* Do the saveall we should have done then */
		saveall();
#ifdef TRACE
		vudump("after saveall");
#endif

		/* Restore current state from where saved */
		more = savedol - dol; /* amount we shift everything by */
		if (more)
			(*(more>0 ? copywR : copyw))(savedol+1, dol+1, truedol-dol);
D 7
		unddol += more; truedol += more;
E 7
I 7
		unddol += more; truedol += more; undap2 += more;
E 7

		truedol -= nlines;
		copyw(zero+1, truedol+1, nlines);
		dot = savedot; dol = savedol ; cursor = savecursor;
I 7
		CP(linebuf, savelb);
E 7
		vch_mac = VC_MANYCHANGE;

		/* Arrange that no further undo saving happens within macro */
		otchng = tchng;	/* Copied this line blindly - bug? */
		inopen = -1;	/* no need to save since it had to be 1 or -1 before */
		vundkind = VMANY;
#ifdef TRACE
		vudump("after vmacchng");
#endif
		break;
	case VC_NOTINMAC:
	case VC_MANYCHANGE:
		/* Nothing to do for various reasons. */
E 4
D 3
		return;
E 3
I 3
		break;
E 3
	}
}

/*
 * Initialize undo information before an append.
 */
vnoapp()
{

	vUD1 = vUD2 = cursor;
}

/*
 * All the rest of the motion sequences have one or more
 * cases to deal with.  In the case wdot == 0, operation
 * is totally within current line, from cursor to wcursor.
 * If wdot is given, but wcursor is 0, then operation affects
 * the inclusive line range.  The hardest case is when both wdot
 * and wcursor are given, then operation affects from line dot at
 * cursor to line wdot at wcursor.
 */

/*
 * Move is simple, except for moving onto new lines in hardcopy open mode.
 */
vmove()
{
	register int cnt;

	if (wdot) {
		if (wdot < one || wdot > dol) {
			beep();
			return;
		}
		cnt = wdot - dot;
		wdot = NOLINE;
		if (cnt)
			killU();
		vupdown(cnt, wcursor);
		return;
	}

	/*
	 * When we move onto a new line, save information for U undo.
	 */
	if (vUNDdot != dot) {
		vUNDsav = *dot;
		vUNDcurs = wcursor;
		vUNDdot = dot;
	}

	/*
	 * In hardcopy open, type characters to left of cursor
	 * on new line, or back cursor up if its to left of where we are.
	 * In any case if the current line is ``rubbled'' i.e. has trashy
	 * looking overstrikes on it or \'s from deletes, we reprint
	 * so it is more comprehensible (and also because we can't work
	 * if we let it get more out of sync since column() won't work right.
	 */
	if (state == HARDOPEN) {
D 19
		register char *cp;
E 19
I 19
		register u_char *cp;
E 19
		if (rubble) {
			register int c;
			int oldhold = hold;

			sethard();
			cp = wcursor;
			c = *cp;
			*cp = 0;
			hold |= HOLDDOL;
D 18
			vreopen(WTOP, lineDOT(), vcline);
E 18
I 18
			ignore(vreopen(WTOP, lineDOT(), vcline));
E 18
			hold = oldhold;
			*cp = c;
		} else if (wcursor > cursor) {
			vfixcurs();
			for (cp = cursor; *cp && cp < wcursor;) {
D 19
				register int c = *cp++ & TRIM;
E 19
I 19
				register int c = *cp++;
E 19

D 18
				putchar(c ? c : ' ');
E 18
I 18
				ex_putchar(c ? c : ' ');
E 18
			}
		}
	}
	vsetcurs(wcursor);
}

/*
 * Delete operator.
 *
 * Hard case of deleting a range where both wcursor and wdot
 * are specified is treated as a special case of change and handled
 * by vchange (although vchange may pass it back if it degenerates
 * to a full line range delete.)
 */
vdelete(c)
D 19
	char c;
E 19
I 19
	u_char c;
E 19
{
D 19
	register char *cp;
E 19
I 19
	register u_char *cp;
E 19
	register int i;

	if (wdot) {
		if (wcursor) {
			vchange('d');
			return;
		}
		if ((i = xdw()) < 0)
			return;
		if (state != VISUAL) {
			vgoto(LINE(0), 0);
			vputchar('@');
		}
		wdot = dot;
D 18
		vremote(i, delete, 0);
E 18
I 18
		vremote(i, ex_delete, 0);
E 18
		notenam = "delete";
		DEL[0] = 0;
		killU();
		vreplace(vcline, i, 0);
		if (wdot > dol)
			vcline--;
		vrepaint(NOSTR);
		return;
	}
	if (wcursor < linebuf)
		wcursor = linebuf;
	if (cursor == wcursor) {
		beep();
		return;
	}
	i = vdcMID();
	cp = cursor;
	setDEL();
	CP(cp, wcursor);
	if (cp > linebuf && (cp[0] == 0 || c == '#'))
		cp--;
	if (state == HARDOPEN) {
		bleep(i, cp);
		cursor = cp;
		return;
	}
	physdc(column(cursor - 1), i);
	DEPTH(vcline) = 0;
D 18
	vreopen(LINE(vcline), lineDOT(), vcline);
E 18
I 18
	ignore(vreopen(LINE(vcline), lineDOT(), vcline));
E 18
	vsyncCL();
	vsetcurs(cp);
}

/*
 * Change operator.
 *
 * In a single line we mark the end of the changed area with '$'.
 * On multiple whole lines, we clear the lines first.
 * Across lines with both wcursor and wdot given, we delete
 * and sync then append (but one operation for undo).
 */
vchange(c)
D 19
	char c;
E 19
I 19
	u_char c;
E 19
{
D 19
	register char *cp;
E 19
I 19
	register u_char *cp;
E 19
	register int i, ind, cnt;
	line *addr;

	if (wdot) {
		/*
		 * Change/delete of lines or across line boundaries.
		 */
		if ((cnt = xdw()) < 0)
			return;
		getDOT();
		if (wcursor && cnt == 1) {
			/*
			 * Not really.
			 */
			wdot = 0;
			if (c == 'd') {
				vdelete(c);
				return;
			}
			goto smallchange;
		}
		if (cursor && wcursor) {
			/*
			 * Across line boundaries, but not
			 * necessarily whole lines.
			 * Construct what will be left.
			 */
			*cursor = 0;
			strcpy(genbuf, linebuf);
			getline(*wdot);
			if (strlen(genbuf) + strlen(wcursor) > LBSIZE - 2) {
				getDOT();
				beep();
				return;
			}
			strcat(genbuf, wcursor);
			if (c == 'd' && *vpastwh(genbuf) == 0) {
				/*
				 * Although this is a delete
				 * spanning line boundaries, what
				 * would be left is all white space,
				 * so take it all away.
				 */
				wcursor = 0;
				getDOT();
				op = 0;
				notpart(lastreg);
				notpart('1');
				vdelete(c);
				return;
			}
			ind = -1;
		} else if (c == 'd' && wcursor == 0) {
			vdelete(c);
			return;
		} else
#ifdef LISPCODE
			/*
			 * We are just substituting text for whole lines,
			 * so determine the first autoindent.
			 */
			if (value(LISP) && value(AUTOINDENT))
				ind = lindent(dot);
			else
#endif
				ind = whitecnt(linebuf);
		i = vcline >= 0 ? LINE(vcline) : WTOP;

		/*
		 * Delete the lines from the buffer,
		 * and remember how the partial stuff came about in
		 * case we are told to put.
		 */
		addr = dot;
D 18
		vremote(cnt, delete, 0);
E 18
I 18
		vremote(cnt, ex_delete, 0);
E 18
		setpk();
		notenam = "delete";
		if (c != 'd')
			notenam = "change";
		/*
		 * If DEL[0] were nonzero, put would put it back
		 * rather than the deleted lines.
		 */
		DEL[0] = 0;
		if (cnt > 1)
			killU();

		/*
		 * Now hack the screen image coordination.
		 */
		vreplace(vcline, cnt, 0);
		wdot = NOLINE;
D 18
		noteit(0);
E 18
I 18
		ignore(noteit(0));
E 18
		vcline--;
		if (addr <= dol)
			dot--;

		/*
		 * If this is a across line delete/change,
		 * cursor stays where it is; just splice together the pieces
		 * of the new line.  Otherwise generate a autoindent
		 * after a S command.
		 */
		if (ind >= 0) {
			*genindent(ind) = 0;
			vdoappend(genbuf);
		} else {
			vmcurs = cursor;
			strcLIN(genbuf);
			vdoappend(linebuf);
		}

		/*
		 * Indicate a change on hardcopies by
		 * erasing the current line.
		 */
		if (c != 'd' && state != VISUAL && state != HARDOPEN) {
			int oldhold = hold;

			hold |= HOLDAT, vclrlin(i, dot), hold = oldhold;
		}

		/*
		 * Open the line (logically) on the screen, and 
		 * update the screen tail.  Unless we are really a delete
		 * go off and gather up inserted characters.
		 */
		vcline++;
		if (vcline < 0)
			vcline = 0;
		vopen(dot, i);
		vsyncCL();
D 18
		noteit(1);
E 18
I 18
		ignore(noteit(1));
E 18
		if (c != 'd') {
			if (ind >= 0) {
				cursor = linebuf;
				linebuf[0] = 0;
				vfixcurs();
			} else {
				ind = 0;
				vcursat(cursor);
			}
			vappend('x', 1, ind);
			return;
		}
		if (*cursor == 0 && cursor > linebuf)
			cursor--;
		vrepaint(cursor);
		return;
	}

smallchange:
	/*
	 * The rest of this is just low level hacking on changes
	 * of small numbers of characters.
	 */
	if (wcursor < linebuf)
		wcursor = linebuf;
	if (cursor == wcursor) {
		beep();
		return;
	}
	i = vdcMID();
	cp = cursor;
	if (state != HARDOPEN)
		vfixcurs();

	/*
	 * Put out the \\'s indicating changed text in hardcopy,
	 * or mark the end of the change with $ if not hardcopy.
	 */
	if (state == HARDOPEN) 
		bleep(i, cp);
	else {
		vcursbef(wcursor);
D 18
		putchar('$');
E 18
I 18
		ex_putchar('$');
E 18
		i = cindent();
	}

	/*
	 * Remember the deleted text for possible put,
	 * and then prepare and execute the input portion of the change.
	 */
	cursor = cp;
	setDEL();
	CP(cursor, wcursor);
	if (state != HARDOPEN) {
		vcursaft(cursor - 1);
		doomed = i - cindent();
	} else {
/*
		sethard();
		wcursor = cursor;
		cursor = linebuf;
		vgoto(outline, value(NUMBER) << 3);
		vmove();
*/
		doomed = 0;
	}
	prepapp();
	vappend('c', 1, 0);
}

/*
 * Open new lines.
 *
 * Tricky thing here is slowopen.  This causes display updating
 * to be held off so that 300 baud dumb terminals don't lose badly.
 * This also suppressed counts, which otherwise say how many blank
 * space to open up.  Counts are also suppressed on intelligent terminals.
 * Actually counts are obsoleted, since if your terminal is slow
 * you are better off with slowopen.
 */
voOpen(c, cnt)
D 10
	char c;
E 10
I 10
	int c;	/* mjm: char --> int */
E 10
	register int cnt;
{
	register int ind = 0, i;
	short oldhold = hold;
I 18
#ifdef	SIGWINCH
E 18
I 12
	int oldmask;
I 18
#endif
E 18
E 12

	if (value(SLOWOPEN) || value(REDRAW) && AL && DL)
		cnt = 1;
I 18
#ifdef	SIGWINCH
E 18
I 12
	oldmask = sigblock(sigmask(SIGWINCH));
I 18
#endif
E 18
E 12
	vsave();
	setLAST();
	if (value(AUTOINDENT))
		ind = whitecnt(linebuf);
	if (c == 'O') {
		vcline--;
		dot--;
		if (dot > zero)
			getDOT();
	}
	if (value(AUTOINDENT)) {
#ifdef LISPCODE
		if (value(LISP))
			ind = lindent(dot + 1);
#endif
	}
	killU();
	prepapp();
D 3
	vundkind = VMANY;
E 3
I 3
	if (FIXUNDO)
		vundkind = VMANY;
E 3
	if (state != VISUAL)
		c = WBOT + 1;
	else {
		c = vcline < 0 ? WTOP - cnt : LINE(vcline) + DEPTH(vcline);
D 18
		if (c < ZERO)
			c = ZERO;
E 18
I 18
		if (c < ex_ZERO)
			c = ex_ZERO;
E 18
		i = LINE(vcline + 1) - c;
		if (i < cnt && c <= WBOT && (!AL || !DL))
			vinslin(c, cnt - i, vcline);
	}
	*genindent(ind) = 0;
	vdoappend(genbuf);
	vcline++;
	oldhold = hold;
	hold |= HOLDROL;
	vopen(dot, c);
	hold = oldhold;
	if (value(SLOWOPEN))
		/*
		 * Oh, so lazy!
		 */
		vscrap();
	else
		vsync1(LINE(vcline));
	cursor = linebuf;
	linebuf[0] = 0;
	vappend('o', 1, ind);
I 18
#ifdef	SIGWINCH
E 18
I 12
	(void)sigsetmask(oldmask);
I 18
#endif
E 18
E 12
}

/*
 * > < and = shift operators.
 *
 * Note that =, which aligns lisp, is just a ragged sort of shift,
 * since it never distributes text between lines.
 */
D 19
char	vshnam[2] = { 'x', 0 };
E 19
I 19
u_char	vshnam[2] = { 'x', 0 };
E 19

vshftop()
{
	register line *addr;
	register int cnt;

	if ((cnt = xdw()) < 0)
		return;
	addr = dot;
	vremote(cnt, vshift, 0);
	vshnam[0] = op;
	notenam = vshnam;
	dot = addr;
	vreplace(vcline, cnt, cnt);
	if (state == HARDOPEN)
		vcnt = 0;
	vrepaint(NOSTR);
}

/*
 * !.
 *
 * Filter portions of the buffer through unix commands.
 */
vfilter()
{
	register line *addr;
	register int cnt;
D 11
	char *oglobp, d;
E 11
I 11
D 19
	char *oglobp;
E 19
I 19
	u_char *oglobp;
E 19
	short d;
E 11

	if ((cnt = xdw()) < 0)
		return;
	if (vglobp)
		vglobp = uxb;
	if (readecho('!'))
		return;
	oglobp = globp; globp = genbuf + 1;
	d = peekc; ungetchar(0);
	CATCH
		fixech();
		unix0(0);
	ONERR
		splitw = 0;
		ungetchar(d);
		vrepaint(cursor);
		globp = oglobp;
		return;
	ENDCATCH
	ungetchar(d); globp = oglobp;
	addr = dot;
	CATCH
		vgoto(WECHO, 0); flusho();
		vremote(cnt, filter, 2);
	ONERR
		vdirty(0, LINES);
	ENDCATCH
	if (dot == zero && dol > zero)
		dot = one;
	splitw = 0;
	notenam = "";
I 3
	/*
	 * BUG: we shouldn't be depending on what undap2 and undap1 are,
	 * since we may be inside a macro.  What's really wanted is the
	 * number of lines we read from the filter.  However, the mistake
	 * will be an overestimate so it only results in extra work,
	 * it shouldn't cause any real screwups.
	 */
E 3
	vreplace(vcline, cnt, undap2 - undap1);
	dot = addr;
	if (dot > dol) {
		dot--;
		vcline--;
	}
	vrepaint(NOSTR);
}

/*
 * Xdw exchanges dot and wdot if appropriate and also checks
 * that wdot is reasonable.  Its name comes from
 *	xchange dotand wdot
 */
xdw()
{
D 19
	register char *cp;
E 19
I 19
	register u_char *cp;
E 19
	register int cnt;
/*
	register int notp = 0;
 */

	if (wdot == NOLINE || wdot < one || wdot > dol) {
		beep();
		return (-1);
	}
	vsave();
	setLAST();
D 13
	if (dot > wdot) {
E 13
I 13
	if (dot > wdot || (dot == wdot && wcursor != 0 && cursor > wcursor)) {
E 13
		register line *addr;

		vcline -= dot - wdot;
		addr = dot; dot = wdot; wdot = addr;
		cp = cursor; cursor = wcursor; wcursor = cp;
	}
	/*
	 * If a region is specified but wcursor is at the begining
	 * of the last line, then we move it to be the end of the
	 * previous line (actually off the end).
	 */
	if (cursor && wcursor == linebuf && wdot > dot) {
		wdot--;
		getDOT();
		if (vpastwh(linebuf) >= cursor)
			wcursor = 0;
		else {
			getline(*wdot);
			wcursor = strend(linebuf);
			getDOT();
		}
		/*
		 * Should prepare in caller for possible dot == wdot.
		 */
	}
	cnt = wdot - dot + 1;
	if (vreg) {
		vremote(cnt, YANKreg, vreg);
/*
		if (notp)
			notpart(vreg);
 */
	}

	/*
	 * Kill buffer code.  If delete operator is c or d, then save
	 * the region in numbered buffers.
	 *
	 * BUG:			This may be somewhat inefficient due
	 *			to the way named buffer are implemented,
	 *			necessitating some optimization.
	 */
	vreg = 0;
	if (any(op, "cd")) {
		vremote(cnt, YANKreg, '1');
/*
		if (notp)
			notpart('1');
 */
	}
	return (cnt);
}

/*
 * Routine for vremote to call to implement shifts.
 */
vshift()
{

	shift(op, 1);
}

/*
 * Replace a single character with the next input character.
 * A funny kind of insert.
 */
vrep(cnt)
	register int cnt;
{
	register int i, c;

	if (cnt > strlen(cursor)) {
		beep();
		return;
	}
	i = column(cursor + cnt - 1);
	vcursat(cursor);
	doomed = i - cindent();
	if (!vglobp) {
		c = getesc();
		if (c == 0) {
			vfixcurs();
			return;
		}
		ungetkey(c);
	}
	CP(vutmp, linebuf);
D 3
	vundkind = VCHNG;
E 3
I 3
	if (FIXUNDO)
		vundkind = VCHNG;
E 3
	wcursor = cursor + cnt;
	vUD1 = cursor; vUD2 = wcursor;
	CP(cursor, wcursor);
	prepapp();
	vappend('r', cnt, 0);
	*lastcp++ = INS[0];
	setLAST();
}

/*
 * Yank.
 *
 * Yanking to string registers occurs for free (essentially)
 * in the routine xdw().
 */
vyankit()
{
	register int cnt;

	if (wdot) {
		if ((cnt = xdw()) < 0)
			return;
		vremote(cnt, yank, 0);
		setpk();
		notenam = "yank";
D 3
		vundkind = VNONE;
E 3
I 3
		if (FIXUNDO)
			vundkind = VNONE;
E 3
		DEL[0] = 0;
		wdot = NOLINE;
		if (notecnt <= vcnt - vcline && notecnt < value(REPORT))
			notecnt = 0;
		vrepaint(cursor);
		return;
	}
	takeout(DEL);
}

/*
 * Set pkill variables so a put can
 * know how to put back partial text.
 * This is necessary because undo needs the complete
 * line images to be saved, while a put wants to trim
 * the first and last lines.  The compromise
 * is for put to be more clever.
 */
setpk()
{

	if (wcursor) {
		pkill[0] = cursor;
		pkill[1] = wcursor;
	}
}
E 1
