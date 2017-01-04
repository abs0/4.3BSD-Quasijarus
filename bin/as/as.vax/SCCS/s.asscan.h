h26952
s 00006/00002/00084
d D 5.1 85/04/30 14:05:39 dist 10 9
c Add copyright
e
s 00000/00008/00086
d D 4.9 83/06/30 19:03:49 rrh 9 8
c The string pool is maintained both in core, and in a second tmp file.
c names are in core and on the file; strings are just in the file.  The file 
c is maintained as a string table per a.out(5), and tacked onto the a.out file
c at the very end.  The string table has more than need be, since discarde 
c labels and .ascii strings find their way (harmlessly) into the string table.
c the string file maintained with stdio; nothing fancy, even if -V set
e
s 00009/00026/00085
d D 4.8 83/06/29 20:07:13 rrh 8 7
c DQ quoted strings no longer put into the temp file, but stored
c directly into the string spool; this fixes serious efficiency/size bugs
c in the temp files. DQ strings put into string pool with preceding 2 bytes
c indicating the length, with a trailing null byte not accounted for in the
c 2byte length; .asciz and .stabs change length and magically get null byte;
c all string moves (lookup and reader) done by subroutine call & movc3
e
s 00001/00001/00110
d D 4.7 83/03/13 15:04:40 linton 7 6
c bumped up maximum string size to 4000
e
s 00001/00001/00110
d D 4.6 82/12/15 04:44:02 linton 6 5
c last fix curdled @(#) stuff, fixed it
e
s 00005/00005/00106
d D 4.5 82/12/15 04:39:46 linton 5 4
c changed to handle longer string constants
e
s 00018/00013/00093
d D 4.4 82/02/14 16:36:05 rrh 4 3
c Fix reported and outstanding bugs. Reformat some text for
c readability/understandability. Assembles new instructions  for G and H
c format floating numbers & new queue instructions
c asscan.c split into 4 files; two additional files to construct and
c manipulate G and H format numbers, with analog for atof()
c Numerical accuracy of new atof() not verified; standard atof() used
c for F and D floating numbers.  As does NOT use G and H instructions itself
e
s 00000/00000/00106
d D 4.3 80/08/15 18:04:23 henry 3 2
c use struct nlist; change field names; vgrind format fixes
e
s 00003/00003/00103
d D 4.2 80/08/15 12:32:44 henry 2 1
c Fixing vgrind formatting glitches
e
s 00106/00000/00000
d D 4.1 80/08/13 18:55:53 bill 1 0
c date and time created 80/08/13 18:55:53 by bill
e
u
U
t
T
I 1
D 4
/* Copyright (c) 1980 Regents of the University of California */
/* "%Z%%M% %I% %G%" */
E 4
/*
I 4
D 10
 *	Copyright (c) 1982 Regents of the University of California
D 5
 *	%Z%%M% %I% %G%
E 5
I 5
D 6
 *	@(#)asscan.h 4.4 2/14/82
E 6
I 6
 *	%Z%%M% %I% %G%
E 10
I 10
 * Copyright (c) 1982 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
E 10
E 6
E 5
 */
I 10

E 10
/*
E 4
 *	The character scanner is called to fill up one token buffer
 *
 *	However, once the tokens are filled up by the
 *	character scanner, they are used in both the first and the second
 *	pass.  Holes created by .stab removal are replaced
 *	with 'skip' tokens that direct the second pass to ignore the
 *	following tokens.
 */

D 5
#define TOKBUFLG		BUFSIZ
E 5
I 5
#define TOKBUFLG		4096
E 5
#define MAXVAX			32		
#define SAFETY			16

#define AVAILTOKS		TOKBUFLG -\
		sizeof(int) -\
		sizeof (struct tokbufdesc *) -\
		MAXVAX - SAFETY

struct tokbufdesc{
	int		tok_count;		/*absolute byte length*/
	struct		tokbufdesc *tok_next;
	char		toks[AVAILTOKS];
	char		bufovf[MAXVAX + SAFETY];
};
/*
 *	Definitions for handling tokens in the intermediate file
 *	buffers.
 *
 *	We want to have the compiler produce the efficient auto increment
 *	instruction for stepping through the buffer of tokens.  We must
 *	fool the type checker into thinking that a pointer can point
 *	to various size things.
 */

D 4
typedef char toktype;
E 4
I 4
typedef int inttoktype;
typedef char bytetoktype;
E 4

typedef char *ptrall;			/*all uses will be type cast*/
D 8
typedef short lgtype;			/*for storing length of strings or skiping*/
E 8
I 8
typedef u_short lgtype;			/*for storing length of strings or skiping*/
E 8
/*
 *	defintions for putting various typed values
 *	into the intermediate buffers
 *	ptr will ALWAYS be of type ptrall
 */

#define	pchar(ptr,val)		*ptr++  = val
#define	puchar(ptr,val)		*ptr++  = val

#define	pshort(ptr,val)		*(short *)ptr=val,	ptr += sizeof(short)
I 8
#define	plgtype(ptr,val)	*(lgtype *)ptr=val,	ptr += sizeof(lgtype)
E 8
D 2
#define	pushort(ptr,val)	*(unsigned short *)ptr=val, ptr += sizeof(short)
E 2
I 2
D 4
#define	pushort(ptr,val)	*(unsigned short *)ptr=val,	ptr += sizeof(short)
E 4
I 4
#define	pushort(ptr,val)	*(u_short *)ptr=val,	ptr += sizeof(short)
E 4
E 2
#define	pint(ptr,val)		*(int *)ptr  = val,	ptr += sizeof(int)
D 2
#define	puint(ptr,val)		*(unsigned int *)ptr=val, ptr += sizeof(int)
E 2
I 2
D 4
#define	puint(ptr,val)		*(unsigned int *)ptr=val,	ptr += sizeof(int)
E 4
I 4
#define	puint(ptr,val)		*(u_int int *)ptr=val,	ptr += sizeof(int)
E 4
E 2
#define	plong(ptr,val)		*(long *)ptr  = val,	ptr += sizeof(long)
D 2
#define	pulong(ptr,val)		*(unsigned long *)ptr=val,ptr += sizeof(long)
E 2
I 2
D 4
#define	pulong(ptr,val)		*(unsigned long *)ptr=val,	ptr += sizeof(long)
E 2
#define	pfloat(ptr,val)		*(float *)ptr  = val,	ptr += sizeof (float)
#define	pdouble(ptr,val)	*(double *)ptr  = val,	ptr += sizeof (double)
E 4
I 4
#define	pulong(ptr,val)		*(u_int long *)ptr=val,	ptr += sizeof(long)
#define	pnumber(ptr,val)	*(Bignum*)ptr=val,	ptr += sizeof(Bignum)
#define	popcode(ptr,val)	*(struct Opcode*)ptr=val,	ptr += sizeof(struct Opcode)

E 4
#define	pptr(ptr,val)		*(int *)ptr  = (val),	ptr += sizeof(ptrall)
#define	ptoken(ptr,val)		*ptr++  = val
D 8
#define	pstrlg(ptr,val)		*(lgtype *)ptr  = val,	ptr += sizeof(short)
E 8
#define	pskiplg(ptr,val)	*(lgtype *)ptr  = val,	ptr += sizeof(short)

#define	gchar(val, ptr)		val = *ptr++
#define	guchar(val, ptr)	val = *ptr++

#define	gshort(val, ptr)	val = *(short *)ptr , ptr += sizeof (short)
I 8
#define	glgtype(val, ptr)	val = *(lgtype *)ptr , ptr += sizeof (lgtype)
E 8
D 4
#define	gushort(val, ptr)	val = *(unsigned short *)ptr , ptr += sizeof (short)
E 4
I 4
#define	gushort(val, ptr)	val = *(u_short *)ptr , ptr += sizeof (short)
E 4
#define	gint(val, ptr)		val = *(int *)ptr, ptr += sizeof (int)
D 4
#define	guint(val, ptr)		val = *(unsigend int *)ptr, ptr += sizeof (int)
E 4
I 4
#define	guint(val, ptr)		val = *(u_int *)ptr, ptr += sizeof (int)
E 4
#define	glong(val, ptr)		val = *(long *)ptr, ptr += sizeof (long)
D 4
#define	gulong(val, ptr)	val = *(unsigned long *)ptr, ptr += sizeof (long)
#define	gfloat(val, ptr)	val = *(float *)ptr, ptr += sizeof (float)
#define	gdouble(val, ptr)	val = *(double *)ptr, ptr += sizeof (double)
E 4
I 4
#define	gulong(val, ptr)	val = *(u_int *)ptr, ptr += sizeof (long)
#define	gnumber(val, ptr)	val = *(Bignum *)ptr, ptr += sizeof(Bignum)
#define	gopcode(val, ptr)	val = *(struct Opcode *)ptr, ptr += sizeof(struct Opcode)

E 4
#define	gptr(val, ptr)		val = *(int *)ptr, ptr += sizeof (ptrall)
#define	gtoken(val, ptr)	val = *ptr++
D 8
#define	gstrlg(val, ptr)	val = *(lgtype *)ptr, ptr += sizeof (short)
E 8
#define	gskiplg(val, ptr)	val = *(lgtype *)ptr, ptr += sizeof (short)

D 8

E 8
extern	ptrall tokptr;	/*the next token to consume, call by copy*/
extern	ptrall tokub;	/*current upper bound in the current buffer*/
D 8

E 8
D 9
/*
D 8
 *	Strings are known for their characters and for their length.
 *	We cannot use a normal zero termination byte, because strings
 *	can contain anything.
 *
 *	We have two "strings", so that an input string that is too long can be
 *	split across two string buffers, and not confuse the yacc grammar.
 *	(This is probably superflous)
 *
 *	We have a third string of nulls so that the .skip can be 
 *	handled in the same way as strings.
E 8
I 8
 *	Strings are stored in the string pool; see strsave(str, length)
 *	Strings are known by their length and values.
 *	A string pointer points to the beginning of the value bytes;
 *	the preceding two bytes are the length.
E 8
 */
D 5
#define MAXSTRLG	127
E 5
I 5
D 7
#define MAXSTRLG	2048
E 7
I 7
D 8
#define MAXSTRLG	4000
E 7
E 5

D 5
struct strdesc{
	char		str_lg;
E 5
I 5
struct strdesc {
	unsigned short	str_lg;
E 5
	char		str[MAXSTRLG];
};

extern	struct 	strdesc		strbuf[3];
extern	struct 	strdesc		*strptr;	/*points to the current string*/
extern	int			strno;		/*the current string being filled*/
char	*savestr();
E 8
I 8
#define	STRLEN(str)	(((lgtype *)str)[-1])
char *savestr();
E 9
E 8
E 1
