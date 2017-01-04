h63651
s 00010/00003/00300
d D 5.1 85/06/05 15:52:49 dist 5 4
c Add copyright
e
s 00000/00000/00303
d D 2.1 84/02/08 20:23:31 aoki 4 3
c synchronizing at version 2
e
s 00000/00013/00303
d D 1.3 82/08/30 00:03:13 mckusick 3 2
c fixes for assert no longer being a keyword
e
s 00001/00001/00315
d D 1.2 81/03/07 17:35:50 mckusic 2 1
c merge in onyx changes
e
s 00316/00000/00000
d D 1.1 81/03/02 21:28:59 peter 1 0
c date and time created 81/03/02 21:28:59 by peter
e
u
U
t
T
I 1
D 5
static	char *sccsid = "%W% (Berkeley) %G%";
/* Copyright (c) 1979 Regents of the University of California */
#
E 5
I 5
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 5
/*
 * pxp - Pascal execution profiler
 *
 * Bill Joy UCB
 * Version 1.2 January 1979
 */

#include "0.h"
#include "tree.h"

int cntstat;
D 2
int cnts 3;
E 2
I 2
int cnts = 3;
E 2

statlist(r)
	int *r;
{
	register int *sl;

	sl = r;
	if (sl != NIL)
		for (;;) {
			statement(sl[1]);
			sl = sl[2];
			if (sl == NIL)
				break;
			ppsep(";");
		}
	else
		statement(NIL);
}


statement(r)
	int *r;
{
	register int *s;

	s = r;
top:
	if (cntstat) {
		cntstat = 0;
		getcnt();
	}
	if (s == NIL) {
		putcm();
		ppitem();
		ppid("null");
		return;
	}
	if (s[0] == T_REPEAT)
		setinfo(s[1]);
	else
		setline(s[1]);
	if (s[0] == T_LABEL) {
		cntstat = 1;
		ppnl();
		labeled(s[2]);
		statement(s[3]);
		return;
	}
	switch (s[0]) {
		default:
			panic("stat");
		case T_PCALL:
			ppitem();
			proc(s);
			break;
		case T_IF:
		case T_IFEL:
			ppnl();
			indent();
			ifop(s);
			break;
		case T_WHILE:
			ppnl();
			indent();
			whilop(s);
			break;
		case T_REPEAT:
			ppnl();
			indent();
			repop(s);
			break;
		case T_FORU:
		case T_FORD:
			ppnl();
			indent();
			forop(s);
			break;
		case T_BLOCK:
			ppnl();
			indent();
			ppstbl(s, DECL);
			break;
		case T_ASGN:
			ppitem();
			asgnop(s);
			break;
		case T_GOTO:
			ppitem();
			gotoop(s[2]);
			cntstat = 1;
			break;
		case T_CASE:
			ppnl();
			indent();
			caseop(s);
			break;
		case T_WITH:
			ppnl();
			indent();
			withop(s);
			break;
D 3
		case T_ASRT:
			ppitem();
			asrtop(s);
			break;
E 3
	}
	setinfo(s[1]);
	putcm();
}

withop(s)
	int *s;
{
	register *p;

	ppkw("with");
	ppspac();
	p = s[2];
	if (p != NIL)
		for (;;) {
			lvalue(p[1]);
			p = p[2];
			if (p == NIL)
				break;
			ppsep(", ");
		}
	else
		ppid("{record variable list}");
	ppstdo(s[3], DECL);
}

asgnop(r)
	int *r;
{

	lvalue(r[2]);
	ppsep(" := ");
	rvalue(r[3], NIL);
}

forop(r)
	int *r;
{
	struct pxcnt scnt;

	savecnt(&scnt);
	ppkw("for");
	ppspac();
	asgnop(r[2]);
	ppspac();
	ppkw(r[0] == T_FORU ? "to" : "downto");
	ppspac();
	rvalue(r[3], NIL);
	getcnt();
	ppstdo(r[4], STAT);
	if (rescnt(&scnt))
		getcnt();
}

ifop(r)
	int *r;
{
	register *s;
	struct pxcnt scnt;

	ppkw("if");
	ppspac();
	rvalue(r[2], NIL);
	ppspac();
	ppkw("then");
	ppspac();
	s = r[3];
	savecnt(&scnt);
	getcnt();
	if (s != NIL && s[0] == T_BLOCK)
		ppstbl1(s, STAT);
	else {
		ppgoin(STAT);
		statement(s);
		ppgoout(STAT);
	}
	if (r[0] == T_IFEL) {
		setcnt(cntof(&scnt)-nowcnt());
		if (s == NIL || s[0] != T_BLOCK) {
			ppnl();
			indent();
		} else {
			ppstbl2();
			ppspac();
		}
		s = r[4];
		ppkw("else");
		unprint();
		ppspac();
		if (s == NIL)
			goto burp;
		if (s[0] == T_BLOCK)
			ppstbl1(s, STAT);
		else if (s[0] == T_IF || s[0] == T_IFEL)
			ifop(s);
		else {
burp:
			ppgoin(STAT);
			statement(s);
			ppgoout(STAT);
		}
	}
	if (rescnt(&scnt))
		getcnt();
	if (r[4] != NIL)
		unprint();
	if (s != NIL && s[0] == T_BLOCK)
		ppstbl2();
}

whilop(r)
	int *r;
{
	struct pxcnt scnt;

	ppkw("while");
	ppspac();
	rvalue(r[2], NIL);
	savecnt(&scnt);
	getcnt();
	ppstdo(r[3], STAT);
	if (rescnt(&scnt))
		getcnt();
}

repop(r)
	int *r;
{
	struct pxcnt scnt;

	ppkw("repeat");
	ppgoin(STAT);
	savecnt(&scnt);
	getcnt();
	statlist(r[2]);
	ppgoout(DECL);
	ppnl();
	indent();
	ppkw("until");
	ppspac();
	rvalue(r[3], NIL);
	ppgoin(DECL);
	ppgoout(STAT);
	if (rescnt(&scnt))
		getcnt();
}

ppstbl(r, m)
int *r;
{
	ppstbl1(r, m);
	ppstbl2();
}

ppstbl1(r, m)
int *r;
{
	ppkw("begin");
	ppgoin(m);
	statlist(r[2]);
	ppgoout(m);
}

ppstbl2()
{
	ppnl();
	indent();
	ppkw("end");
}

ppstdo(r, l)
int *r;
{
	register *s;

	ppspac();
	ppkw("do");
	ppspac();
	s = r;
	if (s != NIL && s[0] == T_BLOCK)
		ppstbl(s, l);
	else {
		ppgoin(l);
		statement(s);
		ppgoout(l);
	}
D 3
}

asrtop(s)
	int *s;
{

	ppkw("assert");
	ppspac();
	rvalue(s[2], NIL);
E 3
}
E 1
