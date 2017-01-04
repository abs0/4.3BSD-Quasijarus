h17127
s 00006/00003/00214
d D 4.6 84/10/13 19:36:46 sam 6 5
c use definitions in <ptrace.h>
e
s 00003/00002/00214
d D 4.5 83/08/11 20:00:48 sam 5 4
c fix sccs keyword lines
e
s 00003/00001/00213
d D 4.4 82/04/01 06:36:22 root 4 3
c bug fixes to -w, output overflow, kernel debugging
e
s 00000/00006/00214
d D 4.3 81/05/15 02:04:53 root 3 2
c works, still with prings
e
s 00006/00000/00214
d D 4.2 81/05/14 20:08:57 root 2 1
c non-working version
e
s 00214/00000/00000
d D 4.1 81/05/14 15:19:41 root 1 0
c date and time created 81/05/14 15:19:41 by root
e
u
U
t
T
I 1
D 5
#
E 5
I 5
#ifndef lint
static	char sccsid[] = "%W% %G%";
#endif
E 5
/*
 *
 *	UNIX debugger
 *
 */

#include "defs.h"
D 5
static	char sccsid[] = "%Z%%M% %I% %G%";
E 5

MSG		BADEQ;
MSG		NOMATCH;
MSG		BADVAR;
MSG		BADCOM;

MAP		txtmap;
MAP		datmap;
INT		executing;
CHAR		*lp;
INT		fcor;
INT		fsym;
INT		mkfault;
STRING		errflg;

CHAR		lastc;
CHAR		eqformat[512] = "z";
CHAR		stformat[512] = "X\"= \"^i";

L_INT		dot;
L_INT		ditto;
INT		dotinc;
INT		lastcom = '=';
L_INT		var[];
L_INT		locval;
L_INT		locmsk;
INT		pid;
L_INT		expv;
L_INT		adrval;
INT		adrflg;
L_INT		cntval;
INT		cntflg;




/* command decoding */

command(buf,defcom)
STRING		buf;
CHAR		defcom;
{
	INT		itype, ptype, modifier, regptr;
	BOOL		longpr, eqcom;
	CHAR		wformat[1];
	CHAR		savc;
	L_INT		w, savdot;
	STRING		savlp=lp;
	IF buf
	THEN IF *buf==EOR
	     THEN return(FALSE);
	     ELSE lp=buf;
	     FI
	FI

	REP
	IF adrflg=expr(0)
	THEN dot=expv; ditto=dot;
	FI
	adrval=dot;
	IF rdc()==',' ANDF expr(0)
	THEN cntflg=TRUE; cntval=expv;
	ELSE cntflg=FALSE; cntval=1; lp--;
	FI

	IF !eol(rdc())
	THEN lastcom=lastc;
	ELSE IF adrflg==0 THEN dot=inkdot(dotinc); FI
	     lp--; lastcom=defcom;
	FI

	switch(lastcom&STRIP) {

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
		IF rdc()=='*' THEN lastcom |= QUOTE; ELSE lp--; FI
		IF lastcom&QUOTE
		THEN itype |= STAR; ptype = (DSYM+ISYM)-ptype;
		FI

	    trypr:
		longpr=FALSE; eqcom=lastcom=='=';
		switch (rdc()) {

			case 'm':
			    {/*reset map data*/
			    INT		fcount;
			    MAP		*smap;
			    UNION{MAP *m; L_INT *mp;}amap;

			    IF eqcom THEN error(BADEQ); FI
			    smap=(itype&DSP?&datmap:&txtmap);
			    amap.m=smap; fcount=3;
			    IF itype&STAR
			    THEN amap.mp += 3;
			    FI
			    WHILE fcount-- ANDF expr(0)
			    DO *(amap.mp)++ = expv; OD
			    IF rdc()=='?' THEN smap->ufd=fsym;
			    ELIF lastc == '/' THEN smap->ufd=fcor;
			    ELSE lp--;
			    FI
			    }
			    break;

			case 'L':
			    longpr=TRUE;
			case 'l':
			    /*search for exp*/
			    IF eqcom THEN error(BADEQ); FI
			    dotinc=(longpr?4:2); savdot=dot;
			    expr(1); locval=expv;
			    IF expr(0) THEN locmsk=expv; ELSE locmsk = -1L; FI
				IF !longpr THEN locmsk &= 0xFFFF; locval &= 0xFFFF; FI
			    LOOP w=get(dot,itype);
				 IF errflg ORF mkfault ORF (w&locmsk)==locval THEN break; FI
				 dot=inkdot(dotinc);
			    POOL
			    IF errflg
			    THEN dot=savdot; errflg=NOMATCH;
			    FI
			    psymoff(dot,ptype,"");
			    break;

			case 'W':
			    longpr=TRUE;
			case 'w':
			    IF eqcom THEN error(BADEQ); FI
			    wformat[0]=lastc; expr(1);
			    REP  savdot=dot; psymoff(dot,ptype,":%16t"); exform(1,wformat,itype,ptype);
				 errflg=0; dot=savdot;
				 IF longpr
				 THEN put(dot,itype,expv);
				 ELSE put(dot,itype,itol(get(dot+2,itype),expv));
				 FI
				 savdot=dot;
				 printf("=%8t"); exform(1,wformat,itype,ptype);
				 newline();
			    PER  expr(0) ANDF errflg==0 DONE
			    dot=savdot;
			    chkerr();
			    break;

			default:
			    lp--;
			    getformat(eqcom ? eqformat : stformat);
			    IF !eqcom
			    THEN psymoff(dot,ptype,":%16t");
			    FI
			    scanform(cntval,(eqcom?eqformat:stformat),itype,ptype);
		}
		break;

	    case '>':
		lastcom=0; savc=rdc();
		IF regptr=getreg(savc)
D 4
		THEN * (ADDR *) (((ADDR)&u)+regptr)=dot;
E 4
I 4
D 6
		THEN IF kcore THEN *(int *)regptr = dot; ELSE
		     * (ADDR *) (((ADDR)&u)+regptr)=dot;
E 4
		     ptrace(WUREGS,pid,regptr,* (ADDR *) (((ADDR)&u)+regptr));
E 6
I 6
		THEN IF kcore THEN
			*(int *)regptr = dot;
		     ELSE
		        *(ADDR *)(((ADDR)&u)+regptr) = dot;
		        ptrace(PT_WRITE_U, pid, regptr,
			     *(ADDR *)(((ADDR)&u)+regptr));
E 6
I 4
		     FI
E 4
		ELIF (modifier=varchk(savc)) != -1
		THEN	var[modifier]=dot;
I 2
D 3
			IF kcore && savc == 'p' THEN
				int pte = access(RD, dot, DSP, 0);
				printf("pte %X\n", pte);
				masterpcbb = (pte&PG_PFNUM)*512;
				getpcb();
			FI
E 3
E 2
		ELSE	error(BADVAR);
		FI
		break;

	    case '!':
		lastcom=0;
		shell(); break;

	    case '$':
		lastcom=0;
		printtrace(nextchar()); break;

	    case ':':
		IF !executing
		THEN executing=TRUE;
		     subpcs(nextchar());
		     executing=FALSE;
		     lastcom=0;
		FI
		break;

	    case 0:
		prints(DBNAME);
		break;

	    default: error(BADCOM);
	}

	flushbuf();
	PER rdc()==';' DONE
	IF buf THEN lp=savlp; ELSE lp--; FI
	return(adrflg ANDF dot!=0);
}

E 1
