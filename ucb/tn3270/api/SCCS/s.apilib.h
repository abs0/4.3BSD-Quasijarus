h35010
s 00014/00002/00009
d D 3.2 88/03/28 13:46:39 bostic 4 3
c add Berkeley specific header
e
s 00000/00000/00011
d D 3.1 87/08/11 10:17:33 minshall 3 2
c New version numbering.
e
s 00002/00000/00009
d D 1.2 87/07/17 10:01:26 minshall 2 1
c Install sccs headers and copyright notices.
e
s 00009/00000/00000
d D 1.1 87/05/25 11:17:36 minshall 1 0
c date and time created 87/05/25 11:17:36 by minshall
e
u
U
t
T
I 1
/*
D 4
 * What one needs to specify
E 4
I 4
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
E 4
I 2
 *
D 4
 * %W% (Berkeley) %G%
E 4
I 4
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
 * What one needs to specify
E 4
E 2
 */

extern int
    api_sup_errno,			/* Supervisor error number */
    api_sup_fcn_id,			/* Supervisor function id (0x12) */
    api_fcn_errno,			/* Function error number */
    api_fcn_fcn_id;			/* Function ID (0x6b, etc.) */
E 1
