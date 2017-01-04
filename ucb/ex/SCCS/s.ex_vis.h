h38148
s 00038/00020/00254
d D 7.6 03/04/13 15:19:24 msokolov 15 14
c 8-bit ex
e
s 00003/00003/00271
d D 7.5 87/03/09 12:46:26 conrad 14 13
c make ex/vi work on vms
e
s 00008/00002/00266
d D 7.4 85/05/31 16:00:19 dist 13 11
c Add copyright
e
s 00008/00002/00265
d D 5.1.1.1 85/05/31 11:54:05 dist 12 7
c Add copyright
e
s 00064/00064/00204
d D 7.3 81/09/03 11:45:58 mark 11 10
c updates for Unix/370 and ins/del line on vt100
e
s 00063/00063/00205
d D 7.2 81/07/26 20:05:07 mark 10 9
c fixes for 3b
e
s 00068/00067/00200
d D 7.1 81/07/08 22:33:20 mark 9 8
c release 3.7 - a few bug fixes and a few new features.
e
s 00000/00000/00267
d D 6.1 80/10/19 01:22:11 mark 8 7
c preliminary release 3.6 10/18/80
e
s 00000/00000/00267
d D 5.1 80/08/20 16:13:46 mark 7 6
c Release 3.5, August 20, 1980
e
s 00001/00001/00266
d D 4.3 80/08/03 23:27:15 mark 6 5
c fixed typo that matters on string table C compiler
e
s 00002/00001/00265
d D 4.2 80/08/01 20:42:47 mark 5 4
c Bill added more buffers, and I put in sccs.
e
s 00015/00001/00251
d D 4.1 80/08/01 00:17:32 mark 4 3
c release 3.4, June 24, 1980
e
s 00000/00000/00252
d D 3.1 80/07/31 23:41:27 mark 3 2
c release 3.3, Feb 2, 1980
e
s 00004/00004/00248
d D 2.1 80/07/31 23:20:38 mark 2 1
c release 3.2, Jan 4, 1980
e
s 00252/00000/00000
d D 1.1 80/07/31 23:00:45 mark 1 0
c date and time created 80/07/31 23:00:45 by mark
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
D 12
/* Copyright (c) 1980 Regents of the University of California */
/* sccs id:	%W% %G%  */
E 12
I 12
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */

E 12
E 9
I 9
D 13
/* Copyright (c) 1981 Regents of the University of California */
D 11
/* sccs id:	%W%	%G%  */
E 11
I 11
/* sccs id:	@(#)ex_vis.h	7.1	7/8/81  */
E 13
I 13
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */

E 13
E 11
E 9
E 5
/*
D 4
 * Ex version 2
E 4
I 4
 * Ex version 3
E 4
 * Mark Horton, UCB
 * Bill Joy UCB
 *
 * Open and visual mode definitions.
 * 
 * There are actually 4 major states in open/visual modes.  These
 * are visual, crt open (where the cursor can move about the screen and
 * the screen can scroll and be erased), one line open (on dumb glass-crt's
 * like the adm3), and hardcopy open (for everything else).
 *
 * The basic state is given by bastate, and the current state by state,
 * since we can be in pseudo-hardcopy mode if we are on an adm3 and the
 * line is longer than 80.
 */

D 9
short	bastate;
short	state;
E 9
I 9
D 10
extern short	bastate;
extern short	state;
E 10
I 10
D 11
var short	bastate;
var short	state;
E 11
I 11
var	short	bastate;
var	short	state;
E 11
E 10
E 9

#define	VISUAL		0
#define	CRTOPEN		1
#define	ONEOPEN		2
#define	HARDOPEN	3

