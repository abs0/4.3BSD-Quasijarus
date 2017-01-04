h40982
s 00014/00002/00008
d D 3.2 88/03/28 13:46:55 bostic 5 4
c add Berkeley specific header
e
s 00000/00000/00010
d D 3.1 87/08/11 10:17:41 minshall 4 3
c New version numbering.
e
s 00002/00000/00008
d D 1.3 87/07/17 10:01:34 minshall 3 2
c Install sccs headers and copyright notices.
e
s 00001/00001/00007
d D 1.2 87/05/28 17:22:34 minshall 2 1
c Size problems.
e
s 00008/00000/00000
d D 1.1 87/05/28 15:33:24 minshall 1 0
c date and time created 87/05/28 15:33:24 by minshall
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
 * Define the translate tables used to go between 3270 display code
 * and ascii
I 3
D 5
 *
 * %W% (Berkeley) %G%
E 5
E 3
 */

extern unsigned char
	disp_asc[256],		/* Goes between display code and ascii */
D 2
	asc_disp[128];		/* Goes between ascii and display code */
E 2
I 2
	asc_disp[256];		/* Goes between ascii and display code */
E 2
E 1
