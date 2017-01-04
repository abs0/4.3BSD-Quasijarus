h30643
s 00010/00005/00206
d D 5.4 88/06/30 17:21:23 bostic 21 20
c install approved copyright notice
e
s 00010/00004/00201
d D 5.3 88/06/08 13:56:51 bostic 20 19
c written by Ken Arnold; add Berkeley specific header
e
s 00002/00001/00203
d D 5.2 85/11/08 17:18:32 bloom 19 18
c make sure fetching the terminal type doesn't clobber anything
e
s 00010/00001/00194
d D 5.1 85/06/07 11:27:08 dist 18 17
c Add copyright
e
s 00014/00009/00181
d D 1.17 85/05/23 15:41:29 bloom 17 16
c add support for XS (from arnold)
e
s 00058/00039/00132
d D 1.16 85/05/01 16:50:04 bloom 16 15
c new version from arnold
e
s 00008/00000/00163
d D 1.15 85/02/21 11:33:25 bloom 15 14
c do ioctl to get window size
e
s 00005/00004/00158
d D 1.14 83/06/01 14:05:55 arnold 14 13
c only use SO or US if SG or UG are 0
e
s 00001/00004/00161
d D 1.13 83/05/19 12:11:10 arnold 13 12
c no check for too many lines or columns
e
s 00002/00002/00163
d D 1.12 83/03/27 15:08:38 arnold 12 11
c 
e
s 00001/00001/00164
d D 1.11 82/04/01 12:13:26 arnold 11 10
c make checking for SG and UG work properly
e
s 00006/00006/00159
d D 1.10 82/02/17 14:12:15 arnold 10 9
c adopt latest version of fgoto() and plod() from vi
e
s 00000/00002/00165
d D 1.9 82/02/16 16:02:36 arnold 9 8
c should undef DEBUG
e
s 00001/00001/00166
d D 1.8 81/10/31 17:16:23 arnold 8 7
c increase size of tspace
e
s 00007/00004/00160
d D 1.7 81/10/26 00:32:45 arnold 7 6
c don't support terminals with garbage for standout
e
s 00002/00000/00162
d D 1.6 81/10/26 00:12:14 arnold 6 5
c properly define tgetent()
e
s 00001/00000/00161
d D 1.5 81/10/26 00:01:54 arnold 5 4
c stty to turn off tab expansion on ALL terminals
e
s 00010/00000/00151
d D 1.4 81/05/15 16:22:14 arnold 4 3
c add getcap function
e
s 00001/00000/00150
d D 1.3 81/04/28 12:19:12 arnold 3 2
c turn off tab expansion for cursor addressing
e
s 00001/00001/00149
d D 1.2 81/02/17 15:43:21 arnold 2 1
c make it so that longname() is not redefined here
e
s 00150/00000/00000
d D 1.1 81/01/26 17:02:44 arnold 1 0
c date and time created 81/01/26 17:02:44 by arnold
e
u
U
t
T
I 1
/*
I 18
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
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 20
#endif not lint
E 20
I 20
#endif /* not lint */
E 20

/*
E 18
 * Terminal initialization routines.
 *
D 16
 * %G% (Berkeley) %W%
E 16
I 16
D 18
 * %W% (Berkeley) %G%
E 18
E 16
 */

D 9
# undef	DEBUG

E 9
# include	"curses.ext"
D 10
# include	"cr_ex.h"
E 10

