h11574
s 00004/00000/00085
d D 7.3 04/03/06 01:49:40 msokolov 3 2
c start knocking some sanity into VAXBI support
e
s 00021/00001/00064
d D 7.2 88/07/09 13:44:01 bostic 2 1
c install approved copyright notice
e
s 00065/00000/00000
d D 7.1 88/05/14 12:19:44 karels 1 0
c vax 8200 support from torek
e
u
U
t
T
I 1
/*
D 2
 *	%W% (Berkeley) %G%
E 2
I 2
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
E 2
 *
I 2
 * This code is derived from software contributed to Berkeley by
 * Chris Torek.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *	%W% (Berkeley) %G%
 */

/*
E 2
 * VAXBI specific routines.
 */

#include "param.h"

#include "../vax/cpu.h"
#include "../vax/mtpr.h"
#include "../vax/nexus.h"

#include "bireg.h"

bi_reset(bi)
	register struct biiregs *bi;
{

	bi->bi_csr |= BICSR_NRST;
	DELAY(10000);		/* ??? */
}

/*
 * Reset with self test.  Return true iff reset fails.
 * BEWARE, THIS RESETS THE BI ARBITRATION LEVEL TO ARB_NONE
 * does self test ever cause a bi bus error?
 */
bi_selftest(bi)
	register struct biiregs *bi;
{
	register int timo;

	bi->bi_csr |= BICSR_ARB_NONE;	/* why? */
	bi->bi_csr |= BICSR_STS | BICSR_INIT;/* must this be separate? */
	DELAY(50);			/* why? */
	timo = todr() + 1000;
	while (bi->bi_csr & BICSR_BROKE) {
		if (todr() > timo)	/* reset failed */
			return (-1);
	}
	return (0);			/* reset OK */
}

/*
 * THIS SHOULD PROBABLY WORK MORE LIKE ubaerror()
 * (but then we would need to be able to reset BI nodes)
 * (we need a per-BI-device driver structure!)
 */
bi_buserr(binum)
	int binum;
{
	register struct bi_node *bi;
	register int node;
I 3
#if 0
E 3
	extern int bi_nodes;
I 3
#endif
E 3
	extern int cold;

	printf("vaxbi%d: bus error\n", binum);
	bi = (struct bi_node *) &nexus[binum * NNODEBI];/* XXX */
	for (node = 0; node < 16; node++, bi++) {
I 3
#if 0
E 3
		if ((bi_nodes & (1 << node)) == 0)	/* XXX crude */
			continue;
I 3
#endif
E 3
		printf("node %x: ber=%b\n", node, bi->biic.bi_ber, BIBER_BITS);
	}
	panic("bi_buserr");
}
E 1
