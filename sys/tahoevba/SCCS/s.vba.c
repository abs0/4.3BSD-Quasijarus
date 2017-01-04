h54317
s 00010/00005/00263
d D 7.2 88/06/29 17:51:01 bostic 18 17
c install approved copyright notice
e
s 00000/00000/00268
d D 7.1 88/05/31 08:42:16 karels 17 16
c bring up to revision 7 for tahoe release
e
s 00014/00009/00254
d D 1.13 88/05/26 09:41:39 karels 16 14
c lint
e
s 00009/00003/00260
d R 7.1 88/05/21 18:33:11 karels 15 14
c bring up to revision 7 for tahoe release
e
s 00003/00005/00260
d D 1.12 88/05/14 11:37:06 karels 14 12
c use external defn. of kvtopte
e
s 00000/00000/00264
d D 1.11.1.1 87/11/24 16:50:24 karels 13 12
x 9
c tahoe distribution (no malloc)
e
s 00007/00001/00258
d D 1.11 87/11/24 16:48:29 karels 12 11
c sccsid, copyright
e
s 00024/00004/00235
d D 1.10 87/11/24 16:47:32 karels 11 10
c I give up, inhibit transfers that might cause problems
e
s 00009/00001/00230
d D 1.9 87/06/30 23:39:59 karels 10 9
c vbmapalloc has a return value now
e
s 00002/00001/00229
d D 1.8 87/06/06 15:09:33 mckusick 9 7
c calloc => malloc
e
s 00030/00030/00200
d D 1.7 87/04/06 17:33:24 karels 7 6
c pfnum's are pages, not bytes!
e
s 00060/00020/00170
d D 1.6 87/04/01 11:56:23 karels 6 5
c new stats, support for scatter-gather
e
s 00131/00076/00059
d D 1.5 87/03/10 18:12:20 karels 5 4
c working (I think!) with uncacheable intermediate buffers:
c add vb_buf struct and vbinit to set up, rm b_upte, remove (old)vbasetup
c and rename vbastart to vbasetup ala uba; use bcopy to kernel, double-
c mapping to user space, and purge user-space cache with dkeyinval
e
s 00000/00003/00135
d D 1.4 86/12/16 22:27:42 karels 4 3
c shut up!
e
s 00014/00011/00124
d D 1.3 86/01/24 01:04:23 sam 3 2
c must look at resid in deciding how much data to copy back to user
e
s 00064/00074/00071
d D 1.2 86/01/05 18:37:38 sam 2 1
c 1st working version (mostly)
e
s 00145/00000/00000
d D 1.1 85/07/21 20:20:52 sam 1 0
c date and time created 85/07/21 20:20:52 by sam
e
u
U
f b 
t
T
I 1
D 12
/*	%M%	%I%	%E%	*/
E 12
I 12
/*
D 16
 * Copyright (c) 1987 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 16
I 16
 * Copyright (c) 1987, 1988 Regents of the University of California.
 * All rights reserved.
E 16
 *
I 16
 * Redistribution and use in source and binary forms are permitted
D 18
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 18
I 18
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
E 18
 *
E 16
 *	%W% (Berkeley) %G%
 */
E 12

I 7
/*
 * Tahoe VERSAbus adapator support routines.
 */

E 7
D 2
#include "../h/param.h"
#include "../h/buf.h"
#include "../h/cmap.h"
#include "../h/conf.h"
#include "../h/dir.h"
#include "../h/dk.h"
#include "../h/map.h"
#include "../machine/mtpr.h"
#include "../machine/pte.h"
#include "../h/systm.h"
#include "../vba/vbavar.h"
#include "../h/user.h"
#include "../h/vmmac.h"
#include "../h/proc.h"
E 2
I 2
D 14
#include "../tahoe/mtpr.h"
#include "../tahoe/pte.h"
E 2

E 14
I 2
#include "param.h"
#include "buf.h"
#include "cmap.h"
#include "conf.h"
#include "dir.h"
#include "dk.h"
#include "map.h"
#include "systm.h"
#include "user.h"
#include "vmparam.h"
#include "vmmac.h"
#include "proc.h"
I 3
#include "syslog.h"
I 9
#include "malloc.h"
E 9
E 3
E 2

I 2
D 14
#include "../tahoevba/vbavar.h"
E 14
I 14
#include "../tahoe/mtpr.h"
#include "../tahoe/pte.h"
E 14

