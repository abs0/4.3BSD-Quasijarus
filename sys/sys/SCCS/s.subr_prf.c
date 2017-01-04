h26071
s 00021/00003/00387
d D 7.13 02/08/02 22:07:33 msokolov 60 59
c add sprintf
e
s 00002/00002/00388
d D 7.12 88/07/25 11:40:19 karels 59 58
c KDB => KADB
e
s 00000/00013/00390
d D 7.11 88/05/26 08:57:31 karels 58 57
c change harderr to diskerr and move to ufs_disksubr.c
e
s 00010/00001/00393
d D 7.10 88/05/25 11:21:46 karels 57 56
c lint, add comments on %r
e
s 00003/00003/00391
d D 7.9 88/05/22 15:05:39 karels 56 55
c lint
e
s 00024/00008/00370
d D 7.8 88/02/08 21:39:03 karels 55 54
c printf %r; endian=>byte_order; lint; add msgbufmapped
e
s 00004/00002/00374
d D 7.7 87/03/29 20:43:32 karels 54 53
c don't let uprintf be interrupted (callers hold locked inodes, etc)
e
s 00013/00001/00363
d D 7.6 87/03/13 10:48:47 karels 53 52
c drop into kdb on panic, too
e
s 00002/00002/00362
d D 7.5 87/02/26 18:05:48 karels 52 51
c do it right
e
s 00016/00004/00348
d D 7.4 87/02/21 15:13:02 karels 51 50
c virtual consoles
e
s 00034/00015/00318
d D 7.3 86/11/03 12:00:08 karels 50 49
x 49
c merge in tahoe support
e
s 00018/00005/00328
d D 7.2 86/08/09 18:02:22 karels 49 48
c add substitutable cnputc, user console
e
s 00001/00001/00332
d D 7.1 86/06/05 00:06:54 mckusick 48 47
c 4.3BSD release version
e
s 00001/00001/00332
d D 6.13 86/02/26 16:04:59 bloom 47 46
c fix problem reading klog when last putchar write last char in buffer
e
s 00001/00001/00332
d D 6.12 86/02/23 23:10:10 karels 46 45
c lint
e
s 00003/00001/00330
d D 6.11 86/02/19 17:42:45 karels 45 44
c as ifdef the code, ifdef the variable
e
s 00043/00016/00288
d D 6.10 85/11/04 18:04:04 karels 44 43
c log tprintf's at LOG_INFO; block or skip tty if output queue is full
e
s 00001/00001/00303
d D 6.9 85/09/17 18:28:05 eric 43 42
c facilities in syslog
e
s 00001/00001/00303
d D 6.8 85/09/16 13:11:50 karels 42 41
c dkunit is gone
e
s 00007/00001/00297
d D 6.7 85/06/08 14:41:33 mckusick 41 40
c Add copyright
e
s 00012/00002/00286
d D 6.6 85/03/18 15:22:02 karels 40 39
c use separate global for open flag; print logged errors if log isn't 
c open yet; tprintf goes to log also
e
s 00009/00012/00279
d D 6.5 84/12/27 17:26:02 karels 39 38
c silliness
e
s 00001/00000/00290
d D 6.4 84/12/21 14:23:58 bloom 38 37
c include ioctl.h
e
s 00012/00012/00278
d D 6.3 84/08/29 20:21:32 bloom 37 36
c Change to includes.  no more ../h
e
s 00063/00027/00227
d D 6.2 84/07/17 16:16:59 ralph 36 35
c changes for /dev/klog. tprintf() interface added.
e
s 00000/00000/00254
d D 6.1 83/07/29 06:35:59 sam 35 34
c 4.2 distribution
e
s 00004/00016/00250
d D 4.28 83/07/01 02:19:10 sam 34 33
c purge #if sun's
e
s 00002/00000/00264
d D 4.27 83/05/27 12:47:29 sam 33 32
c merge of bill's code plus lint (plus, of course, cleanup of bill's bugs)
e
s 00008/00001/00256
d D 4.26 83/05/18 02:01:02 sam 32 31
c sun changes
e
s 00005/00003/00252
d D 4.25 82/12/17 11:45:44 sam 31 30
c sun merge
e
s 00004/00004/00251
d D 4.24 82/10/31 14:14:34 root 30 29
c change #if to #ifdef
e
s 00016/00001/00239
d D 4.23 82/10/31 00:26:35 root 29 28
c first version with 68k stuff
e
s 00001/00001/00239
d D 4.22 82/10/10 15:34:16 root 28 27
c put headers for vax in separate directories
e
s 00003/00002/00237
d D 4.21 82/01/16 20:59:31 wnj 27 26
c clean crashes! 
e
s 00001/00001/00238
d D 4.20 82/01/14 17:00:44 wnj 26 25
c before move async to file table
e
s 00002/00002/00237
d D 4.19 81/11/20 14:43:18 wnj 25 23
c more lint
e
s 00069/00013/00226
d R 4.19 81/08/31 01:09:46 wnj 24 23
c implement error log device and time printing
e
s 00002/00001/00237
d D 4.18 81/06/11 15:42:38 wnj 23 22
c fix per kre to %B
e
s 00004/00000/00234
d D 4.17 81/05/11 11:14:02 root 22 21
c %%
e
s 00001/00000/00233
d D 4.16 81/03/17 05:50:21 wnj 21 20
c restor lost %s
e
s 00001/00001/00232
d D 4.15 81/03/09 01:48:02 wnj 20 19
c lint and a few minor fixed
e
s 00003/00004/00230
d D 4.14 81/03/09 00:32:58 wnj 19 18
c lint
e
s 00015/00003/00219
d D 4.13 81/03/06 18:20:38 wnj 18 17
c reformatting
e
s 00000/00014/00222
d D 4.12 81/03/03 11:06:50 wnj 17 16
c drop prdev
e
s 00044/00027/00192
d D 4.11 81/02/28 17:17:52 wnj 16 15
c changes for rmalloc, rmfree, malloc.c
e
s 00026/00012/00193
d D 4.10 81/02/25 21:23:27 wnj 15 14
c working %b code
e
s 00008/00009/00197
d D 4.9 81/02/15 12:20:06 wnj 14 13
c minor
e
s 00001/00001/00205
d D 4.8 81/02/08 18:34:48 wnj 13 12
c first working autoconf version
e
s 00073/00129/00133
d D 4.7 81/02/08 01:11:38 wnj 12 11
c misc pre-mba changes (non-recursive printf, futz, resuba, %uXX...)
e
s 00032/00003/00230
d D 4.6 81/02/07 15:43:04 kre 11 10
c non-negative hex + uprintf
e
s 00007/00005/00226
d D 4.5 81/01/28 12:04:05 toy 10 9
c unsigned hex; circular msgbuf
e
s 00009/00004/00222
d D 4.4 81/01/15 19:35:40 wnj 9 8
c fixes for saved msgbuf through crashes
e
s 00001/00001/00225
d D 4.3 80/11/09 23:34:46 bill 8 7
c function results (void)'ed for minor lint
e
s 00001/00001/00225
d D 4.2 80/11/09 23:00:38 bill 7 6
c minor lint
e
s 00000/00000/00226
d D 4.1 80/11/09 17:32:22 bill 6 5
c minor fixups to restart stuff; version 4.1 for distrib
e
s 00001/00002/00225
d D 3.5 80/10/11 21:36:05 bill 5 4
c remove update() in panic()
e
s 00004/00005/00223
d D 3.4 80/10/02 10:40:53 bill 4 3
c first attempt at reboot stuff
e
s 00115/00017/00113
d D 3.3 80/06/22 12:32:58 bill 3 2
c trace()
e
s 00001/00001/00129
d D 3.2 80/06/07 02:46:53 bill 2 1
c %H%->%G%
e
s 00130/00000/00000
d D 3.1 80/04/09 16:03:52 bill 1 0
c date and time created 80/04/09 16:03:52 by bill
e
u
U
f b 
t
T
I 1
D 2
/*	%M%	%I%	%H%	*/
E 2
I 2
D 20
/*	%M%	%I%	%G%	*/
E 20
I 20
D 41
/*	%M%	%I%	%E%	*/
E 41
I 41
/*
D 48
 * Copyright (c) 1982 Regents of the University of California.
E 48
I 48
D 56
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 56
I 56
 * Copyright (c) 1982, 1986, 1988 Regents of the University of California.
E 56
E 48
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
I 50
D 53
#include "../machine/mtpr.h"
E 53
E 50
E 41
E 20
E 2

D 37
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/seg.h"
#include "../h/buf.h"
#include "../h/conf.h"
I 3
D 28
#include "../h/mtpr.h"
E 28
I 4
#include "../h/reboot.h"
I 9
#include "../h/vm.h"
#include "../h/msgbuf.h"
I 11
#include "../h/dir.h"
#include "../h/user.h"
I 31
#include "../h/proc.h"
E 31
#include "../h/tty.h"
E 37
I 37
#include "param.h"
#include "systm.h"
#include "seg.h"
#include "buf.h"
#include "conf.h"
#include "reboot.h"
#include "vm.h"
#include "msgbuf.h"
#include "dir.h"
#include "user.h"
#include "proc.h"
I 38
#include "ioctl.h"
E 38
#include "tty.h"
I 40
#include "syslog.h"
E 40
E 37
E 11
E 9
E 4
E 3

I 53
#include "../machine/mtpr.h"
D 59
#ifdef KDB
E 59
I 59
#ifdef KADB
E 59
#include "../machine/kdbparam.h"
#endif

E 53
I 34
D 50
#ifdef vax
#include "../vax/mtpr.h"
#endif

E 50
I 36
D 60
#define TOCONS	0x1
#define TOTTY	0x2
#define TOLOG	0x4
E 60
I 60
#define	TOCONS	0x1
#define	TOTTY	0x2
#define	TOLOG	0x4
#define	TOSTR	0x8
E 60

E 36
E 34
I 3
D 12
#ifdef TRACE
#define	TRCBUFS	4096
char	trcbuf[TRCBUFS];
char	*trcbufp = trcbuf;
int	trcwrap;
int	trcprt = TRCBUFS;
#endif

E 12
E 3
/*
 * In case console is off,
 * panicstr contains argument to last
 * call to panic.
 */
