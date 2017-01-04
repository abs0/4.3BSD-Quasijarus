h13414
s 00026/00023/00387
d D 4.3 88/04/24 15:08:30 bostic 3 2
c fixes for ANSI C
e
s 00003/00001/00407
d D 4.2 83/08/11 20:18:48 sam 2 1
c standardize sccs keyword lines
e
s 00408/00000/00000
d D 4.1 82/05/07 19:36:45 mckusick 1 0
c date and time created 82/05/07 19:36:45 by mckusick
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%E%	*/
E 2
I 2
#ifndef lint
static char sccsid[] = "%W% %G%";
#endif
E 2

#
/*
 * UNIX shell
 *
 * S. R. Bourne
 * Bell Telephone Laboratories
 *
 */

#include	"defs.h"
#include	"sym.h"

PROC IOPTR	inout();
PROC VOID	chkword();
PROC VOID	chksym();
PROC TREPTR	term();
PROC TREPTR	makelist();
PROC TREPTR	list();
PROC REGPTR	syncase();
PROC TREPTR	item();
PROC VOID	skipnl();
PROC VOID	prsym();
PROC VOID	synbad();


/* ========	command line decoding	========*/




TREPTR	makefork(flgs, i)
	INT		flgs;
	TREPTR		i;
{
	REG TREPTR	t;

	t=getstak(FORKTYPE);
D 3
	t->forktyp=flgs|TFORK; t->forktre=i; t->forkio=0;
E 3
I 3
	t->forknod.forktyp=flgs|TFORK;
	t->forknod.forktre=i;
	t->forknod.forkio=0;
E 3
	return(t);
}

LOCAL TREPTR	makelist(type,i,r)
	INT		type;
	TREPTR		i, r;
{
	REG TREPTR	t;

	IF i==0 ORF r==0
	THEN	synbad();
	ELSE	t = getstak(LSTTYPE);
D 3
		t->lsttyp = type;
		t->lstlef = i; t->lstrit = r;
E 3
I 3
		t->lstnod.lsttyp = type;
		t->lstnod.lstlef = i;
		t->lstnod.lstrit = r;
E 3
	FI
	return(t);
}

/*
 * cmd
 *	empty
 *	list
 *	list & [ cmd ]
 *	list [ ; cmd ]
 */

TREPTR	cmd(sym,flg)
	REG INT		sym;
	INT		flg;
{
	REG TREPTR	i, e;

	i = list(flg);

	IF wdval==NL
	THEN	IF flg&NLFLG
		THEN	wdval=';'; chkpr(NL);
		FI
	ELIF i==0 ANDF (flg&MTFLG)==0
	THEN	synbad();
	FI

	SWITCH wdval IN

	    case '&':
		IF i
		THEN	i = makefork(FINT|FPRS|FAMP, i);
		ELSE	synbad();
		FI

	    case ';':
		IF e=cmd(sym,flg|MTFLG)
		THEN	i=makelist(TLST, i, e);
		FI
		break;

	    case EOFSYM:
		IF sym==NL
		THEN	break;
		FI

	    default:
		IF sym
		THEN	chksym(sym);
		FI

	ENDSW
	return(i);
}

/*
 * list
 *	term
 *	list && term
 *	list || term
 */

LOCAL TREPTR	list(flg)
{
	REG TREPTR	r;
	REG INT		b;

	r = term(flg);
	WHILE r ANDF ((b=(wdval==ANDFSYM)) ORF wdval==ORFSYM)
	DO	r = makelist((b ? TAND : TORF), r, term(NLFLG));
	OD
	return(r);
}

/*
 * term
 *	item
 *	item |^ term
 */

LOCAL TREPTR	term(flg)
{
	REG TREPTR	t;

	reserv++;
	IF flg&NLFLG
	THEN	skipnl();
	ELSE	word();
	FI

	IF (t=item(TRUE)) ANDF (wdval=='^' ORF wdval=='|')
	THEN	return(makelist(TFIL, makefork(FPOU,t), makefork(FPIN|FPCL,term(NLFLG))));
	ELSE	return(t);
	FI
}

