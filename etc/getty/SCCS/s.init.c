h49833
s 00000/00000/00093
d D 5.5 04/12/08 04:15:11 msokolov 10 9
x 9
c I wrote all this code only to find out that the modem does not after all behave
c the way I thought. Back to smgetty.
e
s 00001/00000/00093
d D 5.4 04/12/07 23:43:21 msokolov 9 8
c smart modem support
e
s 00001/00000/00092
d D 5.3 03/03/22 18:44:21 msokolov 8 7
c Add PASS8 support (p8 boolean flag)
c This is necessary for 8-bit terminals as the default parity will screw them
e
s 00001/00000/00091
d D 5.2 86/01/07 15:09:59 mckusick 7 6
c set DECCTLQ on specifc lines with getty (from muller@nprdc.arpa)
e
s 00008/00002/00083
d D 5.1 85/04/29 12:45:41 dist 6 5
c Add copyright
e
s 00001/00000/00084
d D 4.5 85/02/05 08:48:55 ralph 5 4
c added autobaud detection.
e
s 00001/00000/00083
d D 4.4 83/07/09 18:34:25 sam 4 3
c allow output to be flushed before first prompt to handle open lines
e
s 00001/00001/00082
d D 4.3 83/07/09 13:04:41 sam 3 2
c screws up single definition entries
e
s 00002/00001/00081
d D 4.2 83/07/07 03:31:54 kre 2 1
c added "ub" to force unbuffered output
e
s 00082/00000/00000
d D 4.1 83/07/06 00:10:11 sam 1 0
c date and time created 83/07/06 00:10:11 by sam
e
u
U
t
T
I 6
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 6
I 1
#ifndef lint
D 6
static char sccsid[] = "%W% (Berkeley) %E%";
#endif
E 6
I 6
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 6

/*
 * Getty table initializations.
 *
 * Melbourne getty.
 */
#include <sgtty.h>
#include "gettytab.h"

extern	struct sgttyb tmode;
extern	struct tchars tc;
extern	struct ltchars ltc;
extern	char hostname[];

struct	gettystrs gettystrs[] = {
D 3
	{ "nx", "default" },		/* next table */
E 3
I 3
	{ "nx" },			/* next table */
E 3
	{ "cl" },			/* screen clear characters */
	{ "im" },			/* initial message */
	{ "lm", "login: " },		/* login message */
	{ "er", &tmode.sg_erase },	/* erase character */
	{ "kl", &tmode.sg_kill },	/* kill character */
	{ "et", &tc.t_eofc },		/* eof chatacter (eot) */
	{ "pc", "" },			/* pad character */
	{ "tt" },			/* terminal type */
	{ "ev" },			/* enviroment */
	{ "lo", "/bin/login" },		/* login program */
	{ "hn", hostname },		/* host name */
	{ "he" },			/* host name edit */
	{ "in", &tc.t_intrc },		/* interrupt char */
	{ "qu", &tc.t_quitc },		/* quit char */
	{ "xn", &tc.t_startc },		/* XON (start) char */
	{ "xf", &tc.t_stopc },		/* XOFF (stop) char */
	{ "bk", &tc.t_brkc },		/* brk char (alt \n) */
	{ "su", &ltc.t_suspc },		/* suspend char */
	{ "ds", &ltc.t_dsuspc },	/* delayed suspend */
	{ "rp", &ltc.t_rprntc },	/* reprint char */
	{ "fl", &ltc.t_flushc },	/* flush output */
	{ "we", &ltc.t_werasc },	/* word erase */
	{ "ln", &ltc.t_lnextc },	/* literal next */
	{ 0 }
};

struct	gettynums gettynums[] = {
	{ "is" },			/* input speed */
	{ "os" },			/* output speed */
	{ "sp" },			/* both speeds */
	{ "nd" },			/* newline delay */
	{ "cd" },			/* carriage-return delay */
	{ "td" },			/* tab delay */
	{ "fd" },			/* form-feed delay */
	{ "bd" },			/* backspace delay */
	{ "to" },			/* timeout */
	{ "f0" },			/* output flags */
	{ "f1" },			/* input flags */
	{ "f2" },			/* user mode flags */
I 4
	{ "pf" },			/* delay before flush at 1st prompt */
E 4
	{ 0 }
};

struct	gettyflags gettyflags[] = {
	{ "ht",	0 },			/* has tabs */
	{ "nl",	1 },			/* has newline char */
	{ "ep",	0 },			/* even parity */
	{ "op",	0 },			/* odd parity */
	{ "ap",	0 },			/* any parity */
	{ "ec",	1 },			/* no echo */
	{ "co",	0 },			/* console special */
	{ "cb",	0 },			/* crt backspace */
	{ "ck",	0 },			/* crt kill */
	{ "ce",	0 },			/* crt erase */
	{ "pe",	0 },			/* printer erase */
	{ "rw",	1 },			/* don't use raw */
	{ "xc",	1 },			/* don't ^X ctl chars */
	{ "lc",	0 },			/* terminal las lower case */
	{ "uc",	0 },			/* terminal has no lower case */
	{ "ig",	0 },			/* ignore garbage */
	{ "ps",	0 },			/* do port selector speed select */
D 2
	{ "hc",	1 },			/* set hangup on close */
E 2
I 2
	{ "hc",	1 },			/* don't set hangup on close */
	{ "ub", 0 },			/* unbuffered output */
I 5
	{ "ab", 0 },			/* auto-baud detect with '\r' */
I 7
	{ "dx", 0 },			/* set decctlq */
I 8
	{ "p8", 0 },			/* set LPASS8 */
I 9
	{ "sm", 0 },			/* smart modem auto-baud */
E 9
E 8
E 7
E 5
E 2
	{ 0 }
};
E 1
