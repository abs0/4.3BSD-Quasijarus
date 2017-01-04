h04053
s 00003/00000/01018
d D 5.3 86/11/17 19:43:22 donn 23 22
c LCSYM stabs require some extra footwork because their value isn't known
c until after the referenced symbol is given a location.  The solution is
c to treat them as forward references.  Note ugly kluge with 'exprisname'.
e
s 00013/00013/01005
d D 5.2 85/06/19 16:43:15 mckusick 22 21
c NBPW changed to NBWD to avoid conflict in param.h
e
s 00005/00002/01013
d D 5.1 85/04/30 13:57:37 dist 21 20
c Add copyright
e
s 00001/00000/01014
d D 4.20 85/04/02 09:34:10 ralph 20 19
c init type so .stabs of static arrays will work under dbx.
e
s 00002/00003/01012
d D 4.19 84/06/06 09:17:06 rrh 19 18
c fix bug causing filled data to not advance the location counter
c during pass 2
e
s 00009/00016/01006
d D 4.18 83/10/14 16:38:00 ralph 18 17
c fixed debugging info and phase error message for label defs.
e
s 00001/00006/01021
d D 4.17 83/07/01 09:42:50 rrh 17 16
c savestr now saves strings in both a file and in core; fixed
c a bug with savestr being too generous in saving strings in core
e
s 00002/00059/01025
d D 4.16 83/06/30 19:19:33 rrh 16 15
c bye bye fixed names (eg, FLEXNAMES is not set)
e
s 00000/00047/01084
d D 4.15 83/06/30 19:11:41 rrh 15 14
c bye bye VMS: UNIX only.  All the preceeding changes to the symbol
c table stuff were never tested under VMS
e
s 00048/00024/01083
d D 4.14 83/06/30 19:02:38 rrh 14 13
c The string pool is maintained both in core, and in a second tmp file.
c names are in core and on the file; strings are just in the file.  The file 
c is maintained as a string table per a.out(5), and tacked onto the a.out file
c at the very end.  The string table has more than need be, since discarde 
c labels and .ascii strings find their way (harmlessly) into the string table.
c the string file maintained with stdio; nothing fancy, even if -V set
e
s 00011/00011/01096
d D 4.13 83/06/30 07:58:12 rrh 13 12
c consolidate character buffer length definitions (manifest constants)
c into one place, with documentation
e
s 00037/00043/01070
d D 4.12 83/06/29 20:05:52 rrh 12 11
c DQ quoted strings no longer put into the temp file, but stored
c directly into the string spool; this fixes serious efficiency/size bugs
c in the temp files. DQ strings put into string pool with preceding 2 bytes
c indicating the length, with a trailing null byte not accounted for in the
c 2byte length; .asciz and .stabs change length and magically get null byte;
c all string moves (lookup and reader) done by subroutine call & movc3
e
s 00034/00000/01079
d D 4.11 83/06/24 16:50:28 rrh 11 10
c complain if the .words in a case table branch too far (eg,
c the .word expression overflows) We don't complain if other expressions overflow
e
s 00009/00000/01070
d D 4.10 83/06/09 11:32:52 rrh 10 9
c shiftover calls special complaint function to get reasonable error messages
e
s 00013/00001/01057
d D 4.9 83/05/19 19:35:07 csvaf 9 8
c kludged stab handling to cope with (name+val) locations
e
s 00135/00140/00923
d D 4.8 82/02/14 16:33:21 rrh 8 7
c Fix reported and outstanding bugs. Reformat some text for
c readability/understandability. Assembles new instructions  for G and H
c format floating numbers & new queue instructions
c asscan.c split into 4 files; two additional files to construct and
c manipulate G and H format numbers, with analog for atof()
c Numerical accuracy of new atof() not verified; standard atof() used
c for F and D floating numbers.  As does NOT use G and H instructions itself
e
s 00016/00000/01047
d D 4.7 80/08/20 10:04:32 henry 7 6
c Add yywarning
e
s 00010/00012/01037
d D 4.6 80/08/20 09:49:51 henry 6 5
c Catch relocation of floats and 8 byte qtys; restructure outrel
e
s 00001/00006/01048
d D 4.5 80/08/16 17:55:41 henry 5 4
c All error messages to stdout
e
s 00023/00006/01031
d D 4.4 80/08/16 17:43:02 henry 4 3
c Add .fill rep, size, value directive
e
s 00001/00000/01036
d D 4.3 80/08/16 17:32:09 henry 3 2
c Add .quad storage filler directive
e
s 00141/00131/00895
d D 4.2 80/08/15 18:03:22 henry 2 1
c use struct nlist; change field names; vgrind format fixes
e
s 01026/00000/00000
d D 4.1 80/08/13 18:55:18 bill 1 0
c date and time created 80/08/13 18:55:18 by bill
e
u
U
t
T
I 1
D 8
/* Copyright (c) 1980 Regents of the University of California */
static	char sccsid[] = "%Z%%M% %I% %G%";
E 8
I 8
/*
D 21
 *	Copyright (c) 1982 Regents of the University of California
E 21
I 21
 * Copyright (c) 1982 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 21
 */
I 21

E 21
#ifndef lint
D 21
static char sccsid[] = "%Z%%M% %I% %G%";
E 21
I 21
static char sccsid[] = "%W% (Berkeley) %G%";
E 21
#endif not lint

E 8
#include <stdio.h>
D 2
#include <sys/types.h>
#ifdef UNIX
#  include <a.out.h>
#endif UNIX

#ifdef VMS
#  ifdef UNIXDEVEL
#	include <a.out.h>
#  else VMSDEVEL
#  	include <aout.h>
#  endif
#endif VMS
E 2
#include "as.h"
D 8
#include "asexpr.h"
E 8
#include "asscan.h"
#include "assyms.h"
I 8
#include "asexpr.h"
E 8

int	lgensym[10];
char	genref[10];

long	bitfield;
int	bitoff;
int	curlen;			/* current length of literals */

/*
 *	The following three variables are communication between various
 *	modules to special case a number of things.  They are properly
 *	categorized as hacks.
 */
extern	struct	symtab *lastnam;/*last name seen by the lexical analyzer*/
int	exprisname;		/*last factor in an expression was a name*/
int	droppedLP;		/*one is analyzing an expression beginning with*/
				/*a left parenthesis, which has already been*/
				/*shifted. (Used to parse (<expr>)(rn)*/

D 13
char	yytext[NCPS+2];		/*the lexical image*/
E 13
I 13
char	yytext[NCPName+2];	/*the lexical image*/
E 13
int	yylval;			/*the lexical value; sloppy typing*/
I 8
struct	Opcode		yyopcode;	/* lexical value for an opcode */
Bignum	yybignum;		/* lexical value for a big number */
E 8
/*
 *	Expression and argument managers
 */
struct	exp	*xp;		/*next free expression slot, used by expr.c*/
struct	exp	explist[NEXP];	/*max of 20 expressions in one opcode*/
struct	arg	arglist[NARG];	/*building up operands in instructions*/
/*
 *	Sets to accelerate token discrimination
 */
char	tokensets[(LASTTOKEN) - (FIRSTTOKEN) + 1];

D 14
static	char	UDotsname[32];	/*name of the assembly source*/
E 14
I 14
static	char	UDotsname[64];	/*name of the assembly source*/
E 14

