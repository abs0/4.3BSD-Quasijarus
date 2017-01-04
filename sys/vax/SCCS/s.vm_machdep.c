h52076
s 00002/00002/00181
d D 7.3 88/05/07 14:17:38 karels 18 17
c cleanup: use kvtopte
e
s 00001/00030/00182
d D 7.2 87/11/30 10:58:00 karels 17 16
c mapin, mapout removed
e
s 00001/00001/00211
d D 7.1 86/06/05 00:50:13 mckusick 16 15
c 4.3BSD release version
e
s 00002/00002/00210
d D 6.8 85/10/23 18:15:38 karels 15 14
c maxtsize  now in bytes
e
s 00007/00001/00205
d D 6.7 85/06/08 13:47:38 mckusick 14 13
c Add copyright
e
s 00008/00003/00198
d D 6.6 85/05/28 12:13:30 mckusick 13 12
c must be careful to check bss and data sizes separately to avoid
c problems if their sum overflows
e
s 00003/00028/00198
d D 6.5 85/03/08 15:48:27 mckusick 12 11
c chksize() can now use constants calculated by vminit() in vm_page.c
e
s 00000/00005/00226
d D 6.4 84/11/19 11:19:46 karels 11 10
c compiler is fixed
e
s 00011/00011/00220
d D 6.3 84/08/28 18:11:27 bloom 10 9
c Change to includes.  No more ../h
e
s 00005/00000/00226
d D 6.2 83/11/18 09:59:14 karels 9 8
c Avoid compiler bug sign-extending c_blkno
e
s 00000/00000/00226
d D 6.1 83/07/29 07:21:43 sam 8 7
c 4.2 distribution
e
s 00002/00003/00224
d D 5.7 83/06/14 23:38:10 sam 7 6
c questionable, but make mapin a macro since it used to be a 
c simple assignment statement (ought to look at how much this buys us)
e
s 00006/00005/00221
d D 5.6 83/05/27 13:48:37 sam 6 5
c lint
e
s 00032/00004/00194
d D 5.5 83/05/18 02:10:07 sam 5 4
c support multiple variable sized swap areas (some from shannon)
e
s 00001/00001/00197
d D 5.4 83/05/10 15:25:08 sam 4 3
c sign extension problem because daddr_t is long instead of 
c u_long; from rws@mit-xx
e
s 00028/00001/00170
d D 5.3 82/12/17 11:57:00 sam 3 2
c sun merge
e
s 00005/00000/00166
d D 5.2 82/11/13 22:59:18 sam 2 1
c merge of 4.1b with 4.1c
e
s 00166/00000/00000
d D 5.1 82/11/06 21:17:11 sam 1 0
c date and time created 82/11/06 21:17:11 by sam
e
u
U
t
T
I 1
D 14
/*	%M%	%I%	%E%	*/
E 14
I 14
/*
D 16
 * Copyright (c) 1982 Regents of the University of California.
E 16
I 16
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 16
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 14

I 3
D 10
#include "../machine/pte.h"
E 10
I 10
D 17
#include "pte.h"
E 10

E 17
E 3
D 10
#include "../h/param.h"
D 3
#include "../h/pte.h"
E 3
#include "../h/systm.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/proc.h"
#include "../h/cmap.h"
#include "../h/mount.h"
#include "../h/vm.h"
I 5
#include "../h/text.h"
E 10
I 10
#include "param.h"
#include "systm.h"
#include "dir.h"
#include "user.h"
#include "proc.h"
#include "cmap.h"
#include "mount.h"
#include "vm.h"
#include "text.h"
E 10
E 5

I 17
#include "pte.h"
E 17
D 10
#include "../vax/mtpr.h"
E 10
I 10
#include "mtpr.h"
E 10

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
		mtpr(TBIS, vaddr + sizeof (struct user));
}
D 17

D 7
/*
 *
 */
E 7
I 7
#ifndef mapin
E 7
mapin(pte, v, pfnum, count, prot)
	struct pte *pte;
D 6
	u_int v;
	int pfnum, count, prot;
E 6
I 6
	u_int v, pfnum;
	int count, prot;
E 6
{

	while (count > 0) {
		*(int *)pte++ = pfnum | prot;
		mtpr(TBIS, ptob(v));
		v++;
		pfnum++;
		count--;
	}
}
I 7
#endif
E 7

I 2
#ifdef notdef
E 2
/*ARGSUSED*/
mapout(pte, size)
	register struct pte *pte;
	int size;
{

	panic("mapout");
}
I 2
#endif
E 17
E 2

