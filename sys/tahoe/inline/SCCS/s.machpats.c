h44064
s 00005/00124/00044
d D 1.3 86/02/24 22:27:17 sam 3 2
c update from monet: check number of arguments in pattern calls
e
s 00039/00007/00129
d D 1.2 86/01/05 18:50:02 sam 2 1
c 1st working version (mostly)
e
s 00136/00000/00000
d D 1.1 85/07/25 17:44:09 sam 1 0
c date and time created 85/07/25 17:44:09 by sam
e
u
U
t
T
I 1
/*
 * Copyright (c) 1984 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
D 2
static char sccsid[] = "@(#)machpats.c	1.4 (Berkeley) 6/8/85";
#endif not lint
E 2
I 2
static char sccsid[] = "%W% (Berkeley) %G%";
#endif
E 2

#include "inline.h"

/*
D 2
 * Pattern table for special VAX instructions.
E 2
I 2
 * Pattern table for special instructions.
E 2
 */
struct pats machine_ptab[] = {

D 2
#ifdef vax
E 2
I 2
D 3
#if defined(vax)
E 2
	{ "3,_blkcpy\n",
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

	{ "3,_bcopy\n",
"	movl	(sp)+,r1\n\
	movl	(sp)+,r3\n\
	movl	(sp)+,r5\n\
	movc3	r5,(r1),(r3)\n" },

	{ "3,_ovbcopy\n",
"	movl	(sp)+,r3\n\
	movl	(sp)+,r4\n\
	movl	(sp)+,r5\n\
	movc3	r5,(r3),(r4)\n" },

	{ "3,_blkcmp\n",
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

	{ "3,_bcmp\n",
"	movl	(sp)+,r1\n\
	movl	(sp)+,r3\n\
	movl	(sp)+,r5\n\
	cmpc3	r5,(r1),(r3)\n" },

	{ "2,_blkclr\n",
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

	{ "2,_bzero\n",
"	movl	(sp)+,r3\n\
	movl	(sp)+,r5\n\
	movc5	$0,(r3),$0,r5,(r3)\n" },

	{ "3,_llocc\n",
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

	{ "3,_locc\n",
"	movl	(sp)+,r3\n\
	movl	(sp)+,r4\n\
	movl	(sp)+,r5\n\
	locc	r3,r4,(r5)\n" },

	{ "4,_scanc\n",
"	movl	(sp)+,r2\n\
	movl	(sp)+,r3\n\
	movl	(sp)+,r4\n\
	movl	(sp)+,r5\n\
	scanc	r2,(r3),(r4),r5\n" },

	{ "3,_skpc\n",
"	movl	(sp)+,r3\n\
	movl	(sp)+,r4\n\
	movl	(sp)+,r5\n\
	skpc	r3,r4,(r5)\n" },

	{ "2,_insque\n",
"	movl	(sp)+,r4\n\
	movl	(sp)+,r5\n\
	insque	(r4),(r5)\n" },

	{ "1,_remque\n",
"	movl	(sp)+,r5\n\
	remque	(r5),r0\n" },
D 2
#endif vax
E 2
I 2
#endif
E 2

D 2
#ifdef mc68000
E 2
I 2
#if defined(tahoe)
	{ "16,_blkcpy\n",
E 3
I 3
	{ 3, "_blkcpy\n",
E 3
"	movl	(sp)+,r0\n\
	movl	(sp)+,r1\n\
	movl	(sp)+,r2\n\
	movblk\n" },

D 3
	{ "16,_bcopy\n",
E 3
I 3
	{ 3, "_bcopy\n",
E 3
"	movl	(sp)+,r0\n\
	movl	(sp)+,r1\n\
	movl	(sp)+,r2\n\
	movblk\n" },

D 3
	{ "12,_bzero\n",
E 3
I 3
	{ 2, "_bzero\n",
E 3
"	movl	(sp)+,r1\n\
	movl	(sp)+,r2\n\
	movab	1f,r0\n\
	movs3\n\
	.data\n\
1:	.byte	0\n\
	.text\n" },

D 3
	{ "12,_blkclr\n",
E 3
I 3
	{ 2, "_blkclr\n",
E 3
"	movl	(sp)+,r1\n\
	movl	(sp)+,r2\n\
	movab	1f,r0\n\
	movs3\n\
	.data\n\
1:	.byte	0\n\
	.text\n" },
D 3
#endif
E 3

D 3
#if defined(mc68000)
E 2
/* someday... */
D 2
#endif mc68000
E 2
I 2
#endif
E 2

	{ "", "" }
E 3
I 3
	{ 0, "", "" }
E 3
};
E 1
