h55173
s 00001/00001/00049
d D 7.1 86/06/04 23:30:18 mckusick 9 8
c 4.3BSD release version
e
s 00007/00001/00043
d D 6.2 85/06/08 15:10:54 mckusick 8 7
c Add copyright
e
s 00000/00000/00044
d D 6.1 83/07/29 06:14:37 sam 7 6
c 4.2 distribution
e
s 00003/00003/00041
d D 4.6 83/07/01 02:25:05 root 6 5
c purge #if sun's
e
s 00003/00003/00041
d D 4.5 83/06/20 20:54:09 root 5 4
c standards are hard to break, sigh
e
s 00000/00007/00044
d D 4.4 83/05/27 13:57:48 sam 4 3
c old goes the old, in comes the new
e
s 00007/00000/00044
d D 4.3 83/05/18 02:42:23 sam 3 2
c sun changes
e
s 00005/00003/00039
d D 4.2 82/12/05 21:54:08 sam 2 1
c handle multiple #include's cleanly
e
s 00042/00000/00000
d D 4.1 82/12/02 11:26:55 sam 1 0
c date and time created 82/12/02 11:26:55 by sam
e
u
U
t
T
I 1
D 8
/*	%M%	%I%	%E%	*/
E 8
I 8
/*
D 9
 * Copyright (c) 1982 Regents of the University of California.
E 9
I 9
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 9
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 8

/*
 * User visible structures and constants
 * related to terminal handling.
 */
D 2

E 2
I 2
#ifndef _TTYCHARS_
#define	_TTYCHARS_
E 2
struct ttychars {
	char	tc_erase;	/* erase last character */
	char	tc_kill;	/* erase entire line */
	char	tc_intrc;	/* interrupt */
	char	tc_quitc;	/* quit */
	char	tc_startc;	/* start output */
	char	tc_stopc;	/* stop output */
	char	tc_eofc;	/* end-of-file */
	char	tc_brkc;	/* input delimiter (like nl) */
	char	tc_suspc;	/* stop process signal */
	char	tc_dsuspc;	/* delayed stop process signal */
	char	tc_rprntc;	/* reprint line */
	char	tc_flushc;	/* flush output (toggles) */
	char	tc_werasc;	/* word erase */
	char	tc_lnextc;	/* literal next character */
};

#define	CTRL(c)	('c'&037)

/* default special characters */
I 3
D 4
#ifdef vax
E 3
#define	CERASE	'#'
#define	CKILL	'@'
D 2
#define	CINTR	0177		/* DEL */
#define	CQUIT	034		/* FS, cntl shift L */
E 2
I 2
#define	CINTR	0177		/* DEL, ^? */
I 3
#endif
#ifdef sun
E 4
D 5
#define	CERASE	0177		/* DEL */
#define	CKILL	CTRL(u)
#define	CINTR	CTRL(c)
E 5
I 5
D 6
#define	CERASE	'#'
#define	CKILL	'@'
#define	CINTR	0177		/* DEL, ^? */
E 6
I 6
#define	CERASE	0177
#define	CKILL	CTRL(u)
#define	CINTR	CTRL(c)
E 6
E 5
D 4
#endif
E 4
E 3
#define	CQUIT	034		/* FS, ^\ */
E 2
#define	CSTART	CTRL(q)
#define	CSTOP	CTRL(s)
#define	CEOF	CTRL(d)
#define	CEOT	CEOF
#define	CBRK	0377
#define	CSUSP	CTRL(z)
#define	CDSUSP	CTRL(y)
#define	CRPRNT	CTRL(r)
#define	CFLUSH	CTRL(o)
#define	CWERASE	CTRL(w)
#define	CLNEXT	CTRL(v)
I 2
#endif
E 2
E 1
