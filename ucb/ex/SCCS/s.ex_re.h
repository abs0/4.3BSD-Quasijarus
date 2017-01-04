h34567
s 00011/00004/00069
d D 7.4 03/04/13 15:19:02 msokolov 12 11
c 8-bit ex
e
s 00008/00002/00065
d D 7.3 85/05/31 15:57:33 dist 11 9
c Add copyright
e
s 00008/00002/00065
d D 5.1.1.1 85/05/31 11:51:33 dist 10 6
c Add copyright
e
s 00006/00006/00061
d D 7.2 81/07/26 20:04:00 mark 9 8
c fixes for 3b
e
s 00008/00008/00059
d D 7.1 81/07/08 22:30:41 mark 8 7
c release 3.7 - a few bug fixes and a few new features.
e
s 00000/00000/00067
d D 6.1 80/10/19 01:21:16 mark 7 6
c preliminary release 3.6 10/18/80
e
s 00000/00000/00067
d D 5.1 80/08/20 16:11:02 mark 6 5
c Release 3.5, August 20, 1980
e
s 00002/00001/00065
d D 4.2 80/08/01 20:40:59 mark 5 4
c Bill added more buffers, and I put in sccs.
e
s 00001/00001/00065
d D 4.1 80/08/01 00:14:54 mark 4 3
c release 3.4, June 24, 1980
e
s 00000/00000/00066
d D 3.1 80/07/31 23:39:12 mark 3 2
c release 3.3, Feb 2, 1980
e
s 00000/00000/00066
d D 2.1 80/07/31 23:19:16 mark 2 1
c release 3.2, Jan 4, 1980
e
s 00066/00000/00000
d D 1.1 80/07/31 23:00:22 mark 1 0
c date and time created 80/07/31 23:00:22 by mark
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
D 10
/* Copyright (c) 1980 Regents of the University of California */
/* sccs id:	%W% %G%  */
E 10
I 10
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */

E 10
E 8
I 8
D 11
/* Copyright (c) 1981 Regents of the University of California */
/* sccs id:	%W%	%G%  */
E 11
I 11
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */

E 11
E 8
E 5
/*
 * Regular expression definitions.
 * The regular expressions in ex are similar to those in ed,
 * with the addition of the word boundaries from Toronto ed
 * and allowing character classes to have [a-b] as in the shell.
 * The numbers for the nodes below are spaced further apart then
 * necessary because I at one time partially put in + and | (one or
 * more and alternation.)
 */
struct	regexp {
D 12
	char	Expbuf[ESIZE + 2];
E 12
I 12
	u_char	Expbuf[ESIZE + 2];
E 12
	bool	Circfl;
	short	Nbra;
};

/*
 * There are three regular expressions here, the previous (in re),
 * the previous substitute (in subre) and the previous scanning (in scanre).
 * It would be possible to get rid of "re" by making it a stack parameter
 * to the appropriate routines.
 */
D 8
struct	regexp re;		/* Last re */
struct	regexp scanre;		/* Last scanning re */
struct	regexp subre;		/* Last substitute re */
E 8
I 8
D 9
extern struct	regexp re;		/* Last re */
extern struct	regexp scanre;		/* Last scanning re */
extern struct	regexp subre;		/* Last substitute re */
E 9
I 9
var struct	regexp re;		/* Last re */
var struct	regexp scanre;		/* Last scanning re */
var struct	regexp subre;		/* Last substitute re */
E 9
E 8

/*
 * Defining circfl and expbuf like this saves us from having to change
 * old code in the ex_re.c stuff.
 */
#define	expbuf	re.Expbuf
#define	circfl	re.Circfl
#define	nbra	re.Nbra

/*
 * Since the phototypesetter v7-epsilon
 * C compiler doesn't have structure assignment...
 */
#define	savere(a)	copy(&a, &re, sizeof (struct regexp))
#define	resre(a)	copy(&re, &a, sizeof (struct regexp))

/*
 * Definitions for substitute
 */
D 8
char	*braslist[NBRA];	/* Starts of \(\)'ed text in lhs */
char	*braelist[NBRA];	/* Ends... */
char	rhsbuf[RHSSIZE];	/* Rhs of last substitute */
E 8
I 8
D 9
extern char	*braslist[NBRA];	/* Starts of \(\)'ed text in lhs */
extern char	*braelist[NBRA];	/* Ends... */
extern char	rhsbuf[RHSSIZE];	/* Rhs of last substitute */
E 9
I 9
D 12
var char	*braslist[NBRA];	/* Starts of \(\)'ed text in lhs */
var char	*braelist[NBRA];	/* Ends... */
var char	rhsbuf[RHSSIZE];	/* Rhs of last substitute */
E 12
I 12
var u_char	*braslist[NBRA];	/* Starts of \(\)'ed text in lhs */
var u_char	*braelist[NBRA];	/* Ends... */
var u_char	rhsbuf[RHSSIZE];	/* Rhs of last substitute */
E 12
E 9
E 8

/*
 * Definitions of codes for the compiled re's.
 * The re algorithm is described in a paper
 * by K. Thompson in the CACM about 10 years ago
 * and is the same as in ed.
 */
#define	STAR	1

#define	CBRA	1
#define	CDOT	4
#define	CCL	8
#define	NCCL	12
#define	CDOL	16
D 4
#define	CEOF	17
E 4
I 4
#define	CEOFC	17
E 4
#define	CKET	18
#define	CCHR	20
#define	CBRC	24
#define	CLET	25
I 12

/*
 * Since in 8-bit ex we can no longer use bit 7 for this purpose, we use ~@
 * (0200) as a prefix in substitute RHS to indicate quoted chars. Thus ~@ is
 * one character that cannot be used in substitute RHS.
 */
#define	RHSQUOTE	0200
E 12
E 1
