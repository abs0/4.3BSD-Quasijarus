h62026
s 00020/00020/00247
d D 7.13 03/04/13 15:19:12 msokolov 22 21
c 8-bit ex
e
s 00002/00002/00265
d D 7.12 88/01/02 23:12:29 bostic 21 20
c fix CTRL macro for ANSI C
e
s 00010/00005/00257
d D 7.11 87/03/09 12:47:19 conrad 20 19
c make ex/vi work on vms
e
s 00001/00001/00261
d D 7.10 85/06/07 18:21:11 bloom 19 18
c fix sccsid and copyright for xstr
e
s 00010/00002/00252
d D 7.9 85/05/31 13:58:15 dist 18 16
c Add copyright
e
s 00010/00002/00183
d D 5.1.1.1 85/05/31 12:09:24 dist 17 6
c Add copyright
e
s 00037/00022/00217
d D 7.8 85/02/21 17:35:29 bloom 16 15
c add window size change support
e
s 00004/00001/00235
d D 7.7 84/12/11 13:24:02 ralph 15 14
c fixes for vt100.
e
s 00002/00001/00234
d D 7.6 83/06/10 10:09:01 ralph 14 13
c updating sccs files due to restoring an older SCCS directory
e
s 00001/00000/00234
d D 7.5 81/10/16 08:31:08 mark 13 12
c last minute fixes before release of 3.7
e
s 00012/00007/00222
d D 7.4 81/09/09 14:25:21 mark 12 11
c improved vt100 interface.  also uses parm termcap entries.
e
s 00001/00001/00228
d D 7.3 81/09/04 11:02:56 mark 11 10
c fixed another USG tty driver NL bug
e
s 00013/00005/00216
d D 7.2 81/09/03 11:45:12 mark 10 9
c updates for Unix/370 and ins/del line on vt100
e
s 00006/00006/00215
d D 7.1 81/07/08 22:31:37 mark 9 8
c release 3.7 - a few bug fixes and a few new features.
e
s 00004/00002/00217
d D 6.2 80/10/30 20:41:08 mark 8 7
c fixed it to work on terminals with over 48 lines, and fixed bug 
c which allowed setting a huge window
e
s 00035/00001/00184
d D 6.1 80/10/19 01:21:34 mark 7 6
c preliminary release 3.6 10/18/80
e
s 00000/00000/00185
d D 5.1 80/08/20 16:11:58 mark 6 5
c Release 3.5, August 20, 1980
e
s 00002/00001/00183
d D 4.2 80/08/01 20:41:31 mark 5 4
c Bill added more buffers, and I put in sccs.
e
s 00044/00013/00140
d D 4.1 80/08/01 00:15:54 mark 4 3
c release 3.4, June 24, 1980
e
s 00004/00004/00149
d D 3.1 80/07/31 23:39:53 mark 3 2
c release 3.3, Feb 2, 1980
e
s 00000/00000/00153
d D 2.1 80/07/31 23:19:52 mark 2 1
c release 3.2, Jan 4, 1980
e
s 00153/00000/00000
d D 1.1 80/07/31 23:00:31 mark 1 0
c date and time created 80/07/31 23:00:31 by mark
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
E 9
I 9
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
E 9
E 5
#include "ex.h"
#include "ex_tty.h"

/*
 * Terminal type initialization routines,
 * and calculation of flags at entry or after
 * a shell escape which may change them.
 */
D 9
short	ospeed = -1;
E 9
I 9
/* short	ospeed = -1;	mjm: def also in tputs.c of termcap.a  */
E 9

