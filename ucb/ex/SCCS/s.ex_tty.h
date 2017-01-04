h09117
s 00058/00058/00136
d D 7.8 03/04/13 15:19:13 msokolov 16 15
c 8-bit ex
e
s 00003/00001/00191
d D 7.7 87/03/09 12:47:02 conrad 15 14
c make ex/vi work on vms
e
s 00001/00001/00191
d D 7.6 86/11/14 12:33:16 bostic 14 13
c changed termcap buffer size to 1024, from 256.
e
s 00008/00002/00184
d D 7.5 85/05/31 15:58:21 dist 13 11
c Add copyright
e
s 00008/00002/00172
d D 5.1.1.1 85/05/31 11:52:34 dist 12 6
c Add copyright
e
s 00001/00000/00185
d D 7.4 85/02/21 17:49:50 bloom 11 10
c add window size change support
e
s 00015/00004/00170
d D 7.3 81/09/09 14:25:28 mark 10 9
c improved vt100 interface.  also uses parm termcap entries.
e
s 00091/00094/00083
d D 7.2 81/07/26 20:04:43 mark 9 8
c fixes for 3b
e
s 00095/00094/00082
d D 7.1 81/07/08 22:31:45 mark 8 7
c release 3.7 - a few bug fixes and a few new features.
e
s 00003/00001/00173
d D 6.1 80/10/19 01:21:37 mark 7 6
c preliminary release 3.6 10/18/80
e
s 00000/00000/00174
d D 5.1 80/08/20 16:12:08 mark 6 5
c Release 3.5, August 20, 1980
e
s 00002/00001/00172
d D 4.2 80/08/01 20:41:37 mark 5 4
c Bill added more buffers, and I put in sccs.
e
s 00046/00005/00127
d D 4.1 80/08/01 00:16:04 mark 4 3
c release 3.4, June 24, 1980
e
s 00008/00002/00124
d D 3.1 80/07/31 23:40:03 mark 3 2
c release 3.3, Feb 2, 1980
e
s 00000/00000/00126
d D 2.1 80/07/31 23:19:54 mark 2 1
c release 3.2, Jan 4, 1980
e
s 00126/00000/00000
d D 1.1 80/07/31 23:00:32 mark 1 0
c date and time created 80/07/31 23:00:32 by mark
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
E 8
I 8
D 13
/* Copyright (c) 1981 Regents of the University of California */
/* sccs id:	%W%	%G%  */
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
E 8
E 5
/*
 * Capabilities from termcap
 *
 * The description of terminals is a difficult business, and we only
 * attempt to summarize the capabilities here;  for a full description
 * see the paper describing termcap.
 *
 * Capabilities from termcap are of three kinds - string valued options,
 * numeric valued options, and boolean options.  The string valued options
 * are the most complicated, since they may include padding information,
 * which we describe now.
 *
 * Intelligent terminals often require padding on intelligent operations
 * at high (and sometimes even low) speed.  This is specified by
 * a number before the string in the capability, and has meaning for the
 * capabilities which have a P at the front of their comment.
 * This normally is a number of milliseconds to pad the operation.
 * In the current system which has no true programmible delays, we
 * do this by sending a sequence of pad characters (normally nulls, but
 * specifiable as "pc").  In some cases, the pad is better computed
 * as some number of milliseconds times the number of affected lines
 * (to bottom of screen usually, except when terminals have insert modes
 * which will shift several lines.)  This is specified as '12*' e.g.
 * before the capability to say 12 milliseconds per affected whatever
 * (currently always line).  Capabilities where this makes sense say P*.
 */
D 8
char	tspace[256];		/* Space for capability strings */
char	*aoftspace;		/* Address of tspace for relocation */
E 8
I 8
D 9
extern char	tspace[256];	/* Space for capability strings */
extern char	*aoftspace;	/* Address of tspace for relocation */
E 9
I 9
D 14
var	char	tspace[256];	/* Space for capability strings */
E 14
I 14
D 16
var	char	tspace[1024];	/* Space for capability strings */
E 14
var	char	*aoftspace;	/* Address of tspace for relocation */
E 16
I 16
var	u_char	tspace[1024];	/* Space for capability strings */
var	u_char	*aoftspace;	/* Address of tspace for relocation */
E 16
E 9
E 8

