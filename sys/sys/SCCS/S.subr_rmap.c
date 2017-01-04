h47052
s 00002/00000/00342
d R 7.2 88/02/27 13:46:21 karels 18 17
c map *must* be terminated after init (even if used before)
e
s 00001/00001/00341
d D 7.1 86/06/05 00:07:10 mckusick 17 16
c 4.3BSD release version
e
s 00001/00001/00341
d D 6.4 85/10/08 22:16:13 bloom 16 15
c could access past end (from allegra!jpl)
e
s 00007/00001/00335
d D 6.3 85/06/08 14:42:03 mckusick 15 14
c Add copyright
e
s 00008/00008/00328
d D 6.2 84/08/29 20:21:40 bloom 14 13
c Change to includes.  no more ../h
e
s 00000/00000/00336
d D 6.1 83/07/29 06:36:18 sam 13 12
c 4.2 distribution
e
s 00003/00003/00333
d D 4.9 83/05/18 01:58:04 sam 12 11
c changes from sun to do swapping on variable sized devices
e
s 00001/00001/00335
d D 4.8 82/10/21 23:53:26 root 11 10
c lint
e
s 00004/00001/00332
d D 4.7 82/10/21 20:57:44 root 10 9
c lint
e
s 00000/00001/00333
d D 4.6 82/10/10 15:34:25 root 9 8
c put headers for vax in separate directories
e
s 00085/00000/00249
d D 4.5 82/04/11 01:03:27 feldman 8 7
c support for ec driver
e
s 00001/00001/00248
d D 4.4 81/03/09 01:48:27 wnj 7 6
c lint and a few minor fixed
e
s 00001/00001/00248
d D 4.3 81/03/06 11:38:30 wnj 6 5
c reformat messages
e
s 00186/00049/00063
d D 4.2 81/02/28 17:17:43 wnj 5 4
c changes for rmalloc, rmfree, malloc.c
e
s 00000/00000/00112
d D 4.1 80/11/09 17:32:13 bill 4 3
c minor fixups to restart stuff; version 4.1 for distrib
e
s 00013/00001/00099
d D 3.3 80/06/24 19:28:44 bill 3 2
c no swplo
e
s 00001/00001/00099
d D 3.2 80/06/07 02:46:12 bill 2 1
c %H%->%G%
e
s 00100/00000/00000
d D 3.1 80/04/09 16:03:27 bill 1 0
c date and time created 80/04/09 16:03:27 by bill
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
D 7
/*	%M%	%I%	%G%	*/
E 7
I 7
D 15
/*	%M%	%I%	%E%	*/
E 15
I 15
/*
D 17
 * Copyright (c) 1982 Regents of the University of California.
E 17
I 17
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 17
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 15
E 7
E 2

D 14
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/map.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/proc.h"
D 9
#include "../h/mtpr.h"
E 9
#include "../h/text.h"
I 10
#include "../h/kernel.h"
E 14
I 14
#include "param.h"
#include "systm.h"
#include "map.h"
#include "dir.h"
#include "user.h"
#include "proc.h"
#include "text.h"
#include "kernel.h"
E 14
E 10

/*
I 5
 * Resource map handling routines.
 *
 * A resource map is an array of structures each
 * of which describes a segment of the address space of an available
 * resource.  The segments are described by their base address and
 * length, and sorted in address order.  Each resource map has a fixed
 * maximum number of segments allowed.  Resources are allocated
 * by taking part or all of one of the segments of the map.
 *
 * Returning of resources will require another segment if
 * the returned resources are not adjacent in the address
 * space to an existing segment.  If the return of a segment
 * would require a slot which is not available, then one of
 * the resource map segments is discarded after a warning is printed.
 * Returning of resources may also cause the map to collapse
 * by coalescing two existing segments and the returned space
 * into a single segment.  In this case the resource map is
 * made smaller by copying together to fill the resultant gap.
 *
 * N.B.: the current implementation uses a dense array and does
 * not admit the value ``0'' as a legal address, since that is used
 * as a delimiter.
 */

