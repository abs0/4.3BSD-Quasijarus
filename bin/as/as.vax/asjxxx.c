/*
 * Copyright (c) 1982 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "@(#)asjxxx.c	5.9 (Berkeley) 11/8/03";
#endif not lint

#include	<stdio.h>
#include	"as.h"
#include	"assyms.h"

/* These are the opcodes involved in relaxation. */
#define	BRB	0x11
#define	BRW	0x31
#define	JMP	0x17
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

/* Bumps for byte to word relaxations, indexed by s_jxstate>>1. */
static int byterelax_bumps[5] = {1, 3, 4, 5, 2};

/*
 *	These variables are filled by asscan.c with the
 *	last name encountered (a pointer buried in the intermediate file),
 *	and the last jxxx symbol table entry encountered.
 */
struct 	symtab	*lastnam;
struct	symtab	*lastjxxx;

/*
 *	Handle jxxx instructions
 */
ijxout(opcode, ap, nact)
	struct	Opcode	opcode;
	struct	arg	*ap;
	int	nact;
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
		putins(opcode, ap, nact); 
		jumpfrom = lastjxxx;
		jumpfrom->s_tag = JXACTIVE;
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
		if (lastnam == 0)
			yyerror("jxxx destination not a label");
		jumpfrom->s_dest = lastnam;
		jumpfrom->s_type = dotp->e_xtype;	/*only TEXT or DATA*/
		jumpfrom->s_index = dotp-usedot;
#ifdef DEBUG
		jumpfrom->s_name = ITABFETCH(opcode)->i_name;
		jumpfrom->s_jxline = lineno;
#endif
		/*
		 *	value ALWAYS (ALWAYS!!!) indexes the next instruction
		 *	after the jump, even if the jump must be exploded
		 *	(bumped)
		 */
		jumpfrom->s_value = dotp->e_xvalue;
		njxxx++;
	} else {/* pass2, resolve */
		/*
		 *	READ THIS AFTER LOOKING AT jxxxfix()
		 */
		reg	long		oxvalue;
		reg	struct	exp 	*xp; 
		reg	struct	symtab	*tunnel;
		reg	struct	arg	*aplast;
			struct	Opcode	nopcode;

		aplast = ap + nact - 1;
		xp = aplast->a_xp;
		if (lastjxxx->s_tag == JXTUNNEL){
			lastjxxx->s_tag = JXINACTIVE;
			tunnel = lastjxxx->s_dest;
			xp->e_xvalue = tunnel->s_value;	/*index of instruction following*/
			if (tunnel->s_jxstate & RELSTATE_BYTE)
				xp->e_xvalue -= 2;
			else if (tunnel->s_jxstate == RELSTATE_LONG)
				xp->e_xvalue -= 6;
			else
				xp->e_xvalue -= 3;
		}
		/* Now determine what instruction or sequence to emit. */
		if ((lastjxxx->s_jxstate & RELSTATE_BYTE)
		    || lastjxxx->s_jxstate == RELSTATE_ACBXW) {
			/* No relaxation, real VAX instruction. */
			putins(opcode, ap, nact);
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
		} else {
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
				oxvalue = xp->e_xvalue;
				xp->e_xvalue = lastjxxx->s_value;
				nopcode = opcode;
				nopcode.Op_popcode ^= 1;
				putins(nopcode, ap, nact);
				xp->e_xvalue = oxvalue;
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
			}
			nopcode.Op_eopcode = CORE;
			nopcode.Op_popcode =
			    (lastjxxx->s_jxstate == RELSTATE_LONG) ? JMP : BRW;
			aplast->a_dispsize = 4;
			putins(nopcode, aplast, 1);
		}
	}
}

