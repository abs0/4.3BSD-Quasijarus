h06510
s 00002/00004/00433
d D 5.2 00/08/29 22:10:41 msokolov 14 13
c Complete jxxx relaxation overhaul. We now relax three-way without -J!
c -J is now ignored. We now also relax SOBs, AOBs, and ACBs. See the comments in
c addsob() in c2 for the motivation.
c As a side effect, we now require -d4.
c As yet another side effect, the handling of branches in instrs has been
c significantly cleaned up for c2.
e
s 00005/00002/00432
d D 5.1 85/04/24 12:13:55 dist 13 12
c Add Copyright
e
s 00002/00002/00432
d D 4.12 84/07/25 11:34:02 ralph 12 11
c just warn branches to undef externals not local defined globals
e
s 00000/00006/00434
d D 4.11 83/06/30 19:11:20 rrh 11 10
c bye bye VMS: UNIX only.  All the preceeding changes to the symbol
c table stuff were never tested under VMS
e
s 00004/00004/00436
d D 4.10 83/06/30 19:02:06 rrh 10 9
c The string pool is maintained both in core, and in a second tmp file.
c names are in core and on the file; strings are just in the file.  The file 
c is maintained as a string table per a.out(5), and tacked onto the a.out file
c at the very end.  The string table has more than need be, since discarde 
c labels and .ascii strings find their way (harmlessly) into the string table.
c the string file maintained with stdio; nothing fancy, even if -V set
e
s 00002/00002/00438
d D 4.9 83/06/13 17:01:57 rrh 9 8
c suggest use of -J flag in yyerror on branch too far
e
s 00233/00168/00207
d D 4.8 82/02/14 16:31:19 rrh 8 7
c Fix reported and outstanding bugs. Reformat some text for
c readability/understandability. Assembles new instructions  for G and H
c format floating numbers & new queue instructions
c asscan.c split into 4 files; two additional files to construct and
c manipulate G and H format numbers, with analog for atof()
c Numerical accuracy of new atof() not verified; standard atof() used
c for F and D floating numbers.  As does NOT use G and H instructions itself
e
s 00025/00005/00350
d D 4.7 80/11/05 20:32:49 henry 7 6
c Change two switches to get casel instruction
e
s 00041/00041/00314
d D 4.6 80/09/08 09:58:33 henry 6 5
c Change variable name "a" to "argtype" to not confuse sdb
e
s 00051/00033/00304
d D 4.5 80/08/20 09:49:29 henry 5 4
c Catch relocation of floats and 8 byte qtys; restructure outrel
e
s 00066/00066/00271
d D 4.4 80/08/19 14:42:50 henry 4 3
c Integrate argcompat into insout; rename locals in insout
e
s 00010/00004/00327
d D 4.3 80/08/19 14:07:02 henry 3 2
c Fix "movab $expression, dst"; is now an error
e
s 00082/00086/00249
d D 4.2 80/08/15 18:02:41 henry 2 1
c use struct nlist; change field names; vgrind format fixes
e
s 00335/00000/00000
d D 4.1 80/08/13 18:55:07 bill 1 0
c date and time created 80/08/13 18:55:07 by bill
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
D 13
 *	Copyright (c) 1982 Regents of the University of California
E 13
I 13
 * Copyright (c) 1982 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 13
 */
I 13

E 13
#ifndef lint
D 13
static char sccsid[] = "%Z%%M% %I% %G%";
E 13
I 13
static char sccsid[] = "%W% (Berkeley) %G%";
E 13
#endif not lint

E 8
#include <stdio.h>
D 2
#include <sys/types.h>
#include <a.out.h>
E 2
#include "as.h"
#include "assyms.h"

I 5
D 8
/*
 *	Loader reference types  (plust PCREL) to bytes and lg bytes
 */
/*		LEN1	LEN1+PC	LEN2	LEN2+PC	LEN4	LEN4+PC	LEN8	LEN8+PC*/
int	reflen[] = 	/* {LEN*+PCREL} ==> number of bytes */
{0,	0,	1,	1,	2,	2,	4,	4,	8,	8};	
int	lgreflen[] =	/* {LEN*+PCREL} ==> lg number of bytes */ 
{-1,	-1,	0,	0,	1,	1,	2,	2,	3,	3};

/*
 *	Sizes to Loader reference types and type flags
 */
/*0	1	2	3	4	5	6	7	8*/
int	len124[] = 	/* {1,2,4,8} ==> {LEN1, LEN2, LEN4, LEN8} */
{0,	LEN1,	LEN2,	0,	LEN4,	0,	0,	0,	LEN8};
char	mod124[] = 	/* {1,2,4,8} ==> {bits to construct operands */
{0,	0x00,	0x20,	0,	0x40,	0,	0,	0,	0};
int	type_124[] =	/* {1,2,4,8} ==> {TYPB, TYPW, TYPL, TYPQ} */
{0,	 TYPB,	TYPW,	 0,	 TYPL,	 0,	 0,	 0,	 TYPQ};

