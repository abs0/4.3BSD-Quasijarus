h21551
s 00005/00002/00325
d D 5.1 85/04/30 14:15:06 dist 7 6
c Add copyright
e
s 00010/00004/00317
d D 4.6 83/07/06 18:18:09 rrh 6 5
c fixed bug with debug only printing of STRINGs
e
s 00009/00008/00312
d D 4.5 83/06/30 19:03:20 rrh 5 4
c The string pool is maintained both in core, and in a second tmp file.
c names are in core and on the file; strings are just in the file.  The file 
c is maintained as a string table per a.out(5), and tacked onto the a.out file
c at the very end.  The string table has more than need be, since discarde 
c labels and .ascii strings find their way (harmlessly) into the string table.
c the string file maintained with stdio; nothing fancy, even if -V set
e
s 00017/00018/00303
d D 4.4 83/06/29 20:06:51 rrh 4 3
c DQ quoted strings no longer put into the temp file, but stored
c directly into the string spool; this fixes serious efficiency/size bugs
c in the temp files. DQ strings put into string pool with preceding 2 bytes
c indicating the length, with a trailing null byte not accounted for in the
c 2byte length; .asciz and .stabs change length and magically get null byte;
c all string moves (lookup and reader) done by subroutine call & movc3
e
s 00000/00000/00321
d D 4.3 82/02/14 16:36:28 rrh 3 2
c Fix reported and outstanding bugs. Reformat some text for
c readability/understandability. Assembles new instructions  for G and H
c format floating numbers & new queue instructions
c asscan.c split into 4 files; two additional files to construct and
c manipulate G and H format numbers, with analog for atof()
c Numerical accuracy of new atof() not verified; standard atof() used
c for F and D floating numbers.  As does NOT use G and H instructions itself
e
s 00000/00000/00321
d D 4.2 82/02/14 16:14:38 rrh 2 1
c Synchronizing this new file to release 4.2
e
s 00321/00000/00000
d D 4.1 82/02/14 16:11:00 rrh 1 0
c date and time created 82/02/14 16:11:00 by rrh
e
u
U
t
T
I 1
/*
D 7
 *	Copyright (c) 1982 Regents of the University of California
E 7
I 7
 * Copyright (c) 1982 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 7
 */
I 7

E 7
#ifndef lint
D 7
static char sccsid[] = "%Z%%M% %I% %G%";
E 7
I 7
static char sccsid[] = "%W% (Berkeley) %G%";
E 7
#endif not lint

#include "asscanl.h"

D 5
inittmpfile()
E 5
I 5
inittokfile()
E 5
{
	if (passno == 1){
		if (useVM){
			bufstart = &tokbuf[0];
			buftail = &tokbuf[1];
			bufstart->tok_next = buftail;
			buftail->tok_next = 0;
		}
		tokbuf[0].tok_count = -1;
		tokbuf[1].tok_count = -1;
	}
	tok_temp = 0;
	tok_free = 0;
	bufno = 0;
	emptybuf = &tokbuf[bufno];
	tokptr = 0;
	tokub = 0;
}

