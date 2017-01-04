h56681
s 00001/00001/00048
d D 1.3 85/06/07 18:26:31 bloom 3 2
c fix sccsid and copyright for xstr
e
s 00009/00002/00040
d D 1.2 85/05/31 15:21:22 dist 2 1
c Add copyright
e
s 00042/00000/00000
d D 1.1 80/08/26 16:14:43 root 1 0
c date and time created 80/08/26 16:14:43 by root
e
u
U
t
T
I 1
D 2
/* Copyright (c) 1979 Regents of the University of California */
static char *sccsid = "%W% %G%";
E 2
I 2
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
D 3
static char sccsid[] = "%W% (Berkeley) %G%";
E 3
I 3
static char *sccsid = "%W% (Berkeley) %G%";
E 3
#endif not lint
E 2

/*
 * This version of printf calls doprnt, and as such is not portable,
 * since doprnt is written in pdp-11 assembly language.  (There is a
 * vax doprnt which has the first 2 arguments reversed.  We don't use it.)
 * This version is used because it is about 900 bytes smaller than the
 * portable version, which is also included in case it is needed.
 */
#ifdef TRACE
#include	<stdio.h>
#undef putchar
#endif

printf(fmt, args)
char *fmt;
{
	_doprnt(fmt, &args, 0);
}

_strout(string, count, adjust, file, fillch)
register char *string;
register count;
int adjust;
register struct _iobuf *file;
{
	while (adjust < 0) {
		if (*string=='-' && fillch=='0') {
			putchar(*string++);
			count--;
		}
		putchar(fillch);
		adjust++;
	}
	while (--count>=0)
		putchar(*string++);
	while (adjust) {
		putchar(fillch);
		adjust--;
	}
}
E 1
