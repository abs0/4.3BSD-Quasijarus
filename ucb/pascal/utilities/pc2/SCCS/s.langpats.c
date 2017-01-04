h02687
s 00014/00025/00634
d D 5.5 87/04/07 15:49:13 mckusick 24 23
c better code for set operations
e
s 00016/00000/00643
d D 5.4 86/11/17 17:36:22 mckusick 23 22
c add IN operator for tahoe
e
s 00163/00000/00480
d D 5.3 86/11/13 18:08:04 mckusick 22 21
c add CCI (tahoe) support
e
s 00037/00037/00443
d D 5.2 85/08/22 17:09:00 mckusick 21 20
c do validity checking on number of arguments (from donn@utah-cs)
e
s 00006/00002/00474
d D 5.1 85/06/05 16:37:23 dist 20 19
c Add copyright
e
s 00068/00031/00408
d D 2.2 84/09/20 13:09:25 mckusick 19 18
c clean up patterns for mc68000
e
s 00077/00195/00362
d D 2.1 84/08/18 18:15:40 mckusick 18 17
c subsume Pascal dependent part of pc2.c
e
s 00020/00000/00537
d D 1.16 84/01/11 23:23:43 aoki 17 16
c inline expansions for range checks (RANG4,RSNG4)
e
s 00002/00002/00535
d D 1.15 83/12/08 05:25:12 peter 16 15
c strcmpn changed to strncmp to confuse the innocent
e
s 00003/00003/00534
d D 1.14 83/09/29 18:54:53 peter 15 14
c fix opcodes to match assembler; 
c invert IN test to fix bug.
e
s 00070/00002/00467
d D 1.13 83/06/01 20:36:43 mckusick 14 13
c file and set operations for mc68000
e
s 00017/00001/00452
d D 1.12 83/04/08 14:52:16 mckusick 13 12
c convert to handle mc68000
e
s 00128/00009/00325
d D 1.11 82/11/12 19:24:17 mckusick 12 11
c add inlines for ASRT, ASRTS, CHR, LINO, NIL, RANG4, RSNG4, SUBSC, SUBSCZ
e
s 00021/00025/00313
d D 1.10 81/07/15 15:56:03 mckusic 11 9
c optimize formal calling code
e
s 00021/00021/00317
d R 1.10 81/06/08 00:46:59 mckusic 10 9
c put display save area back into formal routine structure
e
s 00007/00009/00331
d D 1.9 81/04/01 23:12:57 mckusic 9 8
c mods for dynamically allocated display save area for formal calls
e
s 00002/00002/00338
d D 1.8 81/03/07 00:54:41 mckusic 8 7
c fix ROUND error
e
s 00000/00001/00340
d D 1.7 81/02/04 18:14:39 mckusic 7 6
c fix 1.6, because of 8 char login must do this as a delta
e
s 00016/00009/00325
d D 1.6 81/02/04 18:08:28 mckusic 6 5
c run pc2 after /lib/c2; remove /lib/c2 hacks from pc2
e
s 00002/00002/00332
d D 1.5 81/01/26 12:00:23 mckusic 5 4
c pop args to IN before clearing r0 so /lib/c2 does not discard the clr
e
s 00074/00094/00260
d D 1.4 81/01/17 22:06:44 mckusic 4 3
c shorten length of inline expansion code
e
s 00036/00037/00318
d D 1.3 81/01/16 18:13:36 mckusic 3 2
c require arg count in pattern match, circumvent /lib/c2 in blkclr
e
s 00114/00046/00241
d D 1.2 81/01/10 16:54:54 mckusic 2 1
c convert REL* to operate on >65535 length data
e
s 00287/00000/00000
d D 1.1 81/01/07 20:30:16 mckusick 1 0
c date and time created 81/01/07 20:30:16 by mckusick
e
u
U
t
T
I 1
D 18
/* Copyright (c) 1979 Regents of the University of California */
E 18
I 18
D 20
/* Copyright (c) 1979, 1984 Regents of the University of California */
E 20
I 20
/*
 * Copyright (c) 1979, 1984 Regents of the University of California 
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 20
E 18

D 18
static char sccsid[] = "%Z%%M% %I% %G%";
E 18
I 18
#ifndef lint
D 20
static char sccsid[] = "%W%	(Berkeley)	%G%";
E 20
I 20
static char sccsid[] = "%W% (Berkeley) %G%";
E 20
#endif not lint
E 18

D 18
#include <stdio.h>
#include <ctype.h>
E 18
I 18
#include "inline.h"

E 18
/*
D 18
 * The hash table must be at least twice as big as the number
 * of patterns, preferably bigger. It must also be a prime number
E 18
I 18
 * Pattern table for Pascal library routines.
E 18
 */
