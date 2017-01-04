h27658
s 00008/00000/00172
d D 1.5 86/11/25 15:40:47 sam 5 4
c add spl4 and spl5 for new device drivers
e
s 00003/00000/00169
d D 1.4 86/11/01 09:18:32 sam 4 3
c add movpsl for kdb
e
s 00032/00271/00137
d D 1.3 86/02/24 22:27:11 sam 3 2
c update from monet: check number of arguments in pattern calls
e
s 00157/00006/00251
d D 1.2 86/01/05 18:49:57 sam 2 1
c 1st working version (mostly)
e
s 00257/00000/00000
d D 1.1 85/07/25 17:44:07 sam 1 0
c date and time created 85/07/25 17:44:07 by sam
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
static char sccsid[] = "@(#)langpats.c	2.9 (Berkeley) 6/8/85";
#endif not lint
E 2
I 2
static char sccsid[] = "%W% (Berkeley) %G%";
#endif
E 2

#include "inline.h"

/*
 * Pattern table for kernel specific routines.
 * These patterns are based on the old asm.sed script.
 */
struct pats language_ptab[] = {

D 2
#ifdef vax
E 2
I 2
D 3
#if defined(vax)
E 2
	{ "0,_spl0\n",
"	mfpr	$18,r0\n\
	mtpr	$0,$18\n" },

	{ "0,_spl1\n",
"	mfpr	$18,r0\n\
	mtpr	$1,$18\n" },

	{ "0,_splsoftclock\n",
"	mfpr	$18,r0\n\
	mtpr	$0x8,$18\n" },

	{ "0,_splnet\n",
"	mfpr	$18,r0\n\
	mtpr	$0xc,$18\n" },

	{ "0,_splimp\n",
"	mfpr	$18,r0\n\
	mtpr	$0x16,$18\n" },

	{ "0,_spl4\n",
"	mfpr	$18,r0\n\
	mtpr	$0x14,$18\n" },

	{ "0,_splbio\n",
"	mfpr	$18,r0\n\
	mtpr	$0x15,$18\n" },

	{ "0,_spltty\n",
"	mfpr	$18,r0\n\
	mtpr	$0x15,$18\n" },

	{ "0,_spl5\n",
"	mfpr	$18,r0\n\
	mtpr	$0x15,$18\n" },

	{ "0,_splclock\n",
"	mfpr	$18,r0\n\
	mtpr	$0x18,$18\n" },

	{ "0,_spl6\n",
"	mfpr	$18,r0\n\
	mtpr	$0x18,$18\n" },

	{ "0,_splhigh\n",
"	mfpr	$18,r0\n\
	mtpr	$0x1f,$18\n" },

	{ "0,_spl7\n",
"	mfpr	$18,r0\n\
	mtpr	$0x1f,$18\n" },

	{ "1,_splx\n",
"	movl	(sp)+,r1\n\
	mfpr	$18,r0\n\
	mtpr	r1,$18\n" },

	{ "1,_mfpr\n",
"	movl	(sp)+,r5\n\
	mfpr	r5,r0\n" },

	{ "2,_mtpr\n",
"	movl	(sp)+,r4\n\
	movl	(sp)+,r5\n\
	mtpr	r5,r4\n" },

	{ "0,_setsoftclock\n",
"	mtpr	$0x8,$0x14\n" },

	{ "1,_resume\n",
"	movl	(sp)+,r5\n\
	ashl	$9,r5,r0\n\
	movpsl	-(sp)\n\
	jsb	_Resume\n" },

	{ "3,_copyin\n",
"	movl	(sp)+,r1\n\
	movl	(sp)+,r3\n\
	movl	(sp)+,r5\n\
	jsb	_Copyin\n" },

	{ "3,_copyout\n",
"	movl	(sp)+,r1\n\
	movl	(sp)+,r3\n\
	movl	(sp)+,r5\n\
	jsb	_Copyout\n" },