/*
 * The screen in visual and crtopen is of varying size; the basic
 * window has top basWTOP and basWLINES lines are thereby implied.
 * The current window (which may have grown from the basic size)
 * has top WTOP and WLINES lines.  The top line of the window is WTOP,
 * and the bottom line WBOT.  The line WECHO is used for messages,
 * search strings and the like.  If WBOT==WECHO then we are in ONEOPEN
 * or HARDOPEN and there is no way back to the line we were on if we
 * go to WECHO (i.e. we will have to scroll before we go there, and
 * we can't get back).  There are WCOLS columns per line.
 * If WBOT!=WECHO then WECHO will be the last line on the screen
 * and WBOT is the line before it.
 */
D 9
short	basWTOP;
short	basWLINES;
short	WTOP;
short	WBOT;
short	WLINES;
short	WCOLS;
short	WECHO;
E 9
I 9
D 10
extern short	basWTOP;
extern short	basWLINES;
extern short	WTOP;
extern short	WBOT;
extern short	WLINES;
extern short	WCOLS;
extern short	WECHO;
E 10
I 10
D 11
var short	basWTOP;
var short	basWLINES;
var short	WTOP;
var short	WBOT;
var short	WLINES;
var short	WCOLS;
var short	WECHO;
E 11
I 11
var	short	basWTOP;
var	short	basWLINES;
var	short	WTOP;
var	short	WBOT;
var	short	WLINES;
var	short	WCOLS;
var	short	WECHO;
E 11
E 10
E 9

/*
 * When we are dealing with the echo area we consider the window
 * to be "split" and set the variable splitw.  Otherwise, moving
 * off the bottom of the screen into WECHO causes a screen rollup.
 */
D 9
bool	splitw;
E 9
I 9
D 10
extern bool	splitw;
E 10
I 10
D 11
var bool	splitw;
E 11
I 11
var	bool	splitw;
E 11
E 10
E 9

/*
 * Information about each line currently on the screen includes
 * the y coordinate associated with the line, the printing depth
 * of the line (0 indicates unknown), and a mask which indicates
 * whether the line is "unclean", i.e. whether we should check
 * to make sure the line is displayed correctly at the next
 * appropriate juncture.
 */
struct vlinfo {
D 9
	char	vliny;		/* Y coordinate */
	char	vdepth;		/* Depth of displayed line */
E 9
I 9
	short	vliny;		/* Y coordinate */	/* mjm: was char */
	short	vdepth;		/* Depth of displayed line */ /*mjm: was char */
E 9
	short	vflags;		/* Is line potentially dirty ? */
D 9
} vlinfo[TUBELINES + 2];
E 9
I 9
};
D 10
extern struct vlinfo  vlinfo[TUBELINES + 2];
E 10
I 10
D 11
var struct vlinfo  vlinfo[TUBELINES + 2];
E 11
I 11
var	struct vlinfo  vlinfo[TUBELINES + 2];
E 11
E 10
E 9

#define	DEPTH(c)	(vlinfo[c].vdepth)
#define	LINE(c)		(vlinfo[c].vliny)
#define	FLAGS(c)	(vlinfo[c].vflags)

#define	VDIRT	1

/*
 * Hacks to copy vlinfo structures around
 */
#ifdef	V6
	/* Kludge to make up for no structure assignment */
	struct {
		long	longi;
	};
#	define	vlcopy(i, j)	i.longi = j.longi
#else
#	define	vlcopy(i, j)	i = j;
#endif

/*
 * The current line on the screen is represented by vcline.
 * There are vcnt lines on the screen, the last being "vcnt - 1".
 * Vcline is intimately tied to the current value of dot,
 * and when command mode is used as a subroutine fancy footwork occurs.
 */
D 9
short	vcline;
short	vcnt;
E 9
I 9
D 10
extern short	vcline;
extern short	vcnt;
E 10
I 10
D 11
var short	vcline;
var short	vcnt;
E 11
I 11
var	short	vcline;
var	short	vcnt;
E 11
E 10
E 9

/*
 * To allow many optimizations on output, an exact image of the terminal
 * screen is maintained in the space addressed by vtube0.  The vtube
 * array indexes this space as lines, and is shuffled on scrolls, insert+delete
 * lines and the like rather than (more expensively) shuffling the screen
 * data itself.  It is also rearranged during insert mode across line
 * boundaries to make incore work easier.
 */
