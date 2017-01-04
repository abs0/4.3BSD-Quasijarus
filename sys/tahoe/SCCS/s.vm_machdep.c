h56977
s 00016/00002/00444
d D 7.2 88/07/09 16:35:10 karels 15 14
c add CCI credit, update copyright
e
s 00000/00000/00446
d D 7.1 88/05/26 09:09:55 karels 14 13
c bring up to revision 7 for tahoe release
e
s 00007/00002/00439
d D 1.12 88/05/26 09:05:22 karels 13 11
c lint, header cleanups
e
s 00007/00001/00440
d R 7.1 88/05/21 18:36:42 karels 12 11
c bring up to revision 7 for tahoe release
e
s 00002/00002/00439
d D 1.11 88/05/06 12:34:10 karels 11 10
c cleanup: use kvtopte
e
s 00002/00031/00439
d D 1.10 88/01/07 11:34:24 karels 10 9
c rm junk
e
s 00017/00007/00453
d D 1.9 87/04/06 17:21:44 karels 9 8
c fix code for all code keys shared; clean up comments
e
s 00112/00125/00348
d D 1.8 87/03/13 10:51:10 karels 8 7
c streamline cache key management; rm vtopte (use macro again)
e
s 00001/00001/00472
d D 1.7 86/12/15 20:27:54 sam 7 6
c lint
e
s 00001/00000/00472
d D 1.6 86/11/03 12:05:51 karels 6 5
c move key stats, etc. to cpu.h
e
s 00001/00001/00471
d D 1.5 86/04/03 19:04:36 sam 5 4
c calculate stack pte's relative to p_addr
e
s 00000/00008/00472
d D 1.4 86/01/24 02:21:52 sam 4 3
c move keystats definition to machparam.h for vmstat
e
s 00007/00002/00473
d D 1.3 86/01/12 15:38:43 sam 3 2
c 4.3- plus start of autoconfig
e
s 00268/00128/00207
d D 1.2 86/01/05 18:42:47 sam 2 1
c 1st working version
e
s 00335/00000/00000
d D 1.1 85/07/21 20:20:55 sam 1 0
c date and time created 85/07/21 20:20:55 by sam
e
u
U
t
T
I 1
D 13
/*	%M%	%I%	%E%	*/
E 13
I 13
/*
 * Copyright (c) 1988 Regents of the University of California.
D 15
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 15
I 15
 * All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Computer Consoles Inc.
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
E 15
 *
 *	%W% (Berkeley) %G%
 */
E 13

D 10
#include "../machine/pte.h"

E 10
D 2
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/proc.h"
#include "../h/cmap.h"
#include "../h/mount.h"
#include "../h/vm.h"
#include "../h/text.h"
E 2
I 2
#include "param.h"
#include "systm.h"
#include "dir.h"
#include "user.h"
#include "proc.h"
#include "cmap.h"
#include "mount.h"
#include "vm.h"
#include "text.h"
#include "kernel.h"
E 2

I 10
#include "pte.h"
E 10
I 6
D 8
#include "../tahoe/cpu.h"
E 6
D 2
#include "../machine/mtpr.h"
E 2
I 2
#include "../tahoe/mtpr.h"
E 8
I 8
#include "cpu.h"
#include "mtpr.h"
E 8
E 2

/*
 * Set a red zone in the kernel stack after the u. area.
 */
setredzone(pte, vaddr)
	register struct pte *pte;
	caddr_t vaddr;
{

	pte += (sizeof (struct user) + NBPG - 1) / NBPG;
	*(int *)pte &= ~PG_PROT;
	*(int *)pte |= PG_URKR;
	if (vaddr)
D 2
		mtpr(vaddr + sizeof (struct user) + NBPG - 1, TBIS);
E 2
I 2
		mtpr(TBIS, vaddr + sizeof (struct user) + NBPG - 1);
E 2
}

D 10
#ifndef mapin
mapin(pte, v, pfnum, count, prot)
	struct pte *pte;
	u_int v, pfnum;
	int count, prot;
{

	while (count > 0) {
		*(int *)pte++ = pfnum | prot;
D 2
		mtpr(ptob(v), TBIS);
E 2
I 2
		mtpr(TBIS, ptob(v));
E 2
		v++;
		pfnum++;
		count--;
	}
}
#endif