	{ "1,_fubyte\n",
"	movl	(sp)+,r0\n\
	jsb	_Fubyte\n" },

	{ "1,_fuibyte\n",
"	movl	(sp)+,r0\n\
	jsb	_Fubyte\n" },

	{ "1,_fuword\n",
"	movl	(sp)+,r0\n\
	jsb	_Fuword\n" },

	{ "1,_fuiword\n",
"	movl	(sp)+,r0\n\
	jsb	_Fuword\n" },

	{ "2,_subyte\n",
"	movl	(sp)+,r0\n\
	movl	(sp)+,r1\n\
	jsb	_Subyte\n" },

	{ "2,_suibyte\n",
"	movl	(sp)+,r0\n\
	movl	(sp)+,r1\n\
	jsb	_Subyte\n" },

	{ "2,_suword\n",
"	movl	(sp)+,r0\n\
	movl	(sp)+,r1\n\
	jsb	_Suword\n" },

	{ "2,_suiword\n",
"	movl	(sp)+,r0\n\
	movl	(sp)+,r1\n\
	jsb	_Suword\n" },

	{ "1,_setrq\n",
"	movl	(sp)+,r0\n\
	jsb	_Setrq\n" },

	{ "1,_remrq\n",
"	movl	(sp)+,r0\n\
	jsb	_Remrq\n" },

	{ "0,_swtch\n",
"	movpsl	-(sp)\n\
	jsb	_Swtch\n" },

	{ "1,_setjmp\n",
"	movl	(sp)+,r1\n\
	clrl	r0\n\
	movl	fp,(r1)+\n\
	moval	1(pc),(r1)\n" },

	{ "1,_longjmp\n",
"	movl	(sp)+,r0\n\
	jsb	_Longjmp\n" },

	{ "1,_ffs\n",
"	movl	(sp)+,r1\n\
	ffs	$0,$32,r1,r0\n\
	bneq	1f\n\
	mnegl	$1,r0\n\
1:\n\
	incl	r0\n" },

	{ "1,_htons\n",
"	movl	(sp)+,r5\n\
	rotl	$8,r5,r0\n\
	rotl	$-8,r5,r1\n\
	movb	r1,r0\n\
	movzwl	r0,r0\n" },

	{ "1,_ntohs\n",
"	movl	(sp)+,r5\n\
	rotl	$8,r5,r0\n\
	rotl	$-8,r5,r1\n\
	movb	r1,r0\n\
	movzwl	r0,r0\n" },

	{ "1,_htonl\n",
"	movl	(sp)+,r5\n\
	rotl	$-8,r5,r0\n\
	insv	r0,$16,$8,r0\n\
	rotl	$8,r5,r1\n\
	movb	r1,r0\n" },

	{ "1,_ntohl\n",
"	movl	(sp)+,r5\n\
	rotl	$-8,r5,r0\n\
	insv	r0,$16,$8,r0\n\
	rotl	$8,r5,r1\n\
	movb	r1,r0\n" },

	{ "2,__insque\n",
"	movl	(sp)+,r4\n\
	movl	(sp)+,r5\n\
	insque	(r4),(r5)\n" },

	{ "1,__remque\n",
"	movl	(sp)+,r5\n\
	remque	(r5),r0\n" },

	{ "2,__queue\n",
"	movl	(sp)+,r0\n\
	movl	(sp)+,r1\n\
	insque	(r1),*4(r0)\n" },

	{ "1,__dequeue\n",
"	movl	(sp)+,r0\n\
	remque	*(r0),r0\n" },

	{ "2,_imin\n",
"	movl	(sp)+,r0\n\
	movl	(sp)+,r5\n\
	cmpl	r0,r5\n\
	bleq	1f\n\
	movl	r5,r0\n\
1:\n" },

	{ "2,_imax\n",
"	movl	(sp)+,r0\n\
	movl	(sp)+,r5\n\
	cmpl	r0,r5\n\
	bgeq	1f\n\
	movl	r5,r0\n\
1:\n" },