/*
D 5
 * Check that a process will not be too large.
E 5
I 5
 * Check for valid program size
I 13
 * NB - Check data and data growth separately as they may overflow 
 * when summed together.
E 13
E 5
 */
D 13
chksize(ts, ds, ss)
D 5
	size_t ts, ds, ss;
E 5
I 5
D 6
	unsigned ts, ds, ss;
E 6
I 6
	register unsigned ts, ds, ss;
E 13
I 13
chksize(ts, ids, uds, ss)
	unsigned ts, ids, uds, ss;
E 13
E 6
E 5
{
I 5
D 12
	static int maxdmap = 0;
E 12
I 12
D 15
	extern int maxtsize;
E 15
I 15
	extern unsigned maxtsize;
E 15
E 12
E 5

D 5
	if (ts>MAXTSIZ || ds>MAXDSIZ || ss>MAXSSIZ) {
E 5
I 5
D 12
	if (ts > MAXTSIZ || ds > MAXDSIZ || ss > MAXSSIZ) {
E 5
		u.u_error = ENOMEM;
D 5
		return(1);
E 5
I 5
		return (1);
	}
	/* check for swap map overflow */
	if (maxdmap == 0) {
D 6
		int i, blk;
E 6
I 6
		register int i, blk;
E 6

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
E 12
I 12
D 13
	if (ts > maxtsize || ctob(ds) > u.u_rlimit[RLIMIT_DATA].rlim_cur ||
E 13
I 13
D 15
	if (ts > maxtsize ||
E 15
I 15
	if (ctob(ts) > maxtsize ||
E 15
	    ctob(ids) > u.u_rlimit[RLIMIT_DATA].rlim_cur ||
	    ctob(uds) > u.u_rlimit[RLIMIT_DATA].rlim_cur ||
	    ctob(ids + uds) > u.u_rlimit[RLIMIT_DATA].rlim_cur ||
E 13
	    ctob(ss) > u.u_rlimit[RLIMIT_STACK].rlim_cur) {
E 12
		u.u_error = ENOMEM;
		return (1);
E 5
	}
	return (0);
}

/*ARGSUSED*/
newptes(pte, v, size)
	register struct pte *pte;
	u_int v;
	register int size;
{
	register caddr_t a = ptob(v);

I 2
#ifdef lint
	pte = pte;
#endif
E 2
	if (size >= 8) {
		mtpr(TBIA, 0);
		return;
	}
	while (size > 0) {
		mtpr(TBIS, a);
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
I 9
D 11
#ifdef	lint
E 11
E 9
D 4
			munhash(mount[c->c_mdev].m_dev, (daddr_t)c->c_blkno);
E 4
I 4
D 6
			munhash(mount[c->c_mdev].m_dev, c->c_blkno);
E 6
I 6
			munhash(mount[c->c_mdev].m_dev,
			    (daddr_t)(u_long)c->c_blkno);
I 9
D 11
#else
			/* avoid C compiler sign-extension bug */
			munhash(mount[c->c_mdev].m_dev, c->c_blkno);
#endif
E 11
E 9
E 6
E 4
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
	mtpr(TBIA, 0);
}

/*
 * Rest are machine-dependent
 */

getmemc(addr)
	caddr_t addr;
{
	register int c;
	struct pte savemap;

	savemap = mmap[0];
	*(int *)mmap = PG_V | PG_KR | btop(addr);
	mtpr(TBIS, vmmap);
	c = *(char *)&vmmap[(int)addr & PGOFSET];
	mmap[0] = savemap;
	mtpr(TBIS, vmmap);
	return (c & 0377);
}

putmemc(addr, val)
	caddr_t addr;
{
	struct pte savemap;

	savemap = mmap[0];
	*(int *)mmap = PG_V | PG_KW | btop(addr);
	mtpr(TBIS, vmmap);
	*(char *)&vmmap[(int)addr & PGOFSET] = val;
	mmap[0] = savemap;
	mtpr(TBIS, vmmap);
I 3
}

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
D 18
	fpte = &Sysmap[btop(from - 0x80000000)];
	tpte = &Sysmap[btop(to - 0x80000000)];
E 18
I 18
	fpte = kvtopte(from);
	tpte = kvtopte(to);
E 18
	while (size > 0) {
		*tpte++ = *fpte;
		*(int *)fpte++ = 0;
		mtpr(TBIS, from);
		mtpr(TBIS, to);
		from += NBPG;
		to += NBPG;
		size -= NBPG;
	}
E 3
}
E 1
