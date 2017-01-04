h48367
s 00006/00002/00125
d D 5.1 85/04/30 14:05:20 dist 6 5
c Add copyright
e
s 00029/00039/00098
d D 4.5 83/06/30 09:56:48 rrh 5 4
c assembly language source file reading now does end of buffer 
c detection on a per character basis, not  on a per line basis, thereby 
c simplifying the monkey business with reading lines in asscan2.c; slight 
c execution penalty
e
s 00000/00009/00137
d D 4.4 83/06/29 20:06:47 rrh 4 3
c DQ quoted strings no longer put into the temp file, but stored
c directly into the string spool; this fixes serious efficiency/size bugs
c in the temp files. DQ strings put into string pool with preceding 2 bytes
c indicating the length, with a trailing null byte not accounted for in the
c 2byte length; .asciz and .stabs change length and magically get null byte;
c all string moves (lookup and reader) done by subroutine call & movc3
e
s 00000/00000/00146
d D 4.3 82/02/14 16:36:23 rrh 3 2
c Fix reported and outstanding bugs. Reformat some text for
c readability/understandability. Assembles new instructions  for G and H
c format floating numbers & new queue instructions
c asscan.c split into 4 files; two additional files to construct and
c manipulate G and H format numbers, with analog for atof()
c Numerical accuracy of new atof() not verified; standard atof() used
c for F and D floating numbers.  As does NOT use G and H instructions itself
e
s 00000/00000/00146
d D 4.2 82/02/14 16:20:44 rrh 2 1
c Synchronizing this new file to release 4.2
e
s 00146/00000/00000
d D 4.1 82/02/14 16:20:09 rrh 1 0
c date and time created 82/02/14 16:20:09 by rrh
e
u
U
t
T
I 1
/*
D 6
 *	Copyright (c) 1982 Regents of the University of California
 *	%Z%%M% %I% %G%
E 6
I 6
 * Copyright (c) 1982 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
E 6
 */
I 6

E 6
/*
 *	This file contains definitions local to the files implementing
 *	the character scanner and the token buffer managers.
 *	It is not intended to be shared with any other parts of the
 *	assembler.
 *	The file ``asscan.h'' is shared with other parts of the assembler
 */
#include <stdio.h>
#include "as.h"
#include "asscan.h"
D 5
/*
 *	Maps characters to their use in assembly language
 */
#define EOFCHAR	(-1)
#define	NEEDCHAR (-2)
E 5

I 5
#define EOFCHAR	(-1)
E 5
/*
 *	The table of possible uses for each character to test set inclusion.
D 5
 *	Different than the above table, which knows about tokens yylex
 *	is to return.
E 5
 */
#define	HEXFLAG		01		/* 'x' or 'X' */
#define	HEXLDIGIT	02		/* 'a' .. 'f' */
#define	HEXUDIGIT	04		/* 'A' .. 'F' */
#define	ALPHA		010		/* 'A' .. 'Z', 'a' .. 'z', '_'*/
#define	DIGIT		020		/* '0' .. '9' */
#define	FLOATEXP	040		/* 'd' 'e' 'D' 'E' 'g' 'h' 'G' 'H' */
#define	SIGN		0100		/* '+' .. '-'*/
#define	REGDIGIT	0200		/* '0' .. '5' */
#define	SZSPECBEGIN	0400		/* 'b', 'B', 'l', 'L', 'w', 'W' */
#define	POINT		01000		/* '.' */
#define	SPACE		02000		/* '\t' or ' ' */
#define	BSESCAPE	04000		/* bnrtf */
#define	STRESCAPE	010000		/* '"', '\\', '\n' */
#define	OCTDIGIT	020000		/* '0' .. '7' */
#define	FLOATFLAG	040000		/* 'd', 'D', 'f', 'F' */

#define	INCHARSET(val, kind) (charsets[val] & (kind) )
D 5
#ifdef	getchar
#undef		getchar
#endif
#define	getchar() *inbufptr++

#ifdef	ungetc
#undef		ungetc
#endif
#define	ungetc(char) *--inbufptr = char

E 5
/*
D 5
 *	NOTE:
 *		This version of the assembler does not use fread and fwrite
 *	for the token buffering.  The token buffers are integrals of BUFSIZ
 *	at all times, so we use direct read and write.  fread and fwrite
 *	as supplied from BTL in stdio are HORRENDOUSLY inefficient,
 *	as they use putchar for each character, nested two deep in loops.
E 5
I 5
 *	We use our own version of getchar/ungetc to get
 *	some speed improvement
E 5
 */
D 5
#define writeTEST(pointer, size, nelements, ioptr) \
	write(ioptr->_file, pointer, nelements * size) != nelements * size