LOCAL REGPTR	syncase(esym)
	REG INT	esym;
{
	skipnl();
	IF wdval==esym
	THEN	return(0);
	ELSE	REG REGPTR	r=getstak(REGTYPE);
		r->regptr=0;
		LOOP wdarg->argnxt=r->regptr;
		     r->regptr=wdarg;
		     IF wdval ORF ( word()!=')' ANDF wdval!='|' )
		     THEN synbad();
		     FI
		     IF wdval=='|'
		     THEN word();
		     ELSE break;
		     FI
		POOL
		r->regcom=cmd(0,NLFLG|MTFLG);
		IF wdval==ECSYM
		THEN	r->regnxt=syncase(esym);
		ELSE	chksym(esym);
			r->regnxt=0;
		FI
		return(r);
	FI
}

/*
 * item
 *
 *	( cmd ) [ < in  ] [ > out ]
 *	word word* [ < in ] [ > out ]
 *	if ... then ... else ... fi
 *	for ... while ... do ... done
 *	case ... in ... esac
 *	begin ... end
 */

LOCAL TREPTR	item(flag)
	BOOL		flag;
{
	REG TREPTR	t;
	REG IOPTR	io;

	IF flag
	THEN	io=inout((IOPTR)0);
	ELSE	io=0;
	FI

	SWITCH wdval IN

	    case CASYM:
		BEGIN
		   t=getstak(SWTYPE);
		   chkword();
D 3
		   t->swarg=wdarg->argval;
E 3
I 3
		   t->swnod.swarg=wdarg->argval;
E 3
		   skipnl(); chksym(INSYM|BRSYM);
D 3
		   t->swlst=syncase(wdval==INSYM?ESSYM:KTSYM);
		   t->swtyp=TSW;
E 3
I 3
		   t->swnod.swlst=syncase(wdval==INSYM?ESSYM:KTSYM);
		   t->swnod.swtyp=TSW;
E 3
		   break;
		END

	    case IFSYM:
		BEGIN
		   REG INT	w;
		   t=getstak(IFTYPE);
D 3
		   t->iftyp=TIF;
		   t->iftre=cmd(THSYM,NLFLG);
		   t->thtre=cmd(ELSYM|FISYM|EFSYM,NLFLG);
		   t->eltre=((w=wdval)==ELSYM ? cmd(FISYM,NLFLG) : (w==EFSYM ? (wdval=IFSYM, item(0)) : 0));
E 3
I 3
		   t->ifnod.iftyp=TIF;
		   t->ifnod.iftre=cmd(THSYM,NLFLG);
		   t->ifnod.thtre=cmd(ELSYM|FISYM|EFSYM,NLFLG);
		   t->ifnod.eltre=((w=wdval)==ELSYM ? cmd(FISYM,NLFLG) : (w==EFSYM ? (wdval=IFSYM, item(0)) : 0));
E 3
		   IF w==EFSYM THEN return(t) FI
		   break;
		END

	    case FORSYM:
		BEGIN
		   t=getstak(FORTYPE);
D 3
		   t->fortyp=TFOR;
		   t->forlst=0;
E 3
I 3
		   t->fornod.fortyp=TFOR;
		   t->fornod.forlst=0;
E 3
		   chkword();
D 3
		   t->fornam=wdarg->argval;
E 3
I 3
		   t->fornod.fornam=wdarg->argval;
E 3
		   IF skipnl()==INSYM
		   THEN	chkword();
D 3
			t->forlst=item(0);
E 3
I 3
			t->fornod.forlst=item(0);
E 3
			IF wdval!=NL ANDF wdval!=';'
			THEN	synbad();
			FI
			chkpr(wdval); skipnl();
		   FI
		   chksym(DOSYM|BRSYM);
D 3
		   t->fortre=cmd(wdval==DOSYM?ODSYM:KTSYM,NLFLG);
E 3
I 3
		   t->fornod.fortre=cmd(wdval==DOSYM?ODSYM:KTSYM,NLFLG);
E 3
		   break;
		END

	    case WHSYM:
	    case UNSYM:
		BEGIN
		   t=getstak(WHTYPE);
D 3
		   t->whtyp=(wdval==WHSYM ? TWH : TUN);
		   t->whtre = cmd(DOSYM,NLFLG);
		   t->dotre = cmd(ODSYM,NLFLG);
E 3
I 3
		   t->whnod.whtyp=(wdval==WHSYM ? TWH : TUN);
		   t->whnod.whtre = cmd(DOSYM,NLFLG);
		   t->whnod.dotre = cmd(ODSYM,NLFLG);
E 3
		   break;
		END

	    case BRSYM:
		t=cmd(KTSYM,NLFLG);
		break;

	    case '(':
		BEGIN
		   REG PARPTR	 p;
		   p=getstak(PARTYPE);
		   p->partre=cmd(')',NLFLG);
		   p->partyp=TPAR;
		   t=makefork(0,p);
		   break;
		END

	    default:
		IF io==0
		THEN	return(0);
		FI

	    case 0:
		BEGIN
		   REG ARGPTR	argp;
		   REG ARGPTR	*argtail;
		   REG ARGPTR	*argset=0;
		   INT		keywd=1;
		   t=getstak(COMTYPE);
D 3
		   t->comio=io; /*initial io chain*/
		   argtail = &(t->comarg);
E 3
I 3
		   t->comnod.comio=io; /*initial io chain*/
		   argtail = &(t->comnod.comarg);
E 3
		   WHILE wdval==0
		   DO	argp = wdarg;
			IF wdset ANDF keywd
			THEN	argp->argnxt=argset; argset=argp;
			ELSE	*argtail=argp; argtail = &(argp->argnxt); keywd=flags&keyflg;
			FI
			word();
			IF flag
D 3
			THEN t->comio=inout(t->comio);
E 3
I 3
			THEN t->comnod.comio=inout(t->comnod.comio);
E 3
			FI
		   OD

D 3
		   t->comtyp=TCOM; t->comset=argset; *argtail=0;
E 3
I 3
		   t->comnod.comtyp=TCOM; t->comnod.comset=argset; *argtail=0;
E 3
		   return(t);
		END

	ENDSW
	reserv++; word();
	IF io=inout(io)
D 3
	THEN	t=makefork(0,t); t->treio=io;
E 3
I 3
	THEN	t=makefork(0,t); t->treio.treio=io;
E 3
	FI
	return(t);
}


