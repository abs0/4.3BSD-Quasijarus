h27800
s 00011/00005/00180
d D 7.3 86/12/15 20:26:44 sam 3 2
c lint
e
s 00013/00015/00172
d D 7.2 86/11/20 14:43:02 sam 2 1
c miscellaneous cleanups; don't print debugger name on blank line
e
s 00187/00000/00000
d D 7.1 86/11/20 12:22:01 sam 1 0
c date and time created 86/11/20 12:22:01 by sam
e
u
U
t
T
I 1
D 3
/*	%M%	%I%	%E%	*/
E 3
I 3
/*
 * Copyright (c) 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 3

#include "../kdb/defs.h"

char	*BADEQ;
char	*NOMATCH;
char	*BADVAR;
char	*BADCOM;

int	executing;
char	*lp;

char	lastc;
char	eqformat[512] = "z";
char	stformat[512] = "X\"= \"^i";

long	ditto;
int	lastcom = '=';
long	locval;
long	locmsk;
long	expv;

/* command decoding */

command(buf, defcom)
	char *buf, defcom;
{
	register itype, ptype, modifier, regptr;
	int longpr, eqcom;
	char wformat[1], savc;
	register long w, savdot;
	char *savlp=lp;

	if (buf) {
		if (*buf==EOR)
D 2
			return (FALSE);
E 2
I 2
			return (0);
E 2
		lp=buf;
	}

	do {
		if (adrflg=expr(0)) {
			dot=expv;
			ditto=dot;
		}
		adrval=dot;
D 2
		if (rdc()==',' && expr(0))
			cntflg=TRUE, cntval=expv;
E 2
I 2
		cntflg = (rdc() == ',' && expr(0));
		if (cntflg)
			cntval=expv;
E 2
		else
D 2
			cntflg=FALSE, cntval=1, lp--;
E 2
I 2
			cntval=1, lp--;
E 2
		if (eol(rdc())) {
			if (!adrflg)
				dot=inkdot(dotinc);
			lp--; lastcom=defcom;
		} else
			lastcom=lastc;
		switch (lastcom&STRIP) {

		case '/':
			itype=DSP; ptype=DSYM;
			goto trystar;

		case '=':
			itype=NSP; ptype=0;
			goto trypr;

		case '?':
			itype=ISP; ptype=ISYM;
			goto trystar;

		trystar:
			if (rdc()=='*')
				lastcom |= QUOTE;
			else
				lp--;
			if (lastcom&QUOTE) {
				itype |= STAR;
				ptype = (DSYM+ISYM)-ptype;
			}

		trypr:
D 2
			longpr=FALSE; eqcom=lastcom=='=';
E 2
I 2
			longpr=0; eqcom=lastcom=='=';
E 2
			switch (rdc()) {

			case 'L':
D 2
				longpr=TRUE;
E 2
I 2
				longpr=1;
E 2
			case 'l':
				/*search for exp*/
				if (eqcom)
					error(BADEQ);
				dotinc=(longpr?4:2); savdot=dot;
D 3
				expr(1); locval=expv;
E 3
I 3
				(void) expr(1); locval=expv;
E 3
				if (expr(0))
					locmsk=expv;
				else
					locmsk = -1L;
				if (!longpr) {
					locmsk &= 0xFFFF;
					locval &= 0xFFFF;
				}
				for (;;) {
					w=get(dot,itype);
					if (errflg || mkfault ||
					    (w&locmsk)==locval)
						break;
					 dot=inkdot(dotinc);
				}
				if (errflg) {
					dot=savdot;
					errflg=NOMATCH;
				}
				psymoff(dot,ptype,"");
				break;

			case 'W':
D 2
				longpr=TRUE;
E 2
I 2
				longpr=1;
E 2
			case 'w':
				if (eqcom)
					error(BADEQ);
D 3
				wformat[0]=lastc; expr(1);
E 3
I 3
				wformat[0]=lastc; (void) expr(1);
E 3
				do {
					savdot=dot;
					psymoff(dot,ptype,":%16t");
D 3
					exform(1,wformat,itype,ptype);
E 3
I 3
					(void) exform(1,wformat,itype,ptype);
E 3
					errflg=0; dot=savdot;
					if (longpr)
						put(dot,itype,expv);
					else
						put(dot,itype,
						    itol(expv,get(dot,itype)));
					savdot=dot;
					printf("=%8t");
D 3
					exform(1,wformat,itype,ptype);
E 3
I 3
					(void) exform(1,wformat,itype,ptype);
E 3
					printc(EOR);
				} while (expr(0) && errflg==0);
				dot=savdot;
				chkerr();
				break;

			default:
				lp--;
				getformat(eqcom ? eqformat : stformat);
				if (!eqcom)
					psymoff(dot,ptype,":%16t");
				scanform(cntval,
				    (eqcom?eqformat:stformat),itype,ptype);
			}
			break;

		case '>':
			lastcom=0; savc=rdc();
			if ((regptr=getreg(savc)) != -1)
				*(int *)regptr = dot;
			else if ((modifier=varchk(savc)) != -1)
				var[modifier]=dot;
			else
				error(BADVAR);
			break;

		case '$':
			lastcom=0;
			printtrace(nextchar());
			break;

		case ':':
D 2
			if (!executing) {
				executing=TRUE;
				subpcs(nextchar());
				executing=FALSE;
				lastcom=0;
			}
E 2
I 2
			if (executing)
				break;
			executing=1; subpcs(nextchar()); executing=0;
			lastcom=0;
E 2
			break;

D 2
		case 0:
			printf(DBNAME);
E 2
I 2
		case '\0':
E 2
			break;

		default:
			error(BADCOM);
		}
		flushbuf();
	} while (rdc()==';');
	if (buf)
		lp=savlp;
	else
		lp--;
	return (adrflg && dot!=0);
}
E 1