D 8
char	*AL;			/* P* Add new blank line */
char	*BC;			/*    Back cursor */
char	*BT;			/* P  Back tab */
char	*CD;			/* P* Clear to end of display */
char	*CE;			/* P  Clear to end of line */
char	*CL;			/* P* Clear screen */
char	*CM;			/* P  Cursor motion */
I 4
char	*xCR;			/* P  Carriage return */
E 4
char	*DC;			/* P* Delete character */
char	*DL;			/* P* Delete line sequence */
char	*DM;			/*    Delete mode (enter)  */
char	*DO;			/*    Down line sequence */
char	*ED;			/*    End delete mode */
char	*EI;			/*    End insert mode */
char	*F0,*F1,*F2,*F3,*F4,*F5,*F6,*F7,*F8,*F9;
E 8
I 8
D 9
extern char	*AL;		/* P* Add new blank line */
extern char	*BC;		/*    Back cursor */
extern char	*BT;		/* P  Back tab */
extern char	*CD;		/* P* Clear to end of display */
extern char	*CE;		/* P  Clear to end of line */
extern char	*CL;		/* P* Clear screen */
extern char	*CM;		/* P  Cursor motion */
extern char	*xCR;		/* P  Carriage return */
extern char	*DC;		/* P* Delete character */
extern char	*DL;		/* P* Delete line sequence */
extern char	*DM;		/*    Delete mode (enter)  */
extern char	*DO;		/*    Down line sequence */
extern char	*ED;		/*    End delete mode */
extern char	*EI;		/*    End insert mode */
extern char	*F0,*F1,*F2,*F3,*F4,*F5,*F6,*F7,*F8,*F9;
E 9
I 9
D 16
var	char	*AL;		/* P* Add new blank line */
I 10
var	char	*AL_PARM;	/* P* Add n new blank lines */
E 10
extern	char	*BC;		/*    Back cursor */
var	char	*BT;		/* P  Back tab */
var	char	*CD;		/* P* Clear to end of display */
var	char	*CE;		/* P  Clear to end of line */
var	char	*CL;		/* P* Clear screen */
D 10
var	char	*CM;		/* P  Cursor motion */
E 10
I 10
var	char	*CM;		/* PG Cursor motion */
var	char	*CS;		/* PG Change scrolling region (vt100) */
E 10
var	char	*xCR;		/* P  Carriage return */
var	char	*DC;		/* P* Delete character */
var	char	*DL;		/* P* Delete line sequence */
I 10
var	char	*DL_PARM;	/* P* Delete n lines */
E 10
var	char	*DM;		/*    Delete mode (enter)  */
var	char	*DO;		/*    Down line sequence */
I 10
var	char	*DOWN_PARM;	/*    Down n lines */
E 10
var	char	*ED;		/*    End delete mode */
var	char	*EI;		/*    End insert mode */
var	char	*F0,*F1,*F2,*F3,*F4,*F5,*F6,*F7,*F8,*F9;
E 16
I 16
var	u_char	*AL;		/* P* Add new blank line */
var	u_char	*AL_PARM;	/* P* Add n new blank lines */
extern	u_char	*BC;		/*    Back cursor */
var	u_char	*BT;		/* P  Back tab */
var	u_char	*CD;		/* P* Clear to end of display */
var	u_char	*CE;		/* P  Clear to end of line */
var	u_char	*CL;		/* P* Clear screen */
var	u_char	*CM;		/* PG Cursor motion */
var	u_char	*CS;		/* PG Change scrolling region (vt100) */
var	u_char	*xCR;		/* P  Carriage return */
var	u_char	*DC;		/* P* Delete character */
var	u_char	*DL;		/* P* Delete line sequence */
var	u_char	*DL_PARM;	/* P* Delete n lines */
var	u_char	*DM;		/*    Delete mode (enter)  */
var	u_char	*DO;		/*    Down line sequence */
var	u_char	*DOWN_PARM;	/*    Down n lines */
var	u_char	*ED;		/*    End delete mode */
var	u_char	*EI;		/*    End insert mode */
var	u_char	*F0,*F1,*F2,*F3,*F4,*F5,*F6,*F7,*F8,*F9;
E 16
E 9
E 8
				/*    Strings sent by various function keys */
