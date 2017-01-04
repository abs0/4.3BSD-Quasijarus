/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	@(#)ex_tty.h	7.8 (Berkeley) 4/13/03
 */

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
var	u_char	tspace[1024];	/* Space for capability strings */
var	u_char	*aoftspace;	/* Address of tspace for relocation */

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
				/*    Strings sent by various function keys */
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
var	bool	XX;		/* Tektronix 4025 insert line */
	/* X? is reserved for severely nauseous glitches */
	/* If there are enough of these we may need bit masks! */

/*
 * From the tty modes...
 */
var	bool	NONL;		/* Terminal can't hack linefeeds doing a CR */
var	bool	UPPERCASE;	/* Ick! */
extern	short	LINES;		/* Number of lines on screen */
extern	short	COLUMNS;
var	short	OCOLUMNS;	/* Save COLUMNS for a hack in open mode */
#ifdef	TIOCGWINSZ
var	struct winsize winsz;	/* Save window size for stopping comparisons */
#endif

var	short	outcol;		/* Where the cursor is */
var	short	outline;

var	short	destcol;	/* Where the cursor should be */
var	short	destline;

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
 * is the thing we pass to ex_sTTY and family to turn "RAW" mode on or off
 * when we go into or out of visual mode.  In V7/V6 it's just the flags word
 * to stty.  In USG V3 it's the whole tty structure.
 */
#ifdef	USG3TTY			/* USG V3 */
  var	struct	termio tty;	/* Use this one structure to change modes */
  typedef	struct termio ttymode;	/* Mode to contain tty flags */

#else				/* All others */
  var	struct	sgttyb tty;	/* Always stty/gtty using this one structure */
  typedef	int ttymode;	/* Mode to contain tty flags */
# ifdef 	TIOCSETC	/* V7 */
   var	struct	tchars ottyc, nttyc;	/* For V7 character masking */
# endif
# ifdef		TIOCLGET	/* Berkeley */
   var	struct	ltchars olttyc, nlttyc;	/* More of tchars style stuff */
# endif

#endif

var	ttymode	normf;		/* Restore tty flags to this (someday) */
var	bool	normtty;	/* Have to restore normal mode from normf */

ttymode ostart(), setty(), unixex();

var	short	costCM;	/* # chars to output a typical CM, with padding etc. */
var	short	costSR;	/* likewise for scroll reverse */
var	short	costAL;	/* likewise for insert line */
var	short	costDP;	/* likewise for DOWN_PARM */
var	short	costLP;	/* likewise for LEFT_PARM */
var	short	costRP;	/* likewise for RIGHT_PARM */

#ifdef VMUNIX
# define MAXNOMACS	128	/* max number of macros of each kind */
# define MAXCHARMACS	2048	/* max # of chars total in macros */
#else
# define MAXNOMACS	32	/* max number of macros of each kind */
# define MAXCHARMACS	512	/* max # of chars total in macros */
#endif
struct maps {
	u_char *cap;	/* pressing button that sends this.. */
	u_char *mapto;	/* .. maps to this string */
	u_char *descr;	/* legible description of key */
};
var	struct maps arrows[MAXNOMACS];	/* macro defs - 1st 5 built in */
var	struct maps immacs[MAXNOMACS];	/* for while in insert mode */
var	struct maps abbrevs[MAXNOMACS];	/* for word abbreviations */
var	int	ldisc;			/* line discipline for ucb tty driver */
var	u_char	mapspace[MAXCHARMACS];
var	u_char	*msnext;	/* next free location in mapspace */
var	int	maphopcnt;	/* check for infinite mapping loops */
var	bool	anyabbrs;	/* true if abbr or unabbr has been done */
var	u_char	ttynbuf[20];	/* result of ttyname() */
var	int	ttymesg;	/* original mode of users tty */