#define readTEST(pointer, size, nelements, ioptr) \
	read(ioptr->_file, pointer, nelements * size) != nelements * size
E 5
I 5
extern	char	*Ginbufptr;
extern	int	Ginbufcnt;
#define	REGTOMEMBUF	Ginbufptr = inbufptr, Ginbufcnt = inbufcnt
#define	MEMTOREGBUF	inbufptr = Ginbufptr, inbufcnt = Ginbufcnt
#undef getchar
#define	getchar() \
	(inbufcnt-- > 0 ? (*inbufptr++) : \
		(fillinbuffer(), \
		MEMTOREGBUF, \
		inbufptr[-1]))
#undef ungetc
#define ungetc(ch) \
	(++inbufcnt, *--inbufptr = ch)

E 5
/*
D 5
 *	Variables to manage the token buffering.
E 5
I 5
 *	Variables and definitions to manage the token buffering.
E 5
 *	We scan (lexically analyze) a large number of tokens, and
 *	then parse all of the tokens in the scan buffer.
 *	This reduces procedure call overhead when the parser
 *	demands a token, allows for an efficient reread during
 *	the second pass, and confuses the line number reporting
 *	for errors encountered in the scanner and in the parser.
 */
#define TOKDALLOP	8
struct	tokbufdesc *bufstart;	/*where the buffer list begins*/
struct	tokbufdesc *buftail;	/*last one on the list*/
struct	tokbufdesc *emptybuf;	/*the one being filled*/
/*
 *	If we are using VM, during the second pass we reclaim the used
 *	token buffers for saving the relocation information
 */
struct	tokbufdesc *tok_free;	/* free pool */
struct	tokbufdesc *tok_temp;	/* temporary for doing list manipulation */
/*
 *	Other token buffer managers
 */
int	bufno;			/*which buffer number: 0,1 for tmp file*/
struct 	tokbufdesc tokbuf[2];	/*our initial increment of buffers*/
ptrall	tokptr;			/*where the current token comes from*/
ptrall	tokub;			/*the last token in the current token buffer*/
I 5
/*
 *	as does not use fread and fwrite for the token buffering.
 *	The token buffers are integrals of BUFSIZ
 *	at all times, so we use direct read and write.
 *	fread and fwrite in stdio are HORRENDOUSLY inefficient,
 *	as they use putchar for each character, nested two deep in loops.
 */
#define writeTEST(pointer, size, nelements, ioptr) \
	write(ioptr->_file, pointer, nelements * size) != nelements * size
E 5

D 4
/*
 *	Variables to manage the string buffering
 *	declared in asscan.h.
 */
int	strno;			/*the current string being filled*/
struct	strdesc	strbuf[3];	/*the string buffers; the first for nulls*/
struct	strdesc	*strptr;	/*current string buffer being filled*/
	

E 4
D 5
#define bstrlg(from, length) \
	*(lgtype *)from = length; \
	(bytetoktype *)from += sizeof(lgtype) + length 

#define bstrfromto(from,to) \
	*(lgtype *)from = (bytetoktype *)to - (bytetoktype *)from - sizeof(lgtype); \
	(bytetoktype *)from += sizeof(lgtype) + (bytetoktype *)to - (bytetoktype *)from

#define eatstrlg(from) \
	(bytetoktype *)from +=  sizeof(lgtype) + *(lgtype *)from
E 5
I 5
#define readTEST(pointer, size, nelements, ioptr) \
	read(ioptr->_file, pointer, nelements * size) != nelements * size
E 5

#define bskiplg(from, length) \
	*(lgtype *)from = length; \
	(bytetoktype *)from += sizeof(lgtype) + length

#define bskipfromto(from, to) \
	*(lgtype *)from = (bytetoktype *)to - (bytetoktype *)from - sizeof(lgtype); \
	(bytetoktype *)from += sizeof (lgtype) + (bytetoktype *)to - (bytetoktype *)from

#define eatskiplg(from) \
	(bytetoktype *)from += sizeof(lgtype) + *(lgtype *)from

#ifdef DEBUG
	ptrall	firsttoken;
#endif DEBUG

/*
 *	The following three variables are the slots for global
 *	communication with the parser.
 *	They are the semantic values associated with a particular token.
 *	The token itself is the return value from yylex()
 */
int	yylval;			/* normal semantic value */
Bignum	yybignum;		/* a big number */
struct	Opcode	yyopcode;	/* a structure opcode */

int	newfflag;
char	*newfname;
int	scanlineno;		/*the scanner's linenumber*/

/*
 *	Definitions for sets of characters
 */
readonly short charsets[];
readonly short type[];
E 1