D 8
char	*HO;			/*    Home cursor */
char	*IC;			/* P  Insert character */
char	*IM;			/*    Insert mode (give as ':im=:' if 'ic' */
char	*IP;			/* P* Insert pad after char ins'd using IM+IE */
char	*KD;			/*    Keypad down arrow */
char	*KE;			/*    Keypad don't xmit */
char	*KH;			/*    Keypad home key */
char	*KL;			/*    Keypad left arrow */
char	*KR;			/*    Keypad right arrow */
char	*KS;			/*    Keypad start xmitting */
char	*KU;			/*    Keypad up arrow */
char	*LL;			/*    Quick to last line, column 0 */
char	*ND;			/*    Non-destructive space */
I 4
char	*xNL;			/*    Line feed (new line) */
E 4
char	PC;			/*    Pad character */
char	*SE;			/*    Standout end (may leave space) */
char	*SF;			/* P  Scroll forwards */
char	*SO;			/*    Stand out begin (may leave space) */
char	*SR;			/* P  Scroll backwards */
char	*TA;			/* P  Tab (other than ^I or with padding) */
char	*TE;			/*    Terminal end sequence */
char	*TI;			/*    Terminal initial sequence */
char	*UP;			/*    Upline */
char	*VB;			/*    Visible bell */
char	*VE;			/*    Visual end sequence */
char	*VS;			/*    Visual start sequence */
bool	AM;			/* Automatic margins */
bool	BS;			/* Backspace works */
bool	CA;			/* Cursor addressible */
bool	DA;			/* Display may be retained above */
bool	DB;			/* Display may be retained below */
bool	EO;			/* Can erase overstrikes with ' ' */
bool	GT;			/* Gtty indicates tabs */
bool	HC;			/* Hard copy terminal */
bool	HZ;			/* Hazeltine ~ braindamage */
bool	IN;			/* Insert-null blessing */
bool	MI;			/* can move in insert mode */
bool	NC;			/* No Cr - \r snds \r\n then eats \n (dm2500) */
I 4
bool	NS;			/* No scroll - linefeed at bottom won't scroll */
E 4
bool	OS;			/* Overstrike works */
bool	UL;			/* Underlining works even though !os */
I 4
bool	XB;			/* Beehive (no escape key, simulate with f1) */
E 4
bool	XN;			/* A newline gets eaten after wrap (concept) */
bool	XT;			/* Tabs are destructive */
I 4
bool	XX;			/* Tektronix 4025 insert line */
E 8
I 8
D 9
extern char	*HO;		/*    Home cursor */
extern char	*IC;		/* P  Insert character */
extern char	*IM;		/*    Insert mode (give as ':im=:' if 'ic' */
extern char	*IP;		/* P* Insert pad after char ins'd using IM+IE */
extern char	*KD;		/*    Keypad down arrow */
extern char	*KE;		/*    Keypad don't xmit */
extern char	*KH;		/*    Keypad home key */
extern char	*KL;		/*    Keypad left arrow */
extern char	*KR;		/*    Keypad right arrow */
extern char	*KS;		/*    Keypad start xmitting */
extern char	*KU;		/*    Keypad up arrow */
extern char	*LL;		/*    Quick to last line, column 0 */
extern char	*ND;		/*    Non-destructive space */
extern char	*xNL;		/*    Line feed (new line) */
extern char	PC;		/*    Pad character */
extern char	*SE;		/*    Standout end (may leave space) */
extern char	*SF;		/* P  Scroll forwards */
extern char	*SO;		/*    Stand out begin (may leave space) */
extern char	*SR;		/* P  Scroll backwards */
extern char	*TA;		/* P  Tab (other than ^I or with padding) */
extern char	*TE;		/*    Terminal end sequence */
extern char	*TI;		/*    Terminal initial sequence */
extern char	*UP;		/*    Upline */
extern char	*VB;		/*    Visible bell */
extern char	*VE;		/*    Visual end sequence */
extern char	*VS;		/*    Visual start sequence */
extern bool	AM;		/* Automatic margins */
extern bool	BS;		/* Backspace works */
extern bool	CA;		/* Cursor addressible */
extern bool	DA;		/* Display may be retained above */
extern bool	DB;		/* Display may be retained below */
extern bool	EO;		/* Can erase overstrikes with ' ' */
extern bool	GT;		/* Gtty indicates tabs */
extern bool	HC;		/* Hard copy terminal */
extern bool	HZ;		/* Hazeltine ~ braindamage */
extern bool	IN;		/* Insert-null blessing */
extern bool	MI;		/* can move in insert mode */
extern bool	NC;		/* No Cr - \r snds \r\n then eats \n (dm2500) */
extern bool	NS;		/* No scroll - linefeed at bottom won't scroll */
extern bool	OS;		/* Overstrike works */
extern bool	UL;		/* Underlining works even though !os */
extern bool	XB;		/* Beehive (no escape key, simulate with f1) */
extern bool	XN;		/* A newline gets eaten after wrap (concept) */
extern bool	XT;		/* Tabs are destructive */
bool	XV;			/* VT100 - run AL and DL through tgoto */
extern bool	XX;		/* Tektronix 4025 insert line */
E 9
I 9
D 16
var	char	*HO;		/*    Home cursor */
var	char	*IC;		/* P  Insert character */
var	char	*IM;		/*    Insert mode (give as ':im=:' if 'ic' */
var	char	*IP;		/* P* Insert pad after char ins'd using IM+IE */
var	char	*KD;		/*    Keypad down arrow */
var	char	*KE;		/*    Keypad don't xmit */
var	char	*KH;		/*    Keypad home key */
var	char	*KL;		/*    Keypad left arrow */
var	char	*KR;		/*    Keypad right arrow */
var	char	*KS;		/*    Keypad start xmitting */
var	char	*KU;		/*    Keypad up arrow */
I 10
var	char	*LEFT_PARM;	/*    Left n chars */
E 10
var	char	*LL;		/*    Quick to last line, column 0 */
var	char	*ND;		/*    Non-destructive space */
I 10
var	char	*RIGHT_PARM;	/*    Right n spaces */
E 10
var	char	*xNL;		/*    Line feed (new line) */
extern	char	PC;		/*    Pad character */
I 10
var	char	*RC;		/*    Restore cursor from last SC */
var	char	*SC;		/*    Save cursor */
E 10
var	char	*SE;		/*    Standout end (may leave space) */
var	char	*SF;		/* P  Scroll forwards */
var	char	*SO;		/*    Stand out begin (may leave space) */
var	char	*SR;		/* P  Scroll backwards */
var	char	*TA;		/* P  Tab (other than ^I or with padding) */
var	char	*TE;		/*    Terminal end sequence */
var	char	*TI;		/*    Terminal initial sequence */
extern	char	*UP;		/*    Upline */
I 10
var	char	*UP_PARM;	/*    Up n lines */
E 10
var	char	*VB;		/*    Visible bell */
var	char	*VE;		/*    Visual end sequence */
var	char	*VS;		/*    Visual start sequence */
E 16
I 16
var	u_char	*HO;		/*    Home cursor */
var	u_char	*IC;		/* P  Insert character */
var	u_char	*IM;		/*    Insert mode (give as ':im=:' if 'ic' */
var	u_char	*IP;		/* P* Insert pad after char ins'd using IM+IE */
var	u_char	*KD;		/*    Keypad down arrow */
var	u_char	*KE;		/*    Keypad don't xmit */
var	u_char	*KH;		/*    Keypad home key */
var	u_char	*KL;		/*    Keypad left arrow */
var	u_char	*KR;		/*    Keypad right arrow */
var	u_char	*KS;		/*    Keypad start xmitting */
var	u_char	*KU;		/*    Keypad up arrow */
var	u_char	*LEFT_PARM;	/*    Left n chars */
var	u_char	*LL;		/*    Quick to last line, column 0 */
var	u_char	*ND;		/*    Non-destructive space */
var	u_char	*RIGHT_PARM;	/*    Right n spaces */
var	u_char	*xNL;		/*    Line feed (new line) */
extern	u_char	PC;		/*    Pad character */
var	u_char	*RC;		/*    Restore cursor from last SC */
var	u_char	*SC;		/*    Save cursor */
var	u_char	*SE;		/*    Standout end (may leave space) */
var	u_char	*SF;		/* P  Scroll forwards */
var	u_char	*SO;		/*    Stand out begin (may leave space) */
var	u_char	*SR;		/* P  Scroll backwards */
var	u_char	*TA;		/* P  Tab (other than ^I or with padding) */
var	u_char	*TE;		/*    Terminal end sequence */
var	u_char	*TI;		/*    Terminal initial sequence */
extern	u_char	*UP;		/*    Upline */
var	u_char	*UP_PARM;	/*    Up n lines */
var	u_char	*VB;		/*    Visible bell */
var	u_char	*VE;		/*    Visual end sequence */
var	u_char	*VS;		/*    Visual start sequence */
E 16
var	bool	AM;		/* Automatic margins */
var	bool	BS;		/* Backspace works */
var	bool	CA;		/* Cursor addressible */
var	bool	DA;		/* Display may be retained above */
var	bool	DB;		/* Display may be retained below */
var	bool	EO;		/* Can erase overstrikes with ' ' */
var	bool	GT;		/* Gtty indicates tabs */
var	bool	HC;		/* Hard copy terminal */
var	bool	HZ;		/* Hazeltine ~ braindamage */
var	bool	IN;		/* Insert-null blessing */
var	bool	MI;		/* can move in insert mode */
var	bool	NC;		/* No Cr - \r snds \r\n then eats \n (dm2500) */
var	bool	NS;		/* No scroll - linefeed at bottom won't scroll */
var	bool	OS;		/* Overstrike works */
var	bool	UL;		/* Underlining works even though !os */
var	bool	XB;		/* Beehive (no escape key, simulate with f1) */
var	bool	XN;		/* A newline gets eaten after wrap (concept) */
var	bool	XT;		/* Tabs are destructive */
D 10
var	bool	XV;		/* VT100 - run AL and DL through tgoto */
E 10
var	bool	XX;		/* Tektronix 4025 insert line */
E 9
E 8
E 4
	/* X? is reserved for severely nauseous glitches */
	/* If there are enough of these we may need bit masks! */