	{ "2,_min\n",
"	movl	(sp)+,r0\n\
	movl	(sp)+,r5\n\
	cmpl	r0,r5\n\
	blequ	1f\n\
	movl	r5,r0\n\
1:\n" },

	{ "2,_max\n",
"	movl	(sp)+,r0\n\
	movl	(sp)+,r5\n\
	cmpl	r0,r5\n\
	bgequ	1f\n\
	movl	r5,r0\n\
1:\n" },
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
	{ "4,_spl0\n",
E 3
I 3
	{ 0, "_spl0\n",
E 3
"	mfpr	$8,r0\n\
	mtpr	$0,$8\n" },

D 3
	{ "4,_spl1\n",
E 3
I 3
	{ 0, "_spl1\n",
E 3
"	mfpr	$8,r0\n\
	mtpr	$0x11,$8\n" },

D 3
	{ "4,_spl3\n",
E 3
I 3
	{ 0, "_spl3\n",
E 3
"	mfpr	$8,r0\n\
	mtpr	$0x13,$8\n" },

I 5
	{ 0, "_spl4\n",
"	mfpr	$8,r0\n\
	mtpr	$0x14,$8\n" },

	{ 0, "_spl5\n",
"	mfpr	$8,r0\n\
	mtpr	$0x15,$8\n" },

E 5
D 3
	{ "4,_spl7\n",
E 3
I 3
	{ 0, "_spl7\n",
E 3
"	mfpr	$8,r0\n\
	mtpr	$0x17,$8\n" },

D 3
	{ "4,_spl8\n",
E 3
I 3
	{ 0, "_spl8\n",
E 3
"	mfpr	$8,r0\n\
	mtpr	$0x18,$8\n" },

D 3
	{ "4,_splimp\n",
E 3
I 3
	{ 0, "_splimp\n",
E 3
"	mfpr	$8,r0\n\
	mtpr	$0x18,$8\n" },

D 3
	{ "4,_splsoftclock\n",
E 3
I 3
	{ 0, "_splsoftclock\n",
E 3
"	mfpr	$18,r0\n\
	mtpr	$0x8,$8\n" },

D 3
	{ "4,_splnet\n",
E 3
I 3
	{ 0, "_splnet\n",
E 3
"	mfpr	$8,r0\n\
	mtpr	$0xc,$8\n" },

D 3
	{ "4,_splbio\n",
E 3
I 3
	{ 0, "_splbio\n",
E 3
"	mfpr	$8,r0\n\
	mtpr	$0x18,$8\n" },

D 3
	{ "4,_spltty\n",
E 3
I 3
	{ 0, "_spltty\n",
E 3
"	mfpr	$8,r0\n\
	mtpr	$0x18,$8\n" },

D 3
	{ "4,_splclock\n",
E 3
I 3
	{ 0, "_splclock\n",
E 3
"	mfpr	$8,r0\n\
	mtpr	$0x18,$8\n" },

D 3
	{ "4,_splhigh\n",
E 3
I 3
	{ 0, "_splhigh\n",
E 3
"	mfpr	$8,r0\n\
	mtpr	$0x18,$8\n" },

D 3
	{ "8,_splx\n",
E 3
I 3
	{ 1, "_splx\n",
E 3
"	movl	(sp)+,r1\n\
	mfpr	$8,r0\n\
	mtpr	r1,$8\n" },

D 3
	{ "8,_mfpr\n",
E 3
I 3
	{ 1, "_mfpr\n",
E 3
"	movl	(sp)+,r1\n\
	mfpr	r1,r0\n" },

D 3
	{ "12,_mtpr\n",
E 3
I 3
	{ 2, "_mtpr\n",
E 3
"	movl	(sp)+,r1\n\
	movl	(sp)+,r0\n\
	mtpr	r0,r1\n" },

#ifdef notdef
D 3
	{ "8,_uncache\n",
E 3
I 3
	{ 1, "_uncache\n",
E 3
"	movl	(sp)+,r1\n\
	mtpr	r1,$0x1c\n" },
#endif

D 3
	{ "4,_setsoftclock\n",
E 3
I 3
	{ 0, "_setsoftclock\n",
E 3
"	mtpr	$0x8,$0x10\n" },

D 3
	{ "8,_fuibyte\n",
E 3
I 3
	{ 1, "_fuibyte\n",
E 3
"	callf	$8,_fubyte\n" },

D 3
	{ "8,_fuiword\n",
E 3
I 3
	{ 1, "_fuiword\n",
E 3
"	callf	$8,_fuword\n" },

D 3
	{ "12,_suibyte\n",
E 3
I 3
	{ 2, "_suibyte\n",
E 3
"	callf	$12,_subyte\n" },

D 3
	{ "12,_suiword\n",
E 3
I 3
	{ 2, "_suiword\n",
E 3
"	callf	$12,_suword\n" },

D 3
	{ "8,_setjmp\n",
E 3
I 3
	{ 1, "_setjmp\n",
E 3
"	movl	(sp)+,r1\n\
	clrl	r0\n\
	movab	(fp),(r1)\n\
	addl2	$4,r1\n\
	movab	1(pc),(r1)\n" },

D 3
	{ "8,_ffs\n",
E 3
I 3
	{ 1, "_ffs\n",
E 3
"	movl	(sp)+,r1\n\
	ffs	r1,r0\n\
	bgeq	1f\n\
	mnegl	$1,r0\n\
1:\n\
	incl	r0\n" },

D 3
	{ "12,__insque\n",
E 3
I 3
	{ 2, "__insque\n",
E 3
"	movl	(sp)+,r0\n\
	movl	(sp)+,r1\n\
	insque	(r0),(r1)\n" },

D 3
	{ "8,__remque\n",
E 3
I 3
	{ 1, "__remque\n",
E 3
"	movl	(sp)+,r1\n\
	remque	(r1)\n" },

D 3
	{ "12,_imin\n",
E 3
I 3
	{ 2, "_imin\n",
E 3
"	movl	(sp)+,r0\n\
	movl	(sp)+,r1\n\
	cmpl	r0,r1\n\
	bleq	1f\n\
	movl	r1,r0\n\
1:\n" },

D 3
	{ "12,_imax\n",
E 3
I 3
	{ 2, "_imax\n",
E 3
"	movl	(sp)+,r0\n\
	movl	(sp)+,r1\n\
	cmpl	r0,r1\n\
	bgeq	1f\n\
	movl	r1,r0\n\
1:\n" },

D 3
	{ "12,_min\n",
E 3
I 3
	{ 2, "_min\n",
E 3
"	movl	(sp)+,r0\n\
	movl	(sp)+,r1\n\
	cmpl	r0,r1\n\
	blequ	1f\n\
	movl	r1,r0\n\
1:\n" },

D 3
	{ "12,_max\n",
E 3
I 3
	{ 2, "_max\n",
E 3
"	movl	(sp)+,r0\n\
	movl	(sp)+,r1\n\
	cmpl	r0,r1\n\
	bgequ	1f\n\
	movl	r1,r0\n\
1:\n" },

D 3
	{ "12,__movow\n",
E 3
I 3
	{ 2, "__movow\n",
E 3
"	movl	(sp)+,r1\n\
	movl	(sp)+,r0\n\
	movow	r0,(r1)\n" },

D 3
	{ "12,__movob\n",
E 3
I 3
	{ 2, "__movob\n",
E 3
"	movl	(sp)+,r1\n\
	movl	(sp)+,r0\n\
	movob	r0,(r1)\n" },
D 3
#endif
E 3

I 4
	{ 0, "_movpsl\n",
"	movpsl	r0\n" },

E 4
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