D 9
char	*vtube[TUBELINES];
char	*vtube0;
E 9
I 9
D 10
extern char	*vtube[TUBELINES];
extern char	*vtube0;
E 10
I 10
D 11
var char	*vtube[TUBELINES];
var char	*vtube0;
E 11
I 11
D 15
var	char	*vtube[TUBELINES];
var	char	*vtube0;
E 15
I 15
var	u_char	*vtube[TUBELINES];
var	u_char	*vtube0;
E 15
E 11
E 10
E 9

/*
I 15
 * We need to represent "tab spaces" and "tab blanks" in vtube. We use the
 * following C1 chars for this purpose. It is not a problem that they coincide
 * with valid C1 chars that we allow in edited text, as the latter will never
 * be sent to the tube as they are, they will be ~X on the tube.
 */
#define	TABSPC	0200
#define	TABLANK	0201	/* formerly meta-space 0240 */

/*
E 15
 * The current cursor position within the current line is kept in
 * cursor.  The current line is kept in linebuf.  During insertions
 * we use the auxiliary array genbuf as scratch area.
 * The cursor wcursor and wdot are used in operations within/spanning
 * lines to mark the other end of the affected area, or the target
 * for a motion.
 */
D 9
char	*cursor;
char	*wcursor;
line	*wdot;
E 9
I 9
D 10
extern char	*cursor;
extern char	*wcursor;
extern line	*wdot;
E 10
I 10
D 11
var char	*cursor;
var char	*wcursor;
var line	*wdot;
E 11
I 11
D 15
var	char	*cursor;
var	char	*wcursor;
E 15
I 15
var	u_char	*cursor;
var	u_char	*wcursor;
E 15
var	line	*wdot;
E 11
E 10
E 9

/*
 * Undo information is saved in a LBSIZE buffer at "vutmp" for changes
 * within the current line, or as for command mode for multi-line changes
 * or changes on lines no longer the current line.
 * The change kind "VCAPU" is used immediately after a U undo to prevent
 * two successive U undo's from destroying the previous state.
 */
#define	VNONE	0
#define	VCHNG	1
#define	VMANY	2
#define	VCAPU	3
#define	VMCHNG	4
#define	VMANYINS 5

D 9
short	vundkind;	/* Which kind of undo - from above */
char	*vutmp;		/* Prev line image when "VCHNG" */
E 9
I 9
D 10
extern short	vundkind;	/* Which kind of undo - from above */
extern char	*vutmp;		/* Prev line image when "VCHNG" */
E 10
I 10
D 11
var short	vundkind;	/* Which kind of undo - from above */
var char	*vutmp;		/* Prev line image when "VCHNG" */
E 11
I 11
var	short	vundkind;	/* Which kind of undo - from above */
D 15
var	char	*vutmp;		/* Prev line image when "VCHNG" */
E 15
I 15
var	u_char	*vutmp;		/* Prev line image when "VCHNG" */
E 15
E 11
E 10
E 9
I 4

/*
 * State information for undoing of macros.  The basic idea is that
 * if the macro does only 1 change or even none, we don't treat it
 * specially.  If it does 2 or more changes we want to be able to
 * undo it as a unit.  We remember how many changes have been made
 * within the current macro.  (Remember macros can be nested.)
 */
#define VC_NOTINMAC	0	/* Not in a macro */
#define VC_NOCHANGE	1	/* In a macro, no changes so far */
D 6
#define VC_ONECHANCE	2	/* In a macro, one change so far */
E 6
I 6
#define VC_ONECHANGE	2	/* In a macro, one change so far */
E 6
#define VC_MANYCHANGE	3	/* In a macro, at least 2 changes so far */

D 9
short	vch_mac;	/* Change state - one of the above */
E 9
I 9
D 10
extern short	vch_mac;	/* Change state - one of the above */
E 10
I 10
D 11
var short	vch_mac;	/* Change state - one of the above */
E 11
I 11
var	short	vch_mac;	/* Change state - one of the above */
E 11
E 10
E 9
E 4

