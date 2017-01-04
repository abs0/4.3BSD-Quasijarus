h28254
s 00001/00014/00099
d D 7.5 87/07/21 17:36:07 mckusick 38 37
c delete unneeded header files
e
s 00000/00047/00113
d D 7.4 87/06/06 15:12:30 mckusick 37 36
c calloc is gone
e
s 00001/00001/00159
d D 7.3 86/12/15 20:23:26 sam 36 35
c lint
e
s 00009/00003/00151
d D 7.2 86/11/03 12:00:12 karels 35 34
c merge in tahoe support
e
s 00001/00001/00153
d D 7.1 86/06/05 00:07:24 mckusick 34 33
c 4.3BSD release version
e
s 00001/00001/00153
d D 6.8 86/03/09 15:36:16 karels 33 32
c someone DOES use it
e
s 00004/00002/00150
d D 6.7 86/02/23 23:10:17 karels 32 31
c lint
e
s 00007/00001/00145
d D 6.6 85/06/08 14:42:25 mckusick 31 30
c Add copyright
e
s 00012/00012/00134
d D 6.5 84/08/29 20:21:48 bloom 30 29
c Change to includes.  no more ../h
e
s 00002/00000/00144
d D 6.4 84/08/22 19:03:05 mckusick 29 28
c imax, imin, max, and min are now expanded inline
e
s 00010/00000/00134
d D 6.3 84/07/28 12:05:52 mckusick 28 27
c allocate profiling buffers from special profiling map instead of Kernelmap
e
s 00000/00038/00134
d D 6.2 83/09/09 17:26:13 mckusick 27 26
c get rid of passuc as it is equivalent to ureadc (shannon)
e
s 00000/00000/00172
d D 6.1 83/07/29 06:36:33 sam 26 25
c 4.2 distribution
e
s 00001/00001/00171
d D 4.22 83/05/27 12:47:36 sam 25 24
c merge of bill's code plus lint (plus, of course, cleanup of bill's bugs)
e
s 00002/00001/00170
d D 4.21 82/12/17 11:45:52 sam 24 23
c sun merge
e
s 00001/00014/00170
d D 4.20 82/10/31 00:39:24 root 23 22
c bugs in #ifndef vax stuff (from 68k)
e
s 00000/00000/00184
d D 4.20 82/10/19 10:31:06  23 22
c more lint
e
s 00003/00002/00181
d D 4.19 82/10/17 21:49:40 root 22 21
c more lint
e
s 00003/00003/00180
d D 4.18 82/10/17 11:28:54 root 21 20
c nulldev and nullioctl return values
e
s 00000/00095/00183
d D 4.17 82/08/22 20:37:01 root 20 19
c remove cpass and passc (now ureadc and uwritec in sys_generic)
c also drop copyuout (in favor of iomove) and move pfind to sys_process
e
s 00005/00005/00273
d D 4.16 82/08/14 18:01:19 root 19 18
c read() now goes through readip()
e
s 00069/00000/00209
d D 4.15 82/08/13 00:04:14 wnj 18 17
c fixes to get uio'd readi for char devs
e
s 00023/00003/00186
d D 4.14 82/07/25 23:12:37 root 17 16
c add more vax less calls bcmp and strlen
e
s 00015/00000/00174
d D 4.13 82/07/24 18:10:39 root 16 15
c merge with calder
e
s 00051/00192/00123
d D 4.12 82/07/15 20:23:52 root 15 14
c pull out bmap, add calloc and ffs
e
s 00009/00004/00306
d D 4.11 82/06/07 23:47:29 mckusick 14 13
c fix read-ahead block calculation
e
s 00134/00063/00176
d D 4.10 82/04/19 19:36:42 mckusic 13 12
c merge into new file system
e
s 00002/00000/00237
d D 4.9 81/11/20 14:43:52 wnj 12 11
c more lint
e
s 00000/00002/00237
d D 4.8 81/08/31 01:11:24 wnj 11 10
c always have cpass (needed by error log code)
e
s 00001/00001/00238
d D 4.7 81/03/11 21:49:58 wnj 10 9
c speeeling error
e
s 00002/00001/00237
d D 4.6 81/03/11 19:17:16 wnj 9 8
c cpass #if NCT > 0
e
s 00001/00001/00237
d D 4.5 81/03/09 01:49:05 wnj 8 7
c lint and a few minor fixed
e
s 00002/00000/00236
d D 4.4 81/03/09 00:33:30 wnj 7 6
c lint
e
s 00000/00002/00236
d D 4.3 80/12/20 01:29:53 wnj 6 5
c include cpass()
e
s 00000/00000/00238
d D 4.2 80/12/16 15:58:54 wnj 5 4
c comet changes
e
s 00000/00000/00238
d D 4.1 80/11/09 17:32:40 bill 4 3
c minor fixups to restart stuff; version 4.1 for distrib
e
s 00024/00004/00214
d D 3.3 80/10/03 10:45:28 bill 3 2
c file system update orderings
e
s 00001/00001/00217
d D 3.2 80/06/07 02:47:32 bill 2 1
c %H%->%G%
e
s 00218/00000/00000
d D 3.1 80/04/09 16:04:17 bill 1 0
c date and time created 80/04/09 16:04:17 by bill
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%H%	*/
E 2
I 2
D 8
/*	%M%	%I%	%G%	*/
E 8
I 8
D 31
/*	%M%	%I%	%E%	*/
E 31
I 31
/*
D 34
 * Copyright (c) 1982 Regents of the University of California.
E 34
I 34
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 34
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 31
E 8
E 2

I 24
D 38
#include "../machine/pte.h"

E 24
I 13
D 15
/* merged into kernel:	@(#)subr.c 2.2 4/8/82 */