jalign(xp, sp)
	register struct exp *xp;
	register struct symtab *sp;
{
	register	int	mask;
#ifdef DEBUG
	static struct strdesc noname;
#endif
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
	 *	to a .align (maxalign), if possible, where maxalign
	 *	is set in the command line, and defaults to 2.
	 */
	if (   ( (xp->e_xtype & XTYPE) != XABS)
	    || (xp->e_xvalue <= 0)
	    || (xp->e_xvalue > 16)
	    ) {
		yyerror("Illegal `align' argument");
		return;
	}
	if (xp->e_xvalue > maxalign){
		if (passno == 1){
			yywarning(".align %d is NOT preserved by the loader",
				xp->e_xvalue);
			yywarning(".align %d converted to .align %d",
				xp->e_xvalue, maxalign);
		}
		xp->e_xvalue = maxalign;
	}
	flushfield(NBWD/4);
	if (passno == 1) {
		sp->s_tag = JXALIGN;
		sp->s_jxstate = RELSTATE_ALIGN;
		sp->s_jxfear = (1 << xp->e_xvalue) - 2;
		sp->s_type = dotp->e_xtype;
		sp->s_index = dotp-usedot;
#ifdef DEBUG
		sp->s_name = (char *)&noname;
		sp->s_jxline = lineno;
#endif
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
		dotp->e_xvalue += 1;
		sp->s_value = dotp->e_xvalue;
		njxxx++;
	} else {
		mask = (1 << xp->e_xvalue) - 1;
		while (dotp->e_xvalue & mask)
			Outb(0);
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

	 	 int 		displ, lowlim, highlim, nchange;
		 int		badjxalign;	/*if jump across an align*/
		 int		stillactives;	/*if still active jxxxes*/
		 int		segno;		/*current segment number*/
		 int		topono;		/*which iteration in the topo sort*/
	/*
	 *	consider each segment in turn...
	 */
	for (segno = 0; segno < NLOC + NLOC; segno++){
	    /*
	     *	Do a lazy topological sort.
	     */
	    for (topono = 1, nchange = 1; nchange != 0; topono++){
#ifdef lint
		topno = topno;
#endif lint
#ifdef DEBUG
		if (debug)
			printf("\nSegment %d, topo iteration %d\n",
				segno, topono);
#endif
		nchange = 0;
		stillactives = 0;
		badjxalign = 0;
		SEGITERATE(segno, 0, 0, cojumpfrom, jumpfrom, ubjumpfrom, ++) {
			if (jumpfrom->s_tag != JXACTIVE)
				continue;
			dest = jumpfrom->s_dest;
			if (jumpfrom->s_index != dest->s_index) {
				yyerror("Intersegment jxxx");
				continue;
			}
			displ = dest->s_value - jumpfrom->s_value;
			if (jumpfrom->s_jxstate & RELSTATE_BYTE) {
				lowlim = MINBYTE;
				highlim = MAXBYTE;
			} else {
				lowlim = MINWORD;
				highlim = MAXWORD;
			}
			if (displ < lowlim || displ > highlim) {
				/*
				 * We have to bump it. If it's a conditional
				 * branch, a SOB, an AOB, or an ACB, this will
				 * mean turning a nice single instruction into
				 * a branch-around sequence. Rather than do
				 * that if possible, we try to tunnel this
				 * branch instead through a nearby
				 * unconditional jump (either a jbr or part of
				 * a relaxed sequence).
				 */
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
#ifdef DEBUG
				if(debug)
					printf("Tunnel from %s from line %d\n",
						FETCHNAME(jumpfrom),
						jumpfrom->s_jxline);
#endif
				continue;
			}
			/*
			 *	Do a forward search for an intervening jxxx
			 */
			if (displ >= 0) {
				SEGITERATE(segno, cojumpfrom + 1,0,cointdest,
						intdest, ubintdest, ++){
					if (intdest == dest)
						break; /* beyond destination */
					if (intdest->s_tag <= JXQUESTIONABLE)
						continue;	/*frozen solid*/
					if (intdest->s_tag == JXALIGN)
						jumpfrom->s_jxoveralign = 1;
					/*
					 *	we assume the worst case
					 *	for unfrozen jxxxxes
					 */
					displ += intdest->s_jxfear;
				}
				if (displ <= highlim) {
					/*
					 *	the worst possible conditions
					 *	can't hurt us, so forget about
					 *	this jump
					 */
					jumpfrom->s_tag = JXINACTIVE;
				} else {
					stillactives++;
					if (jumpfrom->s_jxoveralign)
						badjxalign++;
				}
			} else {
			/*
			 *	backward search for intervening jxxx
			 */
				SEGITERATE(segno, cojumpfrom - 1,1,cointdest,
				  intdest, ubintdest, --){
					if (intdest == dest)
						break; /* beyond destination */
					if (intdest->s_tag <= JXQUESTIONABLE)
						continue;	/*frozen solid*/
					if (intdest->s_tag == JXALIGN){
						jumpfrom->s_jxoveralign = 1;
					}
					displ -= intdest->s_jxfear; 
				}
				if (displ >= lowlim) {
					jumpfrom->s_tag = JXINACTIVE;
				} else {
					stillactives++;
					if (jumpfrom->s_jxoveralign)
						badjxalign++;
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
			    if (jumpfrom->s_tag == JXALIGN){
				/*
				 *	Predict the true displacement
				 *	needed, irregardless of the
				 *	fact that we guessed 1
				 */
				displ = (jumpfrom->s_value - 1) &
					(unsigned) (jumpfrom->s_jxfear + 1);
				if (displ == 0) {	/*no virtual displacement*/
					jumpfrom->s_jxfear = -1;
				} else {
					jumpfrom->s_jxfear =
						(jumpfrom->s_jxfear + 2)
						- displ - 1;
					if (!jumpfrom->s_jxfear)
						continue;
				}
				/*
				 *	assert jumpfrom->s_jxfear = -1, +1...2**n-1
				 */
				jumpfrom->s_tag = JXNOTYET;	/*signal*/
				jxxxbump(segno, cojumpfrom);
				jumpfrom->s_tag = JXINACTIVE;
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
	register	int	bump, cum_bump;
	register	unsigned	char	tag;

	cum_bump = 0;
	SEGITERATE(segno, starthint, 0, cosp, sp, ub, ++){
		tag = sp->s_tag;
		if (tag == JXNOTYET){
#ifdef DEBUG
			if (debug){
			if (sp->s_dest != 0)
				printf("Explode jump to %s on line %d\n",
					FETCHNAME(sp->s_dest), sp->s_jxline);
			else
				printf("Explode an align! on line %d\n",
					sp->s_jxline);
			}
#endif
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
		}
		/*
		 *	Only bump labels and jxxxes. Ignored entries can
		 *	be incremented, as they are thrown away later on.
		 *	Stabds are given their final value in the second 
		 *	pass.
		 */
		if (tag >= OKTOBUMP)	/*only bump labels and jxxxes and floating stabs*/
			sp->s_value += cum_bump;
	}
	usedot[segno].e_xvalue += cum_bump;
}
