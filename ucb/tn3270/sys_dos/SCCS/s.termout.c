h11570
s 00009/00019/00485
d D 3.2 88/03/28 12:23:53 bostic 15 14
c add Berkeley specific header
e
s 00000/00000/00504
d D 3.1 87/08/11 10:20:23 minshall 14 13
c New version numbering.
e
s 00002/00002/00502
d D 1.13 87/07/17 10:05:01 minshall 13 12
c Install sccs headers and copyright notices.
e
s 00012/00001/00492
d D 1.12 87/07/16 14:04:58 minshall 12 11
c Make transparent mode work.
e
s 00021/00016/00472
d D 1.11 87/07/16 12:29:58 minshall 11 10
c Put up error messages (on 25th line) in dos environment.
e
s 00001/00001/00487
d D 1.10 87/07/16 11:52:37 minshall 10 9
c New directory structure.
e
s 00001/00002/00487
d D 1.9 87/06/15 10:47:55 minshall 9 8
c Remove unused global variable (yeah!).
e
s 00003/00007/00486
d D 1.8 87/05/28 17:26:47 minshall 8 7
c New .h file; translate table in separate .o file.
e
s 00006/00001/00487
d D 1.7 87/05/25 16:10:03 minshall 7 6
c Make "connection closed by remote host" come out on its own line.
e
s 00003/00003/00485
d D 1.6 87/05/22 12:21:17 minshall 6 5
c New directory structure.
e
s 00033/00039/00455
d D 1.5 87/05/20 11:28:06 minshall 5 4
c This version works.
e
s 00002/00002/00492
d D 1.4 87/05/15 16:04:09 minshall 4 3
c Set the maximum number of lines; number of lines is set using 
c maximum number in telnet.c.
e
s 00119/00004/00375
d D 1.3 87/05/13 11:33:51 minshall 3 2
c This version may work, and is intact.
e
s 00092/00636/00287
d D 1.2 87/05/13 08:58:27 minshall 2 1
c This version compiles.
e
s 00923/00000/00000
d D 1.1 87/05/12 14:20:26 minshall 1 0
c date and time created 87/05/12 14:20:26 by minshall
e
u
U
t
T
I 1
/*
D 13
 *	Copyright (c) 1984, 1985, 1986 by the Regents of the
E 13
I 13
D 15
 *	Copyright (c) 1984-1987 by the Regents of the
E 13
 *	University of California and by Gregory Glenn Minshall.
E 15
I 15
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
E 15
 *
D 15
 *	Permission to use, copy, modify, and distribute these
 *	programs and their documentation for any purpose and
 *	without fee is hereby granted, provided that this
 *	copyright and permission appear on all copies and
 *	supporting documentation, the name of the Regents of
 *	the University of California not be used in advertising
 *	or publicity pertaining to distribution of the programs
 *	without specific prior permission, and notice be given in
 *	supporting documentation that copying and distribution is
 *	by permission of the Regents of the University of California
 *	and by Gregory Glenn Minshall.  Neither the Regents of the
 *	University of California nor Gregory Glenn Minshall make
 *	representations about the suitability of this software
 *	for any purpose.  It is provided "as is" without
 *	express or implied warranty.
E 15
I 15
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 15
 */

#ifndef lint
D 13
static	char	sccsid[] = "@(#)outbound.c	3.1  10/29/86";
E 13
I 13
static char sccsid[] = "%W% (Berkeley) %G%";
E 13
D 15
#endif	/* lint */

E 15
I 15
#endif /* not lint */
E 15

D 2
#if defined(unix)
#include <signal.h>
#include <sgtty.h>
#endif
E 2
#include <stdio.h>
I 3
#include <dos.h>
E 3
D 2
#include <curses.h>

E 2
D 6
#include "../general.h"
E 6
I 6
#include "../general/general.h"
E 6

D 2
#include "terminal.h"

E 2
#include "../telnet.ext"

I 8
D 10
#include "../ascii/disp_asc.h"
E 10
I 10
#include "../api/disp_asc.h"
E 10
#include "../ascii/map3270.ext"

E 8
#include "../ctlr/hostctlr.h"
#include "../ctlr/inbound.ext"
I 2
#include "../ctlr/oia.h"
E 2
#include "../ctlr/options.ext"
#include "../ctlr/outbound.ext"
#include "../ctlr/screen.h"

D 6
#include "../keyboard/map3270.ext"
E 6
I 6
D 8
#include "../ascii/map3270.ext"
E 6

E 8
D 6
#include "../system/globals.h"
E 6
I 6
#include "../general/globals.h"
E 6

I 3
#include "video.h"

E 3
extern void EmptyTerminal();

#define CorrectTerminalCursor() ((TransparentClock == OutputClock)? \
		terminalCursorAddress:UnLocked? CursorAddress: HighestScreen())


static int terminalCursorAddress;	/* where the cursor is on term */
static int screenInitd; 		/* the screen has been initialized */
static int screenStopped;		/* the screen has been stopped */
D 2
#if	defined(SLOWSCREEN)
static int max_changes_before_poll;	/* how many characters before looking */
					/* at terminal and net again */
#endif	/* defined(SLOWSCREEN) */
E 2

static int needToRing;			/* need to ring terinal bell */
D 2
static char *bellSequence = "\07";	/* bell sequence (may be replaced by
					 * VB during initialization)
					 */
