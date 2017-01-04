h48526
s 00003/00003/00232
d D 7.6 03/04/13 15:19:04 msokolov 16 15
c 8-bit ex
e
s 00009/00009/00226
d D 7.5 87/03/09 12:46:31 conrad 15 14
c make ex/vi work on vms
e
s 00001/00001/00234
d D 7.4 85/06/07 18:20:20 bloom 14 13
c fix sccsid and copyright for xstr
e
s 00010/00002/00225
d D 7.3 85/05/31 13:56:26 dist 13 11
c Add copyright
e
s 00010/00002/00219
d D 5.1.1.1 85/05/31 12:05:31 dist 12 6
c Add copyright
e
s 00002/00000/00225
d D 7.2 83/06/27 13:29:47 sam 11 10
c don't allow hardtabs to be set to 0
e
s 00002/00002/00223
d D 7.1 81/07/08 22:30:45 mark 10 9
c release 3.7 - a few bug fixes and a few new features.
e
s 00001/00000/00224
d D 6.3 80/10/30 20:44:40 mark 9 8
c had to include ex_tty.h since it refers to LINES
e
s 00004/00001/00220
d D 6.2 80/10/30 20:40:57 mark 8 7
c fixed it to work on terminals with over 48 lines, and fixed bug 
c which allowed setting a huge window
e
s 00000/00000/00221
d D 6.1 80/10/19 01:21:18 mark 7 6
c preliminary release 3.6 10/18/80
e
s 00000/00000/00221
d D 5.1 80/08/20 16:11:09 mark 6 5
c Release 3.5, August 20, 1980
e
s 00002/00001/00219
d D 4.2 80/08/01 20:41:04 mark 5 4
c Bill added more buffers, and I put in sccs.
e
s 00002/00000/00218
d D 4.1 80/08/01 00:14:59 mark 4 3
c release 3.4, June 24, 1980
e
s 00023/00002/00195
d D 3.1 80/07/31 23:39:15 mark 3 2
c release 3.3, Feb 2, 1980
e
s 00000/00000/00197
d D 2.1 80/07/31 23:19:18 mark 2 1
c release 3.2, Jan 4, 1980
e
s 00197/00000/00000
d D 1.1 80/07/31 23:00:24 mark 1 0
c date and time created 80/07/31 23:00:24 by mark
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
D 10
D 12
/* Copyright (c) 1980 Regents of the University of California */
static char *sccsid = "%W% %G%";
E 12
I 12
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 12
E 10
I 10
D 13
/* Copyright (c) 1981 Regents of the University of California */
static char *sccsid = "%W%	%G%";
E 13
I 13
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
D 14
static char sccsid[] = "%W% (Berkeley) %G%";
E 14
I 14
static char *sccsid = "%W% (Berkeley) %G%";
E 14
#endif not lint

E 13
E 10
E 5
#include "ex.h"
#include "ex_temp.h"
I 9
#include "ex_tty.h"
E 9

/*
 * Set command.
 */
D 16
char	optname[ONMSZ];
E 16
I 16
u_char	optname[ONMSZ];
E 16

