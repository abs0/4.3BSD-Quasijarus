h41407
s 00001/00001/00728
d D 5.2 87/10/22 10:06:19 bostic 16 15
c ANSI C; sprintf now returns an int.
e
s 00005/00002/00724
d D 5.1 85/04/30 14:16:44 dist 15 14
c Add copyright
e
s 00048/00028/00678
d D 4.14 83/08/11 10:59:50 rrh 14 13
c The string pool now includes just those strings referenced in
c the symbol table; this fixes laziness in the previous deltas
e
s 00035/00023/00671
d D 4.13 83/07/01 09:43:04 rrh 13 12
c savestr now saves strings in both a file and in core; fixed
c a bug with savestr being too generous in saving strings in core
e
s 00001/00055/00693
d D 4.12 83/06/30 19:19:54 rrh 12 11
c bye bye fixed names (eg, FLEXNAMES is not set)
e
s 00063/00053/00685
d D 4.11 83/06/30 19:03:03 rrh 11 10
c The string pool is maintained both in core, and in a second tmp file.
c names are in core and on the file; strings are just in the file.  The file 
c is maintained as a string table per a.out(5), and tacked onto the a.out file
c at the very end.  The string table has more than need be, since discarde 
c labels and .ascii strings find their way (harmlessly) into the string table.
c the string file maintained with stdio; nothing fancy, even if -V set
e
s 00004/00008/00734
d D 4.10 83/06/30 07:58:46 rrh 10 9
c consolidate character buffer length definitions (manifest constants)
c into one place, with documentation
e
s 00035/00040/00707
d D 4.9 83/06/29 20:06:20 rrh 9 8
c DQ quoted strings no longer put into the temp file, but stored
c directly into the string spool; this fixes serious efficiency/size bugs
c in the temp files. DQ strings put into string pool with preceding 2 bytes
c indicating the length, with a trailing null byte not accounted for in the
c 2byte length; .asciz and .stabs change length and magically get null byte;
c all string moves (lookup and reader) done by subroutine call & movc3
e
s 00013/00002/00734
d D 4.8 83/05/19 19:36:38 csvaf 8 7
c kludged stabfix to cope with (name+val) locations
e
s 00047/00014/00689
d D 4.7 82/02/14 16:34:35 rrh 7 6
c Fix reported and outstanding bugs. Reformat some text for
c readability/understandability. Assembles new instructions  for G and H
c format floating numbers & new queue instructions
c asscan.c split into 4 files; two additional files to construct and
c manipulate G and H format numbers, with analog for atof()
c Numerical accuracy of new atof() not verified; standard atof() used
c for F and D floating numbers.  As does NOT use G and H instructions itself
e
s 00002/00000/00701
d D 4.6 80/11/05 20:12:59 henry 6 5
c Fixing so that can compile with FLEXNAMES turned off
e
s 00025/00034/00676
d D 4.5 80/08/20 09:50:25 henry 5 4
c Catch relocation of floats and 8 byte qtys; restructure outrel
e
s 00001/00001/00709
d D 4.4 80/08/16 15:01:27 bill 4 3
c restore sccs line
e
s 00006/00002/00704
d D 4.3 80/08/16 15:00:07 bill 3 2
c -R
e
s 00091/00112/00615
d D 4.2 80/08/15 18:03:58 henry 2 1
c use struct nlist; change field names; vgrind format fixes
e
s 00727/00000/00000
d D 4.1 80/08/13 18:55:27 bill 1 0
c date and time created 80/08/13 18:55:27 by bill
e
u
U
t
T
I 1
D 7
/* Copyright (c) 1980 Regents of the University of California */
D 3
static	char sccsid[] = "%Z%%M% %I% %G%";
E 3
I 3
D 4
static	char sccsid[] = "@(#)assyms.c 4.2 8/15/80";
E 4
I 4
static	char sccsid[] = "%Z%%M% %I% %G%";
E 7
I 7
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
D 15
static char sccsid[] = "%Z%%M% %I% %G%";
E 15
I 15
static char sccsid[] = "%W% (Berkeley) %G%";
E 15
#endif not lint

E 7
E 4
E 3
#include <stdio.h>
#include <ctype.h>
D 2
#include <sys/types.h>
#include <a.out.h>
E 2
#include "as.h"
#include "asscan.h"
#include "assyms.h"

/*
 *	Managers for chunks of symbols allocated from calloc()
 *	We maintain a linked list of such chunks.
 *
 */
struct	allocbox	*allochead;	/*head of chunk list*/
struct	allocbox	*alloctail;	/*tail*/
struct	allocbox	*newbox;	/*for creating a new chunk*/
struct	symtab		*nextsym;	/*next symbol free*/
int			symsleft;	/*slots left in current chunk*/

struct	symtab		**symptrs;
struct	symtab		**symdelim[NLOC + NLOC +1];
struct	symtab		**symptrub;
/*
 *	Managers for the dynamically extendable hash table
 */
struct	hashdallop	*htab;

D 7
struct	instab		*itab[NINST];	/*maps opcodes to instructions*/
E 7
I 7
Iptr	*itab[NINST];	/*maps opcodes to instructions*/
E 7
/*
 *	Counts what went into the symbol table, so that the
 *	size of the symbol table can be computed.
 */
int	nsyms;		/* total number in the symbol table */
int	njxxx;		/* number of jxxx entrys */
int	nforgotten;	/* number of symbols erroneously entered */
int	nlabels;	/* number of label entries */
D 7
int	hshused;	/* number of hash slots used */
E 7

/*
 *	Managers of the symbol literal storage.
D 10
 *	If we have flexible names, then we allocate BUFSIZ long
 *	string, and pack strings into that.  Otherwise, we allocate
 *	symbol storage in fixed hunks NCPS long when we allocate space
 *	for other symbol attributes.
E 10
 */
D 9
#ifdef	FLEXNAMES
E 9
struct	strpool		*strplhead = 0;
D 2
#else
char			*namebuffer;
#endif
E 2
I 2
D 9
#endif	FLEXNAMES
E 9
E 2

