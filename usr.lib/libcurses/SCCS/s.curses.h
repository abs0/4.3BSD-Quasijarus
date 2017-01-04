h49372
s 00010/00005/00176
d D 5.4 88/06/30 17:21:26 bostic 21 20
c install approved copyright notice
e
s 00009/00003/00172
d D 5.3 88/06/08 13:56:57 bostic 20 19
c written by Ken Arnold; add Berkeley specific header
e
s 00007/00002/00168
d D 5.2 87/06/24 14:17:16 minshall 19 18
c Add 'addbytes.c', plus some cleanup by K. Bostic in Makefile.
e
s 00008/00001/00162
d D 5.1 85/06/07 11:45:28 dist 18 17
c Add copyright
e
s 00001/00001/00162
d D 1.16 85/05/23 15:37:45 bloom 17 16
c Add support for XS
e
s 00026/00013/00137
d D 1.15 85/05/01 17:44:05 bloom 16 15
c new version from arnold
e
s 00001/00000/00149
d D 1.14 83/07/04 18:43:51 sam 15 14
c extern
e
s 00004/00000/00145
d D 1.13 83/07/03 18:08:05 sam 14 13
c put unctrl back in as a macro
e
s 00016/00016/00129
d D 1.12 83/05/09 21:13:00 arnold 13 12
c integrate subwindows fully into all parts of curses
e
s 00001/00001/00144
d D 1.11 83/02/02 15:19:13 arnold 12 11
c unctrl should strip off parity bit
e
s 00004/00004/00141
d D 1.10 82/02/17 14:10:44 arnold 11 10
c adopt latest version of fgoto() and plod() from vi
e
s 00002/00002/00143
d D 1.9 82/02/16 17:04:47 arnold 10 9
c forgot to add str as a parameter to getstr, mvgetstr
e
s 00001/00001/00144
d D 1.8 81/05/15 16:21:56 arnold 9 8
c add getcap() function
e
s 00003/00000/00142
d D 1.7 81/04/17 00:42:33 arnold 8 7
c add delch(), mvdelch(), and mvwdelch()
e
s 00003/00000/00139
d D 1.6 81/04/17 00:31:10 arnold 7 6
c add insch(), mvinsch(), and mvwinsch()
e
s 00001/00001/00138
d D 1.5 81/03/29 22:18:38 arnold 6 5
c fix up mxinch to use stdscr instead of win
e
s 00009/00009/00130
d D 1.4 81/03/05 20:50:52 arnold 5 3
c move all declarations from curses.h to curses.c
e
s 00005/00005/00134
d R 1.4 81/03/05 20:02:01 arnold 4 3
c make the "extern" variables not extern so they are defined
e
s 00003/00004/00136
d D 1.3 81/03/05 19:33:52 arnold 3 2
c make #ifndef WINDOW apply to whole file
e
s 00036/00096/00104
d D 1.2 81/02/17 15:52:42 arnold 2 1
c shorten everything up for faster compilation
e
s 00200/00000/00000
d D 1.1 81/01/26 17:02:47 arnold 1 0
c date and time created 81/01/26 17:02:47 by arnold
e
u
U
t
T
I 1
D 13
/* %G% (Berkeley) %W% */
E 13
I 13
D 16
/* %W% (Berkeley) %G% */
E 16
I 16
D 18
/* %G% (Berkeley) %W% */
E 18
I 18
/*
D 20
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 20
I 20
 * Copyright (c) 1981 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 21
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 21
I 21
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 21
E 20
 *
 *	%W% (Berkeley) %G%
 */

E 18
E 16
E 13
I 3
# ifndef WINDOW
E 3

# include	<stdio.h>
 
# include	<sgtty.h>

D 2
# define	bool	char		/* boolean variable		*/
# define	reg	register	/* register varaible abbr.	*/
E 2
I 2
# define	bool	char
# define	reg	register
E 2

# define	TRUE	(1)
# define	FALSE	(0)
D 2
# define	ERR	(0)		/* default return on error	*/
# define	OK	(1)		/* default return on good run	*/
E 2
I 2
# define	ERR	(0)
# define	OK	(1)
E 2

