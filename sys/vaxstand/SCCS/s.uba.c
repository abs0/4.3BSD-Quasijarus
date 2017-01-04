h00005
s 00006/00003/00085
d D 7.4 88/07/09 14:40:08 karels 16 15
c check adaptor numbers against actual number
e
s 00005/00005/00083
d D 7.3 88/02/22 13:00:02 bostic 15 14
c change to dev(a,b,c,d) format
e
s 00012/00005/00076
d D 7.2 88/01/28 20:53:29 karels 14 13
c uvax changes; fix devsw index in confxx; header updates
e
s 00001/00001/00080
d D 7.1 86/06/05 01:46:20 mckusick 13 12
c 4.3BSD release version
e
s 00001/00000/00080
d D 6.3 85/08/02 19:05:46 bloom 12 11
c add 8600 support
e
s 00007/00001/00073
d D 6.2 85/06/08 13:13:11 mckusick 11 10
c Add copyright
e
s 00000/00000/00074
d D 6.1 83/07/29 07:47:54 sam 10 9
c 4.2 distribution
e
s 00002/00001/00072
d D 4.8 82/12/17 17:01:35 sam 9 8
c pte.h is now in ../machine/
e
s 00004/00002/00069
d D 4.7 82/11/13 23:15:35 sam 8 7
c move includes for 4.1c directory layout
e
s 00002/00001/00069
d D 4.6 82/07/15 21:32:32 root 7 6
c new boot scheme
e
s 00006/00004/00064
d D 4.5 81/11/12 13:47:41 root 6 5
c added in uda and mt support
e
s 00001/00001/00067
d D 4.4 81/04/03 00:10:43 root 5 4
c s/730/7ZZ
e
s 00017/00004/00051
d D 4.3 81/03/21 17:30:02 wnj 4 3
c add 730 and ts11 support and fix bdp purging bug
e
s 00026/00012/00029
d D 4.2 81/03/15 20:46:59 wnj 3 2
c 
e
s 00000/00000/00041
d D 4.1 80/11/09 16:29:49 bill 2 1
c stamp for 4bsd
e
s 00041/00000/00000
d D 1.1 80/06/28 10:43:17 bill 1 0
c date and time created 80/06/28 10:43:17 by bill
e
u
U
t
T
I 1
D 4
/*	%M%	%I%	%G%	*/
E 4
I 4
D 11
/*	%M%	%I%	%E%	*/
E 11
I 11
/*
D 13
 * Copyright (c) 1982 Regents of the University of California.
E 13
I 13
D 16
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 16
I 16
 * Copyright (c) 1982, 1986, 1988 Regents of the University of California.
E 16
E 13
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 11
E 4

I 9
D 16
#include "../machine/pte.h"

E 16
E 9
D 14
#include "../h/param.h"
#include "../h/inode.h"
I 3
D 8
#include "../h/cpu.h"
E 8
E 3
D 9
#include "../h/pte.h"
E 9
D 3
#include "../h/uba.h"
E 3
I 3
D 8
#include "../h/ubareg.h"
E 8
E 3
#include "../h/vm.h"
I 7
#include "../h/fs.h"
E 14
I 14
#include "param.h"
#include "inode.h"
#include "vm.h"
#include "fs.h"
E 14
I 8

I 16
#include "../vax/pte.h"
E 16
#include "../vax/cpu.h"
#include "../vaxuba/ubareg.h"

E 8
E 7
#include "saio.h"
I 3
#include "savax.h"
E 3

I 4
/*
 * Note... this routine does not
 * really allocate; unless bdp == 2
 * you always get the same space.
 * When bdp == 2 you get some other space.
 */
E 4
ubasetup(io, bdp)
D 3
register struct iob *io;
E 3
I 3
	register struct iob *io;
	int bdp;
E 3
{
D 3
	register int i;
E 3
	int npf;
D 15
	unsigned v;
E 15
I 15
	unsigned int v;
E 15
	register struct pte *pte;
D 3
	int o, vaddr, temp;
E 3
I 3
D 4
	int o, temp;
E 4
I 4
	int o, temp, reg;
I 6
	static int lastreg = 128+64;
E 6
E 4
E 3

I 6
	v = btop(io->i_ma);
	o = (int)io->i_ma & PGOFSET;
	npf = btoc(io->i_cc + o) +1;
E 6
I 4
	if (bdp == 2) {
D 6
		reg = 128+64;		/* for stupid ts-11 */
E 6
I 6
		reg = lastreg;
		lastreg += npf;
E 6
		bdp = 0;
	} else
		reg = 0;
E 4
D 6
	v = btop(io->i_ma);
	o = (int)io->i_ma & PGOFSET;
	npf = btoc(io->i_cc + o) +1;
E 6
D 3
	pte = &(((struct uba_regs *)PHYSUBA0)->uba_map[0]);
	temp = (bdp << 21) | MRV;
E 3
I 3
D 4
	pte = ubauba(io->i_unit)->uba_map;
E 4
I 4
D 15
	pte = &ubauba(io->i_unit)->uba_map[reg];
E 15
I 15
	pte = &ubauba(io->i_adapt)->uba_map[reg];
E 15
E 4
	temp = (bdp << 21) | UBAMR_MRV;
E 3
	if (bdp && (o & 01))
D 3
		temp |= BO;
E 3
I 3
		temp |= UBAMR_BO;
E 3
	v &= 0x1fffff;			/* drop to physical addr */
	while (--npf != 0)
		*(int *)pte++ = v++ | temp;
	*(int *)pte++ = 0;
D 3
	return ((bdp << 28) | o);
E 3
I 3
D 4
	return ((bdp << UBAMR_DPSHIFT) | o);
E 4
I 4
	return ((bdp << 28) | (reg << 9) | o);
E 4
E 3
}

D 3
ubafree(mr)
E 3
I 3
ubafree(io, mr)
	struct iob *io;
E 3
	int mr;
{
D 3
	register int bdp, reg, npf, a;
E 3
I 3
	register int bdp;
E 3
 
	bdp = (mr >> 28) & 0x0f;
D 3
	if (bdp)
		((struct uba_regs *)PHYSUBA0)->uba_dpr[bdp] |= BNE;
E 3
I 3
	if (bdp == 0)
		return;
	switch (cpu) {

I 14
#if VAX8200
	case VAX_8200:
D 15
		UBA_PURGEBUA(ubauba(io->i_unit), bdp);
E 15
I 15
		UBA_PURGEBUA(ubauba(io->i_adapt), bdp);
E 15
		break;
#endif

I 16
#if VAX780 || VAX8600
E 16
E 14
I 12
	case VAX_8600:
E 12
	case VAX_780:
D 15
		ubauba(io->i_unit)->uba_dpr[bdp] |= UBADPR_BNE;
E 15
I 15
		ubauba(io->i_adapt)->uba_dpr[bdp] |= UBADPR_BNE;
E 15
		break;
I 16
#endif
E 16

I 16
#if VAX750
E 16
	case VAX_750:
D 15
		ubauba(io->i_unit)->uba_dpr[bdp] |=
E 15
I 15
		ubauba(io->i_adapt)->uba_dpr[bdp] |=
E 15
		     UBADPR_PURGE|UBADPR_NXM|UBADPR_UCE;
I 4
		break;
I 16
#endif
E 16
D 5
	case VAX_730:
E 5
I 5
D 7
	case VAX_7ZZ:
E 7
I 7
D 14
	case VAX_730:
E 14
I 14

	default:
E 14
E 7
E 5
E 4
		break;
	}
E 3
}
E 1