symtabinit()
{
	allochead = 0;
	alloctail = 0;
	nextsym = 0;
	symsleft = 0;
D 9
#ifdef FLEXNAMES
E 9
	strpoolalloc();		/* get the first strpool storage area */
D 9
#endif FLEXNAMES
E 9
	htab = 0;
	htaballoc();		/* get the first part of the hash table */
}

/*
 *	Install all known instructions in the symbol table
 */
syminstall()
{
D 7
	register	struct	instab	*ip;
E 7
I 7
	register	Iptr	ip;
E 7
	register	struct	symtab	**hp;
	register	char	*p1, *p2;
I 7
	register	int	i;
E 7

I 7
	for (i = 0; i < NINST; i++)
		itab[i] = (Iptr*)BADPOINT;

E 7
D 2
	for (ip=instab; ip->name!=0; ip++) {
		p1 = ip->name;
E 2
I 2
D 11
#ifdef FLEXNAMES
D 7
	for (ip = (struct instab *)instab; ip->s_name != 0; ip++) {
E 7
I 7
	for (ip = (Iptr)instab; ip->s_name != 0; ip++) {
E 7
#else not FLEXNAMES
D 7
	for (ip = (struct instab *)instab; ip->s_name[0] != '\0'; ip++){
E 7
I 7
	for (ip = (Iptr)instab; ip->s_name[0] != '\0'; ip++){
E 7
#endif not FLEXNAMES
		p1 = ip->s_name;
E 11
I 11
	for (ip = (Iptr)instab; FETCHNAME(ip)[0]; ip++) {
		p1 = FETCHNAME(ip);
E 11
E 2
		p2 = yytext;
		while (*p2++ = *p1++);
		hp = lookup(0);		/* 0 => don't install this*/
		if (*hp==NULL) {
			*hp = (struct symtab *)ip;
D 2
			if (   (ip->tag!=INSTn)
			    && (ip->tag!=INST0)
			    && (ip->tag!=0))
E 2
I 2
			if (   (ip->s_tag!=INSTn)
			    && (ip->s_tag!=INST0)
			    && (ip->s_tag!=0))
E 2
				continue; /* was pseudo-op */
D 2
			itab[ip->opcode & 0xFF] = ip;
E 2
I 2
D 7
			itab[ip->i_opcode & 0xFF] = ip;
E 7
I 7
			if (itab[ip->i_eopcode] == (Iptr*)BADPOINT){
				itab[ip->i_eopcode] =
					(Iptr*)ClearCalloc(256, sizeof(Iptr));
				for (i = 0; i < 256; i++)
					itab[ip->i_eopcode][i] =
						(Iptr)BADPOINT;
			}
			itab[ip->i_eopcode][ip->i_popcode] = ip;
E 7
E 2
		}
	}
}	/*end of syminstall*/

D 14

E 14
I 14
#define ISLABEL(sp) \
	(   (!savelabels) \
	 && (sp->s_tag == LABELID) \
	 && (STRPLACE(sp) & STR_CORE) \
	 && (FETCHNAME(sp)[0] == 'L'))
E 14
/*
 *	Assign final values to symbols,
 *	and overwrite the index field with its relative position in
 *	the symbol table we give to the loader.
 */
extern struct exec hdr;

freezesymtab()
{
	register	struct	symtab	*sp;
				long	bs;
	register	int	relpos = 0;
	register	struct	symtab		*ubsp;
	register	struct	allocbox	*allocwalk;

	DECLITERATE(allocwalk, sp, ubsp)
	{
D 2
		if (sp->tag >= IGNOREBOUND)
E 2
I 2
		if (sp->s_tag >= IGNOREBOUND)
E 2
			continue; 		/*totally ignore jxxx entries */
		/*
		 *	Ignore stabs, but give them a symbol table index
		 */
D 2
		if (sp->type & STABFLAG)
E 2
I 2
		if (sp->s_type & STABFLAG)
E 2
			goto assignindex;
D 2
		if ((sp->type&XTYPE)==XUNDEF)
			sp->type = XXTRN+XUNDEF;
		else if ((sp->type&XTYPE)==XDATA)
			sp->value += usedot[sp->index].xvalue;
		else if ((sp->type&XTYPE)==XTEXT)
			sp->value += usedot[sp->index].xvalue;
		else if ((sp->type&XTYPE)==XBSS) {
			bs = sp->value;
			sp->value = hdr.a_bss + datbase;
E 2
I 2
		if ((sp->s_type&XTYPE)==XUNDEF)
			sp->s_type = XXTRN+XUNDEF;
		else if ((sp->s_type&XTYPE)==XDATA)
			sp->s_value += usedot[sp->s_index].e_xvalue;
		else if ((sp->s_type&XTYPE)==XTEXT)
			sp->s_value += usedot[sp->s_index].e_xvalue;
		else if ((sp->s_type&XTYPE)==XBSS) {
			bs = sp->s_value;
			sp->s_value = hdr.a_bss + datbase;
E 2
			hdr.a_bss += bs;
		}
	   assignindex:
D 2
		if (    (sp->name[0] != 'L')
		     || (sp->tag != LABELID)
E 2
I 2
D 11
		if (    (sp->s_name[0] != 'L')
E 11
I 11
D 14
		if (    (FETCHNAME(sp)[0] != 'L')
E 11
		     || (sp->s_tag != LABELID)
E 2
		     || savelabels
		     )			/*then, we will write it later on*/
D 2
				sp->index = relpos++;
E 2
I 2
				sp->s_index = relpos++;
E 14
I 14
		if (!ISLABEL(sp))
			sp->s_index = relpos++;
E 14
E 2
	}
}

D 14


E 14
/*
 *	For all of the stabs that had their final value undefined during pass 1
 *	and during pass 2 assign a final value.
 *	We have already given stab entrys a initial approximation
 *	when we constsructed the sorted symbol table.
 *	Iteration order doesn't matter.
 */
D 8
stabfix() {
E 8
I 8

stabfix()
{
E 8
	register struct symtab *sp, **cosp;
	register struct symtab *p;
	
	SYMITERATE(cosp, sp){
D 2
		if(sp->ptype && (sp->type & STABFLAG)) {	
			p = sp->dest;	
			sp->value = p->value;	
			sp->index = p->index;
			sp->type = p->type;
E 2
I 2
		if(sp->s_ptype && (sp->s_type & STABFLAG)) {	
			p = sp->s_dest;	
D 8
			sp->s_value = p->s_value;	
E 8
I 8
/* 
 * STABFLOATING indicates that the offset has been saved in s_desc, s_other
 */
			if(sp->s_tag == STABFLOATING) {
			  sp->s_value = ( ( ((unsigned char) sp->s_other) << 16)  					| ( (unsigned short) sp->s_desc )  );
			  sp->s_value = sp->s_value + p->s_value;
			}
			else sp->s_value = p->s_value;
E 8
			sp->s_index = p->s_index;
			sp->s_type = p->s_type;
I 8

              
E 8
E 2
		}
	}
}

char *Calloc(number, size)
	int	number, size;
{
	register	char *newstuff;
D 7
	newstuff = (char *)sbrk(number*size);
E 7
I 7
	char	*sbrk();
	newstuff = sbrk(number*size);
E 7
	if ((int)newstuff == -1){
		yyerror("Ran out of Memory");
		delexit();
	}
	return(newstuff);
}

char *ClearCalloc(number, size)
	int	number, size;
{
	register	char	*newstuff;		/* r11 */
	register	int	length = number * size;	/* r10 */
I 7
#ifdef lint
	length = length;
#endif length
E 7
	newstuff = Calloc(number, size);
	asm("movc5 $0, (r0), $0, r10, (r11)");
	return(newstuff);
}

struct symtab *symalloc()
{
	if (symsleft == 0){
		newbox = (struct allocbox *)ClearCalloc(1,ALLOCQTY);
		symsleft = SYMDALLOP;
		nextsym = &newbox->symslots[0];
D 2
#ifndef FLEXNAMES
		namebuffer = &newbox->symnames[0];
#endif not FLEXNAMES
E 2
		if (alloctail == 0){
			allochead = alloctail = newbox;
		} else {
			alloctail->nextalloc = newbox;
			alloctail = newbox;
		}
	}
	--symsleft;
	++nsyms;
D 2
#ifndef FLEXNAMES
	nextsym->name = namebuffer;
	namebuffer += NCPS;
#endif not FLEXNAMES
E 2
	return(nextsym++);
}

D 9
#ifdef FLEXNAMES
E 9
strpoolalloc()
{
	register	struct	strpool	*new;

	new = (struct strpool *)Calloc(1, sizeof (struct strpool));
	new->str_nalloc = 0;
	new->str_next = strplhead;
	strplhead = new;
}
D 9
#endif FLEXNAMES
E 9

symcmp(Pptr, Qptr)
	struct symtab **Pptr, **Qptr;
{
	register struct symtab *p = *Pptr;
	register struct symtab *q = *Qptr;
D 2
	if (p->index < q->index)
E 2
I 2
	if (p->s_index < q->s_index)
E 2
		return(-1);
D 2
	if (p->index > q->index)
E 2
I 2
	if (p->s_index > q->s_index)
E 2
		return(1);
D 2
	if (p->value < q->value)
E 2
I 2
	if (p->s_value < q->s_value)
E 2
		return(-1);
D 2
	if (p->value > q->value)
E 2
I 2
	if (p->s_value > q->s_value)
E 2
		return(1);
	/*
	 *	Force jxxx entries to virtually preceed labels defined
	 *	to follow the jxxxx instruction, so that bumping the
	 *	jxxx instruction correctly fixes up the following labels
	 */
D 2
	if (p->tag >= IGNOREBOUND)	/*p points to a jxxx*/
E 2
I 2
	if (p->s_tag >= IGNOREBOUND)	/*p points to a jxxx*/
E 2
		return(-1);		
D 2
	if (q->tag >= IGNOREBOUND)
E 2
I 2
	if (q->s_tag >= IGNOREBOUND)
E 2
		return(1);
	/*
	 *	both are now just plain labels; the relative order doesn't
	 *	matter.  Both can't be jxxxes, as they would have different
	 *	values.
	 */
	return(0);			
}	/*end of symcmp*/

/*
 *	We construct the auxiliary table of pointers, symptrs and
 *	symdelim
 *	We also assign preliminary values to stab entries that did not yet
 *	have an absolute value (because they initially referred to
 *	forward references). We don't worry about .stabds, as they
 *	already have an estimated final value
 */

sortsymtab()
{
	register	struct	symtab	*sp;
	register	struct	symtab	**cowalk;
	register	struct	allocbox	*allocwalk;
			struct	symtab	*ubsp;
				int	segno;
				int	slotno;
				int	symsin;	/*number put into symptrs*/

	symptrs =  (struct symtab **)Calloc(nsyms + 2, sizeof *symptrs);
	/*
	 *	Allocate one word at the beginning of the symptr array
	 *	so that backwards scans through the symptr array will
	 *	work correctly while scanning through the zeroth segment
	 */
	*symptrs++ = 0;
	cowalk = symptrs;
	symsin = 0;
	DECLITERATE(allocwalk, sp, ubsp) {
D 2
		if (sp->ptype && (sp->type &STABFLAG)){
			sp->value = sp->dest->value;
			sp->index = sp->dest->index;
E 2
I 2
		if (sp->s_ptype && (sp->s_type &STABFLAG)){
			sp->s_value = sp->s_dest->s_value;
			sp->s_index = sp->s_dest->s_index;
E 2
		}
		if (symsin >= nsyms)
			yyerror("INTERNAL ERROR: overfilled symbol table indirection table");
		*cowalk++ = sp;
		symsin++;
	}
	if (symsin != nsyms)
		yyerror("INTERNAL ERROR: installed %d syms, should have installed %d",
			symsin, nsyms);
	symptrub = &symptrs[nsyms ];
	qsort(symptrs, nsyms, sizeof *symptrs, symcmp);
	symdelim[0] = symptrs;
	for (cowalk = symptrs, sp = *cowalk, segno = 0, slotno = 1;
	     segno < NLOC + NLOC;
	     segno++, slotno++){
D 2
		for (; sp && sp->index == segno; sp = *++cowalk);
E 2
I 2
		for (; sp && sp->s_index == segno; sp = *++cowalk);
E 2
		symdelim[slotno] = cowalk;	/*forms the ub delimeter*/
	}
}	/*end of sortsymtab*/

#ifdef DEBUG
dumpsymtab()
{
	register	int	segno;
	register	struct symtab *sp, **cosp, *ub;
	char		*tagstring();

	printf("Symbol Table dump:\n");
	for (segno = 0; segno < NLOC + NLOC; segno++){
		printf("Segment number: %d\n", segno);
		SEGITERATE(segno, 0, 0, cosp, sp, ub, ++){
D 12
#ifdef FLEXNAMES
E 12
			printf("\tSeg: %d \"%s\" value: %d index: %d tag %s\n",
D 2
				segno, sp->name,
				sp->value, sp->index,
				tagstring(sp->tag));
E 2
I 2
D 11
				segno, sp->s_name,
E 11
I 11
				segno, FETCHNAME(sp),
E 11
				sp->s_value, sp->s_index,
				tagstring(sp->s_tag));
E 2
D 12
#else not FLEXNAMES
			printf("\tSeg: %d \"%*.*s\" value: %d index: %d tag %s\n",
D 2
				segno, NCPS, NCPS, sp->name,
				sp->value, sp->index,
				tagstring(sp->tag));
E 2
I 2
D 10
				segno, NCPS, NCPS, sp->s_name,
E 10
I 10
D 11
				segno, NCPName, NCPName, sp->s_name,
E 11
I 11
				segno, NCPName, NCPName, FETCHNAME(sp),
E 11
E 10
				sp->s_value, sp->s_index,
				tagstring(sp->s_tag));
E 2
#endif not FLEXNAMES
E 12
			printf("\t\ttype: %d jxbump %d jxfear: %d\n",
D 2
				sp->type, sp->jxbump, sp->jxfear);
E 2
I 2
				sp->s_type, sp->s_jxbump, sp->s_jxfear);
E 2
		}
		printf("\n\n");
	}
}

static	char tagbuff[4];

char *tagstring(tag)
	unsigned	char	tag;
{
	switch(tag){
		case JXACTIVE:		return("active");
		case JXNOTYET:		return("notyet");
		case JXALIGN:		return("align");
		case JXQUESTIONABLE:	return("jxquestionable");
		case JXINACTIVE:	return("inactive");
		case JXTUNNEL:		return("tunnel");
		case OBSOLETE:		return("obsolete");
		case IGNOREBOUND:	return("ignorebound");
		case STABFLOATING:	return("stabfloating");
		case STABFIXED:		return("stabfixed");
		case LABELID:		return("labelid");
		case OKTOBUMP:		return("oktobump");
		case ISET:		return("iset");
		case ILSYM:		return("ilsym");
D 16
		default:		sprintf(tagbuff,"%d", tag);
E 16
I 16
		default:		(void)sprintf(tagbuff,"%d", tag);
E 16
					return(tagbuff);
	}
}
#endif DEBUG

htaballoc()
{
	register	struct	hashdallop	*new;
	new = (struct hashdallop *)ClearCalloc(1, sizeof (struct hashdallop));
	if (htab == 0)
		htab = new;
	else {		/* add AFTER the 1st slot */
		new->h_next = htab->h_next;
		htab->h_next = new;
	}
}

#define 	HASHCLOGGED	(NHASH / 2)

/*
 *	Lookup a symbol stored in extern yytext.
 *	All strings passed in via extern yytext had better have
 *	a trailing null.  Strings are placed in yytext for hashing by
 *	syminstall() and by yylex();
 *
 *	We take pains to avoid function calls; this functdion
 *	is called quite frequently, and the calls overhead
 *	in the vax contributes significantly to the overall
 *	execution speed of as.
 */
struct symtab **lookup(instflg)
	int	instflg;		/* 0: don't install */
{
	static	 int		initialprobe;
	register struct	symtab 	**hp;
	register char 		*from;
	register char		*to;
	register	int	len;
	register	int	nprobes;
D 11
	static	 struct hashdallop *hdallop;
	static	 struct symtab	**emptyslot;
	static 	 struct hashdallop *emptyhd;
	static	 struct	symtab	**hp_ub;
E 11
I 11
	static	struct	hashdallop *hdallop;
	static	struct	symtab	**emptyslot;
	static 	struct	hashdallop *emptyhd;
	static	struct	symtab	**hp_ub;
D 13
	static	struct	strdesc	strdp;
E 13
E 11

	emptyslot = 0;
	for (nprobes = 0, from = yytext;
	     *from;
	     nprobes <<= 2, nprobes += *from++)
		continue;
	nprobes += from[-1] << 5;
	nprobes %= NHASH;
	if (nprobes < 0)
		nprobes += NHASH;

	initialprobe = nprobes;
	for (hdallop = htab; hdallop != 0; hdallop = hdallop->h_next){
		for (hp = &(hdallop->h_htab[initialprobe]),
				nprobes = 1,
				hp_ub = &(hdallop->h_htab[NHASH]);
		     (*hp) && (nprobes < NHASH);
				hp += nprobes,
				hp -= (hp >= hp_ub) ? NHASH:0,
				nprobes += 2)
		{
			from = yytext;
D 2
			to = (*hp)->name;
E 2
I 2
D 11
			to = (*hp)->s_name;
E 11
I 11
			to = FETCHNAME(*hp);
E 11
E 2
D 12
#ifndef FLEXNAMES
D 10
			for (len = 0; (len<NCPS) && *from; len++)
E 10
I 10
			for (len = 0; (len<NCPName) && *from; len++)
E 10
				if (*from++ != *to++)
					goto nextprobe;
D 10
			if (len >= NCPS)	/*both are maximal length*/
E 10
I 10
			if (len >= NCPName)	/*both are maximal length*/
E 10
				return(hp);
			if (*to == 0)		/*assert *from == 0*/
				return(hp);
#else FLEXNAMES
E 12
			while (*from && *to)
				if (*from++ != *to++)
					goto nextprobe;
			if (*to == *from)	/*assert both are == 0*/
				return(hp);
D 12
#endif FLEXNAMES

	nextprobe: ;
E 12
I 12
		nextprobe: ;
E 12
		}
		if (*hp == 0 && emptyslot == 0 &&
		    hdallop->h_nused < HASHCLOGGED) {
			emptyslot = hp;
			emptyhd = hdallop;
		}
	}
	if (emptyslot == 0) {
		htaballoc();
		hdallop = htab->h_next;		/* aren't we smart! */
		hp = &hdallop->h_htab[initialprobe];
	} else {
		hdallop = emptyhd;
		hp = emptyslot;
	}
	if (instflg) {
		*hp = symalloc();
		hdallop->h_nused++;
D 12
#ifndef FLEXNAMES
D 2
		for(len = 0, from = yytext, to = (*hp)->name; (len<NCPS); len++)
E 2
I 2
D 9
		for(len = 0, from = yytext, to = (*hp)->s_name; (len<NCPS); len++)
E 2
 			if ((*to++ = *from++) == '\0')
 				break;
E 9
I 9
D 10
		strncpy((*hp)->s_name, yytext, NCPS);
E 10
I 10
D 11
		strncpy((*hp)->s_name, yytext, NCPName);
E 11
I 11
		strncpy(FETCHNAME(*hp), yytext, NCPName);
E 11
E 10
E 9
#else FLEXNAMES
E 12
D 9
		for (from = yytext, len = 1; *from++; len++)
E 9
I 9
		for (from = yytext, len = 0; *from++; len++)
E 9
			continue;
D 9
		if (len >= (STRPOOLDALLOP - strplhead->str_nalloc))
			strpoolalloc();
D 2
		for ( (*hp)->name = to = strplhead->str_names + strplhead->str_nalloc, from = yytext;
E 2
I 2
		for ( (*hp)->s_name = to = strplhead->str_names + strplhead->str_nalloc, from = yytext;
E 2
		     ( (*to++ = *from++) != '\0'); )
			continue;
		strplhead->str_nalloc += len;
E 9
I 9
D 13
		/*
D 11
		 *	save string and trailing null
E 11
I 11
		 *	save string and trailing null, both
		 *	internally, and in the string temporary file
E 11
		 */
D 11
		(*hp)->s_name = savestr(yytext, len + 1);
E 11
I 11
		strdp.sd_stroff = strfilepos;
		strdp.sd_place = STR_BOTH;
		strdp.sd_strlen = len + 1;	/* length and null */
		fputs(yytext, strfile);		/* string */
		putc(0, strfile);		/* null */
		strfilepos += strdp.sd_strlen;
		(*hp)->s_name = (char *)savestr(yytext, &strdp);
E 13
I 13
		(*hp)->s_name = (char *)savestr(yytext, len + 1, STR_BOTH);
E 13
E 11
E 9
D 12
#endif FLEXNAMES
E 12
	}
	return(hp);
}	/*end of lookup*/
D 9

I 6
#ifdef FLEXNAMES
E 6
char *savestr(str)
	char *str;
E 9
I 9
/*
D 11
 *	save a string str, length len in the string pool.
 *	string known just by its length; can have or not have trailing nulls.
 *
 *	The length of the string occurs as a short just before
 *	the character pointer returned.
E 11
I 11
D 13
 *	save a string str, descriptor strdp, in the string pool
E 13
I 13
 *	save a string str with len in the places indicated by place
E 13
E 11
 */
D 11
char *savestr(str, len)
E 11
I 11
D 13
struct strdesc *savestr(str, strdp)
E 13
I 13
struct strdesc *savestr(str, len, place)
E 13
E 11
	char	*str;
D 11
	int	len;
E 11
I 11
D 13
	struct	strdesc	*strdp;
E 13
I 13
	int	len;
	int	place;
E 13
E 11
E 9
{
D 9
	register int len;
	register char *from, *to;
	char *res;
E 9
I 9
D 11
	char	*res;
E 11
I 11
	reg	struct	strdesc	*res;
		int	tlen;
E 11
E 9
D 13

E 13
I 13
	/*
	 *	Compute the total length of the record to live in core
	 */
E 13
D 9
	for (from = str, len = 1; *from++; len++)
		continue;
	if (len >= (STRPOOLDALLOP - strplhead->str_nalloc))
E 9
I 9
D 11
	if (len + sizeof(lgtype) >= (STRPOOLDALLOP - strplhead->str_nalloc))
E 11
I 11
	tlen = sizeof(struct strdesc) - sizeof(res->sd_string);
D 13
	if (strdp->sd_place & STR_FILE)
		tlen += strdp->sd_strlen;

E 13
I 13
	if (place & STR_CORE)
		tlen += len;
	/*
	 *	See if there is enough space for the record,
	 *	and allocate the record.
	 */
E 13
	if (tlen >= (STRPOOLDALLOP - strplhead->str_nalloc))
E 11
E 9
		strpoolalloc();
D 9
	for ( res = to = strplhead->str_names + strplhead->str_nalloc, from = str;
		     ( (*to++ = *from++) != '\0'); )
			continue;
	strplhead->str_nalloc += len;
	return (res);
E 9
I 9
D 11
	res = strplhead->str_names + strplhead->str_nalloc;
	plgtype(res, len);
	movestr(res, str, len);
	strplhead->str_nalloc += sizeof(lgtype) + len;
E 11
I 11
	res = (struct strdesc *)(strplhead->str_names + strplhead->str_nalloc);
D 13
	res[0] = *strdp;
	if (strdp->sd_place & STR_FILE)
		movestr(res[0].sd_string, str, strdp->sd_strlen);
E 13
I 13
	/*
	 *	Save the string information that is always present
	 */
	res->sd_stroff = strfilepos;
	res->sd_strlen = len;
	res->sd_place = place;
	/*
	 *	Now, save the string itself.  If str is null, then
	 *	the characters have already been dumped to the file
	 */
	if ((place & STR_CORE) && str)
		movestr(res[0].sd_string, str, len);
	if (place & STR_FILE){
		if (str){
			fwrite(str, 1, len, strfile);
		}
		strfilepos += len;
	}
	/*
	 *	Adjust the in core string pool size
	 */
E 13
	strplhead->str_nalloc += tlen;
E 11
	return(res);
E 9
}
I 6
D 9
#endif FLEXNAMES
E 9
E 6
D 13

E 13
/*
D 5
 *	The following two tables are indexed by
 *		{LEN1,LEN2,LEN4,LEN8} | {PCREL,0}
 *	Note that PCREL = 1
 */
int	reflen[] = 	{0,   0, 1, 1, 2, 2, 4, 4, 8, 8};	
int	lgreflen[] = 	{-1, -1, 0, 0, 1, 1, 2, 2, 3, 3};

/*
E 5
 *	The relocation information is saved internally in an array of
 *	lists of relocation buffers.  The relocation buffers are
 *	exactly the same size as a token buffer; if we use VM for the
 *	temporary file we reclaim this storage, otherwise we create
 *	them by mallocing.
 */
#define	RELBUFLG	TOKBUFLG
#define	NRELOC		((TOKBUFLG - \
			  (sizeof (int) + sizeof (struct relbufdesc *)) \
			) / (sizeof (struct relocation_info)))

struct	relbufdesc{
	int	rel_count;
	struct	relbufdesc	*rel_next;
	struct	relocation_info	rel_reloc[NRELOC];
};
extern	struct	relbufdesc	*tok_free;
#define	rel_free tok_free
static	struct	relbufdesc	*rel_temp;
D 2
struct	relocation_info r_can_1PC = {0,0,0,0,0,0};
struct	relocation_info	r_can_0PC = {0,0,0,0,0,0};
E 2
I 2
struct	relocation_info r_can_1PC;
struct	relocation_info	r_can_0PC;
E 2

initoutrel()
{
I 2
	r_can_0PC.r_address = 0;
	r_can_0PC.r_symbolnum = 0;
	r_can_0PC.r_pcrel = 0;
	r_can_0PC.r_length = 0;
	r_can_0PC.r_extern = 0;

	r_can_1PC = r_can_0PC;
E 2
	r_can_1PC.r_pcrel = 1;
}

D 5
outrel(pval,reftype,reltype,xsym)
	long 		*pval;
	register int 	reftype,reltype;
	struct symtab 	*xsym;
E 5
I 5
outrel(xp, reloc_how)
	register	struct	exp	*xp;
D 7
	int		reloc_how;	/* TYPB..TYPD + (possibly)RELOC_PCREL */
E 7
I 7
	int		reloc_how;	/* TYPB..TYPH + (possibly)RELOC_PCREL */
E 7
E 5
{
D 5
/*
 *	reftype: PCREL or not, plus length LEN1, LEN2, LEN4, LEN8
 *	reltype: csect ("segment") number (XTEXT, XDATA, ...) associated with 'val'
 * 	xsym: symbol table pointer
 */
	short	this_reflen;
	struct	relocation_info	reloc;
E 5
I 5
	struct		relocation_info	reloc;
	register	int	x_type_mask;	
D 9
	int		pcrel;
E 9
I 9
			int	pcrel;
E 9
E 5

D 5
	this_reflen = reflen[reftype];
E 5
I 5
	x_type_mask = xp->e_xtype & ~XFORW;
	pcrel = reloc_how & RELOC_PCREL;
	reloc_how &= ~RELOC_PCREL;
	
E 5
	if (bitoff&07)
		yyerror("Padding error");
D 5
	reltype &= ~XFORW;
	if (reltype == XUNDEF)
E 5
I 5
	if (x_type_mask == XUNDEF)
E 5
		yyerror("Undefined reference");

D 5
	if (reltype != XABS || reftype & PCREL) {
		reloc = (reftype & PCREL)? r_can_1PC : r_can_0PC;
E 5
I 5
	if ( (x_type_mask != XABS) || pcrel ) {
		if (ty_NORELOC[reloc_how])
D 7
			yyerror("Illegal Relocation of float, double or quad.");
E 7
I 7
			yyerror("Illegal Relocation of floating or large int number.");
E 7
		reloc = pcrel ? r_can_1PC : r_can_0PC;
E 5
D 2
		reloc.r_address = dotp->xvalue -
E 2
I 2
		reloc.r_address = dotp->e_xvalue -
E 2
D 3
			( (dotp < &usedot[NLOC]) ? 0 : datbase );
E 3
I 3
		    ( (dotp < &usedot[NLOC] || readonlydata) ? 0 : datbase );
E 3
D 5
		reloc.r_length = lgreflen[reftype];
		switch(reltype){
E 5
I 5
		reloc.r_length = ty_nlg[reloc_how];
		switch(x_type_mask){
E 5
			case XXTRN | XUNDEF:
D 2
				reloc.r_symbolnum = xsym->index;
E 2
I 2
D 5
				reloc.r_symbolnum = xsym->s_index;
E 5
I 5
				reloc.r_symbolnum = xp->e_xname->s_index;
E 5
E 2
				reloc.r_extern = 1;
				break;
			default:
I 3
D 5
				if (readonlydata && (reltype&~XXTRN) == XDATA)
					reltype = XTEXT | (reltype&XXTRN);
E 3
				reloc.r_symbolnum = reltype;
E 5
I 5
				if (readonlydata && (x_type_mask&~XXTRN) == XDATA)
					x_type_mask = XTEXT | (x_type_mask&XXTRN);
				reloc.r_symbolnum = x_type_mask;
E 5
				break;
		}
		if ( (relfil == 0) || (relfil->rel_count >= NRELOC) ){
			if (rel_free){
				rel_temp = rel_free;
				rel_free = rel_temp->rel_next;
			} else {
				rel_temp = (struct relbufdesc *)
					Calloc(1,sizeof (struct relbufdesc));
			}
			rel_temp->rel_count = 0;
			rel_temp->rel_next = relfil;
			relfil = rusefile[dotp - &usedot[0]] = rel_temp;
		}
		relfil->rel_reloc[relfil->rel_count++] = reloc;
	}
	/*
	 *	write the unrelocated value to the text file
	 */
D 2
	dotp->xvalue += this_reflen;
E 2
I 2
D 5
	dotp->e_xvalue += this_reflen;
E 2
	if (reftype & PCREL)
D 2
		*pval -= dotp->xvalue;
E 2
I 2
		*pval -= dotp->e_xvalue;
E 2
	bwrite((char *)pval, this_reflen, txtfil);
E 5
I 5
	dotp->e_xvalue += ty_nbyte[reloc_how];
	if (pcrel)
		xp->e_xvalue -= dotp->e_xvalue;
D 7
	bwrite((char *)&(xp->e_xvalue), ty_nbyte[reloc_how], txtfil);
E 7
I 7
	switch(reloc_how){
	case TYPO:
	case TYPQ:

	case TYPF:
	case TYPD:
	case TYPG:
	case TYPH:
		bignumwrite(xp->e_number, reloc_how);
		break;

	default:
		bwrite((char *)&(xp->e_xvalue), ty_nbyte[reloc_how], txtfil);
		break;
	}
E 7
E 5
}
/*
 *	Flush out all of the relocation information.
 *	Note that the individual lists of buffers are in
 *	reverse order, so we must reverse them
 */
off_t closeoutrel(relocfile)
	BFILE	*relocfile;
{
	int	locindex;
	u_long	Closeoutrel();

	trsize = 0;
	for (locindex = 0; locindex < NLOC; locindex++){
		trsize += Closeoutrel(rusefile[locindex], relocfile);
	}
	drsize = 0;
	for (locindex = 0; locindex < NLOC; locindex++){
		drsize += Closeoutrel(rusefile[NLOC + locindex], relocfile);
	}
	return(trsize + drsize);
}

u_long Closeoutrel(relfil, relocfile)
	struct	relbufdesc	*relfil;
	BFILE	*relocfile;
{
	u_long	tail;
	if (relfil == 0)
		return(0L);
	tail = Closeoutrel(relfil->rel_next, relocfile);
	bwrite((char *)&relfil->rel_reloc[0],
		relfil->rel_count * sizeof (struct relocation_info),
		relocfile);
	return(tail + relfil->rel_count * sizeof (struct relocation_info));
}

I 2
#define NOUTSYMS (nsyms - njxxx - nforgotten - (savelabels ? 0 : nlabels))
E 2
int sizesymtab()
{
D 2
	struct symtab *sp;

#define NOUTSYMS (nsyms - njxxx - nforgotten - (savelabels ? 0 : nlabels))

	return (
		(
#ifndef FLEXNAMES
		 NCPS
#else FLEXNAMES
		 sizeof (long)
#endif FLEXNAMES
		 + sizeof (sp->ptype)
		 + sizeof (sp->other)
		 + sizeof (sp->desc)
		 + sizeof (sp->value)
		) 
		*	NOUTSYMS
	);
E 2
I 2
	return (sizeof (struct nlist) * NOUTSYMS);
E 2
}
D 12

#ifdef FLEXNAMES
E 12
/*
D 12
 *	We write out the flexible length character strings for  names
 *	in two stages.
D 9
 *	1)	We have always! maintain a fixed sized name list entry;
E 9
I 9
 *	1)	We always! maintain a fixed sized name list entry;
E 9
 *	the string is indexed by a four byte quantity from the beginning
 *	of the string pool area.  Index 0 is reserved, and indicates
 *	that there is no associated string. The first valid index is 4.
 *	2)	 We concatenate together and write all of the strings
 *	in the string pool at the end of the name list. The first 
 *	four bytes in the string pool are indexed only by 0 (see above);
 *	they contain the total number of bytes in the string pool.
 */
#endif FLEXNAMES

/*
E 12
 *	Write out n symbols to file f, beginning at p
 *	ignoring symbols that are obsolete, jxxx instructions, and
 *	possibly, labels
 */
D 12

E 12
int symwrite(symfile)
	BFILE *symfile;
{
D 11
	int	symsout;			/*those actually written*/
	int	symsdesired = NOUTSYMS;
	register	struct	symtab *sp, *ub;
E 11
I 11
		int	symsout;		/*those actually written*/
		int	symsdesired = NOUTSYMS;
	reg	struct	symtab *sp, *ub;
E 11
D 12
#ifdef FLEXNAMES
E 12
D 2
	register	int	len;
E 2
I 2
D 11
	char		*name;			/* temp to save the name */
E 2
	long		stroff	= sizeof (stroff);
E 11
I 11
		char	*name;			/* temp to save the name */
D 14
		int	nread;
		char	rbuf[2048];
		int	i;
E 14
I 14
		int	totalstr;
E 14
E 11
I 2
	/*
	 *	We use sp->s_index to hold the length of the
	 *	name; it isn't used for anything else
	 */
E 2
D 12
#endif FLEXNAMES

E 12
	register	struct	allocbox	*allocwalk;

	symsout = 0;
D 14
	DECLITERATE(allocwalk, sp, ub)
	{
E 14
I 14
	totalstr = sizeof(totalstr);
	DECLITERATE(allocwalk, sp, ub) {
E 14
D 2
		if (sp->tag >= IGNOREBOUND) 
E 2
I 2
		if (sp->s_tag >= IGNOREBOUND) 
E 2
			continue;
D 2
		if ((sp->name[0] == 'L') && (sp->tag == LABELID) && !savelabels)
E 2
I 2
D 11
		if ((sp->s_name[0] == 'L') && (sp->s_tag == LABELID) && !savelabels)
E 11
I 11
D 14
		if ((FETCHNAME(sp)[0] == 'L') && (sp->s_tag == LABELID) && !savelabels)
E 14
I 14
		if (ISLABEL(sp))
E 14
E 11
E 2
			continue;
		symsout++;
D 2
#ifndef FLEXNAMES
		bwrite(sp->name, NCPS, symfile);
#else FLEXNAMES
		len = strlen(sp->name);
		if (len != 0) {
			bwrite(&stroff, sizeof (stroff), symfile);
			stroff += len + 1;
		} else
			bwrite("\0\0\0\0", sizeof (stroff), symfile);
E 2
I 2
D 14

E 14
D 12
#ifdef FLEXNAMES
E 12
		name = sp->s_name;		/* save pointer */
D 9
		if ( (sp->s_index = strlen(sp->s_name)) != 0){
E 9
I 9
		/*
		 *	the length of the symbol table string
D 14
		 *	always includes the trailing null
E 14
I 14
		 *	always includes the trailing null;
		 *	blast the pointer to its a.out value.
E 14
		 */
D 11
		if (sp->s_name && (sp->s_index = STRLEN(sp->s_name))){
E 9
			sp->s_nmx = stroff;	/* clobber pointer */
D 9
			stroff += sp->s_index + 1;
E 9
I 9
			stroff += sp->s_index;
E 11
I 11
		if (sp->s_name && (sp->s_index = STRLEN(sp))){
D 14
			sp->s_nmx = STROFF(sp);	/* clobber */
E 14
I 14
			sp->s_nmx = totalstr;
			totalstr += sp->s_index;
E 14
E 11
E 9
		} else {
D 9
			sp->s_nmx = 0;		/* clobber pointer */
E 9
I 9
			sp->s_nmx = 0;
E 9
		}
D 11
#endif
E 11
I 11
D 12
#ifdef DEBUG
		printf("symbol %d: nmx == %d\n", symsout, sp->s_nmx);
#endif DEBUG
#endif FLEXNAMES
E 12
E 11
D 14
		sp->s_type = (sp->s_ptype != 0) ? sp->s_ptype : (sp->s_type & (~XFORW));
E 14
I 14
		if (sp->s_ptype != 0)
			sp->s_type = sp->s_ptype;
		else
			sp->s_type = (sp->s_type & (~XFORW));
E 14
I 3
		if (readonlydata && (sp->s_type&~N_EXT) == N_DATA)
			sp->s_type = N_TEXT | (sp->s_type & N_EXT);
E 3
D 7
		bwrite(&sp->s_nm, sizeof (struct nlist), symfile);
E 7
I 7
		bwrite((char *)&sp->s_nm, sizeof (struct nlist), symfile);
E 7
D 12
#ifdef FLEXNAMES
E 12
		sp->s_name = name;		/* restore pointer */
E 2
D 12
#endif FLEXNAMES
E 12
D 2
		sp->type &= ~XFORW;
		bputc( ( (sp->ptype != 0) ? sp->ptype : sp->type ),
			symfile);
	/*
	 *	WATCH OUT.  THIS DEPENDS THAT THE ALLOCATION OF
	 *	the four fields ptype, other, desc and value are
	 *	contiguous, which is compiler dependent.
	 */
		bwrite((char *)&(sp->other),
			  sizeof (sp->other)
			+ sizeof (sp->desc)
		        + sizeof (sp->value),
		       symfile
		);
E 2
	}
	if (symsout != symsdesired)
		yyerror("INTERNAL ERROR: Wrote %d symbols, wanted to write %d symbols\n",
			symsout, symsdesired);
D 12
#ifdef FLEXNAMES
E 12
	/*
D 11
	 *	Pass 2 through the string pool
E 11
I 11
D 14
	 *	Copy the string temporary file to the symbol file,
	 *	copying all the strings and symbols we ever saw,
	 *	including labels, stabs strings, ascii strings, etc.
	 *	This is slightly wasteful.
E 14
I 14
	 *	Construct the string pool from the symbols that were written,
	 *	possibly fetching from the string file if the string
	 *	is not core resident.
E 14
E 11
	 */
D 11
	symsout = 0;
D 7
	bwrite(&stroff, sizeof (stroff), symfile);
E 7
I 7
	bwrite((char *)&stroff, sizeof (stroff), symfile);
E 7
	stroff = sizeof (stroff);
	symsout = 0;
	DECLITERATE(allocwalk, sp, ub)
	{
D 2
		if (sp->tag >= IGNOREBOUND) 
E 2
I 2
		if (sp->s_tag >= IGNOREBOUND) 
E 2
			continue;
D 2
		if ((sp->name[0] == 'L') && (sp->tag == LABELID) && !savelabels)
E 2
I 2
		if ((sp->s_name[0] == 'L') && (sp->s_tag == LABELID) && !savelabels)
E 2
			continue;
D 2
		len = strlen(sp->name);
		if (len)
			bwrite(sp->name, len + 1, symfile);
E 2
I 2
D 9
		sp->s_index = strlen(sp->s_name);
		if (sp->s_index)
			bwrite(sp->s_name, sp->s_index + 1, symfile);
E 9
I 9
		if (sp->s_name && (sp->s_index = STRLEN(sp->s_name))){
			bwrite(sp->s_name, sp->s_index, symfile);
E 11
I 11
D 14
	i = 0;
	while((nread = read(strfile->_file, rbuf, sizeof(rbuf))) > 0){
		if (i == 0){
D 12
#ifdef DEBUG
			printf("%d bytes of strings\n", strfilepos);
#endif DEBUG
E 12
			((int *)rbuf)[0] = strfilepos;
E 14
I 14
	bwrite(&totalstr, sizeof(totalstr), symfile);
	symsout = 0;
	DECLITERATE(allocwalk, sp, ub) {
		if (sp->s_tag >= IGNOREBOUND) 
			continue;
		if (ISLABEL(sp))
			continue;
		symsout++;
		if (STRLEN(sp) > 0){
		 if (STRPLACE(sp) & STR_CORE){
			bwrite(FETCHNAME(sp), STRLEN(sp), symfile);
		 } else if (STRPLACE(sp) & STR_FILE){
			char	rbuf[2048];
			int	left, nread;
			fseek(strfile, STROFF(sp), 0);
			for (left = STRLEN(sp); left > 0; left -= nread){
				nread = fread(rbuf, sizeof(char),
					min(sizeof(rbuf), left), strfile);
				if (nread == 0)
					break;
				bwrite(rbuf, nread, symfile);
			}
		 }
E 14
E 11
		}
I 11
D 14
		bwrite(rbuf, nread, symfile);
		i++;
E 14
E 11
E 9
E 2
	}
I 14
	if (symsout != symsdesired)
		yyerror("INTERNAL ERROR: Wrote %d strings, wanted %d\n",
			symsout, symsdesired);
E 14
D 12
#endif FLEXNAMES
E 12
}
E 1
