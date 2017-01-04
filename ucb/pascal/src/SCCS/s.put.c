h14831
s 00001/00001/00790
d D 5.2 86/11/12 10:23:11 mckusick 32 31
c eliminate unnecessary evening
e
s 00007/00003/00784
d D 5.1 85/06/18 18:04:03 mckusick 31 30
c Add copyright
e
s 00000/00000/00787
d D 2.1 84/02/08 20:52:59 aoki 30 29
c synchronize to version 2
e
s 00001/00001/00786
d D 1.25 83/10/11 06:38:46 thien 29 27
c fixed for lint
e
s 00001/00001/00786
d R 1.25 83/10/11 06:37:28 thien 28 27
c fixed idkeyword
e
s 00045/00031/00742
d D 1.24 83/10/11 06:33:56 thien 27 23
c fixes for lint
e
s 00000/00000/00787
d R 1.26 83/10/10 10:26:40 thien 26 25
c 
e
s 00000/00000/00787
d R 1.25 83/09/19 07:00:17 thien 25 24
c Restoring to unlinted version
e
s 00044/00030/00743
d R 1.24 83/08/19 05:01:12 thien 24 23
c The changes were made to allow successful linting
e
s 00007/00003/00766
d D 1.23 83/04/08 18:45:32 mckusick 23 22
c break up two character "short" constants into explicit
c shifts of two one character constants (DEC11 specific)
e
s 00020/00029/00749
d D 1.22 83/02/09 13:52:59 mckusick 22 21
c range checks are now hoisted out of loops
e
s 00003/00008/00775
d D 1.21 83/02/01 20:18:09 peter 21 20
c make machine independent during port to the mc68000.
e
s 00008/00004/00775
d D 1.20 83/01/21 18:09:03 mckusick 20 19
c byte reversal botches
e
s 00008/00002/00771
d D 1.19 83/01/12 21:09:43 peter 19 18
c port to the mc68000; pass 1.
e
s 00001/00000/00772
d D 1.18 82/08/29 21:28:14 mckusick 18 17
c remove restriction on files in dynamic structures
e
s 00008/00008/00764
d D 1.17 82/08/26 22:35:36 mckusick 17 16
c convert namelist structure to use unions
e
s 00005/00001/00767
d D 1.16 82/04/27 15:42:25 mckusick 16 15
c check for zero length assignments
e
s 00032/00016/00736
d D 1.15 81/07/22 19:11:47 mckusic 15 14
c put long operands into sub-opcodes for FOR, RANG, SUCC, and PRED
e
s 00004/00002/00748
d D 1.14 81/03/26 18:05:52 peter 14 13
c printing of relative jumps for FOR4[UD].
e
s 00015/00015/00735
d D 1.13 81/03/20 14:27:08 peter 13 12
c use cgenflg consistently; take out )#'s on pi code.
e
s 00000/00005/00750
d D 1.12 81/03/18 21:18:03 mckusic 12 11
c mods for new formal routine syntax
e
s 00001/00000/00754
d D 1.11 81/03/10 00:53:17 mckusic 11 10
c onyx optimizations
e
s 00155/00099/00599
d D 1.10 81/03/08 19:27:02 mckusic 10 9
c merge in onyx changes
e
s 00018/00006/00680
d D 1.9 81/01/24 16:21:55 mckusic 9 8
c optimize AS to AS2, AS4, and AS8
e
s 00001/00001/00685
d D 1.8 81/01/22 21:03:53 peter 8 7
c put in OBJ in endif to match
e
s 00011/00004/00675
d D 1.7 81/01/16 18:00:27 mckusic 7 6
c convert pi for loop construct to look like pc for loop
e
s 00020/00000/00659
d D 1.6 81/01/10 17:00:44 mckusic 6 5
c convert to "fp", "ap" type display; fix SUCC and PRED
e
s 00000/00002/00659
d D 1.5 81/01/06 17:17:40 mckusic 5 4
c modify to allow use of px written in `C' and the use of libpc
e
s 00001/00001/00660
d D 1.4 80/12/12 00:00:29 mckusic 4 3
c fix printout bug in listing REL*
e
s 00006/00002/00655
d D 1.3 80/10/03 01:09:23 peter 3 2
c Implement formal functions and procedures
e
s 00001/00001/00656
d D 1.2 80/09/19 19:25:42 peter 2 1
c use only low byte of (signed) 1 byte case labels
e
s 00657/00000/00000
d D 1.1 80/08/27 19:56:09 peter 1 0
c date and time created 80/08/27 19:56:09 by peter
e
u
U
t
T
I 1
D 31
/* Copyright (c) 1979 Regents of the University of California */
E 31
I 31
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 31

D 10
static	char sccsid[] = "%Z%%M% %I% %G%";
E 10
I 10
D 27
static char sccsid[] = "%Z%%M% %I% %G%";
E 27
I 27
#ifndef lint
D 29
static char sccsid[] = "@(#)put.c 1.24 8/19/83";
E 29
I 29
D 31
static char sccsid[] = "%W%	(Berkeley)	%E%";
E 29
#endif
E 31
I 31
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 31
E 27
E 10

#include "whoami.h"
#include "opcode.h"
#include "0.h"
#include "objfmt.h"
#ifdef PC
#   include	"pc.h"
I 21
#   include	"align.h"
E 21
D 27
#endif PC
E 27
I 27
#else
    short	*obufp	= obuf;
#endif
E 27

D 27
short	*obufp	= obuf;

E 27
/*
 * If DEBUG is defined, include the table
 * of the printing opcode names.
 */
#ifdef DEBUG
#include "OPnames.h"
#endif

#ifdef OBJ
/*
 * Put is responsible for the interpreter equivalent of code
 * generation.  Since the interpreter is specifically designed
 * for Pascal, little work is required here.
 */
I 27
/*VARARGS*/
E 27
put(a)
{
	register int *p, i;
	register char *cp;
I 10
	register short *sp;
	register long *lp;
E 10
D 27
	int n, subop, suboppr, op, oldlc, w;
E 27
I 27
	int n, subop, suboppr, op, oldlc;
E 27
	char *string;
	static int casewrd;

	/*
	 * It would be nice to do some more
	 * optimizations here.  The work
	 * done to collapse offsets in lval
	 * should be done here, the IFEQ etc
	 * relational operators could be used
	 * etc.
	 */
D 27
	oldlc = lc;
E 27
I 27
	oldlc = (int) lc; /* its either this or change put to return a char * */
E 27
D 13
	if (cgenflg < 0)
E 13
I 13
	if ( !CGENNING )
E 13
		/*
		 * code disabled - do nothing
		 */
		return (oldlc);
	p = &a;
	n = *p++;
D 10
	suboppr = subop = (*p>>8) & 0377;
E 10
I 10
	suboppr = subop = (*p >> 8) & 0377;
E 10
	op = *p & 0377;
	string = 0;
#ifdef DEBUG
	if ((cp = otext[op]) == NIL) {
		printf("op= %o\n", op);
		panic("put");
	}
#endif
	switch (op) {
		case O_ABORT:
			cp = "*";
			break;
I 9
		case O_AS:
			switch(p[1]) {
I 16
			case 0:
				break;
E 16
			case 2:
				op = O_AS2;
I 16
				n = 1;
E 16
				break;
			case 4:
				op = O_AS4;
I 16
				n = 1;
E 16
				break;
			case 8:
				op = O_AS8;
I 16
				n = 1;
E 16
				break;
			default:
				goto pack;
			}
D 16
			n = 1;
E 16
D 10
			cp = otext[op];
E 10
I 10
#			ifdef DEBUG
				cp = otext[op];
#			endif DEBUG
E 10
			break;
I 22
		case O_FOR1U:
		case O_FOR2U:
		case O_FOR4U:
		case O_FOR1D:
		case O_FOR2D:
		case O_FOR4D:
			/* relative addressing */
			p[1] -= ( unsigned ) lc + sizeof(short);
			/* try to pack the jump */
			if (p[1] <= 127 && p[1] >= -128) {
				suboppr = subop = p[1];
				p++;
				n--;
			} else {
				/* have to allow for extra displacement */
				p[1] -= sizeof(short);
			}
			break;
E 22
I 10
		case O_CONG:
		case O_LVCON:
		case O_CON:
E 10
E 9
		case O_LINO:
D 9
/*****
			if (line == codeline)
				return (oldlc);
			codeline = line;
*****/
E 9
		case O_NEW:
		case O_DISPOSE:
I 18
		case O_DFDISP:
E 18
D 9
		case O_AS:
E 9
		case O_IND:
D 10
		case O_LVCON:
		case O_CON:
E 10
		case O_OFF:
		case O_INX2:
		case O_INX4:
		case O_CARD:
		case O_ADDT:
		case O_SUBT:
		case O_MULT:
		case O_IN:
		case O_CASE1OP:
		case O_CASE2OP:
		case O_CASE4OP:
I 3
		case O_FRTN:
E 3
		case O_WRITES:
I 11
		case O_WRITEC:
E 11
		case O_WRITEF:
		case O_MAX:
		case O_MIN:
D 5
		case O_PACK:
		case O_UNPACK:
E 5
		case O_ARGV:
		case O_CTTOT:
		case O_INCT:
		case O_RANG2:
		case O_RSNG2:
		case O_RANG42:
		case O_RSNG42:
I 6
		case O_SUCC2:
		case O_SUCC24:
		case O_PRED2:
		case O_PRED24:
E 6
			if (p[1] == 0)
				break;
		case O_CON2:
		case O_CON24:
I 9
		pack:
E 9
D 22
			if (p[1] < 128 && p[1] >= -128) {
E 22
I 22
			if (p[1] <= 127 && p[1] >= -128) {
E 22
				suboppr = subop = p[1];
				p++;
				n--;
				if (op == O_CON2) {
					op = O_CON1;
D 10
					cp = otext[O_CON1];
E 10
I 10
#					ifdef DEBUG
						cp = otext[O_CON1];
#					endif DEBUG
E 10
				}
				if (op == O_CON24) {
					op = O_CON14;
D 10
					cp = otext[O_CON14];
E 10
I 10
#					ifdef DEBUG
						cp = otext[O_CON14];
#					endif DEBUG
E 10
				}
			}
			break;
		case O_CON8:
		    {
D 27
			short	*sp = &p[1];
E 27
I 27
			short	*sp = (short *) (&p[1]);
E 27

#ifdef	DEBUG
			if ( opt( 'k' ) )
D 10
			    printf ( ")#%5d\tCON8\t%10.3f\n" ,
E 10
I 10
D 13
			    printf ( ")#%5d\tCON8\t%22.14e\n" ,
E 13
I 13
			    printf ( "%5d\tCON8\t%22.14e\n" ,
E 13
E 10
					lc - HEADER_BYTES ,
					* ( ( double * ) &p[1] ) );
#endif
D 10
			word ( op );
E 10
I 10
#			ifdef DEC11
			    word(op);
#			else
			    word(op << 8);
#			endif DEC11
E 10
			for ( i = 1 ; i <= 4 ; i ++ )
			    word ( *sp ++ );
			return ( oldlc );
		    }
		default:
			if (op >= O_REL2 && op <= O_REL84) {
D 4
				if ((i = (subop >> 1) * 5 ) >= 30)
E 4
I 4
				if ((i = (subop >> INDX) * 5 ) >= 30)
E 4
					i -= 30;
				else
					i += 2;
#ifdef DEBUG
				string = &"IFEQ\0IFNE\0IFLT\0IFGT\0IFLE\0IFGE"[i];
#endif
				suboppr = 0;
			}
			break;
		case O_IF:
		case O_TRA:
/*****
			codeline = 0;
*****/
I 7
			/* relative addressing */
			p[1] -= ( unsigned ) lc + sizeof(short);
			break;
E 7
D 22
		case O_FOR1U:
		case O_FOR2U:
D 7
		case O_FOR4U:
E 7
		case O_FOR1D:
		case O_FOR2D:
I 15
			/* sub opcode optimization */
			if (p[1] < 128 && p[1] >= -128 && p[1] != 0) {
				suboppr = subop = p[1];
				p++;
				n--;
			}
E 15
D 7
		case O_FOR4D:
E 7
			/* relative addressing */
D 7
			p[1] -= ( unsigned ) lc + 2;
E 7
I 7
D 15
			p[3] -= ( unsigned ) lc + 3 * sizeof(short);
E 15
I 15
			p[n - 1] -= ( unsigned ) lc + (n - 1) * sizeof(short);
E 15
E 7
			break;
E 22
D 10
		case O_CONG:
			i = p[1];
			cp = * ( ( char ** ) &p[2] ) ;
#ifdef DEBUG
			if (opt('k'))
				printf(")#%5d\tCONG:%d\t%s\n",
					lc - HEADER_BYTES, i, cp);
#endif
			if (i <= 127)
				word(O_CON | i << 8);
			else {
				word(O_CON);
				word(i);
			}
			while (i > 0) {
				w = *cp ? *cp++ : ' ';
				w |= (*cp ? *cp++ : ' ') << 8;
				word(w);
				i -= 2;
			}
			return (oldlc);
E 10
		case O_CONC:
#ifdef DEBUG
			(string = "'x'")[1] = p[1];
#endif
			suboppr = 0;
			op = O_CON1;
D 10
			cp = otext[O_CON1];
E 10
I 10
#			ifdef DEBUG
				cp = otext[O_CON1];
#			endif DEBUG
E 10
			subop = p[1];
			goto around;
		case O_CONC4:
#ifdef DEBUG
			(string = "'x'")[1] = p[1];
#endif
			suboppr = 0;
			op = O_CON14;
			subop = p[1];
			goto around;
		case O_CON1:
		case O_CON14:
			suboppr = subop = p[1];
around:
			n--;
			break;
		case O_CASEBEG:
			casewrd = 0;
			return (oldlc);
		case O_CASEEND:
			if ((unsigned) lc & 1) {
				lc--;
				word(casewrd);
			}
			return (oldlc);
		case O_CASE1:
#ifdef DEBUG
			if (opt('k'))
D 13
				printf(")#%5d\tCASE1\t%d\n"
E 13
I 13
				printf("%5d\tCASE1\t%d\n"
E 13
D 10
					, lc - HEADER_BYTES
					, ( int ) *( ( long * ) &p[1] ) );
E 10
I 10
					, lc - HEADER_BYTES, p[1]);
E 10
#endif
			/*
			 * this to build a byte size case table 
			 * saving bytes across calls in casewrd
			 * so they can be put out by word()
			 */
			lc++;
			if ((unsigned) lc & 1)
D 2
				casewrd = *( ( long * ) &p[1] );
E 2
I 2
D 10
				casewrd = *( ( long * ) &p[1] ) & 0377;
E 10
I 10
#				ifdef DEC11
				    casewrd = p[1] & 0377;
#				else
				    casewrd = (p[1] & 0377) << 8;
#				endif DEC11
E 10
E 2
			else {
				lc -= 2;
D 10
				word (   casewrd
				       | ( ( int ) *( ( long * ) &p[1] ) << 8 ) );
E 10
I 10
#				ifdef DEC11
				    word(((p[1] & 0377) << 8) | casewrd);
#				else
				    word((p[1] & 0377) | casewrd);
#				endif DEC11
E 10
			}
			return (oldlc);
		case O_CASE2:
#ifdef DEBUG
			if (opt('k'))
D 13
				printf(")#%5d\tCASE2\t%d\n"
E 13
I 13
				printf("%5d\tCASE2\t%d\n"
E 13
D 10
					, lc - HEADER_BYTES
					, ( int ) *( ( long * ) &p[1] ) );
E 10
I 10
					, lc - HEADER_BYTES , p[1]);
E 10
#endif
D 10
			word( ( short ) *( ( long * ) &p[1] ) );
E 10
I 10
			word(p[1]);
E 10
			return (oldlc);
I 15
D 22
		case O_FOR4U:
		case O_FOR4D:
			/* sub opcode optimization */
			lp = (long *)&p[1];
			if (*lp < 128 && *lp >= -128 && *lp != 0) {
				suboppr = subop = *lp;
				p += (sizeof(long) / sizeof(int));
				n--;
			}
			/* relative addressing */
			p[1 + (n - 2) * (sizeof(long) / sizeof(int))] -=
			    (unsigned)lc + (sizeof(short) +
			    (n - 2) * sizeof(long));
			goto longgen;
E 22
E 15
D 3
		case O_POP:
E 3
I 3
D 12
		case O_FCALL:
D 10
			if (p[1] == 0)
E 10
I 10
			lp = (long *)&p[1];
			if (*lp == 0)
E 10
				goto longgen;
			/* and fall through */
E 12
E 3
		case O_PUSH:
D 10
			if (p[1] == 0)
E 10
I 10
			lp = (long *)&p[1];
			if (*lp == 0)
E 10
				return (oldlc);
D 10
			if (p[1] < 128 && p[1] >= -128) {
				suboppr = subop = p[1];
E 10
I 10
D 15
			if (*lp < 128 && *lp >= -128) {
E 15
I 15
			/* and fall through */
		case O_RANG4:
		case O_RANG24:
		case O_RSNG4:
		case O_RSNG24:
		case O_SUCC4:
		case O_PRED4:
			/* sub opcode optimization */
			lp = (long *)&p[1];
			if (*lp < 128 && *lp >= -128 && *lp != 0) {
E 15
				suboppr = subop = *lp;
E 10
D 15
				p++;
E 15
I 15
				p += (sizeof(long) / sizeof(int));
E 15
				n--;
D 15
				break;
E 15
			}
			goto longgen;
I 7
D 15
		case O_FOR4U:
		case O_FOR4D:
			/* relative addressing */
D 10
			p[3] -= ( unsigned ) lc +
				(sizeof(short) + 2 * sizeof(long));
E 10
I 10
			p[1 + 2 * (sizeof(long) / sizeof(int))] -=
			    (unsigned)lc + (sizeof(short) + 2 * sizeof(long));
E 10
			goto longgen;
E 15
E 7
		case O_TRA4:
		case O_CALL:
I 3
		case O_FSAV:
E 3
		case O_GOTO:
D 3
		case O_TRACNT:
E 3
		case O_NAM:
		case O_READE:
			/* absolute long addressing */
D 10
			p[1] -= HEADER_BYTES;
E 10
I 10
			lp = (long *)&p[1];
			*lp -= HEADER_BYTES;
E 10
			goto longgen;
		case O_RV1:
		case O_RV14:
		case O_RV2:
		case O_RV24:
		case O_RV4:
		case O_RV8:
		case O_RV:
		case O_LV:
I 6
			/*
			 * positive offsets represent arguments
			 * and must use "ap" display entry rather
			 * than the "fp" entry
			 */
			if (p[1] >= 0) {
				subop++;
				suboppr++;
			}
D 10
			/*
			 * offsets out of range of word addressing
			 * must use long offset opcodes
			 */
E 6
			if (p[1] < SHORTADDR && p[1] >= -SHORTADDR)
				break;
			else {
E 10
I 10
#			ifdef PDP11
			    break;
#			else
			    /*
			     * offsets out of range of word addressing
			     * must use long offset opcodes
			     */
			    if (p[1] < SHORTADDR && p[1] >= -SHORTADDR)
				    break;
			    else {
E 10
				op += O_LRV - O_RV;
D 10
				cp = otext[op];
			}
I 6
			/* and fall through */
E 10
I 10
#				ifdef DEBUG
				    cp = otext[op];
#				endif DEBUG
			    }
			    /* and fall through */
#			endif PDP11
E 10
E 6
		case O_BEG:
		case O_NODUMP:
		case O_CON4:
		case O_CASE4:
D 15
		case O_RANG4:
		case O_RANG24:
		case O_RSNG4:
		case O_RSNG24:
I 6
		case O_SUCC4:
		case O_PRED4:
E 15
E 6
		longgen:
D 10
		    {
			short	*sp = &p[1];
			long	*lp = &p[1];

E 10
			n = (n << 1) - 1;
D 7
			if ( op == O_LRV )
E 7
I 7
D 20
			if ( op == O_LRV || op == O_FOR4U || op == O_FOR4D)
E 20
I 20
D 22
			if ( op == O_LRV || op == O_FOR4U || op == O_FOR4D) {
E 22
I 22
			if ( op == O_LRV ) {
E 22
E 20
E 7
				n--;
I 20
#				if defined(ADDR32) && !defined(DEC11)
				    p[n / 2] <<= 16;
#				endif
			}
E 20
#ifdef DEBUG
D 10
			if (opt('k'))
			    {
				printf( ")#%5d\t%s" , lc - HEADER_BYTES , cp+1 );
E 10
I 10
			if (opt('k')) {
D 13
				printf(")#%5d\t%s", lc - HEADER_BYTES, cp+1);
E 13
I 13
				printf("%5d\t%s", lc - HEADER_BYTES, cp+1);
E 13
E 10
				if (suboppr)
D 10
					printf(":%1d", suboppr);
				for ( i = 1 ; i < n 
E 10
I 10
					printf(":%d", suboppr);
				for ( i = 2, lp = (long *)&p[1]; i < n 
E 10
				    ; i += sizeof ( long )/sizeof ( short ) )
					printf( "\t%D " , *lp ++ );
I 10
D 14
				if (i == n) 
					printf( "\t%d ", p[i - 1] );
E 14
I 14
				if (i == n) {
					sp = (short *)lp;
					printf( "\t%d ", *sp );
				}
E 14
E 10
				pchr ( '\n' );
D 10
			    }
E 10
I 10
			}
E 10
#endif
			if ( op != O_CASE4 )
D 10
			    word ( op | subop<<8 );
			for ( i = 1 ; i < n ; i ++ )
			    word ( *sp ++ );
E 10
I 10
#				ifdef DEC11
			    	    word((op & 0377) | subop << 8);
#				else
				    word(op << 8 | (subop & 0377));
#				endif DEC11
			for ( i = 1, sp = (short *)&p[1]; i < n; i++)
				word ( *sp ++ );
E 10
			return ( oldlc );
D 10
		    }
E 10
	}
#ifdef DEBUG
	if (opt('k')) {
D 13
		printf(")#%5d\t%s", lc - HEADER_BYTES, cp+1);
E 13
I 13
		printf("%5d\t%s", lc - HEADER_BYTES, cp+1);
E 13
		if (suboppr)
			printf(":%d", suboppr);
		if (string)
			printf("\t%s",string);
		if (n > 1)
			pchr('\t');
		for (i=1; i<n; i++)
D 10
			printf("%d ", ( short ) p[i]);
E 10
I 10
			printf("%d ", p[i]);
E 10
		pchr('\n');
	}
#endif
	if (op != NIL)
D 10
		word(op | subop << 8);
E 10
I 10
#		ifdef DEC11
		    word((op & 0377) | subop << 8);
#		else
		    word(op << 8 | (subop & 0377));
#		endif DEC11
E 10
	for (i=1; i<n; i++)
		word(p[i]);
	return (oldlc);
}
#endif OBJ

/*
 * listnames outputs a list of enumerated type names which
 * can then be selected from to output a TSCAL
 * a pointer to the address in the code of the namelist
 * is kept in value[ NL_ELABEL ].
 */
listnames(ap)

	register struct nl *ap;
{
	struct nl *next;
D 27
	register int oldlc, len;
E 27
I 27
#ifdef OBJ
	register int oldlc;
#endif
	register int len;
E 27
	register unsigned w;
	register char *strptr;

D 13
	if (cgenflg < 0)
E 13
I 13
	if ( !CGENNING )
E 13
		/* code is off - do nothing */
		return(NIL);
	if (ap->class != TYPE)
		ap = ap->type;
	if (ap->value[ NL_ELABEL ] != 0) {
		/* the list already exists */
		return( ap -> value[ NL_ELABEL ] );
	}
#	ifdef OBJ
D 27
	    oldlc = lc;
	    put(2, O_TRA, lc);
	    ap->value[ NL_ELABEL ] = lc;
E 27
I 27
	    oldlc = (int) lc; /* same problem as put */
	    (void) put(2, O_TRA, lc);
	    ap->value[ NL_ELABEL ] = (int) lc;
E 27
#	endif OBJ
#	ifdef PC
D 19
	    putprintf( "	.data" , 0 );
	    putprintf( "	.align 1" , 0 );
E 19
I 19
D 21
#	    ifdef vax
		putprintf("	.data", 0);
		putprintf("	.align 1", 0);
#	    endif vax
#	    ifdef mc68000
		putprintf("	.data", 0);
		putprintf("	.even", 0);
#	    endif mc68000
E 21
I 21
	    putprintf("	.data", 0);
	    aligndot(A_STRUCT);
E 21
E 19
D 27
	    ap -> value[ NL_ELABEL ] = getlab();
	    putlab( ap -> value[ NL_ELABEL ] );
E 27
I 27
	    ap -> value[ NL_ELABEL ] = (int) getlab();
	    (void) putlab((char *) ap -> value[ NL_ELABEL ] );
E 27
#	endif PC
	/* number of scalars */
	next = ap->type;
	len = next->range[1]-next->range[0]+1;
#	ifdef OBJ
D 27
	    put(2, O_CASE2, len);
E 27
I 27
	    (void) put(2, O_CASE2, len);
E 27
#	endif OBJ
#	ifdef PC
	    putprintf( "	.word %d" , 0 , len );
#	endif PC
	/* offsets of each scalar name */
	len = (len+1)*sizeof(short);
#	ifdef OBJ
D 27
	    put(2, O_CASE2, len);
E 27
I 27
	    (void) put(2, O_CASE2, len);
E 27
#	endif OBJ
#	ifdef PC
	    putprintf( "	.word %d" , 0 , len );
#	endif PC
	next = ap->chain;
	do	{
		for(strptr = next->symbol;  *strptr++;  len++)
			continue;
		len++;
#		ifdef OBJ
D 27
		    put(2, O_CASE2, len);
E 27
I 27
		    (void) put(2, O_CASE2, len);
E 27
#		endif OBJ
#		ifdef PC
		    putprintf( "	.word %d" , 0 , len );
#		endif PC
	} while (next = next->chain);
	/* list of scalar names */
	strptr = getnext(ap, &next);
#	ifdef OBJ
	    do	{
D 10
		    w = (unsigned) *strptr;
E 10
I 10
#		    ifdef DEC11
			w = (unsigned) *strptr;
#		    else
			w = *strptr << 8;
#		    endif DEC11
E 10
		    if (!*strptr++)
			    strptr = getnext(next, &next);
D 10
		    w |= *strptr << 8;
E 10
I 10
#		    ifdef DEC11
			w |= *strptr << 8;
#		    else
			w |= (unsigned) *strptr;
#		    endif DEC11
E 10
		    if (!*strptr++)
			    strptr = getnext(next, &next);
D 27
		    word(w);
E 27
I 27
		    word((int) w);
E 27
	    } while (next);
	    /* jump over the mess */
D 27
	    patch(oldlc);
E 27
I 27
	    patch((PTR_DCL) oldlc);
E 27
#	endif OBJ
#	ifdef PC
	    while ( next ) {
		while ( *strptr ) {
		    putprintf( "	.byte	0%o" , 1 , *strptr++ );
		    for ( w = 2 ; ( w <= 8 ) && *strptr ; w ++ ) {
			putprintf( ",0%o" , 1 , *strptr++ );
		    }
		    putprintf( "" , 0 );
		}
		putprintf( "	.byte	0" , 0 );
		strptr = getnext( next , &next );
	    }
	    putprintf( "	.text" , 0 );
#	endif PC
	return( ap -> value[ NL_ELABEL ] );
}

I 27
char *
E 27
getnext(next, new)

	struct nl *next, **new;
{
	if (next != NIL) {
		next = next->chain;
		*new = next;
	}
D 27
	if (next == NIL)
E 27
I 27
	if (next == NLNIL)
E 27
		return("");
#ifdef OBJ
D 13
	if (opt('k') && cgenflg >= 0)
		printf(")#%5d\t\t\"%s\"\n", lc-HEADER_BYTES, next->symbol);
E 13
I 13
	if (opt('k') && CGENNING )
		printf("%5d\t\t\"%s\"\n", lc-HEADER_BYTES, next->symbol);
E 13
D 8
#endif
E 8
I 8
#endif OBJ
E 8
	return(next->symbol);
}

#ifdef OBJ
/*
 * Putspace puts out a table
 * of nothing to leave space
 * for the case branch table e.g.
 */
putspace(n)
	int n;
{
	register i;

D 13
	if (cgenflg < 0)
E 13
I 13
	if ( !CGENNING )
E 13
		/*
		 * code disabled - do nothing
		 */
D 27
		return(lc);
E 27
I 27
		return;
E 27
#ifdef DEBUG
	if (opt('k'))
D 13
		printf(")#%5d\t.=.+%d\n", lc - HEADER_BYTES, n);
E 13
I 13
		printf("%5d\t.=.+%d\n", lc - HEADER_BYTES, n);
E 13
#endif
D 32
	for (i = even(n); i > 0; i -= 2)
E 32
I 32
	for (i = n; i > 0; i -= 2)
E 32
		word(0);
}

putstr(sptr, padding)

	char *sptr;
	int padding;
{
	register unsigned short w;
	register char *strptr = sptr;
	register int pad = padding;

D 13
	if (cgenflg < 0)
E 13
I 13
	if ( !CGENNING )
E 13
		/*
		 * code disabled - do nothing
		 */
D 27
		return(lc);
E 27
I 27
		return;
E 27
#ifdef DEBUG
	if (opt('k'))
D 10
		printf(")#%5D\t\t\"%s\"\n", lc-HEADER_BYTES, strptr);
E 10
I 10
D 13
		printf(")#%5d\t\t\"%s\"\n", lc-HEADER_BYTES, strptr);
E 13
I 13
		printf("%5d\t\t\"%s\"\n", lc-HEADER_BYTES, strptr);
E 13
E 10
#endif
	if (pad == 0) {
		do	{
D 10
			w = (unsigned short) * strptr;
E 10
I 10
#			ifdef DEC11
			    w = (unsigned short) * strptr;
#			else
			    w = (unsigned short)*strptr<<8;
#			endif DEC11
E 10
			if (w)
D 10
				w |= *++strptr << 8;
E 10
I 10
#				ifdef DEC11
				    w |= *++strptr << 8;
#				else
				    w |= *++strptr;
#				endif DEC11
E 10
D 27
			word(w);
E 27
I 27
			word((int) w);
E 27
		} while (*strptr++);
	} else {
D 10
		do 	{
			w = (unsigned short) * strptr;
			if (w) {
				if (*++strptr)
					w |= *strptr << 8;
				else {
					w |= ' ' << 8;
					pad--;
				}
				word(w);
			}
		} while (*strptr++);
E 10
I 10
#		ifdef DEC11
		    do 	{
			    w = (unsigned short) * strptr;
			    if (w) {
				    if (*++strptr)
					    w |= *strptr << 8;
				    else {
D 23
					    w |= ' \0';
E 23
I 23
					    w |= ' ' << 8;
E 23
					    pad--;
				    }
D 27
				    word(w);
E 27
I 27
				    word((int) w);
E 27
			    }
		    } while (*strptr++);
#		else
		    do 	{
			    w = (unsigned short)*strptr<<8;
			    if (w) {
				    if (*++strptr)
					    w |= *strptr;
				    else {
					    w |= ' ';
					    pad--;
				    }
				    word(w);
			    }
		    } while (*strptr++);
#		endif DEC11
E 10
		while (pad > 1) {
D 23
			word('  ');
E 23
I 23
#			ifdef DEC11
			    word(' ' | (' ' << 8));
#			else
			    word((' ' << 8) | ' ');
#			endif DEC11
E 23
			pad -= 2;
		}
		if (pad == 1)
D 10
			word(' ');
E 10
I 10
#			ifdef DEC11
			    word(' ');
#			else
D 23
			    word(' \0');
E 23
I 23
			    word(' ' << 8);
E 23
#			endif DEC11
E 10
		else
			word(0);
	}
}
#endif OBJ

I 27
#ifndef PC
E 27
lenstr(sptr, padding)

	char *sptr;
	int padding;

{
	register int cnt;
	register char *strptr = sptr;

	cnt = padding;
	do	{
		cnt++;
	} while (*strptr++);
	return((++cnt) & ~1);
}
I 27
#endif
E 27

/*
 * Patch repairs the branch
 * at location loc to come
 * to the current location.
 *	for PC, this puts down the label
 *	and the branch just references that label.
 *	lets here it for two pass assemblers.
 */
patch(loc)
I 27
    PTR_DCL loc;
E 27
{

#	ifdef OBJ
D 10
	    patchfil(loc, lc-loc-2, 1);
E 10
I 10
	    patchfil(loc, (long)(lc-loc-2), 1);
E 10
#	endif OBJ
#	ifdef PC
D 27
	    putlab( loc );
E 27
I 27
	    (void) putlab((char *) loc );
E 27
#	endif PC
}

#ifdef OBJ
patch4(loc)
I 27
PTR_DCL loc;
E 27
{
D 10

	patchfil(loc, lc - HEADER_BYTES, 2);
E 10
I 10
	patchfil(loc, (long)(lc - HEADER_BYTES), 2);
E 10
}

/*
D 17
 * Patchfil makes loc+2 have value
E 17
I 17
 * Patchfil makes loc+2 have jmploc
E 17
 * as its contents.
 */
D 17
patchfil(loc, value, words)
E 17
I 17
patchfil(loc, jmploc, words)
E 17
	PTR_DCL loc;
D 10
	int value, words;
E 10
I 10
D 17
	long value;
E 17
I 17
	long jmploc;
E 17
	int words;
E 10
{
	register i;
I 27
	extern long lseek();
E 27
I 10
D 20
	int val;
E 20
I 20
	short val;
E 20
E 10

D 13
	if (cgenflg < 0)
E 13
I 13
	if ( !CGENNING )
E 13
		return;
	if (loc > (unsigned) lc)
		panic("patchfil");
#ifdef DEBUG
	if (opt('k'))
D 10
		printf(")#\tpatch %u %d\n", loc - HEADER_BYTES, value);
E 10
I 10
D 13
		printf(")#\tpatch %u %D\n", loc - HEADER_BYTES, value);
E 13
I 13
D 17
		printf("\tpatch %u %D\n", loc - HEADER_BYTES, value);
E 17
I 17
		printf("\tpatch %u %D\n", loc - HEADER_BYTES, jmploc);
E 17
E 13
E 10
#endif
I 10
D 17
	val = value;
E 17
I 17
	val = jmploc;
E 17
E 10
	do {
I 10
#		ifndef DEC11
		    if (words > 1)
D 17
			    val = value >> 16;
E 17
I 17
			    val = jmploc >> 16;
E 17
		    else
D 17
			    val = value;
E 17
I 17
			    val = jmploc;
E 17
#		endif DEC11
E 10
		i = ((unsigned) loc + 2 - ((unsigned) lc & ~01777))/2;
D 20
		if (i >= 0 && i < 1024)
E 20
I 20
		if (i >= 0 && i < 1024) {
E 20
D 10
			obuf[i] = value;
E 10
I 10
			obuf[i] = val;
E 10
D 20
		else {
E 20
I 20
		} else {
E 20
D 27
			lseek(ofil, (long) loc+2, 0);
D 10
			write(ofil, &value, 2);
E 10
I 10
			write(ofil, &val, 2);
E 10
			lseek(ofil, (long) 0, 2);
E 27
I 27
			(void) lseek(ofil, (long) loc+2, 0);
			write(ofil, (char *) (&val), 2);
			(void) lseek(ofil, (long) 0, 2);
E 27
		}
		loc += 2;
D 10
		value = value >> 16;
E 10
I 10
#		ifdef DEC11
D 17
		    val = value >> 16;
E 17
I 17
		    val = jmploc >> 16;
E 17
#		endif DEC11
E 10
	} while (--words);
}

/*
 * Put the word o into the code
 */
word(o)
	int o;
{

	*obufp = o;
	obufp++;
	lc += 2;
	if (obufp >= obuf+512)
		pflush();
}

extern char	*obj;
/*
 * Flush the code buffer
 */
pflush()
{
	register i;

	i = (obufp - ( ( short * ) obuf ) ) * 2;
D 27
	if (i != 0 && write(ofil, obuf, i) != i)
E 27
I 27
	if (i != 0 && write(ofil, (char *) obuf, i) != i)
E 27
		perror(obj), pexit(DIED);
	obufp = obuf;
}
#endif OBJ

/*
 * Getlab - returns the location counter.
 * included here for the eventual code generator.
 *	for PC, thank you!
 */
I 27
char *
E 27
getlab()
{
#	ifdef OBJ

	    return (lc);
#	endif OBJ
#	ifdef PC
	    static long	lastlabel;

D 27
	    return ( ++lastlabel );
E 27
I 27
	    return ( (char *) ++lastlabel );
E 27
#	endif PC
}

/*
 * Putlab - lay down a label.
 *	for PC, just print the label name with a colon after it.
 */
I 27
char *
E 27
putlab(l)
D 27
	int l;
E 27
I 27
	char *l;
E 27
{

#	ifdef PC
D 27
	    putprintf( PREFIXFORMAT , 1 , LABELPREFIX , l );
E 27
I 27
	    putprintf( PREFIXFORMAT , 1 , (int) LABELPREFIX , (int) l );
E 27
	    putprintf( ":" , 0 );
#	endif PC
	return (l);
}
D 10

E 10
E 1