/*
 * For U undo's the line is grabbed by "vmove" after it first appears
 * on that line.  The "vUNDdot" which specifies which line has been
 * saved is selectively cleared when changes involving other lines
 * are made, i.e. after a 'J' join.  This is because a 'JU' would
 * lose completely the text of the line just joined on.
 */
D 9
char	*vUNDcurs;	/* Cursor just before 'U' */
line	*vUNDdot;	/* The line address of line saved in vUNDsav */
line	vUNDsav;	/* Grabbed initial "*dot" */
E 9
I 9
D 10
extern char	*vUNDcurs;	/* Cursor just before 'U' */
extern line	*vUNDdot;	/* The line address of line saved in vUNDsav */
extern line	vUNDsav;	/* Grabbed initial "*dot" */
E 10
I 10
D 11
var char	*vUNDcurs;	/* Cursor just before 'U' */
var line	*vUNDdot;	/* The line address of line saved in vUNDsav */
var line	vUNDsav;	/* Grabbed initial "*dot" */
E 11
I 11
D 15
var	char	*vUNDcurs;	/* Cursor just before 'U' */
E 15
I 15
var	u_char	*vUNDcurs;	/* Cursor just before 'U' */
E 15
var	line	*vUNDdot;	/* The line address of line saved in vUNDsav */
var	line	vUNDsav;	/* Grabbed initial "*dot" */
E 11
E 10
E 9

#define	killU()		vUNDdot = NOLINE

/*
 * There are a number of cases where special behaviour is needed
 * from deeply nested routines.  This is accomplished by setting
 * the bits of hold, which acts to change the state of the general
 * visual editing behaviour in specific ways.
 *
 * HOLDAT prevents the clreol (clear to end of line) routines from
 * putting out @'s or ~'s on empty lines.
 *
 * HOLDDOL prevents the reopen routine from putting a '$' at the
 * end of a reopened line in list mode (for hardcopy mode, e.g.).
 *
 * HOLDROL prevents spurious blank lines when scrolling in hardcopy
 * open mode.
 *
 * HOLDQIK prevents the fake insert mode during repeated commands.
 *
 * HOLDPUPD prevents updating of the physical screen image when
 * mucking around while in insert mode.
 *
 * HOLDECH prevents clearing of the echo area while rolling the screen
 * backwards (e.g.) in deference to the clearing of the area at the
 * end of the scroll (1 time instead of n times).  The fact that this
 * is actually needed is recorded in heldech, which says that a clear
 * of the echo area was actually held off.
 */
D 9
short	hold;
short	holdupd;		/* Hold off update when echo line is too long */
E 9
I 9
D 10
extern short	hold;
extern short	holdupd;	/* Hold off update when echo line is too long */
E 10
I 10
D 11
var short	hold;
var short	holdupd;	/* Hold off update when echo line is too long */
E 11
I 11
var	short	hold;
var	short	holdupd;	/* Hold off update when echo line is too long */
E 11
E 10
E 9

#define	HOLDAT		1
#define	HOLDDOL		2
#define	HOLDROL		4
#define	HOLDQIK		8
#define	HOLDPUPD	16
#define	HOLDECH		32
#define HOLDWIG		64

/*
 * Miscellaneous variables
 */
