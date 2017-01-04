h64705
s 00005/00000/00028
d D 5.2 00/08/29 22:10:46 msokolov 7 6
c Complete jxxx relaxation overhaul. We now relax three-way without -J!
c -J is now ignored. We now also relax SOBs, AOBs, and ACBs. See the comments in
c addsob() in c2 for the motivation.
c As a side effect, we now require -d4.
c As yet another side effect, the handling of branches in instrs has been
c significantly cleaned up for c2.
e
s 00005/00002/00023
d D 5.1 85/04/30 13:58:46 dist 6 5
c Add copyright
e
s 00001/00001/00024
d D 4.5 83/06/30 19:03:00 rrh 5 4
c The string pool is maintained both in core, and in a second tmp file.
c names are in core and on the file; strings are just in the file.  The file 
c is maintained as a string table per a.out(5), and tacked onto the a.out file
c at the very end.  The string table has more than need be, since discarde 
c labels and .ascii strings find their way (harmlessly) into the string table.
c the string file maintained with stdio; nothing fancy, even if -V set
e
s 00012/00083/00013
d D 4.4 82/02/14 16:34:27 rrh 4 3
c Fix reported and outstanding bugs. Reformat some text for
c readability/understandability. Assembles new instructions  for G and H
c format floating numbers & new queue instructions
c asscan.c split into 4 files; two additional files to construct and
c manipulate G and H format numbers, with analog for atof()
c Numerical accuracy of new atof() not verified; standard atof() used
c for F and D floating numbers.  As does NOT use G and H instructions itself
e
s 00001/00000/00095
d D 4.3 80/08/16 17:32:05 henry 3 2
c Add .quad storage filler directive
e
s 00007/00007/00088
d D 4.2 80/08/15 18:03:39 henry 2 1
c use struct nlist; change field names; vgrind format fixes
e
s 00095/00000/00000
d D 4.1 80/08/13 18:55:21 bill 1 0
c date and time created 80/08/13 18:55:21 by bill
e
u
U
t
T
I 1
D 4
/* Copyright (c) 1980 Regents of the University of California */
static	char sccsid[] = "%Z%%M% %I% %G%";
E 4
I 4
/*
D 6
 *	Copyright (c) 1982 Regents of the University of California
E 6
I 6
 * Copyright (c) 1982 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 6
 */
I 6

E 6
#ifndef lint
D 6
static char sccsid[] = "%Z%%M% %I% %G%";
E 6
I 6
static char sccsid[] = "%W% (Berkeley) %G%";
E 6
#endif not lint

E 4
#include <stdio.h>
D 2
#include <sys/types.h>
E 2
#include "as.h"

D 2
#define OP(name,opcode,nargs,arg1,arg2,arg3,arg4,arg5,arg6) \
E 2
I 2
D 4
#define	OP(name, opcode, nargs, arg1, arg2, arg3, arg4, arg5, arg6) \
E 4
I 4
#define	OP(name, eopcode, popcode, nargs, arg1, arg2, arg3, arg4, arg5, arg6) \
E 4
E 2
	{ \
D 2
		name,(nargs==0 ? INST0:INSTn), opcode,nargs, \
		arg1,arg2,arg3,arg4,arg5,arg6 \
E 2
I 2
D 4
		name, opcode, nargs, arg1, arg2, arg3, arg4, arg5, arg6, \
		(nargs == 0 ? INST0:INSTn) \
E 4
I 4
		name, popcode, nargs, arg1, arg2, arg3, arg4, arg5, arg6, \
		(nargs == 0 ? INST0:INSTn), eopcode \
E 4
E 2
	}
I 7
#define	RELAXOP(name, eopcode, popcode, tag) \
	{ \
		name, popcode, 0,   0, 0, 0, 0, 0, 0, \
		tag, eopcode \
	}
E 7
D 2
#define PSEUDO(name, type, tag) \
E 2
I 2
#define	PSEUDO(name, type, tag) \
E 2
	{ \
D 2
		name, tag, type \
E 2
I 2
		name, type, 0,   0, 0, 0, 0, 0, 0, \
D 4
		tag \
E 4
I 4
		tag, CORE \
E 4
E 2
	}

