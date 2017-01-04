h37775
s 00009/00009/00430
d D 7.10 03/04/13 15:19:17 msokolov 18 17
c 8-bit ex
e
s 00027/00019/00412
d D 7.9 87/03/09 12:46:29 conrad 17 16
c make ex/vi work on vms
e
s 00001/00001/00430
d D 7.8 85/06/07 18:21:27 bloom 16 15
c fix sccsid and copyright for xstr
e
s 00010/00002/00421
d D 7.7 85/05/31 13:58:58 dist 15 13
c Add copyright
e
s 00010/00002/00380
d D 5.1.1.1 85/05/31 12:10:15 dist 14 6
c Add copyright
e
s 00001/00000/00422
d D 7.6 85/05/17 15:03:01 bloom 13 12
c make sure terminal state is reset after window reshape
e
s 00027/00000/00395
d D 7.5 85/02/21 17:39:35 bloom 12 11
c add window size change support
e
s 00005/00001/00390
d D 7.4 83/06/18 17:24:51 sam 11 10
c do longjmp's only when we should
e
s 00003/00001/00388
d D 7.3 83/06/15 13:51:23 sam 10 9
c new signals
e
s 00007/00000/00382
d D 7.2 81/09/03 11:45:30 mark 9 8
c updates for Unix/370 and ins/del line on vt100
e
s 00004/00004/00378
d D 7.1 81/07/08 22:31:58 mark 8 7
c release 3.7 - a few bug fixes and a few new features.
e
s 00000/00000/00382
d D 6.1 80/10/19 01:21:47 mark 7 6
c preliminary release 3.6 10/18/80
e
s 00000/00000/00382
d D 5.1 80/08/20 16:12:31 mark 6 5
c Release 3.5, August 20, 1980
e
s 00002/00001/00380
d D 4.2 80/08/01 20:42:09 mark 5 4
c Bill added more buffers, and I put in sccs.
e
s 00010/00003/00371
d D 4.1 80/08/01 00:16:15 mark 4 3
c release 3.4, June 24, 1980
e
s 00002/00002/00372
d D 3.1 80/07/31 23:40:21 mark 3 2
c release 3.3, Feb 2, 1980
e
s 00000/00000/00374
d D 2.1 80/07/31 23:20:04 mark 2 1
c release 3.2, Jan 4, 1980
e
s 00374/00000/00000
d D 1.1 80/07/31 23:00:36 mark 1 0
c date and time created 80/07/31 23:00:36 by mark
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
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 14
E 8
I 8
D 15
/* Copyright (c) 1981 Regents of the University of California */
D 10
static char *sccsid = "%W%	%G%";
E 10
I 10
static char *sccsid = "%W% %G%";
E 15
I 15
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
D 16
static char sccsid[] = "%W% (Berkeley) %G%";
E 16
I 16
static char *sccsid = "%W% (Berkeley) %G%";
E 16
#endif not lint

E 15
E 10
E 8
E 5
#include "ex.h"
#include "ex_re.h"
#include "ex_tty.h"
#include "ex_vis.h"

/*
 * Entry points to open and visual from command mode processor.
 * The open/visual code breaks down roughly as follows:
 *
 * ex_v.c	entry points, checking of terminal characteristics
 *
 * ex_vadj.c	logical screen control, use of intelligent operations
 *		insert/delete line and coordination with screen image;
 *		updating of screen after changes.
 *
 * ex_vget.c	input of single keys and reading of input lines
 *		from the echo area, handling of \ escapes on input for
 *		uppercase only terminals, handling of memory for repeated
 *		commands and small saved texts from inserts and partline
 *		deletes, notification of multi line changes in the echo
 *		area.
 *
 * ex_vmain.c	main command decoding, some command processing.
 *
 * ex_voperate.c   decoding of operator/operand sequences and
 *		contextual scans, implementation of word motions.
 *
 * ex_vops.c	major operator interfaces, undos, motions, deletes,
 *		changes, opening new lines, shifts, replacements and yanks
 *		coordinating logical and physical changes.
 *
 * ex_vops2.c	subroutines for operator interfaces in ex_vops.c,
 *		insert mode, read input line processing at lowest level.
 *
 * ex_vops3.c	structured motion definitions of ( ) { } and [ ] operators,
 *		indent for lisp routines, () and {} balancing. 
 *
 * ex_vput.c	output routines, clearing, physical mapping of logical cursor
 *		positioning, cursor motions, handling of insert character
 *		and delete character functions of intelligent and unintelligent
 *		terminals, visual mode tracing routines (for debugging),
 *		control of screen image and its updating.
 *
 * ex_vwind.c	window level control of display, forward and backward rolls,
 *		absolute motions, contextual displays, line depth determination
 */