D 2
# define	_SUBWIN		01	/* window is a subindow		*/
# define	_ENDLINE	02	/* lines go to end of screen	*/
# define	_FULLWIN	04	/* window is entire screen	*/
# define	_SCROLLWIN	010	/* window could cause scroll	*/
# define	_FLUSH		020	/* flush after refresh		*/
# define	_STANDOUT	0200	/* standout mode in effect	*/
# define	_NOCHANGE	-1	/* no change on this line	*/
E 2
I 2
D 13
# define	_SUBWIN		01
# define	_ENDLINE	02
# define	_FULLWIN	04
# define	_SCROLLWIN	010
# define	_FLUSH		020
E 13
I 13
# define	_ENDLINE	001
# define	_FULLWIN	002
# define	_SCROLLWIN	004
# define	_FLUSH		010
I 16
# define	_FULLLINE	020
# define	_IDLINE		040
E 16
E 13
# define	_STANDOUT	0200
# define	_NOCHANGE	-1
E 2

D 16
# define	_puts(s)	tputs(s, 0, _putchar);
E 16
I 16
# define	_puts(s)	tputs(s, 0, _putchar)
E 16

typedef	struct sgttyb	SGTTY;

D 3
# ifndef WINDOW

E 3
D 2
/* Copyright (c) 1979 Regents of the University of California */
E 2
/*
 * Capabilities from termcap
 */

D 2
char	*AL;			/* P* Add new blank line		*/
bool	AM;			/*    Automatic margins			*/
char	*BC;			/*    Back cursor			*/
bool	BS;			/*    Backspace works			*/
char	*BT;			/* P  Back tab				*/
bool	CA;			/*    Cursor addressible		*/
char	*CD;			/* P* Clear to end of display		*/
char	*CE;			/* P  Clear to end of line		*/
char	*CL;			/* P* Clear screen			*/
char	*CM;			/* P  Cursor motion			*/
bool	DA;			/*    Display may be retained above	*/
bool	DB;			/*    Display may be retained below	*/
char	*DC;			/* P* Delete character			*/
char	*DL;			/* P* Delete line sequence		*/
char	*DM;			/*    Delete mode (enter)		*/
char	*DO;			/*    Down line sequence		*/
char	*ED;			/*    End delete mode			*/
bool	EO;			/*    Can erase overstrikes with ' '	*/
char	*EI;			/*    End insert mode			*/
bool	GT;			/*    Gtty indicates tabs		*/
char	*HO;			/*    Home cursor			*/
bool	HZ;			/*    Hazeltine ~ braindamage		*/
char	*IC;			/* P  Insert character			*/
bool	IN;			/*    Insert-null blessing		*/
char	*IM;			/*    Insrt mode (as ':im=:' if 'ic')	*/
char	*IP;			/* P* pad after char ins'd using IM+IE	*/
char	*LL;			/*    Quick to last line, column 0	*/
char	*MA;			/*    Ctrl character map for cmd mode	*/
bool	MI;			/*    can Move in Insert mode		*/
bool	MS;			/*    can Move in Standout mode		*/
bool	NC;			/*    No Cr: \r sends \r\n then eats \n	*/
char	*ND;			/*    Non-destructive space		*/
bool	OS;			/*    Overstrike works			*/
char	PC;			/*    Pad character			*/
char	*SE;			/*    Standout end (may leave space)	*/
char	*SF;			/* P  Scroll forwards			*/
char	*SO;			/*    Stand out begin (may leave space)	*/
char	*SR;			/* P  Scroll backwards			*/
char	*TA;			/* P  Tab (not ^I or with padding)	*/
char	*TE;			/*    End sequence after TI		*/
char	*TI;			/*    Terminal Initialize		*/
char	*UC;			/*    Underline a single Character	*/
char	*UE;			/*    Underline End sequence		*/
bool	UL;			/*    Underlining works even though !os	*/
char	*UP;			/*    Upline				*/
char	*US;			/*    Underline Start sequence		*/
char	*VB;			/*    Visible bell			*/
char	*VE;			/*    Visual end sequence		*/
char	*VS;			/*    Visual start sequence		*/
bool	XN;			/*    A newline gets eaten after wrap	*/
	/* X? is reserved for severely nauseous glitches		*/
	/* If there are enough of these we may need bit masks!		*/
E 2
I 2
D 5
bool	AM, BS, CA, DA, DB, EO, GT, HZ, IN, MI, MS, NC, OS, UL, XN;
char    *AL, *BC, *BT, *CD, *CE, *CL, *CM, *DC, *DL, *DM, *DO, *ED,
	*EI, *HO, *IC, *IM, *IP, *LL, *MA, *ND, *SE, *SF, *SO, *SR,
	*TA, *TE, *TI, *UC, *UE, *UP, *US, *VB, *VE, *VS, PC;