E 15
E 13
D 30
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/conf.h"
#include "../h/inode.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/buf.h"
#include "../h/proc.h"
I 13
#include "../h/fs.h"
I 15
#include "../h/vm.h"
D 24
#include "../h/pte.h"
E 24
#include "../h/cmap.h"
I 18
#include "../h/uio.h"
E 30
I 30
#include "param.h"
#include "systm.h"
#include "conf.h"
#include "inode.h"
#include "dir.h"
#include "user.h"
#include "buf.h"
#include "proc.h"
#include "fs.h"
#include "vm.h"
#include "cmap.h"
#include "uio.h"
E 38
I 38
#include "errno.h"
E 38
E 30
E 18
E 15
E 13

/*
D 15
 * Bmap defines the structure of file system storage
 * by returning the physical block number on a device given the
 * inode and the logical block number in a file.
 * When convenient, it also leaves the physical
 * block number of the next block of the file in rablock
 * for use in read-ahead.
 */
I 13
/*VARARGS3*/
E 13
daddr_t
D 13
bmap(ip, bn, rwflg)
register struct inode *ip;
daddr_t bn;
E 13
I 13
bmap(ip, bn, rwflg, size)
	register struct inode *ip;
	daddr_t bn;
	int rwflg;
	int size;	/* supplied only when rwflg == B_WRITE */
