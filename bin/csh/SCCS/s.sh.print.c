h07277
s 00005/00017/00075
d D 5.4 88/06/06 11:47:08 bostic 10 9
c make cshputchar a macro
e
s 00002/00002/00090
d D 5.3 88/05/19 15:38:59 bostic 9 8
c install C version of _doprnt
e
s 00003/00003/00089
d D 5.2 85/06/06 13:08:17 edward 8 7
c cleaning up after bozos
e
s 00008/00002/00084
d D 5.1 85/06/04 11:06:34 dist 7 6
c Add copyright
e
s 00010/00029/00076
d D 4.6 84/12/13 14:38:49 edward 6 5
c performance
e
s 00001/00003/00104
d D 4.5 84/08/31 09:30:52 ralph 5 4
c use new signal calls instead of compatibility routines.
e
s 00002/00002/00105
d D 4.4 83/06/11 16:49:42 sam 4 3
c different approach, try signal compatibility package
e
s 00002/00002/00105
d D 4.3 83/06/10 23:59:27 sam 3 2
c new signals; no libjobs; still loses SIGINT by getting it masked 
c sometimes, but we check it in before we lose something
e
s 00000/00008/00107
d D 4.2 82/12/30 17:35:25 sam 2 1
c finally works (updated for 4.1c and merged with sun)
e
s 00115/00000/00000
d D 4.1 80/10/09 12:41:31 bill 1 0
c date and time created 80/10/09 12:41:31 by bill
e
u
U
t
T
I 7
/*
 * Copyright (c) 1980 Regents of the University of California.
D 8
 * All rights reserved.  The Berkeley software License Agreement
E 8
I 8
 * All rights reserved.  The Berkeley Software License Agreement
E 8
 * specifies the terms and conditions for redistribution.
 */

E 7
I 1
D 6
static	char *sccsid = "%Z%%M% %I% %G%";
E 6
I 6
#ifndef lint
D 7
static	char *sccsid = "%W% (Berkeley) %G%";
#endif
E 7
I 7
D 8
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 8
I 8
static char *sccsid = "%W% (Berkeley) %G%";
#endif
E 8
E 7
E 6

#include "sh.h"
I 6
#include <sys/ioctl.h>
E 6

/*
 * C Shell
 */

D 2
p60ths(l)
	long l;
{

	l += 3;
	printf("%d.%d", (int) (l / 60), (int) ((l % 60) / 6));
}

E 2
psecs(l)
	long l;
{
	register int i;

	i = l / 3600;
	if (i) {
		printf("%d:", i);
		i = l % 3600;
		p2dig(i / 60);
		goto minsec;
	}
	i = l;
	printf("%d", i / 60);
minsec:
	i %= 60;
	printf(":");
	p2dig(i);
}

p2dig(i)
	register int i;
{

	printf("%d%d", i / 10, i % 10);
}

D 10
char	linbuf[128];
char	*linp = linbuf;
E 10
I 10
char linbuf[LINELEN];
char *linp = linbuf;
E 10

D 9
putchar(c)
E 9
I 9
D 10
cshputchar(c)
E 9
	register int c;
E 10
I 10
cshputchar(ch)
	register int ch;
E 10
{
D 10

	if ((c & QUOTE) == 0 && (c == 0177 || c < ' ' && c != '\t' && c != '\n')) {
D 9
		putchar('^');
E 9
I 9
		cshputchar('^');
E 9
		if (c == 0177)
			c = '?';
		else
			c |= 'A' - 1;
	}
	c &= TRIM;
	*linp++ = c;
	if (c == '\n' || linp >= &linbuf[sizeof linbuf - 2])
		flush();
E 10
I 10
	CSHPUTCHAR;
E 10
}

draino()
{
D 10

E 10
	linp = linbuf;
}

flush()
{
	register int unit;
D 6
	int lmode = 0;
E 6
I 6
	int lmode;
E 6

D 6
#include <sys/ioctl.h>

E 6
	if (linp == linbuf)
		return;
	if (haderr)
		unit = didfds ? 2 : SHDIAG;
	else
		unit = didfds ? 1 : SHOUT;
#ifdef TIOCLGET
D 6
	if (didfds==0 && ioctl(unit, TIOCLGET, &lmode)==0 &&
	    lmode & LFLUSHO) {
E 6
I 6
	if (didfds == 0 && ioctl(unit, TIOCLGET, (char *)&lmode) == 0 &&
	    lmode&LFLUSHO) {
E 6
		lmode = LFLUSHO;
D 6
		ioctl(unit, TIOCLBIC, &lmode);
		write(unit, "\n", 1);
E 6
I 6
		(void) ioctl(unit, TIOCLBIC, (char *)&lmode);
		(void) write(unit, "\n", 1);
E 6
	}
#endif
D 6
	write(unit, linbuf, linp - linbuf);
E 6
I 6
	(void) write(unit, linbuf, linp - linbuf);
E 6
	linp = linbuf;
D 6
}

plist(vp)
	register struct varent *vp;
{

	if (setintr)
D 3
		sigrelse(SIGINT);
E 3
I 3
D 4
		(void) sigrelse(mask(SIGINT));
E 4
I 4
D 5
		sigrelse(SIGINT);
E 5
I 5
		sigsetmask(sigblock(0) & ~ sigmask(SIGINT));
E 5
E 4
E 3
	for (vp = vp->link; vp != 0; vp = vp->link) {
		int len = blklen(vp->vec);

		printf(vp->name);
		printf("\t");
		if (len != 1)
			putchar('(');
		blkpr(vp->vec);
		if (len != 1)
			putchar(')');
		printf("\n");
	}
E 6
D 5
	if (setintr)
D 3
		sigrelse(SIGINT);
E 3
I 3
D 4
		(void) sigrelse(mask(SIGINT));
E 4
I 4
		sigrelse(SIGINT);
E 5
E 4
E 3
}
E 1
