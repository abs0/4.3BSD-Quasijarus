h39177
s 00006/00002/00139
d D 5.1 85/04/30 14:05:12 dist 6 5
c Add copyright
e
s 00013/00009/00128
d D 4.5 83/06/09 11:31:54 rrh 5 4
c ACCV turned into ACCR by a cheat, since all fields have same 
c "permission" as read access
e
s 00014/00001/00123
d D 4.4 83/05/19 07:30:00 rrh 4 3
c add ACCV definitions to augment ACCA definitions (ACCV for 
c fields in registers)
e
s 00000/00000/00124
d D 4.3 82/02/14 16:48:00 rrh 3 2
c Definitions for data types.
e
s 00000/00000/00124
d D 4.2 82/02/14 16:47:26 rrh 2 1
c Synchronizing this new file to release 4.2
e
s 00124/00000/00000
d D 4.1 82/02/14 16:47:07 rrh 1 0
c date and time created 82/02/14 16:47:07 by rrh
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
 *	Argument data types
 *
 *	If you change these definitions, you must also change the tables
 *	in assizetab.c
 */
#define	TYPB		000	/* byte integer */
#define	TYPW		001	/* word integer */
#define	TYPL		002	/* long integer */
#define	TYPQ		003	/* quad integer */
#define	TYPO		004	/* octa integer */
#define	TYPF		005	/* F float */
#define	TYPD		006	/* D float */
#define	TYPG		007	/* G float */
#define	TYPH		010	/* H float */
#define	TYPUNPACKED	011	/* when unpacked into mantissa & exponent */
#define	TYPNONE		012	/* when nothing */
#define	TYPLG		4	/* number of bits the above take up */

#define	TYPMASK	((1<<TYPLG)-1)	/* the mask (assumes 2's comp arith) */
/*
 *	Constructors and extractors for argument access kinds and types
 */
#define A_CONS(access, type)	((access) | (type))
#define	A_ACCEXT(consed)	((consed) & (TYPMASK << TYPLG))
#define	A_TYPEXT(consed)	((consed) & TYPMASK)

/*
 * Argument access types used to test validity of operands to operators
 */
#define	ACCR	(1<<TYPLG)			/* read */
#define	ACCW	(2<<TYPLG)			/* write */
#define	ACCB	(4<<TYPLG)			/* branch displacement */
#define	ACCA	(8<<TYPLG)			/* address only */
I 4
#define	ACCV	(8<<TYPLG)			/* address only */
E 4
#define	ACCM	(ACCR | ACCW)			/* modify */
#define	ACCI	(ACCB | ACCR)			/* XFC code */

#define ACCESSMASK	(ACCA | ACCR | ACCW | ACCB)	/* the mask */

/*
 *	Construction of TYPX and ACCX, to make the instrs table
 *	easy to use and read.
 */
/*
D 4
 *	For address
E 4
I 4
 *	For real memory address
E 4
 */
#define	A_AB	A_CONS(ACCA, TYPB)
#define	A_AW	A_CONS(ACCA, TYPW)
#define	A_AL	A_CONS(ACCA, TYPL)
#define	A_AQ	A_CONS(ACCA, TYPQ)
#define	A_AO	A_CONS(ACCA, TYPO)
#define	A_AF	A_CONS(ACCA, TYPF)
#define	A_AD	A_CONS(ACCA, TYPD)
#define	A_AG	A_CONS(ACCA, TYPG)
#define	A_AH	A_CONS(ACCA, TYPH)
I 4
/*
 *	For real memory addresses, or register addresses [sic]
I 5
 *
 *	CHEAT! we just call these read access, since
 *	registers are allowed. All field instruction, except insv,
 *	are are read access fields.
E 5
 */
D 5
#define	A_VB	A_CONS(ACCV, TYPB)
#define	A_VW	A_CONS(ACCV, TYPW)
#define	A_VL	A_CONS(ACCV, TYPL)
#define	A_VQ	A_CONS(ACCV, TYPQ)
#define	A_VO	A_CONS(ACCV, TYPO)
#define	A_VF	A_CONS(ACCV, TYPF)
#define	A_VD	A_CONS(ACCV, TYPD)
#define	A_VG	A_CONS(ACCV, TYPG)
#define	A_VH	A_CONS(ACCV, TYPH)
E 5
I 5
#define	A_VB	A_CONS(ACCR, TYPB)
#define	A_VW	A_CONS(ACCR, TYPW)
#define	A_VL	A_CONS(ACCR, TYPL)
#define	A_VQ	A_CONS(ACCR, TYPQ)
#define	A_VO	A_CONS(ACCR, TYPO)
#define	A_VF	A_CONS(ACCR, TYPF)
#define	A_VD	A_CONS(ACCR, TYPD)
#define	A_VG	A_CONS(ACCR, TYPG)
#define	A_VH	A_CONS(ACCR, TYPH)
E 5
E 4
/*
 *	For branch displacement
 */
#define	A_BB	A_CONS(ACCB, TYPB)
#define	A_BW	A_CONS(ACCB, TYPW)
/*
 *	For modification
 */
#define	A_MB	A_CONS(ACCM, TYPB)
#define	A_MW	A_CONS(ACCM, TYPW)
#define	A_ML	A_CONS(ACCM, TYPL)
#define	A_MF	A_CONS(ACCM, TYPF)
#define	A_MD	A_CONS(ACCM, TYPD)
#define	A_MG	A_CONS(ACCM, TYPG)
#define	A_MH	A_CONS(ACCM, TYPH)
/*
 *	For reading
 */
#define	A_RB	A_CONS(ACCR, TYPB)
#define	A_RW	A_CONS(ACCR, TYPW)
#define	A_RL	A_CONS(ACCR, TYPL)
#define	A_RQ	A_CONS(ACCR, TYPQ)
#define	A_RO	A_CONS(ACCR, TYPO)
#define	A_RF	A_CONS(ACCR, TYPF)
#define	A_RD	A_CONS(ACCR, TYPD)
#define	A_RG	A_CONS(ACCR, TYPG)
#define	A_RH	A_CONS(ACCR, TYPH)
/*
 *	For writing
 */
#define	A_WB	A_CONS(ACCW, TYPB)
#define	A_WW	A_CONS(ACCW, TYPW)
#define	A_WL	A_CONS(ACCW, TYPL)
#define	A_WQ	A_CONS(ACCW, TYPQ)
#define	A_WO	A_CONS(ACCW, TYPO)
#define	A_WF	A_CONS(ACCW, TYPF)
#define	A_WD	A_CONS(ACCW, TYPD)
#define	A_WG	A_CONS(ACCW, TYPG)
#define	A_WH	A_CONS(ACCW, TYPH)

#ifndef INSTTAB
/*
 *	Define what the entries in the table look like.
 *	This is only used for adb and sdb; not for as.
 */
#define	INSTTAB
struct insttab{
	char	*iname;
	u_char	eopcode;
	u_char	popcode;
	char	nargs;
	u_char	argtype[6];
} insttab[];

#define OP(name,eopcode,popdcode,nargs,a1,a2,a3,a4,a5,a6) {name,eopcode,popdcode,nargs,a1,a2,a3,a4,a5,a6}

#endif INSTTAB

/*
 *	Definitions for the escape bytes
 */
#define	CORE	0
#define	NEW	1
#define	ESCD	0xfd
#define	ESCF	0xff
E 1