E 5
I 5
D 16
extern bool     AM, BS, CA, DA, DB, EO, GT, HZ, IN, MI, MS, NC, OS, UL,
		XN;
D 11
extern char     *AL, *BC, *BT, *CD, *CE, *CL, *CM, *DC, *DL, *DM, *DO,
		*ED, *EI, *HO, *IC, *IM, *IP, *LL, *MA, *ND, *SE, *SF,
		*SO, *SR, *TA, *TE, *TI, *UC, *UE, *UP, *US, *VB, *VE,
		*VS, PC;
E 11
I 11
extern char     *AL, *BC, *BT, *CD, *CE, *CL, *CM, *CR, *DC, *DL, *DM,
		*DO, *ED, *EI, *HO, *IC, *IM, *IP, *LL, *MA, *ND, *NL,
		*SE, *SF, *SO, *SR, *TA, *TE, *TI, *UC, *UE, *UP, *US,
		*VB, *VE, *VS, PC;
E 16
I 16
extern bool     AM, BS, CA, DA, DB, EO, HC, HZ, IN, MI, MS, NC, NS, OS, UL,
D 17
		XB, XN, XT, XX;
E 17
I 17
		XB, XN, XT, XS, XX;
E 17
extern char	*AL, *BC, *BT, *CD, *CE, *CL, *CM, *CR, *CS, *DC, *DL,
		*DM, *DO, *ED, *EI, *K0, *K1, *K2, *K3, *K4, *K5, *K6,
		*K7, *K8, *K9, *HO, *IC, *IM, *IP, *KD, *KE, *KH, *KL,
		*KR, *KS, *KU, *LL, *MA, *ND, *NL, *RC, *SC, *SE, *SF,
		*SO, *SR, *TA, *TE, *TI, *UC, *UE, *UP, *US, *VB, *VS,
		*VE, *AL_PARM, *DL_PARM, *UP_PARM, *DOWN_PARM,
		*LEFT_PARM, *RIGHT_PARM;
extern char	PC;
E 16
E 11
E 5
E 2

/*
 * From the tty modes...
 */
D 2
bool	NONL;			/* Term can't hack linefeeds doing a CR	*/
bool	UPPERCASE;		/* Ick!					*/
E 2

D 2
bool	normtty;		/* set if must normal mode from normf	*/
bool	_pfast;			/* Have stty -nl'ed to go faster	*/
E 2
I 2
D 5
bool	NONL, UPPERCASE;
E 5
I 5
D 16
extern bool	NONL, UPPERCASE, normtty, _pfast;
E 16
I 16
extern bool	GT, NONL, UPPERCASE, normtty, _pfast;
E 16
E 5
E 2

D 2
# define	WINDOW	struct _win_st
E 2
I 2
D 5
bool	normtty, _pfast;
E 2

