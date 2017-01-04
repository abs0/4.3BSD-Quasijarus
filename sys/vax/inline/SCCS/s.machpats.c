h63632
s 00004/00000/00203
d D 7.3 89/11/30 18:26:39 mckusick 9 8
c have to add tstl instructions because of moving instructions
e
s 00008/00008/00195
d D 7.2 89/09/25 12:38:33 sklower 8 7
c fix bcmp for zero length compare and others for microvaxen
e
s 00001/00001/00202
d D 7.1 86/06/05 01:12:41 mckusick 7 6
c 4.3BSD release version
e
s 00094/00027/00109
d D 1.6 86/04/27 20:53:59 karels 6 5
c break out tables for subset vax on -s option; for kridle and bloom
e
s 00014/00014/00122
d D 1.5 85/08/21 20:19:48 mckusick 5 4
c do validity checking on number of arguments (from donn@utah-cs)
e
s 00006/00002/00130
d D 1.4 85/06/08 14:24:06 mckusick 4 3
c Add copyright
e
s 00001/00001/00131
d D 1.3 84/08/19 12:55:46 mckusick 3 2
c fix count on bzero
e
s 00001/00001/00131
d D 1.2 84/08/18 18:04:55 mckusick 2 1
c change name of header file from pc2.h to inline.h
e
s 00132/00000/00000
d D 1.1 84/08/18 17:35:39 mckusick 1 0
c date and time created 84/08/18 17:35:39 by mckusick
e
u
U
t
T
I 1
D 4
/* Copyright (c) 1984 Regents of the University of California */
E 4
I 4
/*
D 7
 * Copyright (c) 1984 Regents of the University of California.
E 7
I 7
 * Copyright (c) 1984, 1986 Regents of the University of California.
E 7
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 4

#ifndef lint
D 4
static char sccsid[] = "%W%	(Berkeley)	%G%";
E 4
I 4
static char sccsid[] = "%W% (Berkeley) %G%";
E 4
#endif not lint

D 2
#include "pc2.h"
E 2
I 2
#include "inline.h"
E 2

/*
 * Pattern table for special VAX instructions.
 */
