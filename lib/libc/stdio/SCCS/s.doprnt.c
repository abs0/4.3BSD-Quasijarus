h56217
s 00010/00005/00655
d D 5.35 88/06/27 17:49:57 bostic 36 35
c install approved copyright notice
e
s 00003/00002/00657
d D 5.34 88/06/08 10:37:07 bostic 35 34
c minor optimizations
e
s 00054/00048/00605
d D 5.33 88/06/07 15:15:56 bostic 34 32
c don't allow negative zero; ``printf("%.3f", (double)-0.00005);''
c fix "% +5" and "%+ 5" to be identical, rename _cvt to cvt.
e
s 00033/00042/00611
d R 5.33 88/06/06 13:05:29 bostic 33 32
c don't allow negative zero; ``printf("%.3f", (double)-0.00005);''
e
s 00276/00227/00377
d D 5.32 88/06/03 15:09:35 bostic 32 31
c add D, O, U; completely redo the floating point
e
s 00004/00001/00600
d D 5.31 88/06/01 15:39:50 bostic 31 30
c fix "printf("%4.1f\n", (double)0.0);"
e
s 00004/00003/00597
d D 5.30 88/05/24 19:32:34 bostic 30 29
c fix %.60g to not add on precision digits
e
s 00007/00000/00593
d D 5.29 88/05/23 17:24:40 bostic 29 28
c make sure we can write
e
s 00133/00123/00460
d D 5.28 88/05/23 16:39:26 bostic 28 27
c various padding fixes from Chris
e
s 00040/00029/00543
d D 5.27 88/05/19 11:28:51 bostic 27 26
c handle exponents greater than 2 digits
e
s 00011/00002/00561
d D 5.26 88/05/19 11:00:59 bostic 26 25
c if precision is specified, 0 flag is ignored for diouXx conversions
c also, print out padding characters for special case 0 value, 0 precision
e
s 00002/00006/00561
d D 5.25 88/05/18 17:45:32 bostic 25 24
c remove references to long double; it's just not available
e
s 00046/00032/00521
d D 5.24 88/05/18 17:18:59 bostic 24 23
c write 0's for unreasonable precision requests after number conversion
c combine sections of code to print out buffer
e
s 00044/00019/00509
d D 5.23 88/05/18 14:53:21 bostic 23 22
c fix rest of Chris' bugs, mostly sign and padding placement
e
s 00010/00002/00516
d D 5.22 88/05/18 14:02:59 bostic 22 21
c if zero value, and precision of zero, nothing gets output
e
s 00003/00003/00515
d D 5.21 88/05/18 13:47:54 bostic 21 20
c always pad with spaces on the right
e
s 00022/00015/00496
d D 5.20 88/05/18 13:41:39 bostic 20 19
c Chris' fix for alternate hex and octal mode
e
s 00024/00041/00487
d D 5.19 88/05/18 12:44:31 bostic 19 18
c rip out statics; go back to fixed buffer size, malloc is just too
c painful to get right
e
s 00004/00002/00524
d D 5.18 88/05/17 20:51:04 bostic 18 17
c don't reinit buffer each time
e
s 00023/00006/00503
d D 5.17 88/05/17 20:17:15 bostic 17 16
c Chris says that ANSI now says if you specify the precision of a string
c you should only look for a NUL in the first "precision" characters.
e
s 00009/00000/00500
d D 5.16 88/05/17 20:03:57 bostic 16 15
c Chris argues convincingly for a hex representation for 'p'
e
s 00043/00026/00457
d D 5.15 88/05/17 19:59:58 bostic 15 14
c handle infinite floating point precision
e
s 00093/00084/00390
d D 5.14 88/05/17 16:31:41 bostic 14 13
c Chris's changes, plus some minor fixes
e
s 00001/00000/00473
d D 5.13 88/05/17 10:19:46 bostic 13 12
c make `"%4l3d"', `"%*3d", 4', and `%3*d' do the right (wrong) thing
c at least it's consistent
e
s 00001/00001/00472
d D 5.12 88/05/16 15:17:38 bostic 12 11
c fix string precision check
e
s 00107/00108/00366
d D 5.11 88/05/16 14:38:59 bostic 11 10
c redo putc macro for part of %s, and parsing format string for speed
e
s 00022/00022/00452
d D 5.10 88/05/11 17:47:36 bostic 10 9
c minor whacks; checkpoint before speed attempt
e
s 00029/00026/00445
d D 5.9 88/05/11 14:13:03 bostic 9 8
c minor cleanups, move format checking into _cvt
e
s 00210/00075/00261
d D 5.8 88/05/10 23:03:55 bostic 8 7
c passes basic checks with rewritten floating point
e
s 00028/00023/00308
d D 5.7 88/05/09 17:23:46 bostic 7 6
c checkpoint; gonna try and rewrite floating point
e
s 00096/00067/00235
d D 5.6 88/05/09 16:45:42 bostic 6 5
c first version to pass basic tests; rewrite complete
e
s 00055/00029/00247
d D 5.5 88/05/09 15:06:37 bostic 5 4
c version that attempts to do formatting of floats itsellf
e
s 00032/00013/00244
d D 5.4 88/05/08 18:32:22 bostic 4 3
c add 'e' format
e
s 00146/00093/00111
d D 5.3 88/05/08 17:53:44 bostic 3 2
c first cut at ANSI version; also added 'f' format
e
s 00162/00390/00042
d D 5.2 88/05/07 15:55:36 bostic 2 1
c First "working" version.  Rip out roman number and binary options;
c add working 'l' flag, varargs, '#' and '+' flags, do "%%" in first switch
c basically a complete and total reformat/rewrite, diff won't work
e
s 00432/00000/00000
d D 5.1 88/05/07 10:58:06 bostic 1 0
c original posting by Steve Summit to USENET
e
u
U
f b 
t
T
I 1
D 2
From stevesu@copper.UUCP Wed Mar 25 23:35:32 1987
Path: seismo!ut-sally!husc6!bacchus!mit-eddie!genrad!decvax!tektronix!teklds!copper!stevesu
From: stevesu@copper.TEK.COM (Steve Summit)
Newsgroups: net.sources
Subject: Public Domain _doprnt in C
Message-ID: <938@copper.TEK.COM>
Date: 26 Mar 87 04:35:32 GMT
Reply-To: stevesu@copper.UUCP (Steve Summit)
Distribution: world
Organization: Tektronix, Inc., Beaverton, OR.
Lines: 420

Mark Pulver is looking for a C version of _doprnt, so I thought
I'd pass mine along.  I wrote this from the ground up; it is
absolutely underived from anything proprietary.

This version is not complete, and has the following two key
omissions:

	It doesn't do floating point (%f, %e, or %g).

	It will handle %ld (%lx, etc.) incorrectly on machines
	where sizeof(long) != sizeof(int).

It also does not implement the %# stuff which appeared in the 4.2
documentation but which I haven't seen in any implementation yet.

I believe it handles everything else correctly, although I have
not tested it exhaustively.

There are two "fun" additions: %b is binary, and %r is roman.

You are free to use this code as you wish, but please leave the
identification comment intact.  I can offer no support for this
code, although if I ever implement floating point or pdp11
support (I'm acutely embarrassed to admit making the typical VAX
int/long equivalence assumption) I'll try to remember to post
those additions.

                                           Steve Summit
                                           stevesu@copper.tek.com

--------------------- cut here for doprnt.c ---------------------
E 2
/*
D 2
 *  Common code for printf et al.
E 2
I 2
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
E 2
 *
D 2
 *  The calling routine typically takes a variable number of arguments,
 *  and passes the address of the first one.  This implementation
 *  assumes a straightforward, stack implementation, aligned to the
 *  machine's wordsize.  Increasing addresses are assumed to point to
 *  successive arguments (left-to-right), as is the case for a machine
 *  with a downward-growing stack with arguments pushed right-to-left.
E 2
I 2
 * Redistribution and use in source and binary forms are permitted
D 36
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 36
I 36
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
E 36
E 2
D 3
 *
D 2
 *  To write, for example, fprintf() using this routine, the code
 *
 *	fprintf(fd, format, args)
 *	FILE *fd;
 *	char *format;
 *	{
 *	_doprnt(format, &args, fd);
 *	}
 *
 *  would suffice.  (This example does not handle the fprintf's "return
 *  value" correctly, but who looks at the return value of fprintf
 *  anyway?)
 *
 *  This version implements the following printf features:
 *
 *	%d	decimal conversion
 *	%u	unsigned conversion
 *	%x	hexadecimal conversion
 *	%X	hexadecimal conversion with capital letters
 *	%o	octal conversion
 *	%c	character
 *	%s	string
 *	%m.n	field width, precision
 *	%-m.n	left adjustment
 *	%0m.n	zero-padding
 *	%*.*	width and precision taken from arguments
 *
 *  This version does not implement %f, %e, or %g.  It accepts, but
 *  ignores, an `l' as in %ld, %lo, %lx, and %lu, and therefore will not
 *  work correctly on machines for which sizeof(long) != sizeof(int).
 *  It does not even parse %D, %O, or %U; you should be using %ld, %o and
 *  %lu if you mean long conversion.
 *
 *  This version implements the following nonstandard features:
 *
 *	%b	binary conversion
 *	%r	roman numeral conversion
 *	%R	roman numeral conversion with capital letters
 *
 *  As mentioned, this version does not return any reasonable value.
 *
 *  Permission is granted to use, modify, or propagate this code as
 *  long as this notice is incorporated.
 *
 *  Steve Summit 3/25/87
E 2
I 2
 * Originally derived from code posted by Steve Summit to USENET,
 * dated 3/25/87
E 3
E 2
 */

I 2
#if defined(LIBC_SCCS) && !defined(lint)
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* LIBC_SCCS and not lint */

D 9
#include <sys/param.h>
E 9
I 9
#include <sys/types.h>
E 9
#include <varargs.h>
E 2
#include <stdio.h>
I 2
#include <ctype.h>
E 2

D 2
#define TRUE 1
#define FALSE 0
E 2
I 2
D 3
#define	MAXBUF		(sizeof(long) * 8)	 /* enough for binary */
E 3
I 3
D 5
#define	GETARG(r) \
	r = argsize&LONGINT ? va_arg(argp, long) : \
	    argsize&SHORTINT ? va_arg(argp, short) : va_arg(argp, int);

I 4
#define	MAXBUF		1024			/* should hold any number */
#define	MAXEXP		10			/* should hold any exponent */