gettmode()
{

I 4
#ifndef USG3TTY
E 4
	if (gtty(1, &tty) < 0)
		return;
	if (ospeed != tty.sg_ospeed)
		value(SLOWOPEN) = tty.sg_ospeed < B1200;
	ospeed = tty.sg_ospeed;
	normf = tty.sg_flags;
	UPPERCASE = (tty.sg_flags & LCASE) != 0;
	GT = (tty.sg_flags & XTABS) != XTABS && !XT;
	NONL = (tty.sg_flags & CRMOD) == 0;
I 4
#else
D 20
	if (ioctl(1, TCGETA, &tty) < 0)
E 20
I 20
D 22
	if (ioctl(1, TCGETA, (char *) &tty) < 0)
E 22
I 22
	if (ioctl(1, TCGETA, (u_char *) &tty) < 0)
E 22
E 20
		return;
D 9
	if (ospeed != tty.c_cflag & CBAUD)
E 9
I 9
	if (ospeed != (tty.c_cflag & CBAUD))	/* mjm */
E 9
		value(SLOWOPEN) = (tty.c_cflag & CBAUD) < B1200;
	ospeed = tty.c_cflag & CBAUD;
	normf = tty;
	UPPERCASE = (tty.c_iflag & IUCLC) != 0;
	GT = (tty.c_oflag & TABDLY) != TAB3 && !XT;
D 11
	NONL = (tty.c_oflag & OCRNL) == 0;
E 11
I 11
	NONL = (tty.c_oflag & ONLCR) == 0;
E 11
#endif
E 4
}