#ifdef notdef
/*ARGSUSED*/
mapout(pte, size)
	register struct pte *pte;
	int size;
{

	panic("mapout");
}
#endif

E 10
/*
 * Check for valid program size
I 3
 * NB - Check data and data growth separately as they may overflow 
 * when summed together.
E 3
 */
D 2
chksize(ts, ds, ss)
	register unsigned ts, ds, ss;
E 2
I 2
chksize(ts, ids, uds, ss)
	register unsigned ts, ids, uds, ss;
E 2
{
I 3
D 7
	extern int maxtsize;
E 7
I 7
	extern unsigned maxtsize;
E 7
E 3
D 2
	static int maxdmap = 0;
E 2

D 2
	if (ts > MAXTSIZ || ds > MAXDSIZ || ss > MAXSSIZ) {
E 2
I 2
D 3
	if (ts > maxtsize ||
E 3
I 3
	if (ctob(ts) > maxtsize ||
E 3
	    ctob(ids) > u.u_rlimit[RLIMIT_DATA].rlim_cur ||
	    ctob(uds) > u.u_rlimit[RLIMIT_DATA].rlim_cur ||
	    ctob(ids + uds) > u.u_rlimit[RLIMIT_DATA].rlim_cur ||
	    ctob(ss) > u.u_rlimit[RLIMIT_STACK].rlim_cur) {
E 2
		u.u_error = ENOMEM;
		return (1);
	}
D 2
	/* check for swap map overflow */
	if (maxdmap == 0) {
		register int i, blk;

		blk = dmmin;
		for (i = 0; i < NDMAP; i++) {
			maxdmap += blk;
			if (blk < dmmax)
				blk *= 2;
		}
	}
	if (ctod(ts) > NXDAD * dmtext ||
	    ctod(ds) > maxdmap || ctod(ss) > maxdmap) {
		u.u_error = ENOMEM;
		return (1);
	}
	/*
	 * Make sure the process isn't bigger than our
	 * virtual memory limit.
	 *
	 * THERE SHOULD BE A CONSTANT FOR THIS.
	 */
	if (ts + ds + ss + LOWPAGES + HIGHPAGES > btoc(USRSTACK)) {
		u.u_error = ENOMEM;
		return (1);
	}
E 2
	return (0);
}

/*ARGSUSED*/
newptes(pte, v, size)
	register struct pte *pte;
	u_int v;
	register int size;
{
	register caddr_t a = ptob(v);

#ifdef lint
	pte = pte;
#endif
	if (size >= 8) {
D 2
		mtpr(0, TBIA);
E 2
I 2
		mtpr(TBIA, 0);
E 2
		return;
	}
	while (size > 0) {
D 2
		mtpr(a, TBIS);
E 2
I 2
		mtpr(TBIS, a);
E 2
		a += NBPG;
		size--;
	}
}

/*
 * Change protection codes of text segment.
 * Have to flush translation buffer since this
 * affect virtual memory mapping of current process.
 */
chgprot(addr, tprot)
	caddr_t addr;
	long tprot;
{
	unsigned v;
	int tp;
	register struct pte *pte;
	register struct cmap *c;

	v = clbase(btop(addr));
	if (!isatsv(u.u_procp, v)) {
		u.u_error = EFAULT;
		return (0);
	}
	tp = vtotp(u.u_procp, v);
	pte = tptopte(u.u_procp, tp);
	if (pte->pg_fod == 0 && pte->pg_pfnum) {
		c = &cmap[pgtocm(pte->pg_pfnum)];
		if (c->c_blkno && c->c_mdev != MSWAPX)
			munhash(mount[c->c_mdev].m_dev,
			    (daddr_t)(u_long)c->c_blkno);
	}
	*(int *)pte &= ~PG_PROT;
	*(int *)pte |= tprot;
	distcl(pte);
	tbiscl(v);
	return (1);
}

settprot(tprot)
	long tprot;
{
	register int *ptaddr, i;

	ptaddr = (int *)mfpr(P0BR);
	for (i = 0; i < u.u_tsize; i++) {
		ptaddr[i] &= ~PG_PROT;
		ptaddr[i] |= tprot;
	}
D 2
	mtpr(0, TBIA);
E 2
I 2
	mtpr(TBIA, 0);
E 2
}

I 2
#ifdef notdef
E 2
/*
 * Rest are machine-dependent
 */
D 2

E 2
getmemc(addr)
	caddr_t addr;
{
	register int c;
	struct pte savemap;

	savemap = mmap[0];
	*(int *)mmap = PG_V | PG_KR | btop(addr);
D 2
	mtpr(vmmap, TBIS);
	uncache (&vmmap[(int)addr & PGOFSET]);
E 2
I 2
	mtpr(TBIS, vmmap);
	uncache(&vmmap[(int)addr & PGOFSET]);
E 2
	c = *(char *)&vmmap[(int)addr & PGOFSET];
	mmap[0] = savemap;
D 2
	mtpr(vmmap, TBIS);
E 2
I 2
	mtpr(TBIS, vmmap);
E 2
	return (c & 0377);
}

putmemc(addr, val)
	caddr_t addr;
{
	struct pte savemap;

	savemap = mmap[0];
	*(int *)mmap = PG_V | PG_KW | btop(addr);
D 2
	mtpr(vmmap, TBIS);
E 2
I 2
	mtpr(TBIS, vmmap);
E 2
	*(char *)&vmmap[(int)addr & PGOFSET] = val;

D 2
	mtpr (0, PADC);
	mtpr (0, PACC);
E 2
I 2
	mtpr(PADC, 0);
	mtpr(PACC, 0);
E 2

	mmap[0] = savemap;
D 2
	mtpr(vmmap, TBIS);
E 2
I 2
	mtpr(TBIS, vmmap);
E 2
}
I 2
#endif
E 2

/*
 * Move pages from one kernel virtual address to another.
 * Both addresses are assumed to reside in the Sysmap,
 * and size must be a multiple of CLSIZE.
 */
pagemove(from, to, size)
	register caddr_t from, to;
	int size;
{
	register struct pte *fpte, *tpte;

	if (size % CLBYTES)
		panic("pagemove");
D 8
	fpte = &Sysmap[btop(from - 0xC0000000)];
	tpte = &Sysmap[btop(to - 0xC0000000)];
E 8
I 8
D 11
	fpte = &Sysmap[btop(from - KERNBASE)];
	tpte = &Sysmap[btop(to - KERNBASE)];
E 11
I 11
	fpte = kvtopte(from);
	tpte = kvtopte(to);
E 11
E 8
	while (size > 0) {
		*tpte++ = *fpte;
		*(int *)fpte++ = 0;
D 2
		mtpr(from, TBIS);
		mtpr(to, TBIS);
		mtpr(to, P1DC);		/* purge !! */
E 2
I 2
		mtpr(TBIS, from);
		mtpr(TBIS, to);
		mtpr(P1DC, to);		/* purge !! */
E 2
		from += NBPG;
		to += NBPG;
		size -= NBPG;
	}
}

D 2
#ifndef GLOBKEY
ckeyrelease(key)
/* 
 * release code key
E 2
I 2
D 8
#ifndef vtopte
E 8
/*
D 8
 * Convert a virtual page 
 * number to a pte address.
E 2
 */
I 2
/*VARARGS1*/
struct pte *
vtopte(p, v)
	register struct proc *p;
E 2
{
D 2
	register int ipl,i,j ;
	ipl = spl8();
	if (--ckey_cnt[key-1] < 0 ) {
E 2
I 2

	if ((v & 0x300000) == 0x300000)
		return (struct pte *)(mfpr(SBR) + 0xc0000000 + (v&0xfffff)*4);
D 3
	if (p == 0)
E 3
I 3
	if (p == 0) {
		printf("vtopte v %x\n", v);		/* XXX */
E 3
		panic("vtopte (no proc)");
I 3
	}
E 3
	if (v < p->p_tsize + p->p_dsize)
		return (p->p_p0br + v);
D 5
	return (p->p_p0br + (p->p_szpt*NPTEPG + v - (BTOPUSRSTACK + UPAGES)));
E 5
I 5
	return (p->p_addr + (v - BTOPUSRSTACK));
E 5
}
#endif

E 2
/*
E 8
D 2
		panic ("Code key release");
*/
		printf("Ckey release, key=%d\n", key);
		ckey_cnt[key-1] = 0;
		splx(ipl);
E 2
I 2
 * Code and data key management routines.
 *
I 8
 * The array ckey_cnt maintains the count of processes currently
 * sharing each code key.  The array ckey_cache maintains a record
 * of all code keys used since the last flush of the code cache.
 * Such keys may not be reused, even if unreferenced, until
 * the cache is flushed.  The data cache key handling is analogous.
E 8
 * The arrays ckey_cnt and ckey_cache are allways kept in such a way
 * that the following invariant holds:
 *	ckey_cnt > 0	=>'s	ckey_cache == 1
 * meaning as long as a code key is used by at least one process, it's
 * marked as being 'in the cache'. Of course, the following invariant
 * also holds:
 *	ckey_cache == 0	=>'s	ckey_cnt == 0
 * which is just the reciprocal of the 1'st invariant.
 * Equivalent invariants hold for the data key arrays.
 */
I 8
struct	keystats ckeystats = { NCKEY - 1 };
struct	keystats dkeystats = { NDKEY - 1 };
E 8

/* 
 * Release a code key.
 */
ckeyrelease(key)
	int key;
{
	register int s;

	s = spl8();
	if (--ckey_cnt[key] < 0) {
		printf("ckeyrelease: key = %d\n", key);
		ckey_cnt[key] = 0;
E 2
	}
I 8
	if (ckey_cnt[key] == 0)
		ckeystats.ks_dirty++;
E 8
D 2
	splx(ipl);
E 2
I 2
	splx(s);
E 2
}

D 2

dkeyrelease(key)
E 2
/* 
D 2
 * release data key
E 2
I 2
 * Release a data key.
E 2
 */
I 2
dkeyrelease(key)
	int key;
E 2
{
D 2
	if (--dkey_cnt[key-1] != 0 ) panic ("Data key release");
E 2
I 2
	register int s;

	s = spl8();
	if (--dkey_cnt[key] != 0) {
		printf("dkeyrelease: key = %d\n", key);
		dkey_cnt[key] = 0;
	}
	splx(s);	
I 8
	dkeystats.ks_dirty++;
E 8
E 2
}

I 2
D 4
struct	keystats {
	long	ks_allocs;	/* number of keys allocated */
	long	ks_free;	/* key allocated from free slot */
	long	ks_norefs;	/* key marked in use, but refcnt 0 */
	long	ks_taken;	/* key taken from single process */
	long	ks_shared;	/* key taken from multiple processes */
};
E 4
D 8
struct	keystats ckeystats;
struct	keystats dkeystats;
E 8
I 8
/*
 * Invalidate the data cache for a process
 * by exchanging cache keys.
 */
dkeyinval(p)
	register struct proc *p;
{
D 13
	register int key;
E 13
	int s;

	dkeystats.ks_inval++;
	s = spl8();
	if (--dkey_cnt[p->p_dkey] != 0)
		dkey_cnt[p->p_dkey] = 0;
D 10
	if (p == u.u_procp) {
E 10
I 10
	if (p == u.u_procp && !noproc) {
E 10
		p->p_dkey = getdatakey();
		mtpr(DCK, p->p_dkey);
	} else
		p->p_dkey = 0;
	splx(s);	
}

E 8
E 2
D 4

E 4
D 2
int
getcodekey()
E 2
/* 
D 2
 * Get a code key
E 2
I 2
 * Get a code key.
I 9
 * Strategy: try each of the following in turn
 * until a key is allocated.
 *
 * 1) Find an unreferenced key not yet in the cache.
 *    If this fails, a code cache purge will be necessary.
 * 2) Find an unreferenced key.  Mark all unreferenced keys
 *    as available and purge the cache.
 * 3) Free the keys from all processes not sharing keys.
 * 4) Free the keys from all processes.
E 9
E 2
 */
I 2
getcodekey()
E 2
{
D 2
	register int i, ipl, first;
E 2
I 2
D 8
	register int i, s, freekey, sharedkey;
E 8
I 8
	register int i, s, freekey;
E 8
	register struct proc *p;
I 8
	int desparate = 0;
	static int lastkey = MAXCKEY;
E 8
E 2

D 2
	first = 1;
	ipl = spl8();
retry:
	for (i=0; i<255; i++) {
		if ( (int)ckey_cache[i] == 0) {
			ckey_cache[i] = 1;
			ckey_cnt[i] = 1;
			splx(ipl);
			return (i+1);
		};
E 2
I 2
	ckeystats.ks_allocs++;
	s = spl8();
	freekey = 0;
D 8
	for (i = 1; i <= MAXCKEY; i++) {
E 8
I 8
	for (i = lastkey + 1; ; i++) {
		if (i > MAXCKEY)
			i = 1;
E 8
		if ((int)ckey_cache[i] == 0) {	/* free key, take it */
			ckey_cache[i] = 1, ckey_cnt[i] = 1;
			splx(s);
D 8
			ckeystats.ks_free++;
E 8
I 8
			ckeystats.ks_allocfree++;
			ckeystats.ks_avail--;
			lastkey = i;
E 8
			return (i);
		}
D 8
		if (ckey_cnt[i] == 0) {		/* save for potential use */
			if (freekey == 0)
				freekey = i;
		} else if (ckey_cnt[i] > 1 && i != MAXCKEY)
			sharedkey = i;
E 8
I 8
		if (ckey_cnt[i] == 0)		/* save for potential use */
			freekey = i;
		if (i == lastkey)
			break;
E 8
E 2
	}
D 2
	if ( !first) {
		splx(ipl);
		panic ("Not enough code keys\n");
E 2
I 2
	/*
	 * All code keys were marked as being in cache.
D 8
	 * Moreover, we are assured that sharedkey has a meaningful value,
	 * since we know that the init process and the shell are around
	 * and they have shared text!
	 */
	/*
E 8
	 * If a key was in the cache, but not in use, grab it.
	 */
	if (freekey != 0) {
I 8
purge:
E 8
		/*
D 8
		 * If we've run out of bonified free keys,
E 8
I 8
		 * If we've run out of free keys,
E 8
		 * try and free up some other keys to avoid
		 * future cache purges.
		 */
I 8
		ckey_cnt[freekey] = 1, ckey_cache[freekey] = 1;
E 8
		for (i = 1; i <= MAXCKEY; i++)
D 8
			if (ckey_cnt[i] == 0)
E 8
I 8
			if (ckey_cnt[i] == 0) {
E 8
				ckey_cache[i] = 0;
D 8
		ckey_cnt[freekey] = 1, ckey_cache[freekey] = 1;
E 8
I 8
				ckeystats.ks_avail++;
			}
E 8
		mtpr(PACC, 0);
		splx(s);
I 8
		ckeystats.ks_dirty = 0;
E 8
		ckeystats.ks_norefs++;
		return (freekey);
E 2
	}
D 2
	mtpr (0, PACC);
	first = 0;
	for (i=0; i<255; i++)
		if ( ckey_cnt[i] > 0 ) ckey_cache[i] = 1;
		else ckey_cache[i] = 0;
	goto retry;
E 2
I 2

	/*
	 * All keys are marked as in the cache and in use.
D 8
	 *
	 * Strip some process of their code key. First time,
	 * 1) Try hard not to do that to kernel processes !!
	 * 2) Try hard NOT to strip shared text processes of
	 *    their (shared) key, because then they'll run
	 *    with different keys from now on, i.e. less efficient
	 *    cache utilization.
E 8
I 8
D 9
	 * Release all unshared keys.
E 9
I 9
	 * Release all unshared keys, or, on second pass,
	 * release all keys.
E 9
E 8
	 */
D 8
	for (p = proc; p < procNPROC; p++)
		/*
		 * Look for a meaningful key but not
		 * used and not shared text.
		 */
		if (p->p_ckey && p->p_ckey != MAXCKEY &&
		    ckey_cnt[p->p_ckey] < 2) {
E 8
I 8
steal:
	for (p = allproc; p; p = p->p_nxt)
		if (p->p_ckey != 0 && (p->p_flag & SSYS) == 0) {
E 8
			i = p->p_ckey;
D 8
			p->p_ckey = 0;
			ckey_cnt[i] = 1, ckey_cache[i] = 1;
			mtpr(PACC, 0);
			splx(s);
			ckeystats.ks_taken++;
			return (i);
E 8
I 8
			if (ckey_cnt[i] == 1 || desparate) {
D 9
				if (--ckey_cnt[i]) {
E 9
I 9
				p->p_ckey = 0;
				if (--ckey_cnt[i] == 0) {
E 9
					freekey = i;
D 9
					p->p_ckey = 0;
E 9
					if (p->p_textp)
						p->p_textp->x_ckey = 0;
				}
			}
E 8
		}

D 8
	/*
	 * Second time around!
	 * Highly unlikely situation. It means that all keys are
	 * allocated AND shared (i.e. we have at least 510 active
	 * processes).
	 * Strip some of them. We pick some key (known to be shared
	 * by several processes) and strip the poor process group.
	 * At least 2 processes will loose but we gain one key to be reused.
	 * The way 'shared_key' was produced (above) virtually assures
	 * us that this key isn't the 'init' group key (1) nor the
	 * 'shell' group key (2 or 3). It's probably something like 254.
	 * Could be more straightforward to strip all processes, but it's
	 * better to invest in one more loop here and keep the cache
	 * utilization to a maximum.
	 */
	for (p = proc; p < procNPROC; p++)
		if (p->p_ckey == sharedkey) {
			p->p_ckey = 0;
			ckey_cnt[sharedkey]--;
		}
	if (ckey_cnt[sharedkey] != 0) {
		printf("getcodekey: key = %d cnt = %d\n",
		    sharedkey, ckey_cnt[sharedkey]);
		panic("getcodekey");
E 8
I 8
	if (freekey) {
		ckeystats.ks_taken++;
		goto purge;
	} else {
		desparate++;
		goto steal;
E 8
	}
D 8
	ckey_cnt[sharedkey] = 1, ckey_cache[sharedkey] = 1;
	mtpr(PACC, 0);
	splx(s);
	ckeystats.ks_shared++;
	return (sharedkey);
E 8
E 2
}

D 2
int
getdatakey()
E 2
/* 
D 2
 * Get a data key
E 2
I 2
 * Get a data key.
 *
 * General strategy:
 * 1) Try to find a data key that isn't in the cache. Allocate it.
 * 2) If all data keys are in the cache, find one which isn't
D 8
 *    allocated. Clear all status and allocate this one.
 * 3) If all of them are allocated, pick some process, strip him
 *    of the data key and allocate it. We (cold-bloodedly) pick
 *    one process to be the poor looser because that's the
 *    easiest way to do it and because this extreme situation
 *    ( >255 active processes ) is expected to be temporary,
 *    after which 1) or 2) above should be the usual case.
 * The poor looser is the first process which has a data key.
 * However, we try to spare known kernel processes and daemons
 * (fired at bootstrap time), by searching from proc[LOOSER] and on.
E 8
I 8
D 9
 *    allocated.  Mark all unallocated keys as not in cache and
 *    allocate this one.
 * 3) If all of them are allocated, free the all process' keys
E 9
I 9
 *    allocated.  Mark all unallocated keys as not in cache,
 *    purge the cache, and allocate this one.
 * 3) If all of them are allocated, free all process' keys
E 9
 *    and let them reclaim then as they run.
E 8
E 2
 */
I 2
getdatakey()
E 2
{
D 2
	register int i, ipl, first;
	
	first = 1;
	ipl = spl8();
retry:
	for (i=0; i<255; i++)
		if ( (int)dkey_cache[i] == 0) {
			dkey_cache[i] = 1;
			dkey_cnt[i] = 1;
			splx(ipl);
			return (i+1);
		};
	if ( !first) {
		splx(ipl);
		panic("Not enough data keys\n");
E 2
I 2
D 8
	register int i, s, freekey;
E 8
I 8
	register int i, freekey;
E 8
	register struct proc *p;
I 8
	int s;
	static int lastkey = MAXDKEY;
E 8

	dkeystats.ks_allocs++;
	s = spl8();
	freekey = 0;
D 8
	for (i = 1; i <= MAXDKEY; i++) {
E 8
I 8
	for (i = lastkey + 1; ; i++) {
		if (i > MAXDKEY)
			i = 1;
E 8
		if ((int)dkey_cache[i] == 0) {	/* free key, take it */
			dkey_cache[i] = 1, dkey_cnt[i] = 1;
			splx(s);
D 8
			dkeystats.ks_free++;
E 8
I 8
			dkeystats.ks_allocfree++;
			dkeystats.ks_avail--;
			lastkey = i;
E 8
			return (i);
		}
D 8
		if (dkey_cnt[i] == 0 && freekey == 0)
E 8
I 8
		if (dkey_cnt[i] == 0)
E 8
			freekey = i;
I 8
		if (i == lastkey)
			break;
E 8
E 2
	}
I 8
purge:
E 8
D 2
	mtpr (0, PADC);
	first = 0;
	for (i=0; i<255; i++)
		if ( dkey_cnt[i] > 0 ) dkey_cache[i] = 1;
		else dkey_cache[i] = 0;
	goto retry;
E 2
I 2
	if (freekey) {
		/*
		 * Try and free up some more keys to avoid
		 * future allocations causing a cache purge.
		 */
D 8
		for (i = 1; i < MAXDKEY; i++)
			if (dkey_cnt[i] == 0)
				dkey_cache[i] = 0;
E 8
		dkey_cnt[freekey] = 1, dkey_cache[freekey] = 1;
I 8
		for (i = 1; i <= MAXDKEY; i++)
			if (dkey_cnt[i] == 0) {
				dkey_cache[i] = 0;
				dkeystats.ks_avail++;
			}
E 8
		mtpr(PADC, 0);
		splx(s);
		dkeystats.ks_norefs++;
I 8
		dkeystats.ks_dirty = 0;
E 8
		return (freekey);
	}

	/*
D 9
	 * Now, we have to take a code from someone.
E 9
I 9
	 * Now, we have to take a key from someone.
E 9
I 8
	 * May as well take them all, so we get them
	 * from all of the idle procs.
E 8
	 */
D 8
#define LOOSER 20
	for (p = &proc[LOOSER]; p < procNPROC; p++)
		if (p->p_dkey != 0) {
			i = p->p_dkey;
E 8
I 8
	for (p = allproc; p; p = p->p_nxt)
		if (p->p_dkey != 0 && (p->p_flag & SSYS) == 0) {
			freekey = p->p_dkey;
			dkey_cnt[freekey] = 0;
E 8
			p->p_dkey = 0;
D 8
			dkey_cnt[i] = 1;
			dkey_cache[i] = 1;
			mtpr(PADC, 0);
			splx(s);
			dkeystats.ks_taken++;
			return (i);
E 8
		}
D 8
	panic("getdatakey");
	/*NOTREACHED*/
E 8
I 8
	dkeystats.ks_taken++;
	goto purge;
E 8
E 2
}
D 2
#endif
E 2

D 2
/* General (includes system) virtual address to physical */
E 2
I 2
/*VARGARGS1*/
E 2
vtoph(p, v)
D 2
register struct proc *p;
register unsigned v;
E 2
I 2
	register struct proc *p;
D 8
	register unsigned v;
E 8
I 8
	unsigned v;
E 8
E 2
{
D 2
	register struct pte *thispte;
E 2
I 2
	register struct pte *pte;
I 8
	register unsigned pg;
E 8
E 2

D 2
	thispte = vtopte (p, btop(v));
	return ( (thispte->pg_pfnum << PGSHIFT) + (v & PGOFSET));
E 2
I 2
D 8
	pte = vtopte(p, btop(v));
E 8
I 8
	pg = btop(v);
	if (pg >= BTOPKERNBASE)
		pte = &Sysmap[pg - BTOPKERNBASE];
	else
		pte = vtopte(p, pg);
E 8
	return ((pte->pg_pfnum << PGSHIFT) + (v & PGOFSET));
E 2
}
D 2
		
E 2
E 1