D 5
closetmpfile()
E 5
I 5
closetokfile()
E 5
{
	if (passno == 1){
		if (useVM){
			emptybuf->toks[emptybuf->tok_count++] = PARSEEOF;
		} else {
			/*
			 *	Clean up the buffers that haven't been
			 *	written out yet
			 */
			if (tokbuf[bufno ^ 1].tok_count >= 0){
D 5
				if (writeTEST((char *)&tokbuf[bufno ^ 1], sizeof *emptybuf, 1, tmpfil)){
E 5
I 5
				if (writeTEST((char *)&tokbuf[bufno ^ 1], sizeof *emptybuf, 1, tokfile)){
E 5
				  badwrite:
					yyerror("Unexpected end of file writing the interpass tmp file");
				exit(2);
				}
			}
			/*
			 *	Ensure that we will read an End of file,
			 *	if there are more than one file names
			 *	in the argument list
			 */
			tokbuf[bufno].toks[tokbuf[bufno].tok_count++] = PARSEEOF;
D 5
			if (writeTEST((char *)&tokbuf[bufno], sizeof *emptybuf, 1, tmpfil))
E 5
I 5
			if (writeTEST((char *)&tokbuf[bufno], sizeof *emptybuf, 1, tokfile))
E 5
				goto badwrite;
		}
	}	/*end of being pass 1*/
}

inttoktype yylex()
{
	register	ptrall	bufptr;	
	register	inttoktype		val;	
	register	struct	exp	*locxp;
	/*
	 *	No local variables to be allocated; this saves
	 *	one piddling instruction..
	 */
	static	int	Lastjxxx;

	bufptr = tokptr;		/*copy in the global value*/
   top:
	if (bufptr < tokub){
		gtoken(val, bufptr);
		switch(yylval = val){
		case	PARSEEOF:
				yylval = val = PARSEEOF;
				break;
		case	BFINT:
		case	INT:
				if (xp >= &explist[NEXP])
				     yyerror("Too many expressions; try simplyfing");
				else
				    locxp = xp++;
				locxp->e_number = Znumber;
				locxp->e_number.num_tag = TYPL;
				glong(locxp->e_xvalue, bufptr);
			  makevalue:
				locxp->e_xtype = XABS;
				locxp->e_xloc = 0;
				locxp->e_xname = NULL;
				yylval = (int)locxp;
				break;
		case	BIGNUM:	
				if (xp >= &explist[NEXP])
				     yyerror("Too many expressions; try simplyfing");
				else
				    locxp = xp++;
				gnumber(locxp->e_number, bufptr);
				goto makevalue;
		case	NAME:
				gptr(yylval, bufptr);
				lastnam = (struct symtab *)yylval;
				break;
		case	SIZESPEC:
		case 	REG:
				gchar(yylval, bufptr);
				break;
		case	INSTn:
		case	INST0:
				gopcode(yyopcode, bufptr);
				break;
		case	IJXXX:
				gopcode(yyopcode, bufptr);
				/* We can't cast Lastjxxx into (int *) here.. */
				gptr(Lastjxxx, bufptr);
				lastjxxx = (struct symtab *)Lastjxxx;
				break;
		case	ILINESKIP:
				gint(yylval, bufptr);
				lineno += yylval;
				goto top;
		case	SKIP:	
				eatskiplg(bufptr);
				goto top;
		case	VOID:	
				goto top;
		case 	STRING:
D 4
				strptr = &strbuf[strno ^= 1];
				strptr->str_lg = *((lgtype *)bufptr);
				movestr(&strptr->str[0],
					(char *)bufptr + sizeof(lgtype),
					strptr->str_lg);
				eatstrlg(bufptr);
				yylval = (int)strptr;
				break;
E 4
		case 	ISTAB:
		case	ISTABSTR:
		case	ISTABNONE:
		case	ISTABDOT:
		case	IALIGN:
				gptr(yylval, bufptr);
				break;
		} 
#ifdef DEBUG
		if (toktrace){
		char	*tok_to_name();
		printf("P: %d T#: %4d, %s ",
			passno, bufptr -  firsttoken, tok_to_name(val));
		switch(val){
		case 	INT:	printf("val %d",
					((struct exp *)yylval)->e_xvalue);
				break;
		case	BFINT:	printf("val %d",
					((struct exp *)yylval)->e_xvalue);
				break;
		case 	BIGNUM: bignumprint(((struct exp*)yylval)->e_number);
				break;
		case	NAME:	printf("\"%.8s\"",
D 5
					((struct symtab *)yylval)->s_name);
E 5
I 5
					FETCHNAME((struct symtab *)yylval));
E 5
				break;
		case	REG:	printf(" r%d",
					yylval);
				break;
		case	IJXXX:
		case	INST0:	
		case	INSTn:	if (ITABCHECK(yyopcode))
D 5
					printf("%.8s", ITABFETCH(yyopcode)->s_name);
E 5
I 5
					printf("%.8s",
						FETCHNAME(ITABFETCH(yyopcode)));
E 5
				else
					printf("IJXXX or INST0 or INSTn can't get into the itab\n");
				break;
D 4
		case	STRING:	printf("length %d ",
					((struct strdesc *)yylval)->str_lg);
				printf("value\"%s\"",
					((struct strdesc *)yylval)->str);
E 4
I 4
D 6
		case	STRING:	printf("length %d ", ((u_short *)yylval)[-1]);
E 6
I 6
		case	STRING:
			printf("length %d, seekoffset %d, place 0%o ",
				((struct strdesc *)yylval)->sd_strlen,
				((struct strdesc *)yylval)->sd_stroff,
				((struct strdesc *)yylval)->sd_place
				);
			if (((struct strdesc *)yylval)->sd_place & STR_CORE)
E 6
				printf("value\"%*s\"",
D 6
					((u_short *)yylval)[-1],
					(char *)yylval);
E 4
				break;
E 6
I 6
					((struct strdesc *)yylval)->sd_strlen,
					((struct strdesc *)yylval)->sd_string);
			break;
E 6
		}  		/*end of the debug switch*/
		printf("\n");
		}
#endif DEBUG

	} else {	/* start a new buffer */
	    if (useVM){
		if (passno == 2){
			tok_temp = emptybuf->tok_next;
			emptybuf->tok_next = tok_free;
			tok_free = emptybuf;
			emptybuf = tok_temp;
		} else {
			emptybuf = emptybuf->tok_next;
		}
		bufno += 1;
		if (emptybuf == 0){
			struct	tokbufdesc *newdallop;
			int	i;
			if (passno == 2)
				goto badread;
			emptybuf = newdallop = (struct tokbufdesc *)
			  Calloc(TOKDALLOP, sizeof (struct tokbufdesc));
			for (i=0; i < TOKDALLOP; i++){
				buftail->tok_next = newdallop;
				buftail = newdallop;
				newdallop += 1;
			}
			buftail->tok_next = 0;
		}	/*end of need to get more buffers*/
		(bytetoktype *)bufptr = &(emptybuf->toks[0]);
		if (passno == 1)
			scan_dot_s(emptybuf);
	    } else {	/*don't use VM*/
		bufno ^= 1;
		emptybuf = &tokbuf[bufno];
		((bytetoktype *)bufptr) = &(emptybuf->toks[0]);
		if (passno == 1){
			/*
			 *	First check if there are things to write
			 *	out at all
			 */
			if (emptybuf->tok_count >= 0){
D 5
			    if (writeTEST((char *)emptybuf, sizeof *emptybuf, 1, tmpfil)){
E 5
I 5
			    if (writeTEST((char *)emptybuf, sizeof *emptybuf, 1, tokfile)){
E 5
				yyerror("Unexpected end of file writing the interpass tmp file");
				exit(2);
			    }
			}
			scan_dot_s(emptybuf);
		} else {	/*pass 2*/
D 5
		    if (readTEST((char *)emptybuf, sizeof *emptybuf, 1, tmpfil)){
E 5
I 5
		    if (readTEST((char *)emptybuf, sizeof *emptybuf, 1, tokfile)){
E 5
			 badread:
			     yyerror("Unexpected end of file while reading the interpass tmp file");
			     exit(1);
		    }
		}
	    }	/*end of using a real live file*/
	    (char *)tokub = (char *)bufptr + emptybuf->tok_count;
#ifdef DEBUG
	    firsttoken = bufptr;
	    if (debug)
		printf("created buffernumber %d with %d tokens\n",
			bufno, emptybuf->tok_count);
#endif DEBUG
	    goto top;
	}	/*end of reading/creating a new buffer*/
	tokptr = bufptr;		/*copy back the global value*/
	return(val);
}	/*end of yylex*/


buildskip(from, to)
	register	ptrall	from, to;
{
	int	diff;
	register	struct	tokbufdesc *middlebuf;
	/*
	 *	check if from and to are in the same buffer
	 *	from and to DIFFER BY AT MOST 1 buffer and to is
	 *	always ahead of from, with to being in the buffer emptybuf
	 *	points to.
	 *	The hard part here is accounting for the case where the
	 *	skip is to cross a buffer boundary; we must construct
	 *	two skips.
	 *
	 *	Figure out where the buffer boundary between from and to is
	 *	It's easy in VM, as buffers increase to high memory, but
	 *	w/o VM, we alternate between two buffers, and want
	 *	to look at the exact middle of the contiguous buffer region.
	 */
	middlebuf = useVM ? emptybuf : &tokbuf[1];
	if (  ( (bytetoktype *)from > (bytetoktype *)middlebuf)
	    ^ ( (bytetoktype *)to > (bytetoktype *)middlebuf)
	   ){	/*split across a buffer boundary*/
		ptoken(from, SKIP);
		/*
		 *	Set the skip so it lands someplace beyond
		 *	the end of this buffer.
		 *	When we pull this skip out in the second pass,
		 *	we will temporarily move the current pointer
		 *	out beyond the end of the buffer, but immediately
		 *	do a compare and fail the compare, and then reset
		 *	all the pointers correctly to point into the next buffer.
		 */
		bskiplg(from,  TOKBUFLG + 1);
		/*
		 *	Now, force from to be in the same buffer as to
		 */
		(bytetoktype *)from = (bytetoktype *)&(emptybuf->toks[0]);
	}
	/*
	 *	Now, to and from are in the same buffer
	 */
	if (from > to)
		yyerror("Internal error: bad skip construction");
	else {
		if ( (diff = (bytetoktype *)to - (bytetoktype *)from) >= 
			(sizeof(bytetoktype) + sizeof(lgtype) + 1)) {
				ptoken(from, SKIP);
				bskipfromto(from, to);
		} else {
			for ( ; diff > 0; --diff)
				ptoken(from, VOID);
		}
	}
}

movestr(to, from, lg)
D 4
	register	char	*to, *from;
	register	int	lg;
E 4
I 4
	char	*to;	/* 4(ap) */ 
	char	*from;	/* 8(ap) */
	int	lg;	/* 12(ap) */
E 4
{
D 4
	if (lg <= 0) return;
	do
		*to++ = *from++;
	while (--lg);
E 4
I 4
	if (lg <= 0)
		return;
	;
	asm("movc3	12(ap),*8(ap),*4(ap)");
	;
E 4
}

new_dot_s(namep)
	char	*namep;
{
	newfflag = 1;
	newfname = namep;
	dotsname = namep;
	lineno = 1;
	scanlineno = 1;
I 4
}

min(a, b)
{
	return(a < b ? a : b);
E 4
}
E 1
