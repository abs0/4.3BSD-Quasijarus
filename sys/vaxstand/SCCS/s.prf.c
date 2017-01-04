h01037
s 00040/00022/00146
d D 7.7 04/02/07 11:35:20 msokolov 18 17
c started standalone system revamping
e
s 00003/00003/00165
d D 7.6 88/08/27 07:22:38 tef 17 16
c Add support for microvax 3000.
e
s 00018/00000/00150
d D 7.5 88/06/06 15:47:46 marc 16 15
c support for display drivers as console
e
s 00000/00064/00150
d D 7.4 88/02/22 12:58:14 bostic 15 14
c move printn() and gets() to machine independent file
e
s 00001/00001/00213
d D 7.3 88/01/28 20:53:12 karels 14 13
c uvax changes; fix devsw index in confxx; header updates
e
s 00003/00001/00211
d D 7.2 86/11/04 13:39:07 karels 13 12
c don't erase more than input
e
s 00001/00001/00211
d D 7.1 86/06/05 01:44:15 mckusick 12 11
c 4.3BSD release version
e
s 00009/00011/00203
d D 6.4 86/03/08 20:12:07 karels 11 9
c minor niceties
e
s 00010/00011/00203
d R 6.4 86/03/08 18:00:33 karels 10 9
c minor niceties
e
s 00001/00000/00213
d D 6.3 85/07/17 13:44:53 mckusick 9 8
c add DEL as an erase character
e
s 00007/00001/00206
d D 6.2 85/06/08 13:10:35 mckusick 8 7
c Add copyright
e
s 00000/00000/00207
d D 6.1 83/07/29 07:47:27 sam 7 6
c 4.2 distribution
e
s 00003/00002/00204
d D 4.4 82/11/13 23:15:13 sam 6 5
c move includes for 4.1c directory layout
e
s 00000/00026/00206
d D 4.3 81/05/05 21:55:22 wnj 5 4
c flush half-ascii terminal support and mapping to all lower case
e
s 00098/00048/00134
d D 4.2 81/03/15 20:46:29 wnj 4 3
c 
e
s 00000/00000/00182
d D 4.1 80/11/09 16:29:30 bill 3 2
c stamp for 4bsd
e
s 00001/00000/00181
d D 1.2 80/10/19 01:17:04 bill 2 1
c take ^U
e
s 00181/00000/00000
d D 1.1 80/06/28 10:43:03 bill 1 0
c date and time created 80/06/28 10:43:03 by bill
e
u
U
t
T
I 1
D 4
/*	%M%	%I%	%G% */
E 4
I 4
D 8
/*	%M%	%I%	%E%	*/
E 8
I 8
/*
D 12
 * Copyright (c) 1982 Regents of the University of California.
E 12
I 12
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 12
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 8
E 4

I 4
D 14
#include "../h/param.h"
E 14
I 14
#include "param.h"
E 14
E 4
D 6
#include "../h/cons.h"
#include "../h/mtpr.h"
E 6
I 6

I 18
#include "../vax/cpu.h"
E 18
#include "../vax/mtpr.h"
#include "../vax/cons.h"
E 6

/*
 * Scaled down version of C Library printf.
D 4
 * Only %s %u %d (==%u) %o %x %D %c are recognized.
 * Used to print diagnostic information
 * directly on console tty.
 * Since it is not interrupt driven,
 * all system activities are pretty much
 * suspended.
 * Printf should not be used for chit-chat.
E 4
I 4
 * Used to print diagnostic information directly on console tty.
 * Since it is not interrupt driven, all system activities are
 * suspended.  Printf should not be used for chit-chat.
 *
 * One additional format: %b is supported to decode error registers.
 * Usage is:
 *	printf("reg=%b\n", regval, "<base><arg>*");
 * Where <base> is the output base expressed as a control character,
 * e.g. \10 gives octal; \20 gives hex.  Each arg is a sequence of
 * characters, the first of which gives the bit number to be inspected
 * (origin 1), and the next characters (up to a control character, i.e.
 * a character <= 32), give the name of the register.  Thus
 *	printf("reg=%b\n", 3, "\10\2BITTWO\1BITONE\n");
 * would produce output:
 *	reg=2<BITTWO,BITONE>
E 4
 */