/*
 * Initialize map mp to have (mapsize-2) segments
 * and to be called ``name'', which we print if
 * the slots become so fragmented that we lose space.
 * The map itself is initialized with size elements free
 * starting at addr.
 */
rminit(mp, size, addr, name, mapsize)
	register struct map *mp;
D 11
	int size, addr;
E 11
I 11
	long size, addr;
E 11
	char *name;
	int mapsize;
{
	register struct mapent *ep = (struct mapent *)(mp+1);

	mp->m_name = name;
/* N.B.: WE ASSUME HERE THAT sizeof (struct map) == sizeof (struct mapent) */
	/*
	 * One of the mapsize slots is taken by the map structure,
	 * segments has size 0 and addr 0, and acts as a delimiter.
	 * We insure that we never use segments past the end of
	 * the array which is given by mp->m_limit.
	 * Instead, when excess segments occur we discard some resources.
	 */
	mp->m_limit = (struct mapent *)&mp[mapsize];
	/*
	 * Simulate a rmfree(), but with the option to
	 * call with size 0 and addr 0 when we just want
	 * to initialize without freeing.
	 */
	ep->m_size = size;
	ep->m_addr = addr;
}

/*
E 5
 * Allocate 'size' units from the given
D 5
 * map. Return the base of the allocated
 * space.
E 5
I 5
 * map. Return the base of the allocated space.
E 5
 * In a map, the addresses are increasing and the
 * list is terminated by a 0 size.
D 5
 * The swap map unit is 512 bytes.
E 5
I 5
 *
E 5
 * Algorithm is first-fit.
I 5
 *
 * This routine knows about the interleaving of the swapmap
 * and handles that.
E 5
 */
I 10
long
E 10
D 5
malloc(mp, size)
struct map *mp;
E 5
I 5
rmalloc(mp, size)
	register struct map *mp;
I 10
	long size;
