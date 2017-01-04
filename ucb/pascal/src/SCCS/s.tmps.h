h49621
s 00010/00000/00064
d D 5.2 86/11/12 09:52:47 mckusick 5 4
c add CCI (tahoe) support
e
s 00007/00003/00057
d D 5.1 85/06/05 16:01:53 dist 4 3
c Add copyright
e
s 00000/00000/00060
d D 2.1 84/02/08 20:50:58 aoki 3 2
c synchronize to version 2
e
s 00000/00000/00060
d D 1.2 83/09/19 07:08:49 thien 2 1
c changing to unlinted source
e
s 00060/00000/00000
d D 1.1 83/02/28 17:22:38 peter 1 0
c date and time created 83/02/28 17:22:38 by peter
e
u
U
t
T
I 1
D 4
/* Copyright (c) 1983 Regents of the University of California */

/* static	char sccsid[] = "%Z%%M% %I% %G%"; */
E 4
I 4
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 4

/*
 * The following structure is used
 * to keep track of the amount of variable
 * storage required by each block.
 * "Max" is the high water mark, "off"
 * the current need. Temporaries for "for"
 * loops and "with" statements are allocated
 * in the local variable area and these
 * numbers are thereby changed if necessary.
 *
 * for the compiler,
 *	low_water is the lowest number register allocated of its type
 *	next_avail is the next available register of its type
 */

#ifdef PC
#ifdef vax
    /*
     *	the number of register types.
     *	the details of how many of each kind of register there is
     *	(and what they are for) is known in tmps.c
     */
#define	NUMREGTYPES	1
#define	REG_GENERAL	0
#endif vax

I 5
#ifdef tahoe
    /*
     *	the number of register types.
     *	the details of how many of each kind of register there is
     *	(and what they are for) is known in tmps.c
     */
#define	NUMREGTYPES	1
#define	REG_GENERAL	0
#endif tahoe

E 5
#ifdef mc68000
    /*
     *	the number of register types.
     *	the details of how many of each kind of register there is
     *	(and what they are for) is known in tmps.c
     */
#define	NUMREGTYPES	2
#define	REG_DATA	0
#define	REG_ADDR	1
#endif mc68000
#endif PC

struct om {
	long	om_max;
#ifdef PC
	long	low_water[NUMREGTYPES];
#endif PC
	struct tmps {
	    long	om_off;
#ifdef PC
	    long	next_avail[NUMREGTYPES];
#endif PC
	}	curtmps;
} sizes[DSPLYSZ];

    /*
     *	an enumeration for whether a temporary can be a register.  cf. tmps.c
     */
#define NOREG 0
#define REGOK 1
E 1
