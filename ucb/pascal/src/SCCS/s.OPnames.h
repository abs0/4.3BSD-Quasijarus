h32023
s 00007/00001/00261
d D 5.1 85/06/05 15:40:49 dist 10 9
c Add copyright
e
s 00000/00000/00262
d D 2.1 84/02/08 20:40:59 aoki 9 8
c synchronize to version 2
e
s 00005/00005/00257
d D 1.8 84/02/08 00:39:00 mckusick 8 7
c merge in conformant array code by Carol Nishizak
e
s 00000/00000/00262
d D 1.7 83/09/19 07:08:18 thien 7 6
c changing to unlinted source
e
s 00002/00000/00260
d D 1.6 83/08/19 05:06:58 thien 6 5
c Changed for linting
e
s 00005/00005/00255
d D 1.5 82/08/29 16:23:45 mckusick 5 4
c add DFDISP to dispose dynamic files
e
s 00002/00002/00258
d D 1.4 82/02/08 21:39:45 mckusic 4 3
c add BPT pseudo-opcode
e
s 00001/00001/00259
d D 1.3 82/02/02 12:56:31 linton 3 2
c merge pdx into the Pascal system
e
s 00010/00010/00250
d D 1.2 80/10/03 01:07:21 peter 2 1
c Implement formal functions and procedures
e
s 00260/00000/00000
d D 1.1 80/08/27 19:54:09 peter 1 0
c date and time created 80/08/27 19:54:09 by peter
e
u
U
t
T
I 1
D 3
/* static	char sccsid[] = "%Z%%M% %I% %G%"; */
E 3
I 3
D 4
/* static	char sccsid[] = "@(#)OPnames.h 1.2 10/2/80"; */
E 4
I 4
D 10
/* static	char sccsid[] = "%Z%%M% %I% %G%"; */
E 10
I 10
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 10
E 4
E 3

I 6
#ifndef PC
E 6
char	*otext[] = {
	0,
D 2
	" HALT",
	" TRA4",
E 2
	" NODUMP",
	" BEG",
	" END",
	" CALL",
D 2
	"*ABORT",
	" PUSH",
	" POP",
E 2
I 2
	" FCALL",
	" FRTN",
	" FSAV",
E 2
	" SDUP2",
	" SDUP4",
D 2
	" IF",
E 2
	" TRA",
D 2
	" LINO",
E 2
I 2
	" TRA4",
E 2
	" GOTO",
I 2
	" LINO",
	" PUSH",
	0,
	" IF",
E 2
	" REL2",
	" REL4",
	" REL24",
	" REL42",
	" REL8",
	" RELG",
	" RELT",
D 2
	0,
E 2
	" REL28",
	" REL48",
	" REL82",
	" REL84",
	" AND",
	" OR",
	" NOT",
D 8
	0,
E 8
I 8
	" VAS",
E 8
	" AS2",
	" AS4",
	" AS24",
	" AS42",
	" AS21",
	" AS41",
	" AS28",
	" AS48",
	" AS8",
	" AS",
	" INX2P2",
	" INX4P2",
	" INX2",
	" INX4",
	" OFF",
	" NIL",
	" ADD2",
	" ADD4",
	" ADD24",
	" ADD42",
	" ADD28",
	" ADD48",
	" ADD82",
	" ADD84",
	" SUB2",
	" SUB4",
	" SUB24",
	" SUB42",
	" SUB28",
	" SUB48",
	" SUB82",
	" SUB84",
	" MUL2",
	" MUL4",
	" MUL24",
	" MUL42",
	" MUL28",
	" MUL48",
	" MUL82",
	" MUL84",
	" ABS2",
	" ABS4",
	" ABS8",
	0,
	" NEG2",
	" NEG4",
	" NEG8",
	0,
	" DIV2",
	" DIV4",
	" DIV24",
	" DIV42",
	" MOD2",
	" MOD4",
	" MOD24",
	" MOD42",
	" ADD8",
	" SUB8",
	" MUL8",
	" DVD8",
	" STOI",
	" STOD",
	" ITOD",
	" ITOS",
	" DVD2",
	" DVD4",
	" DVD24",
	" DVD42",
	" DVD28",
	" DVD48",
	" DVD82",
	" DVD84",
	" RV1",
	" RV14",
	" RV2",
	" RV24",
	" RV4",
	" RV8",
	" RV",
	" LV",
	" LRV1",
	" LRV14",
	" LRV2",
	" LRV24",
	" LRV4",
	" LRV8",
	" LRV",
	" LLV",
	" IND1",
	" IND14",
	" IND2",
	" IND24",
	" IND4",
	" IND8",
	" IND",
	0,
	" CON1",
	" CON14",
	" CON2",
	" CON24",
	" CON4",
	" CON8",
	" CON",
	" LVCON",
	" RANG2",
	" RANG42",
	" RSNG2",
	" RSNG42",
	" RANG4",
	" RANG24",
	" RSNG4",
	" RSNG24",
	" STLIM",
	" LLIMIT",
	" BUFF",
I 2
	" HALT",
E 2
D 8
	0,
	0,
	0,
	0,
E 8
I 8
	" VINX2",
	" VINX24",
	" VINX42",
	" VINX4",
E 8
D 2
	0,
E 2
	"*ORD2",
	"*CONG",
	"*CONC",
	"*CONC4",
I 2
	"*ABORT",
I 4
	"*BPT",
E 4
E 2
	" PXPBUF",
	" COUNT",
D 2
	" TRACNT",
E 2
D 4
	0,
E 4
	" CASE1OP",
	" CASE2OP",
	" CASE4OP",
	"*CASEBEG",
	"*CASE1",
	"*CASE2",
	"*CASE4",
	"*CASEEND",
	" ADDT",
	" SUBT",
	" MULT",
	" INCT",
	" CTTOT",
	" CARD",
	" IN",
	" ASRT",
	" FOR1U",
	" FOR2U",
	" FOR4U",
	" FOR1D",
	" FOR2D",
	" FOR4D",
	0,
	0,
	" READE",
	" READ4",
	" READC",
	" READ8",
	" READLN",
	" EOF",
	" EOLN",
	0,
	" WRITEC",
	" WRITES",
	" WRITEF",
	" WRITLN",
	" PAGE",
	" NAM",
	" MAX",
	" MIN",
	" UNIT",
	" UNITINP",
	" UNITOUT",
	" MESSAGE",
	" GET",
	" PUT",
	" FNIL",
	0,
	" DEFNAME",
	" RESET",
	" REWRITE",
	" FILE",
	" REMOVE",
	" FLUSH",
	0,
	0,
	" PACK",
	" UNPACK",
I 5
	" NEW",
	" DISPOSE",
	" DFDISP",
E 5
	" ARGC",
	" ARGV",
	0,
D 5
	0,
	0,
	0,
E 5
	" CLCK",
	" WCLCK",
	" SCLCK",
D 5
	" DISPOSE",
	" NEW",
E 5
	" DATE",
	" TIME",
	" UNDEF",
I 5
	0,
	0,
E 5
	" ATAN",
	" COS",
	" EXP",
	" LN",
	" SIN",
	" SQRT",
	" CHR2",
	" CHR4",
	" ODD2",
	" ODD4",
	" PRED2",
	" PRED4",
	" PRED24",
	" SUCC2",
	" SUCC4",
	" SUCC24",
	" SEED",
	" RANDOM",
	" EXPO",
	" SQR2",
	" SQR4",
	" SQR8",
	" ROUND",
	" TRUNC"
};
I 6
#endif
E 6
E 1