E 10
E 5
{
D 5
	register int a;
	register struct map *bp;
E 5
I 5
	register struct mapent *ep = (struct mapent *)(mp+1);
	register int addr;
	register struct mapent *bp;
E 5
I 3
	swblk_t first, rest;
E 3

D 3
	if (size <= 0)
E 3
I 3
D 12
	if (size <= 0 || mp == swapmap && size > DMMAX)
E 12
I 12
	if (size <= 0 || mp == swapmap && size > dmmax)
E 12
E 3
D 5
		panic("malloc");
	for (bp=mp; bp->m_size; bp++) {
E 5
I 5
		panic("rmalloc");
	/*
	 * Search for a piece of the resource map which has enough
	 * free space to accomodate the request.
	 */
	for (bp = ep; bp->m_size; bp++) {
E 5
		if (bp->m_size >= size) {
I 5
			/*
			 * If allocating from swapmap,
			 * then have to respect interleaving
			 * boundaries.
			 */
E 5
I 3
D 12
			if (mp == swapmap &&
			    (first = DMMAX - bp->m_addr%DMMAX) < bp->m_size) {
E 12
I 12
			if (mp == swapmap && nswdev > 1 &&
			    (first = dmmax - bp->m_addr%dmmax) < bp->m_size) {
E 12
				if (bp->m_size - first < size)
					continue;
D 5
				a = bp->m_addr + first;
E 5
I 5
				addr = bp->m_addr + first;
E 5
				rest = bp->m_size - first - size;
				bp->m_size = first;
				if (rest)
D 5
					mfree(swapmap, rest, a+size);
				return (a);
E 5
I 5
					rmfree(swapmap, rest, addr+size);
				return (addr);
E 5
			}
E 3
D 5
			a = bp->m_addr;
E 5
I 5
			/*
			 * Allocate from the map.
			 * If there is no space left of the piece
			 * we allocated from, move the rest of
			 * the pieces to the left.
			 */
			addr = bp->m_addr;
E 5
			bp->m_addr += size;
			if ((bp->m_size -= size) == 0) {
				do {
					bp++;
					(bp-1)->m_addr = bp->m_addr;
				} while ((bp-1)->m_size = bp->m_size);
			}
D 5
			if (mp == swapmap && a % CLSIZE)
				panic("malloc swapmap");
			return(a);
E 5
I 5
			if (mp == swapmap && addr % CLSIZE)
				panic("rmalloc swapmap");
			return (addr);
E 5
		}
	}
D 5
	return(0);
E 5
I 5
	return (0);
E 5
}

/*
D 5
 * Free the previously allocated space aa
E 5
I 5
 * Free the previously allocated space at addr
E 5
 * of size units into the specified map.
D 5
 * Sort aa into map and combine on
E 5
I 5
 * Sort addr into map and combine on
E 5
 * one or both ends if possible.
 */
D 5
mfree(mp, size, a)
struct map *mp;
register int size, a;
E 5
I 5
rmfree(mp, size, addr)
	struct map *mp;
D 10
	register int size, addr;
E 10
I 10
	long size, addr;
E 10
E 5
{
D 5
	register struct map *bp;
E 5
I 5
	struct mapent *firstbp;
	register struct mapent *bp;
E 5
	register int t;

D 5
	if (a <= 0)
		panic("mfree addr");
	if (size <= 0)
		panic("mfree size");
	bp = mp;
	for (; bp->m_addr<=a && bp->m_size!=0; bp++)
E 5
I 5
	/*
	 * Both address and size must be
	 * positive, or the protocol has broken down.
	 */
	if (addr <= 0 || size <= 0)
		goto badrmfree;
	/*
	 * Locate the piece of the map which starts after the
	 * returned space (or the end of the map).
	 */
	firstbp = bp = (struct mapent *)(mp + 1);
	for (; bp->m_addr <= addr && bp->m_size != 0; bp++)
E 5
		continue;
D 5
	if (bp>mp && (bp-1)->m_addr+(bp-1)->m_size > a)
		panic("mfree begov");
	if (a+size > bp->m_addr && bp->m_size)
		panic("mfree endov");
	if (bp>mp && (bp-1)->m_addr+(bp-1)->m_size == a) {
E 5
I 5
	/*
	 * If the piece on the left abuts us,
	 * then we should combine with it.
	 */
	if (bp > firstbp && (bp-1)->m_addr+(bp-1)->m_size >= addr) {
		/*
		 * Check no overlap (internal error).
		 */
		if ((bp-1)->m_addr+(bp-1)->m_size > addr)
			goto badrmfree;
		/*
		 * Add into piece on the left by increasing its size.
		 */
E 5
		(bp-1)->m_size += size;
D 5
		if (a+size == bp->m_addr) {
E 5
I 5
		/*
		 * If the combined piece abuts the piece on
		 * the right now, compress it in also,
		 * by shifting the remaining pieces of the map over.
		 */
		if (bp->m_addr && addr+size >= bp->m_addr) {
			if (addr+size > bp->m_addr)
				goto badrmfree;
E 5
			(bp-1)->m_size += bp->m_size;
			while (bp->m_size) {
				bp++;
				(bp-1)->m_addr = bp->m_addr;
				(bp-1)->m_size = bp->m_size;
			}
		}
D 5
	} else {
		if (a+size == bp->m_addr && bp->m_size) {
			bp->m_addr -= size;
			bp->m_size += size;
		} else if (size) {
			do {
				t = bp->m_addr;
				bp->m_addr = a;
				a = t;
				t = bp->m_size;
				bp->m_size = size;
				bp++;
			} while (size = t);
		}
E 5
I 5
		goto done;
E 5
	}
I 5
	/*
	 * Don't abut on the left, check for abutting on
	 * the right.
	 */
	if (addr+size >= bp->m_addr && bp->m_size) {
		if (addr+size > bp->m_addr)
			goto badrmfree;
		bp->m_addr -= size;
		bp->m_size += size;
		goto done;
	}
	/*
	 * Don't abut at all.  Make a new entry
	 * and check for map overflow.
	 */
	do {
		t = bp->m_addr;
		bp->m_addr = addr;
		addr = t;
		t = bp->m_size;
		bp->m_size = size;
		bp++;
	} while (size = t);
	/*
	 * Segment at bp is to be the delimiter;
	 * If there is not room for it 
	 * then the table is too full
	 * and we must discard something.
	 */
	if (bp+1 > mp->m_limit) {
		/*
		 * Back bp up to last available segment.
		 * which contains a segment already and must
		 * be made into the delimiter.
		 * Discard second to last entry,
		 * since it is presumably smaller than the last
		 * and move the last entry back one.
		 */
		bp--;
D 6
		printf("%s rmap overflow, lost [%d,%d)\n", mp->m_name,
E 6
I 6
		printf("%s: rmap ovflo, lost [%d,%d)\n", mp->m_name,
E 6
		    (bp-1)->m_addr, (bp-1)->m_addr+(bp-1)->m_size);
		bp[-1] = bp[0];
		bp[0].m_size = bp[0].m_addr = 0;
	}
done:
	/*
	 * THIS IS RIDICULOUS... IT DOESN'T BELONG HERE!
	 */
E 5
	if ((mp == kernelmap) && kmapwnt) {
		kmapwnt = 0;
		wakeup((caddr_t)kernelmap);
	}
I 5
	return;
badrmfree:
	panic("bad rmfree");
E 5
}
I 8

/*
 * Allocate 'size' units from the given map, starting at address 'addr'.
 * Return 'addr' if successful, 0 if not.
 * This may cause the creation or destruction of a resource map segment.
 *
 * This routine will return failure status if there is not enough room
 * for a required additional map segment.
 *
 * An attempt to use this on 'swapmap' will result in
 * a failure return.  This is due mainly to laziness and could be fixed
 * to do the right thing, although it probably will never be used.
 */
rmget(mp, size, addr)
	register struct map *mp;
{
	register struct mapent *ep = (struct mapent *)(mp+1);
	register struct mapent *bp, *bp2;

	if (size <= 0)
		panic("rmget");
	if (mp == swapmap)
		return (0);
	/*
	 * Look for a map segment containing the requested address.
	 * If none found, return failure.
	 */
	for (bp = ep; bp->m_size; bp++)
		if (bp->m_addr <= addr && bp->m_addr + bp->m_size > addr)
			break;
	if (bp->m_size == 0)
		return (0);

	/*
	 * If segment is too small, return failure.
	 * If big enough, allocate the block, compressing or expanding
	 * the map as necessary.
	 */
	if (bp->m_addr + bp->m_size < addr + size)
		return (0);
	if (bp->m_addr == addr)
		if (bp->m_addr + bp->m_size == addr + size) {
			/*
			 * Allocate entire segment and compress map
			 */
			bp2 = bp;
			while (bp2->m_size) {
				bp2++;
				(bp2-1)->m_addr = bp2->m_addr;
				(bp2-1)->m_size = bp2->m_size;
			}
		} else {
			/*
			 * Allocate first part of segment
			 */
			bp->m_addr += size;
			bp->m_size -= size;
		}
	else
		if (bp->m_addr + bp->m_size == addr + size) {
			/*
			 * Allocate last part of segment
			 */
			bp->m_size -= size;
		} else {
			/*
			 * Allocate from middle of segment, but only
			 * if table can be expanded.
			 */
			for (bp2=bp; bp2->m_size; bp2++)
				;
D 16
			if (bp2 == mp->m_limit)
E 16
I 16
			if (bp2 + 1 >= mp->m_limit)
E 16
				return (0);
			while (bp2 > bp) {
				(bp2+1)->m_addr = bp2->m_addr;
				(bp2+1)->m_size = bp2->m_size;
				bp2--;
			}
			(bp+1)->m_addr = addr + size;
			(bp+1)->m_size =
			    bp->m_addr + bp->m_size - (addr + size);
			bp->m_size = addr - bp->m_addr;
		}
	return (addr);
}
E 8
E 1
