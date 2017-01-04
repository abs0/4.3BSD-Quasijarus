h12547
s 00007/00003/01175
d D 5.1 85/06/05 14:44:49 dist 25 24
c Add copyright
e
s 00027/00007/01151
d D 2.2 84/04/26 15:14:23 peter 24 23
c when reading from files of integers (or subranges thereof)
c use sign-extending INDirect through buffer pointer
c so the rangecheck works (which it doesn't if zero-extending is done,
c e.g. for 1 byte reads becoming 2 bytes on the stack).
e
s 00000/00000/01158
d D 2.1 84/02/08 20:51:37 aoki 23 20
c synchronize to version 2
e
s 00000/00000/01158
d R 1.21 83/10/09 17:41:18 thien 22 21
c 
e
s 00000/00000/01158
d R 1.20 83/09/19 07:00:04 thien 21 20
c Restoring to unlinted version
e
s 00225/00208/00933
d D 1.19 83/08/19 05:00:42 thien 20 19
c The changes were made to allow successful linting
e
s 00010/00017/01131
d D 1.18 83/04/08 16:44:52 mckusick 19 18
c parameterize number of digits in the exponent of real numbers
e
s 00001/00000/01147
d D 1.17 83/02/28 17:15:47 peter 18 17
c clean up temporary allocation, moving everything relevant to
c tmps.c and (new) tmps.h.  correctly emit LBRAC lines.  allocate registers
c from high to low.  put in data structures for multiple types of registers.
e
s 00018/00006/01129
d D 1.16 82/11/14 16:45:02 mckusick 17 16
c fix bug in delta 1.14 that made fields come out one byte shorter than requested
e
s 00004/00002/01131
d D 1.15 82/10/14 17:42:18 peter 16 15
c setting of output's NUSED flag was missing {};s.
e
s 00001/00001/01132
d D 1.14 82/09/03 18:06:35 mckusick 15 14
c do not put a leading blank before real numbers
e
s 00002/00000/01131
d D 1.13 82/08/29 21:28:31 mckusick 14 13
c remove restriction on files in dynamic structures
e
s 00002/00000/01129
d D 1.12 82/08/29 14:07:39 peter 13 12
c allowing no files list in program statement.
e
s 00032/00001/01097
d D 1.11 82/08/27 00:34:51 mckusick 12 11
c convert "assert" from being a reserved word to being a non-standard procedure
e
s 00011/00001/01087
d D 1.10 82/04/12 15:36:37 mckusick 11 10
c allow writing of pointers to text files
e
s 00012/00006/01076
d D 1.9 81/06/04 19:21:31 peter 10 9
c fix bug in tmpalloc for variable field widths
e
s 00006/00003/01076
d D 1.8 81/03/11 23:40:41 mckusic 9 8
c centralize temporary allocation in tmps.c
e
s 00006/00000/01073
d D 1.7 81/03/10 14:48:38 mckusic 8 7
c restrict zero write widths
e
s 00023/00021/01050
d D 1.6 81/03/10 00:46:45 mckusic 7 6
c onyx optimizations
e
s 00044/00022/01027
d D 1.5 81/03/08 19:26:24 mckusic 6 5
c merge in onyx changes
e
s 00051/00031/00998
d D 1.4 81/01/06 17:16:39 mckusic 5 4
c modify to allow use of px written in `C' and the use of libpc
e
s 00004/00002/01025
d D 1.3 80/10/28 21:35:11 peter 4 2
c add warnings for extensions to language
e
s 00002/00001/01026
d R 1.3 80/10/28 21:10:46 peter 3 2
c add warnings for extensions to language
e
s 00001/00001/01026
d D 1.2 80/10/03 01:09:07 peter 2 1
c Implement formal functions and procedures
e
s 01027/00000/00000
d D 1.1 80/08/27 19:56:02 peter 1 0
c date and time created 80/08/27 19:56:02 by peter
e
u
U
t
T
I 1
D 25
/* Copyright (c) 1979 Regents of the University of California */
E 25
I 25
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 25

I 20
#ifndef lint
E 20
D 6
static	char sccsid[] = "%Z%%M% %I% %G%";
E 6
I 6
D 25
static char sccsid[] = "%Z%%M% %I% %G%";
I 20
#endif
E 25
I 25
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 25
E 20
E 6

#include "whoami.h"
#ifdef OBJ
    /*
     *	and the rest of the file
     */
#include "0.h"
#include "tree.h"
#include "opcode.h"
#include "objfmt.h"
I 18
#include "tmps.h"
I 20
#include "tree_ty.h"
E 20
E 18

/*
I 19
 * The constant EXPOSIZE specifies the number of digits in the exponent
 * of real numbers.
 *
E 19
I 17
 * The constant REALSPC defines the amount of forced padding preceeding
 * real numbers when they are printed. If REALSPC == 0, then no padding
 * is added, REALSPC == 1 adds one extra blank irregardless of the width
 * specified by the user.
 *
 * N.B. - Values greater than one require program mods.
 */
D 19
#define	REALSPC	0
E 19
I 19
#define EXPOSIZE	2
#define	REALSPC		0
E 19

/*
E 17
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
proc(r)
D 20
	int *r;
E 20
I 20
	struct tnode *r;
E 20
{
	register struct nl *p;
D 20
	register int *alv, *al, op;
	struct nl *filetype, *ap;
	int argc, *argv, typ, fmtspec, strfmt, stkcnt, *file;
	char fmt, format[20], *strptr;
	int prec, field, strnglen, fmtlen, fmtstart, pu;
	int *pua, *pui, *puz;
E 20
I 20
	register struct tnode *alv, *al;
 	register int op;
	struct nl *filetype, *ap, *al1;
	int argc, typ, fmtspec, strfmt, stkcnt;
	struct tnode *argv; 
	char fmt, format[20], *strptr, *pu;
	int prec, field, strnglen, fmtlen, fmtstart;
	struct tnode *pua, *pui, *puz, *file;
E 20
	int i, j, k;
	int itemwidth;
I 9
	struct tmps soffset;
I 10
	struct nl	*tempnlp;
E 10
E 9

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
D 20
	p = lookup(r[2]);
E 20
I 20
	p = lookup(r->pcall_node.proc_id);
E 20
	if (p == NIL) {
D 20
		rvlist(r[3]);
E 20
I 20
		rvlist(r->pcall_node.arg);
E 20
		return;
	}
D 2
	if (p->class != PROC) {
E 2
I 2
	if (p->class != PROC && p->class != FPROC) {
E 2
		error("Can't call %s, its %s not a procedure", p->symbol, classes[p->class]);
D 20
		rvlist(r[3]);
E 20
I 20
		rvlist(r->pcall_node.arg);
E 20
		return;
	}
D 20
	argv = r[3];
E 20
I 20
	argv = r->pcall_node.arg;
E 20

	/*
	 * Call handles user defined
	 * procedures and functions.
	 */
	if (bn != 0) {
D 20
		call(p, argv, PROC, bn);
E 20
I 20
		(void) call(p, argv, PROC, bn);
E 20
		return;
	}

	/*
	 * Call to built-in procedure.
	 * Count the arguments.
	 */
	argc = 0;
D 20
	for (al = argv; al != NIL; al = al[2])
E 20
I 20
	for (al = argv; al != TR_NIL; al = al->list_node.next)
E 20
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
D 20
			put(1, O_MESSAGE);
E 20
I 20
			(void) put(1, O_MESSAGE);
E 20
			return;
		}
		if (argc != 1) {
			error("flush takes at most one argument");
			return;
		}
D 5
		ap = stkrval(argv[1], NIL , RREQ );
E 5
I 5
D 20
		ap = stklval(argv[1], NIL , LREQ );
E 5
		if (ap == NIL)
E 20
I 20
		ap = stklval(argv->list_node.list, NIL );
		if (ap == NLNIL)
E 20
			return;
		if (ap->class != FILET) {
			error("flush's argument must be a file, not %s", nameof(ap));
			return;
		}
D 20
		put(1, op);
E 20
I 20
		(void) put(1, op);
E 20
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
D 20
			put(1, O_MESSAGE);
		} else if (argv != NIL && (al = argv[1])[0] != T_WEXP) {
E 20
I 20
			(void) put(1, O_MESSAGE);
		} else if (argv != TR_NIL && (al = argv->list_node.list)->tag !=
					T_WEXP) {
E 20
			/*
			 * If there is a first argument which has
			 * no write widths, then it is potentially
			 * a file name.
			 */
			codeoff();
D 20
			ap = stkrval(argv[1], NIL , RREQ );
E 20
I 20
			ap = stkrval(argv->list_node.list, NLNIL, (long) RREQ );
E 20
			codeon();
D 20
			if (ap == NIL)
				argv = argv[2];
			if (ap != NIL && ap->class == FILET) {
E 20
I 20
			if (ap == NLNIL)
				argv = argv->list_node.next;
			if (ap != NLNIL && ap->class == FILET) {
E 20
				/*
				 * Got "write(f, ...", make
				 * f the active file, and save
				 * it and its type for use in
				 * processing the rest of the
				 * arguments to write.
				 */
D 20
				file = argv[1];
E 20
I 20
				file = argv->list_node.list;
E 20
				filetype = ap->type;
D 5
				stkrval(argv[1], NIL , RREQ );
E 5
I 5
D 20
				stklval(argv[1], NIL , LREQ );
E 5
				put(1, O_UNIT);
E 20
I 20
				(void) stklval(argv->list_node.list, NIL );
				(void) put(1, O_UNIT);
E 20
				/*
				 * Skip over the first argument
				 */
D 20
				argv = argv[2];
E 20
I 20
				argv = argv->list_node.next;
E 20
				argc--;
D 16
			} else
E 16
I 16
			} else {
E 16
				/*
				 * Set up for writing on 
				 * standard output.
				 */
D 20
				put(1, O_UNITOUT);
E 20
I 20
				(void) put(1, O_UNITOUT);
E 20
I 13
				output->nl_flags |= NUSED;
E 13
D 16
		} else
E 16
I 16
			}
		} else {
E 16
D 20
			put(1, O_UNITOUT);
E 20
I 20
			(void) put(1, O_UNITOUT);
E 20
I 13
			output->nl_flags |= NUSED;
I 16
		}
E 16
E 13
		/*
		 * Loop and process each
		 * of the arguments.
		 */
D 20
		for (; argv != NIL; argv = argv[2]) {
E 20
I 20
		for (; argv != TR_NIL; argv = argv->list_node.next) {
E 20
			/*
			 * fmtspec indicates the type (CONstant or VARiable)
			 *	and number (none, WIDTH, and/or PRECision)
			 *	of the fields in the printf format for this
			 *	output variable.
D 7
			 * stkcnt is the number of longs pushed on the stack
E 7
I 7
			 * stkcnt is the number of bytes pushed on the stack
E 7
			 * fmt is the format output indicator (D, E, F, O, X, S)
			 * fmtstart = 0 for leading blank; = 1 for no blank
			 */
			fmtspec = NIL;
			stkcnt = 0;
			fmt = 'D';
			fmtstart = 1;
D 20
			al = argv[1];
			if (al == NIL)
E 20
I 20
			al = argv->list_node.list;
			if (al == TR_NIL)
E 20
				continue;
D 20
			if (al[0] == T_WEXP)
				alv = al[1];
E 20
I 20
			if (al->tag == T_WEXP)
				alv = al->wexpr_node.expr1;
E 20
			else
				alv = al;
D 20
			if (alv == NIL)
E 20
I 20
			if (alv == TR_NIL)
E 20
				continue;
			codeoff();
D 20
			ap = stkrval(alv, NIL , RREQ );
E 20
I 20
			ap = stkrval(alv, NLNIL , (long) RREQ );
E 20
			codeon();
D 20
			if (ap == NIL)
E 20
I 20
			if (ap == NLNIL)
E 20
				continue;
			typ = classify(ap);
D 20
			if (al[0] == T_WEXP) {
E 20
I 20
			if (al->tag == T_WEXP) {
E 20
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
D 20
				if (al[3] == OCT)
E 20
I 20
				if (al->wexpr_node.expr3 == 
						(struct tnode *) OCT)
E 20
					fmt = 'O';
D 20
				else if (al[3] == HEX)
E 20
I 20
				else if (al->wexpr_node.expr3 == 
						(struct tnode *) HEX)
E 20
					fmt = 'X';
D 20
				else if (al[3] != NIL) {
E 20
I 20
				else if (al->wexpr_node.expr3 != TR_NIL) {
E 20
					/*
					 * Evaluate second format spec
					 */
D 20
					if ( constval(al[3])
E 20
I 20
					if ( constval(al->wexpr_node.expr3)
E 20
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
D 20
				if (al[2] != NIL) {
					if ( constval(al[2])
E 20
I 20
				if (al->wexpr_node.expr2 != TR_NIL) {
					if ( constval(al->wexpr_node.expr2)
E 20
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
I 8
				if ( opt('s') &&
				    ((fmtspec & CONPREC) && prec == 0 ||
				    (fmtspec & CONWIDTH) && field == 0)) {
					standard();
					error("Zero widths are non-standard");
				}
E 8
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
D 5
				stkrval(file, NIL , RREQ );
E 5
I 5
D 20
				stklval(file, NIL , LREQ );
E 5
				put(1, O_FNIL);
E 20
I 20
				(void) stklval(file, NIL );
				(void) put(1, O_FNIL);
E 20
				/*
				 * file^ := ...
				 */
D 20
				ap = rvalue(argv[1], NIL);
				if (ap == NIL)
E 20
I 20
				ap = rvalue(argv->list_node.list, NLNIL, LREQ);
				if (ap == NLNIL)
E 20
					continue;
D 20
				if (incompat(ap, filetype, argv[1])) {
E 20
I 20
				if (incompat(ap, filetype,
						argv->list_node.list)) {
E 20
					cerror("Type mismatch in write to non-text file");
					continue;
				}
				convert(ap, filetype);
D 20
				put(2, O_AS, width(filetype));
E 20
I 20
				(void) put(2, O_AS, width(filetype));
E 20
				/*
				 * put(file)
				 */
D 20
				put(1, O_PUT);
E 20
I 20
				(void) put(1, O_PUT);
E 20
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
			 * Place the arguement on the stack. If there is
			 * no format specified by the programmer, implement
			 * the default.
			 */
			switch (typ) {
I 11
			case TPTR:
				warning();
				if (opt('s')) {
					standard();
				}
				error("Writing %ss to text files is non-standard",
				    clnames[typ]);
				/* and fall through */
E 11
			case TINT:
				if (fmt != 'f') {
D 20
					ap = stkrval(alv, NIL , RREQ );
E 20
I 20
					ap = stkrval(alv, NLNIL, (long) RREQ );
E 20
D 7
					stkcnt++;
E 7
I 7
					stkcnt += sizeof(long);
E 7
				} else {
D 20
					ap = stkrval(alv, NIL , RREQ );
					put(1, O_ITOD);
E 20
I 20
					ap = stkrval(alv, NLNIL, (long) RREQ );
					(void) put(1, O_ITOD);
E 20
D 7
					stkcnt += 2;
E 7
I 7
					stkcnt += sizeof(double);
E 7
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
I 5
				if (fmtspec == NIL) {
D 20
					put(1, O_FILE);
					ap = stkrval(alv, NIL , RREQ );
E 20
I 20
					(void) put(1, O_FILE);
					ap = stkrval(alv, NLNIL, (long) RREQ );
E 20
D 7
					put(1, O_WRITEC);
E 7
I 7
					convert(nl + T4INT, INT_TYP);
D 20
					put(2, O_WRITEC,
E 20
I 20
					(void) put(2, O_WRITEC,
E 20
						sizeof(char *) + sizeof(int));
E 7
					fmtspec = SKIP;
					break;
				}
E 5
D 20
				ap = stkrval(alv, NIL , RREQ );
E 20
I 20
				ap = stkrval(alv, NLNIL , (long) RREQ );
E 20
D 7
				stkcnt++;
E 7
I 7
				convert(nl + T4INT, INT_TYP);
				stkcnt += sizeof(int);
E 7
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
D 11
				error("Writing scalars to text files is non-standard");
E 11
I 11
				error("Writing %ss to text files is non-standard",
				    clnames[typ]);
				/* and fall through */
E 11
E 4
			case TBOOL:
D 20
				stkrval(alv, NIL , RREQ );
D 6
				put(2, O_NAM, listnames(ap));
E 6
I 6
				put(2, O_NAM, (long)listnames(ap));
E 20
I 20
				(void) stkrval(alv, NLNIL , (long) RREQ );
				(void) put(2, O_NAM, (long)listnames(ap));
E 20
D 7
#				ifdef PDP11
					put(2, O_CON2, 0);  /* long align ptr */
#				endif PDP11
E 6
				stkcnt++;
E 7
I 7
				stkcnt += sizeof(char *);
E 7
				fmt = 's';
				break;
			case TDOUBLE:
D 20
				ap = stkrval(alv, TDOUBLE , RREQ );
E 20
I 20
				ap = stkrval(alv, (struct nl *) TDOUBLE , (long) RREQ );
E 20
D 7
				stkcnt += 2;
E 7
I 7
				stkcnt += sizeof(double);
E 7
			     tdouble:
				switch (fmtspec) {
				case NIL:
D 6
					field = 21;
E 6
I 6
D 19
#					ifdef DEC11
					    field = 21;
#					else
					    field = 22;
#					endif DEC11
E 6
					prec = 14;
E 19
I 19
					field = 14 + (5 + EXPOSIZE);
				        prec = field - (5 + EXPOSIZE);
E 19
D 6
					fmt = 'E';
E 6
I 6
					fmt = 'e';
E 6
					fmtspec = CONWIDTH + CONPREC;
					break;
				case CONWIDTH:
D 17
					if (--field < 1)
E 17
I 17
					field -= REALSPC;
					if (field < 1)
E 17
						field = 1;
D 6
					prec = field - 7;
E 6
I 6
D 19
#					ifdef DEC11
					    prec = field - 7;
#					else
					    prec = field - 8;
#					endif DEC11
E 19
I 19
				        prec = field - (5 + EXPOSIZE);
E 19
E 6
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
				case CONWIDTH + CONPREC:
				case CONWIDTH + VARPREC:
D 17
					if (--field < 1)
E 17
I 17
					field -= REALSPC;
					if (field < 1)
E 17
						field = 1;
				}
				format[0] = ' ';
D 15
				fmtstart = 0;
E 15
I 15
D 17
				fmtstart = 1;
E 17
I 17
				fmtstart = 1 - REALSPC;
E 17
E 15
				break;
			case TSTR:
D 20
				constval( alv );
E 20
I 20
				(void) constval( alv );
E 20
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
					if (field <= strnglen) {
						fmtspec = SKIP;
						break;
					} else
						field -= strnglen;
				}
				/*
				 * push string to implement leading blank padding
				 */
D 20
				put(2, O_LVCON, 2);
E 20
I 20
				(void) put(2, O_LVCON, 2);
E 20
				putstr("", 0);
I 6
D 7
#				ifdef PDP11
					put(2, O_CON2, 0);  /* long align ptr */
#				endif PDP11
E 6
				stkcnt++;
E 7
I 7
				stkcnt += sizeof(char *);
E 7
				break;
			default:
				error("Can't write %ss to a text file", clnames[typ]);
				continue;
			}
			/*
			 * If there is a variable precision, evaluate it onto
			 * the stack
			 */
			if (fmtspec & VARPREC) {
D 20
				ap = stkrval(al[3], NIL , RREQ );
E 20
I 20
				ap = stkrval(al->wexpr_node.expr3, NLNIL ,
						(long) RREQ );
E 20
				if (ap == NIL)
					continue;
				if (isnta(ap,"i")) {
					error("Second write width must be integer, not %s", nameof(ap));
					continue;
				}
				if ( opt( 't' ) ) {
D 20
				    put(3, O_MAX, 0, 0);
E 20
I 20
				    (void) put(3, O_MAX, 0, 0);
E 20
				}
D 7
				stkcnt++;
E 7
I 7
				convert(nl+T4INT, INT_TYP);
				stkcnt += sizeof(int);
E 7
			}
			/*
			 * If there is a variable width, evaluate it onto
			 * the stack
			 */
			if (fmtspec & VARWIDTH) {
				if ( ( typ == TDOUBLE && fmtspec == VARWIDTH )
				    || typ == TSTR ) {
D 6
					i = sizes[cbn].om_off -= sizeof(int);
E 6
I 6
D 9
					i = sizes[cbn].om_off -= sizeof(long);
E 6
					if (i < sizes[cbn].om_max)
						sizes[cbn].om_max = i;
E 9
I 9
					soffset = sizes[cbn].curtmps;
D 10
					i = tmpalloc(sizeof(long),
E 10
I 10
D 20
					tempnlp = tmpalloc(sizeof(long),
E 20
I 20
					tempnlp = tmpalloc((long) (sizeof(long)),
E 20
E 10
						nl+T4INT, REGOK);
E 9
D 10
					put(2, O_LV | cbn << 8 + INDX, i);
E 10
I 10
D 20
					put(2, O_LV | cbn << 8 + INDX, 
E 20
I 20
					(void) put(2, O_LV | cbn << 8 + INDX, 
E 20
					    tempnlp -> value[ NL_OFFS ] );
E 10
				}
D 20
				ap = stkrval(al[2], NIL , RREQ );
E 20
I 20
				ap = stkrval(al->wexpr_node.expr2, NLNIL, (long) RREQ );
E 20
				if (ap == NIL)
					continue;
				if (isnta(ap,"i")) {
					error("First write width must be integer, not %s", nameof(ap));
					continue;
				}
D 7
				stkcnt++;
E 7
				/*
				 * Perform special processing on widths based
				 * on data type 
				 */
				switch (typ) {
				case TDOUBLE:
					if (fmtspec == VARWIDTH) {
D 6
						fmt = 'E';
E 6
I 6
						fmt = 'e';
E 6
D 20
						put(1, O_AS4);
D 10
						put(2, O_RV4 | cbn << 8 + INDX, i);
E 10
I 10
						put(2, O_RV4 | cbn << 8 + INDX,
E 20
I 20
						(void) put(1, O_AS4);
						(void) put(2, O_RV4 | cbn << 8 + INDX,
E 20
						    tempnlp -> value[NL_OFFS] );
E 10
D 6
						put(3, O_MAX, 8, 1);
E 6
I 6
D 19
#						ifdef DEC11
D 17
						    put(3, O_MAX, 8, 1);
E 17
I 17
						    put(3, O_MAX, 7 + REALSPC, 1);
E 17
#						else
D 17
						    put(3, O_MAX, 9, 1);
E 17
I 17
						    put(3, O_MAX, 8 + REALSPC, 1);
E 17
#						endif DEC11
E 19
I 19
D 20
					        put(3, O_MAX,
E 20
I 20
					        (void) put(3, O_MAX,
E 20
						    5 + EXPOSIZE + REALSPC, 1);
E 19
I 7
						convert(nl+T4INT, INT_TYP);
						stkcnt += sizeof(int);
E 7
E 6
D 10
						put(2, O_RV4 | cbn << 8 + INDX, i);
E 10
I 10
D 20
						put(2, O_RV4 | cbn << 8 + INDX, 
E 20
I 20
						(void) put(2, O_RV4 | cbn << 8 + INDX, 
E 20
						    tempnlp->value[NL_OFFS] );
E 10
D 7
						stkcnt++;
E 7
						fmtspec += VARPREC;
I 9
						tmpfree(&soffset);
E 9
					}
D 17
					put(3, O_MAX, 1, 1);
E 17
I 17
D 20
					put(3, O_MAX, REALSPC, 1);
E 20
I 20
					(void) put(3, O_MAX, REALSPC, 1);
E 20
E 17
					break;
				case TSTR:
D 20
					put(1, O_AS4);
D 10
					put(2, O_RV4 | cbn << 8 + INDX, i);
E 10
I 10
					put(2, O_RV4 | cbn << 8 + INDX, 
E 20
I 20
					(void) put(1, O_AS4);
					(void) put(2, O_RV4 | cbn << 8 + INDX, 
E 20
					    tempnlp -> value[ NL_OFFS ] );
E 10
D 20
					put(3, O_MAX, strnglen, 0);
E 20
I 20
					(void) put(3, O_MAX, strnglen, 0);
E 20
					break;
				default:
					if ( opt( 't' ) ) {
D 20
					    put(3, O_MAX, 0, 0);
E 20
I 20
					    (void) put(3, O_MAX, 0, 0);
E 20
					}
					break;
				}
I 7
				convert(nl+T4INT, INT_TYP);
				stkcnt += sizeof(int);
E 7
			}
			/*
			 * Generate the format string
			 */
			switch (fmtspec) {
			default:
				panic("fmt2");
D 5
			case NIL:
				if (fmt == 'c')
					put(1, O_WRITEC);
				else  {
					sprintf(&format[1], "%%%c", fmt);
					goto fmtgen;
				}
E 5
			case SKIP:
				break;
I 5
			case NIL:
				sprintf(&format[1], "%%%c", fmt);
				goto fmtgen;
E 5
			case CONWIDTH:
D 6
				sprintf(&format[1], "%%%1D%c", field, fmt);
E 6
I 6
				sprintf(&format[1], "%%%d%c", field, fmt);
E 6
				goto fmtgen;
			case VARWIDTH:
				sprintf(&format[1], "%%*%c", fmt);
				goto fmtgen;
			case CONWIDTH + CONPREC:
D 6
				sprintf(&format[1], "%%%1D.%1D%c", field, prec, fmt);
E 6
I 6
				sprintf(&format[1], "%%%d.%d%c", field, prec, fmt);
E 6
				goto fmtgen;
			case CONWIDTH + VARPREC:
D 6
				sprintf(&format[1], "%%%1D.*%c", field, fmt);
E 6
I 6
				sprintf(&format[1], "%%%d.*%c", field, fmt);
E 6
				goto fmtgen;
			case VARWIDTH + CONPREC:
D 6
				sprintf(&format[1], "%%*.%1D%c", prec, fmt);
E 6
I 6
				sprintf(&format[1], "%%*.%d%c", prec, fmt);
E 6
				goto fmtgen;
			case VARWIDTH + VARPREC:
				sprintf(&format[1], "%%*.*%c", fmt);
			fmtgen:
				fmtlen = lenstr(&format[fmtstart], 0);
D 20
				put(2, O_LVCON, fmtlen);
E 20
I 20
				(void) put(2, O_LVCON, fmtlen);
E 20
				putstr(&format[fmtstart], 0);
D 20
				put(1, O_FILE);
E 20
I 20
				(void) put(1, O_FILE);
E 20
D 7
				stkcnt += 2;
E 7
I 7
				stkcnt += 2 * sizeof(char *);
E 7
D 20
				put(2, O_WRITEF, stkcnt);
E 20
I 20
				(void) put(2, O_WRITEF, stkcnt);
E 20
			}
			/*
			 * Write the string after its blank padding
			 */
			if (typ == TSTR) {
D 20
				put(1, O_FILE);
D 7
				put(2, O_CON24, 1);
E 7
I 7
				put(2, CON_INT, 1);
E 20
I 20
				(void) put(1, O_FILE);
				(void) put(2, CON_INT, 1);
E 20
E 7
				if (strfmt & VARWIDTH) {
D 10
					put(2, O_RV4 | cbn << 8 + INDX , i );
E 10
I 10
D 20
					put(2, O_RV4 | cbn << 8 + INDX , 
E 20
I 20
					(void) put(2, O_RV4 | cbn << 8 + INDX , 
E 20
					    tempnlp -> value[ NL_OFFS ] );
E 10
D 20
					put(2, O_MIN, strnglen);
E 20
I 20
					(void) put(2, O_MIN, strnglen);
E 20
I 7
					convert(nl+T4INT, INT_TYP);
I 9
					tmpfree(&soffset);
E 9
E 7
				} else {
					if ((fmtspec & SKIP) &&
					   (strfmt & CONWIDTH)) {
						strnglen = field;
					}
D 7
					put(2, O_CON24, strnglen);
E 7
I 7
D 20
					put(2, CON_INT, strnglen);
E 20
I 20
					(void) put(2, CON_INT, strnglen);
E 20
E 7
				}
D 20
				ap = stkrval(alv, NIL , RREQ );
D 7
				put(1, O_WRITES);
E 7
I 7
				put(2, O_WRITES,
E 20
I 20
				ap = stkrval(alv, NLNIL , (long) RREQ );
				(void) put(2, O_WRITES,
E 20
					2 * sizeof(char *) + 2 * sizeof(int));
E 7
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
D 20
				put(1, O_WRITLN);
E 20
I 20
				(void) put(1, O_WRITLN);
E 20
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
D 20
		if (argv != NIL) {
E 20
I 20
		if (argv != TR_NIL) {
E 20
			codeoff();
D 20
			ap = stkrval(argv[1], NIL , RREQ );
E 20
I 20
			ap = stkrval(argv->list_node.list, NLNIL, (long) RREQ );
E 20
			codeon();
D 20
			if (ap == NIL)
				argv = argv[2];
			if (ap != NIL && ap->class == FILET) {
E 20
I 20
			if (ap == NLNIL)
				argv = argv->list_node.next;
			if (ap != NLNIL && ap->class == FILET) {
E 20
				/*
				 * Got "read(f, ...", make
				 * f the active file, and save
				 * it and its type for use in
				 * processing the rest of the
				 * arguments to read.
				 */
D 20
				file = argv[1];
E 20
I 20
				file = argv->list_node.list;
E 20
				filetype = ap->type;
D 5
				stkrval(argv[1], NIL , RREQ );
E 5
I 5
D 20
				stklval(argv[1], NIL , LREQ );
E 5
				put(1, O_UNIT);
				argv = argv[2];
E 20
I 20
				(void) stklval(argv->list_node.list, NIL );
				(void) put(1, O_UNIT);
				argv = argv->list_node.next;
E 20
				argc--;
			} else {
				/*
				 * Default is read from
				 * standard input.
				 */
D 20
				put(1, O_UNITINP);
E 20
I 20
				(void) put(1, O_UNITINP);
E 20
				input->nl_flags |= NUSED;
			}
		} else {
D 20
			put(1, O_UNITINP);
E 20
I 20
			(void) put(1, O_UNITINP);
E 20
			input->nl_flags |= NUSED;
		}
		/*
		 * Loop and process each
		 * of the arguments.
		 */
D 20
		for (; argv != NIL; argv = argv[2]) {
E 20
I 20
		for (; argv != TR_NIL; argv = argv->list_node.next) {
E 20
			/*
			 * Get the address of the target
			 * on the stack.
			 */
D 20
			al = argv[1];
			if (al == NIL)
E 20
I 20
			al = argv->list_node.list;
			if (al == TR_NIL)
E 20
				continue;
D 20
			if (al[0] != T_VAR) {
E 20
I 20
			if (al->tag != T_VAR) {
E 20
				error("Arguments to %s must be variables, not expressions", p->symbol);
				continue;
			}
			ap = stklval(al, MOD|ASGN|NOUSE);
D 20
			if (ap == NIL)
E 20
I 20
			if (ap == NLNIL)
E 20
				continue;
			if (filetype != nl+T1CHAR) {
				/*
				 * Generalized read, i.e.
				 * from a non-textfile.
				 */
D 20
				if (incompat(filetype, ap, argv[1] )) {
E 20
I 20
				if (incompat(filetype, ap,
					argv->list_node.list )) {
E 20
					error("Type mismatch in read from non-text file");
					continue;
				}
				/*
				 * var := file ^;
				 */
				if (file != NIL)
D 5
					stkrval(file, NIL , RREQ );
E 5
I 5
D 20
					stklval(file, NIL , LREQ );
E 20
I 20
D 24
					(void) stklval(file, NIL );
E 24
I 24
				    (void) stklval(file, NIL);
E 24
E 20
E 5
				else /* Magic */
D 5
					put(2, O_RV2, input->value[0]);
E 5
I 5
D 6
					put(2, PTR_RV, input->value[0]);
E 6
I 6
D 20
					put(2, PTR_RV, (int)input->value[0]);
E 6
E 5
				put(1, O_FNIL);
				put(2, O_IND, width(filetype));
E 20
I 20
D 24
					(void) put(2, PTR_RV, (int)input->value[0]);
E 24
I 24
				    (void) put(2, PTR_RV, (int)input->value[0]);
E 24
				(void) put(1, O_FNIL);
D 24
				(void) put(2, O_IND, width(filetype));
E 20
				convert(filetype, ap);
				if (isa(ap, "bsci"))
					rangechk(ap, ap);
D 20
				put(2, O_AS, width(ap));
E 20
I 20
				(void) put(2, O_AS, width(ap));
E 24
I 24
				if (isa(filetype, "bcsi")) {
				    int filewidth = width(filetype);

				    switch (filewidth) {
					case 4:
					    (void) put(1, O_IND4);
					    break;
					case 2:
					    (void) put(1, O_IND2);
					    break;
					case 1:
					    (void) put(1, O_IND1);
					    break;
					default:
					    (void) put(2, O_IND, filewidth);
				    }
				    convert(filetype, ap);
				    rangechk(ap, ap);
				    (void) gen(O_AS2, O_AS2,
					    filewidth, width(ap));
				} else {
				    (void) put(2, O_IND, width(filetype));
				    convert(filetype, ap);
				    (void) put(2, O_AS, width(ap));
				}
E 24
E 20
				/*
				 * get(file);
				 */
D 20
				put(1, O_GET);
E 20
I 20
				(void) put(1, O_GET);
E 20
				continue;
			}
			typ = classify(ap);
			op = rdops(typ);
			if (op == NIL) {
				error("Can't read %ss from a text file", clnames[typ]);
				continue;
			}
			if (op != O_READE)
D 20
				put(1, op);
E 20
I 20
				(void) put(1, op);
E 20
			else {
D 6
				put(2, op, listnames(ap));
E 6
I 6
D 20
				put(2, op, (long)listnames(ap));
E 20
I 20
				(void) put(2, op, (long)listnames(ap));
E 20
E 6
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
			/*
			 * Data read is on the stack.
			 * Assign it.
			 */
			if (op != O_READ8 && op != O_READE)
				rangechk(ap, op == O_READC ? ap : nl+T4INT);
D 20
			gen(O_AS2, O_AS2, width(ap),
E 20
I 20
			(void) gen(O_AS2, O_AS2, width(ap),
E 20
				op == O_READ8 ? 8 : op == O_READ4 ? 4 : 2);
		}
		/*
		 * Done with arguments.
		 * Handle readln and
		 * insufficient number of args.
		 */
		if (p->value[0] == O_READLN) {
			if (filetype != nl+T1CHAR)
				error("Can't 'readln' a non text file");
D 20
			put(1, O_READLN);
E 20
I 20
			(void) put(1, O_READLN);
E 20
		}
		else if (argc == 0)
			error("read requires an argument");
		return;

	case O_GET:
	case O_PUT:
		if (argc != 1) {
			error("%s expects one argument", p->symbol);
			return;
		}
D 5
		ap = stkrval(argv[1], NIL , RREQ );
E 5
I 5
D 20
		ap = stklval(argv[1], NIL , LREQ );
E 5
		if (ap == NIL)
E 20
I 20
		ap = stklval(argv->list_node.list, NIL );
		if (ap == NLNIL)
E 20
			return;
		if (ap->class != FILET) {
			error("Argument to %s must be a file, not %s", p->symbol, nameof(ap));
			return;
		}
D 20
		put(1, O_UNIT);
		put(1, op);
E 20
I 20
		(void) put(1, O_UNIT);
		(void) put(1, op);
E 20
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
I 5
		codeoff();
E 5
D 20
		ap = stklval(argv[1], MOD|NOUSE);
E 20
I 20
		ap = stklval(argv->list_node.list, MOD|NOUSE);
E 20
I 5
		codeon();
E 5
D 20
		if (ap == NIL)
E 20
I 20
		if (ap == NLNIL)
E 20
			return;
		if (ap->class != FILET) {
			error("First argument to %s must be a file, not %s", p->symbol, nameof(ap));
			return;
		}
I 5
D 20
		put(2, O_CON24, text(ap) ? 0: width(ap->type));
E 20
I 20
		(void) put(2, O_CON24, text(ap) ? 0: width(ap->type));
E 20
E 5
		if (argc == 2) {
			/*
			 * Optional second argument
			 * is a string name of a
			 * UNIX (R) file to be associated.
			 */
D 20
			al = argv[2];
E 20
I 20
			al = argv->list_node.next;
E 20
I 5
			codeoff();
E 5
D 20
			al = stkrval(al[1], NOFLAGS , RREQ );
E 20
I 20
			al = (struct tnode *) stkrval(al->list_node.list,
					(struct nl *) NOFLAGS , (long) RREQ );
E 20
I 5
			codeon();
E 5
D 20
			if (al == NIL)
E 20
I 20
			if (al == TR_NIL)
E 20
				return;
D 20
			if (classify(al) != TSTR) {
				error("Second argument to %s must be a string, not %s", p->symbol, nameof(al));
E 20
I 20
			if (classify((struct nl *) al) != TSTR) {
				error("Second argument to %s must be a string, not %s", p->symbol, nameof((struct nl *) al));
E 20
				return;
			}
D 5
			strnglen = width(al);
E 5
I 5
D 20
			put(2, O_CON24, width(al));
			al = argv[2];
			al = stkrval(al[1], NOFLAGS , RREQ );
E 20
I 20
			(void) put(2, O_CON24, width((struct nl *) al));
			al = argv->list_node.next;
			al = (struct tnode *) stkrval(al->list_node.list,
					(struct nl *) NOFLAGS , (long) RREQ );
E 20
E 5
		} else {
I 5
D 20
			put(2, O_CON24, 0);
E 5
D 6
			put(2, O_CON24, NIL);
E 6
I 6
			put(2, PTR_CON, NIL);
E 20
I 20
			(void) put(2, O_CON24, 0);
			(void) put(2, PTR_CON, NIL);
E 20
E 6
D 5
			strnglen = 0;
E 5
		}
D 5
		put(2, O_CON24, strnglen);
		put(2, O_CON24, text(ap) ? 0: width(ap->type));
E 5
I 5
D 20
		ap = stklval(argv[1], MOD|NOUSE);
E 5
		put(1, op);
E 20
I 20
		ap = stklval(argv->list_node.list, MOD|NOUSE);
		(void) put(1, op);
E 20
		return;

	case O_NEW:
	case O_DISPOSE:
		if (argc == 0) {
			error("%s expects at least one argument", p->symbol);
			return;
		}
D 20
		ap = stklval(argv[1], op == O_NEW ? ( MOD | NOUSE ) : MOD );
		if (ap == NIL)
E 20
I 20
		ap = stklval(argv->list_node.list,
				op == O_NEW ? ( MOD | NOUSE ) : MOD );
		if (ap == NLNIL)
E 20
			return;
		if (ap->class != PTR) {
			error("(First) argument to %s must be a pointer, not %s", p->symbol, nameof(ap));
			return;
		}
		ap = ap->type;
		if (ap == NIL)
			return;
I 14
		if ((ap->nl_flags & NFILES) && op == O_DISPOSE)
			op = O_DFDISP;
E 14
D 20
		argv = argv[2];
		if (argv != NIL) {
E 20
I 20
		argv = argv->list_node.next;
		if (argv != TR_NIL) {
E 20
			if (ap->class != RECORD) {
				error("Record required when specifying variant tags");
				return;
			}
D 20
			for (; argv != NIL; argv = argv[2]) {
E 20
I 20
			for (; argv != TR_NIL; argv = argv->list_node.next) {
E 20
				if (ap->ptr[NL_VARNT] == NIL) {
					error("Too many tag fields");
					return;
				}
D 20
				if (!isconst(argv[1])) {
E 20
I 20
				if (!isconst(argv->list_node.list)) {
E 20
					error("Second and successive arguments to %s must be constants", p->symbol);
					return;
				}
D 20
				gconst(argv[1]);
E 20
I 20
				gconst(argv->list_node.list);
E 20
				if (con.ctype == NIL)
					return;
D 20
				if (incompat(con.ctype, (ap->ptr[NL_TAG])->type , NIL )) {
E 20
I 20
				if (incompat(con.ctype, (
					ap->ptr[NL_TAG])->type , TR_NIL )) {
E 20
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
D 20
		put(2, op, width(ap));
E 20
I 20
		(void) put(2, op, width(ap));
E 20
		return;

	case O_DATE:
	case O_TIME:
		if (argc != 1) {
			error("%s expects one argument", p->symbol);
			return;
		}
D 20
		ap = stklval(argv[1], MOD|NOUSE);
		if (ap == NIL)
E 20
I 20
		ap = stklval(argv->list_node.list, MOD|NOUSE);
		if (ap == NLNIL)
E 20
			return;
		if (classify(ap) != TSTR || width(ap) != 10) {
			error("Argument to %s must be a alfa, not %s", p->symbol, nameof(ap));
			return;
		}
D 20
		put(1, op);
E 20
I 20
		(void) put(1, op);
E 20
		return;

	case O_HALT:
		if (argc != 0) {
			error("halt takes no arguments");
			return;
		}
D 20
		put(1, op);
		noreach = 1;
E 20
I 20
		(void) put(1, op);
		noreach = TRUE; /* used to be 1 */
E 20
		return;

	case O_ARGV:
		if (argc != 2) {
			error("argv takes two arguments");
			return;
		}
D 20
		ap = stkrval(argv[1], NIL , RREQ );
		if (ap == NIL)
E 20
I 20
		ap = stkrval(argv->list_node.list, NLNIL , (long) RREQ );
		if (ap == NLNIL)
E 20
			return;
		if (isnta(ap, "i")) {
			error("argv's first argument must be an integer, not %s", nameof(ap));
			return;
		}
D 20
		al = argv[2];
		ap = stklval(al[1], MOD|NOUSE);
		if (ap == NIL)
E 20
I 20
		al = argv->list_node.next;
		ap = stklval(al->list_node.list, MOD|NOUSE);
		if (ap == NLNIL)
E 20
			return;
		if (classify(ap) != TSTR) {
			error("argv's second argument must be a string, not %s", nameof(ap));
			return;
		}
D 20
		put(2, op, width(ap));
E 20
I 20
		(void) put(2, op, width(ap));
E 20
		return;

	case O_STLIM:
		if (argc != 1) {
			error("stlimit requires one argument");
			return;
		}
D 20
		ap = stkrval(argv[1], NIL , RREQ );
		if (ap == NIL)
E 20
I 20
		ap = stkrval(argv->list_node.list, NLNIL , (long) RREQ );
		if (ap == NLNIL)
E 20
			return;
		if (isnta(ap, "i")) {
			error("stlimit's argument must be an integer, not %s", nameof(ap));
			return;
		}
		if (width(ap) != 4)
D 20
			put(1, O_STOI);
		put(1, op);
E 20
I 20
			(void) put(1, O_STOI);
		(void) put(1, op);
E 20
		return;

	case O_REMOVE:
		if (argc != 1) {
			error("remove expects one argument");
			return;
		}
I 5
		codeoff();
E 5
D 20
		ap = stkrval(argv[1], NOFLAGS , RREQ );
E 20
I 20
		ap = stkrval(argv->list_node.list, (struct nl *) NOFLAGS,
				(long) RREQ );
E 20
I 5
		codeon();
E 5
D 20
		if (ap == NIL)
E 20
I 20
		if (ap == NLNIL)
E 20
			return;
		if (classify(ap) != TSTR) {
			error("remove's argument must be a string, not %s", nameof(ap));
			return;
		}
D 20
		put(2, O_CON24, width(ap));
I 5
		ap = stkrval(argv[1], NOFLAGS , RREQ );
E 5
		put(1, op);
E 20
I 20
		(void) put(2, O_CON24, width(ap));
		ap = stkrval(argv->list_node.list, (struct nl *) NOFLAGS,
				(long) RREQ );
		(void) put(1, op);
E 20
		return;

	case O_LLIMIT:
		if (argc != 2) {
			error("linelimit expects two arguments");
			return;
		}
D 5
		ap = stklval(argv[1], NOFLAGS|NOUSE);
		if (ap == NIL)
			return;
		if (!text(ap)) {
			error("linelimit's first argument must be a text file, not %s", nameof(ap));
			return;
		}
E 5
D 20
		al = argv[2];
		ap = stkrval(al[1], NIL , RREQ );
E 20
I 20
		al = argv->list_node.next;
		ap = stkrval(al->list_node.list, NLNIL , (long) RREQ );
E 20
		if (ap == NIL)
			return;
		if (isnta(ap, "i")) {
			error("linelimit's second argument must be an integer, not %s", nameof(ap));
			return;
		}
I 5
D 20
		ap = stklval(argv[1], NOFLAGS|NOUSE);
		if (ap == NIL)
E 20
I 20
		ap = stklval(argv->list_node.list, NOFLAGS|NOUSE);
		if (ap == NLNIL)
E 20
			return;
		if (!text(ap)) {
			error("linelimit's first argument must be a text file, not %s", nameof(ap));
			return;
		}
E 5
D 20
		put(1, op);
E 20
I 20
		(void) put(1, op);
E 20
		return;
	case O_PAGE:
		if (argc != 1) {
			error("page expects one argument");
			return;
		}
D 5
		ap = stkrval(argv[1], NIL , RREQ );
E 5
I 5
D 20
		ap = stklval(argv[1], NIL , LREQ );
E 5
		if (ap == NIL)
E 20
I 20
		ap = stklval(argv->list_node.list, NIL );
		if (ap == NLNIL)
E 20
			return;
		if (!text(ap)) {
			error("Argument to page must be a text file, not %s", nameof(ap));
			return;
		}
D 20
		put(1, O_UNIT);
		put(1, op);
E 20
I 20
		(void) put(1, O_UNIT);
		(void) put(1, op);
E 20
		return;

I 12
	case O_ASRT:
		if (!opt('t'))
			return;
		if (argc == 0 || argc > 2) {
			error("Assert expects one or two arguments");
			return;
		}
		if (argc == 2) {
			/*
			 * Optional second argument is a string specifying
			 * why the assertion failed.
			 */
D 20
			al = argv[2];
			al = stkrval(al[1], NIL , RREQ );
			if (al == NIL)
E 20
I 20
			al = argv->list_node.next;
			al1 =  stkrval(al->list_node.list, NLNIL , (long) RREQ );
			if (al1 == NIL)
E 20
				return;
D 20
			if (classify(al) != TSTR) {
				error("Second argument to assert must be a string, not %s", nameof(al));
E 20
I 20
			if (classify(al1) != TSTR) {
				error("Second argument to assert must be a string, not %s", nameof(al1));
E 20
				return;
			}
		} else {
D 20
			put(2, PTR_CON, NIL);
E 20
I 20
			(void) put(2, PTR_CON, NIL);
E 20
		}
D 20
		ap = stkrval(argv[1], NIL , RREQ );
E 20
I 20
		ap = stkrval(argv->list_node.list, NLNIL , (long) RREQ );
E 20
		if (ap == NIL)
			return;
		if (isnta(ap, "b"))
			error("Assert expression must be Boolean, not %ss", nameof(ap));
D 20
		put(1, O_ASRT);
E 20
I 20
		(void) put(1, O_ASRT);
E 20
		return;

E 12
	case O_PACK:
		if (argc != 3) {
			error("pack expects three arguments");
			return;
		}
		pu = "pack(a,i,z)";
D 6
		pua = (al = argv)[1];
		pui = (al = al[2])[1];
		puz = (al = al[2])[1];
E 6
I 6
D 20
		pua = argv[1];
		al = argv[2];
		pui = al[1];
		alv = al[2];
		puz = alv[1];
E 20
I 20
		pua = argv->list_node.list;
		al = argv->list_node.next;
		pui = al->list_node.list;
		alv = al->list_node.next;
		puz = alv->list_node.list;
E 20
E 6
		goto packunp;
	case O_UNPACK:
		if (argc != 3) {
			error("unpack expects three arguments");
			return;
		}
		pu = "unpack(z,a,i)";
D 6
		puz = (al = argv)[1];
		pua = (al = al[2])[1];
		pui = (al = al[2])[1];
E 6
I 6
D 20
		puz = argv[1];
		al = argv[2];
		pua = al[1];
		alv = al[2];
		pui = alv[1];
E 20
I 20
		puz = argv->list_node.list;
		al = argv->list_node.next;
		pua = al->list_node.list;
		alv = al->list_node.next;
		pui = alv->list_node.list;
E 20
E 6
packunp:
D 5
		ap = stkrval((int *) pui, NLNIL , RREQ );
		if (ap == NIL)
			return;
E 5
I 5
		codeoff();
E 5
		ap = stklval(pua, op == O_PACK ? NOFLAGS : MOD|NOUSE);
I 5
D 20
		al = (struct nl *) stklval(puz, op == O_UNPACK ? NOFLAGS : MOD|NOUSE);
E 20
I 20
		al1 = stklval(puz, op == O_UNPACK ? NOFLAGS : MOD|NOUSE);
E 20
		codeon();
E 5
		if (ap == NIL)
			return;
		if (ap->class != ARRAY) {
			error("%s requires a to be an unpacked array, not %s", pu, nameof(ap));
			return;
		}
D 5
		al = (struct nl *) stklval(puz, op == O_UNPACK ? NOFLAGS : MOD|NOUSE);
E 5
D 20
		if (al->class != ARRAY) {
E 20
I 20
		if (al1->class != ARRAY) {
E 20
			error("%s requires z to be a packed array, not %s", pu, nameof(ap));
			return;
		}
D 20
		if (al->type == NIL || ap->type == NIL)
E 20
I 20
		if (al1->type == NIL || ap->type == NIL)
E 20
			return;
D 20
		if (al->type != ap->type) {
E 20
I 20
		if (al1->type != ap->type) {
E 20
			error("%s requires a and z to be arrays of the same type", pu, nameof(ap));
			return;
		}
D 20
		k = width(al);
E 20
I 20
		k = width(al1);
E 20
		itemwidth = width(ap->type);
		ap = ap->chain;
D 20
		al = al->chain;
		if (ap->chain != NIL || al->chain != NIL) {
E 20
I 20
		al1 = al1->chain;
		if (ap->chain != NIL || al1->chain != NIL) {
E 20
			error("%s requires a and z to be single dimension arrays", pu);
			return;
		}
D 20
		if (ap == NIL || al == NIL)
E 20
I 20
		if (ap == NIL || al1 == NIL)
E 20
			return;
		/*
D 20
		 * al is the range for z i.e. u..v
E 20
I 20
		 * al1 is the range for z i.e. u..v
E 20
		 * ap is the range for a i.e. m..n
		 * i will be n-m+1
		 * j will be v-u+1
		 */
		i = ap->range[1] - ap->range[0] + 1;
D 20
		j = al->range[1] - al->range[0] + 1;
E 20
I 20
		j = al1->range[1] - al1->range[0] + 1;
E 20
		if (i < j) {
D 20
			error("%s cannot have more elements in a (%d) than in z (%d)", pu, j, i);
E 20
I 20
			error("%s cannot have more elements in a (%d) than in z (%d)", pu, (char *) j, (char *) i);
E 20
			return;
		}
		/*
		 * get n-m-(v-u) and m for the interpreter
		 */
		i -= j;
		j = ap->range[0];
D 5
		put(5, op, itemwidth , j, i, k);
E 5
I 5
D 20
		put(2, O_CON24, k);
		put(2, O_CON24, i);
		put(2, O_CON24, j);
		put(2, O_CON24, itemwidth);
		al = (struct nl *) stklval(puz, op == O_UNPACK ? NOFLAGS : MOD|NOUSE);
E 20
I 20
		(void) put(2, O_CON24, k);
		(void) put(2, O_CON24, i);
		(void) put(2, O_CON24, j);
		(void) put(2, O_CON24, itemwidth);
		al1 = stklval(puz, op == O_UNPACK ? NOFLAGS : MOD|NOUSE);
E 20
		ap = stklval(pua, op == O_PACK ? NOFLAGS : MOD|NOUSE);
D 20
		ap = stkrval((int *) pui, NLNIL , RREQ );
E 20
I 20
		ap = stkrval(pui, NLNIL , (long) RREQ );
E 20
		if (ap == NIL)
			return;
D 20
		put(1, op);
E 20
I 20
		(void) put(1, op);
E 20
E 5
		return;
	case 0:
D 12
		error("%s is an unimplemented 6400 extension", p->symbol);
E 12
I 12
		error("%s is an unimplemented extension", p->symbol);
E 12
		return;

	default:
		panic("proc case");
	}
}
#endif OBJ
E 1