D 18
#define HSHSIZ	101
E 18
I 18
struct pats language_ptab[] = {
E 18

I 13
#ifdef vax
D 18
#define CALLTEMPLATE	"calls\t$"
#define TEMPLATESIZE	7
#endif vax

#ifdef mc68000
#define CALLTEMPLATE	"jbsr\t"
#define TEMPLATESIZE	5
#endif mc68000

E 13
struct pats {
	char	*name;
	char	*replace;
} ptab[] = {

I 13
#ifdef vax
E 18
E 13
D 3
	{ "ACTFILE\n",
E 3
I 3
D 12
	{ "1,_ACTFILE\n",
E 3
D 4
"	movl	(sp)+,r1\n\
E 4
I 4
D 11
"	popr	$0x2\n\
E 11
I 11
"	movl	(sp)+,r1\n\
E 11
E 4
	movl	12(r1),r0\n" },

E 12
I 12
/*
D 18
 * C library routines
E 18
I 18
 * General Pascal library routines
E 18
 */
E 12
D 3
	{ "fgetc\n",
"	decl	*(sp)\n\
	jgeq	1f\n\
E 3
I 3
D 18
	{ "1,_fgetc\n",
"	sobgeq	*(sp),1f\n\
E 3
	calls	$1,__filbuf\n\
	jbr     2f\n\
1:\n\
	addl3	$4,(sp)+,r1\n\
	movzbl	*(r1),r0\n\
	incl	(r1)\n\
2:\n" },

D 3
	{ "fputc\n",
"	decl	*4(sp)\n\
	jgeq	1f\n\
E 3
I 3
	{ "2,_fputc\n",
"	sobgeq	*4(sp),1f\n\
E 3
	calls	$2,__flsbuf\n\
	jbr	2f\n\
1:\n\
D 4
	movl	(sp)+,r0\n\
	addl3	$4,(sp)+,r1\n\
	movb	r0,*(r1)\n\
	incl	(r1)\n\
E 4
I 4
	popr	$0x3\n\
	movb	r0,*4(r1)\n\
	incl	4(r1)\n\
E 4
2:\n" },

I 12
/*
 * VAX special instructions
 */
E 12
D 3
	{ "blkcpy\n",
E 3
I 3
	{ "3,_blkcpy\n",
E 3
D 4
"	movl	4(sp),r1\n\
	movl	8(sp),r3\n\
E 4
I 4
D 12
"	popr	$0xb\n\
	pushl	r0\n\
E 12
I 12
"	popr	$0xa\n\
E 12
	jbr	2f\n\
E 4
1:\n\
D 4
	movzwl	$65535,r0\n\
	cmpl	(sp),r0\n\
D 2
	bleq	1f\n\
E 2
I 2
	jleq	1f\n\
E 4
E 2
	subl2	r0,(sp)\n\
	movc3	r0,(r1),(r3)\n\
D 2
	brb	1b\n\
E 2
I 2
D 4
	jbr	1b\n\
E 2
1:\n\
	movl	(sp)+,r0\n\
	addl2	$8,sp\n\
E 4
I 4
2:\n\
	movzwl	$65535,r0\n\
	cmpl	(sp),r0\n\
	jgtr	1b\n\
D 11
	popr	$0x1\n\
E 11
I 11
	movl	(sp)+,r0\n\
E 11
E 4
	movc3	r0,(r1),(r3)\n" },

D 3
	{ "blkclr\n",
E 3
I 3
	{ "2,_blkclr\n",
E 3
D 12
"	movl	4(sp),r3\n\
E 12
I 12
"	movl	(sp)+,r3\n\
E 12
I 3
D 6
	subl3	r3,r3,-4(sp)\n\
E 6
	jbr	2f\n\
E 3
1:\n\
I 3
	subl2	r0,(sp)\n\
	movc5	$0,(r3),$0,r0,(r3)\n\
2:\n\
E 3
	movzwl	$65535,r0\n\
	cmpl	(sp),r0\n\
D 2
	bleq	1f\n\
E 2
I 2
D 3
	jleq	1f\n\
E 2
	subl2	r0,(sp)\n\
	movc5	$0,(r1),$0,r0,(r3)\n\
D 2
	brb	1b\n\
E 2
I 2
	jbr	1b\n\
E 2
1:\n\
	movl	(sp)+,r0\n\
	addl2	$4,sp\n\
	movc5	$0,(r1),$0,r0,(r3)\n" },
E 3
I 3
	jgtr	1b\n\
D 4
	movq	(sp)+,r0\n\
E 4
I 4
D 12
	popr	$0x3\n\
E 12
I 12
	movl	(sp)+,r0\n\
E 12
E 4
	movc5	$0,(r3),$0,r0,(r3)\n" },
E 3

D 3
	{ "LOCC\n",
E 3
I 3
	{ "3,_LOCC\n",
E 3
D 4
"	movl	(sp)+,r5\n\
	movl	(sp)+,r4\n\
	movl	(sp)+,r1\n\
E 4
I 4
"	popr	$0x30\n\
D 11
	popr	$0x2\n\
E 11
I 11
	movl	(sp)+,r1\n\
E 11
E 4
1:\n\
	movzwl	$65535,r0\n\
D 4
	cmpl	r4,r0\n\
E 4
I 4
	cmpl	r5,r0\n\
E 4
D 2
	bleq	1f\n\
E 2
I 2
	jleq	1f\n\
E 2
D 4
	subl2	r0,r4\n\
	locc	r5,r0,(r1)\n\
E 4
I 4
	subl2	r0,r5\n\
	locc	r4,r0,(r1)\n\
E 4
D 2
	beql	1b\n\
E 2
I 2
	jeql	1b\n\
E 2
D 4
	addl2	r4,r0\n\
E 4
I 4
	addl2	r5,r0\n\
E 4
D 2
	brb	2f\n\
E 2
I 2
	jbr	2f\n\
E 2
1:\n\
D 4
	locc	r5,r4,(r1)\n\
E 4
I 4
	locc	r4,r5,(r1)\n\
E 4
2:\n" },

E 18
D 3
	{ "ROUND\n",
E 3
I 3
D 8
	{ "1,_ROUND\n",
E 8
I 8
D 21
	{ "2,_ROUND\n",
E 21
I 21
	{ 2, "_ROUND\n",
E 21
E 8
E 3
D 18
"	cvtrdl	(sp)+,r0\n" },
E 18
I 18
"	movd	(sp)+,r0\n\
	cvtrdl	r0,r0\n" },
E 18

D 3
	{ "TRUNC\n",
E 3
I 3
D 8
	{ "1,_TRUNC\n",
E 8
I 8
D 21
	{ "2,_TRUNC\n",
E 21
I 21
	{ 2, "_TRUNC\n",
E 21
E 8
E 3
D 18
"	cvtdl	(sp)+,r0\n" },
E 18
I 18
"	movd	(sp)+,r0\n\
	cvtdl	r0,r0\n" },
E 18

I 12
D 18
/*
 * General Pascal library routines
 */
E 18
D 21
	{ "1,_ACTFILE\n",
E 21
I 21
	{ 1, "_ACTFILE\n",
E 21
"	movl	(sp)+,r1\n\
	movl	12(r1),r0\n" },

E 12
D 3
	{ "FCALL\n",
E 3
I 3
D 9
	{ "1,_FCALL\n",
E 3
"	movl	(sp),r0\n\
E 9
I 9
D 21
	{ "2,_FCALL\n",
E 21
I 21
	{ 2, "_FCALL\n",
E 21
D 18
"	movl	4(sp),r0\n\
E 9
D 11
	ashl	$3,4(r0),r1\n\
D 9
	movc3	r1,__disply+8,8(r0)[r1]\n\
	movl	(sp),r0\n\
E 9
I 9
	movc3	r1,__disply+8,*(sp)+\n\
E 11
I 11
	movc3	4(r0),__disply+8,*(sp)+\n\
E 18
I 18
"	movl	(sp)+,r5\n\
	movl	(sp),r0\n\
	movc3	4(r0),__disply+8,(r5)\n\
E 18
E 11
	movl	(sp)+,r0\n\
E 9
D 11
	ashl	$3,4(r0),r1\n\
D 9
	movc3	r1,8(r0),__disply+8\n\
	movl	*(sp)+,r0\n" },
E 9
I 9
	movc3	r1,8(r0),__disply+8\n" },
E 11
I 11
	movc3	4(r0),8(r0),__disply+8\n" },
E 11
E 9

D 3
	{ "FRTN\n",
E 3
I 3
D 21
	{ "2,_FRTN\n",
E 21
I 21
	{ 2, "_FRTN\n",
E 21
E 3
D 4
"	movl	(sp)+,r0\n\
E 4
I 4
D 9
"	popr	$0x1\n\
E 9
I 9
"	movl	(sp)+,r0\n\
E 9
E 4
D 11
	ashl	$3,4(r0),r1\n\
D 9
	movc3	r1,8(r0)[r1],__disply+8\n\
D 4
	movl	(sp)+,r0\n" },
E 4
I 4
	popr	$0x1\n" },
E 9
I 9
	movc3	r1,*(sp)+,__disply+8\n" },
E 11
I 11
D 18
	movc3	4(r0),*(sp)+,__disply+8\n" },
E 18
I 18
	movl	(sp)+,r5\n\
	movc3	4(r0),(r5),__disply+8\n" },
E 18
E 11
E 9
E 4

D 3
	{ "FSAV\n",
E 3
I 3
D 21
	{ "3,_FSAV\n",
E 21
I 21
	{ 3, "_FSAV\n",
E 21
E 3
D 18
"	movl	8(sp),r0\n\
	movl	(sp)+,(r0)\n\
D 11
	movl	(sp)+,4(r0)\n\
	ashl	$3,4(r0),r1\n\
	movc3	r1,__disply+8,8(r0)\n\
D 4
	movl	(sp)+,r0\n" },
E 4
I 4
	popr	$0x1\n" },
E 11
I 11
	ashl	$3,(sp)+,4(r0)\n\
	movc3	4(r0),__disply+8,8(r0)\n\
E 18
I 18
"	movl	(sp)+,r3\n\
	movl	(sp)+,r4\n\
	movl	(sp),r5\n\
	movl	r3,(r5)\n\
	ashl	$3,r4,4(r5)\n\
	movc3	4(r5),__disply+8,8(r5)\n\
E 18
	movl	(sp)+,r0\n" },
E 11
E 4

I 12
/*
 * Pascal relational comparisons
 */
E 12
D 3
	{ "RELEQ\n",
E 3
I 3
D 21
	{ "3,_RELEQ\n",
E 21
I 21
	{ 3, "_RELEQ\n",
E 21
E 3
D 2
"	movl	(sp)+,r1\n\
	cmpc3	r1,*(sp)+,*(sp)+\n\
	beql	1f\n\
	clrl	r0\n\
	brb	2f\n\
E 2
I 2
D 4
"	movl	(sp)+,r4\n\
	movl	(sp)+,r1\n\
	movl	(sp)+,r3\n\
E 4
I 4
D 11
"	popr	$0x10\n\
	popr	$0xa\n\
E 11
I 11
D 18
"	popr	$0xb\n\
E 18
I 18
"	movl	(sp)+,r0\n\
	movl	(sp)+,r1\n\
	movl	(sp)+,r3\n\
E 18
	movl	r0,r4\n\
E 11
E 4
E 2
1:\n\
D 2
	movl	$1,r0\n\
2:\n" },
E 2
I 2
	movzwl	$65535,r0\n\
	cmpl	r4,r0\n\
D 4
	jleq	2f\n\
E 4
I 4
	jleq	3f\n\
E 4
	subl2	r0,r4\n\
	cmpc3	r0,(r1),(r3)\n\
	jeql	1b\n\
D 4
	jbr	3f\n\
E 4
2:\n\
D 4
	cmpc3	r4,(r1),(r3)\n\
	jneq	3f\n\
	incl	r0\n\
E 4
I 4
	clrl	r0\n\
E 4
	jbr	4f\n\
3:\n\
D 4
	clrl	r0\n\
E 4
I 4
	cmpc3	r4,(r1),(r3)\n\
	jneq	2b\n\
	incl	r0\n\
E 4
4:\n" },
E 2

D 3
	{ "RELNE\n",
E 3
I 3
D 21
	{ "3,_RELNE\n",
E 21
I 21
	{ 3, "_RELNE\n",
E 21
E 3
D 2
"	movl	(sp)+,r1\n\
	cmpc3	r1,*(sp)+,*(sp)+\n\
	bneq	1f\n\
	clrl	r0\n\
	brb	2f\n\
E 2
I 2
D 4
"	movl	(sp)+,r4\n\
	movl	(sp)+,r1\n\
	movl	(sp)+,r3\n\
E 4
I 4
D 11
"	popr	$0x10\n\
	popr	$0xa\n\
E 11
I 11
D 18
"	popr	$0xb\n\
E 18
I 18
"	movl	(sp)+,r0\n\
	movl	(sp)+,r1\n\
	movl	(sp)+,r3\n\
E 18
	movl	r0,r4\n\
E 11
E 4
E 2
1:\n\
I 2
	movzwl	$65535,r0\n\
	cmpl	r4,r0\n\
D 4
	jleq	2f\n\
E 4
I 4
	jleq	3f\n\
E 4
	subl2	r0,r4\n\
	cmpc3	r0,(r1),(r3)\n\
	jeql	1b\n\
D 4
	jbr	3f\n\
E 4
2:\n\
D 4
	cmpc3	r4,(r1),(r3)\n\
	jeql	4f\n\
3:\n\
E 4
E 2
	movl	$1,r0\n\
I 4
	jbr	4f\n\
3:\n\
	cmpc3	r4,(r1),(r3)\n\
	jneq	2b\n\
E 4
D 2
2:\n" },
E 2
I 2
4:\n" },
E 2

D 3
	{ "RELSLT\n",
E 3
I 3
D 21
	{ "3,_RELSLT\n",
E 21
I 21
	{ 3, "_RELSLT\n",
E 21
E 3
D 2
"	movl	(sp)+,r1\n\
	cmpc3	r1,*(sp)+,*(sp)+\n\
	blss	1f\n\
	clrl	r0\n\
	brb	2f\n\
E 2
I 2
D 4
"	movl	(sp)+,r4\n\
	movl	(sp)+,r1\n\
	movl	(sp)+,r3\n\
E 4
I 4
D 11
"	popr	$0x10\n\
	popr	$0xa\n\
E 11
I 11
D 18
"	popr	$0xb\n\
E 18
I 18
"	movl	(sp)+,r0\n\
	movl	(sp)+,r1\n\
	movl	(sp)+,r3\n\
E 18
	movl	r0,r4\n\
E 11
	jbr	2f\n\
E 4
E 2
1:\n\
I 2
D 4
	movzwl	$65535,r0\n\
	cmpl	r4,r0\n\
	jleq	2f\n\
E 4
	subl2	r0,r4\n\
	cmpc3	r0,(r1),(r3)\n\
D 4
	jeql	1b\n\
	jbr	3f\n\
E 4
I 4
	jneq	3f\n\
E 4
2:\n\
I 4
	movzwl	$65535,r0\n\
	cmpl	r4,r0\n\
	jgtr	1b\n\
E 4
	cmpc3	r4,(r1),(r3)\n\
3:\n\
	jlss	4f\n\
	clrl	r0\n\
	jbr	5f\n\
4:\n\
E 2
	movl	$1,r0\n\
D 2
2:\n" },
E 2
I 2
5:\n" },
E 2

D 3
	{ "RELSLE\n",
E 3
I 3
D 21
	{ "3,_RELSLE\n",
E 21
I 21
	{ 3, "_RELSLE\n",
E 21
E 3
D 2
"	movl	(sp)+,r1\n\
	cmpc3	r1,*(sp)+,*(sp)+\n\
	bleq	1f\n\
	clrl	r0\n\
	brb	2f\n\
E 2
I 2
D 4
"	movl	(sp)+,r4\n\
	movl	(sp)+,r1\n\
	movl	(sp)+,r3\n\
E 4
I 4
D 11
"	popr	$0x10\n\
	popr	$0xa\n\
E 11
I 11
D 18
"	popr	$0xb\n\
E 18
I 18
"	movl	(sp)+,r0\n\
	movl	(sp)+,r1\n\
	movl	(sp)+,r3\n\
E 18
	movl	r0,r4\n\
E 11
	jbr	2f\n\
E 4
E 2
1:\n\
I 2
D 4
	movzwl	$65535,r0\n\
	cmpl	r4,r0\n\
	jleq	2f\n\
E 4
	subl2	r0,r4\n\
	cmpc3	r0,(r1),(r3)\n\
D 4
	jeql	1b\n\
	jbr	3f\n\
E 4
I 4
	jneq	3f\n\
E 4
2:\n\
I 4
	movzwl	$65535,r0\n\
	cmpl	r4,r0\n\
	jgtr	1b\n\
E 4
	cmpc3	r4,(r1),(r3)\n\
3:\n\
	jleq	4f\n\
	clrl	r0\n\
	jbr	5f\n\
4:\n\
E 2
	movl	$1,r0\n\
D 2
2:\n" },
E 2
I 2
5:\n" },
E 2

D 3
	{ "RELSGT\n",
E 3
I 3
D 21
	{ "3,_RELSGT\n",
E 21
I 21
	{ 3, "_RELSGT\n",
E 21
E 3
D 2
"	movl	(sp)+,r1\n\
	cmpc3	r1,*(sp)+,*(sp)+\n\
	bgtr	1f\n\
	clrl	r0\n\
	brb	2f\n\
E 2
I 2
D 4
"	movl	(sp)+,r4\n\
	movl	(sp)+,r1\n\
	movl	(sp)+,r3\n\
E 4
I 4
D 11
"	popr	$0x10\n\
	popr	$0xa\n\
E 11
I 11
D 18
"	popr	$0xb\n\
E 18
I 18
"	movl	(sp)+,r0\n\
	movl	(sp)+,r1\n\
	movl	(sp)+,r3\n\
E 18
	movl	r0,r4\n\
E 11
	jbr	2f\n\
E 4
E 2
1:\n\
I 2
D 4
	movzwl	$65535,r0\n\
	cmpl	r4,r0\n\
	jleq	2f\n\
E 4
	subl2	r0,r4\n\
	cmpc3	r0,(r1),(r3)\n\
D 4
	jeql	1b\n\
	jbr	3f\n\
E 4
I 4
	jneq	3f\n\
E 4
2:\n\
I 4
	movzwl	$65535,r0\n\
	cmpl	r4,r0\n\
	jgtr	1b\n\
E 4
	cmpc3	r4,(r1),(r3)\n\
3:\n\
	jgtr	4f\n\
	clrl	r0\n\
	jbr	5f\n\
4:\n\
E 2
	movl	$1,r0\n\
D 2
2:\n" },
E 2
I 2
5:\n" },
E 2

D 3
	{ "RELSGE\n",
E 3
I 3
D 21
	{ "3,_RELSGE\n",
E 21
I 21
	{ 3, "_RELSGE\n",
E 21
E 3
D 2
"	movl	(sp)+,r1\n\
	cmpc3	r1,*(sp)+,*(sp)+\n\
	bgeq	1f\n\
	clrl	r0\n\
	brb	2f\n\
E 2
I 2
D 4
"	movl	(sp)+,r4\n\
	movl	(sp)+,r1\n\
	movl	(sp)+,r3\n\
E 4
I 4
D 11
"	popr	$0x10\n\
	popr	$0xa\n\
E 11
I 11
D 18
"	popr	$0xb\n\
E 18
I 18
"	movl	(sp)+,r0\n\
	movl	(sp)+,r1\n\
	movl	(sp)+,r3\n\
E 18
	movl	r0,r4\n\
E 11
	jbr	2f\n\
E 4
E 2
1:\n\
I 2
D 4
	movzwl	$65535,r0\n\
	cmpl	r4,r0\n\
	jleq	2f\n\
E 4
	subl2	r0,r4\n\
	cmpc3	r0,(r1),(r3)\n\
D 4
	jeql	1b\n\
	jbr	3f\n\
E 4
I 4
	jneq	3f\n\
E 4
2:\n\
I 4
	movzwl	$65535,r0\n\
	cmpl	r4,r0\n\
	jgtr	1b\n\
E 4
	cmpc3	r4,(r1),(r3)\n\
3:\n\
	jgeq	4f\n\
	clrl	r0\n\
	jbr	5f\n\
4:\n\
E 2
	movl	$1,r0\n\
D 2
2:\n" },
E 2
I 2
5:\n" },
E 2

I 12
/*
 * Pascal set operations.
 */
E 12
D 3
	{ "ADDT\n",
E 3
I 3
D 21
	{ "4,_ADDT\n",
E 21
I 21
	{ 4, "_ADDT\n",
E 21
E 3
D 4
"	movl	(sp)+,r0\n\
	movl	(sp)+,r1\n\
	movl	(sp)+,r2\n\
E 4
I 4
D 18
"	popr	$0x17\n\
E 18
I 18
"	movl	(sp)+,r0\n\
	movl	(sp)+,r1\n\
	movl	(sp)+,r2\n\
	movl	(sp)+,r4\n\
E 18
E 4
	movl	r0,r3\n\
D 4
	movl	(sp)+,r4\n\
E 4
1:\n\
	bisl3	(r1)+,(r2)+,(r3)+\n\
	sobgtr	r4,1b\n" },

D 3
	{ "SUBT\n",
E 3
I 3
D 21
	{ "4,_SUBT\n",
E 21
I 21
	{ 4, "_SUBT\n",
E 21
E 3
D 4
"	movl	(sp)+,r0\n\
	movl	(sp)+,r1\n\
	movl	(sp)+,r2\n\
E 4
I 4
D 18
"	popr	$0x17\n\
E 18
I 18
"	movl	(sp)+,r0\n\
	movl	(sp)+,r1\n\
	movl	(sp)+,r2\n\
	movl	(sp)+,r4\n\
E 18
E 4
	movl	r0,r3\n\
D 4
	movl	(sp)+,r4\n\
E 4
1:\n\
	bicl3	(r2)+,(r1)+,(r3)+\n\
	sobgtr	r4,1b\n" },

D 3
	{ "MULT\n",
E 3
I 3
D 21
	{ "4,_MULT\n",
E 21
I 21
	{ 4, "_MULT\n",
E 21
E 3
D 4
"	movl	(sp)+,r0\n\
	movl	(sp)+,r1\n\
	movl	(sp)+,r2\n\
E 4
I 4
D 18
"	popr	$0x17\n\
E 18
I 18
"	movl	(sp)+,r0\n\
	movl	(sp)+,r1\n\
	movl	(sp)+,r2\n\
	movl	(sp)+,r4\n\
E 18
E 4
	movl	r0,r3\n\
D 4
	movl	(sp)+,r4\n\
E 4
1:\n\
	mcoml	(r1)+,r5\n\
	bicl3	r5,(r2)+,(r3)+\n\
	sobgtr	r4,1b\n" },

D 3
	{ "IN\n",
E 3
I 3
D 21
	{ "4,_IN\n",
E 21
I 21
	{ 4, "_IN\n",
E 21
E 3
D 5
"	clrl	r0\n\
D 4
	movl	(sp)+,r1\n\
	subl2	(sp)+,r1\n\
	cmpl	r1,(sp)+\n\
E 4
I 4
	popr	$0x1e\n\
E 5
I 5
D 18
"	popr	$0x1e\n\
E 18
I 18
"	movl	(sp)+,r1\n\
	movl	(sp)+,r2\n\
	movl	(sp)+,r3\n\
	movl	(sp)+,r4\n\
E 18
	clrl	r0\n\
E 5
	subl2	r2,r1\n\
	cmpl	r1,r3\n\
E 4
D 2
	bgtru	1f\n\
	bbc	r1,*(sp)+,1f\n\
E 2
I 2
	jgtru	1f\n\
D 3
	jbc	r1,*(sp)+,1f\n\
E 3
I 3
D 4
	jbc	r1,*(sp),1f\n\
E 3
E 2
	movl	$1,r0\n\
D 3
1:\n" }
E 3
I 3
1:\n\
	addl2	$4,sp\n" }
E 4
I 4
	jbc	r1,(r4),1f\n\
	incl	r0\n\
D 12
1:\n" }
E 12
I 12
1:\n" },

/*
 * Pascal runtime checks
 */
D 21
	{ "1,_ASRT\n",
E 21
I 21
	{ 1, "_ASRT\n",
E 21
D 18
"	tstl	(sp)+\n\
E 18
I 18
"	movl	(sp)+,r0\n\
	tstl	r0\n\
E 18
	jneq	1f\n\
	pushl	$0\n\
	pushl	$_EASRT\n\
	calls	$2,_ERROR\n\
1:\n" },

D 21
	{ "2,_ASRTS\n",
E 21
I 21
	{ 2, "_ASRTS\n",
E 21
D 18
"	popr	$0x03\n\
E 18
I 18
"	movl	(sp)+,r0\n\
	movl	(sp)+,r1\n\
E 18
	tstl	r0\n\
	jneq	1f\n\
	pushl	r1\n\
	pushl	$_EASRTS\n\
	calls	$2,_ERROR\n\
1:\n" },

D 21
	{ "1,_CHR\n",
E 21
I 21
	{ 1, "_CHR\n",
E 21
"	movl	(sp)+,r0\n\
	cmpl	r0,$127\n\
	jlequ	1f\n\
	pushl	r0\n\
	pushl	$_ECHR\n\
	calls	$2,_ERROR\n\
1:\n" },

D 21
	{ "0,_LINO\n",
E 21
I 21
	{ 0, "_LINO\n",
E 21
"	incl	__stcnt\n\
	cmpl	__stcnt,__stlim\n\
	jlss	1f\n\
	pushl	__stcnt\n\
	pushl	$_ELINO\n\
	calls	$2,_ERROR\n\
1:\n" },

D 21
	{ "1,_NIL\n",
E 21
I 21
	{ 1, "_NIL\n",
E 21
"	movl	(sp)+,r0\n\
	cmpl	r0,__maxptr\n\
	jgtr	1f\n\
	cmpl	r0,__minptr\n\
	jgeq	2f\n\
1:\n\
	pushl	$0\n\
	pushl	$_ENIL\n\
	calls	$2,_ERROR\n\
2:\n" },

D 21
	{ "2,_RANDOM\n",
E 21
I 21
	{ 2, "_RANDOM\n",
E 21
D 18
"	addl2	$8,sp\n\
E 18
I 18
"	movd	(sp)+,r0\n\
E 18
	emul	__seed,$1103515245,$0,r0\n\
	ediv	$0x7fffffff,r0,r1,r0\n\
	movl	r0,__seed\n\
	cvtld	r0,r0\n\
	divd2	$0d2.147483647e+09,r0\n" },

D 21
	{ "3,_RANG4\n",
E 21
I 21
	{ 3, "_RANG4\n",
E 21
D 18
"	popr	$0x07\n\
E 18
I 18
"	movl	(sp)+,r0\n\
	movl	(sp)+,r1\n\
	movl	(sp)+,r2\n\
E 18
	cmpl	r0,r1\n\
	jlss	1f\n\
	cmpl	r0,r2\n\
	jleq	2f\n\
1:\n\
	pushl	r0\n\
	pushl	$_ERANG\n\
	calls	$2,_ERROR\n\
2:\n" },

D 21
	{ "2,_RSNG4\n",
E 21
I 21
	{ 2, "_RSNG4\n",
E 21
D 18
"	popr	$0x03\n\
E 18
I 18
"	movl	(sp)+,r0\n\
	movl	(sp)+,r1\n\
E 18
	cmpl	r0,r1\n\
	jlequ	1f\n\
	pushl	r0\n\
	pushl	$_ERANG\n\
	calls	$2,_ERROR\n\
1:\n" },

D 21
	{ "1,_SEED\n",
E 21
I 21
	{ 1, "_SEED\n",
E 21
D 18
"	movl	__seed,r0\n\
	movl	(sp)+,__seed\n" },
E 18
I 18
"	movl	(sp)+,r1\n\
	movl	__seed,r0\n\
	movl	r1,__seed\n" },
E 18

D 21
	{ "3,_SUBSC\n",
E 21
I 21
	{ 3, "_SUBSC\n",
E 21
D 18
"	popr	$0x07\n\
E 18
I 18
"	movl	(sp)+,r0\n\
	movl	(sp)+,r1\n\
	movl	(sp)+,r2\n\
E 18
	cmpl	r0,r1\n\
	jlss	1f\n\
	cmpl	r0,r2\n\
	jleq	2f\n\
1:\n\
	pushl	r0\n\
	pushl	$_ESUBSC\n\
	calls	$2,_ERROR\n\
2:\n" },

D 21
	{ "2,_SUBSCZ\n",
E 21
I 21
	{ 2, "_SUBSCZ\n",
E 21
D 18
"	popr	$0x03\n\
E 18
I 18
"	movl	(sp)+,r0\n\
	movl	(sp)+,r1\n\
E 18
	cmpl	r0,r1\n\
	jlequ	1f\n\
	pushl	r0\n\
	pushl	$_ESUBSC\n\
	calls	$2,_ERROR\n\
1:\n" },
I 13
#endif vax
E 13

I 13
#ifdef mc68000
D 14
	{ "NONE", "IMPLEMENTED" },
E 14
I 14
D 18

E 18
/*
 * General Pascal library routines
 */
D 21
	{ "_ACTFILE\n",
E 21
I 21
	{ 1, "_ACTFILE\n",
E 21
D 19
"	movl	sp@,a0\n\
E 19
I 19
"	movl	sp@+,a0\n\
E 19
	movl	a0@(12),d0\n" },

D 21
	{ "_ADDT\n",
E 21
I 21
	{ 4, "_ADDT\n",
E 21
D 19
"	movl	a2,sp@-\n\
	movl	sp@(8),a2\n\
	movl	sp@(12),a1\n\
	movl	sp@(4),a0\n\
	movl	sp@(16),d1\n\
E 19
I 19
"	movl	sp@+,a0\n\
	movl	sp@+,d0\n\
	movl	sp@+,a1\n\
	movl	sp@+,d1\n\
	movl	a0,sp@-\n\
	movl	a2,sp@-\n\
	movl	d0,a2\n\
E 19
	subql	#1,d1\n\
1:\n\
	movl	a2@+,d0\n\
	orl	a1@+,d0\n\
	movl	d0,a0@+\n\
	dbra	d1,1b\n\
	movl	sp@+,a2\n\
D 19
	movl	sp@,d0\n" },
E 19
I 19
	movl	sp@+,d0\n" },
E 19

D 21
	{ "_SUBT\n",
E 21
I 21
	{ 4, "_SUBT\n",
E 21
D 19
"	movl	a2,sp@-\n\
	movl	sp@(8),a2\n\
	movl	sp@(12),a1\n\
	movl	sp@(4),a0\n\
	movl	sp@(16),d1\n\
E 19
I 19
"	movl	sp@+,a0\n\
	movl	sp@+,d0\n\
	movl	sp@+,a1\n\
	movl	sp@+,d1\n\
	movl	a0,sp@-\n\
	movl	a2,sp@-\n\
	movl	d0,a2\n\
E 19
	subql	#1,d1\n\
1:\n\
	movl	a1@+,d0\n\
	notl	d0\n\
	andl	a2@+,d0\n\
	movl	d0,a0@+\n\
	dbra	d1,1b\n\
	movl	sp@+,a2\n\
D 19
	movl	sp@,d0\n" },
E 19
I 19
	movl	sp@+,d0\n" },
E 19

D 21
	{ "_MULT\n",
E 21
I 21
	{ 4, "_MULT\n",
E 21
D 19
"	movl	a2,sp@-\n\
	movl	sp@(8),a2\n\
	movl	sp@(12),a1\n\
	movl	sp@(4),a0\n\
	movl	sp@(16),d1\n\
E 19
I 19
"	movl	sp@+,a0\n\
	movl	sp@+,d0\n\
	movl	sp@+,a1\n\
	movl	sp@+,d1\n\
	movl	a0,sp@-\n\
	movl	a2,sp@-\n\
	movl	d0,a2\n\
E 19
	subql	#1,d1\n\
1:\n\
	movl	a2@+,d0\n\
	andl	a1@+,d0\n\
	movl	d0,a0@+\n\
	dbra	d1,1b\n\
	movl	sp@+,a2\n\
D 19
	movl	sp@,d0\n" },
E 19
I 19
	movl	sp@+,d0\n" },
E 19

D 21
	{ "_IN\n",
E 21
I 21
	{ 4, "_IN\n",
E 21
D 19
"	movl	sp@,d1\n\
	subl	sp@(4),d1\n\
	cmpl	sp@(8),d1\n\
E 19
I 19
"	movl	sp@+,d0\n\
	movl	sp@+,a0\n\
	movl	sp@+,d1\n\
	movl	sp@+,a1\n\
	subl	a0,d0\n\
	cmpl	d1,d0\n\
E 19
D 15
	jbhi	1f\n\
E 15
I 15
	jhi	1f\n\
E 15
D 19
	movl	sp@(12),a0\n\
	movl	d1,d0\n\
	lsrl	#3,d0\n\
	btst	d1,a0@(0,d0:l)\n\
E 19
I 19
	movl	d0,d1\n\
	lsrl	#3,d1\n\
	btst	d0,a1@(0,d1:l)\n\
E 19
D 15
	jbne	1f\n\
E 15
I 15
	jeq	1f\n\
E 15
	moveq	#1,d0\n\
D 15
	jbra	2f\n\
E 15
I 15
	jra	2f\n\
E 15
1:\n\
	moveq	#0,d0\n\
2:\n" },
I 19

E 19
I 17
D 21
	{ "_RANG4\n",
E 21
I 21
	{ 3, "_RANG4\n",
E 21
D 19
"	movl	sp@,d0\n\
	cmpl	sp@(4),d0\n\
E 19
I 19
"	movl	sp@+,d0\n\
	movl	sp@+,a0\n\
	movl	sp@+,a1\n\
	cmpl	a0,d0\n\
E 19
	jlt	1f\n\
D 19
	cmpl	sp@(8),d0\n\
E 19
I 19
	cmpl	a1,d0\n\
E 19
	jle	2f\n\
1:\n\
	pea	_ERANG\n\
	jbsr	_ERROR\n\
	addqw	#4,sp\n\
2:\n" },
D 21
	{ "_RSNG4\n",
E 21
I 21
	{ 2, "_RSNG4\n",
E 21
D 19
"	movl	sp@,d0\n\
	cmpl	sp@(4),d0\n\
E 19
I 19
"	movl	sp@+,a0\n\
	movl	sp@+,a1\n\
	cmpl	a1,a0\n\
E 19
	jls	1f\n\
	pea	_ERANG\n\
	jbsr	_ERROR\n\
	addqw	#4,sp\n\
1:\n" },
I 19

D 21
	{ "_SUBSC\n",
E 21
I 21
	{ 3, "_SUBSC\n",
E 21
"	movl	sp@+,d0\n\
	movl	sp@+,a0\n\
	movl	sp@+,a1\n\
	cmpl	a0,d0\n\
	jlt	1f\n\
	cmpl	a1,d0\n\
	jle	2f\n\
1:\n\
	pea	_ESUBSC\n\
	jbsr	_ERROR\n\
	addqw	#4,sp\n\
2:\n" },

D 21
	{ "_SUBSCZ\n",
E 21
I 21
	{ 2, "_SUBSCZ\n",
E 21
"	movl	sp@+,a0\n\
	movl	sp@+,a1\n\
	cmpl	a1,a0\n\
	jls	1f\n\
	pea	_ESUBSC\n\
	jbsr	_ERROR\n\
	addqw	#4,sp\n\
1:\n" },

E 19
D 18

E 18
E 17
E 14
#endif mc68000

I 22
#ifdef tahoe
	{ 2, "_TRUNC\n",
"	ldd	(sp)\n\
	movab	8(sp),sp\n\
	cvdl	r0\n" },

	{ 1, "_ACTFILE\n",
"	movl	(sp)+,r1\n\
	movl	12(r1),r0\n" },

/*
 * Pascal set operations.
 */

	{ 4, "_ADDT\n",
"	movl	(sp)+,r0\n\
	movl	(sp)+,r1\n\
	movl	(sp)+,r2\n\
D 24
	movl	(sp)+,r4\n\
	movl	r0,r3\n\
	clrl	r5\n\
E 24
I 24
	movl	(sp)+,r3\n\
	clrl	r4\n\
E 24
1:\n\
D 24
	orl3	(r1),(r2),(r3)\n\
	addl2	$4,r1\n\
	addl2	$4,r2\n\
	addl2	$4,r3\n\
	aoblss	r4,r5,1b\n" },
E 24
I 24
	orl3	(r1)[r4],(r2)[r4],(r0)[r4]\n\
	aoblss	r3,r4,1b\n" },
E 24

	{ 4, "_SUBT\n",
"	movl	(sp)+,r0\n\
	movl	(sp)+,r1\n\
	movl	(sp)+,r2\n\
D 24
	movl	(sp)+,r4\n\
	movl	r0,r3\n\
E 24
I 24
	movl	(sp)+,r3\n\
	decl	r3\n\
E 24
1:\n\
D 24
	mcoml	(r2),r5\n\
	andl3	r5,(r1),(r3)\n\
	addl2	$4,r1\n\
	addl2	$4,r2\n\
	addl2	$4,r3\n\
	decl	r4\n\
	jgtr	1b\n" },
E 24
I 24
	mcoml	(r2)[r3],r4\n\
	andl3	r4,(r1)[r3],(r0)[r3]\n\
	decl	r3\n\
	jgeq	1b\n" },
E 24

	{ 4, "_MULT\n",
"	movl	(sp)+,r0\n\
	movl	(sp)+,r1\n\
	movl	(sp)+,r2\n\
D 24
	movl	(sp)+,r4\n\
	movl	r0,r3\n\
	clrl	r5\n\
E 24
I 24
	movl	(sp)+,r3\n\
	clrl	r4\n\
E 24
1:\n\
D 24
	andl3	(r1),(r2),(r3)\n\
	addl2	$4,r1\n\
	addl2	$4,r2\n\
	addl2	$4,r3\n\
	aoblss	r4,r5,1b\n" },
E 24
I 24
	andl3	(r1)[r4],(r2)[r4],(r0)[r4]\n\
	aoblss	r3,r4,1b\n" },
E 24

I 23
	{ 4, "_IN\n",
"	movl	(sp)+,r1\n\
	movl	(sp)+,r2\n\
	movl	(sp)+,r3\n\
	movl	(sp)+,r4\n\
	clrl	r0\n\
	subl2	r2,r1\n\
	cmpl	r1,r3\n\
	jgtru	1f\n\
	shrl	$3,r1,r2\n\
	movzbl	(r4)[r2],r3\n\
	andl2	$7,r1\n\
	jbc	r1,r3,1f\n\
	incl	r0\n\
1:\n" },

E 23
/*
 * Pascal runtime checks
 */
	{ 1, "_ASRT\n",
"	movl	(sp)+,r0\n\
	tstl	r0\n\
	jneq	1f\n\
	pushl	$0\n\
	pushl	$_EASRT\n\
	callf	$12,_ERROR\n\
1:\n" },

	{ 2, "_ASRTS\n",
"	movl	(sp)+,r0\n\
	movl	(sp)+,r1\n\
	tstl	r0\n\
	jneq	1f\n\
	pushl	r1\n\
	pushl	$_EASRTS\n\
	callf	$12,_ERROR\n\
1:\n" },

	{ 1, "_CHR\n",
"	movl	(sp)+,r0\n\
	cmpl	r0,$127\n\
	jlequ	1f\n\
	pushl	r0\n\
	pushl	$_ECHR\n\
	callf	$12,_ERROR\n\
1:\n" },

	{ 0, "_LINO\n",
"	incl	__stcnt\n\
	cmpl	__stcnt,__stlim\n\
	jlss	1f\n\
	pushl	__stcnt\n\
	pushl	$_ELINO\n\
	callf	$12,_ERROR\n\
1:\n" },

	{ 1, "_NIL\n",
"	movl	(sp)+,r0\n\
	cmpl	r0,__maxptr\n\
	jgtr	1f\n\
	cmpl	r0,__minptr\n\
	jgeq	2f\n\
1:\n\
	pushl	$0\n\
	pushl	$_ENIL\n\
	callf	$12,_ERROR\n\
2:\n" },

	{ 3, "_RANG4\n",
"	movl	(sp)+,r0\n\
	movl	(sp)+,r1\n\
	movl	(sp)+,r2\n\
	cmpl	r0,r1\n\
	jlss	1f\n\
	cmpl	r0,r2\n\
	jleq	2f\n\
1:\n\
	pushl	r0\n\
	pushl	$_ERANG\n\
	callf	$12,_ERROR\n\
2:\n" },

	{ 2, "_RSNG4\n",
"	movl	(sp)+,r0\n\
	movl	(sp)+,r1\n\
	cmpl	r0,r1\n\
	jlequ	1f\n\
	pushl	r0\n\
	pushl	$_ERANG\n\
	callf	$12,_ERROR\n\
1:\n" },

	{ 1, "_SEED\n",
"	movl	(sp)+,r1\n\
	movl	__seed,r0\n\
	movl	r1,__seed\n" },

	{ 3, "_SUBSC\n",
"	movl	(sp)+,r0\n\
	movl	(sp)+,r1\n\
	movl	(sp)+,r2\n\
	cmpl	r0,r1\n\
	jlss	1f\n\
	cmpl	r0,r2\n\
	jleq	2f\n\
1:\n\
	pushl	r0\n\
	pushl	$_ESUBSC\n\
	callf	$12,_ERROR\n\
2:\n" },

	{ 2, "_SUBSCZ\n",
"	movl	(sp)+,r0\n\
	movl	(sp)+,r1\n\
	cmpl	r0,r1\n\
	jlequ	1f\n\
	pushl	r0\n\
	pushl	$_ESUBSC\n\
	callf	$12,_ERROR\n\
1:\n" },
#endif tahoe

E 22
I 18
D 21
	{ "", "" }
E 21
I 21
	{ 0, "", "" }
E 21
E 18
E 13
E 12
E 4
E 3
};
D 18

struct pats		*htbl[HSHSIZ];


D 6
#define	CHK(c)	if (*cp++ != c) goto copy;

E 6
#define HASH(cp, hp) {\
	hash = 0; rehash = 1; ccp = cp; \
	do	{ \
		hash *= (int)*ccp++; \
	} while (*ccp && *ccp != '\n'); \
	hash >>= 7; hash %= HSHSIZ; hp = &htbl[hash]; size = ccp - cp + 1; \
	}

#define REHASH(hp) {\
	hp += rehash; rehash += 2; \
	if (hp >= &htbl[HSHSIZ]) \
		hp -= HSHSIZ; \
	}


main(argc, argv)

	int	argc;
	char	**argv;
{
	register struct pats	*pp;
	register struct pats	**hp;
D 6
	register char		*cp, *ccp;
E 6
I 6
	register char		*cp, *ccp, *lp;
E 6
	register int		hash, rehash, size;
	char			line[BUFSIZ];
I 6
	extern char		*index();
E 6

	if (argc > 1)
		freopen(argv[1], "r", stdin);
	if (argc > 2)
		freopen(argv[2], "w", stdout);
	/*
	 * set up the hash table
	 */
	for(pp = ptab; pp < &ptab[sizeof ptab/sizeof ptab[0]]; pp++) {
		HASH(pp->name, hp);
		while (*hp)
			REHASH(hp);
		*hp = pp;
	}
	/*
	 * check each line and replace as appropriate
	 */
	while (fgets(line, BUFSIZ, stdin)) {
D 6
		for (cp = line; *cp && *cp == '\t'; )
E 6
I 6
		lp = index(line, ':');
		for (cp = (lp != NULL) ? ++lp : line; *cp == '\t'; )
E 6
			cp++;
D 3
		CHK('c'); CHK('a'); CHK('l'); CHK('l'); CHK('s'); CHK('\t');
		CHK('$'); if (!isdigit(*cp++)) goto copy; CHK(','); CHK('_');
E 3
I 3
D 6
		CHK('c'); CHK('a'); CHK('l'); CHK('l'); CHK('s');
		CHK('\t'); CHK('$');
E 6
I 6
D 13
		if (strcmpn(cp, "calls\t$", 7) != 0) {
E 13
I 13
D 16
		if (strcmpn(cp, CALLTEMPLATE, TEMPLATESIZE) != 0) {
E 16
I 16
		if (strncmp(cp, CALLTEMPLATE, TEMPLATESIZE) != 0) {
E 16
E 13
			fputs(line, stdout);
			continue;
		}
D 14
		cp += 7;
E 14
I 14
		cp += TEMPLATESIZE;
E 14
E 6
E 3
		HASH(cp, hp);
		while (*hp) {
D 6
			if (RELEQ(size, (*hp)->name, cp)) {
E 6
I 6
D 16
			if (strcmpn((*hp)->name, cp, size)==NULL) {
E 16
I 16
			if (strncmp((*hp)->name, cp, size)==NULL) {
E 16
D 7
				fprintf(stderr, "name = %s\n", (*hp)->name);
E 7
				if (lp != NULL) {
					*lp++ = '\n';
					*lp = '\0';
					fputs(line, stdout);
				}
E 6
				fputs((*hp)->replace, stdout);
				goto nextline;
			}
			REHASH(hp);
		}
D 6
copy:
E 6
		fputs(line, stdout);
nextline:;
	}
	exit(0);
}
E 18
E 1
