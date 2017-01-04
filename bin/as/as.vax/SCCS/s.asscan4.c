h30271
s 00005/00002/00279
d D 5.1 85/04/30 14:16:19 dist 5 4
c Add copyright
e
s 00039/00029/00242
d D 4.4 83/06/30 09:57:05 rrh 4 3
c assembly language source file reading now does end of buffer 
c detection on a per character basis, not  on a per line basis, thereby 
c simplifying the monkey business with reading lines in asscan2.c; slight 
c execution penalty
e
s 00000/00000/00271
d D 4.3 82/02/14 16:36:49 rrh 3 2
c Fix reported and outstanding bugs. Reformat some text for
c readability/understandability. Assembles new instructions  for G and H
c format floating numbers & new queue instructions
c asscan.c split into 4 files; two additional files to construct and
c manipulate G and H format numbers, with analog for atof()
c Numerical accuracy of new atof() not verified; standard atof() used
c for F and D floating numbers.  As does NOT use G and H instructions itself
e
s 00000/00000/00271
d D 4.2 82/02/14 16:15:19 rrh 2 1
c Synchronizing this new file to release 4.2
e
s 00271/00000/00000
d D 4.1 82/02/14 16:11:14 rrh 1 0
c date and time created 82/02/14 16:11:14 by rrh
e
u
U
t
T
I 1
/*
D 5
 *	Copyright (c) 1982 Regents of the University of California
E 5
I 5
 * Copyright (c) 1982 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 5
 */
I 5

E 5
#ifndef lint
D 5
static char sccsid[] = "%Z%%M% %I% %G%";
E 5
I 5
static char sccsid[] = "%W% (Berkeley) %G%";
E 5
#endif not lint

#include "asscanl.h"

#define	reg	register
#define	NUMSIZE	128	/* how many characters long a number can be */
#define	FLTCHAR(x)	(INCHARSET((x),(DIGIT|SIGN|FLOATEXP|POINT)))

static char	numbuf[NUMSIZE];

D 4
int number(ch, cpp)
E 4
I 4
#define	BACK(backval)	intval = backval; goto stuffback;

int number(ch)
E 4
	reg	int	ch;
D 4
		char	**cpp;
E 4
{
		int	radix;
		int	digit;		/* part of number being constructed */
	reg	int	intval;		/* number being constructed */
	reg	char	*cp;
	reg	char	*inbufptr;
I 4
	reg	int	inbufcnt;
E 4
		char	ch1;
		Bignum	floatnumber();
		Ovf	overflow;	/* overflow flag */
		int	maxstrlg;

D 4
	inbufptr = *cpp;
E 4
I 4
	MEMTOREGBUF;
E 4
	cp = numbuf;
	radix = 10;

	switch(ch){
	case '0':
		switch(ch = getchar()){
		case 'b':
			yylval = -1;
D 4
			*cpp = inbufptr;
			return(BFINT);
E 4
I 4
			BACK(BFINT);
E 4
		case 'f':
			/*
			 * Check if it is a local label by peeking ahead
			 */
			ch1 = getchar();
			ungetc(ch1);
			if (!FLTCHAR(ch1)){
				yylval = 1;
D 4
				*cpp = inbufptr;
				return(BFINT);
E 4
I 4
				BACK(BFINT);
E 4
			}
			/*FALLTHROUGH*/
		case 'F': ch = 'f';	goto floatnum;
		case 'd':
		case 'D': ch = 'd';	goto floatnum;
		case 'h':
		case 'H': ch = 'h';	goto floatnum;
		case 'g':
		case 'G': ch = 'g';	goto floatnum;

		case 'x':
		case 'X':
			ch = '0';
			radix = 16;
			break;
		case '0':
		case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8':
		case '9':
			radix = 8;
			break;
		default:	/* single 0 */
			ungetc(ch);
			intval = 0;
			goto smallnum;
		}
		break;

	case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8':
	case '9':
		switch(ch1 = getchar()){
		case 'f':
			yylval = ((ch - '0') + 1);
D 4
			*cpp = inbufptr;
			return(BFINT);
E 4
I 4
			BACK(BFINT);
E 4
		case 'b':
			yylval = -((ch - '0') + 1);
D 4
			*cpp = inbufptr;
			return(BFINT);
E 4
I 4
			BACK(BFINT);
E 4
		default:
			ungetc(ch1);	/* put back non zero */
		}
		radix = 10;
		break;
	}
	intval = 0;
	/*
	 *	There is a character in ch that must be used to
	 *	cons up the number; we can't ungetc it
	 */
	do{
		digit = ch - '0';
		switch(radix){
		case 8:
			intval <<= 3;
			break;
		case 10:
			intval *= 10;
			break;
		case 16:
			intval <<= 4;
			if (INCHARSET(ch, HEXLDIGIT)){
				digit = (ch - 'a') + 10;
				break;
			}
			if (INCHARSET(ch, HEXUDIGIT)){
				digit = (ch - 'A') + 10;
				break;
			}
		}
		*cp++ = ch;
		/*
		 *	Build a negative number, then negate it
		 */
		intval -= digit;

		ch = getchar();
		if(!INCHARSET(ch, DIGIT)){
			if (radix != 16)
				break;
			if(!INCHARSET(ch, (HEXLDIGIT|HEXUDIGIT)))
				break;
		}
	} while (1);
	ungetc(ch);
	*cp = 0;
	maxstrlg = cp - numbuf;
	/*
	 *	See if the number is too large for our previous calculation
	 */
	switch(radix){
	case 16:
		if (maxstrlg > 8)
			goto bignum;
		break;
	case 10:
		if (maxstrlg >= 10)
			goto bignum;
		break;
	case 8:
		if (maxstrlg > 11)
			goto bignum;
		if (maxstrlg == 11 && numbuf[0] > 3)
			goto bignum;
		break;
	}
	/*
	 *	Negate the number
	 */
  smallnum: ;
	yylval = -intval;
D 4
	*cpp = inbufptr;
	return(INT);
E 4
I 4
	BACK(INT);
E 4
  bignum: ;
	yybignum = as_atoi(numbuf, radix, &overflow);
D 4
	*cpp = inbufptr;
	return(BIGNUM);
E 4
I 4
	BACK(BIGNUM);
E 4
  floatnum: ;
D 4
	*cpp = inbufptr;
	yybignum = floatnumber(ch, cpp);
E 4
I 4
	REGTOMEMBUF;
	yybignum = floatnumber(ch);
E 4
	return(BIGNUM);
I 4
 stuffback: ;
	REGTOMEMBUF;
	return(intval);
E 4
}

