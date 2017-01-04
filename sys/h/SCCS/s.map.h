h12737
s 00001/00000/00050
d D 7.2 87/06/06 13:25:28 mckusick 14 13
c camap is replaced by kmempt
e
s 00001/00001/00049
d D 7.1 86/06/04 23:24:38 mckusick 13 12
c 4.3BSD release version
e
s 00007/00001/00043
d D 6.2 85/06/08 15:00:43 mckusick 12 11
c Add copyright
e
s 00000/00000/00044
d D 6.1 83/07/29 06:12:59 sam 11 10
c 4.2 distribution
e
s 00001/00003/00043
d D 4.7 81/11/08 16:45:03 wnj 10 9
c netmap --> mbmap
e
s 00003/00000/00043
d D 4.6 81/05/12 17:20:19 root 9 8
c bbn tcp/ip
e
s 00030/00004/00013
d D 4.5 81/02/28 18:01:30 wnj 8 7
c fixups for rm* routines
e
s 00001/00000/00016
d D 4.4 81/02/27 17:50:52 wnj 7 6
c for dynamic kernel allocate version
e
s 00003/00005/00013
d D 4.3 81/02/27 02:38:37 wnj 6 5
c dynamic alloc kernel version
e
s 00001/00001/00017
d D 4.2 81/02/19 21:41:02 wnj 5 4
c %G%->%E%
e
s 00000/00000/00018
d D 4.1 80/11/09 17:01:10 bill 4 3
c stamp for 4bsd
e
s 00002/00000/00016
d D 3.3 80/07/01 08:17:07 bill 3 2
c various minor fixups pre-split to dev dir
e
s 00001/00001/00015
d D 3.2 80/06/07 02:58:19 bill 2 1
c %H%->%G%
e
s 00016/00000/00000
d D 3.1 80/04/09 16:24:10 bill 1 0
c date and time created 80/04/09 16:24:10 by bill
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
D 5
/*	%M%	%I%	%G%	*/
E 5
I 5
D 12
/*	%M%	%I%	%E%	*/
E 12
I 12
/*
D 13
 * Copyright (c) 1982 Regents of the University of California.
E 13
I 13
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 13
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 12
E 5
E 2

/*
D 8
 * Resource Allocation Maps
E 8
I 8
 * Resource Allocation Maps.
 *
 * Associated routines manage sub-allocation of an address space using
 * an array of segment descriptors.  The first element of this array
 * is a map structure, describing the arrays extent and the name
 * of the controlled object.  Each additional structure represents
 * a free segment of the address space.
 *
 * A call to rminit initializes a resource map and may also be used
 * to free some address space for the map.  Subsequent calls to rmalloc
 * and rmfree allocate and free space in the resource map.  If the resource
 * map becomes too fragmented to be described in the available space,
 * then some of the resource is discarded.  This may lead to critical
 * shortages, but is better than not checking (as the previous versions
 * of these routines did) or giving up and calling panic().  The routines
 * could use linked lists and call a memory allocator when they run
 * out of space, but that would not solve the out of space problem when
 * called at interrupt time.
 *
 * N.B.: The address 0 in the resource address space is not available
 * as it is used internally by the resource map routines.
E 8
 */
D 8
struct map
E 8
I 8
struct map {
	struct	mapent *m_limit;	/* address of last slot in map */
	char	*m_name;		/* name of resource */
/* we use m_name when the map overflows, in warning messages */
};
struct mapent
E 8
{
D 8
	int	m_size;
	int	m_addr;
E 8
I 8
	int	m_size;		/* size of this segment of the map */
	int	m_addr;		/* resource-space addr of start of segment */
E 8
};

#ifdef KERNEL
D 6
struct	map swapmap[SMAPSIZ];	/* space for swap allocation */
I 3
#define	AMAPSIZ	25
struct	map argmap[AMAPSIZ];
E 3

struct	map kernelmap[NPROC];	/* space for kernel map for user page tables */
E 6
I 6
struct	map *swapmap;
I 7
int	nswapmap;
E 7
struct	map *argmap;
I 8
#define	ARGMAPSIZE	16
E 8
struct	map *kernelmap;
I 9
D 10
#ifdef BBNNET
struct  map *netmap;
#endif
E 10
I 10
struct	map *mbmap;
I 14
struct	map *kmemmap;
E 14
E 10
E 9
E 6
#endif
E 1
