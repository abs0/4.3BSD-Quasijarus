h24164
s 00003/00003/00389
d D 5.3 87/10/16 11:52:09 donn 6 5
c Get rid of even more old-fashioned assignment operators.
e
s 00003/00003/00389
d D 5.2 87/03/17 20:23:39 lepreau 5 4
c get rid of old-style asgop syntax
e
s 00010/00003/00382
d D 5.1 85/06/05 15:49:24 dist 4 3
c Add copyright
e
s 00000/00000/00385
d D 2.1 84/02/08 20:22:33 aoki 3 2
c synchronizing at version 2
e
s 00001/00001/00384
d D 1.2 83/02/05 12:07:42 mckusick 2 1
c use more intelligent printf format
e
s 00385/00000/00000
d D 1.1 81/03/02 21:28:46 peter 1 0
c date and time created 81/03/02 21:28:46 by peter
e
u
U
t
T
I 1
D 4
static	char *sccsid = "%W% (Berkeley) %G%";
/* Copyright (c) 1979 Regents of the University of California */
#
E 4
I 4
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 4
/*
 * pxp - Pascal execution profiler
 *
 * Bill Joy UCB
 * Version 1.2 January 1979
 */

#include "0.h"

#define noprint() nopflg

int	pplev[3];	/* STAT, DECL, PRFN */
int	nopflg;

setprint()
{

	if (profile == 0) {
		if (table)
			nopflg = 1;
		else
			nopflg = 0;
		return;
	}
	nopflg = !all && nowcnt() == 0 || !opt('z');
}

printon()
{

	if (profile == 0) {
		if (table)
			nopflg = 1;
		return;
	}
	nopflg = 0;
}

printoff()
{

	nopflg = 1;
}

ppkw(s)
	register char *s;
{
	register char *cp, i;

	if (noprint())
		return;
	/*
	 * First real thing printed
	 * is always a keyword
	 * or includes an "id" (if a comment)
	 * (See ppnl below)
	 */
	hadsome = 1;
	if (underline) {
		for (cp = s; *cp; cp++)
			putchar('_');
		for (cp = s; *cp; cp++)
			putchar('\b');
	}
	printf(s);
}

ppid(s)
	register char *s;
{

	if (noprint())
		return;
	hadsome = 1;
	if (s == NIL)
		s = "{identifier}";
	printf(s);
}

ppbra(s)
	char *s;
{

	if (noprint())
		return;
	if (s != NIL)
		printf(s);
}

ppsep(s)
	char *s;
{

	if (noprint())
		return;
	printf(s);
}

ppket(s)
	char *s;
{

	if (noprint())
		return;
	if (s != NIL)
		printf(s);
}

char	killsp;

ppunspac()
{

	killsp = 1;
}

ppspac()
{

	if (killsp) {
		killsp = 0;
		return;
	}
	if (noprint())
		return;
	putchar(' ');
}

ppitem()
{

	if (noprint())
		return;
	ppnl();
	indent();
}

int	owenl, owenlb;

ppsnlb()
{

	if (nopflg)
		return;
	owenlb++;
}

ppsnl()
{

	if (nopflg)
		return;
	owenl++;
}

pppay()
{

	while (owenl || owenlb) {
		putchar('\n');
		if (owenlb) {
			putchar(' ');
			owenlb--;
		} else
			owenl--;
	}
}

ppnl()
{

	if (noprint())
		return;
	if (hadsome == 0)
		return;
	pppay();
	putchar('\n');
}

indent()
{
	register i;

	if (noprint())
		return;
	linopr();
	if (profile == 0) {
		indent1(pplev[PRFN] + pplev[DECL] + pplev[STAT]);
		return;
	}
	indent1(pplev[PRFN] + pplev[STAT]);
	switch (i = shudpcnt()) {
		case 1:
D 2
			printf("%7.7ld.", nowcnt());
E 2
I 2
			printf("%7ld.", nowcnt());
E 2
			dashes('-');
			putchar('|');
			break;
		case 0:
		case -1:
			printf("        ");
			dashes(' ');
			putchar(i == 0 ? '|' : ' ');
			break;
	}
	indent1(pplev[DECL]);
}

dashes(c)
	char c;
{
	register i;

	for (i = unit - 1; i != 0; i--)
		putchar(c);
}

indent1(in)
	int in;
{
	register i;

	if (noprint())
		return;
	i = in;
	if (profile == 0)
		while (i >= 8) {
			putchar('\t');
D 6
			i =- 8;
E 6
I 6
			i -= 8;
E 6
		}
	while (i > 0) {
		putchar(' ');
		i--;
	}
}

linopr()
{

	if (noprint())
		return;
	if (profile) {
		if (line < 0)
			line = -line;
		printf("%6d  ", line);
	}
}

indentlab()
{

	indent1(pplev[PRFN]);
}

ppop(s)
	char *s;
{

	if (noprint())
		return;
	printf(s);
}

ppnumb(s)
	char *s;
{

	if (noprint())
		return;
	if (s == NIL)
		s = "{number}";
	printf(s);
}

ppgoin(lv)
{

D 5
	pplev[lv] =+ unit;
E 5
I 5
	pplev[lv] += unit;
E 5
}

ppgoout(lv)
{

D 6
	pplev[lv] =- unit;
E 6
I 6
	pplev[lv] -= unit;
E 6
	if (pplev[lv] < 0)
		panic("pplev");
}

ppstr(s)
	char *s;
{
	register char *cp;

	if (noprint())
		return;
	if (s == NIL) {
		printf("{string}");
		return;
	}
	putchar('\'');
	cp = s;
	while (*cp) {
		putchar(*cp);
		if (*cp == '\'')
			putchar('\'');
		cp++;
	}
	putchar('\'');
}

pplab(s)
	char *s;
{

	if (noprint())
		return;
	if (s == NIL)
		s = "{integer label}";
	printf(s);
}

int	outcol;


putchar(c)
	char c;
{

	putc(c, stdout);
	if (ferror(stdout))
		outerr();
	switch (c) {
		case '\n':
			outcol = 0;
			flush();
			break;
		case '\t':
D 5
			outcol =+ 8;
			outcol =& ~07;
E 5
I 5
			outcol += 8;
			outcol &= ~07;
E 5
			break;
		case '\b':
			if (outcol)
				outcol--;
			break;
		default:
			outcol++;
		case '\f':
			break;
	}
}

flush()
{

	fflush(stdout);
	if (ferror(stdout))
		outerr();
}

pptab()
{
	register int i;

	if (noprint())
		return;
	i = pplev[PRFN] + profile ? 44 + unit : 28;
/*
	if (outcol > i + 8) {
		ppnl();
D 6
		i =+ 8;
E 6
I 6
		i += 8;
E 6
	}
*/
	do
		putchar('\t');
	while (outcol < i);
}

outerr()
{

	perror(stdoutn);
	pexit(DIED);
}
E 1
