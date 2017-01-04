h19155
s 00001/00001/00255
d D 7.1 86/06/05 01:11:50 mckusick 19 18
c 4.3BSD release version
e
s 00007/00007/00249
d D 2.12 86/02/23 23:37:26 karels 18 17
c make spl6, slp7 be ipl 16, 17 resp.
e
s 00002/00003/00254
d D 2.11 86/02/23 19:08:15 karels 17 16
c splx need not return previous priority
e
s 00047/00047/00210
d D 2.10 85/08/21 20:19:39 mckusick 16 15
c do validity checking on number of arguments (from donn@utah-cs)
e
s 00006/00002/00251
d D 2.9 85/06/08 14:22:04 mckusick 15 14
c Add copyright
e
s 00000/00006/00253
d D 2.8 85/02/20 15:14:27 mckusick 14 13
c remove bogus strncmp expansion
e
s 00001/00005/00258
d D 2.7 85/02/20 11:28:18 karels 13 12
c splhigh is 1f again; don't need splextreme
e
s 00001/00001/00262
d D 2.6 84/11/19 15:38:04 mckusick 12 11
c fix queue pattern (from chris@maryland)
e
s 00005/00001/00258
d D 2.5 84/11/16 09:49:55 karels 11 10
c splhigh should be ipl 18; add "splextreme" for spl7
e
s 00008/00004/00251
d D 2.4 84/08/23 16:45:14 mckusick 10 8
c copyin and copyout now take their parameters in registers
e
s 00008/00004/00251
d R 2.4 84/08/22 19:55:28 mckusick 9 8
c copyin and copyout now take their parameters in registers
e
s 00032/00000/00223
d D 2.3 84/08/22 19:06:40 mckusick 8 7
c add imin, imax, min, and max as inline expansions
e
s 00011/00007/00212
d D 2.2 84/08/20 19:11:46 mckusick 7 6
c fix expansions for htons, ntohs, htonl, and ntohl
e
s 00106/00220/00113
d D 2.1 84/08/19 12:54:54 mckusick 6 5
c subsume Kernel dependent part of asm.c
e
s 00004/00002/00329
d D 1.5 84/08/12 00:18:13 mckusick 5 4
c setjmp is now expanded inline
e
s 00004/00000/00327
d D 1.4 84/07/28 16:34:55 mckusick 4 3
c add `skpc' instruction
e
s 00004/00000/00323
d D 1.3 84/07/27 15:35:02 karels 3 2
c add splhigh
e
s 00057/00081/00266
d D 1.2 84/05/12 20:44:28 sam 2 1
c pattern match only the routine being called (use lint to catch 
c incorrect calling sequences)
e
s 00347/00000/00000
d D 1.1 84/05/12 17:44:09 sam 1 0
c date and time created 84/05/12 17:44:09 by sam
e
u
U
t
T
I 6
D 15
/* Copyright (c) 1984 Regents of the University of California */
E 15
I 15
/*
D 19
 * Copyright (c) 1984 Regents of the University of California.
E 19
I 19
 * Copyright (c) 1984, 1986 Regents of the University of California.
E 19
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 15

E 6
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 15
#endif
E 15
I 15
#endif not lint
E 15

D 6
/*
 * In-line assembly code expander for
D 2
 * the kernel.  This code is stolen from
E 2
I 2
 * the kernel.  This code is based on
E 2
 * pc2 and the old asm.sed script.
 */
#include <stdio.h>
#include <ctype.h>
E 6
I 6
#include "inline.h"
E 6

/*
D 6
 * The hash table must be at least twice as big as the number
 * of patterns, preferably bigger. It must also be a prime number
E 6
I 6
 * Pattern table for kernel specific routines.
 * These patterns are based on the old asm.sed script.
E 6
 */
D 6
#define HSHSIZ	139
E 6
I 6
struct pats language_ptab[] = {
E 6

D 6
/*
 * Pattern table.
 */
struct pats {
	char	*name;
	char	*replace;
} ptab[] = {
D 2
	{ "$0,_spl0\n",
E 2
I 2
	{ "_spl0\n",
E 6
I 6
#ifdef vax
D 16
	{ "0,_spl0\n",
E 16
I 16
	{ 0, "_spl0\n",
E 16
E 6
E 2
"	mfpr	$18,r0\n\
	mtpr	$0,$18\n" },

D 2
	{ "$0,_spl1\n",
E 2
I 2
D 6
	{ "_spl1\n",
E 6
I 6
D 16
	{ "0,_spl1\n",
E 16
I 16
	{ 0, "_spl1\n",
E 16
E 6
E 2
"	mfpr	$18,r0\n\
	mtpr	$1,$18\n" },

D 2
	{ "$0,_splsoftclock\n",
E 2
I 2
D 6
	{ "_splsoftclock\n",
E 6
I 6
D 16
	{ "0,_splsoftclock\n",
E 16
I 16
	{ 0, "_splsoftclock\n",
E 16
E 6
E 2
"	mfpr	$18,r0\n\
	mtpr	$0x8,$18\n" },

D 2
	{ "$0,_splnet\n",
E 2
I 2
D 6
	{ "_splnet\n",
E 6
I 6
D 16
	{ "0,_splnet\n",
E 16
I 16
	{ 0, "_splnet\n",
E 16
E 6
E 2
"	mfpr	$18,r0\n\
	mtpr	$0xc,$18\n" },

D 2
	{ "$0,_splimp\n",
E 2
I 2
D 6
	{ "_splimp\n",
E 6
I 6
D 16
	{ "0,_splimp\n",
E 16
I 16
	{ 0, "_splimp\n",
E 16
E 6
E 2
"	mfpr	$18,r0\n\
	mtpr	$0x16,$18\n" },

D 2
	{ "$0,_spl4\n",
E 2
I 2
D 6
	{ "_spl4\n",
E 6
I 6
D 16
	{ "0,_spl4\n",
E 16
I 16
	{ 0, "_spl4\n",
E 16
E 6
E 2
"	mfpr	$18,r0\n\
	mtpr	$0x14,$18\n" },

D 2
#ifdef notdef
	{ "r[0-9]*,_spl4\n",
E 2
I 2
D 6
	{ "_splbio\n",
E 6
I 6
D 16
	{ "0,_splbio\n",
E 16
I 16
	{ 0, "_splbio\n",
E 16
E 6
E 2
"	mfpr	$18,r0\n\
D 2
	mtpr	$0x14,$18\n" },
#endif

	{ "$0,_splbio",
"	mfpr	$18,r0\n\
E 2
	mtpr	$0x15,$18\n" },

D 2
#ifdef notdef
	{ "r[0-9]*,_splbio",
E 2
I 2
D 6
	{ "_spltty\n",
E 6
I 6
D 16
	{ "0,_spltty\n",
E 16
I 16
	{ 0, "_spltty\n",
E 16
E 6
E 2
"	mfpr	$18,r0\n\
	mtpr	$0x15,$18\n" },
D 2
#endif
E 2

D 2
	{ "$0,_spltty",
E 2
I 2
D 6
	{ "_spl5\n",
E 6
I 6
D 16
	{ "0,_spl5\n",
E 16
I 16
	{ 0, "_spl5\n",
E 16
E 6
E 2
"	mfpr	$18,r0\n\
	mtpr	$0x15,$18\n" },

D 2
#ifdef notdef
	{ "r[0-9]*,_spltty\n",
E 2
I 2
D 6
	{ "_splclock\n",
E 6
I 6
D 16
	{ "0,_splclock\n",
E 16
I 16
D 18
	{ 0, "_splclock\n",
E 18
I 18
	{ 0, "_spl6\n",
E 18
E 16
E 6
E 2
"	mfpr	$18,r0\n\
D 2
	mtpr	$0x15,$18\n" },
#endif

	{ "$0,_spl5\n", 
"	mfpr	$18,r0\n\
	mtpr	$0x15,$18\n" },

#ifdef notdef
	{ "r[0-9]*,_spl5\n",
"	mfpr	$18,r0\n\
	mtpr	$0x15,$18\n" },
#endif

	{ "$0,_splclock\n",
"	mfpr	$18,r0\n\
E 2
D 18
	mtpr	$0x18,$18\n" },
E 18
I 18
	mtpr	$0x16,$18\n" },
E 18

D 2
	{ "$0,_spl6\n",
E 2
I 2
D 6
	{ "_spl6\n",
E 6
I 6
D 16
	{ "0,_spl6\n",
E 16
I 16
D 18
	{ 0, "_spl6\n",
E 18
I 18
	{ 0, "_spl7\n",
E 18
E 16
E 6
E 2
"	mfpr	$18,r0\n\
D 18
	mtpr	$0x18,$18\n" },
E 18
I 18
	mtpr	$0x17,$18\n" },
E 18

I 11
D 16
	{ "0,_splhigh\n",
E 16
I 16
D 18
	{ 0, "_splhigh\n",
E 18
I 18
	{ 0, "_splclock\n",
E 18
E 16
"	mfpr	$18,r0\n\
D 13
	mtpr	$0x18,$18\n" },

E 11
D 2
#ifdef notdef
	{ "r[0-9]*,_spl6\n",
E 2
I 2
D 6
	{ "_spl7\n",
E 6
I 6
	{ "0,_spl7\n",
E 6
E 2
"	mfpr	$18,r0\n\
E 13
D 2
	mtpr	$0x18,$18\n" },
#endif

	{ "$0,_spl7\n",
"	mfpr	$18,r0\n\
E 2
D 18
	mtpr	$0x1f,$18\n" },
E 18
I 18
	mtpr	$0x18,$18\n" },
E 18

I 3
D 6
	{ "_splhigh\n",
E 6
I 6
D 11
	{ "0,_splhigh\n",
E 11
I 11
D 13
	{ "0,_splextreme\n",
E 13
I 13
D 16
	{ "0,_spl7\n",
E 16
I 16
D 18
	{ 0, "_spl7\n",
E 18
I 18
	{ 0, "_splhigh\n",
E 18
E 16
E 13
E 11
E 6
"	mfpr	$18,r0\n\
	mtpr	$0x1f,$18\n" },

E 3
D 2
	{ "$1,_splx\n",
E 2
I 2
D 6
	{ "_splx\n",
E 2
"	mfpr	$18,r0\n\
	mtpr	(sp)+,$18\n" },
E 6
I 6
D 16
	{ "1,_splx\n",
E 16
I 16
	{ 1, "_splx\n",
E 16
D 17
"	movl	(sp)+,r1\n\
	mfpr	$18,r0\n\
	mtpr	r1,$18\n" },
E 17
I 17
"	movl	(sp)+,r0\n\
	mtpr	r0,$18\n" },
E 17
E 6

D 2
	{ "$1,_mfpr\n",
E 2
I 2
D 6
	{ "_mfpr\n",
E 2
"	mfpr	(sp)+,r0\n" },
E 6
I 6
D 16
	{ "1,_mfpr\n",
E 16
I 16
	{ 1, "_mfpr\n",
E 16
"	movl	(sp)+,r5\n\
	mfpr	r5,r0\n" },
E 6

D 2
	{ "$2,_mtpr\n",
E 2
I 2
D 6
	{ "_mtpr\n",
E 2
"	mtpr	4(sp),(sp)\n\
	addl2	$8,sp\n" },
E 6
I 6
D 16
	{ "2,_mtpr\n",
E 16
I 16
	{ 2, "_mtpr\n",
E 16
"	movl	(sp)+,r4\n\
	movl	(sp)+,r5\n\
	mtpr	r5,r4\n" },
E 6

D 2
	{ "$0,_setsoftclock\n",
E 2
I 2
D 6
	{ "_setsoftclock\n",
E 6
I 6
D 16
	{ "0,_setsoftclock\n",
E 16
I 16
	{ 0, "_setsoftclock\n",
E 16
E 6
E 2
"	mtpr	$0x8,$0x14\n" },

D 2
	{ "$1,_resume\n",
E 2
I 2
D 6
	{ "_resume\n",
E 2
"	ashl	$9,(sp)+,r0 \n\
	movpsl	-(sp) \n\
E 6
I 6
D 16
	{ "1,_resume\n",
E 16
I 16
	{ 1, "_resume\n",
E 16
"	movl	(sp)+,r5\n\
	ashl	$9,r5,r0\n\
	movpsl	-(sp)\n\
E 6
	jsb	_Resume\n" },

D 2
	{ "$3,_bcopy\n", 
E 2
I 2
D 6
	{ "_bcopy\n", 
E 2
"	movc3	8(sp),*(sp),*4(sp)\n\
	addl2	$12,sp\n" },
E 6
I 6
D 14
	{ "3,_strncmp\n",
"	movl	(sp)+,r1\n\
	movl	(sp)+,r3\n\
	movl	(sp)+,r5\n\
	cmpc3	r5,(r1),(r3)\n" },
E 6

E 14
D 2
	{ "$3,_ovbcopy\n",
E 2
I 2
D 6
	{ "_ovbcopy\n",
E 2
"	movc3	8(sp),*(sp),*4(sp)\n\
	addl2	$12,sp\n" },

D 2
	{ "$2,_bzero\n",
E 2
I 2
	{ "_bzero\n",
E 2
"	movc5	$0,(r0),$0,4(sp),*(sp)\n\
	addl2	$8,sp\n" },

D 2
	{ "$3,_bcmp\n",
E 2
I 2
	{ "_bcmp\n",
E 2
"	popr	$0x7\n\
	cmpc3	r2,(r0),(r1)\n" },

D 2
	{ "$3,_strncmp\n",
E 2
I 2
	{ "_strncmp\n",
E 2
"	cmpc3	8(sp),*(sp),*4(sp)\n\
	addl2	$12,sp\n" },

D 2
	{ "$2,_blkclr\n",
E 2
I 2
	{ "_blkclr\n",
E 2
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

D 2
	{ "$1,_strlen\n",
E 2
I 2
	{ "_strlen\n",
E 2
"	movl	(sp),r1\n\
1:\n\
	locc	$0,$65535,(r1)\n\
	jeql	1b\n\
	subl3	(sp)+,r1,r0\n" },

D 2
	{ "$4,_scanc\n",
E 2
I 2
	{ "_scanc\n",
E 2
"	popr	$0xf\n\
	scanc	r0,(r1),(r2),r3\n" },

I 4
	{ "_skpc\n",
"	popr	$0x7\n\
	skpc	r0,r1,(r2)\n" },

E 4
D 2
	{ "$3,_copyin\n",
E 2
I 2
	{ "_copyin\n",
E 6
I 6
D 16
	{ "3,_copyin\n",
E 16
I 16
	{ 3, "_copyin\n",
E 16
E 6
E 2
D 10
"	jsb	_Copyin\n\
	addl2	$12,sp\n" },
E 10
I 10
"	movl	(sp)+,r1\n\
	movl	(sp)+,r3\n\
	movl	(sp)+,r5\n\
	jsb	_Copyin\n" },
E 10

D 2
	{ "$3,_copyout\n",
E 2
I 2
D 6
	{ "_copyout\n",
E 6
I 6
D 16
	{ "3,_copyout\n",
E 16
I 16
	{ 3, "_copyout\n",
E 16
E 6
E 2
D 10
"	jsb	_Copyout\n\
	addl2	$12,sp\n" },
E 10
I 10
"	movl	(sp)+,r1\n\
	movl	(sp)+,r3\n\
	movl	(sp)+,r5\n\
	jsb	_Copyout\n" },
E 10

D 2
	{ "$1,_fubyte\n",
E 2
I 2
D 6
	{ "_fubyte\n",
E 6
I 6
D 16
	{ "1,_fubyte\n",
E 16
I 16
	{ 1, "_fubyte\n",
E 16
E 6
E 2
"	movl	(sp)+,r0\n\
	jsb	_Fubyte\n" },

D 2
	{ "$1,_fuibyte\n",
E 2
I 2
D 6
	{ "_fuibyte\n",
E 2
"	movl (sp)+,r0\n\
E 6
I 6
D 16
	{ "1,_fuibyte\n",
E 16
I 16
	{ 1, "_fuibyte\n",
E 16
"	movl	(sp)+,r0\n\
E 6
	jsb	_Fubyte\n" },

D 2
	{ "$1,_fuword\n",
E 2
I 2
D 6
	{ "_fuword\n",
E 2
"	movl (sp)+,r0\n\
E 6
I 6
D 16
	{ "1,_fuword\n",
E 16
I 16
	{ 1, "_fuword\n",
E 16
"	movl	(sp)+,r0\n\
E 6
	jsb	_Fuword\n" },

D 2
	{ "$1,_fuiword\n",
E 2
I 2
D 6
	{ "_fuiword\n",
E 2
"	movl (sp)+,r0\n\
E 6
I 6
D 16
	{ "1,_fuiword\n",
E 16
I 16
	{ 1, "_fuiword\n",
E 16
"	movl	(sp)+,r0\n\
E 6
	jsb	_Fuword\n" },

D 2
	{ "$2,_subyte\n",
E 2
I 2
D 6
	{ "_subyte\n",
E 6
I 6
D 16
	{ "2,_subyte\n",
E 16
I 16
	{ 2, "_subyte\n",
E 16
E 6
E 2
"	movl	(sp)+,r0\n\
	movl	(sp)+,r1\n\
	jsb	_Subyte\n" },

D 2
	{ "$2,_suibyte\n",
E 2
I 2
D 6
	{ "_suibyte\n",
E 2
"	movl (sp)+,r0\n\
E 6
I 6
D 16
	{ "2,_suibyte\n",
E 16
I 16
	{ 2, "_suibyte\n",
E 16
"	movl	(sp)+,r0\n\
E 6
	movl	(sp)+,r1\n\
	jsb	_Subyte\n" },

D 2
	{ "$2,_suword\n",
E 2
I 2
D 6
	{ "_suword\n",
E 2
"	movl (sp)+,r0\n\
E 6
I 6
D 16
	{ "2,_suword\n",
E 16
I 16
	{ 2, "_suword\n",
E 16
"	movl	(sp)+,r0\n\
E 6
	movl	(sp)+,r1\n\
	jsb	_Suword\n" },

D 2
	{ "$2,_suiword\n",
E 2
I 2
D 6
	{ "_suiword\n",
E 2
"	movl (sp)+,r0\n\
E 6
I 6
D 16
	{ "2,_suiword\n",
E 16
I 16
	{ 2, "_suiword\n",
E 16
"	movl	(sp)+,r0\n\
E 6
	movl	(sp)+,r1\n\
	jsb	_Suword\n" },

D 2
	{ "$1,_setrq\n",
E 2
I 2
D 6
	{ "_setrq\n",
E 2
"	movl	(sp)+,r0 \n\
E 6
I 6
D 16
	{ "1,_setrq\n",
E 16
I 16
	{ 1, "_setrq\n",
E 16
"	movl	(sp)+,r0\n\
E 6
	jsb	_Setrq\n" },

D 2
	{ "$1,_remrq\n",
E 2
I 2
D 6
	{ "_remrq\n",
E 2
"	movl	(sp)+,r0 \n\
E 6
I 6
D 16
	{ "1,_remrq\n",
E 16
I 16
	{ 1, "_remrq\n",
E 16
"	movl	(sp)+,r0\n\
E 6
	jsb	_Remrq\n" },

D 2
	{ "$0,_swtch\n",
E 2
I 2
D 6
	{ "_swtch\n",
E 6
I 6
D 16
	{ "0,_swtch\n",
E 16
I 16
	{ 0, "_swtch\n",
E 16
E 6
E 2
"	movpsl	-(sp)\n\
	jsb	_Swtch\n" },

D 2
	{ "$1,_setjmp\n",
E 2
I 2
D 6
	{ "_setjmp\n",
E 2
D 5
"	movl	(sp)+,r0 \n\
	jsb	_Setjmp\n" },
E 5
I 5
"	movl	(sp)+,r1 \n\
	clrl	r0 \n\
	movl	fp,(r1)+ \n\
E 6
I 6
D 16
	{ "1,_setjmp\n",
E 16
I 16
	{ 1, "_setjmp\n",
E 16
"	movl	(sp)+,r1\n\
	clrl	r0\n\
	movl	fp,(r1)+\n\
E 6
	moval	1(pc),(r1)\n" },
E 5

D 2
	{ "$1,_longjmp\n",
E 2
I 2
D 6
	{ "_longjmp\n",
E 2
"	movl	(sp)+,r0 \n\
E 6
I 6
D 16
	{ "1,_longjmp\n",
E 16
I 16
	{ 1, "_longjmp\n",
E 16
"	movl	(sp)+,r0\n\
E 6
	jsb	_Longjmp\n" },

D 2
	{ "$1,_ffs\n",
E 2
I 2
D 6
	{ "_ffs\n",
E 6
I 6
D 16
	{ "1,_ffs\n",
E 16
I 16
	{ 1, "_ffs\n",
E 16
E 6
E 2
"	movl	(sp)+,r1\n\
D 6
	ffs	$0,$32,r1,r0 \n\
	bneq	1f \n\
	mnegl	$1,r0 \n\
1: \n\
E 6
I 6
	ffs	$0,$32,r1,r0\n\
	bneq	1f\n\
	mnegl	$1,r0\n\
1:\n\
E 6
	incl	r0\n" },

D 2
	{ "$1,_htons\n",
E 2
I 2
D 6
	{ "_htons\n",
E 2
"	rotl	$8,(sp),r0\n\
	movb	1(sp),r0\n\
	movzwl	r0,r0\n\
	addl2	$4,sp\n" },
E 6
I 6
D 16
	{ "1,_htons\n",
E 16
I 16
	{ 1, "_htons\n",
E 16
"	movl	(sp)+,r5\n\
	rotl	$8,r5,r0\n\
D 7
	movb	1(r5),r0\n\
E 7
I 7
	rotl	$-8,r5,r1\n\
	movb	r1,r0\n\
E 7
	movzwl	r0,r0\n" },
E 6

D 2
	{ "$1,_ntohs\n",
E 2
I 2
D 6
	{ "_ntohs\n",
E 2
"	rotl	$8,(sp),r0\n\
	movb	1(sp),r0\n\
	movzwl	r0,r0\n\
	addl2	$4,sp\n" },
E 6
I 6
D 16
	{ "1,_ntohs\n",
E 16
I 16
	{ 1, "_ntohs\n",
E 16
"	movl	(sp)+,r5\n\
D 7
	rotl	$8,(r5),r0\n\
	movb	1(r5),r0\n\
E 7
I 7
	rotl	$8,r5,r0\n\
	rotl	$-8,r5,r1\n\
	movb	r1,r0\n\
E 7
	movzwl	r0,r0\n" },
E 6

D 2
	{ "$1,_htonl\n",
E 2
I 2
D 6
	{ "_htonl\n",
E 2
"	rotl	$-8,(sp),r0\n\
E 6
I 6
D 16
	{ "1,_htonl\n",
E 16
I 16
	{ 1, "_htonl\n",
E 16
"	movl	(sp)+,r5\n\
D 7
	rotl	$-8,(r5),r0\n\
E 7
I 7
	rotl	$-8,r5,r0\n\
E 7
E 6
	insv	r0,$16,$8,r0\n\
D 6
	movb	3(sp),r0\n\
	addl2	$4,sp\n" },
E 6
I 6
D 7
	movb	3(sp),r0\n" },
E 7
I 7
	rotl	$8,r5,r1\n\
	movb	r1,r0\n" },
E 7
E 6

D 2
	{ "$1,_ntohl\n",
E 2
I 2
D 6
	{ "_ntohl\n",
E 2
"	rotl	$-8,(sp),r0\n\
E 6
I 6
D 16
	{ "1,_ntohl\n",
E 16
I 16
	{ 1, "_ntohl\n",
E 16
"	movl	(sp)+,r5\n\
D 7
	rotl	$-8,(r5),r0\n\
E 7
I 7
	rotl	$-8,r5,r0\n\
E 7
E 6
	insv	r0,$16,$8,r0\n\
D 6
	movb	3(sp),r0\n\
	addl2	$4,sp\n" },
E 6
I 6
D 7
	movb	3(r5),r0\n" },
E 7
I 7
	rotl	$8,r5,r1\n\
	movb	r1,r0\n" },
E 7
E 6

D 2
	{ "$2,__insque\n",
E 2
I 2
D 6
	{ "__insque\n",
E 2
"	insque	*(sp)+,*(sp)+\n" },
E 6
I 6
D 16
	{ "2,__insque\n",
E 16
I 16
	{ 2, "__insque\n",
E 16
"	movl	(sp)+,r4\n\
	movl	(sp)+,r5\n\
	insque	(r4),(r5)\n" },
E 6

D 2
	{ "$1,__remque\n",
E 2
I 2
D 6
	{ "__remque\n",
E 2
"	remque	*(sp)+,r0\n" },
E 6
I 6
D 16
	{ "1,__remque\n",
E 16
I 16
	{ 1, "__remque\n",
E 16
"	movl	(sp)+,r5\n\
	remque	(r5),r0\n" },
E 6

D 2
	{ "$2,__queue\n",
E 2
I 2
D 6
	{ "__queue\n",
E 6
I 6
D 16
	{ "2,__queue\n",
E 16
I 16
	{ 2, "__queue\n",
E 16
E 6
E 2
"	movl	(sp)+,r0\n\
	movl	(sp)+,r1\n\
D 12
	insque	r1,*4(r0)\n" },
E 12
I 12
	insque	(r1),*4(r0)\n" },
E 12

D 2
	{ "$1,__dequeue\n",
E 2
I 2
D 6
	{ "__dequeue\n",
E 6
I 6
D 16
	{ "1,__dequeue\n",
E 16
I 16
	{ 1, "__dequeue\n",
E 16
E 6
E 2
"	movl	(sp)+,r0\n\
	remque	*(r0),r0\n" },
I 8

D 16
	{ "2,_imin\n",
E 16
I 16
	{ 2, "_imin\n",
E 16
"	movl	(sp)+,r0\n\
	movl	(sp)+,r5\n\
	cmpl	r0,r5\n\
	bleq	1f\n\
	movl	r5,r0\n\
1:\n" },

D 16
	{ "2,_imax\n",
E 16
I 16
	{ 2, "_imax\n",
E 16
"	movl	(sp)+,r0\n\
	movl	(sp)+,r5\n\
	cmpl	r0,r5\n\
	bgeq	1f\n\
	movl	r5,r0\n\
1:\n" },

D 16
	{ "2,_min\n",
E 16
I 16
	{ 2, "_min\n",
E 16
"	movl	(sp)+,r0\n\
	movl	(sp)+,r5\n\
	cmpl	r0,r5\n\
	blequ	1f\n\
	movl	r5,r0\n\
1:\n" },

D 16
	{ "2,_max\n",
E 16
I 16
	{ 2, "_max\n",
E 16
"	movl	(sp)+,r0\n\
	movl	(sp)+,r5\n\
	cmpl	r0,r5\n\
	bgequ	1f\n\
	movl	r5,r0\n\
1:\n" },
E 8
D 6
};
struct pats *htbl[HSHSIZ];
E 6
I 6
#endif vax
E 6

D 6
#define HASH(cp, hp) {\
    hash = 0; rehash = 1; ccp = cp; \
    do	{ \
    	hash *= (int)*ccp++; \
    } while (*ccp && *ccp != '\n'); \
    hash >>= 7; hash %= HSHSIZ; hp = &htbl[hash]; size = ccp - cp + 1; \
}
E 6
I 6
#ifdef mc68000
/* someday... */
#endif mc68000
E 6

D 6
#define REHASH(hp) {\
    hp += rehash; rehash += 2; \
    if (hp >= &htbl[HSHSIZ]) \
    	hp -= HSHSIZ; \
}

main(argc, argv)
	char *argv[];
{
	register struct pats *pp, **hp;
	register char *cp, *ccp, *lp;
	register int hash, rehash, size;
	char line[BUFSIZ];
	extern char *index();

	if (argc > 1)
		freopen(argv[1], "r", stdin);
	if (argc > 2)
		freopen(argv[2], "w", stdout);
	/*
	 * Set up the hash table.
	 */
	for (pp = ptab; pp < &ptab[sizeof (ptab)/sizeof (ptab[0])]; pp++) {
		HASH(pp->name, hp);
		while (*hp)
			REHASH(hp);
		*hp = pp;
	}
	/*
	 * Check each line and replace as appropriate.
	 */
	while (fgets(line, BUFSIZ, stdin)) {
		lp = index(line, ':');
		for (cp = (lp != NULL) ? ++lp : line; *cp == '\t'; )
			cp++;
#define	CALLS	"calls\t"
		if (strncmp(cp, CALLS, sizeof (CALLS) - 1) != 0) {
			fputs(line, stdout);
			continue;
		}
D 2
		cp += sizeof (CALLS) - 1;
E 2
I 2
		for (cp += sizeof (CALLS) - 1; *cp && *cp != ','; cp++)
			;
		if (*cp != ',') {
			fputs(line, stdout);
			continue;
		}
		cp++;
E 2
		HASH(cp, hp);
		while (*hp) {
			if (strncmp((*hp)->name, cp, size) == NULL) {
				if (lp != NULL) {
					*lp++ = '\n';
					*lp = '\0';
					fputs(line, stdout);
				}
				fputs((*hp)->replace, stdout);
				goto nextline;
			}
			REHASH(hp);
		}
		fputs(line, stdout);
nextline:
		;
	}
	exit(0);
}
E 6
I 6
D 16
	{ "", "" }
E 16
I 16
	{ 0, "", "" }
E 16
};
E 6
E 1
