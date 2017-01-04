h05075
s 00007/00001/00080
d D 5.1 85/06/07 23:37:11 kre 10 9
c Add copyright
e
s 00000/00001/00081
d D 1.7 85/05/21 19:25:56 libs 9 8
c make unneeded globals LOCAL (static); move several routines to .c
c in which they are called.
e
s 00003/00001/00079
d D 1.6 85/02/19 22:28:18 libs 8 7
c Add warning comment re changes to the defines.
e
s 00024/00000/00056
d D 1.5 85/02/14 22:58:32 libs 7 4
c Speed up dofio by replacing type_f() function call by array reference.
e
s 00022/00000/00056
d R 1.5 85/02/14 22:56:14 libs 6 4
c Speed up dofio by replacing type_f() function call by array reference.
e
s 00002/00000/00056
d R 1.5 85/02/14 22:21:06 libs 5 4
c Speed up dofio by replacing type_f() function by array.
e
s 00006/00003/00050
d D 1.4 85/02/14 21:28:59 libs 4 3
c Recognize compiled formats, change syl[] members to shorts and 
c don't generate STACK operators for rep. factors for editing 
c terms so compiled formats will be shorter & execute faster.
e
s 00002/00002/00051
d D 1.3 85/01/29 10:24:55 dlw 3 2
c combined BN & BZ; added B. DLW
e
s 00001/00001/00052
d D 1.2 84/06/21 10:29:47 ralph 2 1
c changes from dlw to fix I/O hanging on illegal fmt specs.
e
s 00053/00000/00000
d D 1.1 81/02/18 18:22:17 dlw 1 0
c date and time created 81/02/18 18:22:17 by dlw
e
u
U
t
T
I 1
/*
D 10
char id_format[] = "%W%";
E 10
I 10
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 10
 *
I 10
 *	%W% (Berkeley) %G%
 */

/*
E 10
 * format parser definitions
 */

struct syl
{
D 4
	int op,p1,p2,p3;
E 4
I 4
	short op,p1,p2,rpcnt;
E 4
};

I 7
/*	do NOT change this defines or add new ones without
D 8
 *	changing the value of the follow define for OP_TYPE_TAB
E 8
I 8
 *	changing the value of the following define for OP_TYPE_TAB.
 *	change format.h both in the compiler and libI77 simultaneously.
E 8
 */
I 8

E 8

E 7
#define RET	1
#define REVERT 	2
#define GOTO 	3
#define X 	4
#define SLASH 	5
#define STACK 	6
#define I 	7
#define ED 	8
#define NED 	9
#define IM 	10
#define APOS 	11
#define H 	12
#define TL 	13
#define TR 	14
#define T 	15
#define COLON 	16
#define S 	17
#define SP 	18
#define SS 	19
#define P 	20
D 3
#define BN 	21
#define BZ 	22
E 3
I 3
#define BNZ 	21
#define B 	22
E 3
#define F 	23
#define E 	24
#define EE 	25
#define D 	26
#define DE	27		/*** NOT STANDARD FORTRAN ***/
#define G 	28
#define GE 	29
#define L 	30
#define A 	31
#define AW	32
#define R	33		/*** NOT STANDARD FORTRAN ***/
#define DOLAR	34		/*** NOT STANDARD FORTRAN ***/
#define SU	35		/*** NOT STANDARD FORTRAN ***/
I 7

#define LAST_TERM SU

/* OP_TYPE_TAB is used in dofio.c .
	  Each value corresponds to a value above, and must be
	  ED for editing terms: I,IM,F,E,EE,D,DE,G,GE,L,A,AW
	  NED for nonediting terms which change the I/O stream:
			X,SLASH,APOS,H,TL,TR,T
	  and just the value of the term for all others.

	  E.g. SP is defined above as 17, so the element 17 of
	  OP_TYPE_TAB (counting from zero) is SP since SP does not
	  read or write data;
	  IM is defined as 10 so the element 10 of OP_TYPE_TAB
	  is ED since IM edits data from the i/o list.
 */
#define OP_TYPE_TAB {0, RET, REVERT, GOTO, NED, NED, STACK, ED, ED, NED, \
			ED, NED, NED, NED, NED, NED, COLON, S, SP, SS, P, \
			BNZ, B, ED, ED, ED, ED, ED, ED, ED, ED, ED, ED, \
			R, DOLAR, SU }
E 7

I 2
#define	FMTUNKN	-1
E 2
#define FMTOK	1
#define FMTERR	0

D 4
extern struct syl syl[];
extern int pc,parenlvl,revloc;
E 4
I 4
#define FMT_COMP 0x101		/* indicates pre-compiled formats */

extern struct syl *syl_ptr;
D 9
extern int parenlvl,revloc;
E 9
extern short pc;
E 4
D 2

E 2
E 1