E 5
D 2
struct _win_st {		/* window description structure		*/
	short	_cury, _curx;		/* current y,x positions	*/
	short	_maxy, _maxx;		/* maximum y,x positions	*/
	short	_begy, _begx;		/* start y,x positions		*/
	short	_flags;			/* various window flags		*/
	bool	_clear;			/* need to clear		*/
	bool	_leave;			/* leave curx,y at last update	*/
	bool	_scroll;		/* scrolls allowed		*/
	char	**_y;			/* actual window		*/
	short	*_firstch;		/* first change on line		*/
	short	*_lastch;		/* last change on line		*/
E 2
I 2
struct _win_st {
D 13
	short	_cury, _curx;
	short	_maxy, _maxx;
	short	_begy, _begx;
	short	_flags;
	bool	_clear;
	bool	_leave;
	bool	_scroll;
	char	**_y;
	short	*_firstch;
	short	*_lastch;
E 13
I 13
	short		_cury, _curx;
	short		_maxy, _maxx;
	short		_begy, _begx;
	short		_flags;
I 16
	short		_ch_off;
E 16
	bool		_clear;
	bool		_leave;
	bool		_scroll;
	char		**_y;
	short		*_firstch;
	short		*_lastch;
	struct _win_st	*_nextp, *_orig;
E 13
E 2
};

D 2
extern bool	My_term,	/* set if user species terminal		*/
		_echoit,	/* set if echoing characters		*/
		_rawmode,	/* set if terminal in raw mode		*/
		_endwin;	/* endwin has been called		*/
E 2
I 2
# define	WINDOW	struct _win_st
E 2

D 2
extern char	*Def_term,	/* default terminal type		*/
		ttytype[];	/* long name of current terminal	*/
E 2
I 2
extern bool	My_term, _echoit, _rawmode, _endwin;
E 2

D 2
extern int	LINES, COLS,	/* number of lines and columns		*/
		_tty_ch,	/* channel with tty on it		*/
		_res_flg;	/* sgtty flags stored for reset		*/
E 2
I 2
extern char	*Def_term, ttytype[];
E 2

D 2
# ifdef DEBUG
FILE		*outf;		/* error outfile			*/
# endif
E 2
I 2
extern int	LINES, COLS, _tty_ch, _res_flg;
E 2

D 2
SGTTY		_tty;		/* tty structure			*/
E 2
I 2
D 5
SGTTY		_tty;
E 5
I 5
extern SGTTY	_tty;
E 5
E 2

D 2
WINDOW		*stdscr,	/* standard screen			*/
		*curscr;	/* current screen			*/
E 2
I 2
D 5
WINDOW		*stdscr, *curscr;
E 5
I 5
extern WINDOW	*stdscr, *curscr;
E 5
E 2

/*
 *	Define VOID to stop lint from generating "null effect"
 * comments.
 */
# ifdef lint
D 2
int	__void__;		/* place to assign to			*/
E 2
I 2
int	__void__;
E 2
# define	VOID(x)	(__void__ = (int) (x))
# else
# define	VOID(x)	(x)
# endif

D 3
# endif

E 3
/*
 * psuedo functions for standard screen
 */
# define	addch(ch)	VOID(waddch(stdscr, ch))
# define	getch()		VOID(wgetch(stdscr))
D 19
# define	addstr(str)	VOID(waddstr(stdscr, str))
E 19
I 19
# define	addbytes(da,co)	VOID(waddbytes(stdscr, da,co))
# define	addstr(str)	VOID(waddbytes(stdscr, str, strlen(str)))
E 19
# define	getstr(str)	VOID(wgetstr(stdscr, str))
# define	move(y, x)	VOID(wmove(stdscr, y, x))
# define	clear()		VOID(wclear(stdscr))
# define	erase()		VOID(werase(stdscr))
# define	clrtobot()	VOID(wclrtobot(stdscr))
# define	clrtoeol()	VOID(wclrtoeol(stdscr))
# define	insertln()	VOID(winsertln(stdscr))
# define	deleteln()	VOID(wdeleteln(stdscr))
# define	refresh()	VOID(wrefresh(stdscr))
# define	inch()		VOID(winch(stdscr))
I 7
# define	insch(c)	VOID(winsch(stdscr,c))
I 8
# define	delch()		VOID(wdelch(stdscr))
E 8
E 7
# define	standout()	VOID(wstandout(stdscr))
# define	standend()	VOID(wstandend(stdscr))

/*
 * mv functions
 */
#define	mvwaddch(win,y,x,ch)	VOID(wmove(win,y,x)==ERR?ERR:waddch(win,ch))
#define	mvwgetch(win,y,x)	VOID(wmove(win,y,x)==ERR?ERR:wgetch(win))
D 19
#define	mvwaddstr(win,y,x,str)	VOID(wmove(win,y,x)==ERR?ERR:waddstr(win,str))
E 19
I 19
#define	mvwaddbytes(win,y,x,da,co) \
		VOID(wmove(win,y,x)==ERR?ERR:waddbytes(win,da,co))
#define	mvwaddstr(win,y,x,str) \
		VOID(wmove(win,y,x)==ERR?ERR:waddbytes(win,str,strlen(str)))
E 19
D 10
#define	mvwgetstr(win,y,x)	VOID(wmove(win,y,x)==ERR?ERR:wgetstr(win))
E 10
I 10
#define mvwgetstr(win,y,x,str)  VOID(wmove(win,y,x)==ERR?ERR:wgetstr(win,str))
E 10
#define	mvwinch(win,y,x)	VOID(wmove(win,y,x) == ERR ? ERR : winch(win))
I 8
#define	mvwdelch(win,y,x)	VOID(wmove(win,y,x) == ERR ? ERR : wdelch(win))
E 8
I 7
#define	mvwinsch(win,y,x,c)	VOID(wmove(win,y,x) == ERR ? ERR:winsch(win,c))
E 7
#define	mvaddch(y,x,ch)		mvwaddch(stdscr,y,x,ch)
#define	mvgetch(y,x)		mvwgetch(stdscr,y,x)
I 19
#define	mvaddbytes(y,x,da,co)	mvwaddbytes(stdscr,y,x,da,co)
E 19
#define	mvaddstr(y,x,str)	mvwaddstr(stdscr,y,x,str)
D 10
#define	mvgetstr(y,x)		mvwgetstr(stdscr,y,x)
E 10
I 10
#define mvgetstr(y,x,str)       mvwgetstr(stdscr,y,x,str)
E 10
D 6
#define	mvinch(y,x)		mvwinch(win,y,x)
E 6
I 6
#define	mvinch(y,x)		mvwinch(stdscr,y,x)
I 8
#define	mvdelch(y,x)		mvwdelch(stdscr,y,x)
E 8
I 7
#define	mvinsch(y,x,c)		mvwinsch(stdscr,y,x,c)
E 7
E 6

/*
 * psuedo functions
 */

#define	clearok(win,bf)	 (win->_clear = bf)
#define	leaveok(win,bf)	 (win->_leave = bf)
#define	scrollok(win,bf) (win->_scroll = bf)
#define flushok(win,bf)	 (bf ? (win->_flags |= _FLUSH):(win->_flags &= ~_FLUSH))
#define	getyx(win,y,x)	 y = win->_cury, x = win->_curx
D 12
#define	winch(win)	 (win->_y[win->_cury][win->_curx])
E 12
I 12
#define	winch(win)	 (win->_y[win->_cury][win->_curx] & 0177)
E 12

#define raw()	 (_tty.sg_flags|=RAW, _pfast=_rawmode=TRUE, stty(_tty_ch,&_tty))
#define noraw()	 (_tty.sg_flags&=~RAW,_rawmode=FALSE,_pfast=!(_tty.sg_flags&CRMOD),stty(_tty_ch,&_tty))
D 16
#define crmode() (_tty.sg_flags |= CBREAK, _rawmode = TRUE, stty(_tty_ch,&_tty))
#define nocrmode() (_tty.sg_flags &= ~CBREAK,_rawmode=FALSE,stty(_tty_ch,&_tty))
E 16
I 16
#define cbreak() (_tty.sg_flags |= CBREAK, _rawmode = TRUE, stty(_tty_ch,&_tty))
#define nocbreak() (_tty.sg_flags &= ~CBREAK,_rawmode=FALSE,stty(_tty_ch,&_tty))
#define crmode() cbreak()	/* backwards compatability */
#define nocrmode() nocbreak()	/* backwards compatability */
E 16
#define echo()	 (_tty.sg_flags |= ECHO, _echoit = TRUE, stty(_tty_ch, &_tty))
#define noecho() (_tty.sg_flags &= ~ECHO, _echoit = FALSE, stty(_tty_ch, &_tty))
#define nl()	 (_tty.sg_flags |= CRMOD,_pfast = _rawmode,stty(_tty_ch, &_tty))
#define nonl()	 (_tty.sg_flags &= ~CRMOD, _pfast = TRUE, stty(_tty_ch, &_tty))
D 16
#define	savetty() (gtty(_tty_ch, &_tty), _res_flg = _tty.sg_flags)
#define	resetty() (_tty.sg_flags = _res_flg, stty(_tty_ch, &_tty))
E 16
I 16
#define	savetty() ((void) gtty(_tty_ch, &_tty), _res_flg = _tty.sg_flags)
#define	resetty() (_tty.sg_flags = _res_flg, (void) stty(_tty_ch, &_tty))

#define	erasechar()	(_tty.sg_erase)
#define	killchar()	(_tty.sg_kill)
#define baudrate()	(_tty.sg_ospeed)
E 16

WINDOW	*initscr(), *newwin(), *subwin();
I 2
D 9
char	*longname();
E 9
I 9
char	*longname(), *getcap();
E 9
I 3

I 14
/*
 * Used to be in unctrl.h.
 */
#define	unctrl(c)	_unctrl[(c) & 0177]
I 15
extern char *_unctrl[];
E 15
E 14
# endif
E 3
E 2
E 1