/*
 * From the tty modes...
 */
D 8
bool	NONL;			/* Terminal can't hack linefeeds doing a CR */
bool	UPPERCASE;		/* Ick! */
short	LINES;			/* Number of lines on screen */
short	COLUMNS;
short	OCOLUMNS;		/* Save COLUMNS for a hack in open mode */
E 8
I 8
D 9
extern bool	NONL;		/* Terminal can't hack linefeeds doing a CR */
extern bool	UPPERCASE;	/* Ick! */
extern short	LINES;		/* Number of lines on screen */
extern short	COLUMNS;
extern short	OCOLUMNS;	/* Save COLUMNS for a hack in open mode */
E 9
I 9
var	bool	NONL;		/* Terminal can't hack linefeeds doing a CR */
var	bool	UPPERCASE;	/* Ick! */
extern	short	LINES;		/* Number of lines on screen */
extern	short	COLUMNS;
var	short	OCOLUMNS;	/* Save COLUMNS for a hack in open mode */
I 15
#ifdef	TIOCGWINSZ
E 15
I 11
var	struct winsize winsz;	/* Save window size for stopping comparisons */
I 15
#endif
E 15
E 11
E 9
E 8

D 8
short	outcol;			/* Where the cursor is */
short	outline;
E 8
I 8
D 9
extern short	outcol;		/* Where the cursor is */
extern short	outline;
E 9
I 9
var	short	outcol;		/* Where the cursor is */
var	short	outline;
E 9
E 8

