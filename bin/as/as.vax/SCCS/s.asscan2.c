h35964
s 00005/00002/00460
d D 5.1 85/04/30 14:15:29 dist 15 14
c Add copyright
e
s 00005/00003/00457
d D 4.14 83/07/06 18:18:26 rrh 14 13
c fixed bug preventing assembly of > 1 file.
e
s 00001/00001/00459
d D 4.13 83/07/01 09:47:05 rrh 13 12
c remove manifest constants for NCPString and ASINBUFSIZ, reflecting
c the fact that arbitrary length strings are stored in a file
e
s 00005/00024/00455
d D 4.12 83/07/01 09:43:17 rrh 12 11
c savestr now saves strings in both a file and in core; fixed
c a bug with savestr being too generous in saving strings in core
e
s 00004/00008/00475
d D 4.11 83/06/30 19:20:22 rrh 11 10
c bye bye fixed names (eg, FLEXNAMES is not set)
e
s 00020/00012/00463
d D 4.10 83/06/30 19:03:39 rrh 10 9
c The string pool is maintained both in core, and in a second tmp file.
c names are in core and on the file; strings are just in the file.  The file 
c is maintained as a string table per a.out(5), and tacked onto the a.out file
c at the very end.  The string table has more than need be, since discarde 
c labels and .ascii strings find their way (harmlessly) into the string table.
c the string file maintained with stdio; nothing fancy, even if -V set
e
s 00050/00133/00425
d D 4.9 83/06/30 09:57:35 rrh 9 8
c assembly language source file reading now does end of buffer 
c detection on a per character basis, not  on a per line basis, thereby 
c simplifying the monkey business with reading lines in asscan2.c; slight 
c execution penalty
e
s 00014/00005/00544
d D 4.8 83/06/30 07:59:21 rrh 8 7
c consolidate character buffer length definitions (manifest constants)
c into one place, with documentation
e
s 00075/00082/00474
d D 4.7 83/06/29 20:06:58 rrh 7 6
c DQ quoted strings no longer put into the temp file, but stored
c directly into the string spool; this fixes serious efficiency/size bugs
c in the temp files. DQ strings put into string pool with preceding 2 bytes
c indicating the length, with a trailing null byte not accounted for in the
c 2byte length; .asciz and .stabs change length and magically get null byte;
c all string moves (lookup and reader) done by subroutine call & movc3
e
s 00001/00001/00555
d D 4.6 82/12/15 04:44:10 linton 6 5
c last fix curdled @(#) stuff, fixed it
e
s 00007/00001/00549
d D 4.5 82/12/15 04:39:52 linton 5 4
c changed to handle longer string constants
e
s 00038/00006/00512
d D 4.4 82/04/16 18:55:07 rrh 4 3
c Fixed buffering bug.  Fix bug in string assembly with back slash 
c escaped numerical constants
e
s 00000/00000/00518
d D 4.3 82/02/14 16:36:35 rrh 3 2
c Fix reported and outstanding bugs. Reformat some text for
c readability/understandability. Assembles new instructions  for G and H
c format floating numbers & new queue instructions
c asscan.c split into 4 files; two additional files to construct and
c manipulate G and H format numbers, with analog for atof()
c Numerical accuracy of new atof() not verified; standard atof() used
c for F and D floating numbers.  As does NOT use G and H instructions itself
e
s 00000/00000/00518
d D 4.2 82/02/14 16:14:50 rrh 2 1
c Synchronizing this new file to release 4.2
e
s 00518/00000/00000
d D 4.1 82/02/14 16:11:06 rrh 1 0
c date and time created 82/02/14 16:11:06 by rrh
e
u
U
t
T
I 1
/*
D 15
 *	Copyright (c) 1982 Regents of the University of California
E 15
I 15
 * Copyright (c) 1982 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 15
 */
I 15

E 15
#ifndef lint
D 5
static char sccsid[] = "%Z%%M% %I% %G%";
E 5
I 5
D 6
static char sccsid[] = "@(#)asscan2.c 4.4 4/16/82";
E 6
I 6
D 15
static char sccsid[] = "%Z%%M% %I% %G%";
E 15
I 15
static char sccsid[] = "%W% (Berkeley) %G%";
E 15
E 6
E 5
#endif not lint

#include "asscanl.h"
I 9

E 9
static	inttoktype	oval = NL;
I 5
D 13

E 13
I 13
#define	ASINBUFSIZ	4096
E 13
D 7
#ifdef BUFSIZ
#undef BUFSIZ
#endif

#define BUFSIZ 4096
E 5

E 7
I 7
D 8
#define ASINBUFSIZ 4096
E 8
E 7
D 9
#define	NINBUFFERS	2
D 7
#define	INBUFLG		NINBUFFERS*BUFSIZ + 2
E 7
I 7
#define	INBUFLG		NINBUFFERS*ASINBUFSIZ + 2
E 9
I 9
char	inbufunget[8];
char	inbuffer[ASINBUFSIZ];
char	*Ginbufptr = inbuffer;
int	Ginbufcnt = 0;
I 14
int	scannerhadeof;
E 14

fillinbuffer()
{
		int	nread;
D 14
	static	int	hadeof;
E 14
		int	goal;
		int	got;

	nread = 0;
D 14
	if (hadeof == 0){
E 14
I 14
	if (scannerhadeof == 0){
E 14
		goal = sizeof(inbuffer);
		do {
			got = read(stdin->_file, inbuffer + nread, goal);
			if (got == 0)
D 14
				hadeof = 1;
E 14
I 14
				scannerhadeof = 1;
E 14
			if (got <= 0)
				break;
			nread += got;
			goal -= got;
		} while (goal);
I 14
	} else {
		scannerhadeof = 0;
E 14
	}
E 9
E 7
	/*
D 7
	 *	We have two input buffers; the first one is reserved
E 7
I 7
D 9
	 *	We have NINBUFFERS input buffers; the first one is reserved
E 7
	 *	for catching the tail of a line split across a buffer
D 7
	 *	boundary; the other one are used for snarfing a buffer
	 *	worth of .s source.
E 7
I 7
	 *	boundary; the other ones are used for snarfing a buffer
	 *	worth of assembly language source.
E 9
I 9
	 *	getchar assumes that Ginbufcnt and Ginbufptr
	 *	are adjusted as if one character has been removed
	 *	from the input.
E 9
E 7
	 */
D 9
static	char	inbuffer[INBUFLG];
static	char	*InBufPtr = 0;
E 9
I 9
	if (nread == 0){
		inbuffer[0] = EOFCHAR;
		nread = 1;
	}
	Ginbufcnt = nread - 1;
	Ginbufptr = inbuffer + 1;
}
E 9

I 8
D 11
#ifndef FLEXNAMES
E 11
I 11
D 12
#if NCPName < NCPString
E 11
char	strtext[NCPString + 1];
D 11
#else FLEXNAMES
# if NCPName < NCPString
char	strtext[NCPString + 1];
# else
#define	strtext yytext
# endif
#endif FLEXNAMES
E 11
I 11
#else
#	define	strtext yytext
#endif
E 11

E 12
E 8
D 9
/*
 *	fill the inbuffer from the standard input.
 *	Assert: there are always n COMPLETE! lines in the buffer area.
 *	Assert: there is always a \n terminating the last line
 *		in the buffer area.
 *	Assert: after the \n, there is an EOFCHAR (hard end of file)
 *		or a NEEDCHAR (end of buffer)
 *	Assert:	fgets always null pads the string it reads.
 *	Assert:	no ungetc's are done at the end of a line or at the
 *		beginning of a line.
 *	
 *	We read a complete buffer of characters in one single read.
 *	We then back scan within this buffer to find the end of the
 *	last complete line, and force the assertions, and save a pointer
 *	to the incomplete line.
 *	The next call to fillinbuffer will move the unread characters
 *	to the end of the first buffer, and then read another two buffers,
 *	completing the cycle.
 */

static	char	p_swapped = '\0';			
D 7
static	char	*p_start = &inbuffer[NINBUFFERS * BUFSIZ];
static	char	*p_stop = &inbuffer[NINBUFFERS * BUFSIZ];
E 7
I 7
static	char	*p_start = &inbuffer[NINBUFFERS * ASINBUFSIZ];
static	char	*p_stop = &inbuffer[NINBUFFERS * ASINBUFSIZ];
E 7
I 4

I 7
#define	MIDDLE	&inbuffer[ASINBUFSIZ]

E 7
E 4
char *fillinbuffer()
{
D 7
	register	char	*to;
E 7
	register	char	*from;
			char	*inbufptr;
	int		nread;
I 4
	static		int	hadeof;
	int		goal;
	int		got;
E 4

	*p_start = p_swapped;
D 7
	inbufptr = &inbuffer[1*BUFSIZ] - (p_stop - p_start);

	for (to = inbufptr, from = p_start; from < p_stop;)
		*to++ = *from++;
E 7
I 7
	inbufptr = MIDDLE - (p_stop - p_start);
	movestr(inbufptr, p_start, p_stop - p_start);
E 7
	/*
D 7
	 *	Now, go read two full buffers (hopefully)
E 7
I 7
	 *	Now, go read up to NINBUFFERS - 1 full buffers
E 7
	 */
D 4
	nread = read(stdin->_file, &inbuffer[1*BUFSIZ], (NINBUFFERS - 1)*BUFSIZ);
E 4
I 4
	if (hadeof){
		hadeof = 0;
		return (0);
	}
D 7
	goal = (NINBUFFERS - 1)*BUFSIZ;
E 7
I 7
	goal = (NINBUFFERS - 1)*ASINBUFSIZ;
E 7
	nread = 0;
	do {
D 7
		got = read(stdin->_file, &inbuffer[1*BUFSIZ + nread], goal);
E 7
I 7
		got = read(stdin->_file, MIDDLE + nread, goal);
E 7
		if (got == 0)
			hadeof = 1;
		if (got <= 0)
			break;
		nread += got;
		goal -= got;
	} while (goal);

E 4
	if (nread == 0)
		return(0);
D 7
	p_stop = from = &inbuffer[1*BUFSIZ + nread];
E 7
I 7
	from = MIDDLE + nread;
	p_stop = from;
E 7
	*from = '\0';
D 4
	while (*--from != '\n')		/* back over the partial line */
		continue;
E 4
I 4
D 7

E 7
	while (*--from != '\n'){
		/*
		 *	back over the partial line
		 */
D 7
		if (from == &inbuffer[1*BUFSIZ]) {
E 7
I 7
		if (from == MIDDLE) {
E 7
			from = p_stop;
			*p_stop++ = '\n';
			break;
		} else {
			continue;
		}
	}

E 4
	from++;				/* first char of partial line */
	p_start = from;
	p_swapped = *p_start;
	*p_start = NEEDCHAR;		/* force assertion */
	return(inbufptr);
}

E 9
scan_dot_s(bufferbox)
	struct tokbufdesc *bufferbox;
{
I 9
	reg	char	*inbufptr;
	reg	int	inbufcnt;
E 9
	reg	int	ryylval;	/* local copy of lexical value */
	extern	int	yylval;		/* global copy of lexical value */
	reg	int	val;		/* the value returned */
		int	i;		/* simple counter */
	reg	char	*rcp;	
D 9
		char	*cp;		/* can have address taken */
	reg	int	ch;		/* treated as a character */
E 9
I 9
		int	ch;		/* treated as a character */
E 9
		int	ch1;		/* shadow value */
D 9
	reg	char	*inbufptr;
E 9
		struct 	symtab	*op;
D 9

	reg	ptrall	bufptr;		/* where to stuff tokens */
E 9
		ptrall	lgbackpatch;	/* where to stuff a string length */
I 9
	reg	ptrall	bufptr;		/* where to stuff tokens */
E 9
		ptrall	bufub;		/* where not to stuff tokens */
D 7
		int	maxstrlg;	/* how long a string can be */
E 7
I 7
D 10
	reg	int	maxstrlg;	/* how long a string can be */
E 10
I 10
D 12
	reg	int	strlg;		/* the length of a string */
E 12
E 10
E 7
		long	intval;		/* value of int */
		int	linescrossed;	/* when doing strings and comments */
		struct	Opcode		opstruct;
I 10
D 12
		struct	strdesc	strd;	/* for building DQ strings */
E 12
I 12
	reg	int	strlg;		/* the length of a string */
E 12
E 10

	(bytetoktype *)bufptr = (bytetoktype *) & (bufferbox->toks[0]);	
	(bytetoktype *)bufub = &(bufferbox->toks[AVAILTOKS]);

D 9
	inbufptr = InBufPtr;
	if (inbufptr == 0){
		inbufptr = fillinbuffer();
		if (inbufptr == 0){	/*end of file*/
   		  endoffile:
			inbufptr = 0;
			ptoken(bufptr, PARSEEOF);
			goto done;
		}
	}

E 9
I 9
	MEMTOREGBUF;
E 9
	if (newfflag){
I 7
		newfflag = 0;
D 10
		ryylval = (int)savestr(newfname, strlen(newfname) + 1);
E 10
I 10
D 12
		strd.sd_stroff = strfilepos;
		strd.sd_place = STR_BOTH;
		strd.sd_strlen = strlen(newfname) + 1;
		fputs(newfname, strfile);
		putc(0, strfile);
		strfilepos += strd.sd_strlen;
		ryylval = (int)savestr(newfname, &strd);
E 12
I 12
		ryylval = (int)savestr(newfname, strlen(newfname)+1, STR_BOTH);
E 12
E 10

E 7
		ptoken(bufptr, IFILE);
		ptoken(bufptr, STRING);
D 7
		val = strlen(newfname) + 1;
		movestr( (char *)&( ( (lgtype *)bufptr)[1]), newfname, val);
		bstrlg(bufptr, val);
E 7
I 7
		pptr(bufptr, ryylval);
E 7

		ptoken(bufptr, ILINENO);
		ptoken(bufptr, INT);
		pint(bufptr,  1);
D 7
		newfflag = 0;
E 7
	}

	while (bufptr < bufub){
   loop:
D 9
        switch(ryylval = (type+2)[ch = getchar()]) {
E 9
I 9
        switch(ryylval = (type+1)[ch = getchar()]) {
E 9
	case SCANEOF:
I 9
	endoffile: ;
E 9
		inbufptr = 0;
D 9
		goto endoffile;
E 9
I 9
		ptoken(bufptr, PARSEEOF);
		goto done;
E 9

D 9
	case NEEDSBUF:
		inbufptr = fillinbuffer();
		if (inbufptr == 0)
			goto endoffile;
		goto loop;

E 9
	case DIV:		/*process C style comments*/
		if ( (ch = getchar()) == '*') {  /*comment prelude*/
			int	incomment;
			linescrossed = 0;
			incomment = 1;
			ch = getchar();	/*skip over the * */
			while(incomment){
				switch(ch){
				case '*':
					ch = getchar();
					incomment = (ch != '/');
					break;
				case '\n':
					scanlineno++;
					linescrossed++;
					ch = getchar();
					break;
				case EOFCHAR:
					goto endoffile;
D 9
				case NEEDCHAR:
					inbufptr = fillinbuffer();
					if (inbufptr == 0)
						goto endoffile;
					lineno++;
					ch = getchar();
					break;
E 9
				default:
					ch = getchar();
					break;
				}
			}
			val = ILINESKIP;
			ryylval = linescrossed;
			goto ret;
		} else {	/*just an ordinary DIV*/
			ungetc(ch);
			val = ryylval = DIV;
			goto ret;
		}
	case SH:
		if (oval == NL){
			/*
			 *	Attempt to recognize a C preprocessor
			 *	style comment '^#[ \t]*[0-9]*[ \t]*".*"
			 */
			ch = getchar();	/*bump the #*/
			while (INCHARSET(ch, SPACE))
				ch = getchar();/*bump white */
			if (INCHARSET(ch, DIGIT)){
				intval = 0;
				while(INCHARSET(ch, DIGIT)){
					intval = intval*10 + ch - '0';
					ch = getchar();
				}
				while (INCHARSET(ch, SPACE))
					ch = getchar();
				if (ch == '"'){
					ptoken(bufptr, ILINENO);
					ptoken(bufptr, INT);
					pint(bufptr, intval - 1);
					ptoken(bufptr, IFILE);
					/*
					 *	The '"' has already been
					 *	munched
					 *	
					 *	eatstr will not eat
					 *	the trailing \n, so
					 *	it is given to the parser
					 *	and counted.
					 */
					goto eatstr;
				}
			}
		}
		/*
		 *	Well, its just an ordinary decadent comment
		 */
		while ((ch != '\n') && (ch != EOFCHAR)) 
			ch = getchar();
		if (ch == EOFCHAR)
			goto endoffile;
		val = ryylval = oval = NL;
		scanlineno++;
		goto ret;

	case NL:
		scanlineno++;
		val = ryylval;
		goto ret;

	case SP:
		oval = SP;	/*invalidate ^# meta comments*/
		goto loop;

	case REGOP:		/* % , could be used as modulo, or register*/
		ch = getchar();
		if (INCHARSET(ch, DIGIT)){
			ryylval = ch-'0';
			if (ch=='1') {
				if (INCHARSET( (ch = getchar()), REGDIGIT))
					ryylval = 10+ch-'0';
				else
					ungetc(ch);
			}
			/*
			 *	God only knows what the original author
			 *	wanted this undocumented feature to
			 *	do.
			 *		%5++ is really  r7
			 */
			while(INCHARSET( (ch = getchar()), SIGN)) {
				if (ch=='+')
					ryylval++;
				else
					ryylval--;
			}
			ungetc(ch);
			val = REG;
		} else {
			ungetc(ch);
			val = REGOP;
		}
		goto ret;

	case ALPH:
		ch1 = ch;
		if (INCHARSET(ch, SZSPECBEGIN)){
			if( (ch = getchar()) == '`' || ch == '^'){
				ch1 |= 0100;	/*convert to lower*/
				switch(ch1){
				case 'b':	ryylval = 1;	break;
				case 'w':	ryylval = 2;	break;
				case 'l':	ryylval = 4;	break;
				default:	ryylval = d124;	break;
				}
				val = SIZESPEC;
				goto ret;
			} else {
				ungetc(ch);
				ch = ch1;	/*restore first character*/
			}
		}
		rcp = yytext;
		do {
D 8
			if (rcp < &yytext[NCPS])
E 8
I 8
			if (rcp < &yytext[NCPName])
E 8
				*rcp++ = ch;
		} while (INCHARSET ( (ch = getchar()), ALPHA | DIGIT));
		*rcp = '\0';
		while (INCHARSET(ch, SPACE))
			ch = getchar();
		ungetc(ch);
	
		switch((op = *lookup(1))->s_tag){
		case 0:
		case LABELID:
			/*
D 10
			 *	Its a name... (Labels are subsets ofname)
E 10
I 10
			 *	Its a name... (Labels are subsets of name)
E 10
			 */
			ryylval = (int)op;
			val = NAME;
			break;
		case INST0:
		case INSTn:
		case IJXXX:
			opstruct.Op_popcode = ( (struct instab *)op)->i_popcode;
			opstruct.Op_eopcode = ( (struct instab *)op)->i_eopcode;
			val = op->s_tag;
			break;
		default:
			ryylval = ( (struct instab *)op)->i_popcode;
			val = op->s_tag;
			break;
		}
		goto ret;

	case DIG:
		/*
D 9
		 *	Implement call by reference on a reg variable
E 9
I 9
		 *	restore local inbufptr and inbufcnt
E 9
		 */
D 9
		cp = inbufptr;
		val = number(ch, &cp);
E 9
I 9
		REGTOMEMBUF;
		val = number(ch);
		MEMTOREGBUF;
E 9
		/*
		 *	yylval or yybignum has been stuffed as a side
		 *	effect to number(); get the global yylval
		 *	into our fast local copy in case it was an INT.
		 */
		ryylval = yylval;
D 9
		inbufptr = cp;
E 9
		goto ret;

	case LSH:
	case RSH:
		/*
		 *	We allow the C style operators
		 *	<< and >>, as well as < and >
		 */
		if ( (ch1 = getchar()) != ch)
			ungetc(ch1);
		val = ryylval;
		goto ret;

	case MINUS:
		if ( (ch = getchar()) =='(')
			ryylval=val=MP;
		else {
			ungetc(ch);
			val=MINUS;
		}
		goto ret;

	case SQ:
		if ((ryylval = getchar()) == '\n')
			scanlineno++;		/*not entirely correct*/
		val = INT;
		goto ret;

	case DQ:
	   eatstr:
		linescrossed = 0;
D 7
		maxstrlg = (char *)bufub - (char *)bufptr;

		if (maxstrlg < MAXSTRLG) {
			ungetc('"');
			*(bytetoktype *)bufptr = VOID ;
			bufub = bufptr;
			goto done;
		}
		if (maxstrlg > MAXSTRLG)
			maxstrlg = MAXSTRLG;
		
		ptoken(bufptr, STRING);
		lgbackpatch = bufptr;	/*this is where the size goes*/
		bufptr += sizeof(lgtype);
		/*
		 *	bufptr is now set to
		 *	be stuffed with characters from
		 *	the input
		 */

		while (   (maxstrlg > 0)
		       && !(INCHARSET( (ch = getchar()), STRESCAPE))
		      ){
			stuff:
D 4
				maxstrlg-= 1;
E 4
I 4
				maxstrlg -= 1;
E 4
				pchar(bufptr, ch);
			}
		if (maxstrlg <= 0){	/*enough characters to fill a string buffer*/
			ungetc('"');		/*will read it next*/
		}
D 4
		else if (ch == '"');		/*done*/
E 4
I 4
		else if (ch == '"')
			/*VOID*/ ;		/*done*/
E 4
		else if (ch == '\n'){
			yywarning("New line embedded in a string constant.");
E 7
I 7
D 8
		for(rcp = yytext, maxstrlg = NCPS; maxstrlg > 0; --maxstrlg){
E 8
I 8
D 10
		for(rcp = strtext, maxstrlg = NCPString; maxstrlg > 0; --maxstrlg){
E 10
I 10
D 12
		strd.sd_stroff = strfilepos;
		strd.sd_place = STR_FILE;
		for (strd.sd_strlen = 0; /*VOID*/; strd.sd_strlen++){
E 12
I 12
		for (strlg = 0; /*VOID*/; strlg++){
E 12
E 10
E 8
		    switch(ch = getchar()){
		    case '"':
			goto tailDQ;
		    default:
		    stuff:
D 10
			pchar(rcp, ch);
E 10
I 10
			putc(ch, strfile);
E 10
			break;
		    case '\n':
			yywarning("New line in a string constant");
E 7
			scanlineno++;
			linescrossed++;
			ch = getchar();
D 7
			if (ch == EOFCHAR){
			  do_eof:
				pchar(bufptr, '\n');
E 7
I 7
			switch(ch){
D 9
			case NEEDCHAR:
				if ( (inbufptr = fillinbuffer()) != 0){
					ch = '\n';
					goto stuff;
				}
				/*FALLTHROUGH*/
E 9
			case EOFCHAR:
D 10
				pchar(rcp, '\n');
E 10
I 10
				putc('\n', strfile);
E 10
E 7
				ungetc(EOFCHAR);
D 7
			} else
			if (ch == NEEDCHAR){
				if ( (inbufptr = fillinbuffer()) == 0)
					goto do_eof;
				ch = '\n';
				goto stuff;
			} else {	/* simple case */
E 7
I 7
				goto tailDQ;
			default:
E 7
				ungetc(ch);
				ch = '\n';
				goto stuff;
			}
D 7
		} else {
E 7
I 7
			break;

		    case '\\':
E 7
			ch = getchar();		/*skip the '\\'*/
			if ( INCHARSET(ch, BSESCAPE)){
				switch (ch){
				  case 'b':  ch = '\b'; goto stuff;
				  case 'f':  ch = '\f'; goto stuff;
				  case 'n':  ch = '\n'; goto stuff;
				  case 'r':  ch = '\r'; goto stuff;
				  case 't':  ch = '\t'; goto stuff;
				}
			}
D 7
			if ( !(INCHARSET(ch,OCTDIGIT)) )  goto stuff;
E 7
I 7
			if ( !(INCHARSET(ch, OCTDIGIT)) ) 
				goto stuff;
E 7
			i = 0;
			intval = 0;
			while ( (i < 3) && (INCHARSET(ch, OCTDIGIT))){
D 7
				i++;intval <<= 3;intval += ch - '0';
E 7
I 7
				i++;
				intval <<= 3;
				intval += ch - '0';
E 7
				ch = getchar();
			}
			ungetc(ch);
D 4
			val = (char)intval;
E 4
I 4
			ch = (char)intval;
E 4
			goto stuff;
I 7
		    }
E 7
		}
I 7
	tailDQ: ;
E 7
		/*
D 7
		 *	bufptr now points at the next free slot
E 7
I 7
		 *	account for any lines that were crossed
E 7
		 */
D 7
		bstrfromto(lgbackpatch, bufptr);
E 7
		if (linescrossed){
D 7
			val = ILINESKIP;
			ryylval = linescrossed;
			goto ret;
		} else
			goto builtval;
E 7
I 7
			ptoken(bufptr, ILINESKIP);
			pint(bufptr, linescrossed);
		}
		/*
D 8
		 *	put the string in yytext into the string pool
E 8
I 8
D 12
		 *	put the string in strtext into the string pool
E 8
		 *
E 12
D 10
		 *	The value in ryylval points to the string;
		 *	the previous 2 bytes is the length of the string
		 *
E 10
		 *	Cheat: append a trailing null to the string
		 *	and then adjust the string length to ignore
		 *	the trailing null.  If any STRING client requires
		 *	the trailing null, the client can just change STRLEN
		 */
D 12
		val = STRING;
E 12
D 10
		*rcp++ = 0;
D 8
		ryylval = (int)savestr(yytext, rcp - yytext);
E 8
I 8
		ryylval = (int)savestr(strtext, rcp - strtext);
E 8
		STRLEN(((char *)ryylval)) -= 1;
E 10
I 10
		putc(0, strfile);
D 12
		strd.sd_strlen += 1;
		strfilepos += strd.sd_strlen;
		ryylval = (int)savestr(strtext, &strd);
E 12
I 12
		ryylval = (int)savestr((char *)0, strlg + 1, STR_FILE);
		val = STRING;
E 12
		((struct strdesc *)ryylval)->sd_strlen -= 1;
E 10
		goto ret;
E 7

	case BADCHAR:
		linescrossed = lineno;
		lineno = scanlineno;
		yyerror("Illegal character mapped: %d, char read:(octal) %o",
			ryylval, ch);
		lineno = linescrossed;
		val = BADCHAR;
		goto ret;

	default:
		val = ryylval;
		goto ret;
	}	/*end of the switch*/
	/*
	 *	here with one token, so stuff it
	 */
   ret:	
	oval = val;
	ptoken(bufptr, val);
	switch(val){
		case	ILINESKIP:
				pint(bufptr, ryylval);
				break;
		case	SIZESPEC:
				pchar(bufptr, ryylval);
				break;
		case	BFINT:	plong(bufptr, ryylval);
				break;
		case	INT:	plong(bufptr, ryylval);
				break;
		case 	BIGNUM:	pnumber(bufptr, yybignum);
I 7
				break;
		case	STRING:	pptr(bufptr, (int)(char *)ryylval);
E 7
				break;
		case	NAME:	pptr(bufptr, (int)(struct symtab *)ryylval);
				break;
		case	REG:	pchar(bufptr, ryylval);
				break;	
		case	INST0:
		case	INSTn:
				popcode(bufptr, opstruct);
				break;
		case 	IJXXX:
				popcode(bufptr, opstruct);
				pptr(bufptr, (int)(struct symtab *)symalloc());
				break;
		case	ISTAB:
		case	ISTABSTR:
		case	ISTABNONE:
		case	ISTABDOT:
		case	IALIGN:
				pptr(bufptr, (int)(struct symtab *)symalloc());
				break;
	/*
	 *	default:
	 */
	 }
	 builtval: ;
   }			/*end of the while to stuff the buffer*/
   done:
	bufferbox->tok_count = (bytetoktype *)bufptr - &(bufferbox->toks[0]);
D 9

E 9
	/*
	 *	This is a real kludge:
	 *
	 *	We put the last token in the buffer to be  a MINUS
	 *	symbol.  This last token will never be picked up
	 *	in the normal way, but can be looked at during
	 *	a peekahead look that the short circuit expression
	 *	evaluator uses to see if an expression is complicated.
	 *
	 *	Consider the following situation:
	 *
	 *	.word	45		+	47
	 *        buffer 1      |  buffer 0
	 *	the peekahead would want to look across the buffer,
	 *	but will look in the buffer end zone, see the minus, and
	 *	fail.
	 */
	ptoken(bufptr, MINUS);
D 9
	InBufPtr = inbufptr;		/*copy this back*/
E 9
I 9
	REGTOMEMBUF;
E 9
}
E 1
