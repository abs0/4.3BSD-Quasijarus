h12297
s 00005/00002/00174
d D 5.1 85/04/30 14:16:30 dist 5 4
c Add copyright
e
s 00004/00000/00172
d D 4.4 82/11/11 10:06:56 rrh 4 3
c conditional inclusion for adb
e
s 00000/00000/00172
d D 4.3 82/02/14 16:36:53 rrh 3 2
c Fix reported and outstanding bugs. Reformat some text for
c readability/understandability. Assembles new instructions  for G and H
c format floating numbers & new queue instructions
c asscan.c split into 4 files; two additional files to construct and
c manipulate G and H format numbers, with analog for atof()
c Numerical accuracy of new atof() not verified; standard atof() used
c for F and D floating numbers.  As does NOT use G and H instructions itself
e
s 00000/00000/00172
d D 4.2 82/02/14 16:15:27 rrh 2 1
c Synchronizing this new file to release 4.2
e
s 00172/00000/00000
d D 4.1 82/02/14 16:11:17 rrh 1 0
c date and time created 82/02/14 16:11:17 by rrh
e
u
U
t
T
I 1
/*
D 5
 *	Copyright (c) 1982 Regents of the University of California
E 5
I 5
 * Copyright (c) 1982 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 5
 */
I 5

E 5
#ifndef lint
D 5
static char sccsid[] = "%Z%%M% %I% %G%";
E 5
I 5
static char sccsid[] = "%W% (Berkeley) %G%";
E 5
#endif not lint

#ifdef AS
#include <stdio.h>
#include "as.h"
#include "assyms.h"

/*
 *	Convert loader reference types (plus PCREL) to bytes and lg bytes
 */
int	reflen[] = { 	/* {LEN*+PCREL} ==> number of bytes */
	0,	0,
	1,	1,	/* LEN1,	LEN1 + PCREL */
	2,	2,	/* LEN2,	LEN2 + PCREL */
	4,	4,	/* LEN4,	LEN2 + PCREL */
	8,	8,	/* LEN8,	LEN2 + PCREL */
	16,	16	/* LEN16,	LEN16 + PCREL */
};	
int	lgreflen[] = { 	/* {LEN*+PCREL} ==> number of bytes */
	-1,	-1,
	0,	0,	/* LEN1,	LEN1 + PCREL */
	1,	1,	/* LEN2,	LEN2 + PCREL */
	2,	2,	/* LEN4,	LEN2 + PCREL */
	3,	3,	/* LEN8,	LEN2 + PCREL */
	4,	4	/* LEN16,	LEN16 + PCREL */
};	

/*
 *	Convert sizes to loader reference types and type flags
 */
/*0	1	2	3	4	5	6	7	8*/
/*
 *	Convert {1,2,4,8} into {LEN1, LEN2, LEN4, LEN8}
 */
int	len124[] = {
	0,	LEN1,	/* 0 */
	LEN2,	0,	/* 2 */
	LEN4,	0,	/* 4 */
	0,	0,	/* 6 */
	LEN8,	0,	/* 8 */
	0,	0,	/* 10 */
	0,	0,	/* 12 */
	0,	0,	/* 14 */
	LEN16,	0	/* 16 */
};
/*
 *	Convert {1,2,4,8} into {bits to construct operands}
 */
char	mod124[] = {
	0,	0x00,	/* 0 */
	0x20,	0,	/* 2 */
	0x40,	0,	/* 4 */
	0,	0,	/* 6 */
	0,	0,	/* 8 */
	0,	0,	/* 10 */
	0,	0,	/* 12 */
	0,	0,	/* 14 */
	0,	0	/* 16 */
};
/*
 *	{1,2,4,8} into {TYPB, TYPW, TYPL, TYPQ}
 */
int	type_124[] = {
	0,	TYPB,	/* 0 */
	TYPW,	0,	/* 2 */
	TYPL,	0,	/* 4 */
	0,	0,	/* 6 */
	TYPQ,	0,	/* 8 */
	0,	0,	/* 10 */
	0,	0,	/* 12 */
	0,	0,	/* 14 */
	TYPO,	0	/* 16 */
};
#endif AS
/*
 *	Convert TYP[BWLQOFDGH] into {1 if relocation not OK}
 */
int	ty_NORELOC[] = {
	0,	/* TYPB */
	0,	/* TYPW */
	0,	/* TYPL */
	1,	/* TYPQ */
	1,	/* TYPO */
	1,	/* TYPF */
	1,	/* TYPD */
	1,	/* TYPG */
	1,	/* TYPH */
	1	/* TYPNONE */
};
I 4
#ifndef ADB
E 4
/*
 *	Convert TYP[BWLQOFDGH] into {1 if a floating point number}
 */
int	ty_float[] = {
	0,	/* TYPB */
	0,	/* TYPW */
	0,	/* TYPL */
	0,	/* TYPQ */
	0,	/* TYPO */
	1,	/* TYPF */
	1,	/* TYPD */
	1,	/* TYPG */
	1,	/* TYPH */
	0	/* TYPNONE */
};
I 4
#endif
E 4
#ifdef AS
/*
 *	Convert TYP[BWLQOFDGH] into {LEN1 ... LEN16}
 */
int	ty_LEN[] = {
	LEN1,	/* TYPB */
	LEN2,	/* TYPW */
	LEN4,	/* TYPL */
	LEN8,	/* TYPQ */
	LEN16,	/* TYPO */
	LEN4,	/* TYPF */
	LEN8,	/* TYPD */
	LEN8,	/* TYPG */
	LEN16,	/* TYPH */
	0	/* TYPNONE */
};
#endif AS
/*
 *	Convert TYP[BWLQOFDGH] into {1 ... 16}
 */
int	ty_nbyte[] = {
	1,	/* TYPB */
	2,	/* TYPW */
	4,	/* TYPL */
	8,	/* TYPQ */
	16,	/* TYPO */
	4,	/* TYPF */
	8,	/* TYPD */
	8,	/* TYPG */
	16,	/* TYPH */
	0	/* TYPNONE */
};
I 4
#ifndef ADB
E 4
/*
 *	Convert TYP[BWLQOFDGH] into lg{1 ... 16}
 */
int	ty_nlg[] = {
	0,	/* TYPB */
	1,	/* TYPW */
	2,	/* TYPL */
	3,	/* TYPQ */
	4,	/* TYPO */
	2,	/* TYPF */
	3,	/* TYPD */
	3,	/* TYPG */
	4,	/* TYPH */
	-1	/* TYPNONE */
};
/*
 *	Convert TYP[BWLQOFDGH] into strings
 */
char	*ty_string[] = {
	"byte",		/* TYPB */
	"word",		/* TYPW */
	"long",		/* TYPL */
	"quad",		/* TYPQ */
	"octa",		/* TYPO */
	"f_float",	/* TYPF */
	"d_float",	/* TYPD */
	"g_float",	/* TYPG */
	"h_float",	/* TYPH */
	"unpackd",	/* TYPUNPACKED */
	"??snark??"	/* TYPNONE */
};
I 4
#endif
E 4
E 1