static WINDOW *bellwin = 0;		/* The window the bell message is in */
int	bellwinup = 0;			/* Are we up with it or not */
E 2

D 2
#if	defined(unix)
static char *KS, *KE;
#endif	/* defined(unix) */
E 2
I 2
typedef struct {
    char
	data,		/* The data for this position */
	attr;		/* The attributes for this position */
} ScreenBuffer;
E 2

I 2
ScreenBuffer Screen[MAXNUMBERLINES*MAXNUMBERCOLUMNS];
I 3
ScreenBuffer saveScreen[sizeof Screen/sizeof Screen[0]];
E 3
E 2
D 8

D 2
#if	defined(SLOWSCREEN)
static int inHighlightMode = 0;
ScreenImage Terminal[MAXSCREENSIZE];
#endif	/* defined(SLOWSCREEN) */

E 2
/* Variables for transparent mode */
D 2
#if	defined(unix)
static int tcflag = -1;			/* transparent mode command flag */
static int savefd[2];			/* for storing fds during transcom */
extern int	tin, tout;		/* file descriptors */
#endif	/* defined(unix) */
E 2

D 2

E 2
#include "disp_asc.out"

E 8

D 2

/*
 * init_screen()
 *
 * Initialize variables used by screen.
 */

void
init_screen()
{
    bellwinup = 0;
#if	defined(SLOWSCREEN)
    inHighlightMode = 0;
    ClearArray(Terminal);
#endif	/* defined(SLOWSCREEN) */
}


E 2
/* OurExitString - designed to keep us from going through infinite recursion */

static void
OurExitString(file, string, value)
FILE	*file;
char	*string;
int	value;
{
    static int recursion = 0;

    if (!recursion) {
	recursion = 1;
	ExitString(file, string, value);
    }
}


D 2
/* DoARefresh */

E 2
static void
D 2
DoARefresh()
{
    if (ERR == refresh()) {
	OurExitString(stderr, "ERR from refresh\n", 1);
    }
}

static void
E 2
GoAway(from, where)
char *from;		/* routine that gave error */
int	where;		/* cursor address */
{
	char foo[100];

	sprintf(foo, "ERR from %s at %d (%d, %d)\n",
		from, where, ScreenLine(where), ScreenLineOffset(where));
	OurExitString(stderr, foo, 1);
	/* NOTREACHED */
}

I 3
/*
 * Routines to deal with the screen.  These routines are lifted
 * from mskermit.
 */

#define	CRT_STATUS	0x3da		/* Color card */
#define	DISPLAY_ENABLE	0x08		/* Enable */
#define	scrseg()	((crt_mode == 7)? 0xb000 : 0xb800)
#define	scrwait()	if (crt_mode != 7) { \
			    while ((inp(CRT_STATUS)&DISPLAY_ENABLE) == 0) { \
				; \
			    } \
			}
static int
    		crt_mode,
		crt_cols,
		crt_lins,
		curpage;

/*
 * Set the cursor position to where it belongs.
 */

E 3
D 2
#if	defined(SLOWSCREEN)
/* What is the screen address of the attribute byte for the terminal */

static int
WhereTermAttrByte(p)
register int	p;
{
    register int i;

    i = p;

    do {
	if (TermIsStartField(i)) {
	    return(i);
	}
	i = ScreenDec(i);
    } while (i != p);

    return(LowestScreen());	/* unformatted screen... */
}
#endif	/* defined(SLOWSCREEN) */

/*
 *	There are two algorithms for updating the screen.
 *  The first, SlowScreen() optimizes the line between the
 *  computer and the screen (say a 9600 baud line).  To do
 *  this, we break out of the loop every so often to look
 *  at any pending input from the network (so that successive
 *  screens will only partially print until the final screen,
 *  the one the user possibly wants to see, is displayed
 *  in its entirety).
 *
 *	The second algorithm tries to optimize CPU time (by
 *  being simpler) at the cost of the bandwidth to the
 *  screen.
 *
 *	Of course, curses(3X) gets in here also.
 */


#if defined(SLOWSCREEN)
#if	defined(NOT43)
static int
#else	/* defined(NOT43) */
E 2
static void
I 3
setcursor(row, column, page)
int
    row,
    column,
    page;
{
    union REGS inregs, outregs;

    inregs.h.dh = row;
    inregs.h.dl = column;
    inregs.h.bh = page;
    inregs.h.ah = SetCursorPosition;

    int86(BIOS_VIDEO, &inregs, &outregs);
}
/*
 * Read the state of the video system.  Put the cursor somewhere
 * reasonable.
 */

static void
scrini()
{
    union REGS inregs, outregs;

    inregs.h.ah = CurrentVideoState;
    int86(BIOS_VIDEO, &inregs, &outregs);

    crt_mode = outregs.h.al;
    crt_cols = outregs.h.ah;
    crt_lins = 25;
    curpage = outregs.h.bh;

    inregs.h.ah = ReadCursorPosition;
    inregs.h.bh = curpage;

    int86(BIOS_VIDEO, &inregs, &outregs);

    if (outregs.h.dh > crt_lins) {
	outregs.h.dh = crt_lins;
    }
    if (outregs.h.dl > crt_cols) {
	outregs.h.dl = crt_cols;
    }
    inregs.h.dh = outregs.h.dh;
    inregs.h.dl = outregs.h.dl;
    inregs.h.bh = curpage;

    inregs.h.ah = SetCursorPosition;
    int86(BIOS_VIDEO, &inregs, &outregs);
}


