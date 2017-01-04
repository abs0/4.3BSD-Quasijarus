h36905
s 00001/00000/00654
d D 5.9 03/11/08 22:34:01 msokolov 19 18
c bring back -d124, without affecting 3-way relaxing of branches
e
s 00009/00015/00645
d D 5.8 00/08/31 13:09:59 msokolov 18 17
c Correct .align handling. On the first pass set the fear value to one byte less
c because we guess 1 byte initially, not 0. Correct the expansion accordingly.
c Also reject bogus .align 0.
e
s 00093/00080/00567
d D 5.7 00/08/31 12:53:45 msokolov 17 16
c Reimplement tunneling. We no longer try to maintain the tunnel location, which
c never worked right. Instead, we actively seek a tunnel when we want one. There
c we do our best to find one, looking both backward and forward. We also make
c sure that future expansions can't break it.
e
s 00007/00006/00640
d D 5.6 00/08/30 22:54:11 msokolov 16 15
c Raise a red flag on a JXACTIVE over a JXALIGN only when it's actually
c dangerous. Also don't carry over this flag from previous iterations.
e
s 00208/00077/00438
d D 5.5 00/08/29 22:10:43 msokolov 15 14
c Complete jxxx relaxation overhaul. We now relax three-way without -J!
c -J is now ignored. We now also relax SOBs, AOBs, and ACBs. See the comments in
c addsob() in c2 for the motivation.
c As a side effect, we now require -d4.
c As yet another side effect, the handling of branches in instrs has been
c significantly cleaned up for c2.
e
s 00000/00000/00515
d D 5.4 87/12/11 20:05:35 donn 14 13
c to terminate but many of the values in the range of the loop are bogus
c after the first pass of the sort, so breakage resulted (e.g. 'use -J'
c complaint even if you did use -J).  The break condition in the loops was
c changed to test for the location of the destination instead of its value.
e
s 00002/00002/00513
d D 5.3 87/12/11 20:05:30 donn 13 12
c utah rcsid 1.2 87/01/12 04:27:27: A bug in jxxxfix() was fixed(!).  After
c the first pass through the topo sort, the symbols in symptrs are no longer
c sorted by value, since the jxxxbump() routine only fixes the values of a
c few relevant symbols.  There are a couple loops which are used to check the
c range of a jump for other jumps whose size isn't fully determined yet;
c these loops were using the value of the destination label to determine when
e
s 00001/00001/00514
d D 5.2 85/06/19 16:46:09 mckusick 12 11
c NBPW changed to NBWD to avoid conflict in param.h
e
s 00005/00002/00510
d D 5.1 85/04/30 13:57:05 dist 11 10
c Add copyright
e
s 00006/00005/00506
d D 4.10 83/11/21 14:42:47 rrh 10 9
c -a flag allows alignment to be specified; defaults to 2
e
s 00001/00001/00510
d D 4.9 83/10/25 10:52:55 ralph 9 8
c fixed off by one error introduced by previous delta.
e
s 00017/00005/00494
d D 4.8 83/10/14 16:37:43 ralph 8 7
c fixed debugging info and phase error message for label defs.
e
s 00003/00002/00496
d D 4.7 83/06/30 19:02:16 rrh 7 6
c The string pool is maintained both in core, and in a second tmp file.
c names are in core and on the file; strings are just in the file.  The file 
c is maintained as a string table per a.out(5), and tacked onto the a.out file
c at the very end.  The string table has more than need be, since discarde 
c labels and .ascii strings find their way (harmlessly) into the string table.
c the string file maintained with stdio; nothing fancy, even if -V set
e
s 00041/00031/00457
d D 4.6 82/02/14 16:32:13 rrh 6 5
c Fix reported and outstanding bugs. Reformat some text for
c readability/understandability. Assembles new instructions  for G and H
c format floating numbers & new queue instructions
c asscan.c split into 4 files; two additional files to construct and
c manipulate G and H format numbers, with analog for atof()
c Numerical accuracy of new atof() not verified; standard atof() used
c for F and D floating numbers.  As does NOT use G and H instructions itself
e
s 00026/00005/00462
d D 4.5 80/08/20 12:10:30 henry 5 4
c Partial backout of previous delta; align to no more than full word
e
s 00010/00001/00457
d D 4.4 80/08/20 10:05:55 henry 4 3
c Catch .align by > 3 if not in text 0 (doesn't work because of segment concatnation)
e
s 00031/00011/00427
d D 4.3 80/08/15 18:33:19 henry 3 2
c -J option: use jmp instead of brw for jxxx resolution
e
s 00076/00077/00362
d D 4.2 80/08/15 18:03:02 henry 2 1
c use struct nlist; change field names; vgrind format fixes
e
s 00439/00000/00000
d D 4.1 80/08/13 18:55:13 bill 1 0
c date and time created 80/08/13 18:55:13 by bill
e
u
U
t
T
I 1
D 6
/* Copyright (c) 1980 Regents of the University of California */
static	char sccsid[] = "%Z%%M% %I% %G%";
E 6
I 6
/*
D 11
 *	Copyright (c) 1982 Regents of the University of California
E 11
I 11
 * Copyright (c) 1982 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 11
 */
I 11

E 11
#ifndef lint
D 11
static char sccsid[] = "%Z%%M% %I% %G%";
E 11
I 11
static char sccsid[] = "%W% (Berkeley) %G%";
E 11
#endif not lint

E 6
#include	<stdio.h>
D 2
#include	<sys/types.h>
E 2
#include	"as.h"
#include	"assyms.h"

D 3
#define JBR 0x11
#define BRW 0x31
E 3
I 3
D 15
#define	JBR	0x11
E 15
I 15
/* These are the opcodes involved in relaxation. */
#define	BRB	0x11
E 15
#define	BRW	0x31
#define	JMP	0x17
I 15
#define	DECL	0xD7
#define	BLEQ	0x15
#define	BLSS	0x19
#define	SOBGTR	0xF5
#define	SOBGEQ	0xF4
#define	AOBLSS	0xF2
#define	AOBLEQ	0xF3
#define	ACBB	0x9D
#define	ACBW	0x3D
#define	ACBL	0xF1
#define	ACBF	0x4F	/* also ACBG */
#define	ACBD	0x6F	/* also ACBH */
E 15
E 3

D 15
/*
 *	The number of bytes to add if the jxxx must be "exploded"
 *	into the long form
 */
D 3
#define	JBRFSIZE	1	/*goes to brw*/
#define JXXXFSIZE	3	/*goes to brb, brw <byte> <byte> */
E 3
I 3
#define	JBRDELTA	1	/* brb <byte> ==> brw <byte> <byte> */
#define	JXXXDELTA	3	/* brb <byte> ==> brb <byte> brw <byte> <byte> */
#define	JBRJDELTA	d124	/* brb <byte> ==> jmp L^(pc) <byte>*d124 */
#define	JXXXJDELTA	d124+2	/* brb <byte> ==> brb <byte> jmp L^(pc) <byte>*d124 */
E 15
I 15
/* Relaxation states for s_jxstate. */
#define	RELSTATE_UNCONDW	0x00
#define	RELSTATE_UNCONDB	0x01
#define	RELSTATE_CONDW		0x02
#define	RELSTATE_CONDB		0x03
#define	RELSTATE_SOBW		0x04
#define	RELSTATE_SOBB		0x05
#define	RELSTATE_AOBLSSW	0x06
#define	RELSTATE_AOBLSSB	0x07
#define	RELSTATE_AOBLEQW	0x08
#define	RELSTATE_AOBLEQB	0x09
#define	RELSTATE_ACBXW		0x0A
/* Mask for all byte relaxation states. */
#define	RELSTATE_BYTE		0x01
/* The following two are special kludges. */
#define	RELSTATE_ALIGN		0x0B
#define	RELSTATE_LONG		0x0C
E 15
E 3

I 3
D 15
int	jbrfsize = JBRDELTA;
int	jxxxfsize = JXXXDELTA;
E 15
I 15
/* Bumps for byte to word relaxations, indexed by s_jxstate>>1. */
static int byterelax_bumps[5] = {1, 3, 4, 5, 2};
E 15

E 3
/*
 *	These variables are filled by asscan.c with the
 *	last name encountered (a pointer buried in the intermediate file),
 *	and the last jxxx symbol table entry encountered.
 */
struct 	symtab	*lastnam;
struct	symtab	*lastjxxx;

I 3
D 15
initijxxx()
{
	jbrfsize = jxxxJUMP ? JBRJDELTA : JBRDELTA;
	jxxxfsize = jxxxJUMP ? JXXXJDELTA : JXXXDELTA;
	/*
	 *	Note: ifjxxxJUMP is set, then we do NOT do any tunnelling;
	 *	this was too complicated to figure out, and in the first
	 *	version of the assembler, tunnelling proved to be the hardest
	 *	to get to work!
	 */
}
E 15
E 3
/*
 *	Handle jxxx instructions
 */
D 6
ijxout(op,ap,nact)
	struct arg *ap;
E 6
I 6
ijxout(opcode, ap, nact)
	struct	Opcode	opcode;
	struct	arg	*ap;
	int	nact;
E 6
{
	if (passno == 1){
		/*
		 *	READ THIS BEFORE LOOKING AT jxxxfix()
		 *
		 *	Record the jxxx in a special symbol table entry
		 */
		register struct symtab *jumpfrom;

		/*
		 *	We assume the MINIMAL length
		 */
D 6
		putins(op,ap,nact); 
E 6
I 6
		putins(opcode, ap, nact); 
E 6
		jumpfrom = lastjxxx;
D 2
		jumpfrom->tag = JXACTIVE;
		jumpfrom->jxbump = 0;
E 2
I 2
		jumpfrom->s_tag = JXACTIVE;
D 15
		jumpfrom->s_jxbump = 0;
E 2
D 6
		if (op == JBR)
E 6
I 6
		if (opcode.Op_popcode == JBR)
E 6
D 2
			jumpfrom->jxfear = JBRFSIZE;
E 2
I 2
D 3
			jumpfrom->s_jxfear = JBRFSIZE;
E 3
I 3
			jumpfrom->s_jxfear = jbrfsize;
E 3
E 2
		else
D 2
			jumpfrom->jxfear = JXXXFSIZE;
E 2
I 2
D 3
			jumpfrom->s_jxfear = JXXXFSIZE;
E 3
I 3
			jumpfrom->s_jxfear = jxxxfsize;
E 15
I 15
		switch (opcode.Op_popcode) {
		case BRB:
			jumpfrom->s_jxstate = RELSTATE_UNCONDB;
			jumpfrom->s_jxfear = 4;
			break;
		default:	/* conditional branch */
			jumpfrom->s_jxstate = RELSTATE_CONDB;
			jumpfrom->s_jxfear = 6;
			break;
		case SOBGTR:
		case SOBGEQ:
			jumpfrom->s_jxstate = RELSTATE_SOBB;
			jumpfrom->s_jxfear = 7;
			break;
		case AOBLSS:
			jumpfrom->s_jxstate = RELSTATE_AOBLSSB;
			jumpfrom->s_jxfear = 8;
			break;
		case AOBLEQ:
			jumpfrom->s_jxstate = RELSTATE_AOBLEQB;
			jumpfrom->s_jxfear = 8;
			break;
		case ACBB:
		case ACBW:
		case ACBL:
		case ACBF:	/* also ACBG */
		case ACBD:	/* also ACBH */
			jumpfrom->s_jxstate = RELSTATE_ACBXW;
			jumpfrom->s_jxfear = 8;
		}
E 15
E 3
E 2
		if (lastnam == 0)
			yyerror("jxxx destination not a label");
D 2
		jumpfrom->dest = lastnam;
		jumpfrom->type = dotp->xtype;	/*only TEXT or DATA*/
		jumpfrom->index = dotp-usedot;
E 2
I 2
		jumpfrom->s_dest = lastnam;
		jumpfrom->s_type = dotp->e_xtype;	/*only TEXT or DATA*/
		jumpfrom->s_index = dotp-usedot;
I 8
#ifdef DEBUG
		jumpfrom->s_name = ITABFETCH(opcode)->i_name;
		jumpfrom->s_jxline = lineno;
#endif
E 8
E 2
		/*
		 *	value ALWAYS (ALWAYS!!!) indexes the next instruction
D 8
		 *	after the jump, even in the jump must be exploded
E 8
I 8
		 *	after the jump, even if the jump must be exploded
E 8
		 *	(bumped)
		 */
D 2
		jumpfrom->value = dotp->xvalue;
E 2
I 2
		jumpfrom->s_value = dotp->e_xvalue;
E 2
		njxxx++;
	} else {/* pass2, resolve */
		/*
		 *	READ THIS AFTER LOOKING AT jxxxfix()
		 */
D 6
		register long		oxvalue;
		register struct	exp 	*xp; 
		register struct symtab	*tunnel;
		register struct arg	*aplast;
E 6
I 6
		reg	long		oxvalue;
		reg	struct	exp 	*xp; 
		reg	struct	symtab	*tunnel;
		reg	struct	arg	*aplast;
			struct	Opcode	nopcode;
E 6

		aplast = ap + nact - 1;
D 2
		xp = aplast->xp;
		if (lastjxxx->tag == JXTUNNEL){
			lastjxxx->tag = JXINACTIVE;
			tunnel = lastjxxx->dest;
			xp->xvalue = tunnel->value	/*index of instruction following*/
E 2
I 2
		xp = aplast->a_xp;
		if (lastjxxx->s_tag == JXTUNNEL){
			lastjxxx->s_tag = JXINACTIVE;
			tunnel = lastjxxx->s_dest;
D 15
			xp->e_xvalue = tunnel->s_value	/*index of instruction following*/
E 2
				    - 3			/* size of brw + word*/
D 2
				    + ( ( (tunnel->jxfear == JBRFSIZE) &&
					  (tunnel->jxbump == 0))?1:0);
E 2
I 2
D 3
				    + ( ( (tunnel->s_jxfear == JBRFSIZE) &&
E 3
I 3
				    + ( ( (tunnel->s_jxfear == jbrfsize) &&
E 3
					  (tunnel->s_jxbump == 0))?1:0);
E 2
							/*non bumped branch byteis only 2 back*/
E 15
I 15
			xp->e_xvalue = tunnel->s_value;	/*index of instruction following*/
			if (tunnel->s_jxstate & RELSTATE_BYTE)
				xp->e_xvalue -= 2;
			else if (tunnel->s_jxstate == RELSTATE_LONG)
				xp->e_xvalue -= 6;
			else
				xp->e_xvalue -= 3;
E 15
		}
D 2
		if (lastjxxx->jxbump == 0){	/*wasn't bumped, so is short form*/
E 2
I 2
D 15
		if (lastjxxx->s_jxbump == 0){	/*wasn't bumped, so is short form*/
E 15
I 15
		/* Now determine what instruction or sequence to emit. */
		if ((lastjxxx->s_jxstate & RELSTATE_BYTE)
		    || lastjxxx->s_jxstate == RELSTATE_ACBXW) {
			/* No relaxation, real VAX instruction. */
E 15
E 2
D 6
			putins(op, ap, nact);
E 6
I 6
			putins(opcode, ap, nact);
I 15
		} else if (lastjxxx->s_jxstate == RELSTATE_AOBLEQW) {
			/* Turn AOBLEQ into ACBL. */
			struct arg narglist[4];
			struct exp nxp;
			nopcode.Op_eopcode = CORE;
			nopcode.Op_popcode = ACBL;
			nxp.e_xtype = XABS;
			nxp.e_number.num_tag = TYPL;
			nxp.e_xvalue = 1;
			narglist[0] = ap[0];
			narglist[1].a_atype = AIMM;
			narglist[1].a_areg1 = 0;
			narglist[1].a_xp = &nxp;
			narglist[2] = ap[1];
			narglist[3] = ap[2];
			putins(nopcode, narglist, 4);
E 15
E 6
		} else {
D 6
			if (op != JBR){	/*branch reverse conditional byte over 
					  branch unconditional word*/
E 6
I 6
D 15
			if (opcode.Op_popcode != JBR){
				/*
				 *	branch reverse conditional byte over
				 *	branch unconditional word
				 */
E 15
I 15
			/*
			 * Relaxed sequence. The start of the sequence depends
			 * on what we are relaxing, but at the end we'll always
			 * have a BRW or JMP to the real destination.
			 */
			switch (opcode.Op_popcode) {
			case BRB:
				/* Nothing except the big jump! */
				break;
			default:	/* conditional branch */
				/* Reversed branch around. */
E 15
E 6
D 2
				oxvalue = xp->xvalue;
				xp->xvalue = lastjxxx->value;
E 2
I 2
				oxvalue = xp->e_xvalue;
				xp->e_xvalue = lastjxxx->s_value;
E 2
D 6
				putins(op^1, ap, nact);
E 6
I 6
				nopcode = opcode;
				nopcode.Op_popcode ^= 1;
				putins(nopcode, ap, nact);
E 6
D 2
				xp->xvalue = oxvalue;
E 2
I 2
				xp->e_xvalue = oxvalue;
I 15
				break;
			case SOBGTR:
			case SOBGEQ:
				/* DECL and reversed branch around. */
				nopcode.Op_eopcode = CORE;
				nopcode.Op_popcode = DECL;
				putins(nopcode, ap, 1);
				oxvalue = xp->e_xvalue;
				xp->e_xvalue = lastjxxx->s_value;
				nopcode.Op_popcode =
				    (opcode.Op_popcode == SOBGTR) ? BLEQ : BLSS;
				putins(nopcode, aplast, 1);
				xp->e_xvalue = oxvalue;
				break;
			case AOBLSS:
			case AOBLEQ:
			case ACBB:
			case ACBW:
			case ACBL:
			case ACBF:	/* also ACBG */
			case ACBD:	/* also ACBH */
				/* Real instruction, then branch around. */
				oxvalue = xp->e_xvalue;
				xp->e_xvalue = lastjxxx->s_value;
				if (lastjxxx->s_jxstate != RELSTATE_LONG)
					xp->e_xvalue -= 3;
				else
					xp->e_xvalue -= 6;
				putins(opcode, ap, nact);
				nopcode.Op_eopcode = CORE;
				nopcode.Op_popcode = BRB;
				xp->e_xvalue = lastjxxx->s_value;
				putins(nopcode, aplast, 1);
				xp->e_xvalue = oxvalue;
E 15
E 2
			}
D 3
			putins(BRW, aplast, 1);
E 3
I 3
D 6
			putins(jxxxJUMP ? JMP : BRW, aplast, 1);
E 6
I 6
			nopcode.Op_eopcode = CORE;
D 15
			nopcode.Op_popcode = jxxxJUMP ? JMP : BRW;
E 15
I 15
			nopcode.Op_popcode =
			    (lastjxxx->s_jxstate == RELSTATE_LONG) ? JMP : BRW;
I 19
			aplast->a_dispsize = 4;
E 19
E 15
			putins(nopcode, aplast, 1);
E 6
E 3
		}
	}
D 6
}	/*end of ijxout*/
E 6
I 6
}
E 6

jalign(xp, sp)
	register struct exp *xp;
	register struct symtab *sp;
{
	register	int	mask;
I 8
#ifdef DEBUG
	static struct strdesc noname;
#endif
E 8
I 5
	/*
	 *	Problem with .align
	 *
	 *	When the loader constructs an executable file from
	 *	a number of objects, it effectively concatnates
	 *	together all of the text segments from all objects,
	 *	and then all of the data segments.
	 *
	 *	If we do an align by a large value, we can align
	 *	within the a.out this assembly produces, but
	 *	after the loader concatnates, the alignment can't
	 *	be guaranteed if the objects preceding this one
	 *	in the load are also aligned to the same size.
	 *
	 *	Currently, the loader guarantees full word alignment.
	 *	So, ridiculous aligns are caught here and converted
D 10
	 *	to a .align 2, if possible.
E 10
I 10
	 *	to a .align (maxalign), if possible, where maxalign
	 *	is set in the command line, and defaults to 2.
E 10
	 */
E 5
D 2
	if (xp->xtype != XABS || xp->xvalue < 0 || xp->xvalue > 16) {
E 2
I 2
D 4
	if (xp->e_xtype != XABS || xp->e_xvalue < 0 || xp->e_xvalue > 16) {
E 4
I 4
D 6
	if (   (xp->e_xtype != XABS)
E 6
I 6
	if (   ( (xp->e_xtype & XTYPE) != XABS)
E 6
D 18
	    || (xp->e_xvalue < 0)
E 18
I 18
	    || (xp->e_xvalue <= 0)
E 18
	    || (xp->e_xvalue > 16)
	    ) {
E 4
E 2
		yyerror("Illegal `align' argument");
		return;
I 4
	}
D 5
	if (   (xp->e_xvalue > 3)
	    && (dotp != &usedot[0])
	    ) {
		yywarning("Alignment by %d in segments other than text 0 may not work.", xp->e_xvalue);
		yywarning("Phase errors may occur after this .align in the second pass.");
E 5
I 5
D 10
	if (xp->e_xvalue > 2){
E 10
I 10
	if (xp->e_xvalue > maxalign){
E 10
		if (passno == 1){
D 6
		  yywarning(".align %d in any segment is NOT preserved by the loader",
			xp->e_xvalue);
		  yywarning(".align %d converted to .align 2",
			xp->e_xvalue);
E 6
I 6
			yywarning(".align %d is NOT preserved by the loader",
				xp->e_xvalue);
D 10
			yywarning(".align %d converted to .align 2",
				xp->e_xvalue);
E 10
I 10
			yywarning(".align %d converted to .align %d",
				xp->e_xvalue, maxalign);
E 10
E 6
		}
D 10
		xp->e_xvalue = 2;
E 10
I 10
		xp->e_xvalue = maxalign;
E 10
E 5
E 4
	}
D 12
	flushfield(NBPW/4);
E 12
I 12
	flushfield(NBWD/4);
E 12
	if (passno == 1) {
D 2
		sp->tag = JXALIGN;
		sp->jxfear = (1 << xp->xvalue) - 1;
		sp->type = dotp->xtype;
		sp->index = dotp-usedot;
E 2
I 2
		sp->s_tag = JXALIGN;
I 15
		sp->s_jxstate = RELSTATE_ALIGN;
E 15
D 18
		sp->s_jxfear = (1 << xp->e_xvalue) - 1;
E 18
I 18
		sp->s_jxfear = (1 << xp->e_xvalue) - 2;
E 18
		sp->s_type = dotp->e_xtype;
		sp->s_index = dotp-usedot;
I 8
#ifdef DEBUG
		sp->s_name = (char *)&noname;
		sp->s_jxline = lineno;
#endif
E 8
E 2
		/*
		 *	We guess that the align will take up at least one
		 *	byte in the code output.  We will correct for this
		 *	initial high guess when we explode (bump) aligns
		 *	when we fix the jxxxes.  We must do this guess
		 *	so that the symbol table is sorted correctly
		 *	and labels declared to fall before the align
		 *	really get their, instead of guessing zero size
		 *	and have the label (incorrectly) fall after the jxxx.
		 *	This is a quirk of our requirement that indices into
		 *	the code stream point to the next byte following
		 *	the logical entry in the symbol table
		 */
D 2
		dotp->xvalue += 1;
		sp->value = dotp->xvalue;
E 2
I 2
		dotp->e_xvalue += 1;
		sp->s_value = dotp->e_xvalue;
E 2
		njxxx++;
	} else {
D 2
		mask = (1 << xp->xvalue) - 1;
		while (dotp->xvalue & mask){
E 2
I 2
		mask = (1 << xp->e_xvalue) - 1;
D 6
		while (dotp->e_xvalue & mask){
E 2
#ifdef UNIX
			outb(0);
#endif UNIX
#ifdef VMS
			*vms_obj_ptr++ = -1;
			*vms_obj_ptr++ = 0;
D 2
			dotp->xvalue += 1;
E 2
I 2
			dotp->e_xvalue += 1;
E 2
#endif VMS
		}
E 6
I 6
		while (dotp->e_xvalue & mask)
			Outb(0);
E 6
	}
}

/*
 *	Pass 1.5, resolve jxxx instructions and .align in .text
 */
jxxxfix() 
{
	register struct symtab 	*jumpfrom;
		 struct symtab	**cojumpfrom, *ubjumpfrom;
	register struct symtab 	*dest;
	register struct symtab	*intdest;	/*intermediate dest*/
	register struct symtab	**cointdest, *ubintdest;

D 17
	register struct symtab 	*tunnel;
E 17
D 15
	 	 int 		displ,nchange;
E 15
I 15
	 	 int 		displ, lowlim, highlim, nchange;
E 15
		 int		badjxalign;	/*if jump across an align*/
		 int		stillactives;	/*if still active jxxxes*/
		 int		segno;		/*current segment number*/
		 int		topono;		/*which iteration in the topo sort*/
D 17
	register unsigned char	tag;
E 17
	/*
	 *	consider each segment in turn...
	 */
	for (segno = 0; segno < NLOC + NLOC; segno++){
D 16
	    badjxalign = 0;		/*done on a per segment basis*/
E 16
	    /*
	     *	Do a lazy topological sort.
	     */
	    for (topono = 1, nchange = 1; nchange != 0; topono++){
I 6
#ifdef lint
		topno = topno;
#endif lint
E 6
#ifdef DEBUG
		if (debug)
			printf("\nSegment %d, topo iteration %d\n",
				segno, topono);
#endif
		nchange = 0;
		stillactives = 0;
I 16
		badjxalign = 0;
E 16
D 17
		/*
		 *	We keep track of one possible tunnel location.
		 *	A tunnel will eventually be an unconditional
		 *	branch to the same place that another jxxx
		 *	will want to branch to.  We will turn a
		 *	branch conditional/unconditional (word) that would
		 *	have to get bumped because its destination is too
		 *	far away, into a branch conditional/unconditional
		 *	byte to the tunnel branch conditional/unconditional.
		 *	Of course, the tunnel must branch to the same place
		 *	as we want to go.
		 */
		tunnel = 0;	/*initially, no tunnel*/
		SEGITERATE(segno, 0, 0, cojumpfrom, jumpfrom, ubjumpfrom, ++){
D 2
			tag = jumpfrom->tag;
E 2
I 2
			tag = jumpfrom->s_tag;
E 2
			if (tag <= IGNOREBOUND)
				continue;	/*just an ordinary symbol*/
			if (tag == JXALIGN){
				tunnel = 0;	/*avoid tunneling across a flex alocation*/
				continue;	/*we take care of these later*/
			}
D 2
			if (   jumpfrom->jxfear == JBRFSIZE	/*unconditional*/
E 2
I 2
D 3
			if (   jumpfrom->s_jxfear == JBRFSIZE	/*unconditional*/
E 3
I 3
D 15
			if (   jumpfrom->s_jxfear == jbrfsize	/*unconditional*/
E 3
E 2
			    || (   tag == JXINACTIVE		/*inactive bumped*/
D 2
				&& (jumpfrom->jxbump != 0)
E 2
I 2
				&& (jumpfrom->s_jxbump != 0)
E 2
			       )
			   ) tunnel = jumpfrom;
E 15
I 15
			switch (jumpfrom->s_jxstate) {
			case RELSTATE_UNCONDB:
			case RELSTATE_UNCONDW:
			case RELSTATE_CONDW:
			case RELSTATE_SOBW:
			case RELSTATE_AOBLSSW:
			case RELSTATE_LONG:
				tunnel = jumpfrom;
			}
E 15
			if (tag != JXACTIVE)
E 17
I 17
		SEGITERATE(segno, 0, 0, cojumpfrom, jumpfrom, ubjumpfrom, ++) {
			if (jumpfrom->s_tag != JXACTIVE)
E 17
				continue;
D 2
			dest = jumpfrom->dest;
			if (jumpfrom->index != dest->index){
E 2
I 2
			dest = jumpfrom->s_dest;
D 17
			if (jumpfrom->s_index != dest->s_index){
E 17
I 17
			if (jumpfrom->s_index != dest->s_index) {
E 17
E 2
				yyerror("Intersegment jxxx");
				continue;
			}
D 2
			displ = dest->value - jumpfrom->value;
E 2
I 2
			displ = dest->s_value - jumpfrom->s_value;
E 2
D 15
			if (displ < MINBYTE || displ > MAXBYTE) {
E 15
I 15
			if (jumpfrom->s_jxstate & RELSTATE_BYTE) {
				lowlim = MINBYTE;
				highlim = MAXBYTE;
			} else {
				lowlim = MINWORD;
				highlim = MAXWORD;
			}
			if (displ < lowlim || displ > highlim) {
E 15
				/*
D 17
				 *	This is an immediate lose!
				 *
				 *	We first attempt to tunnel
				 *	by finding an intervening jump that
				 *	has  the same destination.
				 *	The tunnel is always the first preceeding
				 *	jxxx instruction, so the displacement
				 *	to the tunnel is less than zero, and
				 *	its relative position will be unaffected
				 *	by future jxxx expansions.
E 17
I 17
				 * We have to bump it. If it's a conditional
				 * branch, a SOB, an AOB, or an ACB, this will
				 * mean turning a nice single instruction into
				 * a branch-around sequence. Rather than do
				 * that if possible, we try to tunnel this
				 * branch instead through a nearby
				 * unconditional jump (either a jbr or part of
				 * a relaxed sequence).
E 17
I 3
D 15
				 *
				 *	No tunnels if doing jumps...
E 15
E 3
				 */
D 2
				if (    (jumpfrom->jxfear > JBRFSIZE)
E 2
I 2
D 3
				if (    (jumpfrom->s_jxfear > JBRFSIZE)
E 3
I 3
D 15
				if (    (!jxxxJUMP)
				     && (jumpfrom->s_jxfear > jbrfsize)
E 3
E 2
				     && (tunnel) 
D 2
				     && (tunnel->dest == jumpfrom->dest)	
				     && (tunnel->index == jumpfrom->index)
				     && (tunnel->value - jumpfrom->value >=
E 2
I 2
				     && (tunnel->s_dest == jumpfrom->s_dest)	
				     && (tunnel->s_index == jumpfrom->s_index)
				     && (tunnel->s_value - jumpfrom->s_value >=
E 2
D 3
						MINBYTE + JXXXFSIZE)
E 3
I 3
						MINBYTE + jxxxfsize)
E 3
				   ) {
						/*
						 *	tunnelling is OK
						 */
D 2
						jumpfrom->dest = tunnel;
E 2
I 2
						jumpfrom->s_dest = tunnel;
E 2
						/*
						 * no bumping needed, this
						 * is now effectively inactive
						 * but must be remembered
						 */
D 2
						jumpfrom->tag = JXTUNNEL;
E 2
I 2
						jumpfrom->s_tag = JXTUNNEL;
E 15
I 15
D 17
				if (((jumpfrom->s_jxstate & RELSTATE_BYTE)
				     && jumpfrom->s_jxstate != RELSTATE_UNCONDB
				     || jumpfrom->s_jxstate == RELSTATE_ACBXW)
				    && (tunnel) 
				    && (tunnel->s_dest == jumpfrom->s_dest)	
				    && (tunnel->s_index == jumpfrom->s_index)
				    && (tunnel->s_value - 6 - jumpfrom->s_value
					>= lowlim)) {
					/*
					 *	tunnelling is OK
					 */
					jumpfrom->s_dest = tunnel;
					/*
					 * no bumping needed, this
					 * is now effectively inactive
					 * but must be remembered
					 */
					jumpfrom->s_tag = JXTUNNEL;
E 17
I 17
				if (!(jumpfrom->s_jxstate & RELSTATE_BYTE)
				    && jumpfrom->s_jxstate != RELSTATE_AOBLEQW
				    && jumpfrom->s_jxstate != RELSTATE_ACBXW
				    || jumpfrom->s_jxstate == RELSTATE_UNCONDB
				    || jumpfrom->s_jxstate == RELSTATE_AOBLEQB)
					goto notunnel;
				displ = 0;
				SEGITERATE(segno, cojumpfrom - 1, 1, cointdest,
					   intdest, ubintdest, --) {
					u_char tag, state;

					tag = intdest->s_tag;
					if (tag == JXACTIVE
					    || tag == JXINACTIVE
					    || tag == JXNOTYET) {
					    if (intdest->s_value - 6 -
						jumpfrom->s_value - displ
						< lowlim)
						    break;
					    state = intdest->s_jxstate;
					    if (intdest->s_dest ==
						jumpfrom->s_dest &&
						(state == RELSTATE_UNCONDB
						 || !(state & RELSTATE_BYTE)
						 && state != RELSTATE_AOBLEQW
						 && state != RELSTATE_ACBXW
						 || tag == JXNOTYET
						 && state != RELSTATE_AOBLEQB))
						    goto tunnel;
					}
					if (tag == JXACTIVE || tag == JXNOTYET
					    || tag == JXALIGN)
						displ += intdest->s_jxfear;
				}
				displ = 0;
				SEGITERATE(segno, cojumpfrom + 1, 0, cointdest,
					   intdest, ubintdest, ++) {
					u_char tag, state;

					tag = intdest->s_tag;
					if (tag == JXACTIVE || tag == JXNOTYET
					    || tag == JXALIGN)
						displ += intdest->s_jxfear;
					if (tag == JXACTIVE
					    || tag == JXINACTIVE
					    || tag == JXNOTYET) {
					    if (intdest->s_value - 6 -
						jumpfrom->s_value + displ
						> highlim)
						    break;
					    state = intdest->s_jxstate;
					    if (intdest->s_dest ==
						jumpfrom->s_dest &&
						(state == RELSTATE_UNCONDB
						 || !(state & RELSTATE_BYTE)
						 && state != RELSTATE_AOBLEQW
						 && state != RELSTATE_ACBXW
						 || tag == JXNOTYET
						 && state != RELSTATE_AOBLEQB))
						    goto tunnel;
					}
				}
			notunnel:
				/* tunneling is not possible */
				jumpfrom->s_tag = JXNOTYET;
				++nchange;
				continue;
			tunnel:
				/* tunnelling is OK */
				jumpfrom->s_dest = intdest;
				/*
				 * no bumping needed, this
				 * is now effectively inactive
				 * but must be remembered
				 */
				jumpfrom->s_tag = JXTUNNEL;
E 17
E 15
E 2
#ifdef DEBUG
D 15
						if(debug)
E 15
I 15
D 17
					if(debug)
E 15
						printf("Tunnel from %s from line %d\n",
D 2
							jumpfrom->name, lineno);
E 2
I 2
D 7
							jumpfrom->s_name, lineno);
E 7
I 7
							FETCHNAME(jumpfrom),
D 8
							lineno);
E 8
I 8
							jumpfrom->s_jxline);
E 17
I 17
				if(debug)
					printf("Tunnel from %s from line %d\n",
						FETCHNAME(jumpfrom),
						jumpfrom->s_jxline);
E 17
E 8
E 7
E 2
#endif
D 15
						continue;
E 15
I 15
D 17
					continue;
E 15
				} else {	/*tunneling not possible*/
					/*
					 *	since this will be turned
					 *	into a bumped jump, we can
					 *	use the unconditional jump
					 *	as a tunnel
					 */
					tunnel = jumpfrom;
D 2
					jumpfrom->tag = JXNOTYET;
E 2
I 2
					jumpfrom->s_tag = JXNOTYET;
E 2
					++nchange;
					continue;
				}
			}	/*end of immediate lose*/
E 17
I 17
				continue;
			}
E 17
			/*
			 *	Do a forward search for an intervening jxxx
			 */
			if (displ >= 0) {
				SEGITERATE(segno, cojumpfrom + 1,0,cointdest,
						intdest, ubintdest, ++){
D 2
					if (intdest->value > dest->value) 
E 2
I 2
D 8
					if (intdest->s_value > dest->s_value) 
E 8
I 8
D 9
					if (intdest->s_value >= dest->s_value) 
E 9
I 9
D 13
					if (intdest->s_value > dest->s_value) 
E 13
I 13
					if (intdest == dest)
E 13
E 9
E 8
E 2
						break; /* beyond destination */
D 2
					if (intdest->tag <= JXQUESTIONABLE)
E 2
I 2
					if (intdest->s_tag <= JXQUESTIONABLE)
E 2
						continue;	/*frozen solid*/
D 2
					if (intdest->tag == JXALIGN){
						jumpfrom->jxoveralign = 1;
E 2
I 2
D 16
					if (intdest->s_tag == JXALIGN){
E 16
I 16
					if (intdest->s_tag == JXALIGN)
E 16
						jumpfrom->s_jxoveralign = 1;
E 2
D 16
						badjxalign++;
					}
E 16
					/*
					 *	we assume the worst case
					 *	for unfrozen jxxxxes
					 */
D 2
					displ += intdest->jxfear;
E 2
I 2
					displ += intdest->s_jxfear;
E 2
				}
D 15
				if (displ <= MAXBYTE){
E 15
I 15
D 16
				if (displ <= highlim){
E 16
I 16
				if (displ <= highlim) {
E 16
E 15
					/*
					 *	the worst possible conditions
					 *	can't hurt us, so forget about
					 *	this jump
					 */
D 2
					jumpfrom->tag = JXINACTIVE;
E 2
I 2
					jumpfrom->s_tag = JXINACTIVE;
E 2
				} else {
					stillactives++;
I 16
					if (jumpfrom->s_jxoveralign)
						badjxalign++;
E 16
				}
			} else {
			/*
			 *	backward search for intervening jxxx
			 */
				SEGITERATE(segno, cojumpfrom - 1,1,cointdest,
				  intdest, ubintdest, --){
D 2
					if (intdest->value <= dest->value) 
E 2
I 2
D 13
					if (intdest->s_value <= dest->s_value) 
E 13
I 13
					if (intdest == dest)
E 13
E 2
						break; /* beyond destination */
D 2
					if (intdest->tag <= JXQUESTIONABLE)
E 2
I 2
					if (intdest->s_tag <= JXQUESTIONABLE)
E 2
						continue;	/*frozen solid*/
D 2
					if (intdest->tag == JXALIGN){
						jumpfrom->jxoveralign = 1;
E 2
I 2
					if (intdest->s_tag == JXALIGN){
						jumpfrom->s_jxoveralign = 1;
E 2
D 16
						badjxalign++;
E 16
					}
D 2
					displ -= intdest->jxfear; 
E 2
I 2
					displ -= intdest->s_jxfear; 
E 2
				}
D 15
				if (displ >= MINBYTE) {
E 15
I 15
				if (displ >= lowlim) {
E 15
D 2
					jumpfrom->tag = JXINACTIVE;
E 2
I 2
					jumpfrom->s_tag = JXINACTIVE;
E 2
				} else {
					stillactives++;
I 16
					if (jumpfrom->s_jxoveralign)
						badjxalign++;
E 16
				}
			}	/*end of backwards search*/
		}	/*end of iterating through all symbols in this seg*/

		if (nchange == 0) {
			/*
			 *	Now, if there are still active jxxx entries,
			 *	we are partially deadlocked.  We can leave
			 *	these jxxx entries in their assumed short jump
			 *	form, as all initial displacement calcualtions
			 *	are hanging on unresolved jxxx instructions
			 *	that might explode into a long form, causing
			 *	other jxxxes jumping across the first set of
			 *	jxxxes to explode, etc.
			 *	However, if a jxxx jumps across a .align,
			 *	we assume the worst for the deadlock cycle,
			 *	and resolve all of them towards the long
			 *	jump.
			 *	Currently, the C compiler does not produce
			 *	jumps across aligns, as aligns are only used
			 *	in data segments, or in text segments to align
			 *	functions.
			 */
			if (stillactives){
				SEGITERATE(segno, 0, 0, cojumpfrom, jumpfrom,
				    ubjumpfrom, ++){
D 2
					if (jumpfrom->tag == JXACTIVE){
						jumpfrom->tag =
E 2
I 2
D 15
					if (jumpfrom->s_tag == JXACTIVE){
						jumpfrom->s_tag =
E 2
						  badjxalign?JXNOTYET:JXINACTIVE;
E 15
I 15
					if (jumpfrom->s_tag == JXACTIVE) {
						if (badjxalign) {
							jumpfrom->s_tag =
								JXNOTYET;
							jumpfrom->s_jxstate &=
								~RELSTATE_BYTE;
							/*
							 * The above is to
							 * force jxxxbump to go
							 * all the way to long.
							 */
						} else
							jumpfrom->s_tag =
								JXINACTIVE;
E 15
					}
				}
				if (badjxalign){
					jxxxbump(segno, (struct symtab **)0);
				}
			}
			/*
			 *	Handle  all of the .align s
			 */
			SEGITERATE(segno, 0, 0, cojumpfrom, jumpfrom,
			   ubjumpfrom, ++){
D 2
			    if (jumpfrom->tag == JXALIGN){
E 2
I 2
			    if (jumpfrom->s_tag == JXALIGN){
E 2
				/*
				 *	Predict the true displacement
				 *	needed, irregardless of the
				 *	fact that we guessed 1
				 */
D 2
				displ = (jumpfrom->value - 1) & (unsigned)jumpfrom->jxfear;
E 2
I 2
D 18
				displ = (jumpfrom->s_value - 1) & (unsigned)jumpfrom->s_jxfear;
E 2
				if (displ == 0){	/*no virtual displacement*/
E 18
I 18
				displ = (jumpfrom->s_value - 1) &
					(unsigned) (jumpfrom->s_jxfear + 1);
				if (displ == 0) {	/*no virtual displacement*/
E 18
D 2
					jumpfrom->jxfear = -1;
E 2
I 2
					jumpfrom->s_jxfear = -1;
E 2
				} else {
D 2
					jumpfrom->jxfear = (jumpfrom->jxfear + 1) - displ;
E 2
I 2
D 18
					jumpfrom->s_jxfear = (jumpfrom->s_jxfear + 1) - displ;
E 2
					/*
D 2
					 *	assert jumpfrom->jxfear > 0
E 2
I 2
					 *	assert jumpfrom->s_jxfear > 0
E 2
					 */
D 2
					if (jumpfrom->jxfear == 1){
E 2
I 2
					if (jumpfrom->s_jxfear == 1){
E 2
						/*our prediction was correct*/
E 18
I 18
					jumpfrom->s_jxfear =
						(jumpfrom->s_jxfear + 2)
						- displ - 1;
					if (!jumpfrom->s_jxfear)
E 18
						continue;
D 18
					}
					/*
D 2
					 *	assert jumpfrom->jxfear > 1
E 2
I 2
					 *	assert jumpfrom->s_jxfear > 1
E 2
					 */
D 2
					jumpfrom->jxfear -= 1;	/*correct guess*/
E 2
I 2
					jumpfrom->s_jxfear -= 1;	/*correct guess*/
E 18
E 2
				}
				/*
D 2
				 *	assert jumpfrom->jxfear = -1, +1...2**n-1
E 2
I 2
				 *	assert jumpfrom->s_jxfear = -1, +1...2**n-1
E 2
				 */
D 2
				jumpfrom->tag = JXNOTYET;	/*signal*/
E 2
I 2
				jumpfrom->s_tag = JXNOTYET;	/*signal*/
E 2
				jxxxbump(segno, cojumpfrom);
D 2
				jumpfrom->tag = JXINACTIVE;
E 2
I 2
				jumpfrom->s_tag = JXINACTIVE;
E 2
				/*
				 *	Assert jxfrom->jxvalue indexes the first
				 *	code byte after the added bytes, and
				 *	has n low order zeroes.
				 */
			  }
			}	/*end of walking through each segment*/
	    	}	/*end of no changes */
		else {	/*changes, and still have to try another pass*/
			jxxxbump(segno, (struct symtab **)0);
		}
	   }	/*end of doing the topologic sort*/
	}	/*end of iterating through all segments*/
}	/*end of jxxxfix*/

/*
 *	Go through the symbols in a given segment number,
 *	and see which entries are jxxx entries that have
 *	been logically "exploded" (expanded), but for which
 *	the value of textually following symbols has not been
 *	increased
 */

jxxxbump(segno, starthint)
	int	segno;
	struct	symtab **starthint;
{
	register	struct	symtab	**cosp, *sp;
	register	struct	symtab		*ub;
D 15
	register	int	cum_bump;
E 15
I 15
	register	int	bump, cum_bump;
E 15
	register	unsigned	char	tag;

	cum_bump = 0;
	SEGITERATE(segno, starthint, 0, cosp, sp, ub, ++){
D 2
		tag = sp->tag;
E 2
I 2
		tag = sp->s_tag;
E 2
		if (tag == JXNOTYET){
#ifdef DEBUG
			if (debug){
D 2
			if (sp->dest != 0)
E 2
I 2
			if (sp->s_dest != 0)
E 2
				printf("Explode jump to %s on line %d\n",
D 2
					sp->dest->name, lineno);
E 2
I 2
D 7
					sp->s_dest->s_name, lineno);
E 7
I 7
D 8
					FETCHNAME(sp->s_dest), lineno);
E 8
I 8
					FETCHNAME(sp->s_dest), sp->s_jxline);
E 8
E 7
E 2
			else
D 8
				printf("Explode an align!\n");
E 8
I 8
				printf("Explode an align! on line %d\n",
					sp->s_jxline);
E 8
			}
#endif
D 2
			sp->tag = JXINACTIVE;
			sp->jxbump = 1;
			cum_bump += sp->jxfear;
E 2
I 2
D 15
			sp->s_tag = JXINACTIVE;
			sp->s_jxbump = 1;
			cum_bump += sp->s_jxfear;
E 15
I 15
			if (sp->s_jxstate == RELSTATE_ALIGN) {
				sp->s_tag = JXINACTIVE;
				cum_bump += sp->s_jxfear;
			} else if (sp->s_jxstate & RELSTATE_BYTE) {
				bump = byterelax_bumps[sp->s_jxstate >> 1];
				cum_bump += bump;
				sp->s_tag = JXACTIVE;
				sp->s_jxstate &= ~RELSTATE_BYTE;
				sp->s_jxfear -= bump;
			} else {
				cum_bump += sp->s_jxfear;
				sp->s_tag = JXINACTIVE;
				sp->s_jxstate = RELSTATE_LONG;
				sp->s_jxfear = 0;
			}
E 15
E 2
		}
		/*
		 *	Only bump labels and jxxxes. Ignored entries can
		 *	be incremented, as they are thrown away later on.
		 *	Stabds are given their final value in the second 
		 *	pass.
		 */
		if (tag >= OKTOBUMP)	/*only bump labels and jxxxes and floating stabs*/
D 2
			sp->value += cum_bump;
E 2
I 2
			sp->s_value += cum_bump;
E 2
	}
D 2
	usedot[segno].xvalue += cum_bump;
E 2
I 2
	usedot[segno].e_xvalue += cum_bump;
E 2
}
E 1
