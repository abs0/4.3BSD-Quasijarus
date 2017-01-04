h57027
s 00080/00000/00000
d D 7.1 04/03/19 22:49:15 msokolov 1 0
c separated out of ka650.c to use for all CVAXen
e
u
U
t
T
I 1
/*
 * Copyright (c) 1988 The Regents of the University of California.
 * All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Mt. Xinu.
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

#include "cpucond.h"
#if NEED_CVAX_SUPPORT

/*
 * CVAX common support code.
 */

#include "param.h"
#include "time.h"
#include "kernel.h"
#include "systm.h"

#include "cpu.h"
#include "psl.h"
#include "mem.h"
#include "mtpr.h"
#include "cvax.h"
#include "ka650.h"

int cvax_l2cache_size;

char *mcvax[] = {
	0,			"FPA proto err",	"FPA resv inst",
	"FPA Ill Stat 2",	"FPA Ill Stat 1",	"PTE in P0, TB miss",
	"PTE in P1, TB miss",	"PTE in P0, Mod",	"PTE in P1, Mod",
	"Illegal intr IPL",	"MOVC state error",	"read error (virt)",
	"read error (phys)",	"write error (virt)",	"write error (phys)"
};

/*
 * Make sure both caches are off and not in diagnostic mode.  Clear the
 * 2nd level cache (by writing to each quadword entry), then enable it.
 * Enable 1st level cache too.
 */
cvaxencache()
{
	register int i;

	cvaxdiscache();
	if (cvax_l2cache_size) {
		for (i = 0; i < (cvax_l2cache_size / sizeof(ka650cache[0]));
		     i += 2)
			ka650cache[i] = 0;
		ka650cbd.cbd_cacr = CACR_CEN;
	}
	if (cpusid.cpu_cvax.cp_type == SID_CPUTYPE_CVAX)
		mtpr(CADR, CADR_SEN2 | CADR_SEN1 | CADR_CENI | CADR_CEND);
	if (cpusid.cpu_cvax.cp_type == SID_CPUTYPE_SOC)
		mtpr(CCR, CCR_ENA | CCR_FLU);
}

cvaxdiscache()
{
	mtpr(CADR, 0);			/* happens to be correct for SOC too */
	if (cvax_l2cache_size)
		ka650cbd.cbd_cacr = CACR_CPE;
}
#endif
E 1