static void
scrwrite(source, length, offset)
ScreenBuffer *source;
int
	length,
	offset;
{
    struct SREGS segregs;

    segread(&segregs);		/* read the current segment register */

    scrwait();
D 5
    movedata(segregs.ds, source, scrseg(), offset, length);
E 5
I 5
    movedata(segregs.ds, source, scrseg(), sizeof *source*offset,
						sizeof *source*length);
E 5
}

static void
scrsave(buffer)
ScreenBuffer *buffer;
{
    struct SREGS segregs;

    segread(&segregs);		/* read the current segment register */

    scrwait();
D 5
    movedata(scrseg(), 0, segregs.ds, buffer, scrseg(), 0, crt_cols*crt_lins*2);
E 5
I 5
    movedata(scrseg(), 0, segregs.ds, buffer, crt_cols*crt_lins*2);
E 5
}

static void
scrrest(buffer)
ScreenBuffer *buffer;
{
D 5
    scrwrite(buffer, 2*crt_cols*crt_lins, 0);
E 5
I 5
    scrwrite(buffer, crt_cols*crt_lins, 0);
E 5
}

static void
E 3
D 2
#endif	/* defined(NOT43) */
SlowScreen()
E 2
I 2
TryToSend()
E 2
{
D 2
    register int pointer;
    register int c;
    register int fieldattr;
    register int columnsleft;
E 2
I 2
D 5
#define	STANDOUT	0x0a
E 5
I 5
#define	STANDOUT	0x0a	/* Highlighted mode */
E 5
#define	NORMAL		0x02	/* Normal mode */
I 5
#define	NONDISPLAY	0x00	/* Don't display */
E 5
E 2

D 2
#   define  SetHighlightMode(p) { \
		if (!IsStartField(p) && IsHighlightedAttr(fieldattr)) { \
		    if (!inHighlightMode) { \
			inHighlightMode = 1; \
			standout(); \
		    } \
		} else { \
		    if (inHighlightMode) { \
			inHighlightMode = 0; \
			standend(); \
		    } \
		} \
	    }