D 16
static bool	*sflags[]	= {
			&AM, &BS, &EO, &HZ, &IN, &MI, &MS, &NC, &OS, &UL, &XN
E 16
I 16
static bool	*sflags[] = {
			&AM, &BS, &DA, &DB, &EO, &HC, &HZ, &IN, &MI,
D 17
			&MS, &NC, &NS, &OS, &UL, &XB, &XN, &XT, &XX
E 17
I 17
			&MS, &NC, &NS, &OS, &UL, &XB, &XN, &XT, &XS,
			&XX
E 17
E 16
		};

D 16
static char	*xPC,
		**sstrs[]	= {
D 10
			&AL, &BC,  &BT, &CD, &CE, &CL, &CM, &DC, &DL,
			&DM, &DO,  &ED, &EI, &HO, &IC, &IM, &IP, &LL,
			&MA, &ND, &xPC, &SE, &SF, &SO, &SR, &TA, &TE,
			&TI, &UC,  &UE, &UP, &US, &VB, &VS, &VE
E 10
I 10
			&AL, &BC, &BT, &CD,  &CE, &CL, &CM, &CR, &DC,
			&DL, &DM, &DO, &ED,  &EI, &HO, &IC, &IM, &IP,
			&LL, &MA, &ND, &NL, &xPC, &SE, &SF, &SO, &SR,
			&TA, &TE, &TI, &UC,  &UE, &UP, &US, &VB, &VS,
			&VE
E 16
I 16
static char	*_PC,
		**sstrs[] = {
			&AL, &BC, &BT, &CD, &CE, &CL, &CM, &CR, &CS,
			&DC, &DL, &DM, &DO, &ED, &EI, &K0, &K1, &K2,
			&K3, &K4, &K5, &K6, &K7, &K8, &K9, &HO, &IC,
			&IM, &IP, &KD, &KE, &KH, &KL, &KR, &KS, &KU,
			&LL, &MA, &ND, &NL, &_PC, &RC, &SC, &SE, &SF,
			&SO, &SR, &TA, &TE, &TI, &UC, &UE, &UP, &US,
			&VB, &VS, &VE, &AL_PARM, &DL_PARM, &UP_PARM,
			&DOWN_PARM, &LEFT_PARM, &RIGHT_PARM,
E 16
E 10
		},
D 2
		*longname(), *tgoto();
E 2
I 2
		*tgoto();
E 2

D 8
static char	tspace[128],		/* Space for capability strings */
E 8
I 8
D 16
static char	tspace[256],		/* Space for capability strings */
E 8
		*aoftspace;		/* Address of tspace for relocation */
E 16
I 16
char		_tspace[2048];		/* Space for capability strings */
E 16

I 16
static char	*aoftspace;		/* Address of _tspace for relocation */

E 16
static int	destcol, destline;

/*
 *	This routine does terminal type initialization routines, and
 * calculation of flags at entry.  It is almost entirely stolen from
 * Bill Joy's ex version 2.6.
 */
short	ospeed = -1;

gettmode() {

	if (gtty(_tty_ch, &_tty) < 0)
		return;
	savetty();
	if (stty(_tty_ch, &_tty) < 0)
		_tty.sg_flags = _res_flg;
	ospeed = _tty.sg_ospeed;
	_res_flg = _tty.sg_flags;
	UPPERCASE = (_tty.sg_flags & LCASE) != 0;
	GT = ((_tty.sg_flags & XTABS) == 0);
	NONL = ((_tty.sg_flags & CRMOD) == 0);
I 3
	_tty.sg_flags &= ~XTABS;
I 5
	stty(_tty_ch, &_tty);
E 5
E 3
# ifdef DEBUG
	fprintf(outf, "GETTMODE: UPPERCASE = %s\n", UPPERCASE ? "TRUE":"FALSE");
	fprintf(outf, "GETTMODE: GT = %s\n", GT ? "TRUE" : "FALSE");
	fprintf(outf, "GETTMODE: NONL = %s\n", NONL ? "TRUE" : "FALSE");
	fprintf(outf, "GETTMODE: ospeed = %d\n", ospeed);
# endif
}

setterm(type)
reg char	*type; {

D 12
	reg int	unknown;
	char	genbuf[1024];
E 12
I 12
	reg int		unknown;
	static char	genbuf[1024];
I 16
# ifdef TIOCGWINSZ
E 16
I 15
	struct winsize win;
I 16
# endif
E 16
E 15
E 12

# ifdef DEBUG
	fprintf(outf, "SETTERM(\"%s\")\n", type);
	fprintf(outf, "SETTERM: LINES = %d, COLS = %d\n", LINES, COLS);
# endif
	if (type[0] == '\0')
		type = "xx";
	unknown = FALSE;
	if (tgetent(genbuf, type) != 1) {
		unknown++;
		strcpy(genbuf, "xx|dumb:");
	}
# ifdef DEBUG
	fprintf(outf, "SETTERM: tty = %s\n", type);
# endif
I 16
# ifdef TIOCGWINSZ
E 16
I 15
	if (ioctl(_tty_ch, TIOCGWINSZ, &win) >= 0) {
		if (LINES == 0)
			LINES = win.ws_row;
		if (COLS == 0)
			COLS = win.ws_col;
	}
I 16
# endif
E 16

E 15
	if (LINES == 0)
		LINES = tgetnum("li");
	if (LINES <= 5)
		LINES = 24;
D 13
	else if (LINES > 48)
		LINES = 48;
E 13

	if (COLS == 0)
		COLS = tgetnum("co");
	if (COLS <= 4)
		COLS = 80;
D 13
	else if (COLS > 1000)
		COLS = 1000;
E 13
I 13

E 13
# ifdef DEBUG
	fprintf(outf, "SETTERM: LINES = %d, COLS = %d\n", LINES, COLS);
# endif
D 16
	aoftspace = tspace;
E 16
I 16
	aoftspace = _tspace;
E 16
	zap();			/* get terminal description		*/
I 16

	/*
	 * Handle funny termcap capabilities
	 */
	if (CS && SC && RC) AL=DL="";
	if (AL_PARM && AL==NULL) AL="";
	if (DL_PARM && DL==NULL) DL="";
	if (IC && IM==NULL) IM="";
	if (IC && EI==NULL) EI="";
	if (!GT) BT=NULL;	/* If we can't tab, we can't backtab either */

E 16
	if (tgoto(CM, destcol, destline)[0] == 'O')
		CA = FALSE, CM = 0;
	else
		CA = TRUE;
D 16
	PC = xPC ? xPC[0] : FALSE;
	aoftspace = tspace;
E 16
I 16

	PC = _PC ? _PC[0] : FALSE;
	aoftspace = _tspace;
E 16
D 19
	strcpy(ttytype, longname(genbuf, type));
E 19
I 19
	strncpy(ttytype, longname(genbuf, type), sizeof(ttytype) - 1);
	ttytype[sizeof(ttytype) - 1] = '\0';
E 19
	if (unknown)
		return ERR;
	return OK;
}
I 16

E 16
/*
D 7
 *	This routine gets all the terminal falgs from the termcap database
E 7
I 7
 *	This routine gets all the terminal flags from the termcap database
E 7
 */
D 16
zap() {
E 16

D 16
	reg bool	**fp;
	reg char	*namp, ***sp;
E 16
I 16
zap()
{
	register char	*namp;
	register bool	**fp;
	register char	***sp;
#ifdef	DEBUG
	register char	*cp;
#endif
E 16
I 7
D 14
	reg int		SG, UG;
E 14
E 7
	extern char	*tgetstr();

D 16
	/*
	 * get boolean flags
	 */
 	namp = "ambseohzinmimsncosulxn\0\0";
# ifdef FULLDEBUG
	fprintf(outf, "ZAP: namp = \"%s\"\n", namp);
# endif
E 16
I 16
D 17
	namp = "ambsdadbeohchzinmimsncnsosulxbxnxtxx";
E 17
I 17
	namp = "ambsdadbeohchzinmimsncnsosulxbxnxtxsxx";
E 17
E 16
	fp = sflags;
	do {
		*(*fp++) = tgetflag(namp);
D 16
# ifdef FULLDEBUG
		fprintf(outf, "ZAP: %.2s = %d", namp, *(*(fp - 1)));
# endif
E 16
I 16
#ifdef DEBUG
		fprintf(outf, "%2.2s = %s\n", namp, *fp[-1] ? "TRUE" : "FALSE");
#endif
E 16
		namp += 2;
	} while (*namp);
D 16

	/*
	 * get string values
	 */
D 10
	namp = "albcbtcdceclcmdcdldmdoedeihoicimipllmandpcsesfsosrtatetiucueupusvbvsve";
E 10
I 10
	namp = "albcbtcdceclcmcrdcdldmdoedeihoicimipllmandnlpcsesfsosrtatetiucueupusvbvsve";
E 10
# ifdef FULLDEBUG
	fprintf(outf, "ZAP: namp = \"%s\"\n", namp);
# endif
E 16
I 16
	namp = "albcbtcdceclcmcrcsdcdldmdoedeik0k1k2k3k4k5k6k7k8k9hoicimipkdkekhklkrkskullmandnlpcrcscsesfsosrtatetiucueupusvbvsveALDLUPDOLERI";
E 16
	sp = sstrs;
	do {
		*(*sp++) = tgetstr(namp, &aoftspace);
D 16
# ifdef FULLDEBUG
		fprintf(outf, "ZAP: %.2s = \"%s\"\n", namp, *(*(sp-1)));
# endif
E 16
I 16
#ifdef DEBUG
		fprintf(outf, "%2.2s = %s", namp, *sp[-1] == NULL ? "NULL\n" : "\"");
		if (*sp[-1] != NULL) {
			for (cp = *sp[-1]; *cp; cp++)
				fprintf(outf, "%s", unctrl(*cp));
			fprintf(outf, "\"\n");
		}
#endif
E 16
		namp += 2;
	} while (*namp);
D 7
	if (!SO && US) {
E 7
I 7
D 14
	SG = tgetnum("sg");
	UG = tgetnum("ug");
D 11
	if ((SG || !SO) && (!UG && US)) {
E 11
I 11
	if ((SG > 0 || !SO) && (UG <= 0 && US)) {
E 14
I 14
D 17
	if (tgetnum("sg") > 0)
		SO = NULL;
	if (tgetnum("ug") > 0)
		US = NULL;
	if (!SO && US) {
E 14
E 11
E 7
		SO = US;
		SE = UE;
E 17
I 17
	if (XS)
		SO = SE = NULL;
	else {
		if (tgetnum("sg") > 0)
			SO = NULL;
		if (tgetnum("ug") > 0)
			US = NULL;
		if (!SO && US) {
			SO = US;
			SE = UE;
		}
E 17
	}
}
I 4

/*
 * return a capability from termcap
 */
char *
getcap(name)
char *name;
{
I 6
D 7
	char *tgetent();
E 7
I 7
	char *tgetstr();
E 7

E 6
D 7
	return tgetent(name, &aoftspace);
E 7
I 7
	return tgetstr(name, &aoftspace);
E 7
}
E 4
E 1
