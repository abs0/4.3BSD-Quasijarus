h21022
s 00010/00005/00224
d D 7.10 88/06/29 17:15:02 bostic 10 9
c install approved copyright notice
e
s 00019/00014/00210
d D 7.9 88/05/27 16:42:22 karels 9 8
c lint
e
s 00013/00009/00211
d D 7.8 88/02/27 16:18:27 mckusick 8 7
c limit is now enforced as a function of memory use 
c rather than based on number of allocations
e
s 00010/00007/00210
d D 7.7 88/02/18 16:17:03 mckusick 7 6
c correct statistic for `total elements allocated'
e
s 00008/00002/00209
d D 7.6 88/02/06 11:00:10 mckusick 6 5
c change copyright
e
s 00050/00017/00161
d D 7.5 88/02/06 10:55:39 mckusick 5 4
c put in needed sleeps; more detailed statistics
e
s 00003/00002/00175
d D 7.4 87/10/23 14:08:09 kre 4 3
c fix problems with allocation of the last page (or allocation
c of the last cluster after the previous fix)
e
s 00001/00001/00176
d D 7.3 87/10/22 19:47:42 kre 3 2
c base mem allocation at cluster boundary.
e
s 00000/00001/00177
d D 7.2 87/06/22 19:40:57 mckusick 2 1
c one statistic too many
e
s 00178/00000/00000
d D 7.1 87/06/06 13:25:59 mckusick 1 0
c date and time created 87/06/06 13:25:59 by mckusick
e
u
U
f b 
t
T
I 1
/*
 * Copyright (c) 1987 Regents of the University of California.
D 6
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 6
I 6
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 10
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 10
I 10
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
E 10
E 6
 *
 *	%W% (Berkeley) %G%
 */

#include "param.h"
#include "vm.h"
#include "cmap.h"
#include "time.h"
#include "proc.h"
#include "map.h"
#include "kernel.h"
#include "malloc.h"

#include "../machine/pte.h"

struct kmembuckets bucket[MINBUCKET + 16];
struct kmemstats kmemstats[M_LAST];
struct kmemusage *kmemusage;
I 5
long wantkmemmap;
E 5

/*
 * Allocate a block of memory
 */
D 7
qaddr_t malloc(size, type, flags)
E 7
I 7
qaddr_t
malloc(size, type, flags)
E 7
	unsigned long size;
D 9
	long type, flags;
E 9
I 9
	int type, flags;
E 9
{
	register struct kmembuckets *kbp;
	register struct kmemusage *kup;
D 9
	long indx, npg, alloc, allocsize, s;
E 9
I 9
	long indx, npg, alloc, allocsize;
	int s;
E 9
	caddr_t va, cp;
#ifdef KMEMSTATS
D 5
	register struct kmemstats *ksp;

	ksp = &kmemstats[type];
	if (ksp->ks_inuse >= ksp->ks_limit)
		return (0);
E 5
I 5
	register struct kmemstats *ksp = &kmemstats[type];
E 5
#endif
I 5

E 5
	indx = BUCKETINDX(size);
	kbp = &bucket[indx];
	s = splimp();
I 5
again:
#ifdef KMEMSTATS
D 8
	while (ksp->ks_inuse >= ksp->ks_limit) {
E 8
I 8
	while (ksp->ks_memuse >= ksp->ks_limit) {
E 8
		if (flags & M_NOWAIT) {
			splx(s);
			return (0);
		}
		if (ksp->ks_limblocks < 65535)
			ksp->ks_limblocks++;
		sleep((caddr_t)ksp, PSWP+2);
	}
#endif
E 5
	if (kbp->kb_next == NULL) {
		if (size > MAXALLOCSAVE)
			allocsize = roundup(size, CLBYTES);
		else
			allocsize = 1 << indx;
		npg = clrnd(btoc(allocsize));
		if ((flags & M_NOWAIT) && freemem < npg) {
			splx(s);
			return (0);
		}
		alloc = rmalloc(kmemmap, npg);
		if (alloc == 0) {
D 5
			splx(s);
			return (0);
E 5
I 5
			if (flags & M_NOWAIT) {
				splx(s);
				return (0);
			}
#ifdef KMEMSTATS
			if (ksp->ks_mapblocks < 65535)
				ksp->ks_mapblocks++;
#endif
			wantkmemmap++;
			sleep((caddr_t)&wantkmemmap, PSWP+2);
			goto again;
E 5
		}
I 4
		alloc -= CLSIZE;		/* convert to base 0 */
E 4
D 5
		if (vmemall(&kmempt[alloc], npg, &proc[0], CSYS) == 0) {
D 4
			rmfree(kmemmap, npg, alloc);
E 4
I 4
			rmfree(kmemmap, npg, alloc+CLSIZE);
E 4
			splx(s);
			return (0);
		}
E 5
I 5
D 9
		(void) vmemall(&kmempt[alloc], npg, &proc[0], CSYS);
E 9
I 9
		(void) vmemall(&kmempt[alloc], (int)npg, &proc[0], CSYS);
E 9
E 5
		va = (caddr_t) kmemxtob(alloc);
D 9
		vmaccess(&kmempt[alloc], va, npg);
E 9
I 9
		vmaccess(&kmempt[alloc], va, (int)npg);
E 9
#ifdef KMEMSTATS
		kbp->kb_total += kbp->kb_elmpercl;
#endif
		kup = btokup(va);
		kup->ku_indx = indx;
		if (allocsize > MAXALLOCSAVE) {
			if (npg > 65535)
				panic("malloc: allocation too large");
			kup->ku_pagecnt = npg;
I 5
#ifdef KMEMSTATS
			ksp->ks_memuse += allocsize;
#endif
E 5
			goto out;
		}
#ifdef KMEMSTATS
		kup->ku_freecnt = kbp->kb_elmpercl;
		kbp->kb_totalfree += kbp->kb_elmpercl;
#endif
		kbp->kb_next = va + (npg * NBPG) - allocsize;
D 5
		for(cp = kbp->kb_next; cp > va; cp -= allocsize)
E 5
I 5
		for (cp = kbp->kb_next; cp > va; cp -= allocsize)
E 5
			*(caddr_t *)cp = cp - allocsize;
		*(caddr_t *)cp = NULL;
	}
	va = kbp->kb_next;
	kbp->kb_next = *(caddr_t *)va;
#ifdef KMEMSTATS
	kup = btokup(va);
	if (kup->ku_indx != indx)
		panic("malloc: wrong bucket");
	if (kup->ku_freecnt == 0)
		panic("malloc: lost data");
	kup->ku_freecnt--;
	kbp->kb_totalfree--;
I 5
	ksp->ks_memuse += 1 << indx;
E 5
out:
	kbp->kb_calls++;
	ksp->ks_inuse++;
	ksp->ks_calls++;
D 8
	if (ksp->ks_inuse > ksp->ks_maxused)
		ksp->ks_maxused = ksp->ks_inuse;
E 8
I 8
	if (ksp->ks_memuse > ksp->ks_maxused)
		ksp->ks_maxused = ksp->ks_memuse;
E 8
#else
out:
#endif
	splx(s);
	return ((qaddr_t)va);
}

/*
 * Free a block of memory allocated by malloc.
 */
D 7
void free(addr, type)
E 7
I 7
void
free(addr, type)
E 7
	caddr_t addr;
D 9
	long type;
E 9
I 9
	int type;
E 9
{
	register struct kmembuckets *kbp;
	register struct kmemusage *kup;
D 8
	long alloc, s;
E 8
I 8
D 9
	long alloc, size, s;
E 9
I 9
	long alloc, size;
	int s;
E 9
E 8
I 5
#ifdef KMEMSTATS
	register struct kmemstats *ksp = &kmemstats[type];
#endif
E 5

	kup = btokup(addr);
I 7
	kbp = &bucket[kup->ku_indx];
E 7
	s = splimp();
D 8
	if (1 << kup->ku_indx > MAXALLOCSAVE) {
E 8
I 8
	size = 1 << kup->ku_indx;
	if (size > MAXALLOCSAVE) {
E 8
		alloc = btokmemx(addr);
D 9
		(void) memfree(&kmempt[alloc], kup->ku_pagecnt, 0);
E 9
I 9
		(void) memfree(&kmempt[alloc], (int)kup->ku_pagecnt, 0);
E 9
D 4
		rmfree(kmemmap, (long)kup->ku_pagecnt, alloc);
E 4
I 4
D 5
		rmfree(kmemmap, (long)kup->ku_pagecnt, alloc+CLSIZE);
E 5
I 5
		rmfree(kmemmap, (long)kup->ku_pagecnt, alloc + CLSIZE);
		if (wantkmemmap) {
			wakeup((caddr_t)&wantkmemmap);
			wantkmemmap = 0;
		}
E 5
E 4
#ifdef KMEMSTATS
I 5
D 8
		ksp->ks_memuse -= kup->ku_pagecnt << PGSHIFT;
E 8
I 8
		size = kup->ku_pagecnt << PGSHIFT;
		ksp->ks_memuse -= size;
E 8
E 5
		kup->ku_indx = 0;
		kup->ku_pagecnt = 0;
D 2
		kbp->kb_total -= kbp->kb_elmpercl;
E 2
D 5
		kmemstats[type].ks_inuse--;
E 5
I 5
D 8
		if (ksp->ks_inuse == ksp->ks_limit)
E 8
I 8
		if (ksp->ks_memuse + size >= ksp->ks_limit &&
		    ksp->ks_memuse < ksp->ks_limit)
E 8
			wakeup((caddr_t)ksp);
		ksp->ks_inuse--;
I 7
		kbp->kb_total -= 1;
E 7
E 5
#endif
		splx(s);
		return;
	}
D 7
	kbp = &bucket[kup->ku_indx];
E 7
#ifdef KMEMSTATS
	kup->ku_freecnt++;
	if (kup->ku_freecnt >= kbp->kb_elmpercl)
		if (kup->ku_freecnt > kbp->kb_elmpercl)
			panic("free: multiple frees");
		else if (kbp->kb_totalfree > kbp->kb_highwat)
			kbp->kb_couldfree++;
	kbp->kb_totalfree++;
D 5
	kmemstats[type].ks_inuse--;
E 5
I 5
D 8
	if (ksp->ks_inuse == ksp->ks_limit)
E 8
I 8
	ksp->ks_memuse -= size;
	if (ksp->ks_memuse + size >= ksp->ks_limit &&
	    ksp->ks_memuse < ksp->ks_limit)
E 8
		wakeup((caddr_t)ksp);
	ksp->ks_inuse--;
D 8
	ksp->ks_memuse -= 1 << kup->ku_indx;
E 8
E 5
#endif
	*(caddr_t *)addr = kbp->kb_next;
	kbp->kb_next = addr;
	splx(s);
}

/*
 * Initialize the kernel memory allocator
 */
kmeminit()
{
	register long indx;
I 7
	int npg;
E 7

D 9
	if (!powerof2(MAXALLOCSAVE))
		panic("kmeminit: MAXALLOCSAVE not power of 2");
	if (MAXALLOCSAVE > MINALLOCSIZE * 32768)
		panic("kmeminit: MAXALLOCSAVE too big");
	if (MAXALLOCSAVE < CLBYTES)
		panic("kmeminit: MAXALLOCSAVE too small");
E 9
I 9
#if	((MAXALLOCSAVE & (MAXALLOCSAVE - 1)) != 0)
		ERROR!_kmeminit:_MAXALLOCSAVE_not_power_of_2
#endif
#if	(MAXALLOCSAVE > MINALLOCSIZE * 32768)
		ERROR!_kmeminit:_MAXALLOCSAVE_too_big
#endif
#if	(MAXALLOCSAVE < CLBYTES)
		ERROR!_kmeminit:_MAXALLOCSAVE_too_small
#endif
E 9
D 3
	rminit(kmemmap, ekmempt - kmempt, (long)1,
E 3
I 3
D 7
	rminit(kmemmap, ekmempt - kmempt, (long)CLSIZE,
E 3
		"malloc map", ekmempt - kmempt);
E 7
I 7
	npg = ekmempt - kmempt;
D 9
	rminit(kmemmap, npg, (long)CLSIZE, "malloc map", npg);
E 9
I 9
	rminit(kmemmap, (long)npg, (long)CLSIZE, "malloc map", npg);
E 9
E 7
#ifdef KMEMSTATS
	for (indx = 0; indx < MINBUCKET + 16; indx++) {
		if (1 << indx >= CLBYTES)
			bucket[indx].kb_elmpercl = 1;
		else
			bucket[indx].kb_elmpercl = CLBYTES / (1 << indx);
		bucket[indx].kb_highwat = 5 * bucket[indx].kb_elmpercl;
	}
	for (indx = 0; indx < M_LAST; indx++)
D 5
		kmemstats[indx].ks_limit = 0x7fffffff;
E 5
I 5
D 7
		kmemstats[indx].ks_limit =
			(ekmempt - kmempt) * CLBYTES * 9 / 10;
E 7
I 7
		kmemstats[indx].ks_limit = npg * CLBYTES * 8 / 10;
E 7
E 5
#endif
}
E 1