I 12
jmp_buf venv;
int	winch();

E 12
/*
 * Enter open mode
 */
I 9
#ifdef u370
D 18
char	atube[TUBESIZE+LBSIZE];
E 18
I 18
u_char	atube[TUBESIZE+LBSIZE];
E 18
#endif
E 9
oop()
{
D 18
	register char *ic;
E 18
I 18
	register u_char *ic;
E 18
I 9
#ifndef u370
E 9
D 18
	char atube[TUBESIZE + LBSIZE];
E 18
I 18
	u_char atube[TUBESIZE + LBSIZE];
E 18
I 9
#endif
E 9
D 4
	register int f;
E 4
I 4
D 8
	register ttymode f;
E 8
I 8
	ttymode f;	/* mjm: was register */
I 12
D 17
	int resize;
E 17
E 12
E 8
E 4

I 12
D 17
	if (resize = setjmp(venv)) {
E 17
I 17
	if (setjmp(venv)) {
E 17
		setsize();
D 18
		initev = (char *)0;
E 18
I 18
		initev = (u_char *)0;
E 18
		inopen = 0;
		addr1 = addr2 = dot;
	}
I 17
#ifdef	SIGWINCH
E 17
	(void)signal(SIGWINCH, winch);
I 17
#endif
E 17
E 12
	ovbeg();
	if (peekchar() == '/') {
D 17
		ignore(compile(getchar(), 1));
E 17
I 17
		ignore(compile(ex_getchar(), 1));
E 17
		savere(scanre);
		if (execute(0, dot) == 0)
			error("Fail|Pattern not found on addressed line");
		ic = loc1;
		if (ic > linebuf && *ic == 0)
			ic--;
	} else {
		getDOT();
		ic = vskipwh(linebuf);
	}
	newline();

	/*
	 * If overstrike then have to HARDOPEN
	 * else if can move cursor up off current line can use CRTOPEN (~~vi1)
	 * otherwise (ugh) have to use ONEOPEN (like adm3)
	 */
	if (OS && !EO)
		bastate = HARDOPEN;
	else if (CA || UP)
		bastate = CRTOPEN;
	else
		bastate = ONEOPEN;
	setwind();

	/*
	 * To avoid bombing on glass-crt's when the line is too long
	 * pretend that such terminals are 160 columns wide.
	 * If a line is too wide for display, we will dynamically
	 * switch to hardcopy open mode.
	 */
	if (state != CRTOPEN)
		WCOLS = TUBECOLS;
	if (!inglobal)
		savevis();
	vok(atube);
	if (state != CRTOPEN)
		COLUMNS = WCOLS;
	Outchar = vputchar;
	f = ostart();
	if (state == CRTOPEN) {
		if (outcol == UKCOL)
			outcol = 0;
		vmoveitup(1, 1);
	} else
		outline = destline = WBOT;
	vshow(dot, NOLINE);
	vnline(ic);
	vmain();
	if (state != CRTOPEN)
		vclean();
	Command = "open";
	ovend(f);
I 17
#ifdef	SIGWINCH
E 17
I 12
	(void)signal(SIGWINCH, SIG_DFL);
I 17
#endif
E 17
E 12
}

ovbeg()
{

	if (!value(OPEN))
		error("Can't use open/visual unless open option is set");
	if (inopen)
		error("Recursive open/visual not allowed");
	Vlines = lineDOL();
	fixzero();
	setdot();
	pastwh();
	dot = addr2;
}

ovend(f)
D 4
	int f;
E 4
I 4
	ttymode f;
E 4
{

	splitw++;
	vgoto(WECHO, 0);
	vclreol();
	vgoto(WECHO, 0);
	holdcm = 0;
	splitw = 0;
	ostop(f);
	setoutt();
	undvis();
	COLUMNS = OCOLUMNS;
	inopen = 0;
	flusho();
	netchHAD(Vlines);
}

/*
 * Enter visual mode
 */
vop()
{
	register int c;
I 9
#ifndef u370
E 9
D 18
	char atube[TUBESIZE + LBSIZE];
E 18
I 18
	u_char atube[TUBESIZE + LBSIZE];
E 18
I 9
#endif
E 9
D 4
	register int f;
E 4
I 4
D 8
	register ttymode f;
E 8
I 8
	ttymode f;	/* mjm: was register */
I 12
D 17
	int resize;
E 17
E 12
E 8
E 4

	if (!CA && UP == NOSTR) {
		if (initev) {
toopen:
			merror("[Using open mode]");
			putNFL();
			oop();
			return;
		}
		error("Visual needs addressible cursor or upline capability");
	}
	if (OS && !EO) {
		if (initev)
			goto toopen;
		error("Can't use visual on a terminal which overstrikes");
	}
	if (!CL) {
		if (initev)
			goto toopen;
		error("Visual requires clear screen capability");
	}
I 4
	if (NS && !SF) {
		if (initev)
			goto toopen;
		error("Visual requires scrolling");
	}
I 12
D 17
	if (resize = setjmp(venv)) {
E 17
I 17
	if (setjmp(venv)) {
E 17
		setsize();
D 18
		initev = (char *)0;
E 18
I 18
		initev = (u_char *)0;
E 18
		inopen = 0;
		addr1 = addr2 = dot;
	}
I 17
#ifdef	SIGWINCH
E 17
	(void)signal(SIGWINCH, winch);
I 17
#endif
E 17
E 12
E 4
	ovbeg();
	bastate = VISUAL;
	c = 0;
	if (any(peekchar(), "+-^."))
D 17
		c = getchar();
E 17
I 17
		c = ex_getchar();
E 17
	pastwh();
	vsetsiz(isdigit(peekchar()) ? getnum() : value(WINDOW));
	setwind();
	newline();
	vok(atube);
	if (!inglobal)
		savevis();
	Outchar = vputchar;
	vmoving = 0;
	f = ostart();
	if (initev == 0) {
		vcontext(dot, c);
		vnline(NOSTR);
	}
	vmain();
	Command = "visual";
	ovend(f);
I 17
#ifdef	SIGWINCH
E 17
I 12
	(void)signal(SIGWINCH, SIG_DFL);
I 17
#endif
E 17
E 12
}

/*
 * Hack to allow entry to visual with
 * empty buffer since routines internally
 * demand at least one line.
 */
fixzero()
{

	if (dol == zero) {
		register bool ochng = chng;

		vdoappend("");
		if (!ochng)
D 17
			sync();
E 17
I 17
			ex_sync();
E 17
		addr1 = addr2 = one;
	} else if (addr2 == zero)
		addr2 = one;
}

/*
 * Save lines before visual between unddol and truedol.
 * Accomplish this by throwing away current [unddol,truedol]
 * and then saving all the lines in the buffer and moving
 * unddol back to dol.  Don't do this if in a global.
 *
 * If you do
 *	g/xxx/vi.
 * and then do a
 *	:e xxxx
 * at some point, and then quit from the visual and undo
 * you get the old file back.  Somewhat weird.
 */
savevis()
{

	if (inglobal)
		return;
	truedol = unddol;
	saveall();
	unddol = dol;
	undkind = UNDNONE;
}

/*
 * Restore a sensible state after a visual/open, moving the saved
 * stuff back to [unddol,dol], and killing the partial line kill indicators.
 */
undvis()
{

	if (ruptible)
		signal(SIGINT, onintr);
	squish();
	pkill[0] = pkill[1] = 0;
	unddol = truedol;
	unddel = zero;
	undap1 = one;
	undap2 = dol + 1;
	undkind = UNDALL;
I 4
	if (undadot <= zero || undadot > dol)
		undadot = zero+1;
E 4
}

/*
 * Set the window parameters based on the base state bastate
 * and the available buffer space.
 */
setwind()
{

	WCOLS = COLUMNS;
	switch (bastate) {

	case ONEOPEN:
		if (AM)
			WCOLS--;
		/* fall into ... */

	case HARDOPEN:
		basWTOP = WTOP = WBOT = WECHO = 0;
D 17
		ZERO = 0;
E 17
I 17
		ex_ZERO = 0;
E 17
		holdcm++;
		break;

	case CRTOPEN:
		basWTOP = LINES - 2;
		/* fall into */

	case VISUAL:
D 17
		ZERO = LINES - TUBESIZE / WCOLS;
		if (ZERO < 0)
			ZERO = 0;
		if (ZERO > basWTOP)
E 17
I 17
		ex_ZERO = LINES - TUBESIZE / WCOLS;
		if (ex_ZERO < 0)
			ex_ZERO = 0;
		if (ex_ZERO > basWTOP)
E 17
			error("Screen too large for internal buffer");
		WTOP = basWTOP; WBOT = LINES - 2; WECHO = LINES - 1;
		break;
	}
	state = bastate;
	basWLINES = WLINES = WBOT - WTOP + 1;
}

/*
 * Can we hack an open/visual on this terminal?
 * If so, then divide the screen buffer up into lines,
 * and initialize a bunch of state variables before we start.
 */
vok(atube)
D 18
	register char *atube;
E 18
I 18
	register u_char *atube;
E 18
{
	register int i;

	if (WCOLS == 1000)
		serror("Don't know enough about your terminal to use %s", Command);
	if (WCOLS > TUBECOLS)
		error("Terminal too wide");
D 17
	if (WLINES >= TUBELINES || WCOLS * (WECHO - ZERO + 1) > TUBESIZE)
E 17
I 17
	if (WLINES >= TUBELINES || WCOLS * (WECHO - ex_ZERO + 1) > TUBESIZE)
E 17
		error("Screen too large");

	vtube0 = atube;
D 17
	vclrbyte(atube, WCOLS * (WECHO - ZERO + 1));
	for (i = 0; i < ZERO; i++)
E 17
I 17
	vclrbyte(atube, WCOLS * (WECHO - ex_ZERO + 1));
	for (i = 0; i < ex_ZERO; i++)
E 17
D 3
		vtube[i] = (char *) -20000;
E 3
I 3
D 18
		vtube[i] = (char *) 0;
E 18
I 18
		vtube[i] = (u_char *) 0;
E 18
E 3
	for (; i <= WECHO; i++)
		vtube[i] = atube, atube += WCOLS;
	for (; i < TUBELINES; i++)
D 3
		vtube[i] = (char *) -20000;
E 3
I 3
D 18
		vtube[i] = (char *) 0;
E 18
I 18
		vtube[i] = (u_char *) 0;
E 18
E 3
	vutmp = atube;
	vundkind = VNONE;
	vUNDdot = 0;
	OCOLUMNS = COLUMNS;
	inopen = 1;
#ifdef CBREAK
	signal(SIGINT, vintr);
#endif
	vmoving = 0;
	splitw = 0;
	doomed = 0;
	holdupd = 0;
D 17
	Peekkey = 0;
E 17
I 17
	Peek_key = 0;
E 17
	vcnt = vcline = 0;
D 17
	if (vSCROLL == 0)
		vSCROLL = (value(WINDOW)+1)/2;	/* round up so dft=6,11 */
E 17
I 17
	if (ex_vSCROLL == 0)
		ex_vSCROLL = (value(WINDOW)+1)/2; /* round up so dft=6,11 */
E 17
}

#ifdef CBREAK
vintr()
{
I 10
	extern jmp_buf readbuf;
I 11
	extern int doingread;
E 11
E 10

	signal(SIGINT, vintr);
	if (vcatch)
		onintr();
	ungetkey(ATTN);
	draino();
I 10
D 11
	longjmp(readbuf, 1);
E 11
I 11
	if (doingread) {
		doingread = 0;
		longjmp(readbuf, 1);
	}
E 11
E 10
}
#endif

/*
 * Set the size of the screen to size lines, to take effect the
 * next time the screen is redrawn.
 */
vsetsiz(size)
	int size;
{
	register int b;

	if (bastate != VISUAL)
		return;
	b = LINES - 1 - size;
	if (b >= LINES - 1)
		b = LINES - 2;
	if (b < 0)
		b = 0;
	basWTOP = b;
	basWLINES = WBOT - b + 1;
I 12
}

I 17
#ifdef	SIGWINCH
E 17
winch()
{
	vsave();
I 13
D 17
	setty(normf);
E 17
I 17
	ignore(setty(normf));
E 17
E 13
	longjmp(venv, 1);
E 12
}
I 17
#endif
E 17
E 1