#   define  DoCharacterAt(c,p) { \
		SetTerminal(p, c); \
		if (p != HighestScreen()) { \
		    c = TerminalCharacterAttr(disp_asc[c&0xff], p, \
								fieldattr); \
		    if (terminalCursorAddress != p) { \
			if (ERR == mvaddch(ScreenLine(p), \
						ScreenLineOffset(p), c)) {\
			    GoAway("mvaddch", p); \
			} \
		    } else { \
			if (ERR == addch(c)) {\
			    GoAway("addch", p); \
			} \
		    } \
		    terminalCursorAddress = ScreenInc(p); \
		} \
	    }


    /* run through screen, printing out non-null lines */

    /* There are two separate reasons for wanting to terminate this
     * loop early.  One is to respond to new input (either from
     * the terminal or from the network [host]).  For this reason,
     * we expect to see 'HaveInput' come true when new input comes in.
     *
     * The second reason is a bit more difficult (for me) to understand.
     * Basically, we don't want to get too far ahead of the characters that
     * appear on the screen.  Ideally, we would type out a few characters,
     * wait until they appeared on the screen, then type out a few more.
     * The reason for this is that the user, on seeing some characters
     * appear on the screen may then start to type something.  We would
     * like to look at what the user types at about the same 'time'
     * (measured by characters being sent to the terminal) that the
     * user types them.  For this reason, what we would like to do
     * is update a bit, then call curses to do a refresh, flush the
     * output to the terminal, then wait until the terminal data
     * has been sent.
     *
     * Note that curses is useful for, among other things, deciding whether
     * or not to send :ce: (clear to end of line), so we should call curses
     * at end of lines (beginning of next lines).
     *
     * The problems here are the following:  If we do lots of write(2)s,
     * we will be doing lots of context switches, thus lots of overhead
     * (which we have already).  Second, if we do a select to wait for
     * the output to drain, we have to contend with the fact that NOW
     * we are scheduled to run, but who knows what the scheduler will
     * decide when the output has caught up.
     */

    if (Highest == HighestScreen()) {
	Highest = ScreenDec(Highest);	/* else, while loop will never end */
    }
    if (Lowest < LowestScreen()) {
	Lowest = LowestScreen();	/* could be -1 in some cases with
					 * unformatted screens.
					 */
    }
    if (Highest >= (pointer = Lowest)) {
		/* if there is anything to do, do it.  We won't terminate
		 * the loop until we've gone at least to Highest.
		 */
	while ((pointer <= Highest) && !HaveInput) {

		/* point at the next place of disagreement */
	    pointer += (bunequal(Host+pointer, Terminal+pointer,
			(Highest-pointer+1)*sizeof Host[0])/sizeof Host[0]);

		/* how many characters to change until the end of the
		 * current line
		 */
	    columnsleft = NumberColumns - ScreenLineOffset(pointer);
		/*
		 * Make sure we are where we think we are.
		 */
	    move(ScreenLine(pointer), ScreenLineOffset(pointer));

		/* what is the field attribute of the current position */
	    fieldattr = FieldAttributes(WhereAttrByte(pointer));

	    if ((IsStartField(pointer) != TermIsStartField(pointer)) ||
		    (IsStartField(pointer) &&
			fieldattr != TermAttributes(pointer))) {

		int oldterm;

		oldterm = TermAttributes(pointer);
		if (IsStartField(pointer)) {
		    TermNewField(pointer, fieldattr);
		    SetTerminal(pointer, 0);
		} else {
		    TermDeleteField(pointer);
		}
		    /* We always do the first character in a divergent
		     * field, since otherwise the start of a field in
		     * the Host structure may leave a highlighted blank
		     * on the screen, and the start of a field in the
		     * Terminal structure may leave a non-highlighted
		     * something in the middle of a highlighted field
		     * on the screen.
		     */
		SetHighlightMode(pointer);
		c = GetHost(pointer);
		DoCharacterAt(c,pointer);		/* MACRO */

		if (NotVisuallyCompatibleAttributes
				(pointer, fieldattr, oldterm)) {
		    int j;

		    j = pointer;

		    pointer = ScreenInc(pointer);
		    if (!(--columnsleft)) {
			DoARefresh();
			EmptyTerminal();
			move(ScreenLine(pointer), 0);
			columnsleft = NumberColumns;
		    }
		    SetHighlightMode(pointer);	/* Turn on highlighting */
		    while (!IsStartField(pointer) &&
				!TermIsStartField(pointer)) {
			c = GetHost(pointer);
			DoCharacterAt(c,pointer);	/* MACRO */
			pointer = ScreenInc(pointer);
			if (!(--columnsleft)) {
			    DoARefresh();
			    EmptyTerminal();
			    move(ScreenLine(pointer), 0);
			    columnsleft = NumberColumns;
				/* We don't look at HaveInput here, since
				 * if we leave this loop before the end of
				 * the 3270 field, we could have pointer
				 * higher than Highest.  This would cause
				 * us to end the highest "while" loop,
				 * but we may, in fact, need to go around the
				 * screen once again.
				 */
			}
			/*		The loop needs to be protected
			 *	from the situation where there had been only
			 *	one field on the Terminal, and none on the Host.
			 *	In this case, we have just deleted our last
			 *	field.	Hence, the break.
			 */
			if (j == pointer) {
			    break;
			}
		    }
		    if (IsStartField(pointer) && !TermIsStartField(pointer)) {
			    /* Remember what the terminal looked like */
			TermNewField(pointer, oldterm);
			    /*
			     * The danger here is that the current position may
			     * be the start of a Host field.  If so, and the
			     * field is highlighted, and our terminal was
			     * highlighted, then we will leave a highlighted
			     * blank at this position.
			     */
			SetHighlightMode(pointer);
			c = GetHost(pointer);
			DoCharacterAt(c,pointer);
		    }
			/* We could be in the situation of needing to exit.
			 * This could happen if the current field wrapped around
			 * the end of the screen.
			 */
		    if (j > pointer) {
			break;
		    }
		} else {
		    c = GetHost(pointer);
			/* We always do the first character in a divergent
			 * field, since otherwise the start of a field in
			 * the Host structure may leave a highlighted blank
			 * on the screen, and the start of a field in the
			 * Terminal structure may leave a non-highlighted
			 * something in the middle of a highlighted field
			 * on the screen.
			 */
		    SetHighlightMode(pointer);
		    DoCharacterAt(c,pointer);
		}
	    } else {
		SetHighlightMode(pointer);
		/*
		 * The following will terminate at least when we get back
		 * to the original 'pointer' location (since we force
		 * things to be equal).
		 */
		while (((c = GetHost(pointer)) != GetTerminal(pointer)) &&
			!IsStartField(pointer) && !TermIsStartField(pointer)) {
		    DoCharacterAt(c, pointer);
		    pointer = ScreenInc(pointer);
		    if (!(--columnsleft)) {
			DoARefresh();
			EmptyTerminal();
			if (HaveInput) {	/* if input came in, take it */
			    break;
			}
			move(ScreenLine(pointer), 0);
			columnsleft = NumberColumns;
		    }
		}
	    }
	}
    }
    DoARefresh();
    Lowest = pointer;
    if (Lowest > Highest) {		/* if we finished input... */
	Lowest = HighestScreen()+1;
	Highest = LowestScreen()-1;
	terminalCursorAddress = CorrectTerminalCursor();
	if (ERR == move(ScreenLine(terminalCursorAddress),
			ScreenLineOffset(terminalCursorAddress))) {
	    GoAway("move", terminalCursorAddress);
	}
	DoARefresh();
	if (needToRing) {
	    StringToTerminal(bellSequence);
	    needToRing = 0;
	}
    }
    EmptyTerminal();			/* move data along */
    return;
}
#endif	/* defined(SLOWSCREEN) */

