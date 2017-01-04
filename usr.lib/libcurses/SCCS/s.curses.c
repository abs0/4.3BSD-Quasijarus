h61545
s 00010/00005/00054
d D 5.5 88/06/30 17:21:25 bostic 9 8
c install approved copyright notice
e
s 00011/00005/00048
d D 5.4 88/06/08 13:56:54 bostic 8 7
c written by Ken Arnold; add Berkeley specific header
e
s 00002/00002/00051
d D 5.3 86/01/30 13:43:06 arnold 7 6
c ttytype should have it's sive defined properly
e
s 00001/00001/00052
d D 5.2 85/11/08 17:18:44 bloom 6 5
c make sure fetching the terminal type doesn't clobber anything
e
s 00010/00001/00043
d D 5.1 85/06/07 11:28:03 dist 5 4
c Add copyright
e
s 00001/00001/00043
d D 1.4 85/05/23 15:37:42 bloom 4 3
c Add support for XS
e
s 00014/00005/00030
d D 1.3 85/05/01 16:50:12 bloom 3 2
c new version from arnold
e
s 00003/00003/00032
d D 1.2 83/05/09 20:26:36 arnold 2 1
c add CR to external variable declarations
e
s 00035/00000/00000
d D 1.1 83/03/27 16:12:30 arnold 1 0
c date and time created 83/03/27 16:12:30 by arnold
e
u
U
t
T
I 1
/*
I 5
D 8
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 8
I 8
 * Copyright (c) 1981 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 9
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 9
I 9
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
E 9
E 8
 */

#ifndef lint
D 7
static char sccsid[] = "%W% (Berkeley) %G%";
E 7
I 7
D 8
static char sccsid[] = "@(#)curses.c	5.2 (Berkeley) 11/8/85";
E 7
#endif not lint
E 8
I 8
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 8

/*
E 5
 * Define global variables
 *
D 5
 * %W% (Berkeley) %G%
E 5
 */
# include	"curses.h"

bool	_echoit		= TRUE,	/* set if stty indicates ECHO		*/
	_rawmode	= FALSE,/* set if stty indicates RAW mode	*/
	My_term		= FALSE,/* set if user specifies terminal type	*/
	_endwin		= FALSE;/* set if endwin has been called	*/

D 6
char	ttytype[10],		/* long name of tty			*/
E 6
I 6
D 7
char	ttytype[17],		/* long name of tty			*/
E 7
I 7
char	ttytype[50],		/* long name of tty			*/
E 7
E 6
	*Def_term	= "unknown";	/* default terminal type	*/

int	_tty_ch		= 1,	/* file channel which is a tty		*/
	LINES,			/* number of lines allowed on screen	*/
	COLS,			/* number of columns allowed on screen	*/
	_res_flg;		/* sgtty flags for reseting later	*/

WINDOW	*stdscr		= NULL,
	*curscr		= NULL;

# ifdef DEBUG
FILE	*outf;			/* debug output file			*/
# endif

SGTTY	_tty;			/* tty modes				*/

D 3
bool	AM, BS, CA, DA, DB, EO, GT, HZ, IN, MI, MS, NC, OS, UL, XN,
	NONL, UPPERCASE, normtty, _pfast;
E 3
I 3
bool	AM, BS, CA, DA, DB, EO, HC, HZ, IN, MI, MS, NC, NS, OS, UL, XB, XN,
D 4
	XT, XX;
E 4
I 4
	XT, XS, XX;
E 4
char	*AL, *BC, *BT, *CD, *CE, *CL, *CM, *CR, *CS, *DC, *DL, *DM,
	*DO, *ED, *EI, *K0, *K1, *K2, *K3, *K4, *K5, *K6, *K7, *K8,
	*K9, *HO, *IC, *IM, *IP, *KD, *KE, *KH, *KL, *KR, *KS, *KU,
	*LL, *MA, *ND, *NL, *RC, *SC, *SE, *SF, *SO, *SR, *TA, *TE,
	*TI, *UC, *UE, *UP, *US, *VB, *VS, *VE, *AL_PARM, *DL_PARM,
	*UP_PARM, *DOWN_PARM, *LEFT_PARM, *RIGHT_PARM;
char	PC;
E 3

D 2
char	*AL, *BC, *BT, *CD, *CE, *CL, *CM, *DC, *DL, *DM, *DO, *ED,
	*EI, *HO, *IC, *IM, *IP, *LL, *MA, *ND, *SE, *SF, *SO, *SR,
	*TA, *TE, *TI, *UC, *UE, *UP, *US, *VB, *VE, *VS, PC;
E 2
I 2
D 3
char	*AL, *BC, *BT, *CD, *CE, *CL, *CM, *CR, *DC, *DL, *DM, *DO,
	*ED, *EI, *HO, *IC, *IM, *IP, *LL, *MA, *ND, *NL, *SE, *SF,
	*SO, *SR, *TA, *TE, *TI, *UC, *UE, *UP, *US, *VB, *VE, *VS, PC;
E 3
I 3
/*
 * From the tty modes...
 */

bool	GT, NONL, UPPERCASE, normtty, _pfast;
E 3
E 2
E 1
