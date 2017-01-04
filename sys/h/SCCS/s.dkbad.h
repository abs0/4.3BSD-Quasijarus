h43667
s 00001/00001/00046
d D 7.1 86/06/04 23:21:33 mckusick 6 5
c 4.3BSD release version
e
s 00007/00001/00040
d D 6.2 85/06/08 14:56:03 mckusick 5 4
c Add copyright
e
s 00000/00000/00041
d D 6.1 83/07/29 06:12:06 sam 4 3
c 4.2 distribution
e
s 00012/00015/00029
d D 4.3 81/05/10 20:03:05 root 3 2
c s/block/sector/ dk_magic->dk_mbz
e
s 00003/00001/00041
d D 4.2 81/05/09 22:38:31 root 2 1
c add name to internal structure for bad(8)
e
s 00042/00000/00000
d D 4.1 81/05/08 21:57:01 wnj 1 0
c date and time created 81/05/08 21:57:01 by wnj
e
u
U
t
T
I 1
D 5
/*	%M%	%I%	%E%	*/
E 5
I 5
/*
D 6
 * Copyright (c) 1982 Regents of the University of California.
E 6
I 6
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 6
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 5

/*
D 3
 * Definitions needed to perform bad block
E 3
I 3
 * Definitions needed to perform bad sector
E 3
 * revectoring ala DEC STD 144.
 *
D 3
 * The bad block information is located in the
E 3
I 3
 * The bad sector information is located in the
E 3
 * first 5 even numbered sectors of the last
 * track of the disk pack.  There are five
 * identical copies of the information, described
 * by the dkbad structure.
 *
D 3
 * Replacement blocks are allocated starting with
 * the first block before the bad block information
E 3
I 3
 * Replacement sectors are allocated starting with
 * the first sector before the bad sector information
E 3
 * and working backwards towards the beginning of
D 3
 * the disk.  A maximum of 126 bad blocks are supported.
 * The position of the bad block in the bad block table
 * determines which replacement block it corresponds to.
E 3
I 3
 * the disk.  A maximum of 126 bad sectors are supported.
 * The position of the bad sector in the bad sector table
 * determines which replacement sector it corresponds to.
E 3
 *
D 3
 * The bad block information and replacement blocks
 * are conventionally only accessable through the
E 3
I 3
 * The bad sector information and replacement sectors
 * are conventionally only accessible through the
E 3
 * 'c' file system partition of the disk.  If that
 * partition is used for a file system, the user is
 * responsible for making sure that it does not overlap
D 3
 * the bad block information or any replacement blocks.
E 3
I 3
 * the bad sector information or any replacement sector.s
E 3
 */

struct dkbad {
	long	bt_csn;			/* cartridge serial number */
D 3
	u_short	bt_magic;		/* magic number for sanity check */
I 2
#ifdef notdef
E 2
#define	BADMAGIC	0122155
I 2
#endif
E 3
I 3
	u_short	bt_mbz;			/* unused; should be 0 */
E 3
E 2
	u_short	bt_flag;		/* -1 => alignment cartridge */
D 2
	struct {
E 2
I 2
	struct bt_bad {
E 2
D 3
		u_short	bt_cyl;		/* cylinder number of bad block */
E 3
I 3
		u_short	bt_cyl;		/* cylinder number of bad sector */
E 3
		u_short	bt_trksec;	/* track and sector number */
	} bt_bad[126];
};

#define	ECC	0
#define	SSE	1
#define	BSE	2
#define	CONT	3
E 1
