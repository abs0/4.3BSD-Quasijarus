h24657
s 00009/00001/00012
d D 5.1 85/06/07 23:49:20 kre 5 4
c Add copyright
e
s 00001/00001/00012
d D 1.4 83/04/25 17:10:22 dlw 4 3
c default open changed to BOF - redefined flag. DLW
e
s 00007/00003/00006
d D 1.3 83/04/25 01:35:29 dlw 3 2
c changed def of io flags. DLW
e
s 00003/00002/00006
d D 1.2 83/04/21 22:07:01 dlw 2 1
c separate flags for ccntrl, opnbof, blzero. DLW
e
s 00008/00000/00000
d D 1.1 83/04/15 21:49:05 dlw 1 0
c date and time created 83/04/15 21:49:05 by dlw
e
u
U
t
T
I 1
/*
I 5
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W%	%G%
 */

/*
E 5
 * set flag to initialize fortran-66 mods
D 5
 *	%W%
E 5
I 5
 *
E 5
 * usage: f77 ... -lI66 ...
 */

D 2
short init66_ = 1;

E 2
I 2
D 3
short ccntrl_ = 1;	/* carriage control on all units */
short blzero_ = 1;	/* blanks are zero input, 0 => 0.0 on output */
short opnbof_ = 1;	/* open files at beginning */
E 3
I 3
#include	"fiodefs.h"

struct ioiflg	ioiflg_ = {
D 4
	 1,		/* open files at beginning */
E 4
I 4
	 0,		/* open files at beginning */
E 4
	 1,		/* carriage control on all units */
	 1,		/* blanks are zero on input; 0 => 0.0 on output */
};
E 3
E 2
E 1