D 8
short	destcol;		/* Where the cursor should be */
short	destline;
E 8
I 8
D 9
extern short	destcol;	/* Where the cursor should be */
extern short	destline;
E 9
I 9
var	short	destcol;	/* Where the cursor should be */
var	short	destline;
E 9
E 8

D 4
#ifdef 	TIOCSETC
struct	tchars ottyc, nttyc;	/* For V7 character masking */
E 4
I 4
/*
 * There are several kinds of tty drivers to contend with.  These include:
 * (1)	V6:		no CBREAK, no ioctl.  (Include PWB V1 here).
 * (2)	V7 research:	has CBREAK, has ioctl, and has the tchars (TIOCSETC)
 *			business to change start, stop, etc. chars.
 * (3)	USG V2:		Basically like V6 but RAW mode is like V7 RAW.
 *			(We treat it as V6.)
 * (4)	USG V3:		equivalent to V7 but totally incompatible.
 * (5)  Berkeley:	has ltchars in addition to all of V7.
 *
 * The following attempts to decide what we are on, and declare
 * some variables in the appropriate format.  The wierd looking one (ttymode)
D 15
 * is the thing we pass to sTTY and family to turn "RAW" mode on or off
E 15
I 15
 * is the thing we pass to ex_sTTY and family to turn "RAW" mode on or off
E 15
 * when we go into or out of visual mode.  In V7/V6 it's just the flags word
 * to stty.  In USG V3 it's the whole tty structure.
 */