E 5
I 5
D 6
#define	MAXBUF		120			/* should hold any number */
E 5
E 4
#define	DEFPREC		6			/* default precision */
E 6
I 6
D 9
#define	MAXBUF		120
#define	DEFPREC		6
E 9
I 9
D 11
#define	MAXBUF	120
#define	DEFPREC	6
E 11
I 11
D 15
#define	MAXBUF	40
E 15
I 15
D 19
/*
 * To handle arbitrary floating point precision, the buffer has to hold the
 * number, a decimal point, and N precision digits.  We can't just truncate
 * at some point is that the lower-level math routines may very well be
 * repeatedly returning some small fraction.  A 128 bit fraction can be
 * represented in 39 decimal digits.  Guess a max of 40 digits of precision,
 * and add one for the decimal point.
 */
#define	MAXFRAC		39
#define	MAXPREC		40
#define	MAXDIGIT	(MAXFRAC + MAXPREC + 1)
E 19
I 19
D 24
#define	MAXBUF		512
E 24
I 24
/* 11-bit exponent (VAX G floating point) is 308 decimal digits */
#define	MAXEXP		308
/* 128 bit fraction takes up 39 decimal digits; max reasonable precision */
#define	MAXFRACT	39
E 24
E 19
E 15
E 11
E 9
E 6
D 4
#define	MAXBUF		1024
E 3
#define	PUTC(ch, fd)	{ ++cnt; putc(ch, fd); }
#define	todigit(ch)	((ch) - '0')
I 3
#define	tochar(ch)	((ch) + '0')
E 4
E 3
E 2

I 32
#define	DEFPREC		6

E 32
I 24
#define	BUF		(MAXEXP+MAXFRACT+1)	/* + decimal point */

E 24
I 4
D 10
#define	PUTC(ch, fd)	{++cnt; putc(ch, fd);}
E 10
I 10
D 19
#define	PUTC(ch)	{++cnt; putc(ch, fp);}
E 19
I 19
D 28
#define	PUTC(ch)	{++cnt; putc((char)ch, fp);}
E 28
I 28
#define	PUTC(ch)	(void) putc(ch, fp)
E 28
E 19
E 10

I 6
D 8
#define	EFORMAT		1
#define	FFORMAT		2
#define	GFORMAT		3
E 8
I 8
D 9
#define	EFORMAT		0x01
#define	FFORMAT		0x02
#define	GFORMAT		0x04
E 8

E 9
E 6
E 4
D 2
#define ROMAN

#define isdigit(d) ((d) >= '0' && (d) <= '9')
#define Ctod(c) ((c) - '0')

#define MAXBUF (sizeof(long int) * 8)		 /* enough for binary */

#ifdef ROMAN
static tack();
static doit();
#endif

_doprnt(fmt, argp, fd)
register char *fmt;
register int *argp;
FILE *fd;
E 2
I 2
D 3
doprnt(fmt, argp, fd)
E 3
I 3
D 14
#define	LONGINT		0x01
#define	LONGDBL		0x02
#define	SHORTINT	0x04
I 5
#define	GETARG(r) \
	r = argsize&LONGINT ? va_arg(argp, long) : \
	    argsize&SHORTINT ? va_arg(argp, short) : va_arg(argp, int);
E 14
I 14
#define	ARG() \
	_ulong = flags&LONGINT ? va_arg(argp, long) : \
	    flags&SHORTINT ? va_arg(argp, short) : va_arg(argp, int);
E 14
E 5

I 27
#define	todigit(c)	((c) - '0')
#define	tochar(n)	((n) + '0')

E 27
I 8
D 11
static int alternate;
static char printsign;
E 11
I 11
D 14
static int alt;
E 14
I 14
/* have to deal with the negative buffer count kludge */
#define	NEGATIVE_COUNT_KLUDGE

#define	LONGINT		0x01		/* long integer */
#define	LONGDBL		0x02		/* long double; unimplemented */
#define	SHORTINT	0x04		/* short integer */
#define	ALT		0x08		/* alternate form */
#define	LADJUST		0x10		/* left adjustment */
I 28
#define	ZEROPAD		0x20		/* zero (as opposed to blank) pad */
#define	HEXPREFIX	0x40		/* add 0x or 0X prefix */
E 28
D 19
static int flags;
E 19

E 14
D 15
static char sign;
E 15
I 15
D 19
static char sign, *buf;
E 15
E 11

E 8
x_doprnt(fmt, argp, fp)
E 3
	register char *fmt;
E 19
I 19
_doprnt(fmt0, argp, fp)
	u_char *fmt0;
E 19
	va_list argp;
D 3
	register FILE *fd;
E 3
I 3
	register FILE *fp;