set()
{
D 16
	register char *cp;
E 16
I 16
	register u_char *cp;
E 16
	register struct option *op;
	register int c;
	bool no;
I 3
	extern short ospeed;
E 3

	setnoaddr();
	if (skipend()) {
		if (peekchar() != EOF)
			ignchar();
		propts();
		return;
	}
	do {
		cp = optname;
		do {
			if (cp < &optname[ONMSZ - 2])
D 15
				*cp++ = getchar();
E 15
I 15
				*cp++ = ex_getchar();
E 15
D 3
		} while (isalpha(peekchar()));
E 3
I 3
		} while (isalnum(peekchar()));
E 3
		*cp = 0;
		cp = optname;
		if (eq("all", cp)) {
			if (inopen)
				pofix();
			prall();
			goto next;
		}
		no = 0;
		if (cp[0] == 'n' && cp[1] == 'o') {
			cp += 2;
			no++;
		}
I 3
		/* Implement w300, w1200, and w9600 specially */
		if (eq(cp, "w300")) {
			if (ospeed >= B1200) {
dontset:
D 15
				ignore(getchar());	/* = */
E 15
I 15
				ignore(ex_getchar());	/* = */
E 15
				ignore(getnum());	/* value */
				continue;
			}
			cp = "window";
		} else if (eq(cp, "w1200")) {
			if (ospeed < B1200 || ospeed >= B2400)
				goto dontset;
			cp = "window";
		} else if (eq(cp, "w9600")) {
			if (ospeed < B2400)
				goto dontset;
			cp = "window";
		}
E 3
		for (op = options; op < &options[NOPTS]; op++)
			if (eq(op->oname, cp) || op->oabbrev && eq(op->oabbrev, cp))
				break;
		if (op->oname == 0)
			serror("%s: No such option@- 'set all' gives all option values", cp);
		c = skipwh();
		if (peekchar() == '?') {
			ignchar();
printone:
			propt(op);
			noonl();
			goto next;
		}
		if (op->otype == ONOFF) {
			op->ovalue = 1 - no;
I 4
			if (op == &options[PROMPT])
				oprompt = 1 - no;
E 4
			goto next;
		}
		if (no)
			serror("Option %s is not a toggle", op->oname);
		if (c != 0 || setend())
			goto printone;
D 15
		if (getchar() != '=')
E 15
I 15
		if (ex_getchar() != '=')
E 15
			serror("Missing =@in assignment to option %s", op->oname);
		switch (op->otype) {

		case NUMERIC:
			if (!isdigit(peekchar()))
D 3
error("Digits required@after = when assigning numeric option");
E 3
I 3
				error("Digits required@after =");
E 3
			op->ovalue = getnum();
			if (value(TABSTOP) <= 0)
				value(TABSTOP) = TABS;
I 11
			if (value(HARDTABS) <= 0)
				value(HARDTABS) = TABS;
E 11
I 3
D 8
			if (op == &options[WINDOW])
E 8
I 8
			if (op == &options[WINDOW]) {
				if (value(WINDOW) >= LINES)
					value(WINDOW) = LINES-1;
E 8
				vsetsiz(value(WINDOW));
I 8
			}
E 8
E 3
			break;

		case STRING:
		case OTERM:
			cp = optname;
			while (!setend()) {
				if (cp >= &optname[ONMSZ])
					error("String too long@in option assignment");
				/* adb change:  allow whitepace in strings */
D 15
				if( (*cp = getchar()) == '\\')
E 15
I 15
				if( (*cp = ex_getchar()) == '\\')
E 15
					if( peekchar() != EOF)
D 15
						*cp = getchar();
E 15
I 15
						*cp = ex_getchar();
E 15
				cp++;
			}
			*cp = 0;
			if (op->otype == OTERM) {
/*
 * At first glance it seems like we shouldn't care if the terminal type
 * is changed inside visual mode, as long as we assume the screen is
 * a mess and redraw it. However, it's a much harder problem than that.
 * If you happen to change from 1 crt to another that both have the same
 * size screen, it's OK. But if the screen size if different, the stuff
 * that gets initialized in vop() will be wrong. This could be overcome
 * by redoing the initialization, e.g. making the first 90% of vop into
 * a subroutine. However, the most useful case is where you forgot to do
 * a setenv before you went into the editor and it thinks you're on a dumb
 * terminal. Ex treats this like hardcopy and goes into HARDOPEN mode.
 * This loses because the first part of vop calls oop in this case.
 * The problem is so hard I gave up. I'm not saying it can't be done,
 * but I am saying it probably isn't worth the effort.
 */
				if (inopen)
error("Can't change type of terminal from within open/visual");
				setterm(optname);
			} else {
				CP(op->osvalue, optname);
				op->odefault = 1;
			}
			break;
		}
next:
		flush();
	} while (!skipend());
	eol();
}

setend()
{

	return (iswhite(peekchar()) || endcmd(peekchar()));
}

prall()
{
	register int incr = (NOPTS + 2) / 3;
	register int rows = incr;
	register struct option *op = options;

	for (; rows; rows--, op++) {
		propt(op);
		tab(24);
		propt(&op[incr]);
		if (&op[2*incr] < &options[NOPTS]) {
			tab(56);
			propt(&op[2 * incr]);
		}
		putNFL();
	}
}

propts()
{
	register struct option *op;

	for (op = options; op < &options[NOPTS]; op++) {
#ifdef V6
		if (op == &options[TERM])
#else
		if (op == &options[TTYTYPE])
#endif
			continue;
		switch (op->otype) {

		case ONOFF:
		case NUMERIC:
			if (op->ovalue == op->odefault)
				continue;
			break;

		case STRING:
			if (op->odefault == 0)
				continue;
			break;
		}
		propt(op);
D 15
		putchar(' ');
E 15
I 15
		ex_putchar(' ');
E 15
	}
	noonl();
	flush();
}

propt(op)
	register struct option *op;
{
D 16
	register char *name;
E 16
I 16
	register u_char *name;
E 16
	
	name = op->oname;

	switch (op->otype) {

	case ONOFF:
D 15
		printf("%s%s", op->ovalue ? "" : "no", name);
E 15
I 15
		ex_printf("%s%s", op->ovalue ? "" : "no", name);
E 15
		break;

	case NUMERIC:
D 15
		printf("%s=%d", name, op->ovalue);
E 15
I 15
		ex_printf("%s=%d", name, op->ovalue);
E 15
		break;

	case STRING:
	case OTERM:
D 15
		printf("%s=%s", name, op->osvalue);
E 15
I 15
		ex_printf("%s=%s", name, op->osvalue);
E 15
		break;
	}
}
E 1
