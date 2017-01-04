h44308
s 00002/00000/00029
d D 5.2 85/10/01 20:22:11 mckusick 5 4
c add fields for bad sector forwarding and sector offset addressing
e
s 00007/00001/00022
d D 5.1 85/05/30 09:35:32 dist 4 3
c Add copyright
e
s 00001/00001/00022
d D 4.3 83/08/11 23:17:03 sam 3 2
c standardize sccs keyword lines
e
s 00000/00001/00023
d D 4.2 83/03/06 12:44:12 sam 2 1
c crud
e
s 00024/00000/00000
d D 4.1 83/03/06 12:42:55 sam 1 0
c date and time created 83/03/06 12:42:55 by sam
e
u
U
t
T
I 1
D 3
/*	%W% (Berkeley) %G%	*/
E 3
I 3
D 4
/*	%M%	%I%	%E%	*/
E 4
I 4
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 4
E 3

/*
 * Disk description table, see disktab(5)
 */
#define	DISKTAB		"/etc/disktab"
D 2
#define	DISKNMLG	32
E 2

struct	disktab {
	char	*d_name;		/* drive name */
	char	*d_type;		/* drive type */
	int	d_secsize;		/* sector size in bytes */
	int	d_ntracks;		/* # tracks/cylinder */
	int	d_nsectors;		/* # sectors/track */
	int	d_ncylinders;		/* # cylinders */
	int	d_rpm;			/* revolutions/minute */
I 5
	int	d_badsectforw;		/* supports DEC bad144 std */
	int	d_sectoffset;		/* use sect rather than cyl offsets */
E 5
	struct	partition {
		int	p_size;		/* #sectors in partition */
		short	p_bsize;	/* block size in bytes */
		short	p_fsize;	/* frag size in bytes */
	} d_partitions[8];
};

struct	disktab *getdiskbyname();
E 1
