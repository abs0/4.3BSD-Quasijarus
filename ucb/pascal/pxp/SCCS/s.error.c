h30748
s 00001/00001/00142
d D 5.2 87/12/04 19:04:03 bostic 7 6
c old assignment operator
e
s 00010/00002/00133
d D 5.1 85/06/05 15:46:20 dist 6 5
c Add copyright
e
s 00000/00000/00135
d D 2.1 84/02/08 20:22:57 aoki 5 4
c synchronizing at version 2
e
s 00001/00000/00134
d D 1.4 83/05/11 21:49:07 peter 4 3
c since input buffer is variable sized, people who include yy.h need whoami.h.
e
s 00001/00001/00133
d D 1.3 81/03/07 17:34:51 mckusic 3 2
c merge in onyx changes
e
s 00003/00001/00131
d D 1.2 81/03/05 20:15:07 peter 2 1
c error() is always supposed to set errpfx back to 'E'.
e
s 00132/00000/00000
d D 1.1 81/03/02 21:28:05 peter 1 0
c date and time created 81/03/02 21:28:05 by peter
e
u
U
t
T
I 1
D 6
static	char *sccsid = "%W% (Berkeley) %G%";
/* Copyright (c) 1979 Regents of the University of California */
E 6
I 6
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 6
/*
 * pi - Pascal interpreter code translator
 *
 * Charles Haley, Bill Joy UCB
 * Version 1.2 January 1979
 *
 *
 * pxp - Pascal execution profiler
 *
 * Bill Joy UCB
 * Version 1.2 January 1979
 */

I 4
#include "whoami.h"
E 4
#include "0.h"
#include "yy.h"

#ifdef PXP
extern	int yyline;
extern	char errout;
#endif

D 3
char	errpfx	'E';
E 3
I 3
char	errpfx	= 'E';
E 3
extern	int yyline;
/*
 * Panic is called when impossible
 * (supposedly, anyways) situations
 * are encountered.
#ifdef PI
 * Panic messages should be short
 * as they do not go to the message
 * file.
#endif
 */
panic(s)
	char *s;
{

#ifdef DEBUG
	fprintf(stderr, "Snark (%s) line=%d yyline=%d\n", s, line, yyline);
#endif
#ifdef PXP
	Perror( "Snark in pxp", s);
#endif
#ifdef PI
	Perror( "Snark in pi", s);
#endif
	pexit(DIED);
}

extern	char *errfile;
/*
 * Error is called for
 * semantic errors and
 * prints the error and
 * a line number.
 */
error(a1, a2, a3, a4)
{
#ifdef PI
	char buf[256];
	register int i;
#endif
#ifdef PXP
/*
	int ofout;
*/
#endif

D 2
	if (errpfx == 'w' && opt('w') != 0)
E 2
I 2
	if (errpfx == 'w' && opt('w') != 0) {
		errpfx == 'E';
E 2
		return;
I 2
	}
E 2
#ifdef PXP
/*
	flush();
	ofout = fout[0];
	fout[0] = errout;
*/
#endif
#ifdef PI
	Enocascade = 0;
	geterr(a1, buf);
	a1 = buf;
#endif
	if (line < 0)
		line = -line;
	yySsync();
	yysetfile(filename);
#ifdef PI
	if (errpfx == ' ') {
		printf("  ");
D 7
		for (i = line; i >= 10; i =/ 10)
E 7
I 7
		for (i = line; i >= 10; i /= 10)
E 7
			putchar(' ');
		printf("... ");
	} else if (Enoline)
		printf("  %c - ", errpfx);
	else
#endif
		fprintf(stderr, "%c %d - ", errpfx, line);
	fprintf(stderr, a1, a2, a3, a4);
	if (errpfx == 'E')
#ifdef PI
		eflg++, cgenflg++;
#endif
#ifdef PXP
		eflg++;
#endif
	errpfx = 'E';
#ifdef PI
	if (Eholdnl)
		Eholdnl = 0;
	else
#endif
		putc('\n', stderr);
#ifdef PXP
/*
	flush();
	fout[0] = ofout;
*/
#endif
}

#ifdef PI
cerror(a1, a2, a3, a4)
{

	if (Enocascade)
		return;
	setpfx(' ');
	error(a1, a2, a3, a4);
}
#endif
E 1
