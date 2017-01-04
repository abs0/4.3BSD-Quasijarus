h39309
s 00023/00000/00016
d D 5.2 86/11/12 19:23:56 mckusick 6 5
c add machine specific macros for extracting inline data
e
s 00007/00003/00009
d D 5.1 85/06/05 13:59:57 dist 5 4
c Add copyright
e
s 00000/00000/00012
d D 2.1 84/02/08 20:29:09 aoki 4 3
c synchronize to version 2
e
s 00004/00003/00008
d D 1.3 83/01/10 19:52:56 mckusick 3 2
c ifdef VAX => ifdef ADDR32
e
s 00006/00002/00005
d D 1.2 81/03/06 23:01:15 mckusic 2 1
c add onyx code
e
s 00007/00000/00000
d D 1.1 81/01/07 16:55:37 mckusick 1 0
c date and time created 81/01/07 16:55:37 by mckusick
e
u
U
t
T
I 1
D 5
/* Copyright (c) 1979 Regents of the University of California */

D 2
/* static 	char sccsid[] = "%Z%%M% %I% %G%"; */
E 2
I 2
/* static char sccsid[] = "%Z%%M% %I% %G%"; */
E 5
I 5
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 5
E 2

I 2
D 3
#ifdef VAX
E 3
I 3
#ifdef ADDR32
E 3
E 2
#define pushaddr push4
#define popaddr (char *)pop4
D 2
#define popargs(num) popsp(num * sizeof(int))
E 2
I 2
D 3
#else
E 3
I 3
#endif ADDR32
#ifdef ADDR16
E 3
#define pushaddr push2
#define popaddr (char *)pop2
D 3
#endif VAX
E 3
I 3
#endif ADDR16
I 6

/*
 * Machine specific macros for reading quantities from the
 * interpreter instruction stream. Operands in the instruction
 * stream are aligned to short, but not long boundries. Blockmarks
 * are always long aligned. Stack alignment indicates whether the
 * stack is short or long aligned. Stack alignment is assumed to
 * be no more than long aligned for ADDR32 machines, short aligned
 * for ADDR16 machines.
 */
#if defined(vax) || defined(mc68000) || defined(pdp11)
#define PCLONGVAL(target) target = *pc.lp++
#define GETLONGVAL(target, srcptr) target = *(long *)(srcptr)
#define STACKALIGN(target, value) target = ((value) + 1) &~ 1
#endif vax || mc68000 || pdp11

#ifdef tahoe
#define PCLONGVAL(target) target = *pc.sp++ << 16, target += *pc.usp++
#define GETLONGVAL(target, srcptr) \
	tsp = (short *)(srcptr), \
	target = *tsp++ << 16, target += *(unsigned short *)tsp
#define STACKALIGN(target, value) target = ((value) + 3) &~ 3
#endif tahoe
E 6
E 3
E 2
E 1