LOCAL VOID	skipnl()
{
	WHILE (reserv++, word()==NL) DO chkpr(NL) OD
	return(wdval);
}

LOCAL IOPTR	inout(lastio)
	IOPTR		lastio;
{
	REG INT		iof;
	REG IOPTR	iop;
	REG CHAR	c;

	iof=wdnum;

	SWITCH wdval IN

	    case DOCSYM:
		iof |= IODOC; break;

	    case APPSYM:
	    case '>':
		IF wdnum==0 THEN iof |= 1 FI
		iof |= IOPUT;
		IF wdval==APPSYM
		THEN	iof |= IOAPP; break;
		FI

	    case '<':
		IF (c=nextc(0))=='&'
		THEN	iof |= IOMOV;
		ELIF c=='>'
		THEN	iof |= IORDW;
		ELSE	peekc=c|MARK;
		FI
		break;

	    default:
		return(lastio);
	ENDSW

	chkword();
	iop=getstak(IOTYPE); iop->ioname=wdarg->argval; iop->iofile=iof;
	IF iof&IODOC
	THEN iop->iolst=iopend; iopend=iop;
	FI
	word(); iop->ionxt=inout(lastio);
	return(iop);
}

LOCAL VOID	chkword()
{
	IF word()
	THEN	synbad();
	FI
}

LOCAL VOID	chksym(sym)
{
	REG INT		x = sym&wdval;
	IF ((x&SYMFLG) ? x : sym) != wdval
	THEN	synbad();
	FI
}

LOCAL VOID	prsym(sym)
{
	IF sym&SYMFLG
	THEN	REG SYSPTR	sp=reserved;
		WHILE sp->sysval
			ANDF sp->sysval!=sym
		DO sp++ OD
		prs(sp->sysnam);
	ELIF sym==EOFSYM
	THEN	prs(endoffile);
	ELSE	IF sym&SYMREP THEN prc(sym) FI
		IF sym==NL
		THEN	prs("newline");
		ELSE	prc(sym);
		FI
	FI
}

LOCAL VOID	synbad()
{
	prp(); prs(synmsg);
	IF (flags&ttyflg)==0
	THEN	prs(atline); prn(standin->flin);
	FI
	prs(colon);
	prc(LQ);
	IF wdval
	THEN	prsym(wdval);
	ELSE	prs(wdarg->argval);
	FI
	prc(RQ); prs(unexpected);
	newline();
	exitsh(SYNBAD);
}
E 1
