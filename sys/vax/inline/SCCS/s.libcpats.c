h27705
s 00001/00001/00071
d D 7.1 86/06/05 01:12:10 mckusick 6 5
c 4.3BSD release version
e
s 00024/00005/00048
d D 1.5 86/04/27 20:53:56 karels 5 4
c break out tables for subset vax on -s option; for kridle and bloom
e
s 00004/00004/00049
d D 1.4 85/08/21 20:19:46 mckusick 4 3
c do validity checking on number of arguments (from donn@utah-cs)
e
s 00006/00002/00047
d D 1.3 85/06/08 14:23:05 mckusick 3 2
c Add copyright
e
s 00001/00001/00048
d D 1.2 84/08/18 18:04:46 mckusick 2 1
c change name of header file from pc2.h to inline.h
e
s 00049/00000/00000
d D 1.1 84/08/18 17:35:37 mckusick 1 0
c date and time created 84/08/18 17:35:37 by mckusick
e
u
U
t
T
I 1
D 3
/* Copyright (c) 1984 Regents of the University of California */
E 3
I 3
/*
D 6
 * Copyright (c) 1984 Regents of the University of California.
E 6
I 6
 * Copyright (c) 1984, 1986 Regents of the University of California.
E 6
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 3

#ifndef lint
D 3
static char sccsid[] = "%W%	(Berkeley)	%G%";
E 3
I 3
static char sccsid[] = "%W% (Berkeley) %G%";
E 3
#endif not lint

D 2
#include "pc2.h"
E 2
I 2
#include "inline.h"
E 2

/*
 * Pattern table for the C library.
 */
struct pats libc_ptab[] = {

#ifdef vax
D 4
	{ "1,_fgetc\n",
E 4
I 4
	{ 1, "_fgetc\n",
E 4
"	sobgeq	*(sp),1f\n\
	calls	$1,__filbuf\n\
	jbr     2f\n\
1:\n\
	addl3	$4,(sp)+,r1\n\
	movzbl	*(r1),r0\n\
	incl	(r1)\n\
2:\n" },

D 4
	{ "2,_fputc\n",
E 4
I 4
	{ 2, "_fputc\n",
E 4
"	sobgeq	*4(sp),1f\n\
	calls	$2,__flsbuf\n\
	jbr	2f\n\
1:\n\
	movq	(sp)+,r0\n\
	movb	r0,*4(r1)\n\
	incl	4(r1)\n\
2:\n" },
I 5
#endif vax
E 5

I 5
#ifdef mc68000
/* someday... */
#endif mc68000

	{ 0, "", "" }
};

struct pats vaxsubset_libc_ptab[] = {

E 5
D 4
	{ "1,_strlen\n",
E 4
I 4
	{ 1, "_strlen\n",
E 4
"	movl	(sp)+,r5\n\
	movl	r5,r1\n\
1:\n\
I 5
	tstb	(r1)+\n\
	jneq	1b\n\
	decl	r1\n\
	subl3	r5,r1,r0\n" },

	{ 0, "", "" }
};

struct pats vax_libc_ptab[] = {

	{ 1, "_strlen\n",
"	movl	(sp)+,r5\n\
	movl	r5,r1\n\
1:\n\
E 5
	locc	$0,$65535,(r1)\n\
	jeql	1b\n\
	subl3	r5,r1,r0\n" },
D 5
#endif vax

#ifdef mc68000
/* someday... */
#endif mc68000
E 5

D 4
	{ "", "" }
E 4
I 4
	{ 0, "", "" }
E 4
};
E 1