D 8
int	yyparse()
E 8
I 8
yyparse()
E 8
{
D 8
	register	struct	exp	*locxp;
			/*
			 *	loc1xp and ptrloc1xp are used in the
			 * 	expression lookahead
			 */
			struct	exp	*loc1xp;	/*must be non register*/
			struct	exp	**ptrloc1xp = & loc1xp;
			struct	exp	*pval;		/*hacking expr:expr*/
E 8
I 8
	reg	struct	exp	*locxp;
		/*
		 *	loc1xp and ptrloc1xp are used in the
		 * 	expression lookahead
		 */
		struct	exp	*loc1xp;	/*must be non register*/
		struct	exp	**ptrloc1xp = & loc1xp;
		struct	exp	*pval;		/*hacking expr:expr*/
E 8

D 8
	register	struct	symtab	*np;
	register	int		argcnt;
E 8
I 8
	reg	struct	symtab	*np;
	reg	int		argcnt;
E 8

D 8
	register	int		val;		/*what yylex gives*/
	register	int		auxval;		/*saves val*/
E 8
I 8
	reg	inttoktype	val;		/*what yylex gives*/
	reg	inttoktype	auxval;		/*saves val*/
E 8

D 8
	register	struct 	arg	*ap;		/*first free argument*/
E 8
I 8
	reg	struct 	arg	*ap;		/*first free argument*/
E 8

D 8
			struct	symtab	*p;
	register	struct	symtab	*stpt;
E 8
I 8
	reg	struct	symtab	*p;
	reg	struct	symtab	*stpt;
E 8

D 8
			struct	strdesc	*stringp;	/*handles string lists*/
E 8
I 8
D 12
		struct	strdesc	*stringp;	/*handles string lists*/
E 12
I 12
D 14
		char	*stringp;	/*handles string lists*/
E 14
I 14
		struct	strdesc *stringp;	/*handles string lists*/
E 14
E 12
E 8

D 8
			int		regno;		/*handles arguments*/
			int		*ptrregno = &regno;
			int		sawmul;		/*saw * */
			int		sawindex;	/*saw [rn]*/
			int		sawsize;
			int		seg_type; 	/*the kind of segment: data or text*/
			int		seg_number;	/*the segment number*/
			int		space_value;	/*how much .space needs*/
I 4
			int		fill_rep;	/*how many reps for .fill */
			int		fill_size;	/*how many bytes for .fill */
E 8
I 8
		int	regno;		/*handles arguments*/
		int	*ptrregno = &regno;
		int	sawmul;		/*saw * */
		int	sawindex;	/*saw [rn]*/
		int	sawsize;
		int	seg_type; 	/*the kind of segment: data or text*/
		int	seg_number;	/*the segment number*/
		int	space_value;	/*how much .space needs*/
		int	fill_rep;	/*how many reps for .fill */
		int	fill_size;	/*how many bytes for .fill */
E 8
E 4

D 8
			int		field_width;	/*how wide a field is to be*/
			int		field_value;	/*the value to stuff in a field*/
			char		*stabname;	/*name of stab dealing with*/
			ptrall		stabstart;	/*where the stab starts in the buffer*/
I 6
			int		reloc_how;	/* how to relocate expressions */
E 8
I 8
		int	field_width;	/*how wide a field is to be*/
		int	field_value;	/*the value to stuff in a field*/
		char	*stabname;	/*name of stab dealing with*/
		ptrall	stabstart;	/*where the stab starts in the buffer*/
		int	reloc_how;	/* how to relocate expressions */
		int	toconv;		/* how to convert bignums */
I 11
		int	incasetable;	/* set if in a case table */
E 11
E 8
E 6

I 11
	incasetable = 0;
E 11
	xp = explist;
	ap = arglist;

	val = yylex();

    while (val != PARSEEOF){	/* primary loop */

	while (INTOKSET(val, LINSTBEGIN)){
		if (val == INT) {
D 2
			int i = ((struct exp *)yylval)->xvalue;
E 2
I 2
			int i = ((struct exp *)yylval)->e_xvalue;
E 2
			shift;
D 8
			if (val != COLON)
				goto nocolon;
E 8
I 8
			if (val != COLON){
				yyerror("Local label %d is not followed by a ':' for a label definition",
					i);
				goto  errorfix;
			}
E 8
			if (i < 0 || i > 9) {
				yyerror("Local labels are 0-9");
				goto errorfix;
			}
D 8
			sprintf(yytext, "L%d\001%d", i, lgensym[i]);
E 8
I 8
			(void)sprintf(yytext, "L%d\001%d", i, lgensym[i]);
E 8
			lgensym[i]++;
			genref[i] = 0;
			yylval = (int)*lookup(passno == 1);
			val = NAME;
			np = (struct symtab *)yylval;
			goto restlab;
		}
		if (val == NL){
			lineno++;
			shift;
		} else
		if (val == SEMI) 
			shift;
		else {	/*its a name, so we have a label or def */
			if (val != NAME){
				ERROR("Name expected for a label");
			}
			np = (struct symtab *)yylval;
			shiftover(NAME);
D 8
nocolon:
E 8
			if (val != COLON) {
I 2
D 16
#ifdef FLEXNAMES
E 16
E 2
				yyerror("\"%s\" is not followed by a ':' for a label definition",
D 2
					np->name);
E 2
I 2
D 16
#else not FLEXNAMES
				yyerror("\"%.*s\" is not followed by a ':' for a label definition",
D 13
					NCPS,
E 13
I 13
					NCPName,
E 13
#endif not FLEXNAMES
E 16
D 14
					np->s_name);
E 14
I 14
					FETCHNAME(np));
E 14
E 2
				goto  errorfix;
			}
restlab:
			shift;
D 22
			flushfield(NBPW/4);
E 22
I 22
			flushfield(NBWD/4);
E 22
D 2
			if ((np->type&XTYPE)!=XUNDEF) {
				if(  (np->type&XTYPE)!=dotp->xtype 
				   || np->value!=dotp->xvalue
E 2
I 2
			if ((np->s_type&XTYPE)!=XUNDEF) {
D 18
				if(  (np->s_type&XTYPE)!=dotp->e_xtype 
				   || np->s_value!=dotp->e_xvalue
E 2
				   || (  (passno==1)
D 2
				       &&(np->index != dotp->xloc)
E 2
I 2
				       &&(np->s_index != dotp->e_xloc)
E 2
				      )
				  ){
#ifndef DEBUG
D 2
					if (np->name[0] != 'L')
E 2
I 2
D 14
					if (np->s_name[0] != 'L')
E 14
I 14
					if (FETCHNAME(np)[0] != 'L')
E 14
E 2
#endif not DEBUG
					{
						if (passno == 1)
D 2
						  yyerror("%.8s redefined", np->name);
E 2
I 2
D 16
#ifdef FLEXNAMES
E 16
						  yyerror("%s redefined",
E 18
I 18
				if (  (np->s_type&XTYPE) != dotp->e_xtype 
				   || np->s_value != dotp->e_xvalue
				   || (   passno == 1
				       && np->s_index != dotp->e_xloc) ) {
					if (passno == 1)
						yyerror("%s redefined",
E 18
D 16
#else not FLEXNAMES
						  yyerror("%.*s redefined",
D 13
							NCPS,
E 13
I 13
							NCPName,
E 13
#endif not FLEXNAMES 
E 16
D 14
							np->s_name);
E 14
I 14
							FETCHNAME(np));
E 14
E 2
D 18
						else
D 2
						  yyerror("%.8s redefined: PHASE ERROR, 1st: %d, 2nd: %d",
						   np->name,
						   np->value,
						   dotp->xvalue);
E 2
I 2
D 16
#ifdef FLEXNAMES
E 16
						  yyerror("%s redefined: PHASE ERROR, 1st: %d, 2nd: %d",
E 18
I 18
					else
						yyerror("%s redefined: PHASE ERROR, 1st: %d, 2nd: %d",
E 18
D 16
#else not FLEXNAMES
						  yyerror("%.*s redefined: PHASE ERROR, 1st: %d, 2nd: %d",
D 13
							NCPS,
E 13
I 13
							NCPName,
E 13
#endif not FLEXNAMES
E 16
D 14
							np->s_name,
E 14
I 14
							FETCHNAME(np),
E 14
							np->s_value,
							dotp->e_xvalue);
E 2
D 18
					}
E 18
				}
			}
D 2
			np->type &= ~(XTYPE|XFORW);
			np->type |= dotp->xtype;
			np->value = dotp->xvalue;
E 2
I 2
			np->s_type &= ~(XTYPE|XFORW);
			np->s_type |= dotp->e_xtype;
			np->s_value = dotp->e_xvalue;
E 2
			if (passno == 1){
D 2
				np->index = dotp-usedot;
				if (np->name[0] == 'L'){
E 2
I 2
				np->s_index = dotp-usedot;
D 14
				if (np->s_name[0] == 'L'){
E 14
I 14
				if (FETCHNAME(np)[0] == 'L'){
E 14
E 2
					nlabels++;
				}
D 2
				np->tag = LABELID;
E 2
I 2
				np->s_tag = LABELID;
E 2
			}
		}	/*end of this being a label*/
D 18
	}	/*end of to consuming all labels, NLs and SEMIS */ 
E 18
I 18
	}	/*end of consuming all labels, NLs and SEMIS */ 
E 18

	xp = explist;
	ap = arglist;

	/*
	 *	process the INSTRUCTION body
	 */
	switch(val){

    default:
	ERROR("Unrecognized instruction or directive");

   case IABORT:
	shift;
	sawabort();
	/*NOTREACHED*/
	break;

   case PARSEEOF:
D 8
	tokptr -= sizeof(toktype);
E 8
I 8
	tokptr -= sizeof(bytetoktype);
E 8
	*tokptr++ = VOID;
	tokptr[1] = VOID;
	tokptr[2] = PARSEEOF;
	break;

   case IFILE:
	shift;
D 12
	stringp = (struct strdesc *)yylval;
E 12
I 12
D 14
	stringp = (char *)yylval;
E 14
I 14
	stringp = (struct strdesc *)yylval;
E 14
E 12
	shiftover(STRING);
	dotsname = &UDotsname[0];
D 12
	movestr(dotsname, stringp->str,
		stringp->str_lg >= 32? 32 :stringp->str_lg);
	dotsname[stringp->str_lg] = '\0';
E 12
I 12
D 14
	movestr(dotsname, stringp, min(STRLEN(stringp), sizeof(dotsname)));
E 14
I 14
	movestr(dotsname, stringp->sd_string,
		min(stringp->sd_strlen, sizeof(UDotsname)));
E 14
E 12
	break;

   case ILINENO:
	shift;		/*over the ILINENO*/
	expr(locxp, val);
D 2
	lineno = locxp->xvalue;
E 2
I 2
	lineno = locxp->e_xvalue;
E 2
	break;

   case ISET: 	/* .set  <name> , <expr> */
	shift;
	np = (struct symtab *)yylval;
	shiftover(NAME);
	shiftover(CM);
	expr(locxp, val);
D 2
	np->type &= (XXTRN|XFORW);
	np->type |= locxp->xtype&(XTYPE|XFORW);
	np->value = locxp->xvalue;
E 2
I 2
	np->s_type &= (XXTRN|XFORW);
	np->s_type |= locxp->e_xtype&(XTYPE|XFORW);
	np->s_value = locxp->e_xvalue;
E 2
	if (passno==1)
D 2
		np->index = locxp->xloc;
	if ((locxp->xtype&XTYPE) == XUNDEF)
E 2
I 2
		np->s_index = locxp->e_xloc;
	if ((locxp->e_xtype&XTYPE) == XUNDEF)
E 2
		yyerror("Illegal set?");
	break;

   case ILSYM: 	/*.lsym name , expr */
	shift;
	np = (struct symtab *)yylval;
	shiftover(NAME);
	shiftover(CM);
	expr(locxp, val);
	/*
	 *	Build the unique occurance of the
	 *	symbol.
	 *	The character scanner will have
	 *	already entered it into the symbol
	 *	table, but we should remove it
	 */
	if (passno == 1){
		stpt = (struct symtab *)symalloc();
D 16
#ifdef FLEXNAMES
E 16
D 2
		stpt->name = np->name;
E 2
I 2
		stpt->s_name = np->s_name;
E 2
D 16
#else
D 2
		movestr(stpt->name, np->name, NCPS);
E 2
I 2
D 13
		movestr(stpt->s_name, np->s_name, NCPS);
E 13
I 13
D 14
		movestr(stpt->s_name, np->s_name, NCPName);
E 14
I 14
		movestr(FETCHNAME(stpt), FETCHNAME(np), NCPName);
E 14
E 13
E 2
#endif
E 16
D 2
		np->tag = OBSOLETE;	/*invalidate original */
E 2
I 2
		np->s_tag = OBSOLETE;	/*invalidate original */
E 2
		nforgotten++;
		np = stpt;
D 2
		if (locxp->xtype != XABS) 
E 2
I 2
D 8
		if (locxp->e_xtype != XABS) 
E 2
			("Illegal lsym");
D 2
		np->value=locxp->xvalue;
		np->type=XABS;
		np->tag = ILSYM;
E 2
I 2
		np->s_value=locxp->e_xvalue;
		np->s_type=XABS;
E 8
I 8
		if ( (locxp->e_xtype & XTYPE) != XABS)
			yyerror("Illegal second argument to lsym");
		np->s_value = locxp->e_xvalue;
		np->s_type = XABS;
E 8
		np->s_tag = ILSYM;
E 2
	}
	break;

   case IGLOBAL: 	/*.globl <name> */
	shift;
	np = (struct symtab *)yylval;
	shiftover(NAME);
D 2
	np->type |= XXTRN;
E 2
I 2
	np->s_type |= XXTRN;
E 2
	break;

   case IDATA: 	/*.data [ <expr> ] */
   case ITEXT: 	/*.text [ <expr> ] */
	seg_type = -val;
	shift;
	if (INTOKSET(val, EBEGOPS+YUKKYEXPRBEG+SAFEEXPRBEG)){
		expr(locxp, val);
		seg_type = -seg_type;   /*now, it is positive*/
	}

	if (seg_type < 0) {	/*there wasn't an associated expr*/
		seg_number = 0;
		seg_type = -seg_type;
	} else {
D 2
		if (locxp->xtype != XABS || (seg_number=locxp->xvalue) >= NLOC) {
E 2
I 2
D 8
		if (locxp->e_xtype != XABS || (seg_number=locxp->e_xvalue) >= NLOC) {
E 8
I 8
		if (   ((locxp->e_xtype & XTYPE) != XABS)	/* tekmdp */
		    || (seg_number = locxp->e_xvalue) >= NLOC) {
E 8
E 2
			yyerror("illegal location counter");
			seg_number = 0;
		}
	}
	if (seg_type == IDATA)
		seg_number += NLOC;
D 22
	flushfield(NBPW/4);
E 22
I 22
	flushfield(NBWD/4);
E 22
	dotp = &usedot[seg_number];
D 15
#ifdef UNIX
E 15
	if (passno==2) {	/* go salt away in pass 2*/
		txtfil = usefile[seg_number];
		relfil = rusefile[seg_number];
	}
D 15
#endif UNIX
#ifdef VMS
	if (passno==2) {
		puchar(vms_obj_ptr,6);		/*  setpl  */
		puchar(vms_obj_ptr,seg_number);	/* psect # */
D 2
		plong(vms_obj_ptr,dotp->xvalue);/*  offset */
E 2
I 2
		plong(vms_obj_ptr,dotp->e_xvalue);/*  offset */
E 2
		puchar(vms_obj_ptr,80);		/*  setrb  */
		if((vms_obj_ptr-sobuf) > 400){
			write(objfil,sobuf,vms_obj_ptr-sobuf);
			vms_obj_ptr=sobuf+1;	/*flush buf*/
		}
	}
#endif VMS
E 15
	break;

	/*
	 *	Storage filler directives:
	 *
	 *	.byte	[<exprlist>]
	 *
	 *	exprlist:  empty | exprlist outexpr
	 *	outexpr:   <expr> | <expr> : <expr>
	 */
D 22
   case IBYTE:	curlen = NBPW/4; goto elist;
D 8

   case IINT:
E 8
I 8
   case IWORD:	curlen = NBPW/2; goto elist;
   case IINT:	curlen = NBPW;   goto elist;
E 8
   case ILONG:	curlen = NBPW;   goto elist;
E 22
I 22
   case IBYTE:	curlen = NBWD/4; goto elist;
   case IWORD:	curlen = NBWD/2; goto elist;
   case IINT:	curlen = NBWD;   goto elist;
   case ILONG:	curlen = NBWD;   goto elist;
E 22

D 8
   case IWORD:
	curlen = NBPW/2;
E 8
   elist:
	seg_type = val;
	shift;

	/*
	 *	Expression List processing
	 */
	if (INTOKSET(val, EBEGOPS+YUKKYEXPRBEG+SAFEEXPRBEG)){
	    do{
		/*
		 *	expression list consists of a list of :
		 *	<expr>
		 *	<expr> : <expr> 
		 *		(pack expr2 into expr1 bits
		 */
		expr(locxp, val);
		/*
		 *	now, pointing at the next token
		 */
		if (val == COLON){
			shiftover(COLON);
			expr(pval, val);
D 2
			if (locxp->xtype != XABS)
E 2
I 2
D 8
			if (locxp->e_xtype != XABS)
E 2
			  yyerror("Width not absolute");
E 8
I 8
			if ((locxp->e_xtype & XTYPE) != XABS) /* tekmdp */
				yyerror("Width not absolute");
E 8
D 2
			field_width = locxp->xvalue;
E 2
I 2
			field_width = locxp->e_xvalue;
E 2
			locxp = pval;
D 8
			if (bitoff + field_width >
			  curlen)
E 8
I 8
			if (bitoff + field_width > curlen)
E 8
				flushfield(curlen);
			if (field_width > curlen)
				yyerror("Expression crosses field boundary");
		} else {
			field_width = curlen;
			flushfield(curlen);
		}

D 2
		 if ((locxp->xtype&XTYPE)!=XABS) {
E 2
I 2
D 8
		 if ((locxp->e_xtype&XTYPE)!=XABS) {
E 8
I 8
		if ((locxp->e_xtype & XTYPE) != XABS) {
E 8
E 2
			if (bitoff)
				yyerror("Illegal relocation in field");
D 6
			field_width=LEN1;
			if (curlen==NBPW)
				field_width = LEN4;
			if (curlen==NBPW/2)
				field_width = LEN2;
E 6
I 6
			switch(curlen){
D 22
				case NBPW/4:	reloc_how = TYPB; break;
				case NBPW/2:	reloc_how = TYPW; break;
				case NBPW:	reloc_how = TYPL; break;
E 22
I 22
				case NBWD/4:	reloc_how = TYPB; break;
				case NBWD/2:	reloc_how = TYPW; break;
				case NBWD:	reloc_how = TYPL; break;
E 22
			}
E 6
			if (passno == 1){
D 2
				dotp->xvalue += reflen[field_width];
E 2
I 2
D 6
				dotp->e_xvalue += reflen[field_width];
E 6
I 6
				dotp->e_xvalue += ty_nbyte[reloc_how];
E 6
E 2
			} else {
D 2
				outrel(&locxp->xvalue,
E 2
I 2
D 6
				outrel(&locxp->e_xvalue,
E 2
					field_width,
D 2
					locxp->xtype,
					locxp->xname);
E 2
I 2
					locxp->e_xtype,
					locxp->e_xname);
E 6
I 6
				outrel(locxp, reloc_how);
E 6
E 2
			}
		} else {
I 11
			/*
			 *	
			 *	See if we are doing a case instruction.
			 *	If so, then see if the branch distance,
			 *	stored as a word,
			 *	is going to loose sig bits.
			 */
			if (passno == 2 && incasetable){
				if (  (locxp->e_xvalue < -32768)
				    ||(locxp->e_xvalue > 32767)){
					yyerror("Case will branch too far");
				}
			}
E 11
D 2
			field_value = locxp->xvalue & ( (1L << field_width)-1);
E 2
I 2
			field_value = locxp->e_xvalue & ( (1L << field_width)-1);
E 2
			bitfield |= field_value << bitoff;
			bitoff += field_width;
		}
D 8
		if ( auxval = (val == CM)) shift;
E 8
		xp = explist;
I 8
		if (auxval = (val == CM))
			shift;
E 8
	    } while (auxval);
D 8
	}	/*existed an expression  at all*/
E 8
I 8
	}	/* there existed an expression at all */
E 8

	flushfield(curlen);
D 22
	if ( ( curlen == NBPW/4) && bitoff)
E 22
I 22
	if ( ( curlen == NBWD/4) && bitoff)
E 22
D 2
		dotp->xvalue ++;
E 2
I 2
		dotp->e_xvalue ++;
E 2
	break;
	/*end of case IBYTE, IWORD, ILONG, IINT*/

   case ISPACE: 	/* .space <expr> */
	shift;
	expr(locxp, val);
D 2
	if (locxp->xtype != XABS)
E 2
I 2
D 8
	if (locxp->e_xtype != XABS)
E 8
I 8
	if ((locxp->e_xtype & XTYPE) != XABS)	/* tekmdp */
E 8
E 2
		yyerror("Space size not absolute");
D 2
	space_value = locxp->xvalue;
E 2
I 2
	space_value = locxp->e_xvalue;
E 2
  ospace:
D 22
	flushfield(NBPW/4);
E 22
I 22
	flushfield(NBWD/4);
E 22
D 15
#ifdef UNIX
E 15
D 12
	while (space_value > 96){
		outs(strbuf[2].str, 96);
		space_value -= 96;
E 12
I 12
	{
		static char spacebuf[128];
		while (space_value > sizeof(spacebuf)){
			outs(spacebuf, sizeof(spacebuf));
			space_value -= sizeof(spacebuf);
		}
		outs(spacebuf, space_value);
E 12
	}
D 12
	outs(strbuf[2].str, space_value);
E 12
D 15
#endif UNIX
#ifdef VMS
D 2
	dotp->xvalue += space_value;		/*bump pc*/
E 2
I 2
	dotp->e_xvalue += space_value;		/*bump pc*/
E 2
	if (passno==2){
D 12
	  if(*(strbuf[2].str)==0) {
		puchar(vms_obj_ptr,81);		/* AUGR  */
		pulong(vms_obj_ptr,space_value);/* incr  */
	  } else yyerror("VMS, encountered non-0 .space");
E 12
I 12
	  puchar(vms_obj_ptr,81);		/* AUGR  */
	  pulong(vms_obj_ptr,space_value);/* incr  */
E 12
	  if ((vms_obj_ptr-sobuf) > 400) {
		write(objfil,sobuf,vms_obj_ptr-sobuf);
		vms_obj_ptr=sobuf+1;		/*pur buf*/
	  }
	}
#endif VMS
E 15
	break;

D 15
#ifdef UNIX
E 15
D 4
   case	IFILL:	/* .fill count, value */
		/* fill count bytes with value */
E 4
I 4
	/*
	 *	.fill rep, size, value
	 *	repeat rep times: fill size bytes with (truncated) value
	 *	size must be between 1 and 8
	 */
   case	IFILL:
E 4
	shift;
	expr(locxp, val);
D 2
	if (locxp->xtype != XABS)
E 2
I 2
D 8
	if (locxp->e_xtype != XABS)
E 8
I 8
	if ( (locxp->e_xtype & XTYPE) != XABS)	/* tekmdp */
E 8
E 2
		yyerror("Fill repetition count not absolute");
D 2
	space_value = locxp->xvalue;
E 2
I 2
D 4
	space_value = locxp->e_xvalue;
E 4
I 4
	fill_rep = locxp->e_xvalue;
E 4
E 2
	shiftover(CM);
	expr(locxp, val);
D 2
	if (locxp->xtype != XABS)
E 2
I 2
D 8
	if (locxp->e_xtype != XABS)
E 8
I 8
	if ( (locxp->e_xtype & XTYPE) != XABS)	/* tekmdp */
E 8
E 2
D 4
		yyerror("Fill value not absolute");
E 4
I 4
		yyerror("Fill size not absolute");
	fill_size = locxp->e_xvalue;
	if (fill_size <= 0 || fill_size > 8)
		yyerror("Fill count not in in 1..8");
	shiftover(CM);
	expr(locxp, val);
D 8
	if (passno == 2 && locxp->e_xtype != XABS)
			yyerror("Fill value not absolute");
E 8
I 8
	if (passno == 2 && (locxp->e_xtype & XTYPE) != XABS)	/* tekmdp */
		yyerror("Fill value not absolute");
E 8
E 4
D 22
	flushfield(NBPW/4);
E 22
I 22
	flushfield(NBWD/4);
E 22
D 4
	while(space_value-- > 0)
D 2
		outb(locxp->xvalue & 0xFF);
E 2
I 2
		outb(locxp->e_xvalue & 0xFF);
E 4
I 4
D 19
	if (passno == 1) {
D 8
		locxp->e_xvalue += fill_rep * fill_size;
E 8
I 8
		dotp->e_xvalue += fill_rep * fill_size;
E 8
	} else {
E 19
I 19
	dotp->e_xvalue += fill_rep * fill_size;
	if (passno == 2) {
E 19
		while(fill_rep-- > 0)
D 8
			bwrite(&locxp->e_xvalue, fill_size, txtfil);
E 8
I 8
			bwrite((char *)&locxp->e_xvalue, fill_size, txtfil);
E 8
	}
E 4
E 2
	break;
D 15
#endif UNIX
E 15

D 12
   case IASCII:	/* .ascii [ <stringlist> ] */
E 12
I 12
   case IASCII:		/* .ascii [ <stringlist> ] */
E 12
   case IASCIZ: 	/* .asciz [ <stringlist> ] */
	auxval = val;
	shift;
D 12

E 12
	/*
	 *	Code to consume a string list
	 *
	 *	stringlist: empty | STRING | stringlist STRING
	 */
D 12
	while (val ==  STRING){
E 12
I 12
	while (val == STRING){
I 14
		int	mystrlen;
E 14
E 12
D 22
		flushfield(NBPW/4);
E 22
I 22
		flushfield(NBWD/4);
E 22
		if (bitoff)
D 2
		  dotp->xvalue++;
E 2
I 2
D 12
		  dotp->e_xvalue++;
E 2
		stringp = (struct strdesc *)yylval;
E 12
I 12
			dotp->e_xvalue++;
D 14
		stringp = (char *)yylval;
E 14
I 14
		stringp = (struct strdesc *)yylval;
E 14
		/*
D 14
		 *	utilize the string scanner cheat,
		 *	where it appended a null byte on the string,
		 *	but didn't charge it to STRLEN
E 14
I 14
		 *	utilize the string scanner cheat;
		 *	the scanner appended a null byte on the string,
		 *	but didn't charge it to sd_strlen
E 14
		 */
D 14
		STRLEN(stringp) += (auxval == IASCIZ) ? 1 : 0;
E 14
I 14
		mystrlen = stringp->sd_strlen;
		mystrlen += (auxval == IASCIZ) ? 1 : 0;
E 14
E 12
D 15
#ifdef UNIX
E 15
D 12
		outs(stringp->str, stringp->str_lg);
E 12
I 12
D 14
		outs(stringp, STRLEN(stringp));
E 14
I 14
		if (passno == 2){
			if (stringp->sd_place & STR_CORE){
				outs(stringp->sd_string, mystrlen);
			} else {
				int	i, nread;
				fseek(strfile, stringp->sd_stroff, 0);
				for (i = 0; i < mystrlen;/*VOID*/){
					nread = fread(yytext, 1,
						min(mystrlen - i,
						  sizeof(yytext)), strfile);
					outs(yytext, nread);
					i += nread;
				}
			}
		} else {
			dotp->e_xvalue += mystrlen;
		}
E 14
E 12
D 15
#endif UNIX
#ifdef VMS
		{
D 8
			register int i;
E 8
I 8
			reg int i;
E 8
			for (i=0; i < stringp->str_lg; i++){
D 2
			  dotp->xvalue += 1;
E 2
I 2
			  dotp->e_xvalue += 1;
E 2
			    if (passno==2){
				puchar(vms_obj_ptr,-1);
			  	puchar(vms_obj_ptr,stringp->str[i]);
			  	if (vms_obj_ptr-sobuf > 400) {
				  write(objfil,sobuf,vms_obj_ptr-sobuf);
				  vms_obj_ptr = sobuf + 1;
			  	}
			    }
			}
		}
#endif VMS
E 15
		shift;		/*over the STRING*/
		if (val == CM)	/*could be a split string*/
			shift;
	}
D 12

	if (auxval == IASCIZ){
		flushfield(NBPW/4);
#ifdef UNIX
		outb(0);
#endif UNIX
#ifdef VMS
		if (passno == 2) {
			puchar(vms_obj_ptr,-1);
			puchar(vms_obj_ptr,0);
		}
D 2
		dotp->xvalue += 1;
E 2
I 2
		dotp->e_xvalue += 1;
E 2
#endif VMS
	}
E 12
	break;
	
   case IORG: 	/* .org <expr> */
	shift;
	expr(locxp, val);

D 2
	if (locxp->xtype==XABS)
E 2
I 2
D 8
	if (locxp->e_xtype==XABS)
E 8
I 8
	if ((locxp->e_xtype & XTYPE) == XABS)	/* tekmdp */
E 8
E 2
		orgwarn++;
D 2
	else if ((locxp->xtype & ~XXTRN) != dotp->xtype)
E 2
I 2
	else if ((locxp->e_xtype & ~XXTRN) != dotp->e_xtype)
E 2
		yyerror("Illegal expression to set origin");
D 2
	space_value = locxp->xvalue - dotp->xvalue;
E 2
I 2
	space_value = locxp->e_xvalue - dotp->e_xvalue;
E 2
	if (space_value < 0)
		yyerror("Backwards 'org'");
	goto ospace;
	break;

/*
 *
 *	Process stabs.  Stabs are created only by the f77
 *	and the C compiler with the -g flag set.
 *	We only look at the stab ONCE, during pass 1, and
 *	virtually remove the stab from the intermediate file
 *	so it isn't seen during pass2.  This makes for some
 *	hairy processing to handle labels occuring in
 *	stab entries, but since most expressions in the
 *	stab are integral we save lots of time in the second
 *	pass by not looking at the stabs.
 *	A stab that is tagged floating will be bumped during
 *	the jxxx resolution phase.  A stab tagged fixed will
 *	not be be bumped.
 *
 *	.stab:	Old fashioned stabs
 *	.stabn: For stabs without names
 *	.stabs:	For stabs with string names
 *	.stabd: For stabs for line numbers or bracketing,
 *		without a string name, without
 *		a final expression.  The value of the
 *		final expression is taken to be  the current
 *		location counter, and is patched by the 2nd pass
 *
D 6
 *	.stab{<expr>,}*8,<expr>, <expr>, <expr>, <expr>
E 6
I 6
D 13
 *	.stab{<expr>,}*NCPS,<expr>, <expr>, <expr>, <expr>
E 13
I 13
 *	.stab{<expr>,}*NCPName,<expr>, <expr>, <expr>, <expr>
E 13
E 6
 *	.stabn		 <expr>, <expr>, <expr>, <expr>
 *	.stabs   STRING, <expr>, <expr>, <expr>, <expr>
 *	.stabd		 <expr>, <expr>, <expr> # . 
 */
   case ISTAB: 
D 16
#ifndef FLEXNAMES
	stabname = ".stab";
	if (passno == 2)	goto errorfix;
	stpt = (struct symtab *)yylval;
	/*
	 *	Make a pointer to the .stab slot.
	 *	There is a pointer in the way (stpt), and
	 *	tokptr points to the next token.
	 */
	stabstart = tokptr;
	(char *)stabstart -= sizeof(struct symtab *);
D 8
	(char *)stabstart -= sizeof(toktype);
E 8
I 8
	(char *)stabstart -= sizeof(bytetoktype);
E 8
	shift;
D 6
	for (argcnt = 0; argcnt < 8; argcnt++){
E 6
I 6
D 13
	for (argcnt = 0; argcnt < NCPS; argcnt++){
E 13
I 13
	for (argcnt = 0; argcnt < NCPName; argcnt++){
E 13
E 6
		expr(locxp, val);
D 2
		stpt->name[argcnt] = locxp->xvalue;
E 2
I 2
D 14
		stpt->s_name[argcnt] = locxp->e_xvalue;
E 14
I 14
		FETCHNAME(stpt)[argcnt] = locxp->e_xvalue;
E 14
E 2
		xp = explist;
		shiftover(CM);
	}
	goto tailstab;
#else	FLEXNAMES
	yyerror(".stab directive not supported in; report this compiler bug to system administrator");
E 16
I 16
	yyerror(".stab directive no longer supported");
E 16
	goto errorfix;
D 16
#endif FLEXNAMES
E 16

  tailstab:
	expr(locxp, val);
D 2
	if (! (locxp->xvalue & STABTYPS)){
E 2
I 2
	if (! (locxp->e_xvalue & STABTYPS)){
E 2
D 8
		yyerror("Invalid type in %s",stabname);
E 8
I 8
		yyerror("Invalid type in %s", stabname);
E 8
		goto errorfix;
	}
D 2
	stpt->ptype = locxp->xvalue;
E 2
I 2
	stpt->s_ptype = locxp->e_xvalue;
E 2
	shiftover(CM);
	expr(locxp, val);
D 2
	stpt->other = locxp->xvalue;
E 2
I 2
	stpt->s_other = locxp->e_xvalue;
E 2
	shiftover(CM);
	expr(locxp, val);
D 2
	stpt->desc = locxp->xvalue;
E 2
I 2
	stpt->s_desc = locxp->e_xvalue;
E 2
	shiftover(CM);
	exprisname = 0;
	expr(locxp, val);
D 2
	p = locxp->xname;
E 2
I 2
	p = locxp->e_xname;
E 2
	if (p == NULL) {	/*absolute expr to begin with*/
D 2
		stpt->value = locxp->xvalue;
		stpt->index = dotp - usedot;
E 2
I 2
		stpt->s_value = locxp->e_xvalue;
		stpt->s_index = dotp - usedot;
E 2
		if (exprisname){
I 20
			stpt->s_type = locxp->e_xtype;
E 20
D 2
			switch(stpt->ptype){
E 2
I 2
			switch(stpt->s_ptype){
I 23
				case N_LCSYM:
					stpt->s_dest = (struct symtab *)exprisname;
					stpt->s_type |= STABFLAG;
E 23
E 2
				case N_GSYM:
				case N_FNAME:
				case N_RSYM:
				case N_SSYM:
				case N_LSYM:
				case N_PSYM:
				case N_BCOMM:
				case N_ECOMM:
				case N_LENG:
D 2
					stpt->tag = STABFIXED;
E 2
I 2
					stpt->s_tag = STABFIXED;
E 2
					break;
				default:
D 2
					stpt->tag = STABFLOATING;
E 2
I 2
					stpt->s_tag = STABFLOATING;
E 2
					break;
			}
		} else
D 2
			stpt->tag = STABFIXED;
E 2
I 2
			stpt->s_tag = STABFIXED;
E 2
	}
	else {		/*really have a name*/
D 2
		stpt->dest = locxp->xname;
		stpt->index = p->index;
		stpt->type = p->type | STABFLAG;
E 2
I 2
		stpt->s_dest = locxp->e_xname;
		stpt->s_index = p->s_index;
		stpt->s_type = p->s_type | STABFLAG;
E 2
		/*
		 *	We will assign a more accruate
		 *	guess of locxp's location when
		 *	we sort the symbol table
		 *	The final value of value is
		 *	given by stabfix()
		 */
D 2
		stpt->tag = STABFLOATING;
E 2
I 2
D 9
		stpt->s_tag = STABFLOATING;
E 9
I 9
/*
 * For exprs of the form (name + value) one needs to remember locxp->e_xvalue
 * for use in stabfix. The right place to keep this is in stpt->s_value
 * however this gets corrupted at an unknown point.
 * As a bandaid hack the value is preserved in s_desc and s_other (a
 * short and a char). This destroys these two values and will
 * be fixed. May 19 ,1983 Alastair Fyfe
 */
		if(locxp->e_xvalue) {
			stpt->s_other = (locxp->e_xvalue >> 16);
			stpt->s_desc =  (locxp->e_xvalue  & 0x0000ffff);
			stpt->s_tag = STABFLOATING;
		}
E 9
E 2
	}
	/*
	 *	tokptr now points at one token beyond
	 *	the current token stored in val and yylval,
	 *	which are the next tokens after the end of
	 *	this .stab directive.  This next token must
	 *	be either a SEMI or NL, so is of width just
	 *	one.  Therefore, to point to the next token
	 *	after the end of this stab, just back up one..
	 */
D 8
	buildskip(stabstart, (char *)tokptr - sizeof(toktype));
E 8
I 8
	buildskip(stabstart, (bytetoktype *)tokptr - sizeof(bytetoktype));
E 8
	break;	/*end of the .stab*/

   case ISTABDOT:	
	stabname = ".stabd";
	stpt = (struct symtab *)yylval;
	/*
	 *	We clobber everything after the
	 *	.stabd and its pointer... we MUST
	 *	be able to get back to this .stabd
	 *	so that we can resolve its final value
	 */
	stabstart = tokptr;
	shift;		/*over the ISTABDOT*/
	if (passno == 1){
		expr(locxp, val);
D 2
		if (! (locxp->xvalue & STABTYPS)){
E 2
I 2
		if (! (locxp->e_xvalue & STABTYPS)){
E 2
			yyerror("Invalid type in .stabd");
			goto errorfix;
		}
D 2
		stpt->ptype = locxp->xvalue;
E 2
I 2
		stpt->s_ptype = locxp->e_xvalue;
E 2
		shiftover(CM);
		expr(locxp, val);
D 2
		stpt->other = locxp->xvalue;
E 2
I 2
		stpt->s_other = locxp->e_xvalue;
E 2
		shiftover(CM);
		expr(locxp, val);
D 2
		stpt->desc = locxp->xvalue;
E 2
I 2
		stpt->s_desc = locxp->e_xvalue;
E 2
		/*
		 *
		 *	Now, clobber everything but the
		 *	.stabd pseudo and the pointer
		 *	to its symbol table entry
		 *	tokptr points to the next token,
		 *	build the skip up to this
		 */
D 8
		buildskip(stabstart, (toktype *)tokptr - sizeof(toktype));
E 8
I 8
		buildskip(stabstart, (bytetoktype *)tokptr - sizeof(bytetoktype));
E 8
	}
	/*
	 *	pass 1:	Assign a good guess for its position
	 *		(ensures they are sorted into right place)/
	 *	pass 2:	Fix the actual value
	 */
D 2
	stpt->value = dotp->xvalue;
	stpt->index = dotp - usedot;
	stpt->tag = STABFLOATING;	/*although it has no effect in pass 2*/
E 2
I 2
	stpt->s_value = dotp->e_xvalue;
	stpt->s_index = dotp - usedot;
	stpt->s_tag = STABFLOATING;	/*although it has no effect in pass 2*/
E 2
	break;

   case ISTABNONE:	stabname = ".stabn"; goto shortstab;

   case ISTABSTR: 	stabname = ".stabs";
   shortstab:
	auxval = val;
	if (passno == 2) goto errorfix;
	stpt = (struct symtab *)yylval;
	stabstart = tokptr;
D 8
	(char *)stabstart -= sizeof(struct symtab *);
	(char *)stabstart -= sizeof(toktype);
E 8
I 8
	(bytetoktype *)stabstart -= sizeof(struct symtab *);
	(bytetoktype *)stabstart -= sizeof(bytetoktype);
E 8
	shift;
	if (auxval == ISTABSTR){
D 12
		stringp = (struct strdesc *)yylval;
E 12
I 12
D 14
		stringp = (char *)yylval;
E 14
I 14
		stringp = (struct strdesc *)yylval;
E 14
E 12
		shiftover(STRING);
D 16
#ifndef FLEXNAMES
D 12
		auxval = stringp->str_lg > NCPS ? NCPS : stringp->str_lg;
E 12
I 12
D 13
		movestr(stpt->s_name, stringp, min(STRLEN(stringp), NCPS));
E 13
I 13
D 14
		movestr(stpt->s_name, stringp, min(STRLEN(stringp), NCPName));
E 14
I 14
		movestr(FETCHNAME(stpt), stringp,
			min(stringp->sd_strlen, NCPName));
E 14
E 13
E 12
#else
E 16
D 12
		stringp->str[stringp->str_lg] = 0;
E 12
I 12
D 14
		stpt->s_name = stringp;
E 14
I 14
		stpt->s_name = (char *)stringp;
E 14
		/*
		 *	We want the trailing null included in this string.
		 *	We utilize the cheat the string scanner used,
		 *	and merely increment the string length
		 */
D 14
		STRLEN(stringp) += 1;
E 14
I 14
		stringp->sd_strlen += 1;
E 14
E 12
D 16
#endif
E 16
		shiftover(CM);
	} else {
D 12
		stringp = &(strbuf[2]);
E 12
D 16
#ifndef FLEXNAMES
D 12
		auxval = NCPS;
#endif
	}
#ifndef FLEXNAMES
D 2
	movestr(stpt->name, stringp->str, auxval);
E 2
I 2
	movestr(stpt->s_name, stringp->str, auxval);
E 12
I 12
D 13
		static char nullstr[NCPS];
		movestr(stpt->s_name, nullstr, NCPS);
E 13
I 13
		static char nullstr[NCPName];
D 14
		movestr(stpt->s_name, nullstr, NCPName);
E 14
I 14
		movestr(FETCHNAME(stpt), nullstr, NCPName);
E 14
E 13
E 12
E 2
#else
E 16
D 2
	stpt->name = savestr(stringp->str);
E 2
I 2
D 12
	stpt->s_name = savestr(stringp->str);
E 12
I 12
D 17
		static char nullstr[1];
D 14
		stpt->s_name = savestr(nullstr, 1);
E 14
I 14
		static	struct	strdesc strdp;
		strdp.sd_stroff = strfilepos;
		strdp.sd_strlen = 0;
		strdp.sd_place = STR_BOTH;
		stpt->s_name = (char *)savestr(nullstr, &strdp);
E 17
I 17
		stpt->s_name = (char *)savestr("\0", 0, STR_BOTH);
E 17
E 14
E 12
E 2
D 16
#endif
E 16
I 12
	}
E 12
	goto tailstab;
	break;

D 8
   case ICOMM:	/* .comm  <name> , <expr> */
E 8
I 8
   case ICOMM:		/* .comm  <name> , <expr> */
E 8
   case ILCOMM: 	/* .lcomm <name> , <expr> */
	auxval = val;
	shift;
	np = (struct symtab *)yylval;
	shiftover(NAME);
	shiftover(CM);
	expr(locxp, val);

D 2
	if (locxp->xtype != XABS)
E 2
I 2
D 8
	if (locxp->e_xtype != XABS)
E 8
I 8
	if ( (locxp->e_xtype & XTYPE) != XABS)	/* tekmdp */
E 8
E 2
		yyerror("comm size not absolute");
D 2
	if (passno==1 && (np->type&XTYPE)!=XUNDEF)
		yyerror("Redefinition of %.8s", np->name);
E 2
I 2
D 8
	if (passno==1 && (np->s_type&XTYPE)!=XUNDEF)
E 8
I 8
	if (passno == 1 && (np->s_type&XTYPE) != XUNDEF)
E 8
D 16
#ifdef FLEXNAMES
		yyerror("Redefinition of %s",
#else not FLEXNAMES
		yyerror("Redefinition of %.*s",
D 13
			NCPS,
E 13
I 13
			NCPName,
E 13
#endif not FLEXNAMES
D 14
			np->s_name);
E 14
I 14
			FETCHNAME(np));
E 16
I 16
		yyerror("Redefinition of %s", FETCHNAME(np));
E 16
E 14
E 2
	if (passno==1) {
D 2
		np->value = locxp->xvalue;
E 2
I 2
		np->s_value = locxp->e_xvalue;
E 2
		if (auxval == ICOMM)
D 2
			np->type |= XXTRN;
E 2
I 2
			np->s_type |= XXTRN;
E 2
		else {
D 2
			np->type &= ~XTYPE;
			np->type |= XBSS;
E 2
I 2
			np->s_type &= ~XTYPE;
			np->s_type |= XBSS;
E 2
		}
	}
	break;

   case IALIGN: 		/* .align <expr> */
	stpt = (struct symtab *)yylval;
	shift;
	expr(locxp, val);
	jalign(locxp, stpt);
	break;

   case INST0: 		/* instructions w/o arguments*/
I 11
	incasetable = 0;
E 11
D 8
	insout(yylval, (struct arg *)0, 0);
E 8
I 8
	insout(yyopcode, (struct arg *)0, 0);
E 8
	shift;	
	break;

   case INSTn:		/* instructions with arguments*/
   case IJXXX: 		/* UNIX style jump instructions */
	auxval = val;
D 8
	seg_type = yylval;
E 8
	/*
	 *	Code to process an argument list
	 */
	ap = arglist;
	xp = explist;	

	shift;		/* bring in the first token for the arg list*/

	for (argcnt = 1; argcnt <= 6; argcnt++, ap++){
		/*
		 *	code to process an argument proper
		 */
	    sawindex  = sawmul = sawsize = 0;
	    {
		switch(val) {

		   default:
		     disp:
			if( !(INTOKSET(val,
				 EBEGOPS
				+YUKKYEXPRBEG
				+SAFEEXPRBEG)) ) {
				ERROR("expression expected");
			}
D 2
			expr(ap->xp,val);
E 2
I 2
			expr(ap->a_xp,val);
E 2
		     overdisp:
			if ( val == LP || sawsize){
				shiftover(LP);
				findreg(regno);
				shiftover(RP);
D 2
				ap->atype = ADISP;
				ap->areg1 = regno;
E 2
I 2
				ap->a_atype = ADISP;
				ap->a_areg1 = regno;
E 2
			} else {
D 2
				ap->atype = AEXP;
				ap->areg1 = 0;
E 2
I 2
				ap->a_atype = AEXP;
				ap->a_areg1 = 0;
E 2
			}
			goto index;

		   case SIZESPEC: 
		     sizespec:
			sawsize = yylval;
			shift;
			goto disp;

		   case REG:
		   case REGOP: 
			findreg(regno);
D 2
			ap->atype = AREG;
			ap->areg1 = regno;
E 2
I 2
			ap->a_atype = AREG;
			ap->a_areg1 = regno;
E 2
			break;
		    
		   case MUL: 
			sawmul = 1;
			shift;
			if (val == LP) goto base;
			if (val == LITOP) goto imm;
			if (val == SIZESPEC) goto sizespec;
			if (INTOKSET(val,
				 EBEGOPS
				+YUKKYEXPRBEG
				+SAFEEXPRBEG)) goto disp;
			ERROR("expression, '(' or '$' expected");
			break;

		   case LP: 
		     base:
			shift;	/*consume the LP*/
			/*
			 *	hack the ambiguity of
			 *	movl (expr) (rn), ...
			 *	note that (expr) could also
			 *	be (rn) (by special hole in the
			 *	grammar), which we ensure
			 *	means register indirection, instead
			 *	of an expression with value n
			 */
			if (val != REG && val != REGOP){
				droppedLP = 1;
D 2
				val = exprparse(val, &(ap->xp));
E 2
I 2
				val = exprparse(val, &(ap->a_xp));
E 2
				droppedLP = 0;
				goto overdisp;
			}
			findreg(regno);
			shiftover(RP);
			if (val == PLUS){
				shift;
D 2
				ap->atype = AINCR;
E 2
I 2
				ap->a_atype = AINCR;
E 2
			} else
D 2
				ap->atype = ABASE;
			ap->areg1 = regno;
E 2
I 2
				ap->a_atype = ABASE;
			ap->a_areg1 = regno;
E 2
			goto index;

		   case LITOP: 
		      imm:
			shift;
			expr(locxp, val);
D 2
			ap->atype = AIMM;
			ap->areg1 = 0;
			ap->xp = locxp;
E 2
I 2
			ap->a_atype = AIMM;
			ap->a_areg1 = 0;
			ap->a_xp = locxp;
E 2
			goto index;

		   case MP: 
			shift;	/* -(reg) */
			findreg(regno);
			shiftover(RP);
D 2
			ap->atype = ADECR;
			ap->areg1 = regno;
E 2
I 2
			ap->a_atype = ADECR;
			ap->a_areg1 = regno;
E 2
	  index:			/*look for [reg] */
			if (val == LB){
				shift;
				findreg(regno);
				shiftover(RB);
				sawindex = 1;
D 2
				ap->areg2 = regno;
E 2
I 2
				ap->a_areg2 = regno;
E 2
			}
			break;

		}	/*end of the switch to process an arg*/
	    }	/*end of processing an argument*/

	    if (sawmul){
			/*
			 * Make a concession for *(%r)
			 * meaning *0(%r) 
			 */
D 2
			if (ap->atype == ABASE) {
				ap->atype = ADISP;
				xp->xtype = XABS;
				xp->xvalue = 0;
				xp->xloc = 0;
				ap->xp = xp++;
E 2
I 2
			if (ap->a_atype == ABASE) {
				ap->a_atype = ADISP;
				xp->e_xtype = XABS;
D 8
				xp->e_xvalue = 0;
E 8
I 8
				xp->e_number = Znumber;
				xp->e_number.num_tag = TYPL;
E 8
				xp->e_xloc = 0;
				ap->a_xp = xp++;
E 2
			}
D 2
			ap->atype |= ASTAR;
E 2
I 2
			ap->a_atype |= ASTAR;
E 2
			sawmul = 0;
	    }
	    if (sawindex){
D 2
		ap->atype |= AINDX;
E 2
I 2
		ap->a_atype |= AINDX;
E 2
		sawindex = 0;
	    }
D 2
	    ap->dispsize = sawsize == 0 ? d124 : sawsize;
E 2
I 2
	    ap->a_dispsize = sawsize == 0 ? d124 : sawsize;
E 2
		if (val != CM) break;
		shiftover(CM);
	}	/*processing all the arguments*/

	if (argcnt > 6){
		yyerror("More than 6 arguments");
		goto errorfix;
I 11
	}

	/*
	 *	See if this is a case instruction,
	 *	so we can set up tests on the following
	 *	vector of branch displacements
	 */
	if (yyopcode.Op_eopcode == CORE){
		switch(yyopcode.Op_popcode){
		case 0x8f:	/* caseb */
		case 0xaf:	/* casew */
		case 0xcf:	/* casel */
			incasetable++;
			break;
		default:
			incasetable = 0;
			break;
		}
E 11
	}

D 8
	insout(seg_type, arglist,
E 8
I 8
	insout(yyopcode, arglist,
E 8
		auxval == INSTn ? argcnt : - argcnt);
	break;

D 8
   case IFLOAT:	curlen = 4;	goto floatlist;
I 3
   case IQUAD:
E 3
   case IDOUBLE: 
	curlen = 8;
      floatlist:	
E 8
I 8
   case IQUAD:		toconv = TYPQ;	goto bignumlist;
   case IOCTA:		toconv = TYPO;	goto bignumlist;

   case IFFLOAT:	toconv = TYPF;	goto bignumlist;
   case IDFLOAT:	toconv = TYPD;	goto bignumlist;
   case IGFLOAT:	toconv = TYPG;	goto bignumlist;
   case IHFLOAT:	toconv = TYPH;	goto bignumlist;
   bignumlist:	
E 8
	/*
D 8
	 *	eat a list of floating point numbers
E 8
I 8
	 *	eat a list of non 32 bit numbers.
	 *	IQUAD and IOCTA can, possibly, return
	 *	INT's, if the numbers are "small".
	 *
	 *	The value of the numbers is coming back
	 *	as an expression, NOT in yybignum.
E 8
	 */
D 8
	shift;
	if (val == FLTNUM){
		/* KLS MOD */
		float flocal;
E 8
I 8
	shift;	/* over the opener */
	if ((val == BIGNUM) || (val == INT)){
E 8
		do{
D 8
			if (val == CM) shift;
			if (val != FLTNUM) {
			  ERROR("floating number expected");
E 8
I 8
			if ((val != BIGNUM) && (val != INT)){
				ERROR(ty_float[toconv]
				   ? "floating number expected"
				   : "integer number expected" );
E 8
			}
D 2
			dotp->xvalue += curlen;
E 2
I 2
D 8
			dotp->e_xvalue += curlen;
E 2
#ifdef UNIX
			if (passno == 2) {
			  if(curlen == 8)
			   bwrite((char *)&(((union Double *)yylval)->dvalue),
				curlen, txtfil);
			  else  {
			   flocal = ((union Double *)yylval)->dvalue;
			   bwrite((char *)&flocal, curlen, txtfil);
			  }
E 8
I 8
			dotp->e_xvalue += ty_nbyte[toconv];
			if (passno == 2){
				bignumwrite(
					((struct exp *)yylval)->e_number,
					toconv);
E 8
			}
D 8
#endif UNIX

#ifdef VMS
			if (passno == 2) {
			   puchar(vms_obj_ptr,-4);
			   pulong(vms_obj_ptr,
			    ((struct exp *)yylval)
				->doub_MSW);
			   if (curlen==8) {
			    puchar(vms_obj_ptr,-4);
			    pulong(vms_obj_ptr,
			    ((struct exp *)yylval)
				->doub_LSW);
			   }
			   if((vms_obj_ptr-sobuf) > 400) {
			    write(objfil,sobuf,vms_obj_ptr-sobuf);
			    vms_obj_ptr = sobuf + 1;
			   }
			}
#endif VMS
			shift;
E 8
			xp = explist;
D 8
		} while (val == CM);
E 8
I 8
			shift;		/* over this number */
			if (auxval = (val == CM))
				shift;	/* over the comma */
		} while (auxval);	/* as long as there are commas */
E 8
	}
	break;
I 8
	/* end of the case for initialized big numbers */
E 8
    }	/*end of the switch for looking at each reserved word*/

D 8
     continue;
E 8
I 8
	continue;
E 8

   errorfix: 
	/*
	 *	got here by either requesting to skip to the
	 *	end of this statement, or by erroring out and
	 *	wanting to apply panic mode recovery
	 */
	while (    (val != NL) 
		&& (val != SEMI) 
		&& (val != PARSEEOF)
	      ){
		shift;
	}
	if (val == NL)
		lineno++;
	shift;

    }	/*end of the loop to read the entire file, line by line*/

}	/*end of yyparse*/
	
/*
 *	Process a register declaration of the form
 *	% <expr>
 *
 *	Note:
 *		The scanner has already processed funny registers of the form
 *	%dd[+-]*, where dd is a decimal number in the range 00 to 15 (optional
 *	preceding zero digit).  If there was any space between the % and
 *	the digit, the scanner wouldn't have recognized it, so we
 *	hack it out here.
 */
D 8
int funnyreg(val, regnoback)		/*what the read head will sit on*/
	int	val;			/*what the read head is sitting on*/
E 8
I 8
inttoktype funnyreg(val, regnoback)	/*what the read head will sit on*/
	inttoktype	val;		/*what the read head is sitting on*/
E 8
	int	*regnoback;		/*call by return*/
{
D 8
	register	struct	exp *locxp;
			struct	exp *loc1xp;
			struct	exp **ptrloc1xp = & loc1xp;
E 8
I 8
	reg	struct	exp *locxp;
		struct	exp *loc1xp;
		struct	exp **ptrloc1xp = & loc1xp;
E 8

	expr(locxp, val);	/*and leave the current read head with value*/
	if ( (passno == 2) &&
D 2
	    (   locxp->xtype & XTYPE != XABS
	     || locxp->xvalue < 0
	     || locxp->xvalue >= 16 
E 2
I 2
D 8
	    (   locxp->e_xtype & XTYPE != XABS
	     || locxp->e_xvalue < 0
	     || locxp->e_xvalue >= 16 
E 8
I 8
	    (   (locxp->e_xtype & XTYPE) != XABS
	     || (locxp->e_xvalue < 0)
	     || (locxp->e_xvalue >= 16)
E 8
E 2
	    )
	  ){
		yyerror("Illegal register");
		return(0);
	}
D 2
	*regnoback = locxp->xvalue;
E 2
I 2
	*regnoback = locxp->e_xvalue;
E 2
	return(val);
} 
I 10
/*
 *	Shift over error
 */
shiftoerror(token)
	int	token;
{
	char	*tok_to_name();
	yyerror("%s expected", tok_to_name(token));
}
E 10

/*VARARGS1*/
yyerror(s, a1, a2,a3,a4,a5)
	char	*s;
{
D 5
	FILE		*sink;
E 5

D 5
#ifdef DEBUG
	sink = stdout;
#else not DEBUG
	sink = stderr;
#endif DEBUG
E 5
I 5
#define	sink stdout
E 5

D 8
	if (anyerrs == 0 && ! silent) 
E 8
I 8
	if (anyerrs == 0 && anywarnings == 0 && ! silent) 
E 8
		fprintf(sink, "Assembler:\n");
	anyerrs++;
D 8
	if (silent) return;
	
E 8
I 8
	if (silent)
		return;
E 8
	fprintf(sink, "\"%s\", line %d: ", dotsname, lineno);
	fprintf(sink, s, a1, a2,a3,a4,a5);
	fprintf(sink, "\n");
I 8
#undef sink
E 8
}
I 7

/*VARARGS1*/
yywarning(s, a1, a2,a3,a4,a5)
	char	*s;
{
D 8

E 8
#define	sink stdout
D 8

	if (anyerrs == 0 && ! silent) 
E 8
I 8
	if (anyerrs == 0 && anywarnings == 0 && ! silent) 
E 8
		fprintf(sink, "Assembler:\n");
D 8
	if (silent) return;
	
E 8
I 8
	anywarnings++;
	if (silent)
		return;
E 8
	fprintf(sink, "\"%s\", line %d: WARNING: ", dotsname, lineno);
	fprintf(sink, s, a1, a2,a3,a4,a5);
	fprintf(sink, "\n");
I 8
#undef sink
E 8
}
E 7
E 1