D 22
char *xPC;
char **sstrs[] = {
E 22
I 22
u_char *xPC;
u_char **sstrs[] = {
E 22
D 4
	&AL, &BC, &BT, &CD, &CE, &CL, &CM, &DC, &DL, &DM, &DO, &ED, &EI,
E 4
I 4
D 12
	&AL, &BC, &BT, &CD, &CE, &CL, &CM, &xCR, &DC, &DL, &DM, &DO, &ED, &EI,
E 4
	&F0, &F1, &F2, &F3, &F4, &F5, &F6, &F7, &F8, &F9,
E 12
I 12
	&AL, &BC, &BT, &CD, &CE, &CL, &CM, &xCR, &CS, &DC, &DL, &DM, &DO,
	&ED, &EI, &F0, &F1, &F2, &F3, &F4, &F5, &F6, &F7, &F8, &F9,
E 12
D 10
	&HO, &IC, &IM, &IP, &KD, &KE, &KH, &KL, &KR, &KS, &KU, &LL,
D 4
	&ND, &xPC, &SE, &SF, &SO, &SR, &TA, &TE, &TI, &UP, &VB, &VS, &VE
E 4
I 4
	&ND, &xNL, &xPC, &SE, &SF, &SO, &SR, &TA, &TE, &TI, &UP, &VB, &VS, &VE
E 10
I 10
	&HO, &IC, &IM, &IP, &KD, &KE, &KH, &KL, &KR, &KS, &KU, &LL, &ND, &xNL,
D 12
	&xPC, &SE, &SF, &SO, &SR, &TA, &TE, &TI, &UP, &VA, &VB, &VD, &VS, &VE
E 12
I 12
	&xPC, &RC, &SC, &SE, &SF, &SO, &SR, &TA, &TE, &TI, &UP, &VB, &VS, &VE,
	&AL_PARM, &DL_PARM, &UP_PARM, &DOWN_PARM, &LEFT_PARM, &RIGHT_PARM
E 12
E 10
E 4
};
bool *sflags[] = {
D 4
	&AM, &BS, &DA, &DB, &EO, &HC, &HZ, &IN, &MI, &NC, &OS, &UL, &XN, &XT
E 4
I 4
	&AM, &BS, &DA, &DB, &EO, &HC, &HZ, &IN, &MI, &NC, &NS, &OS, &UL,
D 9
	&XB, &XN, &XT, &XX
E 9
I 9
D 10
	&XB, &XN, &XT, &XV, &XX
E 10
I 10
	&XB, &XN, &XT, &XX
E 10
E 9
E 4
};
D 22
char **fkeys[10] = {
E 22
I 22
u_char **fkeys[10] = {
E 22
	&F0, &F1, &F2, &F3, &F4, &F5, &F6, &F7, &F8, &F9
};
setterm(type)
D 22
	char *type;
E 22
I 22
	u_char *type;
E 22
{
D 4
	char *cgoto();
E 4
I 4
	char *tgoto();
E 4
D 16
	register int unknown, i;
	register int l;
E 16
I 16
	register int unknown;
E 16
D 22
	char ltcbuf[TCBUFSIZE];
E 22
I 22
	u_char ltcbuf[TCBUFSIZE];
E 22

	if (type[0] == 0)
		type = "xx";
	unknown = 0;
	putpad(TE);
	if (tgetent(ltcbuf, type) != 1) {
		unknown++;
D 3
		CP(genbuf, "xx|dumb:");
E 3
I 3
		CP(ltcbuf, "xx|dumb:");
E 3
	}
D 16
	i = LINES = tgetnum("li");
	if (LINES <= 5)
		LINES = 24;
D 8
	if (LINES > 48)
		LINES = 48;
E 8
I 8
	if (LINES > TUBELINES)
		LINES = TUBELINES;
E 8
	l = LINES;
	if (ospeed < B1200)
D 3
		l /= 2;
E 3
I 3
		l = 9;	/* including the message line at the bottom */
E 3
	else if (ospeed < B2400)
D 3
		l = (l * 2) / 3;
E 3
I 3
		l = 17;
I 8
	if (l > LINES)
		l = LINES;
E 16
I 16
	setsize();
E 16
E 8
E 3
	aoftspace = tspace;
	zap();
	/*
	 * Initialize keypad arrow keys.
	 */
	arrows[0].cap = KU; arrows[0].mapto = "k"; arrows[0].descr = "up";
	arrows[1].cap = KD; arrows[1].mapto = "j"; arrows[1].descr = "down";
	arrows[2].cap = KL; arrows[2].mapto = "h"; arrows[2].descr = "left";
	arrows[3].cap = KR; arrows[3].mapto = "l"; arrows[3].descr = "right";
	arrows[4].cap = KH; arrows[4].mapto = "H"; arrows[4].descr = "home";

I 10
	/*
	 * Handle funny termcap capabilities
	 */
D 12
	if (VA) AL="";
	if (VD) DL="";
E 12
I 12
D 15
	if (CS && SC && RC) AL=DL="";
E 15
I 15
	if (CS && SC && RC) {
		if (AL==NULL) AL="";
		if (DL==NULL) DL="";
	}
E 15
	if (AL_PARM && AL==NULL) AL="";
	if (DL_PARM && DL==NULL) DL="";
E 12
	if (IC && IM==NULL) IM="";
	if (IC && EI==NULL) EI="";
I 13
	if (!GT) BT=NULL;	/* If we can't tab, we can't backtab either */
E 13

E 10
I 4
#ifdef TIOCLGET
	/*
	 * Now map users susp char to ^Z, being careful that the susp
	 * overrides any arrow key, but only for hackers (=new tty driver).
	 */
	{
D 22
		static char sc[2];
E 22
I 22
		static u_char sc[2];
E 22
D 20
		int i, fnd;
E 20
I 20
		int i;
E 20

D 20
		ioctl(0, TIOCGETD, &ldisc);
E 20
I 20
D 22
		ioctl(0, TIOCGETD, (char *) &ldisc);
E 22
I 22
		ioctl(0, TIOCGETD, (u_char *) &ldisc);
E 22
E 20
		if (ldisc == NTTYDISC) {
			sc[0] = olttyc.t_suspc;
			sc[1] = 0;
D 21
			if (olttyc.t_suspc == CTRL(z)) {
E 21
I 21
			if (olttyc.t_suspc == CTRL('z')) {
E 21
				for (i=0; i<=4; i++)
D 14
					if (arrows[i].cap[0] == CTRL(z))
E 14
I 14
					if (arrows[i].cap &&
D 21
					    arrows[i].cap[0] == CTRL(z))
E 21
I 21
					    arrows[i].cap[0] == CTRL('z'))
E 21
E 14
D 20
						addmac(sc, NULL, NULL, arrows);
E 20
I 20
D 22
						addmac(sc, (char *) NULL,
							(char *) NULL, arrows);
E 22
I 22
						addmac(sc, (u_char *) NULL,
							(u_char *) NULL, arrows);
E 22
E 20
			} else
				addmac(sc, "\32", "susp", arrows);
		}
	}
#endif

E 4
D 16
	options[WINDOW].ovalue = options[WINDOW].odefault = l - 1;
	if (defwind) options[WINDOW].ovalue = defwind;
	options[SCROLL].ovalue = options[SCROLL].odefault = HC ? 11 : ((l-1) / 2);
	COLUMNS = tgetnum("co");
D 4
	if (COLUMNS <= 20)
E 4
I 4
	if (COLUMNS <= 4)
E 4
		COLUMNS = 1000;
E 16
D 4
	if (cgoto()[0] == 'O')	/* OOPS */
E 4
I 4
	if (tgoto(CM, 2, 2)[0] == 'O')	/* OOPS */
E 4
		CA = 0, CM = 0;
	else
D 7
		CA = 1, costCM = strlen(tgoto(CM, 8, 10));
E 7
I 7
		CA = 1, costCM = cost(tgoto(CM, 8, 10));
	costSR = cost(SR);
	costAL = cost(AL);
I 12
	costDP = cost(tgoto(DOWN_PARM, 10, 10));
	costLP = cost(tgoto(LEFT_PARM, 10, 10));
	costRP = cost(tgoto(RIGHT_PARM, 10, 10));
E 12
E 7
	PC = xPC ? xPC[0] : 0;
	aoftspace = tspace;
D 3
	CP(ttytype, longname(genbuf, type));
E 3
I 3
	CP(ttytype, longname(ltcbuf, type));
E 3
D 16
	if (i <= 0)
		LINES = 2;
E 16
	/* proper strings to change tty type */
D 4
#ifdef notdef
	/* Taken out because we don't allow it. See ex_set.c for reasons. */
	if (inopen)
		putpad(VE);
#endif
E 4
	termreset();
	gettmode();
	value(REDRAW) = AL && DL;
	value(OPTIMIZE) = !CA && !GT;
I 7
	if (ospeed == B1200 && !value(REDRAW))
		value(SLOWOPEN) = 1;	/* see also gettmode above */
E 7
	if (unknown)
		serror("%s: Unknown terminal type", type);
I 16
}

setsize()
{
	register int l, i;
I 20
#ifdef	TIOCGWINSZ
E 20
	struct winsize win;

D 20
	if (ioctl(0, TIOCGWINSZ, &win) < 0) {
E 20
I 20
D 22
	if (ioctl(0, TIOCGWINSZ, (char *) &win) < 0) {
E 22
I 22
	if (ioctl(0, TIOCGWINSZ, (u_char *) &win) < 0) {
E 22
#endif
E 20
		i = LINES = tgetnum("li");
		COLUMNS = tgetnum("co");
I 20
#ifdef	TIOCGWINSZ
E 20
	} else {
		if ((LINES = winsz.ws_row = win.ws_row) == 0)
			LINES = tgetnum("li");
		i = LINES;
		if ((COLUMNS = winsz.ws_col = win.ws_col) == 0)
			COLUMNS = tgetnum("co");
	}
I 20
#endif
E 20
	if (LINES <= 5)
		LINES = 24;
	if (LINES > TUBELINES)
		LINES = TUBELINES;
	l = LINES;
	if (ospeed < B1200)
		l = 9;	/* including the message line at the bottom */
	else if (ospeed < B2400)
		l = 17;
	if (l > LINES)
		l = LINES;
	if (COLUMNS <= 4)
		COLUMNS = 1000;
	options[WINDOW].ovalue = options[WINDOW].odefault = l - 1;
	if (defwind) options[WINDOW].ovalue = defwind;
	options[SCROLL].ovalue = options[SCROLL].odefault = HC ? 11 : ((l-1) / 2);
	if (i <= 0)
		LINES = 2;
E 16
}

zap()
{
D 22
	register char *namp;
E 22
I 22
	register u_char *namp;
E 22
	register bool **fp;
D 22
	register char ***sp;
E 22
I 22
	register u_char ***sp;
E 22

D 4
 	namp = "ambsdadbeohchzinmincosulxnxt";
E 4
I 4
D 9
 	namp = "ambsdadbeohchzinmincnsosulxbxnxtxx";
E 9
I 9
D 10
	namp = "ambsdadbeohchzinmincnsosulxbxnxtxvxx";
E 10
I 10
	namp = "ambsdadbeohchzinmincnsosulxbxnxtxx";
E 10
E 9
E 4
	fp = sflags;
	do {
		*(*fp++) = tgetflag(namp);
		namp += 2;
	} while (*namp);
D 4
	namp = "albcbtcdceclcmdcdldmdoedeik0k1k2k3k4k5k6k7k8k9hoicimipkdkekhklkrkskullndpcsesfsosrtatetiupvbvsve";
E 4
I 4
D 10
	namp = "albcbtcdceclcmcrdcdldmdoedeik0k1k2k3k4k5k6k7k8k9hoicimipkdkekhklkrkskullndnlpcsesfsosrtatetiupvbvsve";
E 10
I 10
D 12
	namp = "albcbtcdceclcmcrdcdldmdoedeik0k1k2k3k4k5k6k7k8k9hoicimipkdkekhklkrkskullndnlpcsesfsosrtatetiupvavbvdvsve";
E 12
I 12
	namp = "albcbtcdceclcmcrcsdcdldmdoedeik0k1k2k3k4k5k6k7k8k9hoicimipkdkekhklkrkskullndnlpcrcscsesfsosrtatetiupvbvsveALDLUPDOLERI";
E 12
E 10
E 4
	sp = sstrs;
	do {
		*(*sp++) = tgetstr(namp, &aoftspace);
		namp += 2;
	} while (*namp);
}

D 22
char *
E 22
I 22
u_char *
E 22
longname(bp, def)
D 22
	register char *bp;
	char *def;
E 22
I 22
	register u_char *bp;
	u_char *def;
E 22
{
D 22
	register char *cp;
E 22
I 22
	register u_char *cp;
E 22

	while (*bp && *bp != ':' && *bp != '|')
		bp++;
	if (*bp == '|') {
		bp++;
		cp = bp;
		while (*cp && *cp != ':' && *cp != '|')
			cp++;
		*cp = 0;
		return (bp);
	}
	return (def);
}

D 22
char *
E 22
I 22
u_char *
E 22
fkey(i)
	int i;
{
	if (0 <= i && i <= 9)
		return(*fkeys[i]);
	else
		return(NOSTR);
I 7
}

/*
 * cost figures out how much (in characters) it costs to send the string
 * str to the terminal.  It takes into account padding information, as
 * much as it can, for a typical case.  (Right now the typical case assumes
 * the number of lines affected is the size of the screen, since this is
 * mainly used to decide if AL or SR is better, and this always happens
 * at the top of the screen.  We assume cursor motion (CM) has little
 * padding, if any, required, so that case, which is really more important
 * than AL vs SR, won't be really affected.)
 */
static int costnum;
cost(str)
D 22
char *str;
E 22
I 22
u_char *str;
E 22
{
	int countnum();

D 12
	if (str == NULL)
E 12
I 12
	if (str == NULL || *str=='O')	/* OOPS */
E 12
		return 10000;	/* infinity */
	costnum = 0;
	tputs(str, LINES, countnum);
	return costnum;
}

/* ARGSUSED */
countnum(ch)
D 22
char ch;
E 22
I 22
u_char ch;
E 22
{
	costnum++;
E 7
}
E 1