#if	defined(NOT43)
static int
#else	/* defined(NOT43) */
static void
#endif	/* defined(NOT43) */
FastScreen()
{
#if	defined(MSDOS)
#define	SaveCorner	0
#else	/* defined(MSDOS) */
#define	SaveCorner	1
#endif	/* defined(MSDOS) */

E 2
D 5
#define	DoAttribute(a) 	    if (IsHighlightedAttr(a)) { \
D 2
				standout(); \
E 2
I 2
				a = STANDOUT; \
E 2
			    } else { \
D 2
				standend(); \
E 2
I 2
				a = NORMAL; \
E 2
			    } \
			    if (IsNonDisplayAttr(a)) { \
				a = 0; 	/* zero == don't display */ \
			    } \
			    if (!FormattedScreen()) { \
				a = 1;	/* one ==> do display on unformatted */\
E 5
I 5
#define	DoAttribute(a) 	    \
			    if (screenIsFormatted) { \
				if (IsNonDisplayAttr(a)) { \
				    a = NONDISPLAY; 	/* don't display */ \
				} else if (IsHighlightedAttr(a)) { \
				    a = STANDOUT; \
				} else { \
				    a = NORMAL; \
				} \
			    } else  { \
				a = NORMAL;	/* do display on unformatted */\
E 5
			    }
    ScreenImage *p, *upper;
I 2
    ScreenBuffer *sp;
E 2
    int fieldattr;		/* spends most of its time == 0 or 1 */
I 5
    int screenIsFormatted = FormattedScreen();
E 5

/* OK.  We want to do this a quickly as possible.  So, we assume we
 * only need to go from Lowest to Highest.  However, if we find a
 * field in the middle, we do the whole screen.
 *
 * In particular, we separate out the two cases from the beginning.
 */
    if ((Highest != HighestScreen()) || (Lowest != LowestScreen())) {
D 5
	register int columnsleft;

E 5
D 2
	move(ScreenLine(Lowest), ScreenLineOffset(Lowest));
E 2
I 2
	sp = &Screen[Lowest];
E 2
	p = &Host[Lowest];
D 2
#if	!defined(MSDOS)
	if (Highest == HighestScreen()) {
	    Highest = ScreenDec(Highest);
	}
#endif	/* !defined(MSDOS) */
E 2
	upper = &Host[Highest];
	fieldattr = FieldAttributes(Lowest);
	DoAttribute(fieldattr);	/* Set standout, non-display status */
D 5
	columnsleft = NumberColumns-ScreenLineOffset(p-Host);
E 5

	while (p <= upper) {
	    if (IsStartFieldPointer(p)) {	/* New field? */
		Highest = HighestScreen();
		Lowest = LowestScreen();
D 2
		FastScreen();		/* Recurse */
E 2
I 2
		TryToSend();		/* Recurse */
E 2
		return;
	    } else if (fieldattr) {	/* Should we display? */
D 2
		addch(disp_asc[p->data]);	/* Display translated data */
E 2
I 2
D 5
		sp->data = disp_asc[p->data];	/* Display translated data */
		sp->attr = fieldattr;
E 5
I 5
				/* Display translated data */
		sp->data = disp_asc[GetHostPointer(p)];
E 5
E 2
	    } else {
D 2
		addch(' ');			/* Display a blank */
E 2
I 2
		sp->data = ' ';
D 5
		sp->attr = NORMAL;
E 5
E 2
	    }
D 5
			/* If the physical screen is larger than what we
			 * are using, we need to make sure that each line
			 * starts at the beginning of the line.  Otherwise,
			 * we will just string all the lines together.
			 */
E 5
I 5
	    sp->attr = fieldattr;
E 5
	    p++;
D 2
	    if (--columnsleft == 0) {
		int i = p-Host;

		move(ScreenLine(i), 0);
		columnsleft = NumberColumns;
	    }
E 2
I 2
	    sp++;
E 2
	}
    } else {		/* Going from Lowest to Highest */
D 2
	unsigned char tmpbuf[MAXNUMBERCOLUMNS+1];
	ScreenImage *End = &Host[ScreenSize]-1-SaveCorner;
	register unsigned char *tmp = tmpbuf, *tmpend = tmpbuf+NumberColumns;
E 2
I 2
	ScreenImage *End = &Host[ScreenSize]-1;
E 2

D 2
	*tmpend = 0;		/* terminate from the beginning */
	move(0,0);
E 2
I 2
	sp = Screen;
E 2
	p = Host;
	fieldattr = FieldAttributes(LowestScreen());
	DoAttribute(fieldattr);	/* Set standout, non-display status */

	while (p <= End) {
	    if (IsStartFieldPointer(p)) {	/* New field? */
D 2
		if (tmp != tmpbuf) {
		    *tmp++ = 0;			/* close out */
		    addstr(tmpbuf);
		    tmp = tmpbuf;
		    tmpend = tmpbuf + NumberColumns - ScreenLineOffset(p-Host);
		}
E 2
		fieldattr = FieldAttributesPointer(p);	/* Get attributes */
		DoAttribute(fieldattr);	/* Set standout, non-display */
I 5
	    }
	    if (fieldattr) {	/* Should we display? */
			    /* Display translated data */
		sp->data = disp_asc[GetHostPointer(p)];
E 5
D 2
		*tmp++ = ' ';
E 2
	    } else {
D 5
		if (fieldattr) {	/* Should we display? */
				/* Display translated data */
D 2
		    *tmp++ = disp_asc[p->data];
E 2
I 2
		    sp->data = disp_asc[p->data];
		    sp->attr = fieldattr;
E 2
		} else {
D 2
		    *tmp++ = ' ';
E 2
I 2
		    sp->data = ' ';
		    sp->attr = NORMAL;
E 2
		}
E 5
I 5
		sp->data = ' ';
E 5
	    }
D 5
			/* If the physical screen is larger than what we
			 * are using, we need to make sure that each line
			 * starts at the beginning of the line.  Otherwise,
			 * we will just string all the lines together.
			 */
E 5
I 5
	    sp->attr = fieldattr;
E 5
	    p++;
D 2
	    if (tmp == tmpend) {
		int i = p-Host;		/* Be sure the "p++" happened first! */

		*tmp++ = 0;
		addstr(tmpbuf);
		tmp = tmpbuf;
		move(ScreenLine(i), 0);
		tmpend = tmpbuf + NumberColumns;
	    }
E 2
I 2
	    sp++;
E 2
	}
D 2
	if (tmp != tmpbuf) {
	    *tmp++ = 0;
	    addstr(tmpbuf);
	    tmp = tmpbuf;
	}
E 2
    }
I 2
    terminalCursorAddress = CorrectTerminalCursor();
D 5
    scrwrite(Screen+Lowest, sizeof Screen[0]*(Highest-Lowest), Lowest);
E 5
I 5
    /*
     * We might be here just to update the cursor address.
     */
    if (Highest >= Lowest) {
	scrwrite(Screen+Lowest, (1+Highest-Lowest), Lowest);
    }
E 5
D 3
    VideoSetCursorPosition(ScreenLine(terminalCursorAddress),
E 3
I 3
    setcursor(ScreenLine(terminalCursorAddress),
E 3
		    ScreenLineOffset(terminalCursorAddress), 0);
E 2
    Lowest = HighestScreen()+1;
    Highest = LowestScreen()-1;
D 2
    terminalCursorAddress = CorrectTerminalCursor();
    if (ERR == move(ScreenLine(terminalCursorAddress),
		    ScreenLineOffset(terminalCursorAddress))) {
	GoAway("move", terminalCursorAddress);
    }
    DoARefresh();
E 2
    if (needToRing) {
D 2
	StringToTerminal(bellSequence);
E 2
I 2
	DataToTerminal("\7", 1);
E 2
	needToRing = 0;
    }
D 2
    EmptyTerminal();			/* move data along */
E 2
    return;
}
D 2


/* TryToSend - send data out to user's terminal */

#if	defined(NOT43)
int
#else	/* defined(NOT43) */
void
#endif	/* defined(NOT43) */
	(*TryToSend)() = FastScreen;
E 2

/* InitTerminal - called to initialize the screen, etc. */

void
InitTerminal()
{
D 2
#if defined(unix)
    struct sgttyb ourttyb;
    static int speeds[] = { 0, 50, 75, 110, 134, 150, 200, 300, 600, 1200, 1800,
		2400, 4800, 9600 };
#endif
    
E 2
    InitMapping();		/* Go do mapping file (MAP3270) first */
    if (!screenInitd) { 	/* not initialized */
D 2
#if	defined(unix)
	char KSEbuffer[2050];
	char *lotsofspace = KSEbuffer;
	extern int abort();
	extern char *tgetstr();
#endif	/* defined(unix) */

#if	defined(SLOWSCREEN)
	ClearArray(Terminal);
#endif	/* defined(SLOWSCREEN) */
E 2
I 2
D 4
	NumberLines = 24;	/* XXX */
	NumberColumns = 80;	/* XXX */
E 4
I 4
	MaxNumberLines = 24;	/* XXX */
	MaxNumberColumns = 80;	/* XXX */
E 4
	scrini();
D 3
	savescr();		/* Save the screen buffer away */
E 3
I 3
	scrsave(saveScreen);	/* Save the screen buffer away */
E 3
	ClearArray(Screen);
E 2
	terminalCursorAddress = SetBufferAddress(0,0);
D 2
#if defined(unix)
	signal(SIGHUP, abort);
#endif

	TryToSend = FastScreen;
#if defined(unix) && defined(SLOWSCREEN)
	ioctl(1, TIOCGETP, (char *) &ourttyb);
	if ((ourttyb.sg_ospeed < 0) || (ourttyb.sg_ospeed > B9600)) {
	    max_changes_before_poll = 1920;
	} else {
	    max_changes_before_poll = speeds[ourttyb.sg_ospeed]/10;
	    if (max_changes_before_poll < 40) {
		max_changes_before_poll = 40;
	    }
	    TryToSend = SlowScreen;
	    HaveInput = 1;		/* get signals going */
	}
#endif	/* defined(unix) && defined(SLOWSCREEN) */
	setcommandmode();
	/*
	 * By now, initscr() (in curses) has been called (from telnet.c),
	 * and the screen has been initialized.
	 */
#if defined(unix)
	nonl();
			/* the problem is that curses catches SIGTSTP to
			 * be nice, but it messes us up.
			 */
	signal(SIGTSTP, SIG_DFL);
	if ((KS = tgetstr("ks", &lotsofspace)) != 0) {
	    KS = strsave(KS);
	    StringToTerminal(KS);
	}
	if ((KE = tgetstr("ke", &lotsofspace)) != 0) {
	    KE = strsave(KE);
	}
	if (tgetstr("md", &lotsofspace) && tgetstr("me", &lotsofspace)) {
	   SO = strsave(tgetstr("md", &lotsofspace));
	   SE = strsave(tgetstr("me", &lotsofspace));
	}
#endif
	DoARefresh();
	setconnmode();
	if (VB && *VB) {
	    bellSequence = VB;		/* use visual bell */
	}
E 2
	screenInitd = 1;
	screenStopped = 0;		/* Not stopped */
    }
D 9
    Initialized = 1;
E 9
}


/* StopScreen - called when we are going away... */

void
StopScreen(doNewLine)
int doNewLine;
{
    if (screenInitd && !screenStopped) {
D 2
	move(NumberLines-1, 1);
	standend();
#if	defined(SLOWSCREEN)
	inHighlightMode = 0;
#endif	/* defined(SLOWSCREEN) */
	DoARefresh();
	setcommandmode();
	endwin();
	setconnmode();
#if	defined(unix)
	if (KE) {
	    StringToTerminal(KE);
	}
#endif	/* defined(unix) */
	if (doNewLine) {
	    StringToTerminal("\r\n");
	}
	EmptyTerminal();
	screenStopped = 1;		/* This is stopped */
E 2
I 2
D 3
	scrrest();
	VideoSetCursorPosition(NumberLines-1, NumberColumns-1, 0);
E 3
I 3
	scrrest(saveScreen);
D 7
	setcursor(NumberLines-1, NumberColumns-1, 0);
E 7
I 7
	setcursor(NumberLines-1, 1, 0);
	if (doNewLine) {
	    StringToTerminal("\r\n");
	}
	EmptyTerminal();
	screenStopped = 1;
E 7
E 3
E 2
    }
}


/* RefreshScreen - called to cause the screen to be refreshed */

void
RefreshScreen()
{
D 2
    clearok(curscr, TRUE);
    (*TryToSend)();
E 2
I 2
    Highest = HighestScreen();
    Lowest = LowestScreen();
    TryToSend();
E 2
}


/* ConnectScreen - called to reconnect to the screen */

void
ConnectScreen()
{
    if (screenInitd) {
D 2
#if	defined(unix)
	if (KS) {
	    StringToTerminal(KS);
	}
#endif	/* defined(unix) */
E 2
	RefreshScreen();
D 2
	(*TryToSend)();
E 2
	screenStopped = 0;
    }
}

/* LocalClearScreen() - clear the whole ball of wax, cheaply */

void
LocalClearScreen()
{
D 2
    outputPurge();		/* flush all data to terminal */
    clear();			/* clear in curses */
#if	defined(SLOWSCREEN)
    ClearArray(Terminal);
#endif	/* defined(SLOWSCREEN) */
E 2
    Clear3270();
D 2
    Lowest = HighestScreen()+1; /* everything in sync... */
    Highest = LowestScreen()+1;
E 2
I 2
    Lowest = LowestScreen(); /* everything in sync... */
    Highest = HighestScreen();
    TryToSend();
E 2
}
I 2

/*
 * Implement the bell/error message function.
 */
E 2

I 2
int
	bellwinup = 0;		/* If != 0, length of bell message */
static int
D 11
	bellpos0 = 0;		/* Where error message goes */
E 11
I 11
	bell_len = 0;		/* Length of error message */
E 11
E 2

I 2
D 11
static char	bellstring[100];/* Where message goes */
E 11

D 11
#define	BELL_SPACES	2	/* 2 spaces between border and bell */

#define	BELL_HIGH_LOW(h,l) { \
	    h = bellpos0+2*NumberColumns+bellwinup+BELL_SPACES*2; \
	    l = bellpos0; \
	}