struct pats machine_ptab[] = {

#ifdef vax
D 5
	{ "3,_blkcpy\n",
E 5
I 5
	{ 3, "_blkcpy\n",
E 5
"	movl	(sp)+,r1\n\
	movl	(sp)+,r3\n\
	jbr	2f\n\
1:\n\
	subl2	r0,(sp)\n\
	movc3	r0,(r1),(r3)\n\
2:\n\
	movzwl	$65535,r0\n\
	cmpl	(sp),r0\n\
	jgtr	1b\n\
	movl	(sp)+,r0\n\
	movc3	r0,(r1),(r3)\n" },

D 5
	{ "3,_bcopy\n",
E 5
I 5
	{ 3, "_bcopy\n",
E 5
"	movl	(sp)+,r1\n\
	movl	(sp)+,r3\n\
	movl	(sp)+,r5\n\
	movc3	r5,(r1),(r3)\n" },

D 5
	{ "3,_ovbcopy\n",
E 5
I 5
	{ 3, "_ovbcopy\n",
E 5
"	movl	(sp)+,r3\n\
	movl	(sp)+,r4\n\
	movl	(sp)+,r5\n\
	movc3	r5,(r3),(r4)\n" },

I 6
	{ 2, "_blkclr\n",
"	movl	(sp)+,r3\n\
	jbr	2f\n\
1:\n\
	subl2	r0,(sp)\n\
	movc5	$0,(r3),$0,r0,(r3)\n\
2:\n\
	movzwl	$65535,r0\n\
	cmpl	(sp),r0\n\
	jgtr	1b\n\
	movl	(sp)+,r0\n\
	movc5	$0,(r3),$0,r0,(r3)\n" },

	{ 2, "_bzero\n",
"	movl	(sp)+,r3\n\
	movl	(sp)+,r5\n\
	movc5	$0,(r3),$0,r5,(r3)\n" },

	{ 2, "_insque\n",
"	movl	(sp)+,r4\n\
	movl	(sp)+,r5\n\
	insque	(r4),(r5)\n" },

	{ 1, "_remque\n",
"	movl	(sp)+,r5\n\
	remque	(r5),r0\n" },
#endif vax

#ifdef mc68000
/* someday... */
#endif mc68000

	{ 0, "", "" }
};

#ifdef vax

struct pats vax_ptab[] = {

E 6
D 5
	{ "3,_blkcmp\n",
E 5
I 5
	{ 3, "_blkcmp\n",
E 5
"	movl	(sp)+,r1\n\
	movl	(sp)+,r3\n\
	jbr	2f\n\
1:\n\
	subl2	r0,(sp)\n\
	cmpc3	r0,(r1),(r3)\n\
	bneq	3f\n\
2:\n\
	movzwl	$65535,r0\n\
	cmpl	(sp),r0\n\
	jgtr	1b\n\
	movl	(sp)+,r0\n\
	cmpc3	r0,(r1),(r3)\n\
3:\n" },

D 5
	{ "3,_bcmp\n",
E 5
I 5
	{ 3, "_bcmp\n",
E 5
"	movl	(sp)+,r1\n\
	movl	(sp)+,r3\n\
	movl	(sp)+,r5\n\
	cmpc3	r5,(r1),(r3)\n" },

D 5
	{ "2,_blkclr\n",
E 5
I 5
D 6
	{ 2, "_blkclr\n",
E 5
"	movl	(sp)+,r3\n\
	jbr	2f\n\
1:\n\
	subl2	r0,(sp)\n\
	movc5	$0,(r3),$0,r0,(r3)\n\
2:\n\
	movzwl	$65535,r0\n\
	cmpl	(sp),r0\n\
	jgtr	1b\n\
	movl	(sp)+,r0\n\
	movc5	$0,(r3),$0,r0,(r3)\n" },

D 3
	{ "3,_bzero\n",
E 3
I 3
D 5
	{ "2,_bzero\n",
E 5
I 5
	{ 2, "_bzero\n",
E 5
E 3
"	movl	(sp)+,r3\n\
	movl	(sp)+,r5\n\
	movc5	$0,(r3),$0,r5,(r3)\n" },

E 6
D 5
	{ "3,_llocc\n",
E 5
I 5
	{ 3, "_llocc\n",
E 5
"	movl	(sp)+,r4\n\
	movl	(sp)+,r5\n\
	movl	(sp)+,r1\n\
1:\n\
	movzwl	$65535,r0\n\
	cmpl	r5,r0\n\
	jleq	1f\n\
	subl2	r0,r5\n\
	locc	r4,r0,(r1)\n\
	jeql	1b\n\
	addl2	r5,r0\n\
	jbr	2f\n\
1:\n\
	locc	r4,r5,(r1)\n\
2:\n" },

D 5
	{ "3,_locc\n",
E 5
I 5
	{ 3, "_locc\n",
E 5
"	movl	(sp)+,r3\n\
	movl	(sp)+,r4\n\
	movl	(sp)+,r5\n\
	locc	r3,r4,(r5)\n" },

D 5
	{ "4,_scanc\n",
E 5
I 5
	{ 4, "_scanc\n",
E 5
"	movl	(sp)+,r2\n\
	movl	(sp)+,r3\n\
	movl	(sp)+,r4\n\
	movl	(sp)+,r5\n\
	scanc	r2,(r3),(r4),r5\n" },

D 5
	{ "3,_skpc\n",
E 5
I 5
	{ 3, "_skpc\n",
E 5
"	movl	(sp)+,r3\n\
	movl	(sp)+,r4\n\
	movl	(sp)+,r5\n\
	skpc	r3,r4,(r5)\n" },

D 5
	{ "2,_insque\n",
E 5
I 5
D 6
	{ 2, "_insque\n",
E 6
I 6
	{ 0, "", "" }
};

struct pats vaxsubset_ptab[] = {

	{ 3, "_blkcmp\n",
"	movl	(sp)+,r1\n\
	movl	(sp)+,r3\n\
	movl	(sp)+,r0\n\
2:\n\
	cmpb	(r1)+,(r3)+\n\
	jneq	3f\n\
	sobgtr	r0,2b\n\
3:\n" },

	{ 3, "_bcmp\n",
"	movl	(sp)+,r1\n\
	movl	(sp)+,r3\n\
D 8
	movl	(sp)+,r5\n\
	movl	r5,r0\n\
E 8
I 8
	movl	(sp)+,r0\n\
I 9
	tstl	r0\n\
E 9
	jeql	1f\n\
E 8
2:\n\
	cmpb	(r1)+,(r3)+\n\
	jneq	1f\n\
	sobgtr	r0,2b\n\
1:\n" },

	{ 3, "_llocc\n",
E 6
E 5
"	movl	(sp)+,r4\n\
D 8
	movl	(sp)+,r5\n\
E 8
I 8
	movl	(sp)+,r0\n\
I 9
	tstl	r0\n\
E 9
	jeql	1f\n\
E 8
D 6
	insque	(r4),(r5)\n" },
E 6
I 6
	movl	(sp)+,r1\n\
D 8
	movl	r5,r0\n\
E 8
2:\n\
	cmpb	r4,(r1)+\n\
	jeql	1f\n\
	sobgtr	r0,2b\n\
1:\n" },
E 6

D 5
	{ "1,_remque\n",
E 5
I 5
D 6
	{ 1, "_remque\n",
E 5
"	movl	(sp)+,r5\n\
	remque	(r5),r0\n" },
#endif vax
E 6
I 6
	{ 3, "_locc\n",
"	movl	(sp)+,r3\n\
D 8
	movl	(sp)+,r4\n\
E 8
I 8
	movl	(sp)+,r0\n\
I 9
	tstl	r0\n\
E 9
	jeql	1f\n\
E 8
	movl	(sp)+,r5\n\
D 8
	movl	r4,r0\n\
E 8
2:\n\
	cmpb	r3,(r5)+\n\
	jeql	1f\n\
	sobgtr	r0,2b\n\
1:\n" },
E 6

D 6
#ifdef mc68000
/* someday... */
#endif mc68000
E 6
I 6
	{ 3, "_skpc\n",
"	movl	(sp)+,r3\n\
D 8
	movl	(sp)+,r4\n\
E 8
I 8
	movl	(sp)+,r0\n\
I 9
	tstl	r0\n\
E 9
	jeql	1f\n\
E 8
	movl	(sp)+,r5\n\
D 8
	movl	r4,r0\n\
E 8
2:\n\
	cmpb	r3,(r5)+\n\
	jneq	1f\n\
	sobgtr	r0,2b\n\
1:\n" },
E 6

D 5
	{ "", "" }
E 5
I 5
	{ 0, "", "" }
E 5
};
I 6
#endif
E 6
E 1