/*
 *	type flags to Loader reference and byte lengths
 */
/*TYPB	TYPW	TYPL	TYPQ	TYPF	TYPD*/
int	ty_NORELOC[] =	/* {TYPB..TYPD} ==> {1 if relocation not OK */
{0,	0,	0,	1,	1,	1};
int	ty_LEN[] =	/* {TYPB..TYPD} ==> {LEN1..LEN8} */
{LEN1,	LEN2,	LEN4,	LEN8,	LEN4,	LEN8};
int	ty_nbyte[] =	/* {TYPB..TYPD} ==> {1,2,4,8} */
{1,	2,	4,	8,	4,	8};
int	ty_nlg[] =	/* {TYPB..TYPD} ==> lg{1,2,4,8} */
{0,	1,	2,	3,	2,	3};

E 5
insout(op, ap, nact)
	struct arg *ap;
E 8
I 8
insout(opcode, ap, nact)
	struct	Opcode	opcode;
	struct	arg	*ap;
	int	nact;
E 8
{
D 4
	int jxxflg;

E 4
I 4
D 8
	int		jxxflg;
	register	struct	instab	*ip;		/* the instruction */
	register	struct	arg	*ap_walk;	/* actual param walk */
	register	int	i;
	register	int	ap_type;		/* actual param type */
	register	int	ap_type_mask;		/* masked actual param */
E 4
	op &= 0xFF;
E 8
I 8
	int	jxxflg;
	reg	struct	instab	*ip;		/* the instruction */
	reg	struct	arg	*ap_walk;	/* actual param walk */
	reg	int	i;
	reg	int	ap_type;		/* actual param type */
	reg	int	ap_type_mask;		/* masked actual param */

E 8
	jxxflg = nact;
	if (nact < 0)
		nact = -nact;
	if (passno == 1) {
D 4
		register struct arg 	*ap2;
		register struct instab 	*ip;
		int 			i,nexp;
		ip = itab[op];
D 2
		nexp = ip->nargs;
E 2
I 2
		nexp = ip->i_nargs;
E 2
		if (nact < nexp)
			yyerror("Too few arguments");
		if (nact > nexp) {
			yyerror("Too many arguments");
			nact = nexp;
		}
		/*
		 *	Check argument compatability with instruction template
		 */
		for (ap2 = ap+nact, i = nact; --i >= 0;)
D 2
			argcompat(--ap2, ip->argtype[i], i+1);
E 2
I 2
			argcompat(--ap2, fetcharg(ip, i), i+1);
E 2
	}
E 4
I 4
D 8
	    ip = itab[op];
	    if (nact < ip->i_nargs)
		yyerror("Too few arguments");
	    if (nact > ip->i_nargs) {
		yyerror("Too many arguments");
		nact = ip->i_nargs;
	    }
E 8
I 8
		if (!(ITABCHECK(opcode)))
			panic("Botched reference into itab");
		ip = ITABFETCH(opcode);
		if (nact < ip->i_nargs)
			yyerror("Too few arguments");
		if (nact > ip->i_nargs) {
			yyerror("Too many arguments");
			nact = ip->i_nargs;
		}
E 8
	    /*
	     *	Check argument compatability with instruction template
	     */
	    for (ap_walk = ap, i = 1; i <= nact; ap_walk++, i++){
D 5
		ap_type = ap_walk->a_type;
E 5
I 5
		ap_type = ap_walk->a_atype;
E 5
		ap_type_mask = ap_type & AMASK;
D 5
		switch( (fetcharg(ip, i-1)) & AMASK){	/* type of fp */
E 5
I 5
D 7
		switch( (fetcharg(ip, i-1)) & ACCESSMASK){	/* type of fp */
E 5
		case ACCB:
E 7
I 7
		/*
D 8
		 *	The switch value is >> by 3 so that the switch
E 8
I 8
		 *	The switch value is >> by TYPLG so that the switch
E 8
		 *	code is dense, not implemented as a sequence
		 *	of branches but implemented as a casel.
		 *	In addition, cases ACCI and ACCR are added to force
		 *	dense switch code.
I 8
		 *	switch on the type of fp
E 8
		 */
D 8
		switch( ((fetcharg(ip, i-1)) & ACCESSMASK)>>3){	/* type of fp */
		case ACCI >> 3:
		case ACCR >> 3:
E 8
I 8
		switch( ((fetcharg(ip, i-1)) & ACCESSMASK) >> TYPLG){
		case ACCI >> TYPLG:
		case ACCR >> TYPLG:
E 8
			break;
D 8
		case ACCB >> 3:
E 8
I 8
		case ACCB >> TYPLG:
E 8
E 7
			if ( !((ap_type_mask == AEXP) || (ap_type_mask == AIMM)) ){
				yyerror("arg %d, branch displacement must be an expression",i);
				return;
			}
			break;
D 7
		case ACCA:
E 7
I 7
D 8
		case ACCA >> 3:
E 8
I 8
		case ACCA >> TYPLG:
E 8
E 7
			switch(ap_type_mask){
			case AREG:	yyerror("arg %d, addressing a register",i);
					return;
			case AIMM:	if ( !(ap_type & ASTAR) ){
					 yyerror("arg %d, addressing an immediate operand",i);
					 return;
					}
			}
			break;
D 7
		case ACCM:
		case ACCW:
E 7
I 7
D 8
		case ACCM >> 3:
		case ACCW >> 3:
E 8
I 8
		case ACCM >> TYPLG:
		case ACCW >> TYPLG:
E 8
E 7
			switch(ap_type_mask){
			case AIMM:	if (!(ap_type&ASTAR)) {
					 yyerror("arg %d, modifying a constant",i);
					 return;
					}
			}
			break;
		}	/* end of the switch on fp_type */
		if (ap_type & AINDX) {
			if (ap_walk->a_areg2==0xF) {
				yyerror("arg %d, PC used as index",i);
				return;
			}
			switch(ap_type_mask){
			case AREG:	yyerror("arg %d, indexing the register file",i);
					return;
			case AIMM:	yyerror("arg %d, indexing a constant",i);
					return;
D 5
			case DECR:
			case INCR:	if (ap_walk->a_areg1==ap_walk->a_areg2) {
E 5
I 5
			case ADECR:
			case AINCR:	if (ap_walk->a_areg1==ap_walk->a_areg2) {
E 5
						yyerror("arg %d, indexing with modified register",i);
						return;
					}
					break;
			}	/* end of switch on ap_type_mask */
		} /* end of AINDX */
	   }
	} /* both passes here */
E 4
	if (jxxflg < 0)
D 8
		ijxout(op, ap, nact);
	else putins(op, ap, nact);
E 8
I 8
		ijxout(opcode, ap, nact);
	else
		putins(opcode, ap, nact);
E 8
D 4
}

argcompat(act, exp, i)
	struct arg *act;
	int exp,i;
{
	register 	at,atm;

D 2
	at = act->atype;
E 2
I 2
	at = act->a_atype;
E 2
	atm = at & AMASK;

	if ( (exp & ACCB) && (!((atm == AEXP) || (atm == AIMM))) ){
		yyerror("arg %d, branch displacement must be an expression",i);
		return;
	}
D 3
	if ((exp & ACCA) && (atm == AREG)) {
		yyerror("arg %d, addressing a register",i);
		return;
E 3
I 3
	if (exp & ACCA){
		if (atm == AREG) {
			yyerror("arg %d, addressing a register",i);
			return;
		}
		if ( (atm == AIMM) && !(at & ASTAR) ){
			yyerror("arg %d, addressing an immediate operand",i);
			return;
		}
E 3
	}
	if ((exp&ACCW) && (atm==AIMM) && !(at&ASTAR)) {
		yyerror("arg %d, modifying a constant",i);
		return;
	}
	if (at & AINDX) {
D 2
		if (act->areg2==017) {
E 2
I 2
		if (act->a_areg2==017) {
E 2
			yyerror("arg %d, PC used as index",i);
			return;
		}
		if (atm==AREG) {
			yyerror("arg %d, indexing the register file",i);
			return;
		}
		if (atm==AIMM) {
			yyerror("arg %d, indexing a constant",i);
			return;
		}
D 2
		if (((atm==ADECR) || (atm==AINCR)) && (act->areg1==act->areg2)) {
E 2
I 2
		if (((atm==ADECR) || (atm==AINCR)) && (act->a_areg1==act->a_areg2)) {
E 2
			yyerror("arg %d, indexing with modified register",i);
			return;
		}
	}
E 4
}

D 14
extern	int d124;
D 5
	int len124[] = 	{0,LEN1,LEN2,0,LEN4};
	char mod124[] = {0,0x00,0x20,0,0x40};
E 5

E 14
D 8
putins(op, ap, n)
	/*
	 *	n had better be positive
	 */
E 8
I 8
putins(opcode, ap, n)
	struct	Opcode	opcode;
E 8
	register struct arg *ap;
I 8
	int	n;			/* Must be positive */
E 8
{
D 8
	register struct exp 	*xp;
D 6
	register int 		a;
E 6
I 6
	register int 		argtype;
E 6
D 5
	int 			i,xtrab;
E 5
I 5
	int 			i;
	int			reloc_how;
E 8
I 8
	reg	struct exp 	*xp;
	reg	int 	argtype;
		int 	i;
		int	reloc_how;
		int	value;
E 8
E 5

#ifdef DEBUG
	fflush(stdout);
#endif
	if (passno == 2)
		goto PASS2;

D 2
	dotp->xvalue += n+1;	/* 1 for the opcode, at least 1 per arg */
	for (i=0; i<n; i++,ap++) {/* some args take more than 1 byte */
	    xtrab = 0;
	    a=ap->atype;
E 2
I 2
D 8
	dotp->e_xvalue += n+1;		/* 1 for the opcode, at least 1 per arg */
E 8
I 8
	dotp->e_xvalue += n;		/* at least one byte per arg */
	switch(opcode.Op_eopcode){
	case NEW:
	case CORE:
		dotp->e_xvalue += 1;	/* 1 byte opcode */
		break;
	case ESCD:
	case ESCF:
		dotp->e_xvalue += 2;	/* 2 byte opcode */
		break;
	default:
		panic("Bad escape opcode");
	}

E 8
	for (i=0; i<n; i++,ap++) {	/* some args take more than 1 byte */
D 6
	    a = ap->a_atype;
E 2
	    if (a & AINDX)
E 6
I 6
	    argtype = ap->a_atype;
	    if (argtype & AINDX)
E 6
D 2
		dotp->xvalue++;
E 2
I 2
		dotp->e_xvalue++;
I 7
	    /*
	     *	This switch has been fixed by enumerating the no action
	     *	alternatives (those that have 1 one byte of code)
	     *	so that a casel instruction is emitted.
	     */
E 7
E 2
D 6
	    switch (a&~(AINDX|ASTAR)) {
E 6
I 6
	    switch (argtype&~(AINDX|ASTAR)) {
I 7
		case AREG:
		case ABASE:
		case ADECR:
		case AINCR:
			break;
E 7
E 6
		case AEXP: 
D 2
			a = itab[op]->argtype[i];
E 2
I 2
D 6
			a = fetcharg(itab[op], i);
E 2
			if (a == ACCB+TYPB)
E 6
I 6
D 8
			argtype = fetcharg(itab[op], i);
			if (argtype == ACCB+TYPB)
E 8
I 8
			argtype = fetcharg(ITABFETCH(opcode), i);
			if (argtype == A_BB)
E 8
E 6
				break;
D 6
			if (a==ACCB+TYPW){
E 6
I 6
D 8
			if (argtype==ACCB+TYPW){
E 8
I 8
			if (argtype == A_BW){
E 8
E 6
D 2
				dotp->xvalue++;
E 2
I 2
				dotp->e_xvalue++;
E 2
				break;
			}
			/*
			 *	Reduces to PC relative
			 */
D 2
			xtrab++;
			dotp->xvalue += ap->dispsize;
E 2
I 2
			dotp->e_xvalue += ap->a_dispsize;
E 2
			break;
		
		case ADISP: 
D 2
			xp=ap->xp;
			if ((xp->xtype&XTYPE)!=XABS || xp->xtype&XFORW){
				dotp->xvalue += ap->dispsize;
E 2
I 2
			xp=ap->a_xp;
			if ((xp->e_xtype&XTYPE)!=XABS || xp->e_xtype&XFORW){
				dotp->e_xvalue += ap->a_dispsize;
E 2
				break;
			}
D 2
			if (xp->xvalue==0 && !(a&ASTAR))
E 2
I 2
D 6
			if (xp->e_xvalue==0 && !(a&ASTAR))
E 6
I 6
			if (xp->e_xvalue==0 && !(argtype&ASTAR))
E 6
E 2
				break;
D 2
			dotp->xvalue++;
			if ((xp->xvalue<MINBYTE) || (xp->xvalue>MAXBYTE))
				dotp->xvalue++;
			if ((xp->xvalue<MINWORD) || (xp->xvalue>MAXWORD))
				dotp->xvalue += 2;
E 2
I 2
D 8
			dotp->e_xvalue++;
			if ((xp->e_xvalue<MINBYTE) || (xp->e_xvalue>MAXBYTE))
				dotp->e_xvalue++;
			if ((xp->e_xvalue<MINWORD) || (xp->e_xvalue>MAXWORD))
				dotp->e_xvalue += 2;
E 8
I 8
			dotp->e_xvalue += 1;
			if (ISBYTE(xp->e_xvalue))
				break;
			dotp->e_xvalue += 1;
			if (ISWORD(xp->e_xvalue))
				break;
			dotp->e_xvalue += 2;
E 8
E 2
			break;

		case AIMM: 
D 2
			if (ap->atype&ASTAR) a=TYPL;
E 2
I 2
D 6
			if (ap->a_atype&ASTAR) a=TYPL;
E 6
I 6
D 8
			if (ap->a_atype&ASTAR) argtype=TYPL;
E 6
E 2
			else {
D 2
				a = itab[op]->argtype[i];
E 2
I 2
D 6
				a = fetcharg(itab[op], i);
E 2
				if (a&ACCA)
					a = TYPL;
E 6
I 6
				argtype = fetcharg(itab[op], i);
E 8
I 8
			if (ap->a_atype&ASTAR) {
				argtype=TYPL;
			} else {
				argtype = fetcharg(ITABFETCH(opcode), i);
E 8
				if (argtype&ACCA)
					argtype = TYPL;
E 6
				else
D 6
					a &= TYPMASK;
E 6
I 6
					argtype &= TYPMASK;
E 6
D 2
				xp = ap->xp;
				if (   ((xp->xtype&XTYPE)==XABS)
				    && (!(xp->xtype&XFORW))
				    && (xp->xvalue>=0)
				    && (xp->xvalue<=63) 
				    && (xp->yvalue == 0)
E 2
I 2
				xp = ap->a_xp;
D 8
				if (   ((xp->e_xtype&XTYPE)==XABS)
				    && (!(xp->e_xtype&XFORW))
				    && (xp->e_xvalue>=0)
				    && (xp->e_xvalue<=63) 
				    && (xp->e_yvalue == 0)
E 2
D 6
				    && (a != TYPD)
				    && (a != TYPF)
E 6
I 6
				    && (argtype != TYPD)
				    && (argtype != TYPF)
E 6
				)
						break;
E 8
I 8
				if (immconstant(ap->a_xp, argtype, &value))
					break;
E 8
			}
D 6
			switch (a) {
E 6
I 6
D 8
			switch (argtype) {
E 6
			case TYPD:
			case TYPF:
D 2
				if (   !(((xp->xtype&XTYPE)==XABS)
				    && (!(xp->xtype&XFORW))
E 2
I 2
				if (   !(((xp->e_xtype&XTYPE)==XABS)
				    && (!(xp->e_xtype&XFORW))
E 2
				    && (slitflt(xp)))
				){
				/* it is NOT short */
D 2
					dotp->xvalue += ((a==TYPF)?
E 2
I 2
D 6
					dotp->e_xvalue += ((a==TYPF)?
E 6
I 6
					dotp->e_xvalue += ((argtype==TYPF)?
E 6
E 2
						4 : 8);
				}
				break;
			case TYPQ: 
D 2
				dotp->xvalue += 8;break;
E 2
I 2
				dotp->e_xvalue += 8;break;
E 2
			case TYPL:
D 2
				dotp->xvalue += 4;break;
E 2
I 2
				dotp->e_xvalue += 4;break;
E 2
			case TYPW: 
D 2
				dotp->xvalue += 2;break;
E 2
I 2
				dotp->e_xvalue += 2;break;
E 2
			case TYPB: 
D 2
				dotp->xvalue += 1;break;
E 2
I 2
				dotp->e_xvalue += 1;break;
E 2
D 6
			}	/*end of the switch on a*/
E 6
I 6
			}	/*end of the switch on argtype*/
E 8
I 8
			dotp->e_xvalue += ty_nbyte[argtype];
E 8
E 6
	    }	/*end of the switch on the type*/
	}	/*end of looping for all arguments*/
	return;

PASS2:
I 8
	/*
	 *	Output the opcode
	 */
	switch(opcode.Op_eopcode){
	case NEW:
		nnewopcodes++;
		break;
	case ESCD:
	case ESCF:
		nGHopcodes++;
		Outb(opcode.Op_eopcode);
		break;
	case CORE:
		break;
	default:
		panic("Bad escape opcode");
	}
	Outb(opcode.Op_popcode);
E 8

D 8
#ifdef UNIX
	outb(op); /* the opcode */
#endif UNIX
#ifdef VMS
	*vms_obj_ptr++ = -1; *vms_obj_ptr++ = (char)op;
D 2
	dotp->xvalue += 1;
E 2
I 2
	dotp->e_xvalue += 1;
E 2
#endif VMS

E 8
	for (i=0; i<n; i++,ap++) {/* now for the arguments */
D 2
		a=ap->atype;
		xp=ap->xp;
E 2
I 2
D 6
		a=ap->a_atype;
E 6
I 6
		argtype=ap->a_atype;
E 6
		xp=ap->a_xp;
E 2
D 5
		xtrab=0;
E 5
I 5
		reloc_how = TYPNONE;
E 5
D 6
		if (a&AINDX) {
E 6
I 6
		if (argtype&AINDX) {
E 6
D 8
#ifdef UNIX
D 2
			{ outb(0x40 | ap->areg2); }
E 2
I 2
			{ outb(0x40 | ap->a_areg2); }
E 2
#endif UNIX
#ifdef VMS
			{ *vms_obj_ptr++ = -1;
D 2
			  *vms_obj_ptr++ = (0x40 | ap->areg2);
			  dotp->xvalue += 1; }
E 2
I 2
			  *vms_obj_ptr++ = (0x40 | ap->a_areg2);
			  dotp->e_xvalue += 1; }
E 2
#endif VMS
E 8
I 8
			{ Outb(0x40 | ap->a_areg2); }
E 8
D 6
			a &= ~AINDX;
E 6
I 6
			argtype &= ~AINDX;
E 6
		}
D 6
		if (a&ASTAR) {
E 6
I 6
		if (argtype&ASTAR) {
E 6
D 2
			ap->areg1 |= 0x10;
E 2
I 2
			ap->a_areg1 |= 0x10;
E 2
D 6
			a &= ~ASTAR;
E 6
I 6
			argtype &= ~ASTAR;
E 6
		}
D 6
		switch (a) {
E 6
I 6
		switch (argtype) {
E 6
		case AREG:		/* %r */
D 2
			ap->areg1 |= 0x50;
E 2
I 2
			ap->a_areg1 |= 0x50;
E 2
			break; 
		case ABASE:		/* (%r) */
D 2
			ap->areg1 |= 0x60;
E 2
I 2
			ap->a_areg1 |= 0x60;
E 2
			break; 
		case ADECR: 		/* -(%r) */
D 2
			ap->areg1 |= 0x70;
E 2
I 2
			ap->a_areg1 |= 0x70;
E 2
			break; 
D 3
		case AINCR:		/* (%r) */
E 3
I 3
		case AINCR:		/* (%r)+ */
E 3
D 2
			ap->areg1 |= 0x80;
E 2
I 2
			ap->a_areg1 |= 0x80;
E 2
			break;
		case AEXP: /* expr */
D 2
			a = itab[op]->argtype[i];
E 2
I 2
D 6
			a = fetcharg(itab[op], i);
E 2
			if (a == ACCB+TYPB) {
D 2
				ap->areg1 = a = 
					xp->xvalue - (dotp->xvalue + 1);
E 2
I 2
				ap->a_areg1 = a = 
E 6
I 6
D 8
			argtype = fetcharg(itab[op], i);
			if (argtype == ACCB+TYPB) {
E 8
I 8
			argtype = fetcharg(ITABFETCH(opcode), i);
			if (argtype == A_BB) {
E 8
				ap->a_areg1 = argtype = 
E 6
					xp->e_xvalue - (dotp->e_xvalue + 1);
E 2
D 6
				if (a<MINBYTE || a>MAXBYTE)
E 6
I 6
D 8
				if (argtype<MINBYTE || argtype>MAXBYTE)
E 6
					yyerror("Branch too far"); break;
E 8
I 8
D 12
				if (xp->e_xtype & XXTRN)
E 12
I 12
				if ((xp->e_xtype & XTYPE) == XUNDEF)
E 12
					yywarning("%s: destination label is external",
D 10
						ITABFETCH(opcode)->s_name);
E 10
I 10
						FETCHNAME(ITABFETCH(opcode)));
E 10
				if (!ISBYTE(argtype))
D 9
					yyerror("%s: Branch too far: %d",
E 9
I 9
D 14
					yyerror("%s: Branch too far(%db): try -J flag",
E 14
I 14
					yyerror("%s: Branch too far(%db)",
E 14
E 9
D 10
						ITABFETCH(opcode)->s_name,
E 10
I 10
						FETCHNAME(ITABFETCH(opcode)),
E 10
						argtype);
				break;
E 8
			}
D 6
			if (a == ACCB+TYPW) {
D 2
				ap->areg1 = a = xp->xvalue
					-= dotp->xvalue + 2;
				xp->xtype = XABS;
E 2
I 2
				ap->a_areg1 = a = xp->e_xvalue
E 6
I 6
D 8
			if (argtype == ACCB+TYPW) {
E 8
I 8
			if (argtype == A_BW) {
E 8
				ap->a_areg1 = argtype = xp->e_xvalue
E 6
					-= dotp->e_xvalue + 2;
I 8
D 12
				if (xp->e_xtype & XXTRN)
E 12
I 12
				if ((xp->e_xtype & XTYPE) == XUNDEF)
E 12
					yywarning("%s: destination label is external",
D 10
						ITABFETCH(opcode)->s_name);
E 10
I 10
						FETCHNAME(ITABFETCH(opcode)));
E 10
E 8
				xp->e_xtype = XABS;
E 2
D 6
				if (a<MINWORD || a>MAXWORD) 
E 6
I 6
D 8
				if (argtype<MINWORD || argtype>MAXWORD) 
E 6
					yyerror("Branch too far");
E 8
I 8
				if (!ISWORD(argtype))
D 9
					yyerror("%s: Branch too far: %d",
E 9
I 9
D 14
					yyerror("%s: Branch too far(%db): try -J flag",
E 14
I 14
					yyerror("%s: Branch too far(%db)",
E 14
E 9
D 10
						ITABFETCH(opcode)->s_name,
E 10
I 10
						FETCHNAME(ITABFETCH(opcode)),
E 10
						argtype);
E 8
D 2
				xp->xvalue = a>>8;
E 2
I 2
D 6
				xp->e_xvalue = a>>8;
E 6
I 6
				xp->e_xvalue = argtype>>8;
E 6
E 2
D 5
				xtrab = LEN1;
E 5
I 5
				reloc_how = TYPB;
E 5
				break;
			}
			/* reduces to expr(pc) mode */
D 2
			ap->areg1 |= (0xAF + mod124[ap->dispsize]);
			xtrab = len124[ap->dispsize]+PCREL;
E 2
I 2
			ap->a_areg1 |= (0xAF + mod124[ap->a_dispsize]);
D 5
			xtrab = len124[ap->a_dispsize]+PCREL;
E 5
I 5
			reloc_how = type_124[ap->a_dispsize] + RELOC_PCREL;
E 5
E 2
			break;
		
		case ADISP: /* expr(%r) */
D 2
			ap->areg1 |= 0xA0;
			if ((xp->xtype&XTYPE)!=XABS || xp->xtype&XFORW){
				ap->areg1 += mod124[ap->dispsize];
				xtrab=len124[ap->dispsize];
E 2
I 2
			ap->a_areg1 |= 0xA0;
			if ((xp->e_xtype&XTYPE)!=XABS || xp->e_xtype&XFORW){
				ap->a_areg1 += mod124[ap->a_dispsize];
D 5
				xtrab=len124[ap->a_dispsize];
E 5
I 5
				reloc_how = type_124[ap->a_dispsize];
E 5
E 2
				break;
			}
D 2
			if (xp->xvalue==0 && !(ap->areg1&0x10)) {
				ap->areg1 ^= 0xC0;
E 2
I 2
			if (xp->e_xvalue==0 && !(ap->a_areg1&0x10)) {
				ap->a_areg1 ^= 0xC0;
E 2
				break;
			}
D 5
			xtrab=LEN1;
E 5
I 5
			reloc_how = TYPB;
E 5
D 2
			if ((xp->xvalue<MINBYTE) || (xp->xvalue>MAXBYTE)){
				ap->areg1 += 0x20;
E 2
I 2
D 8
			if ((xp->e_xvalue<MINBYTE) || (xp->e_xvalue>MAXBYTE)){
				ap->a_areg1 += 0x20;
E 2
D 5
				xtrab=LEN2;
E 5
I 5
				reloc_how = TYPW;
E 5
			}
D 2
			if ((xp->xvalue<MINWORD) || (xp->xvalue>MAXWORD)){
				ap->areg1 += 0x20;
E 2
I 2
			if ((xp->e_xvalue<MINWORD) || (xp->e_xvalue>MAXWORD)){
				ap->a_areg1 += 0x20;
E 2
D 5
				xtrab=LEN4;
E 5
I 5
				reloc_how = TYPL;
E 5
			}
E 8
I 8
			if (ISBYTE(xp->e_xvalue))
				break;
			ap->a_areg1 += 0x20;
			reloc_how = TYPW;
			if (ISWORD(xp->e_xvalue))
				break;
			ap->a_areg1 += 0x20;
			reloc_how = TYPL;
E 8
			break;
		
		case AIMM:  /* $expr */
D 2
			if (ap->atype&ASTAR)
E 2
I 2
D 8
			if (ap->a_atype&ASTAR)
E 8
I 8
			if (ap->a_atype&ASTAR) {
E 8
E 2
D 6
				a=TYPL;
E 6
I 6
				argtype=TYPL;
E 6
D 8
			else {
D 2
				a = itab[op]->argtype[i];
E 2
I 2
D 6
				a = fetcharg(itab[op], i);
E 2
				if (a&ACCA)
					a=TYPL;
E 6
I 6
				argtype = fetcharg(itab[op], i);
E 8
I 8
			} else {
				argtype = fetcharg(ITABFETCH(opcode), i);
E 8
				if (argtype&ACCA)
D 8
					argtype=TYPL;
E 8
I 8
					argtype = TYPL;
E 8
E 6
				else
D 6
					a &= TYPMASK;
E 6
I 6
					argtype &= TYPMASK;
E 6
D 2
				if (    ( (xp->xtype&XTYPE) == XABS) 
				    && !(xp->xtype&XFORW)
				    &&  (xp->xvalue >= 0)
				    &&  (xp->xvalue <= 63)
				    &&  (xp->yvalue == 0)
E 2
I 2
D 8
				if (    ( (xp->e_xtype&XTYPE) == XABS) 
				    && !(xp->e_xtype&XFORW)
				    &&  (xp->e_xvalue >= 0)
				    &&  (xp->e_xvalue <= 63)
				    &&  (xp->e_yvalue == 0)
E 2
D 6
				    &&  (a != TYPF)
				    &&  (a != TYPD) ) {
E 6
I 6
				    &&  (argtype != TYPF)
				    &&  (argtype != TYPD) ) {
E 6
D 2
					ap->areg1 = xp->xvalue;
E 2
I 2
					ap->a_areg1 = xp->e_xvalue;
E 8
I 8
				if (immconstant(xp, argtype, &value)){
					reloc_how = TYPNONE;
					ap->a_areg1 = value;
E 8
E 2
					break;
				}
			}
D 2
			ap->areg1 |= 0x8F;
E 2
I 2
			ap->a_areg1 |= 0x8F;
E 2
D 5
			switch (a) {
			case TYPD:
			case TYPF:
E 5
I 5
D 6
			reloc_how = a;
E 6
I 6
			reloc_how = argtype;
E 6
D 8
			if (reloc_how == TYPD || reloc_how == TYPF){
E 5
D 2
				if (   ((xp->xtype&XTYPE)==XABS)
				    && (!(xp->xtype&XFORW))
E 2
I 2
				if (   ((xp->e_xtype&XTYPE)==XABS)
				    && (!(xp->e_xtype&XFORW))
E 2
				    && (slitflt(xp))
				){
I 5
					reloc_how = TYPNONE;
E 5
D 2
					ap->areg1=extlitflt(xp);
E 2
I 2
					ap->a_areg1=extlitflt(xp);
E 2
D 5
				} else {
					xtrab = (a==TYPF) ? LEN4: LEN8;
E 5
				}
D 5
				break;
			case TYPQ: xtrab = LEN8; break;
			case TYPL: xtrab = LEN4; break;
			case TYPW: xtrab = LEN2; break;
			case TYPB: xtrab = LEN1; break;
E 5
			}	
E 8
			break;
		
D 6
		}	/*end of the switch on a*/
E 6
I 6
		}	/*end of the switch on argtype*/
E 6
		/*
		 *	use the first byte to describe the argument
		 */
D 8
#ifdef UNIX
D 2
		outb(ap->areg1);
E 2
I 2
		outb(ap->a_areg1);
E 2
#endif UNIX
E 8
I 8
		Outb(ap->a_areg1);
E 8
D 11
#ifdef VMS
D 2
		*vms_obj_ptr++ = -1; *vms_obj_ptr++ = (char)(ap->areg1);
		dotp->xvalue += 1;
E 2
I 2
D 8
		*vms_obj_ptr++ = -1; *vms_obj_ptr++ = (char)(ap->a_areg1);
		dotp->e_xvalue += 1;
E 8
E 2
		if ((vms_obj_ptr-sobuf) > 400) {
			write(objfil,sobuf,vms_obj_ptr-sobuf);
			vms_obj_ptr=sobuf+1;
		}
#endif VMS
E 11
D 5
		if (xtrab) 
			/*
			 *	Floating point numbers are written to a.out
			 *	by outrel; they require that the least significant
			 *	4 bytes of an 8 byte double precision number
			 *	immediately follow the field xvalue, which
			 *	they do.
			 */
D 2
			outrel(&xp->xvalue, xtrab, xp->xtype, xp->xname);
E 2
I 2
			outrel(&xp->e_xvalue, xtrab, xp->e_xtype, xp->e_xname);
E 5
I 5
		if (reloc_how != TYPNONE) 
			outrel(xp, reloc_how);
E 5
E 2
	}	/*end of the for to pick up all arguments*/
I 8
}
/*
 *	Is xp an immediate constant?
 *	argtype: how the instruction will interpret the bytes
 *	xp->e_number.num_tag ("numtype"): the kind of number given
 *
 *	Use the following table:
 *	float: TYPF, TYPD, TYPG, TYPH
 *	quad: TYPQ, TYPO
 *	int: TYPG, TYPW, TYPL
 *
 *				numtype
 *	argtype		float	quad	int
 *	
 *	float		slitflt	slitflt	slitflt
 *	quad		0	0	0
 *	int		0..63	0	0..63
 *
 *	Where the table entry implies the predicate to return.
 */
#define	IMMFLT	1		/* these flags are not used by anybody (yet) */
#define	IMMINT	2

int immconstant(xp, argtype, valuep)
	reg	struct	exp	*xp;
		int	argtype;
		int	*valuep;
{
	reg	int	back = 0;
		int	numtype;
	reg	int	fits;

	if ((xp->e_xtype & XTYPE) != XABS)
		return(0);
	if ((xp->e_xtype & XFORW) != 0)
		return(0);
	numtype = xp->e_number.num_tag;

	fits = 1;
	if (passno == 2) switch(argtype){
	case TYPB:
		switch(numtype){
		default:	fits = 0; break;
		case TYPB:	fits = 1; break;
		case TYPW:	
		case TYPL:
			fits = ISBYTE(xp->e_xvalue) || ISUBYTE(xp->e_xvalue);
			break;
		}
		break;
	case TYPW:
		switch(numtype){
		default:	fits = 0; break;
		case TYPB:
		case TYPW:	fits = 1; break;
		case TYPL:
			fits = ISWORD(xp->e_xvalue) || ISUWORD(xp->e_xvalue);
			break;
		}
		break;
	case TYPF:
		if (numtype == TYPD){	/* same format for first 32 bits */
			fits = 1;
			break;
		}
		/*FALLTHROUGH*/
	default:
		fits = ty_nbyte[argtype] >= ty_nbyte[numtype];
	}
	if (!fits){
	  yywarning("Immediate constant type %s mismatches instruction type %s",
		ty_string[numtype],
		ty_string[argtype]);
	}

	switch(argtype){
	case TYPF:
	case TYPG:
	case TYPD:
	case TYPH:
		back = slitflt(xp->e_number, argtype, valuep);
		break;
	case TYPO:
	case TYPQ:
		back = 0;
		break;
	case TYPB:
	case TYPW:
	case TYPL:
		switch(numtype){
		case TYPO:
		case TYPQ:
			back = 0;
			break;
		default:
			*valuep = xp->e_xvalue;
			back = ISLIT(xp->e_xvalue);
			break;
		}
		break;
	}
	return(back);
E 8
}
E 1
