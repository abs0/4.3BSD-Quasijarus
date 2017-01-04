h31552
s 00043/00003/00034
d D 5.3 86/11/03 20:20:18 mckusick 4 3
c update for tahoe
e
s 00001/00001/00036
d D 5.2 85/06/07 22:50:30 kre 3 2
c Fix botch in previous delta
e
s 00006/00002/00031
d D 5.1 85/06/07 22:39:10 kre 2 1
c Add copyright
e
s 00033/00000/00000
d D 1.1 81/08/17 23:38:44 dlw 1 0
c date and time created 81/08/17 23:38:44 by dlw
e
u
U
t
T
I 1
/*
D 2
char id_traper[] = "%W%";
 * Arrange to trap integer overflow & floating underflow.
E 2
I 2
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W%	%G%
D 3
 */
E 3
I 3
 *
E 3
E 2
 * Full of Magic! DON'T CHANGE ANYTHING !!
 *
 * To use from f77:
 *	integer oldmsk, traper
 *	oldmsk = traper (mask)
D 4
 * where:
E 4
I 4
 * where for vax:
E 4
 *	mask = 1 to trap integer overflow
 *	mask = 2 to trap floating underflow
 *	mask = 3 to trap both
 *	These 2 bits will be set into the PSW.
 *	The old state will be returned.
I 4
 *
 * where for CCI:
 *	mask = 0 to trap neither
 *	mask = 1 to trap integer overflow
 *	mask = 2 to trap floating underflow
 *	mask = 3 to trap both
 *	These 2 bits will be set into the PSL.
 *	The old state will be returned.
E 4
 */

I 4
#ifdef vax
E 4
long traper_(msk)
long	*msk;
{
	int	old = 0;
D 4
#if	vax
E 4
#define IOV_MASK	0140
	int	**s = &msk;
	int	psw;

	s -= 5;
	psw = (int)*s;
	old = (psw & IOV_MASK) >> 5;
	psw = (psw & ~IOV_MASK) | ((*msk << 5) & IOV_MASK);
	*s = (int *)psw;
D 4
#endif	vax
E 4
	return((long)old);
}
I 4
#endif	vax

/*
 * Assumptions for CCI:
 *	- the two bits are contiguous in PSL;
 *	- integer overflow trap enable bit < floating underflow trap enable bit;
 */
#ifdef tahoe
# include <machine/psl.h>

unsigned long old_msk;
unsigned short new_msk;
unsigned long tst_msk;

long traper_(msk)
long	*msk;
{
#define IOV_MASK (PSL_IV | PSL_FU)
#define IOV_DISP 5

	asm("	movpsl _old_msk");

	old_msk = (old_msk & IOV_MASK) >> IOV_DISP;

	new_msk = (*msk << IOV_DISP) & IOV_MASK;
	asm("	bispsw _new_msk");

	new_msk = ~(*msk << IOV_DISP) & IOV_MASK;
	asm("	bicpsw _new_msk");

	return(old_msk);
}
#endif tahoe
E 4
E 1