D 16

E 16
char	*panicstr;

I 51
extern	cnputc();			/* standard console putc */
extern	struct tty cons;		/* standard console tty */
struct	tty *constty;			/* pointer to console "window" tty */
int	(*v_putc)() = cnputc;		/* routine to putc on virtual console */

E 51
I 49
extern	cnputc();			/* standard console putc */
extern	struct tty cons;		/* standard console tty */
struct	tty *constty;			/* pointer to console "window" tty */
int	(*v_console)() = cnputc;	/* routine to putc on virtual console */

E 49
/*
 * Scaled down version of C Library printf.
D 16
 * Only %s %u %d (==%u) %o %x %D are recognized.
 * Used to print diagnostic information
 * directly on console tty.
 * Since it is not interrupt driven,
 * all system activities are pretty much
 * suspended.
 * Printf should not be used for chit-chat.
E 16
I 16
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
D 39
 *	reg=2<BITTWO,BITONE>
E 39
I 39
 *	reg=3<BITTWO,BITONE>
I 57
 *
 * Another additional format: %r is used to pass an additional format string
 * and argument list recursively.  Usage is typically:
 *
 * fn(otherstuff, fmt [, arg1, ... ] )
 *	char *fmt;
 *	u_int arg1, ...;
 *
 *	printf("prefix: %r, other stuff\n", fmt, &arg1);
E 57
E 39
E 16
 */