I 5
D 14
#define	kvtopte(v) (&Sysmap[btop((int)(v) &~ KERNBASE)])
E 14
I 14
#include "../tahoevba/vbavar.h"
E 14
I 7

E 7
E 5
E 2
/*
I 2
D 7
 * Tahoe VERSAbus adapator support routines.
E 7
I 7
 * Allocate private page map and intermediate buffer
 * for a VERSAbus device, large enough for maximum transfer size.
 * Intermediate buffer 
 * Make intermediate buffer uncacheable.
E 7
 */
D 7

E 7
I 5
vbainit(vb, xsize, flags)
	register struct vb_buf *vb;
	int xsize, flags;
{
	register struct pte *pte;
	register n;

	vb->vb_flags = flags;
D 7
	vbmapalloc(btoc(xsize)+1, &vb->vb_map, &vb->vb_utl);
E 7
I 7
D 10
	vbmapalloc(btoc(xsize) + 1, &vb->vb_map, &vb->vb_utl);
E 10
I 10
D 16
	if (vbmapalloc(btoc(xsize) + 1, &vb->vb_map, &vb->vb_utl) == 0) {
E 16
I 16
	if (vbmapalloc((int)btoc(xsize) + 1, &vb->vb_map, &vb->vb_utl) == 0) {
E 16
		printf("vbmap exhausted\n");
		return (0);
	}
E 10
E 7
	n = roundup(xsize, NBPG);
I 6
	vb->vb_bufsize = n;
E 6
	if (vb->vb_rawbuf == 0)
D 9
		vb->vb_rawbuf = calloc(n);
E 9
I 9
D 16
		vb->vb_rawbuf = (caddr_t)malloc(n, M_DEVBUF, M_NOWAIT);
E 16
I 16
		vb->vb_rawbuf = (caddr_t)malloc((u_long)n, M_DEVBUF, M_NOWAIT);
E 16
I 10
	if (vb->vb_rawbuf == 0) {
		printf("no memory for device buffer\n");
		return (0);
	}
E 10
E 9
	if ((int)vb->vb_rawbuf & PGOFSET)
D 7
		panic("vbinit");
E 7
I 7
		panic("vbinit pgoff");
E 7
D 16
	vb->vb_physbuf = vtoph((struct proc *)0, vb->vb_rawbuf);
E 16
I 16
	vb->vb_physbuf = (u_long)kvtophys(vb->vb_rawbuf);
E 16
	if (flags & VB_20BIT)
		vb->vb_maxphys = btoc(VB_MAXADDR20);
	else if (flags & VB_24BIT)
		vb->vb_maxphys = btoc(VB_MAXADDR24);
	else
		vb->vb_maxphys = btoc(VB_MAXADDR32);
I 7
	if (btoc(vb->vb_physbuf + n) > vb->vb_maxphys)
		panic("vbinit physbuf");
E 7
	
	/*
	 * Make raw buffer pages uncacheable.
	 */
	pte = kvtopte(vb->vb_rawbuf);
	for (n = btoc(n); n--; pte++)
		pte->pg_nc = 1;
	mtpr(TBIA, 0);
I 10
	return (1);
E 10
}

E 5
/*
I 11
 * Due to unknown hardware or software errors, some sites have problems
 * with strange crashes or corruption of text images when DMA is attempted
 * to kernel addresses spanning a page boundary, or to user addresses
 * (even if the buffer is physically contiguous).  To avoid this behavior,
 * the following toggles inhibit such transfers when set.
 *	vba_copyk: copy transfers to kernel address that span a page boundary
 *	vba_copyu: copy transfers to user addresses
 */
#ifndef VBA_TRICKY
int vba_copyk = 1;
int vba_copyu = 1;
#else
int vba_copyk = 0;
int vba_copyu = 0;
#endif

/*
E 11
E 2
D 7
 * Next piece of logic takes care of unusual cases when less (or more) than
D 6
 * a full block (or sector) are required. This is done by the swaping
E 6
I 6
 * a full block (or sector) are required. This is done by the swapping
E 6
 * logic, when it brings page table pages from the swap device.
 * Since some controllers can't read less than a sector, the
 * only alternative is to read the disk to a temporary buffer and
 * then to move the amount needed back to the process (usually proc[0]
 * or proc[2]).
 * On Tahoe, the virtual addresses versus physical I/O problem creates
 * the need to move I/O data through an intermediate buffer whenever one
 * of the following is true:
D 5
 *	1) The data length is not a multiple of sector size
 *	2) The base address + length cross a physical page boundary
 *	3) The virtual address for I/O is not in the system space.
E 5
I 5
 *	1) The data length is not a multiple of sector size (?)
E 7
I 7
 * Check a transfer to see whether it can be done directly
 * to the destination buffer, or whether it must be copied.
 * On Tahoe, the lack of a bus I/O map forces data to be copied
 * to a physically-contiguous buffer whenever one of the following is true:
 *	1) The data length is not a multiple of sector size.
 *	   (The swapping code does this, unfortunately.)
E 7
 *	2) The buffer is not physically contiguous and the controller
 *	   does not support scatter-gather operations.
 *	3) The physical address for I/O is higher than addressible
 *	   by the device.
I 7
 * This routine is called by the start routine.
 * If copying is necessary, the intermediate buffer is mapped;
 * if the operation is a write, the data is copied into the buffer.
 * It returns the physical address of the first byte for DMA, to
 * be presented to the controller.
E 7
E 5
 */
D 7

D 2
buf_setup(bp, sectsize)
struct	buf *bp;
long	sectsize;	/* This disk's physical sector size */
{
E 2
/*
D 3
 * IO buffer preparation for possible buffered transfer.
 * The relevant page table entries are kept in the 'buf' structure,
 * for later use by the driver's 'start' routine or 'interrupt'
 * routine, when user's data has to be moved to the intermediate
 * buffer.
E 3
I 3
D 5
 * I/O buffer preparation for possible buffered transfer.
 * The relevant page table entries are kept in the buf structure,
 * for later use by the driver's start or interrupt routine
 * when user's data has to be moved to the intermediate buffer.
E 3
 */
I 2
vbasetup(bp, sectsize)
	register struct buf *bp;
	int sectsize;	/* This disk's physical sector size */
{
E 2
	caddr_t	source_pte_adr;
I 2
	register int v;
E 2

	if ((((int)bp->b_un.b_addr & PGOFSET) + bp->b_bcount) > NBPG ||
D 2
			(bp->b_bcount % sectsize) != 0 ||
			((int)bp->b_un.b_addr & 0xc0000000) != 0xc0000000) {
E 2
I 2
	    (bp->b_bcount % sectsize) != 0 ||
	    ((int)bp->b_un.b_addr & 0xc0000000) != 0xc0000000) {
E 2
		bp->b_flags |= B_NOT1K;
D 2
		if (bp->b_flags & B_DIRTY)
			source_pte_adr = (caddr_t)vtopte(&proc[2], 
						btop(bp->b_un.b_addr));
			else source_pte_adr = (caddr_t)vtopte(bp->b_proc, 
						btop(bp->b_un.b_addr));
E 2
I 2
		v = btop(bp->b_un.b_addr);
		source_pte_adr = (caddr_t)(bp->b_flags&B_DIRTY ?
		    vtopte(&proc[2], v) : vtopte(bp->b_proc, v));
E 2
		bp->b_ptecnt = (bp->b_bcount + NBPG -1 +
D 2
			((int)bp->b_un.b_addr & PGOFSET)) / NBPG;
		bcopy (source_pte_adr, bp->b_upte, bp->b_ptecnt*4);
E 2
I 2
		    ((int)bp->b_un.b_addr & PGOFSET)) / NBPG;
		bcopy(source_pte_adr, (caddr_t)bp->b_upte,
		    (unsigned)bp->b_ptecnt*4);
E 2
	}
}

D 2
int mapbusy;		/* semaphore on the system IOmap buffer */

get_ioadr(bp, buffer, map, utl)
struct buf *bp;
char	*buffer;	/* Driver's own intermediate buffer. */
long	*map;		/* A bunch of system pte's */
struct	user *utl;	/* The system address mapped through 'map' */
E 2
/*
D 3
 * This routine is usually called by the 'start' routine. It
 * returns the physical address of the first byte for IO, to
E 3
I 3
 * This routine is usually called by the start routine. It
E 5
I 5
 * Check a transfer to see whether it can be done directly
 * to the destination buffer, or whether it must be copied.
 * If copying is necessary, the intermediate buffer is mapped.
 * This routine is called by the start routine. It
E 5
 * returns the physical address of the first byte for i/o, to
E 3
 * be presented to the controller. If intermediate buffering is
 * needed and a write out is done, now is the time to get the
 * original user's data in the buffer.
 */
E 7
I 2
D 5
vbastart(bp, v, map, utl)
	struct buf *bp;
	caddr_t v;		/* Driver's own intermediate buffer. */
	long *map;		/* A bunch of system pte's */
	caddr_t utl;	/* The system address mapped through 'map' */
E 5
I 5
u_long
vbasetup(bp, vb, sectsize)
	register struct buf *bp;
	register struct vb_buf *vb;
	int sectsize;
E 5
E 2
{
D 5
	register phadr, i;
E 5
I 5
	register struct pte *spte, *dpte;
	register int p, i;
	int npf, o, v;
E 5

D 5
	if (bp->b_flags & B_NOT1K) {
D 2
		phadr = vtoph (bp->b_proc, buffer);
		if ( (bp->b_flags & B_READ) == 0) {
E 2
I 2
		phadr = vtoph(bp->b_proc, (unsigned)v);
E 5
I 5
	o = (int)bp->b_un.b_addr & PGOFSET;
D 7
	npf = i = btoc(bp->b_bcount + o);
E 7
I 7
	npf = btoc(bp->b_bcount + o);
E 7
	vb->vb_iskernel = (((int)bp->b_un.b_addr & KERNBASE) == KERNBASE);
D 11
	if (vb->vb_iskernel)
E 11
I 11
	if (vb->vb_iskernel) {
E 11
		spte = kvtopte(bp->b_un.b_addr);
D 11
	else
E 11
I 11
if (vba_copyk && (o != 0 || npf > 1)) goto copy;
	} else {
E 11
		spte = vtopte((bp->b_flags&B_DIRTY) ? &proc[2] : bp->b_proc,
		    btop(bp->b_un.b_addr));
D 11
	if (bp->b_bcount % sectsize)
E 11
I 11
if (vba_copyu) goto copy;
	}
	if (bp->b_bcount % sectsize != 0 || (o & (sizeof(long) - 1)) != 0)
E 11
		goto copy;
	else if ((vb->vb_flags & VB_SCATTER) == 0 ||
D 11
	    vb->vb_maxphys != VB_MAXADDR32) {
E 11
I 11
	    vb->vb_maxphys != btoc(VB_MAXADDR32)) {
E 11
		dpte = spte;
D 7
		for (p = (dpte++)->pg_pfnum; --i; dpte++) {
			if ((v = dpte->pg_pfnum) != p + NBPG &&
E 7
I 7
		p = (dpte++)->pg_pfnum;
		for (i = npf; --i > 0; dpte++) {
			if ((v = dpte->pg_pfnum) != p + CLSIZE &&
E 7
			    (vb->vb_flags & VB_SCATTER) == 0)
				goto copy;
			if (p >= vb->vb_maxphys)
				goto copy;
			p = v;
		}
		if (p >= vb->vb_maxphys)
			goto copy;
	}
	vb->vb_copy = 0;
D 6
	if ((bp->b_flags & BREAD) == 0)
		if (vb->vb_iskernel)
			vbastat.kw_raw++;
		else
			vbastat.uw_raw++;
E 6
I 6
	if (vb->vb_iskernel)
		vbastat.k_raw++;
	else
		vbastat.u_raw++;
E 6
	return ((spte->pg_pfnum << PGSHIFT) + o);

copy:
	vb->vb_copy = 1;
I 6
	if (bp->b_bcount > vb->vb_bufsize)
		panic("vba xfer too large");
E 6
	if (vb->vb_iskernel) {
E 5
D 6
		if ((bp->b_flags & B_READ) == 0) {
E 6
I 6
		if ((bp->b_flags & B_READ) == 0)
E 6
E 2
D 3
			for (i=0; i<bp->b_ptecnt; i++) {
E 3
I 3
D 5
			for (i = 0; i < bp->b_ptecnt; i++) {
E 3
				map[i] = bp->b_upte[i] 
					& ~PG_PROT | PG_V | PG_KR;
D 2
				mtpr ((caddr_t)utl + i*NBPG, TBIS);
				mtpr ((caddr_t)utl + i*NBPG, P1DC);
E 2
I 2
				mtpr(TBIS, utl + i*NBPG);
				mtpr(P1DC, utl + i*NBPG);
E 2
			}
D 2
			bcopy (((int)bp->b_un.b_addr & PGOFSET) + 
					(caddr_t)utl, buffer,bp->b_bcount);
E 2
I 2
			bcopy(((int)bp->b_un.b_addr & PGOFSET) + utl,
			    v, (unsigned)bp->b_bcount);
E 5
I 5
			bcopy(bp->b_un.b_addr, vb->vb_rawbuf,
			    (unsigned)bp->b_bcount);
D 6
			vbastat.kw_copy++;
E 5
E 2
		}
E 6
I 6
		vbastat.k_copy++;
E 6
D 2
	} 
	else
		phadr = vtoph (bp->b_proc, bp->b_un.b_addr);
E 2
I 2
D 5
	} else
		phadr = vtoph(bp->b_proc, (unsigned)bp->b_un.b_addr);
E 2
	return (phadr);
E 5
I 5
	} else  {
		dpte = vb->vb_map;
		for (i = npf, p = (int)vb->vb_utl; i--; p += NBPG) {
D 7
			*(int *)dpte++ = (spte++)->pg_pfnum | PG_V | PG_KW;
E 7
I 7
			*(int *)dpte++ = (spte++)->pg_pfnum |
			    PG_V | PG_KW | PG_N;
E 7
			mtpr(TBIS, p);
		}
D 6
		if ((bp->b_flags & B_READ) == 0) {
E 6
I 6
		if ((bp->b_flags & B_READ) == 0)
E 6
			bcopy(vb->vb_utl + o, vb->vb_rawbuf,
			    (unsigned)bp->b_bcount);
D 6
			vbastat.uw_copy++;
		}
E 6
I 6
		vbastat.u_copy++;
E 6
	}
	return (vb->vb_physbuf);
E 5
}

D 2
end_transfer(bp, buffer, map, utl)
register struct buf *bp;
char	*buffer;	/* Driver's own intermediate buffer. */
long	*map;	/* A bunch of system pte's */
struct	user *utl;	/* The system address mapped through 'map' */
{
E 2
/*
D 5
 * Called by the driver's interrupt routine, after the data is
 * realy in or out. If that was a read, and the NOT1K flag was on,
 * now is the time to move the data back into user's space. 
E 5
I 5
 * Called by the driver's interrupt routine, after DMA is completed.
 * If the operation was a read, copy data to final buffer if necessary
 * or invalidate data cache for cacheable direct buffers.
E 5
D 2
 * Mostly analogous to the get_ioadr routine, but in the reverse direction.
E 2
I 2
 * Similar to the vbastart routine, but in the reverse direction.
E 2
 */
I 2
D 5
vbadone(bp, v, map, utl)
E 5
I 5
vbadone(bp, vb)
E 5
	register struct buf *bp;
D 5
	caddr_t v;	/* Driver's own intermediate buffer. */
	long *map;	/* A bunch of system pte's */
	caddr_t utl;	/* The system address mapped through 'map' */
E 5
I 5
	register struct vb_buf *vb;
E 5
{
E 2
D 5
	register i, cnt;
E 5
I 5
	register npf;
	register caddr_t v;
	int o;
E 5

D 5
	if (bp->b_flags & B_READ)
		if (bp->b_flags & B_NOT1K) {
D 3
			for (cnt = bp->b_bcount ; cnt >= 0; cnt -= NBPG) {
E 3
I 3
			for (cnt = bp->b_bcount; cnt >= 0; cnt -= NBPG) {
E 3
D 2
				mtpr ((int)buffer + cnt-1, P1DC);
				mtpr ((caddr_t)bp->b_un.b_addr + cnt-1, P1DC);
E 2
I 2
				mtpr(P1DC, (int)v + cnt-1);
				mtpr(P1DC, (caddr_t)bp->b_un.b_addr + cnt-1);
E 5
I 5
	if (bp->b_flags & B_READ) {
		o = (int)bp->b_un.b_addr & PGOFSET;
		if (vb->vb_copy) {
D 6
			if (vb->vb_iskernel) {
E 6
I 6
			if (vb->vb_iskernel)
E 6
				bcopy(vb->vb_rawbuf, bp->b_un.b_addr,
				    (unsigned)(bp->b_bcount - bp->b_resid));
D 6
				vbastat.kr_copy++;
			} else {
E 6
I 6
			else {
E 6
				bcopy(vb->vb_rawbuf, vb->vb_utl + o,
				    (unsigned)(bp->b_bcount - bp->b_resid));
				dkeyinval(bp->b_proc);
D 6
				vbastat.ur_copy++;
E 6
E 5
E 2
			}
D 2
			if ( ((int)buffer & PGOFSET) != 0)
				mtpr (buffer, P1DC);
			if ( ((int)bp->b_un.b_addr & PGOFSET) != 0)
				mtpr ((caddr_t)bp->b_un.b_addr, P1DC);
E 2
I 2
D 5
			if (((int)v & PGOFSET) != 0)
				mtpr(P1DC, v);
			if (((int)bp->b_un.b_addr & PGOFSET) != 0)
				mtpr(P1DC, (caddr_t)bp->b_un.b_addr);
E 2
D 3
			for (i=0; i<bp->b_ptecnt; i++) {
E 3
I 3
			for (i = 0; i < bp->b_ptecnt; i++) {
E 3
				map[i] = bp->b_upte[i] 
					& ~PG_PROT | PG_V | PG_KW;
D 2
				mtpr ((caddr_t)utl + i*NBPG, TBIS);
E 2
I 2
				mtpr(TBIS, utl + i*NBPG);
E 5
I 5
		} else {
			if (vb->vb_iskernel) {
				npf = btoc(bp->b_bcount + o);
				for (v = bp->b_un.b_addr; npf--; v += NBPG)
					mtpr(P1DC, (int)v);
D 6
				vbastat.kr_raw++;
			} else {
E 6
I 6
			} else
E 6
				dkeyinval(bp->b_proc);
D 6
				vbastat.ur_raw++;
E 5
E 2
			}
E 6
I 3
D 4
if (bp->b_resid != 0)
	log(LOG_NOTICE, "vbadone: dev %o bcount %d resid %d\n",
	    bp->b_dev, bp->b_bcount, bp->b_resid);
E 4
E 3
D 2
			bcopy (buffer, 
				((int)bp->b_un.b_addr & PGOFSET) + 
					(caddr_t)utl, bp->b_bcount);
		}
		else
			mtpr (bp->b_un.b_addr, P1DC);
E 2
I 2
D 5
			bcopy(v, ((int)bp->b_un.b_addr & PGOFSET)+utl,
D 3
			    (unsigned)bp->b_bcount);
E 3
I 3
			    (unsigned)(bp->b_bcount - bp->b_resid));
E 3
		} else
			mtpr(P1DC, bp->b_un.b_addr);
E 2
	bp->b_flags &= ~B_NOT1K;
E 5
I 5
		}
	}
I 6
}

/*
 * Set up a scatter-gather operation for SMD/E controller.
 * This code belongs half-way between vd.c and this file.
 */
#include "vdreg.h"

vba_sgsetup(bp, vb, sg)
	register struct buf *bp;
	struct vb_buf *vb;
	struct trsg *sg;
{
	register struct pte *spte;
	register struct addr_chain *adr;
D 16
	register int npf, i;
E 16
I 16
	register int i;
E 16
	int o;

	o = (int)bp->b_un.b_addr & PGOFSET;
D 16
	npf = btoc(bp->b_bcount + o);
E 16
	vb->vb_iskernel = (((int)bp->b_un.b_addr & KERNBASE) == KERNBASE);
	vb->vb_copy = 0;
	if (vb->vb_iskernel) {
		spte = kvtopte(bp->b_un.b_addr);
		vbastat.k_sg++;
	} else {
		spte = vtopte((bp->b_flags&B_DIRTY) ? &proc[2] : bp->b_proc,
		    btop(bp->b_un.b_addr));
		vbastat.u_sg++;
	}

	i = min(NBPG - o, bp->b_bcount);
	sg->start_addr.wcount = (i + 1) >> 1;
	sg->start_addr.memadr = ((spte++)->pg_pfnum << PGSHIFT) + o;
	i = bp->b_bcount - i;
	if (i > VDMAXPAGES * NBPG)
		panic("vba xfer too large");
	i = (i + 1) >> 1;
	for (adr = sg->addr_chain; i > 0; adr++, i -= NBPG / 2) {
		adr->nxt_addr = (spte++)->pg_pfnum << PGSHIFT;
D 16
		adr->nxt_len = min(i, NBPG / 2);
E 16
I 16
		adr->nxt_len = imin(i, NBPG / 2);
E 16
	}
	adr->nxt_addr = 0;
	adr++->nxt_len = 0;
	return ((adr - sg->addr_chain) * sizeof(*adr) / sizeof(long));
E 6
E 5
}
D 2

movob (byte, address)
{
	asm(" movob 7(fp),*8(fp);");
}

movow (word, address)
{
	asm(" movow 6(fp),*8(fp);");
}

E 2
E 1
