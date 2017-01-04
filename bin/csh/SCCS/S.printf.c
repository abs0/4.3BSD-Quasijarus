h39858
s 00003/00003/00041
d D 5.2 85/06/06 13:09:39 edward 4 3
c cleaning up after bozos
e
s 00008/00002/00036
d D 5.1 85/06/04 10:54:09 dist 3 2
c Add copyright
e
s 00003/00001/00035
d D 4.2 84/12/13 14:39:55 edward 2 1
c performance
e
s 00036/00000/00000
d D 4.1 80/10/09 12:40:19 bill 1 0
c date and time created 80/10/09 12:40:19 by bill
e
u
U
t
T
I 3
/*
 * Copyright (c) 1980 Regents of the University of California.
D 4
 * All rights reserved.  The Berkeley software License Agreement
E 4
I 4
 * All rights reserved.  The Berkeley Software License Agreement
E 4
 * specifies the terms and conditions for redistribution.
 */

E 3
I 1
D 2
static	char *sccsid = "%Z%%M% %I% %G%";
E 2
I 2
#ifndef lint
D 3
static	char *sccsid = "%W% (Berkeley) %G%";
#endif
E 3
I 3
D 4
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 4
I 4
static char *sccsid = "%W% (Berkeley) %G%";
#endif
E 4
E 3
E 2

/*
 * Hacked "printf" which prints through putchar.
 * DONT USE WITH STDIO!
 */
printf(fmt, args)
char *fmt;
{
	_doprnt(fmt, &args, 0);
}

_strout(count, string, adjust, foo, fillch)
register char *string;
register int count;
int adjust;
register struct { int a[6]; } *foo;
{

	if (foo != 0)
		abort();
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