I 50
#if defined(tahoe)
int	consintr;
#endif

E 50
/*VARARGS1*/
printf(fmt, x1)
D 16
register char *fmt;
unsigned x1;
E 16
I 16
	char *fmt;
	unsigned x1;
E 16
{
I 50
#if defined(tahoe)
	register int savintr;
E 50
I 3

I 50
	savintr = consintr, consintr = 0;	/* disable interrupts */
#endif
E 50
D 36
	prf(fmt, &x1, 0);
E 36
I 36
	prf(fmt, &x1, TOCONS | TOLOG, (struct tty *)0);
	logwakeup();
I 50
#if defined(tahoe)
	consintr = savintr;			/* reenable interrupts */
#endif
E 50
E 36
}

D 12
#ifdef TRACE
trace(fmt, x1)
register char *fmt;
unsigned x1;
E 12
I 12
/*
D 16
 * print to the current users terminal,
 * guarantee not to sleep (so can be called by intr routine)
 * no watermark checking - so no verbose messages
E 16
I 16
D 39
 * Uprintf prints to the current user's terminal,
 * guarantees not to sleep (so can be called by interrupt routines)
E 39
I 39
D 44
 * Uprintf prints to the current user's terminal
E 39
 * and does no watermark checking - (so no verbose messages).
E 44
I 44
 * Uprintf prints to the current user's terminal.
 * It may block if the tty queue is overfull.
I 54
 * No message is printed if the queue does not clear
 * in a reasonable time.
E 54
 * Should determine whether current terminal user is related
 * to this process.
E 44
E 16
 */
/*VARARGS1*/
uprintf(fmt, x1)
D 16
	char	*fmt;
E 16
I 16
	char *fmt;
E 16
	unsigned x1;
E 12
{
I 45
#ifdef notdef
E 45
I 44
	register struct proc *p;
I 45
#endif
E 45
	register struct tty *tp;
E 44

D 12
	prf(fmt, &x1, 1);
E 12
I 12
D 36
	prf(fmt, &x1, 2);
E 36
I 36
D 44
	prf(fmt, &x1, TOTTY, u.u_ttyp);
E 44
I 44
	if ((tp = u.u_ttyp) == NULL)
		return;
#ifdef notdef
	if (tp->t_pgrp && (p = pfind(tp->t_pgrp)))
D 45
		if (p->p_uid != u.u_uid)
E 45
I 45
		if (p->p_uid != u.u_uid)	/* doesn't account for setuid */
E 45
			return;
#endif
D 54
	(void)ttycheckoutq(tp, 1);
	prf(fmt, &x1, TOTTY, tp);
E 54
I 54
	if (ttycheckoutq(tp, 1))
		prf(fmt, &x1, TOTTY, tp);
E 54
E 44
E 36
E 12
}

I 40
/*
 * tprintf prints on the specified terminal (console if none)
 * and logs the message.  It is designed for error messages from
D 44
 * single-open devices, and may be called from interrupt level.
E 44
I 44
 * single-open devices, and may be called from interrupt level
 * (does not sleep).
E 44
 */
E 40
D 12
#endif

prf(fmt, adx, trace)
E 12
I 12
D 16
/* THIS CODE IS VAX DEPENDENT */
E 16
D 36
prf(fmt, adx, touser)
E 36
I 36
/*VARARGS2*/
D 44
tprintf(ttyp, fmt, x1)
	struct tty *ttyp;
