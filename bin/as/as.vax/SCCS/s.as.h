h21818
s 00001/00007/00502
d D 5.5 03/11/08 22:33:59 msokolov 28 27
c bring back -d124, without affecting 3-way relaxing of branches
e
s 00008/00003/00501
d D 5.4 00/08/29 22:10:39 msokolov 27 26
c Complete jxxx relaxation overhaul. We now relax three-way without -J!
c -J is now ignored. We now also relax SOBs, AOBs, and ACBs. See the comments in
c addsob() in c2 for the motivation.
c As a side effect, we now require -d4.
c As yet another side effect, the handling of branches in instrs has been
c significantly cleaned up for c2.
e
s 00001/00001/00503
d D 5.3 85/07/06 11:29:44 bloom 26 25
c allow for longer temporary file names
e
s 00001/00001/00503
d D 5.2 85/06/19 16:41:40 mckusick 25 24
c NBPW changed to NBWD to avoid conflict in param.h
e
s 00006/00002/00498
d D 5.1 85/04/24 12:11:33 dist 24 23
c Add copyright
e
s 00002/00001/00498
d D 4.22 84/02/17 15:38:10 ralph 23 22
c use optimal block size.
e
s 00001/00000/00498
d D 4.21 83/11/21 14:43:46 rrh 22 21
c -a flag allows alignment to be specified; defaults to 2
e
s 00001/00001/00497
d D 4.20 83/10/14 16:37:24 ralph 21 20
c fixed debugging info and phase error message for label defs.
e
s 00001/00000/00497
d D 4.19 83/08/11 10:58:28 rrh 20 19
c Add a macro for STRPLACE, just like STROFF
e
s 00003/00013/00494
d D 4.18 83/07/01 09:46:53 rrh 19 18
c remove manifest constants for NCPString and ASINBUFSIZ, reflecting
c the fact that arbitrary length strings are stored in a file
e
s 00007/00030/00500
d D 4.17 83/06/30 19:20:09 rrh 18 17
c bye bye fixed names (eg, FLEXNAMES is not set)
e
s 00000/00043/00530
d D 4.16 83/06/30 19:12:03 rrh 17 16
c bye bye VMS: UNIX only.  All the preceeding changes to the symbol
c table stuff were never tested under VMS
e
s 00038/00003/00535
d D 4.15 83/06/30 19:03:28 rrh 16 15
c The string pool is maintained both in core, and in a second tmp file.
c names are in core and on the file; strings are just in the file.  The file 
c is maintained as a string table per a.out(5), and tacked onto the a.out file
c at the very end.  The string table has more than need be, since discarde 
c labels and .ascii strings find their way (harmlessly) into the string table.
c the string file maintained with stdio; nothing fancy, even if -V set
e
s 00001/00001/00537
d D 4.14 83/06/30 09:57:15 rrh 15 14
c assembly language source file reading now does end of buffer 
c detection on a per character basis, not  on a per line basis, thereby 
c simplifying the monkey business with reading lines in asscan2.c; slight 
c execution penalty
e
s 00043/00016/00495
d D 4.13 83/06/30 07:59:07 rrh 14 13
c consolidate character buffer length definitions (manifest constants)
c into one place, with documentation
e
s 00000/00004/00511
d D 4.12 83/06/10 23:36:34 sam 13 12
c no more pagsiz.h
e
s 00001/00001/00514
d D 4.11 82/12/15 04:43:39 linton 12 11
c last fix curdled @(#) stuff, fixed it
e
s 00002/00002/00513
d D 4.10 82/12/15 04:39:33 linton 11 10
c changed to handle longer string constants
e
s 00120/00081/00395
d D 4.9 82/02/14 16:35:27 rrh 10 9
c Fix reported and outstanding bugs. Reformat some text for
c readability/understandability. Assembles new instructions  for G and H
c format floating numbers & new queue instructions
c asscan.c split into 4 files; two additional files to construct and
c manipulate G and H format numbers, with analog for atof()
c Numerical accuracy of new atof() not verified; standard atof() used
c for F and D floating numbers.  As does NOT use G and H instructions itself
e
s 00005/00002/00471
d D 4.8 80/11/05 20:13:10 henry 9 8
c Fixing so that can compile with FLEXNAMES turned off
e
s 00025/00016/00448
d D 4.7 80/08/20 09:49:05 henry 8 7
c Catch relocation of floats and 8 byte qtys; restructure outrel
e
s 00008/00006/00456
d D 4.6 80/08/19 14:40:43 henry 7 6
c Readable version of argument access types and mask
e
s 00001/00000/00461
d D 4.5 80/08/16 14:57:03 bill 6 5
c -R
e
s 00001/00000/00460
d D 4.4 80/08/15 18:33:46 henry 5 4
c -J option: use jmp instead of brw for jxxx resolution
e
s 00106/00046/00354
d D 4.3 80/08/15 18:04:11 henry 4 3
c use struct nlist; change field names; vgrind format fixes
e
s 00032/00032/00368
d D 4.2 80/08/15 12:29:01 henry 3 1
c Fixing vgrind format glitches
e
s 00000/00000/00400
d R 4.2 80/08/13 18:58:56 bill 2 1
c hello
e
s 00400/00000/00000
d D 4.1 80/08/13 18:55:50 bill 1 0
c date and time created 80/08/13 18:55:50 by bill
e
u
U
t
T
I 1
D 10
/* Copyright (c) 1980 Regents of the University of California */
/* "%Z%%M% %I% %G%" */
E 10
I 10
/*
D 24
 *	Copyright (c) 1982 Regents of the University of California
D 11
 *	%Z%%M% %I% %G%
E 11
I 11
D 12
 *	@(#)as.h 4.9 2/14/82
E 12
I 12
 *	%Z%%M% %I% %G%
E 24
I 24
 * Copyright (c) 1982 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
E 24
E 12
E 11
 */
I 24

E 24
E 10
D 17
#ifdef VMS
# define	vax	1
# define	VAX	1
#endif VMS

E 17
I 10
#define	reg	register

E 10
D 4
#define readonly
E 4
I 4
#include <sys/types.h>
D 17
#ifdef UNIX
E 4

E 17
I 4
D 18
#ifdef FLEXNAMES
#  include <a.out.h>
#  include <stab.h>
#else not FLEXNAMES
D 9
#  include <olda.out.h>
E 9
I 9
#  define ONLIST
#  include "a.out.h"
E 9
#  include <stab.h>
#endif FLEXNAMES
E 18
I 18
#include <a.out.h>
#include <stab.h>
E 18

D 17
#endif UNIX 
#ifdef VMS

#ifdef UNIXDEVEL
#  include <a.out.h>
#else not UNIXDEVEL
#  include <aout.h>
#endif not UNIXDEVEL

#endif VMS

E 17
#define readonly
E 4
#define	NINST		300

#define	NEXP		20	/* max number of expr. terms per instruction */
#define	NARG		6	/* max number of args per instruction */
#define	NHASH		1103	/* hash table is dynamically extended */
D 3
#define TNAMESIZE	32	/* maximum length of temporary file names */
E 3
I 3
D 26
#define	TNAMESIZE	32	/* maximum length of temporary file names */
E 26
I 26
#define	TNAMESIZE	256	/* maximum length of temporary file names */
E 26
E 3
#define	NLOC		4	/* number of location ctrs */
I 14
/*
 *	Sizes for character buffers.
 *	what			size #define name	comments
 *
D 19
 *	source file reads	ASINBUFSIZ		integral of BUFSIZ
 *	string assembly		NCPString		large for .stabs
E 19
D 18
 *	name assembly		NCPName			depends on FLEXNAMES
E 18
I 18
 *	name assembly		NCPName	
E 18
D 19
 *	string save		STRPOOLDALLOP	
E 19
I 19
 *	name save		STRPOOLDALLOP	
E 19
 *
D 19
 *
 *	-source file reads should be integral of BUFSIZ for efficient reads
 *	-string saving is a simple first fit
E 19
I 19
 *	-name saving is a simple first fit
E 19
 */
D 19
#ifndef ASINBUFSIZ
#	define	ASINBUFSIZ	4096
#endif not ASINBUFSIZ
E 19
#ifndef STRPOOLDALLOP
#	define STRPOOLDALLOP	8192
#endif not STRPOOLDALLOP
D 19
#ifndef NCPString
#	define	NCPString	4080
#endif not NCPString
E 19
E 14

I 14
#define	NCPName	NCPS
E 14
D 17
#ifdef UNIX
E 17
D 14
# ifndef	FLEXNAMES
#	ifndef	NCPS
#		define	NCPS	8	/* number of characters per symbol*/
#	endif
# else
#	ifdef NCPS
#		undef	NCPS
#	endif
D 11
#	define	NCPS	BUFSIZ	/* needed to allocate yytext */
E 11
I 11
#	define	NCPS	4096	/* needed to allocate yytext */
E 11
# endif
E 14
I 14
D 18
# ifndef FLEXNAMES
#	ifndef NCPS
#		undef	NCPName
#		define	NCPName	8
#	endif not NCPS
# else FLEXNAMES
#	ifndef NCPS
#		undef	NCPName
#		define	NCPName	4096
#	endif not NCPS
# endif FLEXNAMES
E 18
I 18
#ifndef NCPS
#	undef	NCPName
#	define	NCPName	4096
#endif not NCPS
E 18
E 14
D 17
# endif UNIX

# ifdef VMS
D 14
# ifdef NCPS
#	undef	NCPS
# endif NCPS
#	define	NCPS	15
E 14
I 14
#	define	NCPName	15
E 14
# endif VMS

E 17
/*
I 14
 *	Check sizes, and compiler error if sizes botch
 */
D 15
#if ((ASINBUFSIZ < NCPString) || (ASINBUFSIZ < NCPName) || (STRPOOLDALLOP < NCPString) || (STRPOOLDALLOP < NCPName))
E 15
I 15
D 19
#if ((STRPOOLDALLOP < NCPString) || (STRPOOLDALLOP < NCPName))
E 19
I 19
#if STRPOOLDALLOP < NCPName
E 19
E 15
	$$$botch with definition sizes
#endif test botches
/*
E 14
 * Symbol types
 */
#define	XUNDEF	0x0
#define	XABS	0x2
#define	XTEXT	0x4
#define	XDATA	0x6
#define	XBSS	0x8

#define	XXTRN	0x1
#define	XTYPE	0x1E

#define	XFORW	0x20	/* Was forward-referenced when undefined */

#define	ERR	(-1)
D 25
#define	NBPW	32	/* Bits per word */
E 25
I 25
#define	NBWD	32	/* Bits per word */
E 25

#define	AMASK	017

/*
 * Actual argument syntax types
 */
D 3
#define AREG	1	/* %r */
#define ABASE	2	/* (%r) */
#define ADECR	3	/* -(%r) */
#define AINCR	4	/* (%r)+ */
#define ADISP	5	/* expr(%r) */
#define AEXP	6	/* expr */
#define AIMM	7	/* $ expr */
#define ASTAR	8	/* * */
#define AINDX	16	/* [%r] */
E 3
I 3
#define	AREG	1	/* %r */
#define	ABASE	2	/* (%r) */
#define	ADECR	3	/* -(%r) */
#define	AINCR	4	/* (%r)+ */
#define	ADISP	5	/* expr(%r) */
#define	AEXP	6	/* expr */
#define	AIMM	7	/* $ expr */
#define	ASTAR	8	/* * */
#define	AINDX	16	/* [%r] */
E 3
D 10

E 10
/*
D 10
 * Argument access types used to test validity of operands to operators
E 10
I 10
 *	Definitions for the things found in ``instrs''
E 10
 */
D 3
#define ACCA	(8<<3)	/* address only */
#define ACCR	(1<<3)	/* read */
#define ACCW	(2<<3)	/* write */
#define ACCM	(3<<3)	/* modify */
#define ACCB	(4<<3)	/* branch displacement */
#define ACCI	(5<<3)	/* XFC code */
E 3
I 3
D 7
#define	ACCA	(8<<3)	/* address only */
#define	ACCR	(1<<3)	/* read */
#define	ACCW	(2<<3)	/* write */
#define	ACCM	(3<<3)	/* modify */
#define	ACCB	(4<<3)	/* branch displacement */
#define	ACCI	(5<<3)	/* XFC code */
E 7
I 7
D 10
#define	ACCR	(1<<3)				/* read */
#define	ACCW	(2<<3)				/* write */
#define	ACCB	(4<<3)				/* branch displacement */
#define	ACCA	(8<<3)				/* address only */
#define	ACCM	(ACCR | ACCW)			/* modify */
#define	ACCI	(ACCB | ACCR)			/* XFC code */
E 10
I 10
#define	INSTTAB 1
#include "instrs.h"
E 10

D 8
#define AMASK	(ACCA | ACCR | ACCW | ACCB)	/* the mask */
E 8
I 8
D 10
#define ACCESSMASK	(ACCA | ACCR | ACCW | ACCB)	/* the mask */
E 8
E 7
E 3

E 10
/*
D 8
 * Argument data types
E 8
I 8
D 10
 *	Argument data types
 *	Also used to tell outrel what it is relocating
 *	(possibly in combination with RELOC_PCREL and TYPNONE)
E 10
I 10
 *	Tells outrel what it is relocating
 *	RELOC_PCREL is an implicit argument to outrel; it is or'ed in
 *	with a TYPX
E 10
E 8
 */
D 3
#define TYPB	0	/* byte */
#define TYPW	1	/* word */
#define TYPL	2	/* long */
#define TYPQ	3	/* quad */
#define TYPF	4	/* floating */
#define TYPD	5	/* double floating */
E 3
I 3
D 8
#define	TYPB	0	/* byte */
#define	TYPW	1	/* word */
#define	TYPL	2	/* long */
#define	TYPQ	3	/* quad */
#define	TYPF	4	/* floating */
#define	TYPD	5	/* double floating */
E 8
I 8
D 10
#define	TYPB		0	/* byte */
#define	TYPW		1	/* word */
#define	TYPL		2	/* long */
#define	TYPQ		3	/* quad */
#define	TYPF		4	/* floating */
#define	TYPD		5	/* double floating */
#define	TYPNONE		6	/* when nothing */
#define	RELOC_PCREL	8	/* implicit argument to outrel; ==> PCREL */
E 8
E 3

D 3
#define TYPMASK 7
E 3
I 3
#define	TYPMASK	7
E 3

E 10
I 10
#define	RELOC_PCREL	(1<<TYPLG)
E 10
D 8
/* reference types for loader */
E 8
I 8
/*
 *	reference types for loader
 */
E 8
D 3
#define PCREL 1
#define LEN1 2
#define LEN2 4
#define LEN4 6
#define LEN8 8
E 3
I 3
#define	PCREL	1
#define	LEN1	2
#define	LEN2	4
#define	LEN4	6
#define	LEN8	8
I 10
#define	LEN16	10
E 10
E 3
D 8
	/*
	 *	reflen table converts between LEN* and PCREL to numbers
	 *		of bytes.
	 *	lgreflen table is the lg base 2 of the values in reflen.
	 */
	extern	int	reflen[];	/* reference lengths */
D 3
	extern	int	lgrefltn[];	/* lg reference lengths */
E 3
I 3
	extern	int	lgreflen[];	/* lg reference lengths */
E 8
I 8

extern	int	reflen[];	/* {LEN*+PCREL} ==> number of bytes */
extern	int	lgreflen[];	/* {LEN*+PCREL} ==> lg number of bytes */
D 10
extern	int	len124[];	/* {1,2,4,8} ==> {LEN1, LEN2, LEN4, LEN8} */
extern	char	mod124[];	/* {1,2,4,8} ==> {bits to construct operands */
extern	int	type_124[];	/* {1,2,4,8} ==> {TYPB, TYPW, TYPL, TYPQ} */
extern	int	ty_NORELOC[];	/* {TYPB..TYPD} ==> {1 if relocation not OK */
extern	int	ty_LEN[];	/* {TYPB..TYPD} ==> {LEN1..LEN8} */
extern	int	ty_nbyte[];	/* {TYPB..TYPD} ==> {1,2,4,8} */
extern	int	ty_nlg[];	/* {TYPB..TYPD} ==> lg{1,2,4,8} */
E 10
I 10
extern	int	len124[];	/* {1,2,4,8,16} ==> {LEN1, LEN2, LEN4, LEN8} */
extern	char	mod124[];	/* {1,2,4,8,16} ==> {bits to construct operands */
extern	int	type_124[];	/* {1,2,4,8,16} ==> {TYPB,TYPW,TYPL,TYPQ,TYPO} */
extern	int	ty_NORELOC[];	/* {TYPB..TYPH} ==> {1 if relocation not OK */
extern	int	ty_float[];	/* {TYPB..TYPH} ==> {1 if floating number */
extern	int	ty_LEN[];	/* {TYPB..TYPH} ==> {LEN1..LEN16} */
extern	int	ty_nbyte[];	/* {TYPB..TYPH} ==> {1,2,4,8,16} */
extern	int	ty_nlg[];	/* {TYPB..TYPH} ==> lg{1,2,4,8,16} */
extern	char	*ty_string[];	/* {TYPB..TYPH} ==> printable */
E 10
E 8
E 3

#define	TMPC	7	
D 10
#define	HW	01
#define	FW	03
#define	DW	07
E 10
I 10
#define	HW	0x1
#define	FW	0x3
#define	DW	0x7
#define	OW	0xF
E 10

I 27
D 28
/*
 * We used to have a -d[124] switch to select the default displacement size. We
 * now require -d4. There used be to a global variable d124 containing the
 * switch setting. Now it's #defined to 4.
 */
#define	d124	4

E 28
E 27
D 13
#ifdef UNIX
#  include <pagsiz.h>
#endif UNIX

E 13
D 17
#ifdef VMS
#  define PAGRND	0x1FFL
#endif VMS

E 17
#define	round(x,y)	(((x)+(y)) & ~(y))

#define	STABTYPS	0340
D 3
#define STABFLAG	0200
E 3
I 3
#define	STABFLAG	0200
E 3

/*
 *	Follows are the definitions for the symbol table tags, which are
 *	all unsigned characters..
 *	High value tags are generated by the asembler for internal
 *	use.
 *	Low valued tags are the parser coded tokens the scanner returns.
 *	There are several pertinant bounds in this ordering:
 *		a)	Symbols greater than JXQUESTIONABLE
 *			are used by the jxxx bumper, indicating that
 *			the symbol table entry is a jxxx entry
 *			that has yet to be bumped.
 *		b)	Symbols greater than IGNOREBOUND are not
 *			bequeathed to the loader; they are truly
 *			for assembler internal use only.
 *		c)	Symbols greater than OKTOBUMP represent
 *			indices into the program text that should
 *			be changed in preceeding jumps or aligns
 *			must get turned into their long form.
 */

D 3
#define TAGMASK		0xFF
E 3
I 3
#define	TAGMASK		0xFF
E 3

#	define	JXACTIVE	0xFF	/*jxxx size unknown*/
#	define	JXNOTYET	0xFE	/*jxxx size known, but not yet expanded*/
#	define	JXALIGN		0xFD	/*align jxxx entry*/
#	define	JXINACTIVE	0xFC	/*jxxx size known and expanded*/

D 3
#define JXQUESTIONABLE		0xFB
E 3
I 3
#define	JXQUESTIONABLE		0xFB
E 3

#	define	JXTUNNEL	0xFA	/*jxxx that jumps to another*/
#	define	OBSOLETE	0xF9	/*erroneously entered symbol*/

#define	IGNOREBOUND	0xF8		/*symbols greater than this are ignored*/
#	define	STABFLOATING	0xF7
#	define	LABELID		0xF6

#define	OKTOBUMP	0xF5
#	define	STABFIXED	0xF4

/*
 *	astoks.h contains reserved word codings the parser should
 *	know about
 */
#include "astoks.h"

/*
 *	The structure for one symbol table entry.
 *	Symbol table entries are used for both user defined symbols,
 *	and symbol slots generated to create the jxxx jump from
 *	slots.
I 4
 *	Caution: the instructions are stored in a shorter version
 *	of the struct symtab, using all fields in sym_nm and
 *	tag.  The fields used in sym_nm are carefully redeclared
 *	in struct Instab and struct instab (see below).
 *	If struct nlist gets changed, then Instab and instab may
 *	have to be changed.
E 4
 */

D 4
#define symfirstfields	char	*name;	unsigned char tag, type

E 4
struct symtab{
D 4
		symfirstfields;
		short	___hole;
		char	ptype;		/*tag == NAME*/

#define		jxbump	ptype		/*tag == JX..., how far to expand*/

		char	other;		/*for stab info*/

 		short	desc;		/*tag == NAME*/

#define		jxfear	desc		/*how far needs to be bumped*/

		long	value;		/*address in the segment*/
		char	jxoveralign;	/*if a JXXX, jumped over an align*/
		short	index;		/*which segment*/
		struct	symtab *dest;	/*if JXXX, where going to*/
E 4
I 4
		struct	nlist	s_nm;
		u_char	s_tag;		/* assembler tag */
		u_char	s_ptype;	/* if tag == NAME */
		u_char	s_jxoveralign;	/* if a JXXX, jumped over align */
		short	s_index;	/* which segment */
		struct	symtab *s_dest;	/* if JXXX, where going to */
E 4
D 21
#ifdef DJXXX
E 21
I 21
#ifdef DEBUG
E 21
D 4
		short	jxline;		/*source line of the jump from*/
E 4
I 4
		short	s_jxline;	/* source line of the jump from */
E 4
#endif
};
I 4
/*
 *	Redefinitions of the fields in symtab for
 *	use when the symbol table entry marks a jxxx instruction.
 */
D 27
#define	s_jxbump	s_ptype		/* tag == JX..., how far to expand */
E 27
I 27
#define	s_jxstate	s_ptype		/* tag == JX..., relaxation state */
E 27
#define	s_jxfear	s_desc		/* how far needs to be bumped */
/*
 *	Redefinitions of fields in the struct nlist for symbols so that
 *	one saves typing, and so that they conform 
 *	with the old naming conventions.
 */
D 18
#ifdef	FLEXNAMES
E 18
D 16
#define	s_name	s_nm.n_un.n_name	/* name pointer */
E 16
I 16
#define	s_name	s_nm.n_un.n_name
#define	i_name	s_name
#define	FETCHNAME(sp)	(((struct strdesc *)(sp)->s_name)->sd_string)
#define	STRLEN(sp)	(((struct strdesc *)(sp)->s_name)->sd_strlen)
#define	STROFF(sp)	(((struct strdesc *)(sp)->s_name)->sd_stroff)
I 20
#define	STRPLACE(sp)	(((struct strdesc *)(sp)->s_name)->sd_place)
E 20
E 16
#define	s_nmx	s_nm.n_un.n_strx	/* string table index */
D 18
#else 	not FLEXNAMES
#define	s_name	s_nm.n_name
I 16
#define	i_name	s_name
#define	FETCHNAME(sp)	((sp)->s_name)
E 16
#endif
E 18
#define	s_type	s_nm.n_type		/* type of the symbol */
#define	s_other	s_nm.n_other		/* other information for sdb */
#define	s_desc	s_nm.n_desc		/* type descriptor */
#define	s_value	s_nm.n_value		/* value of the symbol, or sdb delta */
E 4

D 4
struct instab{
	symfirstfields;

#define		opcode type		/*use the same field as symtab.type*/

	char	nargs;			/*how many arguments*/
	char	argtype[6];		/*argument type info*/
E 4
I 4
struct	instab{
	struct	nlist	s_nm;		/* instruction name, type (opcode) */
	u_char	s_tag;			
I 9
D 10
	char	s_pad[3];		/* round to 20 bytes */
E 10
I 10
	u_char	s_eopcode;
	char	s_pad[2];		/* round to 20 bytes */
E 10
E 9
E 4
};
I 10
typedef	struct	instab	*Iptr;
E 10
I 4
/*
 *	The fields nm.n_desc and nm.n_value total 6 bytes; this is
 *	just enough for the 6 bytes describing the argument types.
 *	We use a macro to define access to these 6 bytes, assuming that
 *	they are allocated adjacently.
 *	IF THE FORMAT OF STRUCT nlist CHANGES, THESE MAY HAVE TO BE CHANGED.
 *
D 9
 *	Instab is cleverly declared to look very much the combination of
E 9
I 9
 *	Instab is cleverly declared to look very much like the combination of
E 9
 *	a struct symtab and a struct nlist.
 */
I 10
/*
 *	With the 1981 VAX architecture reference manual,
 *	DEC defined and named two byte opcodes. 
 *	In addition, DEC defined four new one byte instructions for
 *	queue manipulation.
 *	The assembler was patched in 1982 to reflect this change.
 *
 *	The two byte opcodes are preceded with an escape byte
 *	(usually an ESCD) and an opcode byte.
 *	For one byte opcodes, the opcode is called the primary opcode.
 *	For two byte opcodes, the second opcode is called the primary opcode.
 *
 *	We store the primary opcode in I_popcode,
 *	and the escape opcode in I_eopcode.
 *
 *	For one byte opcodes in the basic arhitecture,
 *		I_eopcode is CORE
 *	For one byte opcodes in the new architecture definition,
 *		I_eopcode is NEW
 *	For the two byte opcodes, I_eopcode is the escape byte.
 *
 *	The assembler checks if a NEW or two byte opcode is used,
 *	and issues a warning diagnostic.
 */
/*
 *	For upward compatability reasons, we can't have the two opcodes
 *	forming an operator specifier byte(s) be physically adjacent
 *	in the instruction table.
 *	We define a structure and a constructor that is used in
 *	the instruction generator.
 */
struct Opcode{
	u_char	Op_eopcode;
	u_char	Op_popcode;
};

#define	BADPOINT	0xAAAAAAAA
/*
 *	See if a structured opcode is bad
 */
#define	ITABCHECK(o)	((itab[o.Op_eopcode] != (Iptr*)BADPOINT) && (itab[o.Op_eopcode][o.Op_popcode] != (Iptr)BADPOINT))
/*
 *	Index the itab by a structured opcode
 */
#define	ITABFETCH(o)	itab[o.Op_eopcode][o.Op_popcode]

E 10
struct	Instab{
D 18
#ifdef FLEXNAMES
E 18
	char	*I_name;
D 18
#else not FLEXNAMES
D 14
	char	I_name[NCPS];
E 14
I 14
	char	I_name[NCPName];
E 14
#endif
E 18
D 10
	u_char	I_opcode;
E 10
I 10
	u_char	I_popcode;		/* basic op code */
E 10
	char	I_nargs;
	char	I_args[6];
	u_char	I_s_tag;
I 9
D 10
	char	I_pad[3];		/* round to 20 bytes */
E 10
I 10
	u_char	I_eopcode;
	char	I_pad[2];		/* round to 20 bytes */
E 10
E 9
};
/*
 *	Redefinitions of fields in the struct nlist for instructions so that
 *	one saves typing, and conforms to the old naming conventions
 */
D 10
#define	i_opcode	s_nm.n_type	/* use the same field as symtab.type */
E 10
I 10
#define	i_popcode	s_nm.n_type	/* use the same field as symtab.type */
#define	i_eopcode	s_eopcode
E 10
#define	i_nargs		s_nm.n_other	/* number of arguments */
#define	fetcharg(ptr, n) ((struct Instab *)ptr)->I_args[n]
E 4

struct	arg {				/*one argument to an instruction*/
D 4
	char	atype;
	char	areg1;
	char	areg2;
	char	dispsize;		/*usually d124, unless have B^, etc*/
	struct	exp *xp;
E 4
I 4
	char	a_atype;
	char	a_areg1;
	char	a_areg2;
	char	a_dispsize;		/*usually d124, unless have B^, etc*/
	struct	exp *a_xp;
E 4
};
D 10

E 10
I 10
/*
 *	Definitions for numbers and expressions.
 */
#include "asnumber.h"
E 10
struct	exp {
D 4
	long	xvalue;		/* MUST be the first field (look at union Double) */
	long	yvalue;		/* MUST be second field; least sig word of a double */
	char	xtype;
	char	xloc;
	struct	symtab *xname;
E 4
I 4
D 10
	long	e_xvalue;		/* MUST be the first field (look at union Double) */
	long	e_yvalue;		/* MUST be second field; least sig word of a double */
E 10
I 10
	Bignum	e_number;	/* 128 bits of #, plus tag */
E 10
	char	e_xtype;
	char	e_xloc;
D 10
	struct	symtab *e_xname;
E 10
I 10
	struct	symtab		*e_xname;
E 10
E 4
};
I 10
#define	e_xvalue	e_number.num_num.numIl_int.Il_long
E 10

D 4
#define doub_MSW xvalue
#define doub_LSW yvalue
E 4
I 4
D 10
#define doub_MSW e_xvalue
#define doub_LSW e_yvalue
E 10
I 10
#define		MINLIT		0
#define		MAXLIT		63
E 10
E 4

D 4
union Double {
E 4
I 4
D 10
union	Double {
E 4
	struct{
		long	doub_MSW;
		long	doub_LSW;
	} dis_dvalue;
	double	dvalue;
};
E 10
I 10
#define		MINBYTE		-128
#define		MAXBYTE		127
#define		MINUBYTE	0
#define		MAXUBYTE	255
E 10

D 4
struct Quad {
E 4
I 4
D 10
struct	Quad {
E 4
	long	quad_low_long;
	long	quad_high_long;
};
E 10
I 10
#define		MINWORD		-32768
#define		MAXWORD		32767
#define		MINUWORD	0
#define		MAXUWORD	65535
E 10

D 10
/*
 *	Magic layout macros
 */
#define 	MINBYTE	-128
#define		MAXBYTE	127
#define		MINWORD	-32768
#define		MAXWORD	32767
E 10
I 10
#define		ISLIT(x)	(((x) >= MINLIT) && ((x) <= MAXLIT))
#define		ISBYTE(x)	(((x) >= MINBYTE) && ((x) <= MAXBYTE))
#define		ISUBYTE(x)	(((x) >= MINUBYTE) && ((x) <= MAXUBYTE))
#define		ISWORD(x)	(((x) >= MINWORD) && ((x) <= MAXWORD))
#define		ISUWORD(x)	(((x) >= MINUWORD) && ((x) <= MAXUWORD))
I 16
/*
 *	Definitions for strings.
 *
 *	Strings are stored in the string pool; see strsave(str, length)
 *	Strings are known by their length and values.
 *	A string pointer points to the beginning of the value bytes;
 *
 *	If this structure is changed, change insts also.
 */
struct	strdesc{
	int	sd_stroff;	/* offset into string file */
	short	sd_place;	/* where string is */
	u_short	sd_strlen;	/* string length */
	char	sd_string[1];	/* the string itself, flexible length */
};
/*
 *	Where a string can be.  If these are changed, also change instrs.
 */
#define	STR_FILE	0x1
#define	STR_CORE	0x2
#define	STR_BOTH	0x3
E 16
E 10

I 16
struct strdesc *savestr();

/*
 *	Global variables
 */
E 16
D 10
#define		LITFLTMASK 0x000043F0	/*really magic*/
/*
 *		Is the floating point double word in xp a
 *		short literal floating point number?
 */
#define 	slitflt(xp) \
			(    (xp->doub_LSW == 0) \
			 &&  ( (xp->doub_MSW & LITFLTMASK) \
			      == xp->doub_MSW) )
/*
 *	If it is a slitflt, then extract the 6 interesting bits
 */
#define		extlitflt(xp) \
			xp->doub_MSW >> 4

E 10
	extern	struct	arg	arglist[NARG];	/*building operands in instructions*/
	extern	struct	exp	explist[NEXP];	/*building up a list of expressions*/
	extern	struct	exp	*xp;		/*current free expression*/
	/*
	 *	Communication between the scanner and the jxxx handlers.
	 *	lastnam:	the last name seen on the input
	 *	lastjxxx:	pointer to the last symbol table entry for
	 *			a jump from
	 */
	extern	struct	symtab	*lastnam;
	extern	struct	symtab	*lastjxxx;	
D 17

#ifdef VMS
D 4
	extern char	*vms_obj_ptr;		/* object buffer pointer */
	extern char	sobuf[];		/* object buffer         */
E 4
I 4
	extern	char	*vms_obj_ptr;		/* object buffer pointer */
	extern	char	sobuf[];		/* object buffer         */
E 4
	extern	int	objfil;			/* VMS object file descriptor */
#endif VMS

E 17
	/*
	 *	Lgensym is used to make up funny names for local labels.
	 *	lgensym[i] is the current funny number to put after
	 *	references to if, lgensym[i]-1 is for ib.
	 *	genref[i] is set when the label is referenced before
	 *	it is defined (i.e. 2f) so that we can be sure these
	 *	labels are always defined to avoid weird diagnostics
	 *	from the loader later.
	 */
	extern	int	lgensym[10];
	extern	char	genref[10];

D 16
	extern	char	tmpn1[TNAMESIZE];	/* Interpass temporary */
E 16
	extern	struct	exp	*dotp;		/* the current dot location */
	extern	int	loctr;

	extern	struct	exec	hdr;		/* a.out header */
	extern	u_long	tsize;			/* total text size */
	extern	u_long	dsize;			/* total data size */
	extern	u_long	trsize;			/* total text relocation size */
	extern	u_long	drsize;			/* total data relocation size */
	extern	u_long	datbase;		/* base of the data segment */
	/*
	 *	Bitoff and bitfield keep track of the packing into 
	 *	bytes mandated by the expression syntax <expr> ':' <expr>
	 */
	extern	int	bitoff;	
	extern	long	bitfield;
	
	/*
	 *	The lexical analyzer builds up symbols in yytext.  Lookup
	 *	expects its argument in this buffer
	 */
D 14
	extern	char	yytext[NCPS+2];		/* text buffer for lexical */
E 14
I 14
	extern	char	yytext[NCPName+2];	/* text buffer for lexical */
E 14
	/*
	 *	Variables to manage the input assembler source file
	 */
	extern	int	lineno;			/*the line number*/
	extern	char	*dotsname;		/*the name of the as source*/

D 16
	extern	FILE	*tmpfil;		/* interpass communication*/
E 16
I 16
	extern	FILE	*tokfile;		/* temp token communication*/
	extern	FILE	*strfile;		/* temp string file*/
	extern	char	tokfilename[TNAMESIZE];	/* token file name */
	extern	char	strfilename[TNAMESIZE];	/* string file name */
	extern	int	strfilepos;		/* position in string file */
E 16

	extern	int	passno;			/* 1 or 2 */

D 10
	extern	int	anyerrs;		/*errors assembling arguments*/
E 10
I 10
	extern	int	anyerrs;		/*errors as'ing arguments*/
	extern	int	anywarnings;		/*warnings as'ing arguments*/
E 10
	extern	int	silent;			/*don't mention the errors*/
	extern	int	savelabels;		/*save labels in a.out*/
	extern	int	orgwarn;		/* questionable origin ? */
	extern	int	useVM;			/*use virtual memory temp file*/
I 5
D 27
	extern	int	jxxxJUMP;		/*use jmp instead of brw for jxxx */
E 27
I 6
	extern	int	readonlydata;		/*initialized data into text space*/
I 10
	extern	int	nGHnumbers;		/* GH numbers used */
	extern	int	nGHopcodes;		/* GH opcodes used */
	extern	int	nnewopcodes;		/* new opcodes used */
E 10
E 6
E 5
#ifdef DEBUG
	extern	int	debug;
	extern	int	toktrace;
#endif
	/*
	 *	Information about the instructions
	 */
D 10
	extern	struct	instab	*itab[NINST];	/*maps opcodes to instructions*/
E 10
I 10
	extern	struct	instab	**itab[NINST];	/*maps opcodes to instructions*/
E 10
D 4
	extern  readonly struct instab instab[];
E 4
I 4
	extern  readonly struct Instab instab[];
E 4

	extern	int	curlen;			/*current literal storage size*/
I 28
	extern	int	d124;			/*current pointer storage size*/
E 28
D 27
	extern	int	d124;			/*current pointer storage size*/
E 27
I 22
	extern	int	maxalign;		/*maximum .align allowed*/
E 22
	
	struct	symtab	**lookup();		/*argument in yytext*/
	struct 	symtab	*symalloc();

I 10
	char	*Calloc();
	char	*ClearCalloc();

E 10
D 4
#define outb(val) {dotp->xvalue++; if (passno==2) bputc((val), (txtfil));}
E 4
I 4
#define outb(val) {dotp->e_xvalue++; if (passno==2) bputc((val), (txtfil));}
E 4

D 4
#define outs(cp, lg) dotp->xvalue += (lg); if (passno == 2) bwrite((cp), (lg), (txtfil))
E 4
I 4
#define outs(cp, lg) dotp->e_xvalue += (lg); if (passno == 2) bwrite((cp), (lg), (txtfil))
I 10

D 17
#ifdef UNIX
E 17
#define	Outb(o)	outb(o)
D 17
#endif UNIX

#ifdef VMS
#define	Outb(o)	{*vms_obj_ptr++=-1;*vms_obj_ptr++=(char)o;dotp->e_xvalue+=1;}
#endif VMS
E 10
E 4

E 17
/*
 *	Most of the time, the argument to flushfield is a power of two constant,
 *	the calculations involving it can be optimized to shifts.
 */
#define flushfield(n) if (bitoff != 0)  Flushfield( ( (bitoff+n-1) /n ) * n)

/*
 * The biobuf structure and associated routines are used to write
 * into one file at several places concurrently.  Calling bopen
 * with a biobuf structure sets it up to write ``biofd'' starting
 * at the specified offset.  You can then use ``bwrite'' and/or ``bputc''
 * to stuff characters in the stream, much like ``fwrite'' and ``fputc''.
 * Calling bflush drains all the buffers and MUST be done before exit.
 */
struct	biobuf {
	short	b_nleft;		/* Number free spaces left in b_buf */
/* Initialize to be less than BUFSIZ initially, to boundary align in file */
	char	*b_ptr;			/* Next place to stuff characters */
D 23
	char	b_buf[BUFSIZ];		/* The buffer itself */
E 23
I 23
	char	*b_buf;			/* Pointer to the buffer */
E 23
	off_t	b_off;			/* Current file offset */
	struct	biobuf *b_link;		/* Link in chain for bflush() */
};
#define	bputc(c,b) ((b)->b_nleft ? (--(b)->b_nleft, *(b)->b_ptr++ = (c)) \
		       : bflushc(b, c))
#define BFILE	struct biobuf

	extern	BFILE	*biobufs;	/* head of the block I/O buffer chain */
	extern	int	biofd;		/* file descriptor for block I/O file */
I 23
	extern	int	biobufsize;	/* optimal block size for I/O */
E 23
	extern	off_t	boffset;	/* physical position in logical file */

	/*
	 *	For each of the named .text .data segments
	 *	(introduced by .text <expr>), we maintain
	 *	the current value of the dot, and the BFILE where
	 *	the information for each of the segments is placed
	 *	during the second pass.
	 */
	extern	struct	exp	usedot[NLOC + NLOC];
	extern		BFILE	*usefile[NLOC + NLOC];
	extern		BFILE	*txtfil;/* file for text and data: into usefile */
	/*
	 *	Relocation information for each segment is accumulated
	 *	seperately from the others.  Writing the relocation
	 *	information is logically viewed as writing to one
	 *	relocation saving file for  each segment; physically
	 *	we have a bunch of buffers allocated internally that
	 *	contain the relocation information.
	 */
	struct	relbufdesc	*rusefile[NLOC + NLOC];
	struct	relbufdesc	*relfil;
E 1
