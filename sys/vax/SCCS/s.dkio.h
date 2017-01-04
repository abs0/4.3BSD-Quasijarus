h24549
s 00001/00001/00017
d D 7.1 86/06/05 00:43:07 mckusick 6 5
c 4.3BSD release version
e
s 00001/00000/00017
d D 6.3 85/06/08 22:19:10 mckusick 5 4
c botched copyright
e
s 00007/00001/00010
d D 6.2 85/06/08 13:41:39 mckusick 4 3
c Add copyright
e
s 00000/00000/00011
d D 6.1 83/07/29 07:19:45 sam 3 2
c 4.2 distribution
e
s 00001/00001/00010
d D 4.2 82/08/01 19:20:03 sam 2 1
c new ioctl's
e
s 00011/00000/00000
d D 4.1 82/02/08 22:48:19 root 1 0
c date and time created 82/02/08 22:48:19 by root
e
u
U
t
T
I 1
D 4
/*	%M%	%I%	%E%	*/
E 4
/*
I 4
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

I 5
/*
E 5
E 4
 * Structures and definitions for disk io control commands
 *
 * THIS WHOLE AREA NEEDS MORE THOUGHT.  FOR NOW JUST IMPLEMENT
 * ENOUGH TO READ AND WRITE HEADERS ON MASSBUS DISKS.  EVENTUALLY
 * SHOULD BE ABLE TO DETERMINE DRIVE TYPE AND DO OTHER GOOD STUFF.
 */

/* disk io control commands */
D 2
#define DKIOCHDR	(('d'<<8)|1)	/* next I/O will read/write header */
E 2
I 2
#define DKIOCHDR	_IO(d, 1)	/* next I/O will read/write header */
E 2
E 1
