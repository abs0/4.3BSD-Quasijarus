h14088
s 00038/00024/00012
d D 5.4 88/06/06 11:46:14 bostic 5 4
c make cshputchar a macro; some reformatting
e
s 00006/00001/00030
d D 5.3 86/03/29 07:37:10 lepreau 4 3
c Minor speedups & cleanups:
c replace letter() et al with ctype-like cmap macros and expand cmap to short
c for new LET and DIG bits; use bzero in private calloc; make btell a macro.
e
s 00001/00001/00030
d D 5.2 85/06/06 13:12:09 edward 3 2
c cleaning up after bozos
e
s 00007/00001/00024
d D 5.1 85/06/04 11:10:04 dist 2 1
c Add copyright
e
s 00025/00000/00000
d D 4.1 84/12/13 16:26:24 edward 1 0
c date and time created 84/12/13 16:26:24 by edward
e
u
U
t
T
I 1
D 2
/* %W% (Berkeley) %G% */
E 2
I 2
/*
 * Copyright (c) 1980 Regents of the University of California.
D 3
 * All rights reserved.  The Berkeley software License Agreement
E 3
I 3
 * All rights reserved.  The Berkeley Software License Agreement
E 3
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 2

D 5
/*
 * Table for spotting special characters quickly
 *
 * Makes for very obscure but efficient coding.
 */

E 5
D 4
extern char _cmap[];
E 4
I 4
extern unsigned short _cmap[];
E 4

D 5
#define _Q	0x01		/* '" */
#define _Q1	0x02		/* ` */
#define _SP	0x04		/* space and tab */
#define _NL	0x08		/* \n */
#define _META	0x10		/* lex meta characters, sp #'`";&<>()|\t\n */
#define _GLOB	0x20		/* glob characters, *?{[` */
#define _ESC	0x40		/* \ */
#define _DOL	0x80		/* $ */
I 4
#define _DIG   0x100		/* 0-9 */
#define _LET   0x200		/* a-z, A-Z, _ */
E 5
I 5
#define	_Q	0x001		/* '" */
#define	_Q1	0x002		/* ` */
#define	_SP	0x004		/* space and tab */
#define	_NL	0x008		/* \n */
#define	_META	0x010		/* lex meta characters, sp #'`";&<>()|\t\n */
#define	_GLOB	0x020		/* glob characters, *?{[` */
#define	_ESC	0x040		/* \ */
#define	_DOL	0x080		/* $ */
#define	_DIG	0x100		/* 0-9 */
#define	_LET	0x200		/* a-z, A-Z, _ */
E 5
E 4

D 5
#define cmap(c, bits)	(_cmap[(unsigned char)(c)] & (bits))
E 5
I 5
#define	cmap(c, bits)	(_cmap[(unsigned char)(c)] & (bits))
E 5

D 5
#define isglob(c)	cmap(c, _GLOB)
#define isspace(c)	cmap(c, _SP)
#define isspnl(c)	cmap(c, _SP|_NL)
#define ismeta(c)	cmap(c, _META)
I 4
#define digit(c)	cmap(c, _DIG)
#define letter(c)	cmap(c, _LET)
#define alnum(c)	(digit(c) || letter(c))
E 5
I 5
#define	isglob(c)	cmap(c, _GLOB)
#define	isspace(c)	cmap(c, _SP)
#define	isspnl(c)	cmap(c, _SP|_NL)
#define	ismeta(c)	cmap(c, _META)
#define	digit(c)	cmap(c, _DIG)
#define	letter(c)	cmap(c, _LET)
#define	alnum(c)	(digit(c) || letter(c))

#define	LINELEN		128
extern char *linp, linbuf[LINELEN];

#define	CSHPUTCHAR { \
	if (!(ch&QUOTE) && (ch == 0177 || ch < ' ' && ch != '\t' && \
	    ch != '\n')) { \
		*linp++ = '^'; \
		if (ch == 0177) \
			ch = '?'; \
		else \
			ch |= 'A' - 1; \
		if (linp >= &linbuf[sizeof linbuf - 2]) \
			flush(); \
	} \
	ch &= TRIM; \
	*linp++ = ch; \
	if (ch == '\n' || linp >= &linbuf[sizeof(linbuf) - 2]) \
		flush(); \
}
E 5
E 4
E 1
