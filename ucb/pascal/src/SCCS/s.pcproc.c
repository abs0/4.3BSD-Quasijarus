h64459
s 00007/00003/01585
d D 5.1 85/06/05 15:21:20 dist 32 31
c Add copyright
e
s 00277/00277/01311
d D 2.2 85/03/20 15:04:19 ralph 31 30
c changes from donn@utah-cs for common header file for pcc
e
s 00000/00000/01588
d D 2.1 84/02/08 20:48:17 aoki 30 29
c synchronize to version 2
e
s 00000/00000/01588
d D 1.23 84/02/04 19:19:18 mckusick 29 27
i 28
c merge lint by thien
e
s 00219/00204/01364
d D 1.21.1.1 84/02/04 19:16:05 mckusick 28 26
c lint (by thien)
e
s 00007/00002/01566
d D 1.22 83/10/19 10:55:06 peter 27 26
c can't free temporaries in the middle of a tree,
c since lbrackets get acted on as they are seen
c so the temporary is freed before it is actually used by the second pass.
e
s 00011/00005/01557
d D 1.21 83/04/08 16:45:20 mckusick 26 25
c parameterize number of digits in the exponent of real numbers
e
s 00009/00008/01553
d D 1.20 83/04/06 22:11:16 peter 25 24
c it says in my description of the ir that STASG's have the type
c pointer to structure.  this makes a difference for the FORCE in fend.c
c on the mc68000.
e
s 00001/00000/01560
d D 1.19 83/02/28 17:18:17 peter 24 23
c clean up temporary allocation, moving everything relevant to
c tmps.c and (new) tmps.h.  correctly emit LBRAC lines.  allocate registers
c from high to low.  put in data structures for multiple types of registers.
e
s 00001/00001/01559
d D 1.18 83/02/01 21:53:42 peter 23 22
c type of a P2CALL has to match the type of the function
c for the more stringent 68000 compiler.
e
s 00000/00000/01560
d D 1.17 83/01/17 14:15:51 peter 22 18
i 21 20 19
c merge in 1.16 and 1.15.1.
e
s 00003/00002/01554
d D 1.15.1.3 83/01/17 14:11:59 peter 21 20
c port to the mc68000.
e
s 00000/00000/01556
d D 1.15.1.2 83/01/17 14:09:22 peter 20 19
c port to the mc68000.
e
s 00000/00000/01556
d D 1.15.1.1 83/01/17 14:06:12 peter 19 17
c branch-place-holder
e
s 00008/00005/01551
d D 1.16 83/01/17 14:03:30 peter 18 17
c put in explicit scalar converts (sconv's) to make less code-generator dependent.
e
s 00001/00001/01555
d D 1.15 82/11/16 13:01:14 mckusick 17 15
c misssing level of indirectin in ptr passed to blkclr() after NEW()
e
s 00001/00001/01555
d R 1.15 82/11/16 12:40:03 mckusick 16 15
c missed a level of indirection...
e
s 00017/00005/01539
d D 1.14 82/11/14 16:40:54 mckusick 15 14
c fix bug in delta 1.12 that made fields come out one byte shorter than requested
e
s 00021/00011/01523
d D 1.13 82/11/12 19:14:46 mckusick 14 13
c get rid of NEWZ (use NEW + blkclr); break ASRTS out of ASRT
e
s 00001/00001/01533
d D 1.12 82/09/03 18:06:19 mckusick 13 12
c do not put a leading blank before real numbers
e
s 00014/00004/01520
d D 1.11 82/08/29 21:29:17 mckusick 12 11
c remove restriction on files in dynamic structures
e
s 00002/00000/01522
d D 1.10 82/08/29 14:07:53 peter 11 10
c allowing no files list in program statement.
e
s 00036/00001/01486
d D 1.9 82/08/27 00:35:00 mckusick 10 9
c convert "assert" from being a reserved word to being a non-standard procedure
e
s 00014/00001/01473
d D 1.8 82/04/12 15:18:14 mckusick 9 8
c allow writing of pointers to text files
e
s 00001/00001/01473
d D 1.7 81/10/23 10:54:29 peter 8 7
c RSGN4 becomes RSNG4 to avoid undefined symbol when loading.
e
s 00075/00055/01399
d D 1.6 81/06/01 15:38:41 peter 7 6
c add storage classes to namelist, and use them.
e
s 00009/00010/01445
d D 1.5 81/03/11 23:38:21 mckusic 6 5
c centralize temporary allocation in tmps.c
e
s 00006/00000/01449
d D 1.4 81/03/10 14:49:25 mckusic 5 4
c restrict zero write widths
e
s 00004/00002/01445
d D 1.3 80/10/28 21:35:25 peter 4 2
c add warnings for extensions to language
e
s 00002/00001/01446
d R 1.3 80/10/28 21:10:26 peter 3 2
c add warnings for extensions to language
e
s 00001/00001/01446
d D 1.2 80/10/03 01:08:38 peter 2 1
c Implement formal functions and procedures
e
s 01447/00000/00000
d D 1.1 80/08/27 19:55:50 peter 1 0
c date and time created 80/08/27 19:55:50 by peter
e
u
U
f b 
t
T
I 1
D 32
/* Copyright (c) 1979 Regents of the University of California */
E 32
I 32
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 32

I 28
#ifndef lint
E 28
D 32
static	char sccsid[] = "%Z%%M% %I% %G%";
I 28
#endif
E 32
I 32
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 32
E 28

#include "whoami.h"
#ifdef PC
    /*
     * and to the end of the file
     */
#include "0.h"
#include "tree.h"
I 21
#include "objfmt.h"
E 21
#include "opcode.h"
D 21
#include	"pc.h"
#include	"pcops.h"
E 21
I 21
#include "pc.h"
D 31
#include "pcops.h"
E 31
I 31
#include <pcc.h>
E 31
I 24
#include "tmps.h"
I 28
#include "tree_ty.h"
E 28
E 24
E 21

/*
I 26
 * The constant EXPOSIZE specifies the number of digits in the exponent
 * of real numbers.
 *
E 26
I 15
 * The constant REALSPC defines the amount of forced padding preceeding
 * real numbers when they are printed. If REALSPC == 0, then no padding
 * is added, REALSPC == 1 adds one extra blank irregardless of the width
 * specified by the user.
 *
 * N.B. - Values greater than one require program mods.
 */
D 26
#define	REALSPC	0
E 26
I 26
#define EXPOSIZE	2
#define	REALSPC		0
E 26

/*
E 15
 * The following array is used to determine which classes may be read
 * from textfiles. It is indexed by the return value from classify.
 */
#define rdops(x) rdxxxx[(x)-(TFIRST)]

int rdxxxx[] = {
	0,		/* -7 file types */
	0,		/* -6 record types */
	0,		/* -5 array types */
	O_READE,	/* -4 scalar types */
	0,		/* -3 pointer types */
	0,		/* -2 set types */
	0,		/* -1 string types */
	0,		/*  0 nil, no type */
	O_READE,	/*  1 boolean */
	O_READC,	/*  2 character */
	O_READ4,	/*  3 integer */
	O_READ8		/*  4 real */
};

/*
 * Proc handles procedure calls.
 * Non-builtin procedures are "buck-passed" to func (with a flag
 * indicating that they are actually procedures.
 * builtin procedures are handled here.
 */
pcproc(r)
D 28
	int *r;
E 28
I 28
	struct tnode *r;	/* T_PCALL */
E 28
{
	register struct nl *p;
D 28
	register int *alv, *al, op;
E 28
I 28
	register struct tnode *alv, *al;
	register op;
E 28
	struct nl *filetype, *ap;
D 28
	int argc, *argv, typ, fmtspec, strfmt, stkcnt, *file;
E 28
I 28
	int argc, typ, fmtspec, strfmt;
	struct tnode *argv, *file;
E 28
D 12
	char fmt, format[20], *strptr;
E 12
I 12
	char fmt, format[20], *strptr, *cmd;
E 12
D 28
	int prec, field, strnglen, fmtlen, fmtstart, pu;
	int *pua, *pui, *puz;
E 28
I 28
	int prec, field, strnglen, fmtstart;
	char *pu;
	struct tnode *pua, *pui, *puz;
E 28
	int i, j, k;
	int itemwidth;
D 7
	char	*readname;
	long	tempoff;
	long	readtype;
I 6
	struct tmps soffset;
E 7
I 7
	char		*readname;
	struct nl	*tempnlp;
	long		readtype;
	struct tmps	soffset;
I 27
	bool		soffset_flag;
E 27
E 7
E 6

#define	CONPREC 4
#define	VARPREC 8
#define	CONWIDTH 1
#define	VARWIDTH 2
#define SKIP 16

	/*
	 * Verify that the name is
	 * defined and is that of a
	 * procedure.
	 */
D 28
	p = lookup(r[2]);
	if (p == NIL) {
		rvlist(r[3]);
E 28
I 28
	p = lookup(r->pcall_node.proc_id);
	if (p == NLNIL) {
		rvlist(r->pcall_node.arg);
E 28
		return;
	}
D 2
	if (p->class != PROC) {
E 2
I 2
	if (p->class != PROC && p->class != FPROC) {
E 2
		error("Can't call %s, its %s not a procedure", p->symbol, classes[p->class]);
D 28
		rvlist(r[3]);
E 28
I 28
		rvlist(r->pcall_node.arg);
E 28
		return;
	}
D 28
	argv = r[3];
E 28
I 28
	argv = r->pcall_node.arg;
E 28

	/*
	 * Call handles user defined
	 * procedures and functions.
	 */
	if (bn != 0) {
D 28
		call(p, argv, PROC, bn);
E 28
I 28
		(void) call(p, argv, PROC, bn);
E 28
		return;
	}

	/*
	 * Call to built-in procedure.
	 * Count the arguments.
	 */
	argc = 0;
D 28
	for (al = argv; al != NIL; al = al[2])
E 28
I 28
	for (al = argv; al != TR_NIL; al = al->list_node.next)
E 28
		argc++;

	/*
	 * Switch on the operator
	 * associated with the built-in
	 * procedure in the namelist
	 */
	op = p->value[0] &~ NSTAND;
	if (opt('s') && (p->value[0] & NSTAND)) {
		standard();
		error("%s is a nonstandard procedure", p->symbol);
	}
	switch (op) {

	case O_ABORT:
		if (argc != 0)
			error("null takes no arguments");
		return;

	case O_FLUSH:
		if (argc == 0) {
D 31
			putleaf( P2ICON , 0 , 0 , P2INT , "_PFLUSH" );
			putop( P2UNARY P2CALL , P2INT );
E 31
I 31
			putleaf( PCC_ICON , 0 , 0 , PCCT_INT , "_PFLUSH" );
			putop( PCCOM_UNARY PCC_CALL , PCCT_INT );
E 31
			putdot( filename , line );
			return;
		}
		if (argc != 1) {
			error("flush takes at most one argument");
			return;
		}
D 31
		putleaf( P2ICON , 0 , 0
			, ADDTYPE( P2FTN | P2INT , P2PTR )
E 31
I 31
		putleaf( PCC_ICON , 0 , 0
			, PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 31
			, "_FLUSH" );
D 28
		ap = stklval(argv[1], NOFLAGS);
		if (ap == NIL)
E 28
I 28
		ap = stklval(argv->list_node.list, NOFLAGS);
		if (ap == NLNIL)
E 28
			return;
		if (ap->class != FILET) {
			error("flush's argument must be a file, not %s", nameof(ap));
			return;
		}
D 31
		putop( P2CALL , P2INT );
E 31
I 31
		putop( PCC_CALL , PCCT_INT );
E 31
		putdot( filename , line );
		return;

	case O_MESSAGE:
	case O_WRITEF:
	case O_WRITLN:
		/*
		 * Set up default file "output"'s type
		 */
		file = NIL;
		filetype = nl+T1CHAR;
		/*
		 * Determine the file implied
		 * for the write and generate
		 * code to make it the active file.
		 */
		if (op == O_MESSAGE) {
			/*
			 * For message, all that matters
			 * is that the filetype is
			 * a character file.
			 * Thus "output" will suit us fine.
			 */
D 31
			putleaf( P2ICON , 0 , 0 , P2INT , "_PFLUSH" );
			putop( P2UNARY P2CALL , P2INT );
E 31
I 31
			putleaf( PCC_ICON , 0 , 0 , PCCT_INT , "_PFLUSH" );
			putop( PCCOM_UNARY PCC_CALL , PCCT_INT );
E 31
			putdot( filename , line );
D 7
			putRV( 0 , cbn , CURFILEOFFSET , P2PTR|P2STRTY );
			putLV( "__err" , 0 , 0 , P2PTR|P2STRTY );
E 7
I 7
D 28
			putRV( 0 , cbn , CURFILEOFFSET , NLOCAL ,
E 28
I 28
			putRV( (char *) 0 , cbn , CURFILEOFFSET , NLOCAL ,
E 28
D 31
				P2PTR|P2STRTY );
			putLV( "__err" , 0 , 0 , NGLOBAL , P2PTR|P2STRTY );
E 7
			putop( P2ASSIGN , P2PTR|P2STRTY );
E 31
I 31
				PCCTM_PTR|PCCT_STRTY );
			putLV( "__err" , 0 , 0 , NGLOBAL , PCCTM_PTR|PCCT_STRTY );
			putop( PCC_ASSIGN , PCCTM_PTR|PCCT_STRTY );
E 31
			putdot( filename , line );
D 28
		} else if (argv != NIL && (al = argv[1])[0] != T_WEXP) {
E 28
I 28
		} else if (argv != TR_NIL && (al = argv->list_node.list)->tag !=
					T_WEXP) {
E 28
			/*
			 * If there is a first argument which has
			 * no write widths, then it is potentially
			 * a file name.
			 */
			codeoff();
D 28
			ap = stkrval(argv[1], NIL , RREQ );
E 28
I 28
			ap = stkrval(argv->list_node.list, NLNIL, (long) RREQ );
E 28
			codeon();
D 28
			if (ap == NIL)
				argv = argv[2];
E 28
I 28
			if (ap == NLNIL)
				argv = argv->list_node.next;
E 28
			if (ap != NIL && ap->class == FILET) {
				/*
				 * Got "write(f, ...", make
				 * f the active file, and save
				 * it and its type for use in
				 * processing the rest of the
				 * arguments to write.
				 */
D 7
				putRV( 0 , cbn , CURFILEOFFSET
					, P2PTR|P2STRTY );
E 7
I 7
D 28
				putRV( 0 , cbn , CURFILEOFFSET , NLOCAL ,
E 28
I 28
				putRV((char *) 0 , cbn , CURFILEOFFSET , NLOCAL ,
E 28
D 31
					P2PTR|P2STRTY );
E 7
				putleaf( P2ICON , 0 , 0
				    , ADDTYPE( P2FTN | P2INT , P2PTR )
E 31
I 31
					PCCTM_PTR|PCCT_STRTY );
				putleaf( PCC_ICON , 0 , 0
				    , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 31
				    , "_UNIT" );
D 28
				file = argv[1];
E 28
I 28
				file = argv->list_node.list;
E 28
				filetype = ap->type;
D 28
				stklval(argv[1], NOFLAGS);
E 28
I 28
				(void) stklval(argv->list_node.list, NOFLAGS);
E 28
D 31
				putop( P2CALL , P2INT );
				putop( P2ASSIGN , P2PTR|P2STRTY );
E 31
I 31
				putop( PCC_CALL , PCCT_INT );
				putop( PCC_ASSIGN , PCCTM_PTR|PCCT_STRTY );
E 31
				putdot( filename , line );
				/*
				 * Skip over the first argument
				 */
D 28
				argv = argv[2];
E 28
I 28
				argv = argv->list_node.next;
E 28
				argc--;
			} else {
				/*
				 * Set up for writing on 
				 * standard output.
				 */
D 7
				putRV( 0, cbn , CURFILEOFFSET , P2PTR|P2STRTY );
				putLV( "_output" , 0 , 0 , P2PTR|P2STRTY );
E 7
I 7
D 28
				putRV( 0, cbn , CURFILEOFFSET ,
E 28
I 28
				putRV((char *) 0, cbn , CURFILEOFFSET ,
E 28
D 31
					NLOCAL , P2PTR|P2STRTY );
E 31
I 31
					NLOCAL , PCCTM_PTR|PCCT_STRTY );
E 31
				putLV( "_output" , 0 , 0 , NGLOBAL ,
D 31
					P2PTR|P2STRTY );
E 7
				putop( P2ASSIGN , P2PTR|P2STRTY );
E 31
I 31
					PCCTM_PTR|PCCT_STRTY );
				putop( PCC_ASSIGN , PCCTM_PTR|PCCT_STRTY );
E 31
				putdot( filename , line );
I 11
				output->nl_flags |= NUSED;
E 11
			}
		} else {
D 7
			putRV( 0, cbn , CURFILEOFFSET , P2PTR|P2STRTY );
			putLV( "_output" , 0 , 0 , P2PTR|P2STRTY );
E 7
I 7
D 28
			putRV( 0, cbn , CURFILEOFFSET , NLOCAL ,
E 28
I 28
			putRV((char *) 0, cbn , CURFILEOFFSET , NLOCAL ,
E 28
D 31
				P2PTR|P2STRTY );
			putLV( "_output" , 0 , 0 , NGLOBAL , P2PTR|P2STRTY );
E 7
			putop( P2ASSIGN , P2PTR|P2STRTY );
E 31
I 31
				PCCTM_PTR|PCCT_STRTY );
			putLV( "_output" , 0 , 0 , NGLOBAL , PCCTM_PTR|PCCT_STRTY );
			putop( PCC_ASSIGN , PCCTM_PTR|PCCT_STRTY );
E 31
			putdot( filename , line );
I 11
			output->nl_flags |= NUSED;
E 11
		}
		/*
		 * Loop and process each
		 * of the arguments.
		 */
D 28
		for (; argv != NIL; argv = argv[2]) {
E 28
I 28
		for (; argv != TR_NIL; argv = argv->list_node.next) {
E 28
I 27
		        soffset_flag = FALSE;
E 27
			/*
			 * fmtspec indicates the type (CONstant or VARiable)
			 *	and number (none, WIDTH, and/or PRECision)
			 *	of the fields in the printf format for this
			 *	output variable.
D 28
			 * stkcnt is the number of longs pushed on the stack
E 28
			 * fmt is the format output indicator (D, E, F, O, X, S)
			 * fmtstart = 0 for leading blank; = 1 for no blank
			 */
			fmtspec = NIL;
D 28
			stkcnt = 0;
E 28
			fmt = 'D';
			fmtstart = 1;
D 28
			al = argv[1];
E 28
I 28
			al = argv->list_node.list;
E 28
			if (al == NIL)
				continue;
D 28
			if (al[0] == T_WEXP)
				alv = al[1];
E 28
I 28
			if (al->tag == T_WEXP)
				alv = al->wexpr_node.expr1;
E 28
			else
				alv = al;
D 28
			if (alv == NIL)
E 28
I 28
			if (alv == TR_NIL)
E 28
				continue;
			codeoff();
D 28
			ap = stkrval(alv, NIL , RREQ );
E 28
I 28
			ap = stkrval(alv, NLNIL , (long) RREQ );
E 28
			codeon();
D 28
			if (ap == NIL)
E 28
I 28
			if (ap == NLNIL)
E 28
				continue;
			typ = classify(ap);
D 28
			if (al[0] == T_WEXP) {
E 28
I 28
			if (al->tag == T_WEXP) {
E 28
				/*
				 * Handle width expressions.
				 * The basic game here is that width
				 * expressions get evaluated. If they
				 * are constant, the value is placed
				 * directly in the format string.
				 * Otherwise the value is pushed onto
				 * the stack and an indirection is
				 * put into the format string.
				 */
D 28
				if (al[3] == OCT)
E 28
I 28
				if (al->wexpr_node.expr3 == 
						(struct tnode *) OCT)
E 28
					fmt = 'O';
D 28
				else if (al[3] == HEX)
E 28
I 28
				else if (al->wexpr_node.expr3 == 
						(struct tnode *) HEX)
E 28
					fmt = 'X';
D 28
				else if (al[3] != NIL) {
E 28
I 28
				else if (al->wexpr_node.expr3 != TR_NIL) {
E 28
					/*
					 * Evaluate second format spec
					 */
D 28
					if ( constval(al[3])
E 28
I 28
					if ( constval(al->wexpr_node.expr3)
E 28
					    && isa( con.ctype , "i" ) ) {
						fmtspec += CONPREC;
						prec = con.crval;
					} else {
						fmtspec += VARPREC;
					}
					fmt = 'f';
					switch ( typ ) {
					case TINT:
						if ( opt( 's' ) ) {
						    standard();
						    error("Writing %ss with two write widths is non-standard", clnames[typ]);
						}
						/* and fall through */
					case TDOUBLE:
						break;
					default:
						error("Cannot write %ss with two write widths", clnames[typ]);
						continue;
					}
				}
				/*
				 * Evaluate first format spec
				 */
D 28
				if (al[2] != NIL) {
					if ( constval(al[2])
E 28
I 28
				if (al->wexpr_node.expr2 != TR_NIL) {
					if ( constval(al->wexpr_node.expr2)
E 28
					    && isa( con.ctype , "i" ) ) {
						fmtspec += CONWIDTH;
						field = con.crval;
					} else {
						fmtspec += VARWIDTH;
					}
				}
				if ((fmtspec & CONPREC) && prec < 0 ||
				    (fmtspec & CONWIDTH) && field < 0) {
					error("Negative widths are not allowed");
					continue;
				}
I 5
				if ( opt('s') &&
				    ((fmtspec & CONPREC) && prec == 0 ||
				    (fmtspec & CONWIDTH) && field == 0)) {
					standard();
					error("Zero widths are non-standard");
				}
E 5
			}
			if (filetype != nl+T1CHAR) {
				if (fmt == 'O' || fmt == 'X') {
					error("Oct/hex allowed only on text files");
					continue;
				}
				if (fmtspec) {
					error("Write widths allowed only on text files");
					continue;
				}
				/*
				 * Generalized write, i.e.
				 * to a non-textfile.
				 */
D 31
				putleaf( P2ICON , 0 , 0
D 28
				    , ADDTYPE(
E 28
I 28
				    , (int) (ADDTYPE(
E 28
					ADDTYPE(
					    ADDTYPE( p2type( filetype )
						    , P2PTR )
					    , P2FTN )
D 28
					, P2PTR )
E 28
I 28
					, P2PTR ))
E 31
I 31
				putleaf( PCC_ICON , 0 , 0
				    , (int) (PCCM_ADDTYPE(
					PCCM_ADDTYPE(
					    PCCM_ADDTYPE( p2type( filetype )
						    , PCCTM_PTR )
					    , PCCTM_FTN )
					, PCCTM_PTR ))
E 31
E 28
				    , "_FNIL" );
D 28
				stklval(file, NOFLAGS);
E 28
I 28
				(void) stklval(file, NOFLAGS);
E 28
D 31
				putop( P2CALL
				    , ADDTYPE( p2type( filetype ) , P2PTR ) );
				putop( P2UNARY P2MUL , p2type( filetype ) );
E 31
I 31
				putop( PCC_CALL
				    , PCCM_ADDTYPE( p2type( filetype ) , PCCTM_PTR ) );
				putop( PCCOM_UNARY PCC_MUL , p2type( filetype ) );
E 31
				/*
				 * file^ := ...
				 */
				switch ( classify( filetype ) ) {
				    case TBOOL:
				    case TCHAR:
				    case TINT:
				    case TSCAL:
D 8
					precheck( filetype , "_RANG4"  , "_RSGN4" );
E 8
I 8
					precheck( filetype , "_RANG4"  , "_RSNG4" );
E 8
					    /* and fall through */
				    case TDOUBLE:
				    case TPTR:
D 28
					ap = rvalue( argv[1] , filetype , RREQ );
E 28
I 28
					ap = rvalue( argv->list_node.list , filetype , RREQ );
E 28
					break;
				    default:
D 28
					ap = rvalue( argv[1] , filetype , LREQ );
E 28
I 28
					ap = rvalue( argv->list_node.list , filetype , LREQ );
E 28
					break;
				}
				if (ap == NIL)
					continue;
D 28
				if (incompat(ap, filetype, argv[1])) {
E 28
I 28
				if (incompat(ap, filetype, argv->list_node.list)) {
E 28
					cerror("Type mismatch in write to non-text file");
					continue;
				}
				switch ( classify( filetype ) ) {
				    case TBOOL:
				    case TCHAR:
				    case TINT:
				    case TSCAL:
D 18
					    postcheck( filetype );
E 18
I 18
					    postcheck(filetype, ap);
					    sconv(p2type(ap), p2type(filetype));
E 18
						/* and fall through */
				    case TDOUBLE:
				    case TPTR:
D 31
					    putop( P2ASSIGN , p2type( filetype ) );
E 31
I 31
					    putop( PCC_ASSIGN , p2type( filetype ) );
E 31
					    putdot( filename , line );
					    break;
				    default:
D 25
					    putstrop( P2STASG
							, p2type( filetype )
							, lwidth( filetype )
							, align( filetype ) );
E 25
I 25
D 31
					    putstrop(P2STASG,
						    ADDTYPE(p2type(filetype),
							    P2PTR),
E 31
I 31
					    putstrop(PCC_STASG,
						    PCCM_ADDTYPE(p2type(filetype),
							    PCCTM_PTR),
E 31
D 28
						    lwidth(filetype),
E 28
I 28
						    (int) lwidth(filetype),
E 28
						    align(filetype));
E 25
					    putdot( filename , line );
					    break;
				}
				/*
				 * put(file)
				 */
D 31
				putleaf( P2ICON , 0 , 0
				    , ADDTYPE( P2FTN | P2INT , P2PTR )
E 31
I 31
				putleaf( PCC_ICON , 0 , 0
				    , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 31
				    , "_PUT" );
D 7
				putRV( 0 , cbn , CURFILEOFFSET
					, P2PTR|P2STRTY );
E 7
I 7
D 28
				putRV( 0 , cbn , CURFILEOFFSET , NLOCAL ,
E 28
I 28
				putRV((char *) 0 , cbn , CURFILEOFFSET , NLOCAL ,
E 28
D 31
					P2PTR|P2STRTY );
E 7
				putop( P2CALL , P2INT );
E 31
I 31
					PCCTM_PTR|PCCT_STRTY );
				putop( PCC_CALL , PCCT_INT );
E 31
				putdot( filename , line );
				continue;
			}
			/*
			 * Write to a textfile
			 *
			 * Evaluate the expression
			 * to be written.
			 */
			if (fmt == 'O' || fmt == 'X') {
				if (opt('s')) {
					standard();
					error("Oct and hex are non-standard");
				}
				if (typ == TSTR || typ == TDOUBLE) {
					error("Can't write %ss with oct/hex", clnames[typ]);
					continue;
				}
				if (typ == TCHAR || typ == TBOOL)
					typ = TINT;
			}
			/*
			 * If there is no format specified by the programmer,
			 * implement the default.
			 */
			switch (typ) {
I 9
			case TPTR:
				warning();
				if (opt('s')) {
					standard();
				}
				error("Writing %ss to text files is non-standard",
				    clnames[typ]);
				/* and fall through */
E 9
			case TINT:
				if (fmt == 'f') {
					typ = TDOUBLE;
					goto tdouble;
				}
				if (fmtspec == NIL) {
					if (fmt == 'D')
						field = 10;
					else if (fmt == 'X')
						field = 8;
					else if (fmt == 'O')
						field = 11;
					else
						panic("fmt1");
					fmtspec = CONWIDTH;
				}
				break;
			case TCHAR:
			     tchar:
				fmt = 'c';
				break;
			case TSCAL:
I 4
				warning();
E 4
				if (opt('s')) {
					standard();
D 4
					error("Writing scalars to text files is non-standard");
E 4
				}
I 4
D 9
				error("Writing scalars to text files is non-standard");
E 9
I 9
				error("Writing %ss to text files is non-standard",
				    clnames[typ]);
E 9
E 4
			case TBOOL:
				fmt = 's';
				break;
			case TDOUBLE:
			     tdouble:
				switch (fmtspec) {
				case NIL:
D 26
					field = 21;
					prec = 14;
E 26
I 26
					field = 14 + (5 + EXPOSIZE);
				        prec = field - (5 + EXPOSIZE);
E 26
D 6
					fmt = 'E';
E 6
I 6
					fmt = 'e';
E 6
					fmtspec = CONWIDTH + CONPREC;
					break;
				case CONWIDTH:
D 15
					if (--field < 1)
E 15
I 15
					field -= REALSPC;
					if (field < 1)
E 15
						field = 1;
D 26
					prec = field - 7;
E 26
I 26
				        prec = field - (5 + EXPOSIZE);
E 26
					if (prec < 1)
						prec = 1;
					fmtspec += CONPREC;
D 6
					fmt = 'E';
E 6
I 6
					fmt = 'e';
E 6
					break;
				case VARWIDTH:
					fmtspec += VARPREC;
D 6
					fmt = 'E';
E 6
I 6
					fmt = 'e';
E 6
					break;
				case CONWIDTH + CONPREC:
				case CONWIDTH + VARPREC:
D 15
					if (--field < 1)
E 15
I 15
					field -= REALSPC;
					if (field < 1)
E 15
						field = 1;
				}
				format[0] = ' ';
D 13
				fmtstart = 0;
E 13
I 13
D 15
				fmtstart = 1;
E 15
I 15
				fmtstart = 1 - REALSPC;
E 15
E 13
				break;
			case TSTR:
D 28
				constval( alv );
E 28
I 28
				(void) constval( alv );
E 28
				switch ( classify( con.ctype ) ) {
				    case TCHAR:
					typ = TCHAR;
					goto tchar;
				    case TSTR:
					strptr = con.cpval;
					for (strnglen = 0;  *strptr++;  strnglen++) /* void */;
					strptr = con.cpval;
					break;
				    default:
					strnglen = width(ap);
					break;
				}
				fmt = 's';
				strfmt = fmtspec;
				if (fmtspec == NIL) {
					fmtspec = SKIP;
					break;
				}
				if (fmtspec & CONWIDTH) {
					if (field <= strnglen)
						fmtspec = SKIP;
					else
						field -= strnglen;
				}
				break;
			default:
				error("Can't write %ss to a text file", clnames[typ]);
				continue;
			}
			/*
			 * Generate the format string
			 */
			switch (fmtspec) {
			default:
				panic("fmt2");
			case NIL:
				if (fmt == 'c') {
					if ( opt( 't' ) ) {
D 31
					    putleaf( P2ICON , 0 , 0
						, ADDTYPE( P2FTN|P2INT , P2PTR )
E 31
I 31
					    putleaf( PCC_ICON , 0 , 0
						, PCCM_ADDTYPE( PCCTM_FTN|PCCT_INT , PCCTM_PTR )
E 31
						, "_WRITEC" );
D 7
					    putRV( 0 , cbn , CURFILEOFFSET
						    , P2PTR|P2STRTY );
E 7
I 7
D 28
					    putRV( 0 , cbn , CURFILEOFFSET ,
E 28
I 28
					    putRV((char *) 0 , cbn , CURFILEOFFSET ,
E 28
D 31
						    NLOCAL , P2PTR|P2STRTY );
E 31
I 31
						    NLOCAL , PCCTM_PTR|PCCT_STRTY );
E 31
E 7
D 28
					    stkrval( alv , NIL , RREQ );
E 28
I 28
					    (void) stkrval( alv , NLNIL , (long) RREQ );
E 28
D 31
					    putop( P2LISTOP , P2INT );
E 31
I 31
					    putop( PCC_CM , PCCT_INT );
E 31
					} else {
D 31
					    putleaf( P2ICON , 0 , 0
						, ADDTYPE( P2FTN|P2INT , P2PTR )
E 31
I 31
					    putleaf( PCC_ICON , 0 , 0
						, PCCM_ADDTYPE( PCCTM_FTN|PCCT_INT , PCCTM_PTR )
E 31
						, "_fputc" );
D 28
					    stkrval( alv , NIL , RREQ );
E 28
I 28
					    (void) stkrval( alv , NLNIL ,
							(long) RREQ );
E 28
					}
D 31
					putleaf( P2ICON , 0 , 0
					    , ADDTYPE( P2FTN | P2INT , P2PTR )
E 31
I 31
					putleaf( PCC_ICON , 0 , 0
					    , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 31
					    , "_ACTFILE" );
D 7
					putRV( 0, cbn , CURFILEOFFSET
						, P2PTR|P2STRTY );
E 7
I 7
D 28
					putRV( 0, cbn , CURFILEOFFSET ,
E 28
I 28
					putRV((char *) 0, cbn , CURFILEOFFSET ,
E 28
D 31
						NLOCAL , P2PTR|P2STRTY );
E 7
					putop( P2CALL , P2INT );
					putop( P2LISTOP , P2INT );
					putop( P2CALL , P2INT );
E 31
I 31
						NLOCAL , PCCTM_PTR|PCCT_STRTY );
					putop( PCC_CALL , PCCT_INT );
					putop( PCC_CM , PCCT_INT );
					putop( PCC_CALL , PCCT_INT );
E 31
					putdot( filename , line );
				} else  {
					sprintf(&format[1], "%%%c", fmt);
					goto fmtgen;
				}
			case SKIP:
				break;
			case CONWIDTH:
				sprintf(&format[1], "%%%1D%c", field, fmt);
				goto fmtgen;
			case VARWIDTH:
				sprintf(&format[1], "%%*%c", fmt);
				goto fmtgen;
			case CONWIDTH + CONPREC:
				sprintf(&format[1], "%%%1D.%1D%c", field, prec, fmt);
				goto fmtgen;
			case CONWIDTH + VARPREC:
				sprintf(&format[1], "%%%1D.*%c", field, fmt);
				goto fmtgen;
			case VARWIDTH + CONPREC:
				sprintf(&format[1], "%%*.%1D%c", prec, fmt);
				goto fmtgen;
			case VARWIDTH + VARPREC:
				sprintf(&format[1], "%%*.*%c", fmt);
			fmtgen:
				if ( opt( 't' ) ) {
D 31
				    putleaf( P2ICON , 0 , 0
					, ADDTYPE( P2FTN | P2INT , P2PTR )
E 31
I 31
				    putleaf( PCC_ICON , 0 , 0
					, PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 31
					, "_WRITEF" );
D 7
				    putRV( 0 , cbn , CURFILEOFFSET
					    , P2PTR|P2STRTY );
E 7
I 7
D 28
				    putRV( 0 , cbn , CURFILEOFFSET ,
E 28
I 28
				    putRV((char *) 0 , cbn , CURFILEOFFSET ,
E 28
D 31
					    NLOCAL , P2PTR|P2STRTY );
E 7
				    putleaf( P2ICON , 0 , 0
					, ADDTYPE( P2FTN | P2INT , P2PTR )
E 31
I 31
					    NLOCAL , PCCTM_PTR|PCCT_STRTY );
				    putleaf( PCC_ICON , 0 , 0
					, PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 31
					, "_ACTFILE" );
D 7
				    putRV( 0 , cbn , CURFILEOFFSET
					    , P2PTR|P2STRTY );
E 7
I 7
D 28
				    putRV( 0 , cbn , CURFILEOFFSET ,
E 28
I 28
				    putRV((char *) 0 , cbn , CURFILEOFFSET ,
E 28
D 31
					    NLOCAL , P2PTR|P2STRTY );
E 7
				    putop( P2CALL , P2INT );
				    putop( P2LISTOP , P2INT );
E 31
I 31
					    NLOCAL , PCCTM_PTR|PCCT_STRTY );
				    putop( PCC_CALL , PCCT_INT );
				    putop( PCC_CM , PCCT_INT );
E 31
				} else {
D 31
				    putleaf( P2ICON , 0 , 0
					, ADDTYPE( P2FTN | P2INT , P2PTR )
E 31
I 31
				    putleaf( PCC_ICON , 0 , 0
					, PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 31
					, "_fprintf" );
D 31
				    putleaf( P2ICON , 0 , 0
					, ADDTYPE( P2FTN | P2INT , P2PTR )
E 31
I 31
				    putleaf( PCC_ICON , 0 , 0
					, PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 31
					, "_ACTFILE" );
D 7
				    putRV( 0 , cbn , CURFILEOFFSET
					    , P2PTR|P2STRTY );
E 7
I 7
D 28
				    putRV( 0 , cbn , CURFILEOFFSET ,
E 28
I 28
				    putRV((char *) 0 , cbn , CURFILEOFFSET ,
E 28
D 31
					    NLOCAL , P2PTR|P2STRTY );
E 7
				    putop( P2CALL , P2INT );
E 31
I 31
					    NLOCAL , PCCTM_PTR|PCCT_STRTY );
				    putop( PCC_CALL , PCCT_INT );
E 31
				}
				putCONG( &format[ fmtstart ]
					, strlen( &format[ fmtstart ] )
					, LREQ );
D 31
				putop( P2LISTOP , P2INT );
E 31
I 31
				putop( PCC_CM , PCCT_INT );
E 31
				if ( fmtspec & VARWIDTH ) {
					/*
					 * either
					 *	,(temp=width,MAX(temp,...)),
					 * or
					 *	, MAX( width , ... ) ,
					 */
D 28
				    if ( ( typ == TDOUBLE && al[3] == NIL )
E 28
I 28
				    if ( ( typ == TDOUBLE &&
						al->wexpr_node.expr3 == TR_NIL )
E 28
					|| typ == TSTR ) {
I 27
					soffset_flag = TRUE;
E 27
D 6
					sizes[ cbn ].om_off -= sizeof( int );
					tempoff = sizes[ cbn ].om_off;
					putlbracket( ftnno , -tempoff );
					if ( tempoff < sizes[ cbn ].om_max ) {
					    sizes[ cbn ].om_max = tempoff;
					}
E 6
I 6
					soffset = sizes[cbn].curtmps;
D 7
					tempoff = tmpalloc(sizeof(long),
E 7
I 7
D 28
					tempnlp = tmpalloc(sizeof(long),
E 28
I 28
					tempnlp = tmpalloc((long) (sizeof(long)),
E 28
E 7
						nl+T4INT, REGOK);
E 6
D 7
					putRV( 0 , cbn , tempoff , P2INT );
E 7
I 7
D 28
					putRV( 0 , cbn ,
E 28
I 28
					putRV((char *) 0 , cbn ,
E 28
					    tempnlp -> value[ NL_OFFS ] ,
D 31
					    tempnlp -> extra_flags , P2INT );
E 31
I 31
					    tempnlp -> extra_flags , PCCT_INT );
E 31
E 7
D 28
					ap = stkrval( al[2] , NIL , RREQ );
E 28
I 28
					ap = stkrval( al->wexpr_node.expr2 ,
						NLNIL , (long) RREQ );
E 28
D 31
					putop( P2ASSIGN , P2INT );
					putleaf( P2ICON , 0 , 0
					    , ADDTYPE( P2FTN | P2INT , P2PTR )
E 31
I 31
					putop( PCC_ASSIGN , PCCT_INT );
					putleaf( PCC_ICON , 0 , 0
					    , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 31
					    , "_MAX" );
D 7
					putRV( 0 , cbn , tempoff , P2INT );
E 7
I 7
D 28
					putRV( 0 , cbn ,
E 28
I 28
					putRV((char *) 0 , cbn ,
E 28
					    tempnlp -> value[ NL_OFFS ] ,
D 31
					    tempnlp -> extra_flags , P2INT );
E 31
I 31
					    tempnlp -> extra_flags , PCCT_INT );
E 31
E 7
				    } else {
					if (opt('t')
					    || typ == TSTR || typ == TDOUBLE) {
D 31
					    putleaf( P2ICON , 0 , 0
						,ADDTYPE( P2FTN | P2INT, P2PTR )
E 31
I 31
					    putleaf( PCC_ICON , 0 , 0
						,PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT, PCCTM_PTR )
E 31
						,"_MAX" );
					}
D 28
					ap = stkrval( al[2] , NIL , RREQ );
E 28
I 28
					ap = stkrval( al->wexpr_node.expr2,
						NLNIL , (long) RREQ );
E 28
				    }
D 28
				    if (ap == NIL)
E 28
I 28
				    if (ap == NLNIL)
E 28
					    continue;
				    if (isnta(ap,"i")) {
					    error("First write width must be integer, not %s", nameof(ap));
					    continue;
				    }
				    switch ( typ ) {
				    case TDOUBLE:
D 15
					putleaf( P2ICON , 1 , 0 , P2INT , 0 );
E 15
I 15
D 28
					putleaf( P2ICON , REALSPC , 0 , P2INT , 0 );
E 28
I 28
D 31
					putleaf( P2ICON , REALSPC , 0 , P2INT , (char *) 0 );
E 28
E 15
					putop( P2LISTOP , P2INT );
D 28
					putleaf( P2ICON , 1 , 0 , P2INT , 0 );
E 28
I 28
					putleaf( P2ICON , 1 , 0 , P2INT , (char *) 0 );
E 28
					putop( P2LISTOP , P2INT );
					putop( P2CALL , P2INT );
E 31
I 31
					putleaf( PCC_ICON , REALSPC , 0 , PCCT_INT , (char *) 0 );
					putop( PCC_CM , PCCT_INT );
					putleaf( PCC_ICON , 1 , 0 , PCCT_INT , (char *) 0 );
					putop( PCC_CM , PCCT_INT );
					putop( PCC_CALL , PCCT_INT );
E 31
D 28
					if ( al[3] == NIL ) {
E 28
I 28
					if ( al->wexpr_node.expr3 == TR_NIL ) {
E 28
						/*
						 * finish up the comma op
						 */
D 31
					    putop( P2COMOP , P2INT );
E 31
I 31
					    putop( PCC_COMOP , PCCT_INT );
E 31
					    fmtspec &= ~VARPREC;
D 31
					    putop( P2LISTOP , P2INT );
					    putleaf( P2ICON , 0 , 0
						, ADDTYPE( P2FTN | P2INT , P2PTR )
E 31
I 31
					    putop( PCC_CM , PCCT_INT );
					    putleaf( PCC_ICON , 0 , 0
						, PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 31
						, "_MAX" );
D 7
					    putRV( 0 , cbn , tempoff , P2INT );
E 7
I 7
D 28
					    putRV( 0 , cbn ,
E 28
I 28
					    putRV((char *) 0 , cbn ,
E 28
						tempnlp -> value[ NL_OFFS ] ,
						tempnlp -> extra_flags ,
D 31
						P2INT );
E 7
D 6
					    sizes[ cbn ].om_off += sizeof( int );
E 6
I 6
D 27
					    tmpfree(&soffset);
E 27
E 6
D 15
					    putleaf( P2ICON , 8 , 0 , P2INT , 0 );
E 15
I 15
D 26
					    putleaf( P2ICON , 7 + REALSPC , 0 , P2INT , 0 );
E 26
I 26
					    putleaf( P2ICON ,
E 31
I 31
						PCCT_INT );
					    putleaf( PCC_ICON ,
E 31
						5 + EXPOSIZE + REALSPC ,
D 28
						0 , P2INT , 0 );
E 28
I 28
D 31
						0 , P2INT , (char *) 0 );
E 28
E 26
E 15
					    putop( P2LISTOP , P2INT );
D 28
					    putleaf( P2ICON , 1 , 0 , P2INT , 0 );
E 28
I 28
					    putleaf( P2ICON , 1 , 0 , P2INT , (char *) 0 );
E 28
					    putop( P2LISTOP , P2INT );
					    putop( P2CALL , P2INT );
E 31
I 31
						0 , PCCT_INT , (char *) 0 );
					    putop( PCC_CM , PCCT_INT );
					    putleaf( PCC_ICON , 1 , 0 , PCCT_INT , (char *) 0 );
					    putop( PCC_CM , PCCT_INT );
					    putop( PCC_CALL , PCCT_INT );
E 31
					}
D 31
					putop( P2LISTOP , P2INT );
E 31
I 31
					putop( PCC_CM , PCCT_INT );
E 31
					break;
				    case TSTR:
D 28
					putleaf( P2ICON , strnglen , 0 , P2INT , 0 );
E 28
I 28
D 31
					putleaf( P2ICON , strnglen , 0 , P2INT , (char *) 0 );
E 28
					putop( P2LISTOP , P2INT );
D 28
					putleaf( P2ICON , 0 , 0 , P2INT , 0 );
E 28
I 28
					putleaf( P2ICON , 0 , 0 , P2INT , (char *) 0 );
E 28
					putop( P2LISTOP , P2INT );
					putop( P2CALL , P2INT );
					putop( P2COMOP , P2INT );
					putop( P2LISTOP , P2INT );
E 31
I 31
					putleaf( PCC_ICON , strnglen , 0 , PCCT_INT , (char *) 0 );
					putop( PCC_CM , PCCT_INT );
					putleaf( PCC_ICON , 0 , 0 , PCCT_INT , (char *) 0 );
					putop( PCC_CM , PCCT_INT );
					putop( PCC_CALL , PCCT_INT );
					putop( PCC_COMOP , PCCT_INT );
					putop( PCC_CM , PCCT_INT );
E 31
					break;
				    default:
					if (opt('t')) {
D 28
					    putleaf( P2ICON , 0 , 0 , P2INT , 0 );
E 28
I 28
D 31
					    putleaf( P2ICON , 0 , 0 , P2INT , (char *) 0 );
E 28
					    putop( P2LISTOP , P2INT );
D 28
					    putleaf( P2ICON , 0 , 0 , P2INT , 0 );
E 28
I 28
					    putleaf( P2ICON , 0 , 0 , P2INT , (char *) 0 );
E 28
					    putop( P2LISTOP , P2INT );
					    putop( P2CALL , P2INT );
E 31
I 31
					    putleaf( PCC_ICON , 0 , 0 , PCCT_INT , (char *) 0 );
					    putop( PCC_CM , PCCT_INT );
					    putleaf( PCC_ICON , 0 , 0 , PCCT_INT , (char *) 0 );
					    putop( PCC_CM , PCCT_INT );
					    putop( PCC_CALL , PCCT_INT );
E 31
					}
D 31
					putop( P2LISTOP , P2INT );
E 31
I 31
					putop( PCC_CM , PCCT_INT );
E 31
					break;
				    }
				}
				/*
				 * If there is a variable precision,
				 * evaluate it 
				 */
				if (fmtspec & VARPREC) {
					if (opt('t')) {
D 31
					putleaf( P2ICON , 0 , 0
					    , ADDTYPE( P2FTN | P2INT , P2PTR )
E 31
I 31
					putleaf( PCC_ICON , 0 , 0
					    , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 31
					    , "_MAX" );
					}
D 28
					ap = stkrval( al[3] , NIL , RREQ );
E 28
I 28
					ap = stkrval( al->wexpr_node.expr3 ,
						NLNIL , (long) RREQ );
E 28
					if (ap == NIL)
						continue;
					if (isnta(ap,"i")) {
						error("Second write width must be integer, not %s", nameof(ap));
						continue;
					}
					if (opt('t')) {
D 28
					    putleaf( P2ICON , 0 , 0 , P2INT , 0 );
E 28
I 28
D 31
					    putleaf( P2ICON , 0 , 0 , P2INT , (char *) 0 );
E 28
					    putop( P2LISTOP , P2INT );
D 28
					    putleaf( P2ICON , 0 , 0 , P2INT , 0 );
E 28
I 28
					    putleaf( P2ICON , 0 , 0 , P2INT , (char *) 0 );
E 28
					    putop( P2LISTOP , P2INT );
					    putop( P2CALL , P2INT );
E 31
I 31
					    putleaf( PCC_ICON , 0 , 0 , PCCT_INT , (char *) 0 );
					    putop( PCC_CM , PCCT_INT );
					    putleaf( PCC_ICON , 0 , 0 , PCCT_INT , (char *) 0 );
					    putop( PCC_CM , PCCT_INT );
					    putop( PCC_CALL , PCCT_INT );
E 31
					}
D 31
				 	putop( P2LISTOP , P2INT );
E 31
I 31
				 	putop( PCC_CM , PCCT_INT );
E 31
				}
				/*
				 * evaluate the thing we want printed.
				 */
				switch ( typ ) {
I 9
				case TPTR:
E 9
				case TCHAR:
				case TINT:
D 28
				    stkrval( alv , NIL , RREQ );
E 28
I 28
				    (void) stkrval( alv , NLNIL , (long) RREQ );
E 28
D 31
				    putop( P2LISTOP , P2INT );
E 31
I 31
				    putop( PCC_CM , PCCT_INT );
E 31
				    break;
				case TDOUBLE:
D 28
				    ap = stkrval( alv , NIL , RREQ );
E 28
I 28
				    ap = stkrval( alv , NLNIL , (long) RREQ );
E 28
D 18
				    if ( isnta( ap , "d" ) ) {
					putop( P2SCONV , P2DOUBLE );
E 18
I 18
				    if (isnta(ap, "d")) {
D 31
					sconv(p2type(ap), P2DOUBLE);
E 31
I 31
					sconv(p2type(ap), PCCT_DOUBLE);
E 31
E 18
				    }
D 31
				    putop( P2LISTOP , P2INT );
E 31
I 31
				    putop( PCC_CM , PCCT_INT );
E 31
				    break;
				case TSCAL:
				case TBOOL:
D 31
				    putleaf( P2ICON , 0 , 0
					, ADDTYPE( P2FTN | P2INT , P2PTR )
E 31
I 31
				    putleaf( PCC_ICON , 0 , 0
					, PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 31
					, "_NAM" );
D 28
				    ap = stkrval( alv , NIL , RREQ );
E 28
I 28
				    ap = stkrval( alv , NLNIL , (long) RREQ );
E 28
				    sprintf( format , PREFIXFORMAT , LABELPREFIX
					    , listnames( ap ) );
D 28
				    putleaf( P2ICON , 0 , 0 , P2PTR | P2CHAR
					    , format );
E 28
I 28
D 31
				    putleaf( P2ICON , 0 , 0 ,
					(int) (P2PTR | P2CHAR), format );
E 28
				    putop( P2LISTOP , P2INT );
				    putop( P2CALL , P2INT );
				    putop( P2LISTOP , P2INT );
E 31
I 31
				    putleaf( PCC_ICON , 0 , 0 ,
					(int) (PCCTM_PTR | PCCT_CHAR), format );
				    putop( PCC_CM , PCCT_INT );
				    putop( PCC_CALL , PCCT_INT );
				    putop( PCC_CM , PCCT_INT );
E 31
				    break;
				case TSTR:
				    putCONG( "" , 0 , LREQ );
D 31
				    putop( P2LISTOP , P2INT );
E 31
I 31
				    putop( PCC_CM , PCCT_INT );
E 31
I 9
				    break;
				default:
				    panic("fmt3");
E 9
				    break;
				}
D 31
				putop( P2CALL , P2INT );
E 31
I 31
				putop( PCC_CALL , PCCT_INT );
E 31
				putdot( filename , line );
			}
			/*
			 * Write the string after its blank padding
			 */
			if (typ == TSTR ) {
				if ( opt( 't' ) ) {
D 31
				    putleaf( P2ICON , 0 , 0
					, ADDTYPE( P2FTN | P2INT , P2PTR )
E 31
I 31
				    putleaf( PCC_ICON , 0 , 0
					, PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 31
					, "_WRITES" );
D 7
				    putRV( 0 , cbn , CURFILEOFFSET
					    , P2PTR|P2STRTY );
E 7
I 7
D 28
				    putRV( 0 , cbn , CURFILEOFFSET ,
E 28
I 28
				    putRV((char *) 0 , cbn , CURFILEOFFSET ,
E 28
D 31
					    NLOCAL , P2PTR|P2STRTY );
E 31
I 31
					    NLOCAL , PCCTM_PTR|PCCT_STRTY );
E 31
E 7
D 28
				    ap = stkrval(alv, NIL , RREQ );
E 28
I 28
				    ap = stkrval(alv, NLNIL , (long) RREQ );
E 28
D 31
				    putop( P2LISTOP , P2INT );
E 31
I 31
				    putop( PCC_CM , PCCT_INT );
E 31
				} else {
D 31
				    putleaf( P2ICON , 0 , 0
					, ADDTYPE( P2FTN | P2INT , P2PTR )
E 31
I 31
				    putleaf( PCC_ICON , 0 , 0
					, PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 31
					, "_fwrite" );
D 28
				    ap = stkrval(alv, NIL , RREQ );
E 28
I 28
				    ap = stkrval(alv, NLNIL , (long) RREQ );
E 28
				}
				if (strfmt & VARWIDTH) {
					    /*
					     *	min, inline expanded as
					     *	temp < len ? temp : len
					     */
D 7
					putRV( 0 , cbn , tempoff , P2INT );
E 7
I 7
D 28
					putRV( 0 , cbn ,
E 28
I 28
					putRV((char *) 0 , cbn ,
E 28
					    tempnlp -> value[ NL_OFFS ] ,
D 31
					    tempnlp -> extra_flags , P2INT );
E 7
D 28
					putleaf( P2ICON , strnglen , 0 , P2INT , 0 );
E 28
I 28
					putleaf( P2ICON , strnglen , 0 , P2INT , (char *) 0 );
E 28
					putop( P2LT , P2INT );
E 31
I 31
					    tempnlp -> extra_flags , PCCT_INT );
					putleaf( PCC_ICON , strnglen , 0 , PCCT_INT , (char *) 0 );
					putop( PCC_LT , PCCT_INT );
E 31
D 7
					putRV( 0 , cbn , tempoff , P2INT );
E 7
I 7
D 28
					putRV( 0 , cbn ,
E 28
I 28
					putRV((char *) 0 , cbn ,
E 28
					    tempnlp -> value[ NL_OFFS ] ,
D 31
					    tempnlp -> extra_flags , P2INT );
E 7
D 28
					putleaf( P2ICON , strnglen , 0 , P2INT , 0 );
E 28
I 28
					putleaf( P2ICON , strnglen , 0 , P2INT , (char *) 0 );
E 28
					putop( P2COLON , P2INT );
					putop( P2QUEST , P2INT );
E 31
I 31
					    tempnlp -> extra_flags , PCCT_INT );
					putleaf( PCC_ICON , strnglen , 0 , PCCT_INT , (char *) 0 );
					putop( PCC_COLON , PCCT_INT );
					putop( PCC_QUEST , PCCT_INT );
E 31
I 6
D 27
					tmpfree(&soffset);
E 27
E 6
				} else {
					if (   ( fmtspec & SKIP )
					    && ( strfmt & CONWIDTH ) ) {
						strnglen = field;
					}
D 28
					putleaf( P2ICON , strnglen , 0 , P2INT , 0 );
E 28
I 28
D 31
					putleaf( P2ICON , strnglen , 0 , P2INT , (char *) 0 );
E 31
I 31
					putleaf( PCC_ICON , strnglen , 0 , PCCT_INT , (char *) 0 );
E 31
E 28
				}
D 31
				putop( P2LISTOP , P2INT );
D 28
				putleaf( P2ICON , 1 , 0 , P2INT , 0 );
E 28
I 28
				putleaf( P2ICON , 1 , 0 , P2INT , (char *) 0 );
E 28
				putop( P2LISTOP , P2INT );
				putleaf( P2ICON , 0 , 0
				    , ADDTYPE( P2FTN | P2INT , P2PTR )
E 31
I 31
				putop( PCC_CM , PCCT_INT );
				putleaf( PCC_ICON , 1 , 0 , PCCT_INT , (char *) 0 );
				putop( PCC_CM , PCCT_INT );
				putleaf( PCC_ICON , 0 , 0
				    , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 31
				    , "_ACTFILE" );
D 7
				putRV( 0, cbn , CURFILEOFFSET , P2PTR|P2STRTY );
E 7
I 7
D 28
				putRV( 0, cbn , CURFILEOFFSET , NLOCAL ,
E 28
I 28
				putRV((char *) 0, cbn , CURFILEOFFSET , NLOCAL ,
E 28
D 31
					P2PTR|P2STRTY );
E 7
				putop( P2CALL , P2INT );
				putop( P2LISTOP , P2INT );
				putop( P2CALL , P2INT );
E 31
I 31
					PCCTM_PTR|PCCT_STRTY );
				putop( PCC_CALL , PCCT_INT );
				putop( PCC_CM , PCCT_INT );
				putop( PCC_CALL , PCCT_INT );
E 31
				putdot( filename , line );
I 27
			}
			if (soffset_flag) {
				tmpfree(&soffset);
				soffset_flag = FALSE;
E 27
			}
		}
		/*
		 * Done with arguments.
		 * Handle writeln and
		 * insufficent number of args.
		 */
		switch (p->value[0] &~ NSTAND) {
			case O_WRITEF:
				if (argc == 0)
					error("Write requires an argument");
				break;
			case O_MESSAGE:
				if (argc == 0)
					error("Message requires an argument");
			case O_WRITLN:
				if (filetype != nl+T1CHAR)
					error("Can't 'writeln' a non text file");
				if ( opt( 't' ) ) {
D 31
				    putleaf( P2ICON , 0 , 0
					, ADDTYPE( P2FTN | P2INT , P2PTR )
E 31
I 31
				    putleaf( PCC_ICON , 0 , 0
					, PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 31
					, "_WRITLN" );
D 7
				    putRV( 0 , cbn , CURFILEOFFSET
					    , P2PTR|P2STRTY );
E 7
I 7
D 28
				    putRV( 0 , cbn , CURFILEOFFSET ,
E 28
I 28
				    putRV((char *) 0 , cbn , CURFILEOFFSET ,
E 28
D 31
					    NLOCAL , P2PTR|P2STRTY );
E 31
I 31
					    NLOCAL , PCCTM_PTR|PCCT_STRTY );
E 31
E 7
				} else {
D 31
				    putleaf( P2ICON , 0 , 0
					, ADDTYPE( P2FTN | P2INT , P2PTR )
E 31
I 31
				    putleaf( PCC_ICON , 0 , 0
					, PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 31
					, "_fputc" );
D 28
				    putleaf( P2ICON , '\n' , 0 , P2CHAR , 0 );
E 28
I 28
D 31
				    putleaf( P2ICON , '\n' , 0 , (int) P2CHAR , (char *) 0 );
E 28
				    putleaf( P2ICON , 0 , 0
					, ADDTYPE( P2FTN | P2INT , P2PTR )
E 31
I 31
				    putleaf( PCC_ICON , '\n' , 0 , (int) PCCT_CHAR , (char *) 0 );
				    putleaf( PCC_ICON , 0 , 0
					, PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 31
					, "_ACTFILE" );
D 7
				    putRV( 0 , cbn , CURFILEOFFSET
					    , P2PTR|P2STRTY );
E 7
I 7
D 28
				    putRV( 0 , cbn , CURFILEOFFSET ,
E 28
I 28
				    putRV((char *) 0 , cbn , CURFILEOFFSET ,
E 28
D 31
					    NLOCAL , P2PTR|P2STRTY );
E 7
				    putop( P2CALL , P2INT );
				    putop( P2LISTOP , P2INT );
E 31
I 31
					    NLOCAL , PCCTM_PTR|PCCT_STRTY );
				    putop( PCC_CALL , PCCT_INT );
				    putop( PCC_CM , PCCT_INT );
E 31
				}
D 31
				putop( P2CALL , P2INT );
E 31
I 31
				putop( PCC_CALL , PCCT_INT );
E 31
				putdot( filename , line );
				break;
		}
		return;

	case O_READ4:
	case O_READLN:
		/*
		 * Set up default
		 * file "input".
		 */
		file = NIL;
		filetype = nl+T1CHAR;
		/*
		 * Determine the file implied
		 * for the read and generate
		 * code to make it the active file.
		 */
D 28
		if (argv != NIL) {
E 28
I 28
		if (argv != TR_NIL) {
E 28
			codeoff();
D 28
			ap = stkrval(argv[1], NIL , RREQ );
E 28
I 28
			ap = stkrval(argv->list_node.list, NLNIL, (long) RREQ );
E 28
			codeon();
D 28
			if (ap == NIL)
				argv = argv[2];
			if (ap != NIL && ap->class == FILET) {
E 28
I 28
			if (ap == NLNIL)
				argv = argv->list_node.next;
			if (ap != NLNIL && ap->class == FILET) {
E 28
				/*
				 * Got "read(f, ...", make
				 * f the active file, and save
				 * it and its type for use in
				 * processing the rest of the
				 * arguments to read.
				 */
D 28
				file = argv[1];
E 28
I 28
				file = argv->list_node.list;
E 28
				filetype = ap->type;
D 7
				putRV( 0, cbn , CURFILEOFFSET , P2PTR|P2STRTY );
E 7
I 7
D 28
				putRV( 0, cbn , CURFILEOFFSET , NLOCAL ,
E 28
I 28
				putRV((char *) 0, cbn , CURFILEOFFSET , NLOCAL ,
E 28
D 31
					P2PTR|P2STRTY );
E 7
				putleaf( P2ICON , 0 , 0 
					, ADDTYPE( P2FTN | P2INT , P2PTR )
E 31
I 31
					PCCTM_PTR|PCCT_STRTY );
				putleaf( PCC_ICON , 0 , 0 
					, PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 31
					, "_UNIT" );
D 28
				stklval(argv[1], NOFLAGS);
E 28
I 28
				(void) stklval(argv->list_node.list, NOFLAGS);
E 28
D 31
				putop( P2CALL , P2INT );
				putop( P2ASSIGN , P2PTR|P2STRTY );
E 31
I 31
				putop( PCC_CALL , PCCT_INT );
				putop( PCC_ASSIGN , PCCTM_PTR|PCCT_STRTY );
E 31
				putdot( filename , line );
D 28
				argv = argv[2];
E 28
I 28
				argv = argv->list_node.next;
E 28
				argc--;
			} else {
				/*
				 * Default is read from
				 * standard input.
				 */
D 7
				putRV( 0, cbn , CURFILEOFFSET , P2PTR|P2STRTY );
				putLV( "_input" , 0 , 0 , P2PTR|P2STRTY );
E 7
I 7
D 28
				putRV( 0, cbn , CURFILEOFFSET , NLOCAL ,
E 28
I 28
				putRV((char *) 0, cbn , CURFILEOFFSET , NLOCAL ,
E 28
D 31
					P2PTR|P2STRTY );
E 31
I 31
					PCCTM_PTR|PCCT_STRTY );
E 31
				putLV( "_input" , 0 , 0 , NGLOBAL ,
D 31
					P2PTR|P2STRTY );
E 7
				putop( P2ASSIGN , P2PTR|P2STRTY );
E 31
I 31
					PCCTM_PTR|PCCT_STRTY );
				putop( PCC_ASSIGN , PCCTM_PTR|PCCT_STRTY );
E 31
				putdot( filename , line );
				input->nl_flags |= NUSED;
			}
		} else {
D 7
			putRV( 0, cbn , CURFILEOFFSET , P2PTR|P2STRTY );
			putLV( "_input" , 0 , 0 , P2PTR|P2STRTY );
E 7
I 7
D 28
			putRV( 0, cbn , CURFILEOFFSET , NLOCAL ,
E 28
I 28
			putRV((char *) 0, cbn , CURFILEOFFSET , NLOCAL ,
E 28
D 31
				P2PTR|P2STRTY );
			putLV( "_input" , 0 , 0 , NGLOBAL , P2PTR|P2STRTY );
E 7
			putop( P2ASSIGN , P2PTR|P2STRTY );
E 31
I 31
				PCCTM_PTR|PCCT_STRTY );
			putLV( "_input" , 0 , 0 , NGLOBAL , PCCTM_PTR|PCCT_STRTY );
			putop( PCC_ASSIGN , PCCTM_PTR|PCCT_STRTY );
E 31
			putdot( filename , line );
			input->nl_flags |= NUSED;
		}
		/*
		 * Loop and process each
		 * of the arguments.
		 */
D 28
		for (; argv != NIL; argv = argv[2]) {
E 28
I 28
		for (; argv != TR_NIL; argv = argv->list_node.next) {
E 28
			/*
			 * Get the address of the target
			 * on the stack.
			 */
D 28
			al = argv[1];
			if (al == NIL)
E 28
I 28
			al = argv->list_node.list;
			if (al == TR_NIL)
E 28
				continue;
D 28
			if (al[0] != T_VAR) {
E 28
I 28
			if (al->tag != T_VAR) {
E 28
				error("Arguments to %s must be variables, not expressions", p->symbol);
				continue;
			}
			codeoff();
			ap = stklval(al, MOD|ASGN|NOUSE);
			codeon();
D 28
			if (ap == NIL)
E 28
I 28
			if (ap == NLNIL)
E 28
				continue;
			if (filetype != nl+T1CHAR) {
				/*
				 * Generalized read, i.e.
				 * from a non-textfile.
				 */
D 28
				if (incompat(filetype, ap, argv[1] )) {
E 28
I 28
				if (incompat(filetype, ap, argv->list_node.list )) {
E 28
					error("Type mismatch in read from non-text file");
					continue;
				}
				/*
				 * var := file ^;
				 */
				ap = lvalue( al , MOD | ASGN | NOUSE , RREQ );
				if ( isa( ap , "bsci" ) ) {
					precheck( ap , "_RANG4" , "_RSNG4" );
				}
D 31
				putleaf( P2ICON , 0 , 0
D 28
				    , ADDTYPE(
E 28
I 28
				    , (int) (ADDTYPE(
E 28
					ADDTYPE(
					    ADDTYPE(
						p2type( filetype ) , P2PTR )
					    , P2FTN )
D 28
					, P2PTR )
E 28
I 28
					, P2PTR ))
E 31
I 31
				putleaf( PCC_ICON , 0 , 0
				    , (int) (PCCM_ADDTYPE(
					PCCM_ADDTYPE(
					    PCCM_ADDTYPE(
						p2type( filetype ) , PCCTM_PTR )
					    , PCCTM_FTN )
					, PCCTM_PTR ))
E 31
E 28
				    , "_FNIL" );
				if (file != NIL)
D 28
					stklval(file, NOFLAGS);
E 28
I 28
					(void) stklval(file, NOFLAGS);
E 28
				else /* Magic */
D 7
					putRV( "_input" , 0 , 0
						, P2PTR | P2STRTY );
E 7
I 7
					putRV( "_input" , 0 , 0 , NGLOBAL ,
D 31
						P2PTR | P2STRTY );
E 7
D 23
				putop( P2CALL , P2INT );
E 23
I 23
				putop(P2CALL, ADDTYPE(p2type(filetype), P2PTR));
E 31
I 31
						PCCTM_PTR | PCCT_STRTY );
				putop(PCC_CALL, PCCM_ADDTYPE(p2type(filetype), PCCTM_PTR));
E 31
E 23
				switch ( classify( filetype ) ) {
				    case TBOOL:
				    case TCHAR:
				    case TINT:
				    case TSCAL:
				    case TDOUBLE:
				    case TPTR:
D 31
					putop( P2UNARY P2MUL
E 31
I 31
					putop( PCCOM_UNARY PCC_MUL
E 31
						, p2type( filetype ) );
				}
				switch ( classify( filetype ) ) {
				    case TBOOL:
				    case TCHAR:
				    case TINT:
				    case TSCAL:
D 18
					    postcheck( ap );
E 18
I 18
					    postcheck(ap, filetype);
					    sconv(p2type(filetype), p2type(ap));
E 18
						/* and fall through */
				    case TDOUBLE:
				    case TPTR:
D 31
					    putop( P2ASSIGN , p2type( ap ) );
E 31
I 31
					    putop( PCC_ASSIGN , p2type( ap ) );
E 31
					    putdot( filename , line );
					    break;
				    default:
D 25
					    putstrop( P2STASG
							, p2type( ap )
							, lwidth( ap )
							, align( ap ) );
E 25
I 25
D 31
					    putstrop(P2STASG,
						    ADDTYPE(p2type(ap), P2PTR),
E 31
I 31
					    putstrop(PCC_STASG,
						    PCCM_ADDTYPE(p2type(ap), PCCTM_PTR),
E 31
D 28
						    lwidth(ap),
E 28
I 28
						    (int) lwidth(ap),
E 28
						    align(ap));
E 25
					    putdot( filename , line );
					    break;
				}
				/*
				 * get(file);
				 */
D 31
				putleaf( P2ICON , 0 , 0 
					, ADDTYPE( P2FTN | P2INT , P2PTR )
E 31
I 31
				putleaf( PCC_ICON , 0 , 0 
					, PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 31
					, "_GET" );
D 7
				putRV( 0 , cbn , CURFILEOFFSET 
					, P2PTR|P2STRTY );
E 7
I 7
D 28
				putRV( 0 , cbn , CURFILEOFFSET , NLOCAL ,
E 28
I 28
				putRV((char *) 0 , cbn , CURFILEOFFSET , NLOCAL ,
E 28
D 31
					P2PTR|P2STRTY );
E 7
				putop( P2CALL , P2INT );
E 31
I 31
					PCCTM_PTR|PCCT_STRTY );
				putop( PCC_CALL , PCCT_INT );
E 31
				putdot( filename , line );
				continue;
			}
			    /*
			     *	if you get to here, you are reading from
			     *	a text file.  only possiblities are:
			     *	character, integer, real, or scalar.
			     *	read( f , foo , ... ) is done as
			     *	foo := read( f ) with rangechecking
			     *	if appropriate.
			     */
			typ = classify(ap);
			op = rdops(typ);
			if (op == NIL) {
				error("Can't read %ss from a text file", clnames[typ]);
				continue;
			}
			    /*
			     *	left hand side of foo := read( f )
			     */
			ap = lvalue( al , MOD|ASGN|NOUSE , RREQ );
			if ( isa( ap , "bsci" ) ) {
			    precheck( ap , "_RANG4" , "_RSNG4" );
			}
			switch ( op ) {
			    case O_READC:
				readname = "_READC";
D 31
				readtype = P2INT;
E 31
I 31
				readtype = PCCT_INT;
E 31
				break;
			    case O_READ4:
				readname = "_READ4";
D 31
				readtype = P2INT;
E 31
I 31
				readtype = PCCT_INT;
E 31
				break;
			    case O_READ8:
				readname = "_READ8";
D 31
				readtype = P2DOUBLE;
E 31
I 31
				readtype = PCCT_DOUBLE;
E 31
				break;
			    case O_READE:
				readname = "_READE";
D 31
				readtype = P2INT;
E 31
I 31
				readtype = PCCT_INT;
E 31
				break;
			}
D 31
			putleaf( P2ICON , 0 , 0
D 28
				, ADDTYPE( P2FTN | readtype , P2PTR )
E 28
I 28
				, (int) ADDTYPE( P2FTN | readtype , P2PTR )
E 31
I 31
			putleaf( PCC_ICON , 0 , 0
				, (int) PCCM_ADDTYPE( PCCTM_FTN | readtype , PCCTM_PTR )
E 31
E 28
				, readname );
D 7
			putRV( 0 , cbn , CURFILEOFFSET , P2PTR|P2STRTY );
E 7
I 7
D 28
			putRV( 0 , cbn , CURFILEOFFSET , NLOCAL ,
E 28
I 28
			putRV((char *) 0 , cbn , CURFILEOFFSET , NLOCAL ,
E 28
D 31
				P2PTR|P2STRTY );
E 31
I 31
				PCCTM_PTR|PCCT_STRTY );
E 31
E 7
			if ( op == O_READE ) {
				sprintf( format , PREFIXFORMAT , LABELPREFIX
					, listnames( ap ) );
D 28
				putleaf( P2ICON , 0 , 0 , P2PTR | P2CHAR
					, format );
E 28
I 28
D 31
				putleaf( P2ICON , 0, 0, (int) (P2PTR | P2CHAR),
E 31
I 31
				putleaf( PCC_ICON , 0, 0, (int) (PCCTM_PTR | PCCT_CHAR),
E 31
					format );
E 28
D 31
				putop( P2LISTOP , P2INT );
E 31
I 31
				putop( PCC_CM , PCCT_INT );
E 31
I 4
				warning();
E 4
				if (opt('s')) {
					standard();
D 4
					error("Reading of enumerated types is non-standard");
E 4
				}
I 4
				error("Reading scalars from text files is non-standard");
E 4
			}
D 28
			putop( P2CALL , readtype );
E 28
I 28
D 31
			putop( P2CALL , (int) readtype );
E 31
I 31
			putop( PCC_CALL , (int) readtype );
E 31
E 28
			if ( isa( ap , "bcsi" ) ) {
D 18
			    postcheck( ap );
E 18
I 18
D 31
			    postcheck(ap, readtype==P2INT?nl+T4INT:nl+TDOUBLE);
E 31
I 31
			    postcheck(ap, readtype==PCCT_INT?nl+T4INT:nl+TDOUBLE);
E 31
E 18
			}
I 18
D 28
			sconv(readtype, p2type(ap));
E 28
I 28
			sconv((int) readtype, p2type(ap));
E 28
E 18
D 31
			putop( P2ASSIGN , p2type( ap ) );
E 31
I 31
			putop( PCC_ASSIGN , p2type( ap ) );
E 31
			putdot( filename , line );
		}
		/*
		 * Done with arguments.
		 * Handle readln and
		 * insufficient number of args.
		 */
		if (p->value[0] == O_READLN) {
			if (filetype != nl+T1CHAR)
				error("Can't 'readln' a non text file");
D 31
			putleaf( P2ICON , 0 , 0 
D 28
				, ADDTYPE( P2FTN | P2INT , P2PTR )
E 28
I 28
				, (int) ADDTYPE( P2FTN | P2INT , P2PTR )
E 31
I 31
			putleaf( PCC_ICON , 0 , 0 
				, (int) PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 31
E 28
				, "_READLN" );
D 7
			putRV( 0 , cbn , CURFILEOFFSET , P2PTR|P2STRTY );
E 7
I 7
D 28
			putRV( 0 , cbn , CURFILEOFFSET , NLOCAL ,
E 28
I 28
			putRV((char *) 0 , cbn , CURFILEOFFSET , NLOCAL ,
E 28
D 31
				P2PTR|P2STRTY );
E 7
			putop( P2CALL , P2INT );
E 31
I 31
				PCCTM_PTR|PCCT_STRTY );
			putop( PCC_CALL , PCCT_INT );
E 31
			putdot( filename , line );
		} else if (argc == 0)
			error("read requires an argument");
		return;

	case O_GET:
	case O_PUT:
		if (argc != 1) {
			error("%s expects one argument", p->symbol);
			return;
		}
D 7
		putRV( 0 , cbn , CURFILEOFFSET , P2PTR|P2STRTY );
E 7
I 7
D 28
		putRV( 0 , cbn , CURFILEOFFSET , NLOCAL , P2PTR|P2STRTY );
E 28
I 28
D 31
		putRV((char *) 0 , cbn , CURFILEOFFSET , NLOCAL , P2PTR|P2STRTY );
E 28
E 7
		putleaf( P2ICON , 0 , 0 , ADDTYPE( P2FTN | P2INT , P2PTR )
E 31
I 31
		putRV((char *) 0 , cbn , CURFILEOFFSET , NLOCAL , PCCTM_PTR|PCCT_STRTY );
		putleaf( PCC_ICON , 0 , 0 , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 31
			, "_UNIT" );
D 28
		ap = stklval(argv[1], NOFLAGS);
		if (ap == NIL)
E 28
I 28
		ap = stklval(argv->list_node.list, NOFLAGS);
		if (ap == NLNIL)
E 28
			return;
		if (ap->class != FILET) {
			error("Argument to %s must be a file, not %s", p->symbol, nameof(ap));
			return;
		}
D 31
		putop( P2CALL , P2INT );
		putop( P2ASSIGN , P2PTR|P2STRTY );
E 31
I 31
		putop( PCC_CALL , PCCT_INT );
		putop( PCC_ASSIGN , PCCTM_PTR|PCCT_STRTY );
E 31
		putdot( filename , line );
D 31
		putleaf( P2ICON , 0 , 0 , ADDTYPE( P2FTN | P2INT , P2PTR )
E 31
I 31
		putleaf( PCC_ICON , 0 , 0 , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 31
			, op == O_GET ? "_GET" : "_PUT" );
D 7
		putRV( 0 , cbn , CURFILEOFFSET , P2PTR|P2STRTY );
E 7
I 7
D 28
		putRV( 0 , cbn , CURFILEOFFSET , NLOCAL , P2PTR|P2STRTY );
E 28
I 28
D 31
		putRV((char *) 0 , cbn , CURFILEOFFSET , NLOCAL , P2PTR|P2STRTY );
E 28
E 7
		putop( P2CALL , P2INT );
E 31
I 31
		putRV((char *) 0 , cbn , CURFILEOFFSET , NLOCAL , PCCTM_PTR|PCCT_STRTY );
		putop( PCC_CALL , PCCT_INT );
E 31
		putdot( filename , line );
		return;

	case O_RESET:
	case O_REWRITE:
		if (argc == 0 || argc > 2) {
			error("%s expects one or two arguments", p->symbol);
			return;
		}
		if (opt('s') && argc == 2) {
			standard();
			error("Two argument forms of reset and rewrite are non-standard");
		}
D 31
		putleaf( P2ICON , 0 , 0 , P2INT
E 31
I 31
		putleaf( PCC_ICON , 0 , 0 , PCCT_INT
E 31
			, op == O_RESET ? "_RESET" : "_REWRITE" );
D 28
		ap = stklval(argv[1], MOD|NOUSE);
		if (ap == NIL)
E 28
I 28
		ap = stklval(argv->list_node.list, MOD|NOUSE);
		if (ap == NLNIL)
E 28
			return;
		if (ap->class != FILET) {
			error("First argument to %s must be a file, not %s", p->symbol, nameof(ap));
			return;
		}
		if (argc == 2) {
			/*
			 * Optional second argument
			 * is a string name of a
			 * UNIX (R) file to be associated.
			 */
D 28
			al = argv[2];
			al = stkrval(al[1], NOFLAGS , RREQ );
			if (al == NIL)
E 28
I 28
			al = argv->list_node.next;
			al = (struct tnode *) stkrval(al->list_node.list,
					NLNIL , (long) RREQ );
			if (al == TR_NIL)
E 28
				return;
D 28
			if (classify(al) != TSTR) {
				error("Second argument to %s must be a string, not %s", p->symbol, nameof(al));
E 28
I 28
			if (classify((struct nl *) al) != TSTR) {
				error("Second argument to %s must be a string, not %s", p->symbol, nameof((struct nl *) al));
E 28
				return;
			}
D 28
			strnglen = width(al);
E 28
I 28
			strnglen = width((struct nl *) al);
E 28
		} else {
D 28
			putleaf( P2ICON , 0 , 0 , P2INT , 0 );
E 28
I 28
D 31
			putleaf( P2ICON , 0 , 0 , P2INT , (char *) 0 );
E 31
I 31
			putleaf( PCC_ICON , 0 , 0 , PCCT_INT , (char *) 0 );
E 31
E 28
			strnglen = 0;
		}
D 31
		putop( P2LISTOP , P2INT );
D 28
		putleaf( P2ICON , strnglen , 0 , P2INT , 0 );
E 28
I 28
		putleaf( P2ICON , strnglen , 0 , P2INT , (char *) 0 );
E 28
		putop( P2LISTOP , P2INT );
D 28
		putleaf( P2ICON , text(ap) ? 0: width(ap->type) , 0 , P2INT , 0 );
E 28
I 28
		putleaf( P2ICON , text(ap) ? 0: width(ap->type) , 0 , P2INT , (char *) 0 );
E 28
		putop( P2LISTOP , P2INT );
		putop( P2CALL , P2INT );
E 31
I 31
		putop( PCC_CM , PCCT_INT );
		putleaf( PCC_ICON , strnglen , 0 , PCCT_INT , (char *) 0 );
		putop( PCC_CM , PCCT_INT );
		putleaf( PCC_ICON , text(ap) ? 0: width(ap->type) , 0 , PCCT_INT , (char *) 0 );
		putop( PCC_CM , PCCT_INT );
		putop( PCC_CALL , PCCT_INT );
E 31
		putdot( filename , line );
		return;

	case O_NEW:
	case O_DISPOSE:
		if (argc == 0) {
			error("%s expects at least one argument", p->symbol);
			return;
		}
I 14
D 28
		alv = argv[1];
E 28
I 28
		alv = argv->list_node.list;
E 28
E 14
D 12
		putleaf( P2ICON , 0 , 0 , ADDTYPE( P2FTN | P2INT , P2PTR )
			, op == O_DISPOSE ? "_DISPOSE" :
				opt('t') ? "_NEWZ" : "_NEW" );
E 12
I 12
		codeoff();
E 12
D 14
		ap = stklval(argv[1], op == O_NEW ? ( MOD | NOUSE ) : MOD );
E 14
I 14
		ap = stklval(alv, op == O_NEW ? ( MOD | NOUSE ) : MOD );
E 14
I 12
		codeon();
E 12
D 28
		if (ap == NIL)
E 28
I 28
		if (ap == NLNIL)
E 28
			return;
		if (ap->class != PTR) {
			error("(First) argument to %s must be a pointer, not %s", p->symbol, nameof(ap));
			return;
		}
		ap = ap->type;
D 28
		if (ap == NIL)
E 28
I 28
		if (ap == NLNIL)
E 28
			return;
I 12
D 14
		if (op == O_DISPOSE)
E 14
I 14
		if (op == O_NEW)
			cmd = "_NEW";
		else /* op == O_DISPOSE */
E 14
			if ((ap->nl_flags & NFILES) != 0)
				cmd = "_DFDISPOSE";
			else
				cmd = "_DISPOSE";
D 14
		else if (opt('t'))
			cmd = "_NEWZ";
		else
			cmd = "_NEW";
E 14
D 31
		putleaf( P2ICON, 0, 0, ADDTYPE( P2FTN | P2INT , P2PTR ), cmd);
E 31
I 31
		putleaf( PCC_ICON, 0, 0, PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR ), cmd);
E 31
D 14
		stklval(argv[1], op == O_NEW ? ( MOD | NOUSE ) : MOD );
E 14
I 14
D 28
		stklval(alv, op == O_NEW ? ( MOD | NOUSE ) : MOD );
E 14
E 12
		argv = argv[2];
		if (argv != NIL) {
E 28
I 28
		(void) stklval(alv, op == O_NEW ? ( MOD | NOUSE ) : MOD );
		argv = argv->list_node.next;
		if (argv != TR_NIL) {
E 28
			if (ap->class != RECORD) {
				error("Record required when specifying variant tags");
				return;
			}
D 28
			for (; argv != NIL; argv = argv[2]) {
E 28
I 28
			for (; argv != TR_NIL; argv = argv->list_node.next) {
E 28
				if (ap->ptr[NL_VARNT] == NIL) {
					error("Too many tag fields");
					return;
				}
D 28
				if (!isconst(argv[1])) {
E 28
I 28
				if (!isconst(argv->list_node.list)) {
E 28
					error("Second and successive arguments to %s must be constants", p->symbol);
					return;
				}
D 28
				gconst(argv[1]);
E 28
I 28
				gconst(argv->list_node.list);
E 28
				if (con.ctype == NIL)
					return;
D 28
				if (incompat(con.ctype, (ap->ptr[NL_TAG])->type , NIL )) {
E 28
I 28
				if (incompat(con.ctype, (ap->ptr[NL_TAG])->type , TR_NIL )) {
E 28
					cerror("Specified tag constant type clashed with variant case selector type");
					return;
				}
				for (ap = ap->ptr[NL_VARNT]; ap != NIL; ap = ap->chain)
					if (ap->range[0] == con.crval)
						break;
				if (ap == NIL) {
					error("No variant case label value equals specified constant value");
					return;
				}
				ap = ap->ptr[NL_VTOREC];
			}
		}
D 28
		putleaf( P2ICON , width( ap ) , 0 , P2INT , 0 );
E 28
I 28
D 31
		putleaf( P2ICON , width( ap ) , 0 , P2INT , (char *) 0 );
E 28
		putop( P2LISTOP , P2INT );
		putop( P2CALL , P2INT );
E 31
I 31
		putleaf( PCC_ICON , width( ap ) , 0 , PCCT_INT , (char *) 0 );
		putop( PCC_CM , PCCT_INT );
		putop( PCC_CALL , PCCT_INT );
E 31
		putdot( filename , line );
I 14
		if (opt('t') && op == O_NEW) {
D 31
		    putleaf( P2ICON , 0 , 0 , ADDTYPE( P2FTN | P2INT , P2PTR )
E 31
I 31
		    putleaf( PCC_ICON , 0 , 0 , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 31
			    , "_blkclr" );
D 17
		    stklval(alv, op == O_NEW ? ( MOD | NOUSE ) : MOD );
E 17
I 17
D 28
		    stkrval(alv, NIL , RREQ );
E 17
		    putleaf( P2ICON , width( ap ) , 0 , P2INT , 0 );
E 28
I 28
		    (void) stkrval(alv, NLNIL , (long) RREQ );
D 31
		    putleaf( P2ICON , width( ap ) , 0 , P2INT , (char *) 0 );
E 28
		    putop( P2LISTOP , P2INT );
		    putop( P2CALL , P2INT );
E 31
I 31
		    putleaf( PCC_ICON , width( ap ) , 0 , PCCT_INT , (char *) 0 );
		    putop( PCC_CM , PCCT_INT );
		    putop( PCC_CALL , PCCT_INT );
E 31
		    putdot( filename , line );
		}
E 14
		return;

	case O_DATE:
	case O_TIME:
		if (argc != 1) {
			error("%s expects one argument", p->symbol);
			return;
		}
D 31
		putleaf( P2ICON , 0 , 0 , ADDTYPE( P2FTN | P2INT , P2PTR )
E 31
I 31
		putleaf( PCC_ICON , 0 , 0 , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 31
			, op == O_DATE ? "_DATE" : "_TIME" );
D 28
		ap = stklval(argv[1], MOD|NOUSE);
E 28
I 28
		ap = stklval(argv->list_node.list, MOD|NOUSE);
E 28
		if (ap == NIL)
			return;
		if (classify(ap) != TSTR || width(ap) != 10) {
			error("Argument to %s must be a alfa, not %s", p->symbol, nameof(ap));
			return;
		}
D 31
		putop( P2CALL , P2INT );
E 31
I 31
		putop( PCC_CALL , PCCT_INT );
E 31
		putdot( filename , line );
		return;

	case O_HALT:
		if (argc != 0) {
			error("halt takes no arguments");
			return;
		}
D 31
		putleaf( P2ICON , 0 , 0 , ADDTYPE( P2FTN | P2INT , P2PTR )
E 31
I 31
		putleaf( PCC_ICON , 0 , 0 , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 31
			, "_HALT" );

D 31
		putop( P2UNARY P2CALL , P2INT );
E 31
I 31
		putop( PCCOM_UNARY PCC_CALL , PCCT_INT );
E 31
		putdot( filename , line );
D 28
		noreach = 1;
E 28
I 28
		noreach = TRUE;
E 28
		return;

	case O_ARGV:
		if (argc != 2) {
			error("argv takes two arguments");
			return;
		}
D 31
		putleaf( P2ICON , 0 , 0 , ADDTYPE( P2FTN | P2INT , P2PTR )
E 31
I 31
		putleaf( PCC_ICON , 0 , 0 , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 31
			, "_ARGV" );
D 28
		ap = stkrval(argv[1], NIL , RREQ );
		if (ap == NIL)
E 28
I 28
		ap = stkrval(argv->list_node.list, NLNIL , (long) RREQ );
		if (ap == NLNIL)
E 28
			return;
		if (isnta(ap, "i")) {
			error("argv's first argument must be an integer, not %s", nameof(ap));
			return;
		}
D 28
		al = argv[2];
		ap = stklval(al[1], MOD|NOUSE);
		if (ap == NIL)
E 28
I 28
		al = argv->list_node.next;
		ap = stklval(al->list_node.list, MOD|NOUSE);
		if (ap == NLNIL)
E 28
			return;
		if (classify(ap) != TSTR) {
			error("argv's second argument must be a string, not %s", nameof(ap));
			return;
		}
D 31
		putop( P2LISTOP , P2INT );
D 28
		putleaf( P2ICON , width( ap ) , 0 , P2INT , 0 );
E 28
I 28
		putleaf( P2ICON , width( ap ) , 0 , P2INT , (char *) 0 );
E 28
		putop( P2LISTOP , P2INT );
		putop( P2CALL , P2INT );
E 31
I 31
		putop( PCC_CM , PCCT_INT );
		putleaf( PCC_ICON , width( ap ) , 0 , PCCT_INT , (char *) 0 );
		putop( PCC_CM , PCCT_INT );
		putop( PCC_CALL , PCCT_INT );
E 31
		putdot( filename , line );
		return;

	case O_STLIM:
		if (argc != 1) {
			error("stlimit requires one argument");
			return;
		}
D 31
		putleaf( P2ICON , 0 , 0 , ADDTYPE( P2FTN | P2INT , P2PTR )
E 31
I 31
		putleaf( PCC_ICON , 0 , 0 , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 31
			, "_STLIM" );
D 28
		ap = stkrval(argv[1], NIL , RREQ );
		if (ap == NIL)
E 28
I 28
		ap = stkrval(argv->list_node.list, NLNIL , (long) RREQ );
		if (ap == NLNIL)
E 28
			return;
		if (isnta(ap, "i")) {
			error("stlimit's argument must be an integer, not %s", nameof(ap));
			return;
		}
D 31
		putop( P2CALL , P2INT );
E 31
I 31
		putop( PCC_CALL , PCCT_INT );
E 31
		putdot( filename , line );
		return;

	case O_REMOVE:
		if (argc != 1) {
			error("remove expects one argument");
			return;
		}
D 31
		putleaf( P2ICON , 0 , 0 , ADDTYPE( P2FTN | P2INT , P2PTR )
E 31
I 31
		putleaf( PCC_ICON , 0 , 0 , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 31
			, "_REMOVE" );
D 28
		ap = stkrval(argv[1], NOFLAGS , RREQ );
		if (ap == NIL)
E 28
I 28
		ap = stkrval(argv->list_node.list, NLNIL, (long) RREQ );
		if (ap == NLNIL)
E 28
			return;
		if (classify(ap) != TSTR) {
			error("remove's argument must be a string, not %s", nameof(ap));
			return;
		}
D 28
		putleaf( P2ICON , width( ap ) , 0 , P2INT , 0 );
E 28
I 28
D 31
		putleaf( P2ICON , width( ap ) , 0 , P2INT , (char *) 0 );
E 28
		putop( P2LISTOP , P2INT );
		putop( P2CALL , P2INT );
E 31
I 31
		putleaf( PCC_ICON , width( ap ) , 0 , PCCT_INT , (char *) 0 );
		putop( PCC_CM , PCCT_INT );
		putop( PCC_CALL , PCCT_INT );
E 31
		putdot( filename , line );
		return;

	case O_LLIMIT:
		if (argc != 2) {
			error("linelimit expects two arguments");
			return;
		}
D 31
		putleaf( P2ICON , 0 , 0 , ADDTYPE( P2FTN | P2INT , P2PTR )
E 31
I 31
		putleaf( PCC_ICON , 0 , 0 , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 31
			, "_LLIMIT" );
D 28
		ap = stklval(argv[1], NOFLAGS|NOUSE);
		if (ap == NIL)
E 28
I 28
		ap = stklval(argv->list_node.list, NOFLAGS|NOUSE);
		if (ap == NLNIL)
E 28
			return;
		if (!text(ap)) {
			error("linelimit's first argument must be a text file, not %s", nameof(ap));
			return;
		}
D 28
		al = argv[2];
		ap = stkrval(al[1], NIL , RREQ );
		if (ap == NIL)
E 28
I 28
		al = argv->list_node.next;
		ap = stkrval(al->list_node.list, NLNIL , (long) RREQ );
		if (ap == NLNIL)
E 28
			return;
		if (isnta(ap, "i")) {
			error("linelimit's second argument must be an integer, not %s", nameof(ap));
			return;
		}
D 31
		putop( P2LISTOP , P2INT );
		putop( P2CALL , P2INT );
E 31
I 31
		putop( PCC_CM , PCCT_INT );
		putop( PCC_CALL , PCCT_INT );
E 31
		putdot( filename , line );
		return;
	case O_PAGE:
		if (argc != 1) {
			error("page expects one argument");
			return;
		}
D 7
		putRV( 0 , cbn , CURFILEOFFSET , P2PTR|P2STRTY );
E 7
I 7
D 28
		putRV( 0 , cbn , CURFILEOFFSET , NLOCAL , P2PTR|P2STRTY );
E 28
I 28
D 31
		putRV((char *) 0 , cbn , CURFILEOFFSET , NLOCAL , P2PTR|P2STRTY );
E 28
E 7
		putleaf( P2ICON , 0 , 0 , ADDTYPE( P2FTN | P2INT , P2PTR )
E 31
I 31
		putRV((char *) 0 , cbn , CURFILEOFFSET , NLOCAL , PCCTM_PTR|PCCT_STRTY );
		putleaf( PCC_ICON , 0 , 0 , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 31
			, "_UNIT" );
D 28
		ap = stklval(argv[1], NOFLAGS);
		if (ap == NIL)
E 28
I 28
		ap = stklval(argv->list_node.list, NOFLAGS);
		if (ap == NLNIL)
E 28
			return;
		if (!text(ap)) {
			error("Argument to page must be a text file, not %s", nameof(ap));
			return;
		}
D 31
		putop( P2CALL , P2INT );
		putop( P2ASSIGN , P2PTR|P2STRTY );
E 31
I 31
		putop( PCC_CALL , PCCT_INT );
		putop( PCC_ASSIGN , PCCTM_PTR|PCCT_STRTY );
E 31
		putdot( filename , line );
		if ( opt( 't' ) ) {
D 31
		    putleaf( P2ICON , 0 , 0
			, ADDTYPE( P2FTN | P2INT , P2PTR )
E 31
I 31
		    putleaf( PCC_ICON , 0 , 0
			, PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 31
			, "_PAGE" );
D 7
		    putRV( 0 , cbn , CURFILEOFFSET
			    , P2PTR|P2STRTY );
E 7
I 7
D 28
		    putRV( 0 , cbn , CURFILEOFFSET , NLOCAL , P2PTR|P2STRTY );
E 28
I 28
D 31
		    putRV((char *) 0 , cbn , CURFILEOFFSET , NLOCAL , P2PTR|P2STRTY );
E 31
I 31
		    putRV((char *) 0 , cbn , CURFILEOFFSET , NLOCAL , PCCTM_PTR|PCCT_STRTY );
E 31
E 28
E 7
		} else {
D 31
		    putleaf( P2ICON , 0 , 0
			, ADDTYPE( P2FTN | P2INT , P2PTR )
E 31
I 31
		    putleaf( PCC_ICON , 0 , 0
			, PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 31
			, "_fputc" );
D 28
		    putleaf( P2ICON , '\f' , 0 , P2CHAR , 0 );
E 28
I 28
D 31
		    putleaf( P2ICON , '\f' , 0 , (int) P2CHAR , (char *) 0 );
E 28
		    putleaf( P2ICON , 0 , 0
			, ADDTYPE( P2FTN | P2INT , P2PTR )
E 31
I 31
		    putleaf( PCC_ICON , '\f' , 0 , (int) PCCT_CHAR , (char *) 0 );
		    putleaf( PCC_ICON , 0 , 0
			, PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 31
			, "_ACTFILE" );
D 7
		    putRV( 0 , cbn , CURFILEOFFSET
			    , P2PTR|P2STRTY );
E 7
I 7
D 28
		    putRV( 0 , cbn , CURFILEOFFSET , NLOCAL , P2PTR|P2STRTY );
E 28
I 28
D 31
		    putRV((char *) 0 , cbn , CURFILEOFFSET , NLOCAL , P2PTR|P2STRTY );
E 28
E 7
		    putop( P2CALL , P2INT );
		    putop( P2LISTOP , P2INT );
E 31
I 31
		    putRV((char *) 0 , cbn , CURFILEOFFSET , NLOCAL , PCCTM_PTR|PCCT_STRTY );
		    putop( PCC_CALL , PCCT_INT );
		    putop( PCC_CM , PCCT_INT );
E 31
		}
D 31
		putop( P2CALL , P2INT );
E 31
I 31
		putop( PCC_CALL , PCCT_INT );
E 31
		putdot( filename , line );
		return;

I 10
	case O_ASRT:
		if (!opt('t'))
			return;
		if (argc == 0 || argc > 2) {
			error("Assert expects one or two arguments");
			return;
		}
I 14
		if (argc == 2)
			cmd = "_ASRTS";
		else
			cmd = "_ASRT";
E 14
D 31
		putleaf( P2ICON , 0 , 0
D 14
		    , ADDTYPE( P2FTN | P2INT , P2PTR ) , "_ASRT" );
E 14
I 14
		    , ADDTYPE( P2FTN | P2INT , P2PTR ) , cmd );
E 31
I 31
		putleaf( PCC_ICON , 0 , 0
		    , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR ) , cmd );
E 31
E 14
D 28
		ap = stkrval(argv[1], NIL , RREQ );
		if (ap == NIL)
E 28
I 28
		ap = stkrval(argv->list_node.list, NLNIL , (long) RREQ );
		if (ap == NLNIL)
E 28
			return;
		if (isnta(ap, "b"))
			error("Assert expression must be Boolean, not %ss", nameof(ap));
		if (argc == 2) {
			/*
			 * Optional second argument is a string specifying
			 * why the assertion failed.
			 */
D 28
			al = argv[2];
			al = stkrval(al[1], NIL , RREQ );
			if (al == NIL)
E 28
I 28
			al = argv->list_node.next;
			al = (struct tnode *) stkrval(al->list_node.list, NLNIL , (long) RREQ );
			if (al == TR_NIL)
E 28
				return;
D 28
			if (classify(al) != TSTR) {
				error("Second argument to assert must be a string, not %s", nameof(al));
E 28
I 28
			if (classify((struct nl *) al) != TSTR) {
				error("Second argument to assert must be a string, not %s", nameof((struct nl *) al));
E 28
				return;
			}
D 14
		} else {
			putleaf( P2ICON , 0 , 0 , P2INT , 0 );
E 14
I 14
D 31
			putop( P2LISTOP , P2INT );
E 31
I 31
			putop( PCC_CM , PCCT_INT );
E 31
E 14
		}
D 14
		putop( P2LISTOP , P2INT );
E 14
D 31
		putop( P2CALL , P2INT );
E 31
I 31
		putop( PCC_CALL , PCCT_INT );
E 31
		putdot( filename , line );
		return;

E 10
	case O_PACK:
		if (argc != 3) {
			error("pack expects three arguments");
			return;
		}
D 31
		putleaf( P2ICON , 0 , 0 , ADDTYPE( P2FTN | P2INT , P2PTR )
E 31
I 31
		putleaf( PCC_ICON , 0 , 0 , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 31
			, "_PACK" );
		pu = "pack(a,i,z)";
D 28
		pua = (al = argv)[1];
		pui = (al = al[2])[1];
		puz = (al = al[2])[1];
E 28
I 28
		pua = (al = argv)->list_node.list;
		pui = (al = al->list_node.next)->list_node.list;
		puz = (al = al->list_node.next)->list_node.list;
E 28
		goto packunp;
	case O_UNPACK:
		if (argc != 3) {
			error("unpack expects three arguments");
			return;
		}
D 31
		putleaf( P2ICON , 0 , 0 , ADDTYPE( P2FTN | P2INT , P2PTR )
E 31
I 31
		putleaf( PCC_ICON , 0 , 0 , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 31
			, "_UNPACK" );
		pu = "unpack(z,a,i)";
D 28
		puz = (al = argv)[1];
		pua = (al = al[2])[1];
		pui = (al = al[2])[1];
E 28
I 28
		puz = (al = argv)->list_node.list;
		pua = (al = al->list_node.next)->list_node.list;
		pui = (al = al->list_node.next)->list_node.list;
E 28
packunp:
D 28
		ap = stkrval((int *) pui, NLNIL , RREQ );
E 28
I 28
		ap = stkrval(pui, NLNIL , (long) RREQ );
E 28
		if (ap == NIL)
			return;
		ap = stklval(pua, op == O_PACK ? NOFLAGS : MOD|NOUSE);
		if (ap == NIL)
			return;
		if (ap->class != ARRAY) {
			error("%s requires a to be an unpacked array, not %s", pu, nameof(ap));
			return;
		}
D 31
		putop( P2LISTOP , P2INT );
E 31
I 31
		putop( PCC_CM , PCCT_INT );
E 31
D 28
		al = (struct nl *) stklval(puz, op == O_UNPACK ? NOFLAGS : MOD|NOUSE);
		if (al->class != ARRAY) {
E 28
I 28
		al = (struct tnode *) stklval(puz, op == O_UNPACK ? NOFLAGS : MOD|NOUSE);
		if (((struct nl *) al)->class != ARRAY) {
E 28
			error("%s requires z to be a packed array, not %s", pu, nameof(ap));
			return;
		}
D 28
		if (al->type == NIL || ap->type == NIL)
E 28
I 28
		if (((struct nl *) al)->type == NIL || 
			((struct nl *) ap)->type == NIL)
E 28
			return;
D 28
		if (al->type != ap->type) {
E 28
I 28
		if (((struct nl *) al)->type != ((struct nl *) ap)->type) {
E 28
			error("%s requires a and z to be arrays of the same type", pu, nameof(ap));
			return;
		}
D 31
		putop( P2LISTOP , P2INT );
E 31
I 31
		putop( PCC_CM , PCCT_INT );
E 31
D 28
		k = width(al);
E 28
I 28
		k = width((struct nl *) al);
E 28
		itemwidth = width(ap->type);
		ap = ap->chain;
D 28
		al = al->chain;
		if (ap->chain != NIL || al->chain != NIL) {
E 28
I 28
		al = ((struct tnode *) ((struct nl *) al)->chain);
		if (ap->chain != NIL || ((struct nl *) al)->chain != NIL) {
E 28
			error("%s requires a and z to be single dimension arrays", pu);
			return;
		}
		if (ap == NIL || al == NIL)
			return;
		/*
		 * al is the range for z i.e. u..v
		 * ap is the range for a i.e. m..n
		 * i will be n-m+1
		 * j will be v-u+1
		 */
		i = ap->range[1] - ap->range[0] + 1;
D 28
		j = al->range[1] - al->range[0] + 1;
E 28
I 28
		j = ((struct nl *) al)->range[1] - 
			((struct nl *) al)->range[0] + 1;
E 28
		if (i < j) {
D 28
			error("%s cannot have more elements in a (%d) than in z (%d)", pu, j, i);
E 28
I 28
			error("%s cannot have more elements in a (%d) than in z (%d)", pu, (char *) j, (char *) i);
E 28
			return;
		}
		/*
		 * get n-m-(v-u) and m for the interpreter
		 */
		i -= j;
		j = ap->range[0];
D 28
		putleaf( P2ICON , itemwidth , 0 , P2INT , 0 );
E 28
I 28
D 31
		putleaf( P2ICON , itemwidth , 0 , P2INT , (char *) 0 );
E 28
		putop( P2LISTOP , P2INT );
D 28
		putleaf( P2ICON , j , 0 , P2INT , 0 );
E 28
I 28
		putleaf( P2ICON , j , 0 , P2INT , (char *) 0 );
E 28
		putop( P2LISTOP , P2INT );
D 28
		putleaf( P2ICON , i , 0 , P2INT , 0 );
E 28
I 28
		putleaf( P2ICON , i , 0 , P2INT , (char *) 0 );
E 28
		putop( P2LISTOP , P2INT );
D 28
		putleaf( P2ICON , k , 0 , P2INT , 0 );
E 28
I 28
		putleaf( P2ICON , k , 0 , P2INT , (char *) 0 );
E 28
		putop( P2LISTOP , P2INT );
		putop( P2CALL , P2INT );
E 31
I 31
		putleaf( PCC_ICON , itemwidth , 0 , PCCT_INT , (char *) 0 );
		putop( PCC_CM , PCCT_INT );
		putleaf( PCC_ICON , j , 0 , PCCT_INT , (char *) 0 );
		putop( PCC_CM , PCCT_INT );
		putleaf( PCC_ICON , i , 0 , PCCT_INT , (char *) 0 );
		putop( PCC_CM , PCCT_INT );
		putleaf( PCC_ICON , k , 0 , PCCT_INT , (char *) 0 );
		putop( PCC_CM , PCCT_INT );
		putop( PCC_CALL , PCCT_INT );
E 31
		putdot( filename , line );
		return;
	case 0:
D 10
		error("%s is an unimplemented 6400 extension", p->symbol);
E 10
I 10
		error("%s is an unimplemented extension", p->symbol);
E 10
		return;

	default:
		panic("proc case");
	}
}
#endif PC
E 1