D 9
short	CDCNT;			/* Count of ^D's in insert on this line */
char	DEL[VBSIZE];		/* Last deleted text */
bool	HADUP;			/* This insert line started with ^ then ^D */
bool	HADZERO;		/* This insert line started with 0 then ^D */
char	INS[VBSIZE];		/* Last inserted text */
D 2
short	Vlines;			/* Number of file lines "before" vi command */
short	Xcnt;			/* External variable holding last cmd's count */
E 2
I 2
int	Vlines;			/* Number of file lines "before" vi command */
int	Xcnt;			/* External variable holding last cmd's count */
E 2
bool	Xhadcnt;		/* Last command had explicit count? */
short	ZERO;
short	dir;			/* Direction for search (+1 or -1) */
short	doomed;			/* Disply chars right of cursor to be killed */
bool	gobblebl;		/* Wrapmargin space generated nl, eat a space */
bool	hadcnt;			/* (Almost) internal to vmain() */
bool	heldech;		/* We owe a clear of echo area */
bool	insmode;		/* Are in character insert mode */
char	lastcmd[5];		/* Chars in last command */
D 2
short	lastcnt;		/* Count for last command */
E 2
I 2
int	lastcnt;		/* Count for last command */
E 2
char	*lastcp;		/* Save current command here to repeat */
bool	lasthad;		/* Last command had a count? */
short	lastvgk;		/* Previous input key, if not from keyboard */
short	lastreg;		/* Register with last command */
char	*ncols['z'-'a'+2];	/* Cursor positions of marks */
char	*notenam;		/* Name to be noted with change count */
char	*notesgn;		/* Change count from last command */
char	op;			/* Operation of current command */
short	Peekkey;		/* Peek ahead key */
bool	rubble;			/* Line is filthy (in hardcopy open), redraw! */
D 2
short	vSCROLL;		/* Number lines to scroll on ^D/^U */
E 2
I 2
int	vSCROLL;		/* Number lines to scroll on ^D/^U */
E 2
char	*vglobp;		/* Untyped input (e.g. repeat insert text) */
char	vmacbuf[VBSIZE];	/* Text of visual macro, hence nonnestable */
char	*vmacp;			/* Like vglobp but for visual macros */
char	*vmcurs;		/* Cursor for restore after undo d), e.g. */
short	vmovcol;		/* Column to try to keep on arrow keys */
bool	vmoving;		/* Are trying to keep vmovcol */
char	vreg;			/* Register for this command */
short	wdkind;			/* Liberal/conservative words? */
char	workcmd[5];		/* Temporary for lastcmd */
E 9
I 9
D 10
extern short	CDCNT;		/* Count of ^D's in insert on this line */
extern char	DEL[VBSIZE];	/* Last deleted text */
extern bool	HADUP;		/* This insert line started with ^ then ^D */
extern bool	HADZERO;	/* This insert line started with 0 then ^D */
extern char	INS[VBSIZE];	/* Last inserted text */
extern int	Vlines;		/* Number of file lines "before" vi command */
extern int	Xcnt;		/* External variable holding last cmd's count */
extern bool	Xhadcnt;	/* Last command had explicit count? */
extern short	ZERO;
extern short	dir;		/* Direction for search (+1 or -1) */
extern short	doomed;		/* Disply chars right of cursor to be killed */
extern bool	gobblebl;	/* Wrapmargin space generated nl, eat a space */
extern bool	hadcnt;		/* (Almost) internal to vmain() */
extern bool	heldech;	/* We owe a clear of echo area */
extern bool	insmode;	/* Are in character insert mode */
extern char	lastcmd[5];	/* Chars in last command */
extern int	lastcnt;	/* Count for last command */
extern char	*lastcp;	/* Save current command here to repeat */
extern bool	lasthad;	/* Last command had a count? */
extern short	lastvgk;	/* Previous input key, if not from keyboard */
extern short	lastreg;	/* Register with last command */
extern char	*ncols['z'-'a'+2];	/* Cursor positions of marks */
extern char	*notenam;	/* Name to be noted with change count */
extern char	*notesgn;	/* Change count from last command */
extern char	op;		/* Operation of current command */
extern short	Peekkey;	/* Peek ahead key */
extern bool	rubble;		/* Line is filthy (in hardcopy open), redraw! */
extern int	vSCROLL;	/* Number lines to scroll on ^D/^U */
extern char	*vglobp;	/* Untyped input (e.g. repeat insert text) */
extern char	vmacbuf[VBSIZE];   /* Text of visual macro, hence nonnestable */
extern char	*vmacp;		/* Like vglobp but for visual macros */
extern char	*vmcurs;	/* Cursor for restore after undo d), e.g. */
extern short	vmovcol;	/* Column to try to keep on arrow keys */
extern bool	vmoving;	/* Are trying to keep vmovcol */
extern short	vreg;		/* Reg for this command */   /* mjm: was char */
extern short	wdkind;		/* Liberal/conservative words? */
extern char	workcmd[5];	/* Temporary for lastcmd */
E 10
I 10
D 11
var short	CDCNT;		/* Count of ^D's in insert on this line */
var char	DEL[VBSIZE];	/* Last deleted text */
var bool	HADUP;		/* This insert line started with ^ then ^D */
var bool	HADZERO;	/* This insert line started with 0 then ^D */
var char	INS[VBSIZE];	/* Last inserted text */
var int	Vlines;		/* Number of file lines "before" vi command */
var int	Xcnt;		/* External variable holding last cmd's count */
var bool	Xhadcnt;	/* Last command had explicit count? */
var short	ZERO;
var short	dir;		/* Direction for search (+1 or -1) */
var short	doomed;		/* Disply chars right of cursor to be killed */
var bool	gobblebl;	/* Wrapmargin space generated nl, eat a space */
var bool	hadcnt;		/* (Almost) internal to vmain() */
var bool	heldech;	/* We owe a clear of echo area */
var bool	insmode;	/* Are in character insert mode */
var char	lastcmd[5];	/* Chars in last command */
var int	lastcnt;	/* Count for last command */
var char	*lastcp;	/* Save current command here to repeat */
var bool	lasthad;	/* Last command had a count? */
var short	lastvgk;	/* Previous input key, if not from keyboard */
var short	lastreg;	/* Register with last command */
var char	*ncols['z'-'a'+2];	/* Cursor positions of marks */
var char	*notenam;	/* Name to be noted with change count */
var char	*notesgn;	/* Change count from last command */
var char	op;		/* Operation of current command */
var short	Peekkey;	/* Peek ahead key */
var bool	rubble;		/* Line is filthy (in hardcopy open), redraw! */
var int	vSCROLL;	/* Number lines to scroll on ^D/^U */
var char	*vglobp;	/* Untyped input (e.g. repeat insert text) */
var char	vmacbuf[VBSIZE];   /* Text of visual macro, hence nonnestable */
var char	*vmacp;		/* Like vglobp but for visual macros */
var char	*vmcurs;	/* Cursor for restore after undo d), e.g. */
var short	vmovcol;	/* Column to try to keep on arrow keys */
var bool	vmoving;	/* Are trying to keep vmovcol */
var short	vreg;		/* Reg for this command */   /* mjm: was char */
var short	wdkind;		/* Liberal/conservative words? */
var char	workcmd[5];	/* Temporary for lastcmd */
E 11
I 11
var	short	CDCNT;		/* Count of ^D's in insert on this line */
D 15
var	char	DEL[VBSIZE];	/* Last deleted text */
E 15
I 15
var	u_char	DEL[VBSIZE];	/* Last deleted text */
E 15
var	bool	HADUP;		/* This insert line started with ^ then ^D */
var	bool	HADZERO;	/* This insert line started with 0 then ^D */
D 15
var	char	INS[VBSIZE];	/* Last inserted text */
E 15
I 15
var	u_char	INS[VBSIZE];	/* Last inserted text */
E 15
var	int	Vlines;		/* Number of file lines "before" vi command */
var	int	Xcnt;		/* External variable holding last cmd's count */
var	bool	Xhadcnt;	/* Last command had explicit count? */
D 14
var	short	ZERO;
E 14
I 14
var	short	ex_ZERO;
E 14
var	short	dir;		/* Direction for search (+1 or -1) */
var	short	doomed;		/* Disply chars right of cursor to be killed */
var	bool	gobblebl;	/* Wrapmargin space generated nl, eat a space */
var	bool	hadcnt;		/* (Almost) internal to vmain() */
var	bool	heldech;	/* We owe a clear of echo area */
var	bool	insmode;	/* Are in character insert mode */
D 15
var	char	lastcmd[5];	/* Chars in last command */
E 15
I 15
var	u_char	lastcmd[5];	/* Chars in last command */
E 15
var	int	lastcnt;	/* Count for last command */
D 15
var	char	*lastcp;	/* Save current command here to repeat */
E 15
I 15
var	u_char	*lastcp;	/* Save current command here to repeat */
E 15
var	bool	lasthad;	/* Last command had a count? */
var	short	lastvgk;	/* Previous input key, if not from keyboard */
var	short	lastreg;	/* Register with last command */
D 15
var	char	*ncols['z'-'a'+2];	/* Cursor positions of marks */
var	char	*notenam;	/* Name to be noted with change count */
var	char	*notesgn;	/* Change count from last command */
var	char	op;		/* Operation of current command */
E 15
I 15
var	u_char	*ncols['z'-'a'+2];	/* Cursor positions of marks */
var	u_char	*notenam;	/* Name to be noted with change count */
var	u_char	*notesgn;	/* Change count from last command */
var	u_char	op;		/* Operation of current command */
E 15
D 14
var	short	Peekkey;	/* Peek ahead key */
E 14
I 14
var	short	Peek_key;	/* Peek ahead key */
E 14
var	bool	rubble;		/* Line is filthy (in hardcopy open), redraw! */
D 14
var	int	vSCROLL;	/* Number lines to scroll on ^D/^U */
E 14
I 14
var	int	ex_vSCROLL;	/* Number lines to scroll on ^D/^U */
E 14
D 15
var	char	*vglobp;	/* Untyped input (e.g. repeat insert text) */
var	char	vmacbuf[VBSIZE];   /* Text of visual macro, hence nonnestable */
var	char	*vmacp;		/* Like vglobp but for visual macros */
var	char	*vmcurs;	/* Cursor for restore after undo d), e.g. */
E 15
I 15
var	u_char	*vglobp;	/* Untyped input (e.g. repeat insert text) */
var	u_char	vmacbuf[VBSIZE];   /* Text of visual macro, hence nonnestable */
var	u_char	*vmacp;		/* Like vglobp but for visual macros */
var	u_char	*vmcurs;	/* Cursor for restore after undo d), e.g. */
E 15
var	short	vmovcol;	/* Column to try to keep on arrow keys */
var	bool	vmoving;	/* Are trying to keep vmovcol */
var	short	vreg;		/* Reg for this command */   /* mjm: was char */
var	short	wdkind;		/* Liberal/conservative words? */
D 15
var	char	workcmd[5];	/* Temporary for lastcmd */
E 15
I 15
var	u_char	workcmd[5];	/* Temporary for lastcmd */
E 15
E 11
E 10
E 9


/*
 * Macros
 */
#define	INF		30000
#define	LASTLINE	LINE(vcnt)
D 15
#define	OVERBUF		QUOTE
E 15
#define	beep		obeep
#define	cindent()	((outline - vlinfo[vcline].vliny) * WCOLS + outcol)
#define	vputp(cp, cnt)	tputs(cp, cnt, vputch)
#define	vputc(c)	putch(c)
I 15

/*
 * The OVERBUF thing. vi puts OVERBUF in the first byte of buffers likes INS
 * and DEL to indicate that they are overflowed. The problem is what should
 * OVERBUF be now that every byte except 0 is a valid character? Well, we
 * define OVERBUF as 0200 (~@). This means that users cutting and pasting text
 * starting with ~@'s will be surprised. Oh well. At least this is just an
 * inconvenience and not an inability to edit files with ~@'s.
 */
#define	OVERBUF		0200
E 15

/*
 * Function types
 */
int	beep();
int	qcount();
int	vchange();
int	vdelete();
int	vgrabit();
int	vinschar();
int	vmove();
int	vputchar();
int	vshift();
int	vyankit();
E 1