#ifdef	USG3TTY			/* USG V3 */
D 8
  struct	termio tty;	/* Use this one structure to change modes */
E 8
I 8
D 9
  extern struct	termio tty;	/* Use this one structure to change modes */
E 9
I 9
  var	struct	termio tty;	/* Use this one structure to change modes */
E 9
E 8
  typedef	struct termio ttymode;	/* Mode to contain tty flags */

#else				/* All others */
D 8
  struct	sgttyb tty;	/* Always stty/gtty using this one structure */
E 8
I 8
D 9
  extern struct	sgttyb tty;	/* Always stty/gtty using this one structure */
E 9
I 9
  var	struct	sgttyb tty;	/* Always stty/gtty using this one structure */
E 9
E 8
  typedef	int ttymode;	/* Mode to contain tty flags */
# ifdef 	TIOCSETC	/* V7 */
D 8
   struct	tchars ottyc, nttyc;	/* For V7 character masking */
E 8
I 8
D 9
   extern struct	tchars ottyc, nttyc;	/* For V7 character masking */
E 9
I 9
   var	struct	tchars ottyc, nttyc;	/* For V7 character masking */
E 9
E 8
# endif
# ifdef		TIOCLGET	/* Berkeley */
D 8
   struct	ltchars olttyc, nlttyc;	/* More of tchars style stuff */
E 8
I 8
D 9
   extern struct	ltchars olttyc, nlttyc;	/* More of tchars style stuff */
E 9
I 9
   var	struct	ltchars olttyc, nlttyc;	/* More of tchars style stuff */
E 9
E 8
# endif

E 4
#endif
D 4
struct	sgttyb tty;		/* Always stty/gtty using this one structure */
bool	normtty;		/* Have to restor normal mode from normf */
int	normf;			/* Restore tty flags to this (someday) */
E 4

I 4
D 8
ttymode	normf;			/* Restore tty flags to this (someday) */
bool	normtty;		/* Have to restore normal mode from normf */
E 8
I 8
D 9
extern ttymode	normf;		/* Restore tty flags to this (someday) */
extern bool	normtty;	/* Have to restore normal mode from normf */
E 9
I 9
var	ttymode	normf;		/* Restore tty flags to this (someday) */
var	bool	normtty;	/* Have to restore normal mode from normf */
E 9
E 8

ttymode ostart(), setty(), unixex();