E 44
I 44
tprintf(tp, fmt, x1)
	register struct tty *tp;
E 44
	char *fmt;
	unsigned x1;
{
I 44
	int flags = TOTTY | TOLOG;
D 49
D 51
	extern struct tty cons;
E 51
E 49
E 44

D 40
	prf(fmt, &x1, TOTTY, ttyp);
E 40
I 40
D 44
	prf(fmt, &x1, TOTTY | TOLOG, ttyp);
E 44
I 44
	logpri(LOG_INFO);
D 49
	if (tp == (struct tty *)NULL)
		tp = &cons;
E 49
I 49
	if (tp == (struct tty *)NULL) {
		tp = constty;
		if (tp == (struct tty *)NULL)
			tp = &cons;
	}
E 49
	if (ttycheckoutq(tp, 0) == 0)
		flags = TOLOG;
	prf(fmt, &x1, flags, tp);
	logwakeup();
E 44
E 40
}

/*
 * Log writes to the log buffer,
D 39
 * guarantees not to sleep (so can be called by interrupt routines)
 * and does no watermark checking - (so no verbose messages).
E 39
I 39
 * and guarantees not to sleep (so can be called by interrupt routines).
I 40
 * If there is no process reading the log yet, it writes to the console also.
E 40
E 39
 */
/*VARARGS2*/
log(level, fmt, x1)
	char *fmt;
	unsigned x1;
{
	register s = splhigh();
I 40
	extern int log_open;
E 40

D 44
	putchar('<', TOLOG, (struct tty *)0);
	printn(level, 10, TOLOG, (struct tty *)0);
	putchar('>', TOLOG, (struct tty *)0);
E 44
I 44
	logpri(level);
E 44
	prf(fmt, &x1, TOLOG, (struct tty *)0);
	splx(s);
I 40
	if (!log_open)
		prf(fmt, &x1, TOCONS, (struct tty *)0);
E 40
	logwakeup();
}

I 44
logpri(level)
	int level;
{

	putchar('<', TOLOG, (struct tty *)0);
D 46
	printn(level, 10, TOLOG, (struct tty *)0);
E 46
I 46
	printn((u_long)level, 10, TOLOG, (struct tty *)0);
E 46
	putchar('>', TOLOG, (struct tty *)0);
}

I 55
/*VARARGS1*/
addlog(fmt, x1)
	char *fmt;
	unsigned x1;
{
	register s = splhigh();

	prf(fmt, &x1, TOLOG, (struct tty *)0);
	splx(s);
	if (!log_open)
		prf(fmt, &x1, TOCONS, (struct tty *)0);
	logwakeup();
}

I 60
/*
 * Basically standard sprintf.
 * NON-REENTRANT!
 */
static char *sprintf_ptr;
/*VARARGS2*/
sprintf(str, fmt, x1)
	char *str, *fmt;
	unsigned x1;
{
	sprintf_ptr = str;
	prf(fmt, &x1, TOSTR, (struct tty *)0);
	*sprintf_ptr = '\0';
}

E 60
E 55
E 44
prf(fmt, adx, flags, ttyp)
E 36
E 12
D 16
register char *fmt;
D 12
register unsigned int *adx;
E 12
I 12
register u_int *adx;
E 16
I 16
	register char *fmt;
	register u_int *adx;
I 36
	struct tty *ttyp;