E 11
E 2
void
BellOff()
{
I 11
    ScreenBuffer a[100];
    int i;

E 11
    if (bellwinup) {
D 2
	delwin(bellwin);
	bellwin = 0;
	bellwinup = 0;
	Lowest = MIN(Lowest, LINES/2);
	Highest = MAX(Highest, (LINES/2)+3);
#if	defined(SLOWSCREEN)
	memset(Terminal+LINES/2, 0, (sizeof Terminal[0])*(3*COLS));
#endif	/* defined(SLOWSCREEN) */
	touchwin(stdscr);
	DoARefresh();
E 2
I 2
D 11
	BELL_HIGH_LOW(Highest,Lowest);
	TryToSend();
E 11
I 11
	unsigned char blank = ' ';

	for (i = 0; i < bell_len; i++) {
	    a[i].attr = NORMAL;
	    a[i].data = ' ';
	}
E 11
E 2
    }
I 11
    scrwrite(a, bell_len, 24*80);		/* XXX */
E 11
}


void
RingBell(s)
char *s;
{
    needToRing = 1;
    if (s) {
D 11
	int len = strlen(s);
E 11
I 11
	int i;
	ScreenBuffer bellstring[100];
E 11

D 2
	if (len > COLS-2) {
	    len = COLS-2;
E 2
I 2
D 11
	if (len > sizeof bellstring-1) {
E 11
I 11
	bell_len = strlen(s);
	bellwinup = 1;
	if (bell_len > sizeof bellstring-1) {
E 11
	    OurExitString(stderr, "Bell string too long.", 1);
E 2
	}
D 2
	if ((bellwin = newwin(3, len+2, LINES/2, 0)) == NULL) {
	    OurExitString(stderr, "Error from newwin in RingBell", 1);
	}
	werase(bellwin);
	wstandout(bellwin);
	box(bellwin, '|', '-');
	if (wmove(bellwin, 1, 1) == ERR) {
	    OurExitString(stderr, "Error from wmove in RingBell", 1);
	}
	while (len--) {
	    if (waddch(bellwin, *s++) == ERR) {
		OurExitString(stderr, "Error from waddch in RingBell", 1);
	    }
	}
	wstandend(bellwin);
	if (wrefresh(bellwin) == ERR) {
	    OurExitString(stderr, "Error from wrefresh in RingBell", 1);
	}
	bellwinup = 1;
E 2
I 2
D 11
	memcpy(bellstring, s, len+1);
	BELL_HIGH_LOW(Highest,Lowest);
	TryToSend();
E 11
I 11
	for (i = 0; i < bell_len; i++) {
	    bellstring[i].attr = STANDOUT;
	    bellstring[i].data = s[i];
	}
	scrwrite(bellstring, bell_len, 24*80);		/* XXX */
E 11
E 2
    }
}

I 2
/*
 * Update the OIA area.
 */
E 2

I 2
void
ScreenOIA(oia)
OIA *oia;
{
}


E 2
/* returns a 1 if no more output available (so, go ahead and block),
    or a 0 if there is more output available (so, just poll the other
    sources/destinations, don't block).
 */

int
DoTerminalOutput()
{
	/* called just before a select to conserve IO to terminal */
D 9
    if (!Initialized) {
E 9
I 9
    if (!(screenInitd||screenStopped)) {
E 9
	return 1;		/* No output if not initialized */
    }
    if ((Lowest <= Highest) || needToRing ||
			(terminalCursorAddress != CorrectTerminalCursor())) {
D 2
	(*TryToSend)();
E 2
I 2
	TryToSend();
E 2
    }
    if (Lowest > Highest) {
	return 1;		/* no more output now */
    } else {
	return 0;		/* more output for future */
    }
}

/*
 * The following are defined to handle transparent data.
 */

void
TransStop()
{
D 2
#if	defined(unix)
    if (tcflag == 0) {
       tcflag = -1;
       (void) signal(SIGCHLD, SIG_DFL);
    } else if (tcflag > 0) {
       setcommandmode();
       (void) close(tin);
       (void) close(tout);
       tin = savefd[0];
       tout = savefd[1];
       setconnmode();
       tcflag = -1;
       (void) signal(SIGCHLD, SIG_DFL);
    }
#endif	/* defined(unix) */
E 2
    RefreshScreen();
}

void
D 12
TransOut(buffer, count)
E 12
I 12
TransOut(buffer, count, kind, control)
E 12
unsigned char	*buffer;
int		count;
I 12
int		kind;		/* 0 or 5 */
int		control;	/* To see if we are done */
E 12
{
I 12
    char *ptr;
E 12
D 2
#if	defined(unix)
    extern char *transcom;
    int inpipefd[2], outpipefd[2], savemode;
    void aborttc();
#endif	/* defined(unix) */
E 2

    while (DoTerminalOutput() == 0) {
D 2
#if defined(unix)
	HaveInput = 0;
#endif /* defined(unix) */
E 2
I 2
	;
E 2
    }
I 12
    for (ptr = buffer; ptr < buffer+count; ptr++) {
	*ptr &= 0x7f;		/* Turn off parity bit */
    }
E 12
D 2
#if	defined(unix)
    if (transcom && tcflag == -1) {
       while (1) {			  /* go thru once */
	     if (pipe(outpipefd) < 0) {
		break;
	     }
	     if (pipe(inpipefd) < 0) {
		break;
	     }
	     if ((tcflag = fork()) == 0) {
		(void) close(outpipefd[1]);
		(void) close(0);
		if (dup(outpipefd[0]) < 0) {
		   exit(1);
		}
		(void) close(outpipefd[0]);
		(void) close(inpipefd[0]);
		(void) close(1);
		if (dup(inpipefd[1]) < 0) {
		   exit(1);
		}
		(void) close(inpipefd[1]);
		if (execl("/bin/csh", "csh", "-c", transcom, (char *) 0)) {
		    exit(1);
		}
	     }
	     (void) close(inpipefd[1]);
	     (void) close(outpipefd[0]);
	     savefd[0] = tin;
	     savefd[1] = tout;
	     setcommandmode();
	     tin = inpipefd[0];
	     tout = outpipefd[1];
	     (void) signal(SIGCHLD, aborttc);
	     setconnmode();
	     tcflag = 1;
	     break;
       }
       if (tcflag < 1) {
	  tcflag = 0;
       }
    }
#endif	/* defined(unix) */
E 2
    (void) DataToTerminal(buffer, count);
I 12
    if (control && (kind == 0)) {		/* Send in AID byte */
	SendToIBM();
    } else {
	TransInput(1, kind);			/* Go get some data */
    }
E 12
}
I 2

/*
 * init_screen()
 *
 * Initialize variables used by screen.
 */
E 2

D 2

#if	defined(unix)
static void
aborttc()
E 2
I 2
void
init_screen()
E 2
{
D 2
	int savemode;

	setcommandmode();
	(void) close(tin);
	(void) close(tout);
	tin = savefd[0];
	tout = savefd[1];
	setconnmode();
	tcflag = 0;
E 2
I 2
    bellwinup = 0;
E 2
}
D 2
#endif	/* defined(unix) */
E 2
I 2


E 2
E 1
