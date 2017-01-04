h24952
s 00001/00001/00086
d D 7.1 86/06/04 23:23:25 mckusick 5 4
c 4.3BSD release version
e
s 00007/00001/00080
d D 6.2 85/06/08 14:58:43 mckusick 4 3
c Add copyright
e
s 00000/00000/00081
d D 6.1 83/07/29 06:12:36 sam 3 2
c 4.2 distribution
e
s 00071/00014/00010
d D 4.2 83/01/15 16:50:07 mckusick 2 1
c new austere memory version
e
s 00024/00000/00000
d D 4.1 82/06/27 14:56:56 sam 1 0
c date and time created 82/06/27 14:56:56 by sam
e
u
U
t
T
I 1
D 4
/*	%M%	%I%	%E%	*/
E 4
I 4
/*
D 5
 * Copyright (c) 1982 Regents of the University of California.
E 5
I 5
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 5
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 4

struct phdr {
D 2
	char	*lpc;
	char	*hpc;
	int	ncnt;
E 2
I 2
    char	*lpc;
    char	*hpc;
    int		ncnt;
E 2
};

I 2
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
     *
     *	NB: for the kernel we assert that the shortest two call sequence is:
     *
     *		calls	$0,_name
     *		calls	$0,_name
     *
     *	which is separated by seven bytes, thus HASHFRACTION is calculated as:
     *
     *		HASHFRACTION = 7 / (2 * 2 - 1) = 2
     */
#define	HASHFRACTION	2

    /*
     *	percent of text space to allocate for tostructs
     *	with a minimum.
     */
#define ARCDENSITY	2
#define MINARCS		50

E 2
struct tostruct {
D 2
	char	*selfpc;
	long	count;
	u_short	link;
E 2
I 2
    char		*selfpc;
    long		count;
    unsigned short	link;
E 2
};

D 2
/*
 * a raw arc,
 *	with pointers to the calling site and the called site
 *	and a count.
 */
E 2
I 2
    /*
     *	a raw arc,
     *	    with pointers to the calling site and the called site
     *	    and a count.
     */
E 2
struct rawarc {
D 2
	u_long	raw_frompc;
	u_long	raw_selfpc;
	long	raw_count;
E 2
I 2
    unsigned long	raw_frompc;
    unsigned long	raw_selfpc;
    long		raw_count;
E 2
};
I 2

    /*
     *	general rounding functions.
     */
#define ROUNDDOWN(x,y)	(((x)/(y))*(y))
#define ROUNDUP(x,y)	((((x)+(y)-1)/(y))*(y))
E 2
E 1