E 13
{
D 13
	register i;
E 13
I 13
	register int i;
	int osize, nsize;
E 13
	struct buf *bp, *nbp;
I 13
	struct fs *fs;
E 13
	int j, sh;
D 13
	daddr_t nb, *bap;
	dev_t dev;
E 13
I 13
	daddr_t nb, *bap, pref, blkpref();
E 13

D 13
	if(bn < 0) {
E 13
I 13
	if (bn < 0) {
E 13
		u.u_error = EFBIG;
D 13
		return((daddr_t)0);
E 13
I 13
		return ((daddr_t)0);
E 13
	}
D 13
	dev = ip->i_dev;
E 13
I 13
	fs = ip->i_fs;
E 13
	rablock = 0;
I 14
	rasize = 0;		/* conservative */
E 14

	/*
D 13
	 * blocks 0..NADDR-4 are direct blocks
E 13
I 13
	 * If the next write will extend the file into a new block,
	 * and the file is currently composed of a fragment
	 * this fragment has to be extended to be a full block.
E 13
	 */
D 13
	if(bn < NADDR-3) {
E 13
I 13
	nb = lblkno(fs, ip->i_size);
	if (rwflg == B_WRITE && nb < NDADDR && nb < bn) {
		osize = blksize(fs, ip, nb);
		if (osize < fs->fs_bsize && osize > 0) {
			bp = realloccg(ip, ip->i_db[nb],
				nb == 0 ? 0 : ip->i_db[nb - 1] + fs->fs_frag,
				osize, fs->fs_bsize);
			ip->i_size = (nb + 1) * fs->fs_bsize;
			ip->i_db[nb] = dbtofsb(fs, bp->b_blkno);
			ip->i_flag |= IUPD|ICHG;
			bdwrite(bp);
		}
	}
	/*
	 * The first NDADDR blocks are direct blocks
	 */
	if (bn < NDADDR) {
E 13
		i = bn;
D 13
		nb = ip->i_un.i_addr[i];
		if(nb == 0) {
			if(rwflg==B_READ || (bp = alloc(dev))==NULL)
				return((daddr_t)-1);
			nb = dbtofsb(bp->b_blkno);
E 13
I 13
		nb = ip->i_db[i];
		if (rwflg == B_READ) {
			if (nb == 0)
				return ((daddr_t)-1);
			goto gotit;
		}
		if (nb == 0 || ip->i_size < (i + 1) * fs->fs_bsize) {
			if (nb != 0) {
				/* consider need to reallocate a frag */
				osize = fragroundup(fs, blkoff(fs, ip->i_size));
				nsize = fragroundup(fs, size);
				if (nsize <= osize)
					goto gotit;
				bp = realloccg(ip, nb, i == 0 ?
					0 : ip->i_db[i - 1] + fs->fs_frag,
					osize, nsize);
			} else {
				if (ip->i_size < (i + 1) * fs->fs_bsize)
					nsize = fragroundup(fs, size);
				else
					nsize = fs->fs_bsize;
				bp = alloc(ip, i > 0 ?
					ip->i_db[i - 1] + fs->fs_frag : 0,
					nsize);
			}
			if (bp == NULL)
				return ((daddr_t)-1);
			nb = dbtofsb(fs, bp->b_blkno);
E 13
D 3
			bdwrite(bp);
E 3
I 3
			if ((ip->i_mode&IFMT) == IFDIR)
				/*
				 * Write directory blocks synchronously
				 * so they never appear with garbage in
				 * them on the disk.
				 */
				bwrite(bp);
			else
				bdwrite(bp);
E 3
D 13
			ip->i_un.i_addr[i] = nb;
E 13
I 13
			ip->i_db[i] = nb;
E 13
			ip->i_flag |= IUPD|ICHG;
		}
D 13
		if(i < NADDR-4)
			rablock = ip->i_un.i_addr[i+1];
		return(nb);
E 13
I 13
gotit:
D 14
		if (i < NDADDR - 1)
			rablock = ip->i_db[i+1];
E 14
I 14
		if (i < NDADDR - 1) {
			rablock = fsbtodb(fs, ip->i_db[i+1]);
			rasize = blksize(fs, ip, i+1);
		}
E 14
		return (nb);
E 13
	}

	/*
D 13
	 * addresses NADDR-3, NADDR-2, and NADDR-1
	 * have single, double, triple indirect blocks.
	 * the first step is to determine
	 * how many levels of indirection.
E 13
I 13
	 * Determine how many levels of indirection.
E 13
	 */
D 13
	sh = 0;
	nb = 1;
	bn -= NADDR-3;
	for(j=3; j>0; j--) {
		sh += NSHIFT;
		nb <<= NSHIFT;
		if(bn < nb)
E 13
I 13
	sh = 1;
	bn -= NDADDR;
	for (j = NIADDR; j>0; j--) {
		sh *= NINDIR(fs);
		if (bn < sh)
E 13
			break;
D 13
		bn -= nb;
E 13
I 13
		bn -= sh;
E 13
	}
D 13
	if(j == 0) {
E 13
I 13
	if (j == 0) {
E 13
		u.u_error = EFBIG;
D 13
		return((daddr_t)0);
E 13
I 13
		return ((daddr_t)0);
E 13
	}

	/*
D 3
	 * fetch the address from the inode
E 3
I 3
	 * fetch the first indirect block
E 3
	 */
D 13
	nb = ip->i_un.i_addr[NADDR-j];
	if(nb == 0) {
		if(rwflg==B_READ || (bp = alloc(dev))==NULL)
			return((daddr_t)-1);
		nb = dbtofsb(bp->b_blkno);
E 13
I 13
	nb = ip->i_ib[NIADDR - j];
	if (nb == 0) {
		if (rwflg==B_READ ||
		    (bp = alloc(ip, (daddr_t)0, fs->fs_bsize)) == NULL)
			return ((daddr_t)-1);
		nb = dbtofsb(fs, bp->b_blkno);
E 13
D 3
		bdwrite(bp);
E 3
I 3
		/*
		 * Write synchronously so that indirect blocks
		 * never point at garbage.
		 */
		bwrite(bp);
E 3
D 13
		ip->i_un.i_addr[NADDR-j] = nb;
E 13
I 13
		ip->i_ib[NIADDR - j] = nb;
E 13
		ip->i_flag |= IUPD|ICHG;
	}

	/*
	 * fetch through the indirect blocks
	 */
D 13
	for(; j<=3; j++) {
		bp = bread(dev, nb);
		if(bp->b_flags & B_ERROR) {
E 13
I 13
	for (; j <= NIADDR; j++) {
		bp = bread(ip->i_dev, fsbtodb(fs, nb), fs->fs_bsize);
		if (bp->b_flags & B_ERROR) {
E 13
			brelse(bp);
D 13
			return((daddr_t)0);
E 13
I 13
			return ((daddr_t)0);
E 13
		}
		bap = bp->b_un.b_daddr;
D 13
		sh -= NSHIFT;
		i = (bn>>sh) & NMASK;
E 13
I 13
		sh /= NINDIR(fs);
		i = (bn / sh) % NINDIR(fs);
E 13
		nb = bap[i];
D 13
		if(nb == 0) {
			if(rwflg==B_READ || (nbp = alloc(dev))==NULL) {
E 13
I 13
		if (nb == 0) {
			if (rwflg==B_READ) {
E 13
				brelse(bp);
D 13
				return((daddr_t)-1);
E 13
I 13
				return ((daddr_t)-1);
E 13
			}
D 13
			nb = dbtofsb(nbp->b_blkno);
D 3
			bdwrite(nbp);
E 3
I 3
			if (j < 3 || (ip->i_mode&IFMT) == IFDIR)
E 13
I 13
			if (i % (fs->fs_fsize / sizeof(daddr_t)) == 0 ||
			    bap[i - 1] == 0)
				pref = blkpref(ip->i_fs);
			else
				pref = bap[i - 1] + fs->fs_frag;
		        nbp = alloc(ip, pref, fs->fs_bsize);
			if (nbp == NULL) {
				brelse(bp);
				return ((daddr_t)-1);
			}
			nb = dbtofsb(fs, nbp->b_blkno);
			if (j < NIADDR || (ip->i_mode&IFMT) == IFDIR)
E 13
				/*
				 * Write synchronously so indirect blocks
				 * never point at garbage and blocks
				 * in directories never contain garbage.
				 */
				bwrite(nbp);
			else
				bdwrite(nbp);
E 3
			bap[i] = nb;
			bdwrite(bp);
		} else
			brelse(bp);
	}

	/*
	 * calculate read-ahead.
	 */
D 13
	if(i < NINDIR-1)
E 13
I 13
D 14
	if (i < NINDIR(fs) - 1)
E 13
		rablock = bap[i+1];
E 14
I 14
	if (i < NINDIR(fs) - 1) {
		rablock = fsbtodb(fs, bap[i+1]);
		rasize = fs->fs_bsize;
	}
E 14
D 13
	return(nb);
E 13
I 13
	return (nb);
E 13
}

/*
E 15
D 20
 * Pass back  c  to the user at his location u_base;
 * update u_base, u_count, and u_offset.  Return -1
 * on the last character of the user's read.
 * u_base is in the user address space unless u_segflg is set.
 */
passc(c)
register c;
{
	register id;

D 13
	if((id = u.u_segflg) == 1)
E 13
I 13
	if ((id = u.u_segflg) == 1)
E 13
		*u.u_base = c;
	else
D 13
		if(id?suibyte(u.u_base, c):subyte(u.u_base, c) < 0) {
E 13
I 13
		if (id?suibyte(u.u_base, c):subyte(u.u_base, c) < 0) {
E 13
			u.u_error = EFAULT;
D 13
			return(-1);
E 13
I 13
			return (-1);
E 13
		}
	u.u_count--;
	u.u_offset++;
	u.u_base++;
D 13
	return(u.u_count == 0? -1: 0);
E 13
I 13
	return (u.u_count == 0? -1: 0);
E 13
}

I 7
D 9
#ifdef unneeded
E 9
I 9
D 10
#include "ct."
E 10
I 10
#include "ct.h"
I 12
#if NCT > 0
E 12
E 10
D 11
#if NCT > 0
E 11
E 9
E 7
/*
 * Pick up and return the next character from the user's
 * write call at location u_base;
 * update u_base, u_count, and u_offset.  Return -1
 * when u_count is exhausted.  u_base is in the user's
 * address space unless u_segflg is set.
 */
D 6
/*
E 6
cpass()
{
	register c, id;

D 13
	if(u.u_count == 0)
		return(-1);
	if((id = u.u_segflg) == 1)
E 13
I 13
	if (u.u_count == 0)
		return (-1);
	if ((id = u.u_segflg) == 1)
E 13
		c = *u.u_base;
	else
D 13
		if((c = id==0?fubyte(u.u_base):fuibyte(u.u_base)) < 0) {
E 13
I 13
		if ((c = id==0?fubyte(u.u_base):fuibyte(u.u_base)) < 0) {
E 13
			u.u_error = EFAULT;
D 13
			return(-1);
E 13
I 13
			return (-1);
E 13
		}
	u.u_count--;
	u.u_offset++;
	u.u_base++;
D 13
	return(c&0377);
E 13
I 13
	return (c&0377);
E 13
}
I 12
#endif
E 12
I 7
D 11
#endif
E 11
E 7
D 6
*/
E 6

/*
E 20
D 21
 * Routine which sets a user error; placed in
 * illegal entries in the bdevsw and cdevsw tables.
E 21
I 21
 * Routine placed in illegal entries in the bdevsw and cdevsw tables.
E 21
 */
nodev()
{

D 21
	u.u_error = ENODEV;
E 21
I 21
	return (ENODEV);
E 21
}

/*
 * Null routine; placed in insignificant entries
 * in the bdevsw and cdevsw tables.
 */
nulldev()
{

I 21
	return (0);
E 21
}

I 29
D 32
#ifndef vax
E 32
I 32
D 35
#ifdef notdef
E 35
I 35
/*
 * Definitions of various trivial functions;
 * usually expanded inline rather than being defined here.
 */
#if !defined(vax) && !defined(tahoe)
E 35
E 32
E 29
imin(a, b)
{

	return (a < b ? a : b);
}

imax(a, b)
I 13
{

	return (a > b ? a : b);
}

unsigned
min(a, b)
D 22
	unsigned int a, b;
E 22
I 22
	u_int a, b;
E 22
{

	return (a < b ? a : b);
}

unsigned
max(a, b)
D 22
	unsigned int a, b;
E 22
I 22
	u_int a, b;
E 22
E 13
{

	return (a > b ? a : b);
}
I 29
D 32
#endif not vax
E 32
I 32
D 35
#endif notdef
E 35
I 35
#endif
E 35
E 32
E 29
I 22

E 22
D 20

struct proc *
pfind(pid)
	int pid;
{
	register struct proc *p;

	for (p = &proc[pidhash[PIDHASH(pid)]]; p != &proc[0]; p = &proc[p->p_idhash])
		if (p->p_pid == pid)
			return (p);
	return ((struct proc *)0);
}
E 20
I 15
D 37
extern	cabase, calimit;
extern	struct pte camap[];

caddr_t	cacur = (caddr_t)&cabase;
caddr_t	camax = (caddr_t)&cabase;
int	cax = 0;
/*
 * This is a kernel-mode storage allocator.
 * It is very primitive, currently, in that
 * there is no way to give space back.
 * It serves, for the time being, the needs of
 * auto-configuration code and the like which
 * need to allocate some stuff at boot time.
 */
caddr_t
calloc(size)
	int size;
{
	register caddr_t res;
	register int i;

	if (cacur+size >= (caddr_t)&calimit)
		panic("calloc");
	while (cacur+size > camax) {
		(void) vmemall(&camap[cax], CLSIZE, &proc[0], CSYS);
		vmaccess(&camap[cax], camax, CLSIZE);
		for (i = 0; i < CLSIZE; i++)
			clearseg(camap[cax++].pg_pfnum);
		camax += NBPG * CLSIZE;
	}
	res = cacur;
	cacur += size;
	return (res);
}
I 17

I 32
D 33
#ifdef notdef
E 33
I 33
#ifdef GPROF
E 33
E 32
I 28
/*
 * Stub routine in case it is ever possible to free space.
 */
cfreemem(cp, size)
	caddr_t cp;
	int size;
{
	printf("freeing %x, size %d\n", cp, size);
}
I 32
#endif
E 32

E 37
E 28
E 17
D 35
#ifndef vax
E 35
I 35
#if !defined(vax) && !defined(tahoe)
E 35
ffs(mask)
	register long mask;
{
	register int i;

D 25
	for(i=1; i<NSIG; i++) {
E 25
I 25
	for(i = 1; i < NSIG; i++) {
E 25
		if (mask & 1)
			return (i);
		mask >>= 1;
	}
	return (0);
}
I 35
#endif
E 35
D 17
#endif
I 16
#ifndef vax
E 17
I 17

I 35
#if !defined(vax)
E 35
E 17
D 23
ffs(mask)
	register long mask;
{
	register int i;

	for(i=1; i<NSIG; i++) {
		if (mask & 1)
			return (i);
		mask >>= 1;
	}
	return (0);
}
D 17
#endif
E 17

E 23
I 17
bcmp(s1, s2, len)
	register char *s1, *s2;
D 36
	register int len;
E 36
I 36
	register unsigned len;
E 36
{

D 23
	while (--len)
E 23
I 23
	while (len--)
E 23
		if (*s1++ != *s2++)
			return (1);
	return (0);
}

strlen(s1)
	register char *s1;
{
	register int len;

	for (len = 0; *s1++ != '\0'; len++)
		/* void */;
	return (len);
}
#endif
I 18
D 27

D 19
copyuout(uio, to, len)
	register struct uio *uio;
	caddr_t to;
E 19
I 19
D 20
copyuout(from, len, uio)
	caddr_t from;
E 19
	int len;
I 19
	register struct uio *uio;
E 19
{
	register struct iovec *iov = uio->uio_iov;
	int error = 0;
	int count;

	while (uio->uio_iovcnt > 0) {
		count = iov->iov_len;
		if (count > len)
			count = len;
D 19
		if (copyout(iov->iov_base, to, count)) {
E 19
I 19
		if (copyout(from, iov->iov_base, count)) {
E 19
			error = EFAULT;
			break;
		}
		iov->iov_base += len;
D 19
		to += count;
E 19
I 19
		from += count;
E 19
		uio->uio_resid -= count;
		iov->iov_len -= len;
		iov++;
		uio->uio_iovcnt--;
		if (iov->iov_len)
			break;
	}
	return (error);
}

E 20
/*
 * Pass back c to the user.
 */
passuc(c, uio)
	register c;
	struct uio *uio;
{
	register struct iovec *iov = uio->uio_iov;
D 20
	register id;
E 20

	switch (uio->uio_segflg) {

	case 0:
		if (subyte(iov->iov_base, c) < 0)
			goto fault;
		break;

	case 1:
		*iov->iov_base = c;
		break;

	case 2:
		if (suibyte(iov->iov_base, c) < 0)
			goto fault;
		break;
	}
	iov->iov_base++;
	iov->iov_len--;
	uio->uio_resid--;
	uio->uio_offset++;
	if (iov->iov_len <= 0) {
		uio->uio_iov++;
		uio->uio_iovcnt--;
	}
	return (0);
fault:
	return (EFAULT);
}
E 27
E 18
E 17
E 16
E 15
E 1