E 4
D 8
short	WBOT;
short	WECHO;
E 8
I 8
D 9
extern short	WBOT;
extern short	WECHO;
E 9
I 9
var	short	costCM;	/* # chars to output a typical CM, with padding etc. */
D 10
var	short	costSR;	/* likewise */
var	short	costAL;
E 10
I 10
var	short	costSR;	/* likewise for scroll reverse */
var	short	costAL;	/* likewise for insert line */
var	short	costDP;	/* likewise for DOWN_PARM */
var	short	costLP;	/* likewise for LEFT_PARM */
var	short	costRP;	/* likewise for RIGHT_PARM */
E 10
E 9
E 8

D 7
short	costCM;
E 7
I 7
D 8
short	costCM;	/* # chars to output a typical CM, with padding etc. */
short	costSR;	/* likewise */
short	costAL;
E 8
I 8
D 9
extern short	costCM;	/* # chars to output a typical CM, with padding etc. */
extern short	costSR;	/* likewise */
extern short	costAL;
E 8
E 7

E 9
D 3
#define MAXNOMACS	32	/* max number of macros */
#define MAXCHARMACS	512	/* max # of chars total in macros */
E 3
I 3
#ifdef VMUNIX
# define MAXNOMACS	128	/* max number of macros of each kind */
# define MAXCHARMACS	2048	/* max # of chars total in macros */
#else
# define MAXNOMACS	32	/* max number of macros of each kind */
# define MAXCHARMACS	512	/* max # of chars total in macros */
#endif
E 3
struct maps {
D 16
	char *cap;	/* pressing button that sends this.. */
	char *mapto;	/* .. maps to this string */
	char *descr;	/* legible description of key */
E 16
I 16
	u_char *cap;	/* pressing button that sends this.. */
	u_char *mapto;	/* .. maps to this string */
	u_char *descr;	/* legible description of key */
E 16
};
D 8
struct maps arrows[MAXNOMACS];	/* macro defs - 1st 5 built in */
I 3
struct maps immacs[MAXNOMACS];	/* for while in insert mode */
I 4
struct maps abbrevs[MAXNOMACS];	/* for word abbreviations */
int	ldisc;			/* line discipline for ucb tty driver */
E 4
E 3
char	mapspace[MAXCHARMACS];
char	*msnext;	/* next free location in mapspace */
I 4
int	maphopcnt;	/* check for infinite mapping loops */
bool	anyabbrs;	/* true if abbr or unabbr has been done */
char	ttynbuf[20];	/* result of ttyname() */
int	ttymesg;	/* original mode of users tty */
E 8
I 8
D 9
extern struct maps arrows[MAXNOMACS];	/* macro defs - 1st 5 built in */
extern struct maps immacs[MAXNOMACS];	/* for while in insert mode */
extern struct maps abbrevs[MAXNOMACS];	/* for word abbreviations */
extern int	ldisc;			/* line discipline for ucb tty driver */
extern char	mapspace[MAXCHARMACS];
extern char	*msnext;	/* next free location in mapspace */
extern int	maphopcnt;	/* check for infinite mapping loops */
extern bool	anyabbrs;	/* true if abbr or unabbr has been done */
extern char	ttynbuf[20];	/* result of ttyname() */
extern int	ttymesg;	/* original mode of users tty */
E 9
I 9
var	struct maps arrows[MAXNOMACS];	/* macro defs - 1st 5 built in */
var	struct maps immacs[MAXNOMACS];	/* for while in insert mode */
var	struct maps abbrevs[MAXNOMACS];	/* for word abbreviations */
var	int	ldisc;			/* line discipline for ucb tty driver */
D 16
var	char	mapspace[MAXCHARMACS];
var	char	*msnext;	/* next free location in mapspace */
E 16
I 16
var	u_char	mapspace[MAXCHARMACS];
var	u_char	*msnext;	/* next free location in mapspace */
E 16
var	int	maphopcnt;	/* check for infinite mapping loops */
var	bool	anyabbrs;	/* true if abbr or unabbr has been done */
D 16
var	char	ttynbuf[20];	/* result of ttyname() */
E 16
I 16
var	u_char	ttynbuf[20];	/* result of ttyname() */
E 16
var	int	ttymesg;	/* original mode of users tty */
E 9
E 8
E 4
E 1
