h16030
s 00006/00005/00132
d D 4.7 88/04/24 15:08:36 bostic 7 6
c fixes for ANSI C
e
s 00002/00001/00135
d D 4.6 85/10/31 16:43:59 bloom 6 5
c serge couldn't get it right ( # as comment only from keyboard )
e
s 00001/00001/00135
d D 4.5 85/09/20 15:31:39 serge 5 4
c allow # comment in .profile and . (source) command
e
s 00001/00001/00135
d D 4.4 85/02/13 18:48:04 serge 4 3
c don't recognize # as a comment character if interactive 
c added -b flag to force next arg as shell input file for setuid scripts
e
s 00003/00001/00133
d D 4.3 83/08/11 20:20:31 sam 3 2
c standardize sccs keyword lines
e
s 00002/00000/00132
d D 4.2 83/06/10 23:38:01 sam 2 1
c new signals make read's restarted, thus must setjmp/longjmp to get 
c prompt reprinted when an interrupt is hit while sitting at the prompt
e
s 00132/00000/00000
d D 4.1 82/05/07 19:39:44 mckusick 1 0
c date and time created 82/05/07 19:39:44 by mckusick
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
#ifndef lint
static char sccsid[] = "%W% %G%";
#endif
E 3

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


/* ========	character handling for command lines	========*/


word()
{
	REG CHAR	c, d;
	REG CHAR	*argp=locstak()+BYTESPERWORD;
I 7
	REG ARGPTR	ap;
E 7
	INT		alpha=1;

	wdnum=0; wdset=0;

	WHILE (c=nextc(0), space(c)) DONE

D 4
	IF c=='#'
E 4
I 4
D 5
	IF c=='#' ANDF (flags&ttyflg)==0
E 5
I 5
D 6
	IF c=='#' ANDF ((flags&prompt)==0 ORF !isatty(input))
E 6
I 6
	IF c=='#' ANDF ((flags&prompt)==0 ORF ((flags&ttyflg) ANDF
	    standin->fstak!=0))
E 6
E 5
E 4
	THEN	WHILE (c=readc()) ANDF c!=NL DONE
	FI

	IF !eofmeta(c)
	THEN	REP	IF c==LITERAL
			THEN	*argp++=(DQUOTE);
				WHILE (c=readc()) ANDF c!=LITERAL
				DO *argp++=(c|QUOTE); chkpr(c) OD
				*argp++=(DQUOTE);

			ELSE	*argp++=(c);
				IF c=='=' THEN wdset |= alpha FI
				IF !alphanum(c) THEN alpha=0 FI
				IF qotchar(c)
				THEN	d=c;
					WHILE (*argp++=(c=nextc(d))) ANDF c!=d
					DO chkpr(c) OD
				FI
			FI
		PER (c=nextc(0), !eofmeta(c)) DONE
D 7
		argp=endstak(argp);
		IF !letter(argp->argval[0]) THEN wdset=0 FI
E 7
I 7
		ap=(ARGPTR)endstak(argp);
		IF !letter(ap->argval[0]) THEN wdset=0 FI
E 7

		peekc=c|MARK;
D 7
		IF argp->argval[1]==0 ANDF (d=argp->argval[0], digit(d)) ANDF (c=='>' ORF c=='<')
E 7
I 7
		IF ap->argval[1]==0 ANDF (d=ap->argval[0], digit(d)) ANDF (c=='>' ORF c=='<')
E 7
		THEN	word(); wdnum=d-'0';
		ELSE	/*check for reserved words*/
D 7
			IF reserv==FALSE ORF (wdval=syslook(argp->argval,reserved))==0
			THEN	wdarg=argp; wdval=0;
E 7
I 7
			IF reserv==FALSE ORF (wdval=syslook(ap->argval,reserved))==0
			THEN	wdarg=ap; wdval=0;
E 7
			FI
		FI

	ELIF dipchar(c)
	THEN	IF (d=nextc(0))==c
		THEN	wdval = c|SYMREP;
		ELSE	peekc = d|MARK; wdval = c;
		FI
	ELSE	IF (wdval=c)==EOF
		THEN	wdval=EOFSYM;
		FI
		IF iopend ANDF eolchar(c)
		THEN	copy(iopend); iopend=0;
		FI
	FI
	reserv=FALSE;
	return(wdval);
}

nextc(quote)
	CHAR		quote;
{
	REG CHAR	c, d;
	IF (d=readc())==ESCAPE
	THEN	IF (c=readc())==NL
		THEN	chkpr(NL); d=nextc(quote);
		ELIF quote ANDF c!=quote ANDF !escchar(c)
		THEN	peekc=c|MARK;
		ELSE	d = c|QUOTE;
		FI
	FI
	return(d);
}

readc()
{
	REG CHAR	c;
	REG INT		len;
	REG FILE	f;

retry:
	IF peekc
	THEN	c=peekc; peekc=0;
	ELIF (f=standin, f->fnxt!=f->fend)
	THEN	IF (c = *f->fnxt++)==0
		THEN	IF f->feval
			THEN	IF estabf(*f->feval++)
				THEN	c=EOF;
				ELSE	c=SP;
				FI
			ELSE	goto retry; /* = c=readc(); */
			FI
		FI
		IF flags&readpr ANDF standin->fstak==0 THEN prc(c) FI
		IF c==NL THEN f->flin++ FI
	ELIF f->feof ORF f->fdes<0
	THEN	c=EOF; f->feof++;
	ELIF (len=readb())<=0
	THEN	close(f->fdes); f->fdes = -1; c=EOF; f->feof++;
	ELSE	f->fend = (f->fnxt = f->fbuf)+len;
		goto retry;
	FI
	return(c);
}

LOCAL	readb()
{
	REG FILE	f=standin;
	REG INT		len;

I 2
	IF setjmp(INTbuf) == 0 THEN trapjmp[INTR] = 1; FI
E 2
	REP	IF trapnote&SIGSET THEN newline(); sigchk() FI
	PER (len=read(f->fdes,f->fbuf,f->fsiz))<0 ANDF trapnote DONE
I 2
	trapjmp[INTR] = 0;
E 2
	return(len);
}
E 1