E 3
E 2
{
I 10
D 11
	register int base, cnt;
	register char *bp, *t;
E 10
D 2
register char *p;
char *p2;
int size;
int length;
int prec;
int ladjust;
char padc;
int n;
unsigned int u;
int base;
char buf[MAXBUF];
int negflag;
char *digs;
#ifdef ROMAN
char *rdigs;
int d;
#endif
E 2
I 2
	register u_long reg_ulong;
	register long reg_long;
E 11
I 11
D 19
	register int cnt, n;
	register char ch, *t;
E 19
I 19
D 28
	register u_char *fmt;
	register int ch, cnt, n;
	register char *t;
E 19
E 11
D 10
	register int base;
D 3
	register char *digs, *p, padc;
	char printsign, buf[MAXBUF];
	int alternate, cnt, n, ladjust, length, setlong, prec, size;
E 3
I 3
	register char *digs, *bp, *t, padc;
E 10
	double _double;
D 4
	char argsize, printsign, buf[MAXBUF], *fcvt();
E 4
I 4
D 6
	char argsize, printsign, buf[MAXBUF], *ecvt(), *fcvt();
E 4
	int alternate, cnt, decpt, n, ladjust, width, prec, sign, size;
E 6
I 6
D 8
	char argsize, printsign, *_cvt(), buf[MAXBUF];
	int alternate, cnt, n, ladjust, width, prec, size;
E 8
I 8
D 10
	char argsize, *_cvt(), buf[MAXBUF];
	int cnt, n, ladjust, width, prec, size;
E 10
I 10
D 11
	char argsize, padc, *_cvt(), *digs, buf[MAXBUF];
	int n, ladjust, width, prec, size;
E 11
I 11
	u_long _ulong;
D 14
	int base, ladjust, width, prec, size;
	char argsize, padc, *digs, *_cvt(), buf[MAXBUF];
E 14
I 14
D 19
	int base, width, prec, size;
D 15
	char padc, *digs, *_cvt(), buf[MAXBUF];
E 15
I 15
	char padc, *digs, sbuf[MAXDIGIT];
E 19
I 19
D 24
	int base, flags, prec, size, width;
	char padc, sign, *digs, buf[MAXBUF], *_cvt();
E 24
I 24
	int base, flags, fpprec, prec, size, width;
	char padc, sign, *digs, buf[BUF], *_cvt();
E 28
I 28
	register u_char *fmt;	/* format string */
	register int ch;	/* character from fmt */
	register int cnt;	/* return value accumulator */
	register int n;		/* random handy integer */
	register char *t;	/* buffer pointer */
	double _double;		/* double precision arguments %[eEfgG] */
	u_long _ulong;		/* integer arguments %[diouxX] */
D 32
	int flags;		/* flags as above */
E 32
I 32
	int base;		/* base for [diouxX] conversion */
E 32
	int dprec;		/* decimal precision in [diouxX] */
I 32
	int fieldsz;		/* field size expanded by sign, etc */
	int flags;		/* flags as above */
E 32
	int fpprec;		/* `extra' floating precision in [eEfgG] */
D 32
	int width;		/* width from format (%8d), or 0 */
E 32
	int prec;		/* precision from format (%.3d), or -1 */
D 32
	int size;		/* size of converted field or string */
	int fieldsz;		/* field size expanded by sign, etc */
E 32
	int realsz;		/* field size expanded by decimal precision */
I 32
	int size;		/* size of converted field or string */
	int width;		/* width from format (%8d), or 0 */
E 32
D 34
	char sign;		/* sign prefix (+ - or \0) */
E 34
I 34
	char sign;		/* sign prefix (' ', '+', '-', or \0) */
	char softsign;		/* temporary negative sign for floats */
E 34
D 32
	int base;		/* base for [diouxX] conversion */
E 32
	char *digs;		/* digits for [diouxX] conversion */
	char buf[BUF];		/* space for %c, %[diouxX], %[eEfgG] */
D 32
	char *_cvt();		/* handles [eEfgG] formats */
E 32
E 28
E 24
E 19
E 15
E 14
E 11
E 10
E 8
E 6
E 3
E 2

I 29
	if (fp->_flag & _IORW) {
		fp->_flag |= _IOWRT;
		fp->_flag &= ~(_IOEOF|_IOREAD);
	}
	if ((fp->_flag & _IOWRT) == 0)
		return (EOF);

E 29
I 19
	fmt = fmt0;
E 19
I 7
	digs = "0123456789abcdef";
E 7
D 2
while(*fmt != '\0')
	{
	if(*fmt != '%')
		{
		putc(*fmt++, fd);
		continue;
E 2
I 2
D 11
	for (cnt = 0; *fmt; ++fmt) {
		if (*fmt != '%') {
D 3
			PUTC(*fmt, fd);
E 3
I 3
D 10
			PUTC(*fmt, fp);
E 10
I 10
			PUTC(*fmt);
E 10
E 3
			continue;
E 11
I 11
D 15
	for (cnt = 0;; ++fmt) {
E 15
I 15
D 18
	for (buf = sbuf, cnt = 0;; ++fmt) {
E 18
I 18
D 19
	if (!buf)
		buf = sbuf;
E 19
	for (cnt = 0;; ++fmt) {
E 18
E 15
D 14
		if ((n = fp->_cnt) >= 0) {
			for (t = fp->_ptr; (ch = *fmt) != '%' && ch; ++fmt) {
				if (--n < 0)
					break;
				*t++ = ch;
E 14
I 14
		n = fp->_cnt;
D 28
		for (t = fp->_ptr; (ch = *fmt) && ch != '%'; ++cnt, ++fmt)
E 28
I 28
		for (t = (char *)fp->_ptr; (ch = *fmt) && ch != '%';
		     ++cnt, ++fmt)
E 28
			if (--n < 0
#ifdef NEGATIVE_COUNT_KLUDGE
			    && (!(fp->_flag & _IOLBF) || -n >= fp->_bufsiz)
#endif
D 28
			    || ch == '\n' && fp->_flag&_IOLBF) {
E 28
I 28
			    || ch == '\n' && fp->_flag & _IOLBF) {
E 28
				fp->_cnt = n;
D 28
				fp->_ptr = t;
				(void)_flsbuf(ch, fp);
E 28
I 28
D 30
				fp->_ptr = (u_char *)t;
E 30
I 30
				fp->_ptr = t;
E 30
				(void) _flsbuf((u_char)ch, fp);
E 28
				n = fp->_cnt;
D 28
				t = fp->_ptr;
E 14
			}
D 14
			fp->_ptr = t;
			cnt += fp->_cnt - n;
			fp->_cnt = n;
			if (ch != '%' && ch) {
				PUTC(ch);
				continue;
			}
E 11
E 2
		}
I 11
		else for (; *fmt && *fmt != '%'; ++fmt)
			PUTC(*fmt);
E 11

D 2
	fmt++;
E 2
I 2
D 3
		alternate = ladjust = length = setlong = 0;
E 3
I 3
D 11
		alternate = ladjust = width = 0;
E 11
I 11
		if (!*fmt)
E 14
I 14
			else
E 28
I 28
				t = (char *)fp->_ptr;
			} else
E 28
				*t++ = ch;
		fp->_cnt = n;
D 28
		fp->_ptr = t;
E 28
I 28
D 30
		fp->_ptr = (u_char *)t;
E 30
I 30
		fp->_ptr = t;
E 30
E 28
		if (!ch)
E 14
D 28
			return(cnt);
E 28
I 28
			return (cnt);
E 28

D 14
		alt = ladjust = width = 0;
E 14
I 14
D 24
		flags = width = 0;
E 24
I 24
D 28
		flags = fpprec = width = 0;
E 28
I 28
D 35
		flags = dprec = fpprec = width = 0;
E 35
I 35
		flags = 0; dprec = 0; fpprec = 0; width = 0;
E 35
E 28
E 24
E 14
E 11
E 3
		prec = -1;
D 28
		padc = ' ';
E 28
D 3
		printsign = '\0';
E 3
I 3
D 11
		argsize = printsign = '\0';
E 11
I 11
D 14
		argsize = sign = '\0';
E 14
I 14
		sign = '\0';
E 14
D 15
		t = buf;
E 15
E 11
E 3
E 2

D 2
	if(*fmt == 'l')
		fmt++;	     /* need to use it if sizeof(int) < sizeof(long) */

	length = 0;
	prec = -1;
	ladjust = FALSE;
	padc = ' ';

	if(*fmt == '-')
		{
		ladjust = TRUE;
		fmt++;
		}

	if(*fmt == '0')
		{
		padc = '0';
		fmt++;
		}

	if(isdigit(*fmt))
		{
		while(isdigit(*fmt))
			length = 10 * length + Ctod(*fmt++);
		}
	else if(*fmt == '*')
		{
		length = *argp++;
		fmt++;
		if(length < 0)
			{
			ladjust = !ladjust;
			length = -length;
E 2
I 2
D 14
flags:		switch (*++fmt) {
E 14
I 14
rflag:		switch (*++fmt) {
		case ' ':
D 34
			sign = ' ';
E 34
I 34
			/*
			 * ``If the space and + flags both appear, the space
			 * flag will be ignored.''
			 *	-- ANSI X3J11
			 */
			if (!sign)
				sign = ' ';
E 34
			goto rflag;
E 14
		case '#':
D 11
			alternate = 1;
E 11
I 11
D 14
			alt = 1;
E 11
			goto flags;
E 14
I 14
			flags |= ALT;
			goto rflag;
E 14
D 7
		case '%':			/* "%#%" prints as "%" */
D 3
			PUTC('%', fd);
E 3
I 3
			PUTC('%', fp);
E 3
			continue;
E 7
		case '*':
D 3
			if ((length = va_arg(argp, int)) < 0) {
				ladjust = !ladjust;
				length = -length;
E 2
			}
E 3
I 3
			/*
			 * ``A negative field width argument is taken as a
			 * - flag followed by a  positive field width.''
			 *	-- ANSI X3J11
			 * They don't exclude field widths read from args.
			 */
			if ((width = va_arg(argp, int)) >= 0)
D 14
				goto flags;
E 14
I 14
				goto rflag;
E 14
			width = -width;
D 28
			/*FALLTHROUGH*/
E 28
I 28
			/* FALLTHROUGH */
E 28
		case '-':
D 14
			ladjust = 1;
E 3
D 2
		}

	if(*fmt == '.')
		{
		fmt++;
		if(isdigit(*fmt))
			{
			prec = 0;
			while(isdigit(*fmt))
				prec = 10 * prec + Ctod(*fmt++);
E 2
I 2
			goto flags;
E 14
I 14
			flags |= LADJUST;
			goto rflag;
E 14
		case '+':
D 11
			printsign = '+';
E 11
I 11
			sign = '+';
E 11
D 14
			goto flags;
E 14
I 14
			goto rflag;
E 14
D 3
		case '-':
			ladjust = 1;
			goto flags;
E 3
		case '.':
D 3
			if (isdigit(*++fmt)) {
E 3
I 3
			if (*++fmt == '*')
D 14
				prec = va_arg(argp, int);
			else if (isdigit(*fmt)) {
				prec = 0;
E 14
I 14
				n = va_arg(argp, int);
D 28
			else if (isascii(*fmt) && isdigit(*fmt)) {
E 28
I 28
			else {
E 28
				n = 0;
E 14
E 3
D 28
				do {
D 4
					prec = 10 * prec + todigit(*fmt);
E 4
I 4
D 14
					prec = 10 * prec + *fmt - '0';
E 4
				} while isdigit(*++fmt);
E 14
I 14
D 27
					n = 10 * n + *fmt - '0';
E 27
I 27
					n = 10 * n + todigit(*fmt);
E 27
				} while (isascii(*++fmt) && isdigit(*fmt));
E 28
I 28
				while (isascii(*fmt) && isdigit(*fmt))
					n = 10 * n + todigit(*fmt++);
E 28
E 14
				--fmt;
E 2
			}
D 2
		else if(*fmt == '*')
			{
			prec = *argp++;
			fmt++;
			}
E 2
I 2
D 3
			else if (*fmt == '*')
				prec = va_arg(argp, int);
E 3
I 3
D 28
			else {
D 14
				prec = 0;
E 14
				--fmt;
D 14
				goto flags;
E 14
I 14
				prec = 0;
				goto rflag;
E 14
			}
E 28
D 14
			if (prec < 0)
				prec = -1;
E 3
			goto flags;
E 14
I 14
			prec = n < 0 ? -1 : n;
			goto rflag;
E 14
		case '0':
D 28
			padc = '0';
D 3
			goto flags;
E 3
I 3
			/*FALLTHROUGH*/
E 28
I 28
			/*
			 * ``Note that 0 is taken as a flag, not as the
			 * beginning of a field width.''
			 *	-- ANSI X3J11
			 */
			flags |= ZEROPAD;
			goto rflag;
E 28
E 3
		case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
I 13
D 14
			width = 0;
E 14
I 14
			n = 0;
E 14
E 13
			do {
D 3
				length = 10 * length + todigit(*fmt);
E 3
I 3
D 4
				width = 10 * width + todigit(*fmt);
E 4
I 4
D 14
				width = 10 * width + *fmt - '0';
E 4
E 3
			} while isdigit(*++fmt);
E 14
I 14
D 27
				n = 10 * n + *fmt - '0';
E 27
I 27
				n = 10 * n + todigit(*fmt);
E 27
			} while (isascii(*++fmt) && isdigit(*fmt));
			width = n;
E 14
			--fmt;
I 15
			goto rflag;
E 15
I 3
		case 'L':
D 14
			argsize |= LONGDBL;
			goto flags;
E 14
I 14
D 25
			/*
			 * C doesn't have a long double; use long for now.
			 * flags |= LONGDBL;
			 */
			flags |= LONGINT;
E 25
I 25
			flags |= LONGDBL;
E 25
			goto rflag;
E 14
		case 'h':
D 14
			argsize |= SHORTINT;
			goto flags;
E 14
I 14
			flags |= SHORTINT;
			goto rflag;
E 14
E 3
		case 'l':
D 3
			setlong = 1;
E 3
I 3
D 14
			argsize |= LONGINT;
E 3
			goto flags;
E 14
I 14
			flags |= LONGINT;
			goto rflag;
E 14
E 2
D 7
		}
E 7
I 7
D 9
		case '%':			/* "%#%" prints as "%" */
			PUTC('%', fp);
			break;
E 9
D 11
		case 'c': {
			char ch;
E 7

D 2
	negflag = FALSE;
	digs = "0123456789abcdef";
#ifdef ROMAN
	rdigs = "  mdclxvi";
#endif
E 2
I 2
D 7
		digs = "0123456789abcdef";
E 2

D 2
	switch(*fmt)
		{
		case 'b':
		case 'B':
			u = *argp++;
			base = 2;
			goto donum;

E 2
I 2
		switch (*fmt) {
E 2
		case 'c':
D 2
			putc(*argp++, fd);
E 2
I 2
D 3
			PUTC(va_arg(argp, int), fd);
E 3
I 3
			PUTC(va_arg(argp, int), fp);
E 7
I 7
			ch = va_arg(argp, int);
D 10
			PUTC(ch, fp);
E 10
I 10
			PUTC(ch);
E 10
E 7
E 3
E 2
			break;
I 7
		}
E 11
I 11
		case 'c':
D 15
			*t = va_arg(argp, int);
E 15
I 15
D 28
			buf[0] = va_arg(argp, int);
E 28
I 28
			*(t = buf) = va_arg(argp, int);
E 28
E 15
			size = 1;
I 15
D 28
			t = buf;
E 28
I 28
			sign = '\0';
E 28
E 15
			goto pforw;
I 32
		case 'D':
			flags |= LONGINT;
			/*FALLTHROUGH*/
E 32
E 11
E 7
I 5
		case 'd':
D 11
		case 'i':
E 11
I 11
D 14
		case 'i': {
			long reg_long;

E 11
			GETARG(reg_long);
			if (reg_long < 0) {
D 11
				reg_ulong = -reg_long;
				printsign = '-';
E 11
I 11
				_ulong = -reg_long;
E 14
I 14
		case 'i':
			ARG();
			if ((long)_ulong < 0) {
				_ulong = -_ulong;
E 14
				sign = '-';
E 11
			}
D 14
			else {
D 11
				reg_ulong = reg_long;
E 11
I 11
				_ulong = reg_long;
E 11
			}
E 14
D 11
			if (printsign)
D 10
				PUTC(printsign, fp);
E 10
I 10
				PUTC(printsign);
E 11
I 11
D 23
			if (sign)
				PUTC(sign);
E 23
E 11
E 10
			base = 10;
D 11
			goto num1;
E 11
I 11
D 23
			goto num;
E 23
I 23
			goto number;
E 23
D 14
		}
E 14
E 11
E 5
I 4
D 9
		case 'E':
E 9
		case 'e':
D 6
			if (prec == -1)
				prec = DEFPREC;
E 6
D 9
			_double = va_arg(argp, double);
D 5
			t = ecvt(_double, prec + 1, &decpt, &sign);
			bp = buf;
E 5
I 5
D 6
			t = fcvt(_double, prec + 1, &decpt, &sign);
gise:			bp = buf;
E 5
			*bp++ = *t ? *t++ : '0';
			if (alternate || prec > 0)
				*bp++ = '.';
			while (prec--)
				*bp++ = *t ? *t++ : '0';
			*bp++ = *fmt;
D 5
			*bp++ = (decpt > 0 || !_double) ? '+' : '-';
			/* we know exponents <= 99 */
			--decpt;
			*bp++ = (int)decpt / 10 + '0';
			*bp++ = (int)decpt % 10 + '0';
E 5
I 5
			if (decpt > 0 || !_double) {
				*bp++ = '+';
				--decpt;
			}
			else {
				*bp++ = '-';
				decpt = -decpt + 1;
			}
			/* exponents <= 99 in ANSI X3J11 */
			*bp++ = (int)(decpt / 10) + '0';
			*bp++ = (int)(decpt % 10) + '0';
E 6
I 6
D 8
			bp = _cvt(_double, prec, buf, EFORMAT, *fmt,
D 7
			    printsign);
E 7
I 7
			    printsign, alternate);
E 8
I 8
			bp = _cvt(_double, prec, EFORMAT, buf,
			    buf + sizeof(buf), *fmt);
E 8
E 7
E 6
E 5
			goto pbuf;
E 9
I 9
		case 'E':
E 9
E 4
I 3
		case 'f':
D 6
			if (prec == -1)
				prec = DEFPREC;
E 6
D 9
			_double = va_arg(argp, double);
D 6
			t = fcvt(_double, prec + 1, &decpt, &sign);
D 4
			if (sign)
				printsign = '-';
E 4
D 5
			bp = buf;
E 5
I 5
gisf:			bp = buf;
E 5
			if (decpt >= 0)
				for (;;) {
					*bp++ = *t ? *t++ : '0';
					if (!--decpt)
						break;
				}
D 5
			if (alternate || prec > 0)
E 5
I 5
			if (alternate || prec > 0) {
				if (decpt < 0)
					*bp++ = '0';
E 5
				*bp++ = '.';
I 5
			}
E 5
			while (decpt++) {
D 5
				*bp++ = *t ? *t++ : '0';
E 5
I 5
				*bp++ = '0';
E 5
				--prec;
			}
			while (prec--)
				*bp++ = *t ? *t++ : '0';
E 6
I 6
D 8
			bp = _cvt(_double, prec, buf, FFORMAT, 'f',
D 7
			    printsign);
E 7
I 7
			    printsign, alternate);
E 8
I 8
			bp = _cvt(_double, prec, FFORMAT, buf,
			    buf + sizeof(buf), 'f');
E 8
			goto pbuf;
		case 'G':
E 9
		case 'g':
I 9
		case 'G':
E 9
			_double = va_arg(argp, double);
I 24
			/*
D 34
			 * don't bother to do unrealistic precision; just
			 * pad it with zeroes later.  This keeps buffer size
			 * rational.
E 34
I 34
			 * don't do unrealistic precision; just pad it with
			 * zeroes later, so buffer size stays rational.
E 34
			 */
			if (prec > MAXFRACT) {
D 30
				fpprec = prec - MAXFRACT;
E 30
I 30
				if (*fmt != 'g' && *fmt != 'G' || (flags&ALT))
					fpprec = prec - MAXFRACT;
E 30
				prec = MAXFRACT;
			}
E 24
D 8
			bp = _cvt(_double, prec, buf, GFORMAT, *fmt - 2,
			    printsign, alternate);
E 8
I 8
D 9
			bp = _cvt(_double, prec, GFORMAT, buf,
			    buf + sizeof(buf), *fmt - 2);
E 9
I 9
D 11
			bp = _cvt(_double, prec, buf, buf + sizeof(buf), *fmt);
E 9
E 8
E 7
E 6
D 4
			size = bp - buf;
E 4
I 4
pbuf:			size = bp - buf;
D 6
			if (sign || printsign)
				PUTC(sign ? '-' : printsign, fp);
E 6
E 4
			if (size < width && !ladjust)
				do {
D 10
					PUTC(padc, fp);
E 10
I 10
					PUTC(padc);
E 10
				} while (--width > size);
			for (t = buf; t < bp; ++t)
D 10
				PUTC(*t, fp);
E 10
I 10
				PUTC(*t);
E 10
			for (; width > size; --width)
D 10
				PUTC(padc, fp);
E 10
I 10
				PUTC(padc);
E 10
			break;
E 11
I 11
D 15
			size = _cvt(_double, prec, buf, buf + sizeof(buf),
			    *fmt) - buf;
E 15
I 15
D 19
			size = _cvt(_double, prec, *fmt);
E 19
I 19
D 23
			size = _cvt(_double, prec, flags, *fmt, sign,
E 23
I 23
D 28
			size = _cvt(_double, prec, flags, *fmt, padc, &sign,
E 23
			    buf, buf + sizeof(buf)) - buf;
E 28
E 19
D 32
			t = buf;
I 23
D 28
			/*
			 * zero-padded sign put out here; blank padded sign
			 * placed in number in _cvt().
			 */
			if (sign && padc == '0') {
				PUTC(sign);
				--width;
			}
E 28
I 28
			size = _cvt(_double, prec, flags, *fmt, &sign,
				    t, t + sizeof(buf)) - t;
E 32
I 32
			else if (prec == -1)
				prec = DEFPREC;
I 34
			/*
			 * softsign avoids negative 0 if _double is < 0 and
			 * no significant digits will be shown
			 */
E 34
			if (_double < 0) {
D 34
				sign = '-';
E 34
I 34
				softsign = '-';
E 34
				_double = -_double;
			}
I 34
			else
				softsign = 0;
E 34
			/*
D 34
			 * _cvt may have to round up past the "start" of the
E 34
I 34
			 * cvt may have to round up past the "start" of the
E 34
			 * buffer, i.e. ``intf("%.2f", (double)9.999);'';
			 * if the first char isn't NULL, it did.
			 */
			*buf = NULL;
D 34
			size = _cvt(_double, prec, flags, *fmt, buf,
E 34
I 34
			size = cvt(_double, prec, flags, &softsign, *fmt, buf,
E 34
			    buf + sizeof(buf));
I 34
			if (softsign)
				sign = '-';
E 34
			t = *buf ? buf : buf + 1;
E 32
E 28
E 23
E 15
			goto pforw;
E 11
E 3
D 2

E 2
D 5
		case 'd':
D 2
		case 'D':
			n = *argp++;

			if(n >= 0)
				u = n;
			else	{
				u = -n;
				negflag = TRUE;
				}

E 2
I 2
D 3
			if (setlong)
				reg_long = va_arg(argp, long);
			else
				reg_long = va_arg(argp, int);
E 3
I 3
		case 'i':
			GETARG(reg_long);
E 3
			if (reg_long < 0) {
				reg_ulong = -reg_long;
				printsign = '-';
E 5
I 5
D 7
		case 'G':
D 6
		case 'g': {
			int gotoe;

			if (prec == -1)
				prec = DEFPREC;
E 6
I 6
		case 'g':
E 6
			_double = va_arg(argp, double);
D 6
			t = fcvt(_double, prec + 1, &decpt, &sign);
			gotoe = decpt > prec;
			if (!alternate) {
				for (bp = t + prec + decpt; prec &&
				    *--bp == '0'; --prec);
E 5
			}
D 5
			else {
				reg_ulong = reg_long;
E 5
I 5
			if (gotoe || decpt < -3) {
				*fmt -= 2;
				goto gise;
E 5
			}
D 5
			if (printsign)
D 3
				PUTC(printsign, fd);
E 3
I 3
				PUTC(printsign, fp);
E 3
E 2
			base = 10;
D 2

E 2
D 3
			goto donum;
E 3
I 3
			goto num1;
E 5
I 5
			--*fmt;
			goto gisf;
		}
E 6
I 6
			bp = _cvt(_double, prec, buf, GFORMAT, *fmt - 2,
			    printsign);
			goto pbuf;
E 7
E 6
E 5
		case 'n':
D 14
			*(va_arg(argp, int *)) = cnt;
E 14
I 14
D 25
			if (flags&LONGDBL || flags&LONGINT)
E 25
I 25
D 28
			if (flags&LONGINT)
E 28
I 28
			if (flags & LONGINT)
E 28
E 25
				*va_arg(argp, long *) = cnt;
D 28
			else if (flags&SHORTINT)
E 28
I 28
			else if (flags & SHORTINT)
E 28
				*va_arg(argp, short *) = cnt;
			else
				*va_arg(argp, int *) = cnt;
E 14
			break;
I 32
		case 'O':
			flags |= LONGINT;
			/*FALLTHROUGH*/
E 32
E 3
D 2

E 2
		case 'o':
D 2
		case 'O':
			u = *argp++;
E 2
I 2
D 3
			if (setlong)
				reg_ulong = va_arg(argp, long);
			else
				reg_ulong = va_arg(argp, int);
E 3
I 3
D 11
			GETARG(reg_ulong);
E 11
I 11
D 14
			GETARG(_ulong);
E 14
I 14
			ARG();
E 14
E 11
E 3
E 2
			base = 8;
D 3
			goto donum;
E 3
I 3
D 11
			if (!reg_ulong || !alternate)
				goto num1;
			bp = buf + sizeof(buf) - 1;
			do {
				*bp-- = digs[reg_ulong % base];
				reg_ulong /= base;
			} while(reg_ulong);
			size = &buf[sizeof(buf) - 1] - bp;
			if (size < --width && !ladjust)
				do {
D 10
					PUTC(padc, fp);
E 10
I 10
					PUTC(padc);
E 10
				} while (--width > size);
D 10
			PUTC('0', fp);
E 10
I 10
			PUTC('0');
E 10
D 4
			goto num3;
E 4
I 4
			goto num2;
E 11
I 11
D 23
			goto num;
E 23
I 23
			goto nosign;
E 23
E 11
E 4
D 6
			break;
E 6
		case 'p':
I 16
			/*
D 17
			 * the argument shall be a pointer to void.  The value
			 * of the pointer is converted to a sequence of
			 * printable characters, in an implementation-defined
			 * manner.
E 17
I 17
			 * ``The argument shall be a pointer to void.  The
			 * value of the pointer is converted to a sequence
			 * of printable characters, in an implementation-
			 * defined manner.''
			 *	-- ANSI X3J11
E 17
			 */
I 23
D 28
			/*NOSTRICT*/
E 28
I 28
			/* NOSTRICT */
E 28
E 23
			_ulong = (u_long)va_arg(argp, void *);
			base = 16;
D 23
			goto num;
E 23
I 23
			goto nosign;
E 23
E 16
E 3
D 2
#ifdef ROMAN
		case 'R':
			rdigs = "  MDCLXVI";
		case 'r':
			n = *argp++;
			p2 = &buf[MAXBUF - 1];

			d = n % 10;
			tack(d, &rdigs[6], &p2);
			n = n / 10;

			d = n % 10;
			tack(d, &rdigs[4], &p2);
			n = n / 10;

			d = n % 10;
			tack(d, &rdigs[2], &p2);
			n /= 10;

			d = n % 10;
			tack(d, rdigs, &p2);

			p = p2;

			goto putpad;
#endif
E 2
		case 's':
D 2
			p = (char *)(*argp++);
E 2
I 2
D 3
			if (!(p = va_arg(argp, char *)))
				p = "(null)";
			if (length > 0 && !ladjust) {
E 3
I 3
D 11
			if (!(bp = va_arg(argp, char *)))
				bp = "(null)";
			if (width > 0 && !ladjust) {
E 3
				char *savep;
E 2

D 2
			if(p == NULL)
				p = "(NULL)";

			if(length > 0 && !ladjust)
				{
				n = 0;
				p2 = p;

				for(; *p != '\0' &&
						(prec == -1 || n < prec); p++)
					n++;

				p = p2;

				while(n < length)
					{
					putc(' ', fd);
					n++;
					}
				}

			n = 0;

			while(*p != '\0')
				{
				if(++n > prec && prec != -1)
E 2
I 2
D 3
				savep = p;
				for (n = 0; *p && (prec == -1 || n < prec);
				    n++, p++);
				p = savep;
				while (n++ < length)
					PUTC(' ', fd);
E 3
I 3
				savep = bp;
				for (n = 0; *bp && (prec < 0 || n < prec);
				    n++, bp++);
				bp = savep;
				while (n++ < width)
D 10
					PUTC(' ', fp);
E 10
I 10
					PUTC(' ');
E 11
I 11
			if (!(t = va_arg(argp, char *)))
				t = "(null)";
D 12
			if ((size = strlen(t)) < prec)
E 12
I 12
D 17
			if ((size = strlen(t)) > prec && prec >= 0)
E 12
				size = prec;
E 17
I 17
			if (prec >= 0) {
				/*
				 * can't use strlen; can only look for the
				 * NUL in the first `prec' characters, and
				 * strlen() will go further.
				 */
				char *p, *memchr();

				if (p = memchr(t, 0, prec)) {
					size = p - t;
					if (size > prec)
						size = prec;
D 28
				}
				else
E 28
I 28
				} else
E 28
					size = prec;
D 28
			}
			else
E 28
I 28
			} else
E 28
				size = strlen(t);
I 28
			sign = '\0';
E 28
E 17
D 14
pforw:			if (!ladjust && width)
E 14
I 14
D 24
pforw:			if (!(flags&LADJUST) && width)
E 14
				for (n = size; n++ < width;)
					PUTC(padc);
			if (fp->_cnt - (n = size) >= 0) {
				cnt += n;
				fp->_cnt -= n;
				bcopy(t, fp->_ptr, n);
				fp->_ptr += n;
E 11
E 10
E 3
			}
D 3
			for (n = 0; *p; ++p) {
				if (++n > prec && prec != -1)
E 3
I 3
D 11
			for (n = 0; *bp; ++bp) {
				if (++n > prec && prec >= 0)
E 3
E 2
					break;
D 2

				putc(*p++, fd);
				}

			if(n < length && ladjust)
				{
				while(n < length)
					{
					putc(' ', fd);
					n++;
					}
				}

E 2
I 2
D 3
				PUTC(*p, fd);
E 3
I 3
D 10
				PUTC(*bp, fp);
E 10
I 10
				PUTC(*bp);
E 10
E 3
			}
D 3
			if (n < length && ladjust)
E 3
I 3
			if (n < width && ladjust)
E 3
				do {
D 3
					PUTC(' ', fd);
				} while (++n < length);
E 3
I 3
D 10
					PUTC(' ', fp);
E 10
I 10
					PUTC(' ');
E 10
				} while (++n < width);
E 11
I 11
			else for (; n--; ++t)
				PUTC(*t);
D 14
			if (ladjust)
E 14
I 14
			if (flags&LADJUST)
E 14
				while (width-- > size)
D 21
					PUTC(padc);
E 21
I 21
					PUTC(' ');
E 21
E 11
E 3
E 2
			break;
E 24
I 24
			goto pforw;
I 32
		case 'U':
			flags |= LONGINT;
			/*FALLTHROUGH*/
E 32
E 24
D 2

E 2
		case 'u':
D 2
		case 'U':
			u = *argp++;
E 2
I 2
D 3
			if (setlong)
				reg_ulong = va_arg(argp, long);
			else
				reg_ulong = va_arg(argp, int);
E 3
I 3
D 11
			GETARG(reg_ulong);
E 11
I 11
D 14
			GETARG(_ulong);
E 14
I 14
			ARG();
E 14
E 11
E 3
E 2
			base = 10;
D 3
			goto donum;
E 3
I 3
D 11
			goto num1;
E 11
I 11
D 23
			goto num;
E 23
I 23
			goto nosign;
E 23
E 11
E 3
D 2

E 2
		case 'X':
			digs = "0123456789ABCDEF";
I 2
D 28
			/*FALLTHROUGH*/
E 28
I 28
			/* FALLTHROUGH */
E 28
E 2
		case 'x':
D 2
			u = *argp++;
E 2
I 2
D 3
			if (setlong)
				reg_ulong = va_arg(argp, long);
			else
				reg_ulong = va_arg(argp, int);
E 3
I 3
D 11
			GETARG(reg_ulong);
E 3
			if (alternate && reg_ulong) {
E 11
I 11
D 14
			GETARG(_ulong);
E 14
I 14
			ARG();
E 14
			base = 16;
D 20
			/* alternate form for hex; leading 0x/X */
D 14
			if (alt && _ulong) {
E 14
I 14
			if (flags&ALT && _ulong) {
E 14
E 11
D 3
				PUTC('0', fd);
				PUTC(*fmt, fd);
E 3
I 3
D 10
				PUTC('0', fp);
				PUTC(*fmt, fp);
E 10
I 10
				PUTC('0');
				PUTC(*fmt);
E 10
E 3
			}
E 20
I 20
D 22
			if (!_ulong)	/* leading 0x/X only if non-zero */
E 22
I 22
			/* leading 0x/X only if non-zero */
D 28
			if (!_ulong)
E 22
				flags &= ~ALT;
E 28
I 28
			if (flags & ALT && _ulong != 0)
				flags |= HEXPREFIX;
E 28
I 23

			/* unsigned conversions */
D 28
nosign:			sign = NULL;
E 28
I 28
nosign:			sign = '\0';
E 28
E 23
E 20
E 2
D 11
			base = 16;
D 2

donum:			p = &buf[MAXBUF - 1];

			do	{
				*p-- = digs[u % base];
				u /= base;
				} while(u != 0);

			if(negflag)
				putc('-', fd);
putpad:
			size = &buf[MAXBUF - 1] - p;

			if(size < length && !ladjust)
				{
				while(length > size)
					{
					putc(padc, fd);
					length--;
					}
				}

			while(++p != &buf[MAXBUF])
				putc(*p, fd);

			if(size < length)	/* must be ladjust */
				{
				while(length > size)
					{
					putc(padc, fd);
					length--;
					}
				}

E 2
I 2
D 3
donum:			p = &buf[sizeof(buf) - 1];
E 3
I 3
num1:			bp = buf + sizeof(buf) - 1;
E 11
I 11
D 15
num:			t = buf + sizeof(buf) - 1;
E 15
I 15
D 19
num:			t = buf + MAXDIGIT - 1;
E 19
I 19
D 22
num:			t = buf + MAXBUF - 1;
E 22
I 22
			/*
I 26
			 * ``... diouXx conversions ... if a precision is
			 * specified, the 0 flag will be ignored.''
			 *	-- ANSI X3J11
			 */
D 28
number:			if (prec >= 0)
				padc = ' ';
E 28
I 28
number:			if ((dprec = prec) >= 0)
				flags &= ~ZEROPAD;

E 28
			/*
E 26
			 * ``The result of converting a zero value with an
			 * explicit precision of zero is no characters.''
			 *	-- ANSI X3J11
			 */
D 23
num:			if (!_ulong && !prec)
E 23
I 23
D 26
number:			if (!_ulong && !prec)
E 23
				break;
E 26
I 26
D 28
			if (!_ulong && !prec) {
				size = 0;
				goto pforw;
E 28
I 28
			t = buf + BUF;
			if (_ulong != 0 || prec != 0) {
				do {
					*--t = digs[_ulong % base];
					_ulong /= base;
				} while (_ulong);
				digs = "0123456789abcdef";
				if (flags & ALT && base == 8 && *t != '0')
					*--t = '0'; /* octal leading 0 */
E 28
			}
I 28
			size = buf + BUF - t;
E 28
E 26
I 23

E 23
D 24
			t = buf + MAXBUF - 1;
E 24
I 24
D 28
			t = buf + BUF - 1;
E 24
E 22
E 19
E 15
E 11
E 3
			do {
D 3
				*p-- = digs[reg_ulong % base];
E 3
I 3
D 11
				*bp-- = digs[reg_ulong % base];
E 3
				reg_ulong /= base;
			} while(reg_ulong);
D 3
			size = &buf[sizeof(buf) - 1] - p;
			if (reg_ulong && alternate && *fmt == 'o') {
				if (size < --length && !ladjust)
					do {
						PUTC(padc, fd);
					} while (--length > size);
				PUTC('0', fd);
				while (++p != &buf[MAXBUF])
					PUTC(*p, fd);
				if (size < length)	/* must be ladjust */
					for (; length > size; --length)
						PUTC(padc, fd);
			}
			else {
				if (size < length && !ladjust)
					do {
						PUTC(padc, fd);
					} while (--length > size);
				while (++p != &buf[MAXBUF])
					PUTC(*p, fd);
				if (size < length)	/* must be ladjust */
					for (; length > size; --length)
						PUTC(padc, fd);
			}
E 3
I 3
			size = &buf[sizeof(buf) - 1] - bp;
			for (; size < prec; *bp-- = '0', ++size);
			if (size < width && !ladjust)
				do {
E 11
I 11
				*t-- = digs[_ulong % base];
				_ulong /= base;
			} while(_ulong);
D 23
			digs = "0123456789abcdef";
E 23
D 15
			size = buf + sizeof(buf) - 1 - t;
E 15
I 15
D 19
			size = buf + MAXDIGIT - 1 - t;
E 19
I 19
D 20
			size = buf + MAXBUF - 1 - t;
E 19
E 15
			if (size >= prec) {
				/* alternate form for octal; leading 0 */
D 14
				if (t[1] != '0' && alt && *fmt == 'o') {
E 14
I 14
				if (t[1] != '0' && flags&ALT && *fmt == 'o') {
E 14
					*t-- = '0';
					++size;
E 20
I 20
D 24
			for (size = buf + MAXBUF - 1 - t; size < prec; ++size)
E 24
I 24
			for (size = buf + BUF - 1 - t; size < prec; ++size)
E 24
				*t-- = '0';
I 24
			digs = "0123456789abcdef";
E 28
I 28
pforw:
			/*
D 32
			 * All reasonable formats wind up here.  At this
			 * point, `t' points to a string which (if not
			 * flags&LADJUST) should be padded out to `width'
			 * places.  If flags&ZEROPAD, it should first be
			 * prefixed by any sign or other prefix; otherwise,
			 * it should be blank padded before the prefix is
			 * emitted.  After any left-hand padding and
			 * prefixing, emit zeroes required by a decimal
			 * [diouxX] precision, then print the string proper,
			 * then emit zeroes required by any leftover floating
			 * precision; finally, if LADJUST, pad with blanks.
E 32
I 32
			 * All reasonable formats wind up here.  At this point,
			 * `t' points to a string which (if not flags&LADJUST)
			 * should be padded out to `width' places.  If
			 * flags&ZEROPAD, it should first be prefixed by any
			 * sign or other prefix; otherwise, it should be blank
			 * padded before the prefix is emitted.  After any
			 * left-hand padding and prefixing, emit zeroes
			 * required by a decimal [diouxX] precision, then print
			 * the string proper, then emit zeroes required by any
			 * leftover floating precision; finally, if LADJUST,
			 * pad with blanks.
E 32
			 */
E 28
E 24
I 23

D 28
			/* alternate mode for hex and octal numbers */
E 23
			if (flags&ALT)
				switch (base) {
				case 16:
					/* avoid "00000x35" */
D 23
					if (padc == '0') {
						PUTC('0');
						PUTC(*fmt);
					}
					else {
E 23
I 23
					if (padc == ' ') {
E 23
						*t-- = *fmt;
						*t-- = '0';
I 24
						size += 2;
E 24
					}
I 23
					else {
						PUTC('0');
						PUTC(*fmt);
I 24
						width -= 2;
E 24
					}
E 23
D 24
					width -= 2;
E 24
					break;
				case 8:
					if (t[1] != '0') {
						*t-- = '0';
D 24
						--width;
E 24
I 24
						++size;
E 24
					}
					break;
E 20
				}
E 28
I 28
D 32
			/* compute actual size, so we know how much to pad */
			/* this code is not terribly satisfactory */
			/* fieldsz excludes decimal prec; realsz includes it */
E 32
I 32
			/*
			 * compute actual size, so we know how much to pad
			 * fieldsz excludes decimal prec; realsz includes it
			 */
E 32
			fieldsz = size + fpprec;
			if (sign)
				fieldsz++;
			if (flags & HEXPREFIX)
				fieldsz += 2;
			realsz = dprec > fieldsz ? dprec : fieldsz;
E 28
I 23

D 28
			if (sign) {
				/* avoid "0000-3" */
D 24
				if (padc == ' ')
E 24
I 24
				if (padc == ' ') {
E 24
					*t-- = sign;
D 24
				else
E 24
I 24
					++size;
				}
				else {
E 24
					PUTC(sign);
D 24
				--width;
E 24
I 24
					--width;
				}
E 28
I 28
			/* right-adjusting blank padding */
			if ((flags & (LADJUST|ZEROPAD)) == 0 && width)
				for (n = realsz; n < width; n++)
					PUTC(' ');
			/* prefix */
			if (sign)
				PUTC(sign);
			if (flags & HEXPREFIX) {
				PUTC('0');
				PUTC((char)*fmt);
E 28
E 24
			}
I 24
D 28
			++t;
E 28
I 28
			/* right-adjusting zero padding */
			if ((flags & (LADJUST|ZEROPAD)) == ZEROPAD)
				for (n = realsz; n < width; n++)
					PUTC('0');
			/* leading zeroes from decimal precision */
			for (n = fieldsz; n < dprec; n++)
				PUTC('0');
E 28
E 24

E 23
D 20
			}
			else
				for (; size < prec; ++size)
					*t-- = '0';
E 20
D 14
			if (!ladjust)
E 14
I 14
D 24
			if (!(flags&LADJUST))
E 14
				while (size++ < width)
E 24
I 24
D 28
pforw:			if (!(flags&LADJUST) && width)
				for (n = size + fpprec; n++ < width;)
E 24
E 11
D 10
					PUTC(padc, fp);
E 10
I 10
					PUTC(padc);
E 10
D 11
				} while (--width > size);
D 4
num3:			while (++bp != &buf[MAXBUF])
E 4
I 4
num2:			while (++bp != &buf[MAXBUF])
E 4
D 10
				PUTC(*bp, fp);
E 10
I 10
				PUTC(*bp);
E 11
I 11
D 15
			while (++t < buf + sizeof(buf))
E 15
I 15
D 19
			while (++t < buf + MAXDIGIT)
E 19
I 19
D 24
			while (++t < buf + MAXBUF)
E 24
I 24
			if (fp->_cnt - (n = size) >= 0) {
				cnt += n;
E 28
I 28
			/* the string or number proper */
			if (fp->_cnt - (n = size) >= 0 &&
			    (fp->_flag & _IOLBF) == 0) {
E 28
				fp->_cnt -= n;
D 28
				bcopy(t, fp->_ptr, n);
E 28
I 28
				bcopy(t, (char *)fp->_ptr, n);
E 28
				fp->_ptr += n;
D 28
			}
			else for (; n--; ++t)
E 24
E 19
E 15
				PUTC(*t);
E 11
E 10
D 21
			for (; width > size; --width)
D 10
				PUTC(padc, fp);
E 10
I 10
				PUTC(padc);
E 21
I 21
D 24
			while (width-- > size)
				PUTC(' ');
I 23
			digs = "0123456789abcdef";
E 24
I 24
			while (fpprec--)
E 28
I 28
			} else
				while (--n >= 0)
					PUTC(*t++);
			/* trailing f.p. zeroes */
			while (--fpprec >= 0)
E 28
				PUTC('0');
D 28
			if (flags&LADJUST)
				for (n = size + fpprec; ++n < width;)
E 28
I 28
			/* left-adjusting padding (always blank) */
			if (flags & LADJUST)
				for (n = realsz; n < width; n++)
E 28
					PUTC(' ');
I 28
D 32

E 32
			/* finally, adjust cnt */
			cnt += width > realsz ? width : realsz;
E 28
E 24
E 23
E 21
E 10
I 7
D 11
			digs = "0123456789abcdef";
E 11
E 7
E 3
E 2
			break;
D 2

		case '\0':
			fmt--;
			break;

E 2
I 2
D 28
		case '\0':		/* "%?" prints ?, unless ? is NULL */
D 3
			return(cnt);
E 3
I 3
D 11
			return(ferror(fp) ? -1 : cnt);
E 11
I 11
			return(cnt);
E 28
I 28
		case '\0':	/* "%?" prints ?, unless ? is NULL */
			return (cnt);
E 28
E 11
E 3
E 2
		default:
D 2
			putc(*fmt, fd);
E 2
I 2
D 3
			PUTC(*fmt, fd);
E 3
I 3
D 10
			PUTC(*fmt, fp);
E 10
I 10
D 28
			PUTC(*fmt);
E 28
I 28
			PUTC((char)*fmt);
			cnt++;
E 28
E 10
E 3
E 2
		}
D 2
	fmt++;
E 2
	}
I 2
D 3
	return(cnt);
E 3
I 3
D 11
	return(ferror(fp) ? -1 : cnt);
E 11
I 11
D 28
	/*NOTREACHED*/
E 28
I 28
	/* NOTREACHED */
E 28
E 11
I 6
}

D 9
char *
D 7
_cvt(number, prec, bp, format, fmtch, printsign)
E 7
I 7
D 8
_cvt(number, prec, bp, format, fmtch, printsign, alternate)
E 8
I 8
_cvt(number, prec, format, startp, endp, fmtch)
E 9
I 9
D 32
#define	EFORMAT	0x01
#define	FFORMAT	0x02
#define	GFORMAT	0x04
I 11
#define	DEFPREC	6
E 11

D 15
static char *
_cvt(number, prec, startp, endp, fmtch)
E 15
I 15
D 19
static
_cvt(number, prec, fmtch)
E 19
I 19
static char *
D 23
_cvt(number, prec, flags, fmtch, sign, startp, endp)
E 23
I 23
D 28
_cvt(number, prec, flags, fmtch, padc, sign, startp, endp)
E 28
I 28
_cvt(number, prec, flags, fmtch, sign, startp, endp)
E 32
I 32
static
D 34
_cvt(number, prec, flags, fmtch, startp, endp)
E 34
I 34
cvt(number, prec, flags, signp, fmtch, startp, endp)
E 34
E 32
E 28
E 23
E 19
E 15
E 9
E 8
E 7
	double number;
D 7
	int prec, format;
E 7
I 7
D 8
	int prec, format, alternate;
E 7
	register char *bp;
	char fmtch, printsign;
E 8
I 8
D 9
	int prec, format;
E 9
I 9
	register int prec;
E 9
D 15
	char *startp, *endp, fmtch;
E 15
I 15
D 19
	char fmtch;
E 19
I 19
	int flags;
	u_char fmtch;
D 23
	char sign, *startp, *endp;
E 23
I 23
D 28
	char padc, *sign, *startp, *endp;
E 28
I 28
D 32
	char *sign, *startp, *endp;
E 32
I 32
D 34
	char *startp, *endp;
E 34
I 34
	char *signp, *startp, *endp;
E 34
E 32
E 28
E 23
E 19
E 15
E 8
{
D 8
	int sign, decpt;
	register char *t;
	register int n;
	double fabs();
	char *ecvt(), *fcvt();
E 8
I 8
D 27
	register char *p;
E 27
I 27
	register char *p, *t;
E 27
I 9
D 32
	register int expcnt, format;
E 32
I 15
D 19
	static int maxprec = MAXPREC;
E 19
E 15
E 9
D 35
	double fract, integer, tmp, modf();
E 35
I 35
	register double fract;
E 35
D 9
	int decpt, expcnt;
E 9
I 9
D 32
	int decpt;
E 9
D 15
	char *savep;
E 15
I 15
D 19
	char *endp, *savep, *startp, *malloc();
E 19
I 19
D 27
	char *savep;
E 27
I 27
	char *savep, exponent[MAXEXP];
E 32
I 32
	int dotrim, expcnt, gformat;
I 35
	double integer, tmp, modf();
E 35
D 34
	char *exponent(), *eround(), *fround();
E 34
I 34
	char *exponent(), *round();
E 34
E 32
E 27
E 19
E 15
E 8

D 8
	if (prec == -1)
E 8
I 8
D 11
	if (prec == -1)				/* set default precision */
E 11
I 11
D 32
	if (prec == -1)
E 11
E 8
		prec = DEFPREC;
E 32
I 32
	dotrim = expcnt = gformat = 0;
	fract = modf(number, &integer);
E 32
D 8
	t = fabs(number) < 1 ? ecvt(number, prec + 1, &decpt, &sign) :
	    fcvt(number, prec + 1, &decpt, &sign);
E 8

I 15
D 19
	/* allocate space for large precision */
	if (prec > maxprec)
		buf = malloc((u_int)((maxprec = prec) + MAXFRAC + 1));

	startp = buf;
E 19
E 15
D 8
	if (sign)
		*bp++ = '-';
E 8
I 8
D 11
	p = endp - 1;
	if (number < 0) {			/* set sign */
E 11
I 11
D 32
	if (number < 0) {
E 11
D 23
		*startp++ = '-';
E 23
I 23
		*sign = '-';
E 23
		number = -number;
	}
E 32
I 32
	/* get an extra slot for rounding. */
	t = ++startp;
E 32
E 8
D 11
	else if (printsign)
E 11
I 11
D 23
	else if (sign)
E 11
D 8
		*bp++ = printsign;
E 8
I 8
D 14
		*startp++ = '+';
E 14
I 14
		*startp++ = sign;
E 23
I 23
D 28

	/* if blank padded, add sign in as part of the number */
	if (*sign && padc == ' ')
		*startp++ = *sign;
E 28
E 23
E 14
I 9

D 32
	switch(fmtch) {
	case 'e':
	case 'E':
		format = EFORMAT;
		break;
	case 'f':
		format = FFORMAT;
		break;
	case 'g':
	case 'G':
		format = GFORMAT;
		fmtch -= 2;
	}
E 9
E 8

E 32
D 8
	/* E format */
	/* use 'e' format if exponent > precision or less than -4 */
	if (format == EFORMAT ||
	    format == GFORMAT && (decpt > prec || decpt < -3)) {
		*bp++ = *t ? *t++ : '0';
		if (format != GFORMAT && prec || prec > 1) {
			*bp++ = '.';
			while(prec--)
				*bp++ = *t ? *t++ : '0';
E 8
I 8
	/*
D 32
	 * if the alternate flag is set, or, at least one digit of precision
	 * was requested, add a decimal point, unless it's the g/G format
D 11
	 * in which case we require two digits of precision, since it counts
E 11
I 11
	 * in which case we require two digits of precision, as it counts
E 11
	 * precision differently.
E 32
I 32
	 * get integer portion of number; put into the end of the buffer; the
	 * .01 is added for modf(356.0 / 10, &integer) returning .59999999...
E 32
	 */
D 11
	decpt = alternate || prec > 1 || !(format&GFORMAT) && prec;
E 11
I 11
D 14
	decpt = alt || prec > 1 || !(format&GFORMAT) && prec;
E 14
I 14
D 32
	decpt = flags&ALT || prec > (format&GFORMAT ? 1 : 0);
E 14
E 11

	expcnt = 0;
I 11
D 15
	p = endp - 1;
E 15
I 15
D 19
	p = buf + maxprec + MAXFRAC;
	endp = p + 1;
E 19
I 19
	p = endp - 1;
E 19
E 15
E 11
	fract = modf(number, &integer);
	if (integer) {
D 27
		register char *p2;

E 27
		/* get integer part of number; count decimal places */
		for (; integer; ++expcnt) {
			tmp = modf(integer / 10, &integer);
D 27
			*p-- = (int)((tmp + .03) * 10) + '0';
E 27
I 27
			*p-- = tochar((int)((tmp + .03) * 10));
E 27
E 8
		}
I 7
D 8
		else if (alternate)
			*bp++ = '.';
E 7
		if (*t && *t > '4')
			++bp[-1];
D 7
		if (format == 2) {
E 7
I 7
		if (format == GFORMAT && !alternate) {
E 7
			for (; bp[-1] == '0'; --bp);
D 7
			if (*bp == '.')
E 7
I 7
			if (bp[-1] == '.')
E 7
				--bp;
E 8
I 8

		/* copy, in reverse order, to start of buffer */
D 27
		p2 = startp;
		*p2++ = *++p;
E 27
I 27
		t = startp;
		*t++ = *++p;
E 27

E 32
I 32
	for (p = endp - 1; integer; ++expcnt) {
		tmp = modf(integer / 10, &integer);
		*p-- = tochar((int)((tmp + .01) * 10));
	}
	switch(fmtch) {
	case 'f':
		/* reverse integer into beginning of buffer */
		if (expcnt)
			for (; ++p < endp; *t++ = *p);
		else
			*t++ = '0';
E 32
		/*
D 32
		 * if the format is g/G, and the resulting exponent will be
		 * greater than the precision, use e/E format.  If e/E format,
		 * put in a decimal point as needed, and decrement precision
		 * count for each digit after the decimal point.
E 32
I 32
		 * if precision required or alternate flag set, add in a
		 * decimal point.
E 32
		 */
D 32
		if (format&GFORMAT && expcnt - 1 > prec || format&EFORMAT) {
			if (format&GFORMAT) {
				format |= EFORMAT;

				/* first digit is precision for g/G format */
				if (prec)
					--prec;
			}
			if (decpt)
E 32
I 32
		if (prec || flags&ALT)
			*t++ = '.';
		/* if requires more precision and some fraction left */
		if (fract) {
			if (prec)
				do {
					fract = modf(fract * 10, &tmp);
					*t++ = tochar((int)tmp);
				} while (--prec && fract);
			if (fract)
D 34
				startp = fround(startp, t - 1, fract);
E 34
I 34
				startp = round(fract, (int *)NULL, startp,
				    t - 1, (char)0, signp);
E 34
		}
		for (; prec--; *t++ = '0');
		break;
	case 'e':
	case 'E':
eformat:	if (expcnt) {
			*t++ = *++p;
			if (prec || flags&ALT)
E 32
D 27
				*p2++ = '.';
			for (; ++p < endp && prec; --prec, *p2++ = *p);
E 27
I 27
				*t++ = '.';
D 32
			for (; ++p < endp && prec; --prec, *t++ = *p);
E 27

D 14
			/* precision ran out; round number */
E 14
I 14
			/* precision ran out, round */
E 14
			if (p < endp) {
				if (*p > '4') {
D 27
					for (savep = p2--;; *p2-- = '0') {
						if (*p2 == '.')
							--p2;
						if (++*p2 <= '9')
E 27
I 27
					for (savep = t--;; *t-- = '0') {
						if (*t == '.')
							--t;
						if (++*t <= '9')
E 27
							break;
					}
D 27
					p2 = savep;
E 27
I 27
					t = savep;
E 27
				}
E 32
I 32
			/* if requires more precision and some integer left */
			for (; prec && ++p < endp; --prec)
				*t++ = *p;
			/*
			 * if done precision and more of the integer component,
			 * round using it; adjust fract so we don't re-round
			 * later.
			 */
			if (!prec && ++p < endp) {
D 34
				startp = eround(startp, t - 1, (double)0,
				    *p, &expcnt);
E 34
E 32
				fract = 0;
I 34
				startp = round((double)0, &expcnt, startp,
				    t - 1, *p, signp);
E 34
			}
I 32
			/* adjust expcnt for digit in front of decimal */
			--expcnt;
E 32
E 8
		}
D 8
		*bp++ = fmtch;
		if (--decpt < 0) {
			decpt = -decpt;
			*bp++ = '-';
E 8
I 8
D 32
		/*
D 11
		 * g/G in f format; if run out of precision, replace digits
		 * with zeroes, note, have to round first, otherwise lose
		 * rounding point.
E 11
I 11
		 * g/G in f format; if out of precision, replace digits with
		 * zeroes, note, have to round first.
E 11
		 */
		else if (format&GFORMAT) {
D 27
			for (; ++p < endp && prec; --prec, *p2++ = *p);
E 27
I 27
			for (; ++p < endp && prec; --prec, *t++ = *p);
E 27
			/* precision ran out; round and then add zeroes */
			if (p < endp) {
				if (*p > '4') {
D 27
					for (savep = p2--; ++*p2 > '9';
					    *p2-- = '0');
					p2 = savep;
E 27
I 27
					for (savep = t--; ++*t > '9';
					    *t-- = '0');
					t = savep;
E 27
				}
				do {
D 27
					*p2++ = '0';
E 27
I 27
					*t++ = '0';
E 27
				} while (++p < endp);
				fract = 0;
E 32
I 32
		/* until first fractional digit, decrement exponent */
		else if (fract) {
			/* adjust expcnt for digit in front of decimal */
			for (expcnt = -1;; --expcnt) {
				fract = modf(fract * 10, &tmp);
				if (tmp)
					break;
E 32
			}
D 32
			if (decpt)
E 32
I 32
			*t++ = tochar((int)tmp);
			if (prec || flags&ALT)
E 32
D 27
				*p2++ = '.';
E 27
I 27
				*t++ = '.';
E 27
E 8
		}
I 8
D 32
		/* f format */
E 32
		else {
D 27
			for (; ++p < endp; *p2++ = *p);
E 27
I 27
D 32
			for (; ++p < endp; *t++ = *p);
E 27
			if (decpt)
E 32
I 32
			*t++ = '0';
			if (prec || flags&ALT)
E 32
D 27
				*p2++ = '.';
E 27
I 27
				*t++ = '.';
E 27
		}
D 27
		p = p2;
E 27
I 27
D 32
		p = t;
E 27
	}
	/*
D 14
	 * it's unclear from the ANSI X3J11 spec if the g/G format should
	 * just result in an empty string, because it's supposed to remove
	 * trailing zeroes.  That seems counter-intuitive, so here it does
	 * what f and e/E do; if no fraction, the number was zero, and if
D 11
	 * no precision can't show anything after the decimal point.
E 11
I 11
	 * no precision, can't show anything after the decimal point.
E 14
I 14
	 * if no fraction, the number was zero, and if no precision, can't
	 * show anything after the decimal point.
E 14
E 11
	 */
	else if (!fract || !prec) {
		*startp++ = '0';
D 14
		if (decpt)
E 14
I 14
D 31
		if (decpt && !(format&GFORMAT))
E 31
I 31
		if (decpt && !(format&GFORMAT)) {
E 31
E 14
			*startp++ = '.';
I 31
			while (prec-- > 0)
				*startp++ = '0';
E 32
I 32
		/* if requires more precision and some fraction left */
		if (fract) {
			if (prec)
				do {
					fract = modf(fract * 10, &tmp);
					*t++ = tochar((int)tmp);
				} while (--prec && fract);
			if (fract)
D 34
				startp = eround(startp, t - 1, fract,
				    (char)0, &expcnt);
E 34
I 34
				startp = round(fract, &expcnt, startp,
				    t - 1, (char)0, signp);
E 34
E 32
		}
E 31
D 14
		*startp++ = '\0';
E 14
I 14
D 32
		*startp = '\0';
E 14
D 15
		return(startp);
E 15
I 15
D 19
		return(startp - buf);
E 19
I 19
		return(startp);
E 19
E 15
	}
	/*
	 * if the format is g/G, and the resulting exponent will be less than
	 * -4 use e/E format.  If e/E format, compute exponent value.
	 */
	else if (format&GFORMAT && fract < .0001 || format&EFORMAT) {
		format |= EFORMAT;
		if (fract)
			for (p = startp; fract;) {
				fract = modf(fract * 10, &tmp);
				if (!tmp) {
					--expcnt;
					continue;
				}
D 27
				*p++ = (int)tmp + '0';
E 27
I 27
				*p++ = tochar((int)tmp);
E 27
				break;
			}
E 32
I 32
		/* if requires more precision */
		for (; prec--; *t++ = '0');

		/* unless alternate flag, trim any g/G format trailing 0's */
		if (gformat && !(flags&ALT)) {
			while (t > startp && *--t == '0');
			if (*t == '.')
				--t;
			++t;
		}
		t = exponent(t, expcnt, fmtch);
		break;
	case 'g':
	case 'G':
		/* a precision of 0 is treated as a precision of 1. */
		if (!prec)
			++prec;
		/*
		 * ``The style used depends on the value converted; style e
		 * will be used only if the exponent resulting from the
		 * conversion is less than -4 or greater than the precision.''
		 *	-- ANSI X3J11
		 */
		if (expcnt > prec || !expcnt && fract && fract < .0001) {
			/*
			 * g/G format counts "significant digits, not digits of
			 * precision; for the e/E format, this just causes an
			 * off-by-one problem, i.e. g/G considers the digit
			 * before the decimal point significant and e/E doesn't
			 * count it as precision.
			 */
			--prec;
			fmtch -= 2;		/* G->E, g->e */
			gformat = 1;
			goto eformat;
		}
		/*
		 * reverse integer into beginning of buffer,
		 * note, decrement precision
		 */
		if (expcnt)
			for (; ++p < endp; *t++ = *p, --prec);
E 32
E 8
		else
D 8
			*bp++ = '+';
		*bp++ = decpt / 10 + '0';
		*bp++ = decpt % 10 + '0';
E 8
I 8
D 32
			*p++ = '0';
E 32
I 32
			*t++ = '0';
		/*
		 * if precision required or alternate flag set, add in a
		 * decimal point.  If no digits yet, add in leading 0.
		 */
		if (prec || flags&ALT) {
			dotrim = 1;
			*t++ = '.';
		}
		else
			dotrim = 0;
		/* if requires more precision and some fraction left */
		if (fract) {
			if (prec) {
				do {
					fract = modf(fract * 10, &tmp);
					*t++ = tochar((int)tmp);
				} while(!tmp);
				while (--prec && fract) {
					fract = modf(fract * 10, &tmp);
					*t++ = tochar((int)tmp);
				}
			}
			if (fract)
D 34
				startp = fround(startp, t - 1, fract);
E 34
I 34
				startp = round(fract, (int *)NULL, startp,
				    t - 1, (char)0, signp);
E 34
		}
		/* alternate format, adds 0's for precision, else trim 0's */
		if (flags&ALT)
			for (; prec--; *t++ = '0');
		else if (dotrim) {
			while (t > startp && *--t == '0');
			if (*t != '.')
				++t;
		}
	}
	return(t - startp);
}
E 32

D 32
		/* g/G format, decrement precision for first digit */
		if (format&GFORMAT && prec)
			--prec;
E 32
I 32
static char *
D 34
fround(start, end, fract)
	register char *start, *end;
E 34
I 34
round(fract, exp, start, end, ch, signp)
E 34
	double fract;
D 34
{
	double tmp;
E 32

D 32
		/* add decimal after first non-zero digit */
		if (decpt)
			*p++ = '.';
E 8
	}
D 8
	/* F format */
E 8
I 8
	/*
	 * f format or g/G printed as f format; don't worry about decimal
	 * point, if g/G format doesn't need it, will get stripped later.
	 */
E 8
	else {
D 8
		if (decpt <= 0) {
			*bp++ = '0';
			if (prec) {
				*bp++ = '.';
				if (format == FFORMAT)
					while (decpt++ < 0 && prec--)
						*bp++ = '0';
				else while (decpt++ < 0)
					*bp++ = '0';
E 8
I 8
		p = startp;
		*p++ = '0';
		*p++ = '.';
	}
E 32
I 32
	(void)modf(fract * 10, &tmp);
	if (tmp > 4)
		for (;; --end) {
			if (*end == '.')
				--end;
			if (++*end <= '9')
				break;
			*end = '0';
			/* add extra digit to round past buffer beginning */
			if (end == start) {
				*--end = '1';
				--start;
				break;
			}
		}
	return(start);
}
E 32

D 15
	/* finish out requested precision from fractional value */
	while (prec--)
		if (fract) {
			fract = modf(fract * 10, &tmp);
			*p++ = (int)tmp + '0';
		}
		else
			*p++ = '0';
E 15
I 15
D 32
	/* finish out requested precision */
	while (fract && prec-- > 0) {
		fract = modf(fract * 10, &tmp);
D 27
		*p++ = (int)tmp + '0';
E 27
I 27
		*p++ = tochar((int)tmp);
E 27
	}
	while (prec-- > 0)
		*p++ = '0';
E 32
I 32
static char *
eround(start, end, fract, ch, exp)
	register char *start, *end;
	double fract;
	char ch;
E 34
	int *exp;
I 34
	register char *start, *end;
	char ch, *signp;
E 34
{
	double tmp;
E 32
E 15

D 32
	/*
	 * if any fractional value left, "round" it back up to the beginning
	 * of the number, fixing the exponent as necessary, and avoiding the
	 * decimal point.
	 */
	if (fract) {
E 32
I 32
	if (fract)
E 32
		(void)modf(fract * 10, &tmp);
D 32
		if (tmp > 4) {
			for (savep = p--;; *p-- = '0') {
				if (*p == '.')
					--p;
				if (p == startp) {
					*p = '1';
					++expcnt;
					break;
				}
				if (++*p <= '9')
					break;
E 32
I 32
	else
		tmp = todigit(ch);
	if (tmp > 4)
		for (;; --end) {
			if (*end == '.')
				--end;
			if (++*end <= '9')
				break;
			*end = '0';
D 34
			/* increment exponent to round past buffer beginning */
E 34
			if (end == start) {
D 34
				*end = '1';
				++*exp;
E 34
I 34
				if (exp) {	/* e/E; increment exponent */
					*end = '1';
					++*exp;
				}
				else {		/* f; add extra digit */
					*--end = '1';
					--start;
				}
E 34
				break;
E 32
E 8
			}
I 34
		}
	/* ``"%.3f", (double)-0.0004'' gives you a negative 0. */
	else if (*signp == '-')
		for (;; --end) {
			if (*end == '.')
				--end;
			if (*end != '0')
				break;
			if (end == start)
				*signp = 0;
E 34
I 7
D 8
			else if (alternate)
				*bp++ = '.';
E 8
I 8
D 32
			p = savep;
E 32
E 8
E 7
		}
D 8
		else {
			for (n = 1; n <= decpt; n++)
				*bp++ = *t++;
D 7
			if (prec)
E 7
I 7
			if (prec || alternate)
E 7
				*bp++ = '.';
E 8
I 8
D 32
	}
E 32
I 32
	return(start);
}
E 32

D 32
	/*
	 * if a g/G format and not alternate flag, lose trailing zeroes,
	 * if e/E or g/G format, and last char is decimal point, lose it.
	 */
D 11
	if (!alternate) {
E 11
I 11
D 14
	if (!alt) {
E 14
I 14
	if (!(flags&ALT)) {
E 14
E 11
		if (format&GFORMAT)
			for (; p[-1] == '0'; --p);
		if (format&(GFORMAT|EFORMAT) && p[-1] == '.')
			--p;
	}
E 32
I 32
static char *
exponent(p, exp, fmtch)
	register char *p;
	register int exp;
	u_char fmtch;
{
	register char *t;
	char expbuf[MAXEXP];
E 32

D 32
	/* if an e/E format, add exponent */
	if (format&EFORMAT) {
		*p++ = fmtch;
		if (--expcnt < 0) {
			expcnt = -expcnt;
			*p++ = '-';
E 8
		}
D 8
		for (n = 1; n <= prec; n++)
			*bp++ = *t ? *t++ : '0';
D 7
		if (format == GFORMAT) {
E 7
I 7
		if (format == GFORMAT && !alternate) {
E 7
			for (; bp[-1] == '0'; --bp);
			if (bp[-1] == '.')
				--bp;
		}
E 8
I 8
		else
			*p++ = '+';
D 27
		*p++ = expcnt / 10 + '0';
		*p++ = expcnt % 10 + '0';
E 27
I 27
		t = exponent + MAXEXP;
		if (expcnt > 9) {
			do {
				*--t = tochar(expcnt % 10);
			} while ((expcnt /= 10) > 9);
			*--t = tochar(expcnt);
			for (; t < exponent + MAXEXP; *p++ = *t++);
		}
		else {
			*p++ = '0';
			*p++ = tochar(expcnt);
		}
E 32
I 32
	*p++ = fmtch;
	if (exp < 0) {
		exp = -exp;
		*p++ = '-';
	}
	else
		*p++ = '+';
	t = expbuf + MAXEXP;
	if (exp > 9) {
		do {
			*--t = tochar(exp % 10);
		} while ((exp /= 10) > 9);
		*--t = tochar(exp);
		for (; t < expbuf + MAXEXP; *p++ = *t++);
	}
	else {
		*p++ = '0';
		*p++ = tochar(exp);
E 32
E 27
E 8
	}
D 8
	return(bp);
E 8
I 8
D 15
	return(p);
E 15
I 15
D 19
	return(p - buf);
E 19
I 19
	return(p);
E 19
E 15
E 8
E 6
E 3
E 2
}
I 3
D 4

E 4
E 3
D 2

#ifdef ROMAN

static
tack(d, digs, p)
int d;
char *digs;
char **p;
{
if(d == 0) return;
if(d >= 1 && d <= 3)
	{
	doit(d, digs[2], p);
	return;
	}

if(d == 4 || d == 5)
	{
	**p = digs[1];
	(*p)--;
	}

if(d == 4)
	{
	**p = digs[2];
	(*p)--;
	return;
	}

if(d == 5) return;

if(d >= 6 && d <= 8)
	{
	doit(d - 5, digs[2], p);
	**p = digs[1];
	(*p)--;
	return;
	}

/* d == 9 */

**p = digs[0];
(*p)--;
**p = digs[2];
(*p)--;
return;
}

static
doit(d, one, p)
int d;
char one;
char **p;
{
int i;

for(i = 0; i < d; i++)
	{
	**p = one;
	(*p)--;
	}
}

#endif
E 2
E 1
