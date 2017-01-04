h59051
s 00001/00001/00045
d D 5.2 87/04/07 13:22:28 bostic 3 2
c change N_FN to 0x1e
e
s 00007/00001/00039
d D 5.1 85/05/30 09:38:50 dist 2 1
c Add copyright
e
s 00040/00000/00000
d D 4.1 83/05/03 13:48:07 sam 1 0
c date and time created 83/05/03 13:48:07 by sam
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%E%	*/
E 2
I 2
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 2

/*
 * Format of a symbol table entry; this file is included by <a.out.h>
 * and should be used if you aren't interested the a.out header
 * or relocation information.
 */
struct	nlist {
	char	*n_name;	/* for use when in-core */
	unsigned char n_type;	/* type flag, i.e. N_TEXT etc; see below */
	char	n_other;	/* unused */
	short	n_desc;		/* see <stab.h> */
	unsigned long n_value;	/* value of this symbol (or sdb offset) */
};
#define	n_hash	n_desc		/* used internally by ld */

/*
 * Simple values for n_type.
 */
#define	N_UNDF	0x0		/* undefined */
#define	N_ABS	0x2		/* absolute */
#define	N_TEXT	0x4		/* text */
#define	N_DATA	0x6		/* data */
#define	N_BSS	0x8		/* bss */
#define	N_COMM	0x12		/* common (internal to ld) */
D 3
#define	N_FN	0x1f		/* file name symbol */
E 3
I 3
#define	N_FN	0x1e		/* file name symbol */
E 3

#define	N_EXT	01		/* external bit, or'ed in */
#define	N_TYPE	0x1e		/* mask for all the type bits */

/*
 * Sdb entries have some of the N_STAB bits set.
 * These are given in <stab.h>
 */
#define	N_STAB	0xe0		/* if any of these bits set, a SDB entry */

/*
 * Format for namelist values.
 */
#define	N_FORMAT	"%08x"
E 1