/*VARARGS1*/
printf(fmt, x1)
D 4
register char *fmt;
unsigned x1;
E 4
I 4
	char *fmt;
	unsigned x1;
E 4
{
D 4
	register c;
	register unsigned int *adx;
E 4
I 4

	prf(fmt, &x1);
}

prf(fmt, adx)
	register char *fmt;
	register u_int *adx;
{
	register int b, c, i;
E 4
	char *s;
I 4
	int any;
E 4

D 4
	adx = &x1;
E 4
loop:
D 4
	while((c = *fmt++) != '%') {
E 4
I 4
	while ((c = *fmt++) != '%') {
E 4
		if(c == '\0')
			return;
		putchar(c);
	}
I 4
again:
E 4
	c = *fmt++;
D 4
	if(c == 'X')
		printx((long)*adx);
	else if(c == 'd' || c == 'u' || c == 'o' || c == 'x')
		printn((long)*adx, c=='o'? 8: (c=='x'? 16:10));
	else if(c == 'c')
		putchar(*adx);
	else if(c == 's') {
E 4
I 4
	/* THIS CODE IS VAX DEPENDENT IN HANDLING %l? AND %c */
	switch (c) {

	case 'l':
		goto again;
	case 'x': case 'X':
		b = 16;
		goto number;
	case 'd': case 'D':
	case 'u':		/* what a joke */
		b = 10;
		goto number;
	case 'o': case 'O':
		b = 8;
number:
		printn((u_long)*adx, b);
		break;
	case 'c':
		b = *adx;
		for (i = 24; i >= 0; i -= 8)
			if (c = (b >> i) & 0x7f)
				putchar(c);
		break;
	case 'b':
		b = *adx++;
E 4
		s = (char *)*adx;
D 4
		while(c = *s++)
E 4
I 4
		printn((u_long)b, *s++);
		any = 0;
		if (b) {
D 11
			putchar('<');
E 11
			while (i = *s++) {
				if (b & (1 << (i-1))) {
D 11
					if (any)
						putchar(',');
E 11
I 11
					putchar(any? ',' : '<');
E 11
					any = 1;
					for (; (c = *s) > 32; s++)
						putchar(c);
				} else
					for (; *s > 32; s++)
						;
			}
D 11
			putchar('>');
E 11
I 11
			if (any)
				putchar('>');
E 11
		}
		break;

	case 's':
		s = (char *)*adx;
		while (c = *s++)
E 4
			putchar(c);
D 4
	} else if (c == 'D') {
		printn(*(long *)adx, 10);
		adx += (sizeof(long) / sizeof(int)) - 1;
E 4
I 4
		break;
E 4
	}
	adx++;
	goto loop;
}

D 4
printx(x)
long x;
{
	int i;

	for (i = 0; i < 8; i++)
		putchar("0123456789ABCDEF"[(x>>((7-i)*4))&0xf]);
}

E 4
/*
D 4
 * Print an unsigned integer in base b.
E 4
I 4
D 15
 * Printn prints a number n in base b.
 * We don't use recursion to avoid deep kernel stacks.
E 4
 */
printn(n, b)
D 4
long n;
E 4
I 4
	u_long n;
E 4
{
D 4
	register long a;
E 4
I 4
	char prbuf[11];
	register char *cp;
E 4

D 4
	if (n<0) {	/* shouldn't happen */
E 4
I 4
	if (b == 10 && (int)n < 0) {
E 4
		putchar('-');
D 4
		n = -n;
E 4
I 4
		n = (unsigned)(-(int)n);
E 4
	}
D 4
	if(a = n/b)
		printn(a, b);
	putchar("0123456789ABCDEF"[(int)(n%b)]);
E 4
I 4
	cp = prbuf;
	do {
		*cp++ = "0123456789abcdef"[n%b];
		n /= b;
	} while (n);
	do
		putchar(*--cp);
	while (cp > prbuf);
E 4
}

/*
E 15
 * Print a character on console.
D 11
 * Attempts to save and restore device
 * status.
D 4
 * If the switches are 0, all
 * printing is inhibited.
E 4
 *
 * Whether or not printing is inhibited,
 * the last MSGBUFS characters
 * are saved in msgbuf for inspection later.
E 11
 */
putchar(c)
D 4
register c;
E 4
I 4
	register c;
E 4
{
D 18
	register s, timo;
I 16
D 17
#if VAX630
E 17
I 17
#if VAX630 || VAX650
E 17
	extern (*v_putc)();
E 18
I 18
	extern int cpu;
E 18
E 16

I 16
D 18
	if (v_putc) {
		(*v_putc)(c);
		if (c == '\n')
			(*v_putc)('\r');
		return;
	}
E 18
I 18
	if (c == '\n')
		putchar('\r');
	switch (cpu) {
#if VAX630 || VAX650
	case VAX_630:
	case VAX_650:
		c6xxputc(c);
		break;
E 18
#endif
I 18
	default:
		_putchar(c);
	}
}

_putchar(c)
	register c;
{
	register s, timo;

E 18
E 16
	timo = 30000;
	/*
	 * Try waiting for the console tty to come ready,
	 * otherwise give up after a reasonable time.
	 */
	while((mfpr(TXCS)&TXCS_RDY) == 0)
		if(--timo == 0)
			break;
	if(c == 0)
		return;
	s = mfpr(TXCS);
	mtpr(TXCS,0);
	mtpr(TXDB, c&0xff);
D 18
	if(c == '\n')
		putchar('\r');
	putchar(0);
E 18
I 18
	_putchar(0);
E 18
	mtpr(TXCS, s);
}

getchar()
{
	register c;
I 16
D 17
#if VAX630
E 17
I 17
D 18
#if VAX630 || VAX650
E 17
	extern (*v_getc)();
E 18
I 18
	extern int cpu;
E 18
E 16

I 16
D 18
	if (v_getc) {
		c = (*v_getc)();
	} else {
#endif
E 16
	while((mfpr(RXCS)&RXCS_DONE) == 0)
		;
	c = mfpr(RXDB)&0177;
E 18
I 18
	switch (cpu) {
E 18
I 16
D 17
#if VAX630
E 17
I 17
#if VAX630 || VAX650
E 17
D 18
	}
E 18
I 18
	case VAX_630:
	case VAX_650:
		c = c6xxgetc(c);
		break;
E 18
#endif
I 18
	default:
		c = _getchar();
	}
E 18
E 16
	if (c=='\r')
		c = '\n';
D 13
	putchar(c);
E 13
I 13
	if (c != '\b' && c != '\177')
		putchar(c);
I 18
	return(c);
}

_getchar()
{
	register c;

	while((mfpr(RXCS)&RXCS_DONE) == 0)
		;
	c = mfpr(RXDB)&0177;
E 18
E 13
	return(c);
D 15
}

gets(buf)
D 4
char	*buf;
E 4
I 4
	char *buf;
E 4
{
D 4
register char *lp;
register c;
E 4
I 4
	register char *lp;
	register c;
E 4

	lp = buf;
	for (;;) {
		c = getchar() & 0177;
D 5
		if (c>='A' && c<='Z')
			c -= 'A' - 'a';
		if (lp != buf && *(lp-1) == '\\') {
			lp--;
			if (c>='a' && c<='z') {
				c += 'A' - 'a';
				goto store;
			}
			switch ( c) {
			case '(':
				c = '{';
				break;
			case ')':
				c = '}';
				break;
			case '!':
				c = '|';
				break;
			case '^':
				c = '~';
				break;
			case '\'':
				c = '`';
				break;
			}
		}
E 5
D 11
	store:
E 11
		switch(c) {
		case '\n':
		case '\r':
			c = '\n';
			*lp++ = '\0';
			return;
		case '\b':
I 11
			if (lp > buf) {
				lp--;
I 13
				putchar('\b');
E 13
				putchar(' ');
				putchar('\b');
			}
			continue;
E 11
		case '#':
I 9
		case '\177':
E 9
			lp--;
			if (lp < buf)
				lp = buf;
			continue;
		case '@':
I 2
		case 'u'&037:
E 2
			lp = buf;
			putchar('\n');
			continue;
		default:
			*lp++ = c;
		}
	}
E 15
}
E 1