E 36
E 16
E 12
{
E 3
D 12
	register c;
E 12
I 12
D 14
	register int b, c;
E 14
I 14
	register int b, c, i;
E 14
E 12
D 3
	register unsigned int *adx;
E 3
	char *s;
I 15
	int any;
E 15

D 3
	adx = &x1;
E 3
loop:
D 12
	while((c = *fmt++) != '%') {
E 12
I 12
	while ((c = *fmt++) != '%') {
E 12
D 36
		if(c == '\0')
E 36
I 36
		if (c == '\0')
E 36
			return;
D 3
		putchar(c);
E 3
I 3
D 12
		putchar(c, trace);
E 12
I 12
D 36
		putchar(c, touser);
E 36
I 36
		putchar(c, flags, ttyp);
E 36
E 12
E 3
	}
I 12
again:
E 12
	c = *fmt++;
I 16
D 50
	/* THIS CODE IS VAX DEPENDENT IN HANDLING %l? AND %c */
E 50
I 50
	/* THIS CODE IS MACHINE DEPENDENT IN HANDLING %l? AND %c */
E 50
E 16
D 3
	if(c == 'X')
		printx((long)*adx);
	else if(c == 'd' || c == 'u' || c == 'o' || c == 'x')
		printn((long)*adx, c=='o'? 8: (c=='x'? 16:10));
	else if(c == 's') {
E 3
I 3
D 12
	if (c == 'X')
		printx((long)*adx, trace);
	else if (c == 'd' || c == 'u' || c == 'o' || c == 'x')
		printn((long)*adx, c=='o'? 8: (c=='x'? 16:10), trace);
	else if (c == 's') {
E 12
I 12
	switch (c) {

	case 'l':
		goto again;
	case 'x': case 'X':
		b = 16;
		goto number;
	case 'd': case 'D':
D 50
	case 'u':		/* what a joke */
E 50
I 50
		b = -10;
		goto number;
	case 'u':
E 50
		b = 10;
		goto number;
	case 'o': case 'O':
		b = 8;
number:
D 19
		printn(*adx, b, touser);
E 19
I 19
D 36
		printn((u_long)*adx, b, touser);
E 36
I 36
		printn((u_long)*adx, b, flags, ttyp);
E 36
E 19
		break;
	case 'c':
D 14
		c = *adx;
		while (c) {
			putchar(c&0x7f, touser);
			c >>= 8;
		}
E 14
I 14
		b = *adx;
I 50
D 55
#if ENDIAN == LITTLE
E 55
I 55
#if BYTE_ORDER == LITTLE_ENDIAN
E 55
E 50
		for (i = 24; i >= 0; i -= 8)
			if (c = (b >> i) & 0x7f)
D 36
				putchar(c, touser);
E 36
I 36
				putchar(c, flags, ttyp);
I 50
#endif
D 55
#if ENDIAN == BIG
E 55
I 55
#if BYTE_ORDER == BIG_ENDIAN
E 55
		if (c = (b & 0x7f))
			putchar(c, flags, ttyp);
#endif
E 50
E 36
E 14
		break;
I 15
	case 'b':
		b = *adx++;
		s = (char *)*adx;
D 19
		printn(b, *s++, touser);
E 19
I 19
D 36
		printn((u_long)b, *s++, touser);
E 36
I 36
		printn((u_long)b, *s++, flags, ttyp);
E 36
E 19
		any = 0;
		if (b) {
D 36
			putchar('<', touser);
E 36
I 36
D 39
			putchar('<', flags, ttyp);
E 39
E 36
			while (i = *s++) {
				if (b & (1 << (i-1))) {
D 39
					if (any)
D 36
						putchar(',', touser);
E 36
I 36
						putchar(',', flags, ttyp);
E 39
I 39
D 50
					putchar(any? ',' : '<', flags, ttyp);
E 50
I 50
					putchar(any ? ',' : '<', flags, ttyp);
E 50
E 39
E 36
					any = 1;
					for (; (c = *s) > 32; s++)
D 36
						putchar(c, touser);
E 36
I 36
						putchar(c, flags, ttyp);
E 36
				} else
					for (; *s > 32; s++)
						;
			}
D 23
			putchar('>', touser);
E 23
I 23
			if (any)
D 36
				putchar('>', touser);
E 36
I 36
				putchar('>', flags, ttyp);
E 36
E 23
		}
		break;

E 15
	case 's':
E 12
E 3
		s = (char *)*adx;
D 3
		while(c = *s++)
			putchar(c);
E 3
I 3
		while (c = *s++)
D 12
#ifdef TRACE
D 11
			if (trace) {
E 11
I 11
			if (trace == 1) {
E 11
				*trcbufp++ = c;
				if (trcbufp >= &trcbuf[TRCBUFS]) {
					trcbufp = trcbuf;
					trcwrap = 1;
				}
			} else
#endif
				putchar(c, trace);
E 3
	} else if (c == 'D') {
D 3
		printn(*(long *)adx, 10);
E 3
I 3
		printn(*(long *)adx, 10, trace);
E 3
		adx += (sizeof(long) / sizeof(int)) - 1;
E 12
I 12
D 36
			putchar(c, touser);
E 36
I 36
			putchar(c, flags, ttyp);
E 36
		break;
I 22

I 55
	case 'r':
		s = (char *)*adx++;
D 57
		prf(s, *adx, flags, ttyp);
E 57
I 57
		prf(s, (u_int *)*adx, flags, ttyp);
E 57
		break;

E 55
	case '%':
D 36
		putchar('%', touser);
E 36
I 36
		putchar('%', flags, ttyp);
E 36
		break;
E 22
E 12
	}
	adx++;
	goto loop;
}
I 12
D 16
/* END VAX DEPENDENT CODE */
E 16
E 12

I 16
/*
 * Printn prints a number n in base b.
 * We don't use recursion to avoid deep kernel stacks.
 */
E 16
D 3
printx(x)
E 3
I 3
D 12
printx(x, trace)
E 3
long x;
E 12
I 12
D 36
printn(n, b, touser)
E 36
I 36
printn(n, b, flags, ttyp)
E 36
D 19
	unsigned long n;
E 19
I 19
	u_long n;
I 36
	struct tty *ttyp;
E 36
E 19
E 12
{
D 12
	int i;
E 12
I 12
D 14
	char buf[11];
E 14
I 14
	char prbuf[11];
E 14
	register char *cp;
E 12

D 12
	for (i = 0; i < 8; i++)
D 3
		putchar("0123456789ABCDEF"[(x>>((7-i)*4))&0xf]);
E 3
I 3
		putchar("0123456789ABCDEF"[(x>>((7-i)*4))&0xf], trace);
E 3
}

/*
D 10
 * Print an unsigned integer in base b.
E 10
I 10
 * Print an integer in base b.  If the base is ten it is condidered a
 * signed integer otherwise it is treated as unsigned.
E 10
 */
D 3
printn(n, b)
E 3
I 3
printn(n, b, trace)
E 3
D 10
long n;
E 10
I 10
unsigned long n;
E 10
{
D 10
	register long a;
E 10
I 10
	register unsigned long a;
	register long a1 = n;
E 10

D 10
	if (n<0) {	/* shouldn't happen */
E 10
I 10
	if (b == 10 && a1 < 0) {
E 10
D 3
		putchar('-');
E 3
I 3
		putchar('-', trace);
E 3
D 10
		n = -n;
E 10
I 10
		n = -a1;
E 12
I 12
D 50
	if (b == 10 && (int)n < 0) {
D 36
		putchar('-', touser);
E 36
I 36
		putchar('-', flags, ttyp);
E 36
		n = (unsigned)(-(int)n);
E 50
I 50
	if (b == -10) {
		if ((int)n < 0) {
			putchar('-', flags, ttyp);
			n = (unsigned)(-(int)n);
		}
		b = -b;
E 50
E 12
E 10
	}
D 12
	if(a = n/b)
D 3
		printn(a, b);
	putchar("0123456789ABCDEF"[(int)(n%b)]);
E 3
I 3
		printn(a, b, trace);
	putchar("0123456789ABCDEF"[(int)(n%b)], trace);
E 12
I 12
D 14
	cp = buf;
E 14
I 14
	cp = prbuf;
E 14
	do {
		*cp++ = "0123456789abcdef"[n%b];
		n /= b;
	} while (n);
	do
D 36
		putchar(*--cp, touser);
E 36
I 36
		putchar(*--cp, flags, ttyp);
E 36
D 14
	while (cp > buf);
E 14
I 14
	while (cp > prbuf);
E 14
E 12
E 3
}

/*
D 4
 * Panic is called on unresolvable
 * fatal errors.
 * It syncs, prints "panic: mesg" and
 * then loops.
E 4
I 4
 * Panic is called on unresolvable fatal errors.
D 16
 * It syncs, prints "panic: mesg", and then reboots.
E 16
I 16
 * It prints "panic: mesg", and then reboots.
 * If we are called twice, then we avoid trying to
 * sync the disks as this often leads to recursive panics.
E 16
E 4
 */
panic(s)
D 16
char *s;
E 16
I 16
	char *s;
E 16
{
I 29
D 30
#if sun
E 30
I 30
D 34
#ifdef sun
E 30
	register int *a5;
#endif
E 34
E 29
I 16
D 27
	int bootopt = panicstr ? RB_AUTOBOOT : RB_AUTOBOOT|RB_NOSYNC;
E 27
I 27
D 52
	int bootopt = RB_AUTOBOOT;
E 52
I 52
	int bootopt = RB_AUTOBOOT | RB_DUMP;
E 52
E 27
E 16
I 12

I 27
	if (panicstr)
		bootopt |= RB_NOSYNC;
I 29
D 30
#if sun
E 30
I 30
D 31
#ifdef sun
E 31
E 30
	else {
I 31
		panicstr = s;
D 34
#ifdef sun
E 31
		asm("movl a6, a5");
		traceback(a5, a5);
D 31
	}
E 31
I 31
D 32
		resume(pcbb(u.u_procp));	/* for adb traceback */
E 32
I 32
		/* make sure u area has been initialized before doing resume */
		if (u.u_procp >= proc && u.u_procp < procNPROC &&
		    u.u_procp->p_addr != 0)
			resume(pcbb(u.u_procp));	/* for adb traceback */
E 32
E 31
#endif
E 34
E 29
E 27
E 12
D 31
	panicstr = s;
E 31
I 31
	}
E 31
I 21
	printf("panic: %s\n", s);
I 53
D 59
#ifdef KDB
E 59
I 59
#ifdef KADB
E 59
	if (boothowto & RB_KDB) {
D 56
		int s = splnet();	/* below kdb pri */
E 56
I 56
		int x = splnet();	/* below kdb pri */
E 56

		setsoftkdb();
D 56
		splx(s);
E 56
I 56
		splx(x);
E 56
	}
#endif
E 53
E 21
D 5
	update();
E 5
D 19
	printf("panic: %s\n", s);
E 19
D 8
	spl0();
E 8
I 8
D 27
	(void) spl0();
E 27
E 8
D 16
	for(;;)
D 4
		;
E 4
I 4
D 5
		boot(RB_PANIC, RB_AUTOBOOT);		/* 0 = automatic */
E 5
I 5
		boot(RB_PANIC, RB_AUTOBOOT);
E 16
I 16
D 52
	boot(RB_PANIC, bootopt);
E 52
I 52
	boot(bootopt);
E 52
E 16
E 5
E 4
}

/*
I 18
 * Warn that a system table is full.
 */
tablefull(tab)
	char *tab;
{

D 40
	printf("%s: table is full\n", tab);
E 40
I 40
D 43
	log(KERN_FAIL, "%s: table is full\n", tab);
E 43
I 43
	log(LOG_ERR, "%s: table is full\n", tab);
E 43
E 40
}

I 33
D 34
#ifdef vax
E 34
E 33
/*
E 18
D 16
 * prdev prints a warning message of the
 * form "mesg on dev x/y".
 * x and y are the major and minor parts of
 * the device argument.
E 16
I 16
D 17
 * Prdev prints a warning message of the form "mesg on dev x/y".
 * x and y are the major and minor parts of the device argument.
 *
 * PRDEV SHOULD COMPUTE AND USE DEVICE NAMES
E 16
 */
prdev(str, dev)
D 12
char *str;
dev_t dev;
E 12
I 12
	char *str;
	dev_t dev;
E 12
{

D 12
	printf("%s on dev %u/%u\n", str, major(dev), minor(dev));
E 12
I 12
	printf("%s on dev %d/%d\n", str, major(dev), minor(dev));
E 12
}

I 16
/*
E 17
D 58
 * Hard error is the preface to plaintive error messages
D 18
 * about failing device transfers.
E 18
I 18
 * about failing disk transfers.
E 18
 */
E 16
D 15
/*
 * deverr prints a diagnostic from
 * a device driver.
 * It prints the device, block number,
 * and an octal word (usually some error
 * status register) passed as argument.
 */
deverror(bp, o1, o2)
D 12
register struct buf *bp;
E 12
I 12
	register struct buf *bp;
E 15
I 15
D 18
harderr(bp)
E 18
I 18
harderr(bp, cp)
E 18
	struct buf *bp;
I 18
	char *cp;
E 18
E 15
E 12
{

D 11
	prdev("err", bp->b_dev);
	printf("bn=%d er=%x,%x\n", bp->b_blkno, o1,o2);
E 11
I 11
D 15
	printf("bn=%d er=%x,%x", bp->b_blkno, o1,o2);
	prdev("", bp->b_dev);
E 15
I 15
D 16
	printf("hard err bn %d ", bp->b_blkno);
E 16
I 16
D 18
	printf("hard err bn%d ", bp->b_blkno);
E 18
I 18
	printf("%s%d%c: hard error sn%d ", cp,
D 42
	    dkunit(bp), 'a'+(minor(bp->b_dev)&07), bp->b_blkno);
E 42
I 42
	    minor(bp->b_dev) >> 3, 'a'+(minor(bp->b_dev)&07), bp->b_blkno);
E 42
E 18
E 16
E 15
E 11
I 3
}
I 33
D 34
#endif
E 34
E 33
I 16

E 16
D 15

E 15
D 12
#ifdef TRACE
dumptrc()
{
	register char *cp;
	register int pos, nch;

	nch = trcprt;
	if (nch < 0 || nch > TRCBUFS)
		nch = TRCBUFS;
	pos = (trcbufp - trcbuf) - nch;
	if (pos < 0)
		if (trcwrap)
			pos += TRCBUFS;
		else {
			nch += pos;
			pos = 0;
		}
	for (cp = &trcbuf[pos]; nch > 0; nch--) {
		putchar(*cp++, 0);
		if (cp >= &trcbuf[TRCBUFS])
			cp = trcbuf;
	}
}
#else
/*ARGSUSED*/
dumptrc(nch)
	int nch;
{

}
#endif

E 12
D 9
char	*msgbufp = msgbuf;	/* Next saved printf character */
E 9
/*
E 58
D 12
 * Print a character on console or in internal trace buffer.
E 12
I 12
 * Print a character on console or users terminal.
E 12
 * If destination is console then the last MSGBUFS characters
 * are saved in msgbuf for inspection later.
 */
I 7
/*ARGSUSED*/
E 7
D 12
putchar(c, trace)
register c;
E 12
I 12
D 36
putchar(c, touser)
E 36
I 36
D 39
putchar(c, flags, ttyp)
E 39
I 39
putchar(c, flags, tp)
E 39
E 36
	register int c;
I 36
D 39
	struct tty *ttyp;
E 39
I 39
	struct tty *tp;
E 39
E 36
E 12
{
I 51
D 55
	int startflags = flags;
E 55
I 55
	extern int msgbufmapped;
E 55
E 51
I 39
D 44
	extern struct tty cons;
E 44
E 39
D 7
	register s, timo;
E 7

I 51
	if (panicstr)
		constty = 0;
	if ((flags & TOCONS) && tp == 0 && constty) {
		tp = constty;
		flags |= TOTTY;
	}
E 51
I 49
	if ((flags & TOCONS) && panicstr == 0 && tp == 0 && constty) {
		tp = constty;
		flags |= TOTTY;
	}
E 49
I 11
D 12
	if (trace == 2) {
		register struct tty *tp;
		register s;
E 12
I 12
D 36
	if (touser) {
		register struct tty *tp = u.u_ttyp;
E 36
I 36
	if (flags & TOTTY) {
D 39
		register struct tty *tp = ttyp;
E 36
E 12

E 39
I 39
D 44
		if (tp == (struct tty *)NULL && (flags & TOCONS) == 0)
			tp = &cons;
E 39
D 12
		if ((tp = u.u_ttyp) && (tp->t_state&CARR_ON)) {
			s = spl7();
E 12
I 12
D 26
		if (tp && (tp->t_state&CARR_ON)) {
E 26
I 26
D 36
		if (tp && (tp->t_state&TS_CARR_ON)) {
E 36
I 36
		if (tp && (tp->t_state & TS_CARR_ON)) {
E 36
E 26
			register s = spl6();
E 44
I 44
		register s = spltty();

		if (tp && (tp->t_state & (TS_CARR_ON | TS_ISOPEN)) ==
		    (TS_CARR_ON | TS_ISOPEN)) {
E 44
			if (c == '\n')
D 25
				ttyoutput('\r', tp);
E 12
			ttyoutput(c, tp);
E 25
I 25
				(void) ttyoutput('\r', tp);
			(void) ttyoutput(c, tp);
E 25
			ttstart(tp);
D 44
			splx(s);
E 44
D 49
D 51
		}
E 51
I 51
		} else if ((flags & TOCONS) && tp == constty)
			constty = 0;
E 51
E 49
I 49
			flags &= ~TOCONS;
		} else if ((flags & TOCONS) && tp == constty)
			constty = 0;
E 49
I 44
		splx(s);
E 44
D 36
		return;
E 36
	}
I 29
D 30
#if vax
E 30
I 30
D 34
#ifdef vax
E 30
E 29
I 28
#include "../vax/mtpr.h"		/* XXX */
E 28
E 11
D 12
#ifdef TRACE
	if (trace) {
		*trcbufp++ = c;
		if (trcbufp >= &trcbuf[TRCBUFS]) {
			trcbufp = trcbuf;
			trcwrap = 1;
		}
		return;
	}
#endif
E 12
D 13
	if (c != '\0' && c != '\r' && c != 0177) {
E 13
I 13
D 29
	if (c != '\0' && c != '\r' && c != 0177 && mfpr(MAPEN)) {
E 29
I 29
#endif
E 34
D 36
	if (c != '\0' && c != '\r' && c != 0177
E 36
I 36
D 50
	if ((flags & TOLOG) && c != '\0' && c != '\r' && c != 0177
E 36
D 30
#if vax
E 30
I 30
#ifdef vax
E 30
	    && mfpr(MAPEN)
#endif
	    ) {
E 50
I 50
D 55
	/*
	 * Can send to log only after memory management enabled:
	 * this has happened by the time maxmem is set.
	 */
	if ((flags & TOLOG) && c != '\0' && c != '\r' && c != 0177 && maxmem) {
E 55
I 55
	if ((flags & TOLOG) && c != '\0' && c != '\r' && c != 0177 &&
	    msgbufmapped) {
E 55
E 50
E 29
E 13
D 9
		*msgbufp++ = c;
		if (msgbufp >= &msgbuf[MSGBUFS])
			msgbufp = msgbuf;
E 9
I 9
		if (msgbuf.msg_magic != MSG_MAGIC) {
I 32
			register int i;

E 32
D 36
			msgbuf.msg_bufx = 0;
E 36
			msgbuf.msg_magic = MSG_MAGIC;
I 36
			msgbuf.msg_bufx = msgbuf.msg_bufr = 0;
E 36
I 32
			for (i=0; i < MSG_BSIZE; i++)
				msgbuf.msg_bufc[i] = 0;
E 32
		}
I 47
		msgbuf.msg_bufc[msgbuf.msg_bufx++] = c;
E 47
		if (msgbuf.msg_bufx < 0 || msgbuf.msg_bufx >= MSG_BSIZE)
			msgbuf.msg_bufx = 0;
D 47
		msgbuf.msg_bufc[msgbuf.msg_bufx++] = c;
E 47
E 9
	}
D 36
	if (c == 0)
		return;
	cnputc(c);
E 36
I 36
D 51
	if ((flags & TOCONS) && c != '\0')
D 49
		cnputc(c);
E 51
I 51
	if ((flags & TOCONS) && constty == 0 && c != '\0')
		(*v_putc)(c);
I 60
	if (flags & TOSTR)
		*sprintf_ptr++ = c;
E 60
E 51
E 49
I 49
		(*v_console)(c);
E 49
E 36
I 11
D 12
}

/*
 * print to the current users terminal,
 * guarantee not to sleep (so can be called by intr routine)
 * no watermark checking - so no verbose messages
 */

/*VARARGS1*/
uprintf(fmt, x1)
char	*fmt;
unsigned x1;
{
	prf(fmt, &x1, 2);
E 12
E 11
E 3
}
E 1
