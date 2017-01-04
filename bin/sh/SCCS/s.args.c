h00602
s 00007/00007/00132
d D 4.5 88/04/24 15:08:29 bostic 6 5
c fixes for ANSI C
e
s 00000/00000/00139
d D 4.4 85/07/31 15:33:14 bloom 5 4
x 4
c the last fix broke shell scripts all over the place
e
s 00007/00002/00137
d D 4.3 85/02/14 13:40:25 serge 4 2
c don't recognize # as a comment character if interactive 
c added -b flag to force next arg as shell input file for setuid scripts
e
s 00007/00002/00137
d R 4.3 85/02/13 18:47:55 serge 3 2
c don't recognize # as a comment character if interactive 
c added -b flag to force next arg as shell input file for setuid scripts
e
s 00003/00001/00136
d D 4.2 83/08/11 20:18:35 sam 2 1
c standardize sccs keyword lines
e
s 00137/00000/00000
d D 4.1 82/05/07 19:36:17 mckusick 1 0
c date and time created 82/05/07 19:36:17 by mckusick
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

D 6
PROC STRING *copyargs();
E 6
I 6
PROC DOLPTR copyargs();
E 6
LOCAL DOLPTR	dolh;

CHAR	flagadr[10];

CHAR	flagchar[] = {
D 4
	'x',	'n',	'v',	't',	's',	'i',	'e',	'r',	'k',	'u',	0
E 4
I 4
	'x',	'n',	'v',	't',	's',	'i',	'e',	'r',	'k',	'u',	'b',	0
E 4
};
INT	flagval[]  = {
D 4
	execpr,	noexec,	readpr,	oneflg,	stdflg,	intflg,	errflg,	rshflg,	keyflg,	setflg,	0
E 4
I 4
	execpr,	noexec,	readpr,	oneflg,	stdflg,	intflg,	errflg,	rshflg,	keyflg,	setflg,	batchflg, 0
E 4
};

/* ========	option handling	======== */


INT	options(argc,argv)
	STRING		*argv;
	INT		argc;
{
	REG STRING	cp;
	REG STRING	*argp=argv;
	REG STRING	flagc;
	STRING		flagp;

	IF argc>1 ANDF *argp[1]=='-'
	THEN	cp=argp[1];
		flags &= ~(execpr|readpr);
		WHILE *++cp
		DO	flagc=flagchar;

			WHILE *flagc ANDF *flagc != *cp DO flagc++ OD
			IF *cp == *flagc
			THEN	flags |= flagval[flagc-flagchar];
			ELIF *cp=='c' ANDF argc>2 ANDF comdiv==0
			THEN	comdiv=argp[2];
				argp[1]=argp[0]; argp++; argc--;
			ELSE	failed(argv[1],badopt);
			FI
		OD
		argp[1]=argp[0]; argc--;
I 4
	FI

	IF !(flags&batchflg) ANDF (getuid()!=geteuid() ORF getgid()!=getegid())
	THEN
		failed("sh","Permission denied");
E 4
	FI

	/* set up $- */
	flagc=flagchar;
	flagp=flagadr;
	WHILE *flagc
	DO IF flags&flagval[flagc-flagchar]
	   THEN *flagp++ = *flagc;
	   FI
	   flagc++;
	OD
	*flagp++=0;

	return(argc);
}

VOID	setargs(argi)
	STRING		argi[];
{
	/* count args */
	REG STRING	*argp=argi;
	REG INT		argn=0;

	WHILE Rcheat(*argp++)!=ENDARGS DO argn++ OD

	/* free old ones unless on for loop chain */
	freeargs(dolh);
	dolh=copyargs(argi,argn);	/* sets dolv */
	assnum(&dolladr,dolc=argn-1);
}

freeargs(blk)
	DOLPTR		blk;
{
	REG STRING	*argp;
	REG DOLPTR	argr=0;
	REG DOLPTR	argblk;

	IF argblk=blk
	THEN	argr = argblk->dolnxt;
		IF (--argblk->doluse)==0
		THEN	FOR argp=argblk->dolarg; Rcheat(*argp)!=ENDARGS; argp++
			DO free(*argp) OD
			free(argblk);
		FI
	FI
	return(argr);
}

D 6
LOCAL STRING *	copyargs(from, n)
E 6
I 6
LOCAL DOLPTR	copyargs(from, n)
E 6
	STRING		from[];
{
D 6
	REG STRING *	np=alloc(sizeof(STRING*)*n+3*BYTESPERWORD);
E 6
I 6
	REG DOLPTR	dp=alloc(sizeof(STRING*)*n+3*BYTESPERWORD);
	REG STRING *	np;
E 6
	REG STRING *	fp=from;
D 6
	REG STRING *	pp=np;
E 6

D 6
	np->doluse=1;	/* use count */
	np=np->dolarg;
E 6
I 6
	dp->doluse=1;	/* use count */
	np=dp->dolarg;
E 6
	dolv=np;

	WHILE n--
	DO *np++ = make(*fp++) OD
	*np++ = ENDARGS;
D 6
	return(pp);
E 6
I 6
	return(dp);
E 6
}

clearup()
{
	/* force `for' $* lists to go away */
	WHILE argfor=freeargs(argfor) DONE

	/* clean up io files */
	WHILE pop() DONE
}

DOLPTR	useargs()
{
	IF dolh
	THEN	dolh->doluse++;
		dolh->dolnxt=argfor;
		return(argfor=dolh);
	ELSE	return(0);
	FI
}
E 1