D 2
readonly struct instab instab[] = {
E 2
I 2
readonly struct Instab instab[] = {
E 2
D 4
PSEUDO(".space",	0,	ISPACE),
PSEUDO(".fill",		0,	IFILL),
PSEUDO(".byte",		0,	IBYTE),
PSEUDO(".word",		0,	IWORD),
PSEUDO(".long",		0,	ILONG),
PSEUDO(".int",		0,	IINT),
I 3
PSEUDO(".quad",		0,	IQUAD),
E 3
PSEUDO(".data",		0,	IDATA),
PSEUDO(".globl",	0,	IGLOBAL),
PSEUDO(".set",		0,	ISET),
PSEUDO(".text",		0,	ITEXT),
PSEUDO(".comm",		0,	ICOMM),
PSEUDO(".lcomm",	0,	ILCOMM),
PSEUDO(".lsym",		0,	ILSYM),
PSEUDO(".align",	0,	IALIGN),
PSEUDO(".float",	0,	IFLOAT),
PSEUDO(".double",	0,	IDOUBLE),
PSEUDO(".org",		0,	IORG),
PSEUDO(".stab",		0,	ISTAB),
PSEUDO(".stabs",	0,	ISTABSTR),
PSEUDO(".stabn",	0,	ISTABNONE),
PSEUDO(".stabd",	0,	ISTABDOT),
PSEUDO(".ascii",	0,	IASCII),
PSEUDO(".asciz",	0,	IASCIZ),
PSEUDO(".file",		0,	IFILE),
PSEUDO(".line",		0,	ILINENO),
PSEUDO(".ABORT",	0,	IABORT),

PSEUDO("r0",		0,	REG),
PSEUDO("r1",		1,	REG),
PSEUDO("r2",		2,	REG),
PSEUDO("r3",		3,	REG),
PSEUDO("r4",		4,	REG),
PSEUDO("r5",		5,	REG),
PSEUDO("r6",		6,	REG),
PSEUDO("r7",		7,	REG),
PSEUDO("r8",		8,	REG),
PSEUDO("r9",		9,	REG),
PSEUDO("r10",		10,	REG),
PSEUDO("r11",		11,	REG),
PSEUDO("r12",		12,	REG),
PSEUDO("r13",		13,	REG),
PSEUDO("r14",		14,	REG),
PSEUDO("r15",		15,	REG),
PSEUDO("ap",		12,	REG),
PSEUDO("fp",		13,	REG),
PSEUDO("sp",		14,	REG),
PSEUDO("pc",		15,	REG),

PSEUDO("jcc",		0x1e,	IJXXX),
PSEUDO("jcs",		0x1f,	IJXXX),
PSEUDO("jeql",		0x13,	IJXXX),
PSEUDO("jeqlu",		0x13,	IJXXX),
PSEUDO("jgeq",		0x18,	IJXXX),
PSEUDO("jgequ",		0x1e,	IJXXX),
PSEUDO("jgtr",		0x14,	IJXXX),
PSEUDO("jgtru",		0x1a,	IJXXX),
PSEUDO("jleq",		0x15,	IJXXX),
PSEUDO("jlequ",		0x1b,	IJXXX),
PSEUDO("jlss",		0x19,	IJXXX),
PSEUDO("jlssu",		0x1f,	IJXXX),
PSEUDO("jneq",		0x12,	IJXXX),
PSEUDO("jnequ",		0x12,	IJXXX),
PSEUDO("jvc",		0x1c,	IJXXX),
PSEUDO("jvs",		0x1d,	IJXXX),
PSEUDO("jbr",		0x11,	IJXXX),
PSEUDO("jbc",		0xe1,	IJXXX),
PSEUDO("jbs",		0xe0,	IJXXX),
PSEUDO("jbcc",		0xe5,	IJXXX),
PSEUDO("jbsc",		0xe4,	IJXXX),
PSEUDO("jbcs",		0xe3,	IJXXX),
PSEUDO("jbss",		0xe2,	IJXXX),
PSEUDO("jlbc",		0xe9,	IJXXX),
PSEUDO("jlbs",		0xe8,	IJXXX),

#include "instrs"

E 4
I 4
#include "instrs.as"
E 4
D 5
0
E 5
I 5
PSEUDO("\0\0\0\0\0\0\0\0\0\0", 0, 0)
E 5
};
E 1
