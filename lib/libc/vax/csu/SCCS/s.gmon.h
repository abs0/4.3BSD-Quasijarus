h05312
s 00007/00001/00071
d D 5.1 85/05/30 14:57:14 dist 7 6
c Add copyright
e
s 00024/00000/00048
d D 4.4 83/01/13 18:59:57 mckusick 6 5
c add HASHFRACTION
e
s 00024/00003/00024
d D 4.3 82/12/10 17:09:50 peter 5 4
c self organizing linked lists.
e
s 00003/00000/00024
d D 4.2 82/12/04 16:42:14 mckusick 4 3
c base number of counters on DENSITY; use ~20% of textsize
e
s 00000/00000/00024
d D 4.1 81/11/29 23:32:37 mckusic 3 2
c renumber to version 4
e
s 00011/00000/00013
d D 1.2 81/11/12 14:49:03 mckusic 2 1
c "gmcrt0" becomes "gcrt0"; eliminate stdio in gcrt0.c
e
s 00013/00000/00000
d D 1.1 81/10/15 21:40:35 peter 1 0
c date and time created 81/10/15 21:40:35 by peter
e
u
U
t
T
I 1
D 7
    /*	%W% (Berkeley) %G%	*/
E 7
I 7
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 7

I 4
D 5
#define DENSITY 2	/* density of routines */
#define MINCNT  50	/* minimum number of counters */

E 5
E 4
struct phdr {
    char	*lpc;
    char	*hpc;
    int		ncnt;
};

I 5
    /*
     *	histogram counters are unsigned shorts (according to the kernel).
     */
#define	HISTCOUNTER	unsigned short

    /*
     *	fraction of text space to allocate for histogram counters
     *	here, 1/2
     */
#define	HISTFRACTION	2

    /*
I 6
     *	Fraction of text space to allocate for from hash buckets.
     *	The value of HASHFRACTION is based on the minimum number of bytes
     *	of separation between two subroutine call points in the object code.
     *	Given MIN_SUBR_SEPARATION bytes of separation the value of
     *	HASHFRACTION is calculated as:
     *
     *		HASHFRACTION = MIN_SUBR_SEPARATION / (2 * sizeof(short) - 1);
     *
     *	For the VAX, the shortest two call sequence is:
     *
     *		calls	$0,(r0)
     *		calls	$0,(r0)
     *
     *	which is separated by only three bytes, thus HASHFRACTION is 
     *	calculated as:
     *
     *		HASHFRACTION = 3 / (2 * 2 - 1) = 1
     *
     *	Note that the division above rounds down, thus if MIN_SUBR_FRACTION
     *	is less than three, this algorithm will not work!
     */
#define	HASHFRACTION	1

    /*
E 6
     *	percent of text space to allocate for tostructs
     *	with a minimum.
     */
#define ARCDENSITY	2
#define MINARCS		50

E 5
struct tostruct {
    char		*selfpc;
    long		count;
    unsigned short	link;
};
I 2

    /*
     *	a raw arc,
     *	    with pointers to the calling site and the called site
     *	    and a count.
     */
struct rawarc {
    unsigned long	raw_frompc;
    unsigned long	raw_selfpc;
    long		raw_count;
};
I 5

    /*
     *	general rounding functions.
     */
#define ROUNDDOWN(x,y)	(((x)/(y))*(y))
#define ROUNDUP(x,y)	((((x)+(y)-1)/(y))*(y))
E 5
E 2
E 1