D 4
#define	TOOLONG	if(cp == &numbuf[NUMSIZE]){if (passno == 2)yywarning(toolong); goto process;}
#define	scanit(sign) *cpp = inbufptr; error |= scanint(sign, &cp, cpp); inbufptr = *cpp; ch = getchar(); TOOLONG;
E 4
I 4
#define	TOOLONG \
	if (cp == &numbuf[NUMSIZE]){ \
		if (passno == 2) \
			yywarning(toolong); \
			goto process; \
	}
#define	scanit(sign) \
	REGTOMEMBUF; \
	error |= scanint(sign, &cp); \
	MEMTOREGBUF; \
	ch = getchar(); \
	TOOLONG;
E 4

D 4
Bignum floatnumber(fltradix, cpp)
E 4
I 4
Bignum floatnumber(fltradix)
E 4
	int	fltradix;
D 4
	char	**cpp;		/* call by copy return semantics */
E 4
{
		char	*cp;
		int	ch;
		char	*toolong = "Floating number too long.";
		char	*prologue =
			"Floating 0%c conflicts with exponent %c; choose %c";
		/*
		 *	This is not implemented yet:
		 *	overflow is set on floating overflow.
		 */
		Ovf	overflow;
		int	error;
		int	fractOK;
	reg	char	*inbufptr;
I 4
	reg	int	inbufcnt;
E 4

D 4
	inbufptr = *cpp;
E 4
I 4
	MEMTOREGBUF;
E 4
	cp = numbuf;
	error = 0;
	fractOK = 0;

	scanit(1);
	if(INCHARSET(ch, POINT)){
		fractOK++;
		*cp++ = '.';
		scanit(0);
	}
	if(INCHARSET(ch, FLOATEXP)){
		fractOK++;
		if(ch != fltradix){
			if (passno == 2)
				yywarning(prologue, fltradix, ch, fltradix);
		}
		switch(fltradix){
		case 'd':
		case 'f':
			*cp++ = 'e';		/* will be read by atof() */
			break;
		default:
			*cp++ = fltradix;	/* will be read by bigatof() */
			break;
		}
		scanit(1);
	}
	if (error || fractOK == 0){
		yyerror("Badly formatted floating point number.");
	}
	ungetc(ch);
	*cp++ = 0;

  process: ;
	switch(fltradix){
	case 'f':	fltradix = TYPF;	break;
	case 'd':	fltradix = TYPD;	break;
	case 'g':	fltradix = TYPG;	nGHnumbers++; break;
	case 'h':	fltradix = TYPH;	nGHnumbers++; break;
	}
I 4
	REGTOMEMBUF;
E 4
	/*
	 *	The overflow value is lost in the call to as_atof
	 */
D 4
	*cpp = inbufptr;
E 4
	return(as_atof(numbuf, fltradix, &overflow));
}
/*
 *	Scan an optionally signed integer, putting back the lookahead
 *	character when finished scanning.
 */
D 4
int scanint(signOK, dstcpp, srccpp)
E 4
I 4
int scanint(signOK, dstcpp)
E 4
	int	signOK;
	char	**dstcpp;
D 4
	char	**srccpp;	/* call by copy return */
E 4
{
D 4
	int	ch;
	int	back = 0;
	reg	char	*inbufptr = *srccpp;
E 4
I 4
		int	ch;
		int	back = 0;
	reg	char	*inbufptr;
	reg	int	inbufcnt;
E 4

I 4
	MEMTOREGBUF;
E 4
	ch = getchar();
	while (INCHARSET(ch, SIGN)){
		if (signOK && !back)
			*((*dstcpp)++) = ch;
		else
			back = 1;
		ch = getchar();
	}
	while (INCHARSET(ch, DIGIT)){
		*((*dstcpp)++) = ch;
		ch = getchar();
	}
	ungetc(ch);
D 4
	*srccpp = inbufptr;
E 4
I 4
	REGTOMEMBUF;
E 4
	return(back);
}
E 1
