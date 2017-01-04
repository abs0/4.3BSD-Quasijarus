h51661
s 00014/00002/00014
d D 3.2 88/03/28 12:23:45 bostic 5 4
c add Berkeley specific header
e
s 00000/00000/00016
d D 3.1 87/08/11 10:20:28 minshall 4 3
c New version numbering.
e
s 00002/00000/00014
d D 1.3 87/07/17 10:05:07 minshall 3 2
c Install sccs headers and copyright notices.
e
s 00001/00001/00013
d D 1.2 87/05/20 12:24:11 minshall 2 1
c This version works.
e
s 00014/00000/00000
d D 1.1 87/05/19 16:13:31 minshall 1 0
c date and time created 87/05/19 16:13:31 by minshall
e
u
U
t
T
I 1
/*
I 5
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 *
 *	%W% (Berkeley) %G%
 */

/*
E 5
 * The 'spint' (spawn and interrupt) routines use this structure.
 *
 * Note that spint_asm.asm contains an Assembly language version of
 * the following, so keep changes in synch!
I 3
D 5
 *
 * %W% (Berkeley) %G%
E 5
E 3
 */

typedef struct {
    union REGS		regs;
    struct SREGS	sregs;
    int			int_no;	/* Which interrupt to wait on */
    int			done;	/* Are we done, or just took an interrupt? */
    int			rc;	/* return code */
D 2
} Spawn;
E 2
I 2
} Spint;
E 2
E 1
